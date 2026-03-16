#!/usr/bin/env python3
"""Test runner for auto_re claims (Daytona USA '95).

Reads a YAML claim file, boots Mednafen, runs each claim's test
against the emulator, reports pass/fail.

This file is the oracle — do not let the agent modify it.

Usage:
    python tools/test_claim.py workstreams/auto_re/claims/FUN_0602D814.yaml
    python tools/test_claim.py workstreams/auto_re/claims/FUN_0602D814.yaml --verbose
    python tools/test_claim.py workstreams/auto_re/claims/FUN_0602D814.yaml --claim writes_speed
"""

import os
import sys
import time
import yaml
import argparse
import struct

PROJECT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(PROJECT, "mednafen"))

from mednafen_bot import MednafenBot, _win_path

# --- Configuration ---

SAVE_STATES = {
    # Race scenarios — 40 cars, rolling start at ~150 mph
    "race_idle": os.path.join(PROJECT, "build", "save_states",
        "daytona_rebuilt.8180a74b2162ad4393a9630de58615e3.mc0"),
    "race_throttle": os.path.join(PROJECT, "build", "save_states",
        "daytona_rebuilt.8180a74b2162ad4393a9630de58615e3.mc0"),
    "race_brake": os.path.join(PROJECT, "build", "save_states",
        "daytona_rebuilt.8180a74b2162ad4393a9630de58615e3.mc0"),
    "race_steer_left": os.path.join(PROJECT, "build", "save_states",
        "daytona_rebuilt.8180a74b2162ad4393a9630de58615e3.mc0"),
    "race_steer_right": os.path.join(PROJECT, "build", "save_states",
        "daytona_rebuilt.8180a74b2162ad4393a9630de58615e3.mc0"),
    # Manual transmission race
    "race_manual_idle": os.path.join(PROJECT, "build", "save_states",
        "daytona_manual_trans.8180a74b2162ad4393a9630de58615e3.mc0"),
    # Time trial scenarios — from save_states README
    "straight_throttle": os.path.join(PROJECT, "build", "save_states",
        "usa_tt_straight.mc0"),
    "right_wall_strike": os.path.join(PROJECT, "build", "save_states",
        "usa_tt_straight.mc0"),
    # Offtrack scenarios — from save_states README
    "offtrack_throttle": os.path.join(PROJECT, "build", "save_states",
        "usa_tt_offtrack_stop.mc0"),
    # Manual transmission time trial — from save_states README
    "manual_throttle_4gear": os.path.join(PROJECT, "build", "save_states",
        "usa_tt_manual_straight.mc0"),
}

SCENARIO_INPUTS = {
    # Race scenarios — C = throttle, B = brake in '95
    "race_idle": [],
    "race_throttle": ["C"],
    "race_brake": ["B"],
    "race_steer_left": ["LEFT"],
    "race_steer_right": ["RIGHT"],
    "race_manual_idle": [],
    # Time trial scenarios
    "straight_throttle": ["C"],
    "right_wall_strike": ["RIGHT", "C"],
    # Offtrack scenarios
    "offtrack_throttle": ["C"],
    # Manual transmission — timed events: (frame, "press"/"release", button)
    # From save_states README: hold C, tap DOWN at 190, 337, 494
    "manual_throttle_4gear": [
        (0, "press", "C"),
        (190, "press", "DOWN"),
        (195, "release", "DOWN"),
        (337, "press", "DOWN"),
        (342, "release", "DOWN"),
        (494, "press", "DOWN"),
        (500, "release", "DOWN"),
    ],
}


def _is_timed_scenario(scenario):
    """Check if a scenario uses timed input events (list of tuples)."""
    inputs = SCENARIO_INPUTS.get(scenario, [])
    return inputs and isinstance(inputs[0], tuple)

CUE_PATH = os.path.join(
    PROJECT, "external_resources",
    "Daytona USA (USA)",
    "Daytona USA (USA).cue",
)
IPC_DIR = os.path.join(PROJECT, "build", "claim_test_ipc")


# --- Address Resolution ---

def _fmt_addr(addr):
    """Format an integer address as hex without 0x prefix."""
    return f"{addr:08X}"


