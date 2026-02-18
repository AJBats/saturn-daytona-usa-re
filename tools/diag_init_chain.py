#!/usr/bin/env python3
"""diag_init_chain.py - Trace system_init callee chain in both builds.

Sets breakpoints at each function called by system_init to find where
the free build diverges. Also checks the event flag at the CORRECT
shifted address.
"""

import os
import sys
import time
import struct
import re

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin

CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")
CUE_FREE = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
TMPDIR = os.path.join(PROJDIR, ".tmp")

SHIFT = 4

def parse_pc(ack):
    m = re.search(r'pc=0x([0-9a-fA-F]+)', ack)
    return int(m.group(1), 16) if m else None

def parse_frame(ack):
    m = re.search(r'frame=(\d+)', ack)
    return int(m.group(1)) if m else None

def dump_regs(inst, ipc_dir, tag=""):
    path = os.path.join(ipc_dir, f"regs_{tag}.bin")
    inst.dump_regs_bin(path)
    time.sleep(0.3)
    return read_regs_bin(path)

def dump_mem(inst, ipc_dir, addr, size, tag=""):
    path = os.path.join(ipc_dir, f"mem_{tag}.bin")
    inst.dump_mem_bin(addr, size, path)
    time.sleep(0.3)
    try:
        with open(path, 'rb') as f:
            return f.read()
    except FileNotFoundError:
        return None


