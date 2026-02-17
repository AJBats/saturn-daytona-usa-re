#!/usr/bin/env python3
"""fix_alias_conflicts.py -- Remove alias declarations that conflict with existing FUN_ definitions.

For each alias like:
    void FUN_XXXXXX(void) __attribute__((alias("named_func")));

Check if FUN_XXXXXX is also defined in the same file (as C code or ASM import).
If so, remove the alias line to prevent duplicate symbol errors.
"""

import re
import os
import glob

SRC_DIR = os.path.join(os.path.dirname(__file__), '..', 'reimpl', 'src')

# Pattern to match alias declarations: void FUN_XXXXXX(...) __attribute__((alias("name")));
ALIAS_PAT = re.compile(
    r'^(.*?)\bFUN_([0-9a-fA-F]{6,8})\b.*__attribute__\(\(alias\('
)

# Pattern to match FUN_ as a C function definition (not in alias, not in comment, not extern)
FUN_DEF_PAT = re.compile(
    r'^\s*(?:void|int|unsigned|short|char|long)[\s\*]+FUN_([0-9a-fA-F]{6,8})\s*\('
)

# Pattern to match ASM .global _FUN_ declaration
ASM_GLOBAL_PAT = re.compile(
    r'\.global\s+_FUN_([0-9a-fA-F]{6,8})'
)

def find_conflicts():
    """Find alias declarations that conflict with existing definitions."""
    conflicts = []

    for cfile in sorted(glob.glob(os.path.join(SRC_DIR, '*.c'))):
        basename = os.path.basename(cfile)

        with open(cfile, 'r') as f:
            lines = f.readlines()

        # Step 1: Find all alias lines and their FUN_ addresses
        alias_lines = {}  # addr -> (line_num, line_text)
        for i, line in enumerate(lines):
            m = ALIAS_PAT.match(line)
            if m:
                addr = m.group(2).lower()
                alias_lines[addr] = (i, line.rstrip())

        if not alias_lines:
            continue

        # Step 2: Find all FUN_ definitions (C code and ASM imports) in same file
        defined_funs = set()
        in_if0 = False
        if0_depth = 0

        for i, line in enumerate(lines):
            stripped = line.strip()

            # Track #if 0 blocks (don't count disabled definitions)
            if stripped.startswith('#if 0'):
                if0_depth += 1
                in_if0 = True
            elif stripped.startswith('#endif') and if0_depth > 0:
                if0_depth -= 1
                if if0_depth == 0:
                    in_if0 = False

            # Skip alias lines themselves
            if '__attribute__((alias(' in line:
                continue
            # Skip extern declarations
            if stripped.startswith('extern '):
                continue
            # Skip comments
            if stripped.startswith('/*') or stripped.startswith('*') or stripped.startswith('//'):
                continue

            if not in_if0:
                # Check C function definitions
                m = FUN_DEF_PAT.match(line)
                if m:
                    defined_funs.add(m.group(1).lower())

                # Check ASM .global declarations
                for m in ASM_GLOBAL_PAT.finditer(line):
                    defined_funs.add(m.group(1).lower())

        # Step 3: Find conflicts
        for addr, (line_num, line_text) in alias_lines.items():
            if addr in defined_funs:
                conflicts.append((basename, line_num + 1, addr, line_text))

    return conflicts


