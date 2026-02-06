#!/usr/bin/env python3
"""
Generate hybrid C files: real C for specified functions, inline asm for rest.
Extracts APROG.BIN from Track 01.bin, uses real C source for functions that
either PASS the test harness or are specified via --use-c-funcs.

Usage:
    python gen_hybrid_funcs.py                    # Use only PASS functions
    python gen_hybrid_funcs.py --use-c-funcs file.txt  # Add functions from file
    python gen_hybrid_funcs.py --all-src          # Use ALL src/*.c files
"""

import os
import sys
import shutil
import subprocess
import argparse

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
    with open(track_path, 'rb') as f:
        f.seek(DISC_OFFSET)
        data = f.read(APROG_SIZE)
    if len(data) != APROG_SIZE:
        return None
    print("  OK (%d bytes)" % len(data))
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

def get_pass_functions(project_dir):
    """Run test harness and get list of PASS functions."""
    print("Running test harness to find PASS functions...")

    # Run test harness via WSL
    cmd = ['wsl', '-d', 'Ubuntu', '--', 'bash',
           '/mnt/d/Projects/SaturnReverseTest/tools/test_harness.sh']

    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=300)
        output = result.stdout + result.stderr
    except Exception as e:
        print("  Warning: Could not run test harness: %s" % e)
        return set()

    pass_funcs = set()
    for line in output.split('\n'):
        if line.startswith('PASS'):
            parts = line.split()
            if len(parts) >= 2:
                # Extract function name (e.g., "FUN_060058FA")
                func_name = parts[1].upper()  # Normalize to uppercase
                pass_funcs.add(func_name)

    print("  Found %d PASS functions" % len(pass_funcs))
    return pass_funcs

def find_src_file(project_dir, func_name):
    """Find the source C file for a function (case-insensitive)."""
    src_dir = os.path.join(project_dir, "src")

    # Try exact match first
    exact_path = os.path.join(src_dir, func_name + ".c")
    if os.path.exists(exact_path):
        return exact_path

    # Try lowercase
    lower_path = os.path.join(src_dir, func_name.lower() + ".c")
    if os.path.exists(lower_path):
        return lower_path

    # Try case-insensitive search
    if os.path.exists(src_dir):
        for f in os.listdir(src_dir):
            if f.lower() == func_name.lower() + ".c":
                return os.path.join(src_dir, f)

    return None

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

def generate_asm_c_file(name, func_bytes, output_path):
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

    with open(output_path, 'w') as f:
        f.write('\n'.join(lines))

    return True

def copy_src_file(src_path, output_path):
    """Copy source C file to output directory."""
    shutil.copy2(src_path, output_path)
    return True

def load_func_list(filepath):
    """Load function names from a file (one per line)."""
    funcs = set()
    with open(filepath, 'r') as f:
        for line in f:
            line = line.strip()
            if line and not line.startswith('#'):
                # Normalize to uppercase
                funcs.add(line.upper())
    return funcs

def get_all_src_funcs(project_dir):
    """Get all function names that have .c files in src/."""
    src_dir = os.path.join(project_dir, "src")
    funcs = set()
    if os.path.exists(src_dir):
        for f in os.listdir(src_dir):
            if f.startswith('FUN_') and f.endswith('.c'):
                funcs.add(f[:-2].upper())  # Remove .c and uppercase
    return funcs

def main():
    parser = argparse.ArgumentParser(description='Generate hybrid C files for Daytona build')
    parser.add_argument('--use-c-funcs', metavar='FILE',
                        help='File with additional functions to use real C for')
    parser.add_argument('--all-src', action='store_true',
                        help='Use real C for ALL functions that have src/*.c files')
    parser.add_argument('--pass-only', action='store_true',
                        help='Only use PASS functions (default behavior)')
    args = parser.parse_args()

    script_dir = os.path.dirname(os.path.abspath(__file__))
    project_dir = os.path.dirname(script_dir)

    sym_file = os.path.join(project_dir, "build", "aprog_syms_merged.txt")
    output_dir = os.path.join(project_dir, "build", "gen")
    src_dir = os.path.join(project_dir, "src")

    # Find and extract from original disc
    track_path = find_disc_track(project_dir)
    if not track_path:
        print("Error: Original disc not found")
        sys.exit(1)

    bin_data = extract_aprog_from_disc(track_path)
    if not bin_data:
        sys.exit(1)

    # Check symbols file
    if not os.path.exists(sym_file):
        print("Error: %s not found" % sym_file)
        sys.exit(1)

    # Determine which functions to use real C for
    c_funcs = set()

    if args.all_src:
        # Use ALL src/*.c files
        c_funcs = get_all_src_funcs(project_dir)
        print("Using ALL src/*.c files: %d functions" % len(c_funcs))
    else:
        # Start with PASS functions
        c_funcs = get_pass_functions(project_dir)

        # Add functions from --use-c-funcs file
        if args.use_c_funcs:
            if os.path.exists(args.use_c_funcs):
                extra = load_func_list(args.use_c_funcs)
                print("  Adding %d functions from %s" % (len(extra), args.use_c_funcs))
                c_funcs.update(extra)
            else:
                print("Warning: %s not found" % args.use_c_funcs)

    os.makedirs(output_dir, exist_ok=True)

    # Step 1: Generate inline asm for ALL functions from aprog_syms.txt
    print("Parsing symbols...")
    symbols = parse_symbols(sym_file)
    print("Found %d functions in symbol table" % len(symbols))

    print("Generating inline asm for all functions...")
    generated_asm = 0
    for i, (name, addr) in enumerate(symbols):
        next_addr = symbols[i + 1][1] if i + 1 < len(symbols) else None
        output_path = os.path.join(output_dir, name + ".c")
        func_bytes = extract_function_bytes(bin_data, addr, next_addr)
        if func_bytes and generate_asm_c_file(name, func_bytes, output_path):
            generated_asm += 1
        if generated_asm % 200 == 0:
            print("  Generated %d asm files..." % generated_asm)

    print("  Generated %d inline asm files" % generated_asm)

    # Step 2: Overwrite with real C for selected functions
    print("Overlaying real C for %d functions..." % len(c_funcs))
    generated_c = 0
    skipped_no_src = 0

    for func_name in c_funcs:
        src_path = find_src_file(project_dir, func_name)
        if src_path:
            output_path = os.path.join(output_dir, func_name + ".c")
            copy_src_file(src_path, output_path)
            generated_c += 1
        else:
            skipped_no_src += 1

    print("")
    print("Done!")
    print("  Inline ASM:  %d functions" % generated_asm)
    print("  Real C:      %d functions" % generated_c)
    print("  No src file: %d functions (skipped)" % skipped_no_src)
    print("  Output:      %s" % output_dir)

if __name__ == "__main__":
    main()
