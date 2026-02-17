#!/usr/bin/env python3
"""debug_stuck_loop.py -- Compare prod vs free-layout memory state at the busy-wait.

Runs both production and free-layout builds side by side.
Sets breakpoints at equivalent points and compares memory state.
"""
import os, sys, time, re, struct

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin, TMPDIR

CUE_REIMPL = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")

SHIFT = 16

# The busy-wait is in sym_06034E58 (inside FUN_06034E24)
# In prod: sym_06034E58 = 0x06034E58
# In free-layout: sym_06034E58 = 0x06034E58 + SHIFT = 0x06034E5C
BP_PROD = 0x06034E58
BP_FREE = 0x06034E58 + SHIFT


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
    """Dump memory and return bytes."""
    path = os.path.join(ipc_dir, f"mem_{tag}.bin")
    wsl_path = path.replace("D:", "/mnt/d").replace("\\", "/")
    inst.dump_mem_bin(addr, size, wsl_path)
    time.sleep(0.5)
    try:
        with open(path, "rb") as f:
            return f.read()
    except FileNotFoundError:
        return None


def print_mem(label, data, base_addr):
    """Print memory dump in hex."""
    if not data:
        print(f"  {label}: <no data>")
        return
    for i in range(0, len(data), 16):
        hex_vals = " ".join(f"{b:02X}" for b in data[i:i+16])
        print(f"  {label} 0x{base_addr+i:08X}: {hex_vals}")


