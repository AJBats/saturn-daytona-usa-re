#!/usr/bin/env python3
"""fix_asm_aliases.py -- Add lowercase aliases to ASM import blocks.

The mass ASM import tool exported symbols as uppercase (e.g., _FUN_0600FFD0)
but C code references lowercase (e.g., FUN_0600ffd0 -> _FUN_0600ffd0).
This causes undefined reference errors at link time.

Fix: For every ASM __asm__ block that defines _FUN_XXXXXXXX (uppercase),
add a lowercase .global and label so both case variants resolve.

Also fixes:
- ASM blocks trapped inside #if 0 (moves them outside)
- Missing #endif for forward declarations

Usage: python tools/fix_asm_aliases.py [--dry-run]
"""

import os
import re
import sys

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC_DIR = os.path.join(PROJ, "reimpl", "src")

DRY_RUN = "--dry-run" in sys.argv


def remove_old_aliases(content, filepath):
    """Remove incorrect all-lowercase aliases (fun_xxx) from previous run."""
    lines = content.split('\n')
    new_lines = []
    removed = 0
    for line in lines:
        # Match wrong pattern: ".global _fun_xxxxxxxx\n" (all lowercase fun_)
        if re.match(r'^\s*"\.global\s+_fun_[0-9a-f]+\\n"\s*$', line):
            removed += 1
            continue
        # Match wrong pattern: "_fun_xxxxxxxx:\n" (all lowercase label)
        if re.match(r'^\s*"_fun_[0-9a-f]+:\\n"\s*$', line):
            removed += 1
            continue
        new_lines.append(line)
    return '\n'.join(new_lines), removed


def add_lowercase_aliases(content, filepath):
    """Add mixed-case aliases (FUN_xxxxxxxx) to ASM blocks."""
    changes = 0

    # Pattern: ".global _FUN_XXXXXXXX\n" where XXXXXXXX has uppercase hex
    # C code uses FUN_xxxxxxxx (uppercase FUN_, lowercase hex digits)
    # ASM defines _FUN_XXXXXXXX (uppercase hex)
    # We need alias _FUN_xxxxxxxx (uppercase FUN_, lowercase hex) to match C symbols
    lines = content.split('\n')
    new_lines = []
    i = 0
    while i < len(lines):
        line = lines[i]
        new_lines.append(line)

        # Match: ".global _FUN_XXXXXXXX\n"
        m = re.match(r'^(\s*"\.global\s+_)(FUN_)([0-9A-Fa-f]+)(\\n"\s*)$', line)
        if m:
            prefix = m.group(1)
            fun_prefix = m.group(2)  # "FUN_"
            hex_part = m.group(3)
            suffix = m.group(4)
            lower_hex = hex_part.lower()

            # Only add if hex part has uppercase letters
            if hex_part != lower_hex:
                mixed_name = fun_prefix + lower_hex  # FUN_xxxxxxxx
                # Check if this alias already exists nearby
                has_alias = False
                for j in range(max(0, i-3), min(len(lines), i+5)):
                    if mixed_name in lines[j] and '.global' in lines[j]:
                        has_alias = True
                        break

                if not has_alias:
                    new_lines.append(f'{prefix}{mixed_name}{suffix}')
                    changes += 1

        # Match: "_FUN_XXXXXXXX:\n" (label)
        m = re.match(r'^(\s*"_)(FUN_)([0-9A-Fa-f]+)(:\\n"\s*)$', line)
        if m:
            prefix = m.group(1)
            fun_prefix = m.group(2)
            hex_part = m.group(3)
            suffix = m.group(4)
            lower_hex = hex_part.lower()

            if hex_part != lower_hex:
                mixed_name = fun_prefix + lower_hex
                has_alias = False
                for j in range(max(0, i-3), min(len(lines), i+5)):
                    if mixed_name in lines[j] and ':\\n"' in lines[j]:
                        has_alias = True
                        break

                if not has_alias:
                    new_lines.append(f'{prefix}{mixed_name}{suffix}')
                    changes += 1

        i += 1

    return '\n'.join(new_lines), changes


def fix_orphaned_if0(content, filepath):
    """Fix #if 0 blocks that trap unrelated code (missing #endif)."""
    changes = 0
    lines = content.split('\n')
    new_lines = []

    i = 0
    while i < len(lines):
        line = lines[i]

        # Pattern: #if 0 wrapping a SINGLE forward declaration, missing #endif before next #if 0
        # e.g.:
        #   #if 0 /* FUN_xxx ... */
        #   void FUN_xxx(void);
        #   #if 0 /* FUN_yyy ... */   <-- second #if 0 without #endif for first
        if (re.match(r'\s*#if\s+0\s*/\*.*replaced by ASM import.*\*/', line) and
            i + 2 < len(lines)):
            next_line = lines[i + 1]
            next_next = lines[i + 2]

            # Is next line a forward declaration?
            is_fwd_decl = re.match(r'\s*(extern\s+)?(void|int|unsigned|char|short)\s+\w+\s*\(', next_line)
            # Is the line after that another #if 0?
            is_another_if0 = re.match(r'\s*#if\s+0\s*/\*', next_next)

            if is_fwd_decl and is_another_if0:
                new_lines.append(line)
                new_lines.append(next_line)
                new_lines.append('#endif')
                changes += 1
                i += 2
                continue

        new_lines.append(line)
        i += 1

    return '\n'.join(new_lines), changes


def main():
    total_alias_changes = 0
    total_if0_fixes = 0
    total_removed = 0

    for fname in sorted(os.listdir(SRC_DIR)):
        if not fname.endswith('.c'):
            continue
        fpath = os.path.join(SRC_DIR, fname)
        with open(fpath, 'r', errors='replace') as f:
            content = f.read()

        # Remove old wrong aliases first
        content, removed = remove_old_aliases(content, fpath)
        # Fix orphaned #if 0
        content, if0_fixes = fix_orphaned_if0(content, fpath)
        # Add correct mixed-case aliases
        content, alias_changes = add_lowercase_aliases(content, fpath)

        if removed > 0 or if0_fixes > 0 or alias_changes > 0:
            total_alias_changes += alias_changes
            total_if0_fixes += if0_fixes
            total_removed += removed
            print(f"  {fname}: +{alias_changes} aliases, -{removed} old, +{if0_fixes} #endif fixes")

            if not DRY_RUN:
                with open(fpath, 'w', newline='\n') as f:
                    f.write(content)

    print(f"\nTotal: {total_alias_changes} mixed-case aliases added, "
          f"{total_removed} old aliases removed, "
          f"{total_if0_fixes} orphaned #if 0 fixed")

    if DRY_RUN:
        print("[DRY RUN] No files modified.")


if __name__ == '__main__':
    main()
