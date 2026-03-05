# Car Object Struct Field Map

Base: `0x06078900` (sym_06078900)
Stride: `0x268` (616 bytes per car)
Count: 40 entries (index 0 = player)
Current car pointer: `sym_0607E940` (updated by FUN_0600e0c0 each iteration)
Car count: `sym_0607EA98`

## Key Globals

| Address | Name | Usage |
|---------|------|-------|
| 0x0607E940 | sym_0607E940 | Current car pointer (set to base + i*0x268) |
| 0x0607E944 | sym_0607E944 | Secondary car pointer (used in collision for other car) |
| 0x0607EA98 | sym_0607EA98 | Car count (loop upper bound) |
| 0x0607EA9C | sym_0607EA9C | Track segment count / global scale (used in integration + wrap check) |
| 0x0607EAD8 | sym_0607EAD8 | AI mode flag (non-zero = skip AI physics) |
| 0x0607EAE0 | sym_0607EAE0 | Race mode flag (non-zero = skip car iteration) |
| 0x0607EB84 | sym_0607EB84 | Track segment table base pointer |
| 0x0607EB88 | sym_0607EB88 | Track surface data table base pointer |
| 0x0607EBC4 | sym_0607EBC4 | GLOBAL mode flags — NOT per-car (bit 15 = AI/player pipeline selector for car iteration loop) |
| 0x0607EBD0 | sym_0607EBD0 | Track progress / global timer |
| 0x0607EBDC | sym_0607EBDC | Collision cooldown counter |
| 0x0607EBE0 | sym_0607EBE0 | Gear shift target car pointer |
| 0x06078680 | sym_06078680 | Track/surface data buffer (14+ bytes, written by CA96/CC38) |
| 0x06087804 | sym_06087804 | Game mode short (2=special, 3=special) |

## Field Map (sorted by offset)

All offsets relative to car struct base. All status = THEORY (static analysis only).
Pool constants resolved from ASM `.2byte` values — offsets are exact.

