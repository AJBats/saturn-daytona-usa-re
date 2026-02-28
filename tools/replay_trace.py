#!/usr/bin/env python3
"""Replay an input trace headlessly and capture screenshots.

Parses a trace file from record_trace.py, replays all inputs at the exact
frame numbers via automation IPC, and captures screenshots at the same
frames where the user took them during recording.

Usage:
    python tools/replay_trace.py                              # default trace
    python tools/replay_trace.py build/golden_trace/arcade_full.txt
    python tools/replay_trace.py --disc vanilla               # use vanilla disc
"""

import os
import sys
import time
import subprocess
import argparse
import tempfile

PROJECT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def wsl_path(win_path):
    """Convert Windows path to WSL path."""
    drive = win_path[0].lower()
    rest = win_path[2:].replace("\\", "/")
    return f"/mnt/{drive}{rest}"


def parse_trace(trace_path):
    """Parse a trace file into a list of (frame, action) tuples.

    Returns list of:
      (frame, "input", button)
      (frame, "input_release", button)
      (frame, "screenshot", index)
    """
    events = []
    screenshot_idx = 0
    with open(trace_path) as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith("#"):
                continue
            # Parse: frame=NNN PRESS/RELEASE/SYSCMD BUTTON
            if not line.startswith("frame="):
                continue
            parts = line.split(None, 2)
            frame = int(parts[0].split("=")[1])
            action = parts[1]
            arg = parts[2] if len(parts) > 2 else ""

            if action == "PRESS":
                events.append((frame, "input", arg))
            elif action == "RELEASE":
                events.append((frame, "input_release", arg))
            elif action == "SYSCMD" and arg == "SCREENSHOT":
                events.append((frame, "screenshot", screenshot_idx))
                screenshot_idx += 1
    return events


