import Lean
import Mathlib.Tactic.Ring
import Mathlib.Data.Real.Basic
import Mathlib.Data.ZMod.Basic
import Mathlib.Data.List.Basic
import Mathlib.Algebra.Group.Defs

open Lean Meta Elab Tactic Expr

partial def getBinders (e : Expr) : MetaM (List BinderInfo) := do
  match e with
  | forallE _ _ b i        => return i :: (← getBinders b)
  | mdata _ b | lam _ _ b _ | app _ b | letE _ _ _ b _ => getBinders b
  | _                      => return []

partial def getInstanceTypes (e : Expr) : MetaM (List Expr) := do
  match e with
  | app _ _ =>
      let (fn, args) := Expr.getAppFnArgs e
      if let some info := (← getEnv).find? fn then
        let bs ← getBinders info.type
        let insts ← (bs.indexesOf .instImplicit).filterMapM fun i => do
          let a := args[i]!
          if a.hasLooseBVars then pure none else some <$> inferType a
        args.foldlM (fun acc a => return acc ++ (← getInstanceTypes a)) insts
      else
        return []
  | mdata _ b | lam _ _ b _ | letE _ _ _ b _ => getInstanceTypes b
  | _ => return []

def unifyWithOne (t : Expr) (gs : List Expr) : MetaM Bool := do
  for g in gs do
    let saved ← getMCtx
    let success ← try
      isDefEq t g
    catch _ =>
      setMCtx saved
      return false
    if success then return true
  return false

def monomorphizeCore (goal : MVarId) (id : Syntax) :
    MetaM (List MVarId) := goal.withContext do
  let constName ← resolveGlobalConstNoOverload id
  let constInfo ← getConstInfo constName
  let goalType ← goal.getType

  let levels ← constInfo.levelParams.mapM (fun _ => mkFreshLevelMVar)
  let baseExpr := Expr.const constName levels

  let typeInstantiated := constInfo.type.instantiateLevelParams constInfo.levelParams levels

  let goalInsts ← getInstanceTypes goalType
  let (mvars, binders, body) ← forallMetaTelescopeReducing typeInstantiated

  for t in ← getInstanceTypes body do
    if t.hasMVar then
      discard (unifyWithOne t goalInsts)

  for pair in mvars.zip binders do
    let mvar  := pair.1
    let binfo := pair.2
    if binfo.isInstImplicit then
      let mty ← instantiateMVars (← mvar.mvarId!.getType)
      try
        let inst ← synthInstance mty
        mvar.mvarId!.assign inst
      catch _ => pure ()

  let mut specialised := baseExpr
  for i in [:mvars.size] do
    let mvar := mvars[i]!
    let isAssigned ← mvar.mvarId!.isAssigned
    if isAssigned then
      let val ← instantiateMVars mvar
      specialised := mkApp specialised val
    else
      break

  let newName := constName.modifyBase fun s => Name.mkSimple (toString s ++ "'")
  let (_, newGoal) ← goal.let newName specialised
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


example (n : Nat) : n = default := by
  monomorphize Inhabited.default
  sorry

example (xs : List Nat) (ys : List Bool) : xs.length + ys.length = ys.length + xs.length := by
  monomorphize add_comm
  exact add_comm' xs.length ys.length

theorem card_positive {α : Type*} [Fintype α] [Nonempty α] :
  Fintype.card α > 0 := by
  sorry

example : Fintype.card Bool > 0 := by
  monomorphize card_positive
  exact card_positive'
