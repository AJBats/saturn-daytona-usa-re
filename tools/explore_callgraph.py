#!/usr/bin/env python3
"""DFS call graph explorer — rat race algorithm.

Steps through a function instruction by instruction. Every time a new
function appears, records the edge and keeps stepping into it. Already-
explored functions get skipped via step_out. Tight loops (100+ steps
with no call) get bailed out of.

Auto-discovers the state handler by breaking on per_frame_update,
stepping out to the main loop, then stepping forward to find the next
function call (which is the per-state handler).

Results stream to disk as edges are discovered — safe to interrupt.
Screenshots taken at start of each scenario for human verification.

Usage:
    python tools/explore_callgraph.py                  # run all scenarios
    python tools/explore_callgraph.py menu_idle         # run one scenario
    python tools/explore_callgraph.py --list            # list scenarios
"""

import os
import sys
import time
import argparse

PROJECT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJECT, "tools"))

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


def func_name(sym):
    """Strip +offset from symbol."""
    return sym.split('+')[0] if '+' in sym else sym


def discover_state_handler(s):
    """Break on per_frame_update, step out to main loop, step forward
    to find the state handler (next function called after per_frame_update).

    Returns (handler_name, handler_pc) or (None, None).
    """
    w = s.run_to("per_frame_update")
    if not w:
        return None, None

    main_loop = func_name(w['pr_sym'])

    # Step out to main loop
    s.verbose = False
    w = s.step_out()
    if not w:
        return None, None

    # Step forward to find the next function call
    for i in range(100):
        w = s.step_into(1)
        if not w:
            break
        new_func = func_name(w['pc_sym'])
        if new_func != main_loop:
            s.verbose = True
            return new_func, w['pc']

    return None, None


def explore_dfs(s, entry_point, out_file, max_steps=2000):
    """DFS through call graph. Streams edges to out_file as discovered.

    entry_point can be a symbol name or an int address.
    Returns (edges, explored).
    """
    explored = set()
    edges = []
    edge_set = set()
    call_stack = []
    MAX_SAME = 100

    # Break at entry
    w = s.run_to(entry_point)
    if not w:
        msg = f"Could not break on {entry_point}\n"
        print(msg, end="")
        out_file.write(msg)
        out_file.flush()
        return edges, explored

    entry_func = func_name(w['pc_sym'])
    entry_pr = w['pr']
    call_stack.append(entry_func)
    current_func = entry_func
    same_func_steps = 0

    def indent():
        return "  " * (len(call_stack) - 1)

    header = f"Entry: {entry_func} (PC=0x{w['pc']:08X}, returns to 0x{entry_pr:08X})\n"
    print(header, end="")
    out_file.write(header)
    out_file.flush()

    steps = 0
    s.verbose = False

    while steps < max_steps:
        w = s.step_into(1)
        steps += 1
        if not w:
            msg = f"  step {steps}: FAILED\n"
            print(msg, end="")
            out_file.write(msg)
            out_file.flush()
            break

        new_func = func_name(w['pc_sym'])

        if new_func == current_func:
            same_func_steps += 1
            if same_func_steps >= MAX_SAME:
                msg = f"  {indent()}  (loop in {current_func}, skipping)\n"
                print(msg, end="")
                out_file.write(msg)
                out_file.flush()
                explored.add(current_func)
                if len(call_stack) <= 1:
                    break
                call_stack.pop()
                w = s.step_out()
                steps += 1
                if not w:
                    break
                current_func = func_name(w['pc_sym'])
                same_func_steps = 0
            continue

        # Function transition
        same_func_steps = 0

        # Did we return from the entry function?
        if len(call_stack) >= 1 and call_stack[0] == entry_func \
                and abs(w['pc'] - entry_pr) <= 4:
            msg = f"  Returned from {entry_func} (PC=0x{w['pc']:08X})\n"
            print(msg, end="")
            out_file.write(msg)
            out_file.flush()
            for f in call_stack:
                explored.add(f)
            break

        if new_func in call_stack:
            while len(call_stack) > 1 and call_stack[-1] != new_func:
                done = call_stack.pop()
                explored.add(done)
            current_func = new_func
            if len(call_stack) == 1 and call_stack[0] == entry_func:
                explored.add(entry_func)
                break

        elif new_func in explored:
            edge = (current_func, new_func)
            if edge not in edge_set:
                edges.append(edge)
                edge_set.add(edge)
                msg = f"  {indent()}+- {new_func} (explored, skipping)\n"
                print(msg, end="")
                out_file.write(msg)
                out_file.flush()
            w = s.step_out()
            steps += 1
            if not w:
                break
            current_func = func_name(w['pc_sym'])

        else:
            edge = (current_func, new_func)
            if edge not in edge_set:
                edges.append(edge)
                edge_set.add(edge)
                msg = f"  {indent()}+- {new_func}\n"
                print(msg, end="")
                out_file.write(msg)
                out_file.flush()
            call_stack.append(new_func)
            current_func = new_func

    for f in call_stack:
        explored.add(f)

    summary = f"\n{steps} steps, {len(edges)} edges, {len(explored)} functions\n"
    print(summary, end="")
    out_file.write(summary)
    out_file.flush()
    return edges, explored


def build_tree(edges):
    """Build adjacency list from edges."""
    from collections import OrderedDict
    children = OrderedDict()
    for caller, callee in edges:
        if caller not in children:
            children[caller] = []
        if callee not in children[caller]:
            children[caller].append(callee)
    root = edges[0][0] if edges else None
    return root, children


def format_tree(root, children):
    """Format ASCII tree."""
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

    _walk(root, "", True, set())
    return "\n".join(lines)


def run_scenario(label, state, button):
    """Run one DFS scenario. Returns True on success."""
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
    # processed by SMPC before we start the DFS.
    if button:
        s.bot.input_press(button)
        s.bot.frame_advance(1)
        print(f"  {button} pressed, frame advanced")

    # Discover the state handler: break on per_frame_update, step out
    # to main loop, step forward to find the next function call.
    print(f"  Discovering state handler...")
    handler_name, handler_pc = discover_state_handler(s)
    if not handler_name:
        print(f"  ERROR: Could not discover state handler")
        s.quit()
        return False
    print(f"  State handler: {handler_name} (0x{handler_pc:08X})")

    # Step out of the state handler so we can DFS into it fresh
    s.step_out()

    with open(out_path, "w") as f:
        action_desc = f"{button} press" if button else "idle"
        f.write(f"CALL GRAPH: {state} {action_desc}\n")
        f.write(f"State handler: {handler_name}\n\n")

        # DFS from the state handler
        if button:
            # Re-press button (it was held during discovery, still held)
            pass  # button still held from earlier input_press
        edges, explored = explore_dfs(s, handler_name, f, max_steps=2000)

        if edges:
            root, children = build_tree(edges)
            tree_str = format_tree(root, children)

            f.write(f"\n{'=' * 60}\n")
            f.write(f"TREE:\n\n")
            f.write(tree_str)
            f.write(f"\n\n{'=' * 60}\n")
            f.write(f"EDGES ({len(edges)}):\n\n")
            for caller, callee in edges:
                f.write(f"  {caller} -> {callee}\n")

            print(f"\n{tree_str}")

    if button:
        s.bot.input_release(button)

    s.quit()
    print(f"  Saved: {out_path}")
    return True


def main():
    parser = argparse.ArgumentParser(description="DFS call graph explorer")
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
