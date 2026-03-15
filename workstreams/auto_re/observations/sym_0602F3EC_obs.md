---
function: sym_0602F3EC
address: 0x0602F3EC
address_end: 0x0602F470
source_file: reimpl/src/FUN_0602F270.s (line 230+)
explored: 2026-03-15
scenarios_tested: [straight_throttle, idle, brake]
reachable: true
---

## Call Frequency

| Scenario | Calls/Frame | Notes |
|----------|-------------|-------|
| straight_throttle | 1 | Pipeline call 4 in FUN_0602EEB8 |

## Field Access (Complete from Static Analysis)

### Reads

| Offset | Notes |
|--------|-------|
| +0x0C | Speed magnitude. `mov.l @(12, r0), r2` |
| +0x48 | Drag accumulator. Read then decremented |
| +0xC0 | Gate flag. `tst r4, r4` — if nonzero, uses alternate drag constant |
| +0x50 | Second drag accumulator. Read then decremented |

### Writes

| Offset | Notes |
|--------|-------|
| +0x08 | Speed index. `mov.l r2, @(8, r0)` — CONFIRMED formula |
| +0x48 | Drag accumulator. `car[+0x48] -= scaled_speed_index` |
| +0x50 | Second drag. `car[+0x50] -= scaled_speed_index` (or alternate constant) |

## Computation (Complete Disassembly)

### Stage 1: Speed Index

```
raw = (car[+0x0C] × 0x00480000) >> 16    // multiply speed by 72 (16.16 FP)
speed_index = clamp(raw >> 16, 0, 0x158)  // clamp to [0, 344]
car[+0x08] = speed_index
```

**Confirms** the empirically known formula: `car[+0x08] = speed × 72 / 65536`,
clamped to [0, 344]. The constant 0x00480000 = 72 × 0x10000.

### Stage 2: Drag Scaling

```
drag_amount = speed_index << 6            // scale up by 64
drag_amount = clamp(drag_amount, 0, ?)    // multi-stage clamp:
    if drag_amount < 0: drag_amount = 0
    if drag_amount > 0x2AAA: drag_amount = 0x2AAA (10922)
    if drag_amount > 0x0AAA: drag_amount = 0x0AAA (2730)
```

Three-stage clamp: floor at 0, cap at 10922, then tighter cap at 2730.
The tighter cap (0x0AAA) is the effective maximum in normal driving.

### Stage 3: Apply Drag

```
car[+0x48] -= drag_amount                 // subtract from drag accumulator
if car[+0xC0] != 0:                       // alternate path
    drag_amount = constant_from_pool      // use fixed drag instead
car[+0x50] -= drag_amount                 // subtract from second accumulator
```

The +0xC0 field gates an alternate drag constant for car[+0x50]. When +0xC0
is zero (normal driving from standstill), both +0x48 and +0x50 use the same
speed-proportional drag. When +0xC0 is nonzero (active driving with force),
+0x50 uses a different constant.

## Per-Frame Verification

From CSV captures:

| Field | Throttle f0 | Throttle f150 | Throttle f299 | Idle | Category |
|-------|-------------|---------------|---------------|------|----------|
| +0x08 | 0 | 0x2C (44) | 0x2F (47) | 0 | input-responsive |
| +0x48 | -2733006 | -2868948 | -2951628 | -2733006 | input-responsive |
| +0x50 | -2814926 | -3339070 | -3798290 | -2814926 | input-responsive |

+0x48 and +0x50 decrease steadily with throttle (drag accumulates as speed
increases). They remain constant when idle (speed=0, drag_amount=0, no change).

The drag accumulators start at large negative values from the save state's
initial conditions. Each frame, speed_index × 64 is subtracted, making them
more negative. These values likely feed into downstream force calculations
that produce aerodynamic or rolling resistance.

## Other Observations

- The speed index upper clamp (344 = 0x158) corresponds to a speed of about
  344 × 65536 / 72 ≈ 313,000 internal units ≈ 213 mph. This is well above
  any achievable speed in normal gameplay, so the clamp likely never triggers.
- The drag scaling uses shift-left-8 then shift-right-2, which is effectively
  multiply by 64. At max speed index (344), drag_amount = 344 × 64 = 22016,
  but clamped to 2730 (0x0AAA). So drag saturates at moderate speeds.
- car[+0xC0] (the gate flag) has 91 unique values with throttle, suggesting
  it's continuously varying, not boolean. Its value determines which drag
  constant applies to +0x50.
