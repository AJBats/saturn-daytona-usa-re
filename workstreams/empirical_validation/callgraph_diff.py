#!/usr/bin/env python3
"""Cross-reference call graphs to find common core vs state-unique edges.

Reads all call_graphs/<state>/<label>.txt files, extracts edges,
and produces a summary showing:
  1. Common core — edges in every scenario
  2. Per-state unique — edges only in one state
  3. Per-button delta — edges that appear with button but not idle

Usage:
    python tools/callgraph_diff.py
"""

import os
import re
import sys
from collections import defaultdict

PROJECT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CALLGRAPH_DIR = os.path.join(PROJECT, "call_graphs")
OUT_PATH = os.path.join(CALLGRAPH_DIR, "cross_reference.txt")


def parse_edges(path):
    """Parse edge list from a call graph txt file. Returns set of (caller, callee)."""
    edges = set()
    in_edges = False
    with open(path) as f:
        for line in f:
            line = line.strip()
            if line.startswith("EDGES ("):
                in_edges = True
                continue
            if in_edges and line:
                # "caller -> callee" or "caller -> callee  (xN)"
                m = re.match(r'(\S+)\s+->\s+(\S+)', line)
                if m:
                    edges.add((m.group(1), m.group(2)))
    return edges


def main():
    # Collect all scenarios
    scenarios = {}   # label -> set of edges
    by_state = defaultdict(dict)  # state -> {label: edges}

    for state_dir in sorted(os.listdir(CALLGRAPH_DIR)):
        state_path = os.path.join(CALLGRAPH_DIR, state_dir)
        if not os.path.isdir(state_path):
            continue
        for fname in sorted(os.listdir(state_path)):
            if not fname.endswith(".txt"):
                continue
            label = fname[:-4]
            edges = parse_edges(os.path.join(state_path, fname))
            scenarios[label] = edges
            by_state[state_dir][label] = edges

    if not scenarios:
        print("No call graphs found.")
        return

    all_edges = set()
    for e in scenarios.values():
        all_edges |= e

    lines = []
    def out(s=""):
        lines.append(s)
        print(s)

    out(f"CALL GRAPH CROSS-REFERENCE")
    out(f"{len(scenarios)} scenarios, {len(all_edges)} unique edges across all")
    out()

    # 1. Common core — in every scenario
    common = set.intersection(*scenarios.values())
    out(f"{'=' * 60}")
    out(f"COMMON CORE ({len(common)} edges — present in all {len(scenarios)} scenarios)")
    out(f"{'=' * 60}")
    for caller, callee in sorted(common):
        out(f"  {caller} -> {callee}")
    out()

    # 2. Per-state analysis
    states = sorted(by_state.keys())
    state_all = {}  # state -> union of all edges in that state
    for state in states:
        state_all[state] = set()
        for edges in by_state[state].values():
            state_all[state] |= edges

    # Edges unique to each state (not in any other state)
    out(f"{'=' * 60}")
    out(f"STATE-UNIQUE EDGES (only appear in one game state)")
    out(f"{'=' * 60}")
    for state in states:
        other_states = set()
        for s in states:
            if s != state:
                other_states |= state_all[s]
        unique = state_all[state] - other_states
        if unique:
            out(f"\n  {state.upper()} only ({len(unique)} edges):")
            for caller, callee in sorted(unique):
                out(f"    {caller} -> {callee}")
    out()

    # 3. Per-button delta (button vs idle for each state)
    out(f"{'=' * 60}")
    out(f"BUTTON DELTAS (edges in button press but not idle)")
    out(f"{'=' * 60}")
    for state in states:
        idle_label = f"{state}_idle"
        if idle_label not in scenarios:
            continue
        idle_edges = scenarios[idle_label]
        for label, edges in sorted(by_state[state].items()):
            if label == idle_label:
                continue
            new = edges - idle_edges
            gone = idle_edges - edges
            if new or gone:
                out(f"\n  {label}:")
                if new:
                    out(f"    + new ({len(new)}):")
                    for caller, callee in sorted(new):
                        out(f"      {caller} -> {callee}")
                if gone:
                    out(f"    - gone ({len(gone)}):")
                    for caller, callee in sorted(gone):
                        out(f"      {caller} -> {callee}")
    out()

    # 4. Function reach — which functions appear in which states
    out(f"{'=' * 60}")
    out(f"FUNCTION REACH (which states call each function)")
    out(f"{'=' * 60}")
    func_states = defaultdict(set)
    for state in states:
        for caller, callee in state_all[state]:
            func_states[caller].add(state)
            func_states[callee].add(state)

    # Only show functions that DON'T appear everywhere
    all_states = set(states)
    selective = {f: s for f, s in func_states.items() if s != all_states}
    for func in sorted(selective.keys()):
        present = sorted(selective[func])
        out(f"  {func:40s} {', '.join(present)}")

    # Write to file
    with open(OUT_PATH, "w") as f:
        f.write("\n".join(lines))
        f.write("\n")
    print(f"\nSaved: {OUT_PATH}")


if __name__ == "__main__":
    main()
