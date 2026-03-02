#!/usr/bin/env python3
"""Find which function handles A/B/C buttons on the circuit select screen.

Uses save state + call trace differential to find button-responsive functions.
"""

import os
import sys
import time

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(PROJECT, "workstreams", "empirical_validation"))

from investigate import MednafenBot, wsl_path, load_symbols

# Not needed anymore since load_symbols knows the path

SAVE_STATE = os.path.join(PROJECT, "build", "save_states", "circuit_select_slot0.mc0")
CUE_PATH = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
IPC_DIR = os.path.join(PROJECT, "build", "debug_ipc")
TRACE_DIR = os.path.join(IPC_DIR, "traces")
os.makedirs(TRACE_DIR, exist_ok=True)

def capture_trace(bot, label, state_wsl, button=None, n_frames=3):
    """Load save state, optionally press button, capture call trace for n frames."""
    bot.send_and_wait("breakpoint_clear", "breakpoint_clear")
    bot.send_and_wait("input_clear", "input_clear")

    ack = bot.send_and_wait(f"load_state {state_wsl}", "load_state", timeout=15)
    if not ack or "error" in ack:
        print(f"  FAIL load_state: {ack}")
        return None

    if button:
        bot.input_press(button)

    trace_path = os.path.join(TRACE_DIR, f"trace_{label}.txt")
    trace_wsl = wsl_path(trace_path)
    bot.send_and_wait(f"call_trace {trace_wsl}", "call_trace")
    bot.frame_advance(n_frames)
    bot.send_and_wait("call_trace_stop", "call_trace_stop")

    if button:
        bot.input_release(button)

    return trace_path


def parse_trace(path, symbols):
    """Parse call trace into edge counts. Returns {(caller, target): count}."""
    from bisect import bisect_right
    addrs = sorted(symbols.keys())

    def resolve(addr):
        idx = bisect_right(addrs, addr) - 1
        if idx >= 0:
            return symbols[addrs[idx]]
        return f"0x{addr:08X}"

    edges = {}
    try:
        with open(path) as f:
            for line in f:
                # Format: <cycle> M|S <caller_PC> <target_PC>
                parts = line.strip().split()
                if len(parts) >= 4 and parts[1] in ("M", "S"):
                    try:
                        caller = int(parts[2], 16)
                        target = int(parts[3], 16)
                        edge = (resolve(caller), resolve(target))
                        edges[edge] = edges.get(edge, 0) + 1
                    except ValueError:
                        pass
    except FileNotFoundError:
        pass
    return edges


def diff_traces(baseline, test):
    """Find edges that are NEW or INCREASED in test vs baseline."""
    new_edges = {}
    increased = {}
    for edge, count in test.items():
        base_count = baseline.get(edge, 0)
        if base_count == 0:
            new_edges[edge] = count
        elif count > base_count:
            increased[edge] = (base_count, count)
    return new_edges, increased


def main():
    addr_to_name, name_to_addr = load_symbols()
    symbols = addr_to_name
    print(f"Loaded {len(symbols)} symbols")

    bot = MednafenBot(IPC_DIR, wsl_path(CUE_PATH))
    print("Starting Mednafen...")
    if not bot.start(timeout=30):
        print("FAIL: Mednafen did not start")
        return

    bot.frame_advance(1)
    state_wsl = wsl_path(SAVE_STATE)
    ack = bot.send_and_wait(f"load_state {state_wsl}", "load_state", timeout=15)
    if not ack or "error" in ack:
        print(f"FAIL: {ack}")
        bot.quit()
        return
    print("Save state loaded\n")

    N = 3  # frames per capture

    # Capture baseline (idle)
    print(f"Capturing IDLE baseline ({N} frames)...")
    idle_path = capture_trace(bot, "idle", state_wsl, button=None, n_frames=N)
    idle_edges = parse_trace(idle_path, symbols)
    print(f"  {len(idle_edges)} edges\n")

    # Capture each button
    for button in ["A", "B", "C"]:
        print(f"Capturing {button} ({N} frames)...")
        btn_path = capture_trace(bot, button, state_wsl, button=button, n_frames=N)
        btn_edges = parse_trace(btn_path, symbols)
        print(f"  {len(btn_edges)} edges")

        new_edges, increased = diff_traces(idle_edges, btn_edges)

        if new_edges:
            print(f"\n  NEW edges ({len(new_edges)}):")
            for (caller, target), count in sorted(new_edges.items(), key=lambda x: -x[1]):
                print(f"    {caller} -> {target} [{count}x]")

        if increased:
            print(f"\n  INCREASED edges ({len(increased)}):")
            for (caller, target), (old, new) in sorted(increased.items(), key=lambda x: -x[1][1]):
                print(f"    {caller} -> {target} [{old}x -> {new}x]")

        if not new_edges and not increased:
            print("  (identical to idle)")
        print()

    bot.quit()
    print("Done.")


if __name__ == "__main__":
    main()
