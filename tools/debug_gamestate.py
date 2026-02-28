#!/usr/bin/env python3
"""debug_gamestate.py -- Compare game state and VDP config between prod and free."""
import os, sys, time, re, struct

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin, TMPDIR

CUE_REIMPL = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")

SHIFT = 16


def dump_mem(inst, ipc_dir, addr, size, tag):
    path = os.path.join(ipc_dir, f"mem_{tag}.bin")
    wsl_path = path.replace("D:", "/mnt/d").replace("\\", "/")
    inst.dump_mem_bin(addr, size, wsl_path)
    time.sleep(0.5)
    try:
        with open(path, "rb") as f:
            return f.read()
    except FileNotFoundError:
        return None


def read32(data, offset=0):
    if data and len(data) >= offset + 4:
        return struct.unpack(">I", data[offset:offset+4])[0]
    return None


def read16(data, offset=0):
    if data and len(data) >= offset + 2:
        return struct.unpack(">H", data[offset:offset+2])[0]
    return None


def main():
    MednafenInstance.kill_stale()

    ipc_prod = os.path.join(TMPDIR, "gs_prod")
    ipc_free = os.path.join(TMPDIR, "gs_free")

    print("Starting both instances...")
    prod = MednafenInstance("prod", CUE_PROD, ipc_prod)
    free = MednafenInstance("free", CUE_REIMPL, ipc_free)
    prod.start()
    free.start()

    # Let both run for 8 seconds
    print("Letting both run for 8 seconds...")
    prod.send("continue")
    free.send("continue")
    time.sleep(8)

    prod.pause()
    free.pause()
    time.sleep(0.5)

    # Dump game state variables
    # From _start.s pool entries:
    #   g_game_state - game state dispatch variable
    #   sym_0607EBC0 - state-related
    #   sym_0607EBC4 - state-related
    #   sym_0607EBC8 - state-related
    STATE_VARS = [
        (0x0605AD10, "game_state"),
        (0x0607EBC0, "state_var1"),
        (0x0607EBC4, "state_var2"),
        (0x0607EBC8, "state_var3"),
    ]

    print("\n=== Game State Variables ===")
    for addr, name in STATE_VARS:
        p = dump_mem(prod, ipc_prod, addr, 4, f"p_{name}")
        f_orig = dump_mem(free, ipc_free, addr, 4, f"f_{name}")
        f_shift = dump_mem(free, ipc_free, addr + SHIFT, 4, f"fs_{name}")
        vp = read32(p)
        vf = read32(f_orig)
        vfs = read32(f_shift)
        print(f"  {name} (0x{addr:08X}):")
        print(f"    prod      = 0x{vp:08X}" if vp is not None else f"    prod      = None")
        print(f"    free@orig = 0x{vf:08X}" if vf is not None else f"    free@orig = None")
        print(f"    free@+{SHIFT:2d}  = 0x{vfs:08X}" if vfs is not None else f"    free@+{SHIFT:2d}  = None")

    # Check if these are in code range or data range
    # g_game_state is at 0x0605AD10 which is in code range (0x06003000-0x06063690)
    # sym_0607EBC0 is at 0x0607EBC0 which is OUTSIDE code range (> 0x06063690)
    print(f"\n  Note: 0x0605AD10 is in code range -> shifts by {SHIFT}")
    print(f"  Note: 0x0607EBxx is outside code range -> does NOT shift")

    # VDP2 registers (at 0x25F80000)
    VDP2_REGS = [
        (0x25F80000, "TVMD", 2),   # TV Mode
        (0x25F80002, "EXTEN", 2),  # External Signal Enable
        (0x25F80004, "TVSTAT", 2), # TV Status
        (0x25F80006, "VRSIZE", 2), # VRAM Size
        (0x25F8000E, "RAMCTL", 2), # RAM Control
        (0x25F80010, "CYCA0", 4),  # Cycle Pattern A0
        (0x25F80020, "BGON", 2),   # BG Control
        (0x25F80038, "SCRX0", 4),  # Scroll X NBG0
        (0x25F80100, "SPCTL", 2),  # Sprite Control
    ]

    print("\n=== VDP2 Registers ===")
    for addr, name, size in VDP2_REGS:
        p = dump_mem(prod, ipc_prod, addr, size, f"p_vdp2_{name}")
        f = dump_mem(free, ipc_free, addr, size, f"f_vdp2_{name}")
        if size == 2:
            vp = read16(p) if p else None
            vf = read16(f) if f else None
            diff = "" if vp == vf else " [DIFF]"
            print(f"  {name:8s} (0x{addr:08X}): prod=0x{vp:04X} free=0x{vf:04X}{diff}" if vp is not None and vf is not None else f"  {name}: unavailable")
        else:
            vp = read32(p) if p else None
            vf = read32(f) if f else None
            diff = "" if vp == vf else " [DIFF]"
            print(f"  {name:8s} (0x{addr:08X}): prod=0x{vp:08X} free=0x{vf:08X}{diff}" if vp is not None and vf is not None else f"  {name}: unavailable")

    # VDP1 registers (at 0x25D00000)
    VDP1_REGS = [
        (0x25D00000, "TVMR", 2),   # TV Mode Register
        (0x25D00002, "FBCR", 2),   # Frame Buffer Change Mode
        (0x25D00004, "PTMR", 2),   # Plot Trigger
        (0x25D00006, "EWDR", 2),   # Erase/Write Data
        (0x25D00008, "EWLR", 2),   # Erase/Write Upper Left
        (0x25D0000A, "EWRR", 2),   # Erase/Write Lower Right
        (0x25D00010, "MODR", 2),   # Mode Status
        (0x25D00012, "LOPR", 2),   # Last Process End Position
        (0x25D00014, "COPR", 2),   # Current Process Position
    ]

    print("\n=== VDP1 Registers ===")
    for addr, name, size in VDP1_REGS:
        p = dump_mem(prod, ipc_prod, addr, size, f"p_vdp1_{name}")
        f = dump_mem(free, ipc_free, addr, size, f"f_vdp1_{name}")
        vp = read16(p) if p else None
        vf = read16(f) if f else None
        diff = "" if vp == vf else " [DIFF]"
        print(f"  {name:8s} (0x{addr:08X}): prod=0x{vp:04X} free=0x{vf:04X}{diff}" if vp is not None and vf is not None else f"  {name}: unavailable")

    # SCU interrupt mask register
    scu_p = dump_mem(prod, ipc_prod, 0x25FE00A0, 4, "p_scu_ims")
    scu_f = dump_mem(free, ipc_free, 0x25FE00A0, 4, "f_scu_ims")
    print(f"\n=== SCU Interrupt Mask ===")
    vp = read32(scu_p)
    vf = read32(scu_f)
    diff = "" if vp == vf else " [DIFF]"
    print(f"  IMS (0x25FE00A0): prod=0x{vp:08X} free=0x{vf:08X}{diff}" if vp is not None and vf is not None else "  IMS: unavailable")

    # Also dump the call chain by checking PR and stack
    print("\n=== Free build call chain ===")
    from parallel_compare import read_regs_bin
    regs_path = os.path.join(ipc_free, "regs.bin")
    free.dump_regs_bin(regs_path)
    time.sleep(0.3)
    regs = read_regs_bin(regs_path)
    if regs:
        pc = regs['PC']
        pr = regs['PR']
        sp = regs['R15']
        print(f"  PC=0x{pc:08X}  PR=0x{pr:08X}  SP=0x{sp:08X}")

        # Dump stack
        stack = dump_mem(free, ipc_free, sp, 128, "f_stack")
        if stack:
            print(f"  Stack dump:")
            for i in range(0, min(len(stack), 128), 4):
                val = struct.unpack(">I", stack[i:i+4])[0]
                # Check if it looks like a return address (in code range)
                if 0x06003000 <= val <= 0x06064000:
                    orig = val - SHIFT
                    print(f"    SP+0x{i:02X}: 0x{val:08X}  (orig ~0x{orig:08X}) <-- possible return addr")
                else:
                    print(f"    SP+0x{i:02X}: 0x{val:08X}")

    prod.send("quit")
    free.send("quit")
    time.sleep(1)
    MednafenInstance.kill_stale()
    print("\nDone.")


if __name__ == "__main__":
    main()
