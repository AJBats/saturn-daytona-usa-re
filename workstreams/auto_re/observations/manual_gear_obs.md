---
function: sym_0602FDA4 (manual gear input)
address: 0x0602FDA4
explored: 2026-03-16
scenarios_tested: [manual_trans_race]
reachable: true
---

## Experiment 2: Manual Gear Writer for +0xDC

### CORRECTED Result: +0xDC and +0xDE Change TOGETHER on Gear Shift

Initial experiment (cycle 36) used an undocumented save state starting at
gear 3 / ~179 mph — both fields were already at max, masking the behavior.
Re-run with properly documented `usa_tt_manual_straight.mc0` (dead stop,
gear 0) shows the correct behavior.

**Replayed scenario**: C held from standstill, DOWN tapped at frames 190,
337, 494 (matching human's recorded input trace).

| Point | Frame | Speed (mph) | +0xDC | +0xDE | Event |
|-------|-------|-------------|-------|-------|-------|
| Start | 0 | 0 | 0 | 0 | C held |
| Pre-shift 1 | 189 | 62.7 | 0 | 0 | |
| Post-shift 1 | 194 | 61.3 | 1 | 1 | DOWN tap |
| Pre-shift 2 | 337 | 104.1 | 1 | 1 | |
| Post-shift 2 | 342 | 102.1 | 2 | 2 | DOWN tap |
| Pre-shift 3 | 494 | 130.6 | 2 | 2 | Early shift |
| Post-shift 3 | 500 | 131.3 | 3 | 3 | DOWN tap |

### Key Findings (Corrected)

1. **+0xDC and +0xDE change TOGETHER** on every manual gear shift. DOWN
   writes +0xDE, and +0xDC follows immediately — either the DOWN handler
   also writes +0xDC, or sym_0602F17C's threshold system detects the gear
   change within the same frame and updates +0xDC to match.

2. **DOWN = upshift** in Daytona USA manual transmission.

3. **Speed drops slightly on upshift** (62.7→61.3, 104.1→102.1 mph).
   Consistent with the gear ratio change affecting the speed→force
   computation — higher gear = lower ratio = momentary speed adjustment.

4. **Shift 3 was early** (human shifted at 130 mph to reach 4th gear
   before wall strike). This produces a different RPM pattern than auto
   transmission would choose via thresholds.

### +0xDE → +0xDC Link: CONFIRMED (Synchronized)

The cycle 36 conclusion that these are "independent systems" was WRONG —
that was an artifact of testing at max gear where both were already 3.
From a clean start, **they move in lockstep on every shift.**

### Save State Used
- `usa_tt_manual_straight.mc0`
- Mode: Time Trial, solo, Three Seven, manual transmission, 0 mph dead stop
