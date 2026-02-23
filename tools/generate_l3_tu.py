#!/usr/bin/env python3
"""Generate L3 assembly (SH-2 mnemonics) from a consolidated L2 retail file.

Converts .byte pair blobs into proper SH-2 instruction mnemonics with symbolic
labels for branches and pool entries.  Produces a single-section output file
suitable for free-layout builds.

Usage:
    python tools/generate_l3_tu.py <name>
    python tools/generate_l3_tu.py game_update_loop
    python tools/generate_l3_tu.py secondary_input_handler

Input:  reimpl/retail/<name>.s
Output: reimpl/src/<name>.s
"""

import argparse
import re
import struct
import sys
from pathlib import Path

# ---------------------------------------------------------------------------
# Import the existing SH-2 decoder
# ---------------------------------------------------------------------------
_tools_dir = str(Path(__file__).resolve().parent)
if _tools_dir not in sys.path:
    sys.path.insert(0, _tools_dir)

from sh2_decode import decode_sh2 as _decode_sh2_base


def decode_sh2(opcode, pc):
    """Wrapper around the base decoder with additional instruction coverage."""
    mnemonic, pool = _decode_sh2_base(opcode, pc)
    if 'UNKNOWN' not in mnemonic:
        return mnemonic, pool

    hi = (opcode >> 12) & 0xF
    rn = (opcode >> 8) & 0xF
    rm = (opcode >> 4) & 0xF
    lo = opcode & 0xF

    # 0000nnnn00000010 = stc sr, Rn
    if hi == 0 and rm == 0 and lo == 2:
        return f"stc sr, r{rn}", None
    # 0000nnnn00010010 = stc gbr, Rn
    if hi == 0 and rm == 1 and lo == 2:
        return f"stc gbr, r{rn}", None
    # 0000nnnn00100010 = stc vbr, Rn
    if hi == 0 and rm == 2 and lo == 2:
        return f"stc vbr, r{rn}", None
    # 0000nnnn00000011 = bsrf Rn
    if hi == 0 and rm == 0 and lo == 3:
        return f"bsrf r{rn}", None
    # 0000nnnn00100011 = braf Rn
    if hi == 0 and rm == 2 and lo == 3:
        return f"braf r{rn}", None
    # 0100nnnn00001110 = ldc Rn, sr
    if hi == 4 and lo == 0xE and rm == 0:
        return f"ldc r{rn}, sr", None
    # 0100nnnn00011110 = ldc Rn, gbr
    if hi == 4 and lo == 0xE and rm == 1:
        return f"ldc r{rn}, gbr", None
    # 0100nnnn00101110 = ldc Rn, vbr
    if hi == 4 and lo == 0xE and rm == 2:
        return f"ldc r{rn}, vbr", None
    # 0100nnnn00000111 = ldc.l @Rn+, sr
    if hi == 4 and lo == 7 and rm == 0:
        return f"ldc.l @r{rn}+, sr", None
    # 0100nnnn00010111 = ldc.l @Rn+, gbr
    if hi == 4 and lo == 7 and rm == 1:
        return f"ldc.l @r{rn}+, gbr", None
    # 0100nnnn00100111 = ldc.l @Rn+, vbr
    if hi == 4 and lo == 7 and rm == 2:
        return f"ldc.l @r{rn}+, vbr", None
    # 0100nnnn00000011 = stc.l sr, @-Rn
    if hi == 4 and lo == 3 and rm == 0:
        return f"stc.l sr, @-r{rn}", None
    # 0100nnnn00010011 = stc.l gbr, @-Rn
    if hi == 4 and lo == 3 and rm == 1:
        return f"stc.l gbr, @-r{rn}", None
    # 0100nnnn00100011 = stc.l vbr, @-Rn
    if hi == 4 and lo == 3 and rm == 2:
        return f"stc.l vbr, @-r{rn}", None
    # 0000nnnn10000011 = pref @Rn
    if hi == 0 and rm == 8 and lo == 3:
        return f"pref @r{rn}", None
    # 0100nnnn00101000 = clrmac (actually standalone 0x0028)
    if opcode == 0x0028:
        return "clrmac", None
    # 0000nnnn10010011 = ocbi @Rn
    if hi == 0 and rm == 9 and lo == 3:
        return f"ocbi @r{rn}", None
    # 0000nnnn10100011 = ocbp @Rn
    if hi == 0 and rm == 0xA and lo == 3:
        return f"ocbp @r{rn}", None
    # 0000nnnn10110011 = ocbwb @Rn
    if hi == 0 and rm == 0xB and lo == 3:
        return f"ocbwb @r{rn}", None
    # 1111 group (FPU - SH4 only, not SH2, but just in case)
    # 0100nnnn00101011 = jmp @Rn  -- already covered
    # 0000nnnn01010010 = sts fpul, Rn
    if hi == 0 and rm == 5 and lo == 0xA:
        return f"sts fpul, r{rn}", None
    # 0100nnnn01011010 = lds Rn, fpul
    if hi == 4 and rm == 5 and lo == 0xA:
        return f"lds r{rn}, fpul", None

    return mnemonic, pool

