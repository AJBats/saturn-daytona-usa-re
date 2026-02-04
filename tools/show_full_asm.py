#!/usr/bin/env python3
"""Show full assembly output for specific delta=0 functions"""
import subprocess
import os
import re

SRCDIR = "/mnt/d/Projects/SaturnReverseTest/src"
TDIR = "/mnt/d/Projects/SaturnReverseTest/tests"
CC1 = "/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1"
TMPDIR = "/tmp/asm_show"

os.makedirs(TMPDIR, exist_ok=True)

targets = [
    "FUN_06026E0C", "FUN_060270D0", "FUN_0601164A",
    "FUN_060285E0", "FUN_06028600",
    "FUN_06035C80", "FUN_0603F3DA", "FUN_0603F4CC",
    "FUN_0603F8B8", "FUN_0603C05C", "FUN_06040954",
]

for base in targets:
    cfile = os.path.join(SRCDIR, base + '.c')
    expfile = os.path.join(TDIR, base + '.expected')
    if not os.path.exists(cfile) or not os.path.exists(expfile):
        continue

    flags = "-O2 -m2 -mbsr"
    flagsfile = os.path.join(TDIR, base + '.flags')
    if os.path.exists(flagsfile):
        with open(flagsfile) as f:
            flags = f.read().strip().replace('\r', '')

    with open(cfile) as f:
        csrc = f.read().replace('\r', '')
    cleanc = os.path.join(TMPDIR, base + '_clean.c')
    with open(cleanc, 'w') as f:
        f.write(csrc)

    outfile = os.path.join(TMPDIR, base + '.s')
    cmd = f"{CC1} -quiet {flags} {cleanc} -o {outfile}"
    subprocess.run(cmd, shell=True, capture_output=True)

    with open(outfile) as f:
        asm = f.read().replace('\r', '')

    with open(expfile) as f:
        expected = [l.strip() for l in f.read().replace('\r', '').split('\n') if l.strip()]

    # Extract instruction lines with full detail
    asm_lines = []
    for line in asm.split('\n'):
        if line.startswith('\t') and re.match(r'\t[a-z]', line):
            asm_lines.append(line.strip())

    ops = [l.split()[0] for l in asm_lines]

    print(f"=== {base} ===")
    for i in range(max(len(asm_lines), len(expected))):
        our_full = asm_lines[i] if i < len(asm_lines) else "---"
        our_op = ops[i] if i < len(ops) else "---"
        exp_op = expected[i] if i < len(expected) else "---"
        marker = " <-- DIFF" if our_op != exp_op else ""
        print(f"  {i+1:2d}: {our_full:<40s} | {exp_op:<14s}{marker}")
    print()
