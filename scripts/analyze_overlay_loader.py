"""
analyze_overlay_loader.py - Deep analysis of FUN_06012E6A (overlay loader)
Disassemble the function and trace how it decides which overlay to load.
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

def hexdump(data, base_addr, offset, length):
    """Hex dump a section of the binary."""
    for i in range(offset, min(offset + length, len(data)), 16):
        addr = base_addr + i
        hex_bytes = " ".join("%02X" % data[i+j] for j in range(min(16, len(data) - i)))
        ascii_str = "".join(
            chr(data[i+j]) if 32 <= data[i+j] < 127 else "."
            for j in range(min(16, len(data) - i)))
        print("  %08X: %-48s %s" % (addr, hex_bytes, ascii_str))


def main():
    aprog_path = os.path.join(FILES_DIR, "APROG.BIN")
    with open(aprog_path, "rb") as f:
        data = f.read()

    print("Daytona USA - Overlay Loader Analysis (FUN_06012E6A)")
    print("=" * 60)

    # The filename table is at 0x06044900-0x06044A60
    # Let's dump it to see the full structure
    print("\n=== Filename Table (0x06044900 - 0x06044A60) ===\n")
    table_offset = 0x06044900 - BASE_ADDR
    hexdump(data, BASE_ADDR, table_offset, 0x160)

    # Now let's look at the structure more carefully.
    # The filenames appear to be in a structured array.
    # Let's find what's between filenames — there might be metadata.
    print("\n=== Filename String Table Analysis ===\n")
    filenames = [
        (0x0604491C, "COURSE1.BIN"),
        (0x06044938, "COURSE2.BIN"),
        (0x06044954, "COURSE0.BIN"),
        (0x06044960, "TEX_PL.BIN"),
        (0x0604496C, "TEX_C1.BIN"),
        (0x06044978, "TEX_C2.BIN"),
        (0x06044990, "SCROLL.BIN"),
        (0x0604499C, "TABLE.BIN"),
        (0x060449A8, "POLYGON.BIN"),
        (0x060449B4, "PIT.BIN"),
        (0x060449BC, "SOUNDS.BIN"),
        (0x060449C8, "APROG.BIN"),
        (0x060449D4, "GAMED.BIN"),
        (0x060449E0, "GAME0.BIN"),
        (0x060449EC, "SLCTD.BIN"),
        (0x06044A04, "OVERD.BIN"),
        (0x06044A10, "OVER0.BIN"),
        (0x06044A1C, "NAMD.BIN"),
        (0x06044A34, "MUSICD.BIN"),
        (0x06044A40, "MUSIC2D.BIN"),
        (0x06044A4C, "MUSIC3D.BIN"),
    ]

    # Look at the bytes BEFORE and between filenames to find structure
    prev_end = None
    for addr, name in filenames:
        offset = addr - BASE_ADDR
        strlen = len(name)
        if prev_end is not None:
            gap = offset - prev_end
            if gap > 0:
                gap_data = data[prev_end:offset]
                hex_str = " ".join("%02X" % b for b in gap_data[:20])
                print("  gap (%d bytes): %s" % (gap, hex_str))
        print("  0x%08X: \"%s\" [%d bytes + null]" % (addr, name, strlen))
        prev_end = offset + strlen + 1  # +1 for null terminator

    # Now look at the function FUN_06012E6A itself
    # Let's dump its raw hex and surroundings
    func_offset = 0x06012E6A - BASE_ADDR
    print("\n=== FUN_06012E6A Raw Hex (overlay loader) ===\n")
    # This function's constant pool entries go up to ~0x06012F80
    hexdump(data, BASE_ADDR, func_offset, 0x120)

    # Check what calls FUN_06012E6A
    print("\n=== Who calls FUN_06012E6A? ===\n")
    target_addr = 0x06012E6A
    # Search for constant pool entries containing this address
    for i in range(0, len(data) - 3, 4):
        val = read_u32(data, i)
        if val == target_addr:
            pool_addr = BASE_ADDR + i
            # Now find mov.l @(disp,PC),Rn that references this pool entry
            for j in range(0, len(data) - 1, 2):
                w = read_u16(data, j)
                if w is not None and (w >> 12) == 0xD:
                    disp = w & 0xFF
                    ins_addr = BASE_ADDR + j
                    pc_val = (ins_addr & ~3) + 4 + disp * 4
                    if pc_val == pool_addr:
                        print("  Pool entry at 0x%08X, referenced by mov.l at 0x%08X" % (
                            pool_addr, ins_addr))

    # Also search for bsr to this address
    for i in range(0, len(data) - 1, 2):
        w = read_u16(data, i)
        if w is not None and (w >> 12) == 0xB:  # bsr
            disp = w & 0xFFF
            if disp & 0x800:
                disp = disp | ~0xFFF
            ins_addr = BASE_ADDR + i
            bsr_target = ins_addr + 4 + disp * 2
            if bsr_target == target_addr:
                print("  bsr at 0x%08X -> 0x%08X" % (ins_addr, target_addr))

    # Look for the overlay LOAD ADDRESS — where do overlays get loaded in memory?
    # Search for common overlay load addresses in the constant pool near FUN_06012E6A
    print("\n=== Constant Pool Values near FUN_06012E6A ===\n")
    # The constant pool for this function starts after its code
    # Based on the references, it spans 0x06012EE8 - 0x06012F80
    pool_start = 0x06012EE8 - BASE_ADDR
    pool_end = 0x06012F80 - BASE_ADDR
    print("  Constant pool entries (32-bit values):")
    for i in range(pool_start, pool_end, 4):
        val = read_u32(data, i)
        if val is not None:
            addr = BASE_ADDR + i
            note = ""
            if 0x06000000 <= val <= 0x060FFFFF:
                note = " [Work RAM High]"
            elif 0x00200000 <= val <= 0x002FFFFF:
                note = " [Work RAM Low]"
            elif 0x25A00000 <= val <= 0x25FFFFFF:
                note = " [VDP/HW]"
            elif 0x06044000 <= val <= 0x06044FFF:
                note = " [filename table]"
            print("    0x%08X: 0x%08X%s" % (addr, val, note))

    # Look at what's near the GAME filenames — is there a mode table?
    # There might be a table like: { mode_id, filename_ptr, load_addr }
    print("\n=== Possible Mode/Overlay Dispatch Table ===\n")
    print("Looking near 0x060449C8 (GAMED.BIN string) for structured data...\n")
    # Check what's before the filename table
    pre_table = 0x06044880 - BASE_ADDR
    hexdump(data, BASE_ADDR, pre_table, 0xA0)


if __name__ == "__main__":
    main()
