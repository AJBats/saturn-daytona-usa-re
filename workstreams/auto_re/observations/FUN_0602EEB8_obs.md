---
function: FUN_0602EEB8
address: 0x0602EEB8
address_end: 0x0602EFCC
source_file: reimpl/src/FUN_0602EEB8.s
explored: 2026-03-15
scenarios_tested: [straight_throttle, left_throttle]
reachable: true
---

## Call Frequency

| Scenario | Calls/Frame | Notes |
|----------|-------------|-------|
| straight_throttle | 1 | Confirmed via breakpoint at 0x0602EEB8, fires once per frame |
| left_throttle | 1 | Same — once per frame regardless of input |

## Register Context at Entry

Consistent across both scenarios (first frame after save state load).

| Register | Value | Notes |
|----------|-------|-------|
| R0 | 0x00000150 | Parameter or offset (336 decimal) |
| R1 | 0x0607EAE4 | Globals region pointer |
| R13 | 0x060786BC | Will be overwritten — used for indirect JSR dispatch |
| R14 | 0x06078900 | Player car struct base (car[0]) — CONFIRMED |
| R15 | 0x06002FA0 | Stack pointer |
| PC | 0x0602EEB8 | Function entry |
| PR | 0x0600E5F8 | Return address — caller is near 0x0600E5F4 |

**Call chain**: BIOS → 0x06000310 → 0x060072E4 → ... → 0x0600DF20 → 0x0600E5F4 → FUN_0602EEB8.

## Pipeline Call Sequence (Empirically Validated)

Captured via pc_trace_frame starting from breakpoint at FUN_0602EEB8 entry.
Each entry is a `jsr @r13` (register-indirect) call from the dispatcher body.
Note: call_trace does NOT capture `jsr @rn` calls — pc_trace_frame was required.

### Scenario: straight_throttle (C held, time trial, 0 mph start)

| Order | PC | Target | Static Name | Sub-calls |
|-------|------|--------|-------------|-----------|
| 1 | dispatcher | 0x0602FDA4 | sym_0602FDA4 | none observed |
| 2 | dispatcher | 0x0602EFF0 | FUN_0602EFF0 | FUN_0602ECCC x3 (atan2/rotation) |
| 3 | inline | — | clear sym_0607EAC8 | inline, no JSR |
| 4 | dispatcher | 0x0602F3EC | sym_0602F3EC | none observed |
| 5 | dispatcher | 0x0602F7BC | sym_0602F7BC | none observed |
| 6 | dispatcher | 0x0602F0E8 | sym_0602F0E8 | none observed |
| 7 | conditional | 0x0602F17C | sym_0602F17C | none observed |
| 8 | dispatcher | 0x0602F474 | sym_0602F474 | none observed |
| 9 | dispatcher | 0x0602F4B4 | sym_0602F4B4 | none observed |
| 10 | dispatcher | 0x0602F5B6 | FUN_0602F5B6 | FUN_06027552 (fixed_mul), FUN_06027344 (atan2_trig) |
| 11 | dispatcher | 0x0602EFCC | sym_0602EFCC | FUN_06027344, FUN_06027378, FUN_0602ECCC |
| 12 | dispatcher | 0x0602C690 | FUN_0602C690 | none observed |
| 13 | dispatcher | 0x0602C8E2 | FUN_0602C8E2 | none observed |
| 14 | dispatcher | 0x0602CA84 | FUN_0602CA84 | none observed |
| 15 | conditional | 0x0602D43C | FUN_0602D43C | FUN_06027344, FUN_0602ECCC |
| 16 | dispatcher | 0x0602CDF6 | FUN_0602CDF6 | none observed |
| 17 | dispatcher | 0x0602D814 | sym_0602D814 | none observed |
| 18 | dispatcher | 0x0602D8BC | sym_0602D8BC | FUN_06027344, FUN_06027378, FUN_06027552, FUN_0602ECCC |

### Conditional Paths Observed

**Condition 1 — car[+0x9C]** (checked between calls 6 and 7):
- Flag value: 0 (bt taken)
- Path taken: sym_0602F17C (gear/section state machine)
- Path NOT taken: FUN_0602F270 (track force application)
- Both scenarios (throttle-only and left+throttle) took the same path at frame 1.

