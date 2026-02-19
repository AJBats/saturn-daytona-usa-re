#!/usr/bin/env python3
"""diag_cdb_commands.py — Compare CD Block command sequences: prod vs free.

Runs both discs to frame 700 with Mednafen's built-in SS_DBG_CDB logging
enabled (ss_dbg_mask |= SS_DBG_CDB). Captures stdout logs, extracts all
[CDB] lines, and diffs them to find the first command sequence divergence.

The CDB log captures:
  - Every command issued (with decoded name, HIRQ state, timestamp)
  - Command results (CR1-CR4 response values)
  - Drive state transitions (buffer full pause, play end pause, etc.)
  - Data transfer events

Usage:
    python tools/diag_cdb_commands.py [--frames 700]
"""

import os
import sys
import re
import difflib
import time

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))

from parallel_compare import MednafenInstance, win_to_wsl, TMPDIR

CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")
CUE_FREE = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")


def extract_cdb_lines(log_path):
    """Extract all [CDB] lines from a Mednafen stdout log."""
    lines = []
    try:
        with open(log_path, "r", errors="replace") as f:
            for line in f:
                line = line.rstrip()
                if "[CDB]" in line:
                    lines.append(line)
    except FileNotFoundError:
        pass
    return lines


def strip_timing(line):
    """Remove timestamp from CDB command line for comparison.

    CDB command lines look like:
      [CDB] Command: GET_STATUS --- HIRQ=0x00C1, HIRQ_Mask=0xFFFF --- 123456
    We strip the final timestamp number so timing differences don't
    show as divergences.
    """
    # Strip trailing timestamp (--- NNNNNN)
    return re.sub(r' --- \d+\s*$', '', line)


def find_first_divergence(prod_lines, free_lines, context=5):
    """Find the index of first line where prod and free differ."""
    min_len = min(len(prod_lines), len(free_lines))
    for i in range(min_len):
        ps = strip_timing(prod_lines[i])
        fs = strip_timing(free_lines[i])
        if ps != fs:
            return i
    if len(prod_lines) != len(free_lines):
        return min_len
    return None


def print_context(lines, idx, label, window=8):
    """Print lines around a divergence index."""
    start = max(0, idx - window)
    end = min(len(lines), idx + window + 1)
    print(f"\n  [{label}] Context around line {idx}:")
    for i in range(start, end):
        marker = ">>>" if i == idx else "   "
        print(f"    {marker} [{i:4d}] {lines[i]}")


def analyze_command_types(lines, label):
    """Count command types and state transitions."""
    cmd_counts = {}
    state_events = []

    for line in lines:
        # Command lines: [CDB] Command: NAME ---
        m = re.search(r'\[CDB\] Command: (\S+)', line)
        if m:
            cmd = m.group(1)
            cmd_counts[cmd] = cmd_counts.get(cmd, 0) + 1

        # State events
        if "buffer full pause" in line.lower():
            state_events.append(("BUFFER_FULL_PAUSE", line))
        elif "play end pause" in line.lower():
            state_events.append(("PLAY_END_PAUSE", line))
        elif "starting pause" in line.lower():
            state_events.append(("PAUSE", line))
        elif "resuming from buffer" in line.lower():
            state_events.append(("RESUME_FROM_BUF", line))

    print(f"\n  [{label}] Command summary ({sum(cmd_counts.values())} total commands):")
    for cmd, count in sorted(cmd_counts.items(), key=lambda x: -x[1]):
        print(f"    {cmd:30s}: {count}")

    if state_events:
        print(f"\n  [{label}] Drive state events ({len(state_events)}):")
        for etype, line in state_events[:20]:
            print(f"    {etype:25s}: {line.strip()}")
    else:
        print(f"\n  [{label}] No drive state events recorded")


