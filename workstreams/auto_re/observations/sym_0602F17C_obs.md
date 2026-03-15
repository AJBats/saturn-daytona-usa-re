---
function: sym_0602F17C
address: 0x0602F17C
address_end: ~0x0602F224
source_file: reimpl/src/FUN_0602EFF0.s (line 278+)
explored: 2026-03-15
scenarios_tested: [straight_throttle]
reachable: true
---

## Call Frequency

| Scenario | Calls/Frame | Notes |
|----------|-------------|-------|
| straight_throttle | 1 | Pipeline call 7a (conditional: car[+0x9C] == 0) |

## Computation

Gear/section state machine with hysteresis thresholds.

### Stage 1: Transition Decay

```
d8 = car[+0xD8]           // transition direction flag
if d8 > 0: d8 = d8 - 1    // decay toward 0 (was +5 on section-up)
if d8 < 0: d8 = d8 + 1    // decay toward 0 (was -5 on section-down)
car[+0xD8] = d8
```

### Stage 2: Threshold Comparison

```
section = car[+0xDC]       // 16-bit section index
force = car[+0xE0]         // gear-scaled speed (from sym_0602D814)
speed_idx = car[+0x08]     // speed index

if speed_idx > 0:          // only check upper threshold when moving
    upper = sym_060477AC[section]  // upper threshold table
    if force > upper:
        → TRANSITION UP
        car[+0xD8] = 5
        car[+0xDC] += 1
        car[+0xE0] = speed × sym_060477CC[section] >> 16
        goto FUN_0602F224

lower = sym_0604779C[section]      // lower threshold table
if force < lower:
    → TRANSITION DOWN (separate code at .L_0602F1F8)

// else: no transition, goto FUN_0602F224
```

### Field Access

| Offset | R/W | Notes |
|--------|-----|-------|
| +0xD8 | RW | Transition direction flag. Set to ±5 on transition, decays to 0 |
| +0xDC | RW | Section index (16-bit). Incremented/decremented on transition |
| +0xE0 | RW | Gear-scaled speed. Recomputed on transition using new section |
| +0x08 | R | Speed index. Gates the upper threshold check |

### Threshold Tables

| Table | Address | Role |
|-------|---------|------|
| sym_060477AC | Upper threshold | Section advance trigger (force > table[section]) |
| sym_0604779C | Lower threshold | Section retreat trigger (force < table[section]) |
| sym_060477CC | Section scaling | Speed recomputation on section change |

The dual-threshold design provides hysteresis: the force must exceed the upper
threshold to advance, but only needs to drop below the lower threshold to
retreat. This prevents rapid oscillation at threshold boundaries.

## Relationship to Speed Pipeline

```
sym_0602D814 (call 18)
    → car[+0xE0] = clamp(speed × gear_ratio[+0xDC], 0, 8500)
                                        ↑
sym_0602F17C (call 7a)                  |
    → reads car[+0xE0]                  |
    → if threshold crossed: update car[+0xDC] (section index)
    → sym_0602D814 uses car[+0xDC] to select gear_ratio
```

The section index (+0xDC) selects the gear ratio used by the speed writer.
When speed pushes +0xE0 past a threshold, the section advances, changing
the gear ratio for subsequent frames. This is the game's gear shift mechanism.

## Other Observations

- +0xD8 values 0-8 (from struct map) correspond to: 0=neutral, +5=just shifted
  up, -5=just shifted down, with intermediate values during decay.
- The function is called TWICE per frame in the dispatcher (calls 7a and 8).
  Call 7a runs conditionally (car[+0x9C] == 0), call 8 runs unconditionally.
  The unconditional call ensures the transition decay always runs.
- In the straight_throttle scenario from standstill, +0xD8 stays at 0 and
  +0xDC stays at 0 throughout — the car never reaches enough speed to trigger
  a section transition in 300 frames.
