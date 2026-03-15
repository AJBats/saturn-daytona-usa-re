---
function: FUN_0602D43C
address: 0x0602D43C
address_end: 0x0602D814
source_file: reimpl/src/FUN_0602D43C.s
explored: 2026-03-15
scenarios_tested: [straight_throttle, idle]
reachable: true
---

## Call Frequency

| Scenario | Calls/Frame | Notes |
|----------|-------------|-------|
| straight_throttle | 1 | Pipeline call 16a (conditional: car[+0x9E] == 0) |

## Overview

689-line function — the largest in the player physics pipeline. Contains
sub-functions FUN_0602D7E4 (damping/clamp) and sym_0602D814 (speed writer,
documented separately). The main body (0x0602D43C to ~0x0602D7E4) handles
collision response and steering angle computation.

## Field Access (from offset constants in source)

### Reads

| Offset | Role | Notes |
|--------|------|-------|
| +0x154 | Smoothed heading | Gates steering intensity computation |
| +0x166 | Effect timer (16-bit) | If > 0, skip heading recomputation |
| +0x08 | Speed index | If ≤ 240, skip collision steering |
| +0x40 | Angular velocity | Must be nonzero for heading correction |
| +0x10C | Clamped force Z | Must be ≤ 0x6800 for heading correction |
| +0x11C | Surface energy | Used in force computation |
| +0x5C | Steering accumulator | Read and modified |
| +0x58 | Steering input | Read and modified |
| +0x144 | World coordinate | Cross-multiplied with force |
| +0x140 | World coordinate | Cross-multiplied with force |
| +0x108 | Clamped force X | Used in steering computation |
| +0x178 | Lateral force | Read and modified |
| +0xD4 | Animation counter | Read (16-bit) |

### Writes

| Offset | Notes |
|--------|-------|
| +0x168 | Steering intensity timer (16-bit). Set to [4, 10] on heading change |
| +0x58 | Updated steering input |
| +0x5C | Updated steering accumulator |
| +0x178 | Updated lateral force |
| +0x166 | Conditionally modified (16-bit) |
| +0x40 | Modified via atan2 computation |

### Sub-calls

| Target | Notes |
|--------|-------|
| FUN_06027344 | atan2/trig lookup — called 3 times |
| FUN_06027378 | Inverse trig — called once |
| FUN_0602ECCC | atan2/rotation — called 3 times |
| FUN_0602D7E4 | Damping/clamp sub-function (at 0x0602D7E4 within this file) |

## Computation Summary

### Entry Gate (lines 7-32)

Four conditions must be met for the main heading correction path:
1. car[+0x166] (effect timer) must be ≤ 0
2. car[+0x08] (speed index) must be > 240 (0xF0) — high speed only
3. car[+0x40] (angular velocity) must be nonzero
4. car[+0x10C] (clamped force) must be ≤ 0x6800

If all pass: compute heading intensity = clamp(abs(+0x154) - 760, 4, 10),
write to +0x168.

### Steering/Collision Response (lines 76+)

Uses the heading intensity (+0x168 or 0) to scale trig computations:
- Three atan2 calls produce rotation corrections
- Applied to +0x58 (steering), +0x5C (steering accumulator), +0x178 (lateral)
- FUN_0602D7E4 (damping) clamps values to prevent overflow

## Per-Frame Field Analysis

| Offset | Idle | Throttle | Category | Notes |
|--------|------|----------|----------|-------|
| +0x58 | 18 unique | 91 unique | active-both | Steering, changes even idle |
| +0x5C | constant 1 | 37 unique | input-responsive | Accumulator, throttle-dependent |
| +0x178 | constant -1 | 47 unique | input-responsive | Lateral force |
| +0x40 | 19 unique (both) | 19 unique (both) | active-both | Converges to -4064 |
| +0x154 | 15 unique | 98 unique | active-both | Smoothed heading |

## Other Observations

- The function's entry gate (speed > 240, angular velocity nonzero, force ≤ 0x6800)
  means the heading correction only activates at higher speeds with active rotation.
  From standstill, the gate is closed for the first ~100 frames until speed builds up.
- sym_0602D814 (speed writer, call 18) is defined WITHIN this same source file
  (line 600+) but is a separate pipeline call, not part of FUN_0602D43C's execution.
- FUN_0602D7E4 (damping/clamp, at line ~560) is a BSR sub-call that limits the
  magnitude of steering corrections to prevent numerical overflow.
