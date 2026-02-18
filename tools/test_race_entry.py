#!/usr/bin/env python3
"""test_race_entry.py -- Navigate into a race and monitor state machine.

Extended menu navigation to reach actual racing gameplay.
The state machine sequence observed so far:
  3 (attract) -> START -> 5 (mode/course select) -> ... -> 1 (init?) -> 2 (setup?)

This script tries to get through the full sequence to see if the game
can enter a race, monitoring all state transitions.
"""
import os, sys, time, struct

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin, win_to_wsl, TMPDIR

CUE_REIMPL = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")

ADDR_PROD = {"state": 0x0605AD10}
ADDR_REIMPL = {"state": 0x0605AD00}


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


def press(inst, button, hold=10, wait=60):
    try:
        inst.send(f"input {button}")
    except TimeoutError:
        pass
    try:
        inst.frame_advance(hold)
    except TimeoutError:
        pass
    try:
        inst.send(f"input_release {button}")
    except TimeoutError:
        pass
    try:
        inst.frame_advance(wait)
    except TimeoutError:
        pass


def monitor_state(inst, ipc, state_addr, frames, chunk=60, tag="m"):
    """Advance frames in chunks, logging every state change."""
    states = []
    total = 0
    while total < frames:
        advance = min(chunk, frames - total)
        try:
            inst.frame_advance(advance)
        except TimeoutError:
            pass
        total += advance
        inst.pause()
        s = read_u32(inst, ipc, state_addr, f"{tag}_{total}")
        states.append((total, s))
        if len(states) >= 2 and states[-1][1] != states[-2][1]:
            print(f"      Frame +{total}: state changed to {s}")
    return states


def test_race_entry(label, cue, addrs, ipc_name):
    print(f"\n{'='*60}")
    print(f"  {label}")
    print(f"{'='*60}")

    ipc = os.path.join(TMPDIR, ipc_name)
    inst = MednafenInstance(ipc_name, cue, ipc)
    inst.start()

    state_addr = addrs["state"]
    all_states = []

    # Boot
    print(f"\n  [1] Booting (1500 frames)...")
    try:
        inst.frame_advance(1500)
    except TimeoutError:
        pass
    inst.pause()
    state = read_u32(inst, ipc, state_addr, "gs0")
    print(f"      State: {state}")
    all_states.append(("boot @1500", state))

    if state != 3:
        # Wait more
        for i in range(4):
            try:
                inst.frame_advance(500)
            except TimeoutError:
                pass
            inst.pause()
            state = read_u32(inst, ipc, state_addr, f"wait{i}")
            if state == 3:
                break
        if state != 3:
            print(f"      Failed to reach attract (state={state})")
            inst.quit()
            time.sleep(1)
            MednafenInstance.kill_stale()
            return all_states

    # START
    print(f"\n  [2] START -> mode select...")
    press(inst, "START", hold=10, wait=120)
    inst.pause()
    state = read_u32(inst, ipc, state_addr, "gs_start")
    print(f"      State: {state}")
    all_states.append(("START", state))

    # Now in state 5 (mode/course select menu).
    # The game has multiple sub-selections in state 5.
    # Let's press A repeatedly with longer waits to go through them.
    for i in range(6):
        print(f"\n  [{i+3}] Pressing A (selection {i+1})...")
        press(inst, "A", hold=10, wait=120)
        inst.pause()
        state = read_u32(inst, ipc, state_addr, f"gs_a{i}")
        print(f"      State: {state}")
        all_states.append((f"A press {i+1}", state))

        regs = dump_regs(inst, ipc)
        if regs:
            print(f"      PC: 0x{regs['PC']:08X}")

        # If state changed from 5, we might be transitioning to race
        if state != 5:
            print(f"      State changed from 5! Monitoring...")
            states = monitor_state(inst, ipc, state_addr, 600, chunk=60, tag=f"post_a{i}")
            for frame, s in states:
                if s != state:
                    print(f"      Frame +{frame}: state={s}")
                    state = s
            all_states.append((f"  monitor after A{i+1}", state))

    # Let game run for 1200 more frames to see if race starts
    print(f"\n  [9] Running 1200 more frames (20 sec)...")
    states = monitor_state(inst, ipc, state_addr, 1200, chunk=120, tag="race")
    last_state = states[-1][1] if states else None
    all_states.append(("after 1200 frames", last_state))

    # Final summary
    print(f"\n  FULL STATE LOG:")
    for action, s in all_states:
        print(f"    {action:30s} -> state {s}")

    # Dump final PC
    regs = dump_regs(inst, ipc)
    if regs:
        print(f"\n  Final PC: 0x{regs['PC']:08X}")

    inst.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()
    time.sleep(0.5)
    return all_states


def main():
    MednafenInstance.kill_stale()
    time.sleep(1)

    print("=" * 60)
    print("  RACE ENTRY TEST")
    print("=" * 60)

    prod_log = test_race_entry("PRODUCTION", CUE_PROD, ADDR_PROD, "race_prod")
    reimpl_log = test_race_entry("REIMPL (free-layout)", CUE_REIMPL, ADDR_REIMPL, "race_reimpl")

    # Compare
    print(f"\n{'='*60}")
    print(f"  COMPARISON")
    print(f"{'='*60}")

    max_len = max(len(prod_log), len(reimpl_log))
    for i in range(max_len):
        p = prod_log[i] if i < len(prod_log) else ("—", "—")
        r = reimpl_log[i] if i < len(reimpl_log) else ("—", "—")
        match = "YES" if p[1] == r[1] else "NO"
        print(f"  {p[0]:30s}  prod={str(p[1]):>4s}  reimpl={str(r[1]):>4s}  {match}")

    print(f"\n{'='*60}")
    print(f"  DONE")
    print(f"{'='*60}")


if __name__ == "__main__":
    main()
