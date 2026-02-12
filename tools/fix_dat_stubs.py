#!/usr/bin/env python3
"""fix_dat_stubs.py -- Fix DAT_/PTR_DAT_ linker stubs with actual constant pool values.

Reads the original binary (aprog.bin) to look up the actual values stored at each
constant pool address, then updates linker_stubs.c with the correct values.

SH-2 constant pool entries:
  - mov.w @(disp,PC), Rn : loads 16-bit value, sign-extends to 32-bit
  - mov.l @(disp,PC), Rn : loads 32-bit value, requires 4-byte alignment

Heuristic for determining width:
  - NOT 4-byte aligned → definitely 16-bit (mov.w)
  - 4-byte aligned WITH addr+2 also referenced → 16-bit (packed pair)
  - 4-byte aligned WITHOUT addr+2 referenced → 32-bit (mov.l)
  - PTR_DAT_ entries → always 32-bit (pointers)
"""

import re
import struct
import sys

BINARY_PATH = "build/aprog.bin"
STUBS_PATH = "reimpl/src/linker_stubs.c"
BASE_ADDR = 0x06003000

def main():
    # Read binary
    with open(BINARY_PATH, "rb") as f:
        binary = f.read()

    # Read stubs file
    with open(STUBS_PATH, "r") as f:
        lines = f.readlines()

    # First pass: collect all DAT_ addresses into a set
    addr_set = set()
    entry_pat = re.compile(r'^int (DAT_|PTR_DAT_)([0-9a-f]+)\s*=\s*(-?\d+|0x[0-9a-fA-F]+)\s*;')
    for line in lines:
        m = entry_pat.match(line.strip())
        if m:
            addr = int(m.group(2), 16)
            addr_set.add(addr)

    # Second pass: update values
    updated = 0
    skipped = 0
    out_of_range = 0
    new_lines = []

    for line in lines:
        m = entry_pat.match(line.strip())
        if not m:
            new_lines.append(line)
            continue

        prefix = m.group(1)  # "DAT_" or "PTR_DAT_"
        addr = int(m.group(2), 16)
        old_val = m.group(3)

        offset = addr - BASE_ADDR
        if offset < 0 or offset + 4 > len(binary):
            # Address outside binary range, keep as-is
            new_lines.append(line)
            out_of_range += 1
            continue

        # Determine value width
        if prefix == "PTR_DAT_":
            # PTR_DAT_ entries are always 32-bit (pointers/indirect refs)
            val = struct.unpack(">I", binary[offset:offset+4])[0]
            # Sign-extend if needed for int representation
            if val >= 0x80000000:
                val_int = val - 0x100000000
            else:
                val_int = val
        elif addr % 4 != 0:
            # Not 4-byte aligned → definitely 16-bit mov.w
            val16 = struct.unpack(">h", binary[offset:offset+2])[0]  # signed short
            val_int = val16  # sign-extended to int
        elif (addr + 2) in addr_set:
            # 4-byte aligned but addr+2 is also referenced → packed 16-bit pair
            val16 = struct.unpack(">h", binary[offset:offset+2])[0]  # signed short
            val_int = val16
        else:
            # 4-byte aligned, no adjacent reference → could be 32-bit mov.l
            val = struct.unpack(">I", binary[offset:offset+4])[0]
            if val >= 0x80000000:
                val_int = val - 0x100000000
            else:
                val_int = val

        # Format the value
        if val_int == 0:
            new_lines.append(line)
            skipped += 1
            continue

        # Use hex for values >= 256, decimal for small values
        if abs(val_int) >= 256:
            if val_int < 0:
                val_str = f"-0x{-val_int:X}"
            else:
                val_str = f"0x{val_int:X}"
        else:
            val_str = str(val_int)

        new_line = f"int {prefix}{addr:08x} = {val_str};\n"
        new_lines.append(new_line)
        updated += 1

    # Write output
    with open(STUBS_PATH, "w") as f:
        f.writelines(new_lines)

    print(f"Updated: {updated}")
    print(f"Already zero (kept): {skipped}")
    print(f"Out of range: {out_of_range}")
    print(f"Total entries: {updated + skipped + out_of_range}")

if __name__ == "__main__":
    main()
