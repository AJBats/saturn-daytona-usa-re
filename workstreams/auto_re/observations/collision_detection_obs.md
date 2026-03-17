---
function: Collision detection system
explored: 2026-03-16
scenarios_tested: [race_throttle, race_right_wall, tt_right_wall_strike]
reachable: false (car[+0x04] never becomes nonzero)
---

## Phase 3: Collision Detection — BLOCKED

### car[+0x04] Never Changes in Any Test Scenario

| Scenario | Frames | +0x04 | +0xB8 | +0x9E |
|----------|--------|-------|-------|-------|
| Race mode, C held, 300 frames | 300 | always 0 | always 0 | always 0 |
| Race mode, C+RIGHT (wall), 200 frames | 200 | always 0 | always 0 | N/A |
| Time trial, C+RIGHT (wall strike), 662 frames | 662 | always 0 | always 0 | always 0 |

### Conclusion: Wall Collision Does NOT Set These Fields

car[+0x04] (collision target), car[+0xB8] (collision gate), and car[+0x9E]
(alternate collision path flag) are all for **car-to-car collision only**.
Wall collisions produce physical effects (speed reduction, heading change,
position bounce) but do NOT set these fields.

The collision detection code that sets +0x04 likely runs in the shared
physics section and triggers only when two cars overlap. To exercise it,
a controlled car-to-car collision is needed — which is difficult to set
up in the emulator without a specialized save state.

### Recommendation

Ask the human to create a save state where the player car is about to
hit an AI car head-on, then replay with sample_memory to catch the
collision frame.

Alternatively: the collision RESPONSE code (FUN_0602C690 through
FUN_0602CA84, calls 13-15) already has observations. The detection
code's output (+0x04) feeds into these response functions. For the
transplant, the response code is already mapped — the detection code
can be traced later when car-to-car collision is exercisable.
