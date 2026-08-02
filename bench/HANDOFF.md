# Hands-off evaluation run — instructions for the operator/agent

You are continuing the evaluation for the paper "Monomorphization with Typeclass
Instances". Two sibling git repos must be present:

- `monomorphization/` — the `monomorphize` tactic + benchmark harness (`bench/README.md`
  documents everything, including results so far).
- `duperbench/` — the Duper/lean-auto comparison environment (its `README.md` has
  one-time patch/build steps).

## Phase 0 — setup (once)

1. Install elan; `elan toolchain install leanprover/lean4:v4.21.0`.
2. In `monomorphization/`: `lake exe cache get && lake build Monomorphization repl extract`.
3. In `duperbench/`: follow its README exactly (lake update → apply patches → cache get
   → `lake build DuperBench repl` → `lake build Batteries:shared`).
4. Smoke test both: from `monomorphization/bench`, run harness with `--sample 3` for
   modes `base,monop`, and for the duper modes with `--repo ../../duperbench` and the
   LD_PRELOAD chain from the READMEs. Expect BENCH_RESULT-backed ok/fail records, no
   `error` statuses about missing symbols.
5. Set WORKERS = floor(free_RAM_GB / 3), capped at CPU cores − 2.

All commands below run from `monomorphization/bench/`. Seed stays 42 everywhere.
ELEM_PREFIXES = "Mathlib.Data.Nat,Mathlib.Data.Int,Mathlib.Data.Rat,Mathlib.Data.Bool,Mathlib.Data.Fin.,Mathlib.Algebra.Order,Mathlib.Algebra.Group,Mathlib.Algebra.Ring,Mathlib.Order.,Mathlib.NumberTheory"

## Phase 1 — elementary population pilot (decision gate)

```
python3 harness.py --sample 60 --workers $W --modes base,monop --concrete-goal \
  --max-deps 8 --grace 25 --module-prefix $ELEM_PREFIXES \
  --out results/exp1c_elem_pilot.jsonl
```

Gate: if base solves ≥ 5/60 (~8%) and monop > base, proceed with the elementary
population as primary. If base ≈ 0, also try `--timeout 30` on the same 60 before
deciding; report findings and continue with whichever budget differentiates.

## Phase 2 — primary tables (elementary population)

```
# Exp1c: Canonical arms, tuning + held-out
python3 harness.py --sample 300 --workers $W --modes base,mono,monop --concrete-goal \
  --max-deps 8 --grace 25 --module-prefix $ELEM_PREFIXES --out results/exp1c_elem.jsonl
python3 harness.py --sample 300 --skip 300 --workers $W --modes base,monop \
  --concrete-goal --max-deps 8 --grace 25 --module-prefix $ELEM_PREFIXES \
  --out results/exp1c_elem_holdout.jsonl

# Exp2c: Duper arms, same population (LD_PRELOAD chain per READMEs)
python3 harness.py --sample 300 --workers $W \
  --modes duper_nopre,duper_monolean,duper_full,duper_ourmono --concrete-goal \
  --max-deps 8 --grace 25 --module-prefix $ELEM_PREFIXES \
  --repo ../../duperbench --imports Mathlib,Duper,DuperBench --preload "$PRELOAD" \
  --out results/exp2c_elem.jsonl
```

## Phase 3 — held-out completions for existing tables

```
# Exp2b held-out (duper arms, broad concrete population)
python3 harness.py --sample 300 --skip 300 --workers $W \
  --modes duper_nopre,duper_monolean,duper_full,duper_ourmono --concrete-goal \
  --grace 25 --repo ../../duperbench --imports Mathlib,Duper,DuperBench \
  --preload "$PRELOAD" --out results/exp2b_holdout.jsonl
# Exp1b held-out exists but was run under memory pressure (results/exp1b_holdout.jsonl,
# partial commit); rerun it fresh:
python3 harness.py --sample 300 --skip 300 --workers $W --modes base,monop \
  --concrete-goal --grace 25 --out results/exp1b_holdout.jsonl
```

## Phase 4 — verification pass

For every Canonical `ok` record with a non-null `suggestion`, replay
`#bench_verify <name> => <suggestion>` through the REPL (same imports/preload as the
run that produced it) and record VERIFY_OK/VERIFY_FAIL. Report the verified-solve
counts next to the raw ok counts; investigate any VERIFY_FAIL before trusting the
number. Duper `ok` records need no verification (real proof assignments).

## Phase 5 — timeout row (parameter table)

Rerun Exp1c tuning (base,monop) with `--timeout 30 --grace 45`. This is the analog of
the source paper's Table 5.

## Reporting

After each phase: run `python3 summarize.py` on the new results, append a dated entry
to `results/RUNLOG.md` (command, counts table, union/unique solves, anomalies), and
commit results. Anomalies worth flagging: error-status records that are not heartbeat
timeouts, mono-phase failure rate ≫ 10%, worker crash loops (same problem crashing
repeatedly is fine; different problems crashing on import is an environment problem).
Final deliverable: an updated results matrix over the three populations
(elementary / broad-concrete / polymorphic) with tuning + held-out columns, plus the
verified-solve counts.
