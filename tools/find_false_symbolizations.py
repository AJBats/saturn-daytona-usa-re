#!/usr/bin/env python3
"""find_false_symbolizations.py -- Find .4byte entries that are actually instruction bytes.

The brute-force pass in symbolize_pools.py may incorrectly symbolize
4-byte-aligned instruction pairs that coincidentally look like code-range
addresses. These false positives work at original addresses but BREAK in
free-layout builds (symbol resolves to shifted value, corrupting instructions).

This tool replicates the discover_jump_tables algorithm's seeding and adjacency
logic, then identifies positions that ONLY the brute-force pass would find.
"""

import os
import re
import struct
import sys

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BINARY_PATH = os.path.join(PROJ, "build", "aprog.bin")
SYMS_PATH = os.path.join(PROJ, "build", "aprog_syms.txt")
STUBS_PATH = os.path.join(PROJ, "reimpl", "src_c_archive", "linker_stubs.c")
DISASM_PATH = os.path.join(PROJ, "build", "aprog.s")

BASE_ADDR = 0x06003000


def load_binary():
    with open(BINARY_PATH, "rb") as f:
        return f.read()


def load_fun_symbols():
    syms = {}
    with open(SYMS_PATH) as f:
        for line in f:
            m = re.match(r"(FUN_[0-9A-Fa-f]+)\s*=\s*0x([0-9A-Fa-f]+)", line)
            if m:
                syms[int(m.group(2), 16)] = m.group(1)
    return syms


def load_dat_symbols():
    syms = {}
    with open(STUBS_PATH) as f:
        for line in f:
            m = re.match(r"int\s+(DAT_[0-9A-Fa-f]+)", line)
            if m:
                name = m.group(1)
                addr = int(name[4:], 16)
                syms[addr] = name
    return syms


def extract_ref_values():
    """Extract referenced values from disassembly comments."""
    ref_values = set()
    pat_pool = re.compile(r"\{\[0x([0-9A-Fa-f]+)\]\s*=\s*0x([0-9A-Fa-f]+)\}")
    pat_ref = re.compile(r"->\s*(FUN_[0-9A-Fa-f]+)")
    with open(DISASM_PATH) as f:
        for line in f:
            for m in pat_pool.finditer(line):
                ref_values.add(int(m.group(2), 16))
            for m in pat_ref.finditer(line):
                ref_values.add(int(m.group(1)[4:], 16))
    return ref_values


def find_movl_pool_targets(binary_data, func_start, func_end):
    """Find all positions referenced by mov.l @(disp,PC),Rn instructions."""
    targets = set()
    off_start = func_start - BASE_ADDR
    off_end = func_end - BASE_ADDR
    for i in range(off_start, off_end - 1, 2):
        word = (binary_data[i] << 8) | binary_data[i + 1]
        if (word >> 12) == 0xD:
            disp = word & 0xFF
            pc = BASE_ADDR + i
            target = (pc & ~3) + 4 + disp * 4
            target_off = target - BASE_ADDR
            if off_start <= target_off < off_end:
                targets.add(target_off)
    return targets


def find_mova_targets(binary_data, func_start, func_end):
    """Find all positions referenced by mova @(disp,PC),R0 instructions."""
    targets = set()
    off_start = func_start - BASE_ADDR
    off_end = func_end - BASE_ADDR
    for i in range(off_start, off_end - 1, 2):
        word = (binary_data[i] << 8) | binary_data[i + 1]
        if (word >> 8) == 0xC7:
            disp = word & 0xFF
            pc = BASE_ADDR + i
            target = (pc & ~3) + 4 + disp * 4
            target_off = target - BASE_ADDR
            if off_start <= target_off < off_end:
                targets.add(target_off)
    return targets


