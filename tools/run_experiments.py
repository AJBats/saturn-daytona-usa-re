#!/usr/bin/env python3
"""
Binary shift experiments for Road to Boot diagnosis.

Creates modified APROG.BIN variants and injects each into a disc image
for boot testing. Each experiment isolates one variable to understand
why the free-layout build (4-byte shift) fails to boot.

Usage:
    python3 tools/run_experiments.py <experiment_number>
    python3 tools/run_experiments.py all

Experiments:
    1  Pad production binary with 4 zero bytes at end (394,900 bytes)
    2  Re-inject unmodified production binary (round-trip test)
    3  Insert 4 zero bytes at mid-binary dead spot (shifts tail by 4)
    4  Sawyer build with free-layout linker, 0-byte padding
"""

import sys
import os
import shutil
import struct
import subprocess

PROJECT_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PROD_BIN = os.path.join(PROJECT_DIR, "build", "aprog.bin")
EXPERIMENT_DIR = os.path.join(PROJECT_DIR, "build", "experiments")
INJECT_SCRIPT = os.path.join(PROJECT_DIR, "tools", "inject_binary.py")
REIMPL_DIR = os.path.join(PROJECT_DIR, "reimpl")

ORIG_SIZE = 394896


def ensure_dirs():
    os.makedirs(EXPERIMENT_DIR, exist_ok=True)


def read_prod_binary():
    with open(PROD_BIN, "rb") as f:
        return bytearray(f.read())


def inject_and_report(bin_path, experiment_name):
    """Inject binary into disc image and report."""
    print("\n--- Injecting %s ---" % experiment_name)
    result = subprocess.run(
        [sys.executable, INJECT_SCRIPT, bin_path],
        capture_output=True, text=True
    )
    print(result.stdout)
    if result.stderr:
        print("STDERR:", result.stderr)
    if result.returncode != 0:
        print("INJECT FAILED (exit %d)" % result.returncode)
        return False
    print("Disc image ready at: build/disc/rebuilt_disc/daytona_rebuilt.cue")
    return True


