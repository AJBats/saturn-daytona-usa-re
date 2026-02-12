#!/usr/bin/env python3
"""Compare code size: GCC 2.6.3 vs GCC 13.3.0 on decomp source files."""

import os
import subprocess
import random
import tempfile
import sys

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRCDIR = os.path.join(PROJ, "src")
CC1 = os.path.join(PROJ, "tools", "gcc26-build", "cc1")
GCC13 = os.path.join(PROJ, "tools", "sh-elf", "bin", "sh-elf-gcc")
SIZE = os.path.join(PROJ, "tools", "sh-elf", "bin", "sh-elf-size")
TESTS = os.path.join(PROJ, "tests")

def wsl_path(p):
    """Convert Windows path to WSL path."""
    return p.replace("\\", "/").replace("D:", "/mnt/d").replace("d:", "/mnt/d")

def run_wsl(cmd):
    """Run a command in WSL, return (returncode, stdout)."""
    r = subprocess.run(
        ["wsl", "-d", "Ubuntu", "--", "bash", "-c", cmd],
        capture_output=True, text=True, timeout=30
    )
    return r.returncode, r.stdout.strip()

def get_text_size(obj_path):
    """Get .text section size from an object file."""
    rc, out = run_wsl(f"{wsl_path(SIZE)} {obj_path} 2>/dev/null | tail -1")
    if rc != 0 or not out:
        return 0
    parts = out.split()
    try:
        return int(parts[0])
    except (ValueError, IndexError):
        return 0

def compile_gcc26(src_wsl, tmpdir, extra_flags=""):
    """Compile with GCC 2.6.3, return text size."""
    asm = f"{tmpdir}/gcc26.s"
    obj = f"{tmpdir}/gcc26.o"
    cmd = f"{wsl_path(CC1)} -quiet -O2 -m2 -mbsr {extra_flags} {src_wsl} -o {asm} 2>/dev/null"
    rc, _ = run_wsl(cmd)
    if rc != 0:
        return 0
    cmd = f"{wsl_path(GCC13)} -m2 -mb -c {asm} -o {obj} 2>/dev/null"
    rc, _ = run_wsl(cmd)
    if rc != 0:
        return 0
    return get_text_size(obj)

def compile_gcc13(src_wsl, tmpdir, opt_flag="-O2"):
    """Compile with GCC 13, return text size."""
    obj = f"{tmpdir}/gcc13.o"
    cmd = f"{wsl_path(GCC13)} -m2 -mb {opt_flag} -nostdlib -ffreestanding -fno-builtin -c {src_wsl} -o {obj} 2>/dev/null"
    rc, _ = run_wsl(cmd)
    if rc != 0:
        return 0
    return get_text_size(obj)

def main():
    n_files = int(sys.argv[1]) if len(sys.argv) > 1 else 80

    # Get all source files
    sources = sorted([f for f in os.listdir(SRCDIR) if f.endswith(".c")])
    random.seed(42)  # Reproducible
    random.shuffle(sources)
    sources = sources[:n_files]

    # Create WSL temp dir
    _, tmpdir = run_wsl("mktemp -d")

    print(f"{'Function':<22} {'GCC2.6':>7} {'GCC13O2':>8} {'GCC13Os':>8} {'O2/2.6':>7} {'Os/2.6':>7}")
    print("-" * 70)

    total_26 = 0
    total_O2 = 0
    total_Os = 0
    count = 0
    skipped = 0

    for fname in sources:
        name = fname[:-2]
        src_path = os.path.join(SRCDIR, fname)

        # Strip CRLF
        src_wsl = f"{tmpdir}/input.c"
        run_wsl(f"tr -d '\\r' < {wsl_path(src_path)} > {src_wsl}")

        # Check per-function flags
        flagfile = os.path.join(TESTS, f"{name}.flags")
        extra = ""
        if os.path.exists(flagfile):
            with open(flagfile) as f:
                extra = f.read().strip().replace("\r", "")

        # Compile with all three
        s26 = compile_gcc26(src_wsl, tmpdir, extra)
        if s26 == 0:
            skipped += 1
            continue

        sO2 = compile_gcc13(src_wsl, tmpdir, "-O2")
        sOs = compile_gcc13(src_wsl, tmpdir, "-Os")

        if sO2 == 0 or sOs == 0:
            skipped += 1
            continue

        rO2 = sO2 * 100 // s26
        rOs = sOs * 100 // s26

        print(f"{name:<22} {s26:>7} {sO2:>8} {sOs:>8} {rO2:>6}% {rOs:>6}%")

        total_26 += s26
        total_O2 += sO2
        total_Os += sOs
        count += 1

    # Cleanup
    run_wsl(f"rm -rf {tmpdir}")

    print()
    print("=== SUMMARY ===")
    print(f"Files compared: {count} (skipped: {skipped})")
    print(f"{'TOTAL bytes':<22} {total_26:>7} {total_O2:>8} {total_Os:>8}")
    if total_26 > 0:
        rO2 = total_O2 * 100 / total_26
        rOs = total_Os * 100 / total_26
        print(f"{'Ratio vs GCC 2.6':<22} {'100%':>7} {rO2:>7.1f}% {rOs:>7.1f}%")
        print(f"{'Overhead bytes':<22} {'0':>7} {total_O2-total_26:>+8} {total_Os-total_26:>+8}")
        print()
        # Extrapolate to full reimpl
        # batch files have ~298KB of L1 code compiled with GCC 13 -O2
        batch_bytes = 297856
        projected_Os = int(batch_bytes * rOs / rO2)
        savings = batch_bytes - projected_Os
        print(f"Projected savings on 298KB L1 code if switched to -Os:")
        print(f"  Current (-O2): {batch_bytes:>8} bytes")
        print(f"  With -Os:      {projected_Os:>8} bytes (projected)")
        print(f"  Savings:       {savings:>8} bytes ({savings*100//batch_bytes}%)")

if __name__ == "__main__":
    main()
