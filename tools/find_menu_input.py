#!/usr/bin/env python3
"""find_menu_input.py — Find what code handles UP/DOWN on the main menu.

Boots to the main menu (ARCADE/SATURN/OPTIONS), then:
  1. Takes baseline screenshot + memory dumps
  2. Presses DOWN
  3. Takes new screenshot + memory dumps
  4. Diffs memory to find the selection variable
  5. Sets watchpoint on that variable
  6. Presses DOWN again — watchpoint reveals the writer PC

Usage:
    python tools/find_menu_input.py
"""

import os
import sys
import time
import subprocess

PROJDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJDIR, "tools"))

MEDNAFEN_WSL = "/opt/mednafen_build/src/mednafen"
CUE = os.path.join(PROJDIR, "build", "disc", "rebuilt_disc", "daytona_rebuilt.cue")
TMPDIR = os.path.join(PROJDIR, ".tmp", "menu_input")
SYMS_FILE = os.path.join(PROJDIR, "build", "aprog_syms.txt")

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
        drive = path[0].lower()
        return f"/mnt/{drive}{path[2:]}"
    return path


def load_syms(syms_file, map_file=None):
    syms = {}
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
    if map_file:
        try:
            with open(map_file) as f:
                for line in f:
                    line = line.strip()
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

        cue_wsl = win_to_wsl(self.cue_path)
        launch_cmd = (
            f'export HOME="{home_wsl}" DISPLAY=:0 MEDNAFEN_ALLOWMULTI=1; '
            f'rm -f "{home_wsl}/.mednafen/mednafen.lck"; '
            f'"{MEDNAFEN_WSL}" '
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
        for attempt in range(10):
            try:
                os.replace(tmp, self.action_file)
                return
            except PermissionError:
                time.sleep(0.1)
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
        hits = []
        try:
            with open(self.watchpoint_file, "r") as f:
                for line in f:
                    line = line.strip()
                    if line and not line.startswith("#"):
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


def parse_hex_dump(ack_str):
    """Parse 'mem ADDR\\nHH HH HH ...' ack into bytes."""
    lines = ack_str.split("\n")
    raw = []
    for line in lines:
        line = line.strip()
        if line.startswith("mem ") or line.startswith("cycle=") or not line:
            continue
        # Strip trailing cycle= info
        if "cycle=" in line:
            line = line[:line.index("cycle=")].strip()
        for token in line.split():
            if len(token) == 2:
                try:
                    raw.append(int(token, 16))
                except ValueError:
                    pass
    return bytes(raw)


def main():
    print("=== Finding Menu UP/DOWN Input Handler ===")
    print()

    MAP_FILE = os.path.join(PROJDIR, "reimpl", "build", "daytona.map")
    syms = load_syms(SYMS_FILE, MAP_FILE)
    print(f"Loaded {len(syms)} symbols")

    if not os.path.exists(CUE):
        print(f"ERROR: Disc not found at {CUE}")
        print(f"Run: make -C reimpl disc")
        sys.exit(1)

    inst = MednafenInstance("menu", CUE, TMPDIR)

    print("Starting Mednafen...")
    inst.start()

    # === Boot to main menu using test_boot_auto.py timing ===
    print("Booting to main menu...")
    current_frame = 0
    for target_frame, action in BOOT_TRACE:
        delta = target_frame - current_frame
        if delta > 0:
            inst.frame_advance(delta)
            current_frame = target_frame
        inst.send(action)

    # Advance to menu ready
    delta = MENU_READY_FRAME - current_frame
    if delta > 0:
        inst.frame_advance(delta)
        current_frame = MENU_READY_FRAME

    # Take screenshot to confirm menu
    ss_menu = os.path.join(TMPDIR, "menu_baseline.png")
    inst.send(f"screenshot {win_to_wsl(ss_menu)}")
    inst.frame_advance(1)
    current_frame += 1
    print(f"  Menu screenshot: {ss_menu}")

    # === Step 1: Baseline memory dumps ===
    # Dump several regions where game state lives
    DUMP_REGIONS = [
        ("0605AD00", 0x40),   # game state dispatch area
        ("06063D90", 0x40),   # button state area
        ("0607887E", 0x10),   # game state byte area
        ("0605D240", 0x10),   # selection bytes (AT/MT, 2P flag)
        ("06078640", 0x20),   # course index area
        ("0605AB10", 0x20),   # menu overlay area
    ]

    print("\n=== Step 1: Baseline memory dumps ===")
    baseline = {}
    for addr_str, size in DUMP_REGIONS:
        ack = inst.send(f"dump_mem {addr_str} {size:X}")
        data = parse_hex_dump(ack)
        baseline[addr_str] = data
        print(f"  0x{addr_str}: {data.hex()}")

    # === Step 2: Press DOWN ===
    print("\n=== Step 2: Press DOWN ===")
    inst.send("input DOWN")
    inst.frame_advance(5)
    inst.send("input_release DOWN")
    inst.frame_advance(5)
    current_frame += 10

    # Take screenshot after DOWN
    ss_after = os.path.join(TMPDIR, "menu_after_down.png")
    inst.send(f"screenshot {win_to_wsl(ss_after)}")
    inst.frame_advance(1)
    current_frame += 1
    print(f"  After-DOWN screenshot: {ss_after}")

    # === Step 3: Memory diff ===
    print("\n=== Step 3: Memory diff ===")
    changed_addrs = []
    for addr_str, size in DUMP_REGIONS:
        ack = inst.send(f"dump_mem {addr_str} {size:X}")
        after = parse_hex_dump(ack)
        before = baseline[addr_str]
        base_int = int(addr_str, 16)
        for i in range(min(len(before), len(after))):
            if before[i] != after[i]:
                full_addr = base_int + i
                print(f"  CHANGED: 0x{full_addr:08X}  {before[i]:02X} -> {after[i]:02X}")
                changed_addrs.append((full_addr, before[i], after[i]))

    if not changed_addrs:
        print("  No changes detected in known regions!")
        print("  Trying a broader dump (0x06050000, 4KB)...")
        # Do a big dump comparison
        for region_base in ["06050000", "06058000", "06060000", "06068000",
                            "06070000", "06078000", "06080000", "06088000"]:
            ack_before = inst.send(f"dump_mem {region_base} 100")
            before_data = parse_hex_dump(ack_before)
            inst.send("input DOWN")
            inst.frame_advance(5)
            inst.send("input_release DOWN")
            inst.frame_advance(5)
            ack_after = inst.send(f"dump_mem {region_base} 100")
            after_data = parse_hex_dump(ack_after)
            base_int = int(region_base, 16)
            for i in range(min(len(before_data), len(after_data))):
                if before_data[i] != after_data[i]:
                    full_addr = base_int + i
                    print(f"  CHANGED: 0x{full_addr:08X}  {before_data[i]:02X} -> {after_data[i]:02X}")
                    changed_addrs.append((full_addr, before_data[i], after_data[i]))
            if changed_addrs:
                break

    if not changed_addrs:
        print("  Still no changes found. The menu selection variable is in an unexpected region.")
        inst.quit()
        return

    # === Step 4: Watchpoint on changed variable ===
    # Pick the first changed address that looks like a selection index (small value change)
    target = None
    for addr, old, new in changed_addrs:
        diff = abs(new - old)
        if diff <= 5:  # Selection index likely changes by 1
            target = addr
            print(f"\n=== Step 4: Watchpoint on 0x{addr:08X} (changed {old} -> {new}) ===")
            break

    if target is None:
        # Just use the first changed address
        target = changed_addrs[0][0]
        old, new = changed_addrs[0][1], changed_addrs[0][2]
        print(f"\n=== Step 4: Watchpoint on 0x{target:08X} (changed {old} -> {new}) ===")

    # Clear any stale watchpoint data
    if os.path.exists(inst.watchpoint_file):
        os.remove(inst.watchpoint_file)

    ack = inst.send(f"watchpoint {target:08X}")
    print(f"  Watchpoint set: {ack}")

    # Press DOWN to trigger the watchpoint
    print("  Pressing DOWN to trigger watchpoint...")
    inst.send("input DOWN")
    inst.frame_advance(5)
    inst.send("input_release DOWN")
    inst.frame_advance(5)

    # === Step 5: Read watchpoint hits ===
    hits = inst.read_watchpoint_hits()
    print(f"\n=== Step 5: Watchpoint Hits: {len(hits)} ===")

    pc_counts = {}
    for hit in hits:
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
        key = (pc, pr)
        if key not in pc_counts:
            pc_counts[key] = {"count": 0, "example_old": old_val, "example_new": new_val,
                              "addr": addr, "frames": []}
        pc_counts[key]["count"] += 1
        pc_counts[key]["frames"].append(frame)

    for (pc, pr), info in sorted(pc_counts.items(), key=lambda x: -x[1]["count"]):
        pc_int = int(pc, 16) if pc.startswith("0x") else 0
        pr_int = int(pr, 16) if pr.startswith("0x") else 0
        pc_sym = find_nearest_sym(pc_int, syms)
        pr_sym = find_nearest_sym(pr_int, syms)
        print(f"  PC={pc} ({pc_sym})")
        print(f"    PR={pr} ({pr_sym})")
        print(f"    Addr={info['addr']}  Count={info['count']}")
        print(f"    Old={info['example_old']} New={info['example_new']}")
        print(f"    Frames: {', '.join(info['frames'][:10])}")
        print()

    # Also check stderr for WP-DBG
    inst._stderr_file.flush()
    try:
        with open(inst.stderr_path, "r") as f:
            wp_lines = [l.strip() for l in f if "WP-DBG" in l]
        if wp_lines:
            print(f"=== WP-DBG lines ({len(wp_lines)}) ===")
            for l in wp_lines[:10]:
                print(f"  {l}")
    except FileNotFoundError:
        pass

    # Cleanup
    print("\nShutting down...")
    inst.quit()
    print("Done.")


if __name__ == "__main__":
    main()
