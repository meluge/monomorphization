import Lean
open Lean

/-- Components that indicate an auto-generated declaration. -/
def isBadComponent (s : String) : Bool :=
  s.startsWith "_" || s.startsWith "proof_" || s.startsWith "match_" ||
  s.startsWith "unsafe_" || s == "eq_def" || s == "injEq" || s == "sizeOf_spec" ||
  s.startsWith "noConfusion" || s.startsWith "below" || s.startsWith "brecOn" ||
  s.startsWith "binductionOn" || s.startsWith "ibelow" || s.startsWith "casesOn" ||
  s.startsWith "recOn" || (s.startsWith "eq_" && (s.drop 3).isNat)

def isBadName (n : Name) : Bool :=
  n.hasMacroScopes ||
  n.components.any fun c =>
    match c with
    | .str _ s => isBadComponent s
    | .num _ _ => true
    | _ => true

/-- Number of instance-implicit binders in the type's outer telescope. -/
partial def numInstBinders : Expr → Nat
  | .forallE _ _ b bi => (if bi == .instImplicit then 1 else 0) + numInstBinders b
  | _ => 0

def moduleOf (env : Environment) (n : Name) : Option Name := do
  let idx ← env.getModuleIdxFor? n
  env.header.moduleNames[idx.toNat]?

def main : IO Unit := do
  initSearchPath (← findSysroot)
  let env ← importModules #[{module := `Mathlib}] {}
  IO.FS.createDirAll "bench"
  let h ← IO.FS.Handle.mk "bench/problems_raw.jsonl" .write
  let mut nOut := 0
  for (name, ci) in env.constants.toList do
    let .thmInfo tv := ci | continue
    if isBadName name then continue
    let some mod := moduleOf env name | continue
    unless (`Mathlib).isPrefixOf mod do continue
    if mod == `Mathlib.Deprecated || (`Mathlib.Deprecated).isPrefixOf mod then continue
    let usedConsts := tv.value.getUsedConstantsAsSet
    if usedConsts.contains ``sorryAx then continue
    -- premises: human-named theorems used by the proof
    let mut deps : Array Name := #[]
    let mut dropped := 0
    let mut clsDeps := 0
    for c in usedConsts do
      match env.find? c with
      | some (.thmInfo dtv) =>
        if isBadName c then
          dropped := dropped + 1
        else
          deps := deps.push c
          if numInstBinders dtv.type > 0 then clsDeps := clsDeps + 1
      | _ => pure ()
    let j := Json.mkObj [
      ("name", Json.str name.toString),
      ("module", Json.str mod.toString),
      ("numDeps", Json.num deps.size),
      ("clsDeps", Json.num clsDeps),
      ("clsGoal", Json.bool (numInstBinders tv.type > 0)),
      ("droppedDeps", Json.num dropped),
      ("deps", Json.arr (deps.map (Json.str ∘ Name.toString)))
    ]
    h.putStrLn j.compress
    nOut := nOut + 1
  IO.println s!"wrote {nOut} problems to bench/problems_raw.jsonl"
