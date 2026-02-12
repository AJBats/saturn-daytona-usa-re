#!/usr/bin/env python3
"""Find unaff_r artifacts that are assigned within the function body.

These are fixable because the register IS set by the function itself
(e.g., unaff_r13 = FUN_xxx()), not inherited from a caller.

Output: functions where ALL unaff_r variables are assigned before use.
"""
import re, os

src_dir = os.path.join(os.path.dirname(os.path.dirname(__file__)), 'reimpl', 'src')

FUNC_START_RE = re.compile(
    r'^(?:(?:void|int|unsigned int|char \*|short|long long|unsigned short)\s+)'
    r'(FUN_([0-9a-fA-F]+))\s*\('
)
UNAFF_DECL_RE = re.compile(r'^\s+\w.*\bunaff_r(\d+)\b.*=\s*0\s*;')
UNAFF_ASSIGN_RE = re.compile(r'^\s+unaff_r(\d+)\s*=\s*(?!0\s*;)')
UNAFF_USE_RE = re.compile(r'\bunaff_r(\d+)\b')

def analyze_file(path, fname):
    with open(path, 'r', encoding='utf-8', errors='replace') as f:
        lines = f.readlines()

    results = []
    i = 0
    while i < len(lines):
        m = FUNC_START_RE.match(lines[i])
        if not m:
            i += 1
            continue

        func_name = m.group(1)
        func_line = i + 1

        # Find function body
        brace_depth = 0
        body_start = None
        j = i
        while j < len(lines):
            if '{' in lines[j]:
                if brace_depth == 0:
                    body_start = j
                brace_depth += lines[j].count('{')
            if '}' in lines[j]:
                brace_depth -= lines[j].count('}')
                if brace_depth <= 0:
                    break
            j += 1

        if body_start is None:
            i = j + 1
            continue

        body = lines[body_start:j+1]

        # Find all unaff_r declarations
        unaff_regs = set()
        for line in body:
            dm = UNAFF_DECL_RE.match(line)
            if dm:
                unaff_regs.add(dm.group(1))

        if not unaff_regs:
            i = j + 1
            continue

        # Check which ones are assigned within the body
        assigned_regs = set()
        for line in body:
            am = UNAFF_ASSIGN_RE.match(line)
            if am:
                assigned_regs.add(am.group(1))

        # Also check if assigned via comma expression (Ghidra pattern)
        for line in body:
            if 'unaff_r' in line and '=' in line:
                for um in UNAFF_USE_RE.finditer(line):
                    reg = um.group(1)
                    # Check if it's on the left side of an assignment
                    pos = um.start()
                    before = line[:pos]
                    after = line[pos:]
                    if '=' in after and after.index('=') < 10:
                        assigned_regs.add(reg)

        # Count total body lines (excluding blanks)
        body_lines = sum(1 for l in body if l.strip())

        if assigned_regs:
            unassigned = unaff_regs - assigned_regs
            if not unassigned:
                # ALL unaff_r vars are assigned within the function!
                results.append({
                    'file': fname,
                    'line': func_line,
                    'func': func_name,
                    'regs': sorted(unaff_regs),
                    'body_lines': body_lines,
                    'status': 'ALL_ASSIGNED',
                })
            else:
                results.append({
                    'file': fname,
                    'line': func_line,
                    'func': func_name,
                    'regs': sorted(unaff_regs),
                    'assigned': sorted(assigned_regs),
                    'unassigned': sorted(unassigned),
                    'body_lines': body_lines,
                    'status': 'PARTIAL',
                })

        i = j + 1

    return results

def main():
    all_results = []
    for fname in sorted(os.listdir(src_dir)):
        if not fname.startswith('batch_') or not fname.endswith('.c'):
            continue
        path = os.path.join(src_dir, fname)
        results = analyze_file(path, fname)
        all_results.extend(results)

    fixable = [r for r in all_results if r['status'] == 'ALL_ASSIGNED']
    partial = [r for r in all_results if r['status'] == 'PARTIAL']

    print(f"=== FIXABLE (all unaff_r assigned within function): {len(fixable)} ===")
    for r in sorted(fixable, key=lambda x: x['body_lines']):
        regs = ', '.join(f'r{reg}' for reg in r['regs'])
        print(f"  {r['file']}:{r['line']} {r['func']} ({r['body_lines']} lines) [{regs}]")

    print(f"\n=== PARTIAL (some assigned, some inherited): {len(partial)} ===")
    for r in sorted(partial, key=lambda x: x['body_lines']):
        assigned = ', '.join(f'r{reg}' for reg in r['assigned'])
        unassigned = ', '.join(f'r{reg}' for reg in r['unassigned'])
        print(f"  {r['file']}:{r['line']} {r['func']} ({r['body_lines']} lines) "
              f"[assigned: {assigned}] [inherited: {unassigned}]")

if __name__ == '__main__':
    main()
