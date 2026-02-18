#!/usr/bin/env python3
"""diag_cdb_state.py - Compare CDB register state at SCDQ poll entry.

Dumps CDB registers in both builds at the moment FUN_060423CC is entered.
Also checks if the issue is the DISC IMAGE by running both builds against
their respective discs with more CDB diagnostic detail.

CDB Registers (from Saturn tech manual):
  0x25890000 - HIRQ (Interrupt Request)
  0x25890004 - HMASK (Interrupt Mask)
  0x25890008 - CR1 (Command Response 1)
  0x2589000C - CR2 (Command Response 2)
  0x25890010 - CR3 (Command Response 3)
  0x25890014 - CR4 (Command Response 4)
  0x25890018 - MPEGRGB

Wait, these offsets need to be checked against Mednafen's CDB layout.
Actually the CDB register layout in Saturn is:
  Base = 0x25890000 (cache-through)
  HIRQ  = base + 0x08  (16-bit)
  HMASK = base + 0x0C  (16-bit) [Interrupt mask]
  CR1   = base + 0x18  (16-bit) [Command/status]
  CR2   = base + 0x1C  (16-bit)
  CR3   = base + 0x20  (16-bit)
  CR4   = base + 0x24  (16-bit)
"""

import os, sys, time, struct, re

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


HIRQ_BITS = {
    0: "CMOK", 1: "DRDY", 2: "CSCT", 3: "BFUL",
    4: "PEND", 5: "DCHG", 6: "ESEL", 7: "EHST",
    8: "ECPY", 9: "EFLS", 10: "SCDQ", 11: "MPED",
    12: "MPCM", 13: "MPST",
}

def hirq_str(val):
    bits = [name for bit, name in sorted(HIRQ_BITS.items()) if val & (1 << bit)]
    return f"0x{val:04X} [{', '.join(bits)}]"


