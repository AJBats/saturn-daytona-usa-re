#!/usr/bin/env python3
"""Capture call graph at car select screen via disc boot (not save state).

This captures what the PRIMARY SH-2 does during car select, which should
include the 3D car model transformation pipeline.
"""

import os
import sys
import time
import bisect

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(PROJECT, "workstreams", "empirical_validation"))

from debugger_utils import DebugSession
from investigate import load_symbols


def main():
    print("=== Capture car select call graph (disc boot) ===\n")

    s = DebugSession("car", verbose=True)

    # Capture call trace for 1 frame
    trace_path = os.path.join(s.results_dir, "car_select_disc_boot.txt")
    print(f"\nCapturing call trace for 1 frame...")
    s.bot.start_call_trace(trace_path)
    s.bot.send_and_wait("frame_advance 1", "done frame_advance", timeout=60)
    s.bot.stop_call_trace()

    # Wait for trace file
    time.sleep(1.0)

    # Parse the call trace
    addr_to_name, _ = load_symbols()
    addrs = sorted(addr_to_name.keys())
    names = [addr_to_name[a] for a in addrs]

    def resolve(addr):
        idx = bisect.bisect_right(addrs, addr) - 1
        if idx >= 0:
            offset = addr - addrs[idx]
            name = names[idx]
            if offset == 0:
                return name
            return f"{name}+0x{offset:X}"
        return f"0x{addr:08X}"

    if os.path.exists(trace_path):
        with open(trace_path) as f:
            lines = f.readlines()
        print(f"\nCall trace: {len(lines)} entries")

        # Count function calls
        from collections import Counter
        call_counts = Counter()
        for line in lines:
            line = line.strip()
            if not line:
                continue
            parts = line.split()
            if len(parts) >= 2 and parts[0] == "CALL":
                try:
                    addr = int(parts[1], 16)
                    call_counts[resolve(addr)] += 1
                except ValueError:
                    pass

        # Print top functions
        print(f"\nTop 40 called functions:")
        for name, count in call_counts.most_common(40):
            print(f"  {count:4d}x  {name}")

        # Look for matrix/transform related functions
        print(f"\nMatrix/transform functions called:")
        matrix_keywords = ["mat_", "rot_", "transform", "vec", "270", "26E", "032"]
        for name, count in call_counts.most_common():
            for kw in matrix_keywords:
                if kw in name.lower():
                    print(f"  {count:4d}x  {name}")
                    break

        # Look for render/display functions
        print(f"\nRender/display functions called:")
        render_keywords = ["render", "draw", "disp", "vdp", "sprite", "geom", "poly"]
        for name, count in call_counts.most_common():
            for kw in render_keywords:
                if kw in name.lower():
                    print(f"  {count:4d}x  {name}")
                    break
    else:
        print("FAIL: trace file not found")

    s.quit()
    print("\nDone.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
