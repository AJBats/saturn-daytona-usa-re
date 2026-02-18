#!/usr/bin/env python3
"""test_multi_shift.py - Test multiple shift values to isolate SCDQ poll hang.

For each shift value:
1. Patches sawyer_free.ld with the shift
2. Rebuilds via WSL
3. Makes disc via WSL
4. Boots in Mednafen and checks if main_loop (0x0600300A) is reached

Results are saved to .tmp/shift_test_results.txt
"""

import os
import sys
import time
import subprocess
import re

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))

try:
    from parallel_compare import MednafenInstance, read_regs_bin
    HAS_MEDNAFEN = True
except ImportError:
    HAS_MEDNAFEN = False
    print("WARNING: parallel_compare not available, using boot test fallback")

CUE_FREE = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
TMPDIR = os.path.join(PROJDIR, ".tmp")
LD_FILE = os.path.join(PROJDIR, "reimpl", "sawyer_free.ld")
RESULTS_FILE = os.path.join(TMPDIR, "shift_test_results.txt")

# Shift values to test
SHIFT_VALUES = [0, 2, 4, 8, 16, 32]


def parse_pc(ack):
    m = re.search(r'pc=0x([0-9a-fA-F]+)', ack)
    return int(m.group(1), 16) if m else None

def parse_frame(ack):
    m = re.search(r'frame=(\d+)', ack)
    return int(m.group(1)) if m else None


def patch_linker_script(shift):
    """Patch the shift value in sawyer_free.ld."""
    with open(LD_FILE, 'r') as f:
        content = f.read()

    # Replace the ". = . + N;" line (or add/remove it for shift=0)
    if shift == 0:
        # Remove the padding line entirely
        content = re.sub(
            r'/\*.*?padding.*?\*/\s*\n\s*\. = \. \+ \d+;',
            '/* no padding -- shift=0 test */',
            content
        )
    else:
        # Replace existing padding or insert new
        if re.search(r'\. = \. \+ \d+;', content):
            content = re.sub(
                r'/\*.*?padding.*?\*/\s*\n\s*\. = \. \+ \d+;',
                f'/* {shift} bytes of padding -- shift test */\n        . = . + {shift};',
                content
            )
        elif '/* no padding' in content:
            content = content.replace(
                '/* no padding -- shift=0 test */',
                f'/* {shift} bytes of padding -- shift test */\n        . = . + {shift};'
            )

    with open(LD_FILE, 'w') as f:
        f.write(content)

    print(f"  Patched LD: shift = +{shift}")


def build_and_disc():
    """Rebuild and create disc image via WSL."""
    wsl_path = "/mnt/d/Projects/SaturnReverseTest/reimpl"

    # Clean + build
    print("  Building...")
    result = subprocess.run(
        ["wsl", "-d", "Ubuntu", "--", "bash", "-c",
         f"cd {wsl_path} && make clean > /dev/null 2>&1 && make LDSCRIPT=sawyer_free.ld 2>&1 | tail -5"],
        capture_output=True, text=True, timeout=120
    )
    if result.returncode != 0:
        print(f"  BUILD FAILED: {result.stderr[-200:]}")
        return False

    # Get binary size
    result2 = subprocess.run(
        ["wsl", "-d", "Ubuntu", "--", "bash", "-c",
         f"wc -c < {wsl_path}/build/aprog_reimpl.bin"],
        capture_output=True, text=True, timeout=30
    )
    size = result2.stdout.strip()
    print(f"  Binary size: {size} bytes")

    # Make disc
    print("  Making disc...")
    result3 = subprocess.run(
        ["wsl", "-d", "Ubuntu", "--", "bash", "-c",
         f"cd {wsl_path} && make disc 2>&1 | tail -3"],
        capture_output=True, text=True, timeout=120
    )
    if result3.returncode != 0:
        print(f"  DISC FAILED: {result3.stderr[-200:]}")
        return False

    print("  Disc created OK")
    return True


