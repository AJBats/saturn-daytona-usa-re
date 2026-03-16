---
function: FUN_0602CA84 (brake force path)
address: 0x0602CA84
explored: 2026-03-16
scenarios_tested: [throttle_vs_brake_at_matched_speed]
reachable: true
---

## Experiment 1: Brake Force Path Inside FUN_0602CA84

Compared throttle (frame 61, 15.5 mph) vs brake (frame 28, 15.7 mph)
using existing CSV captures. Speed-matched to isolate brake-specific changes.

## Brake-Specific Fields (differ ONLY because of brake, not speed)

| Field | Throttle @15mph | Brake @15mph | Role |
|-------|----------------|-------------|------|
| +0x6C | 1 | 0 | Throttle flag OFF |
| +0x74 | 184 | 175 | Throttle accum (decaying, was 184) |
| +0x84 | 0 | 255 | **BRAKE CARRIER into force pipeline** |
| +0x88 | 0 | 1 | Brake active flag |
| +0x8C | 56 | 216 | Brake force copy |
| +0x90 | 56 | 216 | Brake force accumulator |
| +0x94 | 0 | 255 | State value (mirrors +0x84 pattern) |
| +0x114 | 0 | 26214400 | **Resistance term ACTIVATED** |

## How Brake Produces Negative Accel Delta

The brake signal enters FUN_0602CA84 through **TWO paths**:

### Path 1: +0x84 state override

Normal path: sym_0602F0E8 (call 6) copies car[+0x74] → car[+0x84].
During braking: +0x84 = 255 (0xFF) instead of the throttle-derived value.
This value comes from the collision/brake path in sym_0602F0E8 which
sets +0x84 = 0x38 (56) normally, but the brake handler in sym_0602FDA4
writes +0x90 = 216, which propagates through the state transfer chain.

FUN_0602CA84 reads +0x84 as part of its force computation. When +0x84 = 255
(brake) vs 0 (throttle), the force formula produces a different result.

### Path 2: +0x114 resistance term

During braking, +0x114 = 26214400 (0x01900000). This is from the animation
lookup table sym_060477D8[1]. The force formula SUBTRACTS +0x114:

```
accel_delta = (car[+0x108] × A + car[+0x10C] × B - car[+0x114]) × gear >> 8
```

With +0x114 = 26214400 (a large value), the subtraction dominates, producing
a strongly negative accel delta (observed peak: -303).

When throttle-only (no brake), +0x114 = 0 — no resistance subtracted.

### Combined Effect

| Component | Throttle @15mph | Brake @15mph |
|-----------|----------------|-------------|
| +0x108 × A | 65536 × A | 40500 × A |
| +0x10C × B | 53689 × B | 11141 × B |
| - +0x114 | - 0 | - 26214400 |
| Result +0xFC | +1558 | -2217 |

The brake produces negative accel delta through the massive +0x114 resistance
term AND reduced force accumulators (+0x108, +0x10C decrease during braking).

## Other Brake-Related Differences

| Field | Throttle | Brake | Notes |
|-------|----------|-------|-------|
| +0x40 | 4064 | -4064 | Angular velocity — SIGN FLIPS during brake |
| +0x50 | -2935452 | -5545810 | Drag accum diverges (different +0xC0 gate) |
| +0xD0 | -32512 | 32511 | Smoothed rotation — sign flip |
| +0xD4 | 0 | 65536 | Animation counter — active during brake |
| +0xEC | 0 | 188743680 | Surface normals populate during brake scenario |
| +0x1FC | 768 | 1024 | Different surface type (different track position) |

The sign flips in +0x40 and +0xD0 suggest the car was facing the opposite
direction in the brake scenario (it had been driving for 750f before braking,
while throttle started from standstill).

### Sample captures used
- `build/samples/tt_throttle_300f.csv` frame 61 (15.5 mph accelerating)
- `build/samples/tt_brake_300f.csv` frame 28 (15.7 mph braking)
