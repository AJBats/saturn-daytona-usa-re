#!/usr/bin/env python3
"""call_trace_compare.py — Compare function call traces between production and free-layout binaries.

Launches two Mednafen instances, enables JSR/BSR/BSRF call tracing on both,
runs for N frames, then maps raw addresses to FUN_ names and diffs the traces
to find the first divergence.

Usage:
    python3 tools/call_trace_compare.py [--frames 300]

Requires: Modified Mednafen with call_trace automation command.
"""

import os
import sys
import re
import time
import argparse
import bisect

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, win_to_wsl

# Disc images
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")
CUE_FREE = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
SYMS_FILE = os.path.join(PROJDIR, "build", "aprog_syms.txt")
FREE_MAP = os.path.join(PROJDIR, "reimpl", "build", "daytona.map")
TMPDIR = os.path.join(PROJDIR, ".tmp", "call_trace")


def load_symbols(syms_path):
    """Load FUN_ symbols from aprog_syms.txt. Returns sorted list of (addr, name)."""
    syms = []
    with open(syms_path) as f:
        for line in f:
            m = re.match(r'(FUN_[0-9A-Fa-f]+)\s*=\s*0x([0-9A-Fa-f]+)', line)
            if m:
                syms.append((int(m.group(2), 16), m.group(1)))
    syms.sort()
    return syms


def load_free_symbols(map_path):
    """Load symbols from free-layout linker map. Returns sorted list of (addr, name)."""
    syms = []
    # The map file has lines like:
    #  0x06003100     FUN_060030FC
    # or in PROVIDE section:
    #  PROVIDE (FUN_060030FC = 0x6003100)
    with open(map_path) as f:
        for line in f:
            # Look for .text.FUN_ section entries
            m = re.match(r'\s+\.text\.(FUN_[0-9A-Fa-f]+)\s', line)
            if m:
                # Next line might have the address
                continue
            # Look for symbol = address lines
            m = re.match(r'\s+0x([0-9a-f]+)\s+(FUN_[0-9A-Fa-f]+)', line, re.I)
            if m:
                syms.append((int(m.group(1), 16), m.group(2)))
    syms.sort()
    # Deduplicate
    seen = set()
    unique = []
    for addr, name in syms:
        if name not in seen:
            seen.add(name)
            unique.append((addr, name))
    return unique


def addr_to_func(addr, sym_addrs, sym_names):
    """Map an address to its containing function name."""
    idx = bisect.bisect_right(sym_addrs, addr) - 1
    if idx >= 0:
        return sym_names[idx]
    return f"UNKNOWN_{addr:08X}"


def map_trace(trace_path, sym_addrs, sym_names):
    """Read raw trace file, map addresses to function names.
    Returns list of (cpu, caller_func, target_func) tuples."""
    mapped = []
    with open(trace_path) as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            parts = line.split()
            if len(parts) != 3:
                continue
            cpu = parts[0]
            caller = int(parts[1], 16)
            target = int(parts[2], 16)
            caller_func = addr_to_func(caller, sym_addrs, sym_names)
            target_func = addr_to_func(target, sym_addrs, sym_names)
            mapped.append((cpu, caller_func, target_func))
    return mapped


