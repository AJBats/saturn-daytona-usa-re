#!/usr/bin/env python3
"""diag_game_state.py - Monitor game state variable and demo timer.

Watches:
  - 0x0605AD10: game_state (32-bit, index into 32-entry jump table)
  - 0x0607EBCC: demo_timer (32-bit, counts down each frame in state 3)
  - 0x0607EAD8: attract_round (32-bit, incremented on timer expiry)

Runs both production and reimpl builds, comparing state evolution.
"""

import os, sys, time, struct, re

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin

CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")
CUE_REIMPL = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
TMPDIR = os.path.join(PROJDIR, ".tmp")

# Memory addresses to monitor
GAME_STATE   = 0x0605AD10  # 32-bit state index (0-31)
DEMO_TIMER   = 0x0607EBCC  # 32-bit countdown timer
ATTRACT_ROUND = 0x0607EAD8  # 32-bit attract mode round

STATE_NAMES = {
    0: "startup", 1: "transition", 2: "attract_setup", 3: "title_demo",
    4: "mode_select", 5: "course_select", 6: "trans_6", 7: "trans_7",
    8: "trans_8", 9: "trans_9", 10: "trans_10", 11: "trans_11",
    12: "pre_race", 13: "countdown", 14: "first_frame", 15: "main_race",
    16: "lap_trans", 17: "in_race_17", 18: "time_ext", 19: "in_race_19",
    20: "race_end", 21: "results", 22: "game_over", 23: "post_23",
    24: "post_24", 25: "post_25", 26: "post_26", 27: "post_27",
    28: "post_28", 29: "post_29", 30: "service", 31: "diag",
}


def parse_frame(ack):
    m = re.search(r'frame=(\d+)', ack)
    return int(m.group(1)) if m else None


def read_mem_word(inst, ipc_dir, addr, tag):
    """Read a 32-bit big-endian word from Saturn memory."""
    path = os.path.join(ipc_dir, f"mem_{tag}.bin")
    inst.dump_mem_bin(addr, 4, path)
    time.sleep(0.2)
    try:
        with open(path, "rb") as f:
            data = f.read(4)
        if len(data) == 4:
            return struct.unpack(">I", data)[0]
    except:
        pass
    return None


def monitor_build(name, cue, ipc_name, state_addr=GAME_STATE):
    MednafenInstance.kill_stale()
    ipc = os.path.join(TMPDIR, ipc_name)
    inst = MednafenInstance(name, cue, ipc)
    inst.start()

    print(f"\n{'='*70}")
    print(f"  {name}")
    print(f"{'='*70}")

    # Wait for main_loop
    inst.breakpoint(0x0600300A)
    try:
        ack = inst.continue_exec()
        base_frame = parse_frame(ack)
        print(f"  main_loop reached at frame {base_frame}")
    except TimeoutError:
        print(f"  TIMEOUT waiting for main_loop!")
        inst.quit(); MednafenInstance.kill_stale(); return
    inst.breakpoint_clear()

    # Monitor state and timer
    print(f"\n  {'Frame':>6s}  {'State':>5s}  {'Name':>15s}  {'Timer':>12s}  {'Round':>5s}  Notes")
    print(f"  {'-'*70}")

    prev_state = None
    prev_timer = None
    transitions = []

    for i in range(200):
        inst.frame_advance(5)

        state = read_mem_word(inst, ipc, state_addr, f"state_{i}")
        timer = read_mem_word(inst, ipc, DEMO_TIMER, f"timer_{i}")
        rnd = read_mem_word(inst, ipc, ATTRACT_ROUND, f"round_{i}")

        if state is None or timer is None:
            continue

        frame_approx = base_frame + (i + 1) * 5

        # Detect state transitions
        notes = ""
        if prev_state is not None and state != prev_state:
            notes = f"TRANSITION {prev_state}->{state}"
            transitions.append((frame_approx, prev_state, state))

        # Detect timer reset
        if prev_timer is not None and timer > prev_timer + 10:
            notes += f" TIMER_RESET(was {prev_timer})"

        # Convert timer to signed for display
        timer_signed = timer if timer < 0x80000000 else timer - 0x100000000

        state_name = STATE_NAMES.get(state, f"unk_{state}")

        # Print on transitions, first 20 samples, or every 50th
        if i < 20 or notes or i % 25 == 0:
            rnd_str = str(rnd) if rnd is not None else "?"
            print(f"  ~{frame_approx:5d}  {state:>5d}  {state_name:>15s}  {timer_signed:>12d}  {rnd_str:>5s}  {notes}")

        prev_state = state
        prev_timer = timer

    print(f"\n  State transitions detected: {len(transitions)}")
    for frame, old, new in transitions:
        print(f"    Frame ~{frame}: {STATE_NAMES.get(old, str(old))} -> {STATE_NAMES.get(new, str(new))}")

    inst.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()


def main():
    print("=" * 70)
    print("  Game State & Demo Timer Monitor")
    print("=" * 70)

    # Test production first
    print("\n>>> PRODUCTION <<<")
    monitor_build("PROD", CUE_PROD, "state_prod", state_addr=GAME_STATE)

    time.sleep(2)

    # Test reimpl - game state is at 0x0605AD0C in +4 build
    # (sym_0605AD10 is a text-section label shifted by the free layout)
    REIMPL_GAME_STATE = 0x0605AD0C
    print(f"\n>>> REIMPL (state_addr=0x{REIMPL_GAME_STATE:08X}) <<<")
    monitor_build("REIMPL", CUE_REIMPL, "state_reimpl", state_addr=REIMPL_GAME_STATE)


if __name__ == "__main__":
    main()
