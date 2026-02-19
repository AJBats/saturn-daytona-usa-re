#!/usr/bin/env python3
"""diag_scdq_state.py — SCDQ CDB-level trace comparison.

Runs production and free (ICF_FIX=1, SCDQ_FIX=0) discs side by side.
At frame 680, enables the CDB-internal SCDQ trace on both instances.
The trace logs from INSIDE CDB code — no CPU hook, no observer effect.

Trace events:
  SET <sh2_ts> <drv_status> <hirq_after>  — PeriodicIdleCounter fired SCDQ
  READ <sh2_ts> <hirq_val>                — CDB_Read called for HIRQ register

Drive status values (CurPosInfo.status byte):
  0=BUSY  1=PAUSE  2=STANDBY  3=PLAY  4=SEEK  5=SCAN  6=OPEN  7=NODISC

Key questions this answers:
  1. Does SCDQ SET ever fire in the free build during the hang window?
     - NO  →  drive is in wrong state (real hardware bug — SCDQ needs disc reading)
     - YES →  timing issue: SETs fire but READs miss them (Mednafen-specific)

  2. At the first SCDQ SET in the free build: what is the drive status?
     - STANDBY/PAUSE → disc stopped, SCDQ won't fire on real hardware either
     - PLAY/SEEK     → disc reading, SCDQ should fire on real hardware too

Usage:
    python tools/diag_scdq_state.py [--trace-start 680] [--max-frame 695]

Requires: Debug Mednafen with CDB SCDQ trace support (cdb.cpp patched).
"""

import os
import sys
import time
import struct

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))

from parallel_compare import MednafenInstance, win_to_wsl, TMPDIR

CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")
CUE_FREE = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")

# Drive status names
DRV_STATUS = {
    0: "BUSY", 1: "PAUSE", 2: "STANDBY", 3: "PLAY",
    4: "SEEK", 5: "SCAN", 6: "OPEN", 7: "NODISC",
    8: "RETRY", 9: "ERROR", 0xA: "FATAL",
}

HIRQ_NAMES = {
    0: "CMOK", 1: "DRDY", 2: "CSCT", 3: "BFUL",
    4: "PEND", 5: "DCHG", 6: "ESEL", 7: "EHST",
    8: "ECPY", 9: "EFLS", 10: "SCDQ",
}


def decode_hirq(val):
    bits = [HIRQ_NAMES[i] for i in range(11) if val & (1 << i)]
    return f"0x{val:04X}[{','.join(bits) if bits else 'none'}]"


def parse_trace(path):
    """Parse trace file into list of (type, sh2_ts, extra...) tuples."""
    events = []
    try:
        with open(path, "r") as f:
            for line in f:
                line = line.strip()
                if not line or line.startswith("#"):
                    continue
                parts = line.split()
                if len(parts) >= 3 and parts[0] == "SET":
                    ts = int(parts[1])
                    drv = int(parts[2])
                    hirq = int(parts[3], 16) if len(parts) > 3 else 0
                    events.append(("SET", ts, drv, hirq))
                elif len(parts) >= 3 and parts[0] == "READ":
                    ts = int(parts[1])
                    hirq = int(parts[2], 16)
                    events.append(("READ", ts, hirq))
    except FileNotFoundError:
        pass
    return events


def analyze_trace(events, label):
    """Analyze a trace and report key findings."""
    set_events = [e for e in events if e[0] == "SET"]
    read_events = [e for e in events if e[0] == "READ"]
    reads_with_scdq = [e for e in read_events if e[2] & 0x0400]
    reads_without_scdq = [e for e in read_events if not (e[2] & 0x0400)]

    print(f"\n[{label}]")
    print(f"  Total events:   {len(events)}")
    print(f"  SET events:     {len(set_events)}  (SCDQ fired {len(set_events)} times)")
    print(f"  READ events:    {len(read_events)}  ({len(reads_with_scdq)} with SCDQ=1, {len(reads_without_scdq)} with SCDQ=0)")

    if set_events:
        print(f"\n  First 5 SET events:")
        for e in set_events[:5]:
            ts, drv, hirq = e[1], e[2], e[3]
            drv_name = DRV_STATUS.get(drv, f"0x{drv:02X}")
            print(f"    ts={ts:>12d}  drv={drv_name:<10s}  hirq={decode_hirq(hirq)}")

        # Check drive states at SET events
        drv_states = {}
        for e in set_events:
            d = DRV_STATUS.get(e[2], f"0x{e[2]:02X}")
            drv_states[d] = drv_states.get(d, 0) + 1
        print(f"  Drive states at SCDQ fires: {drv_states}")

        # Check: is SCDQ actually visible in HIRQ after SET?
        scdq_visible = sum(1 for e in set_events if e[3] & 0x0400)
        print(f"  SCDQ visible in HIRQ after SET: {scdq_visible}/{len(set_events)}")
    else:
        print(f"\n  *** NO SCDQ SET EVENTS — PeriodicIdleCounter never fired SCDQ!")
        print(f"      This means the drive is not reading sectors, or CDB state is wrong.")

    if reads_with_scdq:
        print(f"\n  First READ with SCDQ=1:")
        e = reads_with_scdq[0]
        print(f"    ts={e[1]:>12d}  hirq={decode_hirq(e[2])}")
    elif read_events:
        print(f"\n  *** ALL READS ({len(read_events)}) saw SCDQ=0 — game never exits poll loop")

    return {
        "set_count": len(set_events),
        "read_count": len(read_events),
        "reads_scdq1": len(reads_with_scdq),
        "set_events": set_events,
        "read_events": read_events,
    }


