#!/usr/bin/env python3
"""Quick check: does the SCDQ poll loop complete with our Mednafen?
Boots a disc, sets breakpoint at the function after SCDQ, checks if it fires."""

import os
import sys
import time

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJ, "tools"))

from parallel_compare import MednafenInstance, TMPDIR

CUE_PROD = os.path.join(PROJ, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")
CUE_FREE = os.path.join(PROJ, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")

def check_disc(name, cue_path, scdq_addr):
    """Boot a disc and check if execution gets past SCDQ."""
    ipc_dir = os.path.join(TMPDIR, f"scdq_{name}")
    inst = MednafenInstance(name, cue_path, ipc_dir)

    print(f"\n=== {name} disc ===")
    inst.start()

    # Advance past BIOS
    inst.frame_advance(60)
    print(f"  Past BIOS (frame 60)")

    # Set breakpoint at SCDQ function entry
    ack = inst.send(f"breakpoint {scdq_addr:X}")
    print(f"  Breakpoint at SCDQ 0x{scdq_addr:08X}: {ack}")

    # Continue and wait for hit
    inst.last_ack = inst._read_ack() or ""
    inst._write_action("continue")
    try:
        ack = inst._wait_ack_change(timeout=5)  # "ok continue"
        ack = inst._wait_ack_change(timeout=60)  # breakpoint hit or timeout
        print(f"  Hit SCDQ: {ack}")
    except TimeoutError:
        print(f"  Didn't reach SCDQ in 60s — maybe already past it?")
        inst._write_action("pause")
        time.sleep(1)
        ack = inst._read_ack()
        print(f"  Paused: {ack}")
        inst.send("quit")
        return

    # Clear breakpoints, set one AFTER the SCDQ function returns
    # (i.e., at the caller's return address)
    inst.send("breakpoint_clear")

    # Read PR register (return address)
    ack = inst.send("dump_regs")
    print(f"  Regs at SCDQ entry: {ack}")

    # Step through a few hundred instructions to see if we exit the loop
    print(f"  Stepping through SCDQ (up to 5000 instructions)...")
    for i in range(50):
        ack = inst.step(100)
        # Check if PC left the SCDQ function range
        if "done step pc=" in ack:
            import re
            m = re.search(r'pc=0x([0-9a-fA-F]+)', ack)
            if m:
                pc = int(m.group(1), 16)
                if abs(pc - scdq_addr) > 0x100:
                    print(f"  EXITED SCDQ at step {(i+1)*100}: PC=0x{pc:08X}")
                    break
    else:
        ack = inst.send("dump_regs")
        print(f"  Still in SCDQ after 5000 steps: {ack}")

    inst.send("quit")
    time.sleep(1)


def main():
    os.makedirs(TMPDIR, exist_ok=True)
    MednafenInstance.kill_stale()

    # Production: SCDQ function is at 0x060423CC
    check_disc("prod", CUE_PROD, 0x060423CC)

    MednafenInstance.kill_stale()

    # Free build: SCDQ function shifted +4 = 0x060423D0
    check_disc("free", CUE_FREE, 0x060423D0)


if __name__ == "__main__":
    main()
