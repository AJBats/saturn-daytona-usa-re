"""
find_structs.py - Identify data structures and global variable patterns
Scans for:
1. Global variable addresses (constant pool values in BSS/data regions)
2. Struct access patterns (repeated @(disp,Rn) with varying displacements)
3. Large struct clusters (many globals near each other = likely struct fields)
"""

import struct
import os
from collections import defaultdict

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


def scan_global_refs(data, base_addr):
    """
    Find all 32-bit constant pool values that point to BSS or data regions.
    These are global variable addresses.
    """
    file_end = base_addr + len(data)
    bss_start = file_end  # BSS starts after file data
    bss_end = 0x060FFFFF  # Work RAM High end

    globals_in_bss = defaultdict(int)  # addr -> ref count
    globals_in_data = defaultdict(int)  # addr -> ref count
    globals_in_wram_low = defaultdict(int)

    for i in range(0, len(data) - 1, 2):
        w = read_u16(data, i)
        if w is None:
            continue
        # mov.l @(disp,PC),Rn
        if (w >> 12) == 0xD:
            disp = w & 0xFF
            ins_addr = base_addr + i
            pc_val = (ins_addr & ~3) + 4 + disp * 4
            pool_offset = pc_val - base_addr
            if 0 <= pool_offset < len(data) - 3:
                val = read_u32(data, pool_offset)
                if val is None:
                    continue
                # BSS region
                if bss_start <= val < bss_end:
                    globals_in_bss[val] += 1
                # Data region (within the file but in data areas)
                elif 0x06044000 <= val < file_end:
                    globals_in_data[val] += 1
                # Work RAM Low
                elif 0x00200000 <= val < 0x00300000:
                    globals_in_wram_low[val] += 1

    return globals_in_bss, globals_in_data, globals_in_wram_low


def find_struct_clusters(globals_dict, max_gap=256):
    """
    Find clusters of nearby global addresses that likely form structs.
    A cluster is a group of addresses where each is within max_gap bytes of the next.
    """
    if not globals_dict:
        return []

    sorted_addrs = sorted(globals_dict.keys())
    clusters = []
    current = [sorted_addrs[0]]

    for addr in sorted_addrs[1:]:
        if addr - current[-1] <= max_gap:
            current.append(addr)
        else:
            if len(current) >= 3:  # Only report clusters with 3+ fields
                clusters.append(current)
            current = [addr]
    if len(current) >= 3:
        clusters.append(current)

    return clusters


def analyze_struct_cluster(cluster, globals_dict):
    """Analyze a cluster of global addresses for struct-like patterns."""
    base = cluster[0]
    size = cluster[-1] - base + 4  # Approximate struct size

    fields = []
    for addr in cluster:
        offset = addr - base
        refs = globals_dict[addr]
        fields.append((offset, addr, refs))

    return {
        "base": base,
        "size": size,
        "field_count": len(cluster),
        "fields": fields,
        "total_refs": sum(globals_dict[a] for a in cluster),
    }


def main():
    aprog_path = os.path.join(FILES_DIR, "APROG.BIN")
    with open(aprog_path, "rb") as f:
        data = f.read()

    file_end = BASE_ADDR + len(data)
    print("Daytona USA (Saturn) - Data Structure & Global Variable Analysis")
    print("=" * 65)
    print("File end: 0x%08X, BSS starts: 0x%08X" % (file_end, file_end))

    # Scan for global references
    bss_globals, data_globals, wram_low_globals = scan_global_refs(data, BASE_ADDR)

    print("\n=== Global Variable Summary ===\n")
    print("  BSS globals (uninitialized): %d unique addresses, %d total refs" % (
        len(bss_globals), sum(bss_globals.values())))
    print("  Data globals (initialized):  %d unique addresses, %d total refs" % (
        len(data_globals), sum(data_globals.values())))
    print("  Work RAM Low globals:        %d unique addresses, %d total refs" % (
        len(wram_low_globals), sum(wram_low_globals.values())))

    # Most-referenced BSS globals
    print("\n=== Most-Referenced BSS Globals (top 40) ===\n")
    top_bss = sorted(bss_globals.items(), key=lambda x: -x[1])[:40]
    for addr, count in top_bss:
        print("  0x%08X: %3d references" % (addr, count))

    # BSS struct clusters
    print("\n=== BSS Struct Clusters (groups of nearby globals) ===\n")
    bss_clusters = find_struct_clusters(bss_globals, max_gap=64)
    bss_clusters.sort(key=lambda c: -len(c))

    for i, cluster in enumerate(bss_clusters[:25]):
        info = analyze_struct_cluster(cluster, bss_globals)
        print("Cluster #%d: base 0x%08X, ~%d bytes, %d fields, %d total refs" % (
            i + 1, info["base"], info["size"], info["field_count"], info["total_refs"]))

        # Show fields
        for offset, addr, refs in info["fields"][:20]:
            print("    +0x%04X (0x%08X): %d refs" % (offset, addr, refs))
        if len(info["fields"]) > 20:
            print("    ... +%d more fields" % (len(info["fields"]) - 20))
        print()

    # Data section globals
    print("\n=== Data Section Globals (top 20 by reference count) ===\n")
    top_data = sorted(data_globals.items(), key=lambda x: -x[1])[:20]
    for addr, count in top_data:
        print("  0x%08X: %3d references" % (addr, count))

    # Work RAM Low globals
    if wram_low_globals:
        print("\n=== Work RAM Low Globals (top 20) ===\n")
        top_wram = sorted(wram_low_globals.items(), key=lambda x: -x[1])[:20]
        for addr, count in top_wram:
            print("  0x%08X: %3d references" % (addr, count))

    # Summary statistics
    print("\n=== Struct Size Estimates ===\n")
    print("Largest BSS clusters (potential major game structs):\n")
    size_sorted = sorted(bss_clusters, key=lambda c: -(c[-1] - c[0]))
    for cluster in size_sorted[:10]:
        info = analyze_struct_cluster(cluster, bss_globals)
        print("  0x%08X: ~%d bytes (%d fields, %d refs) — could be %s" % (
            info["base"], info["size"], info["field_count"], info["total_refs"],
            "car state" if info["size"] > 200 else
            "game state" if info["total_refs"] > 100 else
            "subsystem state"))


if __name__ == "__main__":
    main()
