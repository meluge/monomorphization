import Lean
open Lean Elab Tactic Expr Std
open Meta hiding transform

structure Mono where
  id : MVarId
  levels : List Name
  assignment : Expr

structure MonoState where
  mono : HashMap Name (List Mono)
  given : HashSet Expr
  globalFVars : HashSet FVarId

instance : ToString MonoState where
  toString s := s!"{s.mono.toList.map (fun x => x.1)}\n{s.given.toList}"

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
    let bs := (← getBinders info.type).toArray
    let instImplicit := (bs.zip args).filterMap fun ⟨binfo, a⟩ =>
      if binfo.isInstImplicit then some a else none
    if !instImplicit.isEmpty then
      let mut found := false
      let globalFVars := (← get).globalFVars
      let p := fun x => !globalFVars.contains x
      for arg in instImplicit do
        if arg.hasAnyFVar p then
          found := true
        else
          let type ← inferType arg
          modify (fun s => { s with given := s.given.insert type })
      if args.size == bs.size && !found then
        let set := (← get).mono.getD fn []
        for ⟨id, levels, value⟩ in set do
          let mvarlevels ← mkFreshLevelMVars levels.length
          let instantiated := value.instantiateLevelParams levels mvarlevels
          let ⟨metas, _, body⟩ ← lambdaMetaTelescope instantiated
          if ← isDefEqGuarded e body then
            return mkAppN (.mvar id) (← metas.mapM instantiateMVars)
        -- create new const!
        let mvarlevels ← mkFreshLevelMVars info.levelParams.length
        let typeInstantiated := info.type.instantiateLevelParams info.levelParams mvarlevels
        let ⟨metas, _, _⟩ ← forallMetaTelescope typeInstantiated
        let instImplicit' := (bs.zip metas).filterMap fun ⟨binfo, a⟩ =>
          if binfo.isInstImplicit then some a else none
        for ⟨arg, meta⟩ in instImplicit.zip instImplicit' do
          if !(← isDefEq arg meta) then
            panic! s!"Invalid application of {fn}"
        let value := mkAppN (mkConst fn mvarlevels) metas
        let abstractResult ← abstractMVars (← instantiateMVars value)
        let name := fn.num set.length

        let mvar := (← mkFreshExprMVar (← inferType abstractResult.expr) .syntheticOpaque name).mvarId!

        modify (fun s => { s with mono := s.mono.insert fn (
            ⟨mvar, abstractResult.paramNames.toList, abstractResult.expr⟩ :: set)
          })
        let _ ← isDefEq value e
        return mkAppN (.mvar mvar) (← abstractResult.mvars.mapM instantiateMVars)
  pure e

def preprocess (e : Expr) : MonoM Expr := do
  preprocessMono (← whnf e)

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
-- set_option pp.explicit true
#eval (do
  let e := ((← getEnv).find? `test).get!.value!
  let e' ← (transform e preprocessMono).run {
    mono := .emptyWithCapacity 10,
    given := .emptyWithCapacity 10,
    globalFVars := .emptyWithCapacity 10
  }
  dbg_trace (← ppExpr e)
  dbg_trace (← ppExpr e'.1)
  -- dbg_trace e'.2
)

partial def getInstanceTypes (e : Expr) : MetaM (HashSet Expr) := do
  match e with
  | app _ _ =>
      let (fn, args) := Expr.getAppFnArgs e
      if let some info := (← getEnv).find? fn then
        let bs ← getBinders info.type
        let insts ← (bs.toArray.zip args).filterMapM fun ⟨binfo, arg⟩ => do
          if !binfo.isInstImplicit || arg.hasLooseBVars then
            pure none
          else some <$> inferType arg
        args.foldlM (fun acc a => return acc ∪ (← getInstanceTypes a)) (HashSet.ofArray insts)
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

#check Meta.abstractMVars
#check mkFreshExprMVar
