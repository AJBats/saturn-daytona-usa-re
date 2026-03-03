#!/usr/bin/env python3
"""
Rename reimpl/src/*.s and reimpl/retail/*.s files from human-readable names
to 8-char hex address format (e.g., anim_frame_counter.s → 06005928.s).

The hex address is extracted from the .section .text.FUN_XXXXXXXX directive.
_start.s and mods/ subdirectories are left untouched.

Usage:
    python tools/rename_to_hex.py --dry-run    # preview
    python tools/rename_to_hex.py              # apply (uses git mv)
"""

import re
import os
import sys
import subprocess

REIMPL_DIR = os.path.join(os.path.dirname(__file__), '..', 'reimpl')
SRC_DIR = os.path.join(REIMPL_DIR, 'src')
RETAIL_DIR = os.path.join(REIMPL_DIR, 'retail')

SECTION_RE = re.compile(r'\.section\s+\.text\.FUN_([0-9A-Fa-f]{8})')

SKIP_FILES = {'_start.s'}


def get_hex_addr(filepath):
    """Extract the FUN_XXXXXXXX hex address from a .s file."""
    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        for line in f:
            m = SECTION_RE.search(line)
            if m:
                return m.group(1)
    return None


def build_rename_map(directory):
    """Build old_name -> new_name mapping for a directory."""
    renames = []
    for fname in sorted(os.listdir(directory)):
        if not fname.endswith('.s') or fname in SKIP_FILES:
            continue
        filepath = os.path.join(directory, fname)
        if not os.path.isfile(filepath):
            continue
        hex_addr = get_hex_addr(filepath)
        if hex_addr is None:
            print(f"  WARNING: no FUN_ section in {fname}, skipping")
            continue
        new_name = f"{hex_addr}.s"
        if fname != new_name:
            renames.append((fname, new_name, filepath))
    return renames


def main():
    dry_run = '--dry-run' in sys.argv

    for label, directory in [('src', SRC_DIR), ('retail', RETAIL_DIR)]:
        print(f"\n{'='*60}")
        print(f"  {label}/ directory")
        print(f"{'='*60}")

        renames = build_rename_map(directory)
        already_hex = 0
        for fname in sorted(os.listdir(directory)):
            if fname.endswith('.s') and re.match(r'^[0-9A-Fa-f]{8}\.s$', fname):
                already_hex += 1

        print(f"  Files to rename: {len(renames)}")
        print(f"  Already hex:     {already_hex}")

        # Check for collisions
        new_names = [r[1] for r in renames]
        if len(new_names) != len(set(new_names)):
            dupes = [n for n in new_names if new_names.count(n) > 1]
            print(f"  ERROR: duplicate target names: {set(dupes)}")
            sys.exit(1)

        if dry_run:
            for old, new, _ in renames[:10]:
                print(f"    {old} -> {new}")
            if len(renames) > 10:
                print(f"    ... and {len(renames) - 10} more")
        else:
            for old, new, filepath in renames:
                new_path = os.path.join(directory, new)
                subprocess.run(['git', 'mv', filepath, new_path],
                             check=True, capture_output=True)
            print(f"  Renamed {len(renames)} files")

    if dry_run:
        total = sum(len(build_rename_map(d)) for d in [SRC_DIR, RETAIL_DIR])
        print(f"\nDRY RUN: {total} files would be renamed.")
        print("Re-run without --dry-run to apply.")


if __name__ == '__main__':
    main()
