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
| +0x08 | Observed formula | Speed index: `FUN_06027552(car[+0x0C], 0x480000)` — fixed-point multiply by 72 |
| +0x0C | Watchpoint + HUD + NOP | Speed magnitude. HUD mph = value / 1,467. NOP of sym_0602D814 freezes speed at 0. Written by sym_0602D814 for player. |
| +0x10 | Per-frame sampling + NOP | World X position. Decreases monotonically with forward motion. NOP of sym_0602D8BC freezes car in place (rendering disconnected from physics). |
| +0x18 | Per-frame sampling + NOP | World Z position. Same evidence as +0x10. |
| +0x20 | Per-frame sampling | Heading angle. Changes even when idle (settles to track direction in ~18 frames). 101 unique values in 300f throttle. |
| +0x28 | Per-frame sampling | Slip/body angle. Diverges from +0x20 at speed — ~12K units at steady state on curves. Angular values in 16-bit space. |
| +0x30 | Per-frame sampling | **Copy of +0x20** (NOT heading delta). Identical to +0x20 at every frame across all 4 scenarios. |
| +0x38 | Per-frame sampling | Pre-update X position. NOT previous-frame +0x10 (only 106/299 match). Holds position from before the most recent position update WITHIN the same frame. |
| +0x3C | Per-frame sampling | Pre-update Z position. Same as +0x38 pattern. |
| +0xFC | Watchpoint + C button | Acceleration delta. C button shifts +70/update toward positive. Writer: FUN_0602CA84 RTS delay slot (profiler reported PC 0x0602EF4E = return target artifact). |
| +0x100 | Breakpoint at FUN_06027370 | **sin(car[+0x24])** — NOT throttle input. Written by FUN_06027358 from pipeline call 12 (sym_0602EFCC). On flat track, roll=0 → sin(0)=0. |
| +0x104 | Breakpoint at FUN_06027370 | **cos(car[+0x24])** — paired with +0x100. On flat track, cos(0)=1. |
| +0x18C | Per-frame sampling | Velocity X. Empirically verified: `car[+0x18C] = car[+0x10] - car[+0x38]` — 300/300 frames match. Per-frame position delta. |
| +0x190 | Per-frame sampling | Velocity Z. `car[+0x190] = car[+0x18] - car[+0x3C]` — 300/300 match. |
| +0x1FC | Per-frame sampling | Surface type index. On-track: 0x300/0x400/0x500 (road segments). Off-track: constant 0x600 (grass). 6 discrete values total. |

### Empirically Confirmed Pipeline Facts

| Fact | Evidence | Source |
|------|----------|--------|
| Pipeline order: 18 JSR calls from FUN_0602EEB8 | pc_trace_frame | FUN_0602EEB8_obs.md |
| Player physics runs FIRST in frame | pc_trace_frame on FUN_0600C010 | FUN_0600C010_obs.md |
| Frame budget: physics 3.4%, rendering 93.1% | 217K PCs analyzed | FUN_0600C010_obs.md |
| FUN_0602CA84 is central force accumulator | Assembly + breakpoint | FUN_0602CA84_obs.md |
| sym_0602D814 = speed gate (NOP → speed=0) | Human NOP test | explorer_priorities.md |
| sym_0602D8BC = rendered position writer (NOP → frozen car) | Human NOP test | explorer_priorities.md |
| **NO dual position system** — all physics identical when position frozen | NOP + 200f comparison | dual_position_obs.md |
| Pipeline does NOT read car[+0x10/+0x18] — position is write-only output | dual_position_obs.md | All physics fields identical in NOP vs baseline |
| Track segments diverge at frame 106 in NOP run, surface fields do NOT | CSV analysis | +0xF4/+0x1FC identical all 200f, +0x1E4 diverges at f106 |
| Accel delta (+0xFC) identical NOP vs baseline for all 200 frames | CSV analysis | Human's "felt like grass" was past capture window |
| FUN_0602EFF0 NOP kills ALL input (steering AND throttle) | Human NOP test | Pipeline initializer, not just steering |
| FUN_0602F5B6 NOP kills throttle (unexpected surface dependency) | Human NOP test | Surface fields feed force accumulator |
| FUN_0602CA84 NOP kills throttle but STEERING STILL WORKS | Human NOP test | Clean throttle/force gate. Steering splits before call 14 |
| Steering has no effect at low speed (~30 mph from standstill) | LEFT identical to throttle-only | FUN_0602D8BC_obs.md |
| 16-bit writes invisible to 4-byte watchpoints | +0x252 gets 0 hits | FUN_0602EEB8_answers.md |
| `mov.l Rm, @(R0,Rn)` writes invisible to watchpoints | +0xC0,+0x108,+0x148 all 0 hits | FUN_0602CA84_answers.md |
| Writer map PCs are +4 from actual write instruction | SH-2 pipeline commit delay | FUN_0602CA84_answers.md |
| FUN_0602EEB8 Tier 2 (4/4 claims passed) | Oracle test | results.tsv |
| FUN_0600C010 Tier 2 (3/3 claims passed) | Oracle test | results.tsv |
| sym_0602D8BC Tier 2 (4/5, heading write missed) | Oracle test | results.tsv |
| FUN_0602F5B6 Tier 2 (3/5, surface writes missed) | Oracle test | results.tsv |
| FUN_0602CCEC Tier 2 (3/3, gates on speed>0) | Oracle test | results.tsv |
| FUN_0602CA84 Tier 2 (3/3, writes_to infeasible) | Oracle test | results.tsv |
| FUN_0602EFF0 Tier 2 (3/3, steering processor) | Oracle test | results.tsv |
| sym_0602D814 Tier 2 (3/3, writes_to +0x0C worked — 59 hits) | Oracle test | results.tsv |
| Watchpoint catches `mov.l @(disp,Rn)` but NOT `mov.l @(R0,Rn)` | sym_0602D814 vs FUN_0602CA84 | results.tsv |
| sym_0602F3EC Tier 2 (3/3, writes_to +0x08 — 59 hits) | Oracle test | results.tsv |

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

