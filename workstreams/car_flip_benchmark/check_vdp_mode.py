#!/usr/bin/env python3
"""Check FUN_06010D94 execution at car select.

Sets breakpoints at entry and past early-exit to verify if the function
executes during car select.
"""

import os
import sys
import time

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(PROJECT, "workstreams", "empirical_validation"))

from debugger_utils import DebugSession


def main():
    print("=== Check FUN_06010D94 execution at car select ===\n")

    s = DebugSession("car", verbose=True)

    # FUN_06010D94 is at 0x06010D94
    # Its early exit is at 0x06010DBC (checks sym_060788A0 >= 10)
    # Body starts at 0x06010DC0

    print("\n--- Setting breakpoint at FUN_06010D94 entry (06010D94) ---")
    s.bot.set_breakpoint("06010D94")

    print("Continuing execution...")
    ack = s.bot.continue_to_break(timeout=10)
    if ack:
        print(f"HIT! FUN_06010D94 IS called on primary SH-2")
        w = s.where()
        if w:
            print(f"  PC = 0x{w.get('pc', 0):08X} ({w.get('pc_sym', '?')})")
            print(f"  PR = 0x{w.get('pr', 0):08X} ({w.get('pr_sym', '?')})")
    else:
        print("NOT HIT within timeout. Function may not be called.")

    s.bot.clear_breakpoints()

    # Now check the body (past early exit)
    print("\n--- Setting breakpoint past early exit (06010DC0) ---")
    s.bot.set_breakpoint("06010DC0")

    print("Advancing 1 frame...")
    s.bot.send_and_wait("frame_advance 1", "done frame_advance", timeout=30)

    ack = s.bot.continue_to_break(timeout=10)
    if ack:
        print(f"HIT! FUN_06010D94 body EXECUTES (past early exit)")
        w = s.where()
        if w:
            print(f"  PC = 0x{w.get('pc', 0):08X} ({w.get('pc_sym', '?')})")
    else:
        print("NOT HIT. Early exit IS taken (sym_060788A0 >= 10).")

    s.bot.clear_breakpoints()

    # Also set BP at FUN_06026EDE/FUN_06026E94 call site to verify it's reached
    print("\n--- Setting breakpoint at FUN_06026EDE/x call (approx 06010DE0) ---")
    # The JSR @r3 for FUN_06026EDE is after loading .L_06010EB0
    # Let me set BP at the actual FUN_06026E94 function (06026E94)
    s.bot.set_breakpoint("06026E94")

    print("Advancing 1 frame...")
    s.bot.send_and_wait("frame_advance 1", "done frame_advance", timeout=30)

    ack = s.bot.continue_to_break(timeout=10)
    if ack:
        print(f"HIT! FUN_06026E94 IS called from primary SH-2")
        w = s.where()
        if w:
            print(f"  PC = 0x{w.get('pc', 0):08X} ({w.get('pc_sym', '?')})")
            print(f"  PR = 0x{w.get('pr', 0):08X} ({w.get('pr_sym', '?')})")
            print(f"  r4 = 0x{w.get('r4', 0):08X} (angle param)")
    else:
        print("NOT HIT. FUN_06026E94 is not called during car select.")

    s.bot.clear_breakpoints()
    s.quit()
    print("\nDone.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
