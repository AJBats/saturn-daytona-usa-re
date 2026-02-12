#!/usr/bin/env python3
"""Find L1 functions with only mild/fixable Ghidra artifacts.

Categorizes remaining FUN_ functions by artifact severity:
- CLEAN: no artifacts (should be empty now)
- EASY: only in_r4-in_r7 (just needs proper function parameters)
- MODERATE: in_stack_ or extraout_var (fixable with care)
- HARD: unaff_r, in_pr, in_sr, SUB42 (complex ABI issues)

Reports easiest-to-fix functions first.
"""
import re, os, sys

# Artifact patterns by severity
EASY_RE = re.compile(r'\bin_r[4-7]\b')
MODERATE_RE = re.compile(r'\bin_stack_|\bextraout_var\b|\bextraout_r[0-9]+\b')
HARD_RE = re.compile(r'\bunaff_r|\bin_pr\b|\bin_sr\b|\bSUB4[0-9a-f]|\bin_r[0-3]\b|\bin_r[89]\b|\bin_r1[0-4]\b')

FUNC_RE = re.compile(r'^(?!extern\b)(?:\w[\w *]*\s+)(FUN_[0-9a-fA-F]+)\b')

HAS_HEX_LETTERS = re.compile(r'[A-Fa-f]')
FORWARDING_RE = re.compile(r'^\s*(?:return\s+)?FUN_[0-9a-fA-F]+\s*\(')

results = {'easy': [], 'moderate': [], 'hard': [], 'clean': []}
src_dir = os.path.join(os.path.dirname(os.path.dirname(__file__)), 'reimpl', 'src')

# Build set of addresses that have L2 versions in hand-written files
l2_addrs = set()
for fname in sorted(os.listdir(src_dir)):
    if not fname.endswith('.c'):
        continue
    if fname.startswith('batch_') or fname.startswith('asm_'):
        continue
    if fname in ('linker_stubs.c', 'stubs.c', 'extern_stubs.c'):
        continue
    path = os.path.join(src_dir, fname)
    with open(path, 'r', encoding='utf-8', errors='replace') as f:
        for line in f:
            m = FUNC_RE.match(line)
            if m:
                func = m.group(1)
                addr = func[4:].upper()  # extract hex after FUN_
                if HAS_HEX_LETTERS.search(addr):
                    l2_addrs.add(addr)

for fname in sorted(os.listdir(src_dir)):
    if not fname.startswith('batch_') or not fname.endswith('.c'):
        continue
    path = os.path.join(src_dir, fname)
    with open(path, 'r', encoding='utf-8', errors='replace') as f:
        lines = f.readlines()

    for i, line in enumerate(lines):
        m = FUNC_RE.match(line)
        if not m:
            continue
        # Check if already elevated (has L2 header comment)
        if i > 0 and lines[i-1].strip().endswith('*/'):
            continue
        # Check if disabled
        if i > 0 and '#if 0' in lines[i-1]:
            continue
        for j in range(max(0, i-5), i):
            if '#if 0' in lines[j]:
                break
        else:
            j = -1

        func_name = m.group(1)

        # Skip functions that have L2 versions in hand-written files
        addr = func_name[4:].upper()
        if HAS_HEX_LETTERS.search(addr) and addr in l2_addrs:
            continue

        # Find function end by brace counting
        brace = 0
        end_i = i
        started = False
        for k in range(i, min(i + 800, len(lines))):
            brace += lines[k].count('{') - lines[k].count('}')
            if brace > 0:
                started = True
            if started and brace <= 0:
                end_i = k
                break

        size = end_i - i + 1
        if size <= 3:
            continue

        body = ''.join(lines[i:end_i+1])

        # Skip forwarding wrappers (body is just a call to another function)
        body_lines = [l.strip() for l in lines[i:end_i+1] if l.strip() and not l.strip().startswith('{') and not l.strip().startswith('}') and not l.strip().startswith('/*')]
        real_lines = [l for l in body_lines if l and not FUNC_RE.match(l)]
        if len(real_lines) == 1 and FORWARDING_RE.match(real_lines[0]):
            continue

        has_hard = bool(HARD_RE.search(body))
        has_moderate = bool(MODERATE_RE.search(body))
        has_easy = bool(EASY_RE.search(body))

        # Count specific artifacts for detail
        artifacts = []
        for pattern, label in [
            (r'\bin_r4\b', 'in_r4'), (r'\bin_r5\b', 'in_r5'),
            (r'\bin_r6\b', 'in_r6'), (r'\bin_r7\b', 'in_r7'),
            (r'\bin_stack_', 'in_stack'), (r'\bextraout_var\b', 'extraout_var'),
            (r'\bextraout_r[0-9]+\b', 'extraout_rN'),
            (r'\bunaff_r', 'unaff_r'), (r'\bin_pr\b', 'in_pr'),
            (r'\bin_sr\b', 'in_sr'), (r'\bSUB4', 'SUB4x'),
            (r'\bin_r[0-3]\b', 'in_r0-3'),
        ]:
            count = len(re.findall(pattern, body))
            if count:
                artifacts.append(f'{label}:{count}')

        artifact_str = ', '.join(artifacts) if artifacts else 'CLEAN'

        if has_hard:
            category = 'hard'
        elif has_moderate:
            category = 'moderate'
        elif has_easy:
            category = 'easy'
        else:
            category = 'clean'

        results[category].append((size, fname, i+1, func_name, artifact_str))

# Sort each category by size (smallest first)
for cat in results:
    results[cat].sort()

# Print results
print(f"=== ARTIFACT ANALYSIS ===\n")
print(f"CLEAN (no artifacts):     {len(results['clean'])}")
print(f"EASY (in_r4-r7 only):     {len(results['easy'])}")
print(f"MODERATE (in_stack/extraout): {len(results['moderate'])}")
print(f"HARD (unaff/in_pr/SUB4):  {len(results['hard'])}")
print(f"TOTAL:                    {sum(len(v) for v in results.values())}")

for cat, label in [('clean', 'CLEAN'), ('easy', 'EASY'), ('moderate', 'MODERATE')]:
    if results[cat]:
        print(f"\n--- {label} ({len(results[cat])}) ---")
        for size, fname, linenum, func, arts in results[cat][:30]:
            print(f"  {fname}:{linenum} {func} ({size} lines) [{arts}]")
        if len(results[cat]) > 30:
            print(f"  ... and {len(results[cat]) - 30} more")

if results['hard']:
    print(f"\n--- HARD ({len(results['hard'])}) --- (first 10)")
    for size, fname, linenum, func, arts in results['hard'][:10]:
        print(f"  {fname}:{linenum} {func} ({size} lines) [{arts}]")
    if len(results['hard']) > 10:
        print(f"  ... and {len(results['hard']) - 10} more")
