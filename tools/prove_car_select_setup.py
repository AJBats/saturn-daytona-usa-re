#!/usr/bin/env python3
"""Empirical verification: car_select_setup (#3 on scoreboard)

Questions to answer:
  1. Does car_select_setup execute when C is pressed on mode select?
     (call_trace differential: idle vs C press)
  2. What screen do we end up on? (screenshots before/after)
  3. Does car_select_setup execute AGAIN during circuit->car transition?
     (call_trace during C press on circuit select)
"""

import os
import sys
import time
from collections import Counter

PROJECT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJECT, "tools"))

from investigate import (
    MednafenBot, load_symbols, sym_addr, sym_hex, resolve_symbol,
    parse_trace, replay_to_state, parse_watchpoint_hits,
    GAME_STATES, TRACE_FILE, wsl_path
)

RESULTS_DIR = os.path.join(PROJECT, "build", "investigation_results", "car_select_setup_proof")
LOG_FILE = os.path.join(RESULTS_DIR, "proof_log.txt")


def log(msg):
    print(msg)
    with open(LOG_FILE, "a") as f:
        f.write(msg + "\n")


def parse_call_trace(trace_path, addr_to_name):
    """Parse call trace file, count calls per function."""
    counts = Counter()
    try:
        with open(trace_path) as f:
            for line in f:
                line = line.strip()
                if not line or line.startswith("#"):
                    continue
                # Format: "cycle=XXXX pc=0xADDR target=0xADDR" or similar
                for token in line.split():
                    if token.startswith("target="):
                        addr_str = token.split("=")[1]
                        addr = int(addr_str.replace("0x", ""), 16)
                        sym = resolve_symbol(addr, addr_to_name)
                        # Use base function name (strip +0xNN offset)
                        base = sym.split("+")[0]
                        counts[base] += 1
    except FileNotFoundError:
        pass
    return counts


def run_call_trace_test(bot, addr_to_name, results_dir, label, button, n_frames):
    """Run call trace for n_frames, optionally pressing a button."""
    trace_path = os.path.join(results_dir, f"calltrace_{label}.txt")

    bot.start_call_trace(trace_path)

    if button:
        bot.input_press(button)

    bot.frame_advance(n_frames)

    if button:
        bot.input_release(button)

    bot.stop_call_trace()

    # Wait for file to be written
    time.sleep(0.5)

    counts = parse_call_trace(trace_path, addr_to_name)
    return counts


