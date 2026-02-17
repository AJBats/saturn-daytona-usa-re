#!/usr/bin/env python3
"""
Decode SH-2 branch instructions from .s files and find cross-boundary branches.

Focuses on:
1. Branches from _start into FUN_ territory (or vice versa) -- CRITICAL
2. Branches between different FUN_ sections -- informational (these survive
   uniform padding since all FUN_ sections shift together)

SH-2 branch encoding:
  bra  disp: 0xAnnn  (12-bit signed disp, target = PC + 4 + disp*2)
  bsr  disp: 0xBnnn  (12-bit signed disp, target = PC + 4 + disp*2)
  bf   disp: 0x8Bnn  (8-bit signed disp, target = PC + 4 + disp*2)
  bt   disp: 0x89nn  (8-bit signed disp, target = PC + 4 + disp*2)
  bf.s disp: 0x8Fnn  (8-bit signed disp, target = PC + 4 + disp*2)
  bt.s disp: 0x8Dnn  (8-bit signed disp, target = PC + 4 + disp*2)
"""

import re
import sys
import os
import glob

def sign_extend(value, bits):
    if value & (1 << (bits - 1)):
        value -= (1 << bits)
    return value

def parse_asm_file(filepath):
    instructions = []
    with open(filepath, 'r') as f:
        lines = f.readlines()
    for i, line in enumerate(lines):
        line = line.strip()
        m = re.match(r'\.byte\s+0x([0-9A-Fa-f]{2})\s*,\s*0x([0-9A-Fa-f]{2})', line)
        if m:
            hi = int(m.group(1), 16)
            lo = int(m.group(2), 16)
            instructions.append(('insn', hi, lo, i+1))
            continue
        m = re.match(r'\.4byte\s+(\S+)', line)
        if m:
            instructions.append(('pool', m.group(1), 0, i+1))
    return instructions

def compute_addresses(instructions, base_addr):
    addr = base_addr
    result = []
    for entry in instructions:
        if entry[0] == 'insn':
            result.append((addr, entry))
            addr += 2
        elif entry[0] == 'pool':
            if addr % 4 != 0:
                addr += 2
            result.append((addr, entry))
            addr += 4
    return result, addr

def decode_branches(addressed_insns):
    branches = []
    for addr, entry in addressed_insns:
        if entry[0] != 'insn':
            continue
        hi = entry[1]
        lo = entry[2]
        line_num = entry[3]
        word = (hi << 8) | lo
        opcode_hi4 = (word >> 12) & 0xF
        opcode_hi8 = (word >> 8) & 0xFF
        branch_type = None

        if opcode_hi4 == 0xA:
            disp = sign_extend(word & 0xFFF, 12)
            target = addr + 4 + disp * 2
            branch_type = 'bra'
        elif opcode_hi4 == 0xB:
            disp = sign_extend(word & 0xFFF, 12)
            target = addr + 4 + disp * 2
            branch_type = 'bsr'
        elif opcode_hi8 == 0x89:
            disp = sign_extend(word & 0xFF, 8)
            target = addr + 4 + disp * 2
            branch_type = 'bt'
        elif opcode_hi8 == 0x8B:
            disp = sign_extend(word & 0xFF, 8)
            target = addr + 4 + disp * 2
            branch_type = 'bf'
        elif opcode_hi8 == 0x8D:
            disp = sign_extend(word & 0xFF, 8)
            target = addr + 4 + disp * 2
            branch_type = 'bt.s'
        elif opcode_hi8 == 0x8F:
            disp = sign_extend(word & 0xFF, 8)
            target = addr + 4 + disp * 2
            branch_type = 'bf.s'

        if branch_type:
            branches.append({
                'type': branch_type,
                'addr': addr,
                'target': target,
                'disp': disp,
                'word': word,
                'line': line_num,
            })
    return branches