def test_build(name, cue, ipc_name, poll_addr, sys_init_addr):
    """Boot, breakpoint at FUN_060423CC, dump CDB state."""
    MednafenInstance.kill_stale()

    ipc = os.path.join(TMPDIR, ipc_name)
    inst = MednafenInstance(name, cue, ipc)
    inst.start()

    print(f"\n{'='*60}")
    print(f"  {name}  poll=0x{poll_addr:08X}")
    print(f"{'='*60}")

    # Run to _start
    inst.breakpoint(0x06003000)
    try:
        ack = inst.continue_exec()
        frame = parse_frame(ack)
        print(f"  _start at frame {frame}")
    except TimeoutError:
        print(f"  TIMEOUT at _start!")
        inst.quit(); MednafenInstance.kill_stale(); return None
    inst.breakpoint_clear()

    # Run to system_init
    inst.breakpoint(sys_init_addr)
    try:
        ack = inst.continue_exec()
        frame = parse_frame(ack)
        print(f"  system_init entered at frame {frame}")
    except TimeoutError:
        print(f"  TIMEOUT at system_init!")
        inst.quit(); MednafenInstance.kill_stale(); return None
    inst.breakpoint_clear()

    # Run to FUN_060423CC entry
    inst.breakpoint(poll_addr)
    try:
        ack = inst.continue_exec()
        pc = parse_pc(ack)
        frame = parse_frame(ack)
        print(f"  FUN_060423CC entered at frame {frame}")
    except TimeoutError:
        print(f"  TIMEOUT waiting for FUN_060423CC!")
        inst.quit(); MednafenInstance.kill_stale(); return None
    inst.breakpoint_clear()

    # Dump CPU registers
    regs = dump_regs(inst, ipc, "poll_entry")
    if regs:
        print(f"\n  CPU State:")
        print(f"    PR=0x{regs['PR']:08X}  SR=0x{regs['SR']:08X}")
        print(f"    R0=0x{regs['R0']:08X}  R4=0x{regs['R4']:08X}")
        print(f"    R15=0x{regs['R15']:08X}")
        sr = regs['SR']
        imask = (sr >> 4) & 0xF
        print(f"    Interrupt mask: {imask} (0=all enabled, 15=all masked)")

    # Dump CDB registers
    # Read a block from 0x25890000 to 0x25890030
    cdb = dump_mem(inst, ipc, 0x25890000, 0x30, "cdb_regs")
    cdb_state = {}
    if cdb and len(cdb) >= 0x28:
        hirq = struct.unpack('>H', cdb[0x08:0x0A])[0]
        hmask = struct.unpack('>H', cdb[0x0C:0x0E])[0]
        cr1 = struct.unpack('>H', cdb[0x18:0x1A])[0]
        cr2 = struct.unpack('>H', cdb[0x1C:0x1E])[0]
        cr3 = struct.unpack('>H', cdb[0x20:0x22])[0]
        cr4 = struct.unpack('>H', cdb[0x24:0x26])[0]

        print(f"\n  CDB Registers at poll entry:")
        print(f"    HIRQ  = {hirq_str(hirq)}")
        print(f"    HMASK = 0x{hmask:04X}")
        print(f"    CR1   = 0x{cr1:04X}  (status/command)")
        print(f"    CR2   = 0x{cr2:04X}")
        print(f"    CR3   = 0x{cr3:04X}")
        print(f"    CR4   = 0x{cr4:04X}")

        cdb_state = {
            'hirq': hirq, 'hmask': hmask,
            'cr1': cr1, 'cr2': cr2, 'cr3': cr3, 'cr4': cr4
        }

        # Raw hex dump for comparison
        print(f"\n  CDB raw dump:")
        for off in range(0, min(len(cdb), 0x28), 2):
            val = struct.unpack('>H', cdb[off:off+2])[0]
            print(f"    0x{0x25890000+off:08X} (+0x{off:02X}): 0x{val:04X}")
    else:
        print(f"  CDB dump failed!")

    # Also dump SCU interrupt state
    scu_ims = dump_mem(inst, ipc, 0x25FE00A0, 4, "scu_ims")
    scu_ist = dump_mem(inst, ipc, 0x25FE00A4, 4, "scu_ist")
    if scu_ims and len(scu_ims) >= 4:
        ims_val = struct.unpack('>I', scu_ims[:4])[0]
        print(f"\n  SCU IMS (interrupt mask) = 0x{ims_val:08X}")
    if scu_ist and len(scu_ist) >= 4:
        ist_val = struct.unpack('>I', scu_ist[:4])[0]
        print(f"  SCU IST (interrupt status) = 0x{ist_val:08X}")

    # Check VBR
    if regs:
        vbr = regs.get('VBR', 0)
        print(f"  VBR = 0x{vbr:08X}")

    # Now let's advance 200 frames and check HIRQ periodically
    print(f"\n  Advancing frames, monitoring HIRQ...")
    for i in range(20):
        inst.frame_advance(10)
        hirq_data = dump_mem(inst, ipc, 0x25890008, 2, f"hirq_{i}")
        if hirq_data and len(hirq_data) >= 2:
            hirq_val = struct.unpack('>H', hirq_data[:2])[0]
            scdq = "SET" if (hirq_val & 0x0400) else "clear"
            if i < 5 or (hirq_val & 0x0400) or i % 5 == 0:
                print(f"    +{(i+1)*10:3d} frames: HIRQ={hirq_str(hirq_val)} SCDQ={scdq}")
            if hirq_val & 0x0400:
                print(f"    *** SCDQ FIRED after {(i+1)*10} frames! ***")
                break
    else:
        print(f"    SCDQ never fired in 200 frames")

        # Check where we are
        regs2 = dump_regs(inst, ipc, "final")
        if regs2:
            print(f"    Final PC=0x{regs2['PC']:08X} SR=0x{regs2['SR']:08X}")
            sr2 = regs2['SR']
            imask2 = (sr2 >> 4) & 0xF
            print(f"    Final interrupt mask: {imask2}")

    inst.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()
    return cdb_state


def main():
    print("=" * 70)
    print("  CDB State Comparison at SCDQ Poll Entry")
    print("=" * 70)

    print("\n>>> PRODUCTION (original disc) <<<")
    prod_cdb = test_build("PROD", CUE_PROD, "cdb_prod",
                          poll_addr=0x060423CC,
                          sys_init_addr=0x060030FC)

    time.sleep(2)

    print("\n>>> FREE-LAYOUT (rebuilt disc) <<<")
    free_cdb = test_build("FREE", CUE_FREE, "cdb_free",
                          poll_addr=0x060423D0,
                          sys_init_addr=0x06003100)

    # Compare
    if prod_cdb and free_cdb:
        print(f"\n{'='*70}")
        print(f"  CDB STATE COMPARISON")
        print(f"{'='*70}")
        for key in prod_cdb:
            pv = prod_cdb[key]
            fv = free_cdb[key]
            match = "SAME" if pv == fv else "*** DIFF ***"
            print(f"  {key:8s}: prod=0x{pv:04X}  free=0x{fv:04X}  {match}")


if __name__ == "__main__":
    main()
