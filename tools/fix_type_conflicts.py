#!/usr/bin/env python3
"""Fix type conflicts in batch_*.c files.

Two types of conflicts:
1. extern says 'int', definition says something else -> fix extern
2. definition says 'void', caller assigns return value -> change void to int
"""

import os
import re

REIMPL_DIR = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "reimpl", "src")

def fix_file(filepath):
    with open(filepath, 'r', errors='replace') as f:
        content = f.read()

    lines = content.split('\n')

    # Pass 1: Find all function definitions and their types
    func_defs = {}  # fname -> (return_type, line_number)
    for i, line in enumerate(lines):
        stripped = line.strip()
        if stripped.startswith('extern'):
            continue
        # Match function definitions
        m = re.match(r'^((?:unsigned\s+)?(?:long\s+long|int|short|char|void)(?:\s*\*)?)\s+(FUN_[0-9A-Fa-f]+)\s*\(', stripped)
        if m:
            ret_type = m.group(1).strip()
            fname = m.group(2).lower()
            func_defs[fname] = (ret_type, i)

    # Pass 2: Find all function calls that assign to a variable
    called_with_return = set()
    for line in lines:
        stripped = line.strip()
        # Pattern: var = FUN_XXX(...)
        m = re.search(r'\w+\s*=\s*(FUN_[0-9A-Fa-f]+)\s*\(', stripped)
        if m:
            called_with_return.add(m.group(1).lower())

    fixes = 0

    # Fix: void functions called with return value -> change to int
    for fname in called_with_return:
        if fname in func_defs and func_defs[fname][0] == 'void':
            line_num = func_defs[fname][1]
            old_line = lines[line_num]
            # Change "void FUN_XXX(" to "int FUN_XXX("
            new_line = re.sub(r'\bvoid\b(\s+FUN_)', r'int\1', old_line, count=1)
            if old_line != new_line:
                lines[line_num] = new_line
                func_defs[fname] = ('int', line_num)
                fixes += 1

    # Fix: K&R style definitions that don't match externs
    # Pattern: "FUN_XXX(param_1, param_2)\n    int param_1;"
    # These need the return type added

    # Pass 3: Fix extern declarations to match (now potentially updated) definitions
    for i, line in enumerate(lines):
        stripped = line.strip()
        if not stripped.startswith('extern'):
            continue
        m = re.search(r'(FUN_[0-9A-Fa-f]+)', stripped)
        if not m:
            continue
        fname = m.group(1).lower()
        if fname not in func_defs:
            continue
        actual_type = func_defs[fname][0]
        # Extract current extern type
        em = re.match(r'^extern\s+((?:unsigned\s+)?(?:long\s+long|int|short|char|void)(?:\s*\*)?)\s+FUN_', stripped)
        if em:
            extern_type = em.group(1).strip()
            if extern_type != actual_type:
                new_line = re.sub(
                    r'^(\s*extern\s+)\S+(?:\s+\S+)?(\s+FUN_)',
                    f'\\1{actual_type}\\2',
                    line
                )
                # More robust replacement
                new_line = line.replace(f'extern {extern_type}', f'extern {actual_type}', 1)
                if line != new_line:
                    lines[i] = new_line
                    fixes += 1

    if fixes > 0:
        with open(filepath, 'w', newline='\n') as f:
            f.write('\n'.join(lines))
        print(f"  {os.path.basename(filepath)}: {fixes} fixes")

    return fixes

def main():
    total = 0
    for fname in sorted(os.listdir(REIMPL_DIR)):
        if not fname.startswith('batch_') or not fname.endswith('.c'):
            continue
        total += fix_file(os.path.join(REIMPL_DIR, fname))
    print(f"\nTotal: {total} fixes")

if __name__ == "__main__":
    main()
