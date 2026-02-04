#!/usr/bin/env python3
"""Test delta=0 functions with -fno-schedule-insns2 to see if scheduling is the culprit"""
import subprocess
import os
import re

SRCDIR = "/mnt/d/Projects/SaturnReverseTest/src"
TDIR = "/mnt/d/Projects/SaturnReverseTest/tests"
CC1 = "/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1"
TMPDIR = "/tmp/sched_test"

os.makedirs(TMPDIR, exist_ok=True)

# Focus on 2-diff and 3-diff functions
targets = [
    "FUN_0601164A", "FUN_06026E0C", "FUN_060270D0", "FUN_06035C80",
    "FUN_0603C05C", "FUN_0603F3DA", "FUN_0603F4CC", "FUN_0603F8B8",
    "FUN_06040954", "FUN_06027344", "FUN_06027348", "FUN_060285E0",
    "FUN_06028600", "FUN_06005174", "FUN_06018EC8",
    "FUN_0602760C", "FUN_0602761E", "FUN_06027630",
]

def extract_opcodes(asmfile):
    with open(asmfile) as f:
        lines = f.read().replace('\r', '').split('\n')
    ops = []
    for line in lines:
        if line.startswith('\t') and re.match(r'\t[a-z]', line):
            op = line.strip().split()[0]
            ops.append(op)
    return ops

def count_diffs(a, b):
    diffs = 0
    for i in range(min(len(a), len(b))):
        if a[i] != b[i]:
            diffs += 1
    diffs += abs(len(a) - len(b))
    return diffs

for base in targets:
    cfile = os.path.join(SRCDIR, base + '.c')
    expfile = os.path.join(TDIR, base + '.expected')
    if not os.path.exists(cfile) or not os.path.exists(expfile):
        continue

    flags_base = "-O2 -m2 -mbsr"
    flagsfile = os.path.join(TDIR, base + '.flags')
    if os.path.exists(flagsfile):
        with open(flagsfile) as f:
            flags_base = f.read().strip().replace('\r', '')

    with open(cfile) as f:
        csrc = f.read().replace('\r', '')
    cleanc = os.path.join(TMPDIR, base + '_clean.c')
    with open(cleanc, 'w') as f:
        f.write(csrc)

    with open(expfile) as f:
        expected = [l.strip() for l in f.read().replace('\r', '').split('\n') if l.strip()]

    # Test with normal flags
    out_normal = os.path.join(TMPDIR, base + '_normal.s')
    cmd = f"{CC1} -quiet {flags_base} {cleanc} -o {out_normal}"
    subprocess.run(cmd, shell=True, capture_output=True)
    ops_normal = extract_opcodes(out_normal)

    # Test with -fno-schedule-insns2
    out_nosched = os.path.join(TMPDIR, base + '_nosched.s')
    cmd = f"{CC1} -quiet {flags_base} -fno-schedule-insns2 {cleanc} -o {out_nosched}"
    subprocess.run(cmd, shell=True, capture_output=True)
    ops_nosched = extract_opcodes(out_nosched)

    diffs_normal = count_diffs(ops_normal, expected)
    diffs_nosched = count_diffs(ops_nosched, expected)
    delta_normal = len(ops_normal) - len(expected)
    delta_nosched = len(ops_nosched) - len(expected)

    status = ""
    if diffs_nosched < diffs_normal:
        status = " *** IMPROVED ***"
    elif diffs_nosched == 0:
        status = " *** PASS ***"
    elif diffs_nosched > diffs_normal:
        status = " (worse)"

    print(f"{base}: normal={diffs_normal}diffs(d={delta_normal}) nosched={diffs_nosched}diffs(d={delta_nosched}){status}")

    if diffs_nosched != diffs_normal:
        # Show what changed
        for i in range(max(len(ops_nosched), len(expected))):
            ns = ops_nosched[i] if i < len(ops_nosched) else "---"
            ex = expected[i] if i < len(expected) else "---"
            no = ops_normal[i] if i < len(ops_normal) else "---"
            marker = ""
            if ns != ex:
                marker = " <-- still diff"
            if no != ex and ns == ex:
                marker = " <-- FIXED"
            if no == ex and ns != ex:
                marker = " <-- BROKEN"
            if marker:
                print(f"  {i+1:2d}: normal={no:<12s} nosched={ns:<12s} expected={ex:<12s}{marker}")
