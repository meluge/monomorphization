import Lean
import Canonical
import Monomorphization.Basic

/-!
Benchmark driver command.

`#bench <mode> <timeout> <thm> [<dep>,*]` reconstructs the statement of `thm`
as a fresh goal (universe params instantiated with fresh level mvars) and runs
the tactic arm selected by `mode`:

- `base`:   `canonical <timeout> [deps]`
- `mono`:   `monomorphize [deps]; canonical <timeout>`
- `mononc`: `monomorphize -canonicalize [deps]; canonical <timeout>`

It logs a single machine-readable info line
`BENCH_RESULT {"ok": …, "phases": [{"name": …, "ms": …}, …], "err": …}`.
Success of the `canonical` phase means Canonical found a proof term (it also
logs its usual "Try this: exact …" suggestion, which harnesses can record).
-/

open Lean Elab Meta

namespace Bench

/-- Disable the heartbeat limit for `x`. `withOptions maxHeartbeats.set` is not
enough: the limit is captured in `Core.Context` before this command runs. -/
def withNoHeartbeats [MonadWithReaderOf Core.Context m] (x : m α) : m α :=
  withTheReader Core.Context (fun ctx => { ctx with maxHeartbeats := 0 }) x

/-- Run one tactic phase on a goal, returning remaining goals. -/
def runPhase (goal : MVarId) (tac : Syntax) : TermElabM (List MVarId) := do
  let (gs, _) ← Elab.runTactic goal tac
  return gs

syntax (name := benchCmd) "#bench " ident num ident " [" ident,* "]" : command

open Command in
@[command_elab benchCmd] def elabBench : CommandElab
  | `(#bench $mode $t:num $thm [$ids:ident,*]) => do
    liftTermElabM <| withNoHeartbeats do
     try
      let thmName ← realizeGlobalConstNoOverload thm
      let ci ← getConstInfo thmName
      let us ← ci.levelParams.mapM fun _ => mkFreshLevelMVar
      let type := ci.type.instantiateLevelParams ci.levelParams us
      let goal ← mkFreshExprMVar type
      let phases : Array (String × Syntax) ← do
        match mode.getId with
        | `base => pure #[("canonical", ← `(tactic| canonical $t:num [$ids,*]))]
        | `mono => pure #[
            ("monomorphize", ← `(tactic| monomorphize [$ids,*])),
            ("canonical", ← `(tactic| canonical $t:num))]
        | `mononc => pure #[
            ("monomorphize", ← `(tactic| monomorphize -canonicalize [$ids,*])),
            ("canonical", ← `(tactic| canonical $t:num))]
        | `monop => pure #[
            ("monomorphize", ← `(tactic| monomorphize [$ids,*])),
            ("canonical", ← `(tactic| canonical $t:num [$ids,*]))]
        | m => throwError "unknown bench mode {m}"
      let mut gs := [goal.mvarId!]
      let mut times : Array Json := #[]
      let mut ok := true
      let mut err : String := ""
      for (phaseName, tac) in phases do
        let some g := gs.head? | break
        let t0 ← IO.monoMsNow
        try
          gs ← runPhase g tac
          let t1 ← IO.monoMsNow
          times := times.push (Json.mkObj [("name", Json.str phaseName), ("ms", Json.num (t1 - t0))])
        catch e =>
          let t1 ← IO.monoMsNow
          times := times.push (Json.mkObj [("name", Json.str phaseName), ("ms", Json.num (t1 - t0))])
          ok := false
          err := s!"{phaseName}: {← e.toMessageData.toString}"
          break
      let j := Json.mkObj [("ok", Json.bool ok), ("phases", Json.arr times), ("err", Json.str err)]
      logInfo m!"BENCH_RESULT {j.compress}"
     catch e =>
      let j := Json.mkObj [("ok", Json.bool false), ("phases", Json.arr #[]),
        ("err", Json.str s!"setup: {← e.toMessageData.toString}")]
      logInfo m!"BENCH_RESULT {j.compress}"
  | _ => throwUnsupportedSyntax

/-- `#bench_verify <thm> => <term>` re-elaborates a recorded suggestion against
the statement of `thm` and kernel-checks it. Logs `VERIFY_OK` or `VERIFY_FAIL …`. -/
syntax (name := benchVerifyCmd) "#bench_verify " ident " => " term : command

open Command in
@[command_elab benchVerifyCmd] def elabBenchVerify : CommandElab
  | `(#bench_verify $thm => $prf) => do
    liftTermElabM <| withNoHeartbeats do
      try
        let thmName ← realizeGlobalConstNoOverload thm
        let ci ← getConstInfo thmName
        let us ← ci.levelParams.mapM fun _ => mkFreshLevelMVar
        let type := ci.type.instantiateLevelParams ci.levelParams us
        let e ← Elab.Term.elabTermEnsuringType prf type
        Elab.Term.synthesizeSyntheticMVarsNoPostponing
        let e ← instantiateMVars e
        if e.hasSorry || e.hasExprMVar then
          logInfo m!"VERIFY_FAIL contains sorry or metavariables"
        else
          -- kernel check via addDecl of an auxiliary theorem
          let e ← instantiateMVars e
          let type ← instantiateMVars type
          addDecl <| .thmDecl {
            name := `benchVerifyAux ++ thmName
            levelParams := []
            type := type
            value := e
          }
          logInfo m!"VERIFY_OK"
      catch ex =>
        logInfo m!"VERIFY_FAIL {← ex.toMessageData.toString}"
  | _ => throwUnsupportedSyntax

end Bench
