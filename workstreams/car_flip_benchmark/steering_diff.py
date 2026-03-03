#!/usr/bin/env python3
"""Call-trace differential for steering input.

Reads the call trace and input trace, splits into idle vs LEFT/RIGHT frames,
and reports functions that appear more during input (steering handlers).
"""

import os
import re
from collections import defaultdict

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
CALL_TRACE = os.path.join(PROJECT, "workstreams", "car_flip_benchmark", "steering_call_trace.txt")
INPUT_TRACE = os.path.join(PROJECT, "workstreams", "car_flip_benchmark", "steering_input_trace.txt")
MAP_FILE = os.path.join(PROJECT, "reimpl", "build", "daytona.map")


def load_symbol_map(map_path):
    """Load address->name mapping from linker map."""
    syms = {}
    if not os.path.exists(map_path):
        return syms
    with open(map_path) as f:
        for line in f:
            line = line.strip()
            # Standard: 0xADDR symbol
            m = re.match(r'0x([0-9a-fA-F]+)\s+(\w+)', line)
            if m:
                addr = int(m.group(1), 16)
                syms[addr] = m.group(2)
            # PROVIDE: 0xADDR PROVIDE (sym = 0xval)
            m = re.match(r'0x[0-9a-fA-F]+\s+PROVIDE\s*\(\s*(\w+)\s*=\s*0x([0-9a-fA-F]+)', line)
            if m:
                addr = int(m.group(2), 16)
                syms[addr] = m.group(1)
    return syms


def load_input_windows(input_path):
    """Parse input trace into list of (start_frame, end_frame, button) tuples."""
    windows = []
    active = {}  # button -> start_frame
    with open(input_path) as f:
        for line in f:
            m = re.match(r'frame=(\d+)\s+(PRESS|RELEASE)\s+(\w+)', line)
            if not m:
                continue
            frame, action, button = int(m.group(1)), m.group(2), m.group(3)
            if button not in ("LEFT", "RIGHT"):
                continue
            if action == "PRESS":
                active[button] = frame
            elif action == "RELEASE" and button in active:
                windows.append((active[button], frame, button))
                del active[button]
    # Close any still-active
    for button, start in active.items():
        windows.append((start, 999999, button))
    return windows


def frame_in_input(frame, windows):
    for start, end, _ in windows:
        if start <= frame <= end:
            return True
    return False


def main():
    syms = load_symbol_map(MAP_FILE)
    windows = load_input_windows(INPUT_TRACE)

    print(f"Input windows: {len(windows)}")
    for start, end, btn in windows:
        print(f"  {btn}: frames {start}-{end}")
    print()

    # Parse call trace, bucket by frame
    # Format: <cycle> M/S <caller> <callee>
    idle_calls = defaultdict(int)
    input_calls = defaultdict(int)
    idle_frames = 0
    input_frames = 0

    # First pass: find frame boundaries by watching cycle counter reset patterns
    # Actually, the trace doesn't have frame markers. Use the input windows
    # and bucket by cycle ranges.

    # Simpler approach: bucket each call by whether its cycle falls in an input window.
    # But we need frame numbers, not cycles. Let's estimate frames from the trace.

    # The trace format is: <cycle> M/S <src_pc> <dst_pc>
    # We need to map cycles to frames. Let's use the call trace to find frame boundaries.
    # game_update_loop or vblank_frame_handler should fire once per frame.

    # Actually, let's just count unique callee addresses per input/idle period.
    # Find a known per-frame function to count frames.

    # Load all calls
    all_calls = []
    with open(CALL_TRACE) as f:
        for line in f:
            if line.startswith('#'):
                continue
            parts = line.strip().split()
            if len(parts) < 4:
                continue
            try:
                cycle = int(parts[0])
            except ValueError:
                continue
            cpu = parts[1]
            src = int(parts[2], 16)
            dst = int(parts[3], 16)
            all_calls.append((cycle, cpu, src, dst))

    if not all_calls:
        print("No calls found in trace!")
        return

    print(f"Total calls: {len(all_calls):,}")

    # Find frame boundaries using vblank_frame_handler or game_update_loop
    # Look for a function that fires exactly once per frame
    vblank_addr = None
    for addr, name in syms.items():
        if name == "vblank_frame_handler":
            vblank_addr = addr
            break
    if not vblank_addr:
        # Try game_update_loop
        for addr, name in syms.items():
            if name == "game_update_loop":
                vblank_addr = addr
                break

    if vblank_addr:
        print(f"Using {syms[vblank_addr]} (0x{vblank_addr:08X}) as frame marker")
    else:
        print("WARNING: No frame marker found, using raw call counts")

    # Build frame->cycle mapping
    frame_starts = []
    for cycle, cpu, src, dst in all_calls:
        if dst == vblank_addr and cpu == 'M':
            frame_starts.append(cycle)

    if frame_starts:
        print(f"Found {len(frame_starts)} frames in trace")
    else:
        print("No frame markers found, falling back to proportional frame estimation")

    # Assign each call to a frame number
    def cycle_to_frame(c):
        # Binary search for frame
        lo, hi = 0, len(frame_starts) - 1
        if not frame_starts or c < frame_starts[0]:
            return 0
        while lo < hi:
            mid = (lo + hi + 1) // 2
            if frame_starts[mid] <= c:
                lo = mid
            else:
                hi = mid - 1
        return lo

    # Count calls per callee, split by idle/input
    for cycle, cpu, src, dst in all_calls:
        if cpu != 'M':  # Focus on primary SH-2
            continue
        frame = cycle_to_frame(cycle)
        in_input = frame_in_input(frame, windows)
        name = syms.get(dst, f"0x{dst:08X}")
        if in_input:
            input_calls[name] += 1
        else:
            idle_calls[name] += 1

    # Count frames
    for i in range(len(frame_starts)):
        if frame_in_input(i, windows):
            input_frames += 1
        else:
            idle_frames += 1

    print(f"Idle frames: {idle_frames}, Input frames: {input_frames}")
    print()

    # Find functions unique to input or with significantly more calls during input
    all_funcs = set(idle_calls.keys()) | set(input_calls.keys())

    # NEW: functions that only appear during input
    input_only = []
    for func in all_funcs:
        if idle_calls[func] == 0 and input_calls[func] > 0:
            input_only.append((func, input_calls[func]))
    input_only.sort(key=lambda x: -x[1])

    if input_only:
        print("=== FUNCTIONS ONLY DURING INPUT (strongest leads) ===")
        for func, count in input_only[:30]:
            print(f"  {func}: {count} calls")
        print()

    # RATIO: functions with higher call rate during input
    print("=== FUNCTIONS WITH HIGHER RATE DURING INPUT ===")
    ratios = []
    for func in all_funcs:
        ic = input_calls[func]
        oc = idle_calls[func]
        if input_frames > 0 and idle_frames > 0:
            input_rate = ic / input_frames
            idle_rate = oc / idle_frames
            if input_rate > idle_rate and ic > 5:
                ratio = input_rate / idle_rate if idle_rate > 0 else float('inf')
                ratios.append((func, ic, oc, input_rate, idle_rate, ratio))
    ratios.sort(key=lambda x: -x[5])
    for func, ic, oc, ir, odr, ratio in ratios[:30]:
        print(f"  {func}: input={ic} idle={oc}  rate={ir:.1f}/{odr:.1f}  ratio={ratio:.1f}x")


if __name__ == "__main__":
    main()
