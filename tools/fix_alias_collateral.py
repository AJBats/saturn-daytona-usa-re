#!/usr/bin/env python3
"""fix_alias_collateral.py -- Fix named functions accidentally wrapped in #if 0.

The mass_asm_import.py tool sometimes wraps alias declarations like:
    int FUN_0601e488(unsigned short slot) __attribute__((alias("backup_device_open")));
which matches the FUN_ pattern. When it wraps this in #if 0, it may also
wrap the NEXT function (the alias target) because it finds its closing '}'.

This script finds all such cases and:
1. Narrows the #if 0 to only wrap the alias line
2. Restores the accidentally wrapped named function

Usage: python tools/fix_alias_collateral.py
"""

import os
import re

SRC_DIR = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
                       "reimpl", "src")


def fix_file(filepath):
    """Fix collateral damage from mass import in a single file."""
    with open(filepath, 'r', errors='replace') as f:
        lines = f.readlines()

    fixed = 0
    i = 0
    new_lines = []
    while i < len(lines):
        line = lines[i]

        # Look for pattern: #if 0 /* FUN_... -- replaced by ASM import */
        # followed by an alias declaration (has __attribute__((alias(
        # followed by a named function that shouldn't be wrapped
        if '#if 0' in line and 'replaced by ASM import' in line:
            # Check if the NEXT non-blank line is an alias declaration
            j = i + 1
            while j < len(lines) and lines[j].strip() == '':
                j += 1

            if j < len(lines) and '__attribute__((alias(' in lines[j]:
                alias_line = j
                # Find the #endif for this block
                endif_line = None
                for k in range(alias_line + 1, len(lines)):
                    if lines[k].strip() == '#endif':
                        endif_line = k
                        break

                if endif_line is not None:
                    # Check if there's a named function between alias and #endif
                    # (i.e., the alias target function that got accidentally wrapped)
                    has_func_body = False
                    func_body_start = None
                    for k in range(alias_line + 1, endif_line):
                        if '{' in lines[k] and not lines[k].strip().startswith('/*'):
                            has_func_body = True
                            # Find the actual function definition line (before the {)
                            for m in range(k, alias_line, -1):
                                stripped = lines[m].strip()
                                if stripped and not stripped.startswith('/*') and not stripped.startswith('*') and stripped != '':
                                    if re.match(r'^(void|int|unsigned|char|short|long)', stripped):
                                        func_body_start = m
                                        break
                            if func_body_start is None:
                                func_body_start = k
                            break

                    if has_func_body and func_body_start is not None:
                        # Narrow the #if 0 to only wrap the alias line
                        new_lines.append(line)  # #if 0
                        # Add everything from i+1 to alias_line (inclusive)
                        for k in range(i + 1, alias_line + 1):
                            new_lines.append(lines[k])
                        new_lines.append('#endif\n')
                        new_lines.append('\n')
                        # Add the named function (from func_body_start to endif_line-1)
                        for k in range(func_body_start, endif_line):
                            new_lines.append(lines[k])
                        # Skip everything up to and including #endif
                        i = endif_line + 1
                        fixed += 1
                        continue

        new_lines.append(line)
        i += 1

    if fixed > 0:
        with open(filepath, 'w', newline='\n') as f:
            f.writelines(new_lines)
        print(f"  Fixed {fixed} collateral wraps in {os.path.basename(filepath)}")

    return fixed


def main():
    total = 0
    for fname in sorted(os.listdir(SRC_DIR)):
        if not fname.endswith('.c'):
            continue
        filepath = os.path.join(SRC_DIR, fname)
        total += fix_file(filepath)

    print(f"\nTotal fixes: {total}")


if __name__ == "__main__":
    main()
