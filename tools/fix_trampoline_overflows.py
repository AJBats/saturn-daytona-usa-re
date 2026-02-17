#!/usr/bin/env python3
"""fix_trampoline_overflows.py -- Remove unnecessary trampolines

For functions that have ASM byte imports (exact original bytes), the
trampoline is no longer needed. The ASM import fits the slot exactly,
so the 12-byte trampoline just causes a +12 byte overflow.

This script:
1. Runs the audit to find functions with exactly +12 byte overflow
2. Checks if each has an ASM byte import in the source
3. Removes the trampoline entry from trampolines.s for those functions

Usage: python tools/fix_trampoline_overflows.py [--dry-run]
"""

import re
import sys
import os
import subprocess

REIMPL_DIR = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'reimpl')
TRAMPOLINE_FILE = os.path.join(REIMPL_DIR, 'src', 'trampolines.s')

def get_overflow_12_functions():
    """Get list of functions with exactly +12 byte overflow from the ELF."""
    # We'll parse the map file + aprog.s to find these
    # But simpler: just use the audit tool's output
    audit_script = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'audit_functions.py')
    result = subprocess.run(
        [sys.executable, audit_script],
        capture_output=True, text=True, cwd=os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    )

    overflow_12 = []
    for line in result.stdout.split('\n'):
        # Look for lines like: FUN_XXXXXXXX ... Overflow ... +12
        # The audit output format varies, let's parse it
        if 'Overflow' in line or 'overflow' in line:
            m = re.search(r'(FUN_[0-9A-Fa-f]+)', line)
            if m:
                # Check if overflow is exactly 12
                # Format: "FUN_060032D4  54B slot  66B compiled  +12B overflow  122%"
                overflow_match = re.search(r'\+(\d+)B?\s+overflow', line, re.IGNORECASE)
                if not overflow_match:
                    # Try alternate format: compiled - slot
                    nums = re.findall(r'(\d+)B?\s+(?:slot|compiled)', line)
                    if len(nums) >= 2:
                        slot = int(nums[0])
                        compiled = int(nums[1])
                        if compiled - slot == 12:
                            overflow_12.append(m.group(1))
                elif int(overflow_match.group(1)) == 12:
                    overflow_12.append(m.group(1))

    return overflow_12


def find_asm_import_functions():
    """Find all functions that have ASM byte imports in source files."""
    asm_funcs = set()
    src_dir = os.path.join(REIMPL_DIR, 'src')

    for fname in os.listdir(src_dir):
        if not fname.endswith('.c'):
            continue
        filepath = os.path.join(src_dir, fname)
        with open(filepath, 'r') as f:
            content = f.read()

        # Look for ASM import pattern: .section .text.FUN_XXXXXXXX
        for m in re.finditer(r'\.section\s+\.text\.(FUN_[0-9A-Fa-f]+)', content):
            asm_funcs.add(m.group(1))

    return asm_funcs


def find_trampoline_functions():
    """Parse trampolines.s and return dict mapping FUN name -> (start_line, end_line)."""
    with open(TRAMPOLINE_FILE, 'r') as f:
        lines = f.readlines()

    trampolines = {}
    current_func = None
    current_start = None

    for i, line in enumerate(lines):
        m = re.match(r'\s*\.section\s+\.text\.trampoline_(FUN_[0-9A-Fa-f]+)', line)
        if m:
            # Close previous trampoline
            if current_func is not None:
                trampolines[current_func] = (current_start, i - 1)
            current_func = m.group(1)
            current_start = i

    # Close last trampoline
    if current_func is not None:
        trampolines[current_func] = (current_start, len(lines) - 1)

    return trampolines, lines


def remove_trampolines(functions_to_remove, dry_run=False):
    """Remove trampoline entries for specified functions."""
    trampolines, lines = find_trampoline_functions()

    # Find lines to remove
    lines_to_remove = set()
    removed = []

    for func in functions_to_remove:
        if func in trampolines:
            start, end = trampolines[func]
            for i in range(start, end + 1):
                lines_to_remove.add(i)
            removed.append(func)

    if dry_run:
        print(f"Would remove {len(removed)} trampolines:")
        for func in sorted(removed):
            start, end = trampolines[func]
            print(f"  {func}: lines {start+1}-{end+1}")
        return removed

    # Write new file without removed lines
    new_lines = []
    for i, line in enumerate(lines):
        if i not in lines_to_remove:
            new_lines.append(line)

    # Clean up multiple consecutive blank lines
    cleaned = []
    prev_blank = False
    for line in new_lines:
        is_blank = line.strip() == ''
        if is_blank and prev_blank:
            continue
        cleaned.append(line)
        prev_blank = is_blank

    with open(TRAMPOLINE_FILE, 'w') as f:
        f.writelines(cleaned)

    print(f"Removed {len(removed)} trampolines from {TRAMPOLINE_FILE}")
    return removed


def main():
    dry_run = '--dry-run' in sys.argv

    # Strategy: find functions that are in the overflow-12 list AND have ASM imports
    # These are safe to remove trampolines for

    print("Finding functions with ASM byte imports...")
    asm_funcs = find_asm_import_functions()
    print(f"  Found {len(asm_funcs)} functions with ASM imports")

    print("\nFinding trampoline entries...")
    trampolines, _ = find_trampoline_functions()
    print(f"  Found {len(trampolines)} trampolines")

    # Find overlap: functions with both ASM imports and trampolines
    overlap = asm_funcs & set(trampolines.keys())
    print(f"\nFunctions with BOTH ASM import and trampoline: {len(overlap)}")

    if overlap:
        removed = remove_trampolines(sorted(overlap), dry_run=dry_run)
        print(f"\n{'Would remove' if dry_run else 'Removed'}: {len(removed)} trampolines")
        for func in sorted(removed):
            print(f"  {func}")
    else:
        print("No overlapping functions found - nothing to do")


if __name__ == '__main__':
    main()
