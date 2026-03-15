---
function: FUN_0602C8E2
address: 0x0602C8E2
address_end: ~0x0602CA84
source_file: reimpl/src/FUN_0602C8E2.s
explored: 2026-03-15
scenarios_tested: [straight_throttle]
reachable: true
---

## Call Frequency

| Scenario | Calls/Frame | Notes |
|----------|-------------|-------|
| straight_throttle | 1 | Pipeline call 14 in FUN_0602EEB8 |

## Field Access (from offset constants)

### Reads

| Offset | Notes |
|--------|-------|
| +0x40 | Angular velocity (first read, XOR'd with +0x5C for sign check) |
| +0x5C | Steering accumulator (XOR'd with +0x40) |
| +0x08 | Speed index. Compared against 0x46 (70) and 0x64 (100) as thresholds |
| +0x60, +0x64 | Track angles (XOR'd for direction check) |
| +0xD0 | Smoothed rotation |
| +0x16C | Counter/state (16-bit?) |
| +0xD4 | Animation counter |
| +0x170 | Unknown state field |
| +0x128 | Orientation value |
| +0x16A | Unknown (16-bit) |
| +0x144 | World coordinate |
| +0x11C | Surface energy |
| +0x168 | Steering intensity timer (from FUN_0602D43C) |
| +0xF4 | Surface grip |

### Writes

| Offset | Notes |
|--------|-------|
| +0x168 | Steering timer written at line 45: set to 0xA (10) under conditions |
| +0x16A | Unknown (16-bit), set conditionally |

## Computation Summary

295-line function. Gate conditions based on speed index:
1. If speed_index < 70 (0x46): skip most computation
2. If speed_index < 100 (0x64): reduced computation path

Checks sign agreement between angular velocity (+0x40) and steering
accumulator (+0x5C). If they disagree (XOR < 0), the function applies
corrections — this detects counter-steering or oversteer conditions.

Also checks track angle sign agreement (+0x60 XOR +0x64) and compares
against thresholds. When conditions are met, sets the steering intensity
timer (+0x168) to 10 and writes to +0x16A.

## Per-Frame Field Analysis

| Offset | Idle | Throttle | Category |
|--------|------|----------|----------|
| +0x40 | 19 unique | 19 unique | active-both |
| +0x5C | constant 1 | 37 unique | input-responsive |
| +0xD0 | 22 unique | 61 unique | active-both |

## Other Observations

- The speed thresholds (70 and 100 in speed_index, which correspond to
  ~1.9 mph and ~2.7 mph) gate the collision response computation. At
  very low speeds, collision response is disabled.
- The XOR sign checks detect when the car's angular state (velocity vs
  accumulator, or track angles) is "crossed" — indicating oversteer,
  counter-steering, or loss of traction.
