#!/usr/bin/env python3
"""diag_vectors.py - Compare interrupt vector tables and handler addresses.

Reads the interrupt vector table at VBR+0x100 in both builds to check
if handler addresses are correct. Also tests if interrupts actually fire
by checking VBlank handler execution.

SCU Interrupt Vectors (at VBR + offset):
  0x100: VBlank-IN  (vec 0x40)
  0x104: VBlank-OUT (vec 0x41)
  0x108: HBlank-IN  (vec 0x42)
  0x10C: Timer 0    (vec 0x43)
  0x110: Timer 1    (vec 0x44)
  0x114: DSP End    (vec 0x45)
  0x118: Sound Req  (vec 0x46)
  0x11C: SMPC       (vec 0x47)
  0x120: PAD        (vec 0x48)
  0x124: DMA L2     (vec 0x49)
  0x128: DMA L1     (vec 0x4A)
  0x12C: DMA L0     (vec 0x4B)
  0x130: DMA Ill    (vec 0x4C)
  0x134: Sprite End (vec 0x4D)
"""

import os, sys, time, struct, re

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin

CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")
CUE_FREE = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
TMPDIR = os.path.join(PROJDIR, ".tmp")

SHIFT = 4

VECTOR_NAMES = {
    0x100: "VBlank-IN",
    0x104: "VBlank-OUT",
    0x108: "HBlank-IN",
    0x10C: "Timer 0",
    0x110: "Timer 1",
    0x114: "DSP End",
    0x118: "Sound Req",
    0x11C: "SMPC",
    0x120: "PAD",
    0x124: "DMA L2",
    0x128: "DMA L1",
    0x12C: "DMA L0",
    0x130: "DMA Illegal",
    0x134: "Sprite End",
}


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


def test_build(name, cue, ipc_name, poll_addr, sys_init_addr):
    """Read vector table at poll entry."""
    MednafenInstance.kill_stale()

    ipc = os.path.join(TMPDIR, ipc_name)
    inst = MednafenInstance(name, cue, ipc)
    inst.start()

    print(f"\n{'='*60}")
    print(f"  {name}")
    print(f"{'='*60}")

    # Run to system_init
    inst.breakpoint(sys_init_addr)
    try:
        ack = inst.continue_exec()
        frame = parse_frame(ack)
        print(f"  system_init entered at frame {frame}")
    except TimeoutError:
        print(f"  TIMEOUT!")
        inst.quit(); MednafenInstance.kill_stale(); return None
    inst.breakpoint_clear()

    # Run to poll entry
    inst.breakpoint(poll_addr)
    try:
        ack = inst.continue_exec()
        frame = parse_frame(ack)
        print(f"  FUN_060423CC entered at frame {frame}")
    except TimeoutError:
        print(f"  TIMEOUT!")
        inst.quit(); MednafenInstance.kill_stale(); return None
    inst.breakpoint_clear()

    # Read VBR
    regs = dump_regs(inst, ipc, "entry")
    vbr = regs.get('VBR', 0x06000000) if regs else 0x06000000
    print(f"  VBR = 0x{vbr:08X}")

    # Read interrupt vector table
    vec_base = vbr + 0x100
    vec_data = dump_mem(inst, ipc, vec_base, 0x40, "vectors")
    vectors = {}
    if vec_data and len(vec_data) >= 0x38:
        print(f"\n  Interrupt Vector Table (VBR+0x100 = 0x{vec_base:08X}):")
        for off in range(0, 0x38, 4):
            val = struct.unpack('>I', vec_data[off:off+4])[0]
            vec_name = VECTOR_NAMES.get(0x100 + off, f"vec_{0x100+off:03X}")
            in_code = "code" if 0x06003000 <= val < 0x06070000 else "other"
            print(f"    +0x{0x100+off:03X} ({vec_name:14s}): 0x{val:08X}  [{in_code}]")
            vectors[0x100 + off] = val

    # Also read general exception vectors (0x00-0xFF)
    gen_data = dump_mem(inst, ipc, vbr, 0x100, "gen_vectors")
    if gen_data and len(gen_data) >= 0x100:
        print(f"\n  General Exception Vectors (first 16):")
        for off in range(0, 0x40, 4):
            val = struct.unpack('>I', gen_data[off:off+4])[0]
            if val != 0:
                print(f"    +0x{off:03X}: 0x{val:08X}")

    # Test: is VBlank handler running?
    # Set breakpoint at VBlank handler
    vblank_handler = vectors.get(0x100, 0)
    if vblank_handler and 0x06003000 <= vblank_handler < 0x06070000:
        print(f"\n  Testing VBlank handler at 0x{vblank_handler:08X}...")
        inst.breakpoint(vblank_handler)
        try:
            ack = inst.continue_exec()
            pc = parse_pc(ack)
            frame = parse_frame(ack)
            print(f"  VBlank handler HIT at frame {frame}")
            # Dump registers to check state
            vregs = dump_regs(inst, ipc, "vblank")
            if vregs:
                print(f"    PC=0x{vregs['PC']:08X} PR=0x{vregs['PR']:08X}")
                print(f"    SR=0x{vregs['SR']:08X}")
        except TimeoutError:
            print(f"  VBlank handler NEVER called (30s timeout)!")
        inst.breakpoint_clear()
    else:
        print(f"\n  VBlank handler not in code range: 0x{vblank_handler:08X}")

    inst.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()
    return vectors


def main():
    print("=" * 70)
    print("  Interrupt Vector Table Comparison")
    print("=" * 70)

    print("\n>>> PRODUCTION <<<")
    prod_vecs = test_build("PROD", CUE_PROD, "vec_prod",
                           poll_addr=0x060423CC,
                           sys_init_addr=0x060030FC)

    time.sleep(2)

    print("\n>>> FREE-LAYOUT <<<")
    free_vecs = test_build("FREE", CUE_FREE, "vec_free",
                           poll_addr=0x060423D0,
                           sys_init_addr=0x06003100)

    # Compare
    if prod_vecs and free_vecs:
        print(f"\n{'='*70}")
        print(f"  VECTOR TABLE COMPARISON")
        print(f"{'='*70}")
        for off in sorted(set(list(prod_vecs.keys()) + list(free_vecs.keys()))):
            pv = prod_vecs.get(off, 0)
            fv = free_vecs.get(off, 0)
            vec_name = VECTOR_NAMES.get(off, f"vec_{off:03X}")
            if pv == 0 and fv == 0:
                continue

            # Check if the difference is exactly SHIFT
            if fv == pv + SHIFT:
                status = f"SHIFTED +{SHIFT} (correct)"
            elif fv == pv:
                status = "IDENTICAL"
            elif pv == 0 or fv == 0:
                status = "*** ONE IS ZERO ***"
            else:
                diff = fv - pv
                status = f"*** DIFF = {diff:+d} (expected +{SHIFT}) ***"
            print(f"  +0x{off:03X} ({vec_name:14s}): prod=0x{pv:08X} free=0x{fv:08X} {status}")


if __name__ == "__main__":
    main()
