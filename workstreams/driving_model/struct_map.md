# Car Object Struct Field Map

Base: `0x06078900` (sym_06078900)
Stride: `0x268` (616 bytes per car)
Count: 40 entries (index 0 = player)
Current car pointer: `sym_0607E940` (updated by FUN_0600e0c0 each iteration)
Car count: `sym_0607EA98`

## Key Globals

Addresses are mechanical facts. Usage descriptions are from static analysis (Ghidra)
and require empirical verification unless marked CONFIRMED.

| Address | Name | Static Hypothesis | Writers (globals_writer_map) |
|---------|------|-------------------|-----------------------------|
| 0x0607E940 | sym_0607E940 | Current car pointer (set each iteration) | 5 writers: FUN_0600A918, FUN_0600AFB6, FUN_0600E4F6, FUN_06030A06 + loop |
| 0x0607E944 | sym_0607E944 | Player car pointer? (r0 loaded from here in player physics) | Not in globals_writer_map |
| 0x0607E948 | sym_0607E948 | Car array base (car[1] = 0x06078B68) | 1 writer: FUN_0600E4F6 |
| 0x0607EA98 | sym_0607EA98 | Car count | Not in globals_writer_map |
| 0x0607EA9C | sym_0607EA9C | Unknown | Not in globals_writer_map |
| 0x0607EAAC | sym_0607EAAC | Frame counter? (monotonic +1/frame) | 1 writer: FUN_060092D4 |
| 0x0607EAD8 | sym_0607EAD8 | Unknown | Not in globals_writer_map |
| 0x0607EAE0 | sym_0607EAE0 | Unknown | Not in globals_writer_map |
| 0x0607EB84 | sym_0607EB84 | Track segment table pointer (used by FUN_0600cd40) | Not in globals_writer_map |
| 0x0607EB88 | sym_0607EB88 | Surface property table pointer (used by FUN_0600ca96) | Not in globals_writer_map |
| 0x0607EBC0 | sym_0607EBC0 | Unknown (const 0x11) | 1 writer: FUN_06003000 |
| 0x0607EBC4 | sym_0607EBC4 | Pipeline mode flag: bit 15 selects normal vs AI pipeline | 1 writer: FUN_06003000 (const 0x20000) |
| 0x0607EBC8 | sym_0607EBC8 | Frame counter (different from EAAC?) | 1 writer: FUN_060092D4 |
| 0x0607EBD0 | sym_0607EBD0 | Minimum speed/progress for gear shifting (>0x258) | 1 writer: FUN_060092D4 |
| 0x0607EBDC | sym_0607EBDC | Car iteration index (1..car_count) | 2 writers: FUN_0600C694, FUN_0600D510 |
| 0x0607EBE0 | sym_0607EBE0 | Unknown | Not in globals_writer_map |
| 0x06078680 | sym_06078680 | Track surface buffer (passed to FUN_0600CA96) | Not in globals_writer_map |
| 0x06087804 | sym_06087804 | Unknown | Not in globals_writer_map |

## Empirically Confirmed Fields

Only fields with emulator evidence. Offset labels come from observations, not Ghidra.

| Offset | Evidence | Finding |
|--------|----------|---------|
| +0x0C | Watchpoint + HUD correlation | Speed magnitude. HUD mph = value / 1,467. Written by FUN_0602D814 (pc=0x0602D822) for player car. |
| +0x08 | Observed formula | Speed index: `FUN_06027552(car[+0x0C], 0x480000)` — fixed-point multiply by 72 |
| +0xFC | Watchpoint with C button | Acceleration delta. C button shifts +70/update toward positive. Writer PC: 0x0602EF4E (player path). |

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
- `car[+0x08] = FUN_06027552(car[+0x0C], 0x480000)` — 16.16 fixed-point multiply by 72
- HUD mph = car[+0x0C] / 1,467 (stable across 3 data points)
- 262,577 / 1,467 = 179 mph, 258,164 / 1,467 = 176 mph, 253,749 / 1,467 = 173 mph

### Initial car struct dump at race start

```
+0x00: 00 80 00 00
+0x04: 00 00 00 00
+0x08: 00 00 01 20
+0x0C: 00 04 01 B1  — speed: 262,577 (CONFIRMED via HUD)
+0x10: FF DC EB C7
+0x14: 00 00 00 00
+0x18: FF 7A A9 16
+0x1C: 00 00 00 00
+0x20: FF FF AA AB
+0x24: 00 00 00 00
+0x28: FF FF AA AB
+0x30: FF FF AA AB
+0x38: FF D9 73 40
+0x3C: FF 7C A9 77
+0x78: 00 00 00 38
+0x7C: 00 00 07 05
+0xB8: 00 00 00 00
+0x1E4: 00 00 00 05
+0x228: 00 00 00 00
```

---

## Field Synthesis — All 95 Known Offsets

Cross-reference of writer maps, consumer map, static hypotheses, and initial dump.
Status key: **CONFIRMED** = emulator evidence, **proposed?** = strong cross-evidence,
no label = insufficient evidence.

Sources: W=writer_map_comprehensive, C=consumer_map, S=static_hypotheses, D=initial_dump.

### Core Kinematic State

