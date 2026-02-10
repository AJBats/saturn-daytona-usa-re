#!/usr/bin/env python3
"""Fix extern declaration types to match actual function definitions.

Scans each batch_*.c file for conflicting extern/definition pairs
and corrects the extern declaration to match the definition.
"""

import os
import re
import sys

REIMPL_DIR = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "reimpl", "src")

def extract_return_type(line):
    """Extract return type from a function definition line."""
    line = line.strip()
    # Match: [type] FUN_XXXXXXXX(
    # Types: void, int, unsigned int, unsigned short, short, char, char *, long long, etc.
    m = re.match(r'^((?:unsigned\s+)?(?:long\s+long|int|short|char|void)(?:\s*\*)?)\s+FUN_', line)
    if m:
        return m.group(1).strip()
    return None

def fix_file(filepath):
    """Fix extern declarations in one file."""
    with open(filepath, 'r', errors='replace') as f:
        content = f.read()

    lines = content.split('\n')

    # Find all function definitions and their return types
    func_types = {}
    for line in lines:
        stripped = line.strip()
        # Skip extern lines
        if stripped.startswith('extern'):
            continue
        ret_type = extract_return_type(stripped)
        if ret_type:
            m = re.search(r'(FUN_[0-9A-Fa-f]+)', stripped)
            if m:
                func_types[m.group(1).lower()] = ret_type

    # Fix extern declarations
    fixes = 0
    new_lines = []
    for line in lines:
        stripped = line.strip()
        if stripped.startswith('extern'):
            m = re.search(r'(FUN_[0-9A-Fa-f]+)', stripped)
            if m:
                fname = m.group(1).lower()
                # Also check case-insensitive match
                fname_key = None
                for k in func_types:
                    if k == fname:
                        fname_key = k
                        break
                if fname_key and func_types[fname_key] != 'int':
                    actual_type = func_types[fname_key]
                    # Replace "extern int FUN_XXX()" with "extern <actual_type> FUN_XXX()"
                    old_extern = stripped
                    new_extern = re.sub(
                        r'^extern\s+\S+(\s+\*?\s*)(FUN_)',
                        f'extern {actual_type} \\2',
                        stripped
                    )
                    if old_extern != new_extern:
                        line = line.replace(old_extern, new_extern)
                        fixes += 1
        new_lines.append(line)

    if fixes > 0:
        with open(filepath, 'w', newline='\n') as f:
            f.write('\n'.join(new_lines))
        print(f"  Fixed {fixes} extern declarations in {os.path.basename(filepath)}")

    return fixes

def main():
    total_fixes = 0
    for fname in sorted(os.listdir(REIMPL_DIR)):
        if not fname.startswith('batch_') or not fname.endswith('.c'):
            continue
        filepath = os.path.join(REIMPL_DIR, fname)
        total_fixes += fix_file(filepath)

    print(f"\nTotal fixes: {total_fixes}")

if __name__ == "__main__":
    main()
