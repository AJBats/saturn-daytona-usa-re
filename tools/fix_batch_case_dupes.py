#!/usr/bin/env python3
"""Replace L1 batch function bodies with forwarding wrappers to L2 versions.

Problem: batch_*.c has lowercase FUN_0600cd40 (L1 Ghidra lift, many lines).
         hand-written files have uppercase FUN_0600CD40 (L2 translation).
         C is case-sensitive so both exist as separate symbols.
         Batch callers hit the L1 version instead of the clean L2 version.

Fix: Replace each L1 body with a forwarding wrapper:
     extern int FUN_0600CD40(void);
     int FUN_0600cd40(void) { return FUN_0600CD40(); }
"""
import re, os, sys

src_dir = os.path.join(os.path.dirname(os.path.dirname(__file__)), 'reimpl', 'src')

FUNC_DEF_RE = re.compile(
    r'^(?!extern\b)(?:\w[\w *]*\s+)(FUN_([0-9a-fA-F]+))\s*\('
)

HAS_HEX_LETTERS = re.compile(r'[A-Fa-f]')

def get_l2_signatures(src_dir):
    """Get L2 function signatures from hand-written files."""
    sigs = {}  # normalized_addr -> (return_type, func_name, params_str, file)

    for fname in sorted(os.listdir(src_dir)):
        if not fname.endswith('.c'):
            continue
        if fname.startswith('batch_') or fname.startswith('asm_'):
            continue
        if fname in ('linker_stubs.c', 'stubs.c', 'extern_stubs.c'):
            continue

        path = os.path.join(src_dir, fname)
        with open(path, 'r', encoding='utf-8', errors='replace') as f:
            content = f.read()
            lines = content.split('\n')

        for i, line in enumerate(lines):
            m = FUNC_DEF_RE.match(line)
            if not m:
                continue

            func_name = m.group(1)
            hex_addr = m.group(2)

            if not HAS_HEX_LETTERS.search(hex_addr):
                continue

            norm_addr = hex_addr.upper()
            if func_name != f"FUN_{norm_addr}":
                continue  # not uppercase

            # Extract return type
            ret_match = re.match(r'^([\w][\w *]*?)\s+FUN_', line)
            if not ret_match:
                continue
            ret_type = ret_match.group(1).strip()

            # Extract params
            paren_start = line.index('(')
            # Find matching close paren
            depth = 0
            param_str = ''
            for j in range(paren_start, len(line)):
                if line[j] == '(':
                    depth += 1
                elif line[j] == ')':
                    depth -= 1
                    if depth == 0:
                        param_str = line[paren_start+1:j].strip()
                        break

            if not param_str:
                param_str = 'void'

            sigs[norm_addr] = {
                'ret_type': ret_type,
                'func_name': func_name,
                'params': param_str,
                'file': fname,
            }

    return sigs

def find_batch_dupes(src_dir, l2_sigs):
    """Find L1 batch function definitions that have L2 versions."""
    dupes = []  # list of (batch_file, line_idx, func_name, hex_addr, l2_sig)

    for fname in sorted(os.listdir(src_dir)):
        if not fname.startswith('batch_') or not fname.endswith('.c'):
            continue

        path = os.path.join(src_dir, fname)
        with open(path, 'r', encoding='utf-8', errors='replace') as f:
            lines = f.readlines()

        for i, line in enumerate(lines):
            m = FUNC_DEF_RE.match(line)
            if not m:
                continue

            func_name = m.group(1)
            hex_addr = m.group(2)

            if not HAS_HEX_LETTERS.search(hex_addr):
                continue

            norm_addr = hex_addr.upper()
            if func_name != f"FUN_{hex_addr.lower()}":
                continue  # not lowercase

            if norm_addr not in l2_sigs:
                continue

            # Check it's a real definition (has brace)
            has_brace = False
            for j in range(i, min(i + 10, len(lines))):
                if '{' in lines[j]:
                    has_brace = True
                    break

            if not has_brace:
                continue

            dupes.append({
                'file': fname,
                'line_idx': i,
                'func_name': func_name,
                'norm_addr': norm_addr,
                'l2': l2_sigs[norm_addr],
            })

    return dupes

def find_function_end(lines, start_idx):
    """Find the end of a function body (matching closing brace)."""
    depth = 0
    found_open = False

    for i in range(start_idx, len(lines)):
        for ch in lines[i]:
            if ch == '{':
                depth += 1
                found_open = True
            elif ch == '}':
                depth -= 1
                if found_open and depth == 0:
                    return i

    return None