#### +0x00 — flags/status?
- **Init**: 0x00800000
- **Writers**: 4 PCs. FUN_0602EF4C writes 0x800000 (493x). FUN_06034F7C writes 0x0/0x80/0x100/0x800000/0x800080 (4442x, 6 unique). FUN_06030B2E writes 0x800080 (4x). FUN_06031632 writes 0x800100 (1x).
- **Consumers**: FUN_0600E0C0 reads +0x01 (car flags byte for loop skip). FUN_0600B6A0/B914 read +0x01 (rendering skip). FUN_0600C5D6 checks flags & 0x00E00000 for ground vs airborne.
- **Hypothesis**: Status/mode flags. Byte +0x01 is per-car active flag. Bits in the upper word may encode ground/airborne/collision state.

#### +0x04 — collision/state flags?
- **Init**: 0x00000000
- **Writers**: Not in car[0] writer map (no collision during capture).
- **Consumers**: 10 functions read +0x04. FUN_0600CA96, FUN_0600CC38, FUN_0600CD40, FUN_0600CE66, FUN_0600CEBA, FUN_0600CF58, FUN_0600C74E all read it. FUN_0600CF58 (collision dispatch) checks it for collision target.
- **Hypothesis**: Collision/interaction target pointer or flags. Read by every major pipeline function. Written during collision events.

#### +0x08 — speed_index (CONFIRMED)
- **Init**: 0x00000120 (288)
- **Writers**: FUN_0602F3F0 (pc=0x0602F41E, 493x, 198 unique). Also FUN_0600C4F8 (AI path).
- **Consumers**: FUN_0600A8BC, FUN_0600C4F8, FUN_0600CF58 read it.
- **Confirmed**: `FUN_06027552(car[+0x0C], 0x480000)` — fixed-point multiply speed by 72.

