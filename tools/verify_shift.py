#!/usr/bin/env python3
"""verify_shift.py -- Byte-level verification of shifted binary.

Compares original (0-byte) and shifted (N-byte) binaries, verifying:
1. _start area (offset 0 to START_SIZE) is identical
2. Padding bytes are zeros
3. FUN_ area: every byte matches, with code-range 32-bit values shifted by SHIFT
"""

import struct
import sys
import os

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ORIG = os.path.join(PROJ, "build", "aprog.bin")
SHIFTED = os.path.join(PROJ, "reimpl", "build", "APROG.BIN")

BASE_ADDR = 0x06003000
# _start ends at FUN_060030FC = offset 0xFC
START_SIZE = 0xFC


def main():
    with open(ORIG, "rb") as f:
        orig = f.read()
    with open(SHIFTED, "rb") as f:
        shifted = f.read()

    SHIFT = len(shifted) - len(orig)
    code_end = BASE_ADDR + len(orig)

    print(f"Original: {len(orig)} bytes")
    print(f"Shifted:  {len(shifted)} bytes")
    print(f"SHIFT:    {SHIFT} bytes")
    print(f"Code range: 0x{BASE_ADDR:08X} - 0x{code_end:08X}")
    print()

    # Phase 1: _start area (should be identical)
    print("Phase 1: _start area (0x00 - 0x{:02X})".format(START_SIZE))
    start_diffs = 0
    for i in range(START_SIZE):
        if i < len(orig) and i < len(shifted):
            if orig[i] != shifted[i]:
                if start_diffs < 5:
                    # Check if this is a 4-byte aligned pool entry that shifted
                    addr = BASE_ADDR + i
                    if addr % 4 == 0 and i + 4 <= START_SIZE:
                        vo = struct.unpack(">I", orig[i:i+4])[0]
                        vs = struct.unpack(">I", shifted[i:i+4])[0]
                        delta = vs - vo
                        print(f"  Diff at 0x{i:04X}: orig=0x{vo:08X} shifted=0x{vs:08X} delta={delta}")
                    else:
                        print(f"  Diff at 0x{i:04X}: orig=0x{orig[i]:02X} shifted=0x{shifted[i]:02X}")
                start_diffs += 1

    if start_diffs == 0:
        print("  IDENTICAL (no diffs)")
    else:
        print(f"  {start_diffs} differences!")

    # Check pool entries in _start (4-byte aligned positions after code)
    print("\n  _start pool entries (4-byte aligned, value changes):")
    for i in range(0, START_SIZE - 3, 4):
        vo = struct.unpack(">I", orig[i:i+4])[0]
        vs = struct.unpack(">I", shifted[i:i+4])[0]
        if vo != vs:
            delta = vs - vo
            in_code = BASE_ADDR <= vo < code_end
            status = f"delta={delta}"
            if delta == SHIFT and in_code:
                status += " [CORRECT SHIFT]"
            elif not in_code:
                status += " [NOT IN CODE RANGE!]"
            else:
                status += " [WRONG SHIFT!]"
            print(f"    0x{i:04X}: orig=0x{vo:08X} shifted=0x{vs:08X} {status}")

    # Phase 2: Padding area
    print(f"\nPhase 2: Padding area (0x{START_SIZE:02X} - 0x{START_SIZE + SHIFT:02X})")
    all_zero = all(shifted[i] == 0 for i in range(START_SIZE, START_SIZE + SHIFT))
    print(f"  All zeros: {all_zero}")
    if not all_zero:
        for i in range(START_SIZE, START_SIZE + SHIFT):
            if shifted[i] != 0:
                print(f"  Non-zero at 0x{i:04X}: 0x{shifted[i]:02X}")

    # Phase 3: FUN_ area (orig[START_SIZE:] vs shifted[START_SIZE+SHIFT:])
    print(f"\nPhase 3: FUN_ area comparison")
    fun_match = 0
    fun_shifted_correct = 0
    fun_issues = []

    for i in range(START_SIZE, len(orig) - 3, 4):
        vo = struct.unpack(">I", orig[i:i+4])[0]
        j = i + SHIFT
        if j + 4 > len(shifted):
            break
        vs = struct.unpack(">I", shifted[j:j+4])[0]

        if vo == vs:
            fun_match += 1
        elif vs - vo == SHIFT:
            fun_shifted_correct += 1
        else:
            fun_issues.append((i, vo, vs))

    print(f"  Identical values: {fun_match}")
    print(f"  Correctly shifted by {SHIFT}: {fun_shifted_correct}")
    print(f"  UNEXPECTED differences: {len(fun_issues)}")

    if fun_issues:
        print("\n  First 20 unexpected differences:")
        for i, vo, vs in fun_issues[:20]:
            addr = BASE_ADDR + i
            delta = vs - vo
            in_code = BASE_ADDR <= vo < code_end
            print(f"    offset 0x{i:06X} (addr 0x{addr:08X}): "
                  f"orig=0x{vo:08X} shifted=0x{vs:08X} delta={delta} "
                  f"in_code={in_code}")

    # Also check byte-by-byte for non-aligned differences
    print(f"\n  Byte-level check (non-pool bytes):")
    byte_diffs = 0
    for i in range(START_SIZE, len(orig)):
        j = i + SHIFT
        if j >= len(shifted):
            break
        if orig[i] != shifted[j]:
            # This byte differs. Check if it's part of a 4-byte-aligned pool entry
            aligned_i = i & ~3
            if aligned_i >= START_SIZE and aligned_i + 4 <= len(orig):
                vo4 = struct.unpack(">I", orig[aligned_i:aligned_i+4])[0]
                vs4 = struct.unpack(">I", shifted[aligned_i+SHIFT:aligned_i+SHIFT+4])[0]
                if vs4 - vo4 == SHIFT:
                    continue  # Part of a correctly shifted pool entry
            byte_diffs += 1
            if byte_diffs <= 10:
                print(f"    offset 0x{i:06X}: orig=0x{orig[i]:02X} shifted=0x{shifted[j]:02X}")

    print(f"  Non-pool byte differences: {byte_diffs}")

    # Summary
    print(f"\n=== SUMMARY ===")
    if start_diffs == 0 and len(fun_issues) == 0 and byte_diffs == 0 and all_zero:
        print("BINARY IS PERFECT - all shifts are correct")
    else:
        if start_diffs > 0:
            print(f"ISSUE: {start_diffs} unexpected _start diffs")
        if fun_issues:
            print(f"ISSUE: {len(fun_issues)} unexpected FUN_ diffs")
        if byte_diffs > 0:
            print(f"ISSUE: {byte_diffs} non-pool byte differences")
        if not all_zero:
            print("ISSUE: padding not all zeros")


if __name__ == "__main__":
    main()
