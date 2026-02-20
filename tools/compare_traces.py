#!/usr/bin/env python3
"""compare_traces.py — Find divergences between padded-retail and free unified traces.

Normalizes for the +4 address shift (only for addresses >= CODE_START),
ignoring cycle counts. Finds the first real behavioral divergence.

Usage:
    python tools/compare_traces.py [--start LINE] [--max-check N]
"""

import os
import sys
import argparse

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# Default to the fresh traces
RETAIL_TRACE = os.path.join(PROJDIR, "build", "traces", "unified_padded_retail_1000f.txt")
FREE_TRACE = os.path.join(PROJDIR, "build", "traces", "unified_free_nofixes_1000f.txt")

# Only normalize addresses at or above the first relocated function.
# _start section at 0x06003000 is identical in both builds.
# The +4 padding starts at 0x060030FC, so code at 0x060030FC+ is shifted.
CODE_SHIFT_START = 0x060030FC


def normalize_line(line, shift=0):
    """Normalize a trace line by stripping cycle counts and adjusting addresses.

    For M/S (SH-2) events: adjust addresses >= CODE_SHIFT_START by -shift.
    Returns (event_type, normalized_fields) or None for comments/empty.
    """
    line = line.strip()
    if not line or line.startswith("#"):
        return None

    parts = line.split()
    if len(parts) < 2:
        return None

    # First field is always cycle count — skip it
    event_type = parts[1]

    if event_type in ("M", "S"):
        # Format: <cycle> M/S <PC> <extra>
        if len(parts) < 4:
            return (event_type, " ".join(parts[2:]))
        pc = int(parts[2], 16)
        extra = int(parts[3], 16)
        # Only adjust addresses in the relocated code range
        if pc >= CODE_SHIFT_START:
            pc -= shift
        if extra >= CODE_SHIFT_START:
            extra -= shift
        return (event_type, f"{pc:08X}", f"{extra:08X}")
    else:
        # IRQ, CMD, BUF, DRV events — return as-is minus cycle
        return (event_type, " ".join(parts[2:]))


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--retail", default=RETAIL_TRACE, help="Retail trace path")
    parser.add_argument("--free", default=FREE_TRACE, help="Free trace path")
    parser.add_argument("--start", type=int, default=1,
                        help="Line number to start comparison (1-indexed)")
    parser.add_argument("--max-check", type=int, default=0,
                        help="Max lines to check (0=all)")
    parser.add_argument("--context", type=int, default=5,
                        help="Lines of context around divergence")
    parser.add_argument("--max-divergences", type=int, default=10,
                        help="Stop after this many divergences")
    args = parser.parse_args()

    print(f"Comparing traces:")
    print(f"  Retail: {args.retail}")
    print(f"  Free:   {args.free}")
    print(f"  Starting at line {args.start}")
    print(f"  Normalizing: free addresses -= 4 for addr >= 0x{CODE_SHIFT_START:08X}")
    print()

    divergences = []
    checked = 0
    in_sync = True
    sync_lost_at = None

    # Buffer for context
    retail_buf = []
    free_buf = []

    with open(args.retail, "r") as rf, open(args.free, "r") as ff:
        # Skip to start line
        for i in range(1, args.start):
            rf.readline()
            ff.readline()

        line_num = args.start
        while True:
            r_line = rf.readline()
            f_line = ff.readline()

            # Check for EOF
            if not r_line and not f_line:
                break
            if not r_line:
                print(f"*** Retail trace ended at line {line_num}")
                print(f"    Free trace continues: {f_line.strip()[:80]}")
                divergences.append(("EOF_RETAIL", line_num))
                break
            if not f_line:
                print(f"*** Free trace ended at line {line_num}")
                print(f"    Retail trace continues: {r_line.strip()[:80]}")
                divergences.append(("EOF_FREE", line_num))
                break

            r_norm = normalize_line(r_line, shift=0)
            f_norm = normalize_line(f_line, shift=4)

            # Skip comment lines
            if r_norm is None and f_norm is None:
                line_num += 1
                continue
            if r_norm is None or f_norm is None:
                print(f"*** Line {line_num}: misaligned (comment vs data)")
                print(f"    Retail: {r_line.strip()[:80]}")
                print(f"    Free:   {f_line.strip()[:80]}")
                divergences.append(("MISALIGN", line_num))
                line_num += 1
                continue

            checked += 1

            if r_norm != f_norm:
                if in_sync:
                    in_sync = False
                    sync_lost_at = line_num
                    print(f"{'='*70}")
                    print(f"DIVERGENCE #{len(divergences)+1} at line {line_num} "
                          f"(+{line_num - args.start} from start)")
                    print(f"{'='*70}")
                    if retail_buf:
                        print(f"\n  Last {len(retail_buf)} matching lines:")
                        for (ln, rl, fl) in zip(
                            range(line_num - len(retail_buf), line_num),
                            retail_buf, free_buf
                        ):
                            print(f"    {ln}: R={rl.strip()[:70]}")
                            print(f"    {ln}: F={fl.strip()[:70]}")

                    print(f"\n  Divergent line {line_num}:")
                    print(f"    Retail: {r_line.strip()}")
                    print(f"    Free:   {f_line.strip()}")
                    print(f"    R_norm: {r_norm}")
                    print(f"    F_norm: {f_norm}")
                    divergences.append(("DIVERGE", line_num, r_line.strip(), f_line.strip()))

                    if len(divergences) >= args.max_divergences:
                        print(f"\n*** Reached max divergences ({args.max_divergences})")
                        break
            else:
                if not in_sync:
                    print(f"  Re-synced at line {line_num} "
                          f"(lost sync for {line_num - sync_lost_at} lines)")
                    in_sync = True

            # Keep context buffer
            retail_buf.append(r_line)
            free_buf.append(f_line)
            if len(retail_buf) > args.context:
                retail_buf.pop(0)
                free_buf.pop(0)

            line_num += 1

            if args.max_check and checked >= args.max_check:
                break

            if checked % 500000 == 0:
                print(f"  ... checked {checked:,} lines (at line {line_num:,}), "
                      f"{len(divergences)} divergences so far")

    print(f"\n{'='*70}")
    print(f"SUMMARY")
    print(f"{'='*70}")
    print(f"  Lines checked: {checked:,}")
    print(f"  Divergences found: {len(divergences)}")
    if divergences:
        print(f"  First divergence at line: {divergences[0][1]}")
    else:
        print(f"  NO DIVERGENCES FOUND — traces are functionally identical")


if __name__ == "__main__":
    main()
