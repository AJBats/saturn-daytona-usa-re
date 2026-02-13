#!/usr/bin/env python3
"""
Comprehensive tool to eliminate C functions that overlap with ASM imports.

1. Scans for overlapping C functions (addresses inside ASM-imported functions)
2. Adds global labels at the correct offsets in the ASM files
3. Removes the C function definitions
4. Adds extern declarations where needed

Usage: python dedup_asm_overlaps.py <src_dir> [--dry-run]
"""

import re
import os
import sys
import glob


def parse_asm_functions(src_dir):
    """Parse all asm_*.c files to find ASM-imported function ranges and their line positions."""
    asm_funcs = {}  # {label: (start_addr, size_bytes, file_path, label_line_num)}

    for filepath in sorted(glob.glob(os.path.join(src_dir, 'asm_*.c'))):
        with open(filepath, 'r') as f:
            lines = f.readlines()

        current_label = None
        label_line = None
        word_count = 0

        for i, line in enumerate(lines):
            # Look for function label (not .global, the actual label)
            m = re.search(r'"_?(FUN_[0-9A-Fa-f]+):\\n"', line)
            if m and '.global' not in line:
                current_label = m.group(1).upper()
                label_line = i
                word_count = 0
                continue

            if current_label:
                if '".word ' in line:
                    word_count += 1
                elif '.size' in line:
                    upper = current_label.upper()
                    if upper.replace('FUN_', '') in line.upper().replace('FUN_', '').replace('_', ''):
                        addr = int(current_label.replace('FUN_', ''), 16)
                        size = word_count * 2
                        asm_funcs[current_label] = (addr, size, filepath, label_line)
                        current_label = None

    return asm_funcs


def parse_c_functions(src_dir):
    """Parse batch_*.c files to find C function definitions."""
    c_funcs = []

    for filepath in sorted(glob.glob(os.path.join(src_dir, 'batch_*.c'))):
        with open(filepath, 'r') as f:
            lines = f.readlines()

        i = 0
        while i < len(lines):
            line = lines[i]
            # Skip extern declarations
            if line.strip().startswith('extern '):
                i += 1
                continue

            m = re.match(r'^(?:unsigned\s+int|int|void|long\s+long|short|char|unsigned\s+short)\s+(FUN_[0-9a-f]+)\s*\(', line)
            if m:
                # Skip alias declarations and forward declarations (end with ;)
                stripped = line.strip()
                if '__attribute__' in stripped or stripped.endswith(';'):
                    i += 1
                    continue

                func_name = m.group(1)
                addr = int(func_name.replace('FUN_', ''), 16)
                func_start = i

                # Find end of function (handle K&R-style params before opening brace)
                brace_depth = 0
                found_brace = False
                func_end = i
                for j in range(i, min(i + 2000, len(lines))):
                    for ch in lines[j]:
                        if ch == '{':
                            brace_depth += 1
                            found_brace = True
                        elif ch == '}':
                            brace_depth -= 1
                    if found_brace and brace_depth == 0:
                        func_end = j
                        break

                if not found_brace:
                    # Could not find function body — skip
                    i += 1
                    continue

                c_funcs.append({
                    'name': func_name,
                    'addr': addr,
                    'file': filepath,
                    'start': func_start,
                    'end': func_end,
                    'lines': func_end - func_start + 1,
                })
                i = func_end + 1
            else:
                i += 1

    return c_funcs


def find_overlaps(asm_funcs, c_funcs):
    """Find C functions whose addresses fall within ASM-imported functions."""
    overlaps = []

    for cf in c_funcs:
        for asm_label, (asm_addr, asm_size, asm_file, asm_label_line) in asm_funcs.items():
            if asm_addr <= cf['addr'] < asm_addr + asm_size:
                if cf['name'].upper() != asm_label.upper():
                    offset = cf['addr'] - asm_addr
                    overlaps.append({
                        'c_name': cf['name'],
                        'c_addr': cf['addr'],
                        'c_file': cf['file'],
                        'c_start': cf['start'],
                        'c_end': cf['end'],
                        'c_lines': cf['lines'],
                        'asm_label': asm_label,
                        'asm_addr': asm_addr,
                        'asm_size': asm_size,
                        'asm_file': asm_file,
                        'asm_label_line': asm_label_line,
                        'offset': offset,
                    })
                    break

    return overlaps


