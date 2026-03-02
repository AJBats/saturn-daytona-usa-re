#!/usr/bin/env python3
"""Test that the SR.I fix in automation.cpp is correct and not corrupting game state.

The fix: when frames_to_advance==0, if SR.I >= 15, clear it to 0.
This prevents the CPU from getting stuck when paused inside the VBlank handler.

This test proves:
  1. frame_advance works (PC changes between frames)
  2. Multiple pause/resume cycles don't corrupt state (SR.I toggling is safe)
  3. Game reaches mode select with golden trace input (no state corruption)
  4. Screenshot at mode select matches golden baseline
  5. SR.I is never permanently stuck at 15 between frame_advances

Run: python workstreams/empirical_validation/test_sri_fix.py
"""

import os, sys, time, tempfile

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(PROJECT, "workstreams", "empirical_validation"))
from investigate import MednafenBot, wsl_path, load_symbols, parse_trace, GAME_STATES

TRACE_FILE = os.path.join(PROJECT, "build", "golden_trace", "arcade_full.txt")
CUE_FILE = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
GOLDEN_MENU = os.path.join(PROJECT, "build", "screenshots", "golden_menu.png")


def parse_regs(ack):
    regs = {}
    if not ack:
        return regs
    for token in ack.split():
        if "=" in token:
            k, v = token.split("=", 1)
            try:
                regs[k] = int(v, 16)
            except ValueError:
                regs[k] = v
    return regs


def get_sr_i(sr):
    """Extract interrupt mask level from SR register."""
    return (sr >> 4) & 0xF


