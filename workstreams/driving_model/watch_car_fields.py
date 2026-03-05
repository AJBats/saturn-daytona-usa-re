#!/usr/bin/env python3
"""Watch car struct fields during racing to validate theories.

Boots to race via menu navigation, sets watchpoints on key car struct
fields, advances frames, and reports who writes what.

Usage:
    python workstreams/driving_model/watch_car_fields.py [-v] [--field OFFSET]
"""

import os
import sys
import time
import argparse

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(PROJECT, "tools"))

from test_boot_auto import MednafenBot, wsl_path

CAR_BASE = 0x06078900   # Player car (index 0)
CAR_STRIDE = 0x268

# Fields to investigate — offset within car struct
FIELDS = {
    "speed":   0x0C,
    "vel_x":   0x10,
    "vel_y":   0x14,
    "vel_z":   0x18,
    "heading": 0x20,
    "slip":    0x28,
    "gear_timer": 0xB8,
    "gear_dir": 0x1DC,
    "track_idx": 0x1E4,
    "seg_vel":  0x228,
}


def wait_for_any(bot, keywords, timeout=30):
    """Wait for ack containing any of the given keywords."""
    deadline = time.time() + timeout
    last_content = None
    while time.time() < deadline:
        if bot.proc and bot.proc.poll() is not None:
            return None, None
        if os.path.exists(bot.ack_file):
            try:
                with open(bot.ack_file) as f:
                    content = f.read().strip()
            except (IOError, PermissionError):
                time.sleep(0.05)
                continue
            if content != last_content:
                last_content = content
                if bot.verbose:
                    print(f"  [ack] {content[:120]}")
            if content != bot.last_ack:
                for kw in keywords:
                    if kw in content:
                        bot.last_ack = content
                        return kw, content
        time.sleep(0.05)
    return None, None


def navigate_to_race(bot):
    """Navigate from boot to rolling start (frame ~4200)."""
    nav_trace = [
        (162,  "input START"),
        (167,  "input_release START"),
        (1174, "input START"),
        (1180, "input_release START"),
        (1360, "input START"),
        (1365, "input_release START"),
        (1510, "input C"),         # Select arcade mode
        (1515, "input_release C"),
        (1700, "input C"),         # Confirm circuit
        (1705, "input_release C"),
        (1900, "input START"),     # Skip car select
        (1905, "input_release START"),
    ]

    current_frame = 0
    for target_frame, action in nav_trace:
        delta = target_frame - current_frame
        if delta > 0:
            ack = bot.send_and_wait(
                f"frame_advance {delta}", "done frame_advance", timeout=180,
            )
            if not ack:
                print(f"FAIL: frame_advance to {target_frame} timed out")
                return -1
            current_frame = target_frame
        parts = action.split()
        if parts[0] == "input":
            bot.send_and_wait(f"input {parts[1]}", "ok input")
        elif parts[0] == "input_release":
            bot.send_and_wait(f"input_release {parts[1]}", "ok input_release")

    # Advance to rolling start
    print("Advancing to rolling start (frame 4200)...")
    ack = bot.send_and_wait(
        f"frame_advance {4200 - current_frame}", "done frame_advance", timeout=180,
    )
    if not ack:
        print("FAIL: could not reach rolling start")
        return -1
    return 4200


def run_watchpoint_test(field_name, field_offset, verbose=False, watch_frames=60):
    """Set a watchpoint on a car struct field and advance frames."""
    cue_win = os.path.join(
        PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue"
    )
    cue_wsl = wsl_path(cue_win)
    ipc_dir = os.path.join(PROJECT, "build", "watch_ipc")
    os.makedirs(ipc_dir, exist_ok=True)

    # Clean old watchpoint log
    wp_log = os.path.join(ipc_dir, "watchpoint_hits.txt")
    if os.path.exists(wp_log):
        os.remove(wp_log)

    bot = MednafenBot(ipc_dir, cue_wsl, verbose=verbose)

    print("Launching Mednafen...")
    if not bot.start(timeout=45):
        print("FAIL: Mednafen did not start")
        return False

    current_frame = navigate_to_race(bot)
    if current_frame < 0:
        bot.quit()
        return False

    # Calculate address
    addr = CAR_BASE + field_offset
    print(f"\nSetting watchpoint on car[+0x{field_offset:02X}] ({field_name}) at 0x{addr:08X}")
    ack = bot.send_and_wait(f"watchpoint {addr:08X}", "ok watchpoint", timeout=10)
    if not ack:
        print("FAIL: could not set watchpoint")
        bot.quit()
        return False
    print(f"  {ack}")

    # Advance frames — watchpoint will log every write
    print(f"Advancing {watch_frames} frames with watchpoint active...")
    for i in range(watch_frames):
        bot.send(f"frame_advance 1")
        kw, content = wait_for_any(bot, ["hit watchpoint", "done frame_advance"], timeout=10)
        if kw is None:
            print(f"  Frame {i}: timeout")
            break
        elif "hit watchpoint" in (kw or ""):
            if verbose:
                print(f"  Frame {i}: {content}")
            # Continue after watchpoint hit
            bot.send_and_wait("run", "done frame_advance", timeout=10)

    # Clear watchpoint
    bot.send_and_wait("watchpoint_clear", "ok watchpoint_clear", timeout=5)

    # Read and display the log
    print(f"\n{'='*60}")
    print(f"Watchpoint results for car[+0x{field_offset:02X}] ({field_name})")
    print(f"{'='*60}")

    if os.path.exists(wp_log):
        with open(wp_log) as f:
            lines = f.readlines()
        print(f"Total hits: {len([l for l in lines if 'hit watchpoint' in l])}")
        # Show unique PCs
        pcs = {}
        values = []
        for line in lines:
            if "hit watchpoint" in line:
                parts = line.strip().split()
                pc_str = [p for p in parts if p.startswith("pc=")]
                old_str = [p for p in parts if p.startswith("old=")]
                new_str = [p for p in parts if p.startswith("new=")]
                if pc_str:
                    pc = pc_str[0].split("=")[1]
                    pcs[pc] = pcs.get(pc, 0) + 1
                if new_str:
                    values.append(new_str[0].split("=")[1])

        print(f"\nWriter PCs (who writes this field):")
        for pc, count in sorted(pcs.items(), key=lambda x: -x[1]):
            print(f"  {pc}: {count} writes")

        if values:
            print(f"\nValue samples (first 10):")
            for v in values[:10]:
                int_val = int(v, 16) if v.startswith("0x") else int(v, 16)
                print(f"  {v} (decimal: {int_val})")

            print(f"\nValue range: {values[0]} .. {values[-1]}")
    else:
        print("No watchpoint hits recorded!")

    bot.quit()
    return True


def main():
    parser = argparse.ArgumentParser(description="Watch car struct fields")
    parser.add_argument("-v", "--verbose", action="store_true")
    parser.add_argument("--field", default="speed",
                       choices=list(FIELDS.keys()),
                       help="Which field to watch (default: speed)")
    parser.add_argument("--frames", type=int, default=60,
                       help="Number of frames to watch (default: 60)")
    args = parser.parse_args()

    offset = FIELDS[args.field]
    run_watchpoint_test(args.field, offset, verbose=args.verbose,
                       watch_frames=args.frames)


if __name__ == "__main__":
    main()
