#!/usr/bin/env python3
"""
Generate C files with inline asm for all functions from the original Daytona disc.
Extracts APROG.BIN from Track 01.bin, then generates .c files with .byte directives.
"""

import os
import sys

# APROG.BIN location and size in the disc image
DISC_OFFSET = 49408      # 0xC100 - where APROG.BIN starts in Track 01.bin
APROG_SIZE = 394896      # Size of APROG.BIN
BASE_ADDR = 0x06003000   # Load address in Saturn memory
END_ADDR = 0x06063690    # End of APROG.BIN

def find_disc_track(project_dir):
    """Find the original Track 01.bin from the Daytona disc."""
    track_path = os.path.join(
        project_dir,
        "external_resources",
        "Daytona USA (USA)",
        "Daytona USA (USA) (Track 01).bin"
    )
    if os.path.exists(track_path):
        return track_path
    return None

def extract_aprog_from_disc(track_path):
    """Extract APROG.BIN bytes from the disc track."""
    print("Extracting APROG.BIN from disc...")
    print("  Source: %s" % track_path)
    print("  Offset: 0x%X (%d)" % (DISC_OFFSET, DISC_OFFSET))
    print("  Size: %d bytes" % APROG_SIZE)

    with open(track_path, 'rb') as f:
        f.seek(DISC_OFFSET)
        data = f.read(APROG_SIZE)

    if len(data) != APROG_SIZE:
        print("  ERROR: Only read %d bytes, expected %d" % (len(data), APROG_SIZE))
        return None

    print("  OK")
    return data

def parse_symbols(sym_file):
    """Parse aprog_syms.txt and return sorted list of (name, addr) tuples."""
    symbols = []
    with open(sym_file, 'r') as f:
        for line in f:
            line = line.strip()
            if line.startswith('FUN_') and '=' in line:
                parts = line.rstrip(';').split('=')
                name = parts[0].strip()
                addr = int(parts[1].strip(), 16)
                symbols.append((name, addr))

    symbols.sort(key=lambda x: x[1])
    return symbols

def extract_function_bytes(bin_data, addr, next_addr):
    """Extract bytes for a function from binary data."""
    offset = addr - BASE_ADDR
    if next_addr:
        size = next_addr - addr
    else:
        size = END_ADDR - addr

    if offset < 0 or offset + size > len(bin_data):
        return None

    return bin_data[offset:offset + size]

def generate_c_file(name, func_bytes, output_dir):
    """Generate a C file with inline asm for the function."""
    if not func_bytes:
        return False

    lines = []
    lines.append("void %s()" % name)
    lines.append("{")
    lines.append("    __asm__ volatile (")

    for i in range(0, len(func_bytes), 2):
        if i + 1 < len(func_bytes):
            b1, b2 = func_bytes[i], func_bytes[i+1]
            lines.append('        ".byte 0x%02X, 0x%02X\\n"' % (b1, b2))
        else:
            b1 = func_bytes[i]
            lines.append('        ".byte 0x%02X\\n"' % b1)

    lines.append('        "! .naked\\n"')
    lines.append("    );")
    lines.append("}")
    lines.append("")

    output_path = os.path.join(output_dir, name + ".c")
    with open(output_path, 'w') as f:
        f.write('\n'.join(lines))

    return True

def main():
    script_dir = os.path.dirname(os.path.abspath(__file__))
    project_dir = os.path.dirname(script_dir)

    sym_file = os.path.join(project_dir, "build", "aprog_syms.txt")
    output_dir = os.path.join(project_dir, "build", "gen")

    # Find and extract from original disc
    track_path = find_disc_track(project_dir)
    if not track_path:
        print("Error: Original disc not found at:")
        print("  external_resources/Daytona USA (USA)/Daytona USA (USA) (Track 01).bin")
        sys.exit(1)

    bin_data = extract_aprog_from_disc(track_path)
    if not bin_data:
        sys.exit(1)

    print("Binary size: %d bytes" % len(bin_data))

    # Check symbols file
    if not os.path.exists(sym_file):
        print("Error: %s not found" % sym_file)
        sys.exit(1)

    os.makedirs(output_dir, exist_ok=True)

    print("Parsing symbols...")
    symbols = parse_symbols(sym_file)
    print("Found %d functions" % len(symbols))

    print("Generating C files...")
    generated = 0
    for i, (name, addr) in enumerate(symbols):
        next_addr = symbols[i + 1][1] if i + 1 < len(symbols) else None
        func_bytes = extract_function_bytes(bin_data, addr, next_addr)

        if func_bytes and generate_c_file(name, func_bytes, output_dir):
            generated += 1
            if generated % 100 == 0:
                print("  Generated %d files..." % generated)

    print("Done! Generated %d C files in %s" % (generated, output_dir))

if __name__ == "__main__":
    main()
