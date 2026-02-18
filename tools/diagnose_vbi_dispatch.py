#!/usr/bin/env python3
"""diagnose_vbi_dispatch.py -- Compare VBI dispatcher and low-RAM init between builds.

Dumps the shared interrupt dispatcher at 0x060008F0 and surrounding low-RAM
areas in both production and +4 builds to look for unsymbolized game code
addresses that didn't shift correctly.
"""
import os, sys, time, re, struct

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin, win_to_wsl, TMPDIR

CUE_REIMPL = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")

SHIFT = 4


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


def hex_dump(data, base_addr, label=""):
    """Print hex dump with 32-bit big-endian values annotated."""
    for i in range(0, len(data), 16):
        hex_vals = " ".join(f"{b:02X}" for b in data[i:i+16])
        # Also show as 32-bit words
        words = []
        for j in range(i, min(i+16, len(data)), 4):
            if j + 4 <= len(data):
                w = struct.unpack(">I", data[j:j+4])[0]
                words.append(f"0x{w:08X}")
        word_str = " ".join(words)
        print(f"  {label}0x{base_addr+i:08X}: {hex_vals:<50s} [{word_str}]")


def find_game_code_refs(data, base_addr, label, shift=0):
    """Find 32-bit values that look like game code addresses."""
    refs = []
    for i in range(0, len(data) - 3, 4):
        val = struct.unpack(">I", data[i:i+4])[0]
        if 0x06003000 <= val < 0x06064000:
            addr = base_addr + i
            expected_shift = val + shift if shift else val
            refs.append((addr, val, expected_shift))
    if refs:
        print(f"  {label} Game code references found:")
        for addr, val, expected in refs:
            note = ""
            if shift != 0:
                note = f" (should be 0x{expected:08X} if shifted)"
            print(f"    0x{addr:08X}: 0x{val:08X}{note}")
    else:
        print(f"  {label} No game code references found in this region")
    return refs


