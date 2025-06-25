import Lean
import Mathlib.Tactic.Ring
import Mathlib.Data.Real.Basic
import Mathlib.Data.ZMod.Basic
import Mathlib.Data.List.Basic

open Lean Elab Tactic Expr Std
open Meta hiding transform

structure MonoState where
  mono : HashMap Name (List Name)
  given : HashSet Expr
  globalFVars : HashSet FVarId

instance : ToString MonoState where
  toString s := s!"{s.mono.toList}\n{s.given.toList}"

abbrev MonoM := StateT MonoState MetaM


partial def getBinders (e : Expr) : MetaM (List BinderInfo) := do
  match e with
  | forallE _ _ b i        => return i :: (← getBinders b)
  | mdata _ b | lam _ _ b _ | app _ b | letE _ _ _ b _ => getBinders b
  | _                      => return []

partial def preprocessMono (e : Expr) : MonoM Expr := do
  let (fn, args) := Expr.getAppFnArgs e
  let env ← getEnv
  if let some info := env.find? fn then
    let bs ← getBinders info.type
    let indexes := bs.indexesOf .instImplicit
    if !indexes.isEmpty then
      let mut found := false
      let globalFVars := (← get).globalFVars
      let p := fun x => !globalFVars.contains x
      for i in indexes do
        let a := args[i]! -- TODO check fully applied
        if a.hasAnyFVar p then
          found := true
        else
          let type ← inferType a
          modify (fun s => { s with given := s.given.insert type })
      if !found then
        let set := (← get).mono.getD fn []
        for name in set do
          let constInfo := (env.find? name).get!
          let level ← constInfo.levelParams.mapM (fun _ => mkFreshLevelMVar)
          let instantiated := constInfo.value!.instantiateLevelParams constInfo.levelParams level
          let ⟨metas, _, body⟩ ← lambdaMetaTelescope instantiated
          if ← isDefEqGuarded e body then
            let result := mkAppN (mkConst name level) metas
            return (← instantiateMVars result)
        -- create new const!
        let level ← info.levelParams.mapM (fun _ => mkFreshLevelMVar)
        let typeInstantiated := info.type.instantiateLevelParams info.levelParams level
        let ⟨metas, _, _⟩ ← forallMetaTelescope typeInstantiated
        for i in indexes do
          if !(← isDefEq args[i]! metas[i]!) then
            panic! s!"Invalid application of {fn}"
        let value := mkAppN (mkConst fn level) metas
        let abstractResult ← abstractMVars (← instantiateMVars value)
        let name := fn.num set.length
        modify (fun s => { s with mono := s.mono.insert fn (name :: set) })
        let _ ← addDecl <| Declaration.defnDecl {
          name, levelParams := [] /- TODO-/,
          type := (← inferType abstractResult.expr),
          value := abstractResult.expr,
          hints := .opaque,
          safety := .safe
        }
        let _ ← isDefEq value e
        let result := mkAppN (mkConst name level) abstractResult.mvars
        return (← instantiateMVars result)
  pure e


