#!/usr/bin/env python3
"""Convert PC-relative .byte pool loads to mov.l/mov.w mnemonics.

For each .byte pair that decodes to a mov.l or mov.w @(disp,PC):
  1. Compute the pool target address from the displacement
  2. Find the label at that address in the same file
  3. Replace .byte with proper mnemonic

Only converts when the target label exists in the same file (same section).
Cross-section references stay as .byte.

Usage:
    python tools/clear_fog.py --scan                    # report what can be converted
    python tools/clear_fog.py --apply                   # apply conversions
    python tools/clear_fog.py --apply reimpl/src/FILE.s # apply to one file
"""

import os
import re
import sys
import argparse
from pathlib import Path

PROJECT = Path(__file__).resolve().parent.parent
SRC_DIR = PROJECT / 'reimpl' / 'src'


def compute_pc(section_addr, lines, line_idx):
    """Compute PC value at a given line index.

    PC = section_addr + sum of byte sizes of all lines before this one.
    """
    offset = 0
    for i in range(line_idx):
        offset += line_byte_size(lines[i])
    return section_addr + offset


def compute_line_sizes(lines):
    """Compute byte sizes for all lines, tracking block comment state."""
    sizes = []
    in_comment = False
    for line in lines:
        stripped = line.strip()
        if in_comment:
            sizes.append(0)
            if '*/' in stripped:
                in_comment = False
            continue
        if stripped.startswith('/*'):
            sizes.append(0)
            if '*/' not in stripped:
                in_comment = True
            continue
        sizes.append(line_byte_size(line))
    return sizes


def line_byte_size(text):
    """Return bytes emitted by one assembly source line (no comment tracking)."""
    stripped = text.strip()
    if not stripped:
        return 0
    if stripped.startswith('/*') or stripped.startswith('*'):
        return 0  # single-line comment
    if stripped.startswith('.section') or stripped.startswith('.global') or \
       stripped.startswith('.type') or stripped.startswith('.align') or \
       stripped.startswith('.balign'):
        return 0
    # Labels (with or without colon)
    if re.match(r'^[A-Za-z_\.]\w*:\s*$', stripped):
        return 0
    # .byte with two hex values = 2 bytes
    if re.match(r'\.byte\s+0x[0-9A-Fa-f]+\s*,\s*0x[0-9A-Fa-f]+', stripped):
        return 2
    # .byte with one hex value = 1 byte
    if re.match(r'\.byte\s+0x[0-9A-Fa-f]+\s*$', stripped):
        return 1
    # .2byte = 2 bytes
    if stripped.startswith('.2byte'):
        return 2
    # .4byte = 4 bytes
    if stripped.startswith('.4byte'):
        return 4
    # .reloc = 0 bytes (assembler directive)
    if stripped.startswith('.reloc'):
        return 0
    # .word = 2 bytes
    if stripped.startswith('.word'):
        return 2
    # Labels (with colon, possibly with instruction after)
    if re.match(r'^[A-Za-z_\.]\w*:', stripped):
        rest = stripped.split(':', 1)[1].strip()
        if rest:
            return 2  # instruction after label
        return 0
    # Everything else that looks like an instruction = 2 bytes (SH-2)
    # This catches all mnemonics without needing an exhaustive list
    if re.match(r'[a-z]', stripped, re.IGNORECASE):
        return 2
    return 0


def extract_section_addr(lines):
    """Extract the section base address from .section directive."""
    for line in lines:
        m = re.search(r'\.section\s+\.text\.(FUN_|sym_|DAT_)([0-9A-Fa-f]{6,8})', line)
        if m:
            return int(m.group(2), 16)
    return None


def build_label_map(lines, section_addr):
    """Build map of label_name -> address for all labels in the file."""
    labels = {}
    sizes = compute_line_sizes(lines)
    offset = 0
    for i, line in enumerate(lines):
        stripped = line.strip()
        m = re.match(r'^(\.?[A-Za-z_]\w*)\s*:', stripped)
        if m:
            label_name = m.group(1)
            labels[label_name] = section_addr + offset
        offset += sizes[i]
    return labels


def build_addr_to_label(labels):
    """Reverse map: address -> label_name."""
    addr_map = {}
    for name, addr in labels.items():
        addr_map[addr] = name
    return addr_map


def parse_pool_load(byte_line):
    """Parse a .byte pair that's a mov.l or mov.w @(disp,PC).

    Returns (opcode_hi, opcode_lo, insn_type, reg, disp) or None.
    insn_type is 'mov.l' or 'mov.w'.
    """
    m = re.match(r'\s*\.byte\s+0x([0-9A-Fa-f]{2})\s*,\s*0x([0-9A-Fa-f]{2})', byte_line)
    if not m:
        return None

    hi = int(m.group(1), 16)
    lo = int(m.group(2), 16)
    opcode = (hi << 8) | lo

    # mov.l @(disp,PC),Rn — 1101nnnndddddddd
    if (opcode >> 12) == 0xD:
        reg = (opcode >> 8) & 0xF
        disp = opcode & 0xFF
        return (hi, lo, 'mov.l', reg, disp)

    # mov.w @(disp,PC),Rn — 1001nnnndddddddd
    if (opcode >> 12) == 0x9:
        reg = (opcode >> 8) & 0xF
        disp = opcode & 0xFF
        return (hi, lo, 'mov.w', reg, disp)

    return None


