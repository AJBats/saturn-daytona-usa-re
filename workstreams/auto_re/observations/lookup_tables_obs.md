---
function: N/A (lookup table extraction)
address: N/A
explored: 2026-03-15
scenarios_tested: [usa_tt_straight state loaded]
reachable: N/A
---

## Lookup Table Dumps (Phase 3 Readiness)

All tables read from retail binary via `read_memory` at runtime.
Values are 32-bit big-endian unless noted.

### sym_060477BC — Gear Ratio Table

Used by sym_0602D814: `car[+0xE0] = speed × table[car[+0xDC]] × K`

| Index | Hex | Decimal | Notes |
|-------|-----|---------|-------|
| 0 | 0x00093756 | 603990 | Gear 1 ratio |
| 1 | 0x0005A223 | 369187 | Gear 2 ratio |
| 2 | 0x0003E677 | 255607 | Gear 3 ratio |
| 3 | 0x0003122B | 201259 | Gear 4 ratio |
| 4 | 0x00009C7A | 40058 | (low — high gear?) |
| 5 | 0x0000B13D | 45373 | |
| 6 | 0x0000C991 | 51601 | |
| 7 | 0x00000000 | 0 | (unused/terminator) |

Ratios decrease with gear number — higher gears have lower ratios,
meaning lower force-to-speed conversion (higher max speed, lower accel).

### sym_060477AC — Gear-Up Threshold Table

Used by sym_0602F17C: advance section when `car[+0xE0] > table[+0xDC]`

| Index | Hex | Decimal |
|-------|-----|---------|
| 0 | 0x00001CE8 | 7400 |
| 1 | 0x00001CE8 | 7400 |
| 2 | 0x00001CE8 | 7400 |
| 3 | 0x0000C350 | 50000 |

First 3 gears have identical threshold (7400). Gear 4 threshold is much
higher (50000) — harder to shift past gear 4.

### sym_0604779C — Gear-Down Threshold Table

Used by sym_0602F17C: retreat section when `car[+0xE0] < table[+0xDC]`

| Index | Hex | Decimal (signed) |
|-------|-----|---------|
| 0 | 0xFFFFEC78 | -5000 |
| 1 | 0x00000C14 | 3092 |
| 2 | 0x00000F82 | 3970 |
| 3 | 0x00001388 | 5000 |

Gear 0 has negative threshold (-5000) — can't downshift below gear 1.
Hysteresis gap: gear 1 up=7400, down=3092 (gap of 4308).

### sym_060477CC — Section Scaling Table

Used by sym_0602F17C on gear shift: recomputes +0xE0 with new section.

| Index | Hex | Decimal |
|-------|-----|---------|
| 0 | 0x00009C7A | 40058 |
| 1 | 0x0000B13D | 45373 |
| 2 | 0x0000C991 | 51601 |
| 3 | 0x00000000 | 0 |

Same values as gear ratio table entries 4-7.

### sym_060477D8 — Animation State Table

Used by sym_0602F474: `car[+0x114] = table[counter_state]`

| Index | Hex | Decimal |
|-------|-----|---------|
| 0 | 0x00000000 | 0 |
| 1 | 0x01900000 | 26214400 |
| 2 | 0x0C800000 | 209715200 |
| 3 | 0x12C00000 | 314572800 |
| 4 | 0x19000000 | 419430400 |

Large values — likely 16.16 fixed-point scaling factors for animation.

### sym_0602E938 — Force Constants (Gear × Section)

Used by FUN_0602CCEC: traction force constants indexed by gear and section.
128 bytes dumped — appears to be 8×2 entries of 8 bytes each.

```
0602E938: 8D4F68F5 5000527A  // entry 0
0602E940: 8D4F68F5 5000527A  // entry 1 (same as 0)
0602E948: FD4FC8F5 81EB8500  // entry 2
0602E950: FD4FC8F5 81EB8500  // entry 3 (same as 2)
0602E958: ED4FD8F5 9000717A  // entry 4
0602E960: ED4FD8F5 9000717A  // entry 5 (same as 4)
0602E968: CD4F98F5 81EB847A  // entry 6
0602E970: CD4F98F5 81EB847A  // entry 7 (same as 6)
0602E978: 8D4F68F5 51EB547A  // entry 8
0602E980: 8D4F68F5 51EB547A  // entry 9 (same as 8)
0602E988: CD4FC8F5 A1EB847A  // entry 10
0602E990: CD4FC8F5 A1EB847A  // entry 11 (same as 10)
0602E998: 8D4F68F5 5000517A  // entry 12
0602E9A0: 8D4F68F5 5000517A  // entry 13 (same as 12)
0602E9A8: 00000000 00000018  // entry 14 (near-zero)
0602E9B0: 00000000 00000000  // entry 15 (zero)
```

Entries are paired (each repeated once). 8 unique entries for 4 gears × 2.

### sym_0602F3CC — Track Force Bounds

Used by FUN_0602F270 for track force clamping.

| Index | Hex (signed) | Decimal |
|-------|-------------|---------|
| 0 | 0xFFFFFB50 | -1200 |
| 1 | 0x000004B0 | 1200 |
| 2 | 0xFFFFFDA8 | -600 |
| 3 | 0x00000258 | 600 |
| 4 | 0xFFFFFED4 | -300 |
| 5 | 0x0000012C | 300 |
| 6 | 0xFFFFFED4 | -300 |
| 7 | 0x0000012C | 300 |

Symmetric bounds: ±1200, ±600, ±300, ±300. Force limits decrease with
higher gear/section — tighter force clamping at high speeds.

### sym_0602E8B8 — Drift Scaling Table

Used by sym_0602D8BC: `table[car[+0x250]]` for drift-path velocity scaling.

| Index | Hex | Decimal | 16.16 FP |
|-------|-----|---------|----------|
| 0-6 | 0x00010000 | 65536 | 1.000 |
| 7 | 0x0000E666 | 58982 | 0.900 |
| 8 | 0x0000CCCC | 52428 | 0.800 |
| 9 | 0x0000B333 | 45875 | 0.700 |
| 10-15 | 0x00010000 | 65536 | 1.000 |

Drift counter values 7-9 scale velocity to 90%, 80%, 70%. All other
values (0-6, 10+) are 1.0 (no scaling). The drift ramp: counter starts
at 10 (0xA), counts down. At 9→7, velocity progressively reduces.
Below 7, back to full speed.