def compare_traces(prod_stats, free_stats):
    print(f"\n{'='*65}")
    print("DIAGNOSIS")
    print(f"{'='*65}")

    ps = prod_stats["set_count"]
    fs = free_stats["set_count"]
    pr = prod_stats["reads_scdq1"]
    fr = free_stats["reads_scdq1"]

    if fs == 0:
        print("\n>>> DRIVE STATE BUG (real hardware bug):")
        print("    SCDQ never fired in free build during the trace window.")
        print("    PeriodicIdleCounter never hit zero — the CDB drive state")
        print("    machine is not running the periodic update path.")
        print("    On real Saturn hardware: SCDQ requires disc reading sectors.")
        print("    The free build's CD Block is stuck in a non-reading state.")
        print(f"\n    Production: {ps} SCDQ fires, {pr} reads saw SCDQ=1")
        print(f"    Free build:  {fs} SCDQ fires, {fr} reads saw SCDQ=1")
        print("\n>>> Root cause is UPSTREAM of FUN_060423CC (the poll function).")
        print("    Look at FUN_0603B424 (CD command state machine) for wrong")
        print("    CD commands that put the drive in STANDBY/non-reading state.")

    elif fr == 0 and fs > 0:
        print("\n>>> TIMING BUG (Mednafen-specific):")
        print("    SCDQ DID fire in free build, but HIRQ reads always saw SCDQ=0.")
        print("    This is the timing race: CDB events fire SCDQ but the game's")
        print("    HIRQ reads land in the gap before the event fires.")
        print(f"\n    Production: {ps} fires, {pr} reads with SCDQ=1")
        print(f"    Free build:  {fs} fires, {fr} reads with SCDQ=1")
        print("\n>>> The CDB fix (CDB_Update in CDB_Read) should address this.")
        print("    On real hardware, this might work (registers are always live).")

        # Analyze timing: how long after SET does a READ happen?
        print("\n  Timing analysis (SET→READ gaps):")
        set_ts_list = [e[1] for e in free_stats["set_events"]]
        read_ts_list = [e[1] for e in free_stats["read_events"]]
        for set_ts in set_ts_list[:3]:
            next_read = next((r for r in read_ts_list if r > set_ts), None)
            if next_read:
                print(f"    SET at {set_ts} → next READ at {next_read} (+{next_read-set_ts} cycles)")

    else:
        print(f"\n  Production: {ps} SCDQ fires, {pr} reads saw SCDQ=1")
        print(f"  Free build:  {fs} SCDQ fires, {fr} reads saw SCDQ=1")
        if pr > 0 and fr > 0:
            print("\n  Both builds correctly receive SCDQ. No hang observed?")
            print("  The trace window may not include the hang frame.")
        else:
            print("\n  Unexpected result — check trace files manually.")


