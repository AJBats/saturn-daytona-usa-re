#!/usr/bin/env python3
"""diagnose_scdq_second_call.py -- Analyze the 2nd SCDQ call that hangs in +4 build.

Sets BP at FUN_060423CC, skips the first hit, dumps state on the second hit.
Compares with production to find what's different about the second call.
"""
import os, sys, time, re, struct

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin, win_to_wsl, TMPDIR

CUE_REIMPL = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")

SHIFT = 4
BP_SCDQ_PROD = 0x060423CC
BP_SCDQ_FREE = 0x060423D0


def parse_pc(ack):
    m = re.search(r'pc=0x([0-9a-fA-F]+)', ack)
    return int(m.group(1), 16) if m else None


def parse_frame(ack):
    m = re.search(r'frame=(\d+)', ack)
    return int(m.group(1)) if m else None


def dump_regs(inst, ipc_dir):
    path = os.path.join(ipc_dir, "regs.bin")
    inst.dump_regs_bin(path)
    time.sleep(0.3)
    return read_regs_bin(path)


def dump_mem(inst, ipc_dir, addr, size, tag):
    path = os.path.join(ipc_dir, f"mem_{tag}.bin")
    wsl_path = win_to_wsl(path)
    inst.dump_mem_bin(addr, size, wsl_path)
    time.sleep(0.3)
    try:
        with open(path, "rb") as f:
            return f.read()
    except FileNotFoundError:
        return None


def analyze_scdq_entry(label, inst, ipc, bp_addr, func_start, shift=0):
    """Set BP at SCDQ function and analyze multiple hits."""
    results = []
    inst.breakpoint(bp_addr)

    for hit_num in range(1, 20):  # Up to 20 hits
        try:
            ack = inst.continue_exec()
            pc = parse_pc(ack)
            frame = parse_frame(ack)

            if pc != bp_addr:
                print(f"    [{label}] Hit {hit_num}: UNEXPECTED PC=0x{pc:08X}")
                break

            regs = dump_regs(inst, ipc)
            if not regs:
                break

            pr = regs['PR']
            # Caller address (JSR is 2 bytes before PR)
            caller = pr - 4 if shift == 0 else pr - 4

            result = {
                'hit': hit_num,
                'frame': frame,
                'pr': pr,
                'caller': caller,
                'sp': regs['R15'],
            }

            # After first few instructions, dump registers to see pool loads
            # Step past the prologue to get pool-loaded register values
            for _ in range(10):
                inst.step(1)

            regs2 = dump_regs(inst, ipc)
            if regs2:
                result['r11'] = regs2.get('R11', 0)
                result['r12'] = regs2.get('R12', 0)
                result['r13'] = regs2.get('R13', 0)
                result['r14'] = regs2.get('R14', 0)

            # Read HIRQ at this point
            hirq_mem = dump_mem(inst, ipc, 0x25890008, 4, f"hirq_{hit_num}")
            if hirq_mem and len(hirq_mem) >= 2:
                hirq = struct.unpack(">H", hirq_mem[:2])[0]
                result['hirq'] = hirq
                result['scdq'] = (hirq >> 10) & 1

            # Read the caller's CD Block command setup (stack for context)
            stack_mem = dump_mem(inst, ipc, regs['R15'], 64, f"stack_{hit_num}")
            if stack_mem:
                result['stack'] = []
                for i in range(0, min(len(stack_mem), 64), 4):
                    val = struct.unpack(">I", stack_mem[i:i+4])[0]
                    result['stack'].append(val)

            results.append(result)
            print(f"    [{label}] Hit {hit_num}: frame={frame} PR=0x{pr:08X} "
                  f"SCDQ={result.get('scdq', '?')}")

            # If SCDQ is 0 on entry, this call will hang — report and stop
            if result.get('scdq', 1) == 0:
                print(f"    [{label}] >>> SCDQ=0 on entry! This call will HANG.")
                # Step a few more times to confirm it enters the poll loop
                for _ in range(20):
                    inst.step(1)
                regs3 = dump_regs(inst, ipc)
                if regs3:
                    print(f"    [{label}]     After 20 more steps: PC=0x{regs3['PC']:08X}")
                break

            # SCDQ is 1 — continue past this call (it will return quickly)
            inst.breakpoint_clear()
            inst.breakpoint(bp_addr)

        except TimeoutError:
            print(f"    [{label}] Hit {hit_num}: TIMEOUT")
            # Pause and read state
            try:
                inst.pause()
            except:
                pass
            regs = dump_regs(inst, ipc)
            if regs:
                print(f"    [{label}]     Stuck at PC=0x{regs['PC']:08X} PR=0x{regs['PR']:08X}")
            break

    inst.breakpoint_clear()
    return results


