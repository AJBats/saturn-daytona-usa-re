#!/usr/bin/env python3
"""test_start_response.py -- Test START button in production and reimpl.

Uses CORRECT shifted addresses for reimpl build:
  - Game state: 0x0605AD10 (prod) / 0x0605AD00 (reimpl, -0x10 shift)
  - Input state: 0x0605B6D8 (prod) / 0x0605B6C8 (reimpl, -0x10 shift)
"""
import os, sys, time, struct

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin, win_to_wsl, TMPDIR

CUE_REIMPL = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")


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


def test_start(label, cue, state_addr, input_addr, ipc_name):
    print(f"\n{'='*60}")
    print(f"  {label}")
    print(f"  Game state addr: 0x{state_addr:08X}")
    print(f"  Input state addr: 0x{input_addr:08X}")
    print(f"{'='*60}")

    ipc = os.path.join(TMPDIR, ipc_name)
    inst = MednafenInstance(ipc_name, cue, ipc)
    inst.start()

    # Phase 1: Boot to attract mode
    print(f"\n  [1] Advancing 1500 frames (~25 seconds)...")
    try:
        inst.frame_advance(1500)
    except TimeoutError:
        print(f"      TIMEOUT")

    inst.pause()
    state = read_u32(inst, ipc, state_addr, "gs1")
    inp = read_u32(inst, ipc, input_addr, "inp1")
    regs = dump_regs(inst, ipc)
    pc = regs['PC'] if regs else 0
    print(f"      Game state: {state}")
    print(f"      Input: 0x{inp:08X}" if inp else "      Input: None")
    print(f"      PC: 0x{pc:08X}")

    if state is None or state > 100:
        print(f"      Game state not valid — cannot test START")
        inst.quit()
        time.sleep(1)
        MednafenInstance.kill_stale()
        return

    # Phase 2: Wait for attract mode (state 3)
    print(f"\n  [2] Waiting for state 3 (attract mode)...")
    for extra in [500, 500, 500, 500]:
        if state == 3:
            break
        try:
            inst.frame_advance(extra)
        except TimeoutError:
            pass
        inst.pause()
        state = read_u32(inst, ipc, state_addr, "gs_wait")
        print(f"      state={state}")

    if state != 3:
        print(f"      Never reached state 3 (got {state})")
        inst.quit()
        time.sleep(1)
        MednafenInstance.kill_stale()
        return

    print(f"      In attract mode (state 3)")

    # Phase 3: Press START
    print(f"\n  [3] Pressing START button...")
    try:
        ack = inst.send("input START")
        print(f"      Input ack: {ack}")
    except TimeoutError:
        print(f"      Input timeout")

    # Hold START for 10 frames
    try:
        inst.frame_advance(10)
    except TimeoutError:
        pass
    inst.pause()
    state_during = read_u32(inst, ipc, state_addr, "gs_during")
    inp_during = read_u32(inst, ipc, input_addr, "inp_during")
    print(f"      State during: {state_during}")
    print(f"      Input during: 0x{inp_during:08X}" if inp_during else "      Input during: None")

    # Release START
    try:
        inst.send("input_release START")
    except TimeoutError:
        pass

    # Phase 4: Monitor state transitions after release
    print(f"\n  [4] Monitoring state after START release...")
    states_after = []
    for chunk in [30, 30, 30, 30]:
        try:
            inst.frame_advance(chunk)
        except TimeoutError:
            pass
        inst.pause()
        s = read_u32(inst, ipc, state_addr, f"gs_after_{len(states_after)}")
        states_after.append(s)
        print(f"      +{sum([30]*len(states_after))} frames: state={s}")

    # Phase 5: Take screenshot
    ss_dir = os.path.join(PROJDIR, "build", "screenshots")
    os.makedirs(ss_dir, exist_ok=True)
    ss_path = os.path.join(ss_dir, f"{ipc_name}_after_start.png")
    wsl_ss = win_to_wsl(ss_path)
    try:
        inst.send(f"screenshot {wsl_ss}")
        print(f"\n  [5] Screenshot saved: {ss_path}")
    except TimeoutError:
        pass

    # Summary
    print(f"\n  SUMMARY:")
    print(f"    State before START: {state}")
    print(f"    State during START: {state_during}")
    print(f"    States after release: {states_after}")

    new_states = set(states_after) - {state}
    if new_states:
        print(f"    ==> State changed! New states: {new_states}")
    else:
        print(f"    ==> No state change after START")

    inst.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()
    time.sleep(0.5)


def main():
    MednafenInstance.kill_stale()
    time.sleep(1)

    print("=" * 60)
    print("  START BUTTON RESPONSE TEST")
    print("=" * 60)

    # Production (original addresses)
    test_start("PRODUCTION", CUE_PROD,
               state_addr=0x0605AD10, input_addr=0x0605B6D8,
               ipc_name="start_prod")

    # Reimpl (shifted addresses: -0x10)
    test_start("REIMPL (free-layout)", CUE_REIMPL,
               state_addr=0x0605AD00, input_addr=0x0605B6C8,
               ipc_name="start_reimpl")

    print(f"\n{'='*60}")
    print(f"  DONE")
    print(f"{'='*60}")


if __name__ == "__main__":
    main()
