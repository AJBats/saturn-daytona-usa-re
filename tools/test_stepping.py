#!/usr/bin/env python3
"""test_stepping.py — Validate instruction stepping and breakpoints.

Quick test that:
1. Launches one Mednafen instance with production disc
2. Steps 10 instructions, verifying PC changes
3. Sets a breakpoint and continues to it
4. Dumps registers at breakpoint
"""

import os
import sys
import time
import re

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from parallel_compare import MednafenInstance, read_regs_bin, win_to_wsl

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")
TMPDIR = os.path.join(PROJDIR, ".tmp")


def main():
    ipc = os.path.join(TMPDIR, "emu_step_test")
    inst = MednafenInstance("step_test", CUE_PROD, ipc)

    print("=== Instruction Stepping & Breakpoint Test ===\n")

    print("Starting emulator (production disc)...")
    inst.start()

    # Test 1: frame_advance to get past BIOS init
    print("\n--- Test 1: Advance 100 frames (BIOS init) ---")
    ack = inst.frame_advance(100)
    print(f"  {ack}")

    # Test 2: Step 1 instruction
    print("\n--- Test 2: Step 1 instruction ---")
    ack = inst.step(1)
    print(f"  {ack}")
    m = re.search(r'pc=0x([0-9a-fA-F]+)', ack)
    if m:
        print(f"  Stopped at PC=0x{m.group(1)}")
    else:
        print(f"  WARNING: Could not parse PC from ack")

    # Test 3: Dump registers while instruction-paused
    print("\n--- Test 3: Dump registers at instruction-level pause ---")
    regs_path = os.path.join(ipc, "regs.bin")
    inst.dump_regs_bin(regs_path)
    time.sleep(0.2)
    regs = read_regs_bin(regs_path)
    if regs:
        print(f"  PC=0x{regs['PC']:08X} R15(SP)=0x{regs['R15']:08X}")
        print(f"  SR=0x{regs['SR']:08X} PR=0x{regs['PR']:08X}")
    else:
        print("  ERROR: Could not read registers")

    # Test 4: Step 10 more instructions, track PC changes
    print("\n--- Test 4: Step 10 instructions, tracking PC ---")
    pcs = []
    for i in range(10):
        ack = inst.step(1)
        m = re.search(r'pc=0x([0-9a-fA-F]+)', ack)
        if m:
            pc = int(m.group(1), 16)
            pcs.append(pc)
            print(f"  Step {i+1}: PC=0x{pc:08X}")
        else:
            print(f"  Step {i+1}: ERROR parsing ack: {ack}")

    if len(set(pcs)) > 1:
        print(f"  PASS: PC changed across steps ({len(set(pcs))} unique values)")
    else:
        print(f"  FAIL: PC didn't change — stepping may not work")

    # Test 5: Set breakpoint and continue
    # Use main entry point — the game loops through this every frame
    bp_addr = 0x06003000
    print(f"\n--- Test 5: Set breakpoint at 0x{bp_addr:08X} and continue ---")

    # First, advance some frames to get to a different execution point
    print("  Advancing 10 more frames...")
    ack = inst.frame_advance(10)
    print(f"  {ack}")

    print(f"  Setting breakpoint at 0x{bp_addr:08X}...")
    ack = inst.breakpoint(bp_addr)
    print(f"  {ack}")

    print("  Continuing to breakpoint...")
    ack = inst.continue_exec()
    print(f"  {ack}")

    if "break" in ack:
        m = re.search(r'pc=0x([0-9a-fA-F]+)', ack)
        if m and int(m.group(1), 16) == bp_addr:
            print(f"  PASS: Stopped at expected breakpoint 0x{bp_addr:08X}")
        elif m:
            print(f"  UNEXPECTED: Stopped at 0x{m.group(1)} instead of 0x{bp_addr:08X}")
    else:
        print(f"  WARNING: Did not hit breakpoint (ack: {ack})")

    # Test 6: Clear breakpoints
    print("\n--- Test 6: Clear breakpoints ---")
    ack = inst.breakpoint_clear()
    print(f"  {ack}")

    # Test 7: Dump memory while instruction-paused
    print("\n--- Test 7: Dump memory at instruction-level pause ---")
    mem_path = os.path.join(ipc, "mem_test.bin")
    inst.dump_mem_bin(0x06003000, 0x40, mem_path)
    time.sleep(0.2)
    try:
        with open(mem_path, "rb") as f:
            data = f.read()
        print(f"  Got {len(data)} bytes from 0x06003000")
        if len(data) >= 4:
            first_word = int.from_bytes(data[:4], 'little')
            print(f"  First word: 0x{first_word:08X}")
            print(f"  PASS: Memory dump works during instruction-level pause")
    except FileNotFoundError:
        print(f"  FAIL: Could not read memory dump")

    inst.quit()
    print("\n=== All tests complete ===")


if __name__ == "__main__":
    main()
