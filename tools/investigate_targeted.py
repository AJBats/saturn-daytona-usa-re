#!/usr/bin/env python3
"""Targeted follow-up investigations for specific variables.

Focuses on:
1. Car select: watchpoint on sym_06085FF0 (car index) during RIGHT
2. Circuit select: wider memory scan + watchpoint on flag area during LEFT
3. Race: watchpoint on player car struct position fields during LEFT steering

Usage:
    python tools/investigate_targeted.py
"""

import os
import sys
import time

PROJECT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJECT, "tools"))

from investigate import (
    MednafenBot, load_symbols, sym_addr, sym_hex, resolve_symbol,
    parse_trace, replay_to_state, experiment_watchpoint,
    experiment_memory_diff, experiment_call_trace_diff,
    GAME_STATES, TRACE_FILE, wsl_path, log as base_log
)
import investigate

RESULTS_DIR = os.path.join(PROJECT, "build", "investigation_results", "targeted")
LOG_FILE = os.path.join(RESULTS_DIR, "targeted_log.txt")


def log(msg):
    print(msg)
    with open(LOG_FILE, "a") as f:
        f.write(msg + "\n")


def run_single_state(state, func, addr_to_name, name_to_addr, trace_events):
    """Launch Mednafen, replay to state, run investigation func, quit."""
    cue_path = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
    cue_wsl = wsl_path(cue_path)

    ipc_dir = os.path.join(PROJECT, "build", "investigation_results", "targeted", "ipc")
    os.makedirs(ipc_dir, exist_ok=True)

    log(f"\nLaunching Mednafen...")
    bot = MednafenBot(ipc_dir, cue_wsl)
    if not bot.start(timeout=30):
        log("FAIL: Mednafen did not start")
        return
    log("Ready.")

    log(f"Replaying trace to {state}...")
    if not replay_to_state(bot, state, trace_events):
        log(f"FAIL: Could not replay to {state}")
        bot.quit()
        return
    log(f"At {state} (frame {bot.current_frame}).")

    state_dir = os.path.join(RESULTS_DIR, state)
    os.makedirs(state_dir, exist_ok=True)

    func(bot, addr_to_name, name_to_addr, state_dir)
    log(f"\nDone with {state}.")
    bot.quit()


def investigate_car_targeted(bot, addr_to_name, name_to_addr, results_dir):
    """Targeted car select: watchpoint on sym_06085FF0 (car index byte)."""
    log("\n=== CAR SELECT TARGETED ===")

    # sym_06085FF0 = current car index (byte, 0-7)
    car_idx_addr = sym_hex(name_to_addr, "sym_06085FF0")
    if car_idx_addr:
        log(f"  Car index variable: 0x{car_idx_addr} (sym_06085FF0)")

        # Watchpoint during RIGHT (next car)
        experiment_watchpoint(
            bot, addr_to_name, car_idx_addr, "RIGHT",
            f"Car Select RIGHT — car index writer (0x{car_idx_addr})",
            n_frames=3
        )

        # Watchpoint during LEFT (prev car)
        experiment_watchpoint(
            bot, addr_to_name, car_idx_addr, "LEFT",
            f"Car Select LEFT — car index writer (0x{car_idx_addr})",
            n_frames=3
        )
    else:
        log("  Symbol sym_06085FF0 not found — skipping car index watchpoints")

    # sym_06085FF1 = input dirty flag
    dirty_addr = sym_hex(name_to_addr, "sym_06085FF1")
    if dirty_addr:
        log(f"  Dirty flag variable: 0x{dirty_addr} (sym_06085FF1)")
        experiment_watchpoint(
            bot, addr_to_name, dirty_addr, "RIGHT",
            f"Car Select RIGHT — dirty flag writer (0x{dirty_addr})",
            n_frames=3
        )


