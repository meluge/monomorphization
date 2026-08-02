# Monomorphization benchmark harness

Evaluation infrastructure for the paper "Monomorphization with Typeclass Instances".
Methodology mirrors Bozec & Blanchette, *Iterative Monomorphisation* (seeded samples,
solved-within-budget metric, tuning/held-out split, preprocessing-vs-native arms).

## Layout

- `../Extract.lean` (+ `lean_exe extract`): dumps every human-named Mathlib theorem with
  its proof-dependency premises and typeclass metadata → `problems_raw.jsonl` (202,227
  problems). Fields: `name, module, deps, numDeps, clsDeps` (premises with instance
  binders), `clsGoal` (goal has instance binders = polymorphic goal), `droppedDeps`.
- `../Monomorphization/Bench.lean`: `#bench <mode> <timeout> <thm> [deps,*]` command.
  Modes: `base` (`canonical T [deps]`), `mono` (`monomorphize [deps]; canonical T`),
  `monop` (`monomorphize [deps]; canonical T [deps]` — premises passed to both),
  `mononc` (`-canonicalize` variant). Emits one `BENCH_RESULT {ok, phases, err}` line.
  `#bench_verify <thm> => <term>` kernel-checks a recorded suggestion (VERIFY_OK/FAIL).
- `harness.py`: REPL worker pool, crash/timeout recovery, seeded sampling, JSONL out.
- `summarize.py`: per-mode ok/fail/timeout/crash table + union/unique solves.
- `../../duperbench/`: sibling Lake project for the Duper/lean-auto comparison
  (same mathlib rev; see its README for one-time patch setup). Its `#bench` modes:
  `duper_nopre`, `duper_monolean` (lean-auto monomorphization), `duper_full` (lean-auto
  full preprocessing), `duper_ourmono`, `duper_ourfull` (our monomorphize + duper).

## Setup (this repo)

```sh
lake exe cache get          # mathlib oleans
lake build Monomorphization repl extract
lake env .lake/build/bin/extract        # regenerates bench/problems_raw.jsonl
```

Gotchas:
- Repo was developed on case-insensitive macOS. `Monomorphization/Basic.lean` is a
  symlink to `../monomorphization/Basic.lean` (lowercase dir) — keep it.
- The v4.21 REPL binary ignores argv (`--load-dynlib` is a no-op). The harness injects
  Canonical's native libs via LD_PRELOAD (`--preload canonical`, the default).
- Canonical's success protocol is admit+"Try this" suggestion; `#bench` counts ok when
  the tactic did not throw. Suggestions are recorded in results for later verification.
- Canonical's internal timeout only bounds its Rust search; its Lean-side translation
  can hang (→ status `timeout`, wall watchdog) or stack-overflow (→ status `crash`).

## Running experiments

```sh
# Experiment 1 (Canonical arms), polymorphic-heavy population:
python3 harness.py --sample 300 --workers 2 --modes base,mono,monop \
  --out results/exp1.jsonl

# Experiment 1b/1c primary populations:
#   --concrete-goal            : goals without instance binders (tool's target case)
#   --module-prefix P1,P2,...  : elementary-modules restriction
#   --skip 300                 : held-out split (same seed)

# Experiment 2 (Duper arms) — run from anywhere, pointing at duperbench:
python3 harness.py --sample 300 --workers 2 \
  --modes duper_nopre,duper_monolean,duper_full,duper_ourmono \
  --repo ../../duperbench --imports Mathlib,Duper,DuperBench \
  --preload "<leanshared>:<libBatteries>:<libAuto>:<libDuper>" \
  --out results/exp2.jsonl
# preload chain (order matters):
#   $LEAN_SYSROOT/lib/lean/libleanshared.so
#   duperbench/.lake/packages/batteries/.lake/build/lib/libBatteries.so
#   duperbench/.lake/packages/auto/.lake/build/lib/libAuto.so
#   duperbench/.lake/packages/Duper/.lake/build/lib/libDuper.so

python3 summarize.py results/exp1.jsonl [more.jsonl ...]
```

Scale `--workers` to RAM: each worker is a REPL with Mathlib ≈ 2.5–3 GB.

## Results so far (2026-08-02, seed 42, 10 s budget, solved/300)

| pipeline                    | polymorphic goals | concrete goals |
|-----------------------------|-------------------|----------------|
| canonical                   | 21                | 4              |
| canonical + our mono (monop)| 18                | 11             |
| duper (no preprocessing)    | 29                | 22             |
| duper + our mono            | 21                | 25             |
| duper + lean-auto mono      | 69                | 78             |
| duper + lean-auto full      | 74                | 82             |

Held-out (concrete, partial): base 0 vs monop 4 — direction confirmed, rates noisy.
Thesis all cells support: monomorphization helps exactly where the goal offers concrete
types to specialise. `bug_unknown_fvar.json`: 19 repros of a real `monomorphize` bug.
