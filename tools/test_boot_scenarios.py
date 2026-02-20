#!/usr/bin/env python3
"""test_boot_scenarios.py — Prove whether automation/deterministic mode affects boot.

Runs the RETAIL disc under 4 different automation configurations and takes
screenshots at fixed intervals. If the game boots normally, attract mode
should appear around frame 700-900.

Test matrix:
  A) automation + deterministic + --sound 0   (our current trace setup)
  B) automation + no deterministic + --sound 0
  C) automation + no deterministic + sound ON
  D) automation + sound ON + free-run (no frame_advance, just `run`)

All screenshots go to build/boot_test/<test_name>/frame_NNNNN.png
"""

import os
import sys
import time
import subprocess

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MEDNAFEN = os.path.join(PROJDIR, "mednafen", "src", "mednafen")
CUE_RETAIL = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)",
                          "Daytona USA (USA).cue")
TMPDIR = os.path.join(PROJDIR, ".tmp")
OUTDIR = os.path.join(PROJDIR, "build", "boot_test")

SCREENSHOT_FRAMES = [200, 500, 800, 1100, 1500]


def win_to_wsl(path):
    path = path.replace("\\", "/")
    if len(path) >= 2 and path[1] == ":":
        drive = path[0].lower()
        return f"/mnt/{drive}{path[2:]}"
    return path


class MednafenInstance:
    """Minimal IPC wrapper — same protocol as compare_builds.py."""

    def __init__(self, name, cue_path, ipc_dir, sound_on=False):
        self.name = name
        self.cue_path = cue_path
        self.ipc_dir = ipc_dir
        self.ipc_dir_wsl = win_to_wsl(ipc_dir)
        self.action_file = os.path.join(ipc_dir, "mednafen_action.txt")
        self.ack_file = os.path.join(ipc_dir, "mednafen_ack.txt")
        self.sound_on = sound_on
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
        sound_flag = "" if self.sound_on else "--sound 0"
        launch_cmd = (
            f'export HOME="{home_wsl}" DISPLAY=:0; '
            f'rm -f "{home_wsl}/.mednafen/mednafen.lck"; '
            f'"{mednafen_wsl}" '
            f'{sound_flag} --automation "{self.ipc_dir_wsl}" "{cue_wsl}"'
        )
        self.log_path = os.path.join(self.ipc_dir, "mednafen_stdout.log")
        self._log_file = open(self.log_path, "w")
        self.process = subprocess.Popen(
            ["wsl", "-d", "Ubuntu", "-e", "bash", "-c", launch_cmd],
            stdout=self._log_file, stderr=subprocess.PIPE,
        )
        ack = self._wait_ack("ready", timeout=30)
        print(f"    [{self.name}] {ack}")

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


def run_frame_advance_test(test_name, deterministic, sound_on):
    """Tests A, B, C: use frame_advance in batches, screenshot at intervals."""
    print(f"\n{'='*60}")
    print(f"  TEST {test_name}")
    print(f"  deterministic={deterministic}  sound={'ON' if sound_on else 'OFF'}")
    print(f"  method: frame_advance in batches of 50")
    print(f"{'='*60}")

    out_dir = os.path.join(OUTDIR, test_name)
    os.makedirs(out_dir, exist_ok=True)

    ipc_dir = os.path.join(TMPDIR, f"boot_test_{test_name}")
    emu = MednafenInstance(test_name, CUE_RETAIL, ipc_dir, sound_on=sound_on)

    kill_stale()
    emu.start()

    if deterministic:
        print("    Setting deterministic mode...")
        emu.send("deterministic")

    current_frame = 0
    max_frame = max(SCREENSHOT_FRAMES)
    BATCH = 50
    screenshot_idx = 0

    while current_frame < max_frame and screenshot_idx < len(SCREENSHOT_FRAMES):
        next_ss = SCREENSHOT_FRAMES[screenshot_idx]
        target = min(current_frame + BATCH, next_ss)
        advance = target - current_frame

        if advance > 0:
            try:
                emu.frame_advance(advance, timeout=120)
            except TimeoutError:
                print(f"    *** HANG at frame ~{current_frame}")
                break
            current_frame = target

        if current_frame >= next_ss:
            ss_path = os.path.join(out_dir, f"frame_{next_ss:05d}.png")
            try:
                emu.screenshot(ss_path)
                emu.frame_advance(1, timeout=30)  # render the screenshot
                current_frame += 1
                time.sleep(0.3)
                size = os.path.getsize(ss_path) if os.path.exists(ss_path) else 0
                print(f"    frame {next_ss:5d}: screenshot {size:,} bytes -> {ss_path}")
            except Exception as e:
                print(f"    frame {next_ss:5d}: screenshot FAILED: {e}")
            screenshot_idx += 1

    emu.quit()
    print(f"    Done.")


