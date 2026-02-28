#!/usr/bin/env python3
"""Use PC trace to find actual addresses executed during mode select frame.
Then search for state_mode_select_active's instruction pattern."""

import os
import sys
import time
import struct
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
    with open(os.path.join(RESULTS_DIR, "pctrace_log.txt"), "a") as f:
        f.write(msg + "\n")


def main():
    os.makedirs(RESULTS_DIR, exist_ok=True)
    with open(os.path.join(RESULTS_DIR, "pctrace_log.txt"), "w") as f:
        f.write(f"# PC trace diag -- {time.strftime('%Y-%m-%d %H:%M:%S')}\n\n")

    addr_to_name, name_to_addr = load_symbols()
    trace_events = parse_trace(TRACE_FILE)

    active_addr = sym_hex(name_to_addr, "state_mode_select_active")
    log(f"state_mode_select_active (map) -> 0x{active_addr}")
    log(f"Retail section start: 0x06008D74")

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
    log(f"At mode select (frame {bot.current_frame})")

    # STEP 1: Dump g_game_state
    gs_hex = sym_hex(name_to_addr, "g_game_state")
    log(f"\ng_game_state -> 0x{gs_hex}")
    mem_path = os.path.join(RESULTS_DIR, "gamestate.bin")
    ack = bot.dump_mem_bin(gs_hex, "4", mem_path)
    time.sleep(0.5)
    if os.path.exists(mem_path):
        data = open(mem_path, "rb").read()
        if len(data) >= 4:
            val = struct.unpack(">I", data[:4])[0]  # big-endian (SH-2)
            log(f"g_game_state value = {val} (0x{val:08X})")
    else:
        log("Could not read g_game_state")

    # STEP 2: Dump memory at function addresses to verify code is there
    log(f"\n--- Checking code at map address 0x{active_addr} ---")
    code_path = os.path.join(RESULTS_DIR, "code_at_map.bin")
    ack = bot.dump_mem_bin(active_addr, "20", code_path)
    time.sleep(0.5)
    if os.path.exists(code_path):
        data = open(code_path, "rb").read()
        hex_str = " ".join(f"{b:02X}" for b in data[:32])
        log(f"Bytes at 0x{active_addr}: {hex_str}")
        # mov.l r14, @-r15 = 0x2FE6 (big-endian)
        if data[0:2] == b'\x2f\xe6':
            log("  First 2 bytes match mov.l r14, @-r15 (0x2FE6) -- function IS here")
        else:
            log(f"  First 2 bytes = 0x{data[0]:02X}{data[1]:02X} -- NOT mov.l r14, @-r15")

    log(f"\n--- Checking code at retail address 0x06008D74 ---")
    code_path2 = os.path.join(RESULTS_DIR, "code_at_retail.bin")
    ack = bot.dump_mem_bin("06008D74", "20", code_path2)
    time.sleep(0.5)
    if os.path.exists(code_path2):
        data = open(code_path2, "rb").read()
        hex_str = " ".join(f"{b:02X}" for b in data[:32])
        log(f"Bytes at 0x06008D74: {hex_str}")
        if data[0:2] == b'\x2f\xe6':
            log("  First 2 bytes match mov.l r14, @-r15 (0x2FE6) -- function IS here")
        else:
            log(f"  First 2 bytes = 0x{data[0]:02X}{data[1]:02X} -- NOT mov.l r14, @-r15")

    # STEP 3: PC trace for one frame
    log(f"\n--- PC trace for 1 frame ---")
    pc_trace_path = os.path.join(RESULTS_DIR, "pc_trace_frame.bin")
    pc_trace_wsl = wsl_path(pc_trace_path)
    if os.path.exists(pc_trace_path):
        os.remove(pc_trace_path)

    # Use pc_trace_frame command if available, otherwise use manual approach
    ack = bot.send_and_wait(f"pc_trace_frame {pc_trace_wsl}", "done pc_trace_frame", timeout=120)
    if ack:
        log(f"PC trace frame done: {ack[:80]}")
    else:
        log("pc_trace_frame not available or timed out, trying manual approach...")
        # Start trace, advance 1 frame, stop trace
        bot.send_and_wait(f"pc_trace {pc_trace_wsl}", "ok pc_trace", timeout=5)
        bot.send_and_wait("frame_advance 1", "done frame_advance", timeout=120)
        bot.send_and_wait("pc_trace_stop", "ok pc_trace_stop", timeout=5)

    time.sleep(1)

    if os.path.exists(pc_trace_path):
        data = open(pc_trace_path, "rb").read()
        n_pcs = len(data) // 4
        log(f"PC trace: {n_pcs} instructions recorded ({len(data)} bytes)")

        # Parse all PCs (uint32 little-endian from SH-2 via fwrite)
        pcs = struct.unpack(f"<{n_pcs}I", data[:n_pcs*4])

        # Check for addresses near state_mode_select_active
        active_int = int(active_addr, 16)
        retail_int = 0x06008D74
        setup_int = int(sym_hex(name_to_addr, "car_select_setup"), 16)

        hits_map = []
        hits_retail = []
        hits_setup = []

        for i, pc in enumerate(pcs):
            if active_int <= pc < active_int + 0x8C:
                hits_map.append((i, pc))
            if retail_int <= pc < retail_int + 0x8C:
                hits_retail.append((i, pc))
            if setup_int <= pc < setup_int + 0x50:
                hits_setup.append((i, pc))

        log(f"\nHits in state_mode_select_active range (0x{active_int:08X} - 0x{active_int+0x8C:08X}): {len(hits_map)}")
        if hits_map:
            for i, pc in hits_map[:10]:
                log(f"  instruction #{i}: PC=0x{pc:08X} ({resolve_symbol(pc, addr_to_name)})")

        log(f"\nHits in retail FUN_06008D74 range (0x{retail_int:08X} - 0x{retail_int+0x8C:08X}): {len(hits_retail)}")
        if hits_retail:
            for i, pc in hits_retail[:10]:
                log(f"  instruction #{i}: PC=0x{pc:08X} ({resolve_symbol(pc, addr_to_name)})")

        log(f"\nHits in car_select_setup range (0x{setup_int:08X} - 0x{setup_int+0x50:08X}): {len(hits_setup)}")
        if hits_setup:
            for i, pc in hits_setup[:10]:
                log(f"  instruction #{i}: PC=0x{pc:08X} ({resolve_symbol(pc, addr_to_name)})")

        # Count unique PCs and find the most common ranges
        from collections import Counter
        pc_counter = Counter()
        for pc in pcs:
            # Group by 256-byte region
            region = pc & 0xFFFFFF00
            pc_counter[region] += 1

        log(f"\nTop 20 PC regions (256-byte granularity):")
        for region, count in pc_counter.most_common(20):
            pct = count / n_pcs * 100
            sym = resolve_symbol(region, addr_to_name)
            log(f"  0x{region:08X} ({sym}): {count} hits ({pct:.1f}%)")
    else:
        log("PC trace file not found!")

    bot.quit()
    log("\nDone.")


if __name__ == "__main__":
    main()
