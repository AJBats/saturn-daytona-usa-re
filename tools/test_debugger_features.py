#!/usr/bin/env python3
"""Test debugger features after code review changes.

Validates: breakpoints, breakpoint_remove, step, dump_regs, dump_mem,
dump_mem_bin, watchpoint, watchpoint_clear, dump_cycle, status.

Usage:
    python tools/test_debugger_features.py [rebuilt|vanilla]
"""

import os
import sys
import time
import struct
import subprocess
import tempfile

PROJECT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def wsl_path(win_path):
    drive = win_path[0].lower()
    rest = win_path[2:].replace("\\", "/")
    return f"/mnt/{drive}{rest}"


class MednafenBot:
    def __init__(self, ipc_dir, cue_wsl, verbose=False):
        self.ipc_dir = ipc_dir
        self.action_file = os.path.join(ipc_dir, "mednafen_action.txt")
        self.ack_file = os.path.join(ipc_dir, "mednafen_ack.txt")
        self.seq = 0
        self.last_ack = ""
        self.proc = None
        self.stderr_file = None
        self.cue_wsl = cue_wsl
        self.verbose = verbose

    def start(self, timeout=30):
        mednafen_wsl = wsl_path(os.path.join(PROJECT, "mednafen", "src", "mednafen"))
        ipc_wsl = wsl_path(self.ipc_dir)
        for f in [self.action_file, self.ack_file]:
            if os.path.exists(f):
                os.remove(f)
        launch_cmd = (
            f'export DISPLAY=:0; '
            f'rm -f "$HOME/.mednafen/mednafen.lck"; '
            f'"{mednafen_wsl}" --sound 0 --automation "{ipc_wsl}" "{self.cue_wsl}"'
        )
        self.stderr_file = tempfile.NamedTemporaryFile(
            mode="w", suffix="_mednafen_stderr.txt", delete=False,
        )
        self.proc = subprocess.Popen(
            ["wsl", "-d", "Ubuntu", "-e", "bash", "-c", launch_cmd],
            stdout=subprocess.DEVNULL,
            stderr=self.stderr_file,
        )
        deadline = time.time() + timeout
        while time.time() < deadline:
            if os.path.exists(self.ack_file):
                with open(self.ack_file) as f:
                    content = f.read().strip()
                if "ready" in content:
                    self.last_ack = content
                    return True
            time.sleep(0.2)
        return False

    def send(self, cmd):
        self.seq += 1
        padding = "." * (self.seq % 16)
        tmp = self.action_file + ".tmp"
        with open(tmp, "w", newline="\n") as f:
            f.write(f"# {self.seq}{padding}\n")
            f.write(cmd + "\n")
        if os.path.exists(self.action_file):
            os.remove(self.action_file)
        os.rename(tmp, self.action_file)

    def wait_ack(self, keyword, timeout=30):
        deadline = time.time() + timeout
        while time.time() < deadline:
            if self.proc and self.proc.poll() is not None:
                return None
            if os.path.exists(self.ack_file):
                try:
                    with open(self.ack_file) as f:
                        content = f.read().strip()
                except (IOError, PermissionError):
                    time.sleep(0.05)
                    continue
                if content != self.last_ack and keyword in content:
                    self.last_ack = content
                    if self.verbose:
                        print(f"    [ack] {content[:120]}")
                    return content
            time.sleep(0.05)
        return None

    def cmd(self, command, keyword, timeout=30):
        if self.verbose:
            print(f"    [cmd] {command}")
        self.send(command)
        return self.wait_ack(keyword, timeout)

    def quit(self):
        if self.proc and self.proc.poll() is None:
            self.send("quit")
            try:
                self.proc.wait(timeout=5)
            except subprocess.TimeoutExpired:
                self.proc.kill()
        if self.stderr_file:
            self.stderr_file.close()
            try:
                os.unlink(self.stderr_file.name)
            except OSError:
                pass


