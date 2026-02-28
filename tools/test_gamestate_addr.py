#!/usr/bin/env python3
"""test_gamestate_addr.py -- Find actual game state address in reimpl vs prod.

The symbol g_game_state maps to 0x0605AD00 in the free-layout build
(shifted by -0x10). This script verifies where the game state actually lives.
"""
import os, sys, time, struct

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin, win_to_wsl, TMPDIR

CUE_REIMPL = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")


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


def dump_regs(inst, ipc_dir):
    path = os.path.join(ipc_dir, "regs.bin")
    inst.dump_regs_bin(path)
    time.sleep(0.2)
    return read_regs_bin(path)


def main():
    MednafenInstance.kill_stale()
    time.sleep(1)

    print("=" * 60)
    print("  GAME STATE ADDRESS COMPARISON")
    print("=" * 60)

    # Test both production and reimpl
    for label, cue, ipc_name in [
        ("PRODUCTION", CUE_PROD, "gs_prod"),
        ("REIMPL", CUE_REIMPL, "gs_reimpl"),
    ]:
        print(f"\n{'='*60}")
        print(f"  {label}")
        print(f"{'='*60}")

        ipc = os.path.join(TMPDIR, ipc_name)
        inst = MednafenInstance(ipc_name, cue, ipc)
        inst.start()

        # Advance to attract mode (2000 frames = ~33 seconds)
        print(f"  Advancing 2000 frames...")
        try:
            inst.frame_advance(2000)
        except TimeoutError:
            print(f"  TIMEOUT at 2000 frames")

        inst.pause()
        regs = dump_regs(inst, ipc)
        if regs:
            print(f"  PC = 0x{regs['PC']:08X}")

        # Dump a wide range around 0x0605AD00-0x0605AD20
        mem = dump_mem(inst, ipc, 0x0605ACE0, 0x60, "gamestate_area")
        if mem:
            print(f"\n  Memory at 0x0605ACE0 (96 bytes):")
            for i in range(0, len(mem), 4):
                val = struct.unpack(">I", mem[i:i+4])[0]
                addr = 0x0605ACE0 + i
                # Annotate known addresses
                note = ""
                if addr == 0x0605AD00:
                    note = " <-- g_game_state in free build"
                elif addr == 0x0605AD10:
                    note = " <-- original 0x0605AD10"
                elif val < 100:
                    note = f" (small int: {val})"
                print(f"    0x{addr:08X}: 0x{val:08X}{note}")

        inst.quit()
        time.sleep(1)
        MednafenInstance.kill_stale()
        time.sleep(0.5)

    print("\nDone.")


if __name__ == "__main__":
    main()
