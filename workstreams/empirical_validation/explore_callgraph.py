#!/usr/bin/env python3
"""Call graph explorer — call_trace per scenario.

Captures one frame of call_trace for each scenario (game state + button input).
Builds ASCII call trees from the edges. Fast and complete — captures every
JSR/BSR in the frame.

Screenshots taken at start of each scenario for human verification.

Usage:
    python tools/explore_callgraph.py                  # run all scenarios
    python tools/explore_callgraph.py menu_idle         # run one scenario
    python tools/explore_callgraph.py --list            # list scenarios
"""

import os
import sys
import argparse

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from debugger_utils import DebugSession

# Output directory — committed artifacts
CALLGRAPH_DIR = os.path.join(PROJECT, "call_graphs")

# Scenario manifest: (label, state, button_or_None)
SCENARIOS = [
    # Attract mode
    ("attract_idle",     "attract", None),
    ("attract_START",    "attract", "START"),
    # Title screen
    ("title_idle",       "title",   None),
    ("title_START",      "title",   "START"),
    # Main menu (mode select)
    ("menu_idle",        "menu",    None),
    ("menu_DOWN",        "menu",    "DOWN"),
    ("menu_UP",          "menu",    "UP"),
    ("menu_C",           "menu",    "C"),
    # Course select
    ("circuit_idle",     "circuit", None),
    ("circuit_LEFT",     "circuit", "LEFT"),
    ("circuit_RIGHT",    "circuit", "RIGHT"),
    ("circuit_C",        "circuit", "C"),
    ("circuit_B",        "circuit", "B"),
    # Car / transmission select
    ("car_idle",         "car",     None),
    ("car_LEFT",         "car",     "LEFT"),
    ("car_RIGHT",        "car",     "RIGHT"),
    ("car_C",            "car",     "C"),
    ("car_B",            "car",     "B"),
]


def build_tree(edges):
    """Build adjacency list from edge tuples.

    edges: list of (caller, callee) tuples.
    Returns (roots, children_dict) where roots is a list of root nodes
    (callers that aren't callees of anyone).
    """
    from collections import OrderedDict
    children = OrderedDict()
    all_callees = set()
    all_callers = set()
    for caller, callee in edges:
        if caller not in children:
            children[caller] = []
        if callee not in children[caller]:
            children[caller].append(callee)
        all_callers.add(caller)
        all_callees.add(callee)
    # Roots: callers that nobody calls (within this trace)
    roots = [c for c, _ in edges if c in (all_callers - all_callees)]
    # Deduplicate while preserving order
    seen = set()
    unique_roots = []
    for r in roots:
        if r not in seen:
            seen.add(r)
            unique_roots.append(r)
    return unique_roots, children


def format_tree(roots, children):
    """Format ASCII tree with multiple roots."""
    lines = []

    def _walk(node, prefix, is_last, visited):
        if node in visited:
            connector = "`-- " if is_last else "|-- "
            lines.append(f"{prefix}{connector}{node} (recursive)")
            return
        visited.add(node)
        if not prefix:
            lines.append(node)
        else:
            connector = "`-- " if is_last else "|-- "
            lines.append(f"{prefix}{connector}{node}")
        kids = children.get(node, [])
        for i, child in enumerate(kids):
            last = (i == len(kids) - 1)
            child_prefix = prefix + ("    " if is_last or not prefix else "|   ")
            _walk(child, child_prefix, last, visited.copy())

    for i, root in enumerate(roots):
        if i > 0:
            lines.append("")
        _walk(root, "", True, set())
    return "\n".join(lines)


def run_scenario(label, state, button):
    """Run one call_trace scenario. Returns True on success."""
    scenario_dir = os.path.join(CALLGRAPH_DIR, state)
    os.makedirs(scenario_dir, exist_ok=True)

    out_path = os.path.join(scenario_dir, f"{label}.txt")
    ss_path = os.path.join(scenario_dir, f"{label}.png")

    print(f"\n{'=' * 60}")
    print(f"SCENARIO: {label}  (state={state}, button={button or 'none'})")
    print(f"{'=' * 60}")

    s = DebugSession(state, verbose=True)

    # Screenshot the starting state for human verification
    s.bot.screenshot(ss_path)
    print(f"  Screenshot: {ss_path}")

    # For button presses: press and advance 1 frame so input is
    # processed by SMPC before we capture the trace.
    if button:
        s.bot.input_press(button)
        s.bot.frame_advance(1)
        print(f"  {button} pressed, frame advanced")

    # Capture one frame of call_trace
    print(f"  Capturing call_trace (1 frame)...")
    if button:
        s.bot.input_press(button)  # re-press for the trace frame
    trace = s.frame_calls(1, label=label)
    if button:
        s.bot.input_release(button)

    # Extract edges as ordered list (by first occurrence)
    edge_list = list(trace['edges'].keys())
    edge_counts = trace['edges']

    print(f"  {len(edge_list)} edges, {len(trace['functions'])} functions")

    with open(out_path, "w") as f:
        action_desc = f"{button} press" if button else "idle"
        f.write(f"CALL GRAPH: {state} {action_desc}\n")
        f.write(f"{len(edge_list)} edges, {len(trace['functions'])} functions\n\n")

        if edge_list:
            roots, children = build_tree(edge_list)
            tree_str = format_tree(roots, children)

            f.write(f"TREE:\n\n")
            f.write(tree_str)
            f.write(f"\n\n{'=' * 60}\n")
            f.write(f"EDGES ({len(edge_list)}):\n\n")
            for caller, callee in edge_list:
                count = edge_counts[(caller, callee)]
                f.write(f"  {caller} -> {callee}")
                if count > 1:
                    f.write(f"  (x{count})")
                f.write(f"\n")

            print(f"\n{tree_str}")
        else:
            f.write("No calls captured.\n")
            print("  No calls captured.")

    s.quit()
    print(f"  Saved: {out_path}")
    return True


def main():
    parser = argparse.ArgumentParser(description="Call graph explorer")
    parser.add_argument("scenarios", nargs="*",
                        help="Scenario labels to run (default: all)")
    parser.add_argument("--list", action="store_true",
                        help="List available scenarios")
    args = parser.parse_args()

    if args.list:
        for label, state, button in SCENARIOS:
            action = button or "idle"
            print(f"  {label:20s}  state={state:8s}  action={action}")
        return

    os.makedirs(CALLGRAPH_DIR, exist_ok=True)

    if args.scenarios:
        to_run = [(l, s, b) for l, s, b in SCENARIOS if l in args.scenarios]
        unknown = set(args.scenarios) - {l for l, _, _ in SCENARIOS}
        if unknown:
            print(f"Unknown scenarios: {', '.join(unknown)}")
            print(f"Use --list to see available scenarios")
            return
    else:
        to_run = SCENARIOS

    print(f"Running {len(to_run)} scenario(s)...")

    results = []
    for label, state, button in to_run:
        try:
            ok = run_scenario(label, state, button)
            results.append((label, "OK" if ok else "FAIL"))
        except Exception as e:
            print(f"  ERROR: {e}")
            results.append((label, f"ERROR: {e}"))

    print(f"\n{'=' * 60}")
    print(f"RESULTS:")
    print(f"{'=' * 60}")
    for label, status in results:
        print(f"  {label:20s}  {status}")


if __name__ == "__main__":
    main()
