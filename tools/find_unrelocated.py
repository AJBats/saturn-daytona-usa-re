#!/usr/bin/env python3
"""find_unrelocated.py - Find unsymbolized addresses in free-layout binary.

Compares production and free-layout binaries to find 4-byte values in the
code/data range that should have shifted +4 but didn't (unrelocated addresses).

These are pool entries encoded as .byte instead of .4byte SYMBOL.
"""

import struct
import sys
import os

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

PROD = os.path.join(PROJ, "build", "disc", "files", "APROG.BIN")
FREE = os.path.join(PROJ, ".tmp", "APROG_free.BIN")

BASE = 0x06003000
CODE_START = 0x06003100   # First FUN_ section (after _start + 4-byte pad)
CODE_END   = 0x06063690   # BSS start

SHIFT = 4  # Free build shifts all FUN_ sections by +4


def main():
    with open(PROD, 'rb') as f:
        prod = f.read()
    with open(FREE, 'rb') as f:
        free = f.read()

    print(f"Production: {len(prod)} bytes")
    print(f"Free:       {len(free)} bytes")
    print(f"Code range: [0x{CODE_START:08X}, 0x{CODE_END:08X})")
    print()

    relocated = []      # Values that correctly shifted +4
    unrelocated = []    # Values in code range that stayed the same (BUG)
    data_vals = []      # Unchanged values NOT in code range (fine)

    # Compare the shifted region (production offset 0xFC+ = free offset 0x100+)
    start_offset = 0xFC  # Start of first FUN_ section in production
    end_offset = len(prod) - 3  # Need 4 bytes

    for off in range(start_offset, end_offset, 4):
        prod_val = struct.unpack('>I', prod[off:off+4])[0]
        free_off = off + SHIFT
        if free_off + 4 > len(free):
            break
        free_val = struct.unpack('>I', free[free_off:free_off+4])[0]

        addr = BASE + off  # Address in production memory

        if free_val == prod_val + SHIFT:
            # Correctly relocated
            relocated.append((off, addr, prod_val, free_val))
        elif free_val == prod_val:
            # Unchanged
            if CODE_START <= prod_val < CODE_END:
                # Value is in code range but wasn't relocated - POTENTIAL BUG
                unrelocated.append((off, addr, prod_val))
            else:
                data_vals.append((off, addr, prod_val))
        else:
            # Something unexpected
            pass  # Ignore for now

    print(f"Relocated +4:    {len(relocated):6d} (correct)")
    print(f"Unrelocated:     {len(unrelocated):6d} (potential bugs - in code range, didn't shift)")
    print(f"Data/constant:   {len(data_vals):6d} (not in code range, fine)")
    print()

    if unrelocated:
        print("=== UNRELOCATED ADDRESS REFERENCES ===\n")
        print("These 4-byte values are in the code range but didn't shift +4.")
        print("They may be unsymbolized pool entries or false positives (data).\n")

        # Cross-reference with aprog.s disassembly to check if they're real pool entries
        for off, addr, val in unrelocated:
            print(f"  offset=0x{off:05X}  addr=0x{addr:08X}  value=0x{val:08X}")

        print(f"\nTotal: {len(unrelocated)} unrelocated code-range values")

        # Also check: are any of these in known function pool areas?
        # A pool entry at offset X is used by MOV.L @(disp,PC),Rn where
        # the instruction is within ~1020 bytes before X
        print("\n=== Cross-reference with known FUN_ boundaries ===\n")

        # Load the symbol map to find function boundaries
        map_file = os.path.join(PROJ, "reimpl", "build", "daytona.map")
        func_ranges = []
        if os.path.exists(map_file):
            import re
            with open(map_file, 'r') as f:
                for line in f:
                    m = re.match(r'\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)\s+.*/(FUN_[0-9A-F]+)\.o', line)
                    if m:
                        faddr = int(m.group(1), 16)
                        fsize = int(m.group(2), 16)
                        fname = m.group(3)
                        # In the free build, addresses are shifted +4
                        # But in the production binary, they're at original addresses
                        # Map back: prod_addr = free_addr - 4
                        prod_addr = faddr - SHIFT
                        func_ranges.append((prod_addr, fsize, fname))

        if func_ranges:
            for off, addr, val in unrelocated:
                # Find which function this offset belongs to
                for faddr, fsize, fname in func_ranges:
                    if faddr <= addr < faddr + fsize:
                        foff = addr - faddr  # Offset within function
                        print(f"  0x{addr:08X}: 0x{val:08X}  in {fname}+0x{foff:X} (func size=0x{fsize:X})")
                        break
                else:
                    print(f"  0x{addr:08X}: 0x{val:08X}  (not in any function)")


if __name__ == "__main__":
    main()