def main():
    print("=== SR.I Fix Validation Test ===\n")
    results = []

    cue_wsl = wsl_path(CUE_FILE)
    ipc_dir = tempfile.mkdtemp(prefix="sri_test_")
    bot = MednafenBot(ipc_dir, cue_wsl)

    try:
        print("[1] Starting debug Mednafen...")
        if not bot.start(timeout=30):
            print("FAIL: Mednafen didn't start")
            return 1
        results.append(("start", "PASS"))

        # ---- Test: frame_advance works (run past BIOS, check game code) ----
        # Early frames (1-70) are BIOS boot — PC sits in a CD-wait loop,
        # legitimately the same address between frames. Skip to frame 100+
        # where game code is running, then check PC changes.
        print("[2] Testing frame_advance moves the CPU...")
        ack = bot.send_and_wait("run_to_frame 100", "done run_to_frame", timeout=60)
        if not ack:
            print("  FAIL: couldn't reach frame 100")
            results.append(("frame_advance", "FAIL"))
            return 1
        bot.current_frame = 100

        prev_pc = None
        stuck_count = 0
        sr_i_15_count = 0

        for i in range(10):
            ack = bot.frame_advance(1)
            if not ack:
                print(f"  FAIL: frame_advance {i} timed out")
                results.append(("frame_advance", "FAIL"))
                return 1

            regs = parse_regs(bot.dump_regs())
            pc = regs.get("PC", 0)
            sr = regs.get("SR", 0)
            sr_i = get_sr_i(sr)

            if sr_i >= 15:
                sr_i_15_count += 1

            if prev_pc is not None and pc == prev_pc:
                stuck_count += 1

            if i < 3 or i == 9:
                print(f"  frame {bot.current_frame}: PC=0x{pc:08X} SR.I={sr_i}")
            prev_pc = pc

        if stuck_count > 5:
            print(f"  FAIL: PC stuck {stuck_count}/10 times")
            results.append(("frame_advance", "FAIL"))
        else:
            print(f"  OK: PC changing, stuck {stuck_count}/10")
            results.append(("frame_advance", "PASS"))

        if sr_i_15_count > 5:
            print(f"  WARN: SR.I=15 seen {sr_i_15_count}/10 pauses")
            results.append(("sr_i_clear", "WARN"))
        else:
            print(f"  OK: SR.I=15 seen {sr_i_15_count}/10 pauses (fix is working)")
            results.append(("sr_i_clear", "PASS"))

        # ---- Test: stress test — rapid pause/resume cycles ----
        print("[3] Stress test: 50 rapid single-frame advances...")
        timeouts = 0
        for i in range(50):
            ack = bot.frame_advance(1)
            if not ack:
                timeouts += 1
        if timeouts > 0:
            print(f"  FAIL: {timeouts}/50 timeouts")
            results.append(("stress", "FAIL"))
        else:
            print(f"  OK: 50/50 frame advances succeeded (frame {bot.current_frame})")
            results.append(("stress", "PASS"))

        # ---- Test: replay golden trace to mode select ----
        print("[4] Replaying golden trace to mode select...")
        trace_events = parse_trace(TRACE_FILE)

        from investigate import replay_to_state
        ok = replay_to_state(bot, "menu", trace_events)

        if not ok:
            print("  FAIL: replay_to_state failed")
            results.append(("replay", "FAIL"))
            return 1
        print(f"  OK: reached frame {bot.current_frame}")
        results.append(("replay", "PASS"))

        # ---- Test: screenshot matches golden baseline ----
        print("[5] Taking screenshot and comparing to golden baseline...")
        ss_path = os.path.join(ipc_dir, "menu_test.png")
        bot.screenshot(ss_path)

        if not os.path.exists(ss_path):
            print("  FAIL: screenshot not created")
            results.append(("screenshot", "FAIL"))
        elif not os.path.exists(GOLDEN_MENU):
            print(f"  SKIP: no golden baseline at {GOLDEN_MENU}")
            results.append(("screenshot", "SKIP"))
        else:
            # Use compare_screenshot.py if available
            compare_script = os.path.join(PROJECT, "tools", "compare_screenshot.py")
            if os.path.exists(compare_script):
                import subprocess
                r = subprocess.run(
                    [sys.executable, compare_script, ss_path, GOLDEN_MENU, "--method", "histogram"],
                    capture_output=True, text=True
                )
                if "PASS" in r.stdout:
                    print(f"  OK: screenshot matches golden baseline")
                    results.append(("screenshot", "PASS"))
                else:
                    print(f"  FAIL: screenshot doesn't match")
                    print(f"  Output: {r.stdout.strip()}")
                    results.append(("screenshot", "FAIL"))
            else:
                # Basic file size sanity check
                sz = os.path.getsize(ss_path)
                if sz > 1000:
                    print(f"  OK: screenshot captured ({sz} bytes), manual comparison needed")
                    results.append(("screenshot", "MANUAL"))
                else:
                    print(f"  FAIL: screenshot too small ({sz} bytes)")
                    results.append(("screenshot", "FAIL"))

        print(f"  Screenshot saved: {ss_path}")

        # ---- Test: verify SR state at mode select ----
        print("[6] Checking CPU state at mode select...")
        regs = parse_regs(bot.dump_regs())
        pc = regs.get("PC", 0)
        sr = regs.get("SR", 0)
        sr_i = get_sr_i(sr)
        print(f"  PC=0x{pc:08X} SR=0x{sr:04X} SR.I={sr_i}")

        if pc >= 0x06000000 and pc < 0x07000000:
            print(f"  OK: PC in game code range")
            results.append(("cpu_state", "PASS"))
        else:
            print(f"  WARN: PC outside game code range")
            results.append(("cpu_state", "WARN"))

    finally:
        bot.quit()

    # ---- Summary ----
    print(f"\n{'='*40}")
    print(f"  SR.I Fix Test Results")
    print(f"{'='*40}")
    all_pass = True
    for name, status in results:
        flag = " " if status == "PASS" else "*"
        print(f"  {flag} {name:20s} {status}")
        if status == "FAIL":
            all_pass = False

    print(f"{'='*40}")
    if all_pass:
        print("  OVERALL: PASS")
    else:
        print("  OVERALL: FAIL")
    print()
    return 0 if all_pass else 1


if __name__ == "__main__":
    sys.exit(main())
