"""
analyze_binary.py - Phase 1 binary analysis for Daytona USA Saturn
Parses the Saturn header, analyzes APROG.BIN structure, and scans for
function prologues and data regions.
"""

import struct
import os
import sys

ISO_PATH = os.path.join(os.path.dirname(__file__), "..", "build", "disc", "daytona_data.iso")
FILES_DIR = os.path.join(os.path.dirname(__file__), "..", "build", "disc", "files")

# Saturn Work RAM High starts at 0x06000000
# IP.BIN loads at 0x06002000
# First file typically loads at 0x06004000
WRAM_HIGH_BASE = 0x06000000


def parse_saturn_header(iso_path):
    """Parse the Saturn IP.BIN header from the ISO."""
    with open(iso_path, "rb") as f:
        header = f.read(0x100)

    print("=== Saturn IP.BIN Header ===")
    print("Hardware ID:     %s" % header[0x00:0x10].decode("ascii", errors="replace").strip())
    print("Maker ID:        %s" % header[0x10:0x20].decode("ascii", errors="replace").strip())
    print("Product Number:  %s" % header[0x20:0x30].decode("ascii", errors="replace").strip())
    print("Version:         %s" % header[0x30:0x40].decode("ascii", errors="replace").strip())
    print("Release Date:    %s" % header[0x40:0x50].decode("ascii", errors="replace").strip())
    print("Device Info:     %s" % header[0x50:0x60].decode("ascii", errors="replace").strip())
    print("Compatible Area: %s" % header[0x60:0x70].decode("ascii", errors="replace").strip())
    print("Game Title:      %s" % header[0x70:0xD0].decode("ascii", errors="replace").strip())

    # Dump raw bytes around the first-read-file info area
    print("\nRaw header 0xD0-0x100:")
    for i in range(0xD0, 0x100, 16):
        hex_str = " ".join("%02X" % b for b in header[i:i+16])
        ascii_str = "".join(chr(b) if 32 <= b < 127 else "." for b in header[i:i+16])
        print("  %04X: %s  %s" % (i, hex_str, ascii_str))

    # The IP.BIN itself contains boot code starting at offset 0x100
    # Read the boot code area to find where it loads APROG.BIN
    with open(iso_path, "rb") as f:
        ip_code = f.read(0x1000)

    # Look for the first file load address in IP.BIN
    # Standard Saturn: first file info is at offset 0xE0-0xEF in the header
    # But format varies. Let's check the IP.BIN boot code for common patterns.
    print("\n=== IP.BIN Boot Code (first 64 bytes at 0x100) ===")
    for i in range(0x100, 0x140, 16):
        hex_str = " ".join("%02X" % b for b in ip_code[i:i+16])
        print("  %04X: %s" % (i, hex_str))

    return header


def scan_function_prologues(data, base_addr):
    """
    Scan for GCC 2.6 SH-2 function prologues.
    Pattern: mov.l rN,@-r15 (opcode 2F x6 where x = register number)
    Specifically looking for descending register save order starting with r14.
    """
    prologues = []
    i = 0
    while i < len(data) - 4:
        # mov.l r14,@-r15 = 2F E6
        if data[i] == 0x2F and data[i+1] == 0xE6:
            addr = base_addr + i
            # Check what follows - more register saves or sts.l pr,@-r15 (4F 22)
            saves = ["r14"]
            j = i + 2
            while j < len(data) - 1:
                if data[j] == 0x2F and (data[j+1] & 0x0F) == 0x06:
                    reg = (data[j+1] >> 4) & 0x0F
                    saves.append("r%d" % reg)
                    j += 2
                elif data[j] == 0x4F and data[j+1] == 0x22:
                    # sts.l pr,@-r15
                    saves.append("pr")
                    j += 2
                    break
                else:
                    break
            prologues.append((addr, saves))
        i += 2  # SH-2 instructions are 2 bytes, aligned

    return prologues


def find_strings(data, base_addr, min_length=4):
    """Find printable ASCII strings in binary data."""
    strings = []
    current = []
    start = 0
    for i, b in enumerate(data):
        if 32 <= b < 127:
            if not current:
                start = i
            current.append(chr(b))
        else:
            if len(current) >= min_length:
                strings.append((base_addr + start, "".join(current)))
            current = []
    if len(current) >= min_length:
        strings.append((base_addr + start, "".join(current)))
    return strings