class MednafenBot:
    """Drives WSL Mednafen via automation IPC (headless)."""

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
        """Launch Mednafen headless and wait for ready."""
        mednafen_wsl = wsl_path(os.path.join(PROJECT, "mednafen", "src", "mednafen"))
        ipc_wsl = wsl_path(self.ipc_dir)

        for f in [self.action_file, self.ack_file]:
            if os.path.exists(f):
                os.remove(f)

        launch_cmd = (
            f'export DISPLAY=:0; '
            f'rm -f "$HOME/.mednafen/mednafen.lck"; '
            f'"{mednafen_wsl}" '
            f'--sound 0 --automation "{ipc_wsl}" "{self.cue_wsl}"'
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
        """Send a command via action file."""
        self.seq += 1
        padding = "." * (self.seq % 16)
        tmp = self.action_file + ".tmp"
        with open(tmp, "w", newline="\n") as f:
            f.write(f"# {self.seq}{padding}\n")
            f.write(cmd + "\n")
        if os.path.exists(self.action_file):
            os.remove(self.action_file)
        os.rename(tmp, self.action_file)

    def wait_ack_change(self, keyword, timeout=30):
        """Wait for ack to change and contain keyword."""
        deadline = time.time() + timeout
        while time.time() < deadline:
            if self.proc and self.proc.poll() is not None:
                print(f"  [!] Mednafen exited (rc={self.proc.returncode})")
                return None
            if os.path.exists(self.ack_file):
                try:
                    with open(self.ack_file) as f:
                        content = f.read().strip()
                except (IOError, PermissionError):
                    time.sleep(0.05)
                    continue
                if self.verbose and content != self.last_ack:
                    print(f"  [ack] {content[:80]}")
                if content != self.last_ack and keyword in content:
                    self.last_ack = content
                    return content
            time.sleep(0.05)
        return None

    def send_and_wait(self, cmd, keyword, timeout=30):
        """Send command and wait for ack."""
        if self.verbose:
            print(f"  [send] {cmd}")
        self.send(cmd)
        return self.wait_ack_change(keyword, timeout)

    def quit(self):
        """Shutdown Mednafen."""
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


def main():
    parser = argparse.ArgumentParser(description="Replay trace and capture screenshots")
    parser.add_argument(
        "trace", nargs="?",
        default=os.path.join(PROJECT, "build", "golden_trace", "arcade_full.txt"),
        help="Path to trace file"
    )
    parser.add_argument(
        "--disc", default="rebuilt",
        help="vanilla, rebuilt, or path to CUE file"
    )
    parser.add_argument(
        "-v", "--verbose", action="store_true",
        help="Verbose IPC logging"
    )
    args = parser.parse_args()

    # Resolve disc
    if args.disc == "vanilla":
        cue_win = os.path.join(
            PROJECT, "external_resources", "Daytona USA (USA)", "Daytona USA (USA).cue"
        )
    elif args.disc == "rebuilt":
        cue_win = os.path.join(
            PROJECT, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue"
        )
    else:
        cue_win = args.disc

    if not os.path.exists(cue_win):
        print(f"ERROR: Disc not found: {cue_win}")
        return 1

    cue_wsl = wsl_path(cue_win)

    # Parse trace
    if not os.path.exists(args.trace):
        print(f"ERROR: Trace not found: {args.trace}")
        return 1

    events = parse_trace(args.trace)
    input_events = [(f, a, b) for f, a, b in events if a != "screenshot"]
    screenshot_events = [(f, idx) for f, a, idx in events if a == "screenshot"]

    print(f"Trace: {args.trace}")
    print(f"  {len(input_events)} input events, {len(screenshot_events)} screenshots")
    print(f"  Frames: {events[0][0]} - {events[-1][0]}")
    print()

    # Output directory
    output_dir = os.path.join(PROJECT, "build", "replay_screenshots")
    os.makedirs(output_dir, exist_ok=True)

    # Clean old screenshots
    for f in os.listdir(output_dir):
        if f.startswith("replay_") and f.endswith(".png"):
            os.remove(os.path.join(output_dir, f))

    # Launch
    ipc_dir = os.path.join(PROJECT, "build", "replay_ipc")
    os.makedirs(ipc_dir, exist_ok=True)

    bot = MednafenBot(ipc_dir, cue_wsl, verbose=args.verbose)

    print("Launching Mednafen (headless)...")
    if not bot.start():
        print("FAIL: Mednafen did not start in 30s")
        return 1
    print("Ready.")

    current_frame = 0
    screenshots_taken = 0

    for frame, action, arg in events:
        # Advance to target frame
        delta = frame - current_frame
        if delta > 0:
            ack = bot.send_and_wait(
                f"frame_advance {delta}",
                "done frame_advance",
                timeout=120,
            )
            if not ack:
                print(f"FAIL: frame_advance to {frame} timed out")
                bot.quit()
                return 1
            current_frame = frame

        # Execute action
        if action == "input":
            bot.send_and_wait(f"input {arg}", "ok input")
        elif action == "input_release":
            bot.send_and_wait(f"input_release {arg}", "ok input_release")
        elif action == "screenshot":
            idx = arg
            screenshot_path = os.path.join(output_dir, f"replay_{idx:04d}.png")
            screenshot_wsl = wsl_path(screenshot_path)
            ack = bot.send_and_wait(
                f"screenshot {screenshot_wsl}",
                "ok screenshot_queued",
            )
            if not ack:
                print(f"  screenshot {idx} FAILED (timeout)")
                continue

            # One more frame for capture
            bot.send_and_wait("frame_advance 1", "done frame_advance", timeout=30)
            current_frame += 1

            # Wait for file
            deadline = time.time() + 5
            while time.time() < deadline and not os.path.exists(screenshot_path):
                time.sleep(0.2)

            if os.path.exists(screenshot_path):
                screenshots_taken += 1
                print(f"  [{idx:02d}] frame {frame} - captured")
            else:
                print(f"  [{idx:02d}] frame {frame} - file not found!")

    bot.quit()

    print()
    print(f"Done. {screenshots_taken}/{len(screenshot_events)} screenshots captured.")
    print(f"Output: {output_dir}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
