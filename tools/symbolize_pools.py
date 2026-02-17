#!/usr/bin/env python3
"""
symbolize_pools.py — Sawyer L2: Convert binary to relocatable assembly source.

Reads the original APROG.BIN binary and symbol tables, outputs per-function .s
files with symbolic pool entries (.4byte SYMBOL) for addresses matching known
symbols. All other bytes stay as .byte directives, guaranteeing byte-identical
output when linked at original addresses.

Symbol sources (in priority order):
  1. build/aprog_syms.txt        — FUN_ symbols (1258 functions)
  2. reimpl/src_c_archive/linker_stubs.c — DAT_ symbols (~1341 data addresses)
  3. build/aprog.s comments       — {[pool_addr] = value} annotations (thousands more)

Outputs:
  - reimpl/src/*.s       — one .s file per function (1234 + _start)
  - reimpl/sawyer.ld     — linker script with PROVIDE declarations + ordering

Usage: python3 tools/symbolize_pools.py
"""

import os
import re
import struct
import sys

# --- Configuration ---
BASE_ADDR = 0x06003000

# Address ranges considered relocatable (high work RAM)
# Values outside these ranges are treated as literals (MMIO, constants, etc.)
RELOC_RANGES = [
    (0x06000000, 0x060FFFFF),  # High work RAM (code + data)
]

# Paths relative to project root
PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BINARY_PATH = os.path.join(PROJ, "build", "aprog.bin")
SYMS_PATH = os.path.join(PROJ, "build", "aprog_syms.txt")
STUBS_PATH = os.path.join(PROJ, "reimpl", "src_c_archive", "linker_stubs.c")
DISASM_PATH = os.path.join(PROJ, "build", "aprog.s")
OUT_DIR = os.path.join(PROJ, "reimpl", "src")
LD_OUT = os.path.join(PROJ, "reimpl", "sawyer.ld")


def is_relocatable(addr):
    """Check if an address is in a relocatable memory range."""
    for lo, hi in RELOC_RANGES:
        if lo <= addr <= hi:
            return True
    return False


def load_binary(path):
    with open(path, "rb") as f:
        return f.read()


def load_fun_symbols(path):
    """Parse FUN_ symbols from aprog_syms.txt -> {addr: name}"""
    syms = {}
    with open(path) as f:
        for line in f:
            m = re.match(r"(FUN_[0-9A-Fa-f]+)\s*=\s*0x([0-9A-Fa-f]+)", line)
            if m:
                name = m.group(1)
                addr = int(m.group(2), 16)
                syms[addr] = name
    return syms


def load_dat_symbols(path):
    """Parse DAT_ symbols from linker_stubs.c -> {addr: name}"""
    syms = {}
    with open(path) as f:
        for line in f:
            m = re.match(r"int\s+(DAT_[0-9A-Fa-f]+)", line)
            if m:
                name = m.group(1)
                addr = int(name[4:], 16)
                syms[addr] = name
    return syms


def extract_pool_refs(path):
    """Extract referenced addresses from disassembly comments.

    Parses two patterns:
      {[0xPOOL_ADDR] = 0xVALUE}  — mov.l pool load annotations
      -> FUN_XXXXXXXX             — pool entry target annotations

    Returns:
      pool_addrs: set of addresses that are confirmed pool locations
      ref_values: set of values stored in pools (potential symbols)
    """
    pool_addrs = set()
    ref_values = set()

    # Pattern: {[0x06003060] = 0x060030FC}
    pat_pool = re.compile(r"\{\[0x([0-9A-Fa-f]+)\]\s*=\s*0x([0-9A-Fa-f]+)\}")
    # Pattern: -> FUN_060030FC  (on pool .word lines)
    pat_ref = re.compile(r"->\s*(FUN_[0-9A-Fa-f]+)")

    with open(path) as f:
        for line in f:
            for m in pat_pool.finditer(line):
                pool_addr = int(m.group(1), 16)
                value = int(m.group(2), 16)
                pool_addrs.add(pool_addr)
                ref_values.add(value)

            for m in pat_ref.finditer(line):
                name = m.group(1)
                addr = int(name[4:], 16)
                ref_values.add(addr)

    return pool_addrs, ref_values