def main():
    base_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    src_dir = os.path.join(base_dir, 'reimpl', 'src')

    # --- Parse _start.s ---
    start_file = os.path.join(src_dir, '_start.s')
    start_insns = parse_asm_file(start_file)
    start_addressed, start_end = compute_addresses(start_insns, 0x06003000)

    START_BEGIN = 0x06003000
    START_END = start_end  # should be 0x060030FC

    print(f"=== _start section ===")
    print(f"  Range: 0x{START_BEGIN:08X} - 0x{START_END:08X}  ({START_END - START_BEGIN} bytes)")
    print()

    # Decode branches in _start
    start_branches = decode_branches(start_addressed)
    print(f"  Branches in _start ({len(start_branches)} total):")
    for b in start_branches:
        in_start = START_BEGIN <= b['target'] < START_END
        marker = "" if in_start else " *** LEAVES _start ***"
        print(f"    0x{b['addr']:08X}: {b['type']:5s} -> 0x{b['target']:08X}  (disp={b['disp']:+d}){marker}")
    print()

    # --- Discover all FUN_ .s files ---
    fun_pattern = os.path.join(src_dir, 'FUN_*.s')
    fun_files = sorted(glob.glob(fun_pattern))

    print(f"Found {len(fun_files)} FUN_ assembly files")
    print()

    # Build section map: for each FUN_, compute address range
    sections = []  # (name, start, end, file)
    for fpath in fun_files:
        fname = os.path.basename(fpath)
        m = re.match(r'FUN_(0[xX]?[0-9A-Fa-f]+)\.s', fname)
        if not m:
            continue
        addr_str = m.group(1)
        fun_addr = int(addr_str, 16)
        fun_insns = parse_asm_file(fpath)
        fun_addressed, fun_end = compute_addresses(fun_insns, fun_addr)
        sections.append((fname[:-2], fun_addr, fun_end, fpath, fun_addressed))

    sections.sort(key=lambda x: x[1])

    # --- Find all cross-boundary branches ---
    critical_crosses = []  # _start <-> FUN_ boundary
    inter_section_crosses = []  # FUN_ <-> FUN_ (informational)

    # Check _start -> FUN_
    for b in start_branches:
        if not (START_BEGIN <= b['target'] < START_END):
            critical_crosses.append(('_start', b))

    # Check all FUN_ sections
    for name, sec_start, sec_end, fpath, addressed in sections:
        branches = decode_branches(addressed)
        for b in branches:
            target = b['target']
            # Branch into _start range?
            if START_BEGIN <= target < START_END:
                critical_crosses.append((name, b))
            # Branch outside own section?
            elif not (sec_start <= target < sec_end):
                inter_section_crosses.append((name, sec_start, sec_end, b))

    # --- Report ---
    print("=" * 70)
    print("CRITICAL: Branches crossing _start / FUN_ boundary")
    print("  (These BREAK when padding is inserted between .text.startup and .text.FUN_*)")
    print("=" * 70)
    if critical_crosses:
        for section, b in critical_crosses:
            print(f"  [{section}] 0x{b['addr']:08X}: {b['type']:5s} -> 0x{b['target']:08X}  (disp={b['disp']:+d}, word=0x{b['word']:04X}, line {b['line']})")
    else:
        print("  NONE FOUND -- no branches cross the _start/FUN_ boundary.")
    print()

    print("=" * 70)
    print("INFO: Branches crossing between different FUN_ sections")
    print("  (These survive uniform padding since all FUN_ shift together,")
    print("   but would break if sections are reordered or individually padded)")
    print("=" * 70)
    if inter_section_crosses:
        for name, sec_start, sec_end, b in inter_section_crosses:
            # Determine which section the target is in
            target_sec = "unknown"
            for sn, ss, se, _, _ in sections:
                if ss <= b['target'] < se:
                    target_sec = sn
                    break
            if START_BEGIN <= b['target'] < START_END:
                target_sec = "_start"
            print(f"  [{name}] 0x{b['addr']:08X}: {b['type']:5s} -> 0x{b['target']:08X}  (-> {target_sec}, disp={b['disp']:+d})")
    else:
        print("  None found.")
    print()

    print(f"Total FUN_ sections scanned: {len(sections)}")
    print(f"Critical boundary crosses: {len(critical_crosses)}")
    print(f"Inter-section crosses: {len(inter_section_crosses)}")

if __name__ == '__main__':
    main()
