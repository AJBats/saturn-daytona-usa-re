#!/usr/bin/env python3
"""Definitive test: when does car_select_setup execute?

Test 0: SANITY CHECK — breakpoint on state_mode_select_active (known to run
        every frame at mode select). Proves breakpoints actually work.

Test 1: Breakpoint during car->race transition (the one we haven't tested).
        Replay to car select, set BP, press C, continue_to_break.

Test 2: Breakpoint during full trace from bios through racing.
        Set BP before ANY replay, use continue to run freely through each
        state transition, checking for hits at each stage.
"""

import os
import sys
import time

PROJECT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJECT, "tools"))

from investigate import (
    MednafenBot, load_symbols, sym_hex,
    parse_trace, replay_to_state,
    GAME_STATES, TRACE_FILE, wsl_path
)

RESULTS_DIR = os.path.join(PROJECT, "build", "investigation_results", "car_select_setup_proof")


def log(msg):
    print(msg)
    log_path = os.path.join(RESULTS_DIR, "full_test_log.txt")
    with open(log_path, "a") as f:
        f.write(msg + "\n")


def read_ack_file(bot):
    """Read raw ack file contents (for debugging breakpoint state)."""
    try:
        with open(bot.ack_file) as f:
            return f.read().strip()
    except (IOError, FileNotFoundError):
        return None