# ---------------------------------------------------------------------------
# TU range (set dynamically from input file)
# ---------------------------------------------------------------------------
TU_START = 0
TU_END   = 0
TU_SIZE  = 0
TU_NAME  = ''

def set_tu_range(start, end, name=''):
    """Set the global TU range from the parsed input file."""
    global TU_START, TU_END, TU_SIZE, TU_NAME
    TU_START = start
    TU_END = end
    TU_SIZE = end - start
    TU_NAME = name

# Instructions with delay slots (the instruction AFTER these is always executed)
_DELAY_SLOT_TERMINATORS = {'bra', 'bsr', 'jsr', 'jmp', 'rts', 'rte'}
_DELAY_SLOT_BRANCHES    = {'bf/s', 'bt/s'}
_NO_DELAY_BRANCHES      = {'bf', 'bt'}

# ---------------------------------------------------------------------------
# Parsing
# ---------------------------------------------------------------------------

def parse_retail_file(filepath):
    """Parse the retail .s file into a list of sections.

    Returns a list of dicts:
        {
            'base':    int,           # absolute address of section start
            'name':    str,           # e.g. 'FUN_06033BC8'
            'bytes':   bytearray,     # raw content
            'globals': [(offset, name, has_type), ...],
            'fourbytes': {offset: symbol_string, ...},
        }
    """
    sections = []
    cur = None

    with open(filepath, 'r', encoding='utf-8', errors='replace') as f:
        for raw_line in f:
            line = raw_line.strip()
            if not line or line.startswith('/*') or line.startswith('*') or line.startswith(' *'):
                continue

            # .section .text.FUN_XXXXXXXX
            m = re.match(r'\.section\s+\.text\.(FUN_([0-9A-Fa-f]+))', line)
            if m:
                sec = {
                    'name':      m.group(1),
                    'base':      int(m.group(2), 16),
                    'bytes':     bytearray(),
                    'globals':   [],
                    'fourbytes': {},
                }
                sections.append(sec)
                cur = sec
                continue

            if cur is None:
                continue

            # .global label
            m = re.match(r'\.global\s+(\S+)', line)
            if m:
                cur['globals'].append((len(cur['bytes']), m.group(1), False))
                continue

            # .type label, @function  (mark the preceding global as having a type)
            m = re.match(r'\.type\s+(\S+)\s*,\s*@function', line)
            if m:
                type_name = m.group(1)
                # Find the most recent global with this name and mark it
                for i in range(len(cur['globals']) - 1, -1, -1):
                    if cur['globals'][i][1] == type_name:
                        off, name, _ = cur['globals'][i]
                        cur['globals'][i] = (off, name, True)
                        break
                continue

            # label:  (bare label line — skip, we get names from .global)
            if re.match(r'^[A-Za-z_]\w*\s*:', line):
                continue

            # .byte 0xHH, 0xHH
            m = re.match(r'\.byte\s+0x([0-9A-Fa-f]+)\s*,\s*0x([0-9A-Fa-f]+)', line)
            if m:
                cur['bytes'].append(int(m.group(1), 16))
                cur['bytes'].append(int(m.group(2), 16))
                continue

            # .byte 0xHH (single byte — occurs at odd-offset data labels)
            m = re.match(r'\.byte\s+0x([0-9A-Fa-f]+)\s*$', line)
            if m:
                cur['bytes'].append(int(m.group(1), 16))
                continue

            # .4byte symbol
            m = re.match(r'\.4byte\s+(\S+)', line)
            if m:
                sym = m.group(1)
                off = len(cur['bytes'])
                cur['fourbytes'][off] = sym
                # Write placeholder bytes (will be overwritten from retail binary)
                cur['bytes'].extend(b'\x00\x00\x00\x00')
                continue

    return sections


