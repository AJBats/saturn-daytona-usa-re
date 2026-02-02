"""
trace_flow.py - Trace top-level program flow in APROG.BIN
Lightweight SH-2 disassembly focused on control flow:
  - Follows jsr/bsr calls to build call graph
  - Identifies backward branches (loops)
  - Maps the top-level program structure
"""

import struct
import os
import sys

FILES_DIR = os.path.join(os.path.dirname(__file__), "..", "build", "disc", "files")
BASE_ADDR = 0x06003000


def read_u16(data, offset):
    """Read big-endian 16-bit word."""
    if offset + 1 >= len(data):
        return None
    return (data[offset] << 8) | data[offset + 1]


def read_u32(data, offset):
    """Read big-endian 32-bit word."""
    if offset + 3 >= len(data):
        return None
    return struct.unpack_from(">I", data, offset)[0]


def sign_extend_12(val):
    """Sign-extend a 12-bit value."""
    if val & 0x800:
        return val | ~0xFFF
    return val


def sign_extend_8(val):
    """Sign-extend an 8-bit value."""
    if val & 0x80:
        return val | ~0xFF
    return val


def disasm_one(data, offset, base_addr):
    """
    Disassemble one SH-2 instruction. Returns a dict with:
      - 'addr': address
      - 'raw': raw 16-bit opcode
      - 'mnemonic': instruction mnemonic
      - 'op': simplified operation type
      - 'target': branch/call target address (if applicable)
      - 'reg': register involved (if applicable)
    """
    addr = base_addr + offset
    w = read_u16(data, offset)
    if w is None:
        return None

    result = {"addr": addr, "raw": w, "mnemonic": "???", "op": "other",
              "target": None, "reg": None}

    hi4 = (w >> 12) & 0xF
    lo4 = w & 0xF
    rn = (w >> 8) & 0xF
    rm = (w >> 4) & 0xF

    # mov.l @(disp,PC),Rn  -- 1101 nnnn dddddddd
    if hi4 == 0xD:
        disp = w & 0xFF
        pc_val = (addr & ~3) + 4 + disp * 4
        pool_offset = pc_val - base_addr
        pool_val = read_u32(data, pool_offset) if 0 <= pool_offset < len(data) - 3 else None
        result["mnemonic"] = "mov.l @(0x%X,PC),r%d" % (disp * 4, rn)
        result["op"] = "load_const"
        result["reg"] = rn
        result["target"] = pool_val
        return result

    # jsr @Rn  -- 0100 nnnn 0000 1011
    if hi4 == 0x4 and (w & 0xFF) == 0x0B:
        result["mnemonic"] = "jsr @r%d" % rn
        result["op"] = "jsr"
        result["reg"] = rn
        return result

    # jmp @Rn  -- 0100 nnnn 0010 1011
    if hi4 == 0x4 and (w & 0xFF) == 0x2B:
        result["mnemonic"] = "jmp @r%d" % rn
        result["op"] = "jmp"
        result["reg"] = rn
        return result

    # bsr disp  -- 1011 dddd dddd dddd
    if hi4 == 0xB:
        disp = sign_extend_12(w & 0xFFF)
        target = addr + 4 + disp * 2
        result["mnemonic"] = "bsr 0x%08X" % target
        result["op"] = "bsr"
        result["target"] = target
        return result

    # bra disp  -- 1010 dddd dddd dddd
    if hi4 == 0xA:
        disp = sign_extend_12(w & 0xFFF)
        target = addr + 4 + disp * 2
        result["mnemonic"] = "bra 0x%08X" % target
        result["op"] = "bra"
        result["target"] = target
        return result

    # rts  -- 0000 0000 0000 1011
    if w == 0x000B:
        result["mnemonic"] = "rts"
        result["op"] = "rts"
        return result

    # bt disp  -- 1000 1001 dddd dddd
    if (w >> 8) == 0x89:
        disp = sign_extend_8(w & 0xFF)
        target = addr + 4 + disp * 2
        result["mnemonic"] = "bt 0x%08X" % target
        result["op"] = "bt"
        result["target"] = target
        return result

    # bf disp  -- 1000 1011 dddd dddd
    if (w >> 8) == 0x8B:
        disp = sign_extend_8(w & 0xFF)
        target = addr + 4 + disp * 2
        result["mnemonic"] = "bf 0x%08X" % target
        result["op"] = "bf"
        result["target"] = target
        return result

    # bt/s disp  -- 1000 1101 dddd dddd
    if (w >> 8) == 0x8D:
        disp = sign_extend_8(w & 0xFF)
        target = addr + 4 + disp * 2
        result["mnemonic"] = "bt/s 0x%08X" % target
        result["op"] = "bt_s"
        result["target"] = target
        return result

    # bf/s disp  -- 1000 1111 dddd dddd
    if (w >> 8) == 0x8F:
        disp = sign_extend_8(w & 0xFF)
        target = addr + 4 + disp * 2
        result["mnemonic"] = "bf/s 0x%08X" % target
        result["op"] = "bf_s"
        result["target"] = target
        return result

    # sts.l pr,@-r15  -- 0100 1111 0010 0010
    if w == 0x4F22:
        result["mnemonic"] = "sts.l pr,@-r15"
        result["op"] = "push_pr"
        return result

    # lds.l @r15+,pr  -- 0100 1111 0010 0110
    if w == 0x4F26:
        result["mnemonic"] = "lds.l @r15+,pr"
        result["op"] = "pop_pr"
        return result

    # mov.l Rm,@-r15  -- 0010 1111 mmmm 0110
    if hi4 == 0x2 and rn == 0xF and lo4 == 0x6:
        result["mnemonic"] = "mov.l r%d,@-r15" % rm
        result["op"] = "push_reg"
        result["reg"] = rm
        return result

    # mov Rm,Rn  -- 0110 nnnn mmmm 0011
    if hi4 == 0x6 and lo4 == 0x3:
        result["mnemonic"] = "mov r%d,r%d" % (rm, rn)
        result["op"] = "mov_reg"
        return result

    # mov #imm,Rn  -- 1110 nnnn iiii iiii
    if hi4 == 0xE:
        imm = sign_extend_8(w & 0xFF)
        result["mnemonic"] = "mov #%d,r%d" % (imm, rn)
        result["op"] = "mov_imm"
        result["reg"] = rn
        return result

    # ldc Rm,SR  -- 0100 mmmm 0000 1110
    if hi4 == 0x4 and (w & 0xFF) == 0x0E:
        result["mnemonic"] = "ldc r%d,SR" % rn
        result["op"] = "ldc_sr"
        return result

    # For anything else, just show the hex
    result["mnemonic"] = ".word 0x%04X" % w
    return result


