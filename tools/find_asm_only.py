#!/usr/bin/env python3
"""Find functions that exist in the binary but have no decomp source.

These are in build/aprog.s (1234 labels) but not in src/FUN_*.c (883 files).
"""

import os
import re

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def get_aprog_functions():
    """Get all function labels from aprog.s."""
    funcs = {}
    aprog_path = os.path.join(PROJ, "build", "aprog.s")
    with open(aprog_path, 'r', errors='replace') as f:
        for line in f:
            line = line.strip()
            m = re.match(r'^(FUN_[0-9A-Fa-f]{8}):$', line)
            if m:
                addr = m.group(1)
                funcs[addr.lower()] = addr
    return funcs

def get_decomp_functions():
    """Get all functions that have decomp C source."""
    funcs = set()
    src_dir = os.path.join(PROJ, "src")
    for fname in os.listdir(src_dir):
        m = re.match(r'FUN_([0-9A-Fa-f]{8})\.c$', fname, re.IGNORECASE)
        if m:
            funcs.add(f'fun_{m.group(1).lower()}')
    return funcs

def get_reimpl_functions():
    """Get all functions already in reimpl."""
    funcs = set()
    reimpl_dir = os.path.join(PROJ, "reimpl", "src")
    for fname in os.listdir(reimpl_dir):
        if not fname.endswith('.c'):
            continue
        filepath = os.path.join(reimpl_dir, fname)
        with open(filepath, 'r', errors='replace') as f:
            content = f.read()
        for m in re.finditer(r'\b(FUN_[0-9A-Fa-f]{8})\b', content):
            funcs.add(m.group(1).lower())
    return funcs

def get_function_size(addr_str):
    """Get size of function from aprog.s by counting instructions."""
    aprog_path = os.path.join(PROJ, "build", "aprog.s")
    in_func = False
    count = 0
    label = f'{addr_str}:'

    with open(aprog_path, 'r', errors='replace') as f:
        for line in f:
            stripped = line.strip()
            if stripped == label:
                in_func = True
                count = 0
                continue
            if in_func:
                if stripped.endswith(':') and stripped != label:
                    break
                if stripped and not stripped.startswith('.') and not stripped.startswith('!'):
                    count += 1
    return count

def main():
    aprog = get_aprog_functions()
    decomp = get_decomp_functions()
    reimpl = get_reimpl_functions()

    print(f"aprog.s labels: {len(aprog)}")
    print(f"decomp src files: {len(decomp)}")
    print(f"reimpl references: {len(reimpl)}")

    # Find ASM-only functions (in aprog.s but not in src/*.c)
    asm_only = []
    for addr_lower, addr_orig in sorted(aprog.items()):
        if addr_lower not in decomp:
            asm_only.append(addr_orig)

    print(f"\nASM-only functions: {len(asm_only)}")

    # Check which are already in reimpl
    in_reimpl = 0
    not_in_reimpl = []
    for addr in asm_only:
        if addr.lower() in reimpl:
            in_reimpl += 1
        else:
            not_in_reimpl.append(addr)

    print(f"Already in reimpl: {in_reimpl}")
    print(f"Need translation: {len(not_in_reimpl)}")

    # Show the functions with their sizes
    print("\n=== ASM-only functions needing translation ===")
    for addr in not_in_reimpl[:100]:
        size = get_function_size(addr)
        print(f"  {addr}: {size} instructions")

if __name__ == "__main__":
    main()