#### +0x30 — heading_copy (CONFIRMED copy of +0x20)
- **Init**: 0xFFFFAAAB (-21,845 signed, SAME as +0x20)
- **Writers**: FUN_0602CE4E (pc=0x0602CF16, 493x, 378 unique) + FUN_0602D07C (pc=0x0602D086, 211x). Also FUN_0602D962 (18x), FUN_06030D0C (4x, const 0x4000), FUN_06031526 (1x).
- **Consumers**: 7 READ + 6 WRITE = 13 total. FUN_060061C8, FUN_060085B8, FUN_0600E1D4, FUN_0600E7C8, FUN_0600E906, FUN_0601FEC0, FUN_0603053C, FUN_06030A06.
- **CONFIRMED**: Identical to +0x20 at every frame across all 4 test scenarios (throttle, idle, steer, wall strike). Written at a different pipeline stage — serves as a snapshot for downstream readers. Prior hypothesis "heading delta" was WRONG.

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

#### +0x40 — acceleration_state?
- **Init**: Not in dump.
- **Writers**: FUN_0602CB7E (pc=0x0602CBEC, 493x, 296 unique). Also FUN_0602CC30 (18x, const 0).
- **Consumers**: Not in consumer map.
- **OBSERVED**: 19 unique values during throttle, constant -4064 during braking. Only active during acceleration — becomes static when decelerating.
- **Pipeline**: FUN_0602CA84 zeros this field when drift (+0x250) is active.
- **Hypothesis**: Acceleration-phase internal state. Inactive during braking.

#### +0x48 — drag_accumulator (CONFIRMED computation)
- **Init**: -2,733,006 (from save state).
- **Writers**: sym_0602F3EC (pc=0x0602F452, 493x, 470 unique).
- **Pipeline**: `car[+0x48] -= clamp(speed_index × 64, 0, 2730)`. Decreases each frame proportional to speed. At speed=0, drag_amount=0, no change. Feeds downstream force calculations.
- **CONFIRMED**: Monotonic decrease with throttle (-2733006 → -2951628 over 300f). Static at idle.

#### +0x50 — drag_accumulator_b (CONFIRMED computation)
- **Init**: -2,814,926 (from save state).
- **Writers**: sym_0602F3EC (pc=0x0602EEDE, 493x, 470 unique).
- **Pipeline**: Same as +0x48 UNLESS car[+0xC0] != 0, in which case a fixed alternate constant is subtracted instead of speed-proportional drag. Diverges from +0x48 during active driving.
- **CONFIRMED**: -2814926 → -3798290 over 300f throttle (diverges from +0x48 because +0xC0 becomes nonzero with force applied).