def disasm_function(data, func_addr, base_addr, max_insns=200):
    """
    Disassemble a function starting at func_addr.
    Returns list of instruction dicts.
    Stops at rts + delay slot, or after max_insns.
    """
    offset = func_addr - base_addr
    if offset < 0 or offset >= len(data):
        return []

    insns = []
    hit_rts = False
    for i in range(max_insns):
        ins = disasm_one(data, offset, base_addr)
        if ins is None:
            break
        insns.append(ins)

        # Stop after the delay slot following rts
        if hit_rts:
            break
        if ins["op"] == "rts":
            hit_rts = True

        offset += 2

    return insns


def extract_calls(data, insns, base_addr):
    """
    Extract call targets from a function's instruction list.
    Resolves register-indirect calls (mov.l @(disp,PC),rN + jsr @rN).
    Returns list of (call_addr, target_addr).
    """
    calls = []
    # Track which registers hold which constant pool values
    reg_vals = {}

    for ins in insns:
        if ins["op"] == "load_const" and ins["target"] is not None:
            reg_vals[ins["reg"]] = ins["target"]

        elif ins["op"] == "jsr":
            reg = ins["reg"]
            target = reg_vals.get(reg)
            if target is not None:
                calls.append((ins["addr"], target))
            else:
                calls.append((ins["addr"], None))

        elif ins["op"] == "bsr":
            calls.append((ins["addr"], ins["target"]))

    return calls


def find_backward_branches(insns, func_addr):
    """Find branches that go backward (potential loops)."""
    loops = []
    for ins in insns:
        if ins["op"] in ("bra", "bt", "bf", "bt_s", "bf_s") and ins["target"] is not None:
            if ins["target"] <= ins["addr"]:
                loops.append((ins["addr"], ins["target"]))
    return loops


def analyze_function(data, func_addr, base_addr, label="", depth=0, visited=None):
    """
    Analyze a function: disassemble, extract calls, find loops.
    Recurse into callees up to a certain depth.
    """
    if visited is None:
        visited = set()
    if func_addr in visited:
        return
    visited.add(func_addr)

    offset = func_addr - base_addr
    if offset < 0 or offset >= len(data):
        print("%s  [out of range]" % ("  " * depth))
        return

    indent = "  " * depth
    if label:
        print("%s=== %s (0x%08X) ===" % (indent, label, func_addr))
    else:
        print("%s=== FUN_%08X ===" % (indent, func_addr))

    insns = disasm_function(data, func_addr, base_addr)
    calls = extract_calls(data, insns, base_addr)
    loops = find_backward_branches(insns, func_addr)

    # Show the disassembly for top-level functions
    if depth <= 1:
        for ins in insns:
            marker = ""
            if ins["op"] == "jsr" or ins["op"] == "bsr":
                marker = "  <-- CALL"
                if ins.get("target"):
                    marker += " 0x%08X" % ins["target"]
            elif ins["op"] in ("bra", "bt", "bf", "bt_s", "bf_s"):
                if ins["target"] and ins["target"] <= ins["addr"]:
                    marker = "  <-- LOOP BACK"
            elif ins["op"] == "rts":
                marker = "  <-- RETURN"
            print("%s  0x%08X: %-30s%s" % (indent, ins["addr"], ins["mnemonic"], marker))

    # Summary
    print("%s  Calls %d functions:" % (indent, len(calls)))
    for call_addr, target in calls:
        if target is not None:
            in_range = base_addr <= target < base_addr + len(data)
            print("%s    0x%08X -> 0x%08X%s" % (
                indent, call_addr, target,
                "" if in_range else " [EXTERNAL]"))
        else:
            print("%s    0x%08X -> [unresolved register]" % (indent, call_addr))

    if loops:
        print("%s  Backward branches (loops):" % indent)
        for br_addr, target in loops:
            print("%s    0x%08X -> 0x%08X (loop body: %d bytes)" % (
                indent, br_addr, target, br_addr - target))

    # Recurse into callees
    if depth < 2:
        for _, target in calls:
            if target is not None and base_addr <= target < base_addr + len(data):
                print()
                analyze_function(data, target, base_addr, depth=depth + 1, visited=visited)


