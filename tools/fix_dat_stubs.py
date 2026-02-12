#!/usr/bin/env python3
"""fix_dat_stubs.py -- Fix DAT_/PTR_DAT_ linker stubs with actual constant pool values.

Reads the original binary (aprog.bin) to look up the actual values stored at each
constant pool address, then updates linker_stubs.c with the correct values.

Uses instruction-level analysis to determine load width:
  - Scans all SH-2 mov.w and mov.l instructions in the binary
  - mov.w @(disp,PC),Rn → 16-bit constant pool entry, sign-extended
  - mov.l @(disp,PC),Rn → 32-bit constant pool entry
  - Builds definitive map of which pool addresses are 16-bit vs 32-bit
"""

import re
import struct

BINARY_PATH = "build/aprog.bin"
STUBS_PATH = "reimpl/src/linker_stubs.c"
BASE_ADDR = 0x06003000


def scan_constant_pool_refs(binary, base):
    """Scan all SH-2 instructions to find mov.w and mov.l PC-relative loads.
    Returns dict mapping pool address -> 'w' (16-bit) or 'l' (32-bit)."""
    pool_width = {}

    for offset in range(0, len(binary) - 1, 2):
        pc = base + offset
        insn = (binary[offset] << 8) | binary[offset + 1]

        # mov.w @(disp,PC), Rn  →  opcode 1001 nnnn dddddddd
        if (insn >> 12) == 0x9:
            disp = insn & 0xFF
            ea = pc + disp * 2 + 4
            pool_width[ea] = 'w'

        # mov.l @(disp,PC), Rn  →  opcode 1101 nnnn dddddddd
        elif (insn >> 12) == 0xD:
            disp = insn & 0xFF
            ea = (pc & ~3) + disp * 4 + 4
            pool_width[ea] = 'l'

    return pool_width


def main():
    # Read binary
    with open(BINARY_PATH, "rb") as f:
        binary = f.read()

    # Build instruction-level constant pool map
    print("Scanning SH-2 instructions for constant pool references...")
    pool_width = scan_constant_pool_refs(binary, BASE_ADDR)
    w_count = sum(1 for v in pool_width.values() if v == 'w')
    l_count = sum(1 for v in pool_width.values() if v == 'l')
    print(f"Found {w_count} mov.w pool refs, {l_count} mov.l pool refs")

    # Read stubs file
    with open(STUBS_PATH, "r") as f:
        lines = f.readlines()

    # Parse and update entries
    entry_pat = re.compile(
        r'^int (DAT_|PTR_DAT_)([0-9a-f]+)\s*=\s*(-?(?:0x[0-9a-fA-F]+|\d+))\s*;'
    )

    updated = 0
    skipped = 0
    out_of_range = 0
    unknown_width = 0
    new_lines = []

    for line in lines:
        m = entry_pat.match(line.strip())
        if not m:
            new_lines.append(line)
            continue

        prefix = m.group(1)
        addr = int(m.group(2), 16)

        offset = addr - BASE_ADDR
        if offset < 0 or offset + 4 > len(binary):
            new_lines.append(line)
            out_of_range += 1
            continue

        # Determine width from instruction scan
        width = pool_width.get(addr)

        if width == 'w':
            # 16-bit mov.w: read signed short, sign-extend to int
            val_int = struct.unpack(">h", binary[offset:offset + 2])[0]
        elif width == 'l':
            # 32-bit mov.l: read full 32-bit value
            val = struct.unpack(">I", binary[offset:offset + 4])[0]
            val_int = val - 0x100000000 if val >= 0x80000000 else val
        else:
            # Address not found in instruction scan — might be unreferenced
            # or referenced indirectly. Default to 16-bit (safer for offsets).
            val_int = struct.unpack(">h", binary[offset:offset + 2])[0]
            unknown_width += 1

        # Format the value
        if val_int == 0:
            new_lines.append(line)
            skipped += 1
            continue

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
    print(f"Unknown width (defaulted to 16-bit): {unknown_width}")
    print(f"Total entries: {updated + skipped + out_of_range}")


if __name__ == "__main__":
    main()
