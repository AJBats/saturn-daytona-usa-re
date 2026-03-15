---
function: N/A (scenario observation)
address: N/A
explored: 2026-03-15
scenarios_tested: [throttle_then_brake]
reachable: N/A
---

## Scenario: Sustained Braking from Speed

Requested by Mapper in explorer_priorities.md "Scenario Requests" section.

**Setup**: usa_tt_straight.mc0, hold C for 750 frames (~27 mph), release C,
hold B (brake) for 300 frames. Car decelerates from ~27 mph to 0 by ~frame 100.

## Brake-Specific Fields

Fields that change ONLY during braking (static during throttle-only):

| Offset | Throttle (300f) | Brake (300f) | Notes |
|--------|----------------|-------------|-------|
| +0x8C | constant 56 | 5 values: 56→216 | Brake state? (struct map says "collision_state_a") |
| +0x90 | constant 56 | 5 values: 56→216 | Brake state? (struct map says "collision_recovery_param") |

Both +0x8C and +0x90 have identical values (56→216) during braking. They're listed
in the struct map as collision-related, but this observation suggests they may be
brake-related or dual-purpose (collision+brake share the same state mechanism).

## Throttle-Only Fields (inactive during braking)

| Offset | Throttle | Brake | Notes |
|--------|----------|-------|-------|
| +0x40 | 19 unique | constant -4064 | Only active during acceleration |

## Deceleration Curve

| Frame | Speed (+0x0C) | Accel (+0xFC) | mph |
|-------|---------------|---------------|-----|
| 0 | 39574 | -68 | 27.0 |
| 10 | 36622 | -208 | 25.0 |
| 20 | 32530 | -303 | 22.2 |
| 50 | 14316 | -278 | 9.8 |
| 80 | 1372 | -51 | 0.9 |
| 100 | 0 | 0 | 0.0 |

Braking produces a smooth deceleration from 27 mph to 0 in ~100 frames.
The accel delta (+0xFC) peaks at ~-300 around frame 20, then decreases
in magnitude as speed drops. This is consistent with speed-dependent braking
force (stronger at higher speed, weaker near stop).

## Force Pipeline During Braking

| Offset | Brake f0 | Brake f100 | Brake f299 | Notes |
|--------|----------|-----------|-----------|-------|
| +0x108 | 30194 | 50344 | 50201 | INCREASES toward 65536 (force restored as speed drops) |
| +0x10C | 11141 | 45691 | 46014 | Same pattern |
| +0x110 | 20669 | -1422 | -1422 | Decreases as +0xE0 → 0 |
| +0xE0 | 3036 | 0 | 0 | Track force → 0 when stopped |
| +0x114 | 26214400 | 0 | 0 | Resistance term clears when stopped |

The force pipeline reverses during braking: +0x108/+0x10C increase back toward
their maximum (65536) as speed decreases, +0x110 and +0xE0 drop to zero. The
system returns to its "at rest" state.

### Sample captures
- `build/samples/tt_brake_300f.csv` — B held from ~27 mph, 300 frames