#### +0x58 — steering_input (CONFIRMED — modified by FUN_0602D43C)
- **Init**: Not in dump.
- **Writers**: FUN_0602D736 (pc=0x0602D76C, 493x, 354 unique). Also FUN_0602CC12 (10x), FUN_0602CC32 (18x, const 0).
- **Pipeline**: FUN_0602D43C (call 16a) reads and modifies via atan2-based steering correction. Active even at idle (18 unique values) — affected by heading adjustment.
- **CONFIRMED**: Steering-related field modified by the collision+steering response stage.

#### +0x5C — steering_accumulator (CONFIRMED — modified by FUN_0602D43C)
- **Init**: Not in dump.
- **Writers**: FUN_0602D5F8 (pc=0x0602D650, 493x, 301 unique) + FUN_0602EF4C (pc=0x0602EF92, 493x, 301 unique, SAME values).
- **Pipeline**: FUN_0602D43C reads and modifies. Input-responsive (constant 1 at idle, 37 unique with throttle). Two writers produce identical values = upstream compute + FUN_0602D43C update.
- **CONFIRMED**: Steering accumulator, updated by collision+steering response stage.

#### +0xFC — accel_delta (CONFIRMED)
- **Init**: Not in dump.
- **Writers**: FUN_0602EF4C (pc=0x0602EF4E, 493x, 406 unique). Also FUN_0602D818 (pc=0x0602D82C, 20x, const 0).
- **Consumers**: sym_0602D814 reads +0xFC and adds to +0x0C (speed accumulator).
- **Confirmed**: C button shifts +70/update toward positive. Writer PC: 0x0602EF4E.
- **Pipeline position**: Written inline between calls 15 and 16 in the dispatcher. Read by call 18 (sym_0602D814). The secondary writer (FUN_0602D818, const 0) zeros the delta when speed is clamped to 0.

#### +0x100 — sin(roll_angle) (CONFIRMED)
- **Init**: Not in dump.
- **Writers**: FUN_0602735C (pc=0x06027370, 493x, 72 unique).
- **Pipeline**: Computed by FUN_06027358 (sin/cos), called from sym_0602EFCC (pipeline call 12). `car[+0x100] = sin(car[+0x24])`. On flat track, roll=0 → value=0.
- **CONFIRMED**: Breakpoint at 0x06027370 showed R5=0x06078A00 (car[+0x100]), called from sym_0602EFCC. Prior hypothesis "throttle_input?" was WRONG.

#### +0x104 — cos(roll_angle) (CONFIRMED)
- **Init**: Not in dump.
- **Writers**: FUN_0602EFDE (pc=0x0602EFE2, 493x, 66 unique: 0xE44F-0xEFxx range).
- **Pipeline**: Paired with +0x100. `car[+0x104] = cos(car[+0x24])`. On flat track, cos(0)≈1 (values near 0xE44F-0xEFxx range represent the fixed-point cosine).
- **CONFIRMED**: Same breakpoint evidence as +0x100.

### Speed Pipeline Data Flow (partially validated)

```
C button (0x0200 in g_pad_state)
    ↓ [UNKNOWN — throttle signal enters via car[+0x108] or +0x10C]
car[+0x108] (intermediate force, read+written by FUN_0602CA84)
car[+0x10C] (intermediate force, read+written by FUN_0602CA84)
    ↓ FUN_0602CA84 (pipeline call 15) — central force accumulator
    │  roll_projection: car[+0x100]=sin(roll) × 0x3700000
    │  surface_modulation: +0xEC, +0xF0, +0xF4, +0xF8, +0x11C
    │  gear_selection: car[+0xD8] → constant 0x140 or 0x100
    │  final: (car[+0x108] × A + car[+0x10C] × B - car[+0x114]) × gear >> 8
    ↓
car[+0xFC] (accel delta, CONFIRMED: +70/frame with C)
    ↓ sym_0602D814 (pipeline call 17, NOP CONFIRMED) — speed += accel_delta
car[+0x0C] (speed, CONFIRMED: NOP freezes speed at 0)
    ↓ sym_0602D8BC (pipeline call 18, NOP CONFIRMED) — trig-based decomposition
    │  save: car[+0x38] = car[+0x10], car[+0x3C] = car[+0x18] (pre-update)
    │  car[+0x18C] = position_delta_X (CONFIRMED: = +0x10 - +0x38)
    │  car[+0x190] = position_delta_Z (CONFIRMED: = +0x18 - +0x3C)
    │  car[+0x10] += velocity_x, car[+0x18] += velocity_z
    ↓
car[+0x10] (CONFIRMED: world X position)
car[+0x18] (CONFIRMED: world Z position)
```

