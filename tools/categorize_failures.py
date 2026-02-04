#!/usr/bin/env python3
"""Categorize all test failures by root cause pattern.
Reads .expected files and compiles C sources to compare.
"""
import os
import subprocess
import sys

SRCDIR = "/mnt/d/Projects/SaturnReverseTest/src"
TDIR = "/mnt/d/Projects/SaturnReverseTest/tests"
CC1 = "/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1"

def get_expected(name):
    """Get expected opcodes from .expected file"""
    path = os.path.join(TDIR, name + ".expected")
    if not os.path.exists(path):
        return None
    with open(path) as f:
        return [l.strip() for l in f.read().replace('\r', '').split('\n') if l.strip()]

def get_actual(name):
    """Compile C source and extract opcodes"""
    cfile = os.path.join(SRCDIR, name + ".c")
    if not os.path.exists(cfile):
        return None

    # Check for per-function flags
    flagfile = os.path.join(TDIR, name + ".flags")
    flags = "-quiet -O2 -m2 -mbsr"
    if os.path.exists(flagfile):
        with open(flagfile) as f:
            flags = f.read().replace('\r', '').strip()

    try:
        result = subprocess.run(
            [CC1] + flags.split() + [cfile, "-o", "/tmp/test_out.s"],
            capture_output=True, text=True, timeout=10
        )
        if result.returncode != 0:
            return None

        with open("/tmp/test_out.s") as f:
            asm = f.read()

        opcodes = []
        for line in asm.split('\n'):
            line = line.strip()
            if line.startswith('.') or line.endswith(':') or not line or line.startswith('!'):
                continue
            # Extract opcode (first word)
            parts = line.split()
            if parts:
                op = parts[0]
                # Skip assembler directives
                if op.startswith('.') or op.startswith('_') or op.startswith('L'):
                    continue
                opcodes.append(op)
        return opcodes
    except Exception as e:
        return None

def categorize_diff(name, actual, expected):
    """Categorize the type of diff between actual and expected"""
    delta = len(actual) - len(expected)

    # Build diff details
    # Find specific opcode differences
    diff_types = set()

    # Check for bsr vs jsr
    a_str = ' '.join(actual)
    e_str = ' '.join(expected)

    if 'bsr' in a_str and 'jsr' in e_str:
        # Check if replacing bsr->jsr would help
        has_bsr_jsr = False
        for a, e in zip(actual, expected):
            if a == 'bsr' and e == 'jsr':
                has_bsr_jsr = True
        if has_bsr_jsr or ('bsr' in a_str and 'jsr' in e_str):
            diff_types.add('bsr_vs_jsr')

    if 'bsr' in e_str and 'jsr' in a_str:
        diff_types.add('jsr_vs_bsr_expected')

    if 'bra' in a_str and 'bra' not in e_str:
        diff_types.add('our_bra_tail')

    if 'bra' in e_str and 'bra' not in a_str:
        diff_types.add('expected_bra')

    # Check for nop differences
    a_nops = actual.count('nop')
    e_nops = expected.count('nop')
    if a_nops != e_nops:
        diff_types.add(f'nop_diff(ours={a_nops},orig={e_nops})')

    # Check for scheduling (delta=0, same opcodes different order)
    if delta == 0:
        a_sorted = sorted(actual)
        e_sorted = sorted(expected)
        if a_sorted == e_sorted:
            diff_types.add('pure_reorder')
        else:
            diff_types.add('different_opcodes')

    # Check for delay slot fill (we fill, they nop)
    if delta < 0 and a_nops < e_nops:
        diff_types.add('delay_slot_fill')

    # Check for mov.l vs mov.w differences
    a_movl = a_str.count('mov.l')
    a_movw = a_str.count('mov.w')
    e_movl = e_str.count('mov.l')
    e_movw = e_str.count('mov.w')
    if a_movl != e_movl or a_movw != e_movw:
        diff_types.add('mov_size_diff')

    # Count exact opcode diffs
    n_diffs = 0
    for i in range(min(len(actual), len(expected))):
        if actual[i] != expected[i]:
            n_diffs += 1
    n_diffs += abs(len(actual) - len(expected))

    return {
        'name': name,
        'delta': delta,
        'actual_len': len(actual),
        'expected_len': len(expected),
        'n_diffs': n_diffs,
        'diff_types': diff_types,
        'actual': actual,
        'expected': expected,
    }