**Condition 2 — car[+0x9E]** (checked between calls 14 and 15):
- Flag value: 0 (bt taken)
- Path taken: FUN_0602D43C (collision + steering response)
- Path NOT taken: FUN_0602D08A via dispatcher (alt collision path)
- Both scenarios took the same path at frame 1.

### Corrections to Static Analysis

1. **FUN_0602D08A is NOT a separate dispatcher call in normal flow.** The static
   analysis (player_pipeline.md) lists it as [16b] alternative to [16a]. In the
   PC trace, FUN_0602D08A at address 0x0602D08A is reached by **fall-through
   from FUN_0602CDF6** (code at 0x0602D088 → 0x0602D08A, sequential +2 bytes),
   NOT by a `jsr @r12` from the dispatcher. The dispatcher's conditional selected
   FUN_0602D43C [16a] (car[+0x9E] == 0), but FUN_0602D08A still appears in the
   trace because FUN_0602CDF6's code body extends through that address.

2. **Call ordering differs from static analysis.** Static analysis listed the
   sequence as [16] → [17] → [18] → [19]. Empirical ordering is:
   [15] → [16a] → [17] → [18] → [19]. The [16b] address appears within
   [17]'s execution via fall-through, not as a separate dispatcher call.

3. **FUN_0602EFF0 [2] calls FUN_0602ECCC 3 times** (atan2/rotation sub),
   confirming the static prediction of x3 calls.

4. **FUN_0602F5B6 [10] has sub-calls** not mentioned in the static analysis:
   FUN_06027552 (fixed-point multiply) and FUN_06027344 (atan2/trig lookup).

5. **sym_0602EFCC [11] has sub-calls**: FUN_06027344, FUN_06027378 (inverse trig),
   FUN_0602ECCC (atan2/rotation).

### Scenario Comparison

Both straight_throttle and left_throttle produced **identical** call sequences at
frame 1. This is expected: the save state starts at 0 mph and the first frame's
input hasn't affected the car state flags yet. Both conditional flags (+0x9C, +0x9E)
are 0 in both scenarios.

To observe the alternative conditional paths (FUN_0602F270 and FUN_0602D08A via
dispatcher), the flags +0x9C and +0x9E would need to be nonzero. This likely
requires sustained driving at speed or a collision event.

## Per-Frame Field Analysis

Captures: `tt_throttle_300f.csv` (C held) and `tt_idle_300f.csv` (no input).
Full car struct (616 bytes) sampled every frame for 300 frames from usa_tt_straight.mc0.

### Non-static fields touched by the pipeline:

| Offset | Idle behavior | Input behavior | Category | Notes |
|--------|---------------|----------------|----------|-------|
| +0x00 | static (0x800000) | 2 values (0x800000, 0x800008) | near-static | Flags byte changes late |
| +0x08 | static (0) | 0→0x2F over 300f | input-responsive | Speed index |
| +0x0C | static (0) | 0→0xA866 over 300f | input-responsive | Speed magnitude |
| +0x10 | static (8750591) | 8750591→8080064 | input-responsive | Decreasing with speed (position X?) |
| +0x14 | static (0) | static (0) | static | Y component — flat track |
| +0x18 | static (9587149) | 9587149→9147146 | input-responsive | Decreasing with speed (position Z?) |
| +0x1C | static (0) | 3 values | near-static | Pitch — nearly flat track |
| +0x20 | 19 values | 101 values | active-both | Changes even idle — track curvature? |
| +0x24 | static (0) | static (0) | static | Roll angle — flat track |
| +0x28 | 19 values | 101 values | active-both | Tracks +0x20 pattern |
| +0x30 | 19 values | 101 values | active-both | Matches +0x20 exactly |
| +0x38 | static | 97 values | input-responsive | Position X lag (see velocity section) |
| +0x3C | static | 97 values | input-responsive | Position Z lag |
| +0x40 | 19 values (both) | 19 values (both) | active-both | Converges to 0xFE0 |
| +0x48 | static (-2733006) | -2733006→-2951628 | input-responsive | Drag accumulator |
| +0x50 | static (-2814926) | -2814926→-3798290 | input-responsive | Drag copy |
| +0x58 | 18 values | 91 values | active-both | Changes even idle |
| +0x5C | static (1) | 37 values | input-responsive | Steering accumulator? |
| +0xC0 | static (0) | 91 values | input-responsive | Computed value |
| +0xE0 | static (0) | 97 values | input-responsive | Track force output |
| +0xE8 | static (0) | static (0) | static | Speed headroom — stays 0 |
| +0xF4 | static (0) | 3 values | near-static | Surface grip |
| +0xF8 | static (524288) | 35 values | input-responsive | Increasing from 0x80000 |
| +0xFC | static (0) | 44 values | input-responsive | Accel delta (CONFIRMED) |
| +0x18C | static (0) | 98 values | input-responsive | = +0x10 - +0x38 (see below) |
| +0x190 | static (0) | 98 values | input-responsive | = +0x18 - +0x3C (see below) |

