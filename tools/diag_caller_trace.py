#!/usr/bin/env python3
"""diag_caller_trace.py - Find who calls FUN_060423CC during system_init.

Key question: Does production call FUN_060423CC during system_init,
or does only the free build call it?

Method:
1. Breakpoint at system_init entry
2. After hitting, set breakpoints at FUN_060423CC AND main_loop
3. Continue: see which fires first
4. Capture PR (return address) to identify the caller
5. Read stack to trace the full call chain
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


def trace_build(name, cue, ipc_name, sys_init_addr, poll_addr, main_loop_addr):
    """Trace one build: find if FUN_060423CC is called during system_init."""
    MednafenInstance.kill_stale()

    ipc = os.path.join(TMPDIR, ipc_name)
    inst = MednafenInstance(name, cue, ipc)
    inst.start()

    print(f"\n{'='*60}")
    print(f"  {name}")
    print(f"  system_init=0x{sys_init_addr:08X}  poll=0x{poll_addr:08X}  main_loop=0x{main_loop_addr:08X}")
    print(f"{'='*60}")

    # Step 1: Run to _start
    inst.breakpoint(0x06003000)
    try:
        ack = inst.continue_exec()
        frame = parse_frame(ack)
        print(f"  _start at frame {frame}")
    except TimeoutError:
        print(f"  TIMEOUT at _start!")
        inst.quit(); MednafenInstance.kill_stale(); return
    inst.breakpoint_clear()

    # Step 2: Run to system_init entry
    inst.breakpoint(sys_init_addr)
    try:
        ack = inst.continue_exec()
        frame = parse_frame(ack)
        print(f"  system_init entered at frame {frame}")
    except TimeoutError:
        print(f"  TIMEOUT at system_init!")
        inst.quit(); MednafenInstance.kill_stale(); return
    inst.breakpoint_clear()

    # Step 3: Set breakpoints at BOTH poll function AND main_loop
    # Whichever fires first tells us if poll is called during init
    inst.breakpoint(poll_addr)
    inst.breakpoint(main_loop_addr)
    print(f"\n  Racing: FUN_060423CC (0x{poll_addr:08X}) vs main_loop (0x{main_loop_addr:08X})")

    try:
        ack = inst.continue_exec()
        pc = parse_pc(ack)
        frame = parse_frame(ack)

        if pc == poll_addr:
            print(f"  >>> FUN_060423CC HIT FIRST at frame {frame} <<<")
            print(f"  => Poll is called DURING system_init!")

            # Capture PR (caller's return address)
            regs = dump_regs(inst, ipc, "poll_entry")
            if regs:
                pr = regs['PR']
                sp = regs['R15']
                r4 = regs['R4']
                r5 = regs['R5']
                print(f"\n  Registers at FUN_060423CC entry:")
                print(f"    PR  = 0x{pr:08X}  (return address = caller)")
                print(f"    R15 = 0x{sp:08X}  (stack pointer)")
                print(f"    R4  = 0x{r4:08X}  (arg1)")
                print(f"    R5  = 0x{r5:08X}  (arg2)")

                # Read stack to get the full call chain
                # PR on stack was pushed before calling this function
                # The caller pushed its PR before JSR
                stack_data = dump_mem(inst, ipc, sp, 128, "stack")
                if stack_data:
                    print(f"\n  Stack dump (return addresses):")
                    for off in range(0, min(len(stack_data), 128), 4):
                        val = struct.unpack('>I', stack_data[off:off+4])[0]
                        # Check if it looks like a code address
                        if 0x06003000 <= val < 0x06070000:
                            print(f"    SP+0x{off:02X}: 0x{val:08X}  <-- code addr")
                        else:
                            print(f"    SP+0x{off:02X}: 0x{val:08X}")

            # Now check: does poll exit, or is it stuck?
            inst.breakpoint_clear()
            inst.breakpoint(main_loop_addr)
            print(f"\n  Waiting for main_loop after poll (15s timeout)...")
            try:
                # Manual timeout of 15 seconds
                inst._write_action("continue")
                time.sleep(0.1)
                deadline = time.time() + 15
                hit = False
                while time.time() < deadline:
                    ack = inst._read_ack()
                    if ack and "break" in ack:
                        hit = True
                        break
                    time.sleep(0.05)

                if hit:
                    pc2 = parse_pc(ack)
                    frame2 = parse_frame(ack)
                    print(f"  main_loop reached at frame {frame2} (poll returned)")
                else:
                    print(f"  TIMEOUT: main_loop never reached (poll stuck!)")
                    regs2 = dump_regs(inst, ipc, "stuck")
                    if regs2:
                        print(f"    Stuck at PC=0x{regs2['PC']:08X}")
            except Exception as e:
                print(f"  Error: {e}")

        elif pc == main_loop_addr:
            print(f"  >>> MAIN_LOOP HIT FIRST at frame {frame} <<<")
            print(f"  => Poll is NOT called during system_init!")
            print(f"  => Free build takes a DIFFERENT code path during init")

        else:
            print(f"  >>> UNKNOWN breakpoint at 0x{pc:08X} frame {frame}")

    except TimeoutError:
        print(f"  TIMEOUT: neither poll nor main_loop reached!")
        regs = dump_regs(inst, ipc, "timeout")
        if regs:
            print(f"    Stuck at PC=0x{regs['PC']:08X} PR=0x{regs['PR']:08X}")

    inst.breakpoint_clear()
    inst.quit()
    time.sleep(1)
    MednafenInstance.kill_stale()


def main():
    print("=" * 70)
    print("  Caller Trace: Who calls FUN_060423CC during system_init?")
    print("=" * 70)

    # Production: no shift
    print("\n>>> PRODUCTION <<<")
    trace_build("PROD", CUE_PROD, "caller_prod",
                sys_init_addr=0x060030FC,
                poll_addr=0x060423CC,
                main_loop_addr=0x0600300A)

    time.sleep(2)

    # Free: +4 shift
    print("\n>>> FREE-LAYOUT <<<")
    trace_build("FREE", CUE_FREE, "caller_free",
                sys_init_addr=0x06003100,
                poll_addr=0x060423D0,
                main_loop_addr=0x0600300A)


if __name__ == "__main__":
    main()
