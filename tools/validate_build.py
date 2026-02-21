#!/usr/bin/env python3
"""Full build validation: retail match + free boot + free+4shift boot.

Runs 3 test classes:
  1. Retail binary match (no boot required)
  2. Free build — boot to menu with 3-stage screenshot comparison
  3. Free+4shift — boot to menu with 3-stage screenshot comparison

Each boot test takes 3 screenshots (attract, title, menu) and compares
against golden baselines using all 4 methods (phash, histogram, pixels, rmse).
Menu has blink tolerance: passes if all 4 methods pass against EITHER golden
(blink-on or blink-off variant).

Usage:
    python tools/validate_build.py              # full validation
    python tools/validate_build.py --skip-boot  # retail match only
    python tools/validate_build.py --class free  # single class
"""

import os
import sys
import subprocess
import argparse
import time

PROJECT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCREENSHOT_DIR = os.path.join(PROJECT, "build", "screenshots")
GOLDEN_DIR = SCREENSHOT_DIR  # goldens live alongside other screenshots

# Golden baselines per stage. Menu has two (blink on/off).
GOLDENS = {
    "attract": ["golden_attract.png"],
    "title":   ["golden_title.png"],
    "menu":    ["golden_menu.png", "golden_menu_alt.png"],
}

STAGES = ["attract", "title", "menu"]
METHODS = ["phash", "histogram", "pixels", "rmse"]


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


def test_retail_match():
    """Test 1: retail build must be byte-identical to original."""
    print("=" * 60)
    print("TEST 1: Retail binary match")
    print("=" * 60)

    projdir_wsl = wsl_path(PROJECT)
    rc, out, err = run_wsl(
        f'make -C "{projdir_wsl}/reimpl" validate 2>&1',
        timeout=120,
    )
    print(out.strip())
    if "PASS" in out:
        print("  RESULT: PASS\n")
        return True
    else:
        print("  RESULT: FAIL\n")
        return False


def build_disc(shift=0):
    """Build and inject into disc. Returns True on success."""
    projdir_wsl = wsl_path(PROJECT)
    if shift == 0:
        target = "disc"
        label = "free"
    else:
        target = "disc-4shift"
        label = f"free+{shift}shift"

    print(f"  Building {label}...")
    rc, out, err = run_wsl(
        f'make -C "{projdir_wsl}/reimpl" {target} 2>&1',
        timeout=120,
    )
    if rc != 0:
        print(f"  Build FAILED (rc={rc})")
        print(out[-500:] if len(out) > 500 else out)
        return False
    if "Injecting" in out:
        print(f"  Build + inject OK")
        return True
    print(f"  Build output unexpected:")
    print(out[-300:])
    return False


def compare_screenshot(test_path, golden_path, method):
    """Run a single comparison method. Returns (passed, detail)."""
    result = subprocess.run(
        [
            sys.executable,
            os.path.join(PROJECT, "tools", "compare_screenshot.py"),
            test_path, golden_path,
            "--method", method,
        ],
        capture_output=True, text=True,
    )
    # Extract just the method line, skip "OVERALL:" summary
    lines = [l for l in result.stdout.strip().split("\n")
             if l and not l.startswith("OVERALL")]
    detail = lines[0] if lines else "(no output)"
    return result.returncode == 0, detail


def compare_stage(test_path, stage):
    """Compare a test screenshot against golden(s) using all 4 methods.

    For stages with multiple goldens (menu blink), passes if ALL 4 methods
    pass against at least one golden variant.
    """
    golden_files = GOLDENS[stage]

    for golden_name in golden_files:
        golden_path = os.path.join(GOLDEN_DIR, golden_name)
        if not os.path.exists(golden_path):
            continue

        results = {}
        all_pass = True
        for method in METHODS:
            passed, detail = compare_screenshot(test_path, golden_path, method)
            results[method] = (passed, detail)
            if not passed:
                all_pass = False

        if all_pass:
            return True, results, golden_name

    # If no golden passed all 4, return the results from the first golden
    # (which is the primary one)
    primary_golden = os.path.join(GOLDEN_DIR, golden_files[0])
    results = {}
    for method in METHODS:
        passed, detail = compare_screenshot(test_path, primary_golden, method)
        results[method] = (passed, detail)
    return False, results, golden_files[0]