def run_freerun_test(test_name):
    """Test D: send `run`, wait wall-clock time, then screenshot."""
    print(f"\n{'='*60}")
    print(f"  TEST {test_name}")
    print(f"  deterministic=NO  sound=ON")
    print(f"  method: free-run for 30s wall-clock, then screenshot")
    print(f"{'='*60}")

    out_dir = os.path.join(OUTDIR, test_name)
    os.makedirs(out_dir, exist_ok=True)

    ipc_dir = os.path.join(TMPDIR, f"boot_test_{test_name}")
    emu = MednafenInstance(test_name, CUE_RETAIL, ipc_dir, sound_on=True)

    kill_stale()
    emu.start()

    # Free-run: advance a large number of frames (emulator runs at full speed)
    print("    Sending run command (free-run)...")
    emu.send("run")

    # Wait 30 seconds of wall-clock time. The emulator should run at full speed
    # (or faster than real-time). 30 seconds at 60fps = 1800 frames minimum.
    print("    Waiting 30 seconds wall-clock...")
    time.sleep(30)

    # Pause and screenshot
    print("    Pausing for screenshot...")
    # Send frame_advance 1 to pause and get a clean frame
    try:
        emu.send("frame_advance 1", timeout=10)
        # Wait for it to finish
        emu._wait_ack("done", timeout=10)
    except Exception as e:
        print(f"    Pause failed: {e}")

    ss_path = os.path.join(out_dir, "after_30s_freerun.png")
    try:
        emu.screenshot(ss_path)
        emu.frame_advance(1, timeout=30)
        time.sleep(0.5)
        size = os.path.getsize(ss_path) if os.path.exists(ss_path) else 0
        print(f"    Screenshot: {size:,} bytes -> {ss_path}")
    except Exception as e:
        print(f"    Screenshot FAILED: {e}")

    # Also check what frame we're at
    try:
        ack = emu.send("status", timeout=5)
        print(f"    Status: {ack}")
    except Exception as e:
        print(f"    Status check failed: {e}")

    emu.quit()
    print(f"    Done.")


def main():
    if not os.path.exists(CUE_RETAIL):
        print(f"ERROR: Retail disc not found: {CUE_RETAIL}")
        sys.exit(1)
    if not os.path.exists(MEDNAFEN):
        print(f"ERROR: Mednafen not found: {MEDNAFEN}")
        sys.exit(1)

    os.makedirs(OUTDIR, exist_ok=True)
    kill_stale()

    print("="*60)
    print("  BOOT SCENARIO TEST")
    print("  Testing whether automation/deterministic mode affects boot")
    print(f"  Retail disc: {CUE_RETAIL}")
    print(f"  Screenshot frames: {SCREENSHOT_FRAMES}")
    print("="*60)

    # Test A: current approach (deterministic + sound off)
    run_frame_advance_test("A_determ_nosound", deterministic=True, sound_on=False)

    # Test B: no deterministic, sound off
    run_frame_advance_test("B_nodeterm_nosound", deterministic=False, sound_on=False)

    # Test C: no deterministic, sound on
    run_frame_advance_test("C_nodeterm_sound", deterministic=False, sound_on=True)

    # Test D: free-run (no frame stepping)
    run_freerun_test("D_freerun")

    # Summary
    print(f"\n{'='*60}")
    print("  RESULTS SUMMARY")
    print(f"{'='*60}")
    print(f"\n  All screenshots in: {OUTDIR}/")
    for test_name in ["A_determ_nosound", "B_nodeterm_nosound",
                      "C_nodeterm_sound", "D_freerun"]:
        test_dir = os.path.join(OUTDIR, test_name)
        if os.path.isdir(test_dir):
            files = sorted(os.listdir(test_dir))
            print(f"\n  {test_name}/")
            for f in files:
                fpath = os.path.join(test_dir, f)
                size = os.path.getsize(fpath)
                print(f"    {f}: {size:,} bytes")

    print("\n  Visual inspection needed:")
    print("  - If ALL tests show SEGA logo at frame 1500+, automation mode is broken")
    print("  - If Test D shows attract mode, the issue is frame_advance mechanism")
    print("  - If B/C show attract but A doesn't, deterministic mode is the issue")
    print("  - If all frame_advance tests fail but D works, CD timing is frame-advance-specific")


if __name__ == "__main__":
    main()
