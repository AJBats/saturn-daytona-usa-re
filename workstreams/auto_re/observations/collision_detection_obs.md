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

### Car Graze Replay (2026-03-17) — Full Struct Comparison

Used input_playback to deterministically replay the car graze scenario
(daytona_rebuilt_car_graze.input.txt) with full 616-byte car struct
sampling. Compared against straight-throttle baseline (no steering).

### Collision Impact Fields (abrupt spikes at frames 98-113)

| Field | Frame | Spike | Normal Avg | Notes |
|-------|-------|-------|-----------|-------|
| +0x24 (roll) | 101 | 46x | 12/frame | Car body rolls from impact |
| +0x104 (cos roll) | 104 | 205x | 3/frame | Trig output of roll change |
| +0x100 (sin roll) | 104 | 48x | 76/frame | Same — roll→sin/cos |
| +0xB0 (steer rot) | 110 | 85x | 1/frame | Steering disrupted |
| +0xB4 (prev steer) | 113 | 104x | 1/frame | Previous rotation jolted |
| +0x60/+0x64 | 110 | 33x | 3.5M/frame | Track angles — heading jolted |
| +0x5C (steer accum) | 113 | 34x | 9/frame | Steering accumulator spike |
| +0xF4 (terrain) | 107 | 21x | 27K/frame | Surface contact change |
| +0x1FC (surface idx) | 107 | 11x | 22/frame | Surface type changed |

### Key Finding: No Collision Detection Flags Set

**car[+0x04] and car[+0x9E] remain ZERO throughout the entire graze.**
The car-to-car contact produces physical effects (roll, heading jolt,
steering disruption) through the EXISTING physics pipeline — not through
a dedicated collision detection system. The graze works via:

1. Two cars' physics overlapping in space
2. The track segment / surface system detecting the changed geometry
3. Forces propagating through the normal force accumulator pipeline

This suggests Daytona USA uses **implicit collision** through the physics
simulation rather than explicit collision detection for car-to-car contact.
The +0x04 field may only be set during MAJOR collisions (head-on, high-speed
impact) or may serve a different purpose entirely.
