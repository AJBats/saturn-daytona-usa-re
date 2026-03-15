---
function: FUN_0602CA84 (throttle input tracing)
address: 0x0602CA84
explored: 2026-03-15
scenarios_tested: [straight_throttle, idle]
reachable: true
---

## Final Throttle Gap Resolution

Cross-referenced ALL FUN_0602CA84 read fields between C-held and idle at
early frames (before speed diverges). Only 3 fields differ at frame 1:

| Field | C-held (f1) | Idle (f1) | Source |
|-------|-------------|-----------|--------|
| +0x74 | 66 | 56 | sym_0602FDA4 (call 1) — **throttle accumulator** |
| +0x6C | 1 | 0 | sym_0602FDA4 (call 1) — **throttle active flag** |
| +0x11C | -35530142 | -48064153 | FUN_0602F5B6 (call 11) — surface energy |

**+0x108 and +0x10C do NOT diverge at early frames** — both are 65536 in
both scenarios through frame 10+. These self-accumulate LATER based on
downstream effects of +0x74, not from direct throttle input.

## Complete Throttle Pipeline (No Gaps)

```
C button (bit 0x0200 in g_pad_state)
    ↓ sym_0602FDA4/FUN_0602FDB0 (pipeline call 1)
car[+0x6C] = 1 (throttle flag)
car[+0x74] += 10/frame (max 184, decays to 56)
    ↓ sym_0602F0E8 (call 6) copies +0x74 → +0x84
    ↓ FUN_0602CA84 (call 15) reads +0x74 directly
    ↓ force accumulation using +0x74 and surface/geometry terms
car[+0xFC] (accel delta)
    ↓ sym_0602D814 (call 18)
car[+0x0C] (speed) += car[+0xFC]
car[+0xE0] = gear_scaled_speed
    ↓ FUN_0602CCEC (within call 15, next frame)
car[+0x110] = f(car[+0xE0])  // speed convergence feedback
    ↓ sym_0602D8BC (call 19)
car[+0x10] += velocity_x    // position integration
car[+0x18] += velocity_z
```

The +0x108/+0x10C self-accumulation is a SECONDARY effect driven by the
speed convergence loop, not the primary throttle input path.

## Phase 2 Priority 1: RESOLVED

The "remaining gap" asked which FUN_0602CA84 read carries the C button.
Answer: **car[+0x74]** (throttle accumulator), read directly by FUN_0602CA84.
Watchpoints on +0x108 are unnecessary — that field is downstream of +0x74.
