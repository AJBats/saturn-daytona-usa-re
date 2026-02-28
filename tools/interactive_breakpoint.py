#!/usr/bin/env python3
"""interactive_breakpoint.py — Visual proof with breakpoint + screenshots.

Boots to menu, shows window, takes BEFORE screenshot, sets breakpoint at
the DOWN handler body (0x0601974C — only fires when DOWN is detected),
sends DOWN, catches breakpoint, takes AFTER screenshot, dumps registers.
"""

import os
import sys
import time
import subprocess

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MEDNAFEN_WSL = "/opt/mednafen_build/src/mednafen"
CUE = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
TMPDIR = os.path.join(PROJDIR, ".tmp", "interactive")

BOOT_TRACE = [
    (162,  "input START"),
    (167,  "input_release START"),
    (1174, "input START"),
    (1180, "input_release START"),
    (1360, "input START"),
    (1365, "input_release START"),
]
MENU_READY_FRAME = 1510

# Breakpoint: first instruction of DOWN handler body (line 117: mov.b r13, @r10)
# This instruction ONLY executes when the DOWN button mask (0x2000) is detected.
# 5 instructions before the write at PC=0x06019756.
DOWN_HANDLER_PC = 0x0601974C


def win_to_wsl(path):
    path = path.replace("\\", "/")
    if len(path) >= 2 and path[1] == ":":
        return f"/mnt/{path[0].lower()}{path[2:]}"
    return path