def resolve_address(addr_spec, bot, function_addr, verbose=False):
    """Resolve an address specification to an absolute address.

    Plain hex int or "0x..." string: returned as-is.
    No GBR resolution needed for '95 — car struct base is fixed at 0x06078900.
    """
    if isinstance(addr_spec, int):
        return addr_spec

    if isinstance(addr_spec, str) and addr_spec.startswith("0x"):
        return int(addr_spec, 16)

    # Support "car[0]+N" syntax for convenience
    if isinstance(addr_spec, str) and addr_spec.startswith("car[0]+"):
        offset = int(addr_spec[7:])
        return 0x06078900 + offset

    raise ValueError(f"Unknown address format: {addr_spec!r}")


# --- Test Implementations ---

def test_writes_to(claim, bot, verbose=False):
    """Test: does function F write to address A?"""
    scenario = claim.get("scenario", "race_idle")
    frames = claim.get("frames", 60)

    func_start = int(claim["function"][4:], 16)
    func_end = claim.get("function_end")
    if isinstance(func_end, str):
        func_end = int(func_end, 16)

    _load_scenario(bot, scenario, verbose)

    target_addr = resolve_address(claim["address"], bot, func_start, verbose)
    if target_addr is None:
        return False, "Could not resolve target address"

    # Apply inputs for simple scenarios (timed scenarios need special handling)
    if not _is_timed_scenario(scenario):
        _apply_simple_inputs(bot, scenario)

    bot.send_and_wait(f"watchpoint {_fmt_addr(target_addr)}", "ok watchpoint", timeout=5)

    if verbose:
        print(f"  Watchpoint set at {_fmt_addr(target_addr)}, advancing {frames} frames...")

    if _is_timed_scenario(scenario):
        # For timed scenarios, replay events while watchpoint is active.
        # Watchpoint hits will interrupt frame_advance — handle inline.
        events = [(f, a, b) for f, a, b in SCENARIO_INPUTS[scenario] if f <= frames]
        current_frame = 0
        for frame, action, button in events:
            if frame > current_frame:
                delta = frame - current_frame
                remaining = delta
                while remaining > 0:
                    bot.send(f"frame_advance {remaining}")
                    ack = bot.wait_ack(["done frame_advance", "hit watchpoint"],
                                       timeout=max(remaining, 30))
                    if not ack:
                        break
                    if "hit watchpoint" in ack:
                        remaining -= 1
                        continue
                    break
                current_frame = frame
            if action == "press":
                bot.send_and_wait(f"input {button}", "ok input", timeout=5)
            elif action == "release":
                bot.send_and_wait(f"input_release {button}", "ok input_release", timeout=5)
        # Advance remaining
        remaining = frames - current_frame
        while remaining > 0:
            bot.send(f"frame_advance {remaining}")
            ack = bot.wait_ack(["done frame_advance", "hit watchpoint"],
                               timeout=max(remaining, 30))
            if not ack:
                break
            if "hit watchpoint" in ack:
                remaining -= 1
                continue
            break
    else:
        remaining = frames
        for _ in range(frames + 10):
            if remaining <= 0:
                break
            bot.send(f"frame_advance {remaining}")
            ack = bot.wait_ack(["done frame_advance", "hit watchpoint"],
                               timeout=max(remaining, 30))
            if not ack:
                break
            if "hit watchpoint" in ack:
                if verbose:
                    print(f"  Watchpoint hit, resuming...")
                remaining -= 1
                continue
            if "done frame_advance" in ack:
                break

    hits_path = os.path.join(IPC_DIR, "watchpoint_hits.txt")
    hits = _parse_watchpoint_hits(hits_path)

    bot.send_and_wait("watchpoint_clear", "ok watchpoint_clear", timeout=5)

    if not _is_timed_scenario(scenario):
        _release_simple_inputs(bot, scenario)

    if func_end:
        my_hits = [h for h in hits if func_start <= h["pc"] < func_end]
    else:
        my_hits = [h for h in hits if h["pc"] == func_start]

    passed = len(my_hits) > 0
    detail = f"{len(my_hits)} hits from function, {len(hits)} total watchpoint hits"
    return passed, detail