def find_cross_file_conflicts():
    """Find alias declarations where FUN_ is defined in a DIFFERENT file."""
    # Build map of all FUN_ definitions across all files
    all_defs = {}  # addr -> [(file, type)]
    all_aliases = {}  # addr -> [(file, line_num, line_text)]

    for cfile in sorted(glob.glob(os.path.join(SRC_DIR, '*.c'))):
        basename = os.path.basename(cfile)

        with open(cfile, 'r') as f:
            content = f.read()
            lines = content.split('\n')

        for i, line in enumerate(lines):
            # Find aliases
            m = ALIAS_PAT.match(line)
            if m:
                addr = m.group(2).lower()
                if addr not in all_aliases:
                    all_aliases[addr] = []
                all_aliases[addr].append((basename, i + 1, line.rstrip()))

            # Find ASM .global (not in #if 0)
            if '__attribute__((alias(' not in line:
                for m in ASM_GLOBAL_PAT.finditer(line):
                    addr = m.group(1).lower()
                    if addr not in all_defs:
                        all_defs[addr] = []
                    all_defs[addr].append((basename, 'asm'))

        # Find C definitions (not in #if 0, not aliases, not externs)
        in_if0 = False
        for i, line in enumerate(lines):
            stripped = line.strip()
            if stripped.startswith('#if 0'):
                in_if0 = True
            elif stripped.startswith('#endif'):
                in_if0 = False

            if not in_if0 and '__attribute__((alias(' not in line and not stripped.startswith('extern '):
                m2 = FUN_DEF_PAT.match(line)
                if m2:
                    addr = m2.group(1).lower()
                    if addr not in all_defs:
                        all_defs[addr] = []
                    all_defs[addr].append((basename, 'c_def'))

    # Find cross-file conflicts
    cross = []
    for addr, aliases in all_aliases.items():
        if addr in all_defs:
            for alias_file, alias_line, alias_text in aliases:
                for def_file, def_type in all_defs[addr]:
                    if def_file != alias_file:
                        cross.append((alias_file, alias_line, addr, alias_text, def_file, def_type))

    return cross


def remove_conflicts(conflicts, cross_conflicts, dry_run=True):
    """Remove conflicting alias lines from source files."""
    # Build set of (file, line_num) to remove
    to_remove = {}

    for basename, line_num, addr, line_text in conflicts:
        filepath = os.path.join(SRC_DIR, basename)
        if filepath not in to_remove:
            to_remove[filepath] = set()
        to_remove[filepath].add(line_num - 1)  # 0-indexed

    for alias_file, alias_line, addr, alias_text, def_file, def_type in cross_conflicts:
        filepath = os.path.join(SRC_DIR, alias_file)
        if filepath not in to_remove:
            to_remove[filepath] = set()
        to_remove[filepath].add(alias_line - 1)  # 0-indexed

    total_removed = 0
    for filepath, line_nums in sorted(to_remove.items()):
        with open(filepath, 'r') as f:
            lines = f.readlines()

        new_lines = []
        for i, line in enumerate(lines):
            if i in line_nums:
                # Comment out the alias
                new_lines.append(f'/* REMOVED: conflicting alias */ // {line.rstrip()}\n')
                total_removed += 1
            else:
                new_lines.append(line)

        if not dry_run:
            with open(filepath, 'w') as f:
                f.writelines(new_lines)
            print(f"  Fixed {os.path.basename(filepath)}: removed {len(line_nums)} alias(es)")

    return total_removed


if __name__ == '__main__':
    import sys

    dry_run = '--apply' not in sys.argv

    print("=== Same-file conflicts ===")
    conflicts = find_conflicts()
    for basename, line_num, addr, line_text in conflicts:
        print(f"  {basename}:{line_num}: FUN_{addr} alias conflicts with definition in same file")

    print(f"\nFound {len(conflicts)} same-file conflicts\n")

    print("=== Cross-file conflicts ===")
    cross = find_cross_file_conflicts()
    for alias_file, alias_line, addr, alias_text, def_file, def_type in cross:
        print(f"  {alias_file}:{alias_line}: FUN_{addr} alias conflicts with {def_type} in {def_file}")

    print(f"\nFound {len(cross)} cross-file conflicts\n")

    total = len(conflicts) + len(cross)
    if total > 0:
        if dry_run:
            print(f"Would remove {total} conflicting aliases. Run with --apply to fix.")
        else:
            removed = remove_conflicts(conflicts, cross, dry_run=False)
            print(f"Removed {removed} conflicting aliases.")
