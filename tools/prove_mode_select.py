#!/usr/bin/env python3
"""Definitive proof: is mode_select_handler correctly named?

Three experiments to close all evidence gaps:

  1. SOLE WRITER: Watchpoint on sym_0605D244 (selection index) with NO input
     for 10 frames. If only mode_select_handler PCs write it, it owns that state.

  2. CONFIRM PATH: Press C on mode select, watchpoint on g_game_state
     (game state). If mode_select_handler writes game_state = 4, confirm is proven.

  3. DISPATCH TABLE: Dump 16 bytes at sym_0605D250 (dispatch table).
     Four function pointers -- resolve against symbol table to identify
     the per-item renderers.

Plus re-verify UP/DOWN with the same standard as prove_input_reader.py.
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

RESULTS_DIR = os.path.join(PROJECT, "build", "investigation_results", "mode_select_proof")
LOG_FILE = os.path.join(RESULTS_DIR, "proof_log.txt")


def log(msg):
    print(msg)
    with open(LOG_FILE, "a") as f:
        f.write(msg + "\n")


def run_watchpoint_test(bot, addr_to_name, wp_addr_hex, button_name, n_frames=2):
    """Set watchpoint, optionally press button, advance frames, read hits."""
    if os.path.exists(bot.wp_file):
        os.remove(bot.wp_file)

    bot.set_watchpoint(wp_addr_hex)

    if button_name:
        bot.input_press(button_name)

    bot.frame_advance(n_frames)

    if button_name:
        bot.input_release(button_name)

    hits = bot.read_watchpoint_hits()
    parsed = parse_watchpoint_hits(hits, addr_to_name)
    bot.clear_watchpoint()

    return parsed


def log_hits(parsed):
    """Pretty-print watchpoint hits."""
    if not parsed:
        log("  No watchpoint hits!")
        return
    log(f"  {len(parsed)} watchpoint hits:")
    for i, hit in enumerate(parsed):
        log(f"    [{i}] PC={hit['pc']} ({hit['pc_sym']})")
        log(f"         PR={hit['pr']} ({hit['pr_sym']})")
        old_val = hit.get('old', '?')
        new_val = hit.get('new', '?')
        log(f"         old={old_val} -> new={new_val}")


def main():
    os.makedirs(RESULTS_DIR, exist_ok=True)
    with open(LOG_FILE, "w") as f:
        f.write(f"# mode_select_handler proof experiment -- {time.strftime('%Y-%m-%d %H:%M:%S')}\n\n")

    addr_to_name, name_to_addr = load_symbols()
    log(f"Loaded {len(addr_to_name)} symbols")

    trace_events = parse_trace(TRACE_FILE)
    log(f"Loaded {len(trace_events)} trace events")

    # Resolve all target addresses
    idx_addr = sym_hex(name_to_addr, "sym_0605D244")
    state_addr = sym_hex(name_to_addr, "g_game_state")
    dispatch_addr = sym_hex(name_to_addr, "sym_0605D250")
    handler_addr = sym_hex(name_to_addr, "mode_select_handler")

    log(f"sym_0605D244 (selection index) -> runtime 0x{idx_addr}")
    log(f"g_game_state (game state)      -> runtime 0x{state_addr}")
    log(f"sym_0605D250 (dispatch table)  -> runtime 0x{dispatch_addr}")
    log(f"mode_select_handler            -> runtime 0x{handler_addr}")

    if not idx_addr or not state_addr:
        log("FAIL: required symbols not found")
        return

    cue_path = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
    cue_wsl = wsl_path(cue_path)
    ipc_dir = os.path.join(RESULTS_DIR, "ipc")
    os.makedirs(ipc_dir, exist_ok=True)

    log("Launching Mednafen...")
    bot = MednafenBot(ipc_dir, cue_wsl)
    if not bot.start(timeout=30):
        log("FAIL: Mednafen did not start")
        return
    log("Ready.")

    log("Replaying to mode select menu...")
    if not replay_to_state(bot, "menu", trace_events):
        log("FAIL: Could not replay to menu")
        bot.quit()
        return
    log(f"At mode select (frame {bot.current_frame}).")

    shot_idx = 0
    def take_screenshot(label):
        nonlocal shot_idx
        path = os.path.join(RESULTS_DIR, f"screenshot_{shot_idx:02d}_{label}.png")
        bot.screenshot(path)
        log(f"  Screenshot saved: screenshot_{shot_idx:02d}_{label}.png")
        shot_idx += 1

    # ===================================================================
    # EXPERIMENT 1: Sole writer test (idle -- no input for 10 frames)
    # ===================================================================
    log(f"\n{'='*70}")
    log("EXPERIMENT 1: SOLE WRITER -- watchpoint on selection index, no input")
    log(f"{'='*70}")
    take_screenshot("exp1_idle_before")
    log(f"Watching sym_0605D244 (0x{idx_addr}) for 10 frames with no button...")

    parsed = run_watchpoint_test(bot, addr_to_name, idx_addr, None, n_frames=10)
    log_hits(parsed)

    if parsed:
        writers = set(hit['pc_sym'] for hit in parsed)
        log(f"\n  Unique writer functions: {writers}")
        all_in_handler = all("mode_select_handler" in w for w in writers)
        log(f"  All writes from mode_select_handler? {'YES' if all_in_handler else 'NO'}")
    else:
        log("  No writes during idle -- selection index is stable (expected)")
    take_screenshot("exp1_idle_after")

    # ===================================================================
    # EXPERIMENT 2: Confirm (C) -- watchpoint on game state
    # (Run BEFORE UP/DOWN to avoid contaminating game state)
    # ===================================================================
    log(f"\n{'='*70}")
    log("EXPERIMENT 2: CONFIRM (C) -- watchpoint on game state")
    log(f"{'='*70}")
    take_screenshot("exp2_confirm_before")
    log(f"Watching g_game_state (0x{state_addr}) during C press...")

    parsed = run_watchpoint_test(bot, addr_to_name, state_addr, "C", n_frames=3)
    log_hits(parsed)

    if parsed:
        writers = set(hit['pc_sym'] for hit in parsed)
        log(f"\n  Unique writer functions: {writers}")
        any_in_handler = any("mode_select_handler" in w for w in writers)
        log(f"  mode_select_handler writes game state? {'YES' if any_in_handler else 'NO'}")

        for hit in parsed:
            try:
                new_int = int(hit['new'].replace("0x", ""), 16)
                log(f"  Game state written: {new_int} (expect 4 for advance)")
            except (ValueError, AttributeError):
                pass
    take_screenshot("exp2_confirm_after")

    # Re-replay to mode select for remaining experiments (confirm may have changed state)
    log("\nRe-replaying to mode select for UP/DOWN tests...")
    bot.quit()
    bot = MednafenBot(ipc_dir, cue_wsl)
    if not bot.start(timeout=30):
        log("FAIL: Mednafen restart failed")
        return
    if not replay_to_state(bot, "menu", trace_events):
        log("FAIL: Could not re-replay to menu")
        bot.quit()
        return
    log(f"Back at mode select (frame {bot.current_frame}).")

    # ===================================================================
    # EXPERIMENT 3: UP/DOWN re-verification
    # ===================================================================
    log(f"\n{'='*70}")
    log("EXPERIMENT 3: UP/DOWN input -- watchpoint on selection index")
    log(f"{'='*70}")

    for button in ["DOWN", "UP"]:
        take_screenshot(f"exp3_{button.lower()}_before")
        log(f"\n--- {button} pressed ---")
        parsed = run_watchpoint_test(bot, addr_to_name, idx_addr, button, n_frames=2)
        log_hits(parsed)

        if parsed:
            writers = set(hit['pc_sym'] for hit in parsed)
            all_in_handler = all("mode_select_handler" in w for w in writers)
            log(f"  All writes from mode_select_handler? {'YES' if all_in_handler else 'NO'}")

            # Check the new value to see the index change
            for hit in parsed:
                try:
                    new_int = int(hit['new'].replace("0x", ""), 16)
                    # Selection index is a byte -- extract lowest byte
                    idx_val = new_int & 0xFF
                    log(f"  Selection index written: {idx_val}")
                except (ValueError, AttributeError):
                    pass
        take_screenshot(f"exp3_{button.lower()}_after")

    # ===================================================================
    # EXPERIMENT 4: Dispatch table dump
    # ===================================================================
    log(f"\n{'='*70}")
    log("EXPERIMENT 4: DISPATCH TABLE -- dump 16 bytes at sym_0605D250")
    log(f"{'='*70}")
    take_screenshot("exp4_dispatch")

    if dispatch_addr:
        dump_path = os.path.join(RESULTS_DIR, "dispatch_table.bin")
        bot.dump_mem_bin(dispatch_addr, "10", dump_path)
        if os.path.exists(dump_path):
            with open(dump_path, "rb") as f:
                data = f.read()
            log(f"  Raw bytes: {' '.join(f'{b:02X}' for b in data)}")

            # Parse as 4 big-endian 32-bit pointers
            if len(data) >= 16:
                log("  Dispatch table entries (4 function pointers):")
                for i in range(4):
                    ptr = int.from_bytes(data[i*4:(i+1)*4], "big")
                    sym = resolve_symbol(ptr, addr_to_name)
                    log(f"    [{i}] 0x{ptr:08X} -> {sym}")
    else:
        log("  sym_0605D250 not found in symbol table -- skipping")

    # ===================================================================
    # SUMMARY
    # ===================================================================
    log(f"\n{'='*70}")
    log("SUMMARY")
    log(f"{'='*70}")
    log("If ALL of the following are true, mode_select_handler is 100% proven:")
    log("  1. Selection index (sym_0605D244) is only written by mode_select_handler PCs")
    log("  2. UP/DOWN change the index value (wrapping 0-3)")
    log("  3. C press causes game_state = 4 write from mode_select_handler")
    log("  4. Dispatch table contains 4 valid function pointers (per-item renderers)")
    log(f"{'='*70}")

    bot.quit()
    log("\nDone.")


if __name__ == "__main__":
    main()
