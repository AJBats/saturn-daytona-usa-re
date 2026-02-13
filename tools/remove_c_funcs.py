#!/usr/bin/env python3
"""
Remove C function definitions from a file, keeping extern declarations.

Used to eliminate bloated Ghidra C functions that have been replaced by
ASM labels within existing ASM-imported parent functions.
"""

import re
import sys

# Functions to remove (sub-entry points now defined in ASM imports)
FUNCS_TO_REMOVE = [
    'FUN_0602a134', 'FUN_0602a214', 'FUN_0602a754', 'FUN_0602a834',
    'FUN_0602aaa0', 'FUN_0602ab00', 'FUN_0602ab3a', 'FUN_0602abb8',
    'FUN_0602ae24', 'FUN_0602ae84', 'FUN_0602aebe', 'FUN_0602af3c',
    'FUN_0602b1d6', 'FUN_0602b258', 'FUN_0602b298', 'FUN_0602b328',
    'FUN_0602b546', 'FUN_0602b55a', 'FUN_0602b55e', 'FUN_0602b572',
    'FUN_0602b58e', 'FUN_0602b5a2', 'FUN_0602b5be', 'FUN_0602b5ce',
    'FUN_0602b5d2', 'FUN_0602b8dc', 'FUN_0602b9e0',
    'FUN_0602bc7a', 'FUN_0602bcfc', 'FUN_0602bd3c', 'FUN_0602bdcc',
    'FUN_0602c380',
]


def find_func_ranges(lines, func_names):
    """Find the line ranges of function definitions to remove."""
    ranges = []
    func_set = set(func_names)
    i = 0

    while i < len(lines):
        line = lines[i].strip()

        # Skip extern declarations
        if line.startswith('extern '):
            i += 1
            continue

        # Check if this line starts a function definition
        found_func = None
        for fname in func_set:
            if fname + '(' in line or fname + ' (' in line:
                # Make sure it's a definition (has a return type before it), not a call
                if re.match(r'^(unsigned\s+int|int|void|long\s+long|short|char|unsigned\s+short)\s+' + fname + r'\s*\(', line):
                    found_func = fname
                    break

        if found_func is None:
            i += 1
            continue

        # Found a function definition. Look for any comment block above it.
        def_start = i

        # Check for comment block above (L2-elevated functions may have comments)
        while def_start > 0:
            prev = lines[def_start - 1].strip()
            if prev.startswith('/*') or prev.startswith('*') or prev.startswith('//') or prev == '':
                def_start -= 1
                # Stop going back at blank lines that aren't adjacent to comments
                if prev == '' and def_start > 0:
                    prev2 = lines[def_start - 1].strip()
                    if not (prev2.startswith('/*') or prev2.startswith('*') or prev2.endswith('*/')):
                        def_start += 1  # Keep the blank line
                        break
            else:
                break

        # Find the opening brace
        brace_line = i
        while brace_line < len(lines) and '{' not in lines[brace_line]:
            brace_line += 1

        if brace_line >= len(lines):
            print("  WARNING: no opening brace found for %s at line %d" % (found_func, i + 1))
            i += 1
            continue

        # Find the matching closing brace
        brace_depth = 0
        end_line = brace_line
        for j in range(brace_line, len(lines)):
            for ch in lines[j]:
                if ch == '{':
                    brace_depth += 1
                elif ch == '}':
                    brace_depth -= 1
                    if brace_depth == 0:
                        end_line = j
                        break
            if brace_depth == 0:
                break

        if brace_depth != 0:
            print("  WARNING: unmatched braces for %s at line %d" % (found_func, i + 1))
            i += 1
            continue

        ranges.append((def_start, end_line, found_func))
        print("  Will remove %s: lines %d-%d (%d lines)" % (
            found_func, def_start + 1, end_line + 1, end_line - def_start + 1))

        i = end_line + 1

    return ranges


def process_file(filepath, dry_run=False):
    with open(filepath, 'r') as f:
        lines = f.readlines()

    # Find function definition ranges
    ranges = find_func_ranges(lines, FUNCS_TO_REMOVE)

    if not ranges:
        print("  No matching functions found")
        return 0

    # Sort by start line (should already be sorted)
    ranges.sort(key=lambda x: x[0])

    # Check which functions already have extern declarations
    existing_externs = set()
    for line in lines:
        stripped = line.strip()
        if stripped.startswith('extern '):
            for fname in FUNCS_TO_REMOVE:
                if fname in stripped:
                    existing_externs.add(fname)

    # Build list of extern declarations needed
    removed_funcs = set(r[2] for r in ranges)
    need_extern = removed_funcs - existing_externs

    # Remove ranges in reverse order
    total_removed = 0
    for start, end, fname in reversed(ranges):
        total_removed += end - start + 1
        del lines[start:end + 1]

    # Add missing extern declarations after the existing extern block
    if need_extern:
        # Find insertion point (after last extern FUN_ line)
        insert_at = 0
        for idx, line in enumerate(lines):
            if line.strip().startswith('extern') and 'FUN_' in line:
                insert_at = idx + 1

        new_externs = []
        for fname in sorted(need_extern):
            new_externs.append('extern void %s();\n' % fname)

        for ext in reversed(new_externs):
            lines.insert(insert_at, ext)

        print("  Added %d extern declarations" % len(new_externs))

    if not dry_run:
        with open(filepath, 'w', newline='\n') as f:
            f.writelines(lines)

    print("  Removed %d functions (%d lines total)" % (len(ranges), total_removed))
    return len(ranges)


def main():
    if len(sys.argv) < 2:
        print("Usage: %s <file.c> [--dry-run]" % sys.argv[0])
        sys.exit(1)

    filepath = sys.argv[1]
    dry_run = '--dry-run' in sys.argv

    if dry_run:
        print("DRY RUN")

    count = process_file(filepath, dry_run)
    print("\nDone: %d functions removed" % count)


if __name__ == '__main__':
    main()