partial def transform [Monad n] [MonadControlT MetaM n] (e : Expr) (f : Expr → n Expr) : n Expr := do
  match ← f e with
  | app fn arg =>
    pure (.app (← transform fn f) (← transform arg f))
  | lam name type body info =>
    withLocalDecl name info type fun fvar => do
      pure (.lam name (← transform type f)
        ((← transform (body.instantiate1 fvar) f).abstract #[fvar]) info)
  | forallE name type body info =>
    withLocalDecl name info type fun fvar => do
      pure (.forallE name (← transform type f)
        ((← transform (body.instantiate1 fvar) f).abstract #[fvar]) info)
  | letE name type value body nonDep =>
    withLetDecl name type value fun fvar => do
      pure (.letE name (← transform type f) (← transform value f)
        ((← transform (body.instantiate1 fvar) f).abstract #[fvar]) nonDep)
  | mdata m b => pure (.mdata m (← transform b f))
  | _ => pure e


def test (a b : Nat) := 0 + 1 + 2

#eval (do
  let e := ((← getEnv).find? `test).get!.value!
  let e' ← (transform e preprocessMono).run {
    mono := .emptyWithCapacity 10,
    given := .emptyWithCapacity 10,
    globalFVars := .emptyWithCapacity 10
  }
  -- let e' ← (preprocessMono e).run {
  --   mono := .emptyWithCapacity 10,
  --   given := .emptyWithCapacity 10,
  --   globalFVars := .emptyWithCapacity 10
  -- }
  dbg_trace (← ppExpr e)
  dbg_trace (← ppExpr e'.1)
  dbg_trace e'.2
)

partial def getInstanceTypes (e : Expr) : MetaM (HashSet Expr) := do
  match e with
  | app _ _ =>
      let (fn, args) := Expr.getAppFnArgs e
      if let some info := (← getEnv).find? fn then
        let bs ← getBinders info.type
        let insts ← (bs.indexesOf .instImplicit).filterMapM fun i => do
          let a := args[i]! -- TODO check fully applied
          if a.hasLooseBVars then pure none else some <$> inferType a
        args.foldlM (fun acc a => return acc ∪ (← getInstanceTypes a)) (HashSet.ofList insts)
      else
        return ∅
  | mdata _ b | lam _ _ b _ | letE _ _ _ b _ => getInstanceTypes b
  | _ => return ∅

partial def unify (todo : List Expr) (given : List Expr) (cb : MetaM AbstractionResult) : MetaM (List AbstractionResult) := do
  match todo with
  | [] => return [← cb]
  | type :: todo =>
    let type ← instantiateMVars type
    if type.hasMVar then
      let branches ← given.filterMapM fun inst => do
        withoutModifyingMCtx do
          if ← isDefEqGuarded type inst then
            pure (some (← unify todo given cb))
          else pure none
      if !branches.isEmpty then
        return branches.flatten
    unify todo given cb

def updateLambdaBinderInfos (e : Expr) (binderInfos? : List (Option BinderInfo)) : Expr :=
  match e, binderInfos? with
  | Expr.lam n d b bi, newBi? :: binderInfos? =>
    let b  := updateLambdaBinderInfos b binderInfos?
    let bi := newBi?.getD bi
    Expr.lam n d b bi
  | e, _ => e

def monomorphizeCore (goal : MVarId) (id : Syntax) :
    MetaM (List MVarId) := goal.withContext do
  let constName ← resolveGlobalConstNoOverload id
  let constInfo ← getConstInfo constName
  let goalType ← goal.getType

  let levels ← constInfo.levelParams.mapM (fun _ => mkFreshLevelMVar)

  let typeInstantiated := constInfo.type.instantiateLevelParams constInfo.levelParams levels

  let given := (← getInstanceTypes goalType).toList
  let (mvars, binders, body) ← forallMetaTelescopeReducing typeInstantiated

  let instImplicit := (mvars.zip binders).filterMap fun ⟨m, binfo⟩ =>
    if binfo.isInstImplicit then some m else none

  let instImplicitTypes ← instImplicit.mapM (fun mvar => do mvar.mvarId!.getType)
  let todo := (← getInstanceTypes body).insertMany instImplicitTypes.toList

  let abstResults ← unify todo.toList given do
    for mvar in instImplicit do
      let mty ← instantiateMVars (← mvar.mvarId!.getType)
      try
        let inst ← synthInstance mty
        mvar.mvarId!.assign inst
      catch _ => pure ()

    let appliedExpr := mkAppN (Expr.const constName levels) mvars
    let instantiated ← instantiateMVars appliedExpr
    abstractMVars instantiated

  let newGoal ← abstResults.foldlM (fun goal abstrResult => do
    let binfos := abstrResult.mvars.map (fun mvar =>
      (mvars.idxOf? mvar).map (fun idx => binders[idx]!)
    )

    let withBinders := updateLambdaBinderInfos (abstrResult.expr) binfos.toList

    let newName := constName.modifyBase fun s => Name.mkSimple (toString s ++ "'")
    pure (← goal.note newName withBinders).2
  ) goal
  return [newGoal]

def monomorphizeMultiple (goal : MVarId) (ids : Array Syntax) : MetaM (List MVarId) := do
  ids.foldlM (fun currentGoals id => do
    match currentGoals with
    | [] => return []
    | g :: _ => monomorphizeCore g id
  ) [goal]

syntax (name := monomorphize) "monomorphize " "[" ident,* "]" : tactic
syntax (name := monomorphizeSingle) "monomorphize " ident : tactic

@[tactic monomorphize] def evalMonomorphize : Tactic
| `(tactic| monomorphize [$ids:ident,*]) => do
    let idsArray := ids.getElems
    liftMetaTactic fun g => monomorphizeMultiple g idsArray
| _ => throwUnsupportedSyntax

@[tactic monomorphizeSingle] def evalMonomorphizeSingle : Tactic
| `(tactic| monomorphize $id:ident) =>
    liftMetaTactic fun g => monomorphizeCore g id
| _ => throwUnsupportedSyntax

example (m n : Nat) : m + n = n + m := by
  monomorphize add_comm
  exact add_comm' m n

example (R : Type*) [CommRing R] (x : R) (m n : Nat) : x^(m + n) = x^m * x^n := by
  monomorphize pow_add
  exact pow_add' x m n

example (R : Type*) [CommRing R] (x : R) (m n : Nat) : x^(m + n) = x^m * x^n ∧ m + n = n + m := by
  monomorphize [pow_add, add_comm]
  constructor
  · exact pow_add' x m n
  · exact add_comm' m n

#eval (do
  let _ ← withLocalDecl `unused .default (← mkFreshExprMVar none) fun fvar => do
    addDecl <| Declaration.defnDecl {
      name := `test,
      type := mkSort (Level.succ Level.zero),
      value := mkSort Level.zero,
      levelParams := [],
      hints := .opaque,
      safety := .safe
    }
  dbg_trace ((← getEnv).find? `test).isSome
)
