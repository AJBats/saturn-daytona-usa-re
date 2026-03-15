#!/usr/bin/env python3
"""Check if FUN_06010F04 hits early exit during car select.

Reads sym_060788A4 (the gate variable) at the car select screen to determine
whether FUN_06010F04 exits early (gate >= 10) or executes its body.
"""

import os
import sys
import struct
import time

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(PROJECT, "workstreams", "empirical_validation"))

from debugger_utils import DebugSession


def main():
    print("=== Checking FUN_06010F04 early exit gate ===\n")

    # Boot to car select state
    s = DebugSession("car", verbose=True)

    # Read sym_060788A4 (the gate variable)
    # This address is the same in retail and free builds (PROVIDE)
    mem_path = os.path.join(s.results_dir, "_gate_value.bin")
    s.bot.dump_mem_bin("060788A4", "4", mem_path)
    time.sleep(0.5)

    if os.path.exists(mem_path):
        data = open(mem_path, "rb").read()
        if len(data) >= 4:
            gate_val = struct.unpack(">I", data[:4])[0]
            print(f"\nsym_060788A4 = 0x{gate_val:08X} ({gate_val} decimal)")
            print(f"Early exit condition: gate >= 10 (0xA)")
            if gate_val >= 10:
                print(f">>> EARLY EXIT IS TAKEN! FUN_06010F04 skips its body!")
                print(f">>> This explains why ALL 6 experiments had zero effect.")
            else:
                print(f">>> Function body EXECUTES (gate < 10).")
                print(f">>> Need different explanation for zero-effect experiments.")
    else:
        print("FAIL: Could not read memory")

    # Also check sym_0607884C (loaded at function entry, stored to stack)
    mem2_path = os.path.join(s.results_dir, "_stack_var.bin")
    s.bot.dump_mem_bin("0607884C", "4", mem2_path)
    time.sleep(0.5)

    if os.path.exists(mem2_path):
        data = open(mem2_path, "rb").read()
        if len(data) >= 4:
            val = struct.unpack(">I", data[:4])[0]
            print(f"\nsym_0607884C = 0x{val:08X} ({val} decimal)")

    # Now set a breakpoint at the function entry to verify it's actually called
    print("\n=== Setting breakpoint at FUN_06010F04 (06010F04) ===")
    bp_result = s.bot.set_breakpoint("06010F04")
    print(f"Breakpoint set: {bp_result}")

    # Advance 1 frame — if BP hits, function is being called
    print("Advancing 1 frame...")
    ack = s.bot.continue_to_break(timeout=30)
    if ack:
        print(f"Breakpoint HIT! Function IS called during car select.")
        # Check registers — r2 should have sym_060788A4 value after the load
        w = s.where_str()
        print(f"Position: {w}")
    else:
        print("Breakpoint NOT hit within 1 frame (or continue timed out)")
        # The function may not be called, or the BP might have an issue

    s.bot.clear_breakpoints()

    # Now set BP at the body (past early exit): 0x06010F3C
    print("\n=== Setting breakpoint past early exit (06010F3C) ===")
    s.bot.set_breakpoint("06010F3C")
    print("Advancing 1 frame...")

    # Need to advance a frame first since we may be stopped at the entry BP
    s.bot.send_and_wait("frame_advance 1", "done frame_advance", timeout=30)
    ack = s.bot.continue_to_break(timeout=30)
    if ack:
        print(f"Body breakpoint HIT! Function body EXECUTES during car select.")
        w = s.where_str()
        print(f"Position: {w}")
    else:
        print("Body breakpoint NOT hit — function exits early (gate >= 10).")

    s.bot.clear_breakpoints()
    s.quit()
    print("\nDone.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