def add_asm_labels(overlaps, dry_run=False):
    """Add global labels at correct offsets in ASM files."""
    # Group by ASM file first, then by parent within each file
    by_file = {}
    for o in overlaps:
        by_file.setdefault(o['asm_file'], {})
        by_file[o['asm_file']].setdefault(o['asm_label'], []).append(o)

    total_added = 0
    files_modified = set()

    for asm_file, parents in sorted(by_file.items()):
        with open(asm_file, 'r') as f:
            lines = f.readlines()

        # Build insertion maps for all parents in this file
        all_insertions = {}  # parent_label -> {word_idx: [child_labels]}
        for parent_label, entries in parents.items():
            insertion_map = {}
            for e in entries:
                word_idx = e['offset'] // 2
                insertion_map.setdefault(word_idx, []).append(e['c_name'])
            all_insertions[parent_label] = insertion_map

        # Process the file, handling all parents in one pass
        new_lines = []
        i = 0

        while i < len(lines):
            line = lines[i]

            # Check if this line is a label for any parent we need to process
            active_parent = None
            for parent_label in all_insertions:
                if ('_%s:\\n"' % parent_label) in line and '.global' not in line:
                    active_parent = parent_label
                    break

            if active_parent is None:
                new_lines.append(line)
                i += 1
                continue

            insertion_map = all_insertions[active_parent]
            new_lines.append(line)
            i += 1

            # Process .word lines for this parent
            word_count = 0
            while i < len(lines):
                wline = lines[i]

                if '".word ' in wline:
                    if word_count in insertion_map:
                        indent_m = re.match(r'^(\s*)', wline)
                        indent = indent_m.group(1) if indent_m else '    '
                        for child in insertion_map[word_count]:
                            new_lines.append('%s".global _%s\\n"\n' % (indent, child))
                            new_lines.append('%s"_%s:\\n"\n' % (indent, child))
                            total_added += 1
                    new_lines.append(wline)
                    word_count += 1
                    i += 1
                elif '.size' in wline:
                    new_lines.append(wline)
                    i += 1
                    break
                else:
                    new_lines.append(wline)
                    i += 1

            # Verify offsets
            for e in parents[active_parent]:
                expected = e['offset'] // 2
                if expected >= word_count:
                    print("  WARNING: offset 0x%X for %s exceeds %s size (%d words)" % (
                        e['offset'], e['c_name'], active_parent, word_count))

        if not dry_run:
            with open(asm_file, 'w', newline='\n') as f:
                f.writelines(new_lines)
            files_modified.add(asm_file)

    return total_added, files_modified


def remove_c_functions(overlaps, dry_run=False):
    """Remove C function definitions from batch files."""
    # Group by C file
    by_file = {}
    for o in overlaps:
        by_file.setdefault(o['c_file'], []).append(o)

    total_removed = 0
    total_lines = 0

    for c_file, entries in sorted(by_file.items()):
        with open(c_file, 'r') as f:
            lines = f.readlines()

        # Sort entries by start line (descending) for safe removal
        entries.sort(key=lambda x: x['c_start'], reverse=True)

        # Check existing extern declarations
        existing_externs = set()
        for line in lines:
            s = line.strip()
            if s.startswith('extern '):
                for e in entries:
                    if e['c_name'] in s:
                        existing_externs.add(e['c_name'])

        # Find comment block above each function to include in removal
        for e in entries:
            start = e['c_start']
            # Look for comment/blank lines above
            while start > 0:
                prev = lines[start - 1].strip()
                if prev.startswith('/*') or prev.startswith('*') or prev.startswith('//') or prev == '':
                    start -= 1
                    if prev == '' and start > 0:
                        prev2 = lines[start - 1].strip()
                        if not (prev2.startswith('/*') or prev2.startswith('*') or prev2.endswith('*/')):
                            start += 1
                            break
                else:
                    break
            e['remove_start'] = start

        removed_count = 0
        removed_lines = 0
        for e in entries:
            start = e['remove_start']
            end = e['c_end']
            removed_lines += end - start + 1
            del lines[start:end + 1]
            removed_count += 1

        # Add extern declarations for functions that don't have them
        need_extern = set(e['c_name'] for e in entries) - existing_externs
        if need_extern:
            # Find insertion point
            insert_at = 0
            for idx, line in enumerate(lines):
                if line.strip().startswith('extern') and ('FUN_' in line or 'DAT_' in line or 'PTR_' in line):
                    insert_at = idx + 1

            for fname in sorted(need_extern):
                lines.insert(insert_at, 'extern void %s();\n' % fname)

        if not dry_run:
            with open(c_file, 'w', newline='\n') as f:
                f.writelines(lines)

        total_removed += removed_count
        total_lines += removed_lines
        print("  %s: removed %d functions (%d lines), added %d externs" % (
            os.path.basename(c_file), removed_count, removed_lines, len(need_extern)))

    return total_removed, total_lines


def main():
    if len(sys.argv) < 2:
        print("Usage: %s <src_dir> [--dry-run]" % sys.argv[0])
        sys.exit(1)

    src_dir = sys.argv[1]
    dry_run = '--dry-run' in sys.argv

    if dry_run:
        print("DRY RUN\n")

    # Step 1: Scan
    print("Scanning ASM imports...")
    asm_funcs = parse_asm_functions(src_dir)
    print("  Found %d ASM-imported functions" % len(asm_funcs))

    print("Scanning C functions...")
    c_funcs = parse_c_functions(src_dir)
    print("  Found %d C function definitions" % len(c_funcs))

    print("Finding overlaps...")
    overlaps = find_overlaps(asm_funcs, c_funcs)
    print("  Found %d overlapping functions\n" % len(overlaps))

    if not overlaps:
        return

    # Step 2: Add ASM labels
    print("Adding ASM labels...")
    labels_added, asm_files = add_asm_labels(overlaps, dry_run)
    print("  Added %d labels in %d ASM files\n" % (labels_added, len(asm_files)))

    # Step 3: Remove C functions
    print("Removing C functions...")
    funcs_removed, lines_removed = remove_c_functions(overlaps, dry_run)

    print("\nSummary:")
    print("  Labels added: %d" % labels_added)
    print("  Functions removed: %d" % funcs_removed)
    print("  Lines removed: %d" % lines_removed)


if __name__ == '__main__':
    main()
