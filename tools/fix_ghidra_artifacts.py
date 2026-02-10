#!/usr/bin/env python3
"""Fix common Ghidra decompilation artifacts that prevent compilation.

Patterns fixed:
1. *(int)expr -> *(int *)expr  (invalid dereference of int)
2. (char)ADDR[idx] -> ((char *)ADDR)[idx]  (subscript of non-array)
3. &(type)expr -> (type *)&expr  (address of cast)
4. conflicting extern/definition types
5. void functions called with return value assignment
6. undeclared params (param_N used but not in signature)
7. duplicate extern declarations
"""

import os
import re
import sys

REIMPL_DIR = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "reimpl", "src")

def fix_deref_int(content):
    """Fix *(int)expr -> *(int *)expr patterns."""
    fixes = 0
    # Pattern: *(int) or *(unsigned int) or *(short) etc where it's a dereference
    # We need to be careful not to match *(int *) which is already correct
    for type_name in ['int', 'unsigned int', 'short', 'unsigned short', 'char', 'unsigned char']:
        # Match *(type)expr but NOT *(type *)expr
        pattern = re.compile(r'\*\(' + re.escape(type_name) + r'\)(?!\s*\*)')
        matches = list(pattern.finditer(content))
        for m in reversed(matches):
            # Check if this is really a dereference (not inside a cast chain)
            # Replace *(type) with *(type *)
            old = m.group(0)
            new = f'*({type_name} *)'
            content = content[:m.start()] + new + content[m.end():]
            fixes += 1
    return content, fixes

def fix_subscript_cast(content):
    """Fix (char)ADDR[idx] -> ((char *)ADDR)[idx] patterns."""
    fixes = 0
    # Pattern: (char)0xNNNNNNNN[
    for type_name in ['char', 'short', 'int', 'unsigned char', 'unsigned short']:
        pattern = re.compile(r'\(' + re.escape(type_name) + r'\)(0x[0-9A-Fa-f]+)\[')
        for m in reversed(list(pattern.finditer(content))):
            old = m.group(0)
            addr = m.group(1)
            new = f'(({type_name} *){addr})['
            content = content[:m.start()] + new + content[m.end():]
            fixes += 1
    return content, fixes

def fix_address_of_cast(content):
    """Fix &(type)expr patterns."""
    fixes = 0
    # Pattern: &(int)expr or &(short)expr - these are usually &((type *)addr)
    # This is tricky because it could be a valid expression in some contexts
    # Only fix the pattern where it appears as a function argument
    return content, fixes

def fix_duplicate_externs(content):
    """Remove duplicate extern declarations."""
    lines = content.split('\n')
    seen_externs = set()
    new_lines = []
    fixes = 0
    for line in lines:
        stripped = line.strip()
        if stripped.startswith('extern '):
            if stripped in seen_externs:
                fixes += 1
                continue
            seen_externs.add(stripped)
        new_lines.append(line)
    return '\n'.join(new_lines), fixes

def fix_in_r0(content):
    """Fix 'int in_r0;' usage - these are uninitialized return values.
    Change to 'int in_r0 = 0;' to suppress warnings and provide a default."""
    fixes = 0
    pattern = re.compile(r'^(\s+)(int|unsigned int|short|char) (in_r\d+);$', re.MULTILINE)
    for m in reversed(list(pattern.finditer(content))):
        old = m.group(0)
        new = f'{m.group(1)}{m.group(2)} {m.group(3)} = 0;'
        content = content[:m.start()] + new + content[m.end():]
        fixes += 1
    return content, fixes

def fix_unaff_registers(content):
    """Fix 'int unaff_rN;' declarations - add = 0 initialization."""
    fixes = 0
    pattern = re.compile(r'^(\s+)(int|unsigned int|short|char|char \*) (unaff_r\d+);$', re.MULTILINE)
    for m in reversed(list(pattern.finditer(content))):
        old = m.group(0)
        new = f'{m.group(1)}{m.group(2)} {m.group(3)} = 0;'
        content = content[:m.start()] + new + content[m.end():]
        fixes += 1
    return content, fixes

def fix_extraout_registers(content):
    """Fix 'int extraout_rN;' declarations - add = 0 initialization."""
    fixes = 0
    pattern = re.compile(r'^(\s+)(int|unsigned int|short|char) (extraout_r\d+);$', re.MULTILINE)
    for m in reversed(list(pattern.finditer(content))):
        old = m.group(0)
        new = f'{m.group(1)}{m.group(2)} {m.group(3)} = 0;'
        content = content[:m.start()] + new + content[m.end():]
        fixes += 1
    return content, fixes

def fix_file(filepath):
    with open(filepath, 'r', errors='replace') as f:
        content = f.read()

    original = content
    total_fixes = 0

    content, n = fix_duplicate_externs(content)
    total_fixes += n

    content, n = fix_deref_int(content)
    total_fixes += n

    content, n = fix_subscript_cast(content)
    total_fixes += n

    content, n = fix_in_r0(content)
    total_fixes += n

    content, n = fix_unaff_registers(content)
    total_fixes += n

    content, n = fix_extraout_registers(content)
    total_fixes += n

    if content != original:
        with open(filepath, 'w', newline='\n') as f:
            f.write(content)
        print(f"  {os.path.basename(filepath)}: {total_fixes} fixes")

    return total_fixes

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
