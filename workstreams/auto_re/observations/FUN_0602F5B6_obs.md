---
function: FUN_0602F5B6
address: 0x0602F5B6
address_end: ~0x0602F6E0
source_file: reimpl/src/FUN_0602F5B6.s
explored: 2026-03-15
scenarios_tested: [straight_throttle, offtrack_throttle]
reachable: true
---

## Call Frequency

| Scenario | Calls/Frame | Notes |
|----------|-------------|-------|
| straight_throttle | 1 | Pipeline call 11 in FUN_0602EEB8 |
| offtrack_throttle | 1 | Same |

## Per-Frame Field Analysis

Captures: `tt_throttle_300f.csv` (on-track, C held, 300f) and
`tt_offtrack_throttle_566f.csv` (off-track, C held, 566f, grass at ~frame 109).

### Surface Fields: +0xEC, +0xF0, +0xF4, +0xF8

| Offset | On-Track (300f) | Off-Track (566f) | Category |
|--------|-----------------|------------------|----------|
| +0xEC | constant 0 | constant 0 | static (flat track) |
| +0xF0 | constant 0 | constant 0 | static (flat track) |
| +0xF4 | 3 unique (0, 240800) | 41 unique (-2893600 to +2652800) | surface-dependent |
| +0xF8 | 35 unique (524288→843954) | monotonic increase | track-progress |

**+0xEC, +0xF0 are zero across both scenarios.** The struct map hypothesized
"surface normal" components with 5 discrete values — those values come from the
comprehensive writer map (race mode, 40 cars). On flat Three Seven Speedway in
time trial, the surface normals are zero. These fields likely populate only on
banked or vertically varied track sections. The 5 unique values in the writer
map may correspond to the few elevation changes on Three Seven during a full race.

**+0xF4 is highly surface-dependent:**
- On-track: nearly zero (3 unique values over 300 frames)
- Off-track: oscillates wildly between -2.9M and +2.7M (41 unique values)

This is NOT a surface friction coefficient (those would be small positive values).
The large magnitude and sign oscillation suggest a terrain slope or lateral force
component. The car on grass experiences significant lateral forces that don't
occur on flat road.

**+0xF8 increases monotonically** from 524288 (0x80000) with speed. Consistent
with track progress or accumulated distance. Not surface-dependent — increases
the same way on both road and grass.

### Surface Index: +0x1FC

| Scenario | Values | Notes |
|----------|--------|-------|
| On-track (tt_straight) | 0x300 → 0x400 → 0x500 | Changes with track segments |
| Off-track (tt_offtrack) | constant 0x600 | Car starts on/facing grass |

**+0x1FC is a surface type index.** The on-track scenario shows 3 values
(0x300, 0x400, 0x500) that change as the car moves through track segments.
The off-track scenario shows constant 0x600 — the grass surface type. The
struct map lists 6 unique values total (0x0, 0x200, 0x300, 0x400, 0x500, 0x600),
which may represent: unknown, unknown, road type A, road type B, road type C, grass.

The car starts facing grass in the offtrack save state, so +0x1FC = 0x600 from
frame 0. There's no surface TRANSITION visible in this capture — the car was
already on grass. To observe the transition moment, a save state starting ON
the road and driving ONTO grass would be needed.

### Speed Response to Surface

| Frame | Speed (mph) | Accel Delta | Notes |
|-------|-------------|-------------|-------|
| 0 | 0.0 | 0 | Dead stop on grass |
| 100 | 27.5 | +1237 | Accelerating on grass |
| 150 | 31.8 | -41 | Speed cap approached |
| 300 | 29.6 | -45 | Oscillating around cap |
| 565 | 25.3 | -70 | Slowly decelerating |

On grass (+0x1FC = 0x600), the car reaches ~32 mph then the accel delta goes
negative — the surface limits speed. On road, the same save state position
(tt_straight) shows continuous acceleration past 30 mph. The speed cap mechanism
likely works through the force accumulator (FUN_0602CA84) reading surface
properties.

### Sample captures
- `build/samples/tt_throttle_300f.csv` — on-track baseline
- `build/samples/tt_offtrack_throttle_566f.csv` — off-track, C held, 566 frames

## Other Observations

- FUN_0602F5B6 (pipeline call 11) is the surface writer. It falls through into
  FUN_0602F5EE which does the actual field writes (+0xEC, +0xF0, +0xF4, +0x11C).
  The surface index +0x1FC is written by a DIFFERENT function (FUN_0600C9EA at
  PC 0x0600CA84) that's NOT in the player pipeline — it's in the AI/shared
  track system.
- The +0x11C field (written by FUN_0602F5EE) shows large values (~130M) that
  increase with speed and track position. It may be accumulated surface force
  energy or a world-space coordinate.
