---
function: sym_0602D8BC (NOP test)
address: 0x0602D8BC
explored: 2026-03-15
scenarios_tested: [baseline_throttle_200f, nopped_poswriter_200f]
reachable: true
---

## Experiment: NOP sym_0602D8BC to Find Physics-Internal Position

Per Phase 2 Priority 2. NOP the position writer JSR at 0x0602EF9E
(`poke 0602EF9E 00 09`), hold C for 200 frames, compare full car struct
against un-NOPped baseline.

## Results

### Position fields: FROZEN (confirmed)

| Offset | NOP (200f) | Baseline (200f) | Notes |
|--------|-----------|-----------------|-------|
| +0x10 | FROZEN (8750591) | 65 unique | Position X |
| +0x18 | FROZEN (9587149) | 1 unique | Position Z (no lateral movement) |
| +0x20 | FROZEN (16381) | 1 unique | Heading (straight line) |
| +0x38 | FROZEN (8750591) | 64 unique | Saved position X |
| +0x3C | FROZEN (9587149) | 1 unique | Saved position Z |
| +0x18C | FROZEN (0) | 65 unique | Velocity X |
| +0x190 | FROZEN (0) | 1 unique | Velocity Z |

### Physics fields: ALL IDENTICAL between NOP and baseline

Every non-position field that changes during throttle produces **exactly
the same values** in both the NOPped and baseline runs:

| Offset | NOP unique | Base unique | Match? |
|--------|-----------|-------------|--------|
| +0x0C (speed) | 65 | 65 | IDENTICAL |
| +0xFC (accel delta) | 62 | 62 | IDENTICAL |
| +0xE0 (gear speed) | 65 | 65 | IDENTICAL |
| +0x108 (force X) | — | — | IDENTICAL |
| +0x110 (force term) | 48 | 48 | IDENTICAL |
| +0x140 (world coord) | 68 | 68 | IDENTICAL |
| +0x144 (world coord) | 68 | 68 | IDENTICAL |
| +0x258 (coll counter) | 68 | 68 | IDENTICAL |
| +0x74 (throttle) | 12 | 12 | IDENTICAL |
| +0x48 (drag) | 61 | 61 | IDENTICAL |
| +0x50 (drag) | 61 | 61 | IDENTICAL |

### Track segment fields: FROZEN (depend on position)

| Offset | First Diff Frame | NOP unique | Base unique | Notes |
|--------|-----------------|-----------|-------------|-------|
| +0x184 | 109 | 1 (frozen) | 3 | Track segment data |
| +0x1E4 | 106 | 1 (frozen) | 4 | Track segment index |
| +0x1E8 | 109 | 1 (frozen) | 3 | Track data |
| +0x1EC | 109 | 1 (frozen) | 3 | Track progress |
| +0x1F0 | 112 | 1 (frozen) | 3 | Track progress B |
| +0x1F4 | 109 | 1 (frozen) | 3 | Track speed |

These diverge at frame ~106-112 when the baseline car crosses a track
segment boundary. The NOPped car never crosses (position frozen), so
track segments stay constant.

## KEY FINDING: No Dual Position System

**The "physics-internal position" theorized by the human does NOT exist
in the car struct.** The evidence:

1. **ALL physics fields are identical** whether position is updated or not.
   Speed, force, drag, heading, surface energy, world coordinates — every
   field evolves the same way in both runs.

2. **The player physics pipeline does NOT read car[+0x10/+0x18].** Position
   is a write-only output computed at the end of the pipeline (call 19).
   No upstream pipeline stage reads it.

3. **+0x140/+0x144 are NOT internal position.** They match exactly between
   NOP and baseline. They're computed from speed/heading/surface data, not
   from position.

4. **Track segment system reads position.** The 0x0600xxxx shared code
   (FUN_0600CD44, not in the player pipeline) reads +0x10 for segment
   advance. When position freezes, segments freeze. This is the only
   consumer of rendered position.

## What the Human Observed

The NOP test showed "surface changed as if car was moving." This is
explained by the track segment system freezing at frame ~106. Before
that frame, all surface data is identical. After frame 106, the NOPped
car's surface state stops advancing (track segments frozen), but the
baseline car's continues. The human likely tested past frame 106 where
the divergence in surface behavior becomes visible.

The "acceleration behavior changed" observation is consistent with the
track segment freeze — the gear ratio table (sym_060477BC) is indexed
by +0xDC which depends on +0xE0 which depends on +0x0C (speed), not
on position. But surface properties (+0xF4, +0x1FC) may feed into the
force accumulator differently once track segments stop advancing.

### Sample captures
- `build/samples/tt_baseline_200f.csv` — un-NOPped, C held
- `build/samples/tt_nopped_poswriter_200f.csv` — position writer NOPped
