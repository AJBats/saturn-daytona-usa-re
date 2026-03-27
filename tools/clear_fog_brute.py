#!/usr/bin/env python3
"""Brute-force fog clearing: try converting each .byte pool load, verify with assembler.

For each .byte pair with a comment like /* mov.l .L_xxx, rN */:
  1. Extract the label name and register from the comment
  2. Check if the label exists in the same file
  3. Try converting, assemble, compare output
  4. Keep if byte-identical, revert if not

Usage:
    python tools/clear_fog_brute.py --scan          # report what can be converted
    python tools/clear_fog_brute.py --apply          # apply verified conversions
    python tools/clear_fog_brute.py --apply FILE.s   # apply to one file
"""

import os
import re
import sys
import shutil
import subprocess
import tempfile
import argparse
from pathlib import Path

PROJECT = Path(__file__).resolve().parent.parent
SRC_DIR = PROJECT / 'reimpl' / 'src'
ASSEMBLER = PROJECT / 'tools' / 'sh-elf' / 'bin' / 'sh-elf-as'
OBJCOPY = PROJECT / 'tools' / 'sh-elf' / 'bin' / 'sh-elf-objcopy'


def find_convertible_lines(filepath):
    """Find .byte pool loads and try matching to labels in the same file.

    Strategy: for each .byte pool load, collect ALL pool-type labels
    (starting with .L_) in the file as candidates. The assembler
    verification step will determine which label produces identical output.
    """
    text = filepath.read_text()
    lines = text.splitlines(keepends=True)

    # Collect all label definitions in the file
    labels_defined = set()
    pool_labels = []  # labels that look like pool entries (.L_*)
    for line in lines:
        m = re.match(r'^(\.?[A-Za-z_]\w*)\s*:', line.strip())
        if m:
            name = m.group(1)
            labels_defined.add(name)
            if name.startswith('.L_'):
                pool_labels.append(name)

    # Find .byte pairs that are pool loads (mov.l = 0xDndd, mov.w = 0x9ndd)
    candidates = []
    for i, line in enumerate(lines):
        stripped = line.strip()
        m = re.match(
            r'\.byte\s+0x([0-9A-Fa-f]{2})\s*,\s*0x([0-9A-Fa-f]{2})',
            stripped)
        if not m:
            continue

        hi, lo = int(m.group(1), 16), int(m.group(2), 16)
        opcode_hi = hi >> 4
        reg = hi & 0xF

        if opcode_hi == 0xD:
            insn_type = 'mov.l'
        elif opcode_hi == 0x9:
            insn_type = 'mov.w'
        else:
            continue

        # Check comment for label hint first
        cm = re.search(r'/\*\s*mov\.[lw]\s+(\S+)\s*,\s*r\d+', stripped)
        comment_label = cm.group(1) if cm else None

        # Build candidate labels: comment label first, then all pool labels
        try_labels = []
        if comment_label and comment_label in labels_defined:
            try_labels.append(comment_label)
        for pl in pool_labels:
            if pl not in try_labels:
                try_labels.append(pl)

        if not try_labels:
            continue

        indent = line[:len(line) - len(line.lstrip())]
        candidates.append((i, line, insn_type, reg, indent, try_labels))

    return candidates


def to_wsl_path(win_path):
    """Convert Windows path to WSL path."""
    p = str(win_path).replace('\\', '/')
    if len(p) >= 2 and p[1] == ':':
        drive = p[0].lower()
        return f'/mnt/{drive}{p[2:]}'
    return p


