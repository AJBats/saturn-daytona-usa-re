#!/usr/bin/env python3
"""test_start_button.py -- Test START button response in reimpl build.

Boot the reimpl disc, wait for title screen, press START, check if game
transitions to mode select screen. Compare with production behavior.

Game state machine:
  State 3 (0x06008A18): Title/attract screen
  State 5 (0x06008D74): Input detection router (checks START)
  State 6 (0x06008B04): Course select initialization

Game state variable: 0x0605AD10 (32-bit)
Input state variable: 0x0605B6D8 (32-bit, active-HIGH button bits)
"""
import os, sys, time, re, struct

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin, win_to_wsl, TMPDIR

CUE_REIMPL = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")

# Key memory addresses
GAME_STATE_ADDR = 0x0605AD10
INPUT_STATE_ADDR = 0x0605B6D8

# Game state jump table at 0x0600307C (32 entries, 4 bytes each)
JUMP_TABLE_ADDR = 0x0600307C


def dump_regs(inst, ipc_dir):
    path = os.path.join(ipc_dir, "regs.bin")
    inst.dump_regs_bin(path)
    time.sleep(0.3)
    return read_regs_bin(path)


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


def read_u32(inst, ipc_dir, addr, tag):
    data = dump_mem(inst, ipc_dir, addr, 4, tag)
    if data and len(data) >= 4:
        return struct.unpack(">I", data[:4])[0]
    return None


def read_game_state(inst, ipc_dir):
    return read_u32(inst, ipc_dir, GAME_STATE_ADDR, "gamestate")


def read_input_state(inst, ipc_dir):
    return read_u32(inst, ipc_dir, INPUT_STATE_ADDR, "inputstate")