def main():
    MednafenInstance.kill_stale()
    time.sleep(1)

    print("=" * 60)
    print("  VBI DISPATCHER & LOW-RAM COMPARISON")
    print("=" * 60)

    # Start both instances and advance past init
    ipc_prod = os.path.join(TMPDIR, "vbi_prod")
    ipc_free = os.path.join(TMPDIR, "vbi_free")

    print("\nStarting production...")
    prod = MednafenInstance("prod", CUE_PROD, ipc_prod)
    prod.start()
    prod.frame_advance(400)  # Past init

    print("Starting +4 free-layout...")
    free = MednafenInstance("free", CUE_REIMPL, ipc_free)
    free.start()
    free.frame_advance(400)  # Past init

    prod.pause()
    free.pause()

    # Dump 1: VBI dispatcher at 0x060008F0 (256 bytes)
    print(f"\n{'='*60}")
    print(f"  VBI Dispatcher (0x060008F0, 256 bytes)")
    print(f"{'='*60}")

    for label, inst, ipc in [("PROD", prod, ipc_prod), ("FREE", free, ipc_free)]:
        mem = dump_mem(inst, ipc, 0x060008F0, 256, f"vbi_disp_{label}")
        if mem:
            print(f"\n  [{label}]:")
            hex_dump(mem, 0x060008F0, f"{label} ")
            find_game_code_refs(mem, 0x060008F0, label,
                                shift=SHIFT if label == "PROD" else 0)

    # Dump 2: Full interrupt handler stubs (0x06000800-0x060009FF)
    print(f"\n{'='*60}")
    print(f"  Interrupt Handler Stubs (0x06000800, 512 bytes)")
    print(f"{'='*60}")

    mem_p = dump_mem(prod, ipc_prod, 0x06000800, 512, "int_stubs_prod")
    mem_f = dump_mem(free, ipc_free, 0x06000800, 512, "int_stubs_free")

    if mem_p and mem_f:
        # Compare byte by byte
        diffs = []
        for i in range(min(len(mem_p), len(mem_f))):
            if mem_p[i] != mem_f[i]:
                diffs.append(i)

        if diffs:
            print(f"\n  DIFFERENCES: {len(diffs)} differing bytes in handler stubs!")
            # Show first 20 differences
            for i in diffs[:20]:
                addr = 0x06000800 + i
                print(f"    0x{addr:08X}: prod=0x{mem_p[i]:02X} free=0x{mem_f[i]:02X}")

            # Check if differences are 32-bit values shifted by +4
            print(f"\n  Checking if differences are shifted addresses:")
            for i in range(0, min(len(mem_p), len(mem_f)) - 3, 4):
                vp = struct.unpack(">I", mem_p[i:i+4])[0]
                vf = struct.unpack(">I", mem_f[i:i+4])[0]
                if vp != vf:
                    addr = 0x06000800 + i
                    delta = vf - vp
                    note = ""
                    if delta == SHIFT:
                        note = f" [+{SHIFT} shift OK]"
                    elif delta == -SHIFT:
                        note = f" [-{SHIFT} ??]"
                    elif 0x06003000 <= vp < 0x06064000 and delta == 0:
                        note = f" [STALE! should be +{SHIFT}]"
                    elif abs(delta) < 0x100:
                        note = f" [small delta={delta}]"
                    else:
                        note = f" [delta=0x{delta:08X}]"
                    print(f"    0x{addr:08X}: prod=0x{vp:08X} free=0x{vf:08X}{note}")
        else:
            print(f"\n  Handler stubs are IDENTICAL between builds")
            # But check for game code references that SHOULD differ
            print(f"\n  Checking for stale game code references:")
            find_game_code_refs(mem_p, 0x06000800, "PROD", shift=SHIFT)

    # Dump 3: Full low-RAM area (0x06002000-0x06002FFF)
    print(f"\n{'='*60}")
    print(f"  Low-RAM State (0x06002000, 4096 bytes)")
    print(f"{'='*60}")

    mem_p = dump_mem(prod, ipc_prod, 0x06002000, 4096, "lowram_prod")
    mem_f = dump_mem(free, ipc_free, 0x06002000, 4096, "lowram_free")

    if mem_p and mem_f:
        diffs = []
        for i in range(min(len(mem_p), len(mem_f))):
            if mem_p[i] != mem_f[i]:
                diffs.append(i)

        print(f"\n  {len(diffs)} differing bytes in low-RAM")

        if diffs:
            # Find game code addresses that differ
            print(f"\n  Game code address differences (0x0600XXXX range):")
            for i in range(0, min(len(mem_p), len(mem_f)) - 3, 4):
                vp = struct.unpack(">I", mem_p[i:i+4])[0]
                vf = struct.unpack(">I", mem_f[i:i+4])[0]
                if vp != vf:
                    addr = 0x06002000 + i
                    delta = vf - vp
                    if 0x06003000 <= vp < 0x06064000 or 0x06003000 <= vf < 0x06064000:
                        note = ""
                        if delta == SHIFT:
                            note = " [+4 shift OK]"
                        elif delta == 0 and 0x06003000 <= vp < 0x06064000:
                            note = " [STALE! game code addr not shifted]"
                        else:
                            note = f" [delta={delta}]"
                        print(f"    0x{addr:08X}: prod=0x{vp:08X} free=0x{vf:08X}{note}")

    # Dump 4: Interrupt vector table comparison (0x06000100-0x06000134)
    print(f"\n{'='*60}")
    print(f"  Interrupt Vector Table Detail")
    print(f"{'='*60}")

    vec_p = dump_mem(prod, ipc_prod, 0x06000100, 64, "vectors_prod2")
    vec_f = dump_mem(free, ipc_free, 0x06000100, 64, "vectors_free2")

    if vec_p and vec_f:
        for i in range(0, min(len(vec_p), len(vec_f)), 4):
            vp = struct.unpack(">I", vec_p[i:i+4])[0]
            vf = struct.unpack(">I", vec_f[i:i+4])[0]
            vec_idx = 0x40 + i // 4
            if vp != vf or (0x06003000 <= vp < 0x06064000):
                delta = vf - vp
                note = ""
                if delta == SHIFT:
                    note = " [+4 OK]"
                elif delta == 0 and 0x06003000 <= vp < 0x06064000:
                    note = " [STALE!]"
                else:
                    note = f" [delta={delta}]"
                print(f"  Vec 0x{vec_idx:02X}: prod=0x{vp:08X} free=0x{vf:08X}{note}")

    # Dump 5: CD Block registers
    print(f"\n{'='*60}")
    print(f"  CD Block Registers (0x25890000)")
    print(f"{'='*60}")

    for label, inst, ipc in [("PROD", prod, ipc_prod), ("FREE", free, ipc_free)]:
        cd = dump_mem(inst, ipc, 0x25890000, 64, f"cdblock_{label}")
        if cd:
            print(f"\n  [{label}]:")
            for i in range(0, min(len(cd), 32), 4):
                val = struct.unpack(">I", cd[i:i+4])[0]
                names = {0: "HIRQ", 4: "HMASK", 8: "CR1", 0xC: "CR2",
                         0x10: "CR3", 0x14: "CR4", 0x18: "MPEGRGB"}
                name = names.get(i, f"+0x{i:02X}")
                print(f"    {name:8s}: 0x{val:08X}")

    prod.quit()
    free.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()
    print("\nDone.")


if __name__ == "__main__":
    main()
