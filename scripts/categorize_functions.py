"""
categorize_functions.py - Categorize all functions in APROG.BIN
Uses hardware access patterns, call graph, and code region to classify
functions into: rendering, sound, input, system, file_loading, gameplay_candidate, unknown
"""

import struct
import os

FILES_DIR = os.path.join(os.path.dirname(__file__), "..", "build", "disc", "files")
BASE_ADDR = 0x06003000


def read_u16(data, offset):
    if offset + 1 >= len(data):
        return None
    return (data[offset] << 8) | data[offset + 1]


def read_u32(data, offset):
    if offset + 3 >= len(data):
        return None
    return struct.unpack_from(">I", data, offset)[0]


def find_all_functions(data, base_addr):
    """Find all function entry points via prologue scanning."""
    funcs = []
    i = 0
    while i < len(data) - 4:
        # mov.l r14,@-r15 = 2F E6 (standard GCC frame pointer save)
        if data[i] == 0x2F and data[i + 1] == 0xE6:
            funcs.append(base_addr + i)
            i += 2
            continue
        # sts.l pr,@-r15 = 4F 22 (some functions skip frame pointer)
        if data[i] == 0x4F and data[i + 1] == 0x22:
            # Only count as function start if not preceded by another push
            if i >= 2:
                prev = read_u16(data, i - 2)
                if prev is not None:
                    ph = (prev >> 12) & 0xF
                    # If previous was mov.l rN,@-r15, this isn't a new function
                    if ph == 0x2 and (prev >> 8) & 0xF == 0xF and (prev & 0xF) == 0x6:
                        i += 2
                        continue
            funcs.append(base_addr + i)
        i += 2
    return funcs


def get_function_hw_accesses(data, base_addr, func_addr, max_search=1000):
    """Get hardware regions accessed by a function (via constant pool loads)."""
    offset = func_addr - base_addr
    hw = set()
    for i in range(offset, min(offset + max_search, len(data) - 1), 2):
        w = read_u16(data, i)
        if w is None:
            break
        # rts = end of function
        if w == 0x000B:
            break
        # mov.l @(disp,PC),Rn
        if (w >> 12) == 0xD:
            disp = w & 0xFF
            ins_addr = base_addr + i
            pc_val = (ins_addr & ~3) + 4 + disp * 4
            pool_offset = pc_val - base_addr
            if 0 <= pool_offset < len(data) - 3:
                val = read_u32(data, pool_offset)
                if val is not None:
                    if 0x25D00000 <= val <= 0x25DFFFFF:
                        hw.add("VDP1_REG")
                    elif 0x25C00000 <= val <= 0x25CFFFFF:
                        hw.add("VDP1_VRAM")
                    elif 0x25E00000 <= val <= 0x25EFFFFF:
                        hw.add("VDP2_VRAM")
                    elif 0x25F00000 <= val <= 0x25F0FFFF:
                        hw.add("VDP2_CRAM")
                    elif 0x25F80000 <= val <= 0x25F801FF:
                        hw.add("VDP2_REG")
                    elif 0x25FE0000 <= val <= 0x25FE00FF:
                        hw.add("SCU")
                    elif 0x25A00000 <= val <= 0x25A7FFFF:
                        hw.add("SCSP_RAM")
                    elif 0x25B00000 <= val <= 0x25B00FFF:
                        hw.add("SCSP_REG")
                    elif 0x20100000 <= val <= 0x2017FFFF:
                        hw.add("SMPC")
                    elif 0xFFFFFE00 <= val <= 0xFFFFFFFF:
                        hw.add("SH2_ONCHIP")
    return hw


def get_function_calls(data, base_addr, func_addr, max_search=1000):
    """Get call targets from a function."""
    offset = func_addr - base_addr
    calls = []
    reg_vals = {}

    for i in range(offset, min(offset + max_search, len(data) - 1), 2):
        w = read_u16(data, i)
        if w is None:
            break
        if w == 0x000B:  # rts
            break

        ins_addr = base_addr + i

        # mov.l @(disp,PC),Rn
        if (w >> 12) == 0xD:
            disp = w & 0xFF
            rn = (w >> 8) & 0xF
            pc_val = (ins_addr & ~3) + 4 + disp * 4
            pool_offset = pc_val - base_addr
            if 0 <= pool_offset < len(data) - 3:
                val = read_u32(data, pool_offset)
                if val is not None:
                    reg_vals[rn] = val

        # jsr @Rn
        elif (w >> 8) & 0xFF == 0x4 and (w & 0xFF) == 0x0B:
            # Actually: 0100 nnnn 0000 1011
            rn = (w >> 8) & 0xF
            target = reg_vals.get(rn)
            if target is not None:
                calls.append(target)

        # bsr disp
        elif (w >> 12) == 0xB:
            disp = w & 0xFFF
            if disp & 0x800:
                disp |= ~0xFFF
            target = ins_addr + 4 + disp * 2
            calls.append(target)

    return calls