def experiment_1():
    """Pad production binary with 4 zero bytes at the end."""
    print("=" * 70)
    print("EXPERIMENT 1: Pad production binary +4 bytes at end")
    print("=" * 70)
    print("Purpose: Does a slightly larger binary (same code) break disc loading?")
    print("Isolates: Disc image / ISO directory / sector boundary effects")
    print()

    data = read_prod_binary()
    assert len(data) == ORIG_SIZE, "Production binary is %d bytes, expected %d" % (len(data), ORIG_SIZE)

    # Append 4 zero bytes
    data += b'\x00' * 4
    out_path = os.path.join(EXPERIMENT_DIR, "exp1_padded_end.bin")
    with open(out_path, "wb") as f:
        f.write(data)

    print("Created: %s (%d bytes, was %d)" % (out_path, len(data), ORIG_SIZE))
    print("Change: 4 zero bytes appended after last byte of original")
    print("Sector count: ceil(%d/2048) = %d (same as original %d)" % (
        len(data), (len(data) + 2047) // 2048, (ORIG_SIZE + 2047) // 2048))

    return inject_and_report(out_path, "Experiment 1")


def experiment_2():
    """Re-inject unmodified production binary (round-trip test)."""
    print("=" * 70)
    print("EXPERIMENT 2: Re-inject unmodified production binary")
    print("=" * 70)
    print("Purpose: Does our inject_binary.py pipeline produce a bootable disc?")
    print("Isolates: Disc injection pipeline correctness")
    print()

    out_path = os.path.join(EXPERIMENT_DIR, "exp2_prod_roundtrip.bin")
    shutil.copy2(PROD_BIN, out_path)

    print("Created: %s (%d bytes, exact copy of production)" % (out_path, ORIG_SIZE))

    return inject_and_report(out_path, "Experiment 2")


def find_dead_spot(data):
    """Find a good insertion point in the binary — a run of zeros between functions.

    We look for a 16+ byte run of zeros in the code region (after the first 256 bytes,
    before the data region at ~0x43E48 offset). These are gaps between functions.
    """
    # Search in the code region (skip first 256 bytes of _start, stop before data)
    search_start = 0x1000  # well past _start
    search_end = min(len(data), 0x40000)  # before data region

    best_start = -1
    best_len = 0
    run_start = -1
    run_len = 0

    for i in range(search_start, search_end):
        if data[i] == 0x00:
            if run_start == -1:
                run_start = i
                run_len = 1
            else:
                run_len += 1
            if run_len > best_len:
                best_start = run_start
                best_len = run_len
        else:
            run_start = -1
            run_len = 0

    return best_start, best_len


def experiment_3():
    """Insert 4 zero bytes at a dead spot in mid-binary."""
    print("=" * 70)
    print("EXPERIMENT 3: Insert 4 zero bytes at mid-binary dead spot")
    print("=" * 70)
    print("Purpose: Does shifting PART of the binary (mid-section) break execution?")
    print("Isolates: Whether shifted code itself is the problem vs whole-binary effects")
    print()

    data = read_prod_binary()

    # Find a dead spot (long run of zeros between functions)
    spot_start, spot_len = find_dead_spot(data)
    if spot_len < 8:
        print("WARNING: No good dead spot found (best run: %d zeros at 0x%X)" % (spot_len, spot_start))
        print("Using mid-point of best run anyway")

    # Insert at the middle of the zero run
    insert_point = spot_start + spot_len // 2
    print("Dead spot: %d zeros at offset 0x%X (address 0x%08X)" % (
        spot_len, spot_start, 0x06003000 + spot_start))
    print("Inserting 4 zero bytes at offset 0x%X (address 0x%08X)" % (
        insert_point, 0x06003000 + insert_point))

    # Insert 4 bytes
    new_data = data[:insert_point] + b'\x00' * 4 + data[insert_point:]
    out_path = os.path.join(EXPERIMENT_DIR, "exp3_mid_insert.bin")
    with open(out_path, "wb") as f:
        f.write(new_data)

    print("Created: %s (%d bytes, was %d)" % (out_path, len(new_data), ORIG_SIZE))
    print("Everything after offset 0x%X shifted by +4 bytes" % insert_point)

    return inject_and_report(out_path, "Experiment 3")


def experiment_4():
    """Sawyer build with free-layout linker, 0-byte padding."""
    print("=" * 70)
    print("EXPERIMENT 4: Sawyer free-layout linker with 0-byte padding")
    print("=" * 70)
    print("Purpose: Does the free-layout linker script itself cause issues (even with no shift)?")
    print("Isolates: Linker script differences (PROVIDE removal, SORT_BY_NAME) vs actual shifting")
    print()

    # Create a modified sawyer_free.ld with 0-byte padding
    free_ld = os.path.join(REIMPL_DIR, "sawyer_free.ld")
    exp4_ld = os.path.join(EXPERIMENT_DIR, "exp4_free_0pad.ld")

    with open(free_ld, "r") as f:
        ld_content = f.read()

    # Replace ". = . + 4;" with ". = . + 0;"
    modified = ld_content.replace(". = . + 4;", ". = . + 0;")
    if modified == ld_content:
        print("WARNING: Could not find '. = . + 4;' in sawyer_free.ld")
        # Try alternate patterns
        modified = ld_content.replace(". = . + 4", ". = . + 0")

    with open(exp4_ld, "w") as f:
        f.write(modified)

    print("Created linker script: %s" % exp4_ld)
    print("Change: '. = . + 4' -> '. = . + 0' (no padding)")

    # Build with this linker script via WSL
    # We need to temporarily swap the linker script
    makefile = os.path.join(REIMPL_DIR, "Makefile")
    with open(makefile, "r") as f:
        makefile_content = f.read()

    # Save original
    orig_ldscript_line = None
    for line in makefile_content.split("\n"):
        if line.startswith("LDSCRIPT"):
            orig_ldscript_line = line
            break

    # Point to our experiment linker script (WSL path)
    exp4_ld_wsl = "/mnt/d/Projects/SaturnReverseTest/build/experiments/exp4_free_0pad.ld"
    modified_makefile = makefile_content.replace(
        orig_ldscript_line,
        "LDSCRIPT := %s" % exp4_ld_wsl
    )

    with open(makefile, "w") as f:
        f.write(modified_makefile)

    print("Building with 0-pad free-layout linker script...")
    result = subprocess.run(
        ["wsl", "-d", "Ubuntu", "--", "bash", "-c",
         "cd /mnt/d/Projects/SaturnReverseTest/reimpl && make clean && make"],
        capture_output=True, text=True, timeout=120
    )
    print(result.stdout[-500:] if len(result.stdout) > 500 else result.stdout)
    if result.stderr:
        # Filter out harmless warnings
        stderr_lines = [l for l in result.stderr.split('\n') if l.strip()]
        if stderr_lines:
            print("Build messages: %d lines" % len(stderr_lines))

    # Restore original Makefile
    with open(makefile, "w") as f:
        f.write(makefile_content)

    if result.returncode != 0:
        print("BUILD FAILED")
        return False

    # Check output
    built_bin = os.path.join(REIMPL_DIR, "build", "APROG.BIN")
    if os.path.exists(built_bin):
        size = os.path.getsize(built_bin)
        print("Built: %s (%d bytes)" % (built_bin, size))

        # Validate against production
        with open(built_bin, "rb") as f:
            built_data = f.read()
        with open(PROD_BIN, "rb") as f:
            prod_data = f.read()

        if built_data == prod_data:
            print("RESULT: Byte-identical to production!")
        else:
            print("RESULT: Differs from production (%d vs %d bytes)" % (len(built_data), len(prod_data)))
            # Find first difference
            min_len = min(len(built_data), len(prod_data))
            for i in range(min_len):
                if built_data[i] != prod_data[i]:
                    print("  First diff at offset 0x%X (addr 0x%08X): 0x%02X vs 0x%02X" % (
                        i, 0x06003000 + i, built_data[i], prod_data[i]))
                    break

        # Copy to experiment dir and inject
        out_path = os.path.join(EXPERIMENT_DIR, "exp4_free_0pad.bin")
        shutil.copy2(built_bin, out_path)
        return inject_and_report(out_path, "Experiment 4")
    else:
        print("ERROR: Build output not found")
        return False


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        sys.exit(1)

    ensure_dirs()

    if not os.path.exists(PROD_BIN):
        print("ERROR: Production binary not found: %s" % PROD_BIN)
        sys.exit(1)

    arg = sys.argv[1]

    experiments = {
        "1": experiment_1,
        "2": experiment_2,
        "3": experiment_3,
        "4": experiment_4,
    }

    if arg == "all":
        for num in sorted(experiments.keys()):
            print()
            experiments[num]()
            print()
    elif arg in experiments:
        experiments[arg]()
    else:
        print("Unknown experiment: %s" % arg)
        print("Use 1, 2, 3, 4, or 'all'")
        sys.exit(1)


if __name__ == "__main__":
    main()
