#!/usr/bin/env python3
"""Dump FUN_060102EA pool constants from the running emulator.

Reads the button mask values directly from code memory (ROM loaded into WRAM).
These are mov.w/mov.l pool targets embedded in the instruction stream.
"""

import os
import sys
import struct

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(PROJECT, "workstreams", "empirical_validation"))

from investigate import MednafenBot, wsl_path

SAVE_STATE = os.path.join(PROJECT, "build", "save_states", "circuit_select_slot0.mc0")
CUE_PATH = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
IPC_DIR = os.path.join(PROJECT, "build", "debug_ipc")


def read_mem(bot, addr, size):
    tmp = os.path.join(IPC_DIR, "tmp_memdump.bin")
    if os.path.exists(tmp):
        os.remove(tmp)
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

    bot.frame_advance(1)

    # Verify FUN_060102A8 starts with expected bytes
    verify = read_mem(bot, 0x060102A8, 4)
    if verify:
        print(f"FUN_060102A8 first 4 bytes: {verify.hex().upper()}")
        # Expect D519 634D from retail ASM
        if verify[:2] == b'\xD5\x19':
            print("  MATCH: D519 (mov.l pool, r5)")
        else:
            print(f"  MISMATCH: expected D519, got {verify[:2].hex().upper()}")

    # FUN_060102A8 pool targets:
    # mov.w @(0x20*2, PC), r3 at PC=0x060102C6 -> reads 0x0601030A
    # This is DAT_0601030a = LEFT mask
    left_data = read_mem(bot, 0x0601030A, 2)
    if left_data:
        left_mask = struct.unpack(">H", left_data)[0]
        print(f"\nDAT_0601030a (LEFT mask):    0x{left_mask:04X}")

    # FUN_060102EA pool targets - need to find the actual pool addresses
    # Let me dump the full code region and decode mov.w/mov.l instructions
    code = read_mem(bot, 0x060102EA, 132)  # full FUN_060102EA (132 bytes)
    if not code:
        print("FAIL: couldn't read FUN_060102EA")
        bot.quit()
        return

    print(f"\nFUN_060102EA code dump ({len(code)} bytes):")

    # Find all mov.w and mov.l pool references
    pool_refs = []
    for i in range(0, len(code), 2):
        pc = 0x060102EA + i
        insn = struct.unpack(">H", code[i:i+2])[0]
        op = (insn >> 12) & 0xF

        if op == 0x9:  # mov.w @(disp,PC), Rn
            rn = (insn >> 8) & 0xF
            disp = insn & 0xFF
            target = pc + 4 + disp * 2
            pool_refs.append((pc, f"mov.w @pool, r{rn}", target, 2))
        elif op == 0xD:  # mov.l @(disp,PC), Rn
            rn = (insn >> 8) & 0xF
            disp = insn & 0xFF
            target = (pc & ~3) + 4 + disp * 4
            pool_refs.append((pc, f"mov.l @pool, r{rn}", target, 4))

    print("\nPool references in FUN_060102EA:")
    for pc, insn_str, target, size in pool_refs:
        data = read_mem(bot, target, size)
        if data:
            if size == 2:
                val = struct.unpack(">H", data)[0]
                print(f"  0x{pc:08X}: {insn_str} -> 0x{target:08X} = 0x{val:04X}")
            else:
                val = struct.unpack(">I", data)[0]
                print(f"  0x{pc:08X}: {insn_str} -> 0x{target:08X} = 0x{val:08X}")

    # Also dump FUN_060102A8 pool refs
    code2 = read_mem(bot, 0x060102A8, 66)
    if code2:
        print("\nPool references in FUN_060102A8:")
        for i in range(0, len(code2), 2):
            pc = 0x060102A8 + i
            insn = struct.unpack(">H", code2[i:i+2])[0]
            op = (insn >> 12) & 0xF
            if op == 0x9:
                rn = (insn >> 8) & 0xF
                disp = insn & 0xFF
                target = pc + 4 + disp * 2
                data = read_mem(bot, target, 2)
                if data:
                    val = struct.unpack(">H", data)[0]
                    print(f"  0x{pc:08X}: mov.w @pool, r{rn} -> 0x{target:08X} = 0x{val:04X}")
            elif op == 0xD:
                rn = (insn >> 8) & 0xF
                disp = insn & 0xFF
                target = (pc & ~3) + 4 + disp * 4
                data = read_mem(bot, target, 4)
                if data:
                    val = struct.unpack(">I", data)[0]
                    print(f"  0x{pc:08X}: mov.l @pool, r{rn} -> 0x{target:08X} = 0x{val:08X}")

    # Also verify: press buttons and read g_pad_state+2 to confirm bit mapping
    print("\n=== Button bit verification ===")
    for button in ["A", "B", "C", "LEFT", "RIGHT", "START"]:
        ack = bot.send_and_wait(f"load_state {state_wsl}", "load_state", timeout=15)
        bot.frame_advance(1)
        bot.input_press(button)
        bot.frame_advance(2)
        pad = read_mem(bot, 0x06063D98, 4)
        bot.input_release(button)
        if pad:
            w0 = struct.unpack(">H", pad[0:2])[0]
            w1 = struct.unpack(">H", pad[2:4])[0]
            print(f"  {button:6s}: pad[0:2]=0x{w0:04X}  pad[2:4]=0x{w1:04X}")

    bot.quit()
    print("\nDone.")


if __name__ == "__main__":
    main()