def build_function_ranges(fun_syms, binary_len):
    """Build sorted list of (start_addr, end_addr, name) for all functions."""
    addrs = sorted(fun_syms.keys())
    ranges = []

    # _start: from BASE_ADDR to first FUN_
    ranges.append((BASE_ADDR, addrs[0], "_start"))

    # Each FUN_: from its address to the next FUN_ (or end of binary)
    for i in range(len(addrs)):
        start = addrs[i]
        end = addrs[i + 1] if i + 1 < len(addrs) else BASE_ADDR + binary_len
        ranges.append((start, end, fun_syms[start]))

    return ranges


# Code section boundary — sym_ addresses in this range must become labels in .s files
# (they move with the code). Addresses outside stay as fixed PROVIDEs.
CODE_START = 0x06003000
# CODE_END is set dynamically in main() after loading the binary.
# It must cover the ENTIRE binary (BASE_ADDR + binary_size), not just
# an estimated boundary. The tail of FUN_06046E48 extends to ~0x06063690,
# well past 0x06060000 — any sym_ label in that range must be a .global
# in the .s file so it relocates with the code in free-layout builds.
CODE_END = None  # Set in main()


def discover_jump_tables(binary_data, all_symbols, fun_ranges):
    """Discover unsymbolized jump table entries by adjacency to known pool entries.

    SH-2 functions end with constant pools (and sometimes have pool islands
    mid-function). Jump table entries are 4-byte code addresses stored
    contiguously with regular pool entries. We find them by:
      1. Identifying all 4-byte-aligned positions with values already in all_symbols
      2. Expanding outward from those positions to find adjacent code-range values
      3. Creating loc_XXXXXXXX symbols for each discovered target

    Returns: dict {target_addr: symbol_name} for newly discovered symbols.
    """
    # Step 1: Find all positions in the binary that contain known symbol values
    # These are confirmed data/pool positions
    pool_positions = set()
    for start, end, _ in fun_ranges:
        off_start = start - BASE_ADDR
        off_end = end - BASE_ADDR
        # Align to next 4-byte boundary (functions may start at 2-byte aligned)
        aligned_start = (off_start + 3) & ~3
        for i in range(aligned_start, off_end - 3, 4):
            val = struct.unpack(">I", binary_data[i:i + 4])[0]
            if val in all_symbols:
                pool_positions.add(i)

    # Step 1b: Seed from code-range sym_ labels that are data table pointers.
    # These addresses appear in ref_values (loaded via mov.l from constant pools),
    # meaning they point to data tables. Mark positions near them as data.
    for addr, name in all_symbols.items():
        if not name.startswith("sym_"):
            continue
        if addr < CODE_START or addr >= CODE_END:
            continue
        off = addr - BASE_ADDR
        if 0 <= off < len(binary_data) - 3:
            pool_positions.add(off)

    # Step 2: Iteratively expand from known pool positions
    # Check adjacent 4-byte-aligned positions for code-range values
    new_symbols = {}
    WINDOW = 12  # check within 3 slots (bridges multi-field struct patterns)
    changed = True
    iterations = 0
    while changed:
        changed = False
        iterations += 1
        for start, end, _ in fun_ranges:
            off_start = start - BASE_ADDR
            off_end = end - BASE_ADDR
            aligned_start = (off_start + 3) & ~3
            for i in range(aligned_start, off_end - 3, 4):
                if i in pool_positions:
                    continue
                val = struct.unpack(">I", binary_data[i:i + 4])[0]
                if not (CODE_START <= val < CODE_END):
                    continue
                if val % 2 != 0:
                    continue
                # Check if any position within WINDOW bytes is a known pool position
                found = False
                for check in range(i - WINDOW, i + WINDOW + 1, 4):
                    if check != i and check in pool_positions:
                        found = True
                        break
                if found:
                    sym_name = f"loc_{val:08X}"
                    if val not in all_symbols:
                        new_symbols[val] = sym_name
                    pool_positions.add(i)
                    changed = True
        if iterations > 20:
            break  # safety limit

    # Step 3: Brute-force pass — symbolize any remaining even code-range values
    # at 4-byte-aligned positions. Don't skip pool_positions — Step 1b seeds
    # sym_ label positions but the VALUES there may still need new symbols.
    brute_count = 0
    for start, end, _ in fun_ranges:
        off_start = start - BASE_ADDR
        off_end = end - BASE_ADDR
        aligned_start = (off_start + 3) & ~3
        for i in range(aligned_start, off_end - 3, 4):
            val = struct.unpack(">I", binary_data[i:i + 4])[0]
            if not (CODE_START <= val < CODE_END):
                continue
            if val % 2 != 0:
                continue
            if val in all_symbols or val in new_symbols:
                continue  # value already has a symbol
            sym_name = f"loc_{val:08X}"
            new_symbols[val] = sym_name
            brute_count += 1
            pool_positions.add(i)

    if brute_count:
        print(f"    (brute-force pass added {brute_count} more)")

    # Step 4: Odd code-range values — byte-level data pointers.
    # These point to individual bytes within embedded data tables.
    # Filter out bitmask patterns (0xXXXXFFFF, low16 < 0x10, repeated bytes).
    odd_count = 0
    for start, end, _ in fun_ranges:
        off_start = start - BASE_ADDR
        off_end = end - BASE_ADDR
        aligned_start = (off_start + 3) & ~3
        for i in range(aligned_start, off_end - 3, 4):
            val = struct.unpack(">I", binary_data[i:i + 4])[0]
            if not (CODE_START <= val < CODE_END):
                continue
            if val % 2 == 0:
                continue  # already handled in Step 3
            if val in all_symbols or val in new_symbols:
                continue
            # Filter out likely bitmask/constant patterns
            low16 = val & 0xFFFF
            if low16 == 0xFFFF:
                continue  # bitmask pattern: 0x06XXXXFFFF
            if low16 < 0x0100:
                continue  # small low16 = likely config constant (e.g. 0x06010001)
            # Check adjacency — only symbolize if near a known pool position
            near_pool = False
            for check in range(i - 12, i + 16, 4):
                if check != i and check in pool_positions:
                    near_pool = True
                    break
            if not near_pool:
                continue
            sym_name = f"dat_{val:08X}"
            new_symbols[val] = sym_name
            odd_count += 1
            pool_positions.add(i)

    if odd_count:
        print(f"    (odd data pointers: {odd_count})")

    return new_symbols