**Throttle gap update (2026-03-15)**: car[+0x100] is NOT throttle input —
it's sin(roll_angle). The C button signal enters through car[+0x108] and/or
car[+0x10C], which are intermediate force accumulators read AND written by
FUN_0602CA84. These fields accumulate frame-over-frame.

**Speed convergence loop (PROPOSED — static + correlation, needs NOP confirmation)**:
FUN_0602CCEC (called from FUN_0602CA84) creates a feedback loop:
`car[+0xE0] → car[+0x110] → car[+0xFC] → car[+0x0C] → car[+0xE0]`.
The force term +0x110 is derived from `0x2134 - car[+0xE0]` (force deficit
from gear max speed). +0x110 decays linearly by 1474/frame when positive.
This produces speed convergence: as speed → gear_max, force deficit → 0,
accel delta → 0. The gear lookup table at sym_0602E938 selects different force
constants per gear (+0x7C) and track section (+0xDC).
Evidence: static disassembly of both functions + per-frame CSV correlation.
NOP test of FUN_0602CCEC would confirm (expect: speed exceeds gear max).

**Brake behavior (2026-03-15)**: Braking from 27 mph → 0 in ~100 frames.
Accel delta peaks at -303 (frame 20), decreases as speed drops. Force
accumulators +0x108/+0x10C increase toward 65536 during braking (force
"restored" as speed drops). +0x110 and +0xE0 drop to 0 when stopped.
+0x114 (resistance) clears to 0 at rest. +0x8C/+0x90 activate (56→216)
only during braking — dual-purpose with collision.

**THROTTLE PIPELINE COMPLETE (2026-03-15)**: sym_0602FDA4 (pipeline call 1)
reads g_pad_state (sym_06063D98) and processes button inputs:

```
C button (0x0200 in g_pad_state)
    ↓ sym_0602FDA4 (call 1): C pressed → car[+0x6C]=1, car[+0x74] += 10 (max 184)
    ↓                        C released → car[+0x6C]=0, car[+0x74] decays toward 56
car[+0x74] (throttle force accumulator, range 56-184)
    ↓ sym_0602F0E8 (call 6): copies car[+0x74] → car[+0x84] in normal path
    ↓ downstream force computation reads car[+0x84]
    ↓ FUN_0602CA84 (call 15) → car[+0xFC] (accel delta)
    ↓ sym_0602D814 (call 17) → car[+0x0C] (speed)
    ↓ sym_0602D8BC (call 18) → car[+0x10/+0x18] (position)

B button (0x0100): car[+0x88]=1, car[+0x90] += 40 (max 184+). Copies → +0x8C.
UP (0x2000): car[+0xDE] += 1 (gear up, max 3)
DOWN (0x1000): car[+0xDE] -= 1 (gear down, min 0)
```

**No remaining gaps in the throttle→speed→position pipeline.**

Button mapping table at sym_06081888:
| Mask | Button | Action |
|------|--------|--------|
| 0x2000 | UP | Gear up (+0xDE += 1) |
| 0x1000 | DOWN | Gear down (+0xDE -= 1) |
| 0x0200 | C | Throttle (+0x74 += 10) |
| 0x0100 | B | Brake (+0x90 += 40) |

### Pipeline Coupling Architecture (from NOP tests)

NOP tests revealed the pipeline's dependency structure:

