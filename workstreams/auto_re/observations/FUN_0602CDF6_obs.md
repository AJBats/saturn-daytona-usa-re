---
function: FUN_0602CDF6
address: 0x0602CDF6
address_end: 0x0602D088
source_file: reimpl/src/FUN_0602CDF6.s
explored: 2026-03-15
scenarios_tested: [straight_throttle, idle]
reachable: true
---

## Call Frequency

| Scenario | Calls/Frame | Notes |
|----------|-------------|-------|
| straight_throttle | 1 | Pipeline call 17 in FUN_0602EEB8 |

## Overview

406-line function. State finalize — computes heading/slip angle updates,
manages collision counters, writes +0x30 (heading delta), +0x60/+0x64
(track angles), +0x258 (collision counter), +0x25C (computed angle).
Contains the code region 0x0602CE4E identified by the writer map as the
heading/slip writer.

## Field Access

### Reads

| Offset | Notes |
|--------|-------|
| +0x40 | Angular velocity |
| +0x58 | Steering input |
| +0x5C | Steering accumulator |
| +0x252 | Frame/drift counter |
| +0xD0 | Smoothed rotation (from sym_0602F0E8 EMA) |
| +0x30 | Heading delta (read 3 times, modified, written back) |
| +0x25C | Computed angle |
| +0x28 | Slip angle (read at line 374) |

### Writes

| Offset | Notes |
|--------|-------|
| +0x60 | Track angle X (via FUN_06027344 atan2) |
| +0x64 | Track angle Z (via FUN_06027344 atan2) |
| +0xD0 | Modified rotation |
| +0x30 | Heading delta (final write at line 402) |
| +0x258 | Collision counter (incremented, or zeroed) |
| +0x25C | Computed angle (written) |

### Sub-calls

| Target | Notes |
|--------|-------|
| FUN_06027344 | atan2/trig lookup |
| FUN_06027348 | trig variant |
| FUN_0602ECCC | atan2/rotation (implied from code range) |

## Heading Delta Computation

The function reads car[+0x30] (heading delta) three times (lines 313, 345, 377)
and writes it once (line 402). The computation:

1. Compute difference: `r4 = car[+0x30] - car[+0x25C]` (heading vs computed angle)
2. If difference > ±0x0444 (1092): increment car[+0x258] (collision counter)
3. Apply correction: adjust car[+0x25C] by ±0x8000 toward car[+0x30]
4. Recompute: `r4 = car[+0x30] - adjusted car[+0x25C]`
5. If still > ±0x0444: increment counter again, clamp correction to ±0x3C (60)
6. Final: `car[+0x30] = car[+0x30] + clamped_correction`

This is a heading convergence algorithm: car[+0x30] is adjusted toward a target
angle, with the correction clamped to prevent large jumps. The collision counter
(+0x258) tracks how many frames the heading is far from the target.

## Per-Frame Field Analysis

| Offset | Idle | Throttle | Category |
|--------|------|----------|----------|
| +0x30 | 19 unique | 101 unique | active-both |
| +0x60 | 16 unique | 98 unique | active-both |
| +0x64 | 16 unique | 98 unique | active-both |
| +0x258 | constant 0 | 89 unique | input-responsive |

+0x30 (heading delta) changes even when idle (19 unique) — the track settling
effect. +0x258 (collision counter) is constant 0 when idle but active with
throttle — the heading divergence detection triggers as the car accelerates.

## Other Observations

- The code at 0x0602CE4E (identified in the writer map as the heading/slip
  writer) falls within this function's execution range. The writer map's
  "FUN_0602CE4E" is a profiler-assigned boundary, not a separate function.
- The fall-through to FUN_0602D08A (identified in cycle 1) occurs at the
  end of this function's code range — execution reaches 0x0602D088 and
  continues to 0x0602D08A sequentially.
- Constants: 0x4000 (16384 = quarter-turn in 16-bit angle), 0x0444 (1092 =
  threshold ~6 degrees), 0x8000 (32768 = half-turn correction step).
