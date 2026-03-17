---
function: FUN_0600E0C0 (AI pipeline deep trace)
address: 0x0600E0C0
explored: 2026-03-16
scenarios_tested: [race_throttle_40_cars]
reachable: true
---

## Phase 2: AI Pipeline — Full Call Sequence

PC trace from FUN_0600E0C0 entry in race mode (40 cars, daytona_rebuilt
save state). 228,196 PCs, C held.

### AI Car Call Sequence (per car, 39 iterations)

Each AI car (cars 1-39) receives this exact call sequence:

```
FUN_0600E71A  — AI normal pipeline entry
    ↓
FUN_0600C4F8  — speed/acceleration calculator
    ↓
FUN_0600C5D6  — steering/force dispatcher
    ↓
FUN_0600CD40  — track segment detail (position → segment)
    ↓
FUN_0600CA96  — friction/drag computation
    ↓
FUN_0600C8CC  — heading calculator
    ↓
FUN_0600C928  — heading correction
    ↓
[OPTIONAL] FUN_0600C7D8  — heading/speed damping (3 out of 39 cars)
    ↓
FUN_0600CEBA  — track segment advance
```

### Call Counts

| Function | Calls/Frame | Per Car | Notes |
|----------|------------|---------|-------|
| FUN_0600E71A | 39 | 1 | Every AI car gets normal pipeline |
| FUN_0600C4F8 | 39 | 1 | Speed computation |
| FUN_0600C5D6 | 39 | 1 | Steering/force |
| FUN_0600CD40 | 39 | 1 | Track segment |
| FUN_0600CA96 | 39 | 1 | Friction/drag |
| FUN_0600C8CC | 39 | 1 | Heading |
| FUN_0600C928 | 39 | 1 | Heading correction |
| FUN_0600C7D8 | 3 | 0.08 | **Conditional** — only fires for some cars |
| FUN_0600CEBA | 39 | 1 | Track segment advance |

### Key Finding: FUN_0600C7D8 Is Conditional

Only 3 of 39 AI cars trigger FUN_0600C7D8 (heading/speed damping).
Static analysis says this fires when car is airborne (checks flags &
0x00E00000). This means ~3 AI cars are in an airborne state at the
race start position.

### AI vs Player Pipeline Comparison

| Step | AI Function | Player Equivalent | Notes |
|------|------------|-------------------|-------|
| Speed | FUN_0600C4F8 | sym_0602D814 (call 18) | Both read/write +0x0C |
| Steering | FUN_0600C5D6 | FUN_0602D43C (call 16a) | AI is simpler |
| Track | FUN_0600CD40 | same function (shared!) | Position → segment |
| Friction | FUN_0600CA96 | FUN_0602F5B6 (call 11) | Both write surface fields |
| Heading | FUN_0600C8CC | FUN_0602CDF6 (call 17) | AI heading simpler |
| Heading fix | FUN_0600C928 | embedded in calls 13-16 | AI uses separate func |
| Damping | FUN_0600C7D8 | sym_0602F3EC (call 4) | Both touch +0x48/+0x50 |
| Segment adv | FUN_0600CEBA | same function (shared!) | Track boundary check |

**Two functions are SHARED between AI and player**: FUN_0600CD40 (track
segment detail) and FUN_0600CEBA (track segment advance). These must be
in the physics box.

### AI Pipeline PC Budget

- Total AI PCs: ~30,000 (39 cars × ~770 PCs each)
- Per-car cost: ~770 PCs = ~0.3% of frame per AI car
- Total AI cost: ~12% of frame (vs player pipeline at 0.8%)

### FUN_0600E906 (AI Alt Pipeline)

NOT triggered in this capture (0 calls). This alternate AI pipeline
requires sym_0607EBC4 bit 15 to be set. In normal racing, all AI
cars use FUN_0600E71A (normal pipeline).
