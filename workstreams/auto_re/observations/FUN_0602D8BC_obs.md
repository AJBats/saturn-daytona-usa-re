---
function: sym_0602D8BC
address: 0x0602D8BC
address_end: ~0x0602DA98
source_file: reimpl/src/FUN_0602D89A.s
explored: 2026-03-15
scenarios_tested: [straight_throttle, idle, steer_left_throttle, right_wall_strike]
reachable: true
---

## Call Frequency

| Scenario | Calls/Frame | Notes |
|----------|-------------|-------|
| straight_throttle | 1 | Pipeline call 19 in FUN_0602EEB8 — always runs |
| idle | 1 | Same |
| steer_left_throttle | 1 | Same |
| right_wall_strike | 1 | Same, including during/after collision |

## Register Context at Entry

From FUN_0602EEB8 pipeline: r14 = car pointer (0x06078900 for player),
r0 = car pointer (same). Called via `jsr @r13` where r13 is loaded from
pool constant .L_0602EFC4 = sym_0602D8BC.

## Memory Writes (from writer map)

sym_0602D8BC writes these fields per the writer map and static analysis:

| Target | Writer PC | Notes |
|--------|-----------|-------|
| car[+0x10] | 0x0602D902 | Position X. 475 writes, 455 unique |
| car[+0x18] | 0x0602D912 | Position Z. 475 writes, 375 unique |
| car[+0x20] | 0x0602D8CE | Heading. 475 writes, 361 unique |
| car[+0x38] | 0x0602D8DE | Saved position X (pre-update). 475 writes |
| car[+0x3C] | 0x0602D8E0 | Saved position Z (pre-update). 475 writes |
| car[+0x18C] | 0x0602D8FE | Velocity X component. 475 writes, 456 unique |
| car[+0x190] | 0x0602D90E | Velocity Z component. 475 writes, 376 unique |

## Per-Frame Field Analysis

Captures used: `tt_throttle_300f.csv`, `tt_idle_300f.csv`,
`tt_steer_left_throttle_300f.csv`, `tt_right_wall_strike_662f.csv`.

### Position: +0x10, +0x14, +0x18, +0x1C

| Offset | Throttle (300f) | Idle (300f) | Steer LEFT (300f) | Wall Strike (662f) | Category |
|--------|----------------|-------------|-------------------|-------------------|----------|
| +0x10 | 8750591→8080064 (↓) | constant 8750591 | identical to throttle | 8750591→8615311→8564501 | input-responsive |
| +0x14 | constant 0 | constant 0 | constant 0 | constant 0 | static |
| +0x18 | 9587149→9147146 (↓) | constant 9587149 | identical to throttle | 9587149→9533202→9340000 | input-responsive |
| +0x1C | constant 0 | constant 0 | constant 0 | constant 0 | static |

**Observations:**
- +0x10 and +0x18 decrease monotonically with throttle from standstill. Both are
  constant when idle. Consistent with world position that changes as the car moves.
- +0x14 and +0x1C are zero across ALL scenarios — the track is flat, so Y position
  and pitch angle are unused. These fields are written by different functions
  (FUN_06005ED0 and FUN_0600611A) which are not in the player pipeline.
- Steer LEFT produces IDENTICAL position values to throttle-only through all 300
  frames. At the speeds achieved from standstill (~30 mph), LEFT steering has no
  observable effect on trajectory. This is consistent with speed-dependent steering.
- Wall strike: +0x10 decreases to ~8171000 (frame 100), then INCREASES after wall
  impact (frame ~300+) as the car bounces back. +0x18 continues decreasing but at
  a different rate after collision, indicating the car slides along the wall.

### Heading: +0x20, +0x28, +0x30

| Offset | Throttle (300f) | Idle (300f) | Steer LEFT (300f) | Wall Strike (662f) | Category |
|--------|----------------|-------------|-------------------|-------------------|----------|
| +0x20 | 16381→-18445 (101 uniq) | 16381→15357 (19 uniq) | identical to throttle | 16381→17043 (222 uniq) | active-both |
| +0x28 | 16383→-30358 (101 uniq) | 16383→16383 (19 uniq) | identical to throttle | 16383→28889 (214 uniq) | active-both |
| +0x30 | identical to +0x20 | identical to +0x20 | identical to +0x20 | identical to +0x20 | copy of +0x20 |

**Key finding: +0x30 == +0x20 at every frame across all 4 scenarios.**
The struct map hypothesis of "heading delta" is wrong. +0x30 is a copy of +0x20.
This copy may be written at a different pipeline stage than +0x20, serving as a
snapshot for downstream readers.

