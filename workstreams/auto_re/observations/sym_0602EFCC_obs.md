---
function: sym_0602EFCC
address: 0x0602EFCC
address_end: ~0x0602EFDA
source_file: reimpl/src/FUN_0602EEB8.s (line 158+)
explored: 2026-03-15
scenarios_tested: [straight_throttle]
reachable: true
---

## Call Frequency

| Scenario | Calls/Frame | Notes |
|----------|-------------|-------|
| straight_throttle | 1 | Pipeline call 12 in FUN_0602EEB8 (inline in same source file) |

## Computation (Complete — ~12 instructions + sub-call)

Sin/cos computation of roll angle, stored as force projection components.

```
r4 = car[+0x24]              // roll angle (mov.l @(36, r0), r4)
r5 = car_base + 0x100        // address of car[+0x100]
r6 = car_base + 0x104        // address of car[+0x104]
r14 = car_base               // save car pointer
r12 = FUN_06027358            // sin/cos pair function

// FUN_06027358 computes sin(r4) → car[+0x100], cos(r4) → car[+0x104]
// R5 and R6 are output pointers passed to the function
```

Then calls FUN_0602EFDA which wraps another call via `jsr @r12` (to
FUN_06027358, the sin/cos computation function).

## Field Access

### Reads

| Offset | Notes |
|--------|-------|
| +0x24 | Roll angle. Input to sin/cos computation |

### Writes

| Offset | Notes |
|--------|-------|
| +0x100 | sin(car[+0x24]) — roll projection (written by FUN_06027358 via R5 pointer) |
| +0x104 | cos(car[+0x24]) — roll projection (written via R6 pointer) |

## CONFIRMED by Breakpoint (Cycle 3)

Breakpoint at FUN_06027358 write address (0x06027370) confirmed:
- R5 = 0x06078A00 (car[+0x100] address)
- PR = 0x0602EFE0 (return to sym_0602EFCC body)
- Called from within the rotation/animation pipeline stage

## Per-Frame Field Analysis

| Offset | Idle | Throttle | Category |
|--------|------|----------|----------|
| +0x100 | constant 0 | constant 0 | static (flat track, roll=0) |
| +0x104 | constant 65536 | constant 65536 | static (cos(0) = 1.0 in 16.16 FP) |
| +0x24 | constant 0 | constant 0 | static (flat track, no roll) |

On flat Three Seven Speedway: roll angle = 0, sin(0) = 0, cos(0) = 65536
(1.0 in 16.16 fixed-point). These fields would only vary on banked track
sections with non-zero roll.

## Struct Map Correction (from Cycle 3)

car[+0x100] was labeled "throttle_input?" in the struct map. **CORRECTED**:
it is sin(roll_angle), not throttle input. car[+0x104] is cos(roll_angle).
Both are force projection components used by FUN_0602CA84 (call 15) to
decompose forces relative to the track surface normal.
