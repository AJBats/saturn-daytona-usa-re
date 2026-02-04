#!/usr/bin/env python3
"""Show full assembly with operands for delta=-1 functions"""
import os
import subprocess
import re

SRCDIR = "/mnt/d/Projects/SaturnReverseTest/src"
TDIR = "/mnt/d/Projects/SaturnReverseTest/tests"
CC1 = "/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1"

def get_asm_lines(sfile):
    """Extract instruction lines from .s file (with operands)"""
    lines = []
    with open(sfile) as f:
        for line in f:
            line = line.rstrip()
            if line.startswith('\t') and line.strip() and not line.strip().startswith('.'):
                parts = line.strip().split()
                if parts and parts[0][0].isalpha():
                    lines.append(line.strip())
    return lines

def get_opcodes(lines):
    """Extract just opcodes from instruction lines"""
    opcodes = []
    for line in lines:
        op = line.split()[0].rstrip(',')
        opcodes.append(op)
    return opcodes

def main():
    results = []

    for f in sorted(os.listdir(SRCDIR)):
        if not f.endswith('.c'):
            continue
        name = f[:-2]
        expected_path = os.path.join(TDIR, name + ".expected")
        if not os.path.exists(expected_path):
            continue

        # Compile
        src = os.path.join(SRCDIR, f)
        with open(src) as fh:
            csrc = fh.read().replace('\r', '')
        with open("/tmp/test_src.c", "w") as fh:
            fh.write(csrc)

        result = subprocess.run(
            [CC1, "-quiet", "-O2", "-m2", "-mbsr", "/tmp/test_src.c", "-o", "/tmp/test_out.s"],
            capture_output=True, text=True, timeout=10
        )
        if result.returncode != 0:
            continue

        asm_lines = get_asm_lines("/tmp/test_out.s")
        our_opcodes = get_opcodes(asm_lines)

        with open(expected_path) as fh:
            exp_opcodes = [l.strip().replace('bf/s','bf.s').replace('bt/s','bt.s')
                          for l in fh.read().replace('\r', '').split('\n') if l.strip()]

        delta = len(our_opcodes) - len(exp_opcodes)
        if delta != -1:
            continue

        results.append({
            'name': name,
            'asm_lines': asm_lines,
            'our_opcodes': our_opcodes,
            'exp_opcodes': exp_opcodes,
        })

    print(f"Found {len(results)} delta=-1 functions\n")

    for r in results:
        name = r['name']
        asm = r['asm_lines']
        ours = r['our_opcodes']
        exp = r['exp_opcodes']

        # Find the diff
        n_diffs = 0
        diff_positions = []
        for i in range(min(len(ours), len(exp))):
            if ours[i] != exp[i]:
                n_diffs += 1
                diff_positions.append(i)

        print(f"{'='*60}")
        print(f"{name} (ours={len(ours)} exp={len(exp)}, {n_diffs} opcode diffs at positions {diff_positions})")
        print(f"{'='*60}")

        maxlen = max(len(ours), len(exp))
        for i in range(maxlen):
            our_op = ours[i] if i < len(ours) else "---"
            exp_op = exp[i] if i < len(exp) else "---"
            our_asm = asm[i] if i < len(asm) else "---"
            marker = " <<< DIFF" if our_op != exp_op else ""
            if i < len(exp):
                print(f"  [{i:2d}] {our_asm:35s} | exp: {exp_op:12s}{marker}")
            else:
                print(f"  [{i:2d}] {our_asm:35s} | exp: {exp_op:12s}{marker}")

        # Analyze the specific difference
        # What extra instruction do we have vs expected?
        our_set = {}
        exp_set = {}
        for op in ours:
            our_set[op] = our_set.get(op, 0) + 1
        for op in exp:
            exp_set[op] = exp_set.get(op, 0) + 1

        extra_ours = {}
        extra_exp = {}
        all_ops = set(list(our_set.keys()) + list(exp_set.keys()))
        for op in all_ops:
            diff = our_set.get(op, 0) - exp_set.get(op, 0)
            if diff > 0:
                extra_ours[op] = diff
            elif diff < 0:
                extra_exp[op] = -diff

        if extra_ours or extra_exp:
            print(f"\n  Extra in ours: {extra_ours}")
            print(f"  Extra in expected: {extra_exp}")
        print()

if __name__ == '__main__':
    main()
