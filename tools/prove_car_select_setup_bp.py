#!/usr/bin/env python3
"""Direct breakpoint test: does car_select_setup execute during C on mode select?"""

import os
import sys
import time

PROJECT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJECT, "tools"))

from investigate import (
    MednafenBot, load_symbols, sym_hex,
    parse_trace, replay_to_state,
    TRACE_FILE, wsl_path
)

RESULTS_DIR = os.path.join(PROJECT, "build", "investigation_results", "car_select_setup_proof")


def log(msg):
    print(msg)
    log_path = os.path.join(RESULTS_DIR, "breakpoint_log.txt")
    with open(log_path, "a") as f:
        f.write(msg + "\n")


def main():
    os.makedirs(RESULTS_DIR, exist_ok=True)
    with open(os.path.join(RESULTS_DIR, "breakpoint_log.txt"), "w") as f:
        f.write(f"# breakpoint test -- {time.strftime('%Y-%m-%d %H:%M:%S')}\n\n")

    addr_to_name, name_to_addr = load_symbols()
    trace_events = parse_trace(TRACE_FILE)
    setup_addr = sym_hex(name_to_addr, "car_select_setup")
    log(f"car_select_setup -> 0x{setup_addr}")

    cue_path = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
    cue_wsl = wsl_path(cue_path)
    ipc_dir = os.path.join(RESULTS_DIR, "ipc")
    os.makedirs(ipc_dir, exist_ok=True)

    # ===================================================================
    # TEST: Breakpoint on car_select_setup, press C on mode select,
    #       advance frames and see if breakpoint fires
    # ===================================================================
    log(f"\n{'='*70}")
    log("Breakpoint on car_select_setup + C on mode select")
    log(f"{'='*70}")

    bot = MednafenBot(ipc_dir, cue_wsl)
    if not bot.start(timeout=30):
        log("FAIL: Mednafen did not start")
        return

    if not replay_to_state(bot, "menu", trace_events):
        log("FAIL: replay failed")
        bot.quit()
        return
    log(f"At mode select (frame {bot.current_frame}).")

    # Screenshot to confirm
    bot.screenshot(os.path.join(RESULTS_DIR, "bp_01_menu.png"))
    log("  Screenshot: bp_01_menu.png")

    # Set breakpoint on car_select_setup
    log(f"Setting breakpoint on car_select_setup (0x{setup_addr})...")
    ack = bot.set_breakpoint(setup_addr)
    log(f"  Breakpoint response: {ack}")

    # Press C
    bot.input_press("C")
    log(f"Pressed C, now continuing to breakpoint (timeout 30s)...")

    # Try to hit the breakpoint
    ack = bot.continue_to_break(timeout=30)
    log(f"  Continue result: {ack}")

    if ack and "break" in str(ack).lower():
        log(">>> BREAKPOINT HIT: car_select_setup DOES execute!")
        # Dump registers to see the state
        regs = bot.dump_regs()
        log(f"  Registers: {regs}")
        # Screenshot at breakpoint
        bot.screenshot(os.path.join(RESULTS_DIR, "bp_02_at_breakpoint.png"))
        log("  Screenshot: bp_02_at_breakpoint.png")
    else:
        log(">>> BREAKPOINT NOT HIT within 30s")
        log("    car_select_setup does NOT execute during C on mode select")

    bot.clear_breakpoints()
    bot.input_release("C")

    # Take screenshot of current state
    bot.frame_advance(60)
    bot.screenshot(os.path.join(RESULTS_DIR, "bp_03_after.png"))
    log(f"  Screenshot: bp_03_after.png (frame {bot.current_frame})")

    bot.quit()
    log("\nDone.")


if __name__ == "__main__":
    main()
