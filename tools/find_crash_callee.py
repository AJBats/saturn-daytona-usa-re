#!/usr/bin/env python3
"""Find which callee of system_init crashes on the reimpl.

Strategy: Set breakpoints at each callee entry in the reimpl Mednafen instance.
Run with `continue` — each callee hit tells us it was reached. The last one
hit before the crash (PC lands at exception handler 0x06000956) is the culprit.
"""

import os, sys, time

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, TMPDIR

# system_init callees in execution order, with reimpl link addresses (from nm)
CALLEES = [
    # (name, reimpl_addr)
    ("system_init",          0x060530b8),  # entry — we know this is reached
    ("course_system_init",   0x06056de0),
    ("menu_system_init",     0x06056e34),
    # BIOS_FUNC_0344 — indirect, skip
    ("game_subsystem_init",  0x06056e38),
    ("vdp_init_dispatcher",  0x060579a8),
    ("global_engine_init",   0x06056ea8),  # -> FUN_06004A98 at 0x06004a98
    ("game_subsystem_init2", 0x060562fc),
    ("sound_timer_init",     0x06056834),
    ("cd_system_init",       0x06056eb4),
    # BIOS_FUNC_0344 — indirect, skip
    ("object_system_init",   0x06056f68),
    ("render_system_init",   0x06056f94),
    ("vdp_system_init_a",    0x06057898),
    ("vdp_system_init_b",    0x06053e1c),
]

# Exception handler address (crash destination)
EXCEPTION_HANDLER = 0x06000956

CUE_REIMPL = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")

def main():
    MednafenInstance.kill_stale()

    ipc_dir = os.path.join(TMPDIR, "crash_hunt")
    reimpl = MednafenInstance("reimpl", CUE_REIMPL, ipc_dir)

    print("Starting reimpl...")
    reimpl.start()

    # Set breakpoints at all callees + exception handler
    for name, addr in CALLEES:
        ack = reimpl.breakpoint(addr)
        print(f"  BP: {name} @ 0x{addr:08X} -> {ack}")

    # Also set BP at exception handler to catch the crash
    reimpl.breakpoint(EXCEPTION_HANDLER)
    print(f"  BP: EXCEPTION @ 0x{EXCEPTION_HANDLER:08X}")

    # Also breakpoint at main loop top (0x0600300A) — if we reach this, no crash!
    MAIN_LOOP = 0x0600300A
    reimpl.breakpoint(MAIN_LOOP)
    print(f"  BP: MAIN_LOOP @ 0x{MAIN_LOOP:08X}")

    # Run and collect breakpoint hits
    print("\nRunning... (will hit breakpoints in order)")
    hits = []

    for i in range(30):  # Max 30 breakpoint hits
        try:
            ack = reimpl.continue_exec()
            print(f"  Hit #{i}: {ack}")
            hits.append(ack)

            # Parse PC from ack
            if "pc=" in ack:
                pc_str = ack.split("pc=")[1].split()[0]
                pc = int(pc_str, 16)

                if pc == EXCEPTION_HANDLER:
                    print(f"\n*** CRASH at exception handler 0x{EXCEPTION_HANDLER:08X} ***")
                    print(f"*** Last callee hit before crash: {hits[-2] if len(hits) >= 2 else 'none'}")

                    # Dump registers to see PR (return address = where crash happened)
                    ack = reimpl.dump_regs()
                    print(f"\nRegisters at crash:\n{ack}")
                    break

                if pc == MAIN_LOOP:
                    print(f"\n*** SUCCESS: Reached main loop! No crash in system_init ***")
                    break

        except Exception as e:
            print(f"  Error: {e}")
            break

    # Cleanup
    try:
        reimpl.send("quit")
    except:
        pass
    time.sleep(1)
    MednafenInstance.kill_stale()

    print("\nDone.")

if __name__ == "__main__":
    main()
