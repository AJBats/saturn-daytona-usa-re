#!/usr/bin/env python3
"""Fix pointer-from-integer warnings by adding explicit casts.

Pattern: puVar = 0xNNNNNNNN; (where puVar is char */short */int */etc.)
Fix: puVar = (char *)0xNNNNNNNN;

Also fixes:
- 'return' with no value in non-void functions -> return 0;
- in_sr uninitialized -> add = 0
"""

import os
import re

REIMPL_DIR = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "reimpl", "src")

def fix_ptr_assignments(content):
    """Fix patterns like 'puVar = 0xNNNN;' where puVar is a pointer."""
    fixes = 0

    # Find all pointer variable declarations
    ptr_vars = set()
    for m in re.finditer(r'^\s+(\w+\s*\*+)\s*(\w+)\s*;', content, re.MULTILINE):
        var_name = m.group(2)
        var_type = m.group(1).strip()
        ptr_vars.add((var_name, var_type))

    # Also catch K&R param declarations
    for m in re.finditer(r'^\s+(\w+\s*\*+)\s*(\w+)\s*;', content, re.MULTILINE):
        ptr_vars.add((m.group(2), m.group(1).strip()))

    # Fix assignments of integer constants to pointer variables
    for var_name, var_type in ptr_vars:
        # Pattern: var = 0xNNNN;  or var = expr + 0xNNNN;
        pattern = re.compile(
            r'(\b' + re.escape(var_name) + r'\s*=\s*)(0x[0-9A-Fa-f]+)\s*;'
        )
        for m in reversed(list(pattern.finditer(content))):
            old = m.group(0)
            addr = m.group(2)
            new = f'{m.group(1)}({var_type}){addr};'
            if old != new:
                content = content[:m.start()] + new + content[m.end():]
                fixes += 1

    return content, fixes

def fix_return_void(content):
    """Fix 'return;' in non-void functions."""
    fixes = 0
    lines = content.split('\n')
    current_func_is_void = True

    for i, line in enumerate(lines):
        stripped = line.strip()
        # Detect function definition
        m = re.match(r'^((?:unsigned\s+)?(?:long\s+long|int|short|char)(?:\s*\*)*)\s+FUN_', stripped)
        if m:
            current_func_is_void = False
        elif re.match(r'^void\s+FUN_', stripped):
            current_func_is_void = True

        # Fix return; in non-void functions
        if stripped == 'return;' and not current_func_is_void:
            lines[i] = line.replace('return;', 'return 0;')
            fixes += 1

    return '\n'.join(lines), fixes

def fix_in_sr(content):
    """Fix 'int in_sr;' -> 'int in_sr = 0;'"""
    fixes = 0
    pattern = re.compile(r'^(\s+)(int|unsigned int) (in_sr);$', re.MULTILINE)
    for m in reversed(list(pattern.finditer(content))):
        new = f'{m.group(1)}{m.group(2)} {m.group(3)} = 0;'
        content = content[:m.start()] + new + content[m.end():]
        fixes += 1
    return content, fixes

def fix_in_stack(content):
    """Fix 'int in_stack_NNNNN;' -> 'int in_stack_NNNNN = 0;'"""
    fixes = 0
    pattern = re.compile(r'^(\s+)(int|unsigned int|char|short) (in_stack_\w+);$', re.MULTILINE)
    for m in reversed(list(pattern.finditer(content))):
        new = f'{m.group(1)}{m.group(2)} {m.group(3)} = 0;'
        content = content[:m.start()] + new + content[m.end():]
        fixes += 1
    return content, fixes

def fix_file(filepath):
    with open(filepath, 'r', errors='replace') as f:
        content = f.read()

    original = content
    total = 0

    content, n = fix_ptr_assignments(content)
    total += n

    content, n = fix_return_void(content)
    total += n

    content, n = fix_in_sr(content)
    total += n

    content, n = fix_in_stack(content)
    total += n

    if content != original:
        with open(filepath, 'w', newline='\n') as f:
            f.write(content)
        print(f"  {os.path.basename(filepath)}: {total} fixes")

    return total

def main():
    total = 0
    for fname in sorted(os.listdir(REIMPL_DIR)):
        if not fname.endswith('.c'):
            continue
        if not fname.startswith('batch_'):
            continue
        total += fix_file(os.path.join(REIMPL_DIR, fname))
    print(f"\nTotal: {total} fixes")

if __name__ == "__main__":
    main()