def build_flat_image(sections):
    """Build a contiguous byte array and metadata maps from parsed sections.

    Returns:
        image:        bytearray of TU_SIZE bytes (indexed by addr - TU_START)
        globals_map:  {absolute_addr: (name, has_type)}
        fourbyte_map: {absolute_addr: symbol_string}
    """
    image = bytearray(TU_SIZE)
    globals_map  = {}   # addr -> (name, has_type)
    fourbyte_map = {}   # addr -> symbol string

    for sec in sections:
        base = sec['base']
        data = sec['bytes']
        end  = base + len(data)

        if base < TU_START or end > TU_END:
            print(f"WARNING: section {sec['name']} at 0x{base:08X}-0x{end:08X} "
                  f"outside TU range, clipping", file=sys.stderr)
            # Clip to TU range
            clip_start = max(base, TU_START)
            clip_end   = min(end, TU_END)
            src_off = clip_start - base
            dst_off = clip_start - TU_START
            length  = clip_end - clip_start
            image[dst_off:dst_off + length] = data[src_off:src_off + length]
        else:
            off = base - TU_START
            image[off:off + len(data)] = data

        # Map globals
        for goff, gname, gtype in sec['globals']:
            addr = base + goff
            if TU_START <= addr < TU_END:
                globals_map[addr] = (gname, gtype)

        # Map .4byte entries
        for foff, fsym in sec['fourbytes'].items():
            addr = base + foff
            if TU_START <= addr < TU_END:
                fourbyte_map[addr] = fsym

    return image, globals_map, fourbyte_map


# ---------------------------------------------------------------------------
# Flow analysis — classify every 2-byte slot as CODE or DATA
# ---------------------------------------------------------------------------

def _extract_branch_target(mnemonic):
    """Extract the hex target address from a decoded mnemonic string."""
    m = re.search(r'0x([0-9A-Fa-f]+)', mnemonic)
    if m:
        return int(m.group(1), 16)
    return None


def _mnemonic_base(mnemonic):
    """Return the instruction name (first word) from a decoded mnemonic."""
    return mnemonic.split()[0].rstrip(',') if mnemonic else ''


def _find_pool_targets(image):
    """Pre-scan every 2-byte slot, decode it as if it were an instruction, and
    collect all pool targets (mov.l / mov.w @(disp,PC) targets).

    This runs BEFORE flow analysis so we know which addresses are pool data
    and should not be seeded as code entry points.
    """
    pool_targets = set()
    for off in range(0, TU_SIZE - 1, 2):
        pc = TU_START + off
        opcode = (image[off] << 8) | image[off + 1]
        hi = (opcode >> 12) & 0xF
        if hi == 0xD:  # mov.l @(disp,PC), Rn
            disp = opcode & 0xFF
            target = (pc & 0xFFFFFFFC) + 4 + disp * 4
            if TU_START <= target < TU_END:
                pool_targets.add(target)
        elif hi == 0x9:  # mov.w @(disp,PC), Rn
            disp = opcode & 0xFF
            target = pc + 4 + disp * 2
            if TU_START <= target < TU_END:
                pool_targets.add(target)
    return pool_targets