| Offset | Size | Used By | Observations |
|--------|------|---------|-------------|
| +0x00 | 4 | C5D6, 8640 | Flags word. `& 0x00E00000` → airborne path. `& 0x00C00000` in CF58. `& 0x08` in 8640. `& 0x10`/`& 0x20` in 8318 (pad buttons UP/DOWN) |
| +0x01 | 1 | E0C0 | Flags byte (overlaps +0x00 word). `& 0x80` → extra post-physics processing |
| +0x04 | 4 | CF58 | Collision target ID? Non-zero = active collision. Checked and returned |
| +0x08 | 4 | C4F8, E906, C7D4 | Speed index. Written: `fpmul(+0x0C, 0x480000)`. Used as index into tables (<<2). Speed brackets checked in C7D4: 0x118, 0xFA, 0xDC |
| +0x0C | 4 | C4F8, C5D6, C7D4, C928, E906 | Speed magnitude. Updated by C4F8: `+= accel`. Multiplied with sin/cos for velocity components. Zeroed in E906 when AI disabled |
| +0x10 | 4 | C5D6, C7D4, C8CC, CD40 | X position/velocity. Updated: `+= fpmul(speed, sin)`. Used in atan2 with +0x18. Saved to +0x38 |
| +0x14 | 4 | C5D6 | Y position/velocity. Set to 0 in ground path |
| +0x18 | 4 | C5D6, C7D4, C8CC, CD40 | Z position/velocity. Updated: `+= fpmul(speed, cos)`. Used in atan2 with +0x10. Saved to +0x3C |
| +0x1C | 4 | C7D4 | Pitch angle? Averaged: `(track_pitch + car_pitch) >> 1` |
| +0x20 | 4 | C5D6, C7D4, E906 | Heading angle. Ground: set from track. Airborne: damped toward slip angle. Copied to +0x30 by AI |
| +0x24 | 4 | C7D4 | Roll angle? Averaged: `(track_roll + car_roll) >> 1` |
| +0x28 | 4 | C5D6, C7D4, C8CC | Lateral/slip angle. Negated for sincos. C8CC: steered toward track atan2 angle with clamping (max step ±0x600) |
| +0x30 | 4 | C7D4, E906 | Heading delta/history. C7D4: `heading - prev_heading - track_param`. AI: copies +0x20 |
| +0x38 | 4 | C7D4 | Previous X velocity (saved from +0x10 before airborne update) |
| +0x3C | 4 | C7D4 | Previous Z velocity (saved from +0x18 before airborne update) |
| +0x48 | 4 | C928 | Angular velocity? Decremented by speed-based value. Copied to +0x50 |
| +0x50 | 4 | C928 | Copy of +0x48 |
| +0xB8 | 4 | 8318, C5D6 | Gear change countdown. Set to 0x20 on gear shift. Decremented each frame. If >0, skips collision in C5D6 |
| +0xBC | 4 | C4F8, 8318 | Related flag? C4F8: `< 1` check. 8318: `== 0` check for gear shift permission |
| +0xD4 | 2 | C4F8, 8640 | Timer (short). C4F8: decremented. 8640: set to 0x14 |
| +0xFC | 4 | C4F8 | Acceleration delta. Written by C4F8 (clamped). Added to speed +0x0C |
| +0x0161 | 1 | C5D6 | Byte flag. `& 0x20` controls force-application path |
| +0x0184 | 4 | CD40, CEBA | Track surface lookup index? Written by CD40 from table[+0x16]. Read by CEBA |
| +0x018C | 4 | C5D6, C7D4 | Sin component buffer. Written by sincos_pair. Used in fpmul with speed |
| +0x0190 | 4 | C5D6, C7D4 | Cos component buffer. Written by sincos_pair. Used in fpmul with speed |
| +0x0194 | 4 | C4F8, C5D6 | C4F8: compared with speed (+0x0C). C5D6: written = fpmul(track, +0x198) |
| +0x0198 | 4 | C4F8, C5D6 | Multiplied with track heading in C5D6. Used as acceleration coefficient in C4F8 |
| +0x01B0 | 4 | C7D4 | Heading save. Written: `= car[+0x20]` before heading update |
| +0x01BC | 4 | C5D6, 8640 | Collision/bounce state. If >0: C5D6 skips collision. 8640 checks for bounce processing |
| +0x01D8 | 4 | 8318 | Gear effect value. Written from table[0x060453CC + gear_timer]. Sign depends on shift direction |
| +0x01DC | 4 | 8318 | Gear shift direction. 1 = shift up, -1 = shift down |
| +0x01E0 | 4 | E71A, CD40 | Track segment table pointer. Base for 24-byte entries |
| +0x01E4 | 4 | E71A, CD40 | Track segment index. Multiplied by 0x18. Incremented by CD40 when advancing past segment. Wraps at sym_0607EA9C |
| +0x01EC | 4 | E71A, CEBA, CA96 | Track position / surface parameter. CA96 uses as table lookup base. Integration: addend |
| +0x01F0 | 4 | CEBA | Heading-related. Compared with previous value for segment advance detection |
| +0x01F4 | 4 | E71A | Integration result: `car[+0x228] * scale + car[+0x1EC]` |
| +0x01F8 | 4 | E71A, CA96, CF58 | Track value from table lookup. CA96: delta with +0x1FC used for surface interpolation. CF58: written 0x300/0x400 |
| +0x01FC | 4 | CA96, CF58 | Surface interpolation parameter. Updated by ±4 (CA96) or ±8 (CC38). CF58: written 0x80 |
| +0x0204 | 4 | E71A, C5D6, CF58 | Timer. E71A: reset to 0x400. C5D6: compared < 0x66, decremented by 2. CF58: written 0x80 |
| +0x0208 | 4 | E71A, C5D6 | Countdown. E71A: decremented by 1, triggers table lookup at 0. C5D6: `< 1` check |
| +0x0210 | 4 | CF58 | Collision type? Compared == 1 or == 2 for different collision responses |
| +0x021C | 4 | CEBA | Written same value as +0x228 on segment advance |
| +0x0220 | 4 | CEBA | Written: `sym_0607EBD0 - car[+0x22C]` on segment advance |
| +0x0224 | 4 | CF58 | Collision sub-counter? Compared < 10 |
| +0x0228 | 4 | E71A, CEBA | Velocity/rate for integration. Incremented by CEBA on segment advance |
| +0x022C | 4 | CEBA | Written: `= sym_0607EBD0` on segment advance. Previous progress value |

## Physics Path Logic (from FUN_0600c5d6)

```
if flags[+0x00] & 0x00E00000 == 0:
    GROUND PATH:
    - heading[+0x20] = track_data[+0x0E]
    - sincos(-car[+0x28]) → sin[+0x18C], cos[+0x190]
    - vel_x[+0x10] += fpmul(speed[+0x0C], sin[+0x18C])
    - vel_z[+0x18] += fpmul(speed[+0x0C], cos[+0x190])
    - vel_y[+0x14] = 0
else:
    AIRBORNE PATH:
    - FUN_0600c928(car)
    - FUN_0600c7d4(car, track_data)
    - angle = atan2(vel_x[+0x10], vel_z[+0x18])
    - FUN_06027ede(angle, &vel_x[+0x10], stack_buf)
```

## Velocity Integration (FUN_0600e71a)

```
car[+0x1F4] = car[+0x228] * sym_0607EA9C + car[+0x1EC]
```

## Gear Shift (FUN_06008318)

```
if car[+0xB8] == 0 AND sym_0607EBD0 > 0x258 AND car[+0xBC] == 0:
    if pad UP:   car[+0xB8]=0x20, car[+0x1DC]=-1, car[+0xD4]=0x28
    if pad DOWN: car[+0xB8]=0x20, car[+0x1DC]=+1, car[+0xD4]=0x28
else if car[+0xB8] > 0:
    car[+0xB8]--
    car[+0x1D8] = ±table[0x060453CC + car[+0xB8]*2]
```

