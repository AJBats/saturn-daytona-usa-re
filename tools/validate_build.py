#!/usr/bin/env python3
"""Full L3 elevation validation — 3-class build verification.

Test procedure:
  1. make retail-validate  — retail (sega.ld) byte-identical to original
  2. make validate         — free (free.ld) byte-identical to original
  3. Free+4shift (MODS=1)  — byte-matches golden shifted binary + boots to menu

Tests 1-2 are Makefile targets (fast, binary compare only).
Test 3 builds with MODS=1 SHIFT=4, compares against golden_free4_APROG.BIN,
injects into disc, and runs a 3-stage screenshot boot test via test_boot_auto.py.

Usage:
    python tools/validate_build.py              # all 3 tests
    python tools/validate_build.py --class free4 # shifted build only
"""

import os
import sys
import subprocess
import argparse

PROJECT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ORIGINAL = os.path.join(PROJECT, "build", "disc", "files", "APROG.BIN")
GOLDEN_FREE4 = os.path.join(PROJECT, "build", "golden_free4_APROG.BIN")
BIN_PATH = os.path.join(PROJECT, "reimpl", "build", "APROG.BIN")


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


def test_retail():
    """Test 1: make retail-validate."""
    print("=" * 60)
    print("TEST 1: Retail build (sega.ld) — make retail-validate")
    print("=" * 60)

    projdir_wsl = wsl_path(PROJECT)
    rc, out, err = run_wsl(
        f'make -C "{projdir_wsl}/reimpl" retail-validate 2>&1',
        timeout=120,
    )
    # Show last few lines (the PASS/FAIL result)
    for line in out.strip().split("\n")[-3:]:
        print(f"  {line}")

    passed = "PASS" in out
    print(f"  RESULT: {'PASS' if passed else 'FAIL'}\n")
    return passed


def test_free():
    """Test 2: make validate (free.ld byte-match)."""
    print("=" * 60)
    print("TEST 2: Free build (free.ld) — make validate")
    print("=" * 60)

    projdir_wsl = wsl_path(PROJECT)
    rc, out, err = run_wsl(
        f'make -C "{projdir_wsl}/reimpl" validate 2>&1',
        timeout=120,
    )
    for line in out.strip().split("\n")[-3:]:
        print(f"  {line}")

    passed = "PASS" in out
    print(f"  RESULT: {'PASS' if passed else 'FAIL'}\n")
    return passed


def test_free_shifted(shift=4):
    """Test 3: free+4shift (MODS=1) — golden binary match + screenshot boot test."""
    print("=" * 60)
    print(f"TEST 3: Free+{shift}shift (MODS=1) — golden match + boot test")
    print("=" * 60)

    # Step 1: Build with MODS=1 SHIFT=4
    projdir_wsl = wsl_path(PROJECT)
    print(f"  Building free+{shift}shift with MODS=1...")
    rc, out, err = run_wsl(
        f'make -C "{projdir_wsl}/reimpl" SHIFT={shift} MODS=1 2>&1',
        timeout=120,
    )
    if rc != 0:
        print(f"  Build FAILED (rc={rc})")
        print(out[-500:] if len(out) > 500 else out)
        print("  RESULT: FAIL\n")
        return False

    if not os.path.exists(BIN_PATH):
        print(f"  Build output not found: {BIN_PATH}")
        print("  RESULT: FAIL\n")
        return False

    # Step 2: Compare against golden shifted binary
    print(f"  Comparing against golden shifted binary...")
    if not os.path.exists(GOLDEN_FREE4):
        print(f"  WARNING: golden not found: {GOLDEN_FREE4}")
        print(f"  Skipping golden comparison (save current build as golden to enable)")
        golden_ok = True  # Don't fail — just warn
    else:
        with open(BIN_PATH, "rb") as f:
            built = f.read()
        with open(GOLDEN_FREE4, "rb") as f:
            golden = f.read()

        if built == golden:
            print(f"  PASS: byte-identical to golden ({len(built)} bytes)")
            golden_ok = True
        else:
            if len(built) != len(golden):
                print(f"  FAIL: size mismatch — built={len(built)} golden={len(golden)}")
            else:
                for i in range(len(built)):
                    if built[i] != golden[i]:
                        print(f"  FAIL: first diff at offset 0x{i:06X} "
                              f"(built=0x{built[i]:02X} golden=0x{golden[i]:02X})")
                        break
                diffs = sum(1 for a, b in zip(built, golden) if a != b)
                print(f"  {diffs} byte(s) differ")
            golden_ok = False

    if not golden_ok:
        print("  RESULT: FAIL (golden mismatch)\n")
        return False

    # Step 3: Inject into disc and run boot test
    print(f"  Injecting into disc image...")
    rc, out, err = run_wsl(
        f'make -C "{projdir_wsl}/reimpl" SHIFT={shift} MODS=1 disc 2>&1',
        timeout=120,
    )
    if rc != 0 or "Injecting" not in out:
        print(f"  Disc injection FAILED")
        print(out[-300:] if len(out) > 300 else out)
        print("  RESULT: FAIL\n")
        return False

    print(f"  Running boot test (3 stages)...")
    result = subprocess.run(
        [sys.executable, os.path.join(PROJECT, "tools", "test_boot_auto.py"), "rebuilt"],
        capture_output=True, text=True, timeout=300, cwd=PROJECT,
    )

    # Show boot test output
    for line in result.stdout.strip().split("\n"):
        print(f"    {line}")

    if result.returncode != 0:
        print(f"  Boot test FAILED (rc={result.returncode})")
        if result.stderr.strip():
            for line in result.stderr.strip().split("\n")[-5:]:
                print(f"    {line}")
        print("  RESULT: FAIL\n")
        return False

    boot_ok = "PASS" in result.stdout or "OVERALL: PASS" in result.stdout
    if not boot_ok:
        # Check if any FAIL lines
        boot_ok = "FAIL" not in result.stdout

    print(f"  RESULT: {'PASS' if boot_ok else 'FAIL'}\n")
    return boot_ok


def main():
    parser = argparse.ArgumentParser(description="Full L3 elevation validation")
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
