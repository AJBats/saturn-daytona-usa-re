#!/usr/bin/env python3
"""diag_scdq_trace.py -- SCDQ SET/READ trace comparison.

Runs production and free (+4 shift) builds side by side in Mednafen,
with CDB-level SCDQ tracing enabled. Compares the exact timestamps of
HIRQ_SCDQ SET events and HIRQ READ events to find where they diverge.

NO CPU debug hook is used -- the trace runs inside CDB code only,
avoiding the observer effects that masked this bug previously.

Usage:
    python tools/diag_scdq_trace.py [--end-frame 720]

Requires: Debug Mednafen with scdq_trace command support.
"""

import os
import sys
import time
import argparse

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))

from parallel_compare import MednafenInstance

# Disc paths
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")
CUE_FREE = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
TMPDIR = os.path.join(PROJDIR, ".tmp", "scdq_trace")


def win_to_wsl(path):
    path = path.replace("\\", "/")
    if len(path) >= 2 and path[1] == ":":
        drive = path[0].lower()
        return f"/mnt/{drive}{path[2:]}"
    return path


def parse_trace(path):
    """Parse SCDQ trace log into list of (type, timestamp, hirq_value) tuples."""
    events = []
    try:
        with open(path, "r") as f:
            for line in f:
                line = line.strip()
                if not line:
                    continue
                parts = line.split()
                if len(parts) >= 3:
                    etype = parts[0]  # SET or READ
                    ts = int(parts[1])
                    hirq = int(parts[2], 16)
                    events.append((etype, ts, hirq))
    except FileNotFoundError:
        pass
    return events


def diff_traces(events_prod, events_free, context=5):
    """Find first divergence between two trace event lists.

    Returns (index, description) or None if identical.
    """
    min_len = min(len(events_prod), len(events_free))

    for i in range(min_len):
        ep = events_prod[i]
        ef = events_free[i]
        if ep[0] != ef[0]:
            return i, f"Event type differs: prod={ep[0]} free={ef[0]}"
        if ep[0] == "SET":
            # For SET events, timestamps will likely differ (CDB internal timing)
            # but the HIRQ value should match
            if ep[2] != ef[2]:
                return i, f"SET HIRQ differs: prod=0x{ep[2]:04X} free=0x{ef[2]:04X}"
        if ep[0] == "READ":
            # For READ events, the HIRQ value seen by the CPU is what matters
            if ep[2] != ef[2]:
                return i, f"READ HIRQ differs: prod=0x{ep[2]:04X} free=0x{ef[2]:04X}"

    if len(events_prod) != len(events_free):
        return min_len, f"Length differs: prod={len(events_prod)} free={len(events_free)}"

    return None


def analyze_scdq_pattern(events, label):
    """Analyze the SET/READ interleaving pattern.

    Key question: does every READ after a SET see SCDQ (bit 10) set?
    """
    set_count = 0
    read_count = 0
    read_with_scdq = 0
    read_without_scdq = 0
    last_set_ts = None
    reads_after_set_without_scdq = []

    for etype, ts, hirq in events:
        if etype == "SET":
            set_count += 1
            last_set_ts = ts
        elif etype == "READ":
            read_count += 1
            has_scdq = bool(hirq & 0x0400)
            if has_scdq:
                read_with_scdq += 1
            else:
                read_without_scdq += 1
                if last_set_ts is not None:
                    reads_after_set_without_scdq.append((ts, hirq, last_set_ts))

    print(f"  [{label}] SET events: {set_count}, READ events: {read_count}")
    print(f"  [{label}] READs with SCDQ bit: {read_with_scdq}, without: {read_without_scdq}")
    if reads_after_set_without_scdq:
        print(f"  [{label}] *** {len(reads_after_set_without_scdq)} READs after SET that MISSED SCDQ:")
        for ts, hirq, set_ts in reads_after_set_without_scdq[:10]:
            print(f"         READ ts={ts} HIRQ=0x{hirq:04X} (last SET at ts={set_ts}, delta={ts-set_ts})")


