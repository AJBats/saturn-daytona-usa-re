#!/usr/bin/env python3
"""debug_find_stuck.py -- Find where the free-layout build gets stuck.

Runs free-layout build for 10 seconds, pauses, and checks CPU state.
Also runs prod for comparison.
"""
import os, sys, time, re, struct

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin, TMPDIR

CUE_REIMPL = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")

SHIFT = 16


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
    wsl_path = path.replace("D:", "/mnt/d").replace("\\", "/")
    inst.dump_mem_bin(addr, size, wsl_path)
    time.sleep(0.5)
    try:
        with open(path, "rb") as f:
            return f.read()
    except FileNotFoundError:
        return None


def check_instance(label, inst, ipc_dir):
    """Pause instance and dump its state."""
    print(f"\n=== {label} state ===")

    # Pause it
    ack = inst.pause()
    print(f"  Pause ack: {ack}")
    # Get state from registers instead
    time.sleep(0.5)

    regs = dump_regs(inst, ipc_dir)
    if regs:
        for name in ["PC", "R0", "R1", "R2", "R3", "R4", "R5",
                      "R13", "R14", "R15", "PR", "SR", "VBR"]:
            print(f"  {name:5s} = 0x{regs.get(name, 0):08X}")

    # Step a few times to see if we're in a tight loop
    print(f"\n  Stepping 20 instructions from PC=0x{regs['PC']:08X}...")
    pcs = []
    for i in range(20):
        ack = inst.step(1)
        r = dump_regs(inst, ipc_dir)
        if r:
            pcs.append(r['PC'])
            print(f"    step {i+1:2d}: PC=0x{r['PC']:08X} R0=0x{r['R0']:08X}")

    # Check for loops
    unique_pcs = set(pcs)
    if len(unique_pcs) < 6:
        print(f"\n  TIGHT LOOP DETECTED: {len(unique_pcs)} unique PCs out of 20 steps")
        print(f"  Loop PCs: {', '.join(f'0x{p:08X}' for p in sorted(unique_pcs))}")
    else:
        print(f"\n  {len(unique_pcs)} unique PCs — not a tight loop")

    return regs


def main():
    MednafenInstance.kill_stale()

    ipc_prod = os.path.join(TMPDIR, "find_stuck_prod")
    ipc_free = os.path.join(TMPDIR, "find_stuck_free")

    print("Starting both instances...")
    prod = MednafenInstance("prod", CUE_PROD, ipc_prod)
    free = MednafenInstance("free", CUE_REIMPL, ipc_free)
    prod.start()
    free.start()

    # Let both run freely for 10 seconds
    print("\nLetting both run for 10 seconds...")
    prod.send("continue")
    free.send("continue")
    time.sleep(10)

    # Pause and check both
    regs_p = check_instance("PROD", prod, ipc_prod)
    regs_f = check_instance("FREE", free, ipc_free)

    # Compare
    if regs_p and regs_f:
        print(f"\n=== Comparison ===")
        pc_p = regs_p['PC']
        pc_f = regs_f['PC']
        diff = pc_f - pc_p
        if diff == SHIFT:
            print(f"  PCs differ by exactly +{SHIFT} (shift OK)")
        elif diff == 0:
            print(f"  PCs are identical (possible — both at same instruction)")
        else:
            print(f"  PCs differ by {diff} — FREE is at a different point in execution!")

    prod.send("quit")
    free.send("quit")
    time.sleep(1)
    MednafenInstance.kill_stale()
    print("\nDone.")


if __name__ == "__main__":
    main()
