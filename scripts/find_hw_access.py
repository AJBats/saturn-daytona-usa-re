"""
find_hw_access.py - Find Saturn hardware register references in APROG.BIN
Scans constant pool entries for addresses in known hardware register ranges.
"""

import struct
import os

FILES_DIR = os.path.join(os.path.dirname(__file__), "..", "build", "disc", "files")
BASE_ADDR = 0x06003000

# Saturn hardware register ranges
HW_REGIONS = [
    (0x25D00000, 0x25D00FFF, "VDP1 registers"),
    (0x25C00000, 0x25C7FFFF, "VDP1 VRAM"),
    (0x25C80000, 0x25CFFFFF, "VDP1 framebuffer"),
    (0x25E00000, 0x25EFFFFF, "VDP2 VRAM"),
    (0x25F00000, 0x25F00FFF, "VDP2 color RAM"),
    (0x25F80000, 0x25F8011F, "VDP2 registers"),
    (0x25FE0000, 0x25FE00CF, "SCU registers"),
    (0x25FE0080, 0x25FE009F, "SCU DMA"),
    (0x25FE00A0, 0x25FE00AF, "SCU DSP"),
    (0x25FE00B0, 0x25FE00BF, "SCU timer"),
    (0x25A00000, 0x25A7FFFF, "SCSP (sound) RAM"),
    (0x25B00000, 0x25B00FFF, "SCSP registers"),
    (0x20100000, 0x2017FFFF, "SMPC registers"),
    (0xFFFFFE00, 0xFFFFFFFF, "SH2 on-chip registers"),
    (0xFFFFFE10, 0xFFFFFE1F, "SH2 DMAC"),
    (0xFFFFFE80, 0xFFFFFE8F, "SH2 timers (FRT)"),
    (0xFFFFFE90, 0xFFFFFE9F, "SH2 serial (SCI)"),
    (0xFFFFFEE0, 0xFFFFFEEF, "SH2 bus state controller"),
    (0xFFFFFFA0, 0xFFFFFFBF, "SH2 cache address array"),
    (0x20000000, 0x200FFFFF, "CS0 (cartridge/expansion)"),
    (0x22000000, 0x23FFFFFF, "CS1 (expansion)"),
    (0x00200000, 0x002FFFFF, "Work RAM Low"),
    (0x06000000, 0x060FFFFF, "Work RAM High"),
]


def read_u32(data, offset):
    if offset + 3 >= len(data):
        return None
    return struct.unpack_from(">I", data, offset)[0]


def classify_address(addr):
    """Classify a 32-bit address into a hardware region."""
    for start, end, name in HW_REGIONS:
        if start <= addr <= end:
            return name
    return None


def find_nearby_function(data, base_addr, addr):
    offset = addr - base_addr
    for i in range(offset, max(0, offset - 2000), -2):
        if i + 1 < len(data):
            if data[i] == 0x2F and data[i + 1] == 0xE6:
                return base_addr + i
            if data[i] == 0x4F and data[i + 1] == 0x22:
                return base_addr + i
    return None


def main():
    aprog_path = os.path.join(FILES_DIR, "APROG.BIN")
    with open(aprog_path, "rb") as f:
        data = f.read()

    print("Daytona USA (Saturn) - Hardware Access Pattern Analysis")
    print("=" * 60)

    # Scan all constant pool entries (mov.l @(disp,PC),Rn)
    hw_refs = {}  # region_name -> list of (ins_addr, hw_addr, func_addr)

    for i in range(0, len(data) - 1, 2):
        w = (data[i] << 8) | data[i + 1]
        if (w >> 12) == 0xD:  # mov.l @(disp,PC),Rn
            disp = w & 0xFF
            ins_addr = BASE_ADDR + i
            pc_val = (ins_addr & ~3) + 4 + disp * 4
            pool_offset = pc_val - BASE_ADDR
            if 0 <= pool_offset < len(data) - 3:
                pool_val = read_u32(data, pool_offset)
                if pool_val is not None:
                    region = classify_address(pool_val)
                    if region and region not in ("Work RAM High", "Work RAM Low"):
                        func_addr = find_nearby_function(data, BASE_ADDR, ins_addr)
                        if region not in hw_refs:
                            hw_refs[region] = []
                        hw_refs[region].append((ins_addr, pool_val, func_addr))

    # Print results by hardware region
    print("\n=== Hardware Register References by Region ===\n")
    for region in sorted(hw_refs.keys()):
        refs = hw_refs[region]
        unique_addrs = sorted(set(r[1] for r in refs))
        unique_funcs = sorted(set(r[2] for r in refs if r[2]))

        print("--- %s (%d references, %d unique addresses, %d functions) ---" % (
            region, len(refs), len(unique_addrs), len(unique_funcs)))

        # Show unique hardware addresses accessed
        for addr in unique_addrs[:30]:
            count = sum(1 for r in refs if r[1] == addr)
            print("    0x%08X (%d refs)" % (addr, count))

        # Show functions that access this region
        if len(unique_funcs) <= 15:
            print("  Functions:")
            for f in unique_funcs:
                print("    0x%08X" % f)
        else:
            print("  Functions: %d total (first 15):" % len(unique_funcs))
            for f in unique_funcs[:15]:
                print("    0x%08X" % f)
        print()

    # Summary statistics
    print("\n=== Summary ===\n")
    total_hw_refs = sum(len(v) for v in hw_refs.items())
    print("Total hardware regions accessed: %d" % len(hw_refs))
    for region in sorted(hw_refs.keys()):
        refs = hw_refs[region]
        funcs = set(r[2] for r in refs if r[2])
        print("  %-30s %3d refs, %3d unique addrs, %2d functions" % (
            region, len(refs), len(set(r[1] for r in refs)), len(funcs)))

    # Special analysis: VDP1 and VDP2 functions (rendering)
    print("\n=== VDP1/VDP2 Functions (rendering-related) ===\n")
    vdp_funcs = set()
    for region in hw_refs:
        if "VDP" in region:
            for _, _, func in hw_refs[region]:
                if func:
                    vdp_funcs.add(func)
    print("Functions that access VDP1 or VDP2: %d" % len(vdp_funcs))
    for f in sorted(vdp_funcs):
        print("  0x%08X" % f)

    # SCU functions (DMA, interrupts)
    print("\n=== SCU Functions (DMA, interrupts) ===\n")
    scu_funcs = set()
    for region in hw_refs:
        if "SCU" in region:
            for _, _, func in hw_refs[region]:
                if func:
                    scu_funcs.add(func)
    print("Functions that access SCU: %d" % len(scu_funcs))
    for f in sorted(scu_funcs):
        print("  0x%08X" % f)

    # SH2 on-chip (timer, DMA, interrupts)
    print("\n=== SH2 On-Chip Register Functions ===\n")
    sh2_funcs = set()
    for region in hw_refs:
        if "SH2" in region:
            for _, _, func in hw_refs[region]:
                if func:
                    sh2_funcs.add(func)
    print("Functions that access SH2 on-chip: %d" % len(sh2_funcs))
    for f in sorted(sh2_funcs):
        print("  0x%08X" % f)


if __name__ == "__main__":
    main()