def main():
    # Find all test functions
    tested = set()
    for f in os.listdir(SRCDIR):
        if f.endswith('.c'):
            tested.add(f[:-2])

    failures = []
    passes = []
    errors = []

    for name in sorted(tested):
        expected = get_expected(name)
        if expected is None:
            continue

        actual = get_actual(name)
        if actual is None:
            errors.append(name)
            continue

        if actual == expected:
            passes.append(name)
        else:
            cat = categorize_diff(name, actual, expected)
            failures.append(cat)

    # Sort failures by delta
    failures.sort(key=lambda x: (x['delta'], x['n_diffs']))

    # Print summary by delta
    print("=" * 70)
    print(f"FAILURE ANALYSIS: {len(passes)} PASS / {len(failures)} FAIL")
    print("=" * 70)

    # Group by delta
    by_delta = {}
    for f in failures:
        d = f['delta']
        if d not in by_delta:
            by_delta[d] = []
        by_delta[d].append(f)

    print(f"\nBy delta:")
    for d in sorted(by_delta.keys()):
        funcs = by_delta[d]
        print(f"  delta={d:+d}: {len(funcs)} functions")

    # Detailed analysis per delta group
    for d in sorted(by_delta.keys()):
        funcs = by_delta[d]
        print(f"\n{'='*70}")
        print(f"DELTA = {d:+d} ({len(funcs)} functions)")
        print(f"{'='*70}")

        for f in funcs:
            types_str = ', '.join(sorted(f['diff_types'])) if f['diff_types'] else 'unknown'
            print(f"\n  {f['name']} ({f['actual_len']} vs {f['expected_len']} insns, {f['n_diffs']} diffs)")
            print(f"    Types: {types_str}")

            # Show side-by-side diff (compact)
            maxlen = max(len(f['actual']), len(f['expected']))
            diff_lines = []
            for i in range(maxlen):
                a = f['actual'][i] if i < len(f['actual']) else '---'
                e = f['expected'][i] if i < len(f['expected']) else '---'
                if a != e:
                    diff_lines.append(f"      [{i:2d}] {a:12s} vs {e:12s}")

            for line in diff_lines[:8]:  # Show max 8 diff lines
                print(line)
            if len(diff_lines) > 8:
                print(f"      ... and {len(diff_lines)-8} more diffs")

    # Pattern summary
    print(f"\n{'='*70}")
    print("PATTERN SUMMARY")
    print(f"{'='*70}")

    all_types = {}
    for f in failures:
        for t in f['diff_types']:
            if t not in all_types:
                all_types[t] = []
            all_types[t].append(f['name'])

    for t in sorted(all_types.keys(), key=lambda x: -len(all_types[x])):
        names = all_types[t]
        print(f"\n  {t}: {len(names)} functions")
        for n in names[:5]:
            print(f"    - {n}")
        if len(names) > 5:
            print(f"    ... and {len(names)-5} more")

    # Actionable categories
    print(f"\n{'='*70}")
    print("ACTIONABLE CATEGORIES")
    print(f"{'='*70}")

    # BSR vs JSR: can fix with -mno-bsr flag
    bsr_jsr = [f for f in failures if 'bsr_vs_jsr' in f['diff_types']]
    print(f"\n1. BSR→JSR (fixable with -mno-bsr per-function flag): {len(bsr_jsr)}")
    for f in bsr_jsr:
        print(f"   {f['name']} delta={f['delta']:+d} diffs={f['n_diffs']}")

    # Our tail call where original doesn't
    tail = [f for f in failures if 'our_bra_tail' in f['diff_types']]
    print(f"\n2. Our BRA tail call (fixable with -mno-tail-call): {len(tail)}")
    for f in tail[:10]:
        print(f"   {f['name']} delta={f['delta']:+d} diffs={f['n_diffs']}")
    if len(tail) > 10:
        print(f"   ... and {len(tail)-10} more")

    # Delta=0 pure reorder (scheduling)
    reorder = [f for f in failures if 'pure_reorder' in f['diff_types']]
    print(f"\n3. Pure reorder (delta=0, same opcodes): {len(reorder)}")
    for f in reorder:
        print(f"   {f['name']} diffs={f['n_diffs']}")

    # Delay slot (we fill, they nop)
    ds = [f for f in failures if 'delay_slot_fill' in f['diff_types']]
    print(f"\n4. Delay slot fill diff: {len(ds)}")
    for f in ds[:10]:
        print(f"   {f['name']} delta={f['delta']:+d} diffs={f['n_diffs']}")


if __name__ == '__main__':
    main()