def test_boot_mednafen(shift):
    """Use MednafenInstance to check if main_loop is reached."""
    if not HAS_MEDNAFEN:
        return "SKIP (no MednafenInstance)"

    MednafenInstance.kill_stale()
    ipc = os.path.join(TMPDIR, f"shift_test_{shift}")
    inst = MednafenInstance(f"SHIFT_{shift}", CUE_FREE, ipc)

    try:
        inst.start()
    except Exception as e:
        return f"START_FAIL: {e}"

    # Wait for _start
    inst.breakpoint(0x06003000)
    try:
        ack = inst.continue_exec()
        start_frame = parse_frame(ack)
    except TimeoutError:
        inst.quit()
        MednafenInstance.kill_stale()
        return "TIMEOUT_AT_START"
    inst.breakpoint_clear()

    # Wait for SCDQ poll entry
    poll_addr = 0x060423CC + shift
    inst.breakpoint(poll_addr)
    try:
        ack = inst.continue_exec()
        poll_frame = parse_frame(ack)
    except TimeoutError:
        inst.quit()
        MednafenInstance.kill_stale()
        return "TIMEOUT_AT_POLL"
    inst.breakpoint_clear()

    # Now the critical test: does main_loop get reached?
    # main_loop is at 0x0600300A (within _start, NOT shifted by FUN_ shift)
    main_loop_addr = 0x0600300A
    inst.breakpoint(main_loop_addr)

    # Give it 15 seconds real time
    try:
        inst._write_action("continue")
        time.sleep(0.1)
        ack = inst._read_ack()

        deadline = time.time() + 15
        hit = False
        while time.time() < deadline:
            ack = inst._read_ack()
            if ack and "break" in ack:
                hit = True
                break
            time.sleep(0.1)

        if hit:
            frame = parse_frame(ack)
            result = f"BOOT_OK (main_loop at frame {frame})"
        else:
            # Check where we're stuck
            regs_path = os.path.join(ipc, "regs_stuck.bin")
            inst.dump_regs_bin(regs_path)
            time.sleep(0.3)
            regs = read_regs_bin(regs_path)
            if regs:
                pc = regs['PC']
                r0 = regs['R0']
                result = f"STUCK at PC=0x{pc:08X} R0=0x{r0:08X}"
            else:
                result = "STUCK (no regs)"

    except Exception as e:
        result = f"ERROR: {e}"

    inst.breakpoint_clear()
    inst.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()
    return result


def main():
    os.makedirs(TMPDIR, exist_ok=True)

    print("=" * 70)
    print("  Multi-Shift SCDQ Poll Test")
    print("=" * 70)
    print(f"  Testing shifts: {SHIFT_VALUES}")
    print(f"  Results file: {RESULTS_FILE}")
    print()

    results = {}

    for shift in SHIFT_VALUES:
        print(f"\n{'='*60}")
        print(f"  SHIFT = +{shift}")
        print(f"{'='*60}")

        # Patch LD
        patch_linker_script(shift)

        # Build + disc
        if not build_and_disc():
            results[shift] = "BUILD_FAILED"
            continue

        # Boot test
        result = test_boot_mednafen(shift)
        results[shift] = result
        print(f"  RESULT: {result}")

        time.sleep(2)

    # Summary
    print(f"\n{'='*70}")
    print(f"  MULTI-SHIFT TEST RESULTS")
    print(f"{'='*70}")

    with open(RESULTS_FILE, 'w') as f:
        f.write("Multi-Shift SCDQ Poll Test Results\n")
        f.write("=" * 50 + "\n\n")

        for shift in SHIFT_VALUES:
            r = results.get(shift, "NOT_TESTED")
            line = f"  Shift +{shift:3d}: {r}"
            print(line)
            f.write(line + "\n")

        f.write("\n")

        # Analysis
        boots = [s for s in SHIFT_VALUES if "BOOT_OK" in results.get(s, "")]
        fails = [s for s in SHIFT_VALUES if "STUCK" in results.get(s, "")]

        if len(boots) == len(SHIFT_VALUES):
            conclusion = "ALL shifts boot => original +4 issue was a fluke"
        elif boots == [0]:
            conclusion = "ONLY shift=0 boots => ANY address change breaks CDB timing"
        elif len(boots) > 1:
            conclusion = f"Some shifts boot ({boots}), some fail ({fails}) => alignment-specific issue"
        else:
            conclusion = f"Boots: {boots}, Fails: {fails} => needs more investigation"

        print(f"\n  CONCLUSION: {conclusion}")
        f.write(f"\nConclusion: {conclusion}\n")

    # Restore +4 shift
    patch_linker_script(4)
    print("\n  (Restored LD to +4 shift)")


if __name__ == "__main__":
    main()