def test_build(label, cue, ipc_name, press_start=True):
    """Boot a build, advance to title screen, optionally press START, observe state transitions."""
    print(f"\n{'='*60}")
    print(f"  {label}")
    print(f"{'='*60}")

    ipc = os.path.join(TMPDIR, ipc_name)
    inst = MednafenInstance(ipc_name, cue, ipc)
    inst.start()

    # Phase 1: Advance 800 frames to get past BIOS + CD loading + init
    print(f"\n  [1] Advancing 800 frames to reach title screen...")
    try:
        ack = inst.frame_advance(800)
        print(f"      Done: {ack}")
    except TimeoutError:
        print(f"      TIMEOUT at 800 frames")

    # Check game state
    inst.pause()
    state = read_game_state(inst, ipc)
    regs = dump_regs(inst, ipc)
    if state is not None:
        print(f"      Game state: {state}")
    if regs:
        print(f"      PC=0x{regs['PC']:08X}")

    # Phase 2: Advance more to ensure we're past title screen init
    print(f"\n  [2] Advancing 400 more frames (stabilize)...")
    try:
        ack = inst.frame_advance(400)
        print(f"      Done: {ack}")
    except TimeoutError:
        print(f"      TIMEOUT")

    inst.pause()
    state = read_game_state(inst, ipc)
    inp = read_input_state(inst, ipc)
    print(f"      Game state: {state}")
    print(f"      Input state: 0x{inp:08X}" if inp is not None else "      Input state: None")

    if not press_start:
        # Just observe — take screenshot
        print(f"\n  [3] Observing without START press...")
        try:
            ack = inst.frame_advance(300)
        except TimeoutError:
            pass
        inst.pause()
        state = read_game_state(inst, ipc)
        print(f"      Game state: {state}")
        inst.quit()
        time.sleep(1)
        MednafenInstance.kill_stale()
        return

    # Phase 3: Press START button
    print(f"\n  [3] Pressing START button...")
    try:
        ack = inst.send("input START")
        print(f"      Input ack: {ack}")
    except TimeoutError:
        print(f"      Input ack timeout (non-fatal)")

    # Hold START for 10 frames
    try:
        ack = inst.frame_advance(10)
        print(f"      10 frames with START held: {ack}")
    except TimeoutError:
        print(f"      TIMEOUT")

    inst.pause()
    state_during = read_game_state(inst, ipc)
    inp_during = read_input_state(inst, ipc)
    print(f"      Game state (during press): {state_during}")
    print(f"      Input state: 0x{inp_during:08X}" if inp_during is not None else "      Input state: None")

    # Release START
    try:
        ack = inst.send("input_release START")
        print(f"      Release ack: {ack}")
    except TimeoutError:
        pass

    # Phase 4: Advance 120 frames to see if state transitions
    print(f"\n  [4] Advancing 120 frames after START release...")
    states_seen = []
    for chunk in range(4):  # 4 chunks of 30 frames
        try:
            ack = inst.frame_advance(30)
        except TimeoutError:
            pass
        inst.pause()
        s = read_game_state(inst, ipc)
        states_seen.append(s)
        print(f"      +{(chunk+1)*30} frames: state={s}")

    # Phase 5: Take screenshot for visual verification
    print(f"\n  [5] Taking screenshot...")
    ss_path = os.path.join(PROJDIR, "build", "screenshots", f"{ipc_name}_start.png")
    wsl_ss_path = win_to_wsl(ss_path)
    try:
        ack = inst.send(f"screenshot {wsl_ss_path}")
        print(f"      Screenshot ack: {ack}")
    except TimeoutError:
        print(f"      Screenshot timeout")

    # Phase 6: Read jump table to understand state machine
    print(f"\n  [6] Jump table entries (first 10 states)...")
    jtable = dump_mem(inst, ipc, JUMP_TABLE_ADDR, 40, "jtable")
    if jtable:
        for i in range(10):
            off = i * 4
            if off + 4 <= len(jtable):
                val = struct.unpack(">I", jtable[off:off+4])[0]
                marker = " <-- current" if i == (state_during or 0) else ""
                print(f"      State {i}: 0x{val:08X}{marker}")

    # Phase 7: Dump some key memory to understand game state
    print(f"\n  [7] Key memory regions...")
    # VDP2 TVMD - is display on?
    vdp2 = dump_mem(inst, ipc, 0x25F80000, 8, "vdp2")
    if vdp2:
        tvmd = struct.unpack(">H", vdp2[:2])[0]
        disp = (tvmd >> 15) & 1
        print(f"      VDP2 TVMD=0x{tvmd:04X} (DISP={disp})")

    # Game mode area
    mode_area = dump_mem(inst, ipc, GAME_STATE_ADDR, 32, "mode_area")
    if mode_area:
        print(f"      Game mode area (0x{GAME_STATE_ADDR:08X}):")
        for i in range(0, min(len(mode_area), 32), 4):
            val = struct.unpack(">I", mode_area[i:i+4])[0]
            print(f"        +0x{i:02X}: 0x{val:08X}")

    inst.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()
    time.sleep(0.5)

    # Summary
    print(f"\n  SUMMARY:")
    print(f"    State before START: {state}")
    print(f"    State during START: {state_during}")
    print(f"    States after release: {states_seen}")
    if state_during != state:
        print(f"    ==> STATE CHANGED on START press!")
    else:
        print(f"    ==> No state change on START press")

    unique_states = set(states_seen) - {state}
    if unique_states:
        print(f"    ==> New states reached: {unique_states}")
    else:
        print(f"    ==> No new states after release")


def main():
    MednafenInstance.kill_stale()
    time.sleep(1)

    os.makedirs(os.path.join(PROJDIR, "build", "screenshots"), exist_ok=True)

    print("=" * 60)
    print("  START BUTTON TEST")
    print("=" * 60)

    # Test 1: Production — press START
    test_build("PRODUCTION (with START)", CUE_PROD, "start_prod", press_start=True)

    # Test 2: Reimpl — press START
    test_build("REIMPL (with START)", CUE_REIMPL, "start_reimpl", press_start=True)

    # Test 3: Reimpl — no START (control)
    test_build("REIMPL (no START - control)", CUE_REIMPL, "start_control", press_start=False)

    print("\n" + "=" * 60)
    print("  DONE")
    print("=" * 60)


if __name__ == "__main__":
    main()
