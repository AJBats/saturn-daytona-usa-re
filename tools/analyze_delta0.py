#!/usr/bin/env python3
"""Analyze delta=0 failures - show full side-by-side opcode comparison"""
import subprocess
import os
import re

SRCDIR = "/mnt/d/Projects/SaturnReverseTest/src"
TDIR = "/mnt/d/Projects/SaturnReverseTest/tests"
CC1 = "/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1"
TMPDIR = "/tmp/delta0_analysis"

os.makedirs(TMPDIR, exist_ok=True)

results = []

for fname in sorted(os.listdir(SRCDIR)):
    if not fname.endswith('.c'):
        continue
    base = fname[:-2]
    expfile = os.path.join(TDIR, base + '.expected')
    if not os.path.exists(expfile):
        continue

    flags = "-O2 -m2 -mbsr"
    flagsfile = os.path.join(TDIR, base + '.flags')
    if os.path.exists(flagsfile):
        with open(flagsfile) as f:
            flags = f.read().strip().replace('\r', '')

    # Compile
    cfile = os.path.join(SRCDIR, fname)
    with open(cfile) as f:
        csrc = f.read().replace('\r', '')
    cleanc = os.path.join(TMPDIR, base + '_clean.c')
    with open(cleanc, 'w') as f:
        f.write(csrc)

    outfile = os.path.join(TMPDIR, base + '.s')
    cmd = f"{CC1} -quiet {flags} {cleanc} -o {outfile}"
    subprocess.run(cmd, shell=True, capture_output=True)

    # Extract our opcodes
    with open(outfile) as f:
        lines = f.read().replace('\r', '').split('\n')
    ours = []
    for line in lines:
        if line.startswith('\t') and re.match(r'\t[a-z]', line):
            op = line.strip().split()[0]
            ours.append(op)

    # Extract expected opcodes
    with open(expfile) as f:
        expected = [l.strip() for l in f.read().replace('\r', '').split('\n') if l.strip()]

    delta = len(ours) - len(expected)
    if delta != 0:
        continue

    # Count diffs
    diffs = 0
    diff_positions = []
    for i in range(min(len(ours), len(expected))):
        if ours[i] != expected[i]:
            diffs += 1
            diff_positions.append(i)

    if diffs == 0:
        continue

    results.append((base, len(ours), diffs, ours, expected, diff_positions))

# Sort by number of diffs (easiest first)
results.sort(key=lambda x: x[2])

# Categorize
print(f"{'='*70}")
print(f"  DELTA=0 FAILURES: {len(results)} functions")
print(f"{'='*70}")
print()

for base, count, ndiffs, ours, expected, diffpos in results:
    print(f"=== {base} ({count} insns, {ndiffs} opcode diffs) ===")
    for i in range(count):
        marker = "  <-- DIFF" if i in diffpos else ""
        print(f"  {i+1:2d}: {ours[i]:<14s} | {expected[i]:<14s}{marker}")
    print()