def test_call_count_per_frame(claim, bot, verbose=False):
    """Test: how many times is function F called per frame?"""
    scenario = claim.get("scenario", "race_idle")
    func_addr = claim["address"]
    if isinstance(func_addr, str):
        func_addr = int(func_addr, 16)
    expected = claim["expected_count"]
    tolerance = claim.get("tolerance", 5)

    _load_scenario(bot, scenario, verbose)

    if not _is_timed_scenario(scenario):
        _apply_simple_inputs(bot, scenario)
    else:
        # For call_count, apply initial presses (frame 0 events)
        for frame, action, button in SCENARIO_INPUTS[scenario]:
            if frame == 0 and action == "press":
                bot.send_and_wait(f"input {button}", "ok input", timeout=5)

    bot.send_and_wait(f"breakpoint {_fmt_addr(func_addr)}", "ok breakpoint", timeout=5)

    if verbose:
        print(f"  Breakpoint at {_fmt_addr(func_addr)}, counting hits in 1 frame...")

    hit_count = 0
    ref_frame = None

    for _ in range(200):
        bot.send("run")
        ack = bot.wait_ack("break ", timeout=10)
        if not ack or "break " not in ack:
            break
        current_frame = _parse_frame_from_ack(ack)
        if ref_frame is None:
            ref_frame = current_frame
        if current_frame is not None and current_frame > ref_frame:
            break
        hit_count += 1

    bot.send_and_wait("breakpoint_clear", "breakpoint_clear", timeout=5)

    if not _is_timed_scenario(scenario):
        _release_simple_inputs(bot, scenario)
    else:
        for frame, action, button in SCENARIO_INPUTS[scenario]:
            if frame == 0 and action == "press":
                bot.send_and_wait(f"input_release {button}", "ok input_release", timeout=5)

    passed = abs(hit_count - expected) <= tolerance
    detail = f"{hit_count} calls (expected {expected} +/- {tolerance})"
    return passed, detail


def test_value_changes_with_input(claim, bot, verbose=False):
    """Test: does value at A change in expected direction with input?"""
    frames = claim.get("frames", 60)
    input_btn = claim.get("input", "none")
    direction = claim["direction"]
    scenario = claim.get("scenario", "straight_throttle")

    func_addr = claim.get("_parent_address", 0)

    _load_scenario(bot, scenario, verbose)

    target_addr = resolve_address(claim["address"], bot, func_addr, verbose)
    if target_addr is None:
        return False, "Could not resolve target address"

    before = _read_u32(bot, target_addr)
    if before is None:
        return False, "Could not read before value"

    if verbose:
        print(f"  Before: {target_addr:#010x} = 0x{before:08X} ({before})")

    if _is_timed_scenario(scenario):
        _advance_with_timed_inputs(bot, scenario, frames, verbose)
    else:
        if input_btn and input_btn != "none":
            bot.send_and_wait(f"input {input_btn}", "ok input", timeout=5)
        bot.send_and_wait(f"frame_advance {frames}", "done frame_advance",
                          timeout=max(frames, 30))
        if input_btn and input_btn != "none":
            bot.send_and_wait(f"input_release {input_btn}", "ok input_release", timeout=5)

    after = _read_u32(bot, target_addr)
    if after is None:
        return False, "Could not read after value"

    if verbose:
        print(f"  After:  {target_addr:#010x} = 0x{after:08X} ({after})")

    before_s = struct.unpack('>i', struct.pack('>I', before))[0]
    after_s = struct.unpack('>i', struct.pack('>I', after))[0]

    if direction == "increases":
        passed = after_s > before_s
    elif direction == "decreases":
        passed = after_s < before_s
    else:
        return False, f"Unknown direction: {direction}"

    detail = f"before={before_s}, after={after_s}, direction={direction}"
    return passed, detail


def test_value_stable(claim, bot, verbose=False):
    """Test: does value at A stay constant when idle?"""
    frames = claim.get("frames", 60)
    scenario = claim.get("scenario", "straight_throttle")

    func_addr = claim.get("_parent_address", 0)

    _load_scenario(bot, scenario, verbose)

    target_addr = resolve_address(claim["address"], bot, func_addr, verbose)
    if target_addr is None:
        return False, "Could not resolve target address"

    before = _read_u32(bot, target_addr)
    if before is None:
        return False, "Could not read before value"

    bot.send_and_wait(f"frame_advance {frames}", "done frame_advance",
                      timeout=max(frames, 30))

    after = _read_u32(bot, target_addr)
    if after is None:
        return False, "Could not read after value"

    passed = before == after
    detail = f"before=0x{before:08X}, after=0x{after:08X}"
    return passed, detail


