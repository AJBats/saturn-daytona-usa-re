#!/usr/bin/env python3
"""compare_builds.py — Boot retail and free builds, take screenshots, dump memory for comparison.

Boots both builds in deterministic mode to a specified frame number,
takes screenshots, and dumps key memory regions to identify divergences.

Usage:
    python tools/compare_builds.py [--frame N]
"""

import os
import re
import sys
import time
import struct
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

    def dump_regs(self):
        return self.send("dump_regs")

    def dump_mem(self, addr, size=256):
        return self.send(f"dump_mem {addr:X} {size:X}")

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


def parse_mem_dump(ack_str):
    """Parse hex memory dump from ack string into bytes."""
    lines = ack_str.split("\n")
    data = bytearray()
    for line in lines:
        line = line.strip()
        if line.startswith("mem ") or not line:
            continue
        # Parse hex bytes
        for token in line.split():
            if len(token) == 2:
                try:
                    data.append(int(token, 16))
                except ValueError:
                    pass
    return bytes(data)


def kill_stale():
    subprocess.run(["wsl", "-d", "Ubuntu", "-e", "bash", "-c",
                    "pkill -9 -f 'mednafen.*--automation' 2>/dev/null; true"],
                   stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    time.sleep(0.5)


def run_build(name, cue_path, frame_target, fixes=""):
    """Boot a build to a target frame and capture state."""
    ipc_dir = os.path.join(TMPDIR, f"compare_ipc_{name}")
    result = {}

    print(f"\n{'='*60}")
    print(f"  {name.upper()} BUILD — advancing to frame {frame_target}")
    print(f"  CUE: {cue_path}")
    print(f"{'='*60}")

    emu = MednafenInstance(name, cue_path, ipc_dir)

    print("\nLaunching Mednafen...")
    emu.start()

    print("Setting deterministic mode...")
    emu.send("deterministic")

    # Advance to target frame
    print(f"Advancing to frame {frame_target}...")
    BATCH = 50
    for start in range(0, frame_target, BATCH):
        n = min(BATCH, frame_target - start)
        try:
            ack = emu.frame_advance(n, timeout=120)
        except TimeoutError:
            print(f"  *** HANG at frame ~{start}")
            result["hung"] = True
            emu.quit()
            return result
        done = start + n
        if done % 100 == 0 or done >= frame_target:
            print(f"  frame {done}/{frame_target}")

    # Take screenshot (need to advance a frame for rendering)
    ss_path = os.path.join(OUTDIR, f"screenshot_{name}.png")
    print(f"Taking screenshot -> {ss_path}")
    try:
        emu.screenshot(ss_path)
        emu.frame_advance(1, timeout=30)  # Render the screenshot
        time.sleep(0.5)  # Give filesystem time to flush
    except Exception as e:
        print(f"  screenshot error: {e}")

    # Dump registers
    print("Dumping registers...")
    result["regs"] = emu.dump_regs()

    # Dump key memory regions
    # VDP2 color RAM (CRAM): 0x05F00000, 4KB (2048 colors)
    print("Dumping CRAM (VDP2 color RAM)...")
    result["cram"] = parse_mem_dump(emu.dump_mem(0x05F00000, 0x1000))

    # VDP2 registers: 0x05F80000, 512 bytes
    print("Dumping VDP2 registers...")
    result["vdp2_regs"] = parse_mem_dump(emu.dump_mem(0x05F80000, 0x200))

    # VDP1 VRAM (command table + textures): 0x05C00000, 64KB
    print("Dumping VDP1 VRAM (first 64KB)...")
    vdp1_data = bytearray()
    for chunk_off in range(0, 0x10000, 0x10000):
        vdp1_data += parse_mem_dump(emu.dump_mem(0x05C00000 + chunk_off, 0x10000))
    result["vdp1_vram"] = bytes(vdp1_data)

    # VDP2 VRAM: 0x05E00000, 64KB sample
    print("Dumping VDP2 VRAM (first 64KB)...")
    vdp2_data = bytearray()
    for chunk_off in range(0, 0x10000, 0x10000):
        vdp2_data += parse_mem_dump(emu.dump_mem(0x05E00000 + chunk_off, 0x10000))
    result["vdp2_vram"] = bytes(vdp2_data)

    # Game state area in Work RAM (0x0607E000+)
    print("Dumping game state area...")
    result["game_state"] = parse_mem_dump(emu.dump_mem(0x0607E000, 0x1000))

    emu.quit()

    result["name"] = name
    return result


def compare_regions(name, retail_data, free_data):
    """Compare two memory regions, report differences."""
    if not retail_data or not free_data:
        print(f"  {name}: MISSING DATA")
        return

    min_len = min(len(retail_data), len(free_data))
    diffs = 0
    first_diff = None
    for i in range(min_len):
        if retail_data[i] != free_data[i]:
            diffs += 1
            if first_diff is None:
                first_diff = i

    if len(retail_data) != len(free_data):
        print(f"  {name}: SIZE MISMATCH retail={len(retail_data)} free={len(free_data)}")

    if diffs == 0:
        print(f"  {name}: IDENTICAL ({min_len} bytes)")
    else:
        print(f"  {name}: {diffs} DIFFERENT bytes out of {min_len}")
        if first_diff is not None:
            # Show first few diffs
            shown = 0
            for i in range(min_len):
                if retail_data[i] != free_data[i]:
                    print(f"    offset 0x{i:04X}: retail=0x{retail_data[i]:02X} free=0x{free_data[i]:02X}")
                    shown += 1
                    if shown >= 10:
                        print(f"    ... ({diffs - shown} more)")
                        break


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--frame", type=int, default=300,
                        help="Frame to advance to (default: 300)")
    args = parser.parse_args()

    os.makedirs(OUTDIR, exist_ok=True)
    kill_stale()

    # Run retail
    retail = run_build("retail", CUE_RETAIL, args.frame)
    kill_stale()

    # Run free (with fixes to get past boot)
    if not os.path.exists(CUE_FREE):
        print(f"\nERROR: Free build disc not found at {CUE_FREE}")
        print("Run: make -C reimpl free-disc SCDQ_FIX=1 ICF_FIX=1 CD_FIX=1")
        sys.exit(1)
    free = run_build("free", CUE_FREE, args.frame)

    # Compare
    print(f"\n{'='*60}")
    print("  COMPARISON RESULTS")
    print(f"{'='*60}")

    print(f"\nRegisters:")
    if retail.get("regs") and free.get("regs"):
        # Parse register strings
        r_regs = retail["regs"]
        f_regs = free["regs"]
        # Extract R0-R15, PC, SR values
        r_vals = re.findall(r'(R\d+|PC|SR|PR|GBR|VBR)=([0-9A-F]+)', r_regs)
        f_vals = re.findall(r'(R\d+|PC|SR|PR|GBR|VBR)=([0-9A-F]+)', f_regs)
        r_dict = dict(r_vals)
        f_dict = dict(f_vals)
        for key in r_dict:
            rv = r_dict.get(key, "???")
            fv = f_dict.get(key, "???")
            marker = " ***" if rv != fv else ""
            print(f"  {key:5s}: retail={rv} free={fv}{marker}")

    print(f"\nMemory Regions:")
    compare_regions("CRAM", retail.get("cram", b""), free.get("cram", b""))
    compare_regions("VDP2 Regs", retail.get("vdp2_regs", b""), free.get("vdp2_regs", b""))
    compare_regions("VDP1 VRAM", retail.get("vdp1_vram", b""), free.get("vdp1_vram", b""))
    compare_regions("VDP2 VRAM", retail.get("vdp2_vram", b""), free.get("vdp2_vram", b""))
    compare_regions("Game State", retail.get("game_state", b""), free.get("game_state", b""))

    # Save raw dumps for offline analysis
    for region in ["cram", "vdp2_regs", "vdp1_vram", "vdp2_vram", "game_state"]:
        for build in [retail, free]:
            name = build.get("name", "unknown")
            data = build.get(region, b"")
            if data:
                path = os.path.join(OUTDIR, f"{region}_{name}.bin")
                with open(path, "wb") as f:
                    f.write(data)

    print(f"\nScreenshots saved to {OUTDIR}/")
    print("Done.")


if __name__ == "__main__":
    main()
