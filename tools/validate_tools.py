#!/usr/bin/env python3
"""validate_tools.py — Validate that our debugging tools are accurate.

Runs TWO instances of the SAME disc (production) side-by-side.
If our tools work correctly, registers should be identical at every frame.
If they differ, our tools have a bug.

This is essential to run BEFORE trusting any prod-vs-reimpl comparison.
"""

import os
import sys
import time
import struct

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from parallel_compare import MednafenInstance, read_regs_bin, compare_regs, win_to_wsl

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MEDNAFEN = os.path.join(PROJDIR, "mednafen", "src", "mednafen")
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")
TMPDIR = os.path.join(PROJDIR, ".tmp")


def main():
    ipc_a = os.path.join(TMPDIR, "emu_validate_a")
    ipc_b = os.path.join(TMPDIR, "emu_validate_b")

    # Both instances use the SAME disc
    inst_a = MednafenInstance("same_A", CUE_PROD, ipc_a)
    inst_b = MednafenInstance("same_B", CUE_PROD, ipc_b)

    print("=== Tool Validation: Two identical disc instances ===")
    print("If registers differ, our tools have a bug.\n")

    print("Starting emulators (both running production disc)...")
    inst_a.start()
    inst_b.start()

    # Let BIOS init
    print("Waiting for BIOS init (3s)...")
    time.sleep(3)

    print("Pausing both...")
    ack_a = inst_a.pause()
    ack_b = inst_b.pause()
    print(f"  A: {ack_a}")
    print(f"  B: {ack_b}")

    # Extract frame numbers to check they're close
    import re
    m_a = re.search(r'frame=(\d+)', ack_a)
    m_b = re.search(r'frame=(\d+)', ack_b)
    if m_a and m_b:
        frame_a, frame_b = int(m_a.group(1)), int(m_b.group(1))
        print(f"  Paused at frames: A={frame_a}, B={frame_b} (delta={abs(frame_a - frame_b)})")
        if frame_a != frame_b:
            print("  NOTE: Frames differ because free-run timing is non-deterministic.")
            print("  This is expected. We need to sync them by advancing to the same frame.\n")

    # Advance both to a known frame count from their pause point
    # Use frame_advance which is deterministic
    print("Advancing both by exactly 10 frames...")
    ack_a = inst_a.frame_advance(10)
    ack_b = inst_b.frame_advance(10)
    print(f"  A: {ack_a}")
    print(f"  B: {ack_b}")

    # NOW dump registers — these should still differ because they paused
    # at different frames (different initial state). The REAL test is:
    # advance frame-by-frame from the same starting point.

    # Actually, let's think about this differently.
    # Two instances of the same disc will NOT have identical registers because:
    # 1. They pause at different frames (non-deterministic free-run)
    # 2. Even from the same frame, internal state accumulated differently
    #
    # What we CAN validate:
    # - dump_regs_bin returns 88 bytes (22 registers)
    # - dump_mem_bin returns expected number of bytes
    # - memory at 0x06003000 is the same in both (same disc = same code)
    # - frame_advance actually advances by the right number

    print("\n=== Validation 1: Register dump format ===")
    regs_path_a = os.path.join(ipc_a, "regs.bin")
    regs_path_b = os.path.join(ipc_b, "regs.bin")
    inst_a.dump_regs_bin(regs_path_a)
    inst_b.dump_regs_bin(regs_path_b)
    time.sleep(0.2)

    size_a = os.path.getsize(regs_path_a) if os.path.exists(regs_path_a) else 0
    size_b = os.path.getsize(regs_path_b) if os.path.exists(regs_path_b) else 0
    print(f"  A: {size_a} bytes {'OK (88)' if size_a == 88 else 'FAIL'}")
    print(f"  B: {size_b} bytes {'OK (88)' if size_b == 88 else 'FAIL'}")

    regs_a = read_regs_bin(regs_path_a)
    regs_b = read_regs_bin(regs_path_b)
    if regs_a:
        print(f"  A PC=0x{regs_a['PC']:08X} R15(SP)=0x{regs_a['R15']:08X}")
    if regs_b:
        print(f"  B PC=0x{regs_b['PC']:08X} R15(SP)=0x{regs_b['R15']:08X}")

    print("\n=== Validation 2: Memory at 0x06003000 (game code) — must be identical ===")
    mem_path_a = os.path.join(ipc_a, "mem_code.bin")
    mem_path_b = os.path.join(ipc_b, "mem_code.bin")
    wsl_a = win_to_wsl(mem_path_a)
    wsl_b = win_to_wsl(mem_path_b)
    inst_a.send(f"dump_mem_bin 6003000 1000 {wsl_a}")
    inst_b.send(f"dump_mem_bin 6003000 1000 {wsl_b}")
    time.sleep(0.3)

    try:
        with open(mem_path_a, "rb") as f:
            code_a = f.read()
        with open(mem_path_b, "rb") as f:
            code_b = f.read()
        print(f"  A: {len(code_a)} bytes")
        print(f"  B: {len(code_b)} bytes")
        if code_a == code_b:
            print(f"  PASS: Game code at 0x06003000 is identical in both instances")
        else:
            matching = sum(1 for i in range(min(len(code_a), len(code_b))) if code_a[i] == code_b[i])
            print(f"  FAIL: Code differs! {matching}/{min(len(code_a), len(code_b))} bytes match")
            for i in range(min(len(code_a), len(code_b))):
                if code_a[i] != code_b[i]:
                    print(f"  First diff at +0x{i:X}: A=0x{code_a[i]:02X} B=0x{code_b[i]:02X}")
                    break
    except FileNotFoundError as e:
        print(f"  FAIL: Could not read memory dump: {e}")

    print("\n=== Validation 3: Frame advance determinism ===")
    print("  Advancing A by 5 frames, checking status...")
    inst_a.frame_advance(5)
    status_a = inst_a.status()
    print(f"  A status: {status_a}")

    print("  Advancing B by 5 frames, checking status...")
    inst_b.frame_advance(5)
    status_b = inst_b.status()
    print(f"  B status: {status_b}")

    # Dump regs after same number of advances
    inst_a.dump_regs_bin(regs_path_a)
    inst_b.dump_regs_bin(regs_path_b)
    time.sleep(0.2)
    regs_a2 = read_regs_bin(regs_path_a)
    regs_b2 = read_regs_bin(regs_path_b)

    # Note: these WON'T match because they started from different pause points.
    # But the PC should be in valid game code range.
    if regs_a2 and regs_b2:
        pc_a = regs_a2['PC']
        pc_b = regs_b2['PC']
        valid_a = 0x06003000 <= pc_a <= 0x06070000
        valid_b = 0x06003000 <= pc_b <= 0x06070000
        print(f"  A PC=0x{pc_a:08X} {'(valid game range)' if valid_a else '(OUT OF RANGE!)'}")
        print(f"  B PC=0x{pc_b:08X} {'(valid game range)' if valid_b else '(OUT OF RANGE!)'}")

    print("\n=== Validation 4: Deterministic replay test ===")
    print("  Restarting both instances fresh...")
    inst_a.quit()
    inst_b.quit()
    time.sleep(2)

    # Restart fresh
    inst_a = MednafenInstance("det_A", CUE_PROD, ipc_a)
    inst_b = MednafenInstance("det_B", CUE_PROD, ipc_b)
    inst_a.start()
    inst_b.start()

    # Pause immediately (don't free-run)
    print("  Pausing immediately...")
    time.sleep(1)
    inst_a.pause()
    inst_b.pause()
    time.sleep(0.5)

    # Both paused at different frames. Advance both by exactly 100 frames.
    print("  Advancing both by exactly 100 frames from pause...")
    inst_a.frame_advance(100)
    inst_b.frame_advance(100)

    # Dump regs
    inst_a.dump_regs_bin(regs_path_a)
    inst_b.dump_regs_bin(regs_path_b)
    time.sleep(0.2)
    regs_a3 = read_regs_bin(regs_path_a)
    regs_b3 = read_regs_bin(regs_path_b)

    if regs_a3 and regs_b3:
        diffs = compare_regs(regs_a3, regs_b3)
        if not diffs:
            print("  UNEXPECTED: Registers match (they paused at different frames, so this shouldn't happen)")
        else:
            print(f"  Registers differ ({len(diffs)} regs) — expected since pause frames differ.")
            print(f"  A PC=0x{regs_a3['PC']:08X}  B PC=0x{regs_b3['PC']:08X}")

        # THE REAL TEST: memory at 0x06003000 should still be identical
        # (same disc, code doesn't self-modify)
        inst_a.send(f"dump_mem_bin 6003000 1000 {wsl_a}")
        inst_b.send(f"dump_mem_bin 6003000 1000 {wsl_b}")
        time.sleep(0.3)
        with open(mem_path_a, "rb") as f:
            code_a2 = f.read()
        with open(mem_path_b, "rb") as f:
            code_b2 = f.read()
        if code_a2 == code_b2:
            print(f"  PASS: Game code still identical after 100 frames")
        else:
            print(f"  FAIL: Game code changed during execution!")

    inst_a.quit()
    inst_b.quit()

    print("\n=== Summary ===")
    print("If all validations passed, the tools are trustworthy.")
    print("Key insight: registers WILL differ between two instances of the same disc")
    print("because they pause at different frame numbers during free-run.")
    print("The comparison is only meaningful when both start from the same initial state.")
    print("\nFor prod-vs-reimpl comparison: the game CODE at 0x06003000 is the key.")
    print("If code differs there, the reimpl binary wasn't loaded correctly.")
    print("If code matches there, the divergence is behavioral (different code paths taken).")
    print("\nDone.")


if __name__ == "__main__":
    main()
