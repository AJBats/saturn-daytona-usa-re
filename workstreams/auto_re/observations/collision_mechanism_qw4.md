---
function: N/A (collision mechanism investigation QW4)
explored: 2026-03-17
scenarios_tested: [car_graze_replay]
reachable: N/A
---

## QW4: Collision Mechanism — Proximity and Surface Buffer Analysis

### car[+0xD6] (Proximity Counter)

The proximity counter starts at 0x14 (20) at frame 0 — the AI car is
ALREADY within proximity range at race start (position 40/40, surrounded
by AI cars). It counts down at ~1 per 3 physics frames (20→5 over 120f).

**The graze does NOT re-trigger proximity.** The counter just keeps
counting down monotonically through the contact window (frames 98-110).
No spike, no reset. sym_0602F4B4 (call 10) detects proximity but doesn't
react to actual physical contact — it's a proximity COOLDOWN, not a
collision detector.

### sym_06078680 (Surface Buffer)

First 4 words monitored across 120 frames:

| Frame | +0x00 | +0x04 | +0x08 | +0x0C |
|-------|-------|-------|-------|-------|
| 0 | 0x00B00000 | 0 | 0x008A8000 | 0x00004000 |
| 98 | 0x00400000 | 0 | 0x008A8000 | 0x00004000 |
| 101 | 0x00400000 | 0 | 0x008A8000 | 0x00004000 |
| 110 | 0x00300000 | 0 | 0x008A8000 | 0x00004000 |

The first word decreases smoothly (track curvature/position change), no
collision-specific disruption. Words +0x04-+0x0C are stable. The surface
buffer is NOT perturbed by the car-to-car contact.

### Conclusion

The car-to-car graze produces physical effects (roll, heading jolt) through
the EXISTING physics pipeline running on overlapping car geometries. There is:
- No collision flag set (+0x04, +0x9E, +0xB8 all stay 0)
- No proximity re-trigger (+0xD6 keeps counting down)
- No surface buffer disruption (smooth changes only)

The collision is **emergent from shared physics space**, not from an explicit
detection mechanism. Each car's physics computes forces based on track
geometry and car state — when two cars overlap, the forces naturally
produce the collision-like behavior (roll spike, heading change, speed loss).