def boot_test_class(label, output_subdir):
    """Run 3-stage boot test for one disc class. Returns dict of results."""
    print(f"\n  Booting {label}...")

    screenshot_dir = os.path.join(SCREENSHOT_DIR, output_subdir)
    os.makedirs(screenshot_dir, exist_ok=True)

    # Run test_boot_auto.py with "rebuilt" — disc was just injected by build step
    result = subprocess.run(
        [
            sys.executable,
            os.path.join(PROJECT, "tools", "test_boot_auto.py"),
            "rebuilt",
            "--no-compare",  # we'll do comparison ourselves with all 4 methods
        ],
        capture_output=True, text=True,
        timeout=300,
        cwd=PROJECT,
    )

    if result.returncode != 0 and "OVERALL: PASS" not in result.stdout:
        # Check if screenshots were actually captured
        pass

    # Now compare each stage with all 4 methods
    stage_results = {}
    for stage in STAGES:
        test_path = os.path.join(screenshot_dir, f"test_{stage}.png")

        # test_boot_auto.py writes to boot_test/ subdir
        auto_test_path = os.path.join(SCREENSHOT_DIR, "boot_test", f"test_{stage}.png")

        if os.path.exists(auto_test_path):
            # Copy to our output subdir
            import shutil
            shutil.copy2(auto_test_path, test_path)
        elif not os.path.exists(test_path):
            stage_results[stage] = {
                "passed": False,
                "reason": "screenshot not captured",
                "methods": {},
            }
            continue

        passed, methods, golden_used = compare_stage(test_path, stage)
        stage_results[stage] = {
            "passed": passed,
            "golden": golden_used,
            "methods": methods,
        }

    return stage_results


def print_stage_results(stage_results):
    """Pretty-print stage comparison results."""
    for stage in STAGES:
        if stage not in stage_results:
            print(f"    {stage}: NOT RUN")
            continue

        sr = stage_results[stage]
        if "reason" in sr:
            print(f"    {stage}: FAIL ({sr['reason']})")
            continue

        status = "PASS" if sr["passed"] else "FAIL"
        golden = sr.get("golden", "?")
        print(f"    {stage}: {status} (vs {golden})")
        for method in METHODS:
            if method in sr["methods"]:
                m_pass, m_detail = sr["methods"][method]
                m_status = "PASS" if m_pass else "FAIL"
                # Strip method prefix if compare_screenshot.py already added it
                if m_detail.startswith(f"{method}:"):
                    m_detail = m_detail[len(method)+1:].strip()
                    if m_detail.startswith(f"{m_status} -"):
                        m_detail = m_detail[len(m_status)+2:].strip()
                print(f"      {method}: {m_status} - {m_detail}")


def main():
    parser = argparse.ArgumentParser(description="Full build validation")
    parser.add_argument(
        "--skip-boot", action="store_true",
        help="Only run retail match, skip boot tests"
    )
    parser.add_argument(
        "--class", dest="test_class",
        choices=["retail", "free", "free4", "all"],
        default="all", help="Which test class to run"
    )
    args = parser.parse_args()

    results = {}
    overall = True

    # Test 1: Retail binary match
    if args.test_class in ("retail", "all"):
        passed = test_retail_match()
        results["retail"] = passed
        if not passed:
            overall = False

    # Test 2: Free build boot test
    if args.test_class in ("free", "all") and not args.skip_boot:
        print("=" * 60)
        print("TEST 2: Free build — boot to menu")
        print("=" * 60)

        if not build_disc(shift=0):
            results["free"] = False
            overall = False
        else:
            stage_results = boot_test_class("free", "validate_free")
            all_stages_pass = all(
                sr.get("passed", False) for sr in stage_results.values()
            )
            results["free"] = all_stages_pass
            print_stage_results(stage_results)
            if not all_stages_pass:
                overall = False
            print(f"  RESULT: {'PASS' if all_stages_pass else 'FAIL'}\n")

    # Test 3: Free+4shift build boot test
    if args.test_class in ("free4", "all") and not args.skip_boot:
        print("=" * 60)
        print("TEST 3: Free+4shift — boot to menu")
        print("=" * 60)

        if not build_disc(shift=4):
            results["free4"] = False
            overall = False
        else:
            stage_results = boot_test_class("free+4", "validate_free4")
            all_stages_pass = all(
                sr.get("passed", False) for sr in stage_results.values()
            )
            results["free4"] = all_stages_pass
            print_stage_results(stage_results)
            if not all_stages_pass:
                overall = False
            print(f"  RESULT: {'PASS' if all_stages_pass else 'FAIL'}\n")

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
