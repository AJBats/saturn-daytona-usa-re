#!/usr/bin/env python3
"""diag_scdq_poll.py — SCDQ poll loop diagnostic.

Runs production and free (+4 shift) builds side by side in Mednafen,
captures PC traces around the SCDQ hang frame (~683), and analyzes
poll loop iteration counts to find exactly where they diverge.

NO BREAKPOINTS used — they mask the bug via observer effect.

Usage:
    python tools/diag_scdq_poll.py [--start-frame 675] [--end-frame 695]

Requires: Debug Mednafen with automation support.
"""

import os
import sys
import struct
import time
import argparse

# Add parent dir so we can import MednafenInstance
PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))

from parallel_compare import MednafenInstance, read_regs_bin

# Disc paths
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")
CUE_FREE = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
TMPDIR = os.path.join(PROJDIR, ".tmp", "scdq_diag")

# SCDQ poll loop addresses (FUN_060423CC internal structure)
# The poll loop body: jsr @r12, nop, extu.w, and, tst, bt, [bra loop-back]
# Production base: 0x060423CC
PROD_POLL_ENTRY    = 0x060423CC       # Function entry
PROD_POLL_JSR      = 0x060423DE       # jsr @r12 (read HIRQ) = base + 0x12
PROD_POLL_LOOPBACK = 0x060423F2       # bra back to jsr = base + 0x26
PROD_SCDQ_ACK      = 0x060423EA       # jsr @r11 (ack SCDQ) = base + 0x1E
PROD_POLL_EXIT     = 0x060423EE       # bra to epilogue = base + 0x22

# Free (+4 shift) base: 0x060423D0
FREE_POLL_ENTRY    = 0x060423D0
FREE_POLL_JSR      = 0x060423E2       # base + 0x12
FREE_POLL_LOOPBACK = 0x060423F6       # base + 0x26
FREE_SCDQ_ACK      = 0x060423EE       # base + 0x1E
FREE_POLL_EXIT     = 0x060423F2       # base + 0x22

# HIRQ register address (CD Block)
HIRQ_ADDR = 0x25890008

# Call chain addresses (for reference in call traces)
PROD_FUN_0603B21C = 0x0603B21C   # Retry loop
PROD_FUN_0603B424 = 0x0603B424   # CD command state machine
FREE_FUN_0603B21C = 0x0603B220
FREE_FUN_0603B424 = 0x0603B428


def analyze_pc_trace(trace_path, label, poll_jsr, poll_loopback, scdq_ack, poll_entry):
    """Analyze a PC trace file for SCDQ poll loop behavior.

    Returns dict with:
      - poll_iterations: number of times the loop-back BRA was hit
      - scdq_set: True if the SCDQ ack was reached
      - poll_entered: True if FUN_060423CC was entered
      - total_pcs: total instruction count in the frame
      - first_poll_pc_index: index of first poll loop PC (None if not entered)
    """
    result = {
        "poll_iterations": 0,
        "scdq_set": False,
        "poll_entered": False,
        "total_pcs": 0,
        "first_poll_pc_index": None,
        "poll_jsr_count": 0,
    }

    try:
        with open(trace_path, "rb") as f:
            data = f.read()
    except FileNotFoundError:
        print(f"  [{label}] WARNING: trace file not found: {trace_path}")
        return result

    n_pcs = len(data) // 4
    result["total_pcs"] = n_pcs

    if n_pcs == 0:
        return result

    # Parse all PCs (little-endian uint32 from x86 host)
    pcs = struct.unpack(f"<{n_pcs}I", data)

    for i, pc in enumerate(pcs):
        if pc == poll_entry and not result["poll_entered"]:
            result["poll_entered"] = True
            result["first_poll_pc_index"] = i
        if pc == poll_jsr:
            result["poll_jsr_count"] += 1
        if pc == poll_loopback:
            result["poll_iterations"] += 1
        if pc == scdq_ack:
            result["scdq_set"] = True

    return result


def analyze_call_trace(trace_path, label, poll_entry_addr, ack_addr):
    """Analyze a call trace for FUN_060423CC calls and SCDQ acks.

    Returns list of (line_num, caller_pc, target_addr) for relevant calls.
    """
    results = []
    try:
        with open(trace_path, "r") as f:
            for i, line in enumerate(f):
                line = line.strip()
                if not line:
                    continue
                # Format: "M|S <caller_PC-4> <target_addr>"
                parts = line.split()
                if len(parts) >= 3:
                    try:
                        target = int(parts[2], 16)
                        if target == poll_entry_addr or target == ack_addr:
                            results.append((i, parts[1], target))
                    except ValueError:
                        continue
    except FileNotFoundError:
        pass
    return results


