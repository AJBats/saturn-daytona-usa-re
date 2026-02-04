#!/usr/bin/env python3
"""Resolve PTR_DAT_ references to their actual constant pool values.

Reads the disassembly to find 16-bit constant pool values, then replaces
PTR_DAT_ADDR references in C source files with literal values.

Only replaces references where the PTR_DAT_ address falls within the function's
own constant pool (between the function end and next function start).
"""

import re
import os
import sys

def build_word_map(aprog_path):
    """Parse aprog.s to build a map of address -> 16-bit value."""
    word_map = {}
    with open(aprog_path, 'r') as f:
        for line in f:
            # Match: .byte 0xHH, 0xLL  /* ADDR: .word 0xVALUE */
            m = re.search(r'/\*\s*([0-9A-Fa-f]+):\s*\.word\s+(0x[0-9A-Fa-f]+)', line)
            if m:
                addr = int(m.group(1), 16)
                value = int(m.group(2), 16)
                word_map[addr] = value
    return word_map

def build_function_ranges(syms_path):
    """Parse aprog_syms.txt to build function address ranges."""
    funcs = []
    with open(syms_path, 'r') as f:
        for line in f:
            # Format: FUN_ADDR = 0xADDR;
            m = re.search(r'(FUN_[0-9A-Fa-f]+)\s*=\s*0x([0-9A-Fa-f]+)', line)
            if m:
                name = m.group(1)
                addr = int(m.group(2), 16)
                funcs.append((addr, name))
    funcs.sort()
    return funcs

def get_function_end(func_addr, funcs):
    """Get the address of the next function (approximate end of current function + pool)."""
    for i, (addr, name) in enumerate(funcs):
        if addr == func_addr and i + 1 < len(funcs):
            return funcs[i + 1][0]
    return func_addr + 0x1000  # fallback

def process_file(filepath, word_map, funcs):
    """Process a single C file, replacing PTR_DAT_ with literal values."""
    with open(filepath, 'r') as f:
        text = f.read()

    # Get function name/address from filename
    base = os.path.basename(filepath).replace('.c', '')
    m = re.match(r'FUN_([0-9A-Fa-f]+)', base, re.IGNORECASE)
    if not m:
        return False, 0

    func_addr = int(m.group(1), 16)
    func_end = get_function_end(func_addr, funcs)
    # Extend range to catch shared constant pools (fall-through functions)
    pool_end = func_end + 0x200

    # Find all PTR_DAT_ and DAT_ references
    changes = 0
    new_text = text

    # Pattern 1: (int)PTR_DAT_ADDR or (int)DAT_ADDR - cast to int, likely 16-bit constant
    def replace_int_cast(match):
        nonlocal changes
        addr_hex = match.group(1).lower()
        addr = int(addr_hex, 16)

        # Check if address is in function's constant pool range (extended)
        if addr < func_addr or addr >= pool_end:
            return match.group(0)  # outside range, keep as-is

        # Look up 16-bit value
        if addr in word_map:
            val = word_map[addr]
            # Sign-extend if needed (mov.w sign-extends)
            if val > 0x7FFF:
                val = val - 0x10000
            changes += 1
            if val < 0:
                return str(val)
            else:
                return '0x%x' % val
        return match.group(0)

    new_text = re.sub(r'\(int\)\s*(?:PTR_)?DAT_([0-9A-Fa-f]+)', replace_int_cast, new_text)

    # Pattern 2: (short)PTR_DAT_ADDR or (unsigned short)PTR_DAT_ADDR
    def replace_short_cast(match):
        nonlocal changes
        cast = match.group(1)
        addr_hex = match.group(2).lower()
        addr = int(addr_hex, 16)

        if addr < func_addr or addr >= pool_end:
            return match.group(0)

        if addr in word_map:
            val = word_map[addr]
            changes += 1
            if 'unsigned' in cast:
                return '0x%x' % val
            else:
                if val > 0x7FFF:
                    val = val - 0x10000
                return str(val) if val < 0 else '0x%x' % val
        return match.group(0)

    new_text = re.sub(r'\(((?:unsigned )?short)\)\s*(?:PTR_)?DAT_([0-9A-Fa-f]+)', replace_short_cast, new_text)

    # Remove extern declarations for resolved DAT_/PTR_DAT_ symbols
    if changes > 0:
        # Find which symbols were resolved
        resolved = set()
        for m in re.finditer(r'(?:PTR_)?DAT_([0-9A-Fa-f]+)', text):
            addr = int(m.group(1), 16)
            if func_addr <= addr < pool_end and addr in word_map:
                resolved.add(m.group(0))

        # Check if any references remain unresolved
        remaining = set()
        for m in re.finditer(r'(?:PTR_)?DAT_([0-9A-Fa-f]+)', new_text):
            remaining.add(m.group(0))

        # Remove extern lines for fully resolved symbols
        for sym in resolved:
            if sym not in remaining:
                new_text = re.sub(r'extern\s+\w+\s+' + re.escape(sym) + r'\s*;\s*\n', '', new_text)

    if new_text != text:
        with open(filepath, 'w') as f:
            f.write(new_text)
        return True, changes
    return False, 0

def main():
    base_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    aprog_path = os.path.join(base_dir, 'build', 'aprog.s')
    syms_path = os.path.join(base_dir, 'build', 'aprog_syms.txt')
    src_dir = os.path.join(base_dir, 'src')

    print("Building constant pool map from aprog.s...")
    word_map = build_word_map(aprog_path)
    print(f"  Found {len(word_map)} constant pool entries")

    print("Building function ranges from aprog_syms.txt...")
    funcs = build_function_ranges(syms_path)
    print(f"  Found {len(funcs)} functions")

    print("Processing C source files...")
    total_changed = 0
    total_fixes = 0
    import glob
    for filepath in sorted(glob.glob(os.path.join(src_dir, '*.c'))):
        changed, fixes = process_file(filepath, word_map, funcs)
        if changed:
            total_changed += 1
            total_fixes += fixes
            print(f"  {os.path.basename(filepath)}: {fixes} replacements")

    print(f"\n=== SUMMARY ===")
    print(f"Files modified: {total_changed}")
    print(f"Total replacements: {total_fixes}")

if __name__ == '__main__':
    main()
