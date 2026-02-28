#!/usr/bin/env python3
"""prove_down_handler.py — Minimal proof: what PC writes when DOWN is pressed on menu.

Boots to main menu, sets watchpoint on sym_0605D244 (selection index),
presses DOWN, reports the PC that changed the value. That's it.
"""

import os
import sys
import time
import subprocess

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MEDNAFEN_WSL = "/opt/mednafen_build/src/mednafen"
CUE = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
TMPDIR = os.path.join(PROJDIR, ".tmp", "prove_down")

# Boot timing from test_boot_auto.py
BOOT_TRACE = [
    (162,  "input START"),
    (167,  "input_release START"),
    (1174, "input START"),
    (1180, "input_release START"),
    (1360, "input START"),
    (1365, "input_release START"),
]
MENU_READY_FRAME = 1510


def win_to_wsl(path):
    path = path.replace("\\", "/")
    if len(path) >= 2 and path[1] == ":":
        return f"/mnt/{path[0].lower()}{path[2:]}"
    return path


class Mednafen:
    def __init__(self):
        self.ipc_dir = TMPDIR
        self.action_file = os.path.join(TMPDIR, "mednafen_action.txt")
        self.ack_file = os.path.join(TMPDIR, "mednafen_ack.txt")
        self.wp_file = os.path.join(TMPDIR, "watchpoint_hits.txt")
        self.proc = None
        self.last_ack = ""
        self._seq = 0

    def start(self):
        os.makedirs(TMPDIR, exist_ok=True)
        for f in [self.action_file, self.ack_file, self.wp_file]:
            if os.path.exists(f):
                os.remove(f)
        subprocess.run(["wsl", "-d", "Ubuntu", "-e", "bash", "-c",
                        "pkill -9 -f 'mednafen.*--automation' 2>/dev/null; true"],
                       stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        time.sleep(0.5)
        home = "/tmp/mdfn_prove"
        subprocess.run(["wsl", "-d", "Ubuntu", "-e", "bash", "-c",
                        f'mkdir -p "{home}/.mednafen/firmware" && '
                        f'cp /root/.mednafen/firmware/* "{home}/.mednafen/firmware/" 2>/dev/null; true'],
                       stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        cue_wsl = win_to_wsl(CUE)
        ipc_wsl = win_to_wsl(TMPDIR)
        cmd = (f'export HOME="{home}" DISPLAY=:0 MEDNAFEN_ALLOWMULTI=1; '
               f'rm -f "{home}/.mednafen/mednafen.lck"; '
               f'"{MEDNAFEN_WSL}" --sound 0 --automation "{ipc_wsl}" "{cue_wsl}"')
        log = open(os.path.join(TMPDIR, "stdout.log"), "w")
        err = open(os.path.join(TMPDIR, "stderr.log"), "w")
        self.proc = subprocess.Popen(
            ["wsl", "-d", "Ubuntu", "-e", "bash", "-c", cmd],
            stdout=log, stderr=err)
        self._wait_contains("ready", 30)
        print("Emulator ready.")

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
        raise TimeoutError("Timeout waiting for ack change")

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
    print("=== PROOF: What function handles DOWN on the main menu? ===\n")

    m = Mednafen()
    m.start()

    # Boot to main menu
    print("Booting to main menu...")
    frame = 0
    for target, action in BOOT_TRACE:
        if target > frame:
            m.frame_advance(target - frame)
            frame = target
        m.send(action)
    m.frame_advance(MENU_READY_FRAME - frame)
    frame = MENU_READY_FRAME
    print(f"At menu (frame {frame}).")

    # Screenshot to confirm we're on the menu
    ss = os.path.join(TMPDIR, "menu.png")
    m.send(f"screenshot {win_to_wsl(ss)}")
    m.frame_advance(1)
    frame += 1

    # Verify baseline value of sym_0605D244
    ack = m.send("dump_mem 0605D244 1")
    print(f"\nsym_0605D244 BEFORE pressing DOWN: {ack}")

    # Set watchpoint on sym_0605D244
    if os.path.exists(m.wp_file):
        os.remove(m.wp_file)
    ack = m.send("watchpoint 0605D244")
    print(f"Watchpoint set: {ack}")

    # Press DOWN
    print("\nPressing DOWN...")
    m.send("input DOWN")
    m.frame_advance(3)
    m.send("input_release DOWN")
    m.frame_advance(3)

    # Read the value after
    ack = m.send("dump_mem 0605D244 1")
    print(f"sym_0605D244 AFTER pressing DOWN: {ack}")

    # Read watchpoint hits
    hits = []
    try:
        with open(m.wp_file) as f:
            hits = [l.strip() for l in f if l.strip() and not l.startswith("#")]
    except FileNotFoundError:
        pass

    print(f"\n{'='*60}")
    print(f"WATCHPOINT HITS: {len(hits)}")
    print(f"{'='*60}")
    for hit in hits:
        print(f"  {hit}")
    print(f"{'='*60}")

    if hits:
        # Parse the first hit to extract PC
        parts = {}
        for token in hits[0].split():
            if "=" in token:
                k, v = token.split("=", 1)
                parts[k] = v
        pc = parts.get("pc", "?")
        old = parts.get("old", "?")
        new = parts.get("new", "?")
        print(f"\nVERDICT: Instruction at PC={pc} changed sym_0605D244")
        print(f"         from {old} to {new} when DOWN was pressed.")
        print(f"\nThis is the function that handles DOWN on the main menu.")
    else:
        print("\nNo watchpoint hits detected!")
        # Check stderr for WP-DBG
        try:
            with open(os.path.join(TMPDIR, "stderr.log")) as f:
                dbg = [l.strip() for l in f if "WP-DBG" in l]
            if dbg:
                print(f"\nWP-DBG lines ({len(dbg)}):")
                for l in dbg[:20]:
                    print(f"  {l}")
        except FileNotFoundError:
            pass

    m.quit()
    print("\nDone.")


if __name__ == "__main__":
    main()
