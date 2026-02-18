#!/usr/bin/env python3
"""diagnose_shift4_bp.py -- Breakpoint comparison between production and +4 build.

Sets breakpoints at key boot sequence functions in both production and +4
builds to compare WHERE and WHEN they diverge.

Both builds run in VBlank sync loop normally. The question is whether the +4
build reaches SCDQ (FUN_060423CC) and ICF (FUN_0600C010) polls, and what
game state they're in.
"""
import os, sys, time, re, struct

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin, win_to_wsl, TMPDIR

CUE_REIMPL = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")

SHIFT = 4

# The game state machine is at _start (0x06003000), which dispatches
# through a jump table. Game state variable location needs to be found.
# Known from docs: 32-state machine dispatching through jump table at main.

# Key breakpoints
BP_SCDQ_PROD = 0x060423CC
BP_SCDQ_FREE = 0x060423CC + SHIFT  # 0x060423D0
BP_ICF_PROD  = 0x0600C010
BP_ICF_FREE  = 0x0600C010 + SHIFT  # 0x0600C014
BP_INIT_PROD = 0x060030FC
BP_INIT_FREE = 0x060030FC + SHIFT  # 0x06003100


def parse_pc(ack):
    m = re.search(r'pc=0x([0-9a-fA-F]+)', ack)
    return int(m.group(1), 16) if m else None


def parse_frame(ack):
    m = re.search(r'frame=(\d+)', ack)
    return int(m.group(1)) if m else None


def dump_regs(inst, ipc_dir):
    path = os.path.join(ipc_dir, "regs.bin")
    inst.dump_regs_bin(path)
    time.sleep(0.3)
    return read_regs_bin(path)


def dump_mem(inst, ipc_dir, addr, size, tag):
    path = os.path.join(ipc_dir, f"mem_{tag}.bin")
    wsl_path = win_to_wsl(path)
    inst.dump_mem_bin(addr, size, wsl_path)
    time.sleep(0.3)
    try:
        with open(path, "rb") as f:
            return f.read()
    except FileNotFoundError:
        return None


def test_breakpoint(inst, ipc_dir, name, bp_addr, timeout=120):
    """Set breakpoint, continue, see if we reach it. Returns (pc, frame) or None."""
    print(f"    Setting BP at 0x{bp_addr:08X} ({name})...")
    inst.breakpoint(bp_addr)
    try:
        ack = inst.continue_exec()
        pc = parse_pc(ack)
        frame = parse_frame(ack)
        if pc == bp_addr:
            print(f"    HIT at frame {frame}")
            inst.breakpoint_clear()
            return (pc, frame)
        else:
            print(f"    UNEXPECTED PC: 0x{pc:08X} at frame {frame}")
            inst.breakpoint_clear()
            return (pc, frame)
    except TimeoutError:
        print(f"    TIMEOUT (>{timeout}s) — never reached!")
        inst.breakpoint_clear()
        # Pause to read state
        try:
            inst.pause()
        except:
            pass
        regs = dump_regs(inst, ipc_dir)
        if regs:
            print(f"    Stuck at: PC=0x{regs['PC']:08X} PR=0x{regs['PR']:08X}")
        return None


