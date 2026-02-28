#!/usr/bin/env python3
"""Definitive proof: is viewport_coord_calc actually the controller input reader?

Experiment:
  1. Replay to mode select menu
  2. Set watchpoint on sym_06063D98 (the struct read by 30+ functions as "button state")
  3. Advance 1 frame with NO button pressed → record writes and values
  4. Advance 1 frame with DOWN pressed → expect 0x2000 at +2
  5. Advance 1 frame with UP pressed → expect 0x1000 at +2
  6. Advance 1 frame with LEFT pressed → expect 0x4000 at +2

If the same PC (viewport_coord_calc) writes to sym_06063D98, and the values
at offset +2 change to match the pressed button mask, that's 100% conclusive:
viewport_coord_calc IS the controller input state updater.
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

RESULTS_DIR = os.path.join(PROJECT, "build", "investigation_results", "input_proof")
LOG_FILE = os.path.join(RESULTS_DIR, "proof_log.txt")


def log(msg):
    print(msg)
    with open(LOG_FILE, "a") as f:
        f.write(msg + "\n")


def run_button_test(bot, addr_to_name, wp_addr_hex, button_name, n_frames=2):
    """Set watchpoint, optionally press button, advance frames, read hits."""
    # Clear any previous hits
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


def main():
    os.makedirs(RESULTS_DIR, exist_ok=True)
    with open(LOG_FILE, "w") as f:
        f.write(f"# Controller input proof experiment — {time.strftime('%Y-%m-%d %H:%M:%S')}\n\n")

    addr_to_name, name_to_addr = load_symbols()
    log(f"Loaded {len(addr_to_name)} symbols")

    trace_events = parse_trace(TRACE_FILE)
    log(f"Loaded {len(trace_events)} trace events")

    # Find the runtime address for sym_06063D98
    input_addr = sym_hex(name_to_addr, "sym_06063D98")
    if not input_addr:
        log("FAIL: sym_06063D98 not found in symbol table")
        return
    log(f"Target: sym_06063D98 at runtime 0x{input_addr}")

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

    # Also dump the raw memory at sym_06063D98 to see the full 16-byte struct
    dump_path = os.path.join(RESULTS_DIR, "input_struct_idle.bin")
    bot.dump_mem_bin(input_addr, "10", dump_path)
    if os.path.exists(dump_path):
        with open(dump_path, "rb") as f:
            data = f.read()
        hex_str = " ".join(f"{b:02X}" for b in data)
        log(f"  Idle struct dump (16 bytes): {hex_str}")

    # Test matrix: (description, button, expected_mask_at_+2)
    tests = [
        ("No button (baseline)", None,    None),
        ("DOWN pressed",         "DOWN",  0x2000),
        ("UP pressed",           "UP",    0x1000),
        ("LEFT pressed",         "LEFT",  0x4000),
        ("RIGHT pressed",        "RIGHT", 0x8000),
        ("C pressed (confirm)",  "C",     None),  # C = 0x0200? 0x0100? observe
    ]

    log(f"\n{'='*70}")
    log(f"EXPERIMENT: Watchpoint on sym_06063D98 (0x{input_addr})")
    log(f"{'='*70}")

    for desc, button, expected in tests:
        log(f"\n--- Test: {desc} ---")
        parsed = run_button_test(bot, addr_to_name, input_addr, button, n_frames=2)

        if not parsed:
            log(f"  No watchpoint hits!")
            continue

        log(f"  {len(parsed)} watchpoint hits:")
        for i, hit in enumerate(parsed):
            log(f"    [{i}] PC={hit['pc']} ({hit['pc_sym']})")
            log(f"         PR={hit['pr']} ({hit['pr_sym']})")
            old_val = hit.get('old', '?')
            new_val = hit.get('new', '?')
            log(f"         old={old_val} -> new={new_val}")

            # Check the 32-bit value: upper 16 bits = word[0], lower 16 bits = word[+2]
            # SH-2 is big-endian: 0xAAAABBBB → addr+0=0xAAAA, addr+2=0xBBBB
            try:
                new_int = int(new_val.replace("0x", ""), 16)
                word_at_plus2 = new_int & 0xFFFF
                word_at_plus0 = (new_int >> 16) & 0xFFFF
                log(f"         word[+0]=0x{word_at_plus0:04X}  word[+2]=0x{word_at_plus2:04X}")
                if expected and (word_at_plus2 & expected):
                    log(f"         >>> MATCH: word[+2] contains 0x{expected:04X} ({desc}) <<<")
            except (ValueError, AttributeError):
                pass

        # After the test, dump memory to see the struct state
        dump_path = os.path.join(RESULTS_DIR, f"input_struct_{button or 'idle'}.bin")
        bot.dump_mem_bin(input_addr, "10", dump_path)
        if os.path.exists(dump_path):
            with open(dump_path, "rb") as f:
                data = f.read()
            hex_str = " ".join(f"{b:02X}" for b in data)
            log(f"  Post-test struct dump: {hex_str}")

    log(f"\n{'='*70}")
    log("ANALYSIS")
    log(f"{'='*70}")
    log("If viewport_coord_calc PC appears in ALL tests, AND word[+2] contains")
    log("the expected button mask only when that button is pressed, then:")
    log("  viewport_coord_calc IS the controller input state updater.")
    log("  It should be renamed to controller_input_update (or similar).")
    log(f"{'='*70}")

    bot.quit()
    log("\nDone.")


if __name__ == "__main__":
    main()
