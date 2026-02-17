#!/usr/bin/env python3
"""find_crash_callee.py -- Targeted boot sequence diagnosis.

Sequential breakpoint test: set ONE breakpoint at a time, continue, verify hit.
No false positives from BIOS interrupt handlers.

Usage:
    python tools/find_crash_callee.py             # Sequential breakpoint test
    python tools/find_crash_callee.py --parallel   # Prod vs reimpl comparison
"""

import os, sys, time, re, struct

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin, TMPDIR

CUE_REIMPL = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")

# Key addresses from sh-elf-nm (after Class 3 fix rebuild)
BOOT         = 0x060541C8
SYSTEM_INIT  = 0x06053FC4
PER_FRAME    = 0x06054684
STATE2       = 0x06054AF0


def parse_pc(ack):
    m = re.search(r'pc=0x([0-9a-fA-F]+)', ack)
    return int(m.group(1), 16) if m else None


def parse_frame(ack):
    m = re.search(r'frame=(\d+)', ack)
    return int(m.group(1)) if m else None


def dump_regs(inst, ipc_dir):
    """Dump and return register dict."""
    path = os.path.join(ipc_dir, "regs.bin")
    inst.dump_regs_bin(path)
    time.sleep(0.2)
    return read_regs_bin(path)


def run_sequential_test():
    """Test each key breakpoint one at a time."""
    MednafenInstance.kill_stale()

    ipc_dir = os.path.join(TMPDIR, "crash_hunt")
    reimpl = MednafenInstance("reimpl", CUE_REIMPL, ipc_dir)

    print("Starting reimpl...")
    reimpl.start()

    # Phase 1: Verify boot + system_init entered
    print("\n[1] boot() + system_init() entry...")
    reimpl.breakpoint(SYSTEM_INIT)
    try:
        ack = reimpl.continue_exec()
        pc = parse_pc(ack)
        if pc == SYSTEM_INIT:
            print(f"    system_init() entered at frame {parse_frame(ack)}")
        else:
            print(f"    Failed: pc=0x{pc:08X}")
            reimpl.send("quit")
            return
    except TimeoutError:
        print("    TIMEOUT - system_init never reached!")
        reimpl.send("quit")
        return
    reimpl.breakpoint_clear()

    # Phase 2: Walk through system_init callees
    CALLEES = [
        ("course_system_init",  0x06056de0),
        ("menu_system_init",    0x06056e34),
        ("game_subsystem_init", 0x06056e38),
        ("vdp_init_dispatcher", 0x060579a8),
        ("global_engine_init",  0x06056ea8),
        ("game_subsystem_init2",0x060562fc),
        ("sound_timer_init",    0x06056834),
        ("cd_system_init",      0x06056eb4),
        ("object_system_init",  0x06056f68),
        ("render_system_init",  0x06056f94),
        ("vdp_system_init_a",   0x06057898),
        ("vdp_system_init_b",   0x06053e1c),
    ]

    print("\n[2] Walking through system_init callees...")
    # Set ALL callee breakpoints at once, then continue through them
    for name, addr in CALLEES:
        reimpl.breakpoint(addr)
    # Also set per_frame_setup as the "success" marker
    reimpl.breakpoint(PER_FRAME)

    last_hit = "system_init entry"
    for i in range(len(CALLEES) + 1):
        try:
            ack = reimpl.continue_exec()
            pc = parse_pc(ack)
            frame = parse_frame(ack)

            if pc == PER_FRAME:
                print(f"    per_frame_setup reached (frame {frame}) - all callees OK!")
                last_hit = "ALL CALLEES PASSED"
                break

            # Find which callee this is
            callee_name = None
            for name, addr in CALLEES:
                if pc == addr:
                    callee_name = name
                    break

            if callee_name:
                print(f"    {callee_name} reached (frame {frame})")
                last_hit = callee_name
            else:
                print(f"    Unknown BP hit: pc=0x{pc:08X} (frame {frame})")
                break

        except TimeoutError:
            print(f"\n    TIMEOUT after reaching {last_hit}")
            regs = dump_regs(reimpl, ipc_dir)
            if regs:
                print(f"    Crash: PC=0x{regs['PC']:08X} PR=0x{regs['PR']:08X}")
                print(f"           SR=0x{regs['SR']:08X} SP=0x{regs['R15']:08X}")

            # Find next expected callee
            found_last = False
            for name, addr in CALLEES:
                if name == last_hit:
                    found_last = True
                    continue
                if found_last:
                    print(f"\n    => CRASH IS INSIDE: {last_hit}")
                    print(f"       (next callee {name} was never reached)")
                    break
            break

    reimpl.send("quit")
    time.sleep(1)
    MednafenInstance.kill_stale()
    print("\nDone.")


