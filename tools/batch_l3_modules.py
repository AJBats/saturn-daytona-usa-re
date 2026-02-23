#!/usr/bin/env python3
"""Batch L3 uplift for multi-function modules.

Reads build/multi_func_modules.txt, consolidates retail files for each module,
generates L3 src files, and deletes old individual retail files.

Uses explicit file lists (not address ranges) to avoid merging overlapping
but independent modules.

Usage:
    python tools/batch_l3_modules.py [--dry-run] [--consolidate-only] [--l3-only]
"""

import argparse
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
RETAIL_DIR = os.path.join(ROOT, 'reimpl', 'retail')
SRC_DIR = os.path.join(ROOT, 'reimpl', 'src')
MODULES_FILE = os.path.join(ROOT, 'build', 'multi_func_modules.txt')
TOOLS_DIR = os.path.join(ROOT, 'tools')


def parse_modules(path):
    """Parse build/multi_func_modules.txt into list of modules."""
    modules = []
    current = None
    with open(path, 'r') as f:
        for line in f:
            line = line.rstrip()
            m = re.match(r'MODULE\s+(\d+)\s+funcs\s+(0x[0-9A-Fa-f]+)-(0x[0-9A-Fa-f]+)', line)
            if m:
                if current:
                    modules.append(current)
                current = {
                    'count': int(m.group(1)),
                    'start': m.group(2),
                    'end': m.group(3),
                    'start_int': int(m.group(2), 16),
                    'end_int': int(m.group(3), 16),
                    'funcs': [],
                }
            elif current and line.strip():
                current['funcs'].append(line.strip())
    if current:
        modules.append(current)
    return modules


def get_tu_name(module):
    """Choose a TU name for a module based on its first named function."""
    for func in module['funcs']:
        if not func.startswith('FUN_'):
            return func
    # All FUN_ — use address-based name
    return f"module_{module['start'][2:]}"


def get_section_addr(filepath):
    """Get the lowest section address from a retail .s file."""
    with open(filepath, 'r') as f:
        for line in f:
            m = re.search(r'\.section\s+\.text\.FUN_([0-9A-Fa-f]+)', line)
            if m:
                return int(m.group(1), 16)
    return None


def consolidate_by_filelist(tu_name, func_stems, start_int, end_int):
    """Consolidate specific retail files into one, ordered by section address.

    Returns (output_path, files_consumed, error_msg).
    """
    output = os.path.join(RETAIL_DIR, f'{tu_name}.s')

    # Collect existing individual files with their section addresses.
    # Read contents into memory first so we can safely overwrite the output
    # file even if it matches one of the input stems.
    files = []
    for stem in func_stems:
        path = os.path.join(RETAIL_DIR, f'{stem}.s')
        if not os.path.exists(path):
            continue
        addr = get_section_addr(path)
        if addr is not None:
            with open(path, 'r') as f:
                content = f.read()
            files.append((addr, stem, path, content))

    if not files:
        return None, [], "No individual files found"

    # Sort by address for proper ordering
    files.sort(key=lambda x: x[0])

    size_bytes = end_int - start_int

    # Build header
    header = f"""\
/* {tu_name}
 *
 * Translation unit: 0x{start_int:08X} - 0x{end_int:08X} (~{size_bytes:,} bytes, {len(files)} functions)
 * Reconstructed from cross-section pool sharing analysis.
 *
 * Each function retains its own .section directive for retail byte-identical
 * builds. The free-build src/ file uses a single section for all functions.
 */

"""

    # Write consolidated file (may overwrite one of the input files)
    with open(output, 'w', newline='\n') as out:
        out.write(header)
        for addr, stem, path, content in files:
            out.write(content.rstrip() + '\n')
            out.write('\n')

    # All input files are consumed; exclude the output path from deletion list
    consumed = [path for _, _, path, _ in files
                if os.path.abspath(path) != os.path.abspath(output)]
    return output, consumed, None


def run_generate_l3(tu_name):
    """Run generate_l3_tu.py for a module."""
    cmd = [sys.executable, os.path.join(TOOLS_DIR, 'generate_l3_tu.py'), tu_name]
    result = subprocess.run(cmd, capture_output=True, text=True, cwd=ROOT)
    return result


def test_assemble(tu_name):
    """Test-assemble a single src file."""
    src_path = os.path.join(SRC_DIR, f'{tu_name}.s')
    if not os.path.exists(src_path):
        return False, "src file not found"
    cmd = ['sh-elf-as', '--fatal-warnings', '-o', '/dev/null', src_path]
    result = subprocess.run(cmd, capture_output=True, text=True)
    if result.returncode != 0:
        return False, result.stderr[:500]
    return True, ""


