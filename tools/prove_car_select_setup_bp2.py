#!/usr/bin/env python3
"""When does car_select_setup ACTUALLY execute?

Test 1: Breakpoint during circuit select C press (circuit -> car transition)
Test 2: Breakpoint set before replaying through the golden trace
        (catch it whenever it fires during normal gameplay)
"""

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
    log_path = os.path.join(RESULTS_DIR, "breakpoint_log2.txt")
    with open(log_path, "a") as f:
        f.write(msg + "\n")


def main():
    os.makedirs(RESULTS_DIR, exist_ok=True)
    with open(os.path.join(RESULTS_DIR, "breakpoint_log2.txt"), "w") as f:
        f.write(f"# breakpoint test 2 -- {time.strftime('%Y-%m-%d %H:%M:%S')}\n\n")

    addr_to_name, name_to_addr = load_symbols()
    trace_events = parse_trace(TRACE_FILE)
    setup_addr = sym_hex(name_to_addr, "car_select_setup")
    log(f"car_select_setup -> 0x{setup_addr}")

    cue_path = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
    cue_wsl = wsl_path(cue_path)
    ipc_dir = os.path.join(RESULTS_DIR, "ipc")
    os.makedirs(ipc_dir, exist_ok=True)

    # ===================================================================
    # TEST 1: Breakpoint during circuit -> car transition
    # ===================================================================
    log(f"\n{'='*70}")
    log("TEST 1: Breakpoint on car_select_setup during circuit -> car")
    log(f"{'='*70}")

    bot = MednafenBot(ipc_dir, cue_wsl)
    if not bot.start(timeout=30):
        log("FAIL: start")
        return

    if not replay_to_state(bot, "circuit", trace_events):
        log("FAIL: replay")
        bot.quit()
        return
    log(f"At circuit select (frame {bot.current_frame}).")
    bot.screenshot(os.path.join(RESULTS_DIR, "bp2_01_circuit.png"))

    bot.set_breakpoint(setup_addr)
    bot.input_press("C")
    log("Pressed C, continuing to breakpoint (30s timeout)...")
    ack = bot.continue_to_break(timeout=30)

    if ack and "break" in str(ack).lower():
        log(">>> HIT: car_select_setup executes during circuit -> car!")
        regs = bot.dump_regs()
        log(f"  Registers: {regs}")
        bot.screenshot(os.path.join(RESULTS_DIR, "bp2_02_hit.png"))
    else:
        log(">>> NOT HIT during circuit -> car transition")

    bot.clear_breakpoints()
    bot.input_release("C")
    bot.quit()

    # ===================================================================
    # TEST 2: Set breakpoint BEFORE replay, let golden trace play through
    # ===================================================================
    log(f"\n{'='*70}")
    log("TEST 2: Breakpoint set early, replay golden trace through car select")
    log(f"{'='*70}")

    bot = MednafenBot(ipc_dir, cue_wsl)
    if not bot.start(timeout=30):
        log("FAIL: start")
        return

    # Set breakpoint before any replay
    bot.set_breakpoint(setup_addr)
    log(f"Breakpoint set on 0x{setup_addr}")

    # Replay to car select state (this replays through mode select + circuit select + into car)
    log("Replaying golden trace to car select state...")
    log("  (breakpoint should fire if car_select_setup runs during the replay)")
    result = replay_to_state(bot, "car", trace_events)

    if result:
        log(f"Replay completed to car select (frame {bot.current_frame})")
        log("  breakpoint did NOT fire during entire mode->circuit->car flow")
        bot.screenshot(os.path.join(RESULTS_DIR, "bp2_03_car_select.png"))
    else:
        # Replay might have been interrupted by breakpoint
        log(f"Replay interrupted at frame {bot.current_frame}")
        log("  checking if breakpoint fired...")
        regs = bot.dump_regs()
        if regs:
            log(f"  Registers: {regs}")
        bot.screenshot(os.path.join(RESULTS_DIR, "bp2_03_at_break.png"))

    bot.clear_breakpoints()
    bot.quit()
    log("\nDone.")


if __name__ == "__main__":
    main()
