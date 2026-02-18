#!/usr/bin/env python3
"""diag_real_dispatch.py - Find and compare the REAL interrupt dispatch table.

The common handler at 0x060008F4 loads the dispatch table base from
a pool at (PC+4)&~3 + 0x17*4, where PC=0x06000902:
  EA = (0x06000906 & ~3) + 0x5C = 0x06000960

Then indexes by (vector_number * 4) to get the handler.
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
    0x40: "VBlank-IN", 0x41: "VBlank-OUT", 0x42: "HBlank-IN",
    0x43: "Timer 0", 0x44: "Timer 1", 0x45: "DSP End",
    0x46: "Sound Req", 0x47: "SMPC", 0x48: "PAD",
    0x49: "DMA L2", 0x4A: "DMA L1", 0x4B: "DMA L0",
    0x4C: "DMA Illegal", 0x4D: "Sprite End",
}

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


def test_build(name, cue, ipc_name, poll_addr, sys_init_addr):
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
        inst.quit(); MednafenInstance.kill_stale(); return None
    inst.breakpoint_clear()

    inst.breakpoint(poll_addr)
    try:
        ack = inst.continue_exec()
        print(f"  FUN_060423CC entered at frame {parse_frame(ack)}")
    except TimeoutError:
        inst.quit(); MednafenInstance.kill_stale(); return None
    inst.breakpoint_clear()

    # Read pool values used by common handler
    # Pool at 0x06000958: pointer-to-pointer (value = 0x06000348)
    # Pool at 0x06000960: dispatch table base
    pool_area = dump_mem(inst, ipc, 0x06000950, 0x20, "handler_pool")
    if pool_area and len(pool_area) >= 0x14:
        print(f"\n  Common handler pool entries:")
        for off in range(0, 0x14, 4):
            val = struct.unpack('>I', pool_area[off:off+4])[0]
            print(f"    0x{0x06000950+off:08X}: 0x{val:08X}")

    # Get dispatch table base from [0x06000960]
    table_base_data = dump_mem(inst, ipc, 0x06000960, 4, "table_base")
    if not table_base_data or len(table_base_data) < 4:
        print(f"  Failed to read table base!")
        inst.quit(); MednafenInstance.kill_stale(); return None

    table_base = struct.unpack('>I', table_base_data[:4])[0]
    print(f"\n  Dispatch table base: [0x06000960] = 0x{table_base:08X}")

    # Read the dispatch table entries (vectors 0x40-0x50)
    # Table[i] = [table_base + i*4]
    # For vector 0x40: offset = 0x40*4 = 0x100
    entries = {}
    if 0x06000000 <= table_base < 0x06100000:
        # Read entries for SCU vectors (0x40-0x4F)
        start_off = 0x40 * 4  # = 0x100
        table_data = dump_mem(inst, ipc, table_base + start_off, 0x40, "dispatch_entries")
        if table_data and len(table_data) >= 0x38:
            print(f"\n  Dispatch table entries (at 0x{table_base:08X} + vector*4):")
            for i in range(14):  # vectors 0x40-0x4D
                vec = 0x40 + i
                off = i * 4
                val = struct.unpack('>I', table_data[off:off+4])[0]
                vec_name = VECTOR_NAMES.get(vec, f"vec_{vec:02X}")
                in_code = " [CODE]" if 0x06003000 <= val < 0x06070000 else ""
                print(f"    vec 0x{vec:02X} ({vec_name:14s}): 0x{val:08X}{in_code}")
                entries[vec] = val
    else:
        # Table base might be in a different memory region
        print(f"  Table base 0x{table_base:08X} is outside expected range!")
        # Try reading it anyway
        table_data = dump_mem(inst, ipc, table_base, 0x200, "dispatch_raw")
        if table_data and len(table_data) >= 0x150:
            print(f"\n  Table entries around vector 0x40 (offset 0x100):")
            for off in range(0x100, min(len(table_data), 0x140), 4):
                val = struct.unpack('>I', table_data[off:off+4])[0]
                vec = off // 4
                vec_name = VECTOR_NAMES.get(vec, f"idx_{vec:02X}")
                in_code = " [CODE]" if 0x06003000 <= val < 0x06070000 else ""
                print(f"    [{vec:02X}] 0x{val:08X}{in_code}")
                entries[vec] = val

    inst.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()
    return entries


def main():
    print("=" * 70)
    print("  Real Interrupt Dispatch Table Comparison")
    print("=" * 70)

    print("\n>>> PRODUCTION <<<")
    prod = test_build("PROD", CUE_PROD, "realdisp_prod",
                      poll_addr=0x060423CC,
                      sys_init_addr=0x060030FC)

    time.sleep(2)

    print("\n>>> FREE-LAYOUT <<<")
    free = test_build("FREE", CUE_FREE, "realdisp_free",
                      poll_addr=0x060423D0,
                      sys_init_addr=0x06003100)

    if prod and free:
        print(f"\n{'='*70}")
        print(f"  DISPATCH TABLE COMPARISON")
        print(f"{'='*70}")
        wrong_count = 0
        for vec in sorted(set(list(prod.keys()) + list(free.keys()))):
            pv = prod.get(vec, 0)
            fv = free.get(vec, 0)
            vec_name = VECTOR_NAMES.get(vec, f"vec_{vec:02X}")

            if pv == 0 and fv == 0:
                continue

            if fv == pv + SHIFT:
                status = f"SHIFTED +{SHIFT} (correct)"
            elif fv == pv:
                if pv >= 0x06003000 and pv < 0x06070000:
                    status = "*** NOT SHIFTED! Should be +4 ***"
                    wrong_count += 1
                else:
                    status = "IDENTICAL (non-code or below shift)"
            elif pv == 0 or fv == 0:
                status = "*** ONE IS ZERO ***"
                wrong_count += 1
            else:
                diff = fv - pv
                status = f"*** UNEXPECTED DIFF = {diff:+d} ***"
                wrong_count += 1

            print(f"  vec 0x{vec:02X} ({vec_name:14s}): prod=0x{pv:08X} free=0x{fv:08X} {status}")

        if wrong_count > 0:
            print(f"\n  *** {wrong_count} INCORRECTLY SHIFTED entries! ***")
            print(f"  Interrupt handlers may be jumping to wrong addresses!")
        else:
            print(f"\n  All entries correctly handled.")


if __name__ == "__main__":
    main()
