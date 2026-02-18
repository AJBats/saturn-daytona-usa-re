#!/usr/bin/env python3
"""diag_free_boot.py - Deep diagnosis of free-layout boot failure.

Boots the free-layout disc, sets breakpoints at critical addresses, and
dumps memory/registers to trace where execution diverges from production.

Key addresses (free build = production + 4):
  _start:      0x06003000 (same in both - before the shift)
  system_init: 0x06003100 (was 0x060030FC in production)
  main_loop:   0x0600300E (was 0x0600300A in production)
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

# Address constants
START_ADDR = 0x06003000
SYSTEM_INIT_PROD = 0x060030FC
SYSTEM_INIT_FREE = 0x06003100  # shifted +4
MAIN_LOOP_PROD = 0x0600300A
MAIN_LOOP_FREE = 0x0600300E   # shifted +4

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

def hexdump(data, base_addr, limit=64):
    """Print hex dump of data."""
    for i in range(0, min(len(data), limit), 16):
        hex_part = ' '.join(f'{b:02X}' for b in data[i:i+16])
        ascii_part = ''.join(chr(b) if 32 <= b < 127 else '.' for b in data[i:i+16])
        print(f"    0x{base_addr+i:08X}: {hex_part:<48s} {ascii_part}")

def test_build(name, cue, ipc_name, sys_init_addr, main_loop_addr):
    """Detailed boot trace of one build."""
    MednafenInstance.kill_stale()

    ipc = os.path.join(TMPDIR, ipc_name)
    inst = MednafenInstance(name, cue, ipc)
    inst.start()

    print(f"\n{'='*60}")
    print(f"  {name}")
    print(f"{'='*60}")

    # Step 1: Breakpoint at _start
    print(f"\n  [1] Breakpoint at _start (0x{START_ADDR:08X})")
    inst.breakpoint(START_ADDR)
    try:
        ack = inst.continue_exec()
    except TimeoutError:
        print(f"  TIMEOUT waiting for _start! Game code never reached.")
        inst.quit()
        MednafenInstance.kill_stale()
        return
    pc = parse_pc(ack)
    frame = parse_frame(ack)
    print(f"  Hit _start at frame {frame}, PC=0x{pc:08X}")
    inst.breakpoint_clear()

    # Dump memory at _start (first 256 bytes of game code)
    mem = dump_mem(inst, ipc, START_ADDR, 256, "start_code")
    if mem:
        print(f"\n  Memory at _start (0x{START_ADDR:08X}):")
        hexdump(mem, START_ADDR, 64)

    # Check what _start's pool entry points to for system_init
    # In _start.s: mov.l @(0x5C, PC), R1  → loads system_init address
    # The pool entry is at _start + 0x60 (word-aligned)
    print(f"\n  Pool entries at _start:")
    if mem and len(mem) >= 0x70:
        for off in range(0x50, min(0x70, len(mem)), 4):
            val = struct.unpack('>I', mem[off:off+4])[0]
            print(f"    0x{START_ADDR+off:08X}: 0x{val:08X}")

    # Dump registers at _start
    regs = dump_regs(inst, ipc, "start")
    if regs:
        print(f"\n  Registers at _start:")
        print(f"    PC=0x{regs['PC']:08X} SR=0x{regs['SR']:08X} PR=0x{regs['PR']:08X}")
        print(f"    R0=0x{regs['R0']:08X} R1=0x{regs['R1']:08X} R15=0x{regs['R15']:08X}")

    # Step 2: Breakpoint at system_init
    print(f"\n  [2] Breakpoint at system_init (0x{sys_init_addr:08X})")
    inst.breakpoint(sys_init_addr)
    try:
        ack = inst.continue_exec()
        pc = parse_pc(ack)
        frame = parse_frame(ack)
        print(f"  Hit system_init at frame {frame}, PC=0x{pc:08X}")
        inst.breakpoint_clear()

        regs = dump_regs(inst, ipc, "sysinit")
        if regs:
            print(f"    R0=0x{regs['R0']:08X} R1=0x{regs['R1']:08X} PR=0x{regs['PR']:08X}")
            print(f"    R15=0x{regs['R15']:08X}")

        # Dump first 128 bytes of system_init
        mem = dump_mem(inst, ipc, sys_init_addr, 128, "sysinit_code")
        if mem:
            print(f"\n  Code at system_init:")
            hexdump(mem, sys_init_addr, 64)

    except TimeoutError:
        print(f"  TIMEOUT waiting for system_init!")
        regs = dump_regs(inst, ipc, "sysinit_timeout")
        if regs:
            print(f"    Stuck at PC=0x{regs['PC']:08X} PR=0x{regs['PR']:08X}")
        inst.quit()
        MednafenInstance.kill_stale()
        return

    # Step 3: Breakpoint at main_loop (system_init return)
    print(f"\n  [3] Breakpoint at main_loop (0x{main_loop_addr:08X}) — 60s timeout")
    inst.breakpoint(main_loop_addr)
    try:
        # Override to longer timeout since system_init takes many frames
        inst.last_ack = inst._read_ack() or ""
        inst._write_action(f"continue")
        time.sleep(0.1)
        ack = inst._read_ack()
        if ack and ack.startswith("ok continue"):
            inst.last_ack = ack
        # Wait up to 60 seconds
        deadline = time.time() + 60
        while time.time() < deadline:
            ack = inst._read_ack()
            if ack and ack != inst.last_ack and "break" in ack:
                inst.last_ack = ack
                break
            time.sleep(0.1)
        else:
            raise TimeoutError("main_loop")

        pc = parse_pc(ack)
        frame = parse_frame(ack)
        print(f"  MAIN LOOP REACHED at frame {frame}, PC=0x{pc:08X}")
        inst.breakpoint_clear()

        regs = dump_regs(inst, ipc, "mainloop")
        if regs:
            print(f"    R0=0x{regs['R0']:08X} R15=0x{regs['R15']:08X}")

    except TimeoutError:
        print(f"  TIMEOUT! Main loop never reached in 60 seconds.")
        inst.breakpoint_clear()
        regs = dump_regs(inst, ipc, "mainloop_timeout")
        if regs:
            print(f"    Stuck at PC=0x{regs['PC']:08X} PR=0x{regs['PR']:08X}")
            print(f"    SR=0x{regs['SR']:08X} R15=0x{regs['R15']:08X}")

        # Step 4: If stuck, try to identify the stuck location
        print(f"\n  [4] Analyzing stuck location...")
        # Sample PC multiple times to see if we're in a tight loop
        pcs = []
        for i in range(5):
            inst.step(100)
            time.sleep(0.2)
            r = dump_regs(inst, ipc, f"sample{i}")
            if r:
                pcs.append(r['PC'])
                print(f"    Sample {i}: PC=0x{r['PC']:08X} PR=0x{r['PR']:08X}")

        if len(pcs) >= 2:
            if len(set(pcs)) == 1:
                print(f"    => STUCK at single address 0x{pcs[0]:08X}")
            elif max(pcs) - min(pcs) < 0x100:
                print(f"    => TIGHT LOOP between 0x{min(pcs):08X} - 0x{max(pcs):08X}")
            else:
                print(f"    => Still executing (addresses spread)")

        # Dump memory around the stuck PC
        if pcs:
            stuck_pc = pcs[-1]
            mem = dump_mem(inst, ipc, stuck_pc & ~0xF, 64, "stuck_code")
            if mem:
                print(f"\n  Code around stuck PC:")
                hexdump(mem, stuck_pc & ~0xF, 64)

            # Also dump the area that SHOULD be system_init callees
            # Check FUN_06040B8E/FUN_06040B90 area (the fall-through chain)
            fall_through_addr = 0x06040B8E + 4  # shifted in free build
            mem2 = dump_mem(inst, ipc, fall_through_addr, 64, "fallthrough")
            if mem2:
                print(f"\n  FUN_06040B8E area (0x{fall_through_addr:08X}) in free build:")
                hexdump(mem2, fall_through_addr, 64)

    inst.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()


def main():
    print("=" * 70)
    print("  Free-Layout Boot Diagnosis")
    print("=" * 70)

    # Test production first (as baseline)
    print("\n>>> PRODUCTION (baseline) <<<")
    test_build("PROD", CUE_PROD, "diag_prod",
               SYSTEM_INIT_PROD, MAIN_LOOP_PROD)

    time.sleep(2)

    # Test free-layout
    print("\n>>> FREE-LAYOUT <<<")
    test_build("FREE", CUE_FREE, "diag_free",
               SYSTEM_INIT_FREE, MAIN_LOOP_FREE)


if __name__ == "__main__":
    main()
