#!/usr/bin/env python3
"""
Analyze all hardcoded BSR/BRA .byte pairs in reimpl/src/.
Determines cross-section vs intra-section references and identifies
those crossing the race_position_track boundary at 0x06011094.

Uses comment-reported target addresses as ground truth (more reliable than
computing PC offsets from line-by-line byte counting).
"""

import re
import os
import glob
import sys

SRC_DIR = os.path.join(os.path.dirname(__file__), '..', 'reimpl', 'src')
MODS_DIR = os.path.join(SRC_DIR, 'mods')

# race_position_track boundary
RPT_START = 0x06010F04
RPT_SIZE = 0x190
RPT_END = RPT_START + RPT_SIZE  # 0x06011094


def parse_section_address(filepath):
    """Extract the section base address from .section .text.FUN_XXXXXXXX"""
    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        for line in f:
            m = re.match(r'\s*\.section\s+\.text\.FUN_([0-9A-Fa-f]+)', line)
            if m:
                return int(m.group(1), 16)
    return None


def get_section_end(filepath, base_addr):
    """Get the end of a section by finding the highest-addressed label."""
    highest = base_addr
    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        for line in f:
            # Match labels that contain hex addresses
            for m in re.finditer(r'(?:\.L_|FUN_|sym_|DAT_)([0-9A-Fa-f]{8})', line):
                addr = int(m.group(1), 16)
                if 0x06000000 <= addr < 0x06100000 and addr > highest:
                    highest = addr
    return highest + 4  # rough end estimate


def compute_source_addr(filepath, base_addr, target_line_num):
    """
    Compute the PC address for a specific line by walking the file and
    counting emitted bytes. Uses label addresses for calibration.
    """
    current_offset = 0
    last_calibrated = base_addr

    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        for line_num, line in enumerate(f, 1):
            stripped = line.strip()

            if not stripped:
                continue

            # Calibrate from label addresses
            label_m = re.match(r'(\S+):', stripped)
            if label_m:
                label = label_m.group(1)
                # Extract address from label
                for m in re.finditer(r'(?:\.?L_|FUN_|sym_|DAT_)([0-9A-Fa-f]{8})', label):
                    addr = int(m.group(1), 16)
                    if 0x06000000 <= addr < 0x06100000:
                        current_offset = addr - base_addr
                        last_calibrated = addr
                        break
                continue

            # Skip non-emitting directives
            if stripped.startswith(('.section', '.global', '.type', '/*', '//')):
                continue

            if line_num == target_line_num:
                return base_addr + current_offset

            # Count emitted bytes
            if stripped.startswith('.byte'):
                vals = [v.strip() for v in stripped.split(',') if v.strip()]
                # First val includes '.byte' prefix
                byte_count = len(vals)
                current_offset += byte_count
            elif stripped.startswith('.2byte') or stripped.startswith('.word'):
                current_offset += 2
            elif stripped.startswith('.4byte') or stripped.startswith('.long'):
                current_offset += 4
            elif stripped.startswith('.align'):
                m_align = re.match(r'\.align\s+(\d+)', stripped)
                if m_align:
                    alignment = 1 << int(m_align.group(1))
                    addr = base_addr + current_offset
                    rem = addr % alignment
                    if rem != 0:
                        current_offset += alignment - rem
            else:
                # Regular SH-2 instruction = 2 bytes
                current_offset += 2

    return None


def find_bsr_bra(filepath, base_addr):
    """
    Find all .byte pairs encoding BSR (0xBn) or BRA (0xAn) in the file.
    Uses comment-reported target address as ground truth.
    Returns list of (line_num, instr_type, source_addr, target_addr, comment)
    """
    results = []

    # Pattern: .byte 0xAn, 0xHH or .byte 0xBn, 0xHH with comment containing target
    bsr_bra_pattern = re.compile(
        r'\.byte\s+0x([AaBb][0-9A-Fa-f]),\s*0x([0-9A-Fa-f]{2})'
    )
    # Extract target address from comment
    target_pattern = re.compile(r'/\*\s*(?:bsr|bra)\s+(?:0x)?([0-9A-Fa-f]{8})')

    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        for line_num, line in enumerate(f, 1):
            m = bsr_bra_pattern.search(line)
            if m:
                high_byte = int(m.group(1), 16)
                low_byte = int(m.group(2), 16)

                opcode_nibble = (high_byte >> 4) & 0xF
                if opcode_nibble == 0xA:
                    instr_type = 'BRA'
                elif opcode_nibble == 0xB:
                    instr_type = 'BSR'
                else:
                    continue

                # Extract displacement for source addr computation
                disp12 = ((high_byte & 0x0F) << 8) | low_byte
                if disp12 & 0x800:
                    disp12 -= 0x1000

                # Try to get target from comment (ground truth)
                target_addr = None
                target_m = target_pattern.search(line)
                if target_m:
                    target_addr = int(target_m.group(1), 16)

                # If we have target from comment (ground truth), back-compute source
                # from displacement. This is more accurate than line-counting.
                if target_addr is not None:
                    # SH-2: target = source + 4 + disp*2
                    # Therefore: source = target - 4 - disp*2
                    source_addr = target_addr - 4 - disp12 * 2
                else:
                    # No comment target -- compute source from line counting,
                    # then derive target from displacement
                    source_addr = compute_source_addr(filepath, base_addr, line_num)
                    if source_addr is not None:
                        target_addr = source_addr + 4 + disp12 * 2

                if source_addr is None or target_addr is None:
                    continue

                comment = ''
                if '/*' in line:
                    comment = line[line.index('/*'):].strip()

                results.append((line_num, instr_type, source_addr, target_addr, comment))

    return results