def categorize_function(func_addr, hw_access, calls, all_hw_funcs, known_categories):
    """Categorize a function based on its hardware access and call patterns."""
    # Direct hardware access
    if hw_access & {"VDP1_REG", "VDP1_VRAM", "VDP2_VRAM", "VDP2_CRAM", "VDP2_REG"}:
        return "rendering"
    if hw_access & {"SCSP_RAM", "SCSP_REG"}:
        return "sound"
    if hw_access & {"SMPC"}:
        return "input"
    if hw_access & {"SCU"}:
        return "system_dma"
    if hw_access & {"SH2_ONCHIP"}:
        return "system_hw"

    # Known functions
    if func_addr in known_categories:
        return known_categories[func_addr]

    # Check if this function only calls rendering/sound/etc functions
    if calls:
        callee_cats = set()
        for c in calls:
            if c in all_hw_funcs:
                callee_cats.add(all_hw_funcs[c])
        if callee_cats == {"rendering"}:
            return "rendering_helper"
        if callee_cats == {"sound"}:
            return "sound_helper"

    return "unknown"


def main():
    aprog_path = os.path.join(FILES_DIR, "APROG.BIN")
    with open(aprog_path, "rb") as f:
        data = f.read()

    print("Daytona USA (Saturn) - Function Categorization")
    print("=" * 55)

    # Find all functions
    all_funcs = find_all_functions(data, BASE_ADDR)
    print("\nTotal functions found: %d" % len(all_funcs))

    # Known function categories from our analysis
    known = {
        0x06003000: "entry_point",
        0x060030FC: "hw_init",
        0x0600A392: "main_game_func",
        0x06020BCE: "state_dispatcher",
        0x06012E6A: "file_loading",
    }

    # Categorize each function
    categories = {}
    hw_map = {}  # func -> category for hw-accessing functions

    for func in all_funcs:
        hw = get_function_hw_accesses(data, BASE_ADDR, func)
        calls = get_function_calls(data, BASE_ADDR, func)
        cat = categorize_function(func, hw, calls, hw_map, known)
        categories[func] = cat
        if cat in ("rendering", "sound", "input", "system_dma", "system_hw"):
            hw_map[func] = cat

    # Count by category
    cat_counts = {}
    for func, cat in categories.items():
        cat_counts[cat] = cat_counts.get(cat, 0) + 1

    print("\n=== Function Categories ===\n")
    for cat in sorted(cat_counts.keys(), key=lambda x: -cat_counts[x]):
        print("  %-20s %4d functions" % (cat, cat_counts[cat]))

    # Show address ranges per category
    print("\n=== Category Address Ranges ===\n")
    for cat in ["rendering", "sound", "input", "system_dma", "system_hw",
                "rendering_helper", "sound_helper", "file_loading", "unknown"]:
        funcs_in_cat = sorted(f for f, c in categories.items() if c == cat)
        if not funcs_in_cat:
            continue

        # Find clusters (groups of functions within 0x200 of each other)
        clusters = []
        current_cluster = [funcs_in_cat[0]]
        for f in funcs_in_cat[1:]:
            if f - current_cluster[-1] < 0x200:
                current_cluster.append(f)
            else:
                clusters.append(current_cluster)
                current_cluster = [f]
        clusters.append(current_cluster)

        print("  %s (%d functions, %d clusters):" % (cat, len(funcs_in_cat), len(clusters)))
        for cluster in clusters[:10]:
            if len(cluster) == 1:
                print("    0x%08X" % cluster[0])
            else:
                print("    0x%08X - 0x%08X (%d functions)" % (
                    cluster[0], cluster[-1], len(cluster)))
        if len(clusters) > 10:
            print("    ... and %d more clusters" % (len(clusters) - 10))
        print()

    # The "unknown" functions are potential gameplay candidates
    # Show how many of the unknown functions are in different address ranges
    unknowns = sorted(f for f, c in categories.items() if c == "unknown")
    print("\n=== Unknown Functions by Address Range (gameplay candidates) ===\n")
    ranges = [
        (0x06003000, 0x06010000, "0x06003-0x06010"),
        (0x06010000, 0x06020000, "0x06010-0x06020"),
        (0x06020000, 0x06030000, "0x06020-0x06030"),
        (0x06030000, 0x06040000, "0x06030-0x06040"),
        (0x06040000, 0x06064000, "0x06040-0x06064"),
    ]
    for start, end, label in ranges:
        count = sum(1 for f in unknowns if start <= f < end)
        hw_count = sum(1 for f, c in categories.items()
                      if start <= f < end and c != "unknown")
        total = sum(1 for f in all_funcs if start <= f < end)
        print("  %s: %3d unknown / %3d total  (%3d hw-accessing)" % (
            label, count, total, hw_count))

    # Cross-reference: which of the "main loop candidates" are unknown (potential gameplay)?
    print("\n=== Main Loop Candidates - Category Check ===\n")
    candidates = [
        0x0601F9CC, 0x0601B160, 0x060116A8, 0x06011AF4,
        0x06003578, 0x060092D0, 0x06012DB4,
    ]
    for addr in candidates:
        cat = categories.get(addr, "not found as function")
        # Also check what it calls
        calls = get_function_calls(data, BASE_ADDR, addr)
        hw_calls = sum(1 for c in calls if c in hw_map)
        non_hw_calls = len(calls) - hw_calls
        print("  0x%08X: %-20s (calls %d hw, %d non-hw functions)" % (
            addr, cat, hw_calls, non_hw_calls))


if __name__ == "__main__":
    main()
