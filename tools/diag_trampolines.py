#!/usr/bin/env python3
"""diag_trampolines.py - Inspect interrupt handler trampolines.

The interrupt vectors point to stubs at 0x06000840-0x060008F0.
These stubs likely contain JMP or BSR to actual handlers in the
shifted code area. Check if these dispatch targets differ between builds.
"""

import os, sys, time, struct, re

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))
from parallel_compare import MednafenInstance, read_regs_bin

CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue")
CUE_FREE = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
TMPDIR = os.path.join(PROJDIR, ".tmp")


def parse_pc(ack):
    m = re.search(r'pc=0x([0-9a-fA-F]+)', ack)
    return int(m.group(1), 16) if m else None

def parse_frame(ack):
    m = re.search(r'frame=(\d+)', ack)
    return int(m.group(1)) if m else None

def dump_mem(inst, ipc_dir, addr, size, tag=""):
    path = os.path.join(ipc_dir, f"mem_{tag}.bin")
    inst.dump_mem_bin(addr, size, path)
    time.sleep(0.3)
    try:
        with open(path, 'rb') as f:
            return f.read()
    except FileNotFoundError:
        return None


def decode_sh2(data, base_addr):
    """Decode SH-2 instructions from raw bytes."""
    instrs = []
    for off in range(0, len(data) - 1, 2):
        w = struct.unpack('>H', data[off:off+2])[0]
        addr = base_addr + off

        # Decode common instructions
        hi = (w >> 12) & 0xF

        if hi == 0xD:  # MOV.L @(disp,PC),Rn
            n = (w >> 8) & 0xF
            disp = w & 0xFF
            ea = ((addr + 4) & ~3) + disp * 4
            instrs.append((addr, w, f"MOV.L @(0x{disp:02X}*4,PC),R{n}  EA=0x{ea:08X}"))
        elif hi == 0x9:  # MOV.W @(disp,PC),Rn
            n = (w >> 8) & 0xF
            disp = w & 0xFF
            ea = addr + 4 + disp * 2
            instrs.append((addr, w, f"MOV.W @(0x{disp:02X}*2,PC),R{n}  EA=0x{ea:08X}"))
        elif hi == 0xA:  # BRA disp
            disp = w & 0xFFF
            if disp & 0x800:
                disp = disp - 0x1000
            target = addr + 4 + disp * 2
            instrs.append((addr, w, f"BRA 0x{target:08X}"))
        elif hi == 0xB:  # BSR disp
            disp = w & 0xFFF
            if disp & 0x800:
                disp = disp - 0x1000
            target = addr + 4 + disp * 2
            instrs.append((addr, w, f"BSR 0x{target:08X}"))
        elif w == 0x000B:
            instrs.append((addr, w, "RTS"))
        elif w == 0x002B:
            instrs.append((addr, w, "RTE"))
        elif w == 0x0009:
            instrs.append((addr, w, "NOP"))
        elif hi == 0x4 and (w & 0xFF) == 0x2B:
            n = (w >> 8) & 0xF
            instrs.append((addr, w, f"JMP @R{n}"))
        elif hi == 0x4 and (w & 0xFF) == 0x0B:
            n = (w >> 8) & 0xF
            instrs.append((addr, w, f"JSR @R{n}"))
        elif hi == 0x6 and (w & 0xF) == 0x3:
            n = (w >> 8) & 0xF
            m = (w >> 4) & 0xF
            instrs.append((addr, w, f"MOV R{m},R{n}"))
        elif hi == 0x6 and (w & 0xF) == 0x2:
            n = (w >> 8) & 0xF
            m = (w >> 4) & 0xF
            instrs.append((addr, w, f"MOV.L @R{m},R{n}"))
        elif hi == 0x2 and (w & 0xF) == 0x2:
            n = (w >> 8) & 0xF
            m = (w >> 4) & 0xF
            instrs.append((addr, w, f"MOV.L R{m},@R{n}"))
        elif hi == 0xE:
            n = (w >> 8) & 0xF
            imm = w & 0xFF
            if imm & 0x80:
                imm = imm - 0x100
            instrs.append((addr, w, f"MOV #{imm},R{n}"))
        elif hi == 0x7:
            n = (w >> 8) & 0xF
            imm = w & 0xFF
            if imm & 0x80:
                imm = imm - 0x100
            instrs.append((addr, w, f"ADD #{imm},R{n}"))
        elif hi == 0x4 and (w & 0xFF) == 0x26:
            n = (w >> 8) & 0xF
            instrs.append((addr, w, f"LDS.L @R{n}+,PR"))
        elif hi == 0x4 and (w & 0xFF) == 0x22:
            n = (w >> 8) & 0xF
            instrs.append((addr, w, f"STS.L PR,@-R{n}"))
        elif hi == 0x4 and (w & 0xFF) == 0x0E:
            n = (w >> 8) & 0xF
            instrs.append((addr, w, f"LDC R{n},SR"))
        elif hi == 0x2 and (w & 0xF) == 0x6:
            n = (w >> 8) & 0xF
            m = (w >> 4) & 0xF
            instrs.append((addr, w, f"MOV.L R{m},@-R{n}"))
        elif hi == 0x6 and (w & 0xF) == 0x6:
            n = (w >> 8) & 0xF
            m = (w >> 4) & 0xF
            instrs.append((addr, w, f"MOV.L @R{m}+,R{n}"))
        else:
            instrs.append((addr, w, f"??? 0x{w:04X}"))

    return instrs


