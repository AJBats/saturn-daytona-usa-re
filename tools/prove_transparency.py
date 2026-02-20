#!/usr/bin/env python3
"""prove_transparency.py — Prove our debugger doesn't change behavior.

Run A: frame_advance only, no tracing — find hang frame+cycle
Run B: full tracing (call_trace + scdq_trace) — find hang frame+cycle

If both hang at the same frame and cycle, our tools are transparent.
If they differ, we still have an observer effect.

Both runs use the same disc. Hang detection: if frame_advance(1) takes
longer than HANG_TIMEOUT seconds, we declare a hang and record the state.
"""

import os
import re
import time
import subprocess

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MEDNAFEN = os.path.join(PROJDIR, "mednafen", "src", "mednafen")
CUE_FREE = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc",
                         "daytona_rebuilt.cue")
TMPDIR = os.path.join(PROJDIR, ".tmp")

MAX_FRAMES = 1500
# If frame_advance(1) takes longer than this, declare hang
HANG_TIMEOUT = 15  # seconds — generous, normal frame_advance(1) takes <1s


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
        raise TimeoutError(f"[{self.name}] Timeout")

    def frame_advance(self, n=1, timeout=None):
        if timeout is None:
            timeout = max(30, n * 2)
        ack = self.send(f"frame_advance {n}", timeout=timeout)
        if ack.startswith("ok frame_advance"):
            ack = self._wait_ack_change(timeout=max(60, n * 2))
        return ack

    def dump_cycle(self):
        return self.send("dump_cycle")

    def dump_regs(self):
        return self.send("dump_regs")

    def call_trace(self, path):
        return self.send(f"call_trace {path}")

    def scdq_trace(self, path):
        return self.send(f"scdq_trace {path}")

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


def run_trial(name, enable_tracing):
    """Run free build, advance frame-by-frame, detect hang.
    Returns (hang_frame, hang_cycle, last_regs) or (None, final_cycle, None) if no hang."""
    kill_stale()
    ipc = os.path.join(TMPDIR, f"prove_{name}")
    out = os.path.join(TMPDIR, f"prove_{name}_out")
    os.makedirs(out, exist_ok=True)

    inst = MednafenInstance(name, CUE_FREE, ipc)
    inst.start()

    if enable_tracing:
        ct_path = win_to_wsl(os.path.join(out, "call_trace.txt"))
        sq_path = win_to_wsl(os.path.join(out, "scdq_trace.txt"))
        inst.call_trace(ct_path)
        inst.scdq_trace(sq_path)
        print(f"  [{name}] Tracing enabled")

    last_cycle = 0
    last_frame = 0
    cycles_log = open(os.path.join(out, "cycles.txt"), "w")

    for frame in range(1, MAX_FRAMES + 1):
        try:
            ack = inst.frame_advance(1, timeout=HANG_TIMEOUT)
            c = extract_cycle(ack)
            f = extract_frame(ack)
            if c is not None:
                last_cycle = c
            if f is not None:
                last_frame = f
            cycles_log.write(f"{frame}\t{c}\n")

            if frame % 100 == 0:
                print(f"  [{name}] frame {frame}: cycle={c}")

        except TimeoutError:
            # HANG DETECTED
            print(f"  [{name}] *** HANG at frame {frame}! ***")
            # Try to get final state
            hang_cycle = last_cycle
            try:
                dc = inst.dump_cycle()
                hang_cycle = extract_cycle(dc)
            except Exception:
                pass
            regs = None
            try:
                regs = inst.dump_regs()
            except Exception:
                pass
            print(f"  [{name}] Last good cycle: {last_cycle}")
            print(f"  [{name}] Hang cycle: {hang_cycle}")
            if regs:
                # Extract just PC from regs
                pc_match = re.search(r'PC=([0-9A-Fa-f]+)', regs)
                if pc_match:
                    print(f"  [{name}] Hang PC: 0x{pc_match.group(1)}")

            cycles_log.close()
            inst.quit()
            return (frame, hang_cycle, regs)

    cycles_log.close()
    print(f"  [{name}] Completed {MAX_FRAMES} frames WITHOUT hanging!")
    final_cycle = extract_cycle(inst.dump_cycle())
    inst.quit()
    return (None, final_cycle, None)


def main():
    print("=" * 70)
    print("  TRANSPARENCY PROOF: Does tracing change behavior?")
    print("  Free build, ZERO fixes (no ICF_FIX, no SCDQ_FIX, no CD_FIX)")
    print(f"  Max frames: {MAX_FRAMES}, hang timeout: {HANG_TIMEOUT}s")
    print("=" * 70)

    # Run A: no tracing
    print(f"\n{'='*70}")
    print(f"  RUN A: No tracing (clean frame_advance only)")
    print(f"{'='*70}")
    a_frame, a_cycle, a_regs = run_trial("A_clean", enable_tracing=False)

    # Run B: full tracing
    print(f"\n{'='*70}")
    print(f"  RUN B: Full tracing (call_trace + scdq_trace)")
    print(f"{'='*70}")
    b_frame, b_cycle, b_regs = run_trial("B_traced", enable_tracing=True)

    # Verdict
    print(f"\n{'='*70}")
    print(f"  RESULTS")
    print(f"{'='*70}")

    if a_frame is not None:
        print(f"  Run A (clean):  HUNG at frame {a_frame}, cycle={a_cycle}")
    else:
        print(f"  Run A (clean):  No hang, final cycle={a_cycle}")

    if b_frame is not None:
        print(f"  Run B (traced): HUNG at frame {b_frame}, cycle={b_cycle}")
    else:
        print(f"  Run B (traced): No hang, final cycle={b_cycle}")

    # Compare
    if a_frame is not None and b_frame is not None:
        if a_frame == b_frame:
            cycle_delta = abs(b_cycle - a_cycle) if (a_cycle and b_cycle) else "?"
            print(f"\n  Both hung at SAME FRAME: {a_frame}")
            print(f"  Cycle delta: {cycle_delta}")
            if isinstance(cycle_delta, int) and cycle_delta == 0:
                print(f"\n  *** VERDICT: PERFECTLY TRANSPARENT ***")
                print(f"  Zero cycle difference. Tracing is completely invisible.")
            elif isinstance(cycle_delta, int) and cycle_delta < 100:
                print(f"\n  *** VERDICT: EFFECTIVELY TRANSPARENT ***")
                print(f"  Same hang frame, <100 cycle jitter.")
            else:
                print(f"\n  *** VERDICT: SAME FRAME BUT CYCLE DRIFT ***")
                print(f"  Tracing may have minor effect. Investigate.")
        else:
            print(f"\n  HUNG AT DIFFERENT FRAMES!")
            print(f"  Frame delta: {b_frame - a_frame}")
            print(f"\n  *** VERDICT: TRACING CHANGES BEHAVIOR ***")
            print(f"  Observer effect still present. Cannot trust traced data.")
    elif a_frame is None and b_frame is None:
        cycle_delta = abs(b_cycle - a_cycle) if (a_cycle and b_cycle) else "?"
        print(f"\n  Neither hung after {MAX_FRAMES} frames!")
        print(f"  Cycle delta: {cycle_delta}")
        print(f"\n  *** NOTE: Hang may occur later, or bug requires different conditions ***")
    else:
        hung_run = "A (clean)" if a_frame else "B (traced)"
        ok_run = "B (traced)" if a_frame else "A (clean)"
        print(f"\n  {hung_run} HUNG but {ok_run} did NOT!")
        print(f"\n  *** VERDICT: TRACING CHANGES BEHAVIOR ***")


if __name__ == "__main__":
    main()
