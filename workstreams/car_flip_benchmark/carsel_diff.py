#!/usr/bin/env python3
"""Call-trace differential for car select input.

Splits call trace into idle (both cars spinning) vs input (LEFT/RIGHT pressed)
frames. Reports functions unique to input and functions with higher call rate.
"""

import os
import re
from collections import defaultdict

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
CALL_TRACE = os.path.join(PROJECT, "workstreams", "car_flip_benchmark", "carsel_call_trace.txt")
INPUT_TRACE = os.path.join(PROJECT, "workstreams", "car_flip_benchmark", "carsel_input_trace.txt")
MAP_FILE = os.path.join(PROJECT, "reimpl", "build", "daytona.map")


def load_symbol_map(map_path):
    syms = {}
    if not os.path.exists(map_path):
        return syms
    with open(map_path) as f:
        for line in f:
            line = line.strip()
            m = re.match(r'0x([0-9a-fA-F]+)\s+(\w+)', line)
            if m:
                syms[int(m.group(1), 16)] = m.group(2)
            m = re.match(r'0x[0-9a-fA-F]+\s+PROVIDE\s*\(\s*(\w+)\s*=\s*0x([0-9a-fA-F]+)', line)
            if m:
                syms[int(m.group(2), 16)] = m.group(1)
    return syms


def load_input_windows(input_path):
    windows = []
    active = {}
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

    # Parse call trace
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

    print(f"Total calls: {len(all_calls):,}")

    # Find frame boundaries — car select doesn't use vblank_frame_handler,
    # use vblank_out_handler instead (fires once per vblank)
    vblank_addr = None
    for addr, name in syms.items():
        if name == "vblank_out_handler":
            vblank_addr = addr
            break

    frame_starts = []
    for cycle, cpu, src, dst in all_calls:
        if dst == vblank_addr and cpu == 'M':
            frame_starts.append(cycle)

    print(f"Frames in trace: {len(frame_starts)}")

    def cycle_to_frame(c):
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
    idle_calls = defaultdict(int)
    input_calls = defaultdict(int)
    idle_frames = 0
    input_frames = 0

    for cycle, cpu, src, dst in all_calls:
        if cpu != 'M':
            continue
        frame = cycle_to_frame(cycle)
        in_input = frame_in_input(frame, windows)
        name = syms.get(dst, f"0x{dst:08X}")
        if in_input:
            input_calls[name] += 1
        else:
            idle_calls[name] += 1

    for i in range(len(frame_starts)):
        if frame_in_input(i, windows):
            input_frames += 1
        else:
            idle_frames += 1

    print(f"Idle frames: {idle_frames}, Input frames: {input_frames}")
    print()

    # Functions unique to input
    all_funcs = set(idle_calls.keys()) | set(input_calls.keys())
    input_only = [(f, input_calls[f]) for f in all_funcs if idle_calls[f] == 0 and input_calls[f] > 0]
    input_only.sort(key=lambda x: -x[1])

    if input_only:
        print("=== FUNCTIONS ONLY DURING INPUT (strongest leads) ===")
        for func, count in input_only[:30]:
            print(f"  {func}: {count} calls")
        print()

    # Functions with higher rate during input
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

    # Also show ALL functions active during idle (rendering pipeline)
    print()
    print("=== ALL FUNCTIONS DURING IDLE (rendering pipeline) ===")
    idle_sorted = sorted(idle_calls.items(), key=lambda x: -x[1])
    for func, count in idle_sorted[:40]:
        in_count = input_calls.get(func, 0)
        print(f"  {func}: idle={count} input={in_count}")


if __name__ == "__main__":
    main()
