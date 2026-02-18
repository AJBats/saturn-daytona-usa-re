#!/usr/bin/env python3
"""diag_handler_table.py - Find the REAL interrupt handler address table.

The common interrupt dispatcher at 0x060008F4 uses TWO tables:
1. Priority/mask table at [0x06000960] = 0x06000980
2. Handler address table at [0x06000968]

Both indexed by vector_number * 4.

The handler table entries should be shifted +4 in the free build.
If they're NOT shifted, interrupts call wrong functions.
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

    # Read all pool entries used by the common handler
    pool_data = dump_mem(inst, ipc, 0x06000958, 0x20, "pools")
    if pool_data and len(pool_data) >= 0x14:
        print(f"\n  Common handler pools:")
        for off in range(0, 0x14, 4):
            val = struct.unpack('>I', pool_data[off:off+4])[0]
            print(f"    [0x{0x06000958+off:08X}] = 0x{val:08X}")

    # Pool at 0x06000968 should be the handler table base
    handler_table_data = dump_mem(inst, ipc, 0x06000968, 4, "handler_table_ptr")
    if not handler_table_data or len(handler_table_data) < 4:
        print(f"  Failed to read handler table pointer!")
        inst.quit(); MednafenInstance.kill_stale(); return None

    handler_table = struct.unpack('>I', handler_table_data[:4])[0]
    print(f"\n  Handler table base: [0x06000968] = 0x{handler_table:08X}")

    # Read handler table entries for vectors 0x40-0x50
    entries = {}
    if 0x06000000 <= handler_table < 0x06100000:
        start_off = 0x40 * 4  # = 0x100
        data = dump_mem(inst, ipc, handler_table + start_off, 0x40, "handler_entries")
        if data and len(data) >= 0x38:
            print(f"\n  Handler address table entries:")
            for i in range(14):
                vec = 0x40 + i
                off = i * 4
                val = struct.unpack('>I', data[off:off+4])[0]
                vec_name = VECTOR_NAMES.get(vec, f"vec_{vec:02X}")
                in_code = " [CODE]" if 0x06003000 <= val < 0x06070000 else ""
                print(f"    vec 0x{vec:02X} ({vec_name:14s}): 0x{val:08X}{in_code}")
                entries[vec] = val
    else:
        print(f"  Handler table at 0x{handler_table:08X} - outside expected range")
        # Still try to read it
        data = dump_mem(inst, ipc, handler_table, 0x200, "handler_raw")
        if data and len(data) >= 0x150:
            start_off = 0x40 * 4
            print(f"\n  Handler entries (from offset 0x{start_off:X}):")
            for off in range(start_off, min(len(data), start_off + 0x38), 4):
                val = struct.unpack('>I', data[off:off+4])[0]
                vec = off // 4
                vec_name = VECTOR_NAMES.get(vec, f"vec_{vec:02X}")
                in_code = " [CODE]" if 0x06003000 <= val < 0x06070000 else ""
                print(f"    vec 0x{vec:02X} ({vec_name:14s}): 0x{val:08X}{in_code}")
                entries[vec] = val

    # Also read the full handler common code for complete understanding
    handler_full = dump_mem(inst, ipc, 0x060008F4, 0x50, "handler_full")
    if handler_full and len(handler_full) >= 0x50:
        print(f"\n  Full common handler disassembly (0x060008F4-0x06000944):")
        for off in range(0, min(len(handler_full), 0x50), 2):
            w = struct.unpack('>H', handler_full[off:off+2])[0]
            addr = 0x060008F4 + off
            print(f"    0x{addr:08X}: {w:04X}")

    inst.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()
    return entries


def main():
    print("=" * 70)
    print("  Handler Address Table Comparison")
    print("=" * 70)

    print("\n>>> PRODUCTION <<<")
    prod = test_build("PROD", CUE_PROD, "htable_prod",
                      poll_addr=0x060423CC,
                      sys_init_addr=0x060030FC)

    time.sleep(2)

    print("\n>>> FREE-LAYOUT <<<")
    free = test_build("FREE", CUE_FREE, "htable_free",
                      poll_addr=0x060423D0,
                      sys_init_addr=0x06003100)

    if prod and free:
        print(f"\n{'='*70}")
        print(f"  HANDLER TABLE COMPARISON")
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
                if 0x06003000 <= pv < 0x06070000:
                    status = "*** NOT SHIFTED! Expected +4 ***"
                    wrong_count += 1
                else:
                    status = "IDENTICAL"
            else:
                diff = fv - pv
                status = f"*** UNEXPECTED DIFF = {diff:+d} ***"
                if 0x06003000 <= pv < 0x06070000 and diff != SHIFT:
                    wrong_count += 1
            print(f"  vec 0x{vec:02X} ({vec_name:14s}): prod=0x{pv:08X} free=0x{fv:08X} {status}")

        if wrong_count > 0:
            print(f"\n  *** {wrong_count} INCORRECTLY SHIFTED handler addresses! ***")
            print(f"  Interrupts calling wrong functions = ROOT CAUSE CANDIDATE!")
        else:
            print(f"\n  All handler addresses correctly shifted.")


if __name__ == "__main__":
    main()
