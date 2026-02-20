#!/usr/bin/env python3
"""icf_trace.py -- Capture Address Error trace from Mednafen stderr.

Runs the free-layout disc (no ICF bypass), advances past the crash point,
and captures stderr for Address Error trace messages from the instrumented
Mednafen build.

Our fprintf() calls in sh7095.inc and sh7095_ops.inc produce:
  [SH2-ADDRERR] Slave: Misaligned N-byte READ/WRITE from/to 0xADDR, PC=0xPC
  [SH2-ADDRERR] Slave: Odd PC after Branch/DelayBranch: PC=0xPC
  [SH2-EXCEPT] Slave: CPU Address Error! PC=0xPC ...
"""

import os
import sys
import time
import subprocess

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJ, "tools"))

from parallel_compare import MednafenInstance, win_to_wsl, TMPDIR

CUE_FREE = os.path.join(PROJ, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")


def main():
    os.makedirs(TMPDIR, exist_ok=True)
    MednafenInstance.kill_stale()

    ipc_dir = os.path.join(TMPDIR, "icf_trace")
    inst = MednafenInstance("free", CUE_FREE, ipc_dir)

    print("Starting Mednafen with free-layout disc (no ICF bypass)...")
    inst.start()
    print("Ready.")

    # Advance in chunks, letting stderr accumulate
    print("\nAdvancing 1300 frames (past ICF crash point)...")
    try:
        ack = inst.frame_advance(1300)
        print(f"  Done: {ack}")
    except TimeoutError:
        print("  TIMEOUT (expected if game hangs)")

    # Check slave state
    try:
        ack = inst.send("dump_slave_regs")
        print(f"\n  Slave regs: {ack}")
    except:
        print("  (could not dump slave regs)")

    # Shutdown
    print("\nShutting down...")
    try:
        inst.send("quit")
    except:
        pass
    time.sleep(2)

    # Read stderr from the process
    stderr_data = b""
    if inst.process:
        try:
            inst.process.wait(timeout=5)
        except:
            inst.process.kill()
            inst.process.wait()
        stderr_data = inst.process.stderr.read()

    # Filter for our trace messages
    trace_lines = []
    all_lines = stderr_data.decode("utf-8", errors="replace").splitlines()
    for line in all_lines:
        if "SH2-ADDRERR" in line or "SH2-EXCEPT" in line or "SH2-EXCEPTION" in line:
            trace_lines.append(line)

    print(f"\n{'=' * 60}")
    print(f"Address Error trace messages ({len(trace_lines)} found):")
    print(f"{'=' * 60}")
    for line in trace_lines[:100]:  # Show first 100
        print(f"  {line}")
    if len(trace_lines) > 100:
        print(f"  ... ({len(trace_lines) - 100} more)")

    # Also save all stderr to file
    stderr_file = os.path.join(TMPDIR, "icf_trace_stderr.txt")
    with open(stderr_file, "w") as f:
        f.write(stderr_data.decode("utf-8", errors="replace"))
    print(f"\n  Full stderr ({len(all_lines)} lines) saved to: {stderr_file}")

    # Save trace lines separately
    trace_file = os.path.join(TMPDIR, "icf_trace_lines.txt")
    with open(trace_file, "w") as f:
        for line in trace_lines:
            f.write(line + "\n")
    print(f"  Trace lines saved to: {trace_file}")

    print("\nDone.")


if __name__ == "__main__":
    main()