#### +0x0C — speed (CONFIRMED)
- **Init**: 0x000401B1 (262,577 = ~179 mph)
- **Writers**: Player: FUN_0602D818 (pc=0x0602D822, 493x). Also 0x0602D82A (20x, writes 0), 0x0602D986 (18x), 0x06030ECE (6x), 0x0603154A (5x). AI: FUN_0600C4F8.
- **Consumers**: 6 READ, 5 WRITE. Most-read field after position. FUN_0600A8BC (HUD), FUN_0600B6A0/B914 (rendering? — actually these don't read +0x0C directly), FUN_0600C4F8 (speed update), FUN_0600C5D6, FUN_0600E7C8, FUN_0600E906.
- **Confirmed**: Speed magnitude. HUD mph = value / 1,467.

#### +0x10 — position_x?
- **Init**: 0xFFDCEBC7 (-2,364,473 signed)
- **Writers**: FUN_0602D8CA (pc=0x0602D902, 475x, 455 unique). Also FUN_0602D9BC (18x), FUN_06030E88 (6x), FUN_0603166A (6x) — collision/special paths.
- **Consumers**: 15 READ (highest of any field). FUN_0600553C, FUN_060061C8, FUN_0600B6A0/B914 (rendering), FUN_0600C5D6, FUN_0600D12C, FUN_0600DCC8/DD88, FUN_0600E1D4, FUN_0601FEC0, FUN_0603053C.
- **Hypothesis**: World X position. Large signed value, 455 unique values in 475 writes = changes nearly every frame. Read by rendering + physics + collision.

#### +0x14 — position_y?
- **Init**: 0x00000000
- **Writers**: FUN_06005ED0 (pc=0x060060B2, 493x, 106 unique).
- **Consumers**: 6 READ. FUN_0600553C, FUN_060061C8, FUN_0600B6A0/B914, FUN_0600E71A.
- **Hypothesis**: World Y position (height). Zero at race start (flat track). Only 106 unique values = less variation than X/Z. Different writer function from X/Z.

#### +0x18 — position_z?
- **Init**: 0xFF7AA916 (-8,738,538 signed)
- **Writers**: FUN_0602D8CA (pc=0x0602D912, 475x, 375 unique). Also FUN_0602D9CC (18x), FUN_06030E94 (6x), FUN_06031676 (6x).
- **Consumers**: 14 READ (tied with +0x28 for 2nd highest). Same consumers as +0x10 plus FUN_0600CD40, FUN_0600CDD0.
- **Hypothesis**: World Z position. Same writer function as +0x10, same write count pattern. Large signed value.

#### +0x1C — pitch_angle?
- **Init**: 0x00000000
- **Writers**: FUN_0600611A (pc=0x06006188, 493x, 54 unique).
- **Consumers**: 3 READ. FUN_0600B6A0/B914 (rendering), FUN_06008730.
- **Hypothesis**: Pitch angle (rotation about lateral axis). Zero at race start on flat ground. Only 54 unique values. Static hypothesis: FUN_0600c7d4 writes car[+0x1C] averaged with track pitch (airborne path).

#### +0x20 — heading?
- **Init**: 0xFFFFAAAB (-21,845 signed)
- **Writers**: FUN_0602D8CA (pc=0x0602D8CE, 475x, 361 unique). Also FUN_0602D964 (18x).
- **Consumers**: 8 READ. FUN_0600B6A0/B914, FUN_0600C5D6/C74E, FUN_0600DA7C, FUN_0600E1D4, FUN_0600E906, FUN_0601FEC0.
- **Hypothesis**: Heading angle (yaw). 3rd most-read numeric offset. Read by every physics pipeline + rendering. Static: FUN_0600c7d4 saves car[+0x1B0] = car[+0x20].

#### +0x24 — roll_angle?
- **Init**: 0x00000000
- **Writers**: FUN_0600611A (pc=0x06006196, 493x, 72 unique).
- **Consumers**: 3 READ. FUN_0600B6A0/B914, FUN_06008730.
- **Hypothesis**: Roll angle (rotation about forward axis). Zero at flat start. Same writer function as +0x1C (pitch). 72 unique values.

#### +0x28 — slip_angle?
- **Init**: 0xFFFFAAAB (-21,845 signed, SAME as +0x20)
- **Writers**: FUN_0602CE4E (pc=0x0602CF50, 493x, 390 unique). Also FUN_0602D96A (18x), FUN_06030D0E (4x, const 0x4000).
- **Consumers**: 8 READ + 6 WRITE = 14 total (tied for 2nd most). FUN_0600B6A0/B914, FUN_060085B8, FUN_0600C5D6/C74E, FUN_0600DA7C, FUN_0600E1D4, FUN_0600E7C8, FUN_0601FEC0, FUN_06030A06.
- **Hypothesis**: Slip angle. Init value = heading value (no slip at start). Static: FUN_0600c8cc adjusts car[+0x28] toward track-derived angle, clamped +-0x600/frame. FUN_0600c7d4 computes car[+0x28] - car[+0x20] for airborne heading correction.

#### +0x30 — heading_delta?
- **Init**: 0xFFFFAAAB (-21,845 signed, SAME as +0x20 and +0x28)
- **Writers**: FUN_0602CE4E (pc=0x0602CF16, 493x, 378 unique) + FUN_0602D07C (pc=0x0602D086, 211x). Also FUN_0602D962 (18x), FUN_06030D0C (4x, const 0x4000), FUN_06031526 (1x).
- **Consumers**: 7 READ + 6 WRITE = 13 total. FUN_060061C8, FUN_060085B8, FUN_0600E1D4, FUN_0600E7C8, FUN_0600E906, FUN_0601FEC0, FUN_0603053C, FUN_06030A06.
- **Hypothesis**: Heading rate or heading delta. Two writers in normal path = updated by two pipeline stages. Static: FUN_0600c7d4 writes car[+0x30] = heading_change - track_yaw_rate.

### Velocity / Previous Position

#### +0x38 — prev_position_x?
- **Init**: 0xFFD97340 (-2,526,400 signed, different from +0x10)
- **Writers**: FUN_0602D8CA (pc=0x0602D8DE, 475x, 455 unique). Also FUN_0602D994 (18x), FUN_06030E62 (6x), FUN_0603164C (6x).
- **Pipeline**: sym_0602D8BC (call 19) saves `car[+0x38] = car[+0x10]` before updating position, in BOTH normal and drift paths.
- **Hypothesis**: Previous-frame X position. Saved for velocity computation or collision rollback. Init differs from +0x10 by ~162K = one frame of movement at 179 mph, confirming one-frame lag.

#### +0x3C — prev_position_z?
- **Init**: 0xFF7CA977 (-8,607,369 signed, differs from +0x18 by ~131K)
- **Writers**: FUN_0602D8CA (pc=0x0602D8E0, 475x, 372 unique). Also FUN_0602D996 (18x), FUN_06030E64 (6x), FUN_0603164E (6x).
- **Pipeline**: sym_0602D8BC saves `car[+0x3C] = car[+0x18]` before updating position.
- **Hypothesis**: Previous-frame Z position. Same pattern as +0x38.

#### +0x18C — velocity_x?
- **Init**: Not in dump.
- **Writers**: FUN_0602D8CA (pc=0x0602D8FE, 475x, 456 unique). Also FUN_0602D9B8 (18x).
- **Pipeline**: sym_0602D8BC computes `car[+0x18C] = speed_factor × sin(heading)` (16.16 fixed-point), then `car[+0x10] += car[+0x18C]`.
- **Hypothesis**: X-axis velocity component. The per-frame position delta. Derived from speed × trig(heading).

#### +0x190 — velocity_z?
- **Init**: Not in dump.
- **Writers**: FUN_0602D8CA (pc=0x0602D90E, 475x, 376 unique). Also FUN_0602D9C8 (18x).
- **Pipeline**: sym_0602D8BC computes `car[+0x190] = speed_factor × cos(heading)` (16.16 fixed-point), then `car[+0x18] += car[+0x190]`.
- **Hypothesis**: Z-axis velocity component. Paired with +0x18C.

### Forces and Derivatives

#### +0x40 — angular_velocity?
- **Init**: Not in dump.
- **Writers**: FUN_0602CB7E (pc=0x0602CBEC, 493x, 296 unique). Also FUN_0602CC30 (18x, const 0).
- **Consumers**: Not in consumer map.
- **Hypothesis**: Unknown. High cardinality but not consumed by any known function. Possibly internal physics state.

#### +0x48 — drag_accumulator?
- **Init**: Not in dump.
- **Writers**: FUN_0602F3F0 (pc=0x0602F452, 493x, 470 unique — nearly unique each frame).
- **Consumers**: Not in consumer map.
- **Hypothesis**: Speed-dependent drag term. Pipeline stage 4 (sym_0602F3EC) subtracts a speed-scaled value from this field every frame. AI path static: FUN_0600c928 also subtracts speed-scaled damping from car[+0x48] (airborne path). Sample values in 0xFFBAxxxx range = small negative.

#### +0x50 — drag_copy?
- **Init**: Not in dump.
- **Writers**: FUN_0602EEC6 (pc=0x0602EEDE, 493x, 470 unique).
- **Consumers**: Not in consumer map.
- **Hypothesis**: Copy of +0x48 drag term. Pipeline stage 4 also writes this field (from +0xC0 check). AI static: FUN_0600c928 copies car[+0x50] = car[+0x48]. Same unique count as +0x48 confirms tight correlation.

#### +0x58 — steering_input?
- **Init**: Not in dump.
- **Writers**: FUN_0602D736 (pc=0x0602D76C, 493x, 354 unique). Also FUN_0602CC12 (10x), FUN_0602CC32 (18x, const 0).
- **Consumers**: Not in consumer map.
- **Hypothesis**: Steering angle or input-derived heading component. High cardinality, written every frame.

#### +0x5C — steering_accumulator?
- **Init**: Not in dump.
- **Writers**: FUN_0602D5F8 (pc=0x0602D650, 493x, 301 unique) + FUN_0602EF4C (pc=0x0602EF92, 493x, 301 unique, SAME values). Also FUN_0602CC14 (10x), FUN_0602CC34 (18x, const 0).
- **Consumers**: Not in consumer map.
- **Hypothesis**: Two writers produce identical values = one computes, the other copies (or both write the same result). Paired with accel delta writer FUN_0602EF4C.

#### +0xFC — accel_delta (CONFIRMED)
- **Init**: Not in dump.
- **Writers**: FUN_0602EF4C (pc=0x0602EF4E, 493x, 406 unique). Also FUN_0602D818 (pc=0x0602D82C, 20x, const 0).
- **Consumers**: sym_0602D814 reads +0xFC and adds to +0x0C (speed accumulator).
- **Confirmed**: C button shifts +70/update toward positive. Writer PC: 0x0602EF4E.
- **Pipeline position**: Written inline between calls 15 and 16 in the dispatcher. Read by call 18 (sym_0602D814). The secondary writer (FUN_0602D818, const 0) zeros the delta when speed is clamped to 0.

#### +0x100 — throttle_input?
- **Init**: Not in dump.
- **Writers**: FUN_0602735C (pc=0x06027370, 493x, 72 unique).
- **Pipeline**: Read by the accel delta computation (near FUN_0602EF4C). Static analysis suggests it's negated and multiplied by fixed-point constants (0x03700000, 0x02D00000) to produce force.
- **Hypothesis**: Throttle input value. Writer FUN_0602735C is near sin/cos lookup functions — possibly a direction-projected throttle. 72 unique values = moderate resolution.
- **GAP**: How does C button (0x0200 in g_pad_state) become car[+0x100]? The function chain between input reading and this field is unmapped. HIGH PRIORITY for Explorer.

#### +0x104 — throttle_secondary?
- **Init**: Not in dump.
- **Writers**: FUN_0602EFDE (pc=0x0602EFE2, 493x, 66 unique: 0xE44F-0xEFxx range).
- **Pipeline**: Also read by the accel delta computation. Multiplied by car[+0x60] and car[+0x64].
- **Hypothesis**: Secondary throttle parameter or heading-projected force. Narrow value range (0xE44F-0xEFxx) = slowly varying signed value near -0x1xxx.

### Speed Pipeline Data Flow (static, unvalidated)

```
C button (0x0200 in g_pad_state)
    ↓ [UNKNOWN FUNCTION — gap]
car[+0x100] (throttle input, writer FUN_0602735C)
car[+0x104] (secondary input, writer FUN_0602EFDE)
    ↓ FUN_0602EF4C — fixed-point multiply + accumulate
car[+0xFC] (accel delta, CONFIRMED: +70/frame with C)
    ↓ sym_0602D814 (pipeline call 18) — speed += accel_delta
car[+0x0C] (speed, CONFIRMED: mph = value / 1467)
    ↓ sym_0602D8BC (pipeline call 19) — trig-based decomposition
    │  save: car[+0x38] = car[+0x10], car[+0x3C] = car[+0x18] (prev position)
    │  if car[+0x250] == 0 (normal):
    │    velocity_x = speed × sin(heading)
    │    velocity_z = speed × cos(heading)
    │  else (drift, counter 1-10):
    │    velocity_x = TABLE[+0x250] × speed × sin(heading)
    │    velocity_z = TABLE[+0x250] × speed × cos(heading)
    │  car[+0x18C] = velocity_x, car[+0x190] = velocity_z
    │  car[+0x10] += velocity_x, car[+0x18] += velocity_z
    ↓
car[+0x10] (position_x?), car[+0x18] (position_z?)
```

The gap between g_pad_state and car[+0x100] is the #1 remaining static
analysis blocker. It requires either (a) the Explorer tracing with a
breakpoint on car[+0x100] writes to find the writer chain, or (b)
finding which function reads sym_06063D98 during racing.

### Surface and Terrain

#### +0xEC — surface_normal_x?
- **Init**: Not in dump.
- **Writers**: FUN_0602F5EE (pc=0x0602F68C, 493x, 5 unique: 0x0, 0x1F197C0, 0x34B7140, 0x7C680C0, 0xB400000).
- **Hypothesis**: Quantized surface property. Only 5 values = discrete terrain types or quantized normals. Large magnitudes suggest fixed-point surface normal component.

#### +0xF0 — surface_normal_z?
- **Init**: Not in dump.
- **Writers**: FUN_0602F5EE (pc=0x0602F690, 493x, 5 unique: 0x0, 0x14BBA80, 0x2324B80, 0x52F0080, 0x7800000).
- **Hypothesis**: Paired with +0xEC. Same writer, same 5-value quantization. Second component of surface normal.

#### +0xF4 — surface_grip?
- **Init**: Not in dump.
- **Writers**: FUN_0602F5EE (pc=0x0602F6B6, 493x, 54 unique: 0x0 to 0x91340).
- **Hypothesis**: Surface friction/grip coefficient. Same writer as +0xEC/+0xF0 but more values (54) and smaller range = continuous within terrain type.

#### +0xF8 — surface_progress?
- **Init**: Not in dump.
- **Writers**: FUN_0602EEC6 (pc=0x0602EF36, 493x, 259 unique starting from 0x80000).
- **Hypothesis**: Related to surface/track position. Different writer from the +0xEC group. Values start at 0x80000 and increase.

### Collision State

#### +0x6C — collision_flag?
- **Init**: Not in dump.
- **Writers**: FUN_0602FDB4: pc=0x0602FE84 (402x, const 1) + pc=0x0602FED8 (91x, const 0).
- **Consumers**: FUN_0600CEBA reads +0x6C.
- **Hypothesis**: Boolean collision active flag. 402 frames = 1, 91 frames = 0. Read by track segment advance.

#### +0x74 — collision_timer?
- **Init**: Not in dump.
- **Writers**: FUN_0602FDB4: pc=0x0602FED2 (91x, 17 unique: 0x38-0xFE) + pc=0x0602FED8 (402x, 15 unique: 0x42-0xFE).
- **Hypothesis**: Collision countdown or magnitude. Small values (0x38-0xFE), variable. Written by same function as +0x6C.

#### +0x88 — collision_state_a?
- **Init**: Not in dump.
- **Writers**: FUN_0602FDB4: pc=0x0602FEE8 (44x, const 1) + pc=0x0602FF2C (449x, const 0).
- **Hypothesis**: Secondary collision flag. 44 frames active out of 493. Same writer function.

#### +0xA0 — collision_state_b?
- **Init**: Not in dump.
- **Writers**: FUN_0602FDB4: pc=0x0602FF62 (156x, const 1) + pc=0x0602FFC0 (98x, const 0) + pc=0x06030042 (27x, const 0).
- **Hypothesis**: Tertiary collision state. Three writers within same function = state machine.

### Track Progress

#### +0x184 — track_segment_data?
- **Init**: Not in dump.
- **Writers**: FUN_0600CD44 (pc=0x0600CD6C, 493x, 60 unique).
- **Consumers**: FUN_06008318 reads +0xB8 and references 0x060453CC table.
- **Hypothesis**: Static: FUN_0600cd40 reads table[+0x16] and writes car[+0x184]. Track segment property field. 60 unique values = ~60 distinct track segments.

#### +0x1E4 — track_segment_index?
- **Init**: 0x00000005
- **Writers**: FUN_0600CD44 (pc=0x0600CDA4, 59x, 59 unique: 0x25-0x5D).
- **Consumers**: Not directly in consumer map but static: FUN_0600cd40 uses car[+0x1E4] as table index.
- **Hypothesis**: Current track segment index. Sequential values (0x25-0x5D = 37-93), monotonically increasing during a lap. Init=5 at race start.

#### +0x1EC — track_progress?
- **Init**: Not in dump.
- **Writers**: FUN_0600CE92 (pc=0x0600CEB6, 493x, 60 unique).
- **Consumers**: FUN_0600D8A4 reads +0x1EC. FUN_0600E71A reads +0x1EC.
- **Hypothesis**: Track progress accumulator or sub-segment position. Same value count as +0x184 (60) = one per segment.

#### +0x1F0 — track_progress_b?
- **Init**: Not in dump.
- **Writers**: FUN_0600CE6A (pc=0x0600CE78, 493x, 60 unique).
- **Hypothesis**: Paired with +0x1EC. Same writer frequency and unique count.

#### +0x228 — lap_segment_counter?
- **Init**: 0x00000000
- **Writers**: Not in writer map (no segment crossings during capture?).
- **Consumers**: FUN_0600E71A writes +0x228.
- **Hypothesis**: Static: FUN_0600ceba increments car[+0x228]. Lap segment counter — wrapping indicates lap completion.

### Rendering / Display

#### +0x100 — display_field?
- **Init**: Not in dump.
- **Writers**: FUN_0602735C (pc=0x06027370, 493x, 72 unique).
- **Consumers**: Not in consumer map.
- **Hypothesis**: sin/cos-related output. Writer is near cos_lookup/sin_lookup functions.

#### +0x104 — display_heading?
- **Init**: Not in dump.
- **Writers**: FUN_0602EFDE (pc=0x0602EFE2, 493x, 66 unique: 0xE44F-0xEFxx range).
- **Hypothesis**: Narrow value range with 66 unique values — possibly a display/HUD heading or compass value.

#### +0x120, +0x124, +0x128, +0x12C — matrix/orientation?
- **Init**: Not in dump.
- **Writers**: All written by FUN_06027E9E (pc=0x06027EBC). Only 3-4 unique values each (0x1, 0x2, 0x4, 0x80).
- **Consumers**: FUN_06027CA4 reads from consumer map DAT references near these offsets.
- **Hypothesis**: Orientation/matrix state flags or rotation indices. Very few values = enumerated states.

### Gear / Transmission

#### +0xB8 — gear_shift_cooldown?
- **Init**: 0x00000000
- **Writers**: Not in car[0] writer map (no gear shifts during capture).
- **Consumers**: FUN_06008318 reads +0xB8 (gear shift handler checks countdown=0 before allowing shift).
- **Pipeline**: Stage 6 (sym_0602F0E8) reads +0xB8 as a collision detection flag — nonzero triggers collision recovery.
- **Hypothesis**: Dual-purpose: gear shift cooldown (static) AND collision state flag (pipeline stage 6). Static says starts at 0x20 on gear shift, decrements each frame. Stage 6 uses nonzero = collision active.

#### +0x152 — effect_timer_a? (16-bit)
- **Init**: Not in dump.
- **Writers**: Comprehensive map shows FUN_0602CCF0 (pc=0x0602CCE8, 2x, const 0xA) + FUN_0602F7C0 (pc=0x0602F7D6, 16x, 10 unique: 0-9).
- **Pipeline**: Stage 5 (sym_0602F7BC) decrements if > 0.
- **Hypothesis**: Frame-based effect timer. Counts down from set value. Part of the 3-timer group (+0x152, +0x166, +0x208).

#### +0x166 — effect_timer_b? (16-bit)
- **Init**: Not in dump.
- **Writers**: Comprehensive map shows FUN_0602D818 (pc=0x0602D806, 32x, 2 unique: 0x7, 0xA) + FUN_0602F7C0 (pc=0x0602F7CA, 171x, 10 unique: 0-9).
- **Pipeline**: Stage 5 (sym_0602F7BC) decrements if > 0. Stage 6 (sym_0602F0E8) resets to 0 during collision recovery.
- **Hypothesis**: Frame-based effect timer, reset on collision. The collision-reset behavior suggests it tracks a state that collision interrupts.

#### +0x208 — effect_timer_c?
- **Init**: Not in dump.
- **Writers**: Comprehensive map shows FUN_0602F7E2 (36x, 8 unique: 0-7) + FUN_060305E0 (6x, const 8).
- **Pipeline**: Stage 5 (sym_0602F7BC) decrements if > 0.
- **Hypothesis**: Frame-based effect timer. Third in the 3-timer group.

#### +0xD8 — gear_state?
- **Init**: Not in dump.
- **Writers**: FUN_0602F180 (pc=0x0602F194, 493x, 9 unique: 0-8). Also FUN_0602F1CE (5x, const 5) and FUN_0602F1F6 (5x, const -5).
- **Hypothesis**: Gear index or gear-related counter. Only 9 values (0-8) = 9 gear states. The +5/-5 writes may be gear shift events.

### Unknown / Needs Investigation

#### +0x0E — sub-field of +0x0C?
- **Init**: Part of +0x0C word.
- **Consumers**: FUN_0600C5D6, FUN_0600E1D4, FUN_0601FEC0 write +0x0E.
- **Hypothesis**: Lower 16 bits of speed or a separate half-word field. 3 functions write it.

#### +0x60, +0x64 — track_angle_x?, track_angle_z?
- **Init**: Not in dump.
- **Writers**: FUN_0602CE4E (pc=0x0602CF96/CF98, 493x each, 490 unique). Also FUN_0602CC1C/1E (10x, const 0), FUN_0602CC3A/3C (18x, const 0).
- **Hypothesis**: Nearly unique every frame = continuous computed values. Written by same function as +0x28 (slip angle). Possibly track-relative angles.

#### +0x68 — track_segment_flag?
- **Init**: Not in dump.
- **Writers**: FUN_0602EEC6 (pc=0x0602EEEA, 493x, 31 unique).
- **Consumers**: FUN_0600CE66, FUN_0600CEBA read +0x68.
- **Hypothesis**: Read by track segment advance functions. 31 unique values. Possibly segment type or track feature flags.

#### +0x74 — collision_recovery_state?
- **Init**: Not in dump.
- **Writers**: FUN_0602FDB4: pc=0x0602FED2 (91x) + pc=0x0602FED8 (402x).
- **Pipeline**: Stage 6 (sym_0602F0E8) sets +0x74 = 0x38 during collision recovery.
- **Hypothesis**: Collision recovery parameter. Set to fixed value during collision detection, then managed by FUN_0602FDB4.

#### +0x78, +0x84, +0x94 — state_transfer_group?
- **Init**: +0x78 = 0x00000038 (56)
- **Writers**: +0x78: FUN_0602F06A (493x, 31 unique). +0x84: FUN_0602F0EC (pc=0x0602F116, 493x, 5 unique: 0x0,0x6A,0x8A,0xD4,0xFF). +0x94: FUN_0602F06A (pc=0x0602F0D6, 493x, 5 unique — same values as +0x84).
- **Pipeline**: Stage 6 (sym_0602F0E8) copies car[+0x94]→[+0x84] and car[+0x78]→[+0x68] in normal path. Sets +0x84 = 0x38 in one path.
- **Hypothesis**: State transfer group. +0x94 and +0x78 are "current" values; +0x84 and +0x68 are "previous" copies. Updated each frame by stage 6.

#### +0x90 — collision_recovery_param?
- **Init**: Not in dump.
- **Pipeline**: Stage 6 (sym_0602F0E8) sets +0x90 = 0x38 during collision recovery path.
- **Hypothesis**: Collision recovery parameter, paired with +0x74. Both set to 0x38 on collision detection.

#### +0xB0, +0xB4 — paired_counters?
- **Init**: Not in dump.
- **Writers**: FUN_0602F022 (pc=0x0602F052/F054, 493x each, 19 unique each — same values).
- **Hypothesis**: Twin fields written by adjacent instructions. 19 unique values = stepped/quantized.

#### +0xC0 — computed_value?
- **Init**: Not in dump.
- **Writers**: FUN_0602CB7E (pc=0x0602CC46, 493x, 119 unique).
- **Consumers**: Not in consumer map.
- **Hypothesis**: Unknown. Moderate cardinality.

#### +0xC4 — cumulative_track_force?
- **Init**: Not in dump.
- **Pipeline**: Stage 7 (FUN_0602F270 / sym_0602F17C) writes +0xC4. Updated with cumulative force from track lookup tables.
- **Hypothesis**: Accumulated track-derived force. Written during the track force application conditional.

#### +0xD0 — collision_delta?
- **Init**: Not in dump.
- **Writers**: FUN_0602F0EC (pc=0x0602F0FE, 493x, 349 unique).
- **Pipeline**: Stage 6 (sym_0602F0E8) reads and modifies +0xD0 with ±0x071C delta during collision path.
- **Hypothesis**: Collision angle or deflection delta. High cardinality, modified during collision state transitions.

#### +0xD6 — proximity_counter? (16-bit)
- **Init**: Not in dump.
- **Writers**: Comprehensive map shows FUN_0602F4B8 (pc=0x0602F4D6, 64x, 20 unique) + FUN_0602F554 (pc=0x0602F5B2, 12x, const 0x14).
- **Pipeline**: Stage 10 (sym_0602F4B4) sets +0xD6 = 0x14 when an opponent is detected nearby and within heading angle. Decremented each frame.
- **Hypothesis**: Opponent proximity cooldown timer. Set to 20 (0x14) on detection, counts down to 0.

#### +0xD8 — section_transition_direction?
- **Init**: Not in dump.
- **Writers**: FUN_0602F180 (pc=0x0602F194, 493x, 9 unique: 0-8).
- **Pipeline**: Stage 7 (sym_0602F17C) sets +0xD8 to +5 or -5 based on track section boundary crossing.
- **Hypothesis**: Track section transition indicator. Values ±5 indicate ascending/descending section change.

#### +0xDC — track_section_index? (16-bit)
- **Init**: Not in dump.
- **Pipeline**: Stage 7 (sym_0602F17C) increments/decrements +0xDC as section boundaries are crossed.
- **Hypothesis**: Current position in a gear/power table indexed by sections.

#### +0xE0 — track_force_output?
- **Init**: Not in dump.
- **Writers**: FUN_0602D86A (pc=0x0602D87E, 493x, 441 unique). Also FUN_0602F224 (pc=0x0602F226, 10x).
- **Pipeline**: Stage 7 (FUN_0602F270) reads and writes +0xE0 with lookup table results. sym_0602D814 (speed writer) also writes +0xE0 as clamped speed via gear lookup.
- **Hypothesis**: Track/gear force output. Very high cardinality (441/493). Updated by both track force stage and speed accumulator.

#### +0xE4 — acceleration_copy?
- **Init**: Not in dump.
- **Writers**: FUN_0602EEC6 (pc=0x0602EF24, 493x, 424 unique).
- **Hypothesis**: Similar cardinality to +0xE0. Written by FUN_0602EEC6 (which also writes +0x50, +0xF8, +0x114, +0x144, +0x252).

#### +0xE8 — speed_headroom?
- **Init**: Not in dump.
- **Writers**: FUN_0602D86A (pc=0x0602D88A, 493x, only 2 unique: 0x0 and 0x212).
- **Pipeline**: sym_0602D814 (speed writer, call 18) writes +0xE8 as `max_available_speed - current_speed`. Represents headroom before speed cap.
- **Hypothesis**: Speed headroom. Only 2 values during capture = car was near max speed most of the time (headroom ~0 or ~0x212).

#### +0x108 — heading_derivative?
- **Init**: Not in dump.
- **Writers**: FUN_0602CB12 (pc=0x0602CB3C, 493x, 167 unique).
- **Hypothesis**: Moderate cardinality, written every frame.

#### +0x10C — dual_writer_field?
- **Init**: Not in dump.
- **Writers**: FUN_0602CB7E (pc=0x0602CBBC, 493x, 229 unique) + FUN_0602CCF0 (pc=0x0602CDEC, 493x, 190 unique) + FUN_0602D7E4 (pc=0x0602D7E6, 10x).
- **Hypothesis**: Three writers = updated by multiple pipeline stages. Important internal state.

#### +0x114 — animation_lookup?
- **Init**: Not in dump.
- **Writers**: FUN_0602EEC6 (pc=0x0602EF2A, 493x, const 0).
- **Pipeline**: Stage 9 (sym_0602F474) writes +0x114 from a 4-entry lookup table (sym_060477D8) based on car[+0xD4] counter value.
- **Hypothesis**: Animation/display state from a 4-frame cycle. The writer map shows const 0, meaning the counter stayed at one value during capture. Needs varied driving to see all 4 states.

#### +0x11C — energy_or_force?
- **Init**: Not in dump.
- **Writers**: FUN_0602F5EE (pc=0x0602F652, 493x, 185 unique: large values 0x3DD485-0x22xxxxxx).
- **Hypothesis**: Same writer as surface fields (+0xEC/+0xF0/+0xF4) but much more variation. Possibly integrated force from surface interaction.

#### +0x140 — world_coordinate?
- **Init**: Not in dump.
- **Writers**: FUN_0602C72E (pc=0x0602C7F4, 493x, 493 unique — unique every frame).
- **Hypothesis**: Completely unique each frame = monotonically changing. Possibly a track-space coordinate or accumulated distance. Values: 0x55AE92A, 0x55B0DF6... (incrementing slowly).

#### +0x144 — world_coordinate_b?
- **Init**: Not in dump.
- **Writers**: FUN_0602EEC6 (pc=0x0602EF42, 493x, 493 unique).
- **Hypothesis**: Also unique every frame. Values: 0x1BCDB3D... (different range from +0x140).

#### +0x148 — rotation_accumulator?
- **Init**: Not in dump.
- **Writers**: FUN_0602CA88 (pc=0x0602CAE0, 493x, 490 unique).
- **Hypothesis**: Nearly unique each frame. High cardinality continuous value.

#### +0x154 — smoothed_heading?
- **Init**: Not in dump.
- **Writers**: FUN_0602CE4E (pc=0x0602CF18, 493x, 286 unique).
- **Hypothesis**: Written by same function as +0x28 (slip angle) and +0x30 (heading delta). Moderate cardinality = smoothed/filtered value.

#### +0x178 — lateral_force?
- **Init**: Not in dump.
- **Writers**: FUN_0602D5F8 (pc=0x0602D63A, 493x, 271 unique).
- **Hypothesis**: High cardinality, written every frame by a force-computation function.

#### +0x1B0 — saved_heading?
- **Init**: Not in dump.
- **Writers**: FUN_0600E526 (pc=0x0600E62C, 493x, 378 unique).
- **Consumers**: Not in consumer map.
- **Hypothesis**: Static: FUN_0600c7d4 writes car[+0x1B0] = car[+0x20]. Saved heading for frame delta computation.

#### +0x1F4 — track_speed?
- **Init**: Not in dump.
- **Writers**: FUN_0600C974 (pc=0x0600C996, 493x, 60 unique).
- **Consumers**: FUN_0600E71A reads +0x1F4 and writes +0x1F8.
- **Hypothesis**: 60 unique values = one per segment. Track-dependent speed property.

#### +0x1FC — surface_index?
- **Init**: Not in dump.
- **Writers**: FUN_0600C9EA (pc=0x0600CA84, 493x, 6 unique: 0x0, 0x200, 0x300, 0x400, 0x500, 0x600).
- **Consumers**: FUN_0600CB90 reads +0x1F8. Static: FUN_0600ca96 reads car[+0x1F8] and car[+0x1FC].
- **Hypothesis**: Surface table index. Only 6 discrete values = 6 surface types.

#### +0x238, +0x23C — track_data_pointers?
- **Init**: Not in dump.
- **Writers**: FUN_0600D4AA: 3 PCs for each, values are pointers (0x6079C40, 0x607AD18, etc.).
- **Hypothesis**: Pointers into track segment data arrays. Values are RAM addresses in the 0x0607xxxx range.

#### +0x252 — frame_counter?
- **Init**: Not in dump.
- **Writers**: FUN_0602EEC6 (pc=0x0602EED8, 493x, 10 unique: 0-9).
- **Hypothesis**: Modulo counter (0-9). Possibly sub-frame phase or animation tick.

#### +0x250 — drift_counter? (16-bit)
- **Init**: Not in dump.
- **Writers**: FUN_06030848 (pc=0x06030848, 2x, const 0xA) + FUN_06030A1C (2x, const 0) + FUN_06030A3C (18x, values 1-9).
- **Pipeline**: sym_0602D8BC (call 19) branches on `car[+0x250] != 0`:
  - If 0: normal heading-based velocity integration
  - If nonzero: drift/rotation path using lookup table at 0x0602E8B8 indexed by this value
- **Hypothesis**: Drift mode intensity counter (0-10). 0 = normal driving. 1-10 = drift with table-scaled rotation. Set to 0xA (10) to start drift, counts down.

#### +0x258 — collision_counter?
- **Init**: Not in dump.
- **Writers**: FUN_0602D054 (pc=0x0602D05A, 230x, 84 unique) + FUN_0602D07C (pc=0x0602D086, 263x, const 0).
- **Hypothesis**: Active in 230 frames, cleared in 263. Possibly collision persistence timer.

#### +0x25C — computed_angle?
- **Init**: Not in dump.
- **Writers**: FUN_06027E9E (pc=0x06027EB0, 493x, 50 unique).
- **Hypothesis**: Moderate cardinality (50). Written by orientation matrix function.

#### +0x264 — continuous_physics?
- **Init**: Not in dump.
- **Writers**: FUN_0602CCF0 (pc=0x0602CD70, 470x, 465 unique).
- **Hypothesis**: Nearly unique each frame. Written by a physics computation function.