def find_stuck_poll(events, label):
    """Find sequences of consecutive READs without SCDQ -- the infinite poll."""
    consecutive_reads = 0
    max_consecutive = 0
    streak_start_idx = 0
    worst_start = 0

    for i, (etype, ts, hirq) in enumerate(events):
        if etype == "READ" and not (hirq & 0x0400):
            if consecutive_reads == 0:
                streak_start_idx = i
            consecutive_reads += 1
            if consecutive_reads > max_consecutive:
                max_consecutive = consecutive_reads
                worst_start = streak_start_idx
        else:
            consecutive_reads = 0

    if max_consecutive > 100:
        print(f"  [{label}] *** STUCK POLL: {max_consecutive} consecutive READs without SCDQ")
        print(f"         Starting at event index {worst_start}")
        # Show context around the stuck poll
        start = max(0, worst_start - 3)
        end = min(len(events), worst_start + 10)
        for i in range(start, end):
            etype, ts, hirq = events[i]
            marker = " >>>" if i == worst_start else "    "
            scdq = " SCDQ" if hirq & 0x0400 else ""
            print(f"       {marker} [{i}] {etype} ts={ts} HIRQ=0x{hirq:04X}{scdq}")
    else:
        print(f"  [{label}] Max consecutive READs without SCDQ: {max_consecutive} (OK)")