def test_build(name, cue, ipc_name, poll_addr, sys_init_addr):
    """Dump trampoline stubs in both builds."""
    MednafenInstance.kill_stale()

    ipc = os.path.join(TMPDIR, ipc_name)
    inst = MednafenInstance(name, cue, ipc)
    inst.start()

    print(f"\n{'='*60}")
    print(f"  {name}")
    print(f"{'='*60}")

    # Run to poll entry
    inst.breakpoint(sys_init_addr)
    try:
        ack = inst.continue_exec()
    except TimeoutError:
        print(f"  TIMEOUT!")
        inst.quit(); MednafenInstance.kill_stale(); return {}
    inst.breakpoint_clear()

    inst.breakpoint(poll_addr)
    try:
        ack = inst.continue_exec()
        print(f"  FUN_060423CC entered at frame {parse_frame(ack)}")
    except TimeoutError:
        print(f"  TIMEOUT!")
        inst.quit(); MednafenInstance.kill_stale(); return {}
    inst.breakpoint_clear()

    # Dump the trampoline area (0x06000800-0x06000A00)
    tramp_data = dump_mem(inst, ipc, 0x06000800, 0x200, "trampolines")

    results = {}
    if tramp_data and len(tramp_data) >= 0x200:
        # Decode the key interrupt handler stubs
        handlers = {
            0x06000840: "VBlank-IN",
            0x06000846: "VBlank-OUT",
            0x060008F0: "HBlank-IN",
            0x0600084C: "Timer 0",
            0x06000852: "Timer 1",
            0x06000858: "DSP End",
            0x0600085E: "Sound Req",
            0x06000864: "SMPC",
            0x0600086A: "PAD",
            0x06000870: "DMA L2",
            0x06000876: "DMA L1",
            0x0600087C: "DMA L0",
            0x06000882: "DMA Illegal",
            0x06000888: "Sprite End",
        }

        for addr, label in sorted(handlers.items()):
            off = addr - 0x06000800
            if off + 16 <= len(tramp_data):
                chunk = tramp_data[off:off+16]
                instrs = decode_sh2(chunk, addr)
                print(f"\n  {label} (0x{addr:08X}):")
                for iaddr, iword, desc in instrs[:6]:
                    print(f"    0x{iaddr:08X}: {iword:04X}  {desc}")

                # Look for dispatch targets (MOV.L from pool + JMP/JSR)
                for iaddr, iword, desc in instrs:
                    if "EA=" in desc:
                        ea = int(desc.split("EA=")[1], 16)
                        # Read the pool value
                        ea_off = ea - 0x06000800
                        if 0 <= ea_off + 4 <= len(tramp_data):
                            pool_val = struct.unpack('>I', tramp_data[ea_off:ea_off+4])[0]
                            print(f"    => Pool at 0x{ea:08X} = 0x{pool_val:08X}")
                            results[label] = pool_val

        # Also dump raw hex of the full trampoline area for comparison
        print(f"\n  Raw trampoline area (0x06000840-0x060008A0):")
        for off in range(0x40, 0xA0, 16):
            addr = 0x06000800 + off
            line = tramp_data[off:off+16]
            hex_str = " ".join(f"{b:02X}" for b in line)
            print(f"    0x{addr:08X}: {hex_str}")

    inst.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()
    return results


def main():
    print("=" * 70)
    print("  Interrupt Handler Trampoline Analysis")
    print("=" * 70)

    print("\n>>> PRODUCTION <<<")
    prod = test_build("PROD", CUE_PROD, "tramp_prod",
                      poll_addr=0x060423CC,
                      sys_init_addr=0x060030FC)

    time.sleep(2)

    print("\n>>> FREE-LAYOUT <<<")
    free = test_build("FREE", CUE_FREE, "tramp_free",
                      poll_addr=0x060423D0,
                      sys_init_addr=0x06003100)

    # Compare dispatch targets
    if prod and free:
        print(f"\n{'='*70}")
        print(f"  DISPATCH TARGET COMPARISON")
        print(f"{'='*70}")
        all_keys = sorted(set(list(prod.keys()) + list(free.keys())))
        for key in all_keys:
            pv = prod.get(key, 0)
            fv = free.get(key, 0)
            diff = fv - pv if (pv and fv) else 0
            if fv == pv + 4:
                status = "SHIFTED +4 (correct)"
            elif fv == pv:
                status = "IDENTICAL"
            else:
                status = f"*** DIFF = {diff:+d} ***"
            print(f"  {key:14s}: prod=0x{pv:08X} free=0x{fv:08X} {status}")


if __name__ == "__main__":
    main()
