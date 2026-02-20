#!/usr/bin/env python3
"""icf_diagnose.py — Find the exact instruction causing the slave SH-2 address error.

Boots the free-layout disc (SCDQ_FIX=1, CD_FIX=1, NO ICF_FIX) in automation mode,
advances past boot, then uses `dump_slave_regs` to check if the slave has hit the
CPU Address Error panic trap. If so, reads the auto-pushed PC from the slave's stack
to identify the exact faulting instruction.

The SH-2 CPU Address Error exception auto-pushes SR and PC onto the stack:
  @(0, R15) = pushed SR
  @(4, R15) = pushed PC  (address of instruction after the fault)

The exception handler (sym_06028248) pushes/pops R0-R7 and PR, then falls to a
SETT/BT$ infinite loop. At that point R15 is restored to point at the auto-pushed
SR/PC, so we can read them directly.
"""

import os
import sys
import time
import struct
import re

# Add project root to path for imports
PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJ, "tools"))

from parallel_compare import MednafenInstance, win_to_wsl, TMPDIR

CUE_FREE = os.path.join(PROJ, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")

# In the free build (+4 shift):
# sym_06028248 (CPU Address Error handler) -> 0x0602824C
# SETT at 0x06028298, BT$ at 0x0602829A, RTE at 0x0602829C, NOP at 0x0602829E
# Mednafen reports PC as 0x0602829E when stuck in the BT$ loop (pipeline artifact)
PANIC_TRAP_FREE = 0x0602829E
PANIC_TRAP_ALT = 0x0602829A  # Alternative: the BT instruction itself

# Slave main loop (FUN_06034F08 + 4 = 0x06034F0C in free build)
SLAVE_MAIN_LOOP = 0x06034F0C


def parse_slave_regs(ack_str):
    """Parse 'regs_slave R0=... R1=... ... PC=... SR=...' into a dict."""
    regs = {}
    for m in re.finditer(r'(\w+)=([0-9A-Fa-f]+)', ack_str):
        regs[m.group(1)] = int(m.group(2), 16)
    return regs


def dump_slave_regs_bin(inst, win_path):
    """Dump slave registers to binary file using the new automation command."""
    wsl_path = win_to_wsl(win_path)
    return inst.send(f"dump_slave_regs_bin {wsl_path}")


def main():
    os.makedirs(TMPDIR, exist_ok=True)

    # Kill stale instances
    MednafenInstance.kill_stale()

    ipc_dir = os.path.join(TMPDIR, "icf_diag")
    inst = MednafenInstance("free", CUE_FREE, ipc_dir)

    print("Starting Mednafen with free-layout disc (no ICF bypass)...")
    inst.start()
    print("Ready.")

    # Phase 1: Advance past BIOS
    print("\nPhase 1: Advancing 60 frames (past BIOS)...")
    ack = inst.frame_advance(60)
    print(f"  Done: {ack}")

    # Check slave state early
    print("\n  Early slave check (frame 60):")
    ack = inst.send("dump_slave_regs")
    print(f"  {ack}")
    regs = parse_slave_regs(ack)
    slave_pc = regs.get("PC", 0)
    print(f"  Slave PC = 0x{slave_pc:08X}")

    # Phase 2: Advance in chunks, checking slave state periodically
    # The ICF crash happens around frame 1253 based on previous testing
    check_points = [200, 500, 800, 1000, 1200, 1300, 1400, 1500]

    found_crash = False
    current_frame = 60
    for target in check_points:
        delta = target - current_frame
        if delta <= 0:
            continue

        print(f"\nPhase 2: Advancing to frame {target} (+{delta})...")
        try:
            ack = inst.frame_advance(delta)
            print(f"  Done: {ack}")
        except TimeoutError:
            print(f"  TIMEOUT at frame advance to {target}")
            # Try to pause and check anyway
            try:
                inst._write_action("pause")
                time.sleep(1)
            except:
                pass

        current_frame = target

        # Check slave state
        print(f"\n  Checking slave state at frame ~{target}:")
        try:
            ack = inst.send("dump_slave_regs")
        except TimeoutError:
            print("  TIMEOUT reading slave regs (trying pause first)...")
            try:
                inst._write_action("pause")
                time.sleep(1)
                ack = inst.send("dump_slave_regs")
            except Exception as e:
                print(f"  Failed: {e}")
                continue

        print(f"  {ack}")
        regs = parse_slave_regs(ack)
        slave_pc = regs.get("PC", 0)
        slave_r15 = regs.get("R15", 0)
        print(f"  Slave PC  = 0x{slave_pc:08X}")
        print(f"  Slave R15 = 0x{slave_r15:08X}")

        if slave_pc in (PANIC_TRAP_FREE, PANIC_TRAP_ALT,
                        PANIC_TRAP_FREE - 2, PANIC_TRAP_ALT - 2):
            print(f"\n  >>> SLAVE IS AT PANIC TRAP (0x{slave_pc:08X})! <<<")
            found_crash = True
            break
        else:
            print(f"  (not at panic trap, continuing...)")

    if not found_crash:
        # Try a few more frames
        print("\n  Slave not at panic trap after frame 1500. Trying more frames...")
        for extra in [1600, 1800, 2000]:
            delta = extra - current_frame
            if delta <= 0:
                continue
            try:
                ack = inst.frame_advance(delta)
                current_frame = extra
                ack = inst.send("dump_slave_regs")
                regs = parse_slave_regs(ack)
                slave_pc = regs.get("PC", 0)
                print(f"  Frame ~{extra}: Slave PC = 0x{slave_pc:08X}")
                if slave_pc in (PANIC_TRAP_FREE, PANIC_TRAP_ALT,
                               PANIC_TRAP_FREE - 2, PANIC_TRAP_ALT - 2):
                    found_crash = True
                    slave_r15 = regs.get("R15", 0)
                    break
            except TimeoutError:
                print(f"  TIMEOUT at frame {extra}")
                continue

    if not found_crash:
        print("\n  ERROR: Slave never reached panic trap!")
        print("  Dumping final slave state:")
        try:
            ack = inst.send("dump_slave_regs")
            print(f"  {ack}")
        except:
            pass
        try:
            inst.send("quit")
        except:
            pass
        return

    # Phase 3: Dump all slave registers in detail
    print("\n" + "=" * 60)
    print("Phase 3: Slave crash analysis")
    print("=" * 60)

    # Get text registers
    ack = inst.send("dump_slave_regs")
    print(f"\n  Slave registers: {ack}")
    regs = parse_slave_regs(ack)

    # Also dump binary for precise parsing
    regs_file = os.path.join(TMPDIR, "icf_diag_slave_regs.bin")
    ack = dump_slave_regs_bin(inst, regs_file)
    print(f"  Binary dump: {ack}")

    if os.path.exists(regs_file):
        with open(regs_file, "rb") as f:
            reg_data = f.read()
        if len(reg_data) >= 88:  # 22 * 4 bytes
            bin_regs = struct.unpack('<22I', reg_data)
            reg_names = [f"R{i}" for i in range(16)] + ["PC", "SR", "PR", "GBR", "VBR", "MACH"]
            print("\n  Parsed slave registers (binary):")
            for i, name in enumerate(reg_names):
                print(f"    {name:4s} = 0x{bin_regs[i]:08X}")

            slave_r15 = bin_regs[15]
            slave_pc = bin_regs[16]
            slave_pr = bin_regs[18]
            slave_vbr = bin_regs[20]

    # Phase 4: Read the auto-pushed SR and PC from slave's stack
    # At the SETT/BT$ trap, handler has popped all its own saves.
    # R15 points at the CPU's auto-pushed values:
    #   @(R15+0) = pushed SR  (4 bytes)
    #   @(R15+4) = pushed PC  (4 bytes, fault return address)
    print(f"\n  Slave R15 = 0x{slave_r15:08X}")
    print(f"  Reading auto-pushed SR/PC from slave stack...")

    stack_file = os.path.join(TMPDIR, "icf_diag_slave_stack.bin")
    stack_wsl = win_to_wsl(stack_file)
    # Read 128 bytes from slave stack for context
    ack = inst.send(f"dump_mem_bin {slave_r15:X} 80 {stack_wsl}")
    print(f"  Stack dump ack: {ack}")

    if os.path.exists(stack_file):
        with open(stack_file, "rb") as f:
            stack_data = f.read()
        print(f"  Stack bytes ({len(stack_data)}):")
        # SH-2 is big-endian
        for off in range(0, min(len(stack_data), 128), 4):
            val = struct.unpack('>I', stack_data[off:off+4])[0]
            label = ""
            if off == 0:
                label = "  <-- auto-pushed PC (FAULT RETURN ADDRESS)"
            elif off == 4:
                label = "  <-- auto-pushed SR"
            elif off == 8:
                label = "  <-- (caller's stack frame)"
            print(f"    @(R15+0x{off:02X}) = 0x{val:08X}{label}")

        if len(stack_data) >= 8:
            # SH-2 exception push order: SR first (higher addr), then PC (lower addr)
            # So @R15+0 = pushed PC, @R15+4 = pushed SR
            pushed_pc = struct.unpack('>I', stack_data[0:4])[0]
            pushed_sr = struct.unpack('>I', stack_data[4:8])[0]
            print(f"\n  {'=' * 50}")
            print(f"  RESULTS:")
            print(f"  {'=' * 50}")
            print(f"  Auto-pushed PC  = 0x{pushed_pc:08X} (fault return address)")
            print(f"  Auto-pushed SR  = 0x{pushed_sr:08X}")
            print(f"")
            print(f"  The CPU Address Error occurred at or near:")
            print(f"    0x{pushed_pc:08X} (pushed PC, next instruction)")
            print(f"    0x{pushed_pc - 2:08X} (faulting instruction, if 16-bit)")
            print(f"    0x{pushed_pc - 4:08X} (faulting instruction, if in delay slot)")
            print(f"")

            # If the fault address is in game code region, convert to retail
            if 0x06003100 <= pushed_pc <= 0x060FFFFF:
                retail_pc = pushed_pc - 4
                retail_fault = pushed_pc - 2 - 4
                retail_delay = pushed_pc - 4 - 4
                print(f"  Retail equivalents (-4 for free build shift):")
                print(f"    Pushed PC:       0x{retail_pc:08X}")
                print(f"    Fault (16-bit):  0x{retail_fault:08X}")
                print(f"    Fault (delay):   0x{retail_delay:08X}")
            else:
                print(f"  NOTE: Fault address 0x{pushed_pc:08X} is OUTSIDE game code")
                print(f"  (game code range: 0x06003100 - 0x060636xx)")
                print(f"  This is in the vector table / init area!")
            print(f"")
            print(f"  Slave PR (return address) = 0x{slave_pr:08X}")

    # Phase 5: Dump code at/near the fault address
    print(f"\n  Phase 5: Dumping code near fault address...")

    # Dump 64 bytes around the fault address
    if 'pushed_pc' in dir() and pushed_pc != 0:
        fault_base = (pushed_pc - 16) & ~1  # align to 2-byte boundary, 16 bytes before
        code_file = os.path.join(TMPDIR, "icf_diag_fault_code.bin")
        code_wsl = win_to_wsl(code_file)
        ack = inst.send(f"dump_mem_bin {fault_base:X} 40 {code_wsl}")
        print(f"  Code dump at 0x{fault_base:08X}: {ack}")

        if os.path.exists(code_file):
            with open(code_file, "rb") as f:
                code_data = f.read()
            print(f"  Disassembly near fault (raw bytes, {len(code_data)} bytes):")
            for off in range(0, min(len(code_data), 64), 2):
                addr = fault_base + off
                if off + 1 < len(code_data):
                    hi = code_data[off]
                    lo = code_data[off + 1]
                    opcode = (hi << 8) | lo
                    marker = ""
                    if addr == pushed_pc:
                        marker = "  <== PUSHED PC (return addr)"
                    elif addr == pushed_pc - 2:
                        marker = "  <== LIKELY FAULT INSTRUCTION"
                    elif addr == pushed_pc - 4:
                        marker = "  <== (if delay slot fault)"
                    print(f"    0x{addr:08X}: {hi:02X}{lo:02X} (0x{opcode:04X}){marker}")

    # Dump the vector table entry for CPU Address Error
    print(f"\n  Dumping Address Error vector entry...")
    vbr = regs.get("VBR", 0x06000400)
    addr_err_vec = vbr + 0x24  # CPU Address Error vector offset
    vec_file = os.path.join(TMPDIR, "icf_diag_vector.bin")
    vec_wsl = win_to_wsl(vec_file)
    ack = inst.send(f"dump_mem_bin {addr_err_vec:X} 4 {vec_wsl}")
    print(f"  Vector at VBR+0x24 (0x{addr_err_vec:08X}): {ack}")

    if os.path.exists(vec_file):
        with open(vec_file, "rb") as f:
            vec_data = f.read()
        if len(vec_data) >= 4:
            handler_addr = struct.unpack('>I', vec_data[0:4])[0]
            print(f"  Address Error handler = 0x{handler_addr:08X}")
            expected = 0x0602824C  # sym_06028248 + 4
            if handler_addr == expected:
                print(f"  (CORRECT: matches sym_06028248+4 = 0x{expected:08X})")
            else:
                print(f"  (MISMATCH: expected 0x{expected:08X})")

    # Dump the callback pointer storage
    print(f"\n  Dumping callback pointer storage (sym_06063574)...")
    cb_file = os.path.join(TMPDIR, "icf_diag_callback.bin")
    cb_wsl = win_to_wsl(cb_file)
    # Use cache-through address for callback pointer
    ack = inst.send(f"dump_mem_bin 6063578 4 {cb_wsl}")
    print(f"  Callback pointer (sym_06063574+4): {ack}")
    if os.path.exists(cb_file):
        with open(cb_file, "rb") as f:
            cb_data = f.read()
        if len(cb_data) >= 4:
            cb_val = struct.unpack('>I', cb_data[0:4])[0]
            print(f"  Callback pointer value = 0x{cb_val:08X}")

    # Also dump the slave's init area (0x06000200-0x06000260) for context
    print(f"\n  Dumping slave init area (0x06000200-0x06000260)...")
    init_file = os.path.join(TMPDIR, "icf_diag_init_area.bin")
    init_wsl = win_to_wsl(init_file)
    ack = inst.send(f"dump_mem_bin 6000200 60 {init_wsl}")
    print(f"  Init area dump: {ack}")
    if os.path.exists(init_file):
        with open(init_file, "rb") as f:
            init_data = f.read()
        print(f"  Init area ({len(init_data)} bytes):")
        for off in range(0, min(len(init_data), 96), 4):
            addr = 0x06000200 + off
            if off + 3 < len(init_data):
                val = struct.unpack('>I', init_data[off:off+4])[0]
                # Also show as two 16-bit instructions
                hi_w = struct.unpack('>H', init_data[off:off+2])[0]
                lo_w = struct.unpack('>H', init_data[off+2:off+4])[0]
                print(f"    0x{addr:08X}: {val:08X}  ({hi_w:04X} {lo_w:04X})")

    # Also dump master registers for context
    print(f"\n  Master registers for context:")
    ack = inst.send("dump_regs")
    print(f"  {ack}")

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
