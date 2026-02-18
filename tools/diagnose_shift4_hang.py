#!/usr/bin/env python3
"""diagnose_shift4_hang.py -- Find where the +4 free-layout build hangs.

Strategy:
  1. Boot the +4 free-layout disc
  2. Let it run for N seconds (enough to get past BIOS)
  3. Pause and read PC to see where it's stuck
  4. If in a known poll loop (SCDQ/ICF), read surrounding state
  5. Run production in parallel for comparison

This is a lightweight diagnostic - just answers "WHERE does it hang?"
"""
import os, sys, time, re, struct

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin, win_to_wsl, TMPDIR

CUE_REIMPL = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")

SHIFT = 4

# Key addresses in +4 build (from linker map)
KNOWN_LOOPS = {
    0x060423D0: "FUN_060423CC (SCDQ poll)",
    0x0600C014: "FUN_0600C010 (ICF poll)",
    0x06003100: "FUN_060030FC (init chain)",
}

# Production addresses for comparison
PROD_ADDRS = {
    "SCDQ": 0x060423CC,
    "ICF":  0x0600C010,
    "INIT": 0x060030FC,
}


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


def identify_location(pc, regs):
    """Try to identify what function PC is in."""
    # Check known loops
    for base, name in KNOWN_LOOPS.items():
        # PC might be anywhere within the function body
        if base <= pc < base + 0x100:
            return name

    # Check if it's in game code range
    if 0x06003000 <= pc < 0x06064000:
        return f"game code (shifted, original ~0x{pc - SHIFT:08X})"
    elif 0x06000000 <= pc < 0x06003000:
        return "vector/stack area"
    elif pc < 0x00080000:
        return "BIOS ROM"
    else:
        return "unknown"