def find_code_labels(all_symbols, fun_ranges):
    """Find sym_/loc_/DAT_ symbols in the code range and map them to containing functions.

    All symbols pointing into function bodies must be emitted as labels in .s
    files so they relocate with the code in free-layout builds.

    Returns:
        code_labels: {func_name: [(offset, sym_name), ...]} sorted by offset
        code_label_addrs: set of addresses that are now labels (not PROVIDEs)
    """
    code_labels = {}
    code_label_addrs = set()

    for addr, name in all_symbols.items():
        if not (name.startswith("sym_") or name.startswith("loc_") or
                name.startswith("DAT_") or name.startswith("dat_")):
            continue
        if addr < CODE_START or addr >= CODE_END:
            continue

        # Find the containing function
        for start, end, func_name in fun_ranges:
            if start <= addr < end:
                offset = addr - start
                if func_name not in code_labels:
                    code_labels[func_name] = []
                code_labels[func_name].append((offset, name))
                code_label_addrs.add(addr)
                break

    # Sort labels within each function by offset
    for func_name in code_labels:
        code_labels[func_name].sort()

    return code_labels, code_label_addrs


def emit_function(name, start, end, binary_data, all_symbols, internal_labels=None):
    """Generate .s file content for one function.

    Scans all 4-byte-aligned positions for known symbol addresses.
    Matching values become .4byte SYMBOL; everything else stays .byte.
    Internal labels (sym_ addresses within this function) are emitted at
    the correct byte offsets so they relocate with the function.
    """
    offset_start = start - BASE_ADDR
    offset_end = end - BASE_ADDR
    func_bytes = binary_data[offset_start:offset_end]
    func_size = len(func_bytes)

    # Build a set of offsets where labels should be emitted
    label_at = {}
    if internal_labels:
        for offset, label_name in internal_labels:
            label_at[offset] = label_name

    lines = []

    # Section header
    section_name = "startup" if name == "_start" else name
    lines.append(f"    .section .text.{section_name}")
    lines.append(f"    .global {name}")
    if name != "_start":
        lines.append(f"    .type {name}, @function")
    lines.append(f"{name}:")

    # Track symbolized pool entries for stats
    sym_count = 0

    i = 0
    while i < func_size:
        addr = start + i

        # Emit internal label at this offset (if any)
        if i in label_at:
            lbl = label_at[i]
            lines.append(f"    .global {lbl}")
            lines.append(f"{lbl}:")

        # Check for 4-byte-aligned position with a known symbol value
        if addr % 4 == 0 and i + 4 <= func_size:
            # Check if any label falls inside this 4-byte entry (at i+1, i+2, or i+3)
            # If so, we must NOT emit .4byte — split into bytes instead
            label_inside = ((i + 1) in label_at or (i + 2) in label_at or
                            (i + 3) in label_at)
            if not label_inside:
                value = struct.unpack(">I", func_bytes[i : i + 4])[0]
                if value in all_symbols:
                    sym_name = all_symbols[value]
                    lines.append(f"    .4byte {sym_name}")
                    i += 4
                    sym_count += 1
                    continue

        # Check if there's a label at the next byte (odd offset) — emit single byte
        if i + 1 < func_size and (i + 1) in label_at:
            lines.append(f"    .byte 0x{func_bytes[i]:02X}")
            i += 1
        elif i + 2 <= func_size:
            lines.append(f"    .byte 0x{func_bytes[i]:02X}, 0x{func_bytes[i+1]:02X}")
            i += 2
        else:
            lines.append(f"    .byte 0x{func_bytes[i]:02X}")
            i += 1

    return "\n".join(lines) + "\n", sym_count


