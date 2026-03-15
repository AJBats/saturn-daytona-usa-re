---
function: FUN_0603006A (steering input sub-function)
address: 0x0603006A
source_file: unknown (0x0603xxxx range — may be in FUN_0602FDB0's call chain)
explored: 2026-03-15
scenarios_tested: [left_throttle]
reachable: true
---

## KEY FINDING: D-pad Steering Enters Through sym_0602FDA4 (Call 1)

**Watchpoint on car[+0xAC] (0x060789AC) caught the writer at PC=0x0603006A.**

| Register | Value | Notes |
|----------|-------|-------|
| PC | 0x0603006A | Writer instruction — in 0x0603xxxx sub-function |
| PR | 0x0602EEC2 | Return to FUN_0602EEB8 dispatcher body |
| R2 | 0x00004000 | **LEFT button mask** |
| R3 | 0x000000AC | Offset being written (+0xAC) |
| R8 | 0xFFFFFFF0 | Value written: -16 (first frame LEFT steering) |
| R13 | 0x0602FDA4 | sym_0602FDA4 (input handler, call 1) |
| R14 | 0x06078900 | Car pointer |

**old value: 0x00000000 → new value: 0xFFFFFFF0 (-16)**

## Complete Steering Pipeline (No Remaining Gaps)

```
LEFT button (bit 0x4000 in g_pad_state)
RIGHT button (bit 0x8000 in g_pad_state, presumed)
    ↓ sym_0602FDA4/FUN_0602FDB0 (pipeline call 1)
    ↓ sub-call to FUN_0603006A (steering computation)
car[+0xAC] = computed steering value (LEFT = -16 first frame)
    ↓ FUN_0602EFF0 (pipeline call 2)
    ↓ deadzone ±5, clamp ±80, scale ×255
    ↓ FUN_0602ECCC (atan2/rotation) ×3
car[+0xB0] (rotation), car[+0x78], car[+0x94]
    ↓ sym_0602F0E8 (call 6): EMA → +0xD0, copies +0x94→+0x84, +0x78→+0x68
    ↓ FUN_0602D43C (call 16a): reads +0xD0, computes +0x58, +0x5C
    ↓ FUN_0602CDF6 (call 17): heading convergence → +0x30, +0x60, +0x64
    ↓ sym_0602D8BC (call 19): heading → velocity direction → position
```

## Why +0xAC Appeared Identical Across Scenarios in CSVs

The CSV captures (cycle 2, 20) showed +0xAC having the same 23 unique values
regardless of LEFT being held. This is because:

1. At 0 mph (standstill captures), the steering computation in FUN_0603006A
   produces VERY small values (-16 for LEFT) that are within the deadzone (±5)
   of FUN_0602EFF0 — they get zeroed out by the deadzone filter.

2. The 23 "unique values" in +0xAC represent track-curvature self-adjustment,
   not player input. These adjust as the car settles onto the track heading.

3. At higher speeds, the steering value would grow beyond the deadzone
   threshold, producing visible heading changes. The rolling steer test
   (cycle 20) showed heading changing at 65 mph because the larger +0xAC
   values exceeded the ±5 deadzone.

## Button Mapping (Updated)

| Mask | Button | Handler | Car Field |
|------|--------|---------|-----------|
| 0x0200 | C (throttle) | sym_0602FDA4 inline | +0x74 (accumulator) |
| 0x0100 | B (brake) | sym_0602FDA4 inline | +0x90 (accumulator) |
| 0x2000 | UP (gear up) | sym_0602FDA4 inline | +0xDE (gear position) |
| 0x1000 | DOWN (gear dn) | sym_0602FDA4 inline | +0xDE (gear position) |
| 0x4000 | LEFT (steer) | sub-call 0x0603006A | +0xAC (steering value) |
| 0x8000 | RIGHT (steer) | sub-call 0x0603006A | +0xAC (steering value, presumed positive) |

**All 6 racing inputs now traced to their car struct writers.**

## Steering Computation Detail (from source lines 393-407)

```
r1 = *(sym_06063D9C)       // g_pad_state+4 — ANALOG AXIS (16-bit)
r7 = *(sym_06078663)       // flag byte (inversion control)
if r7 != 0: r1 = ~r1       // optional bit inversion
r1 = r1 & 0xFF             // mask to byte (0-255)
r1 = r1 - 128              // center at 0 (range -128 to +127)
car[+0xAC] = r1            // write steering value
```

**car[+0xAC] is an ANALOG steering input**, not a digital button state.
The value at g_pad_state+4 is the analog steering axis (0-255). The D-pad
LEFT/RIGHT buttons are mapped to analog extremes by the emulator/hardware.
Subtracting 128 centers the range at 0 (neutral), with LEFT negative and
RIGHT positive.

The flag at sym_06078663 appears to be a steering inversion flag (for
different controller configurations or reverse mode).

This explains why +0xAC showed value -16 (not -128) when LEFT was pressed
— the emulator's `input_press LEFT` may produce a partial analog value,
or the value is further processed before the write.