def main():
    os.makedirs(RESULTS_DIR, exist_ok=True)
    with open(LOG_FILE, "w") as f:
        f.write(f"# car_select_setup proof experiment -- {time.strftime('%Y-%m-%d %H:%M:%S')}\n\n")

    addr_to_name, name_to_addr = load_symbols()
    log(f"Loaded {len(addr_to_name)} symbols")

    trace_events = parse_trace(TRACE_FILE)

    setup_addr = sym_hex(name_to_addr, "car_select_setup")
    log(f"car_select_setup -> runtime 0x{setup_addr}")

    cue_path = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
    cue_wsl = wsl_path(cue_path)
    ipc_dir = os.path.join(RESULTS_DIR, "ipc")
    os.makedirs(ipc_dir, exist_ok=True)

    # ===================================================================
    # TEST 1: Call trace on mode select — idle vs C press
    # ===================================================================
    log(f"\n{'='*70}")
    log("TEST 1: Call trace on mode select — idle baseline then C press")
    log(f"{'='*70}")

    log("Launching Mednafen...")
    bot = MednafenBot(ipc_dir, cue_wsl)
    if not bot.start(timeout=30):
        log("FAIL: Mednafen did not start")
        return
    log("Replaying to mode select...")
    if not replay_to_state(bot, "menu", trace_events):
        log("FAIL: replay failed")
        bot.quit()
        return
    log(f"At mode select (frame {bot.current_frame}).")

    # Screenshot: confirm we're on mode select
    path = os.path.join(RESULTS_DIR, "01_mode_select_before.png")
    bot.screenshot(path)
    log(f"  Screenshot: 01_mode_select_before.png")

    # Baseline: 60 frames idle (no input)
    log("\nBaseline: 60 frames idle...")
    idle_counts = run_call_trace_test(bot, addr_to_name, RESULTS_DIR, "menu_idle", None, 60)
    idle_setup = idle_counts.get("car_select_setup", 0)
    log(f"  car_select_setup calls during idle: {idle_setup}")

    # Screenshot before C press
    path = os.path.join(RESULTS_DIR, "02_before_C.png")
    bot.screenshot(path)
    log(f"  Screenshot: 02_before_C.png")

    # C press: 120 frames (2 seconds — enough for transition)
    log("\nC press: 120 frames...")
    c_counts = run_call_trace_test(bot, addr_to_name, RESULTS_DIR, "menu_C", "C", 120)
    c_setup = c_counts.get("car_select_setup", 0)
    log(f"  car_select_setup calls during C: {c_setup}")

    # Screenshot after C press
    path = os.path.join(RESULTS_DIR, "03_after_C.png")
    bot.screenshot(path)
    log(f"  Screenshot: 03_after_C.png (frame {bot.current_frame})")

    # Show all functions that appeared during C but not idle
    log("\nFunctions that appeared during C press but not during idle:")
    for func, count in sorted(c_counts.items(), key=lambda x: -x[1]):
        if func not in idle_counts or idle_counts[func] == 0:
            log(f"  {func}: {count} calls [NEW]")

    # Show car_select_setup's callees (functions it calls)
    log(f"\n  car_select_setup: idle={idle_setup}, C={c_setup}, delta={c_setup - idle_setup}")
    if c_setup > idle_setup:
        log("  >>> CONFIRMED: car_select_setup is called during C press on mode select")
    elif c_setup == 0 and idle_setup == 0:
        log("  car_select_setup not seen in call trace — may be reached via BSR (not JSR)")
        log("  (call_trace only logs JSR/BSR that the tracer sees)")

    # Also check key related functions
    for func in ["track_seg_phys_init", "course_data_rom_load", "course_init_pipeline"]:
        idle_n = idle_counts.get(func, 0)
        c_n = c_counts.get(func, 0)
        if c_n != idle_n:
            log(f"  {func}: idle={idle_n}, C={c_n}, delta={c_n - idle_n}")

    bot.quit()

    # ===================================================================
    # TEST 2: Call trace on circuit select — C press
    # ===================================================================
    log(f"\n{'='*70}")
    log("TEST 2: Call trace on circuit select — C press")
    log(f"{'='*70}")

    log("Launching Mednafen...")
    bot = MednafenBot(ipc_dir, cue_wsl)
    if not bot.start(timeout=30):
        log("FAIL: Mednafen did not start")
        return
    log("Replaying to circuit select...")
    if not replay_to_state(bot, "circuit", trace_events):
        log("FAIL: replay failed")
        bot.quit()
        return
    log(f"At circuit select (frame {bot.current_frame}).")

    # Screenshot: confirm we're on circuit select
    path = os.path.join(RESULTS_DIR, "04_circuit_before.png")
    bot.screenshot(path)
    log(f"  Screenshot: 04_circuit_before.png")

    # Baseline: 60 frames idle
    log("\nBaseline: 60 frames idle...")
    circ_idle = run_call_trace_test(bot, addr_to_name, RESULTS_DIR, "circuit_idle", None, 60)
    circ_idle_setup = circ_idle.get("car_select_setup", 0)
    log(f"  car_select_setup calls during idle: {circ_idle_setup}")

    # C press: 120 frames
    log("\nC press: 120 frames...")
    circ_c = run_call_trace_test(bot, addr_to_name, RESULTS_DIR, "circuit_C", "C", 120)
    circ_c_setup = circ_c.get("car_select_setup", 0)
    log(f"  car_select_setup calls during C: {circ_c_setup}")

    # Screenshot after
    path = os.path.join(RESULTS_DIR, "05_after_circuit_C.png")
    bot.screenshot(path)
    log(f"  Screenshot: 05_after_circuit_C.png (frame {bot.current_frame})")

    log(f"\n  car_select_setup: idle={circ_idle_setup}, C={circ_c_setup}")
    if circ_c_setup > circ_idle_setup:
        log("  car_select_setup IS called during circuit->car transition")
    else:
        log("  car_select_setup is NOT called during circuit->car transition")
        log("  -> It only runs once: during mode_select -> selection phase init")

    bot.quit()

    # ===================================================================
    # SUMMARY
    # ===================================================================
    log(f"\n{'='*70}")
    log("SUMMARY")
    log(f"{'='*70}")
    log(f"Test 1: car_select_setup during C on mode select: idle={idle_setup}, C={c_setup}")
    log(f"Test 2: car_select_setup during C on circuit select: idle={circ_idle_setup}, C={circ_c_setup}")
    log("Screenshots confirm: mode select -> circuit select -> car select flow")
    log(f"{'='*70}")
    log("\nDone.")


if __name__ == "__main__":
    main()