def main():
    parser = argparse.ArgumentParser(description="Compare call traces between prod and free-layout")
    parser.add_argument("--frames", type=int, default=300, help="Frames to trace (default 300)")
    parser.add_argument("--context", type=int, default=20, help="Context lines around divergence")
    args = parser.parse_args()

    os.makedirs(TMPDIR, exist_ok=True)

    # Load production symbols
    print("Loading symbols...")
    prod_syms = load_symbols(SYMS_FILE)
    prod_addrs = [s[0] for s in prod_syms]
    prod_names = [s[1] for s in prod_syms]
    print(f"  Production: {len(prod_syms)} FUN_ symbols")

    # For free-layout, addresses are shifted +4. Map by subtracting 4 from each address.
    # Actually, we should use the free linker map if available.
    free_addrs = [s + 4 for s in prod_addrs]  # Simple +4 shift
    free_names = list(prod_names)  # Same function names
    print(f"  Free-layout: using production names with +4 offset")

    # Trace file paths (Windows for Python, WSL for Mednafen)
    trace_prod_win = os.path.join(TMPDIR, "trace_prod.txt")
    trace_free_win = os.path.join(TMPDIR, "trace_free.txt")
    trace_prod_wsl = win_to_wsl(trace_prod_win)
    trace_free_wsl = win_to_wsl(trace_free_win)

    # Clean up old traces
    for f in [trace_prod_win, trace_free_win]:
        if os.path.exists(f):
            os.remove(f)

    # Kill stale processes
    print("\nKilling stale Mednafen processes...")
    MednafenInstance.kill_stale()

    # Start both instances
    print("\nStarting production Mednafen...")
    prod = MednafenInstance("prod", CUE_PROD, os.path.join(TMPDIR, "ipc_prod"))
    prod.start()

    print("Starting free-layout Mednafen...")
    free = MednafenInstance("free", CUE_FREE, os.path.join(TMPDIR, "ipc_free"))
    free.start()

    try:
        # Enable call tracing on both (emulator starts paused)
        print(f"\nEnabling call trace...")
        ack = prod.send(f"call_trace {trace_prod_wsl}")
        print(f"  [prod] {ack}")
        ack = free.send(f"call_trace {trace_free_wsl}")
        print(f"  [free] {ack}")

        # Advance N frames (frame_advance handles unpausing)
        print(f"\nRunning {args.frames} frames...")
        ack_prod = prod.frame_advance(args.frames)
        print(f"  [prod] {ack_prod}")
        ack_free = free.frame_advance(args.frames)
        print(f"  [free] {ack_free}")

        # Stop traces
        print("\nStopping traces...")
        ack = prod.send("call_trace_stop")
        print(f"  [prod] {ack}")
        ack = free.send("call_trace_stop")
        print(f"  [free] {ack}")

    finally:
        print("\nShutting down...")
        prod.quit()
        free.quit()

    # Analyze traces
    print(f"\n{'='*60}")
    print("TRACE ANALYSIS")
    print(f"{'='*60}")

    if not os.path.exists(trace_prod_win):
        print("ERROR: Production trace file not found!")
        return 1
    if not os.path.exists(trace_free_win):
        print("ERROR: Free-layout trace file not found!")
        return 1

    prod_size = os.path.getsize(trace_prod_win)
    free_size = os.path.getsize(trace_free_win)
    print(f"\nTrace files:")
    print(f"  prod: {prod_size:,} bytes")
    print(f"  free: {free_size:,} bytes")

    # Count raw lines
    with open(trace_prod_win) as f:
        prod_lines = sum(1 for _ in f)
    with open(trace_free_win) as f:
        free_lines = sum(1 for _ in f)
    print(f"  prod calls: {prod_lines:,}")
    print(f"  free calls: {free_lines:,}")

    # Map to function names
    print("\nMapping addresses to function names...")
    mapped_prod = map_trace(trace_prod_win, prod_addrs, prod_names)
    mapped_free = map_trace(trace_free_win, free_addrs, free_names)
    print(f"  prod mapped: {len(mapped_prod):,}")
    print(f"  free mapped: {len(mapped_free):,}")

    # Check for slave CPU calls
    prod_master = [(c, t) for cpu, c, t in mapped_prod if cpu == 'M']
    prod_slave = [(c, t) for cpu, c, t in mapped_prod if cpu == 'S']
    free_master = [(c, t) for cpu, c, t in mapped_free if cpu == 'M']
    free_slave = [(c, t) for cpu, c, t in mapped_free if cpu == 'S']
    print(f"\n  prod: {len(prod_master):,} master calls, {len(prod_slave):,} slave calls")
    print(f"  free: {len(free_master):,} master calls, {len(free_slave):,} slave calls")

    if prod_slave:
        print("\n  WARNING: Slave SH-2 is active! Daytona uses dual CPUs.")

    # Diff master call sequences
    print(f"\n{'='*60}")
    print("MASTER CPU CALL SEQUENCE DIFF")
    print(f"{'='*60}")

    min_len = min(len(prod_master), len(free_master))
    first_diff = None
    for i in range(min_len):
        if prod_master[i] != free_master[i]:
            first_diff = i
            break

    if first_diff is None and len(prod_master) == len(free_master):
        print("\nPERFECT MATCH! All master CPU calls are identical.")
        print("The function call sequence is the same in both builds.")
        print("The black screen is NOT caused by a wrong function call target.")
        return 0

    if first_diff is None:
        first_diff = min_len
        print(f"\nTraces match for {min_len:,} calls, then one trace is longer:")
        print(f"  prod: {len(prod_master):,} calls")
        print(f"  free: {len(free_master):,} calls")
        print(f"  Free-layout may have STOPPED CALLING functions (hung/crashed)")
    else:
        print(f"\nFIRST DIVERGENCE at call #{first_diff:,}:")

    # Show context
    ctx = args.context
    start = max(0, first_diff - ctx)
    end = min(max(len(prod_master), len(free_master)), first_diff + ctx)

    print(f"\nContext (calls {start}-{end}):")
    print(f"{'#':>8}  {'PROD caller':>20} -> {'target':<20}  {'FREE caller':>20} -> {'target':<20}  {'Match'}")
    print("-" * 120)

    for i in range(start, end):
        p_caller = prod_master[i][0] if i < len(prod_master) else "---"
        p_target = prod_master[i][1] if i < len(prod_master) else "---"
        f_caller = free_master[i][0] if i < len(free_master) else "---"
        f_target = free_master[i][1] if i < len(free_master) else "---"

        match = "OK" if (p_caller == f_caller and p_target == f_target) else "**DIFF**"
        marker = ">>>" if i == first_diff else "   "

        print(f"{marker}{i:>5}  {p_caller:>20} -> {p_target:<20}  {f_caller:>20} -> {f_target:<20}  {match}")

    # Save mapped traces for further analysis
    mapped_prod_path = os.path.join(TMPDIR, "mapped_prod.txt")
    mapped_free_path = os.path.join(TMPDIR, "mapped_free.txt")
    with open(mapped_prod_path, "w") as f:
        for cpu, caller, target in mapped_prod:
            f.write(f"{cpu} {caller} -> {target}\n")
    with open(mapped_free_path, "w") as f:
        for cpu, caller, target in mapped_free:
            f.write(f"{cpu} {caller} -> {target}\n")
    print(f"\nMapped traces saved to:")
    print(f"  {mapped_prod_path}")
    print(f"  {mapped_free_path}")

    return 0


if __name__ == "__main__":
    sys.exit(main())