```
call 1  sym_0602FDA4 [input handler] → +0x6C, +0x74, +0x88, +0x90, +0xDE
call 2  FUN_0602EFF0 [rotation init] → +0xB0, +0xB4, +0x78, +0x94
           ↓ (indirect: +0xB0 → call 6 EMA → +0xD0 → call 16a → +0x58/+0x5C → force)
           NOP kills ALL input — rotation state is the directional reference frame
call 6  sym_0602F0E8 [state transfer] → copies +0x74→+0x84, +0x94→+0x84, +0x78→+0x68
call 11 FUN_0602F5B6 [surface writer] → +0xEC, +0xF0, +0xF4, +0x11C
           ↓ (direct: all 4 fields read by FUN_0602CA84 for surface modulation)
           NOP kills throttle — surface fields feed directly into force formula
call 15 FUN_0602CA84 [force accumulator] → +0xFC, +0x108, +0x10C, +0x40, +0xC0
           NOP kills throttle, steering STILL WORKS — clean force/throttle gate
call 17 sym_0602D814 [speed writer] → +0x0C, +0xE0, +0xE8
           NOP freezes speed at 0
call 18 sym_0602D8BC [position writer] → +0x10, +0x18, +0x38, +0x3C, +0x18C, +0x190
           NOP freezes position, all physics identical (write-only output)
```

### Surface and Terrain

#### +0xEC — surface_normal_x?
- **Init**: Not in dump.
- **Writers**: FUN_0602F5EE (pc=0x0602F68C, 493x, 5 unique: 0x0, 0x1F197C0, 0x34B7140, 0x7C680C0, 0xB400000).
- **Hypothesis**: Quantized surface property. Only 5 values = discrete terrain types or quantized normals. Large magnitudes suggest fixed-point surface normal component.

#### +0xF0 — surface_normal_z?
- **Init**: Not in dump.
- **Writers**: FUN_0602F5EE (pc=0x0602F690, 493x, 5 unique: 0x0, 0x14BBA80, 0x2324B80, 0x52F0080, 0x7800000).
- **Hypothesis**: Paired with +0xEC. Same writer, same 5-value quantization. Second component of surface normal.

#### +0xF4 — terrain_lateral_force?
- **Init**: Not in dump.
- **Writers**: FUN_0602F5EE (pc=0x0602F6B6, 493x, 54 unique: 0x0 to 0x91340).
- **OBSERVED**: On-track: nearly zero (3 unique values). Off-track/grass: oscillates between -2.9M and +2.7M (41 unique values). NOT a friction coefficient — large magnitude and sign oscillation indicate terrain slope or lateral force. Prior hypothesis "surface_grip?" was WRONG.

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

#### +0x74 — throttle_force (CONFIRMED — written by sym_0602FDA4)
- **Init**: Not in dump (likely 56 = 0x38 = resting value).
- **Writers**: sym_0602FDA4 (call 1): C pressed → +10/frame (max 184). C released → decays toward 56. Also FUN_0602FDB4 (91x, values 0x38-0xFE) in comprehensive map.
- **Pipeline**: sym_0602F0E8 (call 6) copies +0x74 → +0x84 in normal path. +0x84 feeds downstream force computation.
- **CONFIRMED**: Throttle force accumulator. Range 56 (idle) to 184 (full throttle). Resting value matches +0x78 init (0x38=56).

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

(+0x100 and +0x104 moved to Forces section — they are sin/cos(roll), not display fields)

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

#### +0x88 — brake_active_flag (CONFIRMED — written by sym_0602FDA4)
- **Init**: Not in dump.
- **Writers**: sym_0602FDA4 (call 1): B pressed → car[+0x88] = 1. B released → clears.
- **CONFIRMED**: Brake active flag, set by the input handler.

#### +0x8C — brake_force_copy (CONFIRMED)
- **Init**: 56 (0x38, resting value).
- **Pipeline**: sym_0602FDA4 copies car[+0x90] → car[+0x8C] each frame. Mirrors +0x90.
- **CONFIRMED**: Brake force mirror. Previously misidentified as "collision_state_a."

#### +0x90 — brake_force (CONFIRMED — written by sym_0602FDA4)
- **Init**: 56 (0x38, resting value).
- **Writers**: sym_0602FDA4 (call 1): B pressed → +40/frame (max 184+). B released → decays (r4 = r4 - r4/2, floor at 56).
- **Pipeline**: sym_0602F0E8 (call 6) sets +0x90 = 0x38 during collision recovery (resets brake force).
- **CONFIRMED**: Brake force accumulator. Range 56 (idle) to 184+ (full brake). Previously misidentified as "collision_recovery_param."