def main():
    parser = argparse.ArgumentParser(description="SCDQ poll loop diagnostic")
    parser.add_argument("--start-frame", type=int, default=675,
                        help="Frame to start detailed tracing (default: 675)")
    parser.add_argument("--end-frame", type=int, default=695,
                        help="Frame to stop tracing (default: 695)")
    parser.add_argument("--skip-to", type=int, default=60,
                        help="Frame to fast-forward to initially (BIOS skip, default: 60)")
    args = parser.parse_args()

    os.makedirs(TMPDIR, exist_ok=True)
    ipc_prod = os.path.join(TMPDIR, "prod")
    ipc_free = os.path.join(TMPDIR, "free")

    print("=" * 70)
    print("SCDQ Poll Loop Diagnostic")
    print(f"Tracing frames {args.start_frame} to {args.end_frame}")
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

        # Start call traces
        ct_prod = os.path.join(TMPDIR, "call_trace_prod.txt")
        ct_free = os.path.join(TMPDIR, "call_trace_free.txt")
        ct_prod_wsl = f"/mnt/{ct_prod[0].lower()}{ct_prod[2:]}".replace("\\", "/")
        ct_free_wsl = f"/mnt/{ct_free[0].lower()}{ct_free[2:]}".replace("\\", "/")
        print("Starting call traces...")
        prod.send(f"call_trace {ct_prod_wsl}")
        free.send(f"call_trace {ct_free_wsl}")

        # Fast-forward to start frame
        advance = args.start_frame - args.skip_to
        if advance > 0:
            print(f"Fast-forwarding to frame {args.start_frame} ({advance} frames)...")
            prod.frame_advance(advance)
            free.frame_advance(advance)

        # Read what function pointer is at sym_060A5400 (the HIRQ read function)
        print("\nChecking HIRQ read function pointer at 0x060A5400...")
        ptr_prod_path = os.path.join(TMPDIR, "ptr_prod.bin")
        ptr_free_path = os.path.join(TMPDIR, "ptr_free.bin")
        prod.dump_mem_bin(0x060A5400, 4, ptr_prod_path)
        free.dump_mem_bin(0x060A5400, 4, ptr_free_path)
        try:
            with open(ptr_prod_path, "rb") as f:
                ptr_prod = struct.unpack(">I", f.read(4))[0]  # Big-endian (SH-2)
            print(f"  [prod] sym_060A5400 contains: 0x{ptr_prod:08X}")
        except Exception as e:
            print(f"  [prod] Could not read: {e}")
        try:
            with open(ptr_free_path, "rb") as f:
                ptr_free = struct.unpack(">I", f.read(4))[0]
            print(f"  [free] sym_060A5400 contains: 0x{ptr_free:08X}")
        except Exception as e:
            print(f"  [free] Could not read: {e}")

        # Frame-by-frame tracing
        print(f"\n{'='*70}")
        print(f"{'Frame':<8} {'Build':<6} {'PollIter':>10} {'SCDQ?':>6} {'TotalPCs':>10} {'PollEntry?':>11}")
        print(f"{'-'*70}")

        frame_results = []

        for frame_num in range(args.start_frame, args.end_frame + 1):
            # PC trace for both instances (this also advances 1 frame)
            trace_prod_path = os.path.join(TMPDIR, f"pctrace_prod_f{frame_num}.bin")
            trace_free_path = os.path.join(TMPDIR, f"pctrace_free_f{frame_num}.bin")

            ack_p = prod.pc_trace_frame(trace_prod_path)
            ack_f = free.pc_trace_frame(trace_free_path)

            # Dump registers after the frame
            regs_prod_path = os.path.join(TMPDIR, f"regs_prod_f{frame_num}.bin")
            regs_free_path = os.path.join(TMPDIR, f"regs_free_f{frame_num}.bin")
            prod.dump_regs_bin(regs_prod_path)
            free.dump_regs_bin(regs_free_path)

            # Dump HIRQ register at end of frame
            hirq_prod_path = os.path.join(TMPDIR, f"hirq_prod_f{frame_num}.bin")
            hirq_free_path = os.path.join(TMPDIR, f"hirq_free_f{frame_num}.bin")
            prod.dump_mem_bin(HIRQ_ADDR, 2, hirq_prod_path)
            free.dump_mem_bin(HIRQ_ADDR, 2, hirq_free_path)

            # Analyze PC traces
            res_p = analyze_pc_trace(
                trace_prod_path, "prod",
                PROD_POLL_JSR, PROD_POLL_LOOPBACK, PROD_SCDQ_ACK, PROD_POLL_ENTRY
            )
            res_f = analyze_pc_trace(
                trace_free_path, "free",
                FREE_POLL_JSR, FREE_POLL_LOOPBACK, FREE_SCDQ_ACK, FREE_POLL_ENTRY
            )

            # Read HIRQ values
            hirq_p = hirq_f = "????"
            try:
                with open(hirq_prod_path, "rb") as f:
                    hirq_p = f"{struct.unpack('>H', f.read(2))[0]:04X}"
            except Exception:
                pass
            try:
                with open(hirq_free_path, "rb") as f:
                    hirq_f = f"{struct.unpack('>H', f.read(2))[0]:04X}"
            except Exception:
                pass

            # Read PC from registers
            regs_p = read_regs_bin(regs_prod_path)
            regs_f = read_regs_bin(regs_free_path)
            pc_p = f"0x{regs_p['PC']:08X}" if regs_p else "????????"
            pc_f = f"0x{regs_f['PC']:08X}" if regs_f else "????????"

            scdq_p = "YES" if res_p["scdq_set"] else "no"
            scdq_f = "YES" if res_f["scdq_set"] else "no"
            entered_p = "YES" if res_p["poll_entered"] else "no"
            entered_f = "YES" if res_f["poll_entered"] else "no"

            print(f"f{frame_num:<7} {'prod':<6} {res_p['poll_iterations']:>10} {scdq_p:>6} {res_p['total_pcs']:>10} {entered_p:>11}  HIRQ={hirq_p} PC={pc_p}")
            print(f"{'':8} {'free':<6} {res_f['poll_iterations']:>10} {scdq_f:>6} {res_f['total_pcs']:>10} {entered_f:>11}  HIRQ={hirq_f} PC={pc_f}")

            frame_results.append((frame_num, res_p, res_f, hirq_p, hirq_f))

            # Flag divergence
            if res_p["poll_entered"] != res_f["poll_entered"]:
                print(f"  >>> DIVERGENCE: poll entered in one but not the other!")
            if res_p["scdq_set"] != res_f["scdq_set"] and res_p["poll_entered"] and res_f["poll_entered"]:
                print(f"  >>> DIVERGENCE: SCDQ set in prod but NOT in free!")
                print(f"  >>> Prod poll iterations: {res_p['poll_iterations']}, Free: {res_f['poll_iterations']}")
            if res_f["poll_iterations"] > 50000:
                print(f"  >>> FREE BUILD STUCK: {res_f['poll_iterations']} poll iterations (likely infinite)")

        # Stop call traces
        print(f"\n{'='*70}")
        print("Stopping call traces...")
        prod.send("call_trace_stop")
        free.send("call_trace_stop")

        # Analyze call traces
        print("\nCall trace analysis (FUN_060423CC calls):")
        ct_prod_calls = analyze_call_trace(ct_prod, "prod", PROD_POLL_ENTRY, PROD_SCDQ_ACK)
        ct_free_calls = analyze_call_trace(ct_free, "free", FREE_POLL_ENTRY, FREE_SCDQ_ACK)

        print(f"  [prod] {len(ct_prod_calls)} relevant calls found:")
        for linenum, caller, target in ct_prod_calls[:20]:
            fname = "FUN_060423CC" if target == PROD_POLL_ENTRY else "FUN_060349B6 (SCDQ ack)"
            print(f"    line {linenum}: caller={caller} → {fname}")
        if len(ct_prod_calls) > 20:
            print(f"    ... and {len(ct_prod_calls) - 20} more")

        print(f"  [free] {len(ct_free_calls)} relevant calls found:")
        for linenum, caller, target in ct_free_calls[:20]:
            fname = "FUN_060423CC" if target == FREE_POLL_ENTRY else "FUN_060349B6 (SCDQ ack)"
            print(f"    line {linenum}: caller={caller} → {fname}")
        if len(ct_free_calls) > 20:
            print(f"    ... and {len(ct_free_calls) - 20} more")

        # Summary
        print(f"\n{'='*70}")
        print("SUMMARY")
        print(f"{'='*70}")
        for frame_num, res_p, res_f, hirq_p, hirq_f in frame_results:
            if res_p["poll_entered"] or res_f["poll_entered"]:
                status_p = f"poll×{res_p['poll_iterations']}"
                if res_p["scdq_set"]:
                    status_p += " → SCDQ"
                status_f = f"poll×{res_f['poll_iterations']}"
                if res_f["scdq_set"]:
                    status_f += " → SCDQ"
                elif res_f["poll_iterations"] > 50000:
                    status_f += " → STUCK"
                print(f"  Frame {frame_num}: prod={status_p:30s} free={status_f}")

        print(f"\nTrace files saved to: {TMPDIR}")
        print("Done.")

    finally:
        print("\nShutting down...")
        prod.quit()
        free.quit()


if __name__ == "__main__":
    main()