# --- Helpers ---

def _load_scenario(bot, scenario, verbose=False):
    """Load the save state for a scenario."""
    state_path = SAVE_STATES.get(scenario)
    if not state_path:
        raise ValueError(f"Unknown scenario: {scenario}")
    bot.send_and_wait("frame_advance 1", "done frame_advance", timeout=10)
    ack = bot.send_and_wait(f"load_state {_win_path(state_path)}", "load_state", timeout=15)
    if not ack or "error" in ack.lower():
        raise RuntimeError(f"Failed to load save state: {ack}")
    bot.send_and_wait("frame_advance 2", "done frame_advance", timeout=10)
    if verbose:
        print(f"  Loaded scenario '{scenario}'")


def _apply_simple_inputs(bot, scenario):
    """Press and hold all buttons for a simple (non-timed) scenario."""
    for btn in SCENARIO_INPUTS.get(scenario, []):
        bot.send_and_wait(f"input {btn}", "ok input", timeout=5)


def _release_simple_inputs(bot, scenario):
    """Release all buttons for a simple (non-timed) scenario."""
    for btn in SCENARIO_INPUTS.get(scenario, []):
        bot.send_and_wait(f"input_release {btn}", "ok input_release", timeout=5)


def _replay_timed_inputs(bot, total_frames, verbose=False):
    """Replay timed input events while advancing frames.

    Returns after advancing total_frames. Timed events from
    SCENARIO_INPUTS are interleaved with frame_advance commands.
    Call _load_scenario first to set up the save state.

    Note: The caller's scenario must already be identified. This
    function is called by the test functions that need timed input.
    """
    # This is handled inline by the test functions that need it.
    # See _advance_with_timed_inputs.
    pass


def _advance_with_timed_inputs(bot, scenario, total_frames, verbose=False):
    """Advance total_frames while replaying timed input events.

    For simple scenarios (button list), holds all buttons then advances.
    For timed scenarios (event tuples), interleaves press/release with
    frame_advance commands.
    """
    if not _is_timed_scenario(scenario):
        _apply_simple_inputs(bot, scenario)
        bot.send_and_wait(f"frame_advance {total_frames}",
                          "done frame_advance", timeout=max(total_frames, 30))
        _release_simple_inputs(bot, scenario)
        return

    events = SCENARIO_INPUTS[scenario]
    # Filter events within our frame window
    events = [(f, act, btn) for f, act, btn in events if f <= total_frames]
    current_frame = 0

    for frame, action, button in events:
        if frame > current_frame:
            delta = frame - current_frame
            bot.send_and_wait(f"frame_advance {delta}",
                              "done frame_advance", timeout=max(delta, 30))
            current_frame = frame
        if action == "press":
            bot.send_and_wait(f"input {button}", "ok input", timeout=5)
        elif action == "release":
            bot.send_and_wait(f"input_release {button}", "ok input_release", timeout=5)
        if verbose:
            print(f"    frame {frame}: {action} {button}")

    # Advance remaining frames
    remaining = total_frames - current_frame
    if remaining > 0:
        bot.send_and_wait(f"frame_advance {remaining}",
                          "done frame_advance", timeout=max(remaining, 30))

    # Release any buttons still held
    for frame, action, button in events:
        if action == "press":
            # Check if there's a matching release
            released = any(f2 > frame and act2 == "release" and btn2 == button
                           for f2, act2, btn2 in events if f2 <= total_frames)
            if not released:
                bot.send_and_wait(f"input_release {button}",
                                  "ok input_release", timeout=5)


def _parse_watchpoint_hits(hits_path):
    """Parse watchpoint_hits.txt into list of dicts."""
    hits = []
    if not os.path.exists(hits_path):
        return hits
    with open(hits_path) as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            hit = {}
            for part in line.split():
                if "=" in part:
                    key, val = part.split("=", 1)
                    if key in ("pc", "pr", "addr", "old", "new"):
                        hit[key] = int(val, 16)
                    elif key == "frame":
                        hit[key] = int(val)
                    else:
                        hit[key] = val
            if "pc" in hit:
                hits.append(hit)
    return hits