#### +0xAC — steering_sensor? (NOT D-pad, NOT in writer maps)
- **Init**: Not in dump.
- **Writers**: NOT in any writer map (81 or 95 offsets). Written before the physics pipeline by unknown mechanism.
- **Pipeline**: Read by FUN_0602EFF0 (call 2). Deadzone ±5, clamp max 80, scale ×255, then 3× atan2 → rotation angles.
- **OBSERVED (rolling_steer_left)**: Does NOT respond to D-pad LEFT. Shows same values (-106 at f100) with and without LEFT held. Prior hypothesis "raw D-pad steering" was WRONG. The D-pad steering input enters through a DIFFERENT mechanism. +0xAC may be an analog steering sensor or track-derived value, not button input. **The D-pad → steering path is still unmapped.**

#### +0xB0 — steering_rotation?
- **Init**: Not in dump.
- **Writers**: FUN_0602F022 (pc=0x0602F052, 493x, 19 unique).
- **Pipeline**: Written by FUN_0602EFF0 (call 2) after atan2 of processed steering input. Previous value copied to +0xB4 before overwrite. Read by sym_0602F0E8 (call 6).
- **Hypothesis**: Computed steering rotation angle from deadzone/clamped input.

#### +0xB4 — prev_steering_rotation?
- **Init**: Not in dump.
- **Writers**: FUN_0602F022 (pc=0x0602F054, 493x, 19 unique — same values as +0xB0).
- **Pipeline**: Written by FUN_0602EFF0 (call 2): old car[+0xB0] → car[+0xB4].
- **Hypothesis**: Previous-frame steering rotation. Same values as +0xB0 = one frame lagged.

#### +0xC0 — force_output?
- **Init**: Not in dump.
- **Writers**: FUN_0602CB7E (pc=0x0602CC46, 493x, 119 unique).
- **Pipeline**: Written by FUN_0602CCEC in RTS delay slot (line 156) — the final output of the force term sub-function. 91 unique values when throttle active, 0 when idle.
- **Hypothesis**: Force computation output from FUN_0602CCEC. Fed back into FUN_0602CA84's next iteration.

#### +0xC4 — cumulative_track_force?
- **Init**: Not in dump.
- **Pipeline**: Stage 7 (FUN_0602F270 / sym_0602F17C) writes +0xC4. Updated with cumulative force from track lookup tables.
- **Hypothesis**: Accumulated track-derived force. Written during the track force application conditional.

#### +0xD0 — smoothed_rotation (CONFIRMED computation)
- **Init**: Not in dump.
- **Writers**: sym_0602F0E8 (pipeline call 6, 493x, 349 unique).
- **Pipeline**: Normal path: `car[+0xD0] = (car[+0xB0] << 8 + car[+0xD0]) >> 1` — exponential moving average of steering rotation signal. Collision path: `car[+0xD0] ±= 0x071C` toward zero (clamped). Smoothed rotation consumed by downstream stages.
- **CONFIRMED**: EMA blending of +0xB0 (steering atan2 output). Prior hypothesis "collision delta" was imprecise — it's the smoothed rotation with collision adjustment.

#### +0xD6 — proximity_counter? (16-bit)
- **Init**: Not in dump.
- **Writers**: Comprehensive map shows FUN_0602F4B8 (pc=0x0602F4D6, 64x, 20 unique) + FUN_0602F554 (pc=0x0602F5B2, 12x, const 0x14).
- **Pipeline**: Stage 10 (sym_0602F4B4) sets +0xD6 = 0x14 when an opponent is detected nearby and within heading angle. Decremented each frame.
- **Hypothesis**: Opponent proximity cooldown timer. Set to 20 (0x14) on detection, counts down to 0.

#### +0xD8 — gear_shift_direction (CONFIRMED computation)
- **Init**: Not in dump.
- **Writers**: sym_0602F17C (pc=0x0602F194, 493x, 9 unique: 0-8).
- **Pipeline**: Set to +5 on gear-up transition, -5 on gear-down, decays toward 0 by ±1/frame. 0 = neutral, ±5 = just shifted, intermediate = decaying. Called 2× per frame (conditional + unconditional).
- **CONFIRMED**: Gear transition flag with decay. Values 0-8 map to: neutral, decaying states, freshly shifted.