def main():
    MednafenInstance.kill_stale()
    time.sleep(1)

    print("=" * 60)
    print("  BREAKPOINT COMPARISON: Production vs +4 Free-Layout")
    print("=" * 60)

    # Test 1: Does the init chain (FUN_060030FC) get called?
    print(f"\n{'='*60}")
    print(f"  TEST 1: Init chain (FUN_060030FC)")
    print(f"{'='*60}")

    for label, cue, bp, ipc_name in [
        ("PROD", CUE_PROD, BP_INIT_PROD, "bp_init_prod"),
        ("+4  ", CUE_REIMPL, BP_INIT_FREE, "bp_init_free"),
    ]:
        print(f"\n  [{label}]")
        ipc = os.path.join(TMPDIR, ipc_name)
        inst = MednafenInstance(ipc_name, cue, ipc)
        inst.start()
        result = test_breakpoint(inst, ipc, "FUN_060030FC", bp)
        if result:
            regs = dump_regs(inst, ipc)
            if regs:
                print(f"    R4=0x{regs['R4']:08X} R5=0x{regs['R5']:08X}")
        inst.quit()
        time.sleep(1)
        MednafenInstance.kill_stale()
        time.sleep(0.5)

    # Test 2: Does SCDQ poll (FUN_060423CC) get called?
    print(f"\n{'='*60}")
    print(f"  TEST 2: SCDQ poll (FUN_060423CC)")
    print(f"{'='*60}")

    for label, cue, bp, ipc_name in [
        ("PROD", CUE_PROD, BP_SCDQ_PROD, "bp_scdq_prod"),
        ("+4  ", CUE_REIMPL, BP_SCDQ_FREE, "bp_scdq_free"),
    ]:
        print(f"\n  [{label}]")
        ipc = os.path.join(TMPDIR, ipc_name)
        inst = MednafenInstance(ipc_name, cue, ipc)
        inst.start()
        result = test_breakpoint(inst, ipc, "FUN_060423CC", bp)
        if result:
            regs = dump_regs(inst, ipc)
            if regs:
                print(f"    R4=0x{regs['R4']:08X} PR=0x{regs['PR']:08X}")
                # Dump HIRQ to see CD Block state
                hirq = dump_mem(inst, ipc, 0x25890008, 4, "hirq")
                if hirq and len(hirq) >= 2:
                    h = struct.unpack(">H", hirq[:2])[0]
                    print(f"    HIRQ=0x{h:04X} (SCDQ bit={(h>>10)&1})")
        inst.quit()
        time.sleep(1)
        MednafenInstance.kill_stale()
        time.sleep(0.5)

    # Test 3: Does ICF poll (FUN_0600C010) get called?
    print(f"\n{'='*60}")
    print(f"  TEST 3: ICF poll (FUN_0600C010)")
    print(f"{'='*60}")

    for label, cue, bp, ipc_name in [
        ("PROD", CUE_PROD, BP_ICF_PROD, "bp_icf_prod"),
        ("+4  ", CUE_REIMPL, BP_ICF_FREE, "bp_icf_free"),
    ]:
        print(f"\n  [{label}]")
        ipc = os.path.join(TMPDIR, ipc_name)
        inst = MednafenInstance(ipc_name, cue, ipc)
        inst.start()
        result = test_breakpoint(inst, ipc, "FUN_0600C010", bp)
        if result:
            regs = dump_regs(inst, ipc)
            if regs:
                print(f"    R4=0x{regs['R4']:08X} PR=0x{regs['PR']:08X}")
        inst.quit()
        time.sleep(1)
        MednafenInstance.kill_stale()
        time.sleep(0.5)

    # Test 4: Let both run for 3000 frames, compare game state
    print(f"\n{'='*60}")
    print(f"  TEST 4: Game state after 3000 frames (~50 seconds)")
    print(f"{'='*60}")

    for label, cue, ipc_name in [
        ("PROD", CUE_PROD, "bp_state_prod"),
        ("+4  ", CUE_REIMPL, "bp_state_free"),
    ]:
        print(f"\n  [{label}]")
        ipc = os.path.join(TMPDIR, ipc_name)
        inst = MednafenInstance(ipc_name, cue, ipc)
        inst.start()

        print(f"    Advancing 3000 frames...")
        try:
            ack = inst.frame_advance(3000)
            print(f"    Done: {ack}")
        except TimeoutError:
            print(f"    TIMEOUT")

        inst.pause()
        regs = dump_regs(inst, ipc)
        if regs:
            print(f"    PC = 0x{regs['PC']:08X}")
            print(f"    PR = 0x{regs['PR']:08X}")
            print(f"    SP = 0x{regs['R15']:08X}")

        # Dump game state variable area
        # The main loop jump table uses a state variable, typically early in data area
        # Let's check 0x06002D80 (sync counter seen before) and surrounding state
        sync = dump_mem(inst, ipc, 0x06002D80, 16, "sync")
        if sync:
            print(f"    Sync area (0x06002D80):")
            for i in range(0, len(sync), 4):
                val = struct.unpack(">I", sync[i:i+4])[0]
                print(f"      0x{0x06002D80+i:08X} = 0x{val:08X}")

        # Check VDP2 state (is display on?)
        vdp2 = dump_mem(inst, ipc, 0x25F80000, 8, "vdp2")
        if vdp2:
            tvmd = struct.unpack(">H", vdp2[:2])[0]
            disp = (tvmd >> 15) & 1
            print(f"    VDP2 TVMD=0x{tvmd:04X} (DISP={disp})")

        # Check VDP1 state
        vdp1 = dump_mem(inst, ipc, 0x25D00010, 8, "vdp1")
        if vdp1:
            edsr = struct.unpack(">H", vdp1[:2])[0]
            print(f"    VDP1 EDSR=0x{edsr:04X}")

        inst.quit()
        time.sleep(1)
        MednafenInstance.kill_stale()
        time.sleep(0.5)

    print("\nDone.")


if __name__ == "__main__":
    main()