def main():
    os.makedirs(RESULTS_DIR, exist_ok=True)
    with open(os.path.join(RESULTS_DIR, "full_test_log.txt"), "w") as f:
        f.write(f"# car_select_setup full test -- {time.strftime('%Y-%m-%d %H:%M:%S')}\n\n")

    addr_to_name, name_to_addr = load_symbols()
    trace_events = parse_trace(TRACE_FILE)

    setup_addr = sym_hex(name_to_addr, "car_select_setup")
    active_addr = sym_hex(name_to_addr, "state_mode_select_active")
    log(f"car_select_setup -> 0x{setup_addr}")
    log(f"state_mode_select_active -> 0x{active_addr}")

    cue_path = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
    cue_wsl = wsl_path(cue_path)
    ipc_dir = os.path.join(RESULTS_DIR, "ipc")
    os.makedirs(ipc_dir, exist_ok=True)

    # ===================================================================
    # TEST 0: Sanity check — breakpoint on known function
    # ===================================================================
    log(f"\n{'='*70}")
    log("TEST 0: SANITY CHECK — breakpoint on state_mode_select_active")
    log(f"{'='*70}")
    log("This function runs every frame during mode select.")
    log("If breakpoint doesn't fire, the mechanism is broken.\n")

    bot = MednafenBot(ipc_dir, cue_wsl)
    if not bot.start(timeout=30):
        log("FAIL: start")
        return

    if not replay_to_state(bot, "menu", trace_events):
        log("FAIL: replay to menu")
        bot.quit()
        return
    log(f"At mode select (frame {bot.current_frame}).")
    bot.screenshot(os.path.join(RESULTS_DIR, "full_00_menu.png"))

    log(f"Setting breakpoint on state_mode_select_active (0x{active_addr})...")
    ack = bot.set_breakpoint(active_addr)
    log(f"  BP set ack: {ack}")

    log("Sending continue, expecting immediate hit...")
    ack = bot.continue_to_break(timeout=30)

    if ack and "break" in str(ack).lower():
        log(">>> SANITY CHECK PASSED: breakpoint mechanism works!")
        log(f"  Ack: {ack}")
        regs = bot.dump_regs()
        log(f"  Registers: {regs}")
    else:
        log(">>> SANITY CHECK FAILED: breakpoints do NOT work!")
        log(f"  Ack: {ack}")
        raw = read_ack_file(bot)
        log(f"  Raw ack file: {raw}")
        log("  ALL PRIOR BREAKPOINT EXPERIMENTS ARE INVALID.")
        bot.quit()
        return

    bot.clear_breakpoints()
    bot.quit()

    # ===================================================================
    # TEST 1: Breakpoint during car -> race transition
    # ===================================================================
    log(f"\n{'='*70}")
    log("TEST 1: Breakpoint on car_select_setup during car -> race")
    log(f"{'='*70}")
    log("This is the transition we never tested.\n")

    bot = MednafenBot(ipc_dir, cue_wsl)
    if not bot.start(timeout=30):
        log("FAIL: start")
        return

    if not replay_to_state(bot, "car", trace_events):
        log("FAIL: replay to car")
        bot.quit()
        return
    log(f"At car select (frame {bot.current_frame}).")
    bot.screenshot(os.path.join(RESULTS_DIR, "full_01_car.png"))

    log(f"Setting breakpoint on car_select_setup (0x{setup_addr})...")
    bot.set_breakpoint(setup_addr)

    log("Pressing C (confirm car -> race)...")
    bot.input_press("C")

    log("Continuing to breakpoint (120s timeout)...")
    ack = bot.continue_to_break(timeout=120)

    if ack and "break" in str(ack).lower():
        log(">>> HIT: car_select_setup fires during car -> race!")
        log(f"  Ack: {ack}")
        regs = bot.dump_regs()
        log(f"  Registers: {regs}")
        bot.screenshot(os.path.join(RESULTS_DIR, "full_02_hit_car_race.png"))
    else:
        log(">>> NOT HIT during car -> race transition (120s)")
        raw = read_ack_file(bot)
        log(f"  Raw ack: {raw}")

    bot.clear_breakpoints()
    bot.input_release("C")
    bot.quit()

    # ===================================================================
    # TEST 2: Breakpoint through each state transition individually
    # ===================================================================
    transitions = [
        ("bios",    "attract", "BIOS -> attract",     None),
        ("attract", "title",   "attract -> title",    "START"),
        ("title",   "menu",    "title -> mode select", "START"),
        ("menu",    "circuit", "mode select -> circuit select", "C"),
        ("circuit", "car",     "circuit -> car select", "C"),
        # car -> race is Test 1 above
    ]

    log(f"\n{'='*70}")
    log("TEST 2: Breakpoint on car_select_setup through each transition")
    log(f"{'='*70}")

    for from_state, to_state, label, button in transitions:
        log(f"\n--- {label} ---")

        bot = MednafenBot(ipc_dir, cue_wsl)
        if not bot.start(timeout=30):
            log(f"FAIL: start for {label}")
            continue

        # Replay to the pre-transition state (no breakpoint, fast)
        if from_state != "bios":
            if not replay_to_state(bot, from_state, trace_events):
                log(f"FAIL: replay to {from_state}")
                bot.quit()
                continue
        log(f"  At {from_state} (frame {bot.current_frame})")

        # Set breakpoint
        bot.set_breakpoint(setup_addr)

        # Press transition button (if any — bios auto-advances)
        if button:
            bot.input_press(button)
            log(f"  Pressed {button}, continuing (60s timeout)...")
        else:
            log(f"  No button (auto-transition), continuing (60s timeout)...")

        ack = bot.continue_to_break(timeout=60)

        if ack and "break" in str(ack).lower():
            log(f"  >>> HIT during {label}!")
            log(f"  Ack: {ack}")
            regs = bot.dump_regs()
            log(f"  Registers: {regs}")
            bot.screenshot(os.path.join(RESULTS_DIR, f"full_t2_{to_state}_hit.png"))
        else:
            log(f"  NOT HIT during {label}")

        bot.clear_breakpoints()
        if button:
            bot.input_release(button)
        bot.quit()

    # ===================================================================
    # SUMMARY
    # ===================================================================
    log(f"\n{'='*70}")
    log("SUMMARY")
    log(f"{'='*70}")
    log("Test 0: Sanity check (breakpoint mechanism works?)")
    log("Test 1: car->race transition")
    log("Test 2: Every other transition individually")
    log("If car_select_setup was NOT hit in any test, the name may be wrong")
    log("or the function may only fire in Saturn Mode (not Arcade Mode).")
    log(f"{'='*70}")
    log("\nDone.")


if __name__ == "__main__":
    main()
