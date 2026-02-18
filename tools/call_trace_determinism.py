#!/usr/bin/env python3
"""call_trace_determinism.py — Run production disc TWICE, capture traces, diff them.

Tests whether Mednafen's call tracing is deterministic. If two runs of the
exact same disc produce different call traces, we know the emulator has
non-deterministic behavior and our prod-vs-free comparison needs more care.

Usage:
    python3 tools/call_trace_determinism.py [--frames 300]
"""

import os
import sys
import time
import argparse

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, win_to_wsl

CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")
TMPDIR = os.path.join(PROJDIR, ".tmp", "call_trace")


def run_trace(label, cue_path, trace_win_path, frames):
    """Run one Mednafen instance, capture call trace, return."""
    trace_wsl = win_to_wsl(trace_win_path)
    ipc_dir = os.path.join(TMPDIR, f"ipc_{label}")

    if os.path.exists(trace_win_path):
        os.remove(trace_win_path)

    print(f"\n[{label}] Starting Mednafen...")
    inst = MednafenInstance(label, cue_path, ipc_dir)
    inst.start()

    try:
        ack = inst.send(f"call_trace {trace_wsl}")
        print(f"  [{label}] {ack}")

        print(f"  [{label}] Running {frames} frames...")
        ack = inst.frame_advance(frames)
        print(f"  [{label}] {ack}")

        ack = inst.send("call_trace_stop")
        print(f"  [{label}] {ack}")
    finally:
        inst.quit()

    if os.path.exists(trace_win_path):
        size = os.path.getsize(trace_win_path)
        with open(trace_win_path) as f:
            lines = sum(1 for _ in f)
        print(f"  [{label}] Trace: {size:,} bytes, {lines:,} calls")
        return lines
    else:
        print(f"  [{label}] ERROR: Trace file not found!")
        return 0


def main():
    parser = argparse.ArgumentParser(description="Test call trace determinism")
    parser.add_argument("--frames", type=int, default=300, help="Frames to trace (default 300)")
    args = parser.parse_args()

    os.makedirs(TMPDIR, exist_ok=True)

    trace_a = os.path.join(TMPDIR, "trace_det_a.txt")
    trace_b = os.path.join(TMPDIR, "trace_det_b.txt")

    # Kill stale processes
    print("Killing stale Mednafen processes...")
    MednafenInstance.kill_stale()

    # Run A
    lines_a = run_trace("run_a", CUE_PROD, trace_a, args.frames)

    # Small delay between runs
    time.sleep(2)

    # Kill stale again just in case
    MednafenInstance.kill_stale()

    # Run B
    lines_b = run_trace("run_b", CUE_PROD, trace_b, args.frames)

    # Compare
    print(f"\n{'='*60}")
    print("DETERMINISM ANALYSIS")
    print(f"{'='*60}")

    if lines_a == 0 or lines_b == 0:
        print("ERROR: One or both traces are empty!")
        return 1

    print(f"\nRun A: {lines_a:,} calls")
    print(f"Run B: {lines_b:,} calls")

    if lines_a != lines_b:
        print(f"\nDIFFERENT call counts! Delta: {abs(lines_a - lines_b):,}")

    # Line-by-line comparison
    print("\nComparing line-by-line...")
    mismatches = 0
    first_diff_line = None
    with open(trace_a) as fa, open(trace_b) as fb:
        for i, (la, lb) in enumerate(zip(fa, fb)):
            if la != lb:
                mismatches += 1
                if first_diff_line is None:
                    first_diff_line = i
                    print(f"\nFIRST DIFFERENCE at line {i:,}:")
                    print(f"  Run A: {la.strip()}")
                    print(f"  Run B: {lb.strip()}")
                if mismatches <= 10:
                    if mismatches > 1:
                        print(f"  Line {i:,}: A={la.strip()} B={lb.strip()}")

    min_lines = min(lines_a, lines_b)
    if mismatches == 0 and lines_a == lines_b:
        print(f"\nPERFECT MATCH! All {lines_a:,} calls are identical across both runs.")
        print("The emulator is DETERMINISTIC for call tracing.")
    elif mismatches == 0:
        print(f"\nAll {min_lines:,} shared lines match, but line counts differ.")
        print(f"Run A has {lines_a - min_lines:,} extra lines at the end." if lines_a > lines_b
              else f"Run B has {lines_b - min_lines:,} extra lines at the end.")
    else:
        print(f"\n{mismatches:,} mismatches found out of {min_lines:,} compared lines.")
        print("The emulator is NOT deterministic for call tracing.")

    print(f"\nTraces saved to:")
    print(f"  {trace_a}")
    print(f"  {trace_b}")

    return 0


if __name__ == "__main__":
    sys.exit(main())
