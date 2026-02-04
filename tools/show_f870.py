#!/usr/bin/env python3
"""Show detailed comparison for FUN_0600F870 with -O2 -m2"""
import os
import subprocess

CC1 = "/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1"
SRCDIR = "/mnt/d/Projects/SaturnReverseTest/src"
TDIR = "/mnt/d/Projects/SaturnReverseTest/tests"

name = "FUN_0600F870"

# Compile
cfile = os.path.join(SRCDIR, name + ".c")
with open(cfile) as f:
    src = f.read().replace('\r', '')
with open("/tmp/test_src.c", "w") as f:
    f.write(src)

# With -mbsr
subprocess.run([CC1, "-quiet", "-O2", "-m2", "-mbsr", "/tmp/test_src.c", "-o", "/tmp/out_bsr.s"],
               capture_output=True, timeout=10)

# Without -mbsr
subprocess.run([CC1, "-quiet", "-O2", "-m2", "/tmp/test_src.c", "-o", "/tmp/out_nobsr.s"],
               capture_output=True, timeout=10)

def get_asm_lines(sfile):
    lines = []
    with open(sfile) as f:
        for line in f:
            line = line.rstrip()
            if line.startswith('\t') and line.strip() and not line.strip().startswith('.'):
                parts = line.strip().split()
                if parts and parts[0][0].isalpha():
                    lines.append(line.strip())
    return lines

bsr_lines = get_asm_lines("/tmp/out_bsr.s")
nobsr_lines = get_asm_lines("/tmp/out_nobsr.s")

with open(os.path.join(TDIR, name + ".expected")) as f:
    exp_opcodes = [l.strip().replace('bf/s','bf.s').replace('bt/s','bt.s')
                   for l in f.read().replace('\r', '').split('\n') if l.strip()]

# Show the C source
print(f"=== C Source ===")
print(src[:500])

print(f"\n=== With -mbsr ({len(bsr_lines)} insns) ===")
for i, line in enumerate(bsr_lines):
    op = line.split()[0].rstrip(',')
    exp = exp_opcodes[i] if i < len(exp_opcodes) else "---"
    marker = " <<< DIFF" if op != exp else ""
    print(f"  [{i:2d}] {line:40s} | exp: {exp}{marker}")

print(f"\n=== Without -mbsr ({len(nobsr_lines)} insns) ===")
for i, line in enumerate(nobsr_lines):
    op = line.split()[0].rstrip(',')
    exp = exp_opcodes[i] if i < len(exp_opcodes) else "---"
    marker = " <<< DIFF" if op != exp else ""
    print(f"  [{i:2d}] {line:40s} | exp: {exp}{marker}")

for i in range(len(nobsr_lines), len(exp_opcodes)):
    print(f"  [{i:2d}] {'---':40s} | exp: {exp_opcodes[i]} <<< DIFF")

print(f"\n=== Expected ({len(exp_opcodes)} insns) ===")
for i, op in enumerate(exp_opcodes):
    print(f"  [{i:2d}] {op}")
