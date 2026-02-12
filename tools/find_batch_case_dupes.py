#!/usr/bin/env python3
"""Find batch_*.c functions that have L2 versions in hand-written files.

Problem: batch_*.c has lowercase FUN_0600cd40 (L1 Ghidra lift).
         hand-written files have uppercase FUN_0600CD40 (L2 translation).
         C is case-sensitive so both exist as separate symbols.
         Batch callers hit the L1 version instead of the clean L2 version.

Output: List of duplicate functions and their locations.
"""
import re, os

src_dir = os.path.join(os.path.dirname(os.path.dirname(__file__)), 'reimpl', 'src')

# Regex to find function definitions
FUNC_DEF_RE = re.compile(
    r'^(?!extern\b)(?:\w[\w *]*\s+)(FUN_([0-9a-fA-F]+))\s*\('
)

HAS_HEX_LETTERS = re.compile(r'[A-Fa-f]')

def scan_functions(src_dir):
    """Find all function definitions grouped by normalized address."""
    funcs = {}  # normalized_addr -> list of (file, line, name, case)

    batch_files = set()
    hand_files = set()

    for fname in sorted(os.listdir(src_dir)):
        if not fname.endswith('.c'):
            continue

        path = os.path.join(src_dir, fname)
        is_batch = fname.startswith('batch_')
        is_asm = fname.startswith('asm_')
        is_hand = not is_batch and not is_asm and fname not in (
            'linker_stubs.c', 'stubs.c', 'extern_stubs.c'
        )

        with open(path, 'r', encoding='utf-8', errors='replace') as f:
            lines = f.readlines()

        for i, line in enumerate(lines):
            # Skip comments, #if 0 blocks
            stripped = line.strip()
            if stripped.startswith('/*') or stripped.startswith('//'):
                continue

            m = FUNC_DEF_RE.match(line)
            if not m:
                continue

            func_name = m.group(1)
            hex_addr = m.group(2)

            # Only care about addresses with hex letters
            if not HAS_HEX_LETTERS.search(hex_addr):
                continue

            norm_addr = hex_addr.upper()
            is_upper = func_name == f"FUN_{norm_addr}"
            is_lower = func_name == f"FUN_{hex_addr.lower()}"

            if func_name != f"FUN_{norm_addr}" and func_name != f"FUN_{hex_addr.lower()}":
                continue  # mixed case, skip

            # Check it's a real definition (has brace)
            has_brace = False
            for j in range(i, min(i + 5, len(lines))):
                if '{' in lines[j]:
                    has_brace = True
                    break

            if not has_brace:
                continue

            entry = {
                'file': fname,
                'line': i + 1,
                'name': func_name,
                'is_upper': is_upper,
                'is_batch': is_batch,
                'is_hand': is_hand,
                'is_asm': is_asm,
            }

            funcs.setdefault(norm_addr, []).append(entry)

    return funcs

def main():
    funcs = scan_functions(src_dir)

    dupes = []
    for addr, entries in sorted(funcs.items()):
        batch_entries = [e for e in entries if e['is_batch']]
        hand_entries = [e for e in entries if e['is_hand']]

        if batch_entries and hand_entries:
            dupes.append((addr, batch_entries, hand_entries))

    print(f"Found {len(dupes)} batch<->hand-written case duplicates\n")

    for addr, batch_entries, hand_entries in dupes:
        print(f"  0x{addr}:")
        for e in hand_entries:
            print(f"    L2: {e['file']}:{e['line']} {e['name']}")
        for e in batch_entries:
            print(f"    L1: {e['file']}:{e['line']} {e['name']}")

    # Summary
    print(f"\nTotal batch functions with L2 duplicates: {len(dupes)}")
    print("These L1 batch versions should be replaced with forwarding wrappers")

if __name__ == '__main__':
    main()
