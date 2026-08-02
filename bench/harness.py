#!/usr/bin/env python3
"""Benchmark harness for the monomorphize/Canonical evaluation.

Reads problems from a JSONL file (produced by `lake env .lake/build/bin/extract`),
samples a seeded subset, and runs each problem under one or more tactic modes
via the Lean REPL:

  base    canonical T [deps]
  mono    monomorphize [deps]; canonical T
  mononc  monomorphize -canonicalize [deps]; canonical T

Each (problem, mode) run is recorded as one JSON line in the output file:
  {"name", "mode", "status", "phases", "err", "suggestion", "wall_ms"}
status is one of: ok | fail | timeout | crash | error
(`timeout` = wall-clock watchdog fired, REPL killed; `crash` = REPL died,
e.g. stack overflow; `error` = REPL reported a non-bench error, e.g. an
unresolvable premise name).

Workers are separate REPL processes; a worker is restarted after a crash,
a timeout, or RECYCLE_AFTER problems (to bound memory growth).
"""

import argparse
import json
import os
import queue
import random
import subprocess
import sys
import threading
import time

DEFAULT_REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
RECYCLE_AFTER = 40
IMPORT_TIMEOUT = 300

# Set by main() from CLI args.
REPO = DEFAULT_REPO
REPL_BIN = None
IMPORTS = None
PRELOAD = None

# Proof-plumbing constants that appear in (mostly simp-generated) proof terms;
# they are not human-meaningful premises, so drop them by default.
PLUMBING = {
    "congrArg", "congrFun", "congr", "Eq.trans", "Eq.symm", "Eq.mpr", "Eq.mp",
    "of_eq_true", "of_eq_false", "eq_true", "eq_false", "iff_self", "eq_self",
    "ne_eq", "funext", "propext", "Iff.rfl", "Iff.trans", "Iff.symm",
    "letFun_val", "implies_congr", "forall_congr", "trans",
}


def lake_env(repo):
    """Environment variables as set by `lake env` (LEAN_PATH etc.)."""
    out = subprocess.run(["lake", "env", "env"], cwd=repo, capture_output=True, text=True, check=True)
    env = dict(os.environ)
    for line in out.stdout.splitlines():
        if "=" in line:
            k, v = line.split("=", 1)
            env[k] = v
    if PRELOAD:
        env["LD_PRELOAD"] = PRELOAD
    return env


class ReplWorker:
    def __init__(self, wid, env):
        self.wid = wid
        self.env = env
        self.proc = None
        self.reader = None
        self.lines = None
        self.env_id = None
        self.jobs_done = 0

    def start(self):
        self.proc = subprocess.Popen(
            [REPL_BIN], stdin=subprocess.PIPE, stdout=subprocess.PIPE,
            stderr=subprocess.DEVNULL, text=True, bufsize=1, cwd=REPO, env=self.env,
        )
        self.lines = queue.Queue()
        self.reader = threading.Thread(target=self._read_loop, daemon=True)
        self.reader.start()
        self.jobs_done = 0
        r = self._send({"cmd": IMPORTS}, IMPORT_TIMEOUT)
        if r is None or "env" not in r:
            raise RuntimeError(f"worker {self.wid}: import failed: {r}")
        self.env_id = r["env"]

    def _read_loop(self):
        for line in self.proc.stdout:
            self.lines.put(line)
        self.lines.put(None)  # EOF

    def _send(self, cmd, timeout):
        self.proc.stdin.write(json.dumps(cmd, ensure_ascii=False) + "\n\n")
        self.proc.stdin.flush()
        buf, deadline = [], time.time() + timeout
        while True:
            try:
                line = self.lines.get(timeout=max(0.05, deadline - time.time()))
            except queue.Empty:
                return "TIMEOUT"
            if line is None:
                return None  # process died
            if line.strip() == "" and buf:
                break
            if line.strip() != "":
                buf.append(line)
        try:
            return json.loads("".join(buf))
        except json.JSONDecodeError:
            return None

    def kill(self):
        if self.proc is not None:
            self.proc.kill()
            self.proc.wait()
            self.proc = None

    def run_problem(self, prob, mode, tac_timeout, grace):
        deps = ", ".join(prob["deps"])
        cmd = f"#bench {mode} {tac_timeout} {prob['name']} [{deps}]"
        t0 = time.time()
        r = self._send({"cmd": cmd, "env": self.env_id}, tac_timeout + grace)
        wall_ms = int((time.time() - t0) * 1000)
        self.jobs_done += 1
        rec = {"name": prob["name"], "mode": mode, "wall_ms": wall_ms,
               "phases": None, "err": None, "suggestion": None}
        if r == "TIMEOUT":
            rec["status"] = "timeout"
            return rec, True
        if r is None:
            rec["status"] = "crash"
            return rec, True
        bench, suggestion, other_err = None, None, None
        for m in r.get("messages", []):
            data = m.get("data", "")
            if data.startswith("BENCH_RESULT "):
                bench = json.loads(data[len("BENCH_RESULT "):])
            elif data.startswith("Try this: "):
                suggestion = data[len("Try this: "):]
            elif m.get("severity") == "error":
                other_err = data
        if bench is None:
            rec["status"] = "error"
            rec["err"] = other_err or json.dumps(r)[:500]
            return rec, False
        rec["status"] = "ok" if bench["ok"] else "fail"
        rec["phases"] = bench["phases"]
        rec["err"] = bench["err"] or None
        rec["suggestion"] = suggestion
        needs_restart = self.jobs_done >= RECYCLE_AFTER
        return rec, needs_restart