#### +0xDC — gear_section_index (CONFIRMED — selects gear ratio)
- **Init**: Not in dump (likely 0 from standstill).
- **Pipeline**: sym_0602F17C increments when `car[+0xE0] > sym_060477AC[section]` (upper threshold), decrements when `car[+0xE0] < sym_0604779C[section]` (lower threshold). Hysteresis design prevents oscillation. **sym_0602D814 uses `sym_060477BC[car[+0xDC]]` as the gear ratio** for speed→force conversion.
- **CONFIRMED**: This is the game's gear shift mechanism. +0xDC selects which entry in the gear ratio table is used. 16-bit field.

#### +0xE0 — gear_scaled_speed (CONFIRMED computation)
- **Init**: Not in dump.
- **Writers**: sym_0602D814 (pc=0x0602D87E, 493x, 441 unique). Also FUN_0602F224 (pc=0x0602F226, 10x).
- **Pipeline**: sym_0602D814 (call 17) computes: `clamp((speed × gear_ratio × 0x0221AC91) >> 32, 0, 0x2134)`. Gear ratio from sym_060477BC[car[+0xDC]]. Max = 8500 (0x2134).
- **CONFIRMED**: Drives the speed convergence feedback loop. FUN_0602CCEC reads `8500 - car[+0xE0]` as force deficit. Braking: drops to 0 when speed = 0.

#### +0xE4 — acceleration_copy?
- **Init**: Not in dump.
- **Writers**: FUN_0602EEC6 (pc=0x0602EF24, 493x, 424 unique).
- **Hypothesis**: Similar cardinality to +0xE0. Written by FUN_0602EEC6 (which also writes +0x50, +0xF8, +0x114, +0x144, +0x252).

#### +0xE8 — gear_speed_headroom (CONFIRMED computation)
- **Init**: Not in dump.
- **Writers**: sym_0602D814 (pc=0x0602D88A, 493x, only 2 unique: 0x0 and 0x212).
- **Pipeline**: sym_0602D814 computes: `max(0, unclamped_scaled - clamped)`. Nonzero only when scaled speed exceeds the 8500 clamp.
- **CONFIRMED**: Always 0 in time-trial captures (speed never reaches clamp at ~30 mph). Would activate at higher speeds in later gears.

#### +0x108 — force_accumulator_a? (THROTTLE PATH)
- **Init**: Not in dump.
- **Writers**: PC 0x0602CB3C (493x, 167 unique) — INSIDE FUN_0602CA84.
- **Pipeline**: Self-accumulated within FUN_0602CA84 (call 15). Written and then read within the same function call. Clamped via FUN_0602755C. Input to final accel delta formula: `(car[+0x108] × A + car[+0x10C] × B - car[+0x114]) × gear >> 8 → car[+0xFC]`.
- **Hypothesis**: Frame-over-frame force accumulator. The throttle signal doesn't arrive as a distinct input — it's accumulated into this field by FUN_0602CA84 itself, reading other car fields that change with throttle. **Explorer next step**: compare +0x108 values frame-by-frame between C-held and idle runs. The DIFFERENCE reveals the throttle contribution.

#### +0x10C — force_accumulator_b? (THROTTLE PATH)
- **Init**: Not in dump.
- **Writers**: PCs 0x0602CBBC, 0x0602CDEC, 0x0602D7E6 — all INSIDE FUN_0602CA84 or its sub-functions (FUN_0602CCF0 is sym_0602CCD0 within the same TU).
- **Pipeline**: Same self-accumulation pattern as +0x108. Together they are the two force components in the final accel delta computation.
- **Hypothesis**: Lateral force component (vs +0x108 longitudinal). Three writer PCs suggest multiple code paths within the force accumulator.

#### +0x114 — animation_lookup?
- **Init**: Not in dump.
- **Writers**: FUN_0602EEC6 (pc=0x0602EF2A, 493x, const 0).
- **Pipeline**: Stage 9 (sym_0602F474) writes +0x114 from a 4-entry lookup table (sym_060477D8) based on car[+0xD4] counter value.
- **Hypothesis**: Animation/display state from a 4-frame cycle. The writer map shows const 0, meaning the counter stayed at one value during capture. Needs varied driving to see all 4 states.

#### +0x11C — energy_or_force?
- **Init**: Not in dump.
- **Writers**: FUN_0602F5EE (pc=0x0602F652, 493x, 185 unique: large values 0x3DD485-0x22xxxxxx).
- **Hypothesis**: Same writer as surface fields (+0xEC/+0xF0/+0xF4) but much more variation. Possibly integrated force from surface interaction.

