#!/usr/bin/env python3
"""Merge TU member files into their head's section (CCE-style).

Concatenates existing src/ (and retail/) files directly — no L3
regeneration. Strips .section directives from members, inlines
.reloc BSR/BRA when targets become same-section, deletes consumed files.

Based on DaytonaCCEReverse clear-fog-work:tools/merge_alignment_tus.py.

Usage:
    # Merge one group
    python tools/merge_tu.py --head FUN_0600C010 --members FUN_0600C170

    # Merge from a batch file (one group per line: head member1 member2 ...)
    python tools/merge_tu.py --batch tools/tu_groups.txt

    # Dry run
    python tools/merge_tu.py --batch tools/tu_groups.txt --dry-run
"""

import os
import re
import sys
import argparse
from pathlib import Path

PROJECT = Path(__file__).resolve().parent.parent
SRC_DIR = PROJECT / 'reimpl' / 'src'
RETAIL_DIR = PROJECT / 'reimpl' / 'retail'


def merge_group(head_name, member_names, dry_run=False, force_strip_section=False):
    """Merge member .s files into the head's .s file.

    Processes both src/ and retail/ directories.
    force_strip_section: strip .section from ALL members regardless of alignment
                         (used for cross-section pool merges where all members are 4-byte aligned).
    Returns (success, message).
    """
    results = []
    for src_dir in [SRC_DIR, RETAIL_DIR]:
        ok, msg = _merge_in_dir(src_dir, head_name, member_names, dry_run, force_strip_section)
        results.append((src_dir.name, ok, msg))

    all_ok = all(ok for _, ok, _ in results)
    msgs = [f"{d}: {msg}" for d, ok, msg in results]
    return all_ok, "; ".join(msgs)


def _merge_in_dir(src_dir, head_name, member_names, dry_run, force_strip_section=False):
    """Merge members into head within a single directory."""
    head_path = src_dir / f"{head_name}.s"
    if not head_path.exists():
        return False, f"head not found: {head_path.name}"

    # Check which members exist as files vs already embedded
    file_members = []
    for mn in member_names:
        mp = src_dir / f"{mn}.s"
        if mp.exists():
            file_members.append(mn)
        else:
            # Check if already embedded in head
            with open(head_path) as f:
                if f".global {mn}" in f.read():
                    continue
            return False, f"member not found and not embedded: {mn}"

    if not file_members:
        return True, "all members already embedded"

    # Read head file
    with open(head_path) as f:
        head_lines = f.readlines()

    # Collect all function names for reloc inlining
    fun_set = set()
    fun_set.add(head_name)
    for mn in member_names:
        fun_set.add(mn)
    for line in head_lines:
        m = re.match(r'\s*\.global\s+(FUN_[0-9A-Fa-f]+|sym_[0-9A-Fa-f]+)', line)
        if m:
            fun_set.add(m.group(1))

    # Read member files and collect their globals
    member_data = {}
    for mn in file_members:
        mp = src_dir / f"{mn}.s"
        with open(mp) as f:
            member_data[mn] = f.readlines()
        for line in member_data[mn]:
            m = re.match(r'\s*\.global\s+(FUN_[0-9A-Fa-f]+|sym_[0-9A-Fa-f]+)', line)
            if m:
                fun_set.add(m.group(1))

    # Inline relocs targeting merged partners
    reloc_count = 0
    reloc_count += _inline_relocs(head_lines, fun_set)
    for mn in file_members:
        reloc_count += _inline_relocs(member_data[mn], fun_set)

    if dry_run:
        return True, f"would merge {len(file_members)} files, {reloc_count} relocs inlined"

    # Build merged output
    merged = []

    # Add head content as-is
    for line in head_lines:
        merged.append(line)

    # Ensure newline between head and first member
    if merged and merged[-1].strip():
        merged.append("\n")

    # Add each member
    for mn in file_members:
        lines = member_data[mn]
        merged.append("\n")
        # Determine if member's .section should be stripped or kept.
        # Non-aligned members (addr % 4 != 0) are inner TU functions —
        # strip their .section so they join the head's section.
        # Aligned members (addr % 4 == 0) had their own linker section —
        # KEEP their .section directive so the linker sort order is preserved.
        member_addr_m = re.search(r'FUN_([0-9A-F]+)', mn)
        member_aligned = True
        if member_addr_m:
            member_addr = int(member_addr_m.group(1), 16)
            member_aligned = (member_addr % 4 == 0)
        skip_blank = True  # skip leading blanks after stripping header
        for line in lines:
            stripped = line.strip()
            # Strip .section for non-aligned members OR when force_strip_section is set
            if stripped.startswith(".section") and (not member_aligned or force_strip_section):
                continue
            # Skip header comments (/* FUN_xxx -- ... */ or /* TU: ... */)
            if stripped.startswith("/*") and (mn in stripped or "TU:" in stripped) and stripped.endswith("*/"):
                continue
            # Skip leading blank lines
            if skip_blank and not stripped:
                continue
            skip_blank = False
            merged.append(line)

    # Write merged file
    with open(head_path, 'w', newline='\n') as f:
        f.writelines(merged)

    # Remove consumed member files
    removed = 0
    for mn in file_members:
        mp = src_dir / f"{mn}.s"
        if mp.exists():
            os.remove(mp)
            removed += 1

    return True, f"merged {len(file_members)} files, {reloc_count} relocs inlined, {removed} removed"


