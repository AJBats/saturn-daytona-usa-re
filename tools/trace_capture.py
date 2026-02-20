#!/usr/bin/env python3
"""trace_capture.py — Comprehensive parallel trace of production vs free build.

Captures EVERYTHING with the deterministic debugger:
  - call_trace: every JSR/BSR/BSRF with caller+target
  - scdq_trace: every CD block interaction
  - per-frame cycle dumps

Both builds run simultaneously to eliminate startup jitter.
Free build (no SCDQ_FIX) will hang — that's what we want to capture.
Production runs as the reference.

Output goes to .tmp/trace_prod/ and .tmp/trace_free/
"""

import os
import re
import sys
import time
import subprocess

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MEDNAFEN = os.path.join(PROJDIR, "mednafen", "src", "mednafen")
CUE_PROD = os.path.join(PROJDIR, "external_resources", "Daytona USA (USA)",
                         "Daytona USA (USA).cue")
CUE_FREE = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc",
                         "daytona_rebuilt.cue")
TMPDIR = os.path.join(PROJDIR, ".tmp")

# How many frames to run. Free build hangs around frame 700.
# Run production to the same point for comparison.
MAX_FRAMES = 800
# Dump cycles every N frames for progress tracking
CYCLE_DUMP_INTERVAL = 50


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

    def frame_advance(self, n=1):
        ack = self.send(f"frame_advance {n}", timeout=max(60, n * 2))
        if ack.startswith("ok frame_advance"):
            ack = self._wait_ack_change(timeout=max(120, n * 2))
        return ack

    def breakpoint(self, addr):
        return self.send(f"breakpoint {addr:X}")

    def dump_cycle(self):
        return self.send("dump_cycle")

    def call_trace(self, path):
        return self.send(f"call_trace {path}")

    def call_trace_stop(self):
        return self.send("call_trace_stop")

    def scdq_trace(self, path):
        return self.send(f"scdq_trace {path}")

    def scdq_trace_stop(self):
        return self.send("scdq_trace_stop")

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
    print("  COMPREHENSIVE PARALLEL TRACE CAPTURE")
    print("  Production vs Free (ICF_FIX=1, no SCDQ_FIX)")
    print("  Deterministic debugger — zero observer effect")
    print("=" * 70)

    kill_stale()

    # Output directories
    out_prod = os.path.join(TMPDIR, "trace_prod")
    out_free = os.path.join(TMPDIR, "trace_free")
    os.makedirs(out_prod, exist_ok=True)
    os.makedirs(out_free, exist_ok=True)

    ipc_prod = os.path.join(TMPDIR, "trace_ipc_prod")
    ipc_free = os.path.join(TMPDIR, "trace_ipc_free")

    prod = MednafenInstance("PROD", CUE_PROD, ipc_prod)
    free = MednafenInstance("FREE", CUE_FREE, ipc_free)

    print("\nLaunching both instances...")
    prod.start()
    free.start()

    # Enable traces on both BEFORE any frames run
    call_trace_prod = win_to_wsl(os.path.join(out_prod, "call_trace.txt"))
    call_trace_free = win_to_wsl(os.path.join(out_free, "call_trace.txt"))
    scdq_trace_prod = win_to_wsl(os.path.join(out_prod, "scdq_trace.txt"))
    scdq_trace_free = win_to_wsl(os.path.join(out_free, "scdq_trace.txt"))

    print("\nEnabling traces...")
    print(f"  [PROD] {prod.call_trace(call_trace_prod)}")
    print(f"  [FREE] {free.call_trace(call_trace_free)}")
    print(f"  [PROD] {prod.scdq_trace(scdq_trace_prod)}")
    print(f"  [FREE] {free.scdq_trace(scdq_trace_free)}")

    # Cycle log files
    cycle_log_prod = open(os.path.join(out_prod, "cycles.txt"), "w")
    cycle_log_free = open(os.path.join(out_free, "cycles.txt"), "w")

    print(f"\nAdvancing both builds frame-by-frame to frame {MAX_FRAMES}...")
    print(f"  Free build expected to hang around frame 700.")
    print(f"  Cycle dumps every {CYCLE_DUMP_INTERVAL} frames.\n")

    free_hung = False
    free_hang_frame = None
    free_hang_cycle = None

    for frame in range(1, MAX_FRAMES + 1):
        # Advance production (always succeeds)
        try:
            ack_p = prod.frame_advance(1)
        except TimeoutError:
            print(f"  [PROD] TIMEOUT at frame {frame}!")
            break

        cp = extract_cycle(ack_p)

        # Advance free build (may hang)
        if not free_hung:
            try:
                ack_f = free.frame_advance(1)
                cf = extract_cycle(ack_f)
            except TimeoutError:
                free_hung = True
                free_hang_frame = frame
                # Get the last known cycle
                try:
                    ack_dc = free.dump_cycle()
                    free_hang_cycle = extract_cycle(ack_dc)
                except Exception:
                    free_hang_cycle = None
                print(f"\n  *** FREE BUILD HUNG at frame {frame}! cycle={free_hang_cycle}")
                print(f"  Continuing production trace for reference...\n")
                cf = free_hang_cycle
        else:
            cf = free_hang_cycle  # static after hang

        # Log cycles
        cycle_log_prod.write(f"{frame}\t{cp}\n")
        cycle_log_free.write(f"{frame}\t{cf}\n")

        # Periodic status
        if frame % CYCLE_DUMP_INTERVAL == 0:
            delta = (cf - cp) if (cp is not None and cf is not None) else "?"
            status = "HUNG" if free_hung else "running"
            print(f"  frame {frame:4d}: PROD={cp:>12,}  FREE={cf:>12,}  delta={delta:>10}  [{status}]")

        # Flush periodically
        if frame % 100 == 0:
            cycle_log_prod.flush()
            cycle_log_free.flush()

    # Stop traces
    print("\nStopping traces...")
    try:
        prod.call_trace_stop()
        prod.scdq_trace_stop()
    except Exception as e:
        print(f"  [PROD] trace stop: {e}")

    if not free_hung:
        try:
            free.call_trace_stop()
            free.scdq_trace_stop()
        except Exception as e:
            print(f"  [FREE] trace stop: {e}")

    # Final cycle dump
    try:
        cp_final = extract_cycle(prod.dump_cycle())
    except Exception:
        cp_final = None

    cycle_log_prod.close()
    cycle_log_free.close()

    # Quit both
    prod.quit()
    free.quit()

    # Summary
    print(f"\n{'='*70}")
    print(f"  TRACE CAPTURE COMPLETE")
    print(f"{'='*70}")
    print(f"  Production final: frame={MAX_FRAMES}, cycle={cp_final}")
    if free_hung:
        print(f"  Free build HUNG: frame={free_hang_frame}, cycle={free_hang_cycle}")
    else:
        print(f"  Free build completed {MAX_FRAMES} frames (no hang?!)")

    print(f"\n  Output files:")
    print(f"    {out_prod}/call_trace.txt")
    print(f"    {out_prod}/scdq_trace.txt")
    print(f"    {out_prod}/cycles.txt")
    print(f"    {out_free}/call_trace.txt")
    print(f"    {out_free}/scdq_trace.txt")
    print(f"    {out_free}/cycles.txt")

    print(f"\n  Next: diff the traces to find first divergence")
    print(f"    python tools/trace_diff.py")


if __name__ == "__main__":
    main()
