#!/usr/bin/env python3
"""Focused experiment: what happens when C is pressed on mode select?

Press C, wait 180 frames (3 seconds), take screenshots every 30 frames,
watchpoint on game_state to see ALL state transitions.
Also test B for comparison.
"""

import os
import sys
import time

PROJECT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJECT, "tools"))

from investigate import (
    MednafenBot, load_symbols, sym_addr, sym_hex, resolve_symbol,
    parse_trace, replay_to_state, parse_watchpoint_hits,
    GAME_STATES, TRACE_FILE, wsl_path
)

RESULTS_DIR = os.path.join(PROJECT, "build", "investigation_results", "mode_select_exp2")
LOG_FILE = os.path.join(RESULTS_DIR, "proof_log.txt")


def log(msg):
    print(msg)
    with open(LOG_FILE, "a") as f:
        f.write(msg + "\n")


def log_hits(parsed):
    if not parsed:
        log("  No watchpoint hits!")
        return
    log(f"  {len(parsed)} watchpoint hits:")
    for i, hit in enumerate(parsed):
        log(f"    [{i}] PC={hit['pc']} ({hit['pc_sym']})")
        log(f"         PR={hit['pr']} ({hit['pr_sym']})")
        log(f"         old={hit.get('old', '?')} -> new={hit.get('new', '?')}")


def run_button_with_timeline(bot, addr_to_name, state_addr_hex, button, results_dir):
    """Press button, take screenshots every 30 frames for 180 frames total,
    watchpoint on game_state the whole time."""
    shot_idx = 0

    # Screenshot before
    path = os.path.join(results_dir, f"{button}_00_before.png")
    bot.screenshot(path)
    log(f"  Screenshot: {button}_00_before.png (frame {bot.current_frame})")
    shot_idx += 1

    # Set watchpoint on game state
    if os.path.exists(bot.wp_file):
        os.remove(bot.wp_file)
    bot.set_watchpoint(state_addr_hex)

    # Press button
    bot.input_press(button)
    log(f"  Pressed {button} at frame {bot.current_frame}")

    # Advance in chunks, screenshot each chunk
    for chunk in range(6):  # 6 x 30 = 180 frames = 3 seconds
        bot.frame_advance(30)
        path = os.path.join(results_dir, f"{button}_{shot_idx:02d}_frame+{(chunk+1)*30}.png")
        bot.screenshot(path)
        log(f"  Screenshot: {button}_{shot_idx:02d}_frame+{(chunk+1)*30}.png (frame {bot.current_frame})")
        shot_idx += 1

    # Release button
    bot.input_release(button)

    # Read all watchpoint hits
    hits = bot.read_watchpoint_hits()
    parsed = parse_watchpoint_hits(hits, addr_to_name)
    bot.clear_watchpoint()

    return parsed


def main():
    os.makedirs(RESULTS_DIR, exist_ok=True)
    with open(LOG_FILE, "w") as f:
        f.write(f"# mode_select experiment 2 -- {time.strftime('%Y-%m-%d %H:%M:%S')}\n\n")

    addr_to_name, name_to_addr = load_symbols()
    log(f"Loaded {len(addr_to_name)} symbols")

    trace_events = parse_trace(TRACE_FILE)

    state_addr = sym_hex(name_to_addr, "g_game_state")
    log(f"g_game_state (game state) -> runtime 0x{state_addr}")

    cue_path = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
    cue_wsl = wsl_path(cue_path)
    ipc_dir = os.path.join(RESULTS_DIR, "ipc")
    os.makedirs(ipc_dir, exist_ok=True)

    # ===================================================================
    # TEST 1: Press C on mode select (A/C = advance to track select)
    # ===================================================================
    log(f"\n{'='*70}")
    log("TEST 1: Press C on mode select -- expect advance to track select")
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

    parsed = run_button_with_timeline(bot, addr_to_name, state_addr, "C", RESULTS_DIR)
    log("\nGame state watchpoint hits during C press:")
    log_hits(parsed)
    if parsed:
        log("\nState transition chain:")
        for hit in parsed:
            log(f"  {hit.get('old','?')} -> {hit.get('new','?')}  by {hit['pc_sym']}")

    bot.quit()

    # ===================================================================
    # TEST 2: Press B on mode select (B = back to title)
    # ===================================================================
    log(f"\n{'='*70}")
    log("TEST 2: Press B on mode select -- expect back to title screen")
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

    parsed = run_button_with_timeline(bot, addr_to_name, state_addr, "B", RESULTS_DIR)
    log("\nGame state watchpoint hits during B press:")
    log_hits(parsed)
    if parsed:
        log("\nState transition chain:")
        for hit in parsed:
            log(f"  {hit.get('old','?')} -> {hit.get('new','?')}  by {hit['pc_sym']}")

    bot.quit()

    # ===================================================================
    # SUMMARY
    # ===================================================================
    log(f"\n{'='*70}")
    log("SUMMARY")
    log(f"{'='*70}")
    log("Compare screenshots and state transitions for C vs B:")
    log("  C should show transition to track select (advance)")
    log("  B should show transition to title screen (back)")
    log("  game_state writes identify which functions handle each path")
    log(f"{'='*70}")
    log("\nDone.")


if __name__ == "__main__":
    main()