def test_debugger(cue_wsl, verbose=False):
    ipc_dir = os.path.join(PROJECT, "build", "debugger_test_ipc")
    os.makedirs(ipc_dir, exist_ok=True)
    tmp_dir = os.path.join(PROJECT, "build", "debugger_test_tmp")
    os.makedirs(tmp_dir, exist_ok=True)

    bot = MednafenBot(ipc_dir, cue_wsl, verbose=verbose)
    passed = 0
    failed = 0
    errors = []

    def check(name, condition, detail=""):
        nonlocal passed, failed
        if condition:
            passed += 1
            print(f"  PASS: {name}")
        else:
            failed += 1
            errors.append(name)
            print(f"  FAIL: {name} -- {detail}")

    print("Launching Mednafen...")
    if not bot.start():
        print("FAIL: Mednafen did not start")
        return 1

    print("Mednafen ready. Running debugger tests...\n")

    # --- Boot a few frames so we have real code running ---
    ack = bot.cmd("frame_advance 200", "done frame_advance", timeout=120)
    check("frame_advance 200", ack and "done frame_advance" in ack, str(ack))

    # --- Test: status ---
    ack = bot.cmd("status", "status")
    check("status command", ack and "paused=true" in ack, str(ack))

    # --- Test: dump_cycle ---
    ack = bot.cmd("dump_cycle", "ok dump_cycle")
    check("dump_cycle", ack and "value=" in ack, str(ack))

    # --- Test: breakpoint set ---
    # BIOS reset vector area - 0x06000000 is Work RAM High start, game code lives here
    ack = bot.cmd("breakpoint 06004000", "ok breakpoint")
    check("breakpoint set", ack and "total=" in ack, str(ack))

    # --- Test: breakpoint_list ---
    ack = bot.cmd("breakpoint_list", "breakpoints")
    check("breakpoint_list shows bp",
          ack and "0x06004000" in ack and "count=1" in ack, str(ack))

    # --- Test: breakpoint_remove (new feature!) ---
    ack = bot.cmd("breakpoint_remove 06004000", "ok breakpoint_remove")
    check("breakpoint_remove", ack and "total=0" in ack, str(ack))

    # Verify it's gone
    ack = bot.cmd("breakpoint_list", "breakpoints")
    check("breakpoint_list empty after remove",
          ack and "count=0" in ack, str(ack))

    # --- Test: breakpoint + continue + hit ---
    # Set breakpoint at a commonly-executed address in BIOS/game loop
    # Use dump_regs first to get current PC, then set breakpoint ahead
    ack = bot.cmd("dump_regs", "R0=")
    check("dump_regs text", ack and "PC=" in ack, str(ack))
    if ack:
        # Parse PC from dump_regs
        for part in ack.split():
            if part.startswith("PC="):
                current_pc = part.split("=")[1]
                print(f"    Current PC: {current_pc}")
                break

    # --- Test: step ---
    ack = bot.cmd("step 5", "done step")
    check("step 5", ack and "done step" in ack and "pc=" in ack, str(ack))

    # --- Test: dump_regs after step ---
    ack = bot.cmd("dump_regs", "R0=")
    check("dump_regs after step", ack and "PC=" in ack and "PR=" in ack, str(ack))

    # --- Test: dump_regs_bin ---
    regs_bin_path = os.path.join(tmp_dir, "test_regs.bin")
    regs_bin_wsl = wsl_path(regs_bin_path)
    ack = bot.cmd(f"dump_regs_bin {regs_bin_wsl}", "ok dump_regs_bin")
    check("dump_regs_bin command", ack and "ok dump_regs_bin" in ack, str(ack))
    # Wait for file to appear
    time.sleep(0.5)
    if os.path.exists(regs_bin_path):
        data = open(regs_bin_path, "rb").read()
        check("dump_regs_bin file size (22 uint32s = 88 bytes)",
              len(data) == 88, f"got {len(data)} bytes")
        if len(data) == 88:
            regs = struct.unpack("<22I", data)
            print(f"    R0=0x{regs[0]:08X} PC=0x{regs[16]:08X} SR=0x{regs[17]:08X}")
    else:
        check("dump_regs_bin file exists", False, "file not found")

    # --- Test: dump_mem text (should work for small sizes) ---
    # Ack starts with "mem XXXXXXXX" followed by hex lines
    ack = bot.cmd("dump_mem 06000000 40", "mem 06000000")
    check("dump_mem text (64 bytes)", ack and "mem 06000000" in ack, str(ack)[:80])

    # --- Test: dump_mem_bin ---
    mem_bin_path = os.path.join(tmp_dir, "test_mem.bin")
    mem_bin_wsl = wsl_path(mem_bin_path)
    ack = bot.cmd(f"dump_mem_bin 06000000 100 {mem_bin_wsl}", "ok dump_mem_bin")
    check("dump_mem_bin command", ack and "ok dump_mem_bin" in ack, str(ack))
    time.sleep(0.5)
    if os.path.exists(mem_bin_path):
        data = open(mem_bin_path, "rb").read()
        check("dump_mem_bin file size (0x100 = 256 bytes)",
              len(data) == 256, f"got {len(data)} bytes")
    else:
        check("dump_mem_bin file exists", False, "file not found")

    # --- Test: dump_mem cap (should reject >4KB for text mode) ---
    ack = bot.cmd("dump_mem 06000000 2000", "dump_mem")
    # 0x2000 = 8192 bytes > 4096 cap, should get error
    check("dump_mem >4KB rejected",
          ack and ("error" in ack.lower() or "too large" in ack.lower() or "dump_mem_bin" in ack.lower()),
          str(ack)[:100])

    # --- Test: watchpoint set ---
    ack = bot.cmd("watchpoint 06010000", "ok watchpoint")
    check("watchpoint set", ack and "ok watchpoint" in ack, str(ack))

    # --- Test: watchpoint_clear ---
    ack = bot.cmd("watchpoint_clear", "ok watchpoint_clear")
    check("watchpoint_clear", ack and "ok watchpoint_clear" in ack, str(ack))

    # --- Test: breakpoint_clear ---
    # Add a couple breakpoints first
    bot.cmd("breakpoint 06001000", "ok breakpoint")
    bot.cmd("breakpoint 06002000", "ok breakpoint")
    ack = bot.cmd("breakpoint_clear", "ok breakpoint_clear")
    check("breakpoint_clear", ack and "removed=" in ack, str(ack))

    # Verify all gone
    ack = bot.cmd("breakpoint_list", "breakpoints")
    check("breakpoint_list empty after clear",
          ack and "count=0" in ack, str(ack))

    # --- Test: continue + breakpoint hit ---
    # Set a breakpoint, continue, and verify it fires
    # We need an address that will be hit - let's step first to find a nearby address
    ack = bot.cmd("step 1", "done step")
    if ack:
        # Parse pc from "done step pc=0xXXXXXXXX"
        for part in ack.split():
            if part.startswith("pc="):
                stepped_pc = part.split("=")[1]
                break
        else:
            stepped_pc = None

        if stepped_pc:
            # Set breakpoint at the PC we just stepped to, then continue
            # It should hit quickly if we're in a loop
            bp_addr = stepped_pc.replace("0x", "")
            bot.cmd(f"breakpoint {bp_addr}", "ok breakpoint")
            ack = bot.cmd("continue", "break pc=", timeout=10)
            check("continue + breakpoint hit",
                  ack and "break pc=" in ack, str(ack)[:100])
            bot.cmd(f"breakpoint_remove {bp_addr}", "ok breakpoint_remove")
        else:
            check("continue + breakpoint hit", False, "could not parse PC from step")
    else:
        check("continue + breakpoint hit", False, "step failed")

    # --- Test: secondary SH-2 register dump ---
    ack = bot.cmd("dump_slave_regs", "R0=")
    check("dump_slave_regs", ack and "PC=" in ack, str(ack)[:80])

    # --- Summary ---
    print(f"\n{'='*50}")
    print(f"Results: {passed} passed, {failed} failed")
    if errors:
        print(f"Failed tests:")
        for e in errors:
            print(f"  - {e}")
    print(f"{'='*50}")

    bot.quit()

    # Clean up temp files
    for f in os.listdir(tmp_dir):
        try:
            os.unlink(os.path.join(tmp_dir, f))
        except OSError:
            pass

    return 0 if failed == 0 else 1


def main():
    disc = sys.argv[1] if len(sys.argv) > 1 else "rebuilt"
    verbose = "-v" in sys.argv or "--verbose" in sys.argv

    if disc == "vanilla":
        cue_win = os.path.join(
            PROJECT, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue"
        )
    elif disc == "rebuilt":
        cue_win = os.path.join(
            PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue"
        )
    else:
        cue_win = disc

    cue_wsl = wsl_path(cue_win)
    print(f"Debugger feature test: {disc}")
    print(f"CUE: {cue_wsl}\n")

    return test_debugger(cue_wsl, verbose=verbose)


if __name__ == "__main__":
    sys.exit(main())