def scan_for_main_loop(data, base_addr):
    """
    Look for the main game loop by finding functions with backward branches
    that also make many calls (a main loop calls subsystems each frame).
    """
    from trace_flow import scan_function_prologues_simple

    print("\n=== Scanning for Main Loop Candidates ===")
    print("Looking for functions with backward branches AND many calls...\n")

    # Get all function entry points from prologues
    prologues = scan_function_prologues_simple(data, base_addr)

    candidates = []
    for func_addr in prologues:
        insns = disasm_function(data, func_addr, base_addr, max_insns=500)
        calls = extract_calls(data, insns, base_addr)
        loops = find_backward_branches(insns, func_addr)

        if loops and len(calls) >= 5:
            candidates.append({
                "addr": func_addr,
                "calls": len(calls),
                "loops": len(loops),
                "insns": len(insns),
            })

    candidates.sort(key=lambda x: -x["calls"])
    print("Top candidates (many calls + backward branches):")
    for c in candidates[:20]:
        print("  0x%08X: %d calls, %d loops, %d instructions" % (
            c["addr"], c["calls"], c["loops"], c["insns"]))

    return candidates


def scan_function_prologues_simple(data, base_addr):
    """Simple prologue scanner returning just addresses."""
    addrs = []
    i = 0
    while i < len(data) - 4:
        if data[i] == 0x2F and data[i + 1] == 0xE6:
            addrs.append(base_addr + i)
        i += 2
    return addrs


def analyze_hw_init(data, base_addr):
    """
    Analyze the hardware init function at 0x060030FC.
    Look for Saturn hardware register writes.
    """
    func_addr = 0x060030FC
    print("\n=== Hardware Init Function (0x%08X) ===" % func_addr)

    insns = disasm_function(data, func_addr, base_addr, max_insns=500)
    calls = extract_calls(data, insns, base_addr)

    # Look for addresses in the Saturn hardware register ranges
    hw_accesses = []
    for ins in insns:
        if ins["op"] == "load_const" and ins["target"] is not None:
            addr = ins["target"]
            region = None
            if 0x25D00000 <= addr <= 0x25D00FFF:
                region = "VDP1"
            elif 0x25E00000 <= addr <= 0x25E00FFF:
                region = "VDP1 VRAM"
            elif 0x25F80000 <= addr <= 0x25F80FFF:
                region = "VDP2"
            elif 0x25FE0000 <= addr <= 0x25FE00FF:
                region = "SCU"
            elif 0x20000000 <= addr <= 0x2007FFFF:
                region = "CS0 (ROM/cart)"
            elif 0xFFFFFE00 <= addr <= 0xFFFFFFFF:
                region = "SH2 on-chip"
            elif 0x25A00000 <= addr <= 0x25A00FFF:
                region = "SCSP (sound)"
            elif 0x25B00000 <= addr <= 0x25B00FFF:
                region = "SMPC"

            if region:
                hw_accesses.append((ins["addr"], addr, region))

    print("  Total instructions: %d" % len(insns))
    print("  Calls: %d" % len(calls))
    for call_addr, target in calls:
        if target:
            print("    0x%08X -> 0x%08X" % (call_addr, target))

    if hw_accesses:
        print("  Hardware register references:")
        for ins_addr, hw_addr, region in hw_accesses:
            print("    0x%08X loads 0x%08X (%s)" % (ins_addr, hw_addr, region))


if __name__ == "__main__":
    aprog_path = os.path.join(FILES_DIR, "APROG.BIN")
    with open(aprog_path, "rb") as f:
        data = f.read()

    print("Daytona USA (Saturn) - Program Flow Analysis")
    print("=" * 55)
    print("APROG.BIN: %d bytes, base 0x%08X\n" % (len(data), BASE_ADDR))

    # 1. Analyze the entry point (main)
    analyze_function(data, BASE_ADDR, BASE_ADDR, label="main (entry point)")

    # 2. Analyze hw init
    analyze_hw_init(data, BASE_ADDR)

    # 3. Analyze the main game function
    print()
    analyze_function(data, 0x0600A392, BASE_ADDR, label="main_game_func", visited=set())

    # 4. Scan for main loop candidates
    scan_for_main_loop(data, BASE_ADDR)
