import Lean
import Mathlib.Tactic.Ring
import Mathlib.Data.Real.Basic
import Mathlib.Data.ZMod.Basic
import Mathlib.Data.List.Basic
import Mathlib.Algebra.Group.Defs

open Lean Meta Elab Tactic Expr Std

partial def getBinders (e : Expr) : MetaM (List BinderInfo) := do
  match e with
  | forallE _ _ b i        => return i :: (← getBinders b)
  | mdata _ b | lam _ _ b _ | app _ b | letE _ _ _ b _ => getBinders b
  | _                      => return []

partial def getInstanceTypes (e : Expr) : MetaM (HashSet Expr) := do
  match e with
  | app _ _ =>
      let (fn, args) := Expr.getAppFnArgs e
      if let some info := (← getEnv).find? fn then
        let bs ← getBinders info.type
        let insts ← (bs.indexesOf .instImplicit).filterMapM fun i => do
          let a := args[i]!
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
    dbg_trace withBinders

    let newName := constName.modifyBase fun s => Name.mkSimple (toString s ++ "'")
    -- note or let
    pure (← goal.note newName withBinders).2
  ) goal
  return [newGoal]

syntax (name := monomorphize) "monomorphize " ident : tactic

@[tactic monomorphize] def evalMonomorphize : Tactic
| `(tactic| monomorphize $id:ident) =>
    liftMetaTactic fun g => monomorphizeCore g id
| _ => throwUnsupportedSyntax

example (m n : Nat) : m + n = n + m := by
  monomorphize add_comm
  exact add_comm' m n

example (R : Type*) [CommRing R] (x : R) (m n : Nat) : x^(m + n) = x^m * x^n := by
  monomorphize pow_add
  exact pow_add' x m n

example (a b : Nat) : a + b = b + a := by
  monomorphize HAdd.hAdd
  sorry

example : Nat := by
  monomorphize default
  sorry

example (a b : Nat) (c d : ℤ) : ↑(a + b) = c + d := by
  monomorphize add_comm
  sorry
