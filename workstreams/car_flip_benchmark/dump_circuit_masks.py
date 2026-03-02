#!/usr/bin/env python3
"""Dump circuit select button mask values from running emulator.

Loads save state (circuit select screen) and reads the 4 button masks
that game_state_dispatch uses to map buttons to circuit selections.
"""

import os
import sys
import struct
import tempfile

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(PROJECT, "workstreams", "empirical_validation"))

from investigate import MednafenBot, wsl_path, load_symbols

SAVE_STATE = os.path.join(PROJECT, "build", "save_states", "circuit_select_slot0.mc0")
CUE_PATH = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
IPC_DIR = os.path.join(PROJECT, "build", "debug_ipc")

# Known button bit names from prior investigation
BUTTON_BITS = {
    0x0001: "RIGHT?",
    0x0002: "LEFT?",
    0x0004: "DOWN?",
    0x0008: "UP?",
    0x0010: "START?",
    0x0020: "A",
    0x0040: "C",
    0x0080: "B?",
    0x0100: "C(confirm)",
    0x0200: "X?",
    0x0400: "Y?",
    0x0800: "Z?",
    0x1000: "UP",
    0x2000: "DOWN",
    0x4000: "LEFT",
    0x8000: "RIGHT",
}


def decode_mask(value):
    """Decode a button mask into known bit names."""
    bits = []
    for bit, name in sorted(BUTTON_BITS.items()):
        if value & bit:
            bits.append(f"{name}(0x{bit:04X})")
    return ", ".join(bits) if bits else "(none)"


def read_mem(bot, addr, size):
    """Read memory region via dump_mem_bin to temp file, return bytes."""
    tmp = os.path.join(IPC_DIR, "tmp_memdump.bin")
    ack = bot.dump_mem_bin(f"{addr:X}", f"{size:X}", tmp)
    if not ack:
        return None
    try:
        with open(tmp, "rb") as f:
            return f.read()
    except FileNotFoundError:
        return None


def main():
    bot = MednafenBot(IPC_DIR, wsl_path(CUE_PATH))
    print("Starting Mednafen...")
    if not bot.start(timeout=30):
        print("FAIL: Mednafen did not start")
        return

    bot.frame_advance(1)
    state_wsl = wsl_path(SAVE_STATE)
    ack = bot.send_and_wait(f"load_state {state_wsl}", "load_state", timeout=15)
    if not ack or "error" in ack:
        print(f"FAIL: {ack}")
        bot.quit()
        return
    print("Save state loaded (circuit select screen)\n")

    # Advance a frame to ensure everything is settled
    bot.frame_advance(1)

    # Dump the region around the circuit select variables
    # sym_06078648 (selection index) through sym_06078660 (end of masks)
    region_start = 0x06078640
    region_size = 0x30  # 48 bytes covers everything
    data = read_mem(bot, region_start, region_size)

    if not data:
        print("FAIL: Could not read memory")
        bot.quit()
        return

    print("=== Raw Memory Dump 0x06078640-0x06078670 ===\n")
    for i in range(0, len(data), 16):
        addr = region_start + i
        hex_part = " ".join(f"{data[j]:02X}" for j in range(i, min(i+16, len(data))))
        print(f"  {addr:08X}: {hex_part}")

    print("\n=== Circuit Select Variables ===\n")

    # Selection index (byte)
    idx_off = 0x06078648 - region_start
    idx_val = data[idx_off]
    print(f"  sym_06078648 (selection index): {idx_val}")

    # Button masks (big-endian words)
    masks = [
        ("sym_06078656", 0x06078656, "mask -> circuit 0"),
        ("sym_06078658", 0x06078658, "mask -> circuit 1"),
        ("sym_0607865A", 0x0607865A, "mask -> circuit 2"),
        ("sym_0607865C", 0x0607865C, "mask -> circuit 3"),
    ]
    for name, addr, desc in masks:
        off = addr - region_start
        value = struct.unpack(">H", data[off:off+2])[0]
        decoded = decode_mask(value)
        print(f"  {name} (0x{addr:08X}): 0x{value:04X} -- {desc}")
        if decoded != "(none)":
            print(f"    bits: {decoded}")

    # Guard value
    guard_off = 0x0607865E - region_start
    guard_val = struct.unpack(">H", data[guard_off:guard_off+2])[0]
    print(f"\n  sym_0607865E (guard check): 0x{guard_val:04X}")

    # Also read g_pad_state for context
    pad_data = read_mem(bot, 0x06063D98, 4)
    if pad_data:
        print(f"\n  g_pad_state: {' '.join(f'{b:02X}' for b in pad_data)}")
        pad_word = struct.unpack(">H", pad_data[0:2])[0]
        pad_word2 = struct.unpack(">H", pad_data[2:4])[0]
        print(f"    word 0: 0x{pad_word:04X}  word 1: 0x{pad_word2:04X}")

    bot.quit()
    print("\nDone.")


if __name__ == "__main__":
    main()