def trace_init(name, cue, ipc_name, shift=0):
    """Boot, wait for _start, then trace through system_init callees."""
    MednafenInstance.kill_stale()

    ipc = os.path.join(TMPDIR, ipc_name)
    inst = MednafenInstance(name, cue, ipc)
    inst.start()

    print(f"\n{'='*60}")
    print(f"  {name} (shift={shift})")
    print(f"{'='*60}")

    # Wait for _start
    inst.breakpoint(0x06003000)
    try:
        ack = inst.continue_exec()
        frame = parse_frame(ack)
        print(f"  _start at frame {frame}")
    except TimeoutError:
        print(f"  TIMEOUT!")
        inst.quit()
        MednafenInstance.kill_stale()
        return {}
    inst.breakpoint_clear()

    # system_init is the first callee from main
    sys_init = 0x060030FC + shift
    print(f"  system_init at 0x{sys_init:08X}")

    # Now trace: set breakpoint at system_init, then step through its callees
    inst.breakpoint(sys_init)
    try:
        ack = inst.continue_exec()
        print(f"  Entered system_init")
    except TimeoutError:
        print(f"  TIMEOUT waiting for system_init!")
        inst.quit()
        MednafenInstance.kill_stale()
        return {}
    inst.breakpoint_clear()

    # Read system_init's pool entries to find its callees
    # system_init loads callee addresses from its constant pool
    # Let me dump its code and pool to identify callees
    mem = dump_mem(inst, ipc, sys_init, 256, "sysinit_code")
    if mem and len(mem) >= 256:
        # Find pool entries (look for 4-byte values in 0x0600xxxx-0x0606xxxx range)
        print(f"\n  system_init pool entries (potential callees):")
        pool_addrs = []
        for off in range(0, 256, 4):
            val = struct.unpack('>I', mem[off:off+4])[0]
            if 0x06003000 <= val < 0x06070000:
                pool_addrs.append((sys_init + off, val))
        for addr, val in pool_addrs[:20]:
            print(f"    0x{addr:08X}: 0x{val:08X}")

    # Set breakpoints at key callees we know about from the init chain
    # These are production addresses; add shift for free build
    key_funcs = [
        (0x0603AC1C, "game_subsystem_init"),
        (0x06040010, "FUN_06040010"),
        (0x06040C98, "FUN_06040C98"),
        (0x06040B8E, "FUN_06040B8E (fall-through head)"),
        (0x06040B90, "FUN_06040B90 (event init)"),
        (0x060423CC, "FUN_060423CC (SCDQ poll)"),
        (0x060400D6, "cd_session_open"),
        (0x0603AE08, "FUN_0603AE08"),
    ]

    results = {}
    for prod_addr, label in key_funcs:
        addr = prod_addr + shift
        inst.breakpoint(addr)
        print(f"\n  Testing 0x{addr:08X} ({label})... ", end="", flush=True)
        try:
            # Use short timeout (5 seconds) — if we don't hit it quickly, move on
            inst.last_ack = inst._read_ack() or ""
            inst._write_action("continue")
            time.sleep(0.1)
            ack = inst._read_ack()
            if ack and ack.startswith("ok continue"):
                inst.last_ack = ack

            deadline = time.time() + 5
            hit = False
            while time.time() < deadline:
                ack = inst._read_ack()
                if ack and ack != inst.last_ack and "break" in ack:
                    inst.last_ack = ack
                    hit = True
                    break
                time.sleep(0.05)

            if hit:
                pc = parse_pc(ack)
                frame_val = parse_frame(ack)
                print(f"HIT at frame {frame_val}")
                results[label] = ("HIT", frame_val, pc)
            else:
                print(f"NOT HIT (5s timeout)")
                results[label] = ("MISS", None, None)
                # We're still running, need to pause
                inst.send("pause")

        except Exception as e:
            print(f"ERROR: {e}")
            results[label] = ("ERROR", None, None)

        inst.breakpoint_clear()

    # Check event flags at both possible addresses
    print(f"\n  Event flag checks:")
    for addr in [0x0606367C, 0x06063680]:
        val_mem = dump_mem(inst, ipc, addr, 4, f"evflag_{addr:08X}")
        if val_mem and len(val_mem) >= 4:
            val = struct.unpack('>I', val_mem[:4])[0]
            print(f"    0x{addr:08X} = 0x{val:08X}")

    # Check main loop address
    main_loop = 0x0600300A  # Same in both builds (within _start)
    inst.breakpoint(main_loop)
    print(f"\n  Checking main loop (0x{main_loop:08X}, 10s timeout)...", end="", flush=True)
    try:
        inst.last_ack = inst._read_ack() or ""
        inst._write_action("continue")
        time.sleep(0.1)
        ack = inst._read_ack()
        if ack and ack.startswith("ok continue"):
            inst.last_ack = ack

        deadline = time.time() + 10
        hit = False
        while time.time() < deadline:
            ack = inst._read_ack()
            if ack and ack != inst.last_ack and "break" in ack:
                inst.last_ack = ack
                hit = True
                break
            time.sleep(0.05)

        if hit:
            pc = parse_pc(ack)
            frame_val = parse_frame(ack)
            print(f" REACHED at frame {frame_val}")
        else:
            print(f" NOT REACHED")
            regs = dump_regs(inst, ipc, "final")
            if regs:
                print(f"    Stuck at PC=0x{regs['PC']:08X} PR=0x{regs['PR']:08X}")
    except Exception as e:
        print(f" ERROR: {e}")
    inst.breakpoint_clear()

    inst.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()
    return results


def main():
    print("=" * 70)
    print("  System Init Chain Trace")
    print("=" * 70)

    print("\n>>> PRODUCTION <<<")
    prod_results = trace_init("PROD", CUE_PROD, "chain_prod", shift=0)

    time.sleep(2)

    print("\n>>> FREE-LAYOUT <<<")
    free_results = trace_init("FREE", CUE_FREE, "chain_free", shift=SHIFT)

    # Compare
    print(f"\n{'='*70}")
    print(f"  COMPARISON")
    print(f"{'='*70}")
    all_keys = set(list(prod_results.keys()) + list(free_results.keys()))
    for key in sorted(all_keys):
        p = prod_results.get(key, ("N/A", None, None))
        f = free_results.get(key, ("N/A", None, None))
        match = "✓" if p[0] == f[0] else "*** DIFF ***"
        print(f"  {key:40s}  prod={p[0]:8s}  free={f[0]:8s}  {match}")


if __name__ == "__main__":
    main()
