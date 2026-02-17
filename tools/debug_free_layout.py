#!/usr/bin/env python3
"""debug_free_layout.py -- Trace where the free-layout build diverges.

Sets breakpoints at key boot sequence points (shifted by SHIFT bytes)
and traces CPU execution to find the exact failure point.
"""
import os, sys, time, re, struct

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin, TMPDIR

CUE_REIMPL = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")

# Shift amount (must match sawyer_free.ld)
SHIFT = 4

# Key addresses (original, from byte-identical build)
# These all shift by SHIFT in the free-layout build, EXCEPT _start (0x06003000)
ENTRY       = 0x06003000  # _start — NOT shifted
FIRST_FUNC  = 0x060030FC + SHIFT  # FUN_060030FC — first function called


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


def main():
    MednafenInstance.kill_stale()
    ipc_dir = os.path.join(TMPDIR, "debug_free")
    inst = MednafenInstance("free", CUE_REIMPL, ipc_dir)

    print(f"Starting free-layout build (shift={SHIFT})...")
    inst.start()

    # Phase 1: Verify entry point reached
    print(f"\n[1] Breakpoint at entry 0x{ENTRY:08X}...")
    inst.breakpoint(ENTRY)
    try:
        ack = inst.continue_exec()
        pc = parse_pc(ack)
        if pc == ENTRY:
            print(f"    Entry reached at frame {parse_frame(ack)}")
        else:
            print(f"    UNEXPECTED: pc=0x{pc:08X}")
            inst.send("quit")
            return
    except TimeoutError:
        print("    TIMEOUT — entry never reached!")
        inst.send("quit")
        return
    inst.breakpoint_clear()

    # Phase 2: Dump registers and memory at entry
    print("\n[2] Registers at entry:")
    regs = dump_regs(inst, ipc_dir)
    if regs:
        for name in ["PC", "R15", "SR", "PR", "VBR", "R0", "R1"]:
            print(f"    {name:5s} = 0x{regs.get(name, 0):08X}")

    # Phase 3: Step through _start instructions to verify pool loads
    print(f"\n[3] Stepping through _start (20 instructions)...")
    for i in range(20):
        ack = inst.step(1)
        regs = dump_regs(inst, ipc_dir)
        if regs:
            pc = regs['PC']
            r0, r1 = regs['R0'], regs['R1']
            r15 = regs['R15']
            pr = regs['PR']
            print(f"    step {i+1:2d}: PC=0x{pc:08X} R0=0x{r0:08X} R1=0x{r1:08X} SP=0x{r15:08X} PR=0x{pr:08X}")

    # Phase 4: Set breakpoint at first function call target
    print(f"\n[4] Breakpoint at FUN_060030FC (shifted to 0x{FIRST_FUNC:08X})...")
    inst.breakpoint(FIRST_FUNC)
    try:
        ack = inst.continue_exec()
        pc = parse_pc(ack)
        frame = parse_frame(ack)
        if pc == FIRST_FUNC:
            print(f"    FUN_060030FC reached at frame {frame}")
        else:
            print(f"    UNEXPECTED: pc=0x{pc:08X} (frame {frame})")
            # Dump registers to understand where we are
            regs = dump_regs(inst, ipc_dir)
            if regs:
                print(f"    PC=0x{regs['PC']:08X} PR=0x{regs['PR']:08X}")
                print(f"    SR=0x{regs['SR']:08X} SP=0x{regs['R15']:08X}")
            inst.send("quit")
            return
    except TimeoutError:
        print("    TIMEOUT — FUN_060030FC never reached!")
        regs = dump_regs(inst, ipc_dir)
        if regs:
            print(f"    Stuck at: PC=0x{regs['PC']:08X} PR=0x{regs['PR']:08X}")
            print(f"              SR=0x{regs['SR']:08X} SP=0x{regs['R15']:08X}")
            print(f"              VBR=0x{regs['VBR']:08X}")
        inst.send("quit")
        return
    inst.breakpoint_clear()

    # Phase 5: Walk through boot callees (all shifted)
    CALLEES = [
        ("FUN_0600A392",    0x0600A392 + SHIFT),  # called from _start jump table
        ("system_init",     0x06053FC4 + SHIFT),
        ("per_frame_setup", 0x06054684 + SHIFT),
    ]

    print(f"\n[5] Walking through key callees...")
    for name, addr in CALLEES:
        inst.breakpoint(addr)

    for name, addr in CALLEES:
        try:
            ack = inst.continue_exec()
            pc = parse_pc(ack)
            frame = parse_frame(ack)
            found_name = "unknown"
            for n, a in CALLEES:
                if pc == a:
                    found_name = n
                    break
            print(f"    {found_name}: pc=0x{pc:08X} (frame {frame})")
        except TimeoutError:
            print(f"    TIMEOUT waiting for {name} (0x{addr:08X})")
            regs = dump_regs(inst, ipc_dir)
            if regs:
                print(f"    Stuck at: PC=0x{regs['PC']:08X} PR=0x{regs['PR']:08X}")
                print(f"              SR=0x{regs['SR']:08X} SP=0x{regs['R15']:08X}")
            break
    inst.breakpoint_clear()

    # Phase 6: Let it run for a few frames and capture PC trace
    print(f"\n[6] Capturing PC trace for one frame...")
    trace_path = os.path.join(ipc_dir, "pc_trace.bin")
    inst.pc_trace_frame(trace_path.replace("D:", "/mnt/d").replace("\\", "/"))
    time.sleep(1)

    # Read and analyze trace
    win_trace = os.path.join(ipc_dir, "pc_trace.bin")
    try:
        with open(win_trace, "rb") as f:
            trace_data = f.read()
        n_pcs = len(trace_data) // 4
        print(f"    {n_pcs} instructions traced")
        if n_pcs > 0:
            pcs = struct.unpack(f"<{n_pcs}I", trace_data)
            # Show last 20 PCs
            print(f"    Last 20 PCs:")
            for j in range(max(0, n_pcs-20), n_pcs):
                print(f"      [{j:5d}] PC=0x{pcs[j]:08X}")
    except FileNotFoundError:
        print("    Trace file not found")

    inst.send("quit")
    time.sleep(1)
    MednafenInstance.kill_stale()
    print("\nDone.")


if __name__ == "__main__":
    main()