def main():
    parser = argparse.ArgumentParser(description='Batch L3 uplift for multi-function modules')
    parser.add_argument('--dry-run', action='store_true', help='Show what would be done')
    parser.add_argument('--consolidate-only', action='store_true', help='Only consolidate, no L3')
    parser.add_argument('--l3-only', action='store_true', help='Only generate L3 (assumes already consolidated)')
    args = parser.parse_args()

    modules = parse_modules(MODULES_FILE)
    print(f"Parsed {len(modules)} modules from {MODULES_FILE}")

    # Classify modules
    skipped_absorbed = []
    skipped_c_override = []
    skipped_exists = []
    to_process = []

    for mod in modules:
        tu_name = get_tu_name(mod)

        # Check if consolidated retail + L3 already exist
        retail_path = os.path.join(RETAIL_DIR, f'{tu_name}.s')
        src_path = os.path.join(SRC_DIR, f'{tu_name}.s')
        if os.path.exists(retail_path) and os.path.exists(src_path):
            skipped_exists.append((tu_name, mod))
            continue

        # Count how many individual files exist
        existing = sum(1 for f in mod['funcs']
                       if os.path.exists(os.path.join(RETAIL_DIR, f'{f}.s')))
        if existing == 0:
            skipped_absorbed.append((tu_name, mod))
            continue

        # Check for C overrides
        c_func = next((f for f in mod['funcs']
                       if os.path.exists(os.path.join(SRC_DIR, f'{f}.c'))), None)
        if c_func:
            skipped_c_override.append((tu_name, mod, c_func))
            continue

        to_process.append((tu_name, mod, existing))

    print(f"\n=== Module Classification ===")
    print(f"  To process:        {len(to_process)}")
    print(f"  Already done:      {len(skipped_exists)}")
    print(f"  Already absorbed:  {len(skipped_absorbed)}")
    print(f"  Has C override:    {len(skipped_c_override)}")
    total_funcs = sum(m['count'] for _, m, _ in to_process)
    print(f"  Total functions:   {total_funcs}")

    if skipped_c_override:
        print(f"\n  C override modules:")
        for name, mod, c_func in skipped_c_override:
            print(f"    {name} ({mod['count']} funcs) -- {c_func}.c")

    if args.dry_run:
        print(f"\n=== Dry Run -- Modules to Process ===")
        for tu_name, mod, count in to_process:
            print(f"  {tu_name:40s} {mod['count']:3d} funcs  "
                  f"{mod['start']}-{mod['end']}  ({count} files)")
        return

    # Phase 1: Consolidate by explicit file list
    if not args.l3_only:
        print(f"\n=== Phase 1: Consolidating {len(to_process)} modules ===")
        consolidated = []
        failed_consolidate = []
        all_files_to_delete = []

        for i, (tu_name, mod, _) in enumerate(to_process):
            output, consumed, err = consolidate_by_filelist(
                tu_name, mod['funcs'], mod['start_int'], mod['end_int'])

            if err:
                print(f"  [{i+1:3d}/{len(to_process)}] {tu_name:40s} SKIP ({err})")
                continue

            print(f"  [{i+1:3d}/{len(to_process)}] {tu_name:40s} OK ({len(consumed)} files)")
            consolidated.append((tu_name, mod))
            all_files_to_delete.extend(consumed)

        # Delete individual files
        if all_files_to_delete:
            print(f"\n  Deleting {len(all_files_to_delete)} individual retail files...")
            deleted = 0
            for fpath in all_files_to_delete:
                try:
                    os.remove(fpath)
                    deleted += 1
                except OSError as e:
                    print(f"    WARN: Could not delete {fpath}: {e}")
            print(f"  Deleted {deleted} files.")

        to_process_l3 = [(name, mod, 0) for name, mod in consolidated]
    else:
        # L3-only mode
        to_process_l3 = []
        for tu_name, mod, _ in to_process:
            retail_path = os.path.join(RETAIL_DIR, f'{tu_name}.s')
            src_path = os.path.join(SRC_DIR, f'{tu_name}.s')
            if os.path.exists(retail_path) and not os.path.exists(src_path):
                to_process_l3.append((tu_name, mod, 0))

    # Phase 2: Generate L3
    if not args.consolidate_only:
        print(f"\n=== Phase 2: Generating L3 for {len(to_process_l3)} modules ===")
        generated = []
        failed_l3 = []

        for i, (tu_name, mod, _) in enumerate(to_process_l3):
            result = run_generate_l3(tu_name)
            if result.returncode != 0:
                print(f"  [{i+1:3d}/{len(to_process_l3)}] {tu_name:40s} FAIL")
                err = result.stderr[:300] if result.stderr else result.stdout[:300]
                print(f"    {err}")
                failed_l3.append((tu_name, mod, err))
                continue

            print(f"  [{i+1:3d}/{len(to_process_l3)}] {tu_name:40s} OK")
            generated.append((tu_name, mod))

        if failed_l3:
            print(f"\n  Failed L3 generations: {len(failed_l3)}")
            for name, mod, err in failed_l3:
                print(f"    {name} ({mod['count']} funcs): {err[:100]}")

    # Phase 3: Test assembly
    if not args.consolidate_only:
        names_to_test = [name for name, _ in generated]
        print(f"\n=== Phase 3: Test assembly for {len(names_to_test)} files ===")
        passed = 0
        failed_asm = []

        for tu_name in names_to_test:
            ok, err = test_assemble(tu_name)
            if ok:
                passed += 1
            else:
                failed_asm.append((tu_name, err))

        print(f"  Passed: {passed}")
        if failed_asm:
            print(f"  Failed: {len(failed_asm)}")
            for name, err in failed_asm:
                print(f"    {name}: {err[:200]}")

    # Summary
    print(f"\n=== Summary ===")
    if not args.l3_only and not args.consolidate_only:
        print(f"  Modules consolidated:  {len(consolidated)}")
        print(f"  L3 files generated:    {len(generated)}")
        print(f"  Assembly passed:       {passed}")
        if failed_asm:
            print(f"  Assembly failed:       {len(failed_asm)}")
            print(f"\n  Failed files (remove from src/ before building):")
            for name, _ in failed_asm:
                print(f"    reimpl/src/{name}.s")


if __name__ == '__main__':
    main()
