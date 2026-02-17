#!/usr/bin/env python3
"""debug_start_pools.py -- Dump _start pool entries from both builds."""
import os, sys, time, struct

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin, TMPDIR

CUE_REIMPL = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")

SHIFT = 16

# _start pool entries (at 0x06003060 in both builds, since _start doesn't shift)
# These are the pool values loaded by mov.l @(disp, PC) in _start
POOL_LABELS = [
    "FUN_060030FC",   # offset 0x60
    "FUN_0600A392",   # offset 0x64
    "sym_06003000",   # offset 0x68
    "sym_0607EBC0",   # offset 0x6C
    "sym_0607EBC4",   # offset 0x70
    "sym_0605AD10",   # offset 0x74
    "sym_0607EBC8",   # offset 0x78
    # Jump table entries:
    "FUN_060088CC",   # offset 0x7C (state 0)
    "loc_0600890A",   # offset 0x80 (state 1)
    "FUN_06008938",   # offset 0x84 (state 2)
    "FUN_06008A18",   # offset 0x88 (state 3)
    "FUN_06008CCC",   # offset 0x8C (state 4)
    "FUN_06008D74",   # offset 0x90 (state 5)
    "FUN_06008B04",   # offset 0x94 (state 6)
    "FUN_06008B34",   # offset 0x98 (state 7)
    "FUN_06008B78",   # offset 0x9C (state 8)
    "FUN_06008B9C",   # offset 0xA0 (state 9)
    "FUN_06008BD8",   # offset 0xA4 (state 10)
    "FUN_06008BFC",   # offset 0xA8 (state 11)
    "FUN_06008E00",   # offset 0xAC (state 12)
    "FUN_06008E48",   # offset 0xB0 (state 13)
    "FUN_06008EBC",   # offset 0xB4 (state 14)
    "FUN_06009098",   # offset 0xB8 (state 15)
    "FUN_06009290",   # offset 0xBC (state 16)
    "FUN_060092D0",   # offset 0xC0 (state 17)
    "FUN_060096DC",   # offset 0xC4 (state 18)
    "FUN_06009788",   # offset 0xC8 (state 19)
    "FUN_06009A60",   # offset 0xCC (state 20)
    "FUN_06009C48",   # offset 0xD0 (state 21)
    "FUN_06009E60",   # offset 0xD4 (state 22)
    "FUN_06009F10",   # offset 0xD8 (state 23)
    "FUN_06009CFC",   # offset 0xDC (state 24)
    "FUN_06009D4E",   # offset 0xE0 (state 25)
    "FUN_06009DD0",   # offset 0xE4 (state 26)
    "FUN_06009E02",   # offset 0xE8 (state 27)
    "FUN_06009508",   # offset 0xEC (state 28)
    "FUN_0600955E",   # offset 0xF0 (state 29)
    "FUN_06008C14",   # offset 0xF4 (state 30)
    "FUN_06008C76",   # offset 0xF8 (state 31)
]


def dump_mem(inst, ipc_dir, addr, size, tag):
    path = os.path.join(ipc_dir, f"mem_{tag}.bin")
    wsl_path = path.replace("D:", "/mnt/d").replace("\\", "/")
    inst.dump_mem_bin(addr, size, wsl_path)
    time.sleep(0.5)
    try:
        with open(path, "rb") as f:
            return f.read()
    except FileNotFoundError:
        return None


def main():
    MednafenInstance.kill_stale()

    ipc_prod = os.path.join(TMPDIR, "sp_prod")
    ipc_free = os.path.join(TMPDIR, "sp_free")

    prod = MednafenInstance("prod", CUE_PROD, ipc_prod)
    free = MednafenInstance("free", CUE_REIMPL, ipc_free)
    prod.start()
    free.start()

    # Let both start, then pause immediately
    prod.send("continue")
    free.send("continue")
    time.sleep(3)
    prod.pause()
    free.pause()
    time.sleep(0.5)

    # Dump _start pool area from both
    POOL_BASE = 0x06003060
    POOL_SIZE = len(POOL_LABELS) * 4
    pool_p = dump_mem(prod, ipc_prod, POOL_BASE, POOL_SIZE, "pool_p")
    pool_f = dump_mem(free, ipc_free, POOL_BASE, POOL_SIZE, "pool_f")

    if not pool_p or not pool_f:
        print("Failed to dump pool area!")
        prod.send("quit")
        free.send("quit")
        time.sleep(1)
        MednafenInstance.kill_stale()
        return

    print("=== _start Pool Entries (0x06003060+) ===")
    print(f"{'Label':20s} {'Prod':>12s} {'Free':>12s} {'Delta':>8s} {'Status':s}")
    print("-" * 70)

    issues = []
    for i, label in enumerate(POOL_LABELS):
        off = i * 4
        vp = struct.unpack(">I", pool_p[off:off+4])[0]
        vf = struct.unpack(">I", pool_f[off:off+4])[0]
        delta = vf - vp

        # Determine expected behavior
        # FUN_ and loc_ labels are in code range -> should shift by SHIFT
        # sym_06003000 is _start itself -> stays (in .text.startup, no shift)
        # sym_0607xxxx are outside code range -> no shift
        # sym_0605AD10 is in code range -> should shift
        in_code_range = 0x06003000 <= vp <= 0x06063690
        in_startup = label == "sym_06003000"

        if in_startup:
            expected_delta = 0
        elif label.startswith("sym_0607") or label.startswith("sym_060A"):
            expected_delta = 0
        elif in_code_range:
            expected_delta = SHIFT
        else:
            expected_delta = 0  # fallback

        if delta == expected_delta:
            status = "OK"
        elif delta == 0 and expected_delta == SHIFT:
            status = "STALE! (should shift)"
            issues.append((label, vp, vf))
        else:
            status = f"UNEXPECTED (expected +{expected_delta})"
            issues.append((label, vp, vf))

        print(f"{label:20s} 0x{vp:08X}   0x{vf:08X}   {delta:+5d}   {status}")

    if issues:
        print(f"\n*** {len(issues)} ISSUES FOUND ***")
        for label, vp, vf in issues:
            print(f"  {label}: prod=0x{vp:08X}, free=0x{vf:08X} (SHOULD be 0x{vp+SHIFT:08X})")
    else:
        print("\n*** All pool entries correct ***")

    prod.send("quit")
    free.send("quit")
    time.sleep(1)
    MednafenInstance.kill_stale()
    print("\nDone.")


if __name__ == "__main__":
    main()
