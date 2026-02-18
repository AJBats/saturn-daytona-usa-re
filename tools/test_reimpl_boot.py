#!/usr/bin/env python3
"""test_reimpl_boot.py -- Quick boot test for reimpl free-layout disc.

Boot the reimpl, advance in chunks, track game state progression.
"""
import os, sys, time, re, struct

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin, win_to_wsl, TMPDIR

CUE_REIMPL = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")

GAME_STATE_ADDR = 0x0605AD10


def dump_regs(inst, ipc_dir):
    path = os.path.join(ipc_dir, "regs.bin")
    inst.dump_regs_bin(path)
    time.sleep(0.2)
    return read_regs_bin(path)


def dump_mem(inst, ipc_dir, addr, size, tag):
    path = os.path.join(ipc_dir, f"mem_{tag}.bin")
    wsl_path = win_to_wsl(path)
    inst.dump_mem_bin(addr, size, wsl_path)
    time.sleep(0.2)
    try:
        with open(path, "rb") as f:
            return f.read()
    except FileNotFoundError:
        return None


def read_u32(inst, ipc_dir, addr, tag):
    data = dump_mem(inst, ipc_dir, addr, 4, tag)
    if data and len(data) >= 4:
        return struct.unpack(">I", data[:4])[0]
    return None


def main():
    MednafenInstance.kill_stale()
    time.sleep(1)

    ipc = os.path.join(TMPDIR, "reimpl_boot")
    inst = MednafenInstance("reimpl", CUE_REIMPL, ipc)

    print("=" * 60)
    print("  REIMPL BOOT PROGRESSION TEST")
    print("=" * 60)

    inst.start()

    # Advance in chunks and track state
    checkpoints = [100, 200, 400, 600, 800, 1000, 1200, 1500, 2000, 2500, 3000]
    last_frame = 0

    for target in checkpoints:
        advance = target - last_frame
        print(f"\n  Frame {target}:", end=" ")
        try:
            ack = inst.frame_advance(advance)
        except TimeoutError:
            print("TIMEOUT")
            break

        inst.pause()
        regs = dump_regs(inst, ipc)
        state = read_u32(inst, ipc, GAME_STATE_ADDR, "gs")

        pc = regs['PC'] if regs else 0
        pc_region = "???"
        if 0x060423D0 <= pc < 0x06042420:
            pc_region = "SCDQ_POLL"
        elif 0x0600C014 <= pc < 0x0600C180:
            pc_region = "ICF_POLL"
        elif 0x060023D0 <= pc < 0x06002500:
            pc_region = "VBLANK_SYNC"
        elif 0x06003000 <= pc < 0x06003100:
            pc_region = "MAIN_LOOP"
        elif 0x06008800 <= pc < 0x0600A000:
            pc_region = "STATE_HANDLER"
        elif pc < 0x00080000:
            pc_region = "BIOS"
        elif 0x06003000 <= pc < 0x06064000:
            pc_region = "GAME_CODE"

        state_str = f"state={state}" if state is not None and state < 100 else f"raw=0x{state:08X}" if state else "None"
        print(f"PC=0x{pc:08X} ({pc_region})  {state_str}")

        last_frame = target

    # If we reached game state, try pressing START
    state = read_u32(inst, ipc, GAME_STATE_ADDR, "gs_final")
    if state is not None and state < 100:
        print(f"\n  Game state is {state} — trying START button...")

        # Press START
        try:
            inst.send("input START")
        except TimeoutError:
            pass

        # Advance 60 frames with START held
        try:
            inst.frame_advance(60)
        except TimeoutError:
            pass

        try:
            inst.send("input_release START")
        except TimeoutError:
            pass

        # Check after
        try:
            inst.frame_advance(60)
        except TimeoutError:
            pass

        inst.pause()
        state_after = read_u32(inst, ipc, GAME_STATE_ADDR, "gs_after")
        print(f"  After START: state={state_after}")

        # Take screenshot
        ss_path = os.path.join(PROJDIR, "build", "screenshots", "reimpl_start_test.png")
        wsl_ss = win_to_wsl(ss_path)
        try:
            inst.send(f"screenshot {wsl_ss}")
        except TimeoutError:
            pass
    else:
        print(f"\n  Game state not initialized by frame {last_frame}")

    inst.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()
    print("\nDone.")


if __name__ == "__main__":
    main()
