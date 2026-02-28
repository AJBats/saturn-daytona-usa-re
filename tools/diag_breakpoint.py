#!/usr/bin/env python3
"""Minimal breakpoint diagnostic at mode select.

Replicates the EXACT pattern from test_debugger_features.py that passes
(step 1, get PC, set BP, continue) but at mode select instead of frame 200.
"""

import os
import sys
import time
import re

PROJECT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJECT, "tools"))

from investigate import (
    MednafenBot, load_symbols, sym_hex,
    parse_trace, replay_to_state,
    TRACE_FILE, wsl_path
)

RESULTS_DIR = os.path.join(PROJECT, "build", "investigation_results", "bp_diag")


def log(msg):
    print(msg)
    with open(os.path.join(RESULTS_DIR, "diag_log.txt"), "a") as f:
        f.write(msg + "\n")


def main():
    os.makedirs(RESULTS_DIR, exist_ok=True)
    with open(os.path.join(RESULTS_DIR, "diag_log.txt"), "w") as f:
        f.write(f"# breakpoint diag -- {time.strftime('%Y-%m-%d %H:%M:%S')}\n\n")

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

    bot = MednafenBot(ipc_dir, cue_wsl)
    if not bot.start(timeout=30):
        log("FAIL: start")
        return

    # ==============================================
    # TEST A: Breakpoint at frame 200 (passing pattern)
    # ==============================================
    log(f"\n{'='*60}")
    log("TEST A: frame 200 (same as passing test)")
    log(f"{'='*60}")

    ack = bot.send_and_wait("frame_advance 200", "done frame_advance", timeout=120)
    log(f"frame_advance 200: {ack is not None}")
    bot.current_frame = 200

    # Step 1 to get current PC
    ack = bot.send_and_wait("step 1", "done step", timeout=10)
    log(f"step 1 ack: {ack}")
    pc = None
    if ack:
        m = re.search(r'pc=0x([0-9a-fA-F]+)', ack)
        if m:
            pc = m.group(1)
            log(f"Current PC: 0x{pc}")

    if pc:
        # Set BP at current PC, continue — should hit immediately
        ack = bot.send_and_wait(f"breakpoint {pc}", "ok breakpoint", timeout=5)
        log(f"BP set: {ack}")

        ack = bot.send_and_wait("continue", "break", timeout=10)
        if ack and "break" in ack.lower():
            log(f">>> TEST A PASS: hit at frame 200! Ack: {ack[:100]}")
        else:
            log(f">>> TEST A FAIL: no hit. Ack: {ack}")

        bot.send_and_wait("breakpoint_clear", "breakpoint_clear", timeout=5)

    # ==============================================
    # TEST B: Same pattern but at mode select
    # ==============================================
    log(f"\n{'='*60}")
    log("TEST B: mode select (step-then-BP pattern)")
    log(f"{'='*60}")

    # Continue from frame 200 to menu
    if not replay_to_state(bot, "menu", trace_events):
        log("FAIL: replay to menu")
        bot.quit()
        return
    log(f"At mode select (frame {bot.current_frame})")

    # Step 1 to get current PC
    ack = bot.send_and_wait("step 1", "done step", timeout=10)
    log(f"step 1 ack: {ack}")
    pc = None
    if ack:
        m = re.search(r'pc=0x([0-9a-fA-F]+)', ack)
        if m:
            pc = m.group(1)
            log(f"Current PC at menu: 0x{pc}")

    if pc:
        ack = bot.send_and_wait(f"breakpoint {pc}", "ok breakpoint", timeout=5)
        log(f"BP set: {ack}")

        ack = bot.send_and_wait("continue", "break", timeout=10)
        if ack and "break" in ack.lower():
            log(f">>> TEST B PASS: hit at mode select! Ack: {ack[:100]}")
        else:
            log(f">>> TEST B FAIL: no hit. Ack: {ack}")

        bot.send_and_wait("breakpoint_clear", "breakpoint_clear", timeout=5)

    # ==============================================
    # TEST C: BP on state_mode_select_active address
    # ==============================================
    log(f"\n{'='*60}")
    log(f"TEST C: BP on state_mode_select_active (0x{active_addr})")
    log(f"{'='*60}")

    # Need to unblock from step mode — send continue first to clear instruction_paused
    # Actually, after TEST B's breakpoint_clear and continue, we might still be paused.
    # Let's do a frame_advance first to get back to normal mode.
    ack = bot.send_and_wait("frame_advance 1", "done frame_advance", timeout=30)
    log(f"frame_advance 1: {ack is not None}")

    ack = bot.send_and_wait(f"breakpoint {active_addr}", "ok breakpoint", timeout=5)
    log(f"BP on 0x{active_addr}: {ack}")

    # Try frame_advance 1 — if BP fires, this will timeout
    log("Trying frame_advance 1 with BP active...")
    ack = bot.send_and_wait("frame_advance 1", "done frame_advance", timeout=30)
    if ack:
        log(f">>> frame_advance completed normally: {ack[:80]}")
        log("  BP did NOT fire — address might be wrong!")
    else:
        # Check if breakpoint fired instead
        try:
            with open(bot.ack_file) as f:
                raw = f.read().strip()
        except:
            raw = "???"
        log(f"  frame_advance timed out. Raw ack: {raw}")
        if "break" in raw.lower():
            log(">>> TEST C PASS: BP fired during frame_advance!")
        else:
            log(">>> TEST C FAIL: frame_advance timed out but no break ack")

    bot.send_and_wait("breakpoint_clear", "breakpoint_clear", timeout=5)

    # ==============================================
    # TEST D: BP on the function's RETAIL address
    # ==============================================
    log(f"\n{'='*60}")
    log("TEST D: BP on retail address 0x06008D74 (original FUN_ address)")
    log(f"{'='*60}")

    ack = bot.send_and_wait("frame_advance 1", "done frame_advance", timeout=30)
    ack = bot.send_and_wait("breakpoint 06008D74", "ok breakpoint", timeout=5)
    log(f"BP on 0x06008D74: {ack}")

    log("Trying frame_advance 1...")
    ack = bot.send_and_wait("frame_advance 1", "done frame_advance", timeout=30)
    if ack:
        log(f">>> frame_advance completed: {ack[:80]}")
        log("  BP did NOT fire at retail address either")
    else:
        try:
            with open(bot.ack_file) as f:
                raw = f.read().strip()
        except:
            raw = "???"
        log(f"  frame_advance timed out. Raw ack: {raw}")
        if "break" in raw.lower():
            log(">>> TEST D PASS: BP fired at retail address!")

    bot.send_and_wait("breakpoint_clear", "breakpoint_clear", timeout=5)

    # ==============================================
    # TEST E: What is state_mode_select_active's actual PC?
    # ==============================================
    log(f"\n{'='*60}")
    log("TEST E: Dump regs to see what PC looks like in game loop")
    log(f"{'='*60}")

    # Step through a few hundred instructions, logging PCs
    ack = bot.send_and_wait("frame_advance 1", "done frame_advance", timeout=30)
    unique_pcs = set()
    for i in range(20):
        ack = bot.send_and_wait("step 100", "done step", timeout=10)
        if ack:
            m = re.search(r'pc=0x([0-9a-fA-F]+)', ack)
            if m:
                unique_pcs.add(m.group(1).upper())

    log(f"Sampled {len(unique_pcs)} unique PCs from stepping:")
    for pc in sorted(unique_pcs):
        sym_name = ""
        try:
            addr_int = int(pc, 16)
            from investigate import resolve_symbol
            sym_name = resolve_symbol(addr_int, addr_to_name)
        except:
            pass
        log(f"  0x{pc} = {sym_name}")

    # Check if state_mode_select_active's address appears
    if active_addr.upper() in unique_pcs:
        log(f"\n>>> state_mode_select_active (0x{active_addr}) WAS found in PC samples!")
    else:
        log(f"\n>>> state_mode_select_active (0x{active_addr}) NOT found in samples.")
        log(f"    Checking nearby addresses...")
        active_int = int(active_addr, 16)
        for pc in sorted(unique_pcs):
            pc_int = int(pc, 16)
            if abs(pc_int - active_int) < 0x200:
                log(f"    NEARBY: 0x{pc} (offset {pc_int - active_int:+d})")

    bot.quit()
    log("\nDone.")


if __name__ == "__main__":
    main()
