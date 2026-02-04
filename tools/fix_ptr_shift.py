#!/usr/bin/env python3
"""Fix invalid 'pointer << N' by casting pointer variables to (int).

The mul-to-shift tool converted ptr * N to (ptr << log2(N)), which fails
because << doesn't do implicit pointer-to-int conversion like * does.
This tool finds pointer variables and adds (int) casts.
"""

import re
import os
import glob


def find_pointer_vars(text):
    """Find all variable names declared as pointer types in the source."""
    ptrs = set()
    # Match declarations like: type *varname; or type *varname,
    # K&R style and ANSI style
    # Pattern: word followed by * followed by identifier
    for m in re.finditer(r'\b(?:char|int|short|unsigned\s+short|unsigned\s+int|void)\s*\*+\s*(\w+)', text):
        ptrs.add(m.group(1))
    # Also match Ghidra pointer naming convention: p[ucislfb]Var\d+
    for m in re.finditer(r'\b(p[ucislfb]Var\d+)\b', text):
        ptrs.add(m.group(1))
    return ptrs


def fix_ptr_shifts(text):
    """Add (int) cast to pointer variables used with << operator."""
    ptrs = find_pointer_vars(text)
    if not ptrs:
        return text, 0

    changes = 0

    def cast_ptr(m):
        nonlocal changes
        full = m.group(0)
        varname = m.group(1)
        shift_amt = m.group(2)

        if varname in ptrs:
            changes += 1
            return '((int)' + varname + ' << ' + shift_amt + ')'
        return full

    # Match (varname << N) patterns created by mul-to-shift tool
    new_text = re.sub(
        r'\((\w+) << (\d+)\)',
        cast_ptr,
        text
    )

    # Also match standalone varname << N (not in parens)
    def cast_ptr_bare(m):
        nonlocal changes
        pre = m.group(1)
        varname = m.group(2)
        shift_amt = m.group(3)

        if varname in ptrs:
            changes += 1
            return pre + '(int)' + varname + ' << ' + shift_amt
        return m.group(0)

    new_text = re.sub(
        r'(\W)(\w+)\s*<<\s*(\d+)',
        cast_ptr_bare,
        new_text
    )

    return new_text, changes


def process_file(filepath):
    """Apply ptr-shift fixes to a single file."""
    with open(filepath, 'r') as f:
        text = f.read()

    new_text, changes = fix_ptr_shifts(text)

    if new_text != text:
        with open(filepath, 'w') as f:
            f.write(new_text)
        return True, changes
    return False, 0


def main():
    srcdir = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'src')
    files = sorted(glob.glob(os.path.join(srcdir, '*.c')))

    total_changed = 0
    total_fixes = 0

    for filepath in files:
        changed, fixes = process_file(filepath)
        if changed:
            total_changed += 1
            total_fixes += fixes
            print(f"  {os.path.basename(filepath)}: {fixes} casts added")

    print(f"\n=== SUMMARY ===")
    print(f"Files modified: {total_changed}")
    print(f"Total casts added: {total_fixes}")


if __name__ == '__main__':
    main()
