---
function: FUN_0602CCEC
address: 0x0602CCEC
address_end: 0x0602CDF4
source_file: reimpl/src/FUN_0602CCEC.s
explored: 2026-03-15
scenarios_tested: [straight_throttle, idle]
reachable: true
---

## Call Frequency

| Scenario | Calls/Frame | Notes |
|----------|-------------|-------|
| straight_throttle | 1 | Called by BSR from FUN_0602CA84 (line 280-281) |
| idle | 1 | Same |

## Register Context at Entry

Called from FUN_0602CA84 via `bsr FUN_0602CCEC`. Inherits:
- R0 = car pointer (0x06078900)
- R14 = car pointer (preserved)

## Field Access (from Static Analysis)

### Reads

| Offset | Notes |
|--------|-------|
| +0x08 | Speed index. `mov.l @(8, r14), r3` — gates the entire computation (r3 > 0 required) |
| +0xE0 | Track force output. Read twice. Used to compute +0x110 |
| +0x11C | Surface energy. Multiplied with FUN_0602755C result |
| +0x10C | Previous clamped force Z |
| +0x144 | World coordinate. Multiplied with +0x10C |
| +0xDC | Section index (16-bit). Used for lookup table |
| +0x7C | Gear state (16-bit). Selects lookup table entry |
| +0x110 | Previous frame's force term. Read for delta computation |
| +0x16C | Counter (16-bit). Checked, gates a code path |

### Writes

| Offset | Notes |
|--------|-------|
| +0x264 | Computed via FUN_0602755C from speed/force inputs |
| +0x110 | Force term. Derived from +0xE0 via clamp (line 97) AND updated in final block (line 150) |
| +0x10C | Updated clamped force Z (line 152) |
| +0xC0 | Written in RTS delay slot (line 156): r7 value at exit |

### Computation Flow

1. Gate: if car[+0x08] (speed index) <= 0, skip to final block at .L_0602CD9A
2. Compute: `r4 = 0x21340000 - car[+0xE0] << 16`. This is a force deficit
   relative to a max value (0x2134 = 8500).
3. Multiply by car[+0x11C] (surface energy) via FUN_0602755C (clamp)
4. Cross-multiply with car[+0x10C] × car[+0x144]
5. Lookup table at sym_0602E938 indexed by car[+0x7C] (gear) and car[+0xDC] (section)
6. Write car[+0x264] with clamped result
7. Call FUN_0602D7E4 (damping/clamp) if threshold exceeded
8. If car[+0x16C] <= 0: compute car[+0x110] from car[+0xE0] × constant 0x23280000
   via FUN_0602755C

### Final block (.L_0602CD9A — always runs):
9. r3 = car[+0x10C] - car[+0x110]. Clamp between 0 and 0x10000.
10. If car[+0x110] > 0: car[+0x110] -= 0x05C2 (1474 decimal, linear decay)
11. Write car[+0x10C] = clamped r3
12. Write car[+0xC0] = r7 (in RTS delay slot)

## Key Finding: Feedback Loop Through +0xE0

car[+0x110] is derived from car[+0xE0] (track force/gear output).
car[+0xE0] is written by sym_0602D814 (speed writer, pipeline call 18)
as clamped speed via gear lookup. This creates a frame-over-frame
feedback loop:

```
car[+0xE0] (prev frame, from speed writer via gear lookup)
    ↓ FUN_0602CCEC
car[+0x110] (force term, with linear decay of 1474/frame)
    ↓ FUN_0602CA84 (force accumulator)
car[+0xFC] (accel delta)
    ↓ sym_0602D814 (speed writer)
car[+0x0C] (speed) → car[+0xE0] (updated for next frame)
```

The linear decay of +0x110 (subtract 1474 each frame when positive)
means the force term naturally decreases over time. This produces the
speed convergence behavior: as the car approaches its gear-limited max
speed, +0xE0 approaches the 0x2134 threshold, the force deficit shrinks,
and +0x110 decreases, reducing the accel delta toward zero.

## Other Observations

- The gate on car[+0x08] (speed index > 0) means this entire computation
  is SKIPPED when the car is at 0 speed. This explains why +0x110 stays
  constant at idle — the function returns immediately without modifying it.
- The lookup table at sym_0602E938 selects different force constants based
  on gear state (+0x7C) and track section (+0xDC). This is the gear ratio
  effect on acceleration.
- FUN_0602D7E4 (damping/clamp) is called when a force threshold is exceeded,
  providing a safety limit on force magnitude.