def run_parallel_comparison():
    """Breakpoint-based comparison: set BP at boot() in both, compare state."""
    MednafenInstance.kill_stale()

    ipc_a = os.path.join(TMPDIR, "emu_prod")
    ipc_b = os.path.join(TMPDIR, "emu_reimpl")

    prod = MednafenInstance("prod", CUE_PROD, ipc_a)
    reimpl = MednafenInstance("reimpl", CUE_REIMPL, ipc_b)

    print("Starting both instances...")
    prod.start()
    reimpl.start()

    # In production, the entry point is the original main() at 0x06003000.
    # The first instruction of original main loads system_init address from constant pool.
    # Let's breakpoint at the original entry: 0x06003000
    ENTRY = 0x06003000
    print(f"\nSetting breakpoint at entry point 0x{ENTRY:08X} in both...")
    prod.breakpoint(ENTRY)
    reimpl.breakpoint(ENTRY)

    print("Continuing both to entry point...")
    ack_a = prod.continue_exec()
    ack_b = reimpl.continue_exec()
    print(f"  prod:   {ack_a}")
    print(f"  reimpl: {ack_b}")

    # Compare registers at entry
    print("\n=== Registers at entry ===")
    regs_a = dump_regs(prod, ipc_a)
    regs_b = dump_regs(reimpl, ipc_b)
    if regs_a and regs_b:
        for name in ["PC", "R15", "SR", "PR", "VBR", "R0", "R1"]:
            va = regs_a.get(name, 0)
            vb = regs_b.get(name, 0)
            match = "OK" if va == vb else "DIFF"
            print(f"  {name:5s}: prod=0x{va:08X}  reimpl=0x{vb:08X}  [{match}]")

    # Compare memory: game code at entry
    print("\n=== Memory at entry ===")
    for addr, size, desc in [
        (0x06003000, 0x200, "Entry code (512B)"),
        (0x06010000, 0x200, "Mid-range code (512B)"),
        (0x06050000, 0x200, "Late code area (512B)"),
    ]:
        pa = os.path.join(ipc_a, f"mem_{addr:08X}.bin")
        pb = os.path.join(ipc_b, f"mem_{addr:08X}.bin")
        prod.dump_mem_bin(addr, size, pa)
        time.sleep(0.1)
        reimpl.dump_mem_bin(addr, size, pb)
        time.sleep(0.2)
        try:
            with open(pa, "rb") as f:
                da = f.read()
            with open(pb, "rb") as f:
                db = f.read()
            if da == db:
                print(f"  {desc}: IDENTICAL")
            else:
                ndiff = sum(1 for i in range(min(len(da), len(db))) if da[i] != db[i])
                print(f"  {desc}: {ndiff}/{size} bytes differ")
                shown = 0
                for i in range(min(len(da), len(db))):
                    if da[i] != db[i]:
                        print(f"    0x{addr+i:08X}: prod=0x{da[i]:02X} reimpl=0x{db[i]:02X}")
                        shown += 1
                        if shown >= 8:
                            print(f"    ... ({ndiff - shown} more)")
                            break
        except FileNotFoundError as e:
            print(f"  {desc}: ERROR {e}")

    prod.quit()
    reimpl.quit()
    print("\nDone.")


def main():
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument("--parallel", action="store_true",
                        help="Run prod + reimpl breakpoint comparison")
    args = parser.parse_args()

    if args.parallel:
        run_parallel_comparison()
    else:
        run_sequential_test()


if __name__ == "__main__":
    main()
