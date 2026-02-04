#!/usr/bin/env python3
"""Fix multiply-by-power-of-2 to shift operations in C source files.

GCC 2.6.3 for SH-2 does NOT do strength reduction (x * 4 → mul.l, not shll2).
The Ghidra decompiler often converts shift sequences back to multiplies.
This tool converts `expr * N` where N is a power of 2 to `(expr << log2(N))`.
"""

import re
import os
import glob
import math

# Powers of 2 and their shift amounts (2 through 2^20)
POWERS = {}
for i in range(1, 21):
    POWERS[1 << i] = i


def fix_multiplies(text):
    """Replace expr * power_of_2 with (expr << shift_amount).

    Only handles cases where * is clearly multiplication (not pointer deref).
    Wraps result in parens for correct precedence since << has lower precedence than *.
    """
    changes = 0

    # Strategy: find all * followed by a power-of-2 constant
    # Pattern: <word_or_close_paren> * <power_of_2_constant>
    # We need to ensure the * is multiplication, not pointer deref

    def replace_mul_word(m):
        nonlocal changes
        full = m.group(0)
        word = m.group(1)
        const_str = m.group(2)

        # Parse the constant
        try:
            if const_str.startswith('0x') or const_str.startswith('0X'):
                val = int(const_str, 16)
            else:
                val = int(const_str)
        except ValueError:
            return full

        if val not in POWERS:
            return full

        shift = POWERS[val]
        changes += 1
        # Wrap in parens for correct precedence (<<  has lower precedence than + - etc)
        return '(' + word + ' << ' + str(shift) + ')'

    # Match: full_word * decimal_constant or full_word * 0xHEX_constant
    # \b ensures we start at a word boundary (won't match inside ->field)
    new_text = re.sub(
        r'\b(\w+)\s*\*\s+((?:0x[0-9A-Fa-f]+|\d+))\b',
        replace_mul_word,
        text
    )

    def replace_mul_paren(m):
        nonlocal changes
        full = m.group(0)
        const_str = m.group(1)

        try:
            if const_str.startswith('0x') or const_str.startswith('0X'):
                val = int(const_str, 16)
            else:
                val = int(const_str)
        except ValueError:
            return full

        if val not in POWERS:
            return full

        shift = POWERS[val]
        changes += 1
        # For ) * N, we can't easily add outer parens, just replace operator
        return ') << ' + str(shift)

    # Handle ) * N case (close paren before multiply - expression already grouped)
    new_text = re.sub(
        r'\)\s*\*\s+((?:0x[0-9A-Fa-f]+|\d+))\b',
        replace_mul_paren,
        new_text
    )

    # Now handle reverse: constant * expr (less common)
    def replace_mul_reverse(m):
        nonlocal changes
        const_str = m.group(1)
        expr = m.group(2)

        try:
            if const_str.startswith('0x') or const_str.startswith('0X'):
                val = int(const_str, 16)
            else:
                val = int(const_str)
        except ValueError:
            return m.group(0)

        if val not in POWERS:
            return m.group(0)

        shift = POWERS[val]
        changes += 1
        return '(' + expr + ' << ' + str(shift) + ')'

    # Match: decimal_or_hex * word (but not inside a cast like (int *)4)
    new_text = re.sub(
        r'\b((?:0x[0-9A-Fa-f]+|\d+))\s*\*\s+(\w+)',
        replace_mul_reverse,
        new_text
    )

    return new_text, changes


def process_file(filepath):
    """Apply mul->shift fixes to a single file."""
    with open(filepath, 'r') as f:
        text = f.read()

    new_text, changes = fix_multiplies(text)

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
            if fixes > 3:
                print(f"  {os.path.basename(filepath)}: {fixes} replacements")

    print(f"\n=== SUMMARY ===")
    print(f"Files modified: {total_changed}")
    print(f"Total replacements: {total_fixes}")


if __name__ == '__main__':
    main()
