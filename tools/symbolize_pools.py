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
CODE_END = 0x06060000  # End of code section (data starts after this)


def find_code_labels(all_symbols, fun_ranges):
    """Find sym_ symbols in the code range and map them to containing functions.

    Returns:
        code_labels: {func_name: [(offset, sym_name), ...]} sorted by offset
        code_label_addrs: set of addresses that are now labels (not PROVIDEs)
    """
    code_labels = {}
    code_label_addrs = set()

    for addr, name in all_symbols.items():
        if not name.startswith("sym_"):
            continue
        if addr < CODE_START or addr >= CODE_END:
            continue
        # Only embed labels at 2-byte-aligned addresses (SH-2 instruction boundary)
        # Odd addresses are data byte pointers — keep as fixed PROVIDEs
        if addr % 2 != 0:
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
            # Check if a label falls at offset i+2 (middle of this 4-byte entry)
            # If so, we must NOT emit .4byte — split into .byte pairs instead
            if (i + 2) not in label_at:
                value = struct.unpack(">I", func_bytes[i : i + 4])[0]
                if value in all_symbols:
                    sym_name = all_symbols[value]
                    lines.append(f"    .4byte {sym_name}")
                    i += 4
                    sym_count += 1
                    continue

        # Emit as .byte pair (2 bytes per line, matching SH-2 instruction width)
        if i + 2 <= func_size:
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
    print("=== Sawyer L2: symbolize_pools.py ===")

    # Load inputs
    print(f"Loading binary: {BINARY_PATH}")
    binary_data = load_binary(BINARY_PATH)
    print(f"  Binary size: {len(binary_data)} bytes")

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

    # Find code-range sym_ labels that should be embedded in .s files
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
