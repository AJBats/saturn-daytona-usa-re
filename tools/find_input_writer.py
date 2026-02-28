#!/usr/bin/env python3
"""find_input_writer.py — Find what code writes to the button state word.

Sets a watchpoint on sym_06063D98 (the processed button state) and logs
which PC writes to it. This identifies the ONE input processing function
that converts raw SMPC data into the game's button state format.

Also watches 0x06063D9C (possible analog axis) to find steering input processing.

Usage:
    python tools/find_input_writer.py
"""

import os
import sys
import time
import subprocess

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))

# WSL-native build path (persistent)
MEDNAFEN_WSL = "/opt/mednafen_build/src/mednafen"
MEDNAFEN = os.path.join(PROJDIR, "mednafen", "src", "mednafen")
CUE = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
TMPDIR = os.path.join(PROJDIR, ".tmp", "input_writer")
SYMS_FILE = os.path.join(PROJDIR, "build", "aprog_syms.txt")


def win_to_wsl(path):
    path = path.replace("\\", "/")
    if len(path) >= 2 and path[1] == ":":
        drive = path[0].lower()
        return f"/mnt/{drive}{path[2:]}"
    return path


def load_syms(syms_file, map_file=None):
    """Load symbol map for address -> name lookup.

    Reads aprog_syms.txt (NAME = 0xADDR;) and optionally the linker map.
    """
    syms = {}
    # Load aprog_syms.txt format: NAME = 0xADDR;
    try:
        with open(syms_file) as f:
            for line in f:
                line = line.strip()
                if "=" in line and line.endswith(";"):
                    parts = line.rstrip(";").split("=")
                    if len(parts) == 2:
                        name = parts[0].strip()
                        try:
                            addr = int(parts[1].strip(), 16)
                            syms[addr] = name
                        except ValueError:
                            pass
    except FileNotFoundError:
        pass

    # Load linker map for renamed symbols (overrides FUN_ names)
    if map_file:
        try:
            with open(map_file) as f:
                for line in f:
                    line = line.strip()
                    # Lines like: 0x06008318                gear_shift_handler
                    if line.startswith("0x"):
                        parts = line.split()
                        if len(parts) >= 2 and not parts[1].startswith("0x"):
                            try:
                                addr = int(parts[0], 16)
                                name = parts[1]
                                if not name.endswith(".o"):
                                    syms[addr] = name
                            except ValueError:
                                pass
        except FileNotFoundError:
            pass

    return syms


def find_nearest_sym(addr, syms):
    """Find the nearest symbol at or before addr."""
    best_addr = None
    best_name = None
    for sa, sn in syms.items():
        if sa <= addr and (best_addr is None or sa > best_addr):
            best_addr = sa
            best_name = sn
    if best_name:
        offset = addr - best_addr
        if offset == 0:
            return best_name
        return f"{best_name}+0x{offset:X}"
    return f"0x{addr:08X}"


