#!/usr/bin/env python3
"""icf_trace.py — Run free-build disc headless, capture address error traces.

Uses Mednafen automation mode (hidden window) to boot the free-layout disc
and capture any CPU address error exceptions from stderr.
"""

import os
import sys
import time
import subprocess
import tempfile

PROJ = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CUE = os.path.join(PROJ, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
MEDNAFEN_WSL = "/mnt/d/Projects/SaturnReverseTest/mednafen/src/mednafen"

def wsl_path(win_path):
    """Convert Windows path to WSL path."""
    drive = win_path[0].lower()
    rest = win_path[2:].replace("\\", "/")
    return f"/mnt/{drive}{rest}"

def main():
    duration = int(sys.argv[1]) if len(sys.argv) > 1 else 30
    print(f"Running for {duration} seconds...")

    # Create IPC directory for automation
    ipc_dir = tempfile.mkdtemp(prefix="icf_trace_")
    ipc_dir_wsl = wsl_path(ipc_dir)
    cue_wsl = wsl_path(CUE)

    stderr_log = os.path.join(ipc_dir, "stderr.log")
    stderr_log_wsl = wsl_path(stderr_log)

    action_file = os.path.join(ipc_dir, "mednafen_action.txt")
    ack_file = os.path.join(ipc_dir, "mednafen_ack.txt")

    # Launch Mednafen in automation mode (starts paused, hidden window)
    home_wsl = "/tmp/icf_trace_home"
    launch_cmd = (
        f'export HOME="{home_wsl}" DISPLAY=:0; '
        f'mkdir -p "{home_wsl}/.mednafen"; '
        f'rm -f "{home_wsl}/.mednafen/mednafen.lck"; '
        f'"{MEDNAFEN_WSL}" '
        f'--sound 0 --automation "{ipc_dir_wsl}" "{cue_wsl}" '
        f'2>"{stderr_log_wsl}"'
    )

    print(f"Launching Mednafen (automation mode, hidden window)...")
    proc = subprocess.Popen(
        ["wsl", "-d", "Ubuntu", "-e", "bash", "-c", launch_cmd],
        stdout=subprocess.PIPE
    )

    # Wait for ready
    for i in range(30):
        time.sleep(0.5)
        if os.path.exists(ack_file):
            try:
                ack = open(ack_file).read().strip()
                if "ready" in ack:
                    print(f"Mednafen ready (attempt {i+1})")
                    break
            except:
                pass
    else:
        print("ERROR: Mednafen didn't become ready in 15 seconds")
        proc.terminate()
        return

    # Send "run" command to free-run
    seq = 1
    with open(action_file, "w", newline="\n") as f:
        f.write(f"# {seq}\n")
        f.write("run\n")

    print(f"Sent 'run' command. Emulating for {duration}s...")
    time.sleep(duration)

    # Send quit
    seq += 1
    try:
        os.remove(action_file)
    except:
        pass
    with open(action_file, "w", newline="\n") as f:
        f.write(f"# {seq}\n")
        f.write("quit\n")

    time.sleep(2)
    proc.terminate()

    # Read and analyze stderr
    print(f"\n=== Analyzing stderr log ===")
    if os.path.exists(stderr_log):
        with open(stderr_log, "r") as f:
            lines = f.readlines()

        print(f"Total lines: {len(lines)}")

        fti_lines = [l for l in lines if "FTI:" in l]
        addr_err_lines = [l for l in lines if "ADDR_ERR" in l]

        print(f"FTI triggers: {len(fti_lines)}")
        print(f"Address errors: {len(addr_err_lines)}")

        if fti_lines:
            print("\n--- FTI triggers ---")
            for l in fti_lines[:20]:
                print(l.rstrip())

        if addr_err_lines:
            print("\n--- Address Errors ---")
            for l in addr_err_lines[:20]:
                print(l.rstrip())

        if not fti_lines and not addr_err_lines:
            print("\nNo FTI or ADDR_ERR found. Last 10 lines:")
            for l in lines[-10:]:
                print(l.rstrip())
    else:
        print("ERROR: stderr log not found")

if __name__ == "__main__":
    main()
