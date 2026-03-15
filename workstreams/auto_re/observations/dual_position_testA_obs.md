---
function: sym_0602D8BC (NOP test A — camera rotation proof)
address: 0x0602D8BC
explored: 2026-03-15
scenarios_tested: [nopped_poswriter_steer_left]
reachable: true
---

## Test A: Camera Rotation Source During Position NOP

Per Phase 2 Priority 2 sub-test A. NOP sym_0602D8BC, hold C+LEFT for
400 frames, check if heading (+0x20) changes.

## Result: Heading FROZEN, Slip Angle CHANGED

| Field | Before | After 400f C+LEFT | Changed? |
|-------|--------|-------------------|----------|
| +0x20 (heading) | 16381 | 16381 | **NO — FROZEN** |
| +0x28 (slip angle) | 16383 | -18830 | **YES — changed by 35213** |
| +0x10 (position X) | 8750591 | 8750591 | NO — frozen (NOP working) |
| +0x0C (speed) | 0 | 40953 (28 mph) | YES — throttle works |

## Key Finding

**sym_0602D8BC writes +0x20 (heading).** When NOPped, heading freezes along
with position. The human's observation of "camera rotation around the frozen
car" is NOT from heading — it's from **car[+0x28] (slip angle)**, which is
written by FUN_0602CDF6 (call 17, state finalize), NOT by sym_0602D8BC.

The rendering system reads BOTH +0x20 (heading) and +0x28 (slip angle) for
camera orientation. When +0x20 is frozen but +0x28 continues evolving, the
camera still rotates — tracking the slip angle, not the heading.

## Dependency Chain

```
sym_0602D8BC writes: +0x10, +0x18, +0x20, +0x38, +0x3C, +0x18C, +0x190
                     ^^^^^^^^^^^^  ^^^^
                     position      heading — ALL FROZEN when NOPped

FUN_0602CDF6 writes: +0x28, +0x30, +0x60, +0x64, +0x258
                      ^^^^
                      slip angle — NOT FROZEN (different writer)
```

The camera uses +0x28 (slip angle) for its rotation when +0x20 (heading)
is frozen, producing the "rotation around frozen car" effect.

## Speed Behavior Note

Speed at frame 400 was 28 mph (down from 30 mph at frame 200). The car
decelerates slightly with C+LEFT held — consistent with the force pipeline
receiving stale heading data (frozen +0x20 means the velocity direction
in sym_0602D8BC never updates, but that function is NOPped so the staleness
is academic — speed still evolves normally via the force pipeline).
