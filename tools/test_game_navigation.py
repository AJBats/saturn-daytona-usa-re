#!/usr/bin/env python3
"""test_game_navigation.py -- Navigate through game menus in both builds.

Tests the full menu sequence:
  1. Boot to attract mode (state 3)
  2. Press START -> mode select (state 5)
  3. Press A/START -> course select (state 6 or similar)
  4. Press A/START -> transmission select (state 7 or similar)
  5. Continue pressing to see how far we get

Both production and reimpl are tested with the same inputs.
"""
import os, sys, time, struct

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin, win_to_wsl, TMPDIR

CUE_REIMPL = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")

# Addresses (production vs reimpl shifted -0x10)
ADDR_PROD = {"state": 0x0605AD10, "input": 0x0605B6D8}
ADDR_REIMPL = {"state": 0x0605AD00, "input": 0x0605B6C8}


def dump_mem(inst, ipc_dir, addr, size, tag):
    path = os.path.join(ipc_dir, f"mem_{tag}.bin")
    wsl_path = win_to_wsl(path)
    inst.dump_mem_bin(addr, size, wsl_path)
    time.sleep(0.3)
    try:
        with open(path, "rb") as f:
            return f.read()
    except FileNotFoundError:
        return None


def dump_regs(inst, ipc_dir):
    path = os.path.join(ipc_dir, "regs.bin")
    inst.dump_regs_bin(path)
    time.sleep(0.2)
    return read_regs_bin(path)


def read_u32(inst, ipc_dir, addr, tag):
    data = dump_mem(inst, ipc_dir, addr, 4, tag)
    if data and len(data) >= 4:
        return struct.unpack(">I", data[:4])[0]
    return None


def press_button(inst, button, hold_frames=10, wait_frames=60):
    """Press button, hold, release, wait."""
    try:
        inst.send(f"input {button}")
    except TimeoutError:
        pass
    try:
        inst.frame_advance(hold_frames)
    except TimeoutError:
        pass
    try:
        inst.send(f"input_release {button}")
    except TimeoutError:
        pass
    try:
        inst.frame_advance(wait_frames)
    except TimeoutError:
        pass


def navigate_menus(label, cue, addrs, ipc_name):
    print(f"\n{'='*60}")
    print(f"  {label}")
    print(f"{'='*60}")

    ipc = os.path.join(TMPDIR, ipc_name)
    inst = MednafenInstance(ipc_name, cue, ipc)
    inst.start()

    state_addr = addrs["state"]
    state_log = []

    # Phase 1: Boot
    print(f"\n  [1] Booting (1500 frames)...")
    try:
        inst.frame_advance(1500)
    except TimeoutError:
        pass
    inst.pause()
    state = read_u32(inst, ipc, state_addr, "gs0")
    print(f"      State: {state}")
    state_log.append(("boot", state))

    if state is None or state > 100:
        print(f"      Invalid state - aborting")
        inst.quit()
        time.sleep(1)
        MednafenInstance.kill_stale()
        return state_log

    # Wait for state 3 if needed
    while state != 3:
        try:
            inst.frame_advance(500)
        except TimeoutError:
            break
        inst.pause()
        state = read_u32(inst, ipc, state_addr, "gs_wait")
        if state is None or state > 100:
            break
        print(f"      Waiting... state: {state}")

    if state != 3:
        print(f"      Never reached attract mode (state 3)")
        inst.quit()
        time.sleep(1)
        MednafenInstance.kill_stale()
        return state_log

    # Phase 2: START -> mode select
    print(f"\n  [2] Pressing START (mode select)...")
    press_button(inst, "START", hold_frames=10, wait_frames=120)
    inst.pause()
    state = read_u32(inst, ipc, state_addr, "gs_after_start")
    print(f"      State: {state}")
    state_log.append(("after START", state))

    regs = dump_regs(inst, ipc)
    if regs:
        print(f"      PC: 0x{regs['PC']:08X}")

    # Phase 3: Press A (or START) for arcade mode selection
    print(f"\n  [3] Pressing A (select arcade mode)...")
    press_button(inst, "A", hold_frames=10, wait_frames=120)
    inst.pause()
    state = read_u32(inst, ipc, state_addr, "gs_after_a1")
    print(f"      State: {state}")
    state_log.append(("after A (1)", state))

    regs = dump_regs(inst, ipc)
    if regs:
        print(f"      PC: 0x{regs['PC']:08X}")

    # Phase 4: Press A again (course select)
    print(f"\n  [4] Pressing A (course select)...")
    press_button(inst, "A", hold_frames=10, wait_frames=120)
    inst.pause()
    state = read_u32(inst, ipc, state_addr, "gs_after_a2")
    print(f"      State: {state}")
    state_log.append(("after A (2)", state))

    # Phase 5: Press A again (transmission select)
    print(f"\n  [5] Pressing A (transmission select)...")
    press_button(inst, "A", hold_frames=10, wait_frames=120)
    inst.pause()
    state = read_u32(inst, ipc, state_addr, "gs_after_a3")
    print(f"      State: {state}")
    state_log.append(("after A (3)", state))

    # Phase 6: Press A again (final confirm / race start)
    print(f"\n  [6] Pressing A (confirm)...")
    press_button(inst, "A", hold_frames=10, wait_frames=180)
    inst.pause()
    state = read_u32(inst, ipc, state_addr, "gs_after_a4")
    print(f"      State: {state}")
    state_log.append(("after A (4)", state))

    regs = dump_regs(inst, ipc)
    if regs:
        print(f"      PC: 0x{regs['PC']:08X}")

    # Phase 7: Let it run 300 more frames
    print(f"\n  [7] Running 300 more frames...")
    try:
        inst.frame_advance(300)
    except TimeoutError:
        pass
    inst.pause()
    state = read_u32(inst, ipc, state_addr, "gs_final")
    print(f"      State: {state}")
    state_log.append(("after 300 more frames", state))

    regs = dump_regs(inst, ipc)
    if regs:
        print(f"      PC: 0x{regs['PC']:08X}")

    # Summary
    print(f"\n  STATE LOG:")
    for action, s in state_log:
        print(f"    {action:25s} -> state {s}")

    inst.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()
    time.sleep(0.5)
    return state_log


def main():
    MednafenInstance.kill_stale()
    time.sleep(1)

    print("=" * 60)
    print("  GAME NAVIGATION TEST")
    print("=" * 60)

    prod_log = navigate_menus("PRODUCTION", CUE_PROD, ADDR_PROD, "nav_prod")
    reimpl_log = navigate_menus("REIMPL (free-layout)", CUE_REIMPL, ADDR_REIMPL, "nav_reimpl")

    # Compare
    print(f"\n{'='*60}")
    print(f"  COMPARISON")
    print(f"{'='*60}")

    max_len = max(len(prod_log), len(reimpl_log))
    print(f"  {'Action':25s} {'Production':>12s} {'Reimpl':>12s} {'Match':>6s}")
    print(f"  {'-'*25} {'-'*12} {'-'*12} {'-'*6}")
    for i in range(max_len):
        p_action = prod_log[i][0] if i < len(prod_log) else "—"
        p_state = prod_log[i][1] if i < len(prod_log) else "—"
        r_state = reimpl_log[i][1] if i < len(reimpl_log) else "—"
        match = "YES" if p_state == r_state else "NO"
        print(f"  {p_action:25s} {str(p_state):>12s} {str(r_state):>12s} {match:>6s}")

    print(f"\n{'='*60}")
    print(f"  DONE")
    print(f"{'='*60}")


if __name__ == "__main__":
    main()