def main():
    MednafenInstance.kill_stale()
    time.sleep(1)

    ipc_free = os.path.join(TMPDIR, "diag_shift4")

    print("=" * 60)
    print("  DIAGNOSTIC: +4 free-layout hang analysis")
    print("=" * 60)

    # Phase 1: Boot and advance frames
    print(f"\n[1] Starting +4 free-layout build...")
    free = MednafenInstance("free", CUE_REIMPL, ipc_free)
    free.start()

    # Automation mode starts paused — advance 600 frames (~10s at 60fps)
    print(f"    Advancing 600 frames (~10 seconds of emulation)...")
    try:
        ack = free.frame_advance(600)
        print(f"    Frame advance done: {ack}")
    except TimeoutError:
        print(f"    Frame advance timed out (expected if hung in poll loop)")
        # Emulator might be stuck — try pausing to read state
        pass

    # Phase 2: Pause and read PC
    print(f"\n[2] Pausing emulator...")
    try:
        ack = free.pause()
        print(f"    Ack: {ack}")
    except TimeoutError:
        print(f"    TIMEOUT on pause - emulator may have crashed")
        MednafenInstance.kill_stale()
        return

    regs = dump_regs(free, ipc_free)
    if not regs:
        print("    ERROR: Could not read registers")
        free.quit()
        return

    pc = regs['PC']
    location = identify_location(pc, regs)

    print(f"\n    ===================================")
    print(f"    PC = 0x{pc:08X}  ({location})")
    print(f"    ===================================")
    print(f"    PR  = 0x{regs['PR']:08X}")
    print(f"    SR  = 0x{regs['SR']:08X}")
    print(f"    SP  = 0x{regs['R15']:08X}")
    print(f"    VBR = 0x{regs['VBR']:08X}")
    for i in range(15):
        print(f"    R{i:<2d} = 0x{regs[f'R{i}']:08X}")

    # Phase 3: Step a few times to see if PC is stuck in a tight loop
    print(f"\n[3] Stepping 20 instructions to detect loop...")
    pcs = []
    for i in range(20):
        ack = free.step(1)
        r = dump_regs(free, ipc_free)
        if r:
            pcs.append(r['PC'])
            print(f"    step {i+1:2d}: PC=0x{r['PC']:08X} R0=0x{r['R0']:08X}")

    # Check if it's looping
    if len(pcs) >= 4:
        unique_pcs = set(pcs[-10:])
        if len(unique_pcs) <= 4:
            loop_min = min(unique_pcs)
            loop_max = max(unique_pcs)
            print(f"\n    DETECTED TIGHT LOOP: 0x{loop_min:08X} - 0x{loop_max:08X}")
            print(f"    {len(unique_pcs)} unique PCs in last 10 steps")
            orig_min = loop_min - SHIFT
            orig_max = loop_max - SHIFT
            print(f"    Original addresses: 0x{orig_min:08X} - 0x{orig_max:08X}")
        else:
            print(f"\n    Not a tight loop ({len(unique_pcs)} unique PCs)")

    # Phase 4: Dump memory around the stuck point
    print(f"\n[4] Dumping memory around PC...")
    code_mem = dump_mem(free, ipc_free, pc & ~0xF, 64, "code_at_pc")
    if code_mem:
        print(f"    Code bytes at PC (0x{pc & ~0xF:08X}):")
        for i in range(0, len(code_mem), 16):
            hex_vals = " ".join(f"{b:02X}" for b in code_mem[i:i+16])
            addr = (pc & ~0xF) + i
            marker = " <<< PC" if addr <= pc < addr + 16 else ""
            print(f"    0x{addr:08X}: {hex_vals}{marker}")

    # Phase 5: Check HIRQ register (for SCDQ diagnosis)
    print(f"\n[5] Checking CD Block HIRQ (0x25890008)...")
    hirq_mem = dump_mem(free, ipc_free, 0x25890008, 4, "hirq")
    if hirq_mem and len(hirq_mem) >= 2:
        hirq = struct.unpack(">H", hirq_mem[:2])[0]
        scdq = (hirq >> 10) & 1
        print(f"    HIRQ = 0x{hirq:04X}")
        print(f"    SCDQ bit (bit 10) = {scdq}")
        if scdq == 0:
            print(f"    ==> SCDQ not set — CD Block hasn't finished data query")
        else:
            print(f"    ==> SCDQ is set — should not be stuck here")

    # Phase 6: Check FTCSR (for ICF diagnosis)
    print(f"\n[6] Checking FRT FTCSR (0xFFFFFE11)...")
    # Note: SH-2 on-chip peripherals are at 0xFFFF8000+
    # In Saturn, cache-through is at 0x2XXXXXXX, but on-chip is always at 0xFFFFFExx
    ftcsr_mem = dump_mem(free, ipc_free, 0xFFFFFE10, 4, "ftcsr")
    if ftcsr_mem and len(ftcsr_mem) >= 2:
        ftcsr = ftcsr_mem[1]  # byte at 0xFFFFFE11
        icf = (ftcsr >> 7) & 1
        print(f"    FTCSR = 0x{ftcsr:02X}")
        print(f"    ICF bit (bit 7) = {icf}")
        if icf == 0:
            print(f"    ==> ICF not set — no input capture event")
        else:
            print(f"    ==> ICF is set — should not be stuck here")

    # Phase 7: Check interrupt vectors
    print(f"\n[7] Checking interrupt vector table (VBR=0x{regs['VBR']:08X})...")
    vbr = regs['VBR']
    vec_mem = dump_mem(free, ipc_free, vbr + 0x100, 64, "int_vectors")
    if vec_mem:
        vec_names = {0: "VBI", 1: "VBO", 2: "HBI", 3: "T0", 4: "T1",
                     5: "DSP", 6: "SndReq", 7: "SysMan", 8: "Pad",
                     9: "DMA2", 10: "DMA1", 11: "DMA0", 12: "DMAill", 13: "SprEnd"}
        print(f"    SCU interrupt vectors (VBR+0x100):")
        for i in range(0, min(len(vec_mem), 56), 4):
            val = struct.unpack(">I", vec_mem[i:i+4])[0]
            vec_idx = i // 4
            name = vec_names.get(vec_idx, f"#{vec_idx}")
            shifted = ""
            if 0x06003000 < val < 0x06064000:
                orig = val - SHIFT
                shifted = f" (orig ~0x{orig:08X})"
            print(f"    Vec {vec_idx:2d} ({name:8s}): 0x{val:08X}{shifted}")

    # Phase 8: Dump VBI handler stub
    print(f"\n[8] Dumping VBI handler at 0x06000840...")
    vbi_mem = dump_mem(free, ipc_free, 0x06000840, 32, "vbi_stub")
    if vbi_mem:
        print(f"    VBI handler code:")
        for i in range(0, len(vbi_mem), 16):
            hex_vals = " ".join(f"{b:02X}" for b in vbi_mem[i:i+16])
            print(f"    0x{0x06000840+i:08X}: {hex_vals}")
        # Decode first few instructions
        print(f"    Decoded:")
        for i in range(0, min(len(vbi_mem), 16), 2):
            opcode = struct.unpack(">H", vbi_mem[i:i+2])[0]
            addr = 0x06000840 + i
            print(f"      0x{addr:08X}: 0x{opcode:04X}")

    # Phase 9: Dump the full polling area and the sync variable
    print(f"\n[9] Dumping memory at 0x06002D84 (sync variable)...")
    sync_mem = dump_mem(free, ipc_free, 0x06002D80, 16, "sync_var")
    if sync_mem:
        for i in range(0, len(sync_mem), 4):
            val = struct.unpack(">I", sync_mem[i:i+4])[0]
            print(f"    0x{0x06002D80+i:08X}: 0x{val:08X}")

    # Phase 10: Dump low-RAM code area (0x06002000-0x060024FF) to see full routine
    print(f"\n[10] Dumping low-RAM code (0x060023D0-0x06002450)...")
    code_area = dump_mem(free, ipc_free, 0x060023D0, 0x80, "low_code")
    if code_area:
        for i in range(0, len(code_area), 16):
            hex_vals = " ".join(f"{b:02X}" for b in code_area[i:i+16])
            print(f"    0x{0x060023D0+i:08X}: {hex_vals}")

    free.quit()
    time.sleep(1)

    # Phase 11: Run production for comparison
    print(f"\n{'='*60}")
    print(f"  PRODUCTION COMPARISON")
    print(f"{'='*60}")
    ipc_prod = os.path.join(TMPDIR, "diag_prod")
    prod = MednafenInstance("prod", CUE_PROD, ipc_prod)
    prod.start()

    print(f"\n    Advancing 600 frames...")
    try:
        ack = prod.frame_advance(600)
        print(f"    Frame advance done: {ack}")
    except TimeoutError:
        print(f"    TIMEOUT")

    prod.pause()
    regs_p = dump_regs(prod, ipc_prod)
    if regs_p:
        pc_p = regs_p['PC']
        loc_p = identify_location(pc_p, regs_p)
        print(f"\n    Production PC = 0x{pc_p:08X}  ({loc_p})")
        print(f"    PR  = 0x{regs_p['PR']:08X}")
        print(f"    SP  = 0x{regs_p['R15']:08X}")

        # Dump production sync variable for comparison
        sync_prod = dump_mem(prod, ipc_prod, 0x06002D80, 16, "sync_var_prod")
        if sync_prod:
            print(f"\n    Production sync variable at 0x06002D80:")
            for i in range(0, len(sync_prod), 4):
                val = struct.unpack(">I", sync_prod[i:i+4])[0]
                print(f"    0x{0x06002D80+i:08X}: 0x{val:08X}")

        # Dump production interrupt vectors for comparison
        vbr_p = regs_p['VBR']
        vec_prod = dump_mem(prod, ipc_prod, vbr_p + 0x100, 64, "int_vectors_prod")
        if vec_prod:
            print(f"\n    Production interrupt vectors (VBR+0x100):")
            vec_names = {0: "VBI", 1: "VBO", 2: "HBI", 3: "T0", 4: "T1",
                         5: "DSP", 6: "SndReq", 7: "SysMan", 8: "Pad",
                         9: "DMA2", 10: "DMA1", 11: "DMA0"}
            for i in range(0, min(len(vec_prod), 48), 4):
                val = struct.unpack(">I", vec_prod[i:i+4])[0]
                vi = i // 4
                name = vec_names.get(vi, f"#{vi}")
                print(f"    Vec {vi:2d} ({name:8s}): 0x{val:08X}")

    prod.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()
    print("\nDone.")


if __name__ == "__main__":
    main()
