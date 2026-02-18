#!/usr/bin/env python3
"""diag_hirq_prod_reimpl.py - Monitor HIRQ in production reimpl on rebuilt disc.

Same test as diag_hirq_evolution.py but using the production reimpl
(sawyer.ld, no shift) on the rebuilt disc to confirm SCDQ fires.
"""

import os, sys, time, struct, re

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin

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


def monitor_hirq(name, cue, ipc_name, poll_addr, extu_addr, sys_init_addr):
    MednafenInstance.kill_stale()
    ipc = os.path.join(TMPDIR, ipc_name)
    inst = MednafenInstance(name, cue, ipc)
    inst.start()

    print(f"\n{'='*60}")
    print(f"  {name}  poll=0x{poll_addr:08X}  extu=0x{extu_addr:08X}")
    print(f"{'='*60}")

    inst.breakpoint(sys_init_addr)
    try:
        inst.continue_exec()
    except TimeoutError:
        print(f"  TIMEOUT at system_init!")
        inst.quit(); MednafenInstance.kill_stale(); return
    inst.breakpoint_clear()

    inst.breakpoint(poll_addr)
    try:
        ack = inst.continue_exec()
        entry_frame = parse_frame(ack)
        print(f"  Poll entered at frame {entry_frame}")
    except TimeoutError:
        print(f"  TIMEOUT at poll entry!")
        inst.quit(); MednafenInstance.kill_stale(); return
    inst.breakpoint_clear()

    # Read R12 after setup (need to step past setup instructions first)
    # Instead, just capture at EXTU.W which is after the JSR returns
    print(f"\n  HIRQ evolution:")
    print(f"  {'Frame':>8s}  {'R0 (HIRQ)':>12s}  {'R12':>12s}  {'SCDQ':>6s}  Notes")
    print(f"  {'-'*65}")

    last_r0 = None
    for trial in range(30):
        inst.breakpoint(extu_addr)
        try:
            ack = inst.continue_exec()
            frame = parse_frame(ack)
            regs = dump_regs(inst, ipc, f"trial{trial}")
            if regs:
                r0 = regs['R0']
                r12 = regs['R12']
                scdq = "SET" if (r0 & 0x0400) else "clear"
                changed = ""
                if last_r0 is not None and r0 != last_r0:
                    changed = f"CHANGED from 0x{last_r0:04X}"
                last_r0 = r0
                print(f"  {frame:>8d}  0x{r0:08X}  0x{r12:08X}  {scdq}  {changed}")

                if r0 & 0x0400:
                    print(f"  *** SCDQ detected! ***")
                    break
        except TimeoutError:
            print(f"  TIMEOUT (poll exited or stuck)")
            regs = dump_regs(inst, ipc, f"timeout{trial}")
            if regs:
                print(f"  PC=0x{regs['PC']:08X} PR=0x{regs['PR']:08X}")
                if regs['PC'] < poll_addr or regs['PC'] > poll_addr + 0x40:
                    print(f"  *** Poll EXITED successfully! ***")
            break

        inst.breakpoint_clear()

        # Same advance schedule as free build test
        if trial < 5:
            advance = 5
        elif trial < 10:
            advance = 10
        elif trial < 20:
            advance = 30
        else:
            advance = 60

        inst.frame_advance(advance)

    inst.breakpoint_clear()
    inst.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()


def main():
    print("=" * 70)
    print("  HIRQ Monitor: Production Reimpl on Rebuilt Disc")
    print("=" * 70)

    # Production reimpl: no shift, addresses same as original
    print("\n>>> PRODUCTION REIMPL (sawyer.ld, no shift) on rebuilt disc <<<")
    monitor_hirq("PROD_REIMPL", CUE_FREE, "hirq_evo_prod",
                 poll_addr=0x060423CC,
                 extu_addr=0x060423E2,
                 sys_init_addr=0x060030FC)


if __name__ == "__main__":
    main()
