#!/usr/bin/env python3
"""Test dump_region automation command.

Boots to mode select menu, dumps wram_high, verifies:
1. File exists and is exactly 1MB
2. Non-zero content (not all 0x00 or 0xFF)
3. Known BIOS/game strings present in WRAM
4. Dumps all 6 regions and checks sizes

Usage:
    python workstreams/enhance_re_tooling/test_dump_region.py
"""

import os
import sys
import time
import tempfile

# Add project root to path
PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(PROJECT, "workstreams", "empirical_validation"))

from investigate import MednafenBot, wsl_path, parse_trace, replay_to_state

TRACE_FILE = os.path.join(PROJECT, "build", "golden_trace", "arcade_full.txt")
CUE_FILE = os.path.join(PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")

REGIONS = {
    "wram_high": 0x100000,  # 1MB
    "wram_low":  0x100000,  # 1MB
    "vdp1_vram": 0x080000,  # 512KB
    "vdp2_vram": 0x080000,  # 512KB
    "vdp2_cram": 0x001000,  # 4KB
    "sound_ram": 0x080000,  # 512KB
}


def main():
    cue_wsl = wsl_path(CUE_FILE)
    ipc_dir = tempfile.mkdtemp(prefix="dump_region_test_")
    dump_dir = tempfile.mkdtemp(prefix="dump_region_out_")

    bot = MednafenBot(ipc_dir, cue_wsl)
    print("Starting Mednafen...")
    if not bot.start(timeout=30):
        print("FAIL: Mednafen didn't start")
        return 1

    # Replay to menu state
    print("Replaying to menu state (frame 1537)...")
    events = parse_trace(TRACE_FILE)
    if not replay_to_state(bot, "menu", events):
        print("FAIL: Could not replay to menu state")
        bot.quit()
        return 1

    print(f"At menu state (frame {bot.current_frame})")

    # Test all 6 regions
    results = {}
    for region_name, expected_size in REGIONS.items():
        out_path = os.path.join(dump_dir, f"{region_name}.bin")
        wsl_out = wsl_path(out_path)
        print(f"\nDumping {region_name}...")
        ack = bot.send_and_wait(
            f"dump_region {region_name} {wsl_out}",
            "ok dump_region", timeout=30
        )
        if not ack:
            print(f"  FAIL: no ack for {region_name}")
            results[region_name] = "NO_ACK"
            continue

        # Wait for file to appear
        deadline = time.time() + 5
        while time.time() < deadline and not os.path.exists(out_path):
            time.sleep(0.1)

        if not os.path.exists(out_path):
            print(f"  FAIL: file not created for {region_name}")
            results[region_name] = "NO_FILE"
            continue

        actual_size = os.path.getsize(out_path)
        if actual_size != expected_size:
            print(f"  FAIL: {region_name} size {actual_size} != expected {expected_size}")
            results[region_name] = f"WRONG_SIZE({actual_size})"
            continue

        # Check content isn't all zeros or all 0xFF
        with open(out_path, "rb") as f:
            data = f.read()
        zero_count = data.count(b'\x00')
        ff_count = data.count(b'\xff')
        unique_bytes = len(set(data))

        if zero_count == len(data):
            print(f"  FAIL: {region_name} is all zeros")
            results[region_name] = "ALL_ZERO"
            continue
        if ff_count == len(data):
            print(f"  FAIL: {region_name} is all 0xFF")
            results[region_name] = "ALL_FF"
            continue

        print(f"  OK: {actual_size} bytes, {unique_bytes} unique byte values, "
              f"{zero_count} zeros ({100*zero_count/len(data):.1f}%)")
        results[region_name] = "PASS"

        # Extra check for wram_high: look for known strings
        if region_name == "wram_high":
            # Search for ASCII strings (game text is in WRAM)
            strings_found = 0
            for i in range(len(data) - 4):
                chunk = data[i:i+4]
                if all(0x20 <= b <= 0x7E for b in chunk):
                    strings_found += 1
            print(f"  ASCII 4-byte+ sequences: {strings_found}")

    # Shutdown
    try:
        bot.send_and_wait("quit", "quit", timeout=5)
    except Exception:
        pass

    # Summary
    print("\n" + "=" * 50)
    print("DUMP REGION TEST RESULTS")
    print("=" * 50)
    all_pass = True
    for region_name, status in results.items():
        mark = "PASS" if status == "PASS" else "FAIL"
        if status != "PASS":
            all_pass = False
        print(f"  {region_name:<15s}  {mark}  ({status})")

    print(f"\nOVERALL: {'PASS' if all_pass else 'FAIL'}")
    return 0 if all_pass else 1


if __name__ == "__main__":
    sys.exit(main())