def main():
    import argparse
    parser = argparse.ArgumentParser(description="CDB command sequence comparison")
    parser.add_argument("--frames", type=int, default=700,
                        help="Frames to run (default: 700)")
    parser.add_argument("--bios-skip", type=int, default=60,
                        help="BIOS skip frames (default: 60)")
    args = parser.parse_args()

    os.makedirs(TMPDIR, exist_ok=True)
    ipc_prod = os.path.join(TMPDIR, "cdb_cmd_prod")
    ipc_free = os.path.join(TMPDIR, "cdb_cmd_free")

    print("=" * 65)
    print("CD Block Command Sequence Diagnostic")
    print(f"Running {args.frames} frames with Mednafen SS_DBG_CDB logging")
    print(f"CDB log goes to stdout (mednafen_stdout.log in each IPC dir)")
    print("=" * 65)

    if not os.path.exists(CUE_PROD):
        print(f"ERROR: {CUE_PROD}")
        sys.exit(1)
    if not os.path.exists(CUE_FREE):
        print(f"ERROR: {CUE_FREE}")
        sys.exit(1)

    print("\nKilling stale instances...")
    MednafenInstance.kill_stale()

    print("\nLaunching production instance...")
    prod = MednafenInstance("prod", CUE_PROD, ipc_prod)
    prod.start()

    print("Launching free (+4) instance...")
    free = MednafenInstance("free", CUE_FREE, ipc_free)
    free.start()

    prod_hung = False
    free_hung = False

    try:
        # BIOS skip
        print(f"\nSkipping BIOS ({args.bios_skip} frames)...")
        prod.frame_advance(args.bios_skip)
        free.frame_advance(args.bios_skip)

        # Advance in chunks
        remaining = args.frames - args.bios_skip
        print(f"Running to frame {args.frames} ({remaining} frames)...")
        chunk = 100
        done = 0
        while done < remaining:
            n = min(chunk, remaining - done)
            try:
                prod.frame_advance(n)
            except TimeoutError:
                print(f"  prod HUNG at frame ~{args.bios_skip + done + n}")
                prod_hung = True
                break
            try:
                free.frame_advance(n)
            except TimeoutError:
                print(f"  free HUNG at frame ~{args.bios_skip + done + n}")
                free_hung = True
                break
            done += n
            print(f"  frame ~{args.bios_skip + done}...")

        print(f"\nRun complete. prod_hung={prod_hung}, free_hung={free_hung}")

    finally:
        prod.quit()
        free.quit()

    # Give log files a moment to flush
    time.sleep(1)

    # Extract CDB lines from stdout logs
    prod_log = os.path.join(ipc_prod, "mednafen_stdout.log")
    free_log = os.path.join(ipc_free, "mednafen_stdout.log")

    prod_lines = extract_cdb_lines(prod_log)
    free_lines = extract_cdb_lines(free_log)

    print(f"\n{'='*65}")
    print("LOG ANALYSIS")
    print(f"{'='*65}")
    print(f"\nProduction: {len(prod_lines)} [CDB] lines")
    print(f"Free build: {len(free_lines)} [CDB] lines")

    if not prod_lines and not free_lines:
        print("\nERROR: No [CDB] lines in either log!")
        print("  SS_DBG_CDB logging may not be active.")
        print(f"  Check: {prod_log}")
        sys.exit(1)

    # Command type analysis
    analyze_command_types(prod_lines, "PRODUCTION")
    analyze_command_types(free_lines, "FREE +4")

    # Find first divergence
    print(f"\n{'='*65}")
    print("DIVERGENCE ANALYSIS")
    print(f"{'='*65}")

    diverge_idx = find_first_divergence(prod_lines, free_lines)

    if diverge_idx is None:
        print("\n  Logs are IDENTICAL through all logged commands.")
        print("  The CD command sequences match — bug is elsewhere.")
    else:
        print(f"\n  FIRST DIVERGENCE at command #{diverge_idx}")
        print_context(prod_lines, diverge_idx, "PRODUCTION")
        print_context(free_lines, diverge_idx, "FREE +4")

        # Show a fuller diff around the divergence
        start = max(0, diverge_idx - 3)
        end = min(min(len(prod_lines), len(free_lines)), diverge_idx + 15)
        p_ctx = [strip_timing(l) for l in prod_lines[start:end]]
        f_ctx = [strip_timing(l) for l in free_lines[start:end]]

        diff = list(difflib.unified_diff(
            p_ctx, f_ctx,
            fromfile=f"production[{start}:{end}]",
            tofile=f"free[{start}:{end}]",
            lineterm=""
        ))
        if diff:
            print(f"\n  Unified diff (timestamps stripped):")
            for d in diff[:50]:
                print(f"    {d}")

    # Save full logs for manual inspection
    out_prod = os.path.join(TMPDIR, "cdb_cmd_prod.log")
    out_free = os.path.join(TMPDIR, "cdb_cmd_free.log")
    with open(out_prod, "w") as f:
        f.write("\n".join(prod_lines))
    with open(out_free, "w") as f:
        f.write("\n".join(free_lines))

    print(f"\nFull logs saved:")
    print(f"  {out_prod} ({len(prod_lines)} lines)")
    print(f"  {out_free} ({len(free_lines)} lines)")
    print("Done.")


if __name__ == "__main__":
    main()
