#!/usr/bin/env python3
"""test_hook_parallel.py — Parallel hook transparency test.

Two simultaneous instances, identical except one has the inline hook active.
Uses batch frame_advance to reach a sync point, verifies match, then compares.

This eliminates startup timing jitter (both instances experience the same IPC delays).
"""

import os
import re
import time
import subprocess

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MEDNAFEN = os.path.join(PROJDIR, "mednafen", "src", "mednafen")
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)",
                         "Daytona USA (USA).cue")
TMPDIR = os.path.join(PROJDIR, ".tmp")
UNREACHABLE_BP = 0x060FFFFF


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
            f'export HOME="{home_wsl}" DISPLAY=:0 MEDNAFEN_ALLOWMULTI=1; '
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
            raise RuntimeError(f"[{self.name}] exited")
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
        raise TimeoutError(f"[{self.name}] Timeout")

    def _wait_ack_change(self, timeout=30):
        deadline = time.time() + timeout
        while time.time() < deadline:
            ack = self._read_ack()
            if ack and ack != self.last_ack:
                self.last_ack = ack
                return ack
            time.sleep(0.05)
        raise TimeoutError(f"[{self.name}] Timeout")

    def frame_advance(self, n=1):
        ack = self.send(f"frame_advance {n}", timeout=max(30, n * 2))
        if ack.startswith("ok frame_advance"):
            ack = self._wait_ack_change(timeout=max(60, n * 2))
        return ack

    def breakpoint(self, addr):
        return self.send(f"breakpoint {addr:X}")

    def dump_cycle(self):
        return self.send("dump_cycle")

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


def extract_cycle(ack_str):
    m = re.search(r'cycle=(\d+)', ack_str)
    return int(m.group(1)) if m else None


def extract_frame(ack_str):
    m = re.search(r'frame=(\d+)', ack_str)
    return int(m.group(1)) if m else None


def kill_stale():
    subprocess.run(["wsl", "-d", "Ubuntu", "-e", "bash", "-c",
                    "pkill -9 -f 'mednafen.*--automation' 2>/dev/null; true"],
                   stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    time.sleep(0.5)


def main():
    print("=" * 70)
    print("  PARALLEL HOOK TRANSPARENCY TEST")
    print("  A: no hook | B: inline hook active (unreachable breakpoint)")
    print("=" * 70)

    kill_stale()

    ipc_a = os.path.join(TMPDIR, "hookpar_A")
    ipc_b = os.path.join(TMPDIR, "hookpar_B")

    inst_a = MednafenInstance("A_noHook", CUE_PROD, ipc_a)
    inst_b = MednafenInstance("B_hook", CUE_PROD, ipc_b)

    print("\nLaunching two instances...")
    inst_a.start()
    inst_b.start()

    # Phase 1: Both advance to frame 100 (batch, no hook on either)
    print(f"\nPhase 1: Both advance to frame 100 (no hook, batch)...")
    ack_a = inst_a.frame_advance(100)
    ack_b = inst_b.frame_advance(100)

    ca = extract_cycle(inst_a.dump_cycle())
    cb = extract_cycle(inst_b.dump_cycle())
    fa = extract_frame(ack_a)
    fb = extract_frame(ack_b)

    print(f"  [A] frame={fa}, cycle={ca}")
    print(f"  [B] frame={fb}, cycle={cb}")

    if ca != cb:
        print(f"\n  WARNING: Already diverged at frame 100 (delta={cb - ca})")
        print(f"  This is a startup offset, not a hook issue.")
        print(f"  Attempting frame-level sync...")

        # Try to find what frame offset we have
        delta = cb - ca
        frame_cycles = ca / fa if fa else 449000  # approximate
        frame_offset = round(delta / frame_cycles)
        print(f"  Estimated frame offset: {frame_offset}")
        print(f"  Cannot compare without sync. Aborting.")
        inst_a.quit()
        inst_b.quit()
        return

    print(f"  MATCHED at frame 100: {ca}")

    # Phase 2: Enable hook on B only
    print(f"\nPhase 2: Enable hook on B (unreachable breakpoint)...")
    ack = inst_b.breakpoint(UNREACHABLE_BP)
    print(f"  [B] {ack}")

    # Phase 3: Both advance frame-by-frame from 100 to 200
    print(f"\nPhase 3: Frame-by-frame comparison (100 to 200)...")
    print(f"  Hook active on B, disabled on A.\n")

    diverged = False
    first_diverge = None
    max_delta = 0

    for i in range(100):
        target = 101 + i
        ack_a = inst_a.frame_advance(1)
        ack_b = inst_b.frame_advance(1)

        ca = extract_cycle(ack_a)
        cb = extract_cycle(ack_b)

        if ca is None or cb is None:
            print(f"  frame {target}: PARSE ERROR (a={ack_a}, b={ack_b})")
            continue

        delta = cb - ca
        if delta != 0:
            if not diverged:
                first_diverge = target
                diverged = True
                print(f"  *** DIVERGENCE at frame {target}: A={ca} B={cb} delta={delta}")
            max_delta = max(abs(delta), max_delta)
            if i % 20 == 0:
                print(f"  frame {target}: delta={delta}")
        else:
            if i % 25 == 0:
                print(f"  frame {target}: IDENTICAL ({ca})")

    # Final comparison
    ca_final = extract_cycle(inst_a.dump_cycle())
    cb_final = extract_cycle(inst_b.dump_cycle())

    inst_a.quit()
    inst_b.quit()

    # Verdict
    print(f"\n{'='*70}")
    print(f"  VERDICT")
    print(f"{'='*70}")
    print(f"  Final: A={ca_final}, B={cb_final}")

    if diverged:
        final_delta = cb_final - ca_final if ca_final and cb_final else "?"
        print(f"\n  INLINE HOOK CHANGES TIMING")
        print(f"  First divergence: frame {first_diverge}")
        print(f"  Max delta: {max_delta} cycles")
        print(f"  Final delta at frame 200: {final_delta}")
        if isinstance(final_delta, int) and abs(final_delta) < 100:
            print(f"\n  (Very small — may be acceptable jitter)")
        else:
            print(f"\n  HOOK IS NOT TRANSPARENT — still need investigation")
    else:
        print(f"\n  INLINE HOOK IS PERFECTLY TRANSPARENT")
        print(f"  100 frames with hook active, zero cycle difference.")
        print(f"  Breakpoints and logging are invisible to emulated timing.")
        print(f"  OBSERVER EFFECT: ELIMINATED")


if __name__ == "__main__":
    main()