def analyze_code_density(data, base_addr, block_size=0x1000):
    """
    Analyze code vs data density in blocks.
    SH-2 code has characteristic byte patterns; data regions look different.
    We look for instruction-like patterns vs large runs of zeros or ASCII.
    """
    blocks = []
    for offset in range(0, len(data), block_size):
        block = data[offset:offset + block_size]
        if len(block) == 0:
            break

        # Count function prologues (mov.l rN,@-r15)
        prologue_count = 0
        # Count rts instructions (00 0B)
        rts_count = 0
        # Count zero words
        zero_words = 0
        # Count printable ASCII
        ascii_count = 0

        for i in range(0, len(block) - 1, 2):
            word = (block[i] << 8) | block[i+1]
            if block[i] == 0x2F and (block[i+1] & 0x0F) == 0x06:
                prologue_count += 1
            if word == 0x000B:
                rts_count += 1
            if word == 0x0000:
                zero_words += 1
            if 32 <= block[i] < 127:
                ascii_count += 1
            if 32 <= block[i+1] < 127:
                ascii_count += 1

        region_type = "CODE"
        if zero_words > len(block) // 8:
            region_type = "DATA/BSS"
        elif ascii_count > len(block) * 0.6:
            region_type = "STRING"
        elif prologue_count == 0 and rts_count == 0:
            region_type = "DATA"

        blocks.append({
            "offset": offset,
            "addr": base_addr + offset,
            "type": region_type,
            "prologues": prologue_count,
            "rts": rts_count,
            "zeros": zero_words,
            "ascii_pct": ascii_count * 100 // len(block),
        })

    return blocks


def analyze_aprog(files_dir):
    """Analyze the main APROG.BIN program."""
    aprog_path = os.path.join(files_dir, "APROG.BIN")
    with open(aprog_path, "rb") as f:
        data = f.read()

    # APROG.BIN load address - need to determine this from the boot code
    # For now, assume a common Saturn load address
    # The boot code (first file at 0x06004000) loads APROG.BIN to some address
    # Common choices: 0x06004000 (replacing boot code) or 0x06010000
    # We'll determine this from the boot code analysis
    base_addr = 0x06003000  # Confirmed from entry point constant pool

    print("\n=== APROG.BIN Analysis ===")
    print("Size: %d bytes (0x%X)" % (len(data), len(data)))
    print("Assumed base: 0x%08X" % base_addr)
    print("End address:  0x%08X" % (base_addr + len(data)))

    # Scan for function prologues
    print("\n--- Function Prologues (first 30) ---")
    prologues = scan_function_prologues(data, base_addr)
    print("Total prologues found: %d" % len(prologues))
    for addr, saves in prologues[:30]:
        print("  0x%08X: saves %s" % (addr, ", ".join(saves)))

    # Count by save pattern
    patterns = {}
    for addr, saves in prologues:
        key = ", ".join(saves)
        patterns[key] = patterns.get(key, 0) + 1
    print("\n--- Prologue Patterns (by frequency) ---")
    for pattern, count in sorted(patterns.items(), key=lambda x: -x[1])[:20]:
        print("  %3d x  %s" % (count, pattern))

    # Find strings
    print("\n--- Strings (>= 6 chars, first 40) ---")
    strings = find_strings(data, base_addr, min_length=6)
    print("Total strings found: %d" % len(strings))
    for addr, s in strings[:40]:
        display = s[:80] + ("..." if len(s) > 80 else "")
        print("  0x%08X: %s" % (addr, display))

    # Code density analysis
    print("\n--- Code Density Map (4KB blocks) ---")
    blocks = analyze_code_density(data, base_addr)
    print("  Address     Type     Prologues  RTS  Zeros  ASCII%%")
    for b in blocks:
        print("  0x%08X  %-8s  %3d       %3d   %3d    %3d%%" % (
            b["addr"], b["type"], b["prologues"], b["rts"], b["zeros"], b["ascii_pct"]))

    return data, base_addr, prologues, strings


def analyze_overlays(files_dir):
    """Quick analysis of the overlay files."""
    overlays = ["GAMED.BIN", "SLCTD.BIN", "MUSICD.BIN", "MUSIC2D.BIN",
                "MUSIC3D.BIN", "OVERD.BIN", "NAMD.BIN"]

    print("\n=== Overlay Analysis ===")
    for name in overlays:
        path = os.path.join(files_dir, name)
        if not os.path.exists(path):
            print("%s: NOT FOUND" % name)
            continue
        with open(path, "rb") as f:
            data = f.read()

        prologues = scan_function_prologues(data, 0)
        strings = find_strings(data, 0, min_length=6)
        print("\n%s (%d bytes):" % (name, len(data)))
        print("  Function prologues: %d" % len(prologues))
        print("  Strings (>=6 chars): %d" % len(strings))

        # Show first few interesting strings
        interesting = [s for _, s in strings if not s.startswith(" ")][:5]
        for s in interesting:
            print("    \"%s\"" % s[:60])


if __name__ == "__main__":
    print("Daytona USA (Saturn) - Binary Analysis")
    print("=" * 50)

    parse_saturn_header(ISO_PATH)
    analyze_aprog(FILES_DIR)
    analyze_overlays(FILES_DIR)