class MednafenInstance:
    def __init__(self, name, cue_path, ipc_dir):
        self.name = name
        self.cue_path = cue_path
        self.ipc_dir = ipc_dir
        self.ipc_dir_wsl = win_to_wsl(ipc_dir)
        self.action_file = os.path.join(ipc_dir, "mednafen_action.txt")
        self.ack_file = os.path.join(ipc_dir, "mednafen_ack.txt")
        self.watchpoint_file = os.path.join(ipc_dir, "watchpoint_hits.txt")
        self.process = None
        self.last_ack = ""
        self._cmd_seq = 0

    def start(self):
        os.makedirs(self.ipc_dir, exist_ok=True)
        for f in [self.action_file, self.ack_file, self.watchpoint_file]:
            if os.path.exists(f):
                os.remove(f)

        # Kill stale
        subprocess.run(["wsl", "-d", "Ubuntu", "-e", "bash", "-c",
                        "pkill -9 -f 'mednafen.*--automation' 2>/dev/null; true"],
                       stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        time.sleep(0.5)

        home_wsl = f"/tmp/mdfn_home_{self.name}"
        setup_cmd = (
            f'mkdir -p "{home_wsl}/.mednafen/firmware" '
            f'"{home_wsl}/.mednafen/pgconfig" '
            f'"{home_wsl}/.mednafen/cheats" '
            f'"{home_wsl}/.mednafen/snaps" '
            f'"{home_wsl}/.mednafen/sav" && '
            f'cp /root/.mednafen/firmware/* "{home_wsl}/.mednafen/firmware/" 2>/dev/null; true'
        )
        subprocess.run(["wsl", "-d", "Ubuntu", "-e", "bash", "-c", setup_cmd],
                       stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)

        mednafen_wsl = MEDNAFEN_WSL  # Use /tmp build directly
        cue_wsl = win_to_wsl(self.cue_path)

        launch_cmd = (
            f'export HOME="{home_wsl}" DISPLAY=:0 MEDNAFEN_ALLOWMULTI=1; '
            f'rm -f "{home_wsl}/.mednafen/mednafen.lck"; '
            f'"{mednafen_wsl}" '
            f'--sound 0 --automation "{self.ipc_dir_wsl}" "{cue_wsl}"'
        )
        self.log_path = os.path.join(self.ipc_dir, "mednafen_stdout.log")
        self._log_file = open(self.log_path, "w")
        self.stderr_path = os.path.join(self.ipc_dir, "mednafen_stderr.log")
        self._stderr_file = open(self.stderr_path, "w")
        self.process = subprocess.Popen(
            ["wsl", "-d", "Ubuntu", "-e", "bash", "-c", launch_cmd],
            stdout=self._log_file, stderr=self._stderr_file,
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
        # Retry atomic rename with fallback (DrvFS contention with WSL)
        for attempt in range(10):
            try:
                os.replace(tmp, self.action_file)
                return
            except PermissionError:
                time.sleep(0.1)
        # Final fallback: remove then rename
        try:
            os.remove(self.action_file)
        except FileNotFoundError:
            pass
        os.rename(tmp, self.action_file)

    def send(self, cmd, timeout=30):
        self.last_ack = self._read_ack() or ""
        self._write_action(cmd)
        if self.process and self.process.poll() is not None:
            raise RuntimeError(f"[{self.name}] process exited (code={self.process.returncode})")
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
        raise TimeoutError(f"[{self.name}] Timeout waiting for ack change")

    def frame_advance(self, n=1):
        ack = self.send(f"frame_advance {n}")
        if ack.startswith("ok frame_advance"):
            timeout = max(30, n)
            ack = self._wait_ack_change(timeout=timeout)
        return ack

    def read_watchpoint_hits(self):
        """Read all watchpoint hits from the log file."""
        hits = []
        try:
            with open(self.watchpoint_file, "r") as f:
                for line in f:
                    line = line.strip()
                    if line:
                        hits.append(line)
        except FileNotFoundError:
            pass
        return hits

    def quit(self):
        try:
            self.send("quit", timeout=5)
        except Exception:
            pass
        if self.process:
            self.process.terminate()
            self.process.wait(timeout=5)


def main():
    print("=== Finding Input State Writer ===")
    print(f"Target: watchpoint on 0x06063D98 (button state word)")
    print(f"Also:   watchpoint on 0x06063D9C (possible analog axis)")
    print()

    # Load symbol map
    MAP_FILE = os.path.join(PROJDIR, "reimpl", "build", "daytona.map")
    syms = load_syms(SYMS_FILE, MAP_FILE)
    print(f"Loaded {len(syms)} symbols from map file")

    # Check disc exists
    if not os.path.exists(CUE):
        print(f"ERROR: Disc not found at {CUE}")
        print(f"Run: make -C reimpl disc")
        sys.exit(1)

    inst = MednafenInstance("input", CUE, TMPDIR)

    print("Starting Mednafen...")
    inst.start()

    # Need lots of frames: BIOS (~60) + SEGA logo (~200) + disc load + title intro
    # Wait for attract mode where "PRESS START BUTTON" appears
    print("Advancing 700 frames (past BIOS + logos + into attract mode)...")
    inst.frame_advance(700)

    # Take screenshot to confirm we're at attract/title
    screenshot_path = os.path.join(TMPDIR, "screen_state.png")
    inst.send(f"screenshot {win_to_wsl(screenshot_path)}")
    inst.frame_advance(1)
    print(f"  Screenshot saved to: {screenshot_path}")

    # Now press START at the title screen
    print("Pressing START at title screen...")
    inst.send("input START")
    inst.frame_advance(10)
    inst.send("input_release START")
    inst.frame_advance(120)  # Wait for mode select to load

    screenshot2_path = os.path.join(TMPDIR, "screen_state2.png")
    inst.send(f"screenshot {win_to_wsl(screenshot2_path)}")
    inst.frame_advance(1)
    print(f"  Screenshot 2 saved to: {screenshot2_path}")

    # First, let's see what's at 0x06063D98 before and after pressing buttons
    print("\n=== Memory probe: check if button state is at 0x06063D98 ===")
    ack = inst.send("dump_mem 06063D90 20")
    print(f"  Before buttons: {ack}")

    inst.send("input LEFT")
    inst.frame_advance(5)
    ack = inst.send("dump_mem 06063D90 20")
    print(f"  During LEFT:    {ack}")

    inst.send("input_release LEFT")
    inst.frame_advance(5)
    ack = inst.send("dump_mem 06063D90 20")
    print(f"  After release:  {ack}")

    inst.send("input START")
    inst.frame_advance(5)
    ack = inst.send("dump_mem 06063D90 20")
    print(f"  During START:   {ack}")

    inst.send("input_release START")
    inst.frame_advance(5)

    # Also check the raw SMPC struct at 0x060A4C9C
    print("\n=== Check raw SMPC struct at 0x060A4C9C ===")
    ack = inst.send("dump_mem 060A4C90 30")
    print(f"  Raw SMPC:       {ack}")

    # CLEAN STATE: release all buttons and wait for state to settle
    print("\n=== Establishing clean baseline ===")
    inst.send("input_clear")
    inst.frame_advance(10)  # Wait for game to process release
    ack = inst.send("dump_mem 06063D98 4")
    print(f"  After clearing all inputs: {ack}")

    # Now set watchpoint on CLEAN state
    print("\n=== Setting watchpoint on 0x06063D98 ===")
    ack = inst.send("watchpoint 06063D98")
    print(f"  Watchpoint: {ack}")

    # Press LEFT to trigger a value CHANGE (from 0x0000 to 0x4000)
    print("Pressing LEFT to trigger watchpoint...")
    inst.send("input LEFT")
    inst.frame_advance(5)
    inst.send("input_release LEFT")
    inst.frame_advance(5)

    # Read hits for button state
    hits = inst.read_watchpoint_hits()
    print(f"\n=== Watchpoint Hits: {len(hits)} ===")

    # Deduplicate by PC
    pc_counts = {}
    for hit in hits:
        # Format: pc=0xXXXXXXXX pr=0xXXXXXXXX addr=0xXXXXXXXX old=0xXXXXXXXX new=0xXXXXXXXX frame=N
        parts = {}
        for token in hit.split():
            if "=" in token:
                k, v = token.split("=", 1)
                parts[k] = v
        pc = parts.get("pc", "unknown")
        pr = parts.get("pr", "unknown")
        addr = parts.get("addr", "unknown")
        old_val = parts.get("old", "?")
        new_val = parts.get("new", "?")
        frame = parts.get("frame", "?")

        key = (pc, pr, addr)
        if key not in pc_counts:
            pc_counts[key] = {"count": 0, "example_old": old_val, "example_new": new_val, "frames": []}
        pc_counts[key]["count"] += 1
        pc_counts[key]["frames"].append(frame)

    print(f"\nUnique PC/PR/Addr combinations: {len(pc_counts)}")
    print("-" * 80)
    for (pc, pr, addr), info in sorted(pc_counts.items(), key=lambda x: -x[1]["count"]):
        pc_int = int(pc, 16) if pc.startswith("0x") else 0
        pr_int = int(pr, 16) if pr.startswith("0x") else 0
        pc_sym = find_nearest_sym(pc_int, syms)
        pr_sym = find_nearest_sym(pr_int, syms)
        print(f"  PC={pc} ({pc_sym})")
        print(f"    PR={pr} ({pr_sym})")
        print(f"    Addr={addr}  Count={info['count']}  Old={info['example_old']} New={info['example_new']}")
        print(f"    Frames: {', '.join(info['frames'][:5])}")
        print()

    # Now clear watchpoint and set new one on 0x06063D9C
    print("=" * 80)
    print("Now watching 0x06063D9C (possible analog/steering axis)...")
    inst.send("watchpoint_clear")

    # Clear the hits file
    if os.path.exists(inst.watchpoint_file):
        os.remove(inst.watchpoint_file)

    inst.send("watchpoint 06063D9C")
    inst.frame_advance(10)

    hits2 = inst.read_watchpoint_hits()
    print(f"\n=== Watchpoint Hits on 0x06063D9C: {len(hits2)} ===")
    pc_counts2 = {}
    for hit in hits2:
        parts = {}
        for token in hit.split():
            if "=" in token:
                k, v = token.split("=", 1)
                parts[k] = v
        pc = parts.get("pc", "unknown")
        pr = parts.get("pr", "unknown")
        addr = parts.get("addr", "unknown")
        old_val = parts.get("old", "?")
        new_val = parts.get("new", "?")
        key = (pc, pr, addr)
        if key not in pc_counts2:
            pc_counts2[key] = {"count": 0, "example_old": old_val, "example_new": new_val}
        pc_counts2[key]["count"] += 1

    for (pc, pr, addr), info in sorted(pc_counts2.items(), key=lambda x: -x[1]["count"]):
        pc_int = int(pc, 16) if pc.startswith("0x") else 0
        pr_int = int(pr, 16) if pr.startswith("0x") else 0
        pc_sym = find_nearest_sym(pc_int, syms)
        pr_sym = find_nearest_sym(pr_int, syms)
        print(f"  PC={pc} ({pc_sym})  PR={pr} ({pr_sym})  Count={info['count']}")
        print(f"    Old={info['example_old']} New={info['example_new']}")
        print()

    # Check stderr for debug watchpoint output
    print("\n=== Checking stderr for WP-DBG messages ===")
    inst._stderr_file.flush()
    try:
        with open(inst.stderr_path, "r") as f:
            lines = f.readlines()
        wp_lines = [l.strip() for l in lines if "WP-DBG" in l]
        print(f"Total stderr lines: {len(lines)}")
        print(f"WP-DBG lines: {len(wp_lines)}")
        for l in wp_lines[:20]:
            print(f"  {l}")
        if not wp_lines:
            print("  NO WP-DBG messages found! The watchpoint check in BusRW_DB_CS3")
            print("  is never matching. Either:")
            print("  1. The binary at /opt/mednafen_build is stale (doesn't have our debug code)")
            print("  2. Writes to 0x06063D98 bypass BusRW_DB_CS3 entirely")
            print("  3. The address masking is wrong")
    except FileNotFoundError:
        print("  stderr file not found!")

    # Cleanup
    print("\nShutting down...")
    inst.quit()
    print("Done.")


if __name__ == "__main__":
    main()