def flow_analysis(image, globals_map, fourbyte_map):
    """Determine which 2-byte-aligned addresses are code vs data.

    Returns:
        code_addrs: set of absolute addresses that are code (instruction starts)
    """
    code_addrs = set()
    work = []  # addresses to explore

    # Pre-scan to find all pool targets — these are data, not code
    pool_targets = _find_pool_targets(image)

    # Also build the set of .4byte regions (each covers 4 bytes = 2 slots)
    fourbyte_addrs = set()
    for addr in fourbyte_map:
        fourbyte_addrs.add(addr)
        fourbyte_addrs.add(addr + 2)

    # Seed with global label addresses that are NOT pool targets or .4byte data
    for addr in globals_map:
        if addr in pool_targets:
            continue
        if addr in fourbyte_addrs:
            continue
        work.append(addr)

    visited = set()

    while work:
        pc = work.pop()

        if pc in visited:
            continue
        visited.add(pc)

        if pc < TU_START or pc >= TU_END:
            continue

        # Skip if this address is a pool target (data, not code)
        if pc in pool_targets:
            continue

        # Skip if this address is inside a .4byte entry
        if pc in fourbyte_map:
            continue
        # Also check if pc is at offset +2 inside a .4byte
        if (pc - 2) in fourbyte_map:
            continue

        off = pc - TU_START
        if off + 2 > TU_SIZE:
            continue

        code_addrs.add(pc)

        opcode = (image[off] << 8) | image[off + 1]
        mnemonic, pool_target = decode_sh2(opcode, pc)
        base = _mnemonic_base(mnemonic)

        target = _extract_branch_target(mnemonic)

        if base in _DELAY_SLOT_TERMINATORS:
            # Mark delay slot as code
            ds_pc = pc + 2
            if TU_START <= ds_pc < TU_END:
                ds_off = ds_pc - TU_START
                if ds_off + 2 <= TU_SIZE:
                    code_addrs.add(ds_pc)
            # Follow branch target (for bra/bsr)
            if target is not None and TU_START <= target < TU_END:
                work.append(target)
            # For bra/jmp/rts/rte: do NOT continue sequential flow
            # For bsr/jsr: continue after delay slot
            if base in ('bsr', 'jsr'):
                work.append(pc + 4)
            # bra/jmp/rts/rte: stop sequential

        elif base in _DELAY_SLOT_BRANCHES:
            # bf/s, bt/s: delay slot IS executed, branch may or may not be taken
            ds_pc = pc + 2
            if TU_START <= ds_pc < TU_END:
                code_addrs.add(ds_pc)
            # Follow both: fall-through after delay slot AND branch target
            work.append(pc + 4)  # fall-through (after delay slot)
            if target is not None and TU_START <= target < TU_END:
                work.append(target)

        elif base in _NO_DELAY_BRANCHES:
            # bf, bt: NO delay slot
            # Follow both: next instruction AND branch target
            work.append(pc + 2)
            if target is not None and TU_START <= target < TU_END:
                work.append(target)

        else:
            # Normal instruction: continue sequential flow
            work.append(pc + 2)

    return code_addrs


# ---------------------------------------------------------------------------
# Pool and label identification
# ---------------------------------------------------------------------------

def identify_pools_and_labels(image, code_addrs, globals_map, fourbyte_map):
    """Identify pool entries and all labels needed in the output.

    Returns:
        pool_labels:   {addr: label_string}   for .4byte pool entries
        wpool_labels:  {addr: label_string}    for .2byte word-pool entries
        branch_labels: {addr: label_string}    for branch targets
    """
    pool_labels   = {}  # addr -> ".L_pool_XXXXXXXX"
    wpool_labels  = {}  # addr -> ".L_wpool_XXXXXXXX"
    branch_labels = {}  # addr -> ".L_XXXXXXXX" or global name

    # -- Collect all branch/pool targets from code instructions --
    for pc in sorted(code_addrs):
        off = pc - TU_START
        opcode = (image[off] << 8) | image[off + 1]
        mnemonic, pool_target = decode_sh2(opcode, pc)
        base = _mnemonic_base(mnemonic)

        # Pool loads: mov.l @(disp,PC) and mov.w @(disp,PC)
        if pool_target is not None:
            if TU_START <= pool_target < TU_END:
                hi = (opcode >> 12) & 0xF
                if hi == 0xD:  # mov.l
                    if pool_target not in pool_labels:
                        pool_labels[pool_target] = f".L_pool_{pool_target:08X}"
                elif hi == 0x9:  # mov.w
                    if pool_target not in wpool_labels:
                        wpool_labels[pool_target] = f".L_wpool_{pool_target:08X}"

        # Branch targets
        target = _extract_branch_target(mnemonic)
        if target is not None and base not in ('mov.l', 'mov.w'):
            # Check if this is a branch instruction
            if base in ('bra', 'bsr', 'bf', 'bt', 'bf/s', 'bt/s'):
                if TU_START <= target < TU_END:
                    if target not in branch_labels:
                        # Use global name if available
                        if target in globals_map:
                            branch_labels[target] = globals_map[target][0]
                        else:
                            branch_labels[target] = f".L_{target:08X}"

    return pool_labels, wpool_labels, branch_labels


def label_for_addr(addr, globals_map, branch_labels, pool_labels, wpool_labels):
    """Get the label for an address, preferring globals over generated labels."""
    if addr in globals_map:
        return globals_map[addr][0]
    if addr in branch_labels:
        return branch_labels[addr]
    if addr in pool_labels:
        return pool_labels[addr]
    if addr in wpool_labels:
        return wpool_labels[addr]
    return None