def main():
    parser = argparse.ArgumentParser(description="SCDQ SET/READ trace comparison")
    parser.add_argument("--end-frame", type=int, default=720,
                        help="Frame to stop tracing (default: 720, well past hang at ~683)")
    parser.add_argument("--skip-to", type=int, default=60,
                        help="Frame to fast-forward to initially (BIOS skip, default: 60)")
    parser.add_argument("--trace-start", type=int, default=600,
                        help="Frame to enable SCDQ trace (default: 600, before hang)")
    args = parser.parse_args()

    os.makedirs(TMPDIR, exist_ok=True)
    ipc_prod = os.path.join(TMPDIR, "prod")
    ipc_free = os.path.join(TMPDIR, "free")

    # Trace output paths (Windows paths for reading back)
    trace_prod = os.path.join(TMPDIR, "scdq_prod.log")
    trace_free = os.path.join(TMPDIR, "scdq_free.log")

    print("=" * 70)
    print("SCDQ SET/READ Trace Comparison")
    print(f"Trace starts at frame {args.trace_start}, ends at frame {args.end_frame}")
    print(f"Production disc: {CUE_PROD}")
    print(f"Free +4 disc:    {CUE_FREE}")
    print("=" * 70)

    # Verify discs exist
    if not os.path.exists(CUE_PROD):
        print(f"ERROR: Production disc not found: {CUE_PROD}")
        sys.exit(1)
    if not os.path.exists(CUE_FREE):
        print(f"ERROR: Free disc not found: {CUE_FREE}")
        print("  Build with: cd reimpl && make free-disc")
        sys.exit(1)

    # Clean old trace files
    for f in [trace_prod, trace_free]:
        if os.path.exists(f):
            os.remove(f)

    # Kill stale instances
    print("\nKilling stale Mednafen instances...")
    MednafenInstance.kill_stale()

    # Launch both instances
    print("\nLaunching production instance...")
    prod = MednafenInstance("prod", CUE_PROD, ipc_prod)
    prod.start()

    print("Launching free (+4) instance...")
    free = MednafenInstance("free", CUE_FREE, ipc_free)
    free.start()

    try:
        # Skip BIOS
        print(f"\nAdvancing both to frame {args.skip_to} (BIOS skip)...")
        prod.frame_advance(args.skip_to)
        free.frame_advance(args.skip_to)

        # Fast-forward to trace start
        advance = args.trace_start - args.skip_to
        if advance > 0:
            print(f"Fast-forwarding to frame {args.trace_start} ({advance} frames)...")
            prod.frame_advance(advance)
            free.frame_advance(advance)

        # Enable SCDQ trace
        trace_prod_wsl = win_to_wsl(trace_prod)
        trace_free_wsl = win_to_wsl(trace_free)
        print(f"\nEnabling SCDQ trace at frame {args.trace_start}...")
        prod.send(f"scdq_trace {trace_prod_wsl}")
        free.send(f"scdq_trace {trace_free_wsl}")

        # Run frame by frame through the danger zone
        trace_frames = args.end_frame - args.trace_start
        print(f"Running {trace_frames} frames with SCDQ trace active...")
        print(f"(frame_advance 1 at a time to catch the exact hang frame)")
        print()

        for frame_num in range(args.trace_start, args.end_frame + 1):
            # Advance one frame at a time
            try:
                ack_p = prod.frame_advance(1)
            except TimeoutError:
                print(f"  [prod] TIMEOUT at frame {frame_num} - hung!")
                break

            try:
                ack_f = free.frame_advance(1)
            except TimeoutError:
                print(f"  [free] TIMEOUT at frame {frame_num} - hung!")
                # Prod is ahead by 1 frame, but that's ok for diagnosis
                break

            # Progress indicator every 10 frames
            if (frame_num - args.trace_start) % 10 == 0:
                print(f"  Frame {frame_num}... (prod: {ack_p.split('frame=')[-1].split()[0] if 'frame=' in ack_p else '?'}, "
                      f"free: {ack_f.split('frame=')[-1].split()[0] if 'frame=' in ack_f else '?'})")

        # Stop traces
        print("\nStopping SCDQ traces...")
        try:
            prod.send("scdq_trace_stop")
        except Exception:
            pass
        try:
            free.send("scdq_trace_stop")
        except Exception:
            pass

        # Analyze traces
        print(f"\n{'='*70}")
        print("TRACE ANALYSIS")
        print(f"{'='*70}")

        events_prod = parse_trace(trace_prod)
        events_free = parse_trace(trace_free)

        print(f"\nProd trace: {len(events_prod)} events")
        print(f"Free trace: {len(events_free)} events")

        # Basic statistics
        print(f"\n--- Statistics ---")
        analyze_scdq_pattern(events_prod, "prod")
        analyze_scdq_pattern(events_free, "free")

        # Find stuck polls
        print(f"\n--- Stuck Poll Detection ---")
        find_stuck_poll(events_prod, "prod")
        find_stuck_poll(events_free, "free")

        # Timestamp comparison for SET events
        print(f"\n--- SET Event Timing ---")
        sets_prod = [(ts, hirq) for etype, ts, hirq in events_prod if etype == "SET"]
        sets_free = [(ts, hirq) for etype, ts, hirq in events_free if etype == "SET"]
        print(f"  Prod SET events: {len(sets_prod)}")
        print(f"  Free SET events: {len(sets_free)}")

        if sets_prod and sets_free:
            min_sets = min(len(sets_prod), len(sets_free))
            print(f"\n  Comparing first {min(min_sets, 20)} SET timestamps:")
            for i in range(min(min_sets, 20)):
                ts_p, hirq_p = sets_prod[i]
                ts_f, hirq_f = sets_free[i]
                delta = ts_f - ts_p
                print(f"    SET[{i}]: prod_ts={ts_p:>12d}  free_ts={ts_f:>12d}  delta={delta:>8d}  "
                      f"prod_hirq=0x{hirq_p:04X} free_hirq=0x{hirq_f:04X}")

        # Event-by-event diff
        print(f"\n--- Event Sequence Diff ---")
        divergence = diff_traces(events_prod, events_free)
        if divergence:
            idx, desc = divergence
            print(f"  FIRST DIVERGENCE at event index {idx}: {desc}")
            # Show context
            print(f"\n  Context (prod events around divergence):")
            for i in range(max(0, idx-5), min(len(events_prod), idx+10)):
                etype, ts, hirq = events_prod[i]
                marker = " >>>" if i == idx else "    "
                scdq = " SCDQ" if hirq & 0x0400 else ""
                print(f"    {marker} [{i}] {etype} ts={ts:>12d} HIRQ=0x{hirq:04X}{scdq}")
            print(f"\n  Context (free events around divergence):")
            for i in range(max(0, idx-5), min(len(events_free), idx+10)):
                etype, ts, hirq = events_free[i]
                marker = " >>>" if i == idx else "    "
                scdq = " SCDQ" if hirq & 0x0400 else ""
                print(f"    {marker} [{i}] {etype} ts={ts:>12d} HIRQ=0x{hirq:04X}{scdq}")
        else:
            print("  Traces are IDENTICAL (no divergence found)")

        # Final summary
        print(f"\n{'='*70}")
        print("SUMMARY")
        print(f"{'='*70}")
        print(f"Trace files saved to: {TMPDIR}")
        print(f"  scdq_prod.log: {len(events_prod)} events")
        print(f"  scdq_free.log: {len(events_free)} events")
        if divergence:
            print(f"  DIVERGENCE at event {divergence[0]}: {divergence[1]}")
        print("Done.")

    finally:
        print("\nShutting down...")
        prod.quit()
        free.quit()


if __name__ == "__main__":
    main()