def compute_pool_target(insn_type, pc, disp):
    """Compute the absolute address of the pool entry.

    mov.l: target = (PC & ~3) + 4 + disp*4
    mov.w: target = PC + 4 + disp*2
    """
    if insn_type == 'mov.l':
        return (pc & ~3) + 4 + disp * 4
    else:  # mov.w
        return pc + 4 + disp * 2


def process_file(filepath, apply=False):
    """Process one .s file. Returns (convertible, total_pool_loads, conversions_list)."""
    with open(filepath, 'r') as f:
        lines = f.readlines()

    section_addr = extract_section_addr(lines)
    if section_addr is None:
        return 0, 0, []

    labels = build_label_map(lines, section_addr)
    addr_to_label = build_addr_to_label(labels)
    sizes = compute_line_sizes(lines)
    section_size = sum(sizes)

    # Pass 1: identify pool loads and needed labels
    total = 0
    needed_labels = {}  # target_addr -> label_name
    pool_loads = []     # (line_idx, insn_type, reg, target)
    offset = 0

    for i, line in enumerate(lines):
        parsed = parse_pool_load(line)
        if parsed:
            hi, lo, insn_type, reg, disp = parsed
            pc = section_addr + offset
            target = compute_pool_target(insn_type, pc, disp)
            total += 1

            in_section = section_addr <= target < section_addr + section_size
            if not in_section:
                offset += sizes[i]
                continue  # cross-section, can't convert
            if insn_type == 'mov.l' and (target - section_addr) % 4 != 0:
                offset += sizes[i]
                continue  # assembler would reject

            if target not in addr_to_label and target not in needed_labels:
                needed_labels[target] = f".L_pool_{target:08X}"

            pool_loads.append((i, insn_type, reg, target))

        offset += sizes[i]

    if not pool_loads:
        return 0, total, []

    # Pass 2: rebuild file — insert labels and convert pool loads
    # Build offset->addr map for label insertion points
    convert_set = {}  # line_idx -> (insn_type, reg, label_name)
    for idx, insn_type, reg, target in pool_loads:
        label = addr_to_label.get(target) or needed_labels.get(target)
        if label:
            convert_set[idx] = (insn_type, reg, label)

    # Build insertion points: offset_in_section -> label_name
    insert_at_offset = {}
    for addr, name in needed_labels.items():
        insert_at_offset[addr - section_addr] = name

    # Rebuild lines
    new_lines = []
    offset = 0
    conversions = []
    for i, line in enumerate(lines):
        # Insert label if needed at this offset
        if offset in insert_at_offset:
            new_lines.append(f"{insert_at_offset[offset]}:\n")

        # Convert pool load if applicable
        if i in convert_set:
            insn_type, reg, label = convert_set[i]
            indent = line[:len(line) - len(line.lstrip())]
            new_line = f"{indent}{insn_type}   {label}, r{reg}\n"
            new_lines.append(new_line)
            conversions.append((i, new_line, line.rstrip(), label, 0))
        else:
            new_lines.append(line)

        offset += sizes[i]

    # Check for label at very end
    if offset in insert_at_offset:
        new_lines.append(f"{insert_at_offset[offset]}:\n")

    if apply and conversions:
        with open(filepath, 'w', newline='\n') as f:
            f.writelines(new_lines)

    return len(conversions), total, conversions


def main():
    parser = argparse.ArgumentParser(description="Clear PC-relative .byte fog")
    parser.add_argument('--scan', action='store_true', help="Report convertible pool loads")
    parser.add_argument('--apply', action='store_true', help="Apply conversions")
    parser.add_argument('files', nargs='*', help="Specific files (default: all src/*.s)")
    args = parser.parse_args()

    if not args.files:
        args.files = sorted(SRC_DIR.glob('*.s'))
    else:
        args.files = [Path(f) for f in args.files]

    total_convertible = 0
    total_pool = 0
    files_converted = 0

    for fp in args.files:
        if fp.name == 'FUN_06046E48.s':
            continue  # skip data blob

        conv, total, details = process_file(fp, apply=args.apply)
        total_convertible += conv
        total_pool += total

        if conv > 0:
            files_converted += 1
            if not args.apply:
                print(f"  {fp.name}: {conv}/{total} convertible")
                for idx, new_line, old_line, label, target in details[:3]:
                    print(f"    L{idx+1}: {old_line.strip()}")
                    print(f"        -> {new_line.strip()}")
                if len(details) > 3:
                    print(f"    ... and {len(details)-3} more")
            else:
                print(f"  {fp.name}: converted {conv}/{total}")

    print(f"\n{'='*60}")
    print(f"  Files with conversions: {files_converted}")
    print(f"  Convertible: {total_convertible} / {total_pool} pool loads")
    print(f"  Remaining:   {total_pool - total_convertible}")
    print(f"{'='*60}")


if __name__ == "__main__":
    main()