def main():
    MednafenInstance.kill_stale()
    time.sleep(1)

    print("=" * 60)
    print("  SCDQ Second-Call Analysis: Production vs +4")
    print("=" * 60)

    # Production
    print(f"\n--- PRODUCTION ---")
    ipc_prod = os.path.join(TMPDIR, "scdq2_prod")
    prod = MednafenInstance("prod", CUE_PROD, ipc_prod)
    prod.start()
    results_prod = analyze_scdq_entry("PROD", prod, ipc_prod, BP_SCDQ_PROD,
                                       BP_SCDQ_PROD, shift=0)
    prod.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()
    time.sleep(0.5)

    # +4 Free-layout
    print(f"\n--- +4 FREE-LAYOUT ---")
    ipc_free = os.path.join(TMPDIR, "scdq2_free")
    free = MednafenInstance("free", CUE_REIMPL, ipc_free)
    free.start()
    results_free = analyze_scdq_entry("+4", free, ipc_free, BP_SCDQ_FREE,
                                       BP_SCDQ_FREE, shift=SHIFT)
    free.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()

    # Summary comparison
    print(f"\n{'='*60}")
    print(f"  SUMMARY")
    print(f"{'='*60}")

    max_hits = max(len(results_prod), len(results_free))
    print(f"\n  {'Hit':>3s}  {'PROD frame':>10s}  {'PROD SCDQ':>9s}  {'PROD PR':>12s}  "
          f"{'FREE frame':>10s}  {'FREE SCDQ':>9s}  {'FREE PR':>12s}")
    print(f"  {'---':>3s}  {'----------':>10s}  {'---------':>9s}  {'--------':>12s}  "
          f"{'----------':>10s}  {'---------':>9s}  {'--------':>12s}")

    for i in range(max_hits):
        rp = results_prod[i] if i < len(results_prod) else None
        rf = results_free[i] if i < len(results_free) else None
        p_frame = f"{rp['frame']:>10d}" if rp else f"{'N/A':>10s}"
        p_scdq = f"{rp.get('scdq', '?'):>9}" if rp else f"{'N/A':>9s}"
        p_pr = f"0x{rp['pr']:08X}" if rp else f"{'N/A':>12s}"
        f_frame = f"{rf['frame']:>10d}" if rf else f"{'N/A':>10s}"
        f_scdq = f"{rf.get('scdq', '?'):>9}" if rf else f"{'N/A':>9s}"
        f_pr = f"0x{rf['pr']:08X}" if rf else f"{'N/A':>12s}"
        print(f"  {i+1:>3d}  {p_frame}  {p_scdq}  {p_pr}  {f_frame}  {f_scdq}  {f_pr}")

    # Compare pool-loaded registers for each hit
    print(f"\n  Pool-loaded registers per hit:")
    for i in range(max_hits):
        rp = results_prod[i] if i < len(results_prod) else None
        rf = results_free[i] if i < len(results_free) else None
        if rp and rf:
            print(f"\n  Hit {i+1}:")
            for reg in ['r11', 'r12', 'r13', 'r14']:
                vp = rp.get(reg, 0)
                vf = rf.get(reg, 0)
                delta = vf - vp
                note = ""
                if delta == SHIFT:
                    note = " [+4 OK]"
                elif delta == 0:
                    if 0x06003000 <= vp < 0x06064000:
                        note = " [STALE!]"
                    else:
                        note = " [same]"
                elif 0x06003000 <= vp < 0x06064000:
                    note = f" [WRONG delta={delta}]"
                print(f"    {reg.upper()}: prod=0x{vp:08X} free=0x{vf:08X}{note}")

    print("\nDone.")


if __name__ == "__main__":
    main()