def generate_linker_script(fun_syms, provide_syms, code_label_addrs=None):
    """Generate sawyer.ld with PROVIDE declarations for all symbols.

    code_label_addrs: set of addresses defined as labels in .s files
    (these are NOT provided — the label is their definition).
    """
    if code_label_addrs is None:
        code_label_addrs = set()

    lines = []
    lines.append("/* sawyer.ld -- Sawyer L2 linker script")
    lines.append(" * AUTO-GENERATED by tools/symbolize_pools.py -- do not edit manually")
    lines.append(" *")
    lines.append(" * Functions placed in address order via SORT_BY_NAME.")
    lines.append(" * Code-range sym_ symbols are labels in .s files (relocatable).")
    lines.append(" * Data-range sym_ and DAT_ symbols are fixed PROVIDEs.")
    lines.append(" */")
    lines.append("")
    lines.append('OUTPUT_FORMAT("elf32-sh")')
    lines.append("OUTPUT_ARCH(sh)")
    lines.append("ENTRY(_start)")
    lines.append("")
    lines.append("SECTIONS")
    lines.append("{")
    lines.append(f"    . = 0x{BASE_ADDR:08X};")
    lines.append("    .text : {")
    lines.append("        *(.text.startup)")
    lines.append("        *(SORT_BY_NAME(.text.FUN_*))")
    lines.append("    }")
    lines.append("")
    lines.append("    /DISCARD/ : {")
    lines.append("        *(.comment)")
    lines.append("        *(.note.*)")
    lines.append("        *(.eh_frame)")
    lines.append("    }")
    lines.append("}")
    lines.append("")

    # PROVIDE declarations — grouped by type, skip code-range labels
    fun_provide = {}
    dat_provide = {}
    syn_provide = {}
    syn_label_count = 0
    for addr, name in sorted(provide_syms.items()):
        if addr in code_label_addrs:
            syn_label_count += 1
            continue  # Defined as label in .s file, no PROVIDE needed
        if name.startswith("FUN_"):
            fun_provide[addr] = name
        elif name.startswith("DAT_"):
            dat_provide[addr] = name
        else:
            syn_provide[addr] = name

    lines.append(f"/* FUN_ symbols ({len(fun_provide)}) */")
    for addr in sorted(fun_provide.keys()):
        lines.append(f"PROVIDE({fun_provide[addr]} = 0x{addr:08X});")
    lines.append("")

    lines.append(f"/* DAT_ symbols ({len(dat_provide)}) */")
    for addr in sorted(dat_provide.keys()):
        lines.append(f"PROVIDE({dat_provide[addr]} = 0x{addr:08X});")
    lines.append("")

    if syn_provide:
        lines.append(f"/* Synthetic symbols -- fixed (data/system range) ({len(syn_provide)}) */")
        for addr in sorted(syn_provide.keys()):
            lines.append(f"PROVIDE({syn_provide[addr]} = 0x{addr:08X});")
        lines.append("")

    if syn_label_count:
        lines.append(f"/* {syn_label_count} code-range sym_ defined as labels in .s files (relocatable) */")

    return "\n".join(lines) + "\n"


