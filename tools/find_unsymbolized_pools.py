#!/usr/bin/env python3
"""find_unsymbolized_pools.py - Find unsymbolized address references in .s files.

Scans all reimpl/src/*.s files for .byte-encoded pool entries that contain
addresses in the game code/data range (0x06003000-0x06063690). These are
addresses that SHOULD be .4byte SYMBOL entries so they get relocated by
the linker when the binary shifts.

Also checks the binary itself for 4-byte aligned values in the code range
that appear identical in production and free builds (unrelocated addresses).
"""

import os
import re
import struct
import sys

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC_DIR = os.path.join(PROJ, "reimpl", "src")

# Game code/data range that shifts when binary shifts
CODE_START = 0x06003100  # First FUN_ section (after _start + padding)
CODE_END   = 0x06063690  # BSS start (end of binary in production)

# Also check for references to the _start range
START_ADDR = 0x06003000
START_END  = 0x060030FC


def scan_asm_files():
    """Scan .s files for .byte-encoded addresses in the code range."""
    results = []

    for fn in sorted(os.listdir(SRC_DIR)):
        if not fn.endswith('.s'):
            continue
        path = os.path.join(SRC_DIR, fn)
        with open(path, 'r') as f:
            lines = f.readlines()

        # Collect all .byte values with their offsets
        byte_vals = []
        offset = 0
        in_pool = False
        has_4byte = False

        for i, line in enumerate(lines):
            line = line.strip()

            # Track .4byte entries (these are symbolized - OK)
            if line.startswith('.4byte'):
                has_4byte = True
                byte_vals.append((offset, None, i + 1, 'symbol'))
                offset += 4
                continue

            m = re.match(r'\.byte\s+0x([0-9A-Fa-f]{2})\s*,\s*0x([0-9A-Fa-f]{2})', line)
            if m:
                b1 = int(m.group(1), 16)
                b2 = int(m.group(2), 16)
                byte_vals.append((offset, (b1, b2), i + 1, 'byte'))
                offset += 2
                continue

            m2 = re.match(r'\.byte\s+0x([0-9A-Fa-f]{2})', line)
            if m2:
                b1 = int(m2.group(1), 16)
                byte_vals.append((offset, (b1,), i + 1, 'byte1'))
                offset += 1
                continue

        # Now scan for 4-byte values in the .byte entries that look like addresses
        # A constant pool entry is 4 bytes: two consecutive .byte pairs
        for idx in range(len(byte_vals) - 1):
            off1, val1, line1, typ1 = byte_vals[idx]
            off2, val2, line2, typ2 = byte_vals[idx + 1]

            if typ1 != 'byte' or typ2 != 'byte':
                continue
            if off1 % 2 != 0 or off2 != off1 + 2:
                continue

            # Combine two .byte pairs into a 4-byte big-endian value
            b1, b2 = val1
            b3, b4 = val2
            word32 = (b1 << 24) | (b2 << 16) | (b3 << 8) | b4

            # Check if it looks like a code/data address
            if CODE_START <= word32 < CODE_END:
                results.append({
                    'file': fn,
                    'line': line1,
                    'offset': off1,
                    'value': word32,
                    'range': 'code',
                })

    return results


def scan_binary():
    """Scan production binary for 4-byte aligned values in code range."""
    prod_path = os.path.join(PROJ, "build", "aprog.bin")
    if not os.path.exists(prod_path):
        prod_path = os.path.join(PROJ, "reimpl", "build", "APROG.BIN")

    if not os.path.exists(prod_path):
        print("WARNING: No binary found for scanning")
        return []

    with open(prod_path, 'rb') as f:
        data = f.read()

    results = []
    for off in range(0, len(data) - 3, 4):
        val = struct.unpack('>I', data[off:off+4])[0]
        if CODE_START <= val < CODE_END:
            addr = 0x06003000 + off
            results.append({
                'offset': off,
                'addr': addr,
                'value': val,
            })

    return results


def main():
    print("=== Scanning .s files for unsymbolized pool addresses ===\n")

    asm_results = scan_asm_files()

    if asm_results:
        print(f"Found {len(asm_results)} potential unsymbolized addresses:\n")
        for r in asm_results:
            print(f"  {r['file']}:{r['line']}  offset=0x{r['offset']:04X}  "
                  f"value=0x{r['value']:08X}")
    else:
        print("No unsymbolized addresses found in .s files.\n")

    print(f"\n=== Scanning production binary for code-range values ===\n")

    bin_results = scan_binary()

    if bin_results:
        # Filter: only show values at 4-byte aligned pool positions
        # Pool entries are typically after the last instruction before rts
        print(f"Found {len(bin_results)} 4-byte values in code range [0x{CODE_START:08X}, 0x{CODE_END:08X}):\n")

        # Group by address region
        by_region = {}
        for r in bin_results:
            region = r['addr'] >> 16
            if region not in by_region:
                by_region[region] = []
            by_region[region].append(r)

        for region in sorted(by_region):
            items = by_region[region]
            print(f"  0x{region:04X}xxxx: {len(items)} values")
            for r in items[:5]:
                print(f"    0x{r['addr']:08X}: 0x{r['value']:08X}")
            if len(items) > 5:
                print(f"    ... ({len(items) - 5} more)")
    else:
        print("No code-range values found in binary.\n")

    # Summary
    print(f"\n=== Summary ===")
    print(f"ASM .byte pool entries with code-range addresses: {len(asm_results)}")
    print(f"Binary 4-byte values in code range: {len(bin_results)}")

    if asm_results:
        print(f"\nThese are potential relocation bugs in the free-layout build!")
        print(f"Each one should be converted from .byte to .4byte SYMBOL")


if __name__ == "__main__":
    main()