def investigate_circuit_targeted(bot, addr_to_name, name_to_addr, results_dir):
    """Targeted circuit select: wider memory scan + flag area watchpoints."""
    log("\n=== CIRCUIT SELECT TARGETED ===")

    # The mode_select_handler checks DOWN (0x2000) and UP (0x1000) which
    # are D-pad DOWN/UP buttons. On the circuit select screen, LEFT/RIGHT
    # are used to browse. Since the handler code checks for 0x2000/0x1000,
    # the LEFT/RIGHT buttons (0x4000/0x8000) won't trigger those paths.
    # The selection change must happen in the tail-called per-item renderer.

    # Try scanning the flag/index area at 0x06085F00-0x06086000
    flag_real = sym_addr(name_to_addr, "sym_06085FF0")
    if flag_real:
        flag_base = flag_real & ~0xFF
        experiment_memory_diff(
            bot, addr_to_name, flag_base, 0x100, "RIGHT",
            f"Circuit Select RIGHT — flag area scan (0x{flag_base:08X})",
            results_dir
        )

    # Also scan the game state area at sym_0605AD10 region
    gs_real = sym_addr(name_to_addr, "sym_0605AD10")
    if gs_real:
        gs_base = gs_real & ~0xFF
        experiment_memory_diff(
            bot, addr_to_name, gs_base, 0x200, "RIGHT",
            f"Circuit Select RIGHT — game state area scan (0x{gs_base:08X})",
            results_dir
        )

    # Scan near sym_0607887A (transition timer) — might be near circuit selection
    timer_real = sym_addr(name_to_addr, "sym_0607887A")
    if timer_real:
        timer_base = timer_real & ~0xFF
        experiment_memory_diff(
            bot, addr_to_name, timer_base, 0x200, "RIGHT",
            f"Circuit Select RIGHT — timer area scan (0x{timer_base:08X})",
            results_dir
        )

    # Scan the dispatch table area (sym_0605D250)
    disp_real = sym_addr(name_to_addr, "sym_0605D250")
    if disp_real:
        disp_base = (disp_real - 0x100) & ~0xFF
        experiment_memory_diff(
            bot, addr_to_name, disp_base, 0x400, "RIGHT",
            f"Circuit Select RIGHT — dispatch table area (0x{disp_base:08X})",
            results_dir
        )

    # Direct watchpoint on the mode select index (sym_0605D244)
    # In case LEFT/RIGHT somehow maps to DOWN/UP in this context
    idx_addr = sym_hex(name_to_addr, "sym_0605D244")
    if idx_addr:
        experiment_watchpoint(
            bot, addr_to_name, idx_addr, "RIGHT",
            f"Circuit Select RIGHT — selection index watchpoint (0x{idx_addr})",
            n_frames=5
        )

    # Try LEFT too
    if idx_addr:
        experiment_watchpoint(
            bot, addr_to_name, idx_addr, "LEFT",
            f"Circuit Select LEFT — selection index watchpoint (0x{idx_addr})",
            n_frames=5
        )


def investigate_race_targeted(bot, addr_to_name, name_to_addr, results_dir):
    """Targeted race: watchpoint on car struct position/heading during steering."""
    log("\n=== RACE TARGETED ===")

    # sym_06078900 is the player car struct base (87 bytes changed during LEFT)
    # Key offsets that changed significantly:
    #   +0x10-0x13: large position-like values
    #   +0x38-0x3B: another large field
    #   +0x0E-0x0F: angle/heading

    car_base_real = sym_addr(name_to_addr, "sym_06078900")
    if car_base_real:
        log(f"  Player car struct base: 0x{car_base_real:08X} (sym_06078900)")

        # Watchpoint on car[+0x10] (likely X position) during LEFT
        wp_addr = car_base_real + 0x10
        experiment_watchpoint(
            bot, addr_to_name, f"{wp_addr:08X}", "LEFT",
            f"Race LEFT — car struct +0x10 position writer (0x{wp_addr:08X})",
            n_frames=3
        )

        # Watchpoint on car[+0x0C] (likely speed or heading) during LEFT
        wp_addr = car_base_real + 0x0C
        experiment_watchpoint(
            bot, addr_to_name, f"{wp_addr:08X}", "LEFT",
            f"Race LEFT — car struct +0x0C writer (0x{wp_addr:08X})",
            n_frames=3
        )

        # Watchpoint on car[+0x38] (another major change field) during LEFT
        wp_addr = car_base_real + 0x38
        experiment_watchpoint(
            bot, addr_to_name, f"{wp_addr:08X}", "LEFT",
            f"Race LEFT — car struct +0x38 writer (0x{wp_addr:08X})",
            n_frames=3
        )

    # Also try watchpoint on speed variable area for the A button (gas)
    experiment_call_trace_diff(
        bot, addr_to_name, "A", "Race A (gas) — call trace diff", results_dir,
        n_frames_baseline=5, n_frames_input=5
    )


def main():
    os.makedirs(RESULTS_DIR, exist_ok=True)

    # Reset log
    with open(LOG_FILE, "w") as f:
        f.write(f"# Targeted investigation run — {time.strftime('%Y-%m-%d %H:%M:%S')}\n\n")

    # Monkey-patch the log function in investigate module
    investigate.LOG_FILE = LOG_FILE

    addr_to_name, name_to_addr = load_symbols()
    log(f"Loaded {len(addr_to_name)} symbols (addr->name), {len(name_to_addr)} (name->addr)")

    trace_events = parse_trace(TRACE_FILE)
    log(f"Loaded {len(trace_events)} trace events")

    # Run investigations for each state
    investigations = [
        ("car",     investigate_car_targeted),
        ("circuit", investigate_circuit_targeted),
        ("race",    investigate_race_targeted),
    ]

    for state, func in investigations:
        log(f"\n{'='*60}")
        log(f"  Targeted investigation: {state} ({GAME_STATES[state]['description']})")
        log(f"{'='*60}")
        run_single_state(state, func, addr_to_name, name_to_addr, trace_events)

    log(f"\n{'='*60}")
    log(f"All targeted investigations complete.")
    log(f"Full log: {LOG_FILE}")
    log(f"Results: {RESULTS_DIR}")
    log(f"{'='*60}")


if __name__ == "__main__":
    main()