def _read_u32(bot, addr):
    """Read a 32-bit big-endian value from memory via dump_mem_bin."""
    out_path = os.path.join(IPC_DIR, "u32_tmp.bin")
    if os.path.exists(out_path):
        os.remove(out_path)
    ack = bot.send_and_wait(
        f"dump_mem_bin {_fmt_addr(addr)} 4 {_win_path(out_path)}",
        "dump_mem_bin", timeout=10,
    )
    if not ack:
        return None
    time.sleep(0.1)
    if not os.path.exists(out_path):
        return None
    with open(out_path, "rb") as f:
        data = f.read(4)
    if len(data) < 4:
        return None
    return struct.unpack(">I", data)[0]


def _get_frame(bot):
    """Get current frame number."""
    ack = bot.send_and_wait("status", "frame=", timeout=5)
    if ack:
        return _parse_frame_from_ack(ack)
    return None


def _parse_frame_from_ack(ack):
    """Extract frame=N from an ack string."""
    for part in ack.split():
        if part.startswith("frame="):
            try:
                return int(part[6:])
            except ValueError:
                pass
    return None


# --- Test Dispatch ---

TEST_TYPES = {
    "writes_to": test_writes_to,
    "call_count_per_frame": test_call_count_per_frame,
    "value_changes_with_input": test_value_changes_with_input,
    "value_stable": test_value_stable,
}


# --- Main ---

def run_claims(claim_file, only_claim=None, verbose=False):
    """Load claim file, boot emulator, run all claims, report results."""
    with open(claim_file) as f:
        data = yaml.safe_load(f)

    function = data.get("function", "unknown")
    claims = data.get("claims", [])
    parent_addr = data.get("address", 0)
    if isinstance(parent_addr, str):
        parent_addr = int(parent_addr, 16)

    if only_claim:
        claims = [c for c in claims if c.get("id") == only_claim]
        if not claims:
            print(f"No claim with id '{only_claim}' found")
            return []

    print(f"Testing {function} -- {len(claims)} claim(s)")
    print(f"Source: {data.get('source_file', 'unknown')}")
    print()

    os.makedirs(IPC_DIR, exist_ok=True)

    hits_path = os.path.join(IPC_DIR, "watchpoint_hits.txt")
    try:
        if os.path.exists(hits_path):
            os.remove(hits_path)
    except PermissionError:
        pass

    bot = MednafenBot(IPC_DIR, CUE_PATH, verbose=verbose)
    print("Starting Mednafen...")
    if not bot.start(timeout=30):
        print("FAIL: Mednafen did not start")
        return []

    print("Mednafen ready.\n")

    results = []
    for claim in claims:
        claim_id = claim.get("id", "unnamed")
        claim_type = claim["type"]
        description = claim.get("description", "")

        print(f"  [{claim_id}] {description}")

        if claim_type not in TEST_TYPES:
            print(f"    SKIP -- unknown test type: {claim_type}")
            results.append({"id": claim_id, "passed": None, "detail": "unknown type"})
            continue

        claim["_parent_address"] = parent_addr

        try:
            if os.path.exists(hits_path):
                os.remove(hits_path)
        except PermissionError:
            pass

        try:
            passed, detail = TEST_TYPES[claim_type](claim, bot, verbose)
        except Exception as e:
            passed, detail = False, f"ERROR: {e}"

        status = "PASS" if passed else "FAIL"
        print(f"    {status} -- {detail}")
        results.append({"id": claim_id, "passed": passed, "detail": detail})

    bot.quit()

    print()
    total = len(results)
    passed_count = sum(1 for r in results if r["passed"])
    types_passed = set()
    for r, c in zip(results, claims):
        if r["passed"]:
            types_passed.add(c["type"])

    if passed_count == 0:
        tier = 0
    elif passed_count >= 3 and len(types_passed) >= 2:
        tier = 2
    else:
        tier = 1

    print(f"Results: {passed_count}/{total} passed -- Tier {tier}")
    return results


def main():
    parser = argparse.ArgumentParser(description="Run auto_re claim tests")
    parser.add_argument("claim_file", help="Path to YAML claim file")
    parser.add_argument("--claim", help="Run only this claim ID")
    parser.add_argument("-v", "--verbose", action="store_true")
    args = parser.parse_args()

    results = run_claims(args.claim_file, args.claim, args.verbose)

    if any(r["passed"] for r in results):
        return 0
    return 1


if __name__ == "__main__":
    sys.exit(main())
