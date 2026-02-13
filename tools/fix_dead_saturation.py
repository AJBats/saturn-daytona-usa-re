#!/usr/bin/env python3
"""
Remove dead MAC saturation checks from Ghidra-decompiled C code.

The SH-2 MAC saturation mode (S-bit in SR register) is never set in the
rendering pipeline. Ghidra emits saturation checks like:

    if (((unsigned char)(in_sr >> 1) & 1) == 1) {
      // ... saturation clamp code (dead) ...
    }
    else {
      // ... normal accumulate code (kept) ...
    }

Since S-bit is always 0, only the else branch executes. This tool:
1. Detects the pattern
2. Removes the if-block and else-keyword, keeping only the else body
3. For patterns without else, removes the entire dead block
"""

import re
import sys


def find_saturation_blocks(lines):
    """Find all saturation check blocks."""
    patterns = []
    i = 0
    while i < len(lines):
        line = lines[i].strip()
        if re.match(r'if \(\(\(unsigned char\)\(\w+ >> 1\) & 1\) == 1\) \{', line):
            sat_start = i
            indent_match = re.match(r'^(\s*)', lines[i])
            base_indent = indent_match.group(1) if indent_match else ''

            # Find the end of the if-block by tracking braces
            brace_depth = 0
            if_end = None

            for j in range(sat_start, min(sat_start + 40, len(lines))):
                for ch in lines[j]:
                    if ch == '{':
                        brace_depth += 1
                    elif ch == '}':
                        brace_depth -= 1
                        if brace_depth == 0:
                            if_end = j
                            break
                if if_end is not None:
                    break

            if if_end is None:
                i += 1
                continue

            # Check if there's an else block after the if
            else_start = None
            else_end = None
            next_line_idx = if_end + 1

            if next_line_idx < len(lines):
                next_stripped = lines[next_line_idx].strip()
                if next_stripped.startswith('else'):
                    else_start = next_line_idx
                    # Find end of else block
                    brace_depth = 0
                    for j in range(else_start, min(else_start + 20, len(lines))):
                        for ch in lines[j]:
                            if ch == '{':
                                brace_depth += 1
                            elif ch == '}':
                                brace_depth -= 1
                                if brace_depth == 0:
                                    else_end = j
                                    break
                        if else_end is not None:
                            break

            if else_start is not None and else_end is not None:
                # Extract the else body (lines between 'else {' and '}')
                else_body_lines = []
                for j in range(else_start + 1, else_end):
                    l = lines[j]
                    # De-indent by removing 2 leading spaces from the else body
                    if l.startswith(base_indent + '  '):
                        l = base_indent + l[len(base_indent) + 2:]
                    elif len(l) > 2 and l[0] == ' ' and l[1] == ' ':
                        l = l[2:]
                    else_body_lines.append(l)

                patterns.append({
                    'start': sat_start,
                    'end': else_end,
                    'else_body': else_body_lines,
                    'has_else': True,
                })
            else:
                # No else block — the entire if block is dead code
                patterns.append({
                    'start': sat_start,
                    'end': if_end,
                    'else_body': [],
                    'has_else': False,
                })

            i = (else_end if else_end is not None else if_end) + 1
        else:
            i += 1

    return patterns


def process_file(filepath, dry_run=False):
    with open(filepath, 'r') as f:
        lines = f.readlines()

    lines = [line.rstrip('\n').rstrip('\r') for line in lines]

    patterns = find_saturation_blocks(lines)

    if not patterns:
        print("  No saturation patterns found in %s" % filepath)
        return 0

    print("  Found %d saturation check blocks in %s" % (len(patterns), filepath))

    original_lines = sum(p['end'] - p['start'] + 1 for p in patterns)
    new_lines = sum(len(p['else_body']) for p in patterns)

    # Process in reverse order to preserve line numbers
    for info in reversed(patterns):
        start = info['start']
        end = info['end']

        if info['has_else']:
            lines[start:end+1] = info['else_body']
        else:
            lines[start:end+1] = []

    if not dry_run:
        with open(filepath, 'w', newline='\n') as f:
            for line in lines:
                f.write(line + '\n')

    print("  Replaced %d blocks: %d lines -> %d lines (saved %d lines)" % (
        len(patterns), original_lines, new_lines, original_lines - new_lines))

    return len(patterns)


def main():
    if len(sys.argv) < 2:
        print("Usage: %s <file.c> [--dry-run]" % sys.argv[0])
        sys.exit(1)

    filepath = sys.argv[1]
    dry_run = '--dry-run' in sys.argv

    if dry_run:
        print("DRY RUN")

    count = process_file(filepath, dry_run)
    print("Done: %d replacements" % count)


if __name__ == '__main__':
    main()
