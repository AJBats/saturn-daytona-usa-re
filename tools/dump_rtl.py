#!/usr/bin/env python3
"""Dump RTL passes for specific functions to understand instruction ordering"""
import subprocess
import os

CC1 = "/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1"
SRCDIR = "/mnt/d/Projects/SaturnReverseTest/src"
TDIR = "/mnt/d/Projects/SaturnReverseTest/tests"
TMPDIR = "/tmp/rtl_dump"

os.makedirs(TMPDIR, exist_ok=True)

# Test a few key functions
targets = ["FUN_06035C80", "FUN_060285E0", "FUN_06026E0C"]

for base in targets:
    cfile = os.path.join(SRCDIR, base + '.c')
    if not os.path.exists(cfile):
        continue

    flags = "-O2 -m2 -mbsr"
    flagsfile = os.path.join(TDIR, base + '.flags')
    if os.path.exists(flagsfile):
        with open(flagsfile) as f:
            flags = f.read().strip().replace('\r', '')

    with open(cfile) as f:
        csrc = f.read().replace('\r', '')

    cleanc = os.path.join(TMPDIR, base + '.c')
    with open(cleanc, 'w') as f:
        f.write(csrc)

    outfile = os.path.join(TMPDIR, base + '.s')

    # Compile with RTL dumps: -dr (RTL after RTL gen), -dj (after first jump opt),
    # -ds (after combine), -dL (after local alloc), -dg (after global alloc),
    # -dR (after sched2), -dJ (after last jump)
    cmd = f"{CC1} -quiet {flags} -dr -ds -dg -dR -dS -dJ {cleanc} -o {outfile}"
    result = subprocess.run(cmd, shell=True, capture_output=True, text=True, cwd=TMPDIR)

    print(f"=== {base} ===")
    print(f"stderr: {result.stderr[:200] if result.stderr else 'none'}")

    # List generated dump files
    for f in sorted(os.listdir(TMPDIR)):
        if f.startswith(base) and f.endswith(('.rtl', '.combine', '.greg', '.sched2', '.jump2', '.sched', '.lreg')):
            fpath = os.path.join(TMPDIR, f)
            size = os.path.getsize(fpath)
            print(f"  {f} ({size} bytes)")

    # Show the final asm
    with open(outfile) as f:
        asm = f.read().replace('\r', '')
    print(f"  Final asm:")
    for line in asm.split('\n'):
        if line.startswith('\t') and line[1:2].isalpha():
            print(f"    {line.strip()}")
    print()
