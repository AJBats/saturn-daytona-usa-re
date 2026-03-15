#!/usr/bin/env python3
"""Check what secondary SH-2 callback is set during car select.

Reads sym_06063574 (the callback pointer that FUN_06034F08 calls)
to determine which function the secondary SH-2 executes.
"""

import os
import sys
import struct
import time

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(PROJECT, "workstreams", "empirical_validation"))

from debugger_utils import DebugSession
from investigate import load_symbols


def main():
    print("=== Checking secondary SH-2 callback at car select ===\n")

    addr_to_name, name_to_addr = load_symbols()

    s = DebugSession("car", verbose=True)

    # Read sym_06063574 (the secondary SH-2 callback)
    mem_path = os.path.join(s.results_dir, "_callback.bin")
    s.bot.dump_mem_bin("06063574", "4", mem_path)
    time.sleep(0.5)

    if os.path.exists(mem_path):
        data = open(mem_path, "rb").read()
        if len(data) >= 4:
            callback = struct.unpack(">I", data[:4])[0]
            sym_name = addr_to_name.get(callback, "UNKNOWN")
            print(f"\nsym_06063574 (secondary callback) = 0x{callback:08X}")
            print(f"  Symbol: {sym_name}")

            # Check if it's FUN_06010F04
            rpt_addr = name_to_addr.get("FUN_06010F04")
            if rpt_addr:
                print(f"\nrace_position_track is at: 0x{rpt_addr:08X}")
                if callback == rpt_addr:
                    print(">>> MATCH! Secondary SH-2 IS running FUN_06010F04")
                else:
                    print(">>> MISMATCH! Secondary SH-2 is running something ELSE")

    # Also check a few related variables
    for name, addr_str in [
        ("sym_060788A4 (gate)", "060788A4"),
        ("sym_060788A0", "060788A0"),
        ("sym_0607884C", "0607884C"),
        ("sym_06078850", "06078850"),
        ("sym_06078854", "06078854"),
        ("sym_06078858", "06078858"),
    ]:
        mp = os.path.join(s.results_dir, f"_var_{addr_str}.bin")
        s.bot.dump_mem_bin(addr_str, "4", mp)
        time.sleep(0.3)
        if os.path.exists(mp):
            data = open(mp, "rb").read()
            if len(data) >= 4:
                val = struct.unpack(">I", data[:4])[0]
                print(f"  {name} = 0x{val:08X} ({val})")

    # Check sym_0608A52C (used as display list pointer in FUN_06010F04)
    mp = os.path.join(s.results_dir, "_var_0608A52C.bin")
    s.bot.dump_mem_bin("0608A52C", "4", mp)
    time.sleep(0.3)
    if os.path.exists(mp):
        data = open(mp, "rb").read()
        if len(data) >= 4:
            val = struct.unpack(">I", data[:4])[0]
            print(f"  sym_0608A52C (display ptr) = 0x{val:08X}")

    s.quit()
    print("\nDone.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
