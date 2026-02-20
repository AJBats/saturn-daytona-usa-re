#!/usr/bin/env python3
"""find_menu_frame.py — Find the frame where the Daytona menu appears.

Runs a single build and takes screenshots at intervals to identify
when the screen changes from loading/SEGA logo to the actual menu.

Usage:
    python tools/find_menu_frame.py [--cue PATH] [--max-frames N] [--interval N]
"""

import os
import sys
import time
import subprocess
import argparse

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MEDNAFEN = os.path.join(PROJDIR, "mednafen", "src", "mednafen")
CUE_RETAIL = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)",
                          "Daytona USA (USA).cue")
CUE_FREE = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
TMPDIR = os.path.join(PROJDIR, ".tmp")
OUTDIR = os.path.join(PROJDIR, "build", "compare")


def win_to_wsl(path):
    path = path.replace("\\", "/")
    if len(path) >= 2 and path[1] == ":":
        drive = path[0].lower()
        return f"/mnt/{drive}{path[2:]}"
    return path


class MednafenInstance:
    def __init__(self, name, cue_path, ipc_dir):
        self.name = name
        self.cue_path = cue_path
        self.ipc_dir = ipc_dir
        self.ipc_dir_wsl = win_to_wsl(ipc_dir)
        self.action_file = os.path.join(ipc_dir, "mednafen_action.txt")
        self.ack_file = os.path.join(ipc_dir, "mednafen_ack.txt")
        self.process = None
        self.last_ack = ""
        self._cmd_seq = 0

    def start(self):
        os.makedirs(self.ipc_dir, exist_ok=True)
        for f in [self.action_file, self.ack_file]:
            if os.path.exists(f):
                os.remove(f)
        home_wsl = f"/tmp/mdfn_home_{self.name}"
        setup_cmd = (
            f'rm -rf "{home_wsl}" && '
            f'mkdir -p "{home_wsl}/.mednafen/firmware" '
            f'"{home_wsl}/.mednafen/pgconfig" '
            f'"{home_wsl}/.mednafen/cheats" '
            f'"{home_wsl}/.mednafen/snaps" '
            f'"{home_wsl}/.mednafen/sav" && '
            f'cp /root/.mednafen/firmware/* "{home_wsl}/.mednafen/firmware/" 2>/dev/null; true'
        )
        subprocess.run(["wsl", "-d", "Ubuntu", "-e", "bash", "-c", setup_cmd],
                       stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        mednafen_wsl = win_to_wsl(MEDNAFEN)
        cue_wsl = win_to_wsl(self.cue_path)
        launch_cmd = (
            f'export HOME="{home_wsl}" DISPLAY=:0; '
            f'rm -f "{home_wsl}/.mednafen/mednafen.lck"; '
            f'"{mednafen_wsl}" '
            f'--sound 0 --automation "{self.ipc_dir_wsl}" "{cue_wsl}"'
        )
        self.log_path = os.path.join(self.ipc_dir, "mednafen_stdout.log")
        self._log_file = open(self.log_path, "w")
        self.process = subprocess.Popen(
            ["wsl", "-d", "Ubuntu", "-e", "bash", "-c", launch_cmd],
            stdout=self._log_file, stderr=subprocess.PIPE,
        )
        ack = self._wait_ack("ready", timeout=30)
        print(f"  [{self.name}] {ack}")

    def _write_action(self, cmd):
        self._cmd_seq += 1
        padding = "." * (self._cmd_seq % 16)
        tmp = self.action_file + ".tmp"
        with open(tmp, "w", newline="\n") as f:
            f.write(f"# {self._cmd_seq}{padding}\n")
            f.write(cmd + "\n")
        if os.path.exists(self.action_file):
            os.remove(self.action_file)
        os.rename(tmp, self.action_file)

    def send(self, cmd, timeout=30):
        self.last_ack = self._read_ack() or ""
        self._write_action(cmd)
        if self.process and self.process.poll() is not None:
            raise RuntimeError(f"[{self.name}] exited (code={self.process.returncode})")
        return self._wait_ack_change(timeout=timeout)

    def _read_ack(self):
        try:
            with open(self.ack_file, "r") as f:
                return f.read().strip()
        except (FileNotFoundError, IOError):
            return None

    def _wait_ack(self, contains, timeout=30):
        deadline = time.time() + timeout
        while time.time() < deadline:
            ack = self._read_ack()
            if ack and contains in ack:
                return ack
            time.sleep(0.1)
        raise TimeoutError(f"[{self.name}] Timeout waiting for '{contains}'")

    def _wait_ack_change(self, timeout=30):
        deadline = time.time() + timeout
        while time.time() < deadline:
            ack = self._read_ack()
            if ack and ack != self.last_ack:
                self.last_ack = ack
                return ack
            time.sleep(0.05)
        raise TimeoutError(f"[{self.name}] Timeout (last ack: {self.last_ack[:80]})")

    def frame_advance(self, n=1, timeout=None):
        t = timeout or max(60, n * 2)
        ack = self.send(f"frame_advance {n}", timeout=t)
        if ack.startswith("ok frame_advance"):
            ack = self._wait_ack_change(timeout=t)
        return ack

    def screenshot(self, path):
        path_wsl = win_to_wsl(path)
        return self.send(f"screenshot {path_wsl}")

    def dump_regs(self):
        return self.send("dump_regs")

    def quit(self):
        try:
            self.send("quit", timeout=5)
        except Exception:
            pass
        if self.process:
            self.process.terminate()
            try:
                self.process.wait(timeout=5)
            except Exception:
                self.process.kill()
        if hasattr(self, '_log_file'):
            self._log_file.close()


def kill_stale():
    subprocess.run(["wsl", "-d", "Ubuntu", "-e", "bash", "-c",
                    "pkill -9 -f 'mednafen.*--automation' 2>/dev/null; true"],
                   stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    time.sleep(0.5)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--cue", default=CUE_RETAIL, help="CUE file to use")
    parser.add_argument("--free", action="store_true", help="Use free build disc")
    parser.add_argument("--max-frames", type=int, default=20000)
    parser.add_argument("--interval", type=int, default=2000,
                        help="Screenshot interval in frames")
    args = parser.parse_args()

    if args.free:
        args.cue = CUE_FREE

    os.makedirs(OUTDIR, exist_ok=True)
    kill_stale()

    name = "free" if args.free else "retail"
    ipc_dir = os.path.join(TMPDIR, f"find_menu_{name}")

    print(f"Finding menu frame for {name} build")
    print(f"CUE: {args.cue}")
    print(f"Max frames: {args.max_frames}, interval: {args.interval}")

    emu = MednafenInstance(name, args.cue, ipc_dir)
    emu.start()
    emu.send("deterministic")

    current_frame = 0
    BATCH = 50
    while current_frame < args.max_frames:
        target = min(current_frame + args.interval, args.max_frames)
        remaining = target - current_frame
        for start in range(0, remaining, BATCH):
            n = min(BATCH, remaining - start)
            try:
                emu.frame_advance(n, timeout=120)
            except TimeoutError:
                print(f"  *** HANG at frame ~{current_frame + start}")
                emu.quit()
                return
        current_frame = target

        # Take screenshot
        ss_path = os.path.join(OUTDIR, f"frame_{current_frame:05d}_{name}.png")
        try:
            emu.screenshot(ss_path)
            emu.frame_advance(1, timeout=30)
            current_frame += 1
            time.sleep(0.3)
        except Exception as e:
            print(f"  screenshot error at frame {current_frame}: {e}")

        # Get PC to show what code is running
        regs = emu.dump_regs()
        import re
        pc_match = re.search(r'PC=([0-9A-F]+)', regs)
        pc_val = pc_match.group(1) if pc_match else "?"
        size = os.path.getsize(ss_path) if os.path.exists(ss_path) else 0
        print(f"  frame {current_frame:5d}  PC={pc_val}  screenshot={size} bytes")

    emu.quit()
    print(f"\nDone. Screenshots in {OUTDIR}/")


if __name__ == "__main__":
    main()