## Track Segment Advance (FUN_0600ceba)

```
On heading change > threshold:
    car[+0x228]++
    car[+0x21C] = car[+0x228]
    car[+0x220] = sym_0607EBD0 - car[+0x22C]
    car[+0x22C] = sym_0607EBD0
```

## Speed Calculation (FUN_0600c4f8)

```
if not AI:
    acceleration = clamped(table_diff * scale, -4014, max)
    car[+0x0C] += acceleration  (floor at 0)
    car[+0x08] = fpmul(car[+0x0C], 0x480000)
```

## Empirical Observations (2026-03-05)

### g_pad_state read-consume-clear pattern

`sym_06063D98` (g_pad_state) IS the pad state during racing — CONFIRMED with breakpoint
at FUN_06008318 mid-frame. A held = 0x0400 at +2, matching known button mapping.

**Critical**: The game CLEARS g_pad_state before frame end. Reading between frames always
returns zero. Must use breakpoints to read transient per-frame state. Persistent car struct
fields (speed, position, heading) are safe to read between frames.

### Save state + input injection verified

Save state `daytona_rebuilt.*.mc0` loads to race start (lap 1/8, pos 40/40, ~179 mph).
Input injection works immediately after load:
- LEFT held 60 frames: car steered onto grass, speed dropped to 6 mph
- A held 30 frames: speed barely dropped (262K → 258K vs idle 262K → 86K)

### Player car = index 0 (CONFIRMED)

Car 0 (base 0x06078900) IS the player car. Confirmed by:
1. Speed field +0x0C correlates perfectly with HUD speedometer (ratio ~1,467 stable)
2. Watchpoint on 0x0607890C: written by FUN_0602D814 (pc=0x0602D822), NOT the main
   physics loop. Player is processed separately from the AI car iteration loop.

The FUN_0600e0c0 loop (i=1..car_count) processes AI cars only. Player car 0 is
handled by a separate code path rooted at ~0x0602EF00.

### C button = throttle (CONFIRMED)

Watchpoint on car[+0xFC] (acceleration delta) at 0x060789FC:

| Frame delta | C held | Idle |
|-------------|--------|------|
| +3 | -468 → -394 (+74) | -468 → -469 (-1) |
| +6 | -394 → -325 (+69) | -469 → -474 (-5) |
| +9 | -325 → -256 (+69) | -474 → -481 (-7) |

C shifts the accel delta toward zero/positive by ~70 units/update. Without C, it drifts
more negative (engine braking). At rolling start speed (~179 mph) the car still
decelerates with C held because it's above the natural max speed for that throttle level.
Writer PC: 0x0602EF4E (in the player-specific physics path, not FUN_0600c4f8).

### Speed unit conversion (CONFIRMED)

Internal speed (+0x0C) → kph-ish (+0x08) → mph (HUD):
- `car[+0x08] = fpmul(car[+0x0C], 0x480000)` — 16.16 fixed-point multiply by 72
- HUD mph = car[+0x0C] / 1,467 (stable across 3 data points)
- 262,577 / 1,467 = 179 mph, 258,164 / 1,467 = 176 mph, 253,749 / 1,467 = 173 mph

### Initial car struct dump at race start

```
+0x00: 00 80 00 00  — flags: 0x00800000 (bit 23 set)
+0x04: 00 00 00 00  — collision target: none
+0x08: 00 00 01 20  — speed index: 0x120 (288)
+0x0C: 00 04 01 B1  — speed: 0x401B1 (262,577)
+0x10: FF DC EB C7  — vel X: -2,298,937
+0x14: 00 00 00 00  — vel Y: 0 (on ground)
+0x18: FF 7A A9 16  — vel Z: -8,738,538
+0x1C: 00 00 00 00  — pitch: 0
+0x20: FF FF AA AB  — heading: -21,845 (0xFFFFAAAB)
+0x24: 00 00 00 00  — roll: 0
+0x28: FF FF AA AB  — slip angle: -21,845 (= heading, no slip)
+0x30: FF FF AA AB  — heading delta: same as heading
+0x38: FF D9 73 40  — prev vel X
+0x3C: FF 7C A9 77  — prev vel Z
+0x78: 00 00 00 38  — (unknown)
+0x7C: 00 00 07 05  — (unknown)
+0xB8: 00 00 00 00  — gear timer: 0 (ready to shift)
+0x1E4: 00 00 00 05  — track segment index: 5
+0x228: 00 00 00 00  — segment velocity: 0
```

## Method

1. [DONE] Resolve ALL pool constants from ASM → concrete struct offsets (45 fields mapped)
2. [DONE] Cross-reference ALL 13 core physics functions
3. [DONE] Hexdump car struct at race start — initial values recorded
4. [DONE] Verify input injection + speed field behavior
5. [NEXT] Breakpoint-based field verification for remaining physics functions