class Mednafen:
    def __init__(self):
        self.action_file = os.path.join(TMPDIR, "mednafen_action.txt")
        self.ack_file = os.path.join(TMPDIR, "mednafen_ack.txt")
        self.proc = None
        self.last_ack = ""
        self._seq = 0

    def start(self):
        os.makedirs(TMPDIR, exist_ok=True)
        for f in [self.action_file, self.ack_file]:
            if os.path.exists(f):
                os.remove(f)
        subprocess.run(["wsl", "-d", "Ubuntu", "-e", "bash", "-c",
                        "pkill -9 -f 'mednafen.*--automation' 2>/dev/null; true"],
                       stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        time.sleep(0.5)
        home = "/tmp/mdfn_interactive"
        subprocess.run(["wsl", "-d", "Ubuntu", "-e", "bash", "-c",
                        f'mkdir -p "{home}/.mednafen/firmware" && '
                        f'cp /root/.mednafen/firmware/* "{home}/.mednafen/firmware/" 2>/dev/null; true'],
                       stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        cmd = (f'export HOME="{home}" DISPLAY=:0 MEDNAFEN_ALLOWMULTI=1; '
               f'rm -f "{home}/.mednafen/mednafen.lck"; '
               f'"{MEDNAFEN_WSL}" --sound 0 --automation "{win_to_wsl(TMPDIR)}" '
               f'"{win_to_wsl(CUE)}"')
        self.proc = subprocess.Popen(
            ["wsl", "-d", "Ubuntu", "-e", "bash", "-c", cmd],
            stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        self._wait_contains("ready", 30)

    def send(self, cmd, timeout=30):
        self.last_ack = self._read_ack() or ""
        self._seq += 1
        tmp = self.action_file + ".tmp"
        with open(tmp, "w", newline="\n") as f:
            f.write(f"# {self._seq}{'.' * (self._seq % 16)}\n{cmd}\n")
        for _ in range(10):
            try:
                os.replace(tmp, self.action_file)
                break
            except PermissionError:
                time.sleep(0.1)
        return self._wait_change(timeout)

    def _read_ack(self):
        try:
            with open(self.ack_file) as f:
                return f.read().strip()
        except (FileNotFoundError, IOError):
            return None

    def _wait_contains(self, s, timeout):
        deadline = time.time() + timeout
        while time.time() < deadline:
            ack = self._read_ack()
            if ack and s in ack:
                return ack
            time.sleep(0.1)
        raise TimeoutError(f"Timeout waiting for '{s}'")

    def _wait_change(self, timeout):
        deadline = time.time() + timeout
        while time.time() < deadline:
            ack = self._read_ack()
            if ack and ack != self.last_ack:
                self.last_ack = ack
                return ack
            time.sleep(0.05)
        raise TimeoutError("Ack timeout")

    def frame_advance(self, n=1):
        ack = self.send(f"frame_advance {n}")
        if ack.startswith("ok frame_advance"):
            ack = self._wait_change(max(30, n))
        return ack

    def quit(self):
        try:
            self.send("quit", 5)
        except Exception:
            pass
        if self.proc:
            self.proc.terminate()
            self.proc.wait(5)


def main():
    print("=" * 60)
    print("INTERACTIVE BREAKPOINT: course_select_render DOWN handler")
    print("=" * 60)

    m = Mednafen()
    print("\n[1/7] Starting emulator...")
    m.start()
    print("  OK")

    print("[2/7] Booting to main menu...")
    frame = 0
    for target, action in BOOT_TRACE:
        if target > frame:
            m.frame_advance(target - frame)
            frame = target
        m.send(action)
    m.frame_advance(MENU_READY_FRAME - frame)
    frame = MENU_READY_FRAME
    print(f"  At menu (frame {frame})")

    print("[3/7] Showing Mednafen window...")
    m.send("show_window")
    m.frame_advance(30)  # Let it render a few frames so window appears
    print("  Window should be visible on your desktop via WSLg")

    print("[4/7] Taking BEFORE screenshot...")
    ss_before = os.path.join(TMPDIR, "before_down.png")
    m.send(f"screenshot {win_to_wsl(ss_before)}")
    m.frame_advance(1)
    print(f"  Saved: {ss_before}")

    print(f"[5/7] Setting breakpoint at 0x{DOWN_HANDLER_PC:08X} (DOWN handler body)...")
    ack = m.send(f"breakpoint {DOWN_HANDLER_PC:08X}")
    print(f"  {ack}")
    print("  This instruction ONLY runs when DOWN (0x2000) is detected.")

    print("[6/7] Pressing DOWN and waiting for breakpoint...")
    m.send("input DOWN")
    # Continue — the breakpoint should fire within the next frame
    m.last_ack = m._read_ack() or ""
    m._seq += 1
    tmp = m.action_file + ".tmp"
    with open(tmp, "w", newline="\n") as f:
        f.write(f"# {m._seq}{'.' * (m._seq % 16)}\ncontinue\n")
    for _ in range(10):
        try:
            os.replace(tmp, m.action_file)
            break
        except PermissionError:
            time.sleep(0.1)

    # Wait for breakpoint hit
    hit = None
    deadline = time.time() + 15
    while time.time() < deadline:
        ack = m._read_ack()
        if ack and "break" in ack and ack != m.last_ack:
            m.last_ack = ack
            hit = ack
            break
        time.sleep(0.05)

    if not hit:
        print("  ERROR: Breakpoint did not fire within 15s!")
        m.quit()
        return

    print(f"\n  >>> BREAKPOINT HIT! <<<")
    print(f"  {hit}")

    # Release DOWN
    m.send("input_release DOWN")

    # Dump registers
    print("\n[7/7] Dumping register state at breakpoint...")
    regs = m.send("dump_regs")
    print(f"\n{regs}")

    # Read selection index value
    mem = m.send("dump_mem 0605D244 1")
    print(f"\nsym_0605D244 (selection index): {mem}")

    # Advance a few frames to let the visual update, then screenshot
    m.send("breakpoint_clear")
    m.frame_advance(5)
    ss_after = os.path.join(TMPDIR, "after_down.png")
    m.send(f"screenshot {win_to_wsl(ss_after)}")
    m.frame_advance(1)
    print(f"\nAFTER screenshot: {ss_after}")

    print("\n" + "=" * 60)
    print("SUMMARY")
    print("=" * 60)
    print(f"Breakpoint 0x{DOWN_HANDLER_PC:08X} fired when DOWN was pressed.")
    print(f"This is inside course_select_render (0x060196B0 - 0x060197F4).")
    print(f"")
    print(f"Screenshots saved:")
    print(f"  BEFORE: {ss_before}")
    print(f"  AFTER:  {ss_after}")
    print(f"")
    print(f"Look at both screenshots and tell me what you see.")
    print("=" * 60)

    m.quit()
    print("\nDone.")


if __name__ == "__main__":
    main()
