#!/usr/bin/env python3
"""Batch rename FUN_XXXXXXXX functions to human-readable names.

Usage:
    python tools/batch_rename.py tools/rename_batch.txt [--dry-run]

Input file format (one per line):
    FUN_XXXXXXXX new_name

Does NOT touch .section names (they're sort keys and must stay as FUN_).
"""

import sys
import os
import re
import subprocess
from pathlib import Path

RETAIL_DIR = Path("reimpl/retail")
SEGA_LD = Path("reimpl/sega.ld")
FREE_LD = Path("reimpl/free.ld")


def find_callers(fun_name):
    """Find all .s files that reference this FUN_ name (excluding build/)."""
    result = subprocess.run(
        ["grep", "-rl", fun_name, "reimpl/retail/", "reimpl/src/"],
        capture_output=True, text=True, cwd="."
    )
    files = [f for f in result.stdout.strip().split('\n') if f]
    return files


def rename_function(old_name, new_name, dry_run=False):
    """Rename a single function. Returns list of actions taken."""
    actions = []
    old_file = RETAIL_DIR / f"{old_name}.s"
    new_file = RETAIL_DIR / f"{new_name}.s"

    if not old_file.exists():
        return [f"ERROR: {old_file} does not exist"]

    # 1. git mv
    if not dry_run:
        subprocess.run(["git", "mv", str(old_file), str(new_file)], check=True)
    actions.append(f"git mv {old_file} -> {new_file}")

    # 2. Edit the renamed file: .global, .type, label (NOT .section)
    content = new_file.read_text() if not dry_run else old_file.read_text()

    # Replace .global FUN_XXXXXXXX -> .global new_name
    content = re.sub(
        rf'\.global\s+{re.escape(old_name)}\b',
        f'.global {new_name}',
        content
    )
    # Replace .type FUN_XXXXXXXX, @function -> .type new_name, @function
    content = re.sub(
        rf'\.type\s+{re.escape(old_name)}\s*,',
        f'.type {new_name},',
        content
    )
    # Replace label (start of line): FUN_XXXXXXXX: -> new_name:
    content = re.sub(
        rf'^{re.escape(old_name)}:',
        f'{new_name}:',
        content,
        flags=re.MULTILINE
    )

    if not dry_run:
        new_file.write_text(content)
    actions.append(f"Updated .global/.type/label in {new_file}")

    # 3. Find and update all callers
    callers = find_callers(old_name)
    for caller_path in callers:
        caller = Path(caller_path)
        if caller == new_file or caller == old_file:
            continue
        if 'build/' in str(caller):
            continue

        caller_content = caller.read_text()
        # Replace all references EXCEPT .section lines
        lines = caller_content.split('\n')
        updated_lines = []
        changed = False
        for line in lines:
            if '.section' in line or '.text.' in line:
                updated_lines.append(line)
            else:
                new_line = re.sub(
                    rf'\b{re.escape(old_name)}\b',
                    new_name,
                    line
                )
                if new_line != line:
                    changed = True
                updated_lines.append(new_line)
        updated = '\n'.join(updated_lines)
        if changed:
            if not dry_run:
                caller.write_text(updated)
            actions.append(f"Updated caller refs in {caller}")

    # 4. Update sega.ld
    sega_content = SEGA_LD.read_text()
    old_provide = f"PROVIDE({old_name} = {old_name} + 0x0);"
    new_provide = f"PROVIDE({new_name} = {new_name} + 0x0);"
    if old_provide in sega_content:
        sega_content = sega_content.replace(old_provide, new_provide)
        if not dry_run:
            SEGA_LD.write_text(sega_content)
        actions.append(f"Updated sega.ld PROVIDE")

    # 5. Update free.ld - DAT_ entries that reference this function
    free_content = FREE_LD.read_text()
    # Pattern: PROVIDE(DAT_XXXXXXXX = old_name + 0xNN);
    old_pat = re.escape(old_name)
    updated_free = re.sub(
        rf'(PROVIDE\(DAT_[0-9a-f]+ = ){old_pat}(\s*\+)',
        rf'\g<1>{new_name}\g<2>',
        free_content
    )
    if updated_free != free_content:
        if not dry_run:
            FREE_LD.write_text(updated_free)
        actions.append(f"Updated free.ld DAT_ references")

    return actions


def main():
    if len(sys.argv) < 2:
        print("Usage: python tools/batch_rename.py <mapping_file> [--dry-run]")
        sys.exit(1)

    mapping_file = sys.argv[1]
    dry_run = "--dry-run" in sys.argv

    # Parse mapping file
    renames = []
    with open(mapping_file) as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('#'):
                continue
            parts = line.split()
            if len(parts) != 2:
                print(f"WARNING: Skipping malformed line: {line}")
                continue
            old_name, new_name = parts
            renames.append((old_name, new_name))

    print(f"{'DRY RUN: ' if dry_run else ''}Processing {len(renames)} renames...")

    for i, (old_name, new_name) in enumerate(renames, 1):
        print(f"\n[{i}/{len(renames)}] {old_name} -> {new_name}")
        actions = rename_function(old_name, new_name, dry_run)
        for a in actions:
            print(f"  {a}")

    print(f"\n{'DRY RUN complete' if dry_run else 'All renames complete'}.")
    print("Next: verify no stale refs, then run validate_build.py")


if __name__ == "__main__":
    main()
