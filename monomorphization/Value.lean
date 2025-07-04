import Lean
import Mathlib.Data.Real.Basic
open Lean Elab Tactic Expr Std
open Meta hiding transform


def canUnfold (_cfg : Config) (info : ConstantInfo) : CoreM Bool := do
  dbg_trace info.name
  pure (!isGlobalInstance (← getEnv) info.name)

variable [MonadControlT MetaM n] [Monad n]
@[inline] def unfoldNonInstance (e : n α) : n α :=
  withTransparency .all (withCanUnfoldPred canUnfold e)

partial def skeleton (e : Expr) : MetaM Expr := do
  withApp e fun fn args => do
    -- special case for OfNat Real _proof_1 decls
    if let some name := fn.constName? then
      let env ← getEnv
      if !isGlobalInstance env name then
        if let some value := (env.find? name).get!.value? then
          return ← skeleton (← whnfR (mkAppN value args))

    let (metas, binders, _) ← forallMetaTelescopeReducing (← inferType fn)
    for i in [0:binders.size] do
      if binders[i]!.isInstImplicit then
        if let some arg := args[i]? then
          let _ ← isDefEq metas[i]! (← skeleton arg)
    instantiateMVars (mkAppN fn metas)


def test : ℝ := 10

#eval (do
  let e := ((← getEnv).find? `test).get!.value!
  withApp e fun fn args => do
    dbg_trace (← ppExpr (← inferType (← skeleton args[2]!)))
    -- let name := args[3]!.constName!
    -- let info := ((← getEnv).find? args[3]!.constName!).get!
    -- dbg_trace (← isIrreducible name)
)
-- instOfNatNat ?_uniq.2187
#check instNatAtLeastTwo
#print test._proof_1
#check isGlobalInstance
