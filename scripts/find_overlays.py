"""
find_overlays.py - Find overlay loading references in APROG.BIN
Searches for filename strings and traces which functions reference them.
"""

import struct
import os

FILES_DIR = os.path.join(os.path.dirname(__file__), "..", "build", "disc", "files")
BASE_ADDR = 0x06003000


def read_u32(data, offset):
    if offset + 3 >= len(data):
        return None
    return struct.unpack_from(">I", data, offset)[0]


def find_string_in_binary(data, target):
    """Find all occurrences of a string in the binary data."""
    encoded = target.encode("ascii")
    results = []
    pos = 0
    while True:
        pos = data.find(encoded, pos)
        if pos == -1:
            break
        results.append(pos)
        pos += 1
    return results


def find_addr_references(data, base_addr, target_addr):
    """Find all 32-bit values in data that equal target_addr."""
    refs = []
    for i in range(0, len(data) - 3, 4):
        val = read_u32(data, i)
        if val == target_addr:
            refs.append(base_addr + i)
    return refs


def find_pc_relative_refs(data, base_addr, target_addr):
    """
    Find mov.l @(disp,PC),Rn instructions that load target_addr.
    These are the instructions that reference the constant pool entries.
    """
    refs = []
    for i in range(0, len(data) - 1, 2):
        w = (data[i] << 8) | data[i + 1]
        # mov.l @(disp,PC),Rn: 1101 nnnn dddddddd
        if (w >> 12) == 0xD:
            disp = w & 0xFF
            addr = base_addr + i
            pc_val = (addr & ~3) + 4 + disp * 4
            pool_offset = pc_val - base_addr
            if 0 <= pool_offset < len(data) - 3:
                pool_val = read_u32(data, pool_offset)
                if pool_val == target_addr:
                    rn = (w >> 8) & 0xF
                    refs.append((addr, rn, pc_val))
    return refs


def find_nearby_function(data, base_addr, addr):
    """
    Find the function containing a given address by scanning backward
    for a function prologue.
    """
    offset = addr - base_addr
    # Scan backward for mov.l r14,@-r15 (2F E6) or sts.l pr,@-r15 (4F 22)
    for i in range(offset, max(0, offset - 2000), -2):
        if i + 1 < len(data):
            if data[i] == 0x2F and data[i + 1] == 0xE6:
                return base_addr + i
            # Some functions start with sts.l pr,@-r15 without frame pointer
            if data[i] == 0x4F and data[i + 1] == 0x22:
                return base_addr + i
    return None


def main():
    aprog_path = os.path.join(FILES_DIR, "APROG.BIN")
    with open(aprog_path, "rb") as f:
        data = f.read()

    print("Daytona USA (Saturn) - Overlay Loading Analysis")
    print("=" * 55)

    # All known filenames from the disc
    filenames = [
        "APROG.BIN",
        "GAMED.BIN", "GAME0.BIN", "GAME1.BIN",
        "SLCTD.BIN",
        "OVERD.BIN", "OVER0.BIN",
        "NAMD.BIN",
        "MUSICD.BIN", "MUSIC2D.BIN", "MUSIC3D.BIN",
        "TEX_PL.BIN", "TEX_C1.BIN", "TEX_C2.BIN",
        "POLYGON.BIN", "SCROLL.BIN",
        "TABLE.BIN", "PIT.BIN", "SOUNDS.BIN",
        "COURSE0.BIN", "COURSE1.BIN", "COURSE2.BIN",
    ]

    print("\n=== Filename Strings in APROG.BIN ===\n")
    string_locations = {}
    for name in filenames:
        positions = find_string_in_binary(data, name)
        if positions:
            addrs = [BASE_ADDR + p for p in positions]
            string_locations[name] = addrs
            print("  %-15s found at %s" % (
                name, ", ".join("0x%08X" % a for a in addrs)))
        else:
            # Try without .BIN extension
            base_name = name.replace(".BIN", "")
            positions = find_string_in_binary(data, base_name)
            if positions and len(base_name) >= 4:
                addrs = [BASE_ADDR + p for p in positions]
                string_locations[name] = addrs
                print("  %-15s found as '%s' at %s" % (
                    name, base_name,
                    ", ".join("0x%08X" % a for a in addrs)))

    # Also search for common filename patterns
    for pattern in ["GAME", "SLCT", "OVER", "NAM", "MUSIC", "TEX_", "COURSE",
                     "POLYGON", "SCROLL", "TABLE", "SOUNDS", "PIT",
                     ".BIN", ":\\", "CDROM"]:
        positions = find_string_in_binary(data, pattern)
        if positions and pattern not in [n.replace(".BIN", "") for n in filenames]:
            # Only show if not already covered
            if len(positions) <= 10:
                print("  %-15s found at %s" % (
                    "'%s'" % pattern,
                    ", ".join("0x%08X" % (BASE_ADDR + p) for p in positions[:5])))
            else:
                print("  %-15s found %d times" % ("'%s'" % pattern, len(positions)))

    # For each found string, trace back to find which functions reference it
    print("\n=== Functions That Reference Overlay Filenames ===\n")

    overlay_names = ["GAMED.BIN", "GAME0.BIN", "GAME1.BIN", "SLCTD.BIN",
                     "OVERD.BIN", "OVER0.BIN", "NAMD.BIN",
                     "MUSICD.BIN", "MUSIC2D.BIN", "MUSIC3D.BIN"]

    for name in overlay_names:
        if name not in string_locations:
            continue

        print("--- %s ---" % name)
        for str_addr in string_locations[name]:
            print("  String at 0x%08X" % str_addr)

            # Find constant pool entries that contain the string address
            pool_refs = find_addr_references(data, BASE_ADDR, str_addr)
            if pool_refs:
                print("  Referenced by constant pool at: %s" % (
                    ", ".join("0x%08X" % r for r in pool_refs)))

            # Find mov.l instructions that load the string address
            pc_refs = find_pc_relative_refs(data, BASE_ADDR, str_addr)
            for ins_addr, reg, pool_addr in pc_refs:
                func_addr = find_nearby_function(data, BASE_ADDR, ins_addr)
                print("  mov.l @(PC),r%d at 0x%08X (pool: 0x%08X) -> in function 0x%08X" % (
                    reg, ins_addr, pool_addr, func_addr or 0))
        print()

    # Also look for CD read / file loading system calls
    print("\n=== CD/File Loading Function Detection ===\n")
    print("Looking for functions that both reference filenames AND call BIOS/CD functions...\n")

    # Common Saturn BIOS CD read functions are at fixed addresses in the BIOS ROM.
    # But AM2 likely wraps these. Look for functions that reference both
    # filename strings and addresses in the 0x0600026x range (BIOS calls we saw earlier)

    # Also look for the GFS (Game File System) or CDC patterns
    for pattern in ["GFS_", "CDC_", "SYS_", "cd_", "gfs_", "cdc_"]:
        positions = find_string_in_binary(data, pattern)
        if positions:
            print("  '%s' found %d times" % (pattern, len(positions)))
            for p in positions[:5]:
                # Show context
                ctx = data[p:p+40]
                s = ctx.split(b'\x00')[0].decode('ascii', errors='replace')
                print("    0x%08X: \"%s\"" % (BASE_ADDR + p, s))


if __name__ == "__main__":
    main()
