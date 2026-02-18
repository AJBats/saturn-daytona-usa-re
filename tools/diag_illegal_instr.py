#!/usr/bin/env python3
"""diag_illegal_instr.py - Diagnose "Illegal Instruction at PC=0x00000002".

Boot the reimpl disc, advance past title screen rendering, and use call trace
to capture what happens right before the crash. PC=0x00000002 suggests a jump
to near-zero (corrupted function pointer or uninitialized jump table entry).

Strategy:
1. Boot and wait for _start (frame ~370)
2. Continue to main_loop (frame ~580)
3. Enable call trace
4. Advance frames in small increments, checking for crash
5. When crash detected, examine call trace for the last call before PC=0x2
"""

import os, sys, time, struct, re

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin

CUE = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
TMPDIR = os.path.join(PROJDIR, ".tmp")


def parse_frame(ack):
    m = re.search(r'frame=(\d+)', ack)
    return int(m.group(1)) if m else None


def dump_regs(inst, ipc_dir, tag=""):
    path = os.path.join(ipc_dir, f"regs_{tag}.bin")
    inst.dump_regs_bin(path)
    time.sleep(0.3)
    return read_regs_bin(path)


def main():
    MednafenInstance.kill_stale()

    ipc = os.path.join(TMPDIR, "diag_illegal")
    inst = MednafenInstance("REIMPL", CUE, ipc)
    inst.start()

    print("Waiting for _start...")
    inst.breakpoint(0x06003000)
    try:
        ack = inst.continue_exec()
        frame = parse_frame(ack)
        print(f"  _start at frame {frame}")
    except TimeoutError:
        print("  TIMEOUT at _start!")
        inst.quit(); MednafenInstance.kill_stale(); return
    inst.breakpoint_clear()

    print("Waiting for main_loop...")
    inst.breakpoint(0x0600300A)
    try:
        ack = inst.continue_exec()
        frame = parse_frame(ack)
        print(f"  main_loop at frame {frame}")
    except TimeoutError:
        print("  TIMEOUT at main_loop!")
        inst.quit(); MednafenInstance.kill_stale(); return
    inst.breakpoint_clear()

    # Now advance frame by frame, checking registers each time
    # The game enters the 32-state machine loop. We need to find where PC goes to 0x2.
    print("\nAdvancing frames, monitoring for crash...")
    print(f"  {'Frame':>6s}  {'PC':>12s}  {'PR':>12s}  {'SR':>12s}  Notes")
    print(f"  {'-'*65}")

    # Enable call trace
    trace_path = os.path.join(ipc, "call_trace.bin")
    trace_path_wsl = f"/mnt/d/Projects/SaturnReverseTest/.tmp/diag_illegal/call_trace.bin"
    inst.send(f"call_trace {trace_path_wsl}")
    print(f"  Call trace enabled: {trace_path}")

    crash_frame = None
    for i in range(500):
        # Advance 10 frames at a time
        advance = 10
        inst.frame_advance(advance)

        regs = dump_regs(inst, ipc, f"f{i}")
        if not regs:
            print(f"  Failed to read registers at step {i}")
            continue

        pc = regs['PC']
        pr = regs['PR']
        sr = regs['SR']

        # Check for crash indicators
        is_crash = pc < 0x06003000 or pc > 0x06100000

        if is_crash or i < 10 or i % 50 == 0:
            notes = ""
            if pc < 0x06003000:
                notes = "*** BELOW CODE RANGE ***"
            if pc < 0x00080000:
                notes = "*** IN BIOS ROM ***"
            if pc == 0x00000002:
                notes = "*** ILLEGAL INSTRUCTION TARGET ***"

            frame_approx = frame + (i + 1) * advance
            print(f"  ~{frame_approx:5d}  0x{pc:08X}  0x{pr:08X}  0x{sr:08X}  {notes}")

        if is_crash:
            crash_frame = frame + (i + 1) * advance
            print(f"\n  CRASH at ~frame {crash_frame}!")
            print(f"  PC=0x{pc:08X} PR=0x{pr:08X}")

            # Stop call trace
            inst.send("call_trace_stop")
            time.sleep(0.5)

            # Read last few calls from trace
            try:
                size = os.path.getsize(trace_path)
                print(f"  Call trace: {size} bytes ({size // 30} approx entries)")

                # Read last 2KB of trace
                with open(trace_path, 'r') as f:
                    lines = f.readlines()
                print(f"  Total trace lines: {len(lines)}")
                print(f"\n  Last 30 calls before crash:")
                for line in lines[-30:]:
                    print(f"    {line.rstrip()}")
            except Exception as e:
                print(f"  Error reading trace: {e}")

            break

    if not crash_frame:
        print("\n  No crash detected in 5000 frames!")
        inst.send("call_trace_stop")

        # Dump final state
        regs = dump_regs(inst, ipc, "final")
        if regs:
            print(f"  Final PC=0x{regs['PC']:08X} PR=0x{regs['PR']:08X}")

    inst.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()


if __name__ == "__main__":
    main()
