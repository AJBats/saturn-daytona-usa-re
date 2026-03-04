#!/usr/bin/env python3
"""
Add missing .global FUN_XXXXXXXX labels to src/ and retail/ files.

For each target address missing from the symbol map, finds the containing
section, computes byte offset, scans the source file tracking cumulative
bytes, and inserts a .global + label at the right position.

Usage:
    python tools/add_sublabels.py                # dry run
    python tools/add_sublabels.py --apply         # apply changes
"""

import re
import os
import sys
import glob

REIMPL_DIR = os.path.join(os.path.dirname(__file__), '..', 'reimpl')
SRC_DIR = os.path.join(REIMPL_DIR, 'src')
RETAIL_DIR = os.path.join(REIMPL_DIR, 'retail')


def find_sections():
    """Build list of (section_start_addr, src_file, retail_file)."""
    sections = {}
    for d, label in [(SRC_DIR, 'src'), (RETAIL_DIR, 'retail')]:
        for f in sorted(glob.glob(os.path.join(d, '*.s'))):
            with open(f, 'r', encoding='utf-8', errors='replace') as fh:
                for line in fh:
                    m = re.match(r'\s*\.section\s+\.text\.(?:FUN_)?([0-9A-Fa-f]+)', line.strip())
                    if m:
                        addr = int(m.group(1), 16)
                        if addr not in sections:
                            sections[addr] = {}
                        sections[addr][label] = f
    return sections


def find_missing_addresses():
    """Get the 100 missing target addresses from convert_bsr_reloc.py output."""
    # Re-implement the scanner here to avoid subprocess dependency
    from convert_bsr_reloc import build_address_to_symbol_map, BSR_BRA_RE

    addr_map = build_address_to_symbol_map()
    missing = set()

    for d in [SRC_DIR]:
        for f in sorted(glob.glob(os.path.join(d, '*.s'))):
            with open(f, 'r', encoding='utf-8', errors='replace') as fh:
                for line in fh:
                    m = BSR_BRA_RE.match(line)
                    if m:
                        target = int(m.group(5), 16)
                        if target not in addr_map:
                            missing.add(target)
        for subdir in ['mods', os.path.join('mods', 're_tests')]:
            for f in sorted(glob.glob(os.path.join(d, subdir, '*.s'))):
                with open(f, 'r', encoding='utf-8', errors='replace') as fh:
                    for line in fh:
                        m = BSR_BRA_RE.match(line)
                        if m:
                            target = int(m.group(5), 16)
                            if target not in addr_map:
                                missing.add(target)
    return missing


def byte_size_of_line(line):
    """Compute bytes emitted by a source line."""
    stripped = line.strip()

    # Empty, comment-only, label, directive (non-data)
    if not stripped or stripped.startswith('!') or stripped.startswith('/*'):
        return 0

    # Section, global, type, reloc directives
    if stripped.startswith('.section') or stripped.startswith('.global') or \
       stripped.startswith('.type') or stripped.startswith('.reloc') or \
       stripped.startswith('.align'):
        return 0

    # Label line (ends with :)
    if re.match(r'^[\w.]+:\s*$', stripped):
        return 0
    # Label followed by instruction on same line
    if re.match(r'^[\w.]+:\s+', stripped):
        # Remove label prefix, count the instruction part
        rest = re.sub(r'^[\w.]+:\s+', '', stripped)
        return byte_size_of_content(rest)

    return byte_size_of_content(stripped)


def strip_comment(s):
    """Strip /* ... */ and ! comments from a line."""
    s = re.sub(r'/\*.*?\*/', '', s)
    s = re.sub(r'!.*$', '', s)
    return s.strip()


def byte_size_of_content(s):
    """Byte size of instruction/data content."""
    # .4byte
    if s.startswith('.4byte'):
        return 4
    # .2byte
    if s.startswith('.2byte'):
        return 2
    # .byte with multiple values — strip comments first to avoid counting
    # hex values inside comments like /* 0x4000 */
    if s.startswith('.byte'):
        clean = strip_comment(s)
        vals = re.findall(r'0x[0-9A-Fa-f]+', clean)
        return len(vals)
    # Any SH-2 mnemonic — all are 2 bytes
    if re.match(r'[a-z]', s):
        return 2

    return 0