def _inline_relocs(lines, fun_set):
    """Convert .reloc R_SH_IND12W targeting fun_set to direct bsr/bra.

    When two functions are in the same section, .reloc + .2byte can be
    replaced with a direct bsr/bra mnemonic.
    """
    conversions = 0
    i = 0
    while i < len(lines):
        line = lines[i].strip()
        m = re.match(
            r'\.reloc\s+\.\s*,\s*R_SH_IND12W\s*,\s*(FUN_[0-9A-Fa-f]+|sym_[0-9A-Fa-f]+)\s*-\s*4',
            line)
        if m and m.group(1) in fun_set:
            target = m.group(1)
            if i + 1 < len(lines):
                next_line = lines[i + 1].strip()
                bsr_m = re.match(r'\.2byte\s+0xB000', next_line)
                bra_m = re.match(r'\.2byte\s+0xA000', next_line)
                if bsr_m or bra_m:
                    mnemonic = "bsr" if bsr_m else "bra"
                    indent = lines[i][:len(lines[i]) - len(lines[i].lstrip())]
                    lines[i] = f"{indent}{mnemonic}     {target}\n"
                    # Remove the .2byte line and any trailing comment
                    lines[i + 1] = ""
                    conversions += 1
                    i += 2
                    continue
        i += 1
    return conversions


def main():
    parser = argparse.ArgumentParser(description="Merge TU members into head (CCE-style)")
    parser.add_argument('--head', help="Head function name (e.g., FUN_0600C010)")
    parser.add_argument('--members', nargs='+', help="Member function names to merge")
    parser.add_argument('--batch', help="Batch file: one group per line (head member1 member2 ...)")
    parser.add_argument('--dry-run', action='store_true', help="Show plan without executing")
    parser.add_argument('--force-strip-section', action='store_true',
                        help="Strip .section from ALL members (for cross-section pool merges)")
    args = parser.parse_args()

    if args.batch:
        with open(args.batch) as f:
            groups = []
            for line in f:
                line = line.strip()
                if not line or line.startswith('#'):
                    continue
                parts = line.split()
                if len(parts) >= 2:
                    groups.append((parts[0], parts[1:]))

        success = 0
        fail = 0
        for head, members in groups:
            ok, msg = merge_group(head, members, args.dry_run, args.force_strip_section)
            if ok:
                success += 1
                if not args.dry_run:
                    print(f"  OK: {head} <- {', '.join(members)} ({msg})")
            else:
                fail += 1
                print(f"  FAIL: {head} <- {', '.join(members)} ({msg})")

        print(f"\n{success} succeeded, {fail} failed")

    elif args.head and args.members:
        ok, msg = merge_group(args.head, args.members, args.dry_run, args.force_strip_section)
        print(f"{'OK' if ok else 'FAIL'}: {args.head} <- {', '.join(args.members)} ({msg})")

    else:
        parser.print_help()


if __name__ == "__main__":
    main()