def assemble_and_extract(src_path):
    """Assemble a .s file and return the raw binary content, or None on error."""
    with tempfile.NamedTemporaryFile(suffix='.o', delete=False, dir=str(src_path.parent)) as tmp_o:
        tmp_o_path = tmp_o.name
    with tempfile.NamedTemporaryFile(suffix='.bin', delete=False, dir=str(src_path.parent)) as tmp_bin:
        tmp_bin_path = tmp_bin.name

    wsl_src = to_wsl_path(src_path)
    wsl_o = to_wsl_path(tmp_o_path)
    wsl_bin = to_wsl_path(tmp_bin_path)
    wsl_as = to_wsl_path(ASSEMBLER)
    wsl_objcopy = to_wsl_path(OBJCOPY)

    try:
        # Assemble
        result = subprocess.run(
            ['wsl', '-d', 'Ubuntu', '--', wsl_as, '--isa=sh2', '-big', '-o', wsl_o, wsl_src],
            capture_output=True, text=True)
        if result.returncode != 0:
            return None

        # Extract raw binary
        result = subprocess.run(
            ['wsl', '-d', 'Ubuntu', '--', wsl_objcopy, '-O', 'binary', wsl_o, wsl_bin],
            capture_output=True, text=True)
        if result.returncode != 0:
            return None

        return Path(tmp_bin_path).read_bytes()
    finally:
        for p in [tmp_o_path, tmp_bin_path]:
            try:
                os.unlink(p)
            except OSError:
                pass


def process_file(filepath, apply=False):
    """Process one file. Returns (converted, total_candidates, details)."""
    candidates = find_convertible_lines(filepath)
    if not candidates:
        return 0, 0, []

    # Get baseline binary
    baseline = assemble_and_extract(filepath)
    if baseline is None:
        return 0, len(candidates), []

    text = filepath.read_text()
    lines = text.splitlines(keepends=True)

    # Try each candidate — find which label produces identical output
    verified = []
    for idx, old_line, insn_type, reg, indent, try_labels in candidates:
        found = False
        for label in try_labels:
            new_line = f"{indent}{insn_type}   {label}, r{reg}\n"

            test_lines = lines.copy()
            test_lines[idx] = new_line

            with tempfile.NamedTemporaryFile(mode='w', suffix='.s', delete=False,
                                             newline='\n', dir=str(filepath.parent)) as tmp:
                tmp.writelines(test_lines)
                tmp_path = tmp.name

            try:
                test_binary = assemble_and_extract(Path(tmp_path))
                if test_binary is not None and test_binary == baseline:
                    verified.append((idx, new_line, old_line.rstrip(), label))
                    found = True
                    break
            finally:
                os.unlink(tmp_path)

            # Optimization: if comment label didn't work, only try labels
            # near the instruction (within 1KB = 256 pool entries)
            # Stop after first 20 misses to avoid O(n^2) per file
            if try_labels.index(label) > 20:
                break

    if apply and verified:
        for idx, new_line, _, _ in verified:
            lines[idx] = new_line
        with open(filepath, 'w', newline='\n') as f:
            f.writelines(lines)

    return len(verified), len(candidates), verified


def main():
    parser = argparse.ArgumentParser(description="Brute-force fog clearing with assembler verification")
    parser.add_argument('--scan', action='store_true', help="Report convertible pool loads")
    parser.add_argument('--apply', action='store_true', help="Apply verified conversions")
    parser.add_argument('files', nargs='*', help="Specific files (default: all src/*.s)")
    args = parser.parse_args()

    if not args.files:
        args.files = sorted(SRC_DIR.glob('FUN_*.s'))
    else:
        args.files = [Path(f) for f in args.files]

    total_verified = 0
    total_candidates = 0
    files_converted = 0

    for fp in args.files:
        if fp.name == 'FUN_06046E48.s':
            continue

        conv, total, details = process_file(fp, apply=args.apply)
        total_verified += conv
        total_candidates += total

        if conv > 0:
            files_converted += 1
            if args.apply:
                print(f"  {fp.name}: converted {conv}/{total}")
            else:
                print(f"  {fp.name}: {conv}/{total} convertible")

    print(f"\n{'='*60}")
    print(f"  Files with conversions: {files_converted}")
    print(f"  Verified: {total_verified} / {total_candidates} candidates")
    print(f"{'='*60}")


if __name__ == "__main__":
    main()