def main():
    global CODE_END
    print("=== Sawyer L2: symbolize_pools.py ===")

    # Load inputs
    print(f"Loading binary: {BINARY_PATH}")
    binary_data = load_binary(BINARY_PATH)
    print(f"  Binary size: {len(binary_data)} bytes")

    # Set CODE_END to cover the entire binary
    CODE_END = BASE_ADDR + len(binary_data)
    print(f"  Code range: 0x{CODE_START:08X} - 0x{CODE_END:08X}")

    print(f"Loading FUN_ symbols: {SYMS_PATH}")
    fun_syms = load_fun_symbols(SYMS_PATH)
    print(f"  {len(fun_syms)} FUN_ symbols")

    print(f"Loading DAT_ symbols: {STUBS_PATH}")
    dat_syms = load_dat_symbols(STUBS_PATH)
    print(f"  {len(dat_syms)} DAT_ symbols")

    # Extract additional symbols from disassembly comments
    print(f"Extracting pool references from: {DISASM_PATH}")
    pool_addrs, ref_values = extract_pool_refs(DISASM_PATH)
    print(f"  {len(pool_addrs)} confirmed pool addresses")
    print(f"  {len(ref_values)} unique referenced values")

    # Build merged symbol table
    # Priority: FUN_ > DAT_ > synthetic
    all_symbols = {}

    # First pass: add synthetics for any referenced value in relocatable range
    new_syns = 0
    for value in ref_values:
        if is_relocatable(value) and value not in fun_syms and value not in dat_syms:
            all_symbols[value] = f"sym_{value:08X}"
            new_syns += 1
    print(f"  {new_syns} new synthetic symbols created")

    # Second pass: overlay named symbols (higher priority)
    all_symbols.update(dat_syms)
    all_symbols.update(fun_syms)
    print(f"  {len(all_symbols)} total unique symbols")

    # Build function ranges
    ranges = build_function_ranges(fun_syms, len(binary_data))
    print(f"  {len(ranges)} functions (including _start)")

    # Discover jump table entries by adjacency to known pool entries
    print(f"\nDiscovering jump table entries...")
    jt_syms = discover_jump_tables(binary_data, all_symbols, ranges)
    all_symbols.update(jt_syms)
    print(f"  {len(jt_syms)} jump table targets discovered (loc_ symbols)")
    print(f"  {len(all_symbols)} total symbols after discovery")

    # Find code-range sym_ and loc_ labels that should be embedded in .s files
    code_labels, code_label_addrs = find_code_labels(all_symbols, ranges)
    print(f"\nCode-range labels:")
    print(f"  {len(code_label_addrs)} sym_ addresses embedded as labels in .s files")
    print(f"  Across {len(code_labels)} functions")

    # Create output directory
    os.makedirs(OUT_DIR, exist_ok=True)

    # Generate per-function .s files
    total_sym = 0
    total_bytes = 0
    for start, end, name in ranges:
        func_labels = code_labels.get(name, None)
        content, sym_count = emit_function(
            name, start, end, binary_data, all_symbols, func_labels
        )
        total_sym += sym_count
        total_bytes += end - start

        filename = f"{name}.s"
        filepath = os.path.join(OUT_DIR, filename)
        with open(filepath, "w", newline="\n") as f:
            f.write(content)

    print(f"\nGenerated {len(ranges)} .s files in {OUT_DIR}")
    print(f"  {total_sym} pool entries symbolized")
    print(f"  {total_bytes} bytes total")

    # Build PROVIDE table for linker script (all symbols that need PROVIDE)
    # FUN_ labels are defined by .global in .s files, but PROVIDE as fallback
    # Code-range sym_ are defined by labels in .s files (no PROVIDE needed)
    # DAT_ and non-code-range synthetic symbols need PROVIDE
    provide_syms = dict(all_symbols)
    generate_ld = generate_linker_script(fun_syms, provide_syms, code_label_addrs)
    with open(LD_OUT, "w", newline="\n") as f:
        f.write(generate_ld)
    print(f"Generated linker script: {LD_OUT}")

    print("\nDone. Run 'cd reimpl && make clean && make && make validate' to test.")


if __name__ == "__main__":
    main()
