#!/usr/bin/env python3
"""Find short L1 functions in batch_*.c files for L2 elevation candidates."""

import os
import re
import glob

SRC_DIR = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "reimpl", "src")

func_start_re = re.compile(r'^(?:void|int|unsigned|short|char)\s+FUN_([0-9a-fA-F]+)\s*\(')
func_end_re = re.compile(r'^}')

results = []

for path in sorted(glob.glob(os.path.join(SRC_DIR, "batch_*.c"))):
    fname = os.path.basename(path)
    with open(path, 'r') as f:
        lines = f.readlines()

    in_func = False
    func_name = None
    func_start = 0
    func_lines = []

    for i, line in enumerate(lines, 1):
        m = func_start_re.match(line)
        if m and not in_func:
            in_func = True
            func_name = f"FUN_0x{m.group(1)}"
            func_start = i
            func_lines = [line]
            continue

        if in_func:
            func_lines.append(line)
            if func_end_re.match(line):
                body_len = len(func_lines) - 2  # minus signature and closing brace
                # Only report functions with 3-20 lines of body (skip trivial 1-2 liners)
                if 3 <= body_len <= 20:
                    # Check for Ghidra artifacts that make it harder
                    body_text = ''.join(func_lines)
                    has_goto = 'goto ' in body_text
                    has_cast_deref = '*(int)' in body_text or '*(uint)' in body_text
                    quality = "CLEAN" if not has_goto and not has_cast_deref else "HAS_ARTIFACTS"
                    results.append((fname, func_name.replace("0x", ""), func_start, body_len, quality, body_text.strip()))
                in_func = False
                func_name = None
                func_lines = []

# Sort by body length (shortest first)
results.sort(key=lambda x: x[3])

print(f"Found {len(results)} functions with 3-20 lines of body:\n")
for fname, func_name, line_no, body_len, quality, body in results[:40]:
    print(f"--- {func_name} in {fname}:{line_no} ({body_len} lines, {quality}) ---")
    # Print just the body (first 25 lines)
    for bline in body.split('\n')[:25]:
        print(f"  {bline}")
    print()