def main():
    # Build map of all sections and their address ranges
    all_files = sorted(glob.glob(os.path.join(SRC_DIR, '*.s')))
    # Exclude mods directory
    mods_prefix = os.path.normpath(MODS_DIR)
    all_files = [f for f in all_files if not f.startswith(mods_prefix)]

    print(f"Scanning {len(all_files)} source files...")

    # Parse all sections
    sections = []  # (base_addr, end_addr, filepath, filename)
    for filepath in all_files:
        base = parse_section_address(filepath)
        if base is None:
            continue
        end = get_section_end(filepath, base)
        sections.append((base, end, filepath, os.path.basename(filepath)))

    sections.sort(key=lambda x: x[0])

    # Compute real section ends (start of next section)
    section_bounds = {}  # base_addr -> (start, end, filepath, filename)
    for i, (base, est_end, fpath, fname) in enumerate(sections):
        if i + 1 < len(sections):
            real_end = sections[i + 1][0]
        else:
            real_end = est_end
        section_bounds[base] = (base, real_end, fpath, fname)

    sorted_bases = sorted(section_bounds.keys())

    def find_section(addr):
        """Find which section an address belongs to."""
        # Binary search
        lo, hi = 0, len(sorted_bases) - 1
        result = None
        while lo <= hi:
            mid = (lo + hi) // 2
            if sorted_bases[mid] <= addr:
                result = sorted_bases[mid]
                lo = mid + 1
            else:
                hi = mid - 1
        if result is not None:
            s_start, s_end, _, _ = section_bounds[result]
            if s_start <= addr < s_end:
                return result
        return None

    # Find all BSR/BRA
    all_branches = []
    for filepath in all_files:
        base = parse_section_address(filepath)
        if base is None:
            continue
        branches = find_bsr_bra(filepath, base)
        for line_num, instr_type, src_addr, tgt_addr, comment in branches:
            src_section = find_section(src_addr)
            tgt_section = find_section(tgt_addr)

            is_cross = (src_section != tgt_section)

            # Does it cross the RPT boundary?
            crosses_rpt = False
            if src_addr < RPT_END and tgt_addr >= RPT_END:
                crosses_rpt = True
            elif src_addr >= RPT_END and tgt_addr < RPT_END:
                crosses_rpt = True

            fname = os.path.basename(filepath)
            all_branches.append({
                'file': fname,
                'filepath': filepath,
                'line': line_num,
                'type': instr_type,
                'src_addr': src_addr,
                'tgt_addr': tgt_addr,
                'src_section': src_section,
                'tgt_section': tgt_section,
                'is_cross': is_cross,
                'crosses_rpt': crosses_rpt,
                'comment': comment,
            })

    all_branches.sort(key=lambda x: x['src_addr'])

    total = len(all_branches)
    cross_section = [b for b in all_branches if b['is_cross']]
    intra_section = [b for b in all_branches if not b['is_cross']]
    rpt_crossers = [b for b in all_branches if b['crosses_rpt']]

    # === HEADER ===
    print(f"\n{'='*100}")
    print(f"BSR/BRA ANALYSIS REPORT")
    print(f"{'='*100}")
    print(f"\nTotal BSR/BRA .byte pairs found: {total}")
    print(f"  Cross-section (PROBLEMATIC): {len(cross_section)}")
    print(f"  Intra-section (safe):        {len(intra_section)}")
    print(f"\nCross race_position_track boundary (0x{RPT_END:08X}): {len(rpt_crossers)}")

    # === CROSS-SECTION LISTING ===
    print(f"\n{'='*100}")
    print(f"ALL CROSS-SECTION BSR/BRA ({len(cross_section)} total)")
    print(f"{'='*100}")
    print(f"{'File':<45} {'Line':>5} {'Type':>4} {'Source':>12} {'Target':>12} {'RPT?':>5} Comment")
    print(f"{'-'*45} {'-'*5} {'-'*4} {'-'*12} {'-'*12} {'-'*5} {'-'*40}")

    for b in cross_section:
        rpt_flag = ' YES' if b['crosses_rpt'] else ''
        print(f"{b['file']:<45} {b['line']:>5} {b['type']:>4} 0x{b['src_addr']:08X} 0x{b['tgt_addr']:08X} {rpt_flag:>5} {b['comment'][:60]}")

    # === INTRA-SECTION LISTING ===
    if intra_section:
        print(f"\n{'='*100}")
        print(f"ALL INTRA-SECTION BSR/BRA ({len(intra_section)} total)")
        print(f"{'='*100}")
        print(f"{'File':<45} {'Line':>5} {'Type':>4} {'Source':>12} {'Target':>12} Comment")
        print(f"{'-'*45} {'-'*5} {'-'*4} {'-'*12} {'-'*12} {'-'*40}")

        for b in intra_section:
            print(f"{b['file']:<45} {b['line']:>5} {b['type']:>4} 0x{b['src_addr']:08X} 0x{b['tgt_addr']:08X} {b['comment'][:60]}")

    # === RPT BOUNDARY CROSSERS ===
    print(f"\n{'='*100}")
    print(f"BSR/BRA CROSSING RACE_POSITION_TRACK BOUNDARY (0x{RPT_END:08X})")
    print(f"{'='*100}")
    if rpt_crossers:
        for b in rpt_crossers:
            direction = "FORWARD (before->after)" if b['src_addr'] < RPT_END else "BACKWARD (after->before)"
            src_sec_name = section_bounds[b['src_section']][3] if b['src_section'] else '???'
            tgt_sec_name = section_bounds[b['tgt_section']][3] if b['tgt_section'] else '???'
            print(f"  {b['file']}:{b['line']}  {b['type']}  src=0x{b['src_addr']:08X} ({src_sec_name})  tgt=0x{b['tgt_addr']:08X} ({tgt_sec_name})  {direction}")
            print(f"    {b['comment']}")
    else:
        print(f"  None found.")

    # === NEARBY REGION DETAIL ===
    # Show all cross-section BSR/BRA in the vicinity of race_position_track
    print(f"\n{'='*100}")
    print(f"CROSS-SECTION BSR/BRA NEAR RACE_POSITION_TRACK (0x{RPT_START:08X}-0x{RPT_END:08X})")
    print(f"Showing all with source or target within 0x06010000-0x06012000")
    print(f"{'='*100}")
    nearby = [b for b in cross_section
              if (0x06010000 <= b['src_addr'] < 0x06012000) or
                 (0x06010000 <= b['tgt_addr'] < 0x06012000)]
    for b in nearby:
        rpt_flag = ' *** RPT CROSS ***' if b['crosses_rpt'] else ''
        src_sec = section_bounds[b['src_section']][3] if b['src_section'] else '???'
        tgt_sec = section_bounds[b['tgt_section']][3] if b['tgt_section'] else '???'
        print(f"  {b['file']}:{b['line']}  {b['type']}  0x{b['src_addr']:08X} ({src_sec}) -> 0x{b['tgt_addr']:08X} ({tgt_sec}){rpt_flag}")

    # === TOP FILES BY CROSS-SECTION COUNT ===
    print(f"\n{'='*100}")
    print(f"TOP 20 FILES BY CROSS-SECTION BSR/BRA COUNT")
    print(f"{'='*100}")
    file_counts = {}
    for b in cross_section:
        file_counts[b['file']] = file_counts.get(b['file'], 0) + 1
    for fname, count in sorted(file_counts.items(), key=lambda x: -x[1])[:20]:
        print(f"  {count:>3}  {fname}")

    # === REGIONAL SUMMARY ===
    print(f"\n{'='*100}")
    print(f"CROSS-SECTION BSR/BRA BY 4KB REGION")
    print(f"{'='*100}")
    regions = {}
    for b in cross_section:
        region = b['src_addr'] & 0xFFFFF000
        regions.setdefault(region, []).append(b)
    for region in sorted(regions.keys()):
        branches = regions[region]
        print(f"  0x{region:08X}: {len(branches):>3} branches")

    # === UNIQUE TARGET FUNCTIONS ===
    print(f"\n{'='*100}")
    print(f"UNIQUE TARGET SECTIONS (functions targeted by cross-section BSR/BRA)")
    print(f"{'='*100}")
    target_sections = {}
    for b in cross_section:
        tgt_sec = b['tgt_section']
        if tgt_sec:
            fname = section_bounds[tgt_sec][3]
            target_sections.setdefault(fname, set()).add(b['file'])
    for tgt_fname, src_files in sorted(target_sections.items(), key=lambda x: -len(x[1])):
        print(f"  {tgt_fname:<45} called from {len(src_files)} files")


if __name__ == '__main__':
    main()
