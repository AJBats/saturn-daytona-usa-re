#!/usr/bin/env python3
"""Find unelevated clean L1 functions in batch_*.c files."""
import re, os

ARTIFACT_RE = re.compile(r'unaff_r|in_r[0-9]|in_pr|in_sr|extraout_r|extraout_var|in_stack_|SUB42')
FUNC_RE = re.compile(r'^(?:int|void|unsigned int|char \*|long long) (FUN_[0-9a-f]+)')

results = []
src_dir = os.path.join(os.path.dirname(os.path.dirname(__file__)), 'reimpl', 'src')

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
        # Check if preceding line closes a comment block
        if i > 0 and lines[i-1].strip().endswith('*/'):
            continue  # Already has L2 header

        func_name = m.group(1)

        # Find function end by brace counting
        brace = 0
        end_i = i
        started = False
        for j in range(i, min(i + 800, len(lines))):
            brace += lines[j].count('{') - lines[j].count('}')
            if brace > 0:
                started = True
            if started and brace <= 0:
                end_i = j
                break

        size = end_i - i + 1
        body = ''.join(lines[i:end_i+1])
        has_artifact = bool(ARTIFACT_RE.search(body))

        if not has_artifact and size > 3:  # Skip trivially small
            results.append((size, fname, i+1, func_name))

results.sort()
for size, fname, linenum, func in results[:50]:
    print(f'{fname}:{linenum} {func} ({size} lines)')