def find_preceding_comment(lines, func_start):
    """Find the start of a comment block before the function."""
    # Check if the line(s) before the function are part of a comment
    i = func_start - 1
    while i >= 0 and lines[i].strip() == '':
        i -= 1

    if i >= 0 and lines[i].strip().endswith('*/'):
        # Found end of comment, find start
        while i >= 0:
            if '/*' in lines[i]:
                return i
            i -= 1

    return func_start

def main():
    dry_run = '--dry-run' in sys.argv

    l2_sigs = get_l2_signatures(src_dir)
    print(f"Found {len(l2_sigs)} L2 function signatures\n")

    dupes = find_batch_dupes(src_dir, l2_sigs)
    print(f"Found {len(dupes)} L1 batch functions to replace\n")

    if not dupes:
        return

    # Group by file
    by_file = {}
    for d in dupes:
        by_file.setdefault(d['file'], []).append(d)

    total_lines_removed = 0
    total_fixes = 0

    for batch_fname, file_dupes in sorted(by_file.items()):
        path = os.path.join(src_dir, batch_fname)
        with open(path, 'r', encoding='utf-8', errors='replace') as f:
            lines = f.readlines()

        # Sort by line number descending (modify from bottom up)
        file_dupes.sort(key=lambda x: x['line_idx'], reverse=True)

        # First pass: remove extern declarations for functions being replaced
        externs_to_remove = set()
        for d in file_dupes:
            externs_to_remove.add(d['func_name'])

        # Remove extern declarations (from bottom up to preserve line indices)
        extern_lines_removed = []
        for i in range(len(lines) - 1, -1, -1):
            stripped = lines[i].strip()
            if stripped.startswith('extern'):
                for fname in externs_to_remove:
                    if fname in stripped:
                        extern_lines_removed.append((i, lines[i].rstrip()))
                        lines[i] = ''  # blank it out
                        # Adjust file_dupes line indices
                        for d in file_dupes:
                            if d['line_idx'] > i:
                                d['line_idx'] -= 0  # don't adjust, we blank not delete
                        break

        for d in file_dupes:
            func_start = d['line_idx']
            func_end = find_function_end(lines, func_start)

            if func_end is None:
                print(f"  WARNING: Could not find end of {d['func_name']} in {batch_fname}:{func_start+1}")
                continue

            l2 = d['l2']
            l2_name = l2['func_name']
            l2_ret = l2['ret_type']
            l2_params = l2['params']
            lc_name = d['func_name']

            # Find any preceding comment
            comment_start = find_preceding_comment(lines, func_start)

            # Count lines being removed
            removed = func_end - comment_start + 1
            total_lines_removed += removed

            # Build the forwarding wrapper
            # Extern declaration for L2 version
            extern_line = f"extern {l2_ret} {l2_name}({l2_params});\n"

            # Build forwarding wrapper with matching params
            if l2_params == 'void' or l2_params == '':
                if l2_ret == 'void':
                    wrapper = f"void {lc_name}(void) {{ {l2_name}(); }}\n"
                else:
                    wrapper = f"{l2_ret} {lc_name}(void) {{ return {l2_name}(); }}\n"
            else:
                # Parse params to extract names for forwarding
                param_parts = []
                param_names = []
                for p in l2_params.split(','):
                    p = p.strip()
                    param_parts.append(p)
                    # Extract param name (last word)
                    name_match = re.search(r'(\w+)\s*$', p)
                    if name_match:
                        param_names.append(name_match.group(1))
                    else:
                        param_names.append(p)

                call_args = ', '.join(param_names)
                if l2_ret == 'void':
                    wrapper = f"void {lc_name}({l2_params}) {{ {l2_name}({call_args}); }}\n"
                else:
                    wrapper = f"{l2_ret} {lc_name}({l2_params}) {{ return {l2_name}({call_args}); }}\n"

            # Comment about the replacement
            comment = f"/* {lc_name}: L2 version in {l2['file']} */\n"

            # Replace the function (and preceding comment) with wrapper
            replacement = [comment, extern_line, wrapper]
            lines[comment_start:func_end + 1] = replacement

            print(f"  {batch_fname}:{func_start+1}: {lc_name} -> {l2_name} ({l2['file']}) [-{removed} lines]")
            total_fixes += 1

        if not dry_run:
            with open(path, 'w', encoding='utf-8', newline='\n') as f:
                f.writelines(lines)
            print(f"  Updated {batch_fname} ({len(file_dupes)} fixes)\n")
        else:
            print(f"  [DRY RUN] Would update {batch_fname} ({len(file_dupes)} fixes)\n")

    print(f"\nTotal: {total_fixes} functions replaced, ~{total_lines_removed} lines of L1 code removed")

if __name__ == '__main__':
    main()
