#!/usr/bin/env python3
"""diag_poll_r0.py - Check what R0 value the SCDQ poll loop sees.

Sets a breakpoint after the HIRQ read returns (at the EXTU.W instruction)
to inspect what value R0 has. Also checks what address R12 points to and
what the pool entry loaded into R0 (the HIRQ address).

Compares production and free builds.
"""

import os
import sys
import time
import struct
import re

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin

CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")
CUE_FREE = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
TMPDIR = os.path.join(PROJDIR, ".tmp")


def parse_pc(ack):
    m = re.search(r'pc=0x([0-9a-fA-F]+)', ack)
    return int(m.group(1), 16) if m else None

def parse_frame(ack):
    m = re.search(r'frame=(\d+)', ack)
    return int(m.group(1)) if m else None

def dump_regs(inst, ipc_dir, tag=""):
    path = os.path.join(ipc_dir, f"regs_{tag}.bin")
    inst.dump_regs_bin(path)
    time.sleep(0.3)
    return read_regs_bin(path)

def dump_mem(inst, ipc_dir, addr, size, tag=""):
    path = os.path.join(ipc_dir, f"mem_{tag}.bin")
    inst.dump_mem_bin(addr, size, path)
    time.sleep(0.3)
    try:
        with open(path, 'rb') as f:
            return f.read()
    except FileNotFoundError:
        return None


def check_build(name, cue, ipc_name, extu_addr, hirq_func_addr):
    """
    extu_addr: address of EXTU.W R0,R0 in the poll loop (after JSR @R12 returns)
    hirq_func_addr: address of sym_06035C4E (the HIRQ read function)
    """
    MednafenInstance.kill_stale()

    ipc = os.path.join(TMPDIR, ipc_name)
    inst = MednafenInstance(name, cue, ipc)
    inst.start()

    print(f"\n{'='*60}")
    print(f"  {name}")
    print(f"{'='*60}")

    # Let the game boot past BIOS
    inst.breakpoint(0x06003000)
    try:
        ack = inst.continue_exec()
        frame = parse_frame(ack)
        print(f"  _start at frame {frame}")
    except TimeoutError:
        print(f"  TIMEOUT waiting for _start!")
        inst.quit()
        MednafenInstance.kill_stale()
        return
    inst.breakpoint_clear()

    # Advance enough frames for the game to reach the poll loop
    print(f"  Advancing to poll loop...")
    inst.frame_advance(350)

    # Step 1: Check the HIRQ read function's pool entry
    # The MOV.L at hirq_func_addr loads the HIRQ register address from pool
    # Let's dump the code and nearby pool entries
    print(f"\n  HIRQ read function at 0x{hirq_func_addr:08X}:")
    mem = dump_mem(inst, ipc, hirq_func_addr, 64, "hirq_func")
    if mem:
        for i in range(0, min(len(mem), 48), 2):
            b = mem[i:i+2]
            print(f"    0x{hirq_func_addr+i:08X}: {b[0]:02X} {b[1]:02X}")

    # Calculate pool entry address for MOV.L @(0x0A*4, PC), R0
    # at hirq_func_addr
    pc_plus4 = hirq_func_addr + 4
    aligned_pc = pc_plus4 & ~3
    pool_addr = aligned_pc + 0x0A * 4
    print(f"\n  MOV.L pool calculation:")
    print(f"    PC = 0x{hirq_func_addr:08X}")
    print(f"    (PC+4) = 0x{pc_plus4:08X}")
    print(f"    (PC+4)&~3 = 0x{aligned_pc:08X}")
    print(f"    EA = 0x{aligned_pc:08X} + 0x28 = 0x{pool_addr:08X}")

    # Dump the pool entry
    pool_mem = dump_mem(inst, ipc, pool_addr, 4, "pool_entry")
    if pool_mem and len(pool_mem) >= 4:
        pool_val = struct.unpack('>I', pool_mem[:4])[0]
        print(f"    Pool value at 0x{pool_addr:08X} = 0x{pool_val:08X}")
        if pool_val == 0x25890008:
            print(f"    => CORRECT! Points to CDB HIRQ register")
        else:
            print(f"    => WRONG! Expected 0x25890008 (CDB HIRQ)")

    # Step 2: Set breakpoint at EXTU.W to see R0 after HIRQ read
    print(f"\n  Breakpoint at EXTU.W (0x{extu_addr:08X}) to inspect R0...")
    inst.breakpoint(extu_addr)
    try:
        ack = inst.continue_exec()
        pc = parse_pc(ack)
        print(f"  Hit EXTU.W at PC=0x{pc:08X}")
        inst.breakpoint_clear()

        # R0 should contain the raw return from sym_06035C4E (HIRQ value)
        regs = dump_regs(inst, ipc, "extu")
        if regs:
            r0 = regs['R0']
            r12 = regs['R12']
            r14 = regs['R14']
            print(f"  R0  = 0x{r0:08X} (raw HIRQ return value)")
            print(f"  R12 = 0x{r12:08X} (HIRQ read function ptr)")
            print(f"  R14 = 0x{r14:08X} (expected 0x00000400 = SCDQ mask)")

            # Simulate what the poll loop does
            r0_extu = r0 & 0xFFFF
            r0_and = r0_extu & r14
            t = 1 if r0_and == 0 else 0
            bt = "TAKEN (loops)" if t == 1 else "NOT TAKEN (exits)"
            print(f"\n  Simulated poll logic:")
            print(f"    EXTU.W R0 -> 0x{r0_extu:04X}")
            print(f"    AND R14   -> 0x{r0_and:08X}")
            print(f"    TST R0,R0 -> T={t}")
            print(f"    BT        -> {bt}")

        # Now step through a few iterations to see if R0 changes
        print(f"\n  Stepping through poll iterations:")
        inst.breakpoint(extu_addr)
        for i in range(5):
            try:
                ack = inst.continue_exec()
                pc = parse_pc(ack)
                regs = dump_regs(inst, ipc, f"iter{i}")
                if regs:
                    r0 = regs['R0']
                    r0_masked = (r0 & 0xFFFF) & 0x0400
                    exits = "EXIT" if r0_masked else "LOOP"
                    print(f"    Iteration {i}: R0=0x{r0:08X} masked=0x{r0_masked:04X} -> {exits}")
            except TimeoutError:
                print(f"    Iteration {i}: TIMEOUT (poll exited or stuck)")
                break
        inst.breakpoint_clear()

    except TimeoutError:
        print(f"  EXTU.W breakpoint not reached!")
        regs = dump_regs(inst, ipc, "extu_timeout")
        if regs:
            print(f"  Stuck at PC=0x{regs['PC']:08X}")

    inst.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()


def main():
    print("=" * 70)
    print("  Poll Loop R0 Diagnosis")
    print("=" * 70)

    # Production:
    # EXTU.W is at 0x060423E2 (after JSR @R12 returns)
    # sym_06035C4E is at 0x06035C4E
    print("\n>>> PRODUCTION <<<")
    check_build("PROD", CUE_PROD, "r0_prod",
                extu_addr=0x060423E2,
                hirq_func_addr=0x06035C4E)

    time.sleep(2)

    # Free layout:
    # EXTU.W is at 0x060423E6 (shifted +4)
    # sym_06035C4E is at 0x06035C52 (shifted +4)
    print("\n>>> FREE-LAYOUT <<<")
    check_build("FREE", CUE_FREE, "r0_free",
                extu_addr=0x060423E6,
                hirq_func_addr=0x06035C52)


if __name__ == "__main__":
    main()