### Velocity Relationships (Empirically Verified)

**+0x18C = +0x10 - +0x38** at every frame (100% match across 300 frames).
**+0x190 = +0x18 - +0x3C** at every frame (100% match across 300 frames).

These fields hold the per-update position delta (displacement since +0x38/+0x3C
was last stored). This is the frame velocity in world coordinates.

**+0x38 ≠ prev_frame(+0x10)**: Only 106/299 frames match. +0x38 holds the position
from a prior update, not the immediately previous frame. At low speeds, position
updates are sparse (small deltas truncate to zero), so +0x38 can lag +0x10 by
several frames. This does not mean +0x38 is "wrong" — it means position updates
don't occur every frame at very low speeds.

### Field Value Snapshots

#### +0x0C (speed)
- Frame 0: 0x0 (0 mph)
- Frame 50 (C held): 0x3DB5 (10.7 mph)
- Frame 100 (C held): 0xA073 (28.0 mph)
- Frame 200 (C held): 0xA4F9 (28.8 mph)
- Frame 299 (C held): 0xA866 (29.4 mph)
- Idle: constant 0x0

#### +0x10 (position field)
- Frame 0: 8750591
- Frame 100 (C held): 8171002 (delta: -579589)
- Frame 299 (C held): 8080064 (delta: -670527)
- Idle: constant 8750591

#### +0x20 (heading field)
- Frame 0: 0x3FFD (16381)
- Frame 100 (C held): 0x6E85 (28293)
- Frame 299 (C held): 0xFFFFB7F3 (-18445 signed)
- Frame 100 (idle): 0x3BFD (15357)
- Frame 299 (idle): 0x3BFD (15357)
- Changes even when idle (19 unique values early, then stabilizes)

### Sample captures
- `build/samples/tt_throttle_300f.csv` — C held, 300 frames
- `build/samples/tt_idle_300f.csv` — no input, 300 frames

## Multi-Car Comparison

N/A — FUN_0602EEB8 is the player-only physics dispatcher. It processes car[0]
exclusively. The AI car loop (FUN_0600e0c0) uses a separate pipeline.

## Other Observations

- FUN_0602EEB8 is called from 0x0600E5F4 (PR=0x0600E5F8). The call chain
  passes through 0x0600DF20, which is within the per-frame game loop.
- The dispatcher uses `jsr @r13` for all sub-calls, loading each target from
  a constant pool. This means standard call_trace (JSR/BSR/BSRF capture) does
  NOT record these calls. Only pc_trace_frame captured the full sequence.
- The total pipeline execution spans ~1700 instructions (idx 0-1700 in PC trace)
  for the dispatcher body, plus ~3000 more for call 18 (POSITION_WRITER) which
  includes trig computations.
- The pipeline ends with a mask operation: `car[+0x00] &= 0xFFFFFC3F` (clears
  bits 6-9 of the flags field).
- +0x20, +0x28, and +0x30 all change even with no input (19 unique values in
  idle). The changes occur in the first ~18 frames then stabilize at +0x3BFD.
  This is consistent with the car "settling" into the track heading at the save
  state position — even at 0 mph, the heading/slip angle adjusts to match the
  track direction.