def insert_label_in_file(filepath, section_start, target_addr, apply=False):
    """Insert .global FUN_XXXXXXXX label at the right byte offset."""
    target_offset = target_addr - section_start

    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        lines = f.readlines()

    # Find section start line and track bytes
    in_section = False
    current_offset = 0
    insert_line = None
    split_4byte = False

    for i, line in enumerate(lines):
        stripped = line.strip()

        if not in_section:
            # Find section start
            m = re.match(r'\s*\.section\s+\.text\.(?:FUN_)?([0-9A-Fa-f]+)', stripped)
            if m:
                addr = int(m.group(1), 16)
                if addr == section_start:
                    in_section = True
                    current_offset = 0
            continue

        # Check if we hit the next section
        m = re.match(r'\s*\.section\s+', stripped)
        if m:
            # Check offset before breaking
            if current_offset == target_offset:
                insert_line = i
            break

        # Check if this line's start offset matches target
        if current_offset == target_offset:
            insert_line = i
            break

        nbytes = byte_size_of_line(line)
        if nbytes > 0:
            # Check if target falls within this multi-byte item
            if current_offset < target_offset < current_offset + nbytes:
                split_offset = target_offset - current_offset
                # Can only split .4byte at the 2-byte midpoint
                stripped = line.strip()
                if stripped.startswith('.4byte') and split_offset == 2:
                    # Record split info for later
                    insert_line = i
                    split_4byte = True
                    break
                else:
                    print(f"  WARNING: target 0x{target_addr:08X} at offset {target_offset} "
                          f"falls mid-item at line {i+1} (offset {current_offset}, size {nbytes})")
                    return False
            current_offset += nbytes

    if insert_line is None:
        print(f"  ERROR: could not find offset {target_offset:#x} in {os.path.basename(filepath)} "
              f"(section 0x{section_start:08X}, scanned to offset {current_offset:#x})")
        return False

    # Check if label already exists
    label_name = f"FUN_{target_addr:08X}"
    for line in lines:
        if f'.global {label_name}' in line:
            return True  # Already exists

    indent = '    '

    if split_4byte:
        # Split .4byte into two .2byte entries with label in between
        old_line = lines[insert_line]
        stripped = old_line.strip()
        # Extract the 32-bit value
        m = re.match(r'\.4byte\s+(0x[0-9A-Fa-f]+)', stripped)
        if not m:
            print(f"  ERROR: cannot parse .4byte for split at line {insert_line+1}")
            return False
        val = int(m.group(1), 16)
        hi = (val >> 16) & 0xFFFF
        lo = val & 0xFFFF
        # Get original indent
        orig_indent = re.match(r'(\s*)', old_line).group(1)
        new_label_lines = [
            f"{orig_indent}.2byte 0x{hi:04X}\n",
            f"{indent}.global {label_name}\n",
            f"{label_name}:\n",
            f"{orig_indent}.2byte 0x{lo:04X}\n",
        ]
        new_lines = lines[:insert_line] + new_label_lines + lines[insert_line+1:]
    else:
        new_label_lines = [
            f"{indent}.global {label_name}\n",
            f"{label_name}:\n",
        ]
        new_lines = lines[:insert_line] + new_label_lines + lines[insert_line:]

    if apply:
        with open(filepath, 'w', encoding='utf-8', newline='\n') as f:
            f.writelines(new_lines)

    return True


def main():
    apply = '--apply' in sys.argv

    # Build section map
    sections = find_sections()
    sorted_sections = sorted(sections.keys())

    # Get missing addresses
    sys.path.insert(0, os.path.join(os.path.dirname(__file__)))
    missing = find_missing_addresses()
    print(f"Missing addresses: {len(missing)}")

    # For each missing address, find containing section
    success = 0
    errors = 0
    for addr in sorted(missing):
        # Binary search for containing section
        best_section = None
        for s in sorted_sections:
            if s <= addr:
                best_section = s
            else:
                break

        if best_section is None:
            print(f"  ERROR: no section for 0x{addr:08X}")
            errors += 1
            continue

        offset = addr - best_section

        # Process both src and retail files
        for which in ['src', 'retail']:
            if which not in sections[best_section]:
                continue
            filepath = sections[best_section][which]
            result = insert_label_in_file(filepath, best_section, addr, apply=apply)
            if result:
                if which == 'src':
                    print(f"  {'Added' if apply else 'Would add'} FUN_{addr:08X} "
                          f"in {os.path.basename(filepath)} (offset {offset:#x})")
                success += 1
            else:
                errors += 1

    print(f"\n{'Applied' if apply else 'Would add'}: {success} labels")
    if errors:
        print(f"Errors: {errors}")
    if not apply and success > 0:
        print("Run with --apply to make changes.")


if __name__ == '__main__':
    main()
