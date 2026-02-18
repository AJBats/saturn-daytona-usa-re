#!/usr/bin/env python3
"""compare_layouts.py - Compare production-layout and free-layout reimpl binaries.

Compares the two reimpl binaries byte-by-byte at corresponding offsets
(production offset X = free offset X+4) to find differences caused by
packed vs gapped function layout.

These differences indicate cross-section pool reads that get different data.
"""

import struct
import os
import re

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# Production reimpl binary (sawyer.ld, fixed addresses)
PROD_REIMPL = os.path.join(PROJ, "reimpl", "build", "APROG_prod.BIN")
# Free reimpl binary (sawyer_free.ld, packed + 4 shift)
FREE_REIMPL = os.path.join(PROJ, "reimpl", "build", "APROG.BIN")
# Original production binary
ORIG = os.path.join(PROJ, "build", "aprog.bin")

BASE = 0x06003000
SHIFT = 4
CODE_START = 0x060030FC  # First function in production
CODE_END   = 0x06063690


def load_map(map_file):
    """Load function boundaries from linker map."""
    funcs = []
    with open(map_file, 'r') as f:
        for line in f:
            m = re.match(r'\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)\s+.*/(FUN_[0-9A-F]+)\.o', line)
            if m:
                addr = int(m.group(1), 16)
                size = int(m.group(2), 16)
                name = m.group(3)
                funcs.append((addr, size, name))
    funcs.sort()
    return funcs


def main():
    # Build production-layout binary if it doesn't exist
    if not os.path.exists(PROD_REIMPL):
        print(f"Production reimpl binary not found at {PROD_REIMPL}")
        print(f"Build with: cd reimpl && make clean && make")
        print(f"Then: cp reimpl/build/APROG.BIN reimpl/build/APROG_prod.BIN")
        print(f"\nUsing original binary instead for gap analysis...")
        prod_path = ORIG
    else:
        prod_path = PROD_REIMPL

    with open(prod_path, 'rb') as f:
        prod = f.read()
    with open(FREE_REIMPL, 'rb') as f:
        free = f.read()

    print(f"Production: {len(prod)} bytes ({prod_path})")
    print(f"Free:       {len(free)} bytes")
    print()

    # Compare at corresponding offsets
    # Production offset X corresponds to Free offset X+4
    # (for code after _start, which is at offset 0xFC)
    start_off = 0xFC  # Start of first FUN_ in production
    diffs = []

    for prod_off in range(start_off, len(prod) - 3, 2):  # Check every 2 bytes (instruction aligned)
        free_off = prod_off + SHIFT
        if free_off + 1 >= len(free):
            break

        prod_byte = prod[prod_off]
        free_byte = free[free_off]

        if prod_byte != free_byte:
            # Check if this is a known relocated pool entry (4-byte)
            if prod_off % 4 == 0 and prod_off + 4 <= len(prod) and free_off + 4 <= len(free):
                prod_val = struct.unpack('>I', prod[prod_off:prod_off+4])[0]
                free_val = struct.unpack('>I', free[free_off:free_off+4])[0]
                if free_val == prod_val + SHIFT:
                    continue  # Correctly relocated, skip

            prod_addr = BASE + prod_off
            diffs.append((prod_off, prod_addr, prod_byte, free_byte))

    print(f"Byte differences (excluding relocated pool entries): {len(diffs)}")

    if diffs:
        # Load function map for cross-reference
        map_file = os.path.join(PROJ, "reimpl", "build", "daytona.map")
        funcs = load_map(map_file) if os.path.exists(map_file) else []

        # Group diffs by function
        func_diffs = {}
        for prod_off, addr, pb, fb in diffs:
            func_name = "unknown"
            for faddr, fsize, fname in funcs:
                # Map from free-build addresses back to production
                prod_faddr = faddr - SHIFT
                if prod_faddr <= addr < prod_faddr + fsize:
                    func_name = fname
                    break
            if func_name not in func_diffs:
                func_diffs[func_name] = []
            func_diffs[func_name].append((prod_off, addr, pb, fb))

        print(f"\nDifferences by function ({len(func_diffs)} functions affected):")
        for fname, fdiffs in sorted(func_diffs.items(), key=lambda x: x[1][0][1]):
            print(f"\n  {fname}: {len(fdiffs)} byte differences")
            for prod_off, addr, pb, fb in fdiffs[:5]:  # Show first 5
                print(f"    0x{addr:08X} (off 0x{prod_off:05X}): prod=0x{pb:02X} free=0x{fb:02X}")
            if len(fdiffs) > 5:
                print(f"    ... and {len(fdiffs)-5} more")

        # Also compare against ORIGINAL binary to see what the correct values should be
        if prod_path != ORIG and os.path.exists(ORIG):
            with open(ORIG, 'rb') as f:
                orig = f.read()
            print(f"\n\n=== Comparison with ORIGINAL binary ===")
            print(f"Checking if production reimpl matches original at diff locations...")
            match_orig = 0
            mismatch_orig = 0
            for prod_off, addr, pb, fb in diffs[:50]:
                if prod_off < len(orig):
                    ob = orig[prod_off]
                    if ob == pb:
                        match_orig += 1
                    else:
                        mismatch_orig += 1
                        if mismatch_orig <= 10:
                            print(f"  0x{addr:08X}: orig=0x{ob:02X} prod_reimpl=0x{pb:02X} free=0x{fb:02X}")
            print(f"\n  Prod reimpl matches original: {match_orig}/{match_orig+mismatch_orig}")

    # Additional analysis: find gaps in production layout
    if os.path.exists(os.path.join(PROJ, "reimpl", "build", "daytona.map")):
        print(f"\n\n=== Gap Analysis (production layout) ===")
        prod_map = os.path.join(PROJ, "reimpl", "build", "daytona.map")
        free_funcs = load_map(prod_map)

        # Convert free-build addresses to production addresses
        prod_funcs = [(addr - SHIFT, size, name) for addr, size, name in free_funcs]
        prod_funcs.sort()

        gaps = []
        for i in range(len(prod_funcs) - 1):
            addr1, size1, name1 = prod_funcs[i]
            addr2, _, name2 = prod_funcs[i + 1]
            end1 = addr1 + size1
            if end1 < addr2:
                gap_size = addr2 - end1
                gaps.append((end1, gap_size, name1, name2))

        print(f"  Total gaps between functions: {len(gaps)}")
        total_gap = sum(g[1] for g in gaps)
        print(f"  Total gap bytes: {total_gap}")

        # Check which gaps have non-zero data in the original binary
        if os.path.exists(ORIG):
            with open(ORIG, 'rb') as f:
                orig = f.read()
            nonzero_gaps = []
            for gap_addr, gap_size, before, after in gaps:
                off = gap_addr - BASE
                if off + gap_size <= len(orig):
                    gap_data = orig[off:off+gap_size]
                    if any(b != 0 for b in gap_data):
                        nonzero_gaps.append((gap_addr, gap_size, before, after, gap_data))

            print(f"  Gaps with non-zero original data: {len(nonzero_gaps)}")
            for gap_addr, gap_size, before, after, gap_data in nonzero_gaps[:20]:
                nonzero_count = sum(1 for b in gap_data if b != 0)
                print(f"    0x{gap_addr:08X} ({gap_size:4d} bytes, {nonzero_count} non-zero): "
                      f"after {before} -> before {after}")
                # Show first few bytes
                preview = gap_data[:16].hex()
                print(f"      Data: {preview}{'...' if gap_size > 16 else ''}")


if __name__ == "__main__":
    main()
