#!/usr/bin/env python3
"""icf_diagnose.py — Find the exact instruction causing the slave SH-2 address error.

Boots the free-layout disc (no ICF bypass) in automation mode, sets a breakpoint
at the CPU Address Error exception handler entry (sym_06028248 -> 0x0602824C in
free build), then dumps registers and stack to find the faulting instruction.

The SH-2 pushes SR and PC onto the stack before entering the exception handler:
  @(0, R15) = pushed SR
  @(4, R15) = pushed PC  (address of instruction after the fault)
"""

import os
import sys
import time
import struct

# Add project root to path for imports
PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJ, "tools"))

from parallel_compare import MednafenInstance, win_to_wsl, TMPDIR

CUE_FREE = os.path.join(PROJ, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")

# In the free build (+4 shift):
# sym_06028248 (CPU Address Error handler) -> 0x0602824C
ADDR_ERR_HANDLER = 0x0602824C

# Also set breakpoints at other exception handlers to see which fires
ILLEGAL_INSN_HANDLER = 0x0602821C  # sym_06028218 + 4 (General Illegal Instruction, vec 4)
SLOT_ILLEGAL_HANDLER = 0x06028234  # sym_06028230 + 4 (Slot Illegal Instruction, vec 6)

# SETT/BT$ trap (the deliberate halt in the handler)
TRAP_ADDR = 0x0602829A  # 0x06028296 + 4

# Master's MINIT write (in FUN_0600C010) — to confirm master reaches ICF sync
# In free build, FUN_0600C010 is at 0x0600C014
MASTER_ICF_ENTRY = 0x0600C014

# Slave callback entry
SLAVE_CALLBACK_ENTRY = 0x0600C174  # FUN_0600C170 + 4


def main():
    os.makedirs(TMPDIR, exist_ok=True)

    # Kill stale instances
    MednafenInstance.kill_stale()

    ipc_dir = os.path.join(TMPDIR, "icf_diag")
    inst = MednafenInstance("free", CUE_FREE, ipc_dir)

    print("Starting Mednafen with free-layout disc (no ICF bypass)...")
    inst.start()
    print("Ready.")

    # Advance past BIOS to game code
    print("Advancing 60 frames (past BIOS)...")
    ack = inst.frame_advance(60)
    print(f"  Frame advance done: {ack}")

    # Set breakpoints at all three exception handlers + key ICF points
    print("\nSetting breakpoints:")
    for name, addr in [
        ("CPU Address Error handler", ADDR_ERR_HANDLER),
        ("Illegal Instruction handler", ILLEGAL_INSN_HANDLER),
        ("Slot Illegal handler", SLOT_ILLEGAL_HANDLER),
        ("SETT/BT$ trap", TRAP_ADDR),
        ("Master ICF entry", MASTER_ICF_ENTRY),
        ("Slave callback entry", SLAVE_CALLBACK_ENTRY),
    ]:
        ack = inst.send(f"breakpoint {addr:X}")
        print(f"  {name} @ 0x{addr:08X}: {ack}")

    # Now continue execution — one of these should fire
    # "continue" sends two acks: "ok continue" then "break pc=..." on hit
    print("\nContinuing execution (waiting for breakpoint hit)...")
    try:
        # First ack: "ok continue"
        inst.last_ack = inst._read_ack() or ""
        inst._write_action("continue")
        ack = inst._wait_ack_change(timeout=10)
        print(f"  First ack: {ack}")

        # Second ack: "break pc=..." (this may take a while as game boots)
        ack = inst._wait_ack_change(timeout=120)
        print(f"  Breakpoint hit: {ack}")
    except TimeoutError:
        print("  TIMEOUT: No breakpoint hit in 120 seconds!")
        # Try to pause and get status
        try:
            inst._write_action("pause")
            time.sleep(1)
            ack = inst._read_ack()
            print(f"  After pause: {ack}")
            ack = inst.send("dump_regs")
            print(f"  Regs at timeout: {ack}")
        except Exception as e:
            print(f"  Error getting status: {e}")
        inst.send("quit")
        return

    # Parse which breakpoint hit
    hit_pc = None
    if "break pc=" in ack:
        import re
        m = re.search(r'break pc=0x([0-9a-fA-F]+)', ack)
        if m:
            hit_pc = int(m.group(1), 16)
            print(f"\n  HIT PC: 0x{hit_pc:08X}")

            if hit_pc == ADDR_ERR_HANDLER:
                print("  >>> CPU Address Error exception handler!")
            elif hit_pc == ILLEGAL_INSN_HANDLER:
                print("  >>> Illegal Instruction exception handler!")
            elif hit_pc == SLOT_ILLEGAL_HANDLER:
                print("  >>> Slot Illegal Instruction handler!")
            elif hit_pc == TRAP_ADDR:
                print("  >>> Hit the SETT/BT$ trap directly!")
            elif hit_pc == MASTER_ICF_ENTRY:
                print("  >>> Master reached ICF sync (FUN_0600C010)!")
            elif hit_pc == SLAVE_CALLBACK_ENTRY:
                print("  >>> Slave callback entered (FUN_0600C170)!")
            else:
                print(f"  >>> Unknown breakpoint at 0x{hit_pc:08X}")

    # Dump registers
    print("\nDumping registers...")
    regs_file = os.path.join(TMPDIR, "icf_diag_regs.bin")
    ack = inst.dump_regs_bin(regs_file)
    print(f"  Dump ack: {ack}")

    # Also get text registers
    ack = inst.dump_regs()
    print(f"  Registers:\n{ack}")

    # Read register binary to get R15 (stack pointer)
    if os.path.exists(regs_file):
        with open(regs_file, "rb") as f:
            reg_data = f.read()
        if len(reg_data) >= 88:  # 22 * 4 bytes
            regs = struct.unpack('<22I', reg_data)
            reg_names = [f"R{i}" for i in range(16)] + ["PC", "SR", "PR", "GBR", "VBR", "MACH"]
            print("\n  Parsed registers:")
            for i, name in enumerate(reg_names):
                print(f"    {name:4s} = 0x{regs[i]:08X}")

            r15 = regs[15]  # Stack pointer
            print(f"\n  Stack pointer R15 = 0x{r15:08X}")

            # Dump stack memory to find pushed SR and PC
            # The exception handler pushes: the CPU auto-pushes SR and PC before handler entry
            # Then the handler pushes R7-R0 and PR (9 more words = 36 bytes)
            # So at handler ENTRY (before its own pushes), the stack looks like:
            #   @(0, R15) = pushed SR
            #   @(4, R15) = pushed PC (fault return address)
            # But if we hit the breakpoint AT the handler entry, the handler hasn't
            # pushed anything yet, so R15 still points at the auto-pushed values.

            # Dump 64 bytes from stack pointer
            print(f"\n  Dumping stack at R15=0x{r15:08X}:")
            stack_file = os.path.join(TMPDIR, "icf_diag_stack.bin")
            stack_wsl = win_to_wsl(stack_file)
            ack = inst.send(f"dump_mem_bin {r15:X} 40 {stack_wsl}")
            print(f"  Stack dump ack: {ack}")

            if os.path.exists(stack_file):
                with open(stack_file, "rb") as f:
                    stack_data = f.read()
                print(f"  Stack bytes ({len(stack_data)}):")
                # SH-2 is big-endian
                for off in range(0, min(len(stack_data), 64), 4):
                    val = struct.unpack('>I', stack_data[off:off+4])[0]
                    print(f"    @(R15+0x{off:02X}) = 0x{val:08X}")

                if len(stack_data) >= 8:
                    pushed_sr = struct.unpack('>I', stack_data[0:4])[0]
                    pushed_pc = struct.unpack('>I', stack_data[4:8])[0]
                    print(f"\n  ==> Pushed SR  = 0x{pushed_sr:08X}")
                    print(f"  ==> Pushed PC  = 0x{pushed_pc:08X} (fault return address)")
                    print(f"  ==> Fault likely near 0x{pushed_pc:08X} or 0x{pushed_pc - 2:08X}")

    # If we hit the exception handler, let's also check: which CPU are we on?
    # Continue to let it reach the SETT/BT$ trap to confirm
    if hit_pc in (ADDR_ERR_HANDLER, ILLEGAL_INSN_HANDLER, SLOT_ILLEGAL_HANDLER,
                  MASTER_ICF_ENTRY, SLAVE_CALLBACK_ENTRY):
        # Let's also continue to see what happens next
        print("\n  Continuing to see next breakpoint...")
        try:
            ack = inst.send_long("continue", timeout=30)
            print(f"  Next breakpoint: {ack}")
        except TimeoutError:
            print("  (timeout — no more breakpoints)")

    # Clean shutdown
    print("\nShutting down...")
    try:
        inst.send("quit")
    except:
        pass
    time.sleep(1)

    print("\nDone.")


if __name__ == "__main__":
    main()