#### +0x140 — force_magnitude_x (CONFIRMED not position)
- **Init**: Not in dump.
- **Writers**: FUN_0602C690 (pc=0x0602C7F4, 493x, 493 unique — unique every frame).
- **Pipeline**: Computed by FUN_0602C690 (call 13) from orientation (+0x120-12C), track angles (+0x60/64), roll projection (+0x100/104). Read by FUN_0602CA84 (force accumulator, call 15).
- **CONFIRMED NOT POSITION**: Dual-position NOP test showed identical values with/without position writer. Computed from speed/heading/surface, not from position.

#### +0x144 — force_magnitude_z (CONFIRMED not position)
- **Init**: Not in dump.
- **Writers**: FUN_0602C690 (pc=0x0602EF42, 493x, 493 unique).
- **Pipeline**: Paired with +0x140. Same evidence from dual-position NOP test.
- **CONFIRMED NOT POSITION**: Identical between NOPped and baseline runs.

#### +0x148 — rotation_accumulator?
- **Init**: Not in dump.
- **Writers**: FUN_0602CA88 (pc=0x0602CAE0, 493x, 490 unique).
- **Hypothesis**: Nearly unique each frame. High cardinality continuous value.

#### +0x154 — smoothed_heading?
- **Init**: Not in dump.
- **Writers**: FUN_0602CE4E (pc=0x0602CF18, 493x, 286 unique).
- **Hypothesis**: Written by same function as +0x28 (slip angle) and +0x30 (heading delta). Moderate cardinality = smoothed/filtered value.

#### +0x178 — lateral_force (CONFIRMED — modified by FUN_0602D43C)
- **Init**: Not in dump.
- **Writers**: FUN_0602D5F8 (pc=0x0602D63A, 493x, 271 unique).
- **Pipeline**: FUN_0602D43C reads and modifies. Constant -1 at idle, 47 unique values with throttle. Lateral force component.
- **CONFIRMED**: Lateral force field, updated by collision+steering response.

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

#### +0x252 — drift_counter_copy? (16-bit, CONFIRMED copy of +0x250)
- **Init**: Not in dump.
- **Writers**: FUN_0602EEC6 (pc=0x0602EED4 actual, profiler says 0x0602EED8). 16-bit `mov.w` write.
- **CONFIRMED**: Assembly at 0x0602EECE-0x0602EED4 reads car[+0x250] then writes it to car[+0x252]. Values 0-9 match +0x250's 0-10 range (lagged copy). 16-bit field — invisible to 4-byte watchpoints.

#### +0x250 — drift_counter? (16-bit)
- **Init**: Not in dump.
- **Writers**: FUN_06030848 (pc=0x06030848, 2x, const 0xA) + FUN_06030A1C (2x, const 0) + FUN_06030A3C (18x, values 1-9).
- **Pipeline**: sym_0602D8BC (call 19) branches on `car[+0x250] != 0`:
  - If 0: normal heading-based velocity integration
  - If nonzero: drift/rotation path using lookup table at 0x0602E8B8 indexed by this value
- **Hypothesis**: Drift mode intensity counter (0-10). 0 = normal driving. 1-10 = drift with table-scaled rotation. Set to 0xA (10) to start drift, counts down.

#### +0x258 — heading_divergence_counter (OBSERVED)
- **Init**: Not in dump.
- **Writers**: FUN_0602D054 (pc=0x0602D05A, 230x, 84 unique) + FUN_0602D07C (pc=0x0602D086, 263x, const 0).
- **Pipeline**: FUN_0602CDF6 (call 17) increments when `|car[+0x30] - car[+0x25C]| > 0x0444` (heading diverged from target by >6°). Zeroed when heading converges. Constant 0 at idle, 89 unique with throttle.
- **OBSERVED**: NOT a collision counter — it's a heading divergence detector.

#### +0x25C — computed_angle?
- **Init**: Not in dump.
- **Writers**: FUN_06027E9E (pc=0x06027EB0, 493x, 50 unique).
- **Hypothesis**: Moderate cardinality (50). Written by orientation matrix function.

#### +0x264 — continuous_physics?
- **Init**: Not in dump.
- **Writers**: FUN_0602CCF0 (pc=0x0602CD70, 470x, 465 unique).
- **Hypothesis**: Nearly unique each frame. Written by a physics computation function.
