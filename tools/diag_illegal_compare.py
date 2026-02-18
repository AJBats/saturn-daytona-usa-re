#!/usr/bin/env python3
"""diag_illegal_compare.py - Compare prod vs reimpl at frame ~1000.

Check if the "Illegal Instruction at PC=0x00000002" is reimpl-specific
or also happens on the production disc.
"""

import os, sys, time, struct, re

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin

CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")
CUE_REIMPL = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
TMPDIR = os.path.join(PROJDIR, ".tmp")


def parse_frame(ack):
    m = re.search(r'frame=(\d+)', ack)
    return int(m.group(1)) if m else None


def dump_regs(inst, ipc_dir, tag=""):
    path = os.path.join(ipc_dir, f"regs_{tag}.bin")
    inst.dump_regs_bin(path)
    time.sleep(0.3)
    return read_regs_bin(path)


def test_build(name, cue, ipc_name):
    MednafenInstance.kill_stale()
    ipc = os.path.join(TMPDIR, ipc_name)
    inst = MednafenInstance(name, cue, ipc)
    inst.start()

    print(f"\n{'='*60}")
    print(f"  {name}")
    print(f"{'='*60}")

    # Wait for _start
    inst.breakpoint(0x06003000)
    try:
        ack = inst.continue_exec()
        frame = parse_frame(ack)
        print(f"  _start at frame {frame}")
    except TimeoutError:
        print(f"  TIMEOUT at _start!")
        inst.quit(); MednafenInstance.kill_stale(); return
    inst.breakpoint_clear()

    # Wait for main_loop
    inst.breakpoint(0x0600300A)
    try:
        ack = inst.continue_exec()
        frame = parse_frame(ack)
        print(f"  main_loop at frame {frame}")
    except TimeoutError:
        print(f"  TIMEOUT at main_loop!")
        inst.quit(); MednafenInstance.kill_stale(); return
    inst.breakpoint_clear()

    # Advance frames and sample PC
    print(f"\n  Frame-by-frame PC sampling:")
    print(f"  {'Frame':>6s}  {'PC':>12s}  {'PR':>12s}  {'SR':>12s}  {'R0':>12s}")
    print(f"  {'-'*60}")

    base_frame = frame
    for i in range(200):
        inst.frame_advance(10)
        regs = dump_regs(inst, ipc, f"f{i}")
        if not regs:
            continue

        pc = regs['PC']
        pr = regs['PR']
        sr = regs['SR']
        r0 = regs['R0']
        f_approx = base_frame + (i + 1) * 10

        # Print every 50th frame, or when something interesting happens
        in_code = 0x06003000 <= pc < 0x06100000
        in_system = 0x06000000 <= pc < 0x06003000
        in_bios = pc < 0x00080000

        notes = ""
        if in_bios:
            notes = "BIOS"
        elif in_system:
            notes = "system"
        elif not in_code:
            notes = "???"

        if i < 10 or i % 20 == 0 or not in_code:
            print(f"  ~{f_approx:5d}  0x{pc:08X}  0x{pr:08X}  0x{sr:08X}  0x{r0:08X}  {notes}")

        if in_bios:
            print(f"  *** BIOS at frame ~{f_approx}! ***")
            break

    inst.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()


def main():
    print("=" * 70)
    print("  Production vs Reimpl: Extended Boot Comparison")
    print("=" * 70)

    print("\n>>> PRODUCTION <<<")
    test_build("PROD", CUE_PROD, "illegal_prod")

    time.sleep(2)

    print("\n>>> REIMPL <<<")
    test_build("REIMPL", CUE_REIMPL, "illegal_reimpl")


if __name__ == "__main__":
    main()
