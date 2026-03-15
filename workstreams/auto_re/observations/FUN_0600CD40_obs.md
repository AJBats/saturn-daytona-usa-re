---
function: FUN_0600CD40
address: 0x0600CD40
address_end: ~0x0600CDCE
source_file: reimpl/src/FUN_0600CD40.s
explored: 2026-03-15
scenarios_tested: [straight_throttle]
reachable: true
---

## Call Frequency

| Scenario | Calls/Frame | Notes |
|----------|-------------|-------|
| straight_throttle | 1 | Called OUTSIDE player pipeline, from 0x0600CE82 |

## Key Finding: Track Segment System is Separate from Player Pipeline

FUN_0600CD40 is called from the shared track system (call chain through
0x0600E640 → 0x0600CE82 → FUN_0600CD40), NOT from the player physics
dispatcher (FUN_0602EEB8). It runs for each car (player + AI) via the
iteration loop.

**R14 = 0x06078900** (player car pointer) at breakpoint, confirming it
processes the player car. But it's called from the shared code path,
not from the 18-call player pipeline.

## Field Access (from Static Analysis)

### Reads

| Offset | Notes |
|--------|-------|
| +0x1E4 | Track segment index. Used to index into track geometry table |
| +0x238 | Track data pointer. Points to segment geometry arrays |
| +0x10 | Position X (via offset computation) — **reads rendered position** |
| +0x18 | Position Z (implied by paired computation) |

### Writes

| Offset | Notes |
|--------|-------|
| +0x184 | Track segment data (property from table[+0x16]) |
| +0x1E4 | Track segment index (advanced when crossing boundary) |

## Relationship to Dual Position Finding

The cycle 23 NOP test confirmed: when sym_0602D8BC is NOPped (position frozen),
track segment fields (+0x184, +0x1E4, +0x1E8, +0x1EC, +0x1F0, +0x1F4) all
freeze. This is because FUN_0600CD40 **reads car[+0x10]** (rendered position)
to determine segment boundaries.

Since this function is OUTSIDE the player pipeline, the pipeline itself doesn't
depend on track segment state for its physics computation. The segments feed
into the rendering and AI systems, not back into the player physics.

## Per-Frame Field Analysis

| Offset | Idle | Throttle | Category |
|--------|------|----------|----------|
| +0x184 | constant | 3 unique | input-responsive (changes with segment) |
| +0x1E4 | constant 5 | 4 unique (5→8) | input-responsive (advances with speed) |

Track segment index starts at 5 and advances to 8 over 200 frames of
throttle. Each segment advance happens ~30-50 frames apart at ~30 mph.

## Other Observations

- The function uses sym_0607E940 (current car pointer) — it re-loads the
  car pointer from the global, supporting iteration over all cars.
- The track geometry is in a table accessed via car[+0x238] with segment
  entries of 24 bytes each (computed via shll2 + shll + add operations).
- FUN_06027344 (atan2/trig) is called to compute angle between car
  position and segment boundaries.
