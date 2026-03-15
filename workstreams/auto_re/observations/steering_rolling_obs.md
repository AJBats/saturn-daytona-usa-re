---
function: N/A (scenario observation)
address: N/A
explored: 2026-03-15
scenarios_tested: [rolling_steer_left]
reachable: N/A
---

## Scenario: Steering at Rolling Speed

Requested by Mapper in Phase 2 Priority 3.

**Setup**: usa_tt_straight.mc0, hold C for 200 frames (~65 mph), then
hold C+LEFT for 300 frames. Car decelerates from 65→22 mph while turning.

## Steering Response at 65 mph

| Offset | f0 | f100 | f299 | Unique | Notes |
|--------|------|------|------|--------|-------|
| +0x0C | 96612 (65 mph) | 46697 (31 mph) | 33198 (22 mph) | 101 | Speed drops — cornering drag or wall |
| +0x20 | 16381 | 24974 | 17394 | 100 | **Heading changes visibly** |
| +0x28 | 16383 | 22999 | 17008 | 62 | Slip angle changes |
| +0x10 | 5923407 | 3568899 | 1528275 | 101 | Position X changes (turning) |
| +0x18 | 9587149 | 8950114 | 8858336 | 92 | Position Z changes |
| +0xAC | 0 | -106 | -106 | 23 | **Same as throttle-only!** |
| +0xB0 | 0 | -127 | -127 | 10 | Same as throttle-only |
| +0x58 | 2 | -4090 | -2930 | 68 | Steering input — more active than standstill |
| +0x5C | 1 | -3784 | -1932 | 71 | Steering accumulator — more active |

## Key Findings

1. **Steering IS visible at 65 mph.** Heading (+0x20) has 100 unique values
   (vs 101 with throttle-only, but DIFFERENT values). The car is turning.

2. **car[+0xAC] does NOT respond to LEFT d-pad.** It shows the same 23 unique
   values and same values (-106 at f100) as idle and throttle-only. The D-pad
   LEFT button does NOT write to +0xAC. This contradicts the FUN_0602EFF0
   observation which identified +0xAC as "raw steering input" — it IS the
   steering input but is NOT set by the d-pad directly. The d-pad may affect
   +0xAC through a separate input processing stage OUTSIDE the player pipeline.

3. **+0x58 and +0x5C respond to steering at speed.** +0x58 goes to -4090
   (vs -4090 range in throttle-only but with DIFFERENT trajectory). +0x5C
   goes to -3784 (much larger magnitude than throttle-only's -2930).

4. **Speed drops during LEFT turn** — from 65→22 mph in 300 frames. Either
   cornering drag or wall collision reduces speed. The save state straightaway
   is finite and the car may hit the corner wall during the turn.

## Steering Threshold

From standstill (0 mph): steering has ZERO effect for 300+ frames.
At 65 mph: steering produces visible heading changes immediately.
The threshold is somewhere between 0 and 65 mph. The gate condition
in FUN_0602D43C (call 16a) requires speed index > 240 (~213 mph
equivalent) — but this seems too high. The actual steering effect
may come through a different mechanism than FUN_0602D43C's heading
correction path.

### Sample captures
- `build/samples/tt_rolling_steer_left_300f.csv` — C+LEFT from ~65 mph
