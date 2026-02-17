#!/usr/bin/env python3
"""binary_pool_diff.py -- Comprehensive comparison of prod vs free binary.

For every 4-byte aligned position:
- In _start area (0x00-0xFB): compare directly, differences should be +16 pool entries
- In FUN_ area: compare prod[off] vs free[off+16], differences should be +16 pool entries
Any difference that's NOT +16 is flagged as suspicious.
"""
import struct, sys

SHIFT = 16
START_SIZE = 0xFC  # _start is 252 bytes (0x06003000-0x060030FB)
BASE_ADDR = 0x06003000

def main():
    with open("build/aprog.bin", "rb") as f:
        prod = f.read()
    with open("reimpl/build/APROG.BIN", "rb") as f:
        free = f.read()

    print(f"Prod: {len(prod)} bytes, Free: {len(free)} bytes")
    print(f"Expected diff: {len(free) - len(prod)} bytes (SHIFT={SHIFT})")

    # Phase 1: Compare _start area (same offset in both)
    print(f"\n=== Phase 1: _start area (0x00-0x{START_SIZE-1:02X}) ===")
    start_diffs = 0
    start_correct = 0
    start_issues = []
    for off in range(0, START_SIZE, 4):
        if off + 4 > len(prod) or off + 4 > len(free):
            break
        vp = struct.unpack(">I", prod[off:off+4])[0]
        vf = struct.unpack(">I", free[off:off+4])[0]
        if vp == vf:
            continue
        delta = vf - vp
        addr = BASE_ADDR + off
        if delta == SHIFT:
            start_correct += 1
        else:
            start_issues.append((off, addr, vp, vf, delta))
            start_diffs += 1

    print(f"  {start_correct} pool entries shifted by +{SHIFT} (correct)")
    if start_issues:
        print(f"  {len(start_issues)} UNEXPECTED differences:")
        for off, addr, vp, vf, delta in start_issues:
            print(f"    offset 0x{off:04X} (addr 0x{addr:08X}): prod=0x{vp:08X} free=0x{vf:08X} delta={delta}")
    else:
        print("  No unexpected differences")

    # Phase 2: Compare FUN_ area (prod[off] vs free[off+SHIFT])
    print(f"\n=== Phase 2: FUN_ area (offset 0x{START_SIZE:02X}+) ===")
    fun_total = 0
    fun_match = 0
    fun_shifted = 0
    fun_issues = []

    for off in range(START_SIZE, len(prod), 4):
        if off + 4 > len(prod) or off + SHIFT + 4 > len(free):
            break
        vp = struct.unpack(">I", prod[off:off+4])[0]
        vf = struct.unpack(">I", free[off+SHIFT:off+SHIFT+4])[0]
        fun_total += 1

        if vp == vf:
            fun_match += 1
            continue

        delta = vf - vp
        addr = BASE_ADDR + off  # original address
        if delta == SHIFT:
            fun_shifted += 1
        else:
            fun_issues.append((off, addr, vp, vf, delta))

    print(f"  {fun_total} total 4-byte positions compared")
    print(f"  {fun_match} identical (instruction bytes, non-code values)")
    print(f"  {fun_shifted} shifted by +{SHIFT} (correct pool entries)")

    if fun_issues:
        print(f"  {len(fun_issues)} UNEXPECTED differences:")
        for off, addr, vp, vf, delta in fun_issues[:50]:  # limit output
            # Check if prod value is in code range
            in_code = BASE_ADDR <= vp <= BASE_ADDR + len(prod)
            code_marker = " [code-range]" if in_code else ""
            print(f"    offset 0x{off:05X} (addr 0x{addr:08X}): prod=0x{vp:08X} free=0x{vf:08X} delta={delta:+d}{code_marker}")
        if len(fun_issues) > 50:
            print(f"    ... and {len(fun_issues) - 50} more")
    else:
        print("  No unexpected differences!")

    # Phase 3: Check padding area
    print(f"\n=== Phase 3: Padding area (offset 0x{START_SIZE:02X}-0x{START_SIZE+SHIFT-1:02X}) ===")
    padding = free[START_SIZE:START_SIZE+SHIFT]
    print(f"  Padding bytes: {' '.join(f'{b:02X}' for b in padding)}")
    if all(b == 0 for b in padding):
        print("  All zeros (clean padding)")
    else:
        print("  WARNING: Non-zero padding!")

    print(f"\n=== Summary ===")
    print(f"  _start: {start_correct} correct shifts, {len(start_issues)} issues")
    print(f"  FUN_: {fun_shifted} correct shifts, {len(fun_issues)} issues")
    if not start_issues and not fun_issues:
        print("  PERFECT: All differences are exactly +{} shifts!".format(SHIFT))


if __name__ == "__main__":
    main()