def start_with_retry(w, attempts=4):
    """Start a worker, retrying slow/failed imports instead of dying."""
    for i in range(attempts):
        try:
            w.start()
            return True
        except Exception as e:
            print(f"worker {w.wid}: start attempt {i + 1} failed ({str(e)[:120]})", flush=True)
            w.kill()
            time.sleep(15 * (i + 1))
    return False


def worker_loop(wid, env, tasks, results, tac_timeout, grace):
    w = ReplWorker(wid, env)
    if not start_with_retry(w):
        print(f"worker {wid}: giving up after repeated import failures", flush=True)
        return
    while True:
        try:
            item = tasks.get_nowait()
        except queue.Empty:
            break
        prob, mode = item
        try:
            rec, restart = w.run_problem(prob, mode, tac_timeout, grace)
        except Exception as e:  # broken pipe etc.
            rec = {"name": prob["name"], "mode": mode, "status": "crash",
                   "wall_ms": None, "phases": None, "err": str(e)[:300], "suggestion": None}
            restart = True
        results.put(rec)
        if restart:
            w.kill()
            if not start_with_retry(w):
                print(f"worker {wid}: giving up after repeated import failures", flush=True)
                return
    w.kill()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--problems", default=os.path.join(DEFAULT_REPO, "bench/problems_raw.jsonl"))
    ap.add_argument("--out", required=True)
    ap.add_argument("--sample", type=int, default=100)
    ap.add_argument("--seed", type=int, default=42)
    ap.add_argument("--modes", default="base,mono")
    ap.add_argument("--timeout", type=int, default=10, help="canonical timeout (s)")
    ap.add_argument("--grace", type=int, default=45, help="extra wall-clock (s) before killing")
    ap.add_argument("--workers", type=int, default=3)
    ap.add_argument("--min-deps", type=int, default=1)
    ap.add_argument("--max-deps", type=int, default=16)
    ap.add_argument("--min-cls-deps", type=int, default=1)
    ap.add_argument("--concrete-goal", action="store_true",
                    help="restrict to problems whose goal has no instance binders (the tool's target scenario)")
    ap.add_argument("--module-prefix", default=None,
                    help="comma-separated module prefixes to restrict the population to")
    ap.add_argument("--skip", type=int, default=0, help="skip first N sampled problems (for splits)")
    ap.add_argument("--keep-plumbing", action="store_true",
                    help="keep proof-plumbing premises (congrArg, Eq.trans, ...)")
    ap.add_argument("--repo", default=DEFAULT_REPO, help="Lake project to run the REPL in")
    ap.add_argument("--imports", default="Mathlib,Canonical,Monomorphization",
                    help="comma-separated modules to import in each worker")
    ap.add_argument("--preload", default="canonical",
                    help="'canonical' (default), 'none', or colon-separated .so paths for LD_PRELOAD")
    args = ap.parse_args()

    global REPO, REPL_BIN, IMPORTS, PRELOAD
    REPO = os.path.abspath(args.repo)
    REPL_BIN = os.path.join(REPO, ".lake/packages/REPL/.lake/build/bin/repl")
    IMPORTS = "\n".join(f"import {m}" for m in args.imports.split(","))
    if args.preload == "canonical":
        lib = os.path.join(REPO, ".lake/packages/Canonical/.lake/build/lib")
        PRELOAD = f"{lib}/libcanonical_lean.so:{lib}/libCanonical.so"
    elif args.preload == "none":
        PRELOAD = None
    else:
        PRELOAD = args.preload

    pop = []
    with open(args.problems) as f:
        for line in f:
            p = json.loads(line)
            if not args.keep_plumbing:
                p["deps"] = [d for d in p["deps"] if d not in PLUMBING]
                p["numDeps"] = len(p["deps"])
            if args.concrete_goal and p["clsGoal"]:
                continue
            if args.module_prefix and not p["module"].startswith(tuple(args.module_prefix.split(","))):
                continue
            if args.min_deps <= p["numDeps"] <= args.max_deps and p["clsDeps"] >= args.min_cls_deps:
                pop.append(p)
    print(f"population: {len(pop)} problems after filtering", flush=True)

    rng = random.Random(args.seed)
    rng.shuffle(pop)
    sample = pop[args.skip:args.skip + args.sample]
    modes = args.modes.split(",")

    tasks = queue.Queue()
    for prob in sample:
        for mode in modes:
            tasks.put((prob, mode))
    total = tasks.qsize()

    env = lake_env(REPO)
    results = queue.Queue()
    threads = [threading.Thread(target=worker_loop, args=(i, env, tasks, results, args.timeout, args.grace))
               for i in range(args.workers)]
    for t in threads:
        t.start()

    os.makedirs(os.path.dirname(os.path.abspath(args.out)), exist_ok=True)
    done, counts = 0, {}
    with open(args.out, "w") as out:
        while done < total:
            if not any(t.is_alive() for t in threads) and results.empty():
                print("all workers exited early!", flush=True)
                break
            try:
                rec = results.get(timeout=1.0)
            except queue.Empty:
                continue
            out.write(json.dumps(rec) + "\n")
            out.flush()
            done += 1
            counts[rec["status"]] = counts.get(rec["status"], 0) + 1
            if done % 10 == 0 or done == total:
                print(f"[{done}/{total}] {counts}", flush=True)
    for t in threads:
        t.join()
    print("done:", counts, flush=True)


if __name__ == "__main__":
    main()
