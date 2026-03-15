---
function: FUN_0602D08A (pipeline call 16b — alternate collision)
address: 0x0602D08A
explored: 2026-03-15
scenarios_tested: [right_wall_strike, race_left_steer]
reachable: false (in tested scenarios)
---

## Reachability: NOT TRIGGERED in Any Test Scenario

car[+0x9E] stays 0 across ALL tested scenarios:
- Wall strike (C+RIGHT, 662 frames, time trial) — 0 throughout
- Race mode (C+LEFT, 300 frames, 40 AI cars) — 0 throughout

The dispatcher conditional at car[+0x9E] was ALWAYS zero, meaning
FUN_0602D43C (call 16a) was always selected, never FUN_0602D08A (16b).

## Possible Triggers for +0x9E != 0

1. **Car-to-car collision at high speed** — the race save state starts at
   ~179 mph among 39 AI cars. Sustained driving might produce a direct hit.
2. **Specific collision geometry** — head-on or T-bone rather than glancing.
3. **Damage state** — may require accumulated collision damage before +0x9E
   activates an alternate physics path.

## What We Know About FUN_0602D08A

From the cycle 1 PC trace: FUN_0602D08A appeared at idx=1632 via
**fall-through from FUN_0602CDF6** (call 17, state finalize), NOT as a
separate dispatcher call. The dispatcher's conditional selected call 16a
(FUN_0602D43C), but FUN_0602D08A's address was reached sequentially from
FUN_0602CDF6's code body.

When +0x9E becomes nonzero, the dispatcher would call FUN_0602D08A via
`jsr @r12` instead of FUN_0602D43C via `jsr @r13`. This is the only
untested pipeline path.

## Recommendation

To trigger +0x9E, try:
- Load race save state, hold C (no steering) for 200+ frames — at ~179 mph
  the car should hit AI cars ahead on the narrow track
- Or create a save state at a corner where collision is guaranteed