def main():
    import argparse
    parser = argparse.ArgumentParser(description="SCDQ CDB trace comparison")
    parser.add_argument("--trace-start", type=int, default=680,
                        help="Frame to enable trace (default: 680)")
    parser.add_argument("--max-frame", type=int, default=700,
                        help="Frame to stop (default: 700, past expected hang)")
    parser.add_argument("--bios-skip", type=int, default=60,
                        help="Frames to skip for BIOS (default: 60)")
    args = parser.parse_args()

    os.makedirs(TMPDIR, exist_ok=True)
    ipc_prod = os.path.join(TMPDIR, "scdq_state_prod")
    ipc_free = os.path.join(TMPDIR, "scdq_state_free")

    trace_prod = os.path.join(TMPDIR, "scdq_trace_prod.log")
    trace_free = os.path.join(TMPDIR, "scdq_trace_free.log")
    trace_prod_wsl = win_to_wsl(trace_prod)
    trace_free_wsl = win_to_wsl(trace_free)

    print("=" * 65)
    print("SCDQ CDB Trace Diagnostic")
    print(f"Trace window: frames {args.trace_start}–{args.max_frame}")
    print(f"No CPU hook — zero observer effect")
    print(f"Production: {os.path.basename(CUE_PROD)}")
    print(f"Free build: {os.path.basename(CUE_FREE)}")
    print("=" * 65)

    # Clean old traces
    for p in [trace_prod, trace_free]:
        if os.path.exists(p):
            os.remove(p)

    if not os.path.exists(CUE_PROD):
        print(f"ERROR: {CUE_PROD}")
        sys.exit(1)
    if not os.path.exists(CUE_FREE):
        print(f"ERROR: {CUE_FREE}")
        sys.exit(1)

    print("\nKilling stale Mednafen instances...")
    MednafenInstance.kill_stale()

    print("\nLaunching production instance...")
    prod = MednafenInstance("prod", CUE_PROD, ipc_prod)
    prod.start()

    print("Launching free instance...")
    free = MednafenInstance("free", CUE_FREE, ipc_free)
    free.start()

    free_hung_at = None

    try:
        # Skip BIOS
        print(f"\nSkipping BIOS ({args.bios_skip} frames)...")
        prod.frame_advance(args.bios_skip)
        free.frame_advance(args.bios_skip)

        # Fast-forward to trace start
        run_to = args.trace_start - args.bios_skip
        print(f"Advancing to frame {args.trace_start} ({run_to} frames)...")
        chunk = 100
        done = 0
        while done < run_to:
            n = min(chunk, run_to - done)
            prod.frame_advance(n)
            free.frame_advance(n)
            done += n
            if done % 200 == 0:
                print(f"  ~frame {args.bios_skip + done}...")
        print(f"  Reached frame {args.trace_start}.")

        # Enable traces (no CPU hook — these go into CDB event code)
        print(f"\nEnabling SCDQ traces at frame {args.trace_start}...")
        prod.send(f"scdq_trace {trace_prod_wsl}")
        free.send(f"scdq_trace {trace_free_wsl}")
        print("  Traces active.")

        # Step through frame by frame watching for hang
        print(f"\nStepping frame-by-frame through {args.trace_start}–{args.max_frame}...")
        for frame_num in range(args.trace_start + 1, args.max_frame + 1):
            try:
                prod.frame_advance(1)
            except TimeoutError:
                print(f"  prod: TIMEOUT at frame {frame_num}")
                break

            try:
                free.frame_advance(1)
                print(f"  frame {frame_num}: both OK")
            except TimeoutError:
                free_hung_at = frame_num
                print(f"  frame {frame_num}: FREE BUILD HUNG (expected!)")
                break

        # Stop traces
        print("\nStopping traces...")
        try:
            prod.send("scdq_trace_stop")
        except Exception:
            pass
        try:
            free.send("scdq_trace_stop")
        except Exception:
            pass

        # Small delay to let file writes flush
        time.sleep(0.5)

        # Parse and analyze
        print(f"\n{'='*65}")
        print("TRACE ANALYSIS")
        print(f"{'='*65}")

        if free_hung_at:
            print(f"\nFree build hung at frame {free_hung_at} (as expected)")
        else:
            print(f"\nFree build did NOT hang through frame {args.max_frame}")
            print("  Check .build_config — SCDQ_FIX may still be active:")
            cfg = os.path.join(PROJDIR, "reimpl", "build", ".build_config")
            if os.path.exists(cfg):
                print(f"  {open(cfg).read().strip()}")

        prod_events = parse_trace(trace_prod)
        free_events = parse_trace(trace_free)

        print(f"\nTrace file sizes: prod={len(prod_events)} events, free={len(free_events)} events")

        prod_stats = analyze_trace(prod_events, "PRODUCTION")
        free_stats = analyze_trace(free_events, "FREE +4")

        compare_traces(prod_stats, free_stats)

        print(f"\nTrace files saved:")
        print(f"  {trace_prod}")
        print(f"  {trace_free}")
        print("Done.")

    finally:
        print("\nShutting down...")
        prod.quit()
        free.quit()


if __name__ == "__main__":
    main()