def main():
    MednafenInstance.kill_stale()

    ipc_prod = os.path.join(TMPDIR, "stuck_prod")
    ipc_free = os.path.join(TMPDIR, "stuck_free")

    print("Starting both instances...")
    prod = MednafenInstance("prod", CUE_PROD, ipc_prod)
    free = MednafenInstance("free", CUE_REIMPL, ipc_free)
    prod.start()
    free.start()

    # Set breakpoints at sym_06034E58 in both builds
    print(f"\nBreakpoints: prod=0x{BP_PROD:08X}, free=0x{BP_FREE:08X}")
    prod.breakpoint(BP_PROD)
    free.breakpoint(BP_FREE)

    # Continue both to breakpoint
    print("\nContinuing prod...")
    try:
        ack_p = prod.continue_exec()
        pc_p = parse_pc(ack_p)
        print(f"  Prod hit: PC=0x{pc_p:08X} frame={parse_frame(ack_p)}")
    except TimeoutError:
        print("  Prod: TIMEOUT!")
        pc_p = None

    print("Continuing free...")
    try:
        ack_f = free.continue_exec()
        pc_f = parse_pc(ack_f)
        print(f"  Free hit: PC=0x{pc_f:08X} frame={parse_frame(ack_f)}")
    except TimeoutError:
        print("  Free: TIMEOUT!")
        pc_f = None

    if pc_p is None or pc_f is None:
        print("\nOne or both didn't reach the breakpoint!")
        if pc_p is not None:
            prod.send("quit")
        if pc_f is not None:
            free.send("quit")
        time.sleep(1)
        MednafenInstance.kill_stale()
        return

    # Dump registers at breakpoint
    print("\n=== Registers at sym_06034E58 ===")
    regs_p = dump_regs(prod, ipc_prod)
    regs_f = dump_regs(free, ipc_free)
    if regs_p and regs_f:
        for name in ["PC", "R0", "R1", "R2", "R3", "R4", "R5",
                      "R6", "R7", "R8", "R9", "R10", "R11", "R12",
                      "R13", "R14", "R15", "PR", "SR", "VBR", "GBR"]:
            vp = regs_p.get(name, 0)
            vf = regs_f.get(name, 0)
            diff = ""
            if vp != vf:
                delta = vf - vp
                if delta == SHIFT:
                    diff = f" [+{SHIFT} shift OK]"
                else:
                    diff = f" [DIFF! delta={delta}]"
            print(f"  {name:5s}: prod=0x{vp:08X}  free=0x{vf:08X}{diff}")

    # Dump key memory regions
    print("\n=== Memory comparison ===")

    # Compare memory at BOTH fixed and shifted addresses
    # In free-layout, sym_ADDR is at ADDR+SHIFT
    POOL_ADDRS = [0x06063578, 0x06063580, 0x06063584, 0x0606358C, 0x06059CAD]

    print(f"\n  --- Pool data comparison (prod@ADDR vs free@ADDR+{SHIFT}) ---")
    for sym_addr in POOL_ADDRS:
        shifted = sym_addr + SHIFT
        mem_p = dump_mem(prod, ipc_prod, sym_addr, 4, f"pool_{sym_addr:08X}_p")
        mem_f_fixed = dump_mem(free, ipc_free, sym_addr, 4, f"pool_{sym_addr:08X}_f_fixed")
        mem_f_shifted = dump_mem(free, ipc_free, shifted, 4, f"pool_{sym_addr:08X}_f_shifted")

        val_p = struct.unpack(">I", mem_p)[0] if mem_p else None
        val_f_fixed = struct.unpack(">I", mem_f_fixed)[0] if mem_f_fixed else None
        val_f_shifted = struct.unpack(">I", mem_f_shifted)[0] if mem_f_shifted else None

        match = "MATCH" if val_p == val_f_shifted else "MISMATCH"
        print(f"\n  sym_{sym_addr:08X}:")
        print(f"    prod @0x{sym_addr:08X} = 0x{val_p:08X}" if val_p is not None else f"    prod: <no data>")
        print(f"    free @0x{sym_addr:08X} (fixed)   = 0x{val_f_fixed:08X}" if val_f_fixed is not None else f"    free fixed: <no data>")
        print(f"    free @0x{shifted:08X} (shifted) = 0x{val_f_shifted:08X} [{match}]" if val_f_shifted is not None else f"    free shifted: <no data>")

        if val_p is not None and val_p != 0 and val_p < 0x10000000:
            deref = dump_mem(prod, ipc_prod, val_p, 4, f"deref_{sym_addr:08X}_p")
            if deref:
                print(f"    prod *0x{val_p:08X} = {' '.join(f'{b:02X}' for b in deref)}")

    # Also dump a wider block around the pool area to see byte-level shifts
    print(f"\n  --- Wide dump of pool area ---")
    wide_p = dump_mem(prod, ipc_prod, 0x06063570, 48, "wide_pool_p")
    wide_f = dump_mem(free, ipc_free, 0x06063570, 48, "wide_pool_f")
    wide_f_s = dump_mem(free, ipc_free, 0x06063570 + SHIFT, 48, "wide_pool_f_shifted")
    if wide_p:
        print_mem("prod @06063570", wide_p, 0x06063570)
    if wide_f:
        print_mem("free @06063570", wide_f, 0x06063570)
    if wide_f_s:
        print_mem(f"free @{0x06063570+SHIFT:08X}", wide_f_s, 0x06063570 + SHIFT)

    # Check interrupt vector table at VBR (0x06000000)
    # SH-2 vectors: each is 4 bytes, starting at VBR
    # Key vectors for Saturn: general illegal (4), slot illegal (6),
    # NMI (11), user break (12), VBlank-in (0x40), VBlank-out (0x41),
    # HBlank-in (0x42), Timer0 (0x43), Timer1 (0x44)
    print(f"\n=== Interrupt Vector Table (VBR=0x06000000) ===")
    vec_p = dump_mem(prod, ipc_prod, 0x06000000, 256, "vectors_p")
    vec_f = dump_mem(free, ipc_free, 0x06000000, 256, "vectors_f")
    if vec_p and vec_f:
        print("  Key vectors (prod vs free):")
        vec_names = {4: "GenIll", 6: "SlotIll", 11: "NMI", 12: "UserBrk",
                     0x40: "VBlankIn", 0x41: "VBlankOut", 0x42: "HBlankIn",
                     0x43: "Timer0", 0x44: "Timer1", 0x45: "DSP", 0x46: "SndReq",
                     0x47: "SysMan", 0x48: "Pad", 0x49: "Lev2DMA", 0x4A: "Lev1DMA", 0x4B: "Lev0DMA"}
        for vecnum, name in sorted(vec_names.items()):
            off = vecnum * 4
            if off + 4 <= len(vec_p) and off + 4 <= len(vec_f):
                vp = struct.unpack(">I", vec_p[off:off+4])[0]
                vf = struct.unpack(">I", vec_f[off:off+4])[0]
                diff = ""
                if vp != vf:
                    delta = vf - vp
                    if delta == SHIFT:
                        diff = f" [+{SHIFT} OK]"
                    else:
                        diff = f" [DIFF! delta={delta}]"
                else:
                    if vp >= 0x06003000 and vp < 0x06064000:
                        diff = " [STALE? code addr not shifted!]"
                print(f"    Vec 0x{vecnum:02X} ({name:10s}): prod=0x{vp:08X}  free=0x{vf:08X}{diff}")

    # Also check vectors 0x100-0x130 range (SCU interrupts)
    vec_p2 = dump_mem(prod, ipc_prod, 0x06000100, 128, "vectors_p2")
    vec_f2 = dump_mem(free, ipc_free, 0x06000100, 128, "vectors_f2")
    if vec_p2 and vec_f2:
        print("  SCU interrupt vectors (0x100+):")
        for i in range(0, min(len(vec_p2), len(vec_f2), 128), 4):
            vp = struct.unpack(">I", vec_p2[i:i+4])[0]
            vf = struct.unpack(">I", vec_f2[i:i+4])[0]
            if vp != vf or (vp >= 0x06003000 and vp < 0x06064000):
                vecnum = 0x40 + i // 4
                diff = ""
                if vp != vf:
                    delta = vf - vp
                    if delta == SHIFT:
                        diff = f" [+{SHIFT} OK]"
                    else:
                        diff = f" [DIFF! delta={delta}]"
                else:
                    if vp >= 0x06003000 and vp < 0x06064000:
                        diff = " [STALE? code addr not shifted!]"
                print(f"    Vec 0x{vecnum:02X}: prod=0x{vp:08X}  free=0x{vf:08X}{diff}")

    # Also dump the stack around SP to see call chain
    print(f"\n=== Stack dump ===")
    if regs_p:
        sp_p = regs_p['R15']
        stack_p = dump_mem(prod, ipc_prod, sp_p, 64, "stack_p")
        if stack_p:
            print(f"  prod stack (SP=0x{sp_p:08X}):")
            for i in range(0, min(len(stack_p), 64), 4):
                val = struct.unpack(">I", stack_p[i:i+4])[0]
                print(f"    0x{sp_p+i:08X}: 0x{val:08X}")

    if regs_f:
        sp_f = regs_f['R15']
        stack_f = dump_mem(free, ipc_free, sp_f, 64, "stack_f")
        if stack_f:
            print(f"  free stack (SP=0x{sp_f:08X}):")
            for i in range(0, min(len(stack_f), 64), 4):
                val = struct.unpack(">I", stack_f[i:i+4])[0]
                print(f"    0x{sp_f+i:08X}: 0x{val:08X}")

    prod.send("quit")
    free.send("quit")
    time.sleep(1)
    MednafenInstance.kill_stale()
    print("\nDone.")


if __name__ == "__main__":
    main()
