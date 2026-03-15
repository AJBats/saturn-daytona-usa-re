---
function: FUN_0602EFF0
address: 0x0602EFF0
address_end: 0x0602F0E4
source_file: reimpl/src/FUN_0602EFF0.s
explored: 2026-03-15
scenarios_tested: [straight_throttle, idle, steer_left_throttle]
reachable: true
---

## Call Frequency

| Scenario | Calls/Frame | Notes |
|----------|-------------|-------|
| straight_throttle | 1 | Pipeline call 2 in FUN_0602EEB8 |

## Field Access (from Static Analysis)

### Reads

| Offset | Notes |
|--------|-------|
| +0xAC | **Raw steering input.** Read at line 19: `mov.l @(r0, r1), r1` where r1=0xAC |
| +0x74 | Clamp value or state. Read at line 68/112 |
| +0x90 | State field. Read at line 112 |

### Writes

| Offset | Notes |
|--------|-------|
| +0xB0 | Computed rotation value (from atan2 of steering). Written at line 65 |
| +0xB4 | Previous rotation value. Written at line 66 (old +0xB0 → +0xB4) |
| +0x78 | State update. Written within second atan2 block |
| +0x94 | Third atan2 result. Written at line 148 |

### Steering Input Pipeline

```
car[+0xAC] (raw steering input, source unknown)
    ↓ abs(value)
    ↓ subtract deadzone (5)
    ↓ clamp to max 80 (0x50)
    ↓ restore sign
    ↓ multiply by 255 (0xFF)
    ↓ FUN_0602ECCC (atan2/rotation computation)
    ↓ output → rotation angle
    ↓
car[+0xB0] (computed rotation, prev value moved to +0xB4)
    ↓ second atan2 pass (car[+0x74] → car[+0x78])
    ↓ third atan2 pass → car[+0x94]
```

The function calls FUN_0602ECCC three times with different inputs/outputs,
producing three rotation-related values from the steering input.

### Steering Input Details

- **Deadzone**: ±5 units. Values between -5 and +5 produce 0 output.
- **Clamp**: Maximum magnitude 80 (0x50). Steering saturates at this value.
- **Scale**: Multiply by 255 (0xFF) after deadzone/clamp. Max output: 80 × 255 = 20400.
- **atan2 parameter**: 0x0096 = 150. The second parameter to FUN_0602ECCC.

### Source of car[+0xAC]

car[+0xAC] is the raw steering input but it does NOT appear in the car[0]
writer map (81 offsets) or the comprehensive writer map (95 offsets). This
means it's written by a function/mechanism NOT captured during the profiling
sessions:
1. Written before the physics pipeline starts (by the input polling code)
2. Written by DMA or the secondary SH-2
3. Written only under specific conditions not covered in profiling

The struct map does not have an entry for +0xAC. **Identifying the writer of
car[+0xAC] would reveal the controller→steering input chain.**

## Per-Frame Field Analysis

Captures: `tt_throttle_300f.csv`, `tt_idle_300f.csv`, `tt_steer_left_throttle_300f.csv`.

| Offset | Idle (300f) | Throttle (300f) | Steer LEFT (300f) | Category |
|--------|-------------|-----------------|-------------------|----------|
| +0xAC | 23 unique, f100=-106 | 23 unique, f100=-106 | 23 unique, f100=-106 | active-all-same |
| +0xB0 | 10 unique, f100=-127 | 10 unique, f100=-127 | 10 unique, f100=-127 | active-all-same |
| +0xB4 | 10 unique, f100=-127 | 10 unique, f100=-127 | 10 unique, f100=-127 | active-all-same |
| +0x94 | constant 0 | constant 0 | constant 0 | static |
| +0xD0 | 22 unique, f100=-32512 | 22 unique, f100=-32512 | 22 unique, f100=-32512 | active-all-same |

**All three scenarios produce IDENTICAL values.** The steering input (+0xAC)
and rotation outputs (+0xB0, +0xB4, +0xD0) change even with no input held,
but the changes are the same regardless of whether LEFT is pressed.

This confirms the cycle 2 finding: from a 0 mph standstill, LEFT steering
has NO observable effect on any car struct field for 300 frames. The changes
in +0xAC (23 unique values, starting near -106) represent the car settling
onto the track heading, not player input. At 0 mph, the steering pipeline
processes track alignment adjustments, not d-pad input.

To observe actual steering response, a capture from a rolling start (30+ mph)
with LEFT held would be needed.

## NOP Test Result: Kills BOTH Steering AND Throttle

**CORRECTION**: The NOP test of FUN_0602EFF0 (poke 0602EEC4 00 09) killed
throttle as well as steering. The original characterization "does NOT process
throttle" was incomplete. While FUN_0602EFF0 doesn't read g_pad_state for the
C button, it initializes state that the force pipeline depends on.

### Dependency Chain (why NOP kills throttle)

```
FUN_0602EFF0 (call 2) writes: +0xB0 (rotation), +0xB4 (prev), +0x78, +0x94
    ↓
sym_0602F0E8 (call 6) copies: +0x94 → +0x84, +0x78 → +0x68
    also: +0xD0 = EMA(+0xB0) (smoothed rotation)
    ↓
FUN_0602D43C (call 16a) reads +0xD0, computes: +0x58, +0x5C (steering values)
    ↓
FUN_0602CDF6 (call 17) reads steering state, writes: +0x60, +0x64 (track angles)
    ↓
FUN_0602CA84 (call 15) reads +0x60, +0x64 → force accumulator → +0xFC
```

When FUN_0602EFF0 is NOPped, the rotation values (+0xB0, +0x78, +0x94) never
update. The downstream EMA (+0xD0) stalls, steering chain (+0x58/+0x5C) freezes,
track angles (+0x60/+0x64) go stale, and the force accumulator receives
zero/stale inputs. Result: accel delta stays at 0, throttle has no effect.

**FUN_0602EFF0 is a PREREQUISITE for the entire force pipeline, not just steering.**
It initializes the rotation state that all downstream physics depends on.

## Characterization: Steering Input + Pipeline State Initialization

FUN_0602EFF0 (pipeline call 2, "input/state dispatch") processes **only steering**
input. It reads car[+0xAC] (steering), applies deadzone/clamp/scale, and writes
rotation angles. There is NO reference to g_pad_state, the C button, or the
B button in this function.

The throttle (C button) → accel delta (+0xFC) path enters through a different
mechanism, likely:
1. An upstream function (before the pipeline) that reads g_pad_state and writes
   a car struct field
2. Inline code in the dispatcher between JSR calls
3. Through the force accumulator (FUN_0602CA84) reading a field that was set
   by the input polling code

## Other Observations

- sym_0602F0E8 (pipeline call 6, collision state check) immediately follows
  in the same source file. It reads +0xB0 (written by this function), +0xB8,
  +0x1BC (collision flags) and does state transfer: copies +0x94→+0x84 and
  +0x78→+0x68 under normal conditions, or resets counters during collision.
- The three atan2 outputs (+0xB0, +0x78, +0x94) form a "rotation state vector"
  that downstream pipeline stages consume for heading and slip angle computation.
