#!/usr/bin/env python3
"""quick_boot_check.py - Quick check if reimpl boots past SCDQ poll.

Tests whether the main_loop address (0x0600300A, in _start, doesn't shift)
is reached within 20 seconds. This proves system_init completed successfully.

Usage: python tools/quick_boot_check.py [shift_value]
"""

import os
import sys
import time
import re

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin

CUE = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
TMPDIR = os.path.join(PROJDIR, ".tmp")

MAIN_LOOP = 0x0600300A  # In _start, never shifts


def parse_pc(ack):
    m = re.search(r'pc=0x([0-9a-fA-F]+)', ack)
    return int(m.group(1), 16) if m else None

def parse_frame(ack):
    m = re.search(r'frame=(\d+)', ack)
    return int(m.group(1)) if m else None


def check_boot(shift=0):
    label = f"shift_{shift}"
    MednafenInstance.kill_stale()

    ipc = os.path.join(TMPDIR, f"qboot_{label}")
    inst = MednafenInstance(label, CUE, ipc)

    print(f"Starting Mednafen for shift=+{shift}...")
    try:
        inst.start()
    except Exception as e:
        print(f"  FAILED to start: {e}")
        return "START_FAIL"

    # Wait for _start
    print("  Waiting for _start (0x06003000)...")
    inst.breakpoint(0x06003000)
    try:
        ack = inst.continue_exec()
        frame = parse_frame(ack)
        print(f"  _start reached at frame {frame}")
    except TimeoutError:
        print(f"  TIMEOUT waiting for _start")
        inst.quit(); MednafenInstance.kill_stale()
        return "TIMEOUT_START"
    inst.breakpoint_clear()

    # Now check if main_loop is reached (proves system_init completed)
    print(f"  Waiting for main_loop (0x{MAIN_LOOP:08X}), 20s timeout...")
    inst.breakpoint(MAIN_LOOP)

    try:
        inst._write_action("continue")
        time.sleep(0.1)
        # Read any pending ack
        inst._read_ack()

        deadline = time.time() + 20
        hit = False
        while time.time() < deadline:
            ack = inst._read_ack()
            if ack and "break" in ack:
                hit = True
                break
            time.sleep(0.1)

        if hit:
            frame = parse_frame(ack)
            print(f"  BOOT SUCCESS! main_loop reached at frame {frame}")
            inst.breakpoint_clear()
            inst.quit()
            time.sleep(1)
            MednafenInstance.kill_stale()
            return f"BOOT_OK(frame={frame})"
        else:
            # Stuck — dump where we are
            regs_path = os.path.join(ipc, "regs_stuck.bin")
            inst.dump_regs_bin(regs_path)
            time.sleep(0.3)
            regs = read_regs_bin(regs_path)
            if regs:
                pc = regs['PC']
                r0 = regs['R0']
                r14 = regs['R14']
                pr = regs['PR']
                print(f"  STUCK: PC=0x{pc:08X} R0=0x{r0:08X} R14=0x{r14:08X} PR=0x{pr:08X}")

                # Check if stuck in SCDQ poll area
                poll_base = 0x060423CC + shift
                if poll_base <= pc <= poll_base + 0x30:
                    scdq = "SET" if (r0 & 0x0400) else "clear"
                    print(f"  Stuck in SCDQ poll (R0 & 0x400 = {scdq})")

                inst.breakpoint_clear()
                inst.quit()
                time.sleep(1)
                MednafenInstance.kill_stale()
                return f"STUCK(PC=0x{pc:08X},R0=0x{r0:08X})"
            else:
                inst.breakpoint_clear()
                inst.quit()
                time.sleep(1)
                MednafenInstance.kill_stale()
                return "STUCK(no_regs)"

    except Exception as e:
        print(f"  ERROR: {e}")
        inst.breakpoint_clear()
        inst.quit()
        time.sleep(1)
        MednafenInstance.kill_stale()
        return f"ERROR({e})"


def main():
    shift = int(sys.argv[1]) if len(sys.argv) > 1 else 0
    print(f"Quick Boot Check: shift=+{shift}")
    print("=" * 50)
    result = check_boot(shift)
    print(f"\nRESULT: {result}")
    return 0 if "BOOT_OK" in result else 1


if __name__ == "__main__":
    sys.exit(main())
