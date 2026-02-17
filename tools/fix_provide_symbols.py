#!/usr/bin/env python3
"""Fix PROVIDE symbols in linker scripts to be relocatable.

Problem: PROVIDE(sym_X = 0xABCDEF) creates an ABSOLUTE symbol. When the binary
content shifts (free-layout), the data at 0xABCDEF moves but the symbol doesn't.

Fix: For in-binary addresses, change to PROVIDE(sym_X = FUN_parent + offset).
Since FUN_parent is a section label (relocatable), the expression is also
relocatable. The linker will adjust sym_X when FUN_parent moves.

Addresses outside the binary are runtime data (work RAM, hardware registers)
that don't move when the binary shifts -- these stay absolute.
"""

import re
import sys
import os

def load_fun_addrs(path):
    """Load FUN_ addresses from aprog_syms.txt, return sorted list of (addr, name)."""
    entries = []
    with open(path) as f:
        for line in f:
            m = re.match(r'(FUN_[0-9A-Fa-f]+)\s*=\s*0x([0-9A-Fa-f]+)', line)
            if m:
                name = m.group(1)
                addr = int(m.group(2), 16)
                entries.append((addr, name))
    entries.sort()
    return entries

def find_parent_fun(addr, fun_entries):
    """Find the largest FUN_ address <= addr. Returns (addr, name) or None."""
    lo, hi = 0, len(fun_entries) - 1
    result = None
    while lo <= hi:
        mid = (lo + hi) // 2
        if fun_entries[mid][0] <= addr:
            result = mid
            lo = mid + 1
        else:
            hi = mid - 1
    if result is not None:
        return fun_entries[result]
    return None

def fix_linker_script(ld_path, fun_entries, binary_end):
    """Fix PROVIDE symbols in a linker script.

    Args:
        ld_path: Path to linker script
        fun_entries: Sorted list of (addr, name) for FUN_ symbols
        binary_end: End address of binary content (exclusive)

    Returns:
        (fixed_count, total_provide_count)
    """
    first_fun_addr = fun_entries[0][0]  # 0x060030FC -- _start section is before this

    with open(ld_path) as f:
        content = f.read()

    lines = content.splitlines(keepends=True)

    fixed = 0
    total = 0
    new_lines = []

    for line in lines:
        # Match PROVIDE lines -- handle both sym_ and DAT_ and loc_ prefixes
        m = re.match(r'(PROVIDE\()(\w+)(\s*=\s*)0x([0-9A-Fa-f]+)(\);.*)', line)
        if m:
            total += 1
            prefix = m.group(1)
            sym_name = m.group(2)
            eq_part = m.group(3)
            addr_hex = m.group(4)
            suffix = m.group(5)
            addr = int(addr_hex, 16)

            # Only fix addresses within the binary, after _start section
            if first_fun_addr <= addr < binary_end:
                parent = find_parent_fun(addr, fun_entries)
                if parent is not None:
                    parent_addr, parent_name = parent
                    offset = addr - parent_addr
                    new_line = f"{prefix}{sym_name}{eq_part}{parent_name} + 0x{offset:X}{suffix}\n"
                    new_lines.append(new_line)
                    fixed += 1
                    continue

        new_lines.append(line)

    with open(ld_path, 'w') as f:
        f.writelines(new_lines)

    return fixed, total

def main():
    proj_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

    # Load function addresses
    syms_path = os.path.join(proj_dir, 'build', 'aprog_syms.txt')
    fun_entries = load_fun_addrs(syms_path)
    print(f"Loaded {len(fun_entries)} FUN_ symbols")
    print(f"  First: {fun_entries[0][1]} = 0x{fun_entries[0][0]:08X}")
    print(f"  Last:  {fun_entries[-1][1]} = 0x{fun_entries[-1][0]:08X}")

    # Binary range
    binary_start = 0x06003000
    binary_size = 394896  # bytes
    binary_end = binary_start + binary_size  # 0x06063690
    print(f"Binary range: 0x{binary_start:08X} - 0x{binary_end:08X}")

    # Fix both linker scripts
    for ld_name in ['sawyer.ld', 'sawyer_free.ld']:
        ld_path = os.path.join(proj_dir, 'reimpl', ld_name)
        if os.path.exists(ld_path):
            fixed, total = fix_linker_script(ld_path, fun_entries, binary_end)
            print(f"\n{ld_name}:")
            print(f"  Total PROVIDE lines: {total}")
            print(f"  Fixed (in-binary -> relative): {fixed}")
            print(f"  Kept absolute (outside binary): {total - fixed}")
        else:
            print(f"\n{ld_name}: NOT FOUND")

if __name__ == '__main__':
    main()
