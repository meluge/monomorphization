#!/usr/bin/env python3
"""Summarize harness results: per-mode solved counts, union, and timing stats."""

import argparse
import json
from collections import defaultdict


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("results", nargs="+")
    args = ap.parse_args()

    recs = []
    for path in args.results:
        with open(path) as f:
            recs.extend(json.loads(line) for line in f)

    by_mode = defaultdict(dict)   # mode -> name -> rec
    for r in recs:
        # Heartbeat exhaustion escaping as a raw Lean error is a budget timeout.
        if r["status"] == "error" and "(deterministic) timeout" in (r["err"] or ""):
            r["status"] = "timeout"
        by_mode[r["mode"]][r["name"]] = r
    modes = sorted(by_mode)
    names = sorted({r["name"] for r in recs})

    print(f"{len(names)} problems, modes: {', '.join(modes)}\n")
    header = f"{'mode':10} {'ok':>5} {'fail':>5} {'t/o':>5} {'crash':>5} {'error':>5} {'ok med ms':>10} {'mono med ms':>12}"
    print(header)
    print("-" * len(header))
    for mode in modes:
        rs = by_mode[mode].values()
        cnt = defaultdict(int)
        ok_times, mono_times = [], []
        for r in rs:
            cnt[r["status"]] += 1
            if r["status"] == "ok":
                ok_times.append(r["wall_ms"])
            for ph in r.get("phases") or []:
                if ph["name"] == "monomorphize":
                    mono_times.append(ph["ms"])
        med = lambda xs: sorted(xs)[len(xs) // 2] if xs else "-"
        print(f"{mode:10} {cnt['ok']:>5} {cnt['fail']:>5} {cnt['timeout']:>5} "
              f"{cnt['crash']:>5} {cnt['error']:>5} {str(med(ok_times)):>10} {str(med(mono_times)):>12}")

    solved = {m: {n for n, r in by_mode[m].items() if r["status"] == "ok"} for m in modes}
    union = set().union(*solved.values()) if solved else set()
    print(f"\nunion solved: {len(union)}")
    for m in modes:
        uniq = solved[m] - set().union(*(solved[o] for o in modes if o != m)) if len(modes) > 1 else solved[m]
        print(f"  solved only by {m}: {len(uniq)}  {sorted(uniq)[:8]}")


if __name__ == "__main__":
    main()
