#!/usr/bin/env python3
"""Full build validation: all build modes must match original retail APROG.BIN.

Runs 3 test classes:
  1. Retail (sega.ld)            — byte-identical to original
  2. Free (free.ld)              — byte-identical to original
  3. Free+4shift (free.ld +4)    — builds successfully, size = original + 4

Tests 1-2 prove: assembly is correct and free.ld recreates original link order.
Test 3 proves: the linker script handles shifted addresses (relocation sanity).

Usage:
    python tools/validate_build.py              # full validation
    python tools/validate_build.py --class free  # single class
"""

import os
import sys
import subprocess
import argparse

PROJECT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ORIGINAL = os.path.join(PROJECT, "build", "disc", "files", "APROG.BIN")


def wsl_path(win_path):
    drive = win_path[0].lower()
    rest = win_path[2:].replace("\\", "/")
    return f"/mnt/{drive}{rest}"


def run_wsl(cmd, timeout=120):
    """Run a command in WSL, return (returncode, stdout, stderr)."""
    result = subprocess.run(
        ["wsl", "-d", "Ubuntu", "-e", "bash", "-c", cmd],
        capture_output=True, text=True, timeout=timeout,
    )
    return result.returncode, result.stdout, result.stderr


def build(ldscript="free.ld", shift=0):
    """Build binary. Returns path to APROG.BIN or None on failure."""
    projdir_wsl = wsl_path(PROJECT)

    if ldscript == "sega.ld":
        label = "retail (sega.ld)"
        cmd = f'make -C "{projdir_wsl}/reimpl" LDSCRIPT=sega.ld REIMPL_C= REIMPL_S= 2>&1'
    else:
        label = f"free (shift={shift})"
        shift_arg = f" SHIFT={shift}" if shift else ""
        cmd = f'make -C "{projdir_wsl}/reimpl"{shift_arg} 2>&1'

    print(f"  Building {label}...")
    rc, out, err = run_wsl(cmd, timeout=120)
    if rc != 0:
        print(f"  Build FAILED (rc={rc})")
        print(out[-500:] if len(out) > 500 else out)
        return None

    bin_path = os.path.join(PROJECT, "reimpl", "build", "APROG.BIN")
    if os.path.exists(bin_path):
        return bin_path
    print(f"  Build output not found: {bin_path}")
    return None


def binary_compare(test_path, label):
    """Compare built binary against original retail APROG.BIN."""
    if not os.path.exists(ORIGINAL):
        print(f"  FAIL: original not found: {ORIGINAL}")
        return False

    if not os.path.exists(test_path):
        print(f"  FAIL: build output not found: {test_path}")
        return False

    test_size = os.path.getsize(test_path)
    orig_size = os.path.getsize(ORIGINAL)

    if test_size != orig_size:
        print(f"  FAIL: size mismatch — built={test_size} original={orig_size}")
        return False

    with open(test_path, "rb") as f:
        test_data = f.read()
    with open(ORIGINAL, "rb") as f:
        orig_data = f.read()

    if test_data == orig_data:
        print(f"  PASS: byte-identical to original ({test_size} bytes)")
        return True

    # Find first difference
    for i in range(len(test_data)):
        if test_data[i] != orig_data[i]:
            print(f"  FAIL: first diff at offset 0x{i:06X} "
                  f"(built=0x{test_data[i]:02X} original=0x{orig_data[i]:02X})")
            break

    diffs = sum(1 for a, b in zip(test_data, orig_data) if a != b)
    print(f"  {diffs} byte(s) differ out of {test_size}")
    return False


def test_retail():
    """Test 1: retail build (sega.ld) must match original."""
    print("=" * 60)
    print("TEST 1: Retail build (sega.ld)")
    print("=" * 60)

    bin_path = build(ldscript="sega.ld")
    if not bin_path:
        print("  RESULT: FAIL\n")
        return False

    passed = binary_compare(bin_path, "retail")
    print(f"  RESULT: {'PASS' if passed else 'FAIL'}\n")
    return passed


def test_free():
    """Test 2: free build (free.ld, shift=0) must be byte-identical to original."""
    print("=" * 60)
    print("TEST 2: Free build (free.ld)")
    print("=" * 60)

    bin_path = build(shift=0)
    if not bin_path:
        print("  RESULT: FAIL\n")
        return False

    passed = binary_compare(bin_path, "free")
    print(f"  RESULT: {'PASS' if passed else 'FAIL'}\n")
    return passed


def test_free_shifted(shift=4):
    """Test 3: free+shift build must succeed and be exactly original_size + shift bytes."""
    print("=" * 60)
    print(f"TEST 3: Free+{shift}shift build (free.ld, shift={shift})")
    print("=" * 60)

    bin_path = build(shift=shift)
    if not bin_path:
        print("  RESULT: FAIL\n")
        return False

    if not os.path.exists(ORIGINAL):
        print(f"  FAIL: original not found: {ORIGINAL}")
        print("  RESULT: FAIL\n")
        return False

    built_size = os.path.getsize(bin_path)
    orig_size = os.path.getsize(ORIGINAL)
    expected = orig_size + shift

    if built_size == expected:
        print(f"  PASS: {built_size} bytes (original {orig_size} + {shift} shift)")
        print("  RESULT: PASS\n")
        return True
    else:
        print(f"  FAIL: expected {expected} bytes, got {built_size}")
        print("  RESULT: FAIL\n")
        return False


def main():
    parser = argparse.ArgumentParser(description="Full build validation")
    parser.add_argument(
        "--class", dest="test_class",
        choices=["retail", "free", "free4", "all"],
        default="all", help="Which test class to run"
    )
    args = parser.parse_args()

    results = {}
    overall = True

    if args.test_class in ("retail", "all"):
        passed = test_retail()
        results["retail"] = passed
        if not passed:
            overall = False

    if args.test_class in ("free", "all"):
        passed = test_free()
        results["free"] = passed
        if not passed:
            overall = False

    if args.test_class in ("free4", "all"):
        passed = test_free_shifted(shift=4)
        results["free4"] = passed
        if not passed:
            overall = False

    # Summary
    print("=" * 60)
    print("VALIDATION SUMMARY")
    print("=" * 60)
    for name, passed in results.items():
        print(f"  {name:12s}: {'PASS' if passed else 'FAIL'}")
    print()
    if overall:
        print("OVERALL: PASS")
    else:
        print("OVERALL: FAIL")

    return 0 if overall else 1


if __name__ == "__main__":
    sys.exit(main())