def main():
    print("Loading binary and symbols...")
    binary_data = load_binary()
    code_end = BASE_ADDR + len(binary_data)

    fun_syms = load_fun_symbols()
    dat_syms = load_dat_symbols()
    ref_values = extract_ref_values()

    # Build all_symbols (matching symbolize_pools.py logic)
    all_symbols = {}
    for value in ref_values:
        if 0x06000000 <= value <= 0x060FFFFF:
            all_symbols[value] = f"sym_{value:08X}"
    all_symbols.update(dat_syms)
    all_symbols.update(fun_syms)

    # Build function ranges
    addrs = sorted(fun_syms.keys())
    ranges = [(BASE_ADDR, addrs[0], "_start")]
    for i in range(len(addrs)):
        start = addrs[i]
        end = addrs[i + 1] if i + 1 < len(addrs) else code_end
        ranges.append((start, end, fun_syms[start]))

    print(f"Analyzing {len(ranges)} functions, {len(all_symbols)} symbols...")

    # Replicate discover_jump_tables Step 1: positions with known symbol values
    pool_positions = set()
    for start, end, _ in ranges:
        off_start = start - BASE_ADDR
        off_end = end - BASE_ADDR
        aligned_start = (off_start + 3) & ~3
        for i in range(aligned_start, off_end - 3, 4):
            val = struct.unpack(">I", binary_data[i:i + 4])[0]
            if val in all_symbols:
                pool_positions.add(i)

    # Step 1b: seed from code-range sym_ labels
    for addr, name in all_symbols.items():
        if not name.startswith("sym_"):
            continue
        if addr < BASE_ADDR or addr >= code_end:
            continue
        off = addr - BASE_ADDR
        if 0 <= off < len(binary_data) - 3:
            pool_positions.add(off)

    # Also seed from mov.l and mova targets (instruction-level confirmation)
    instr_confirmed = set()
    for start, end, _ in ranges:
        movl = find_movl_pool_targets(binary_data, start, end)
        mova = find_mova_targets(binary_data, start, end)
        instr_confirmed |= movl
        instr_confirmed |= mova
    pool_positions |= instr_confirmed

    step1_count = len(pool_positions)
    print(f"Step 1 (known symbols + sym_ seeds + instr refs): {step1_count}")

    # Step 2: adjacency expansion (WINDOW=12, matching symbolize_pools.py)
    WINDOW = 12
    changed = True
    iterations = 0
    step2_added = 0
    while changed:
        changed = False
        iterations += 1
        for start, end, _ in ranges:
            off_start = start - BASE_ADDR
            off_end = end - BASE_ADDR
            aligned_start = (off_start + 3) & ~3
            for i in range(aligned_start, off_end - 3, 4):
                if i in pool_positions:
                    continue
                val = struct.unpack(">I", binary_data[i:i + 4])[0]
                if not (BASE_ADDR <= val < code_end):
                    continue
                if val % 2 != 0:
                    continue
                found = False
                for check in range(i - WINDOW, i + WINDOW + 1, 4):
                    if check != i and check in pool_positions:
                        found = True
                        break
                if found:
                    pool_positions.add(i)
                    step2_added += 1
                    changed = True
        if iterations > 20:
            break

    print(f"Step 2 (adjacency, {iterations} iters): +{step2_added} = {len(pool_positions)}")

    # Step 3 (brute-force): find ALL remaining even code-range values
    # These are what the brute-force pass would add — potential false positives
    brute_force_entries = []
    for start, end, func_name in ranges:
        off_start = start - BASE_ADDR
        off_end = end - BASE_ADDR
        aligned_start = (off_start + 3) & ~3
        for i in range(aligned_start, off_end - 3, 4):
            if i in pool_positions:
                continue
            addr = BASE_ADDR + i
            if addr % 4 != 0:
                continue
            val = struct.unpack(">I", binary_data[i:i + 4])[0]
            if not (BASE_ADDR <= val < code_end):
                continue
            if val % 2 != 0:
                continue
            w1 = (binary_data[i] << 8) | binary_data[i + 1]
            w2 = (binary_data[i + 2] << 8) | binary_data[i + 3]
            is_fun = val in fun_syms
            brute_force_entries.append({
                'func': func_name,
                'addr': addr,
                'offset': i,
                'value': val,
                'word1': w1,
                'word2': w2,
                'is_fun': is_fun,
            })

    print(f"\nStep 3 (brute-force candidates): {len(brute_force_entries)}")

    # Classify: entries matching known FUN_ are more suspicious (could be real data)
    fun_matches = [e for e in brute_force_entries if e['is_fun']]
    non_fun = [e for e in brute_force_entries if not e['is_fun']]

    print(f"  Matching FUN_ entries: {fun_matches and len(fun_matches) or 0}")
    print(f"  Non-FUN (loc_ only): {len(non_fun)}")

    # Check for clusters (positions with nearby brute-force entries)
    brute_offsets = set(e['offset'] for e in brute_force_entries)
    isolated = []
    clustered = []
    for e in brute_force_entries:
        neighbors = 0
        for delta in [-4, 4, -8, 8]:
            if (e['offset'] + delta) in brute_offsets or (e['offset'] + delta) in pool_positions:
                neighbors += 1
        if neighbors >= 1:
            clustered.append(e)
        else:
            isolated.append(e)

    print(f"\n  Clustered (near other brute-force or pool entries): {len(clustered)}")
    print(f"  Isolated (no nearby entries at all): {len(isolated)}")

    # Print isolated entries (most likely false positives)
    print(f"\n=== ISOLATED entries (most likely FALSE POSITIVES) ===")
    for e in isolated[:50]:
        flag = " [FUN!]" if e['is_fun'] else ""
        sym = all_symbols.get(e['value'], f"loc_{e['value']:08X}")
        print(f"  {e['func']} @ 0x{e['addr']:08X}: 0x{e['value']:08X} -> {sym}"
              f"  (insns: 0x{e['word1']:04X} 0x{e['word2']:04X}){flag}")

    # Print clustered entries (might be real data tables)
    print(f"\n=== CLUSTERED entries (might be real data tables) ===")
    shown = 0
    for e in clustered[:50]:
        flag = " [FUN!]" if e['is_fun'] else ""
        sym = all_symbols.get(e['value'], f"loc_{e['value']:08X}")
        print(f"  {e['func']} @ 0x{e['addr']:08X}: 0x{e['value']:08X} -> {sym}"
              f"  (insns: 0x{e['word1']:04X} 0x{e['word2']:04X}){flag}")
        shown += 1

    # Summary
    print(f"\n=== SUMMARY ===")
    print(f"Total pool positions (Steps 1+2): {len(pool_positions)}")
    print(f"Brute-force candidates (Step 3): {len(brute_force_entries)}")
    print(f"  - Isolated: {len(isolated)} (LIKELY FALSE POSITIVES)")
    print(f"  - Clustered: {len(clustered)} (MIGHT BE REAL)")
    print(f"  - Matching FUN_: {len(fun_matches)}")

    # Check: does the actual .s file have .4byte at these positions?
    print(f"\n=== Verifying .s files ===")
    verified_count = 0
    for e in brute_force_entries[:10]:
        s_file = os.path.join(PROJ, "reimpl", "src", f"{e['func']}.s")
        if os.path.exists(s_file):
            with open(s_file) as f:
                content = f.read()
            sym = all_symbols.get(e['value'], f"loc_{e['value']:08X}")
            if f".4byte {sym}" in content or f".4byte loc_{e['value']:08X}" in content:
                verified_count += 1
                print(f"  VERIFIED: {e['func']}.s has .4byte for 0x{e['value']:08X}")
            else:
                print(f"  NOT FOUND: {e['func']}.s does NOT have .4byte for 0x{e['value']:08X}")
    print(f"  Verified in first 10: {verified_count}/10")


if __name__ == "__main__":
    main()
