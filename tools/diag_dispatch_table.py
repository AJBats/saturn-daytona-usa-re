#!/usr/bin/env python3
"""diag_dispatch_table.py - Compare interrupt dispatch table between builds.

The interrupt trampolines use a common handler that reads from a dispatch
table. The dispatch table is pointed to by [0x06000348]. This table contains
function pointers to the actual interrupt handlers.

If the free build's dispatch table doesn't have shifted handler addresses,
interrupts will call wrong functions, potentially causing CDB events to fail.
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
    0x40: "VBlank-IN",
    0x41: "VBlank-OUT",
    0x42: "HBlank-IN",
    0x43: "Timer 0",
    0x44: "Timer 1",
    0x45: "DSP End",
    0x46: "Sound Req",
    0x47: "SMPC",
    0x48: "PAD",
    0x49: "DMA L2",
    0x4A: "DMA L1",
    0x4B: "DMA L0",
    0x4C: "DMA Illegal",
    0x4D: "Sprite End",
}


def parse_pc(ack):
    m = re.search(r'pc=0x([0-9a-fA-F]+)', ack)
    return int(m.group(1), 16) if m else None

def parse_frame(ack):
    m = re.search(r'frame=(\d+)', ack)
    return int(m.group(1)) if m else None

def dump_mem(inst, ipc_dir, addr, size, tag=""):
    path = os.path.join(ipc_dir, f"mem_{tag}.bin")
    inst.dump_mem_bin(addr, size, path)
    time.sleep(0.3)
    try:
        with open(path, 'rb') as f:
            return f.read()
    except FileNotFoundError:
        return None

def dump_regs(inst, ipc_dir, tag=""):
    path = os.path.join(ipc_dir, f"regs_{tag}.bin")
    inst.dump_regs_bin(path)
    time.sleep(0.3)
    return read_regs_bin(path)


def test_build(name, cue, ipc_name, poll_addr, sys_init_addr):
    """Read the interrupt dispatch table."""
    MednafenInstance.kill_stale()

    ipc = os.path.join(TMPDIR, ipc_name)
    inst = MednafenInstance(name, cue, ipc)
    inst.start()

    print(f"\n{'='*60}")
    print(f"  {name}")
    print(f"{'='*60}")

    # Run to poll entry
    inst.breakpoint(sys_init_addr)
    try:
        inst.continue_exec()
    except TimeoutError:
        print(f"  TIMEOUT at system_init!")
        inst.quit(); MednafenInstance.kill_stale(); return None
    inst.breakpoint_clear()

    inst.breakpoint(poll_addr)
    try:
        ack = inst.continue_exec()
        print(f"  FUN_060423CC entered at frame {parse_frame(ack)}")
    except TimeoutError:
        print(f"  TIMEOUT at poll!")
        inst.quit(); MednafenInstance.kill_stale(); return None
    inst.breakpoint_clear()

    # Read the dispatch table pointer at 0x06000348
    ptr_data = dump_mem(inst, ipc, 0x06000348, 4, "dispatch_ptr")
    if not ptr_data or len(ptr_data) < 4:
        print(f"  Failed to read dispatch pointer!")
        inst.quit(); MednafenInstance.kill_stale(); return None

    dispatch_ptr = struct.unpack('>I', ptr_data[:4])[0]
    print(f"  Dispatch table pointer: [0x06000348] = 0x{dispatch_ptr:08X}")

    # Read the common handler code at 0x060008F4 to understand the table indexing
    handler_code = dump_mem(inst, ipc, 0x060008F4, 0x40, "handler_code")
    if handler_code and len(handler_code) >= 0x40:
        print(f"\n  Common interrupt handler at 0x060008F4:")
        for off in range(0, min(len(handler_code), 0x30), 2):
            w = struct.unpack('>H', handler_code[off:off+2])[0]
            addr = 0x060008F4 + off
            print(f"    0x{addr:08X}: {w:04X}")

    # Also read a wider area around the dispatch pointer
    # The dispatch table likely has entries for vectors 0x40-0x4F (16 entries)
    # But we need to understand the table format first
    # Let's read a larger area at 0x06000340-0x060003A0
    table_area = dump_mem(inst, ipc, 0x06000340, 0x60, "dispatch_area")
    if table_area and len(table_area) >= 0x60:
        print(f"\n  Memory around dispatch table (0x06000340-0x060003A0):")
        for off in range(0, min(len(table_area), 0x60), 4):
            val = struct.unpack('>I', table_area[off:off+4])[0]
            addr = 0x06000340 + off
            in_code = " [code]" if 0x06003000 <= val < 0x06070000 else ""
            print(f"    0x{addr:08X}: 0x{val:08X}{in_code}")

    # Now let's read what the dispatch_ptr actually points to
    # The table might be indexed by vector number (R0)
    # Each vector number is in range 0x40-0x5F
    # Table entry = dispatch_ptr + (vector_number - base) * entry_size
    # OR it could be: table[R0] where R0 is the index

    # Read 64 entries starting from the dispatch pointer
    if 0x06000000 <= dispatch_ptr < 0x06100000:
        table_data = dump_mem(inst, ipc, dispatch_ptr, 0x100, "dispatch_table")
        if table_data and len(table_data) >= 0x100:
            print(f"\n  Dispatch table at 0x{dispatch_ptr:08X}:")
            entries = {}
            for off in range(0, min(len(table_data), 0x100), 4):
                val = struct.unpack('>I', table_data[off:off+4])[0]
                idx = off // 4
                in_code = " [code]" if 0x06003000 <= val < 0x06070000 else ""
                if idx >= 0x40 and idx <= 0x50:
                    vec_name = VECTOR_NAMES.get(idx, f"vec_{idx:02X}")
                    print(f"    [{idx:02X}] +0x{off:03X}: 0x{val:08X}  {vec_name}{in_code}")
                    entries[idx] = val
                elif val != 0 and in_code:
                    print(f"    [{idx:02X}] +0x{off:03X}: 0x{val:08X}{in_code}")
                    entries[idx] = val

            inst.quit()
            time.sleep(1)
            MednafenInstance.kill_stale()
            return entries

    inst.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()
    return {}


def main():
    print("=" * 70)
    print("  Interrupt Dispatch Table Comparison")
    print("=" * 70)

    print("\n>>> PRODUCTION <<<")
    prod = test_build("PROD", CUE_PROD, "disp_prod",
                      poll_addr=0x060423CC,
                      sys_init_addr=0x060030FC)

    time.sleep(2)

    print("\n>>> FREE-LAYOUT <<<")
    free = test_build("FREE", CUE_FREE, "disp_free",
                      poll_addr=0x060423D0,
                      sys_init_addr=0x06003100)

    # Compare dispatch table entries
    if prod and free:
        print(f"\n{'='*70}")
        print(f"  DISPATCH TABLE COMPARISON")
        print(f"{'='*70}")
        all_keys = sorted(set(list(prod.keys()) + list(free.keys())))
        wrong_count = 0
        for idx in all_keys:
            pv = prod.get(idx, 0)
            fv = free.get(idx, 0)
            vec_name = VECTOR_NAMES.get(idx, f"idx_{idx:02X}")

            if pv == 0 and fv == 0:
                continue

            if fv == pv + SHIFT:
                status = f"SHIFTED +{SHIFT} (correct)"
            elif fv == pv:
                status = "IDENTICAL (no shift needed if < 0x06003000)"
                if pv >= 0x06003000:
                    status = "*** NOT SHIFTED! Should be +4 ***"
                    wrong_count += 1
            else:
                diff = fv - pv
                status = f"*** DIFF = {diff:+d} ***"
                wrong_count += 1

            print(f"  [{idx:02X}] ({vec_name:14s}): prod=0x{pv:08X} free=0x{fv:08X} {status}")

        if wrong_count > 0:
            print(f"\n  *** {wrong_count} INCORRECTLY SHIFTED entries found! ***")
            print(f"  This could cause interrupts to call wrong handlers!")
        else:
            print(f"\n  All entries correctly shifted or identical.")


if __name__ == "__main__":
    main()