# ---------------------------------------------------------------------------
# Output generation
# ---------------------------------------------------------------------------

def generate_output(image, code_addrs, globals_map, fourbyte_map,
                    pool_labels, wpool_labels, branch_labels):
    """Generate the L3 assembly output as a list of lines."""
    lines = []

    # Header
    lines.append(f"/* {TU_NAME} -- L3 assembly (SH-2 mnemonics)")
    lines.append(f" * Translation unit: 0x{TU_START:08X} - 0x{TU_END:08X}")
    lines.append(" * Auto-generated by tools/generate_l3_tu.py")
    lines.append(" */")
    lines.append("")

    # Get the first section name from the first global
    first_sec = f"FUN_{TU_START:08X}"
    lines.append(f"    .section .text.{first_sec}")
    # If the TU start address is not 4-byte aligned, pad the section so that
    # all absolute addresses within the TU have the same alignment relative to
    # the section base as in the original binary.  This is needed because
    # mov.l @(disp,PC) computes targets relative to (PC & ~3), and the
    # assembler assumes the section base is 4-byte aligned.
    pad = TU_START % 4
    if pad:
        lines.append(f"    .space {pad}    /* align to match original address 0x{TU_START:08X} (mod 4 = {pad}) */")
    lines.append("")

    # Statistics
    stats = {
        'instructions': 0,
        'pool_4byte': 0,
        'pool_2byte': 0,
        'pool_symbol': 0,
        'pool_literal': 0,
        'branch_labels': 0,
        'globals': 0,
        'external_bytes': 0,
    }

    pc = TU_START
    prev_was_code = True  # track transitions for blank-line formatting

    while pc < TU_END:
        off = pc - TU_START
        is_code = pc in code_addrs

        # -- Emit labels at this address --

        # Emit global labels
        if pc in globals_map:
            gname, gtype = globals_map[pc]
            lines.append("")
            lines.append(f"    .global {gname}")
            if gtype:
                lines.append(f"    .type {gname}, @function")
            lines.append(f"{gname}:")
            stats['globals'] += 1

        # Emit branch labels (only if not already a global)
        if pc in branch_labels and pc not in globals_map:
            lines.append(f"{branch_labels[pc]}:")
            stats['branch_labels'] += 1

        # Emit pool labels (only if not already a global)
        if pc in pool_labels and pc not in globals_map:
            if pc % 4 != 0:
                lines.append("    .balign 4")
            lines.append(f"{pool_labels[pc]}:")
        if pc in wpool_labels and pc not in globals_map:
            lines.append(f"{wpool_labels[pc]}:")

        # -- Emit content --
        if is_code:
            # Decode and emit instruction
            opcode = (image[off] << 8) | image[off + 1]
            mnemonic, pool_target = decode_sh2(opcode, pc)
            base = _mnemonic_base(mnemonic)

            # Rewrite pool-referencing instructions to use symbolic labels
            hi = (opcode >> 12) & 0xF
            if hi == 0xD and pool_target is not None:
                # mov.l @(disp,PC), Rn -> mov.l LABEL, Rn
                rn = (opcode >> 8) & 0xF
                if pool_target in globals_map:
                    plabel = globals_map[pool_target][0]
                elif pool_target in pool_labels:
                    plabel = pool_labels[pool_target]
                else:
                    plabel = f".L_pool_{pool_target:08X}"
                    pool_labels[pool_target] = plabel
                lines.append(f"    mov.l   {plabel}, r{rn}")
                stats['instructions'] += 1
                pc += 2
                continue

            if hi == 0x9 and pool_target is not None:
                # mov.w @(disp,PC), Rn -> mov.w LABEL, Rn
                rn = (opcode >> 8) & 0xF
                if pool_target in globals_map:
                    wlabel = globals_map[pool_target][0]
                elif pool_target in wpool_labels:
                    wlabel = wpool_labels[pool_target]
                else:
                    wlabel = f".L_wpool_{pool_target:08X}"
                    wpool_labels[pool_target] = wlabel
                lines.append(f"    mov.w   {wlabel}, r{rn}")
                stats['instructions'] += 1
                pc += 2
                continue

            # Rewrite branch instructions to use symbolic labels
            if base in ('bra', 'bsr', 'bf', 'bt', 'bf/s', 'bt/s'):
                target = _extract_branch_target(mnemonic)
                if target is not None:
                    if TU_START <= target < TU_END:
                        # Internal branch - use symbolic label
                        if target in globals_map:
                            tlabel = globals_map[target][0]
                        elif target in branch_labels:
                            tlabel = branch_labels[target]
                        else:
                            tlabel = f".L_{target:08X}"
                            branch_labels[target] = tlabel
                        lines.append(f"    {base:8s}{tlabel}")
                        stats['instructions'] += 1
                        pc += 2
                        continue
                    else:
                        # External branch - keep as .byte pairs
                        b0 = image[off]
                        b1 = image[off + 1]
                        lines.append(f"    .byte   0x{b0:02X}, 0x{b1:02X}"
                                     f"    /* {mnemonic} (external) */")
                        stats['external_bytes'] += 1
                        pc += 2
                        continue

            # Regular instruction
            lines.append(f"    {mnemonic}")
            stats['instructions'] += 1
            pc += 2

        else:
            # Data region (pool entry)

            # Helper: emit .balign 4 if needed before a 4-byte entry
            def _emit_balign_if_needed():
                if pc % 4 != 0:
                    lines.append("    .balign 4")

            # Check if this is a .4byte symbol reference
            if pc in fourbyte_map:
                _emit_balign_if_needed()
                sym = fourbyte_map[pc]
                lines.append(f"    .4byte  {sym}")
                stats['pool_4byte'] += 1
                stats['pool_symbol'] += 1
                pc += 4
                continue

            # Check if this address is a word-pool target (2-byte)
            if pc in wpool_labels:
                val = (image[off] << 8) | image[off + 1]
                lines.append(f"    .2byte  0x{val:04X}")
                stats['pool_2byte'] += 1
                pc += 2
                continue

            # Check if next byte has a global (odd-offset data label).
            # If so, emit single byte to avoid skipping the label.
            if (pc + 1) in globals_map:
                lines.append(f"    .byte   0x{image[off]:02X}")
                pc += 1
                continue

            # Determine if this data slot should be emitted as a 4-byte entry.
            # Requirements: 4-byte aligned, room for 4 bytes, and no label/code
            # boundary at pc+1, pc+2, or pc+3.
            can_emit_4 = (
                pc % 4 == 0 and
                off + 4 <= TU_SIZE and
                (pc + 1) not in globals_map and
                (pc + 2) not in fourbyte_map and
                (pc + 2) not in code_addrs and
                (pc + 2) not in globals_map and
                (pc + 2) not in branch_labels and
                (pc + 2) not in pool_labels and
                (pc + 2) not in wpool_labels and
                (pc + 3) not in globals_map
            )

            if can_emit_4:
                val = struct.unpack('>I', image[off:off + 4])[0]
                lines.append(f"    .4byte  0x{val:08X}")
                stats['pool_4byte'] += 1
                stats['pool_literal'] += 1
                pc += 4
                continue

            # Fallback: emit as 2 bytes
            if off + 2 <= TU_SIZE:
                val = (image[off] << 8) | image[off + 1]
                lines.append(f"    .2byte  0x{val:04X}")
                stats['pool_2byte'] += 1
                pc += 2
            else:
                lines.append(f"    .byte   0x{image[off]:02X}")
                pc += 1

    return lines, stats


