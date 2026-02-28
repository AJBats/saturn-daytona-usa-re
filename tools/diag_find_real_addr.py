#!/usr/bin/env python3
"""Find the ACTUAL runtime address of state_mode_select_active by breaking
on its callee (camera_finalize) and checking the return address (PR)."""

import os
import sys
import time
import re

PROJECT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJECT, "tools"))

from investigate import (
    MednafenBot, load_symbols, sym_hex, resolve_symbol,
    parse_trace, replay_to_state,
    TRACE_FILE, wsl_path
)

RESULTS_DIR = os.path.join(PROJECT, "build", "investigation_results", "bp_diag")


def log(msg):
    print(msg)
    with open(os.path.join(RESULTS_DIR, "addr_log.txt"), "a") as f:
        f.write(msg + "\n")


def main():
    os.makedirs(RESULTS_DIR, exist_ok=True)
    with open(os.path.join(RESULTS_DIR, "addr_log.txt"), "w") as f:
        f.write(f"# find real addr -- {time.strftime('%Y-%m-%d %H:%M:%S')}\n\n")

    addr_to_name, name_to_addr = load_symbols()
    trace_events = parse_trace(TRACE_FILE)

    # camera_finalize is at sym_06026CE0 in the source
    cam_addr = sym_hex(name_to_addr, "sym_06026CE0")
    active_addr = sym_hex(name_to_addr, "state_mode_select_active")
    setup_addr = sym_hex(name_to_addr, "car_select_setup")

    log(f"camera_finalize (sym_06026CE0) -> 0x{cam_addr}")
    log(f"state_mode_select_active -> 0x{active_addr}")
    log(f"car_select_setup -> 0x{setup_addr}")

    # Also check: what address does the linker map give for the SECTION?
    log(f"\nLinker map says state_mode_select_active = 0x{active_addr}")
    log(f"Section name is .text.FUN_06008D74")
    log(f"Retail address would be 0x06008D74")

    cue_path = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
    cue_wsl = wsl_path(cue_path)
    ipc_dir = os.path.join(RESULTS_DIR, "ipc")
    os.makedirs(ipc_dir, exist_ok=True)

    bot = MednafenBot(ipc_dir, cue_wsl)
    if not bot.start(timeout=30):
        log("FAIL: start")
        return

    if not replay_to_state(bot, "menu", trace_events):
        log("FAIL: replay to menu")
        bot.quit()
        return
    log(f"\nAt mode select (frame {bot.current_frame})")

    # TEST 1: Break on camera_finalize, check PR
    log(f"\n--- Break on camera_finalize (0x{cam_addr}) ---")
    bot.send_and_wait(f"breakpoint {cam_addr}", "ok breakpoint", timeout=5)

    ack = bot.send_and_wait("frame_advance 1", "done frame_advance", timeout=30)
    if ack:
        log(f"frame_advance completed (BP didn't fire). Try 'continue'...")
        # camera_finalize might not be at sym_06026CE0 either!
        bot.send_and_wait("breakpoint_clear", "breakpoint_clear", timeout=5)
    else:
        # Check if BP fired
        try:
            with open(bot.ack_file) as f:
                raw = f.read().strip()
        except:
            raw = "???"
        if "break" in raw.lower():
            log(f"BP hit! Ack: {raw[:120]}")
            regs = bot.send_and_wait("dump_regs", "R0=", timeout=5)
            log(f"Registers: {regs}")
            if regs:
                # Parse PR
                m = re.search(r'PR=([0-9a-fA-F]+)', regs)
                if m:
                    pr = int(m.group(1), 16)
                    pr_sym = resolve_symbol(pr, addr_to_name)
                    log(f"\n>>> PR (return address) = 0x{pr:08X} = {pr_sym}")
                    log(f"    This is inside state_mode_select_active")
                    log(f"    The function's real entry point is nearby")
            # Continue to unblock
            bot.send_and_wait("continue", "ok continue", timeout=5)
        bot.send_and_wait("breakpoint_clear", "breakpoint_clear", timeout=5)

    # TEST 2: Try different addresses near state_mode_select_active
    log(f"\n--- Scanning addresses near 0x{active_addr} ---")
    active_int = int(active_addr, 16)
    found_any = False
    for offset in range(-0x10, 0x10, 2):
        test_addr = active_int + offset
        test_hex = f"{test_addr:08X}"

        bot.send_and_wait(f"breakpoint {test_hex}", "ok breakpoint", timeout=5)
        ack = bot.send_and_wait("frame_advance 1", "done frame_advance", timeout=10)

        if ack:
            # frame_advance completed, BP didn't fire
            bot.send_and_wait("breakpoint_clear", "breakpoint_clear", timeout=5)
        else:
            try:
                with open(bot.ack_file) as f:
                    raw = f.read().strip()
            except:
                raw = "???"
            if "break" in raw.lower():
                log(f"  HIT at 0x{test_hex} (offset {offset:+d} from map addr)")
                found_any = True
                regs = bot.send_and_wait("dump_regs", "R0=", timeout=5)
                if regs:
                    m = re.search(r'PC=([0-9a-fA-F]+)', regs)
                    if m:
                        log(f"  PC = 0x{m.group(1)}")
                bot.send_and_wait("continue", "ok continue", timeout=5)
            bot.send_and_wait("breakpoint_clear", "breakpoint_clear", timeout=5)
            # After hit, need to unblock instruction pause
            bot.send_and_wait("frame_advance 1", "done frame_advance", timeout=10)

    if not found_any:
        log(f"  No hits in range 0x{active_int - 0x10:08X} - 0x{active_int + 0x10:08X}")

    # TEST 3: Check RETAIL addresses too
    retail_int = 0x06008D74
    log(f"\n--- Scanning near retail address 0x{retail_int:08X} ---")
    found_any = False
    for offset in range(-0x10, 0x10, 2):
        test_addr = retail_int + offset
        test_hex = f"{test_addr:08X}"

        bot.send_and_wait(f"breakpoint {test_hex}", "ok breakpoint", timeout=5)
        ack = bot.send_and_wait("frame_advance 1", "done frame_advance", timeout=10)

        if ack:
            bot.send_and_wait("breakpoint_clear", "breakpoint_clear", timeout=5)
        else:
            try:
                with open(bot.ack_file) as f:
                    raw = f.read().strip()
            except:
                raw = "???"
            if "break" in raw.lower():
                log(f"  HIT at 0x{test_hex} (offset {offset:+d} from 0x06008D74)")
                found_any = True
                regs = bot.send_and_wait("dump_regs", "R0=", timeout=5)
                if regs:
                    log(f"  Regs: {regs[:120]}")
                bot.send_and_wait("continue", "ok continue", timeout=5)
            bot.send_and_wait("breakpoint_clear", "breakpoint_clear", timeout=5)
            bot.send_and_wait("frame_advance 1", "done frame_advance", timeout=10)

    if not found_any:
        log(f"  No hits in range 0x{retail_int - 0x10:08X} - 0x{retail_int + 0x10:08X}")

    # TEST 4: Read the actual dispatch table to find the function pointer
    log(f"\n--- Dumping state dispatch table ---")
    # g_game_state is at sym_0605AD10. The dispatch table is nearby.
    # Actually, let's look at what the state dispatcher reads.
    # Read memory around g_game_state to find the function pointer table.
    gs_addr = sym_hex(name_to_addr, "g_game_state")
    if gs_addr:
        log(f"g_game_state -> 0x{gs_addr}")
        ack = bot.send_and_wait(f"dump_mem {gs_addr} 4", f"mem {gs_addr.lower()}")
        log(f"  g_game_state value: {ack}")

    bot.quit()
    log("\nDone.")


if __name__ == "__main__":
    main()
