---
function: FUN_0602CA84
address: 0x0602CA84
explored: 2026-03-15
scenarios_tested: [straight_throttle, idle]
reachable: true
---

## Supplement: Throttle Pipeline Input Fields

Cross-referencing `tt_throttle_300f.csv` and `tt_idle_300f.csv` to identify
which fields carry the throttle signal into the force accumulator.

### Fields That Respond to Throttle (C button)

| Offset | Idle | Throttle f0 | Throttle f50 | Throttle f150 | Unique (T/I) | Role in FUN_0602CA84 |
|--------|------|-------------|--------------|---------------|-------------|---------------------|
| +0x108 | const 65536 | 65536 | 65536 | 28188 | 63/1 | Read + Write (clamped force) |
| +0x10C | const 65536 | 65536 | 57279 | 11141 | 34/1 | Read + Write (clamped force) |
| +0x110 | const -1372 | -1372 | 6783 | 24463 | 91/1 | Not directly read by CA84 |
| +0x178 | const -1 | -1 | -165 | -645 | 47/1 | Not directly read by CA84 |
| +0x264 | const -5323 | -5323 | 49818 | 16710 | 89/1 | Not directly read by CA84 |
| +0x100 | const 0 | 0 | 0 | 0 | 1/1 | sin(roll)=0 on flat (read by CA84) |
| +0x104 | const 65536 | 65536 | 65536 | 65536 | 1/1 | cos(roll)=1 on flat (read by CA84) |

### Observations

1. **+0x108 and +0x10C decrease from 65536 (0x10000) with throttle.** These are
   the clamped force values that FUN_0602CA84 reads AND writes each frame. They
   start at 1.0 (16.16 fixed-point) and decrease as the car accelerates. The
   decrease is the force being "consumed" — as speed builds, the available force
   decreases (drag increases).

2. **+0x108 doesn't change until ~frame 30** (stays at 65536), then starts
   decreasing. +0x10C starts decreasing earlier (~frame 20). This lag suggests
   +0x108 responds to a downstream effect of speed, not directly to throttle.

3. **+0x110 is the most responsive field** (91 unique values). It starts at
   -1372 and increases to 24463 with throttle. This field is NOT directly read
   by FUN_0602CA84 based on static analysis — it may be read by an upstream
   pipeline stage that feeds +0x108/+0x10C.

4. **+0x100 = 0, +0x104 = 65536 (0x10000)** on flat track, confirming cycle 3
   findings. On flat ground: sin(0)=0, cos(0)=1.0 in 16.16 fixed-point. The
   roll projection terms in FUN_0602CA84 are zero, so the accel delta computation
   relies entirely on +0x108/+0x10C and the surface/gear terms.

5. **+0x114 has a step change**: constant 0 for 140+ frames, then jumps to
   26214400 (0x1900000). FUN_0602CA84 reads this and subtracts it in the final
   force computation — this is a RESISTANCE term that kicks in at a threshold
   (possibly a speed or gear threshold).

### Throttle Pipeline (Updated Understanding)

```
C button → g_pad_state
    ↓ [STILL UNMAPPED — upstream function reads pad state]
car[+0x110]? → upstream physics stages
    ↓ pipeline stages (calls 13-16)
car[+0x108] (clamped force X) + car[+0x10C] (clamped force Z)
    ↓ FUN_0602CA84 (call 15)
    ├── × car[+0x108] (read)
    ├── × car[+0x10C] (read)
    ├── - car[+0x114] (resistance, subtracted)
    ├── × gear_constant (from +0x7C/+0xD8)
    ↓ >> 8 (fixed-point shift)
car[+0xFC] (accel delta, CONFIRMED)
    ↓ sym_0602D814 (call 18)
car[+0x0C] (speed, CONFIRMED)
```

### Recommended Next Step

Set breakpoint on the write to car[+0x110] to find its writer function and
trace the connection to g_pad_state. The writer map entry for +0x110 is not
in the struct map field table — it needs identification. +0x110 appears to be
the closest field to the raw throttle input in the force accumulator chain.