**+0x20 vs +0x28 divergence (steer LEFT scenario):**

| Frame | +0x20 | +0x28 | Difference |
|-------|-------|-------|------------|
| 0 | 16381 | 16383 | +2 |
| 50 | 16275 | 16930 | +655 |
| 100 | 28293 | 22583 | -5710 |
| 150 | -527 | -12576 | -12049 |
| 200 | -28033 | 25488 | +53521 (wraps) |
| 250 | 10441 | -1540 | -11981 |
| 299 | -18445 | -30358 | -11913 |

+0x20 and +0x28 start nearly identical (diff=2) and diverge over time. The
divergence grows as the car accelerates and the track curves. At frame 200 the
difference wraps around the 16-bit range (53521 ≈ 65536-11913), confirming
these are angular values in a 16-bit space. The ~12000-unit divergence at steady
state is consistent with a slip angle or body-vs-wheel heading offset.

**Heading changes even when idle:** +0x20 changes from 16381 to 15357 in the
first ~18 frames of idle, then stabilizes. This is the car "settling" onto
the track heading at the save state position — the initial heading doesn't
perfectly match the track direction, so the physics adjusts it.

### Velocity: +0x38, +0x3C, +0x18C, +0x190

| Offset | Throttle | Steer LEFT | Wall Strike | Relationship |
|--------|----------|------------|-------------|-------------|
| +0x38 | tracks +0x10, 97 uniq | identical to throttle | 220 uniq | saved position X |
| +0x3C | tracks +0x18, 97 uniq | identical to throttle | 220 uniq | saved position Z |
| +0x18C | 0→9896, 98 uniq | identical to throttle | 235 uniq | velocity X = +0x10 - +0x38 |
| +0x190 | 0→-41959, 98 uniq | identical to throttle | 235 uniq | velocity Z = +0x18 - +0x3C |

**Empirically verified relationships (all scenarios):**
- `car[+0x18C] = car[+0x10] - car[+0x38]` — 300/300 throttle, 300/300 steer, 656/662 wall
- `car[+0x190] = car[+0x18] - car[+0x3C]` — same match rates
- Wall strike: 6 mismatches out of 662 frames, likely during active collision
  frame where values are mid-update at the sample point.

**+0x38 is NOT previous-frame +0x10.** Verified: only 106/299 match when
comparing +0x38[N] to +0x10[N-1]. However, +0x38 holds the position from
before the most recent position update within the same frame. The pipeline
saves +0x38 = +0x10 then updates +0x10 += velocity. At the sample point
(between frames), both are their post-update values.

### Field Value Snapshots

#### +0x10 (position X) — wall strike scenario
- Frame 0: 8750591
- Frame 100: 8171083 (car moving forward)
- Frame 299: 8615311 (car bounced off wall, position reversed)
- Frame 500: 8571123
- Frame 661: 8564501 (stable post-collision)

#### +0x20 (heading) — wall strike scenario
- Frame 0: 16381
- Frame 100: 4390 (heading changed toward wall)
- Frame 299: -6704 (heading deflected by collision)
- Frame 500: 16921
- Frame 661: 17043 (heading stabilized near original)

### Sample captures
- `build/samples/tt_throttle_300f.csv` — C held, 300 frames (Priority 2/4 baseline)
- `build/samples/tt_idle_300f.csv` — no input, 300 frames
- `build/samples/tt_steer_left_throttle_300f.csv` — C + LEFT, 300 frames (Priority 3)
- `build/samples/tt_right_wall_strike_662f.csv` — C + RIGHT, 662 frames (collision)

## Multi-Car Comparison

N/A — sym_0602D8BC is in the player pipeline (FUN_0602EEB8, call 19).
It processes car[0] only. The AI car loop uses inline velocity integration.

## Other Observations

- Steer LEFT produced IDENTICAL field values to throttle-only across all 300 frames.
  At the speeds achieved from 0 mph standstill (~30 mph at frame 299), steering
  input has no observable effect on position or heading. This is consistent with
  speed-dependent steering — the car needs to be moving faster before steering
  takes effect. A rolling-start save state would be needed to observe steering.

- The position writer is the LAST call in the pipeline (call 19). By the time it
  runs, all upstream pipeline stages have finished computing speed (+0x0C), heading
  (+0x20), and accel delta (+0xFC). The writer decomposes scalar speed into X/Z
  velocity via trig(heading) and integrates position.

- The static analysis says the writer branches on car[+0x250]:
  - If 0 (normal): straight heading-based velocity integration
  - If nonzero (drift): table-scaled rotation path
  In the observed scenarios, +0x250 is always 0. The drift path was not exercised.
