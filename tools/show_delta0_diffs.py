#!/usr/bin/env python3
"""Show side-by-side diffs for delta=0 functions."""
import os
import subprocess
import sys

SRCDIR = "/mnt/d/Projects/SaturnReverseTest/src"
TDIR = "/mnt/d/Projects/SaturnReverseTest/tests"
CC1 = "/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1"

def get_expected(name):
    path = os.path.join(TDIR, name + ".expected")
    if not os.path.exists(path):
        return None
    with open(path) as f:
        return [l.strip() for l in f.read().replace('\r', '').split('\n') if l.strip()]

def get_actual(name):
    cfile = os.path.join(SRCDIR, name + ".c")
    if not os.path.exists(cfile):
        return None, None

    flagfile = os.path.join(TDIR, name + ".flags")
    flags = "-quiet -O2 -m2 -mbsr"
    if os.path.exists(flagfile):
        with open(flagfile) as f:
            flags = "-quiet " + f.read().replace('\r', '').strip()

    try:
        result = subprocess.run(
            [CC1] + flags.split() + [cfile, "-o", "/tmp/test_out.s"],
            capture_output=True, text=True, timeout=10
        )
        if result.returncode != 0:
            return None, None

        with open("/tmp/test_out.s") as f:
            asm = f.read()

        opcodes = []
        full_lines = []
        for line in asm.split('\n'):
            line = line.strip()
            if line.startswith('.') or line.endswith(':') or not line or line.startswith('!'):
                continue
            parts = line.split()
            if parts:
                op = parts[0]
                if op.startswith('.') or op.startswith('_') or op.startswith('L'):
                    continue
                opcodes.append(op)
                full_lines.append(line)
        return opcodes, full_lines
    except Exception:
        return None, None

def main():
    # Find all delta=0 functions
    delta0 = []

    for f in sorted(os.listdir(SRCDIR)):
        if not f.endswith('.c'):
            continue
        name = f[:-2]
        expected = get_expected(name)
        if expected is None:
            continue
        actual, full = get_actual(name)
        if actual is None:
            continue

        delta = len(actual) - len(expected)
        if delta != 0:
            continue

        # Count diffs
        n_diffs = sum(1 for a, e in zip(actual, expected) if a != e)

        # Check if pure reorder (same multiset)
        is_reorder = sorted(actual) == sorted(expected)

        delta0.append({
            'name': name,
            'actual': actual,
            'expected': expected,
            'full': full,
            'n_diffs': n_diffs,
            'is_reorder': is_reorder,
        })

    # Sort by number of diffs
    delta0.sort(key=lambda x: x['n_diffs'])

    print(f"Delta=0 functions: {len(delta0)}")
    print(f"Pure reorder (same opcodes): {sum(1 for d in delta0 if d['is_reorder'])}")
    print(f"Different opcodes: {sum(1 for d in delta0 if not d['is_reorder'])}")
    print()

    for d in delta0:
        tag = "REORDER" if d['is_reorder'] else "DIFF_OPS"
        print(f"{'='*70}")
        print(f"{d['name']} ({len(d['actual'])} insns, {d['n_diffs']} diffs) [{tag}]")
        print(f"{'='*70}")

        maxlen = max(len(d['actual']), len(d['expected']))
        for i in range(maxlen):
            a = d['actual'][i] if i < len(d['actual']) else '---'
            e = d['expected'][i] if i < len(d['expected']) else '---'
            af = d['full'][i] if i < len(d['full']) else '---'
            marker = " <<" if a != e else ""
            print(f"  [{i:2d}] {af:30s}  | {e:12s}{marker}")
        print()

if __name__ == '__main__':
    main()
