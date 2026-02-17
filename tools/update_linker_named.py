#!/usr/bin/env python3
"""update_linker_named.py -- Add named function sections to linker script.

Named L2+ functions compile to .text.<named_func> sections which don't match
the .func_FUN_xxx entries in the linker script. This causes them to fall into
.text.overflow, destroying 78KB of data tables.

Fix: scan source files for alias declarations to build a mapping of
named → FUN_ address, then update the linker script to also capture
.text.<named_func> in the correct .func_FUN_xxx entry.

Usage: python tools/update_linker_named.py [--dry-run]
"""

import os
import re
import sys

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC_DIR = os.path.join(PROJ, "reimpl", "src")
LD_SCRIPT = os.path.join(PROJ, "reimpl", "saturn_fixed.ld")


def scan_alias_map():
    """Scan source files for alias declarations and build named → FUN_ map."""
    # Pattern: TYPE FUN_xxx(...) __attribute__((alias("named_func")));
    # Pattern: TYPE named_func(...) __attribute__((alias("FUN_xxx")));
    alias_re = re.compile(
        r'^\s*(?:void|int|unsigned\s+int|char\s*\*|short)\s+'
        r'([a-zA-Z_]\w+)\s*\([^)]*\)\s*__attribute__\s*\(\s*\(\s*alias\s*\(\s*"(\w+)"\s*\)\s*\)\s*\)',
        re.MULTILINE
    )
    # Skip common false positives (C types matched as names)
    SKIP_NAMES = {'int', 'void', 'char', 'short', 'unsigned', 'long', 'signed'}

    named_to_fun = {}  # named_func -> FUN_addr_hex (uppercase)

    for fname in sorted(os.listdir(SRC_DIR)):
        if not fname.endswith('.c'):
            continue
        fpath = os.path.join(SRC_DIR, fname)
        with open(fpath, 'r', errors='replace') as f:
            content = f.read()

        for m in alias_re.finditer(content):
            sym_name = m.group(1)
            alias_target = m.group(2)

            if sym_name in SKIP_NAMES or alias_target in SKIP_NAMES:
                continue
            if sym_name.startswith('FUN_') and not alias_target.startswith('FUN_'):
                # FUN_xxx is alias for named_func -> named_func at FUN_xxx address
                fun_addr = sym_name.upper()
                named = alias_target
                named_to_fun[named] = fun_addr
            elif alias_target.startswith('FUN_') and not sym_name.startswith('FUN_'):
                # named_func is alias for FUN_xxx -> named_func at FUN_xxx address
                fun_addr = alias_target.upper()
                named = sym_name
                named_to_fun[named] = fun_addr

    return named_to_fun


def scan_function_defs():
    """Scan source files for all function definitions to find named functions
    that might not have explicit aliases but are defined as replacements."""
    # Look for comments like "/* FUN_0601xxxx: named version */" or similar patterns
    # Also look for wrapper patterns like: void FUN_xxx() { named_func(); }
    wrapper_re = re.compile(
        r'(?:void|int|unsigned\s+int)\s+(FUN_[0-9a-fA-F]+)\s*\(\s*(?:void)?\s*\)\s*\{\s*'
        r'(\w+)\s*\(',
        re.MULTILINE
    )

    wrappers = {}  # named_func -> FUN_addr

    for fname in sorted(os.listdir(SRC_DIR)):
        if not fname.endswith('.c'):
            continue
        fpath = os.path.join(SRC_DIR, fname)
        with open(fpath, 'r', errors='replace') as f:
            content = f.read()

        for m in wrapper_re.finditer(content):
            fun_name = m.group(1).upper()
            called = m.group(2)
            # Skip if the called function is also a FUN_
            if not called.startswith('FUN_') and called not in ('if', 'while', 'for', 'return', 'switch'):
                wrappers[called] = fun_name

    return wrappers


def update_linker_script(named_to_fun, dry_run=False):
    """Update the linker script to capture named function sections."""
    with open(LD_SCRIPT, 'r') as f:
        content = f.read()

    # Build a reverse map: FUN_XXXXXXXX -> [named1, named2, ...]
    fun_to_named = {}
    for named, fun in named_to_fun.items():
        fun_to_named.setdefault(fun, []).append(named)

    changes = 0
    lines = content.split('\n')
    new_lines = []

    for i, line in enumerate(lines):
        new_lines.append(line)

        # Look for lines like: *(.text.FUN_XXXXXXXX)
        m = re.match(r'(\s+)\*\(\.text\.(FUN_[0-9a-fA-F]+)\)', line)
        if m:
            indent = m.group(1)
            fun_name = m.group(2).upper()
            if fun_name in fun_to_named:
                for named in fun_to_named[fun_name]:
                    entry = f'{indent}*(.text.{named})'
                    # Check if already present
                    if entry not in content:
                        new_lines.append(entry)
                        changes += 1

    if changes > 0 and not dry_run:
        with open(LD_SCRIPT, 'w') as f:
            f.write('\n'.join(new_lines))

    return changes


def main():
    dry_run = '--dry-run' in sys.argv

    print("Scanning source files for alias declarations...")
    named_to_fun = scan_alias_map()
    print(f"  Found {len(named_to_fun)} named → FUN_ mappings")

    print("\nScanning for wrapper function patterns...")
    wrappers = scan_function_defs()
    print(f"  Found {len(wrappers)} wrapper → FUN_ mappings")

    # Merge (alias map takes priority)
    for named, fun in wrappers.items():
        if named not in named_to_fun:
            named_to_fun[named] = fun

    print(f"\nTotal named → FUN_ mappings: {len(named_to_fun)}")

    # Show all mappings
    for named in sorted(named_to_fun.keys()):
        fun = named_to_fun[named]
        print(f"  {named} → {fun}")

    print(f"\nUpdating linker script...")
    changes = update_linker_script(named_to_fun, dry_run=dry_run)
    if dry_run:
        print(f"  Would add {changes} section entries (dry run)")
    else:
        print(f"  Added {changes} section entries")

    return changes


if __name__ == '__main__':
    main()