# ---------------------------------------------------------------------------
# Post-processing: ensure pool labels exist for all referenced pools
# ---------------------------------------------------------------------------

def ensure_pool_labels(image, code_addrs, pool_labels, wpool_labels, fourbyte_map):
    """Make sure every mov.l/mov.w @(disp,PC) target has a pool label, and
    that pool labels at .4byte addresses work correctly."""
    for pc in sorted(code_addrs):
        off = pc - TU_START
        opcode = (image[off] << 8) | image[off + 1]
        _, pool_target = decode_sh2(opcode, pc)
        hi = (opcode >> 12) & 0xF

        if pool_target is not None and TU_START <= pool_target < TU_END:
            if hi == 0xD:
                if pool_target not in pool_labels:
                    pool_labels[pool_target] = f".L_pool_{pool_target:08X}"
            elif hi == 0x9:
                if pool_target not in wpool_labels:
                    wpool_labels[pool_target] = f".L_wpool_{pool_target:08X}"


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    parser = argparse.ArgumentParser(
        description='Generate L3 assembly from L2 retail file')
    parser.add_argument('name', help='TU name (e.g., game_update_loop)')
    parser.add_argument('--input', '-i', default=None,
                        help='Input retail .s file (default: reimpl/retail/<name>.s)')
    parser.add_argument('--output', '-o', default=None,
                        help='Output L3 .s file (default: reimpl/src/<name>.s)')
    parser.add_argument('--dry-run', '-n', action='store_true',
                        help='Print to stdout instead of writing file')
    args = parser.parse_args()

    input_path = args.input or f'reimpl/retail/{args.name}.s'
    output_path = args.output or f'reimpl/src/{args.name}.s'

    print(f"Parsing {input_path} ...")
    sections = parse_retail_file(input_path)
    print(f"  {len(sections)} sections parsed")

    if not sections:
        print("ERROR: no sections found", file=sys.stderr)
        sys.exit(1)

    # Auto-detect TU range from parsed sections
    sorted_secs = sorted(sections, key=lambda s: s['base'])
    tu_start = sorted_secs[0]['base']
    last_sec = sorted_secs[-1]
    tu_end = last_sec['base'] + len(last_sec['bytes'])
    set_tu_range(tu_start, tu_end, args.name)

    # Validate address coverage
    total_bytes = sum(len(s['bytes']) for s in sections)
    print(f"  {total_bytes} total bytes across sections")
    print(f"  TU range: 0x{TU_START:08X} - 0x{TU_END:08X} ({TU_SIZE} bytes)")

    # Check for gaps or overlaps
    prev_end = None
    for sec in sorted_secs:
        start = sec['base']
        end = start + len(sec['bytes'])
        if prev_end is not None and start != prev_end:
            if start < prev_end:
                print(f"  WARNING: overlap at 0x{start:08X} "
                      f"(prev ended 0x{prev_end:08X})", file=sys.stderr)
            else:
                gap = start - prev_end
                print(f"  WARNING: gap of {gap} bytes at "
                      f"0x{prev_end:08X}-0x{start:08X}", file=sys.stderr)
        prev_end = end

    print("\nBuilding flat image ...")
    image, globals_map, fourbyte_map = build_flat_image(sections)
    print(f"  {len(globals_map)} global labels")
    print(f"  {len(fourbyte_map)} .4byte symbol entries")

    print("\nRunning flow analysis ...")
    code_addrs = flow_analysis(image, globals_map, fourbyte_map)
    data_count = 0
    for addr in range(TU_START, TU_END, 2):
        if addr not in code_addrs:
            data_count += 1
    print(f"  {len(code_addrs)} code slots (instruction starts)")
    print(f"  {data_count} data slots (2-byte granularity)")

    print("\nIdentifying pools and labels ...")
    pool_labels, wpool_labels, branch_labels = identify_pools_and_labels(
        image, code_addrs, globals_map, fourbyte_map)
    ensure_pool_labels(image, code_addrs, pool_labels, wpool_labels, fourbyte_map)
    print(f"  {len(pool_labels)} long-word pool labels (.L_pool_)")
    print(f"  {len(wpool_labels)} word pool labels (.L_wpool_)")
    print(f"  {len(branch_labels)} branch target labels")

    print("\nGenerating output ...")
    output_lines, stats = generate_output(
        image, code_addrs, globals_map, fourbyte_map,
        pool_labels, wpool_labels, branch_labels)

    print(f"\n{'='*60}")
    print(f"STATISTICS")
    print(f"{'='*60}")
    print(f"  Instructions decoded:    {stats['instructions']}")
    print(f"  Pool entries (4-byte):   {stats['pool_4byte']}")
    print(f"    - symbol references:   {stats['pool_symbol']}")
    print(f"    - literal constants:   {stats['pool_literal']}")
    print(f"  Pool entries (2-byte):   {stats['pool_2byte']}")
    print(f"  Global labels emitted:   {stats['globals']}")
    print(f"  Branch labels emitted:   {stats['branch_labels']}")
    print(f"  External branch .bytes:  {stats['external_bytes']}")

    text = '\n'.join(output_lines) + '\n'

    if args.dry_run:
        print(f"\n{'='*60}")
        print("OUTPUT (dry run)")
        print(f"{'='*60}")
        sys.stdout.write(text)
    else:
        out_path = Path(output_path)
        out_path.parent.mkdir(parents=True, exist_ok=True)
        with open(out_path, 'w', newline='\n') as f:
            f.write(text)
        print(f"\nWrote {len(output_lines)} lines to {output_path}")


if __name__ == '__main__':
    main()
