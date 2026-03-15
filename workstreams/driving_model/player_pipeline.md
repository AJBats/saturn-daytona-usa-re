# Player Physics Pipeline — Static Call Tree

**Source: Static analysis only (ASM source + Ghidra decompilation).**
NOT validated with the emulator. This is an experiment-design artifact for
the Explorer to validate via call_trace.

Corresponds to Phase C2 of `boundary_mapping_plan.md`.

## Entry Point

FUN_0602EEB8 — player physics main dispatcher.
Called once per frame for car[0] (player) only.
Car pointer loaded from `sym_0607E944`.

The AI car loop (FUN_0600e0c0, cars 1..N) uses a completely separate
pipeline (FUN_0600e71a / FUN_0600e906). This document covers ONLY the
player path.

## Ordered Call Sequence

```
FUN_0602EEB8 [player physics dispatcher]
│
├─ [1] JSR sym_0602FDA4         — initial state setup
│
├─ [2] JSR FUN_0602EFF0         — input/state dispatch
│      └─ BSR FUN_0602ECCC (x3) — atan2/rotation computation
│
├─ [3] clear sym_0607EAC8       — zero a global (purpose unknown)
│
├─ [4] JSR sym_0602F3EC         — speed index + drag computation
│      Reads: car[+0x0C] (speed)
│      Writes: car[+0x08] (speed index: speed * 0x480000),
│              car[+0x48], car[+0x50] (drag/damping terms)
│      Note: car[+0x08] computation matches CONFIRMED formula.
│            Also applies speed-dependent damping to +0x48/+0x50.
│
├─ [5] JSR sym_0602F7BC         — effect counter decrements
│      Reads/writes: car[+0x166], car[+0x152], car[+0x208]
│      Each counter decremented if > 0. Simple frame-based timers.
│
├─ [6] JSR sym_0602F0E8         — collision state check
│      Reads: car[+0xB8], car[+0x1BC] (collision/damage flags)
│      Normal path: copies car[+0x94]→[+0x84], car[+0x78]→[+0x68]
│      Collision path: resets counter at +0x166, sets +0x90/+0x74=0x38
│      Also reads/writes: +0xB0, +0xD0
│
├─ [7] CONDITIONAL on car[+0x9C]:
│      ├─ if flag == 0: JSR sym_0602F17C — gear/section state machine
│      │   Reads: car[+0xD8], car[+0xE0], car[+0xDC]
│      │   Writes: car[+0xD8] (±5), car[+0xDC] (section index), car[+0xE0]
│      │   Uses lookup tables at sym_060477AC, sym_0604779C
│      │
│      └─ if flag != 0: JSR FUN_0602F270 — track force application
│         Reads: car[+0xD8], car[+0xDC/+0xDE], car[+0xC0], car[+0xE0], car[+0xE8]
│         Writes: car[+0xE0], car[+0xC4], car[+0x84]
│         Uses lookup table at sym_0602F3CC, calls FUN_0602755C (math)
│
├─ [8] JSR sym_0602F17C         — gear/section state machine (unconditional)
│
├─ [9] JSR sym_0602F474         — animation/display counter
│      Reads: car[+0xD4] (frame counter, 16-bit)
│      Writes: car[+0xD4] (decremented), car[+0x114] (lookup table result)
│      4-state lookup from sym_060477D8
│
├─[10] JSR sym_0602F4B4         — opponent proximity check
│      Reads: car[+0x10], car[+0x18] (position), car[+0x28] (heading)
│      Writes: car[+0xD6] (proximity counter, set to 0x14 on detection)
│      Iterates all opponent cars, checks distance < 0x1E0000 AND
│      angle within ±0x071C of heading. Early return on first match.
│
├─[11] JSR FUN_0602F5B6         — surface/drag computation
│                                  (writes +0xEC, +0xF0, +0xF4, +0x11C)
│
├─[12] JSR sym_0602EFCC         — rotation/animation (same TU)
│
├─[13] JSR FUN_0602C690         — collision magnitude
│
├─[14] JSR FUN_0602C8E2         — collision response decision
│
├─[15] JSR FUN_0602CA84         — collision impact computation
│
├─[16] CONDITIONAL on car[+0x9E]:
│      ├─ if flag == 0: JSR FUN_0602D43C — collision & steering response
│      │   ├─ BSR FUN_0602D7E4          — damping/clamp
│      │   ├─ JSR FUN_06027344 (x3)     — atan2/trig lookup
│      │   ├─ JSR FUN_06027378          — inverse trig
│      │   └─ JSR sym_0602ECCC (x3)     — rotation calc
│      │
│      └─ if flag != 0: JSR FUN_0602D08A — alternate collision path
│
├─[17] JSR FUN_0602CDF6         — cleanup/state finalize
│
├─[18] JSR sym_0602D814         — SPEED WRITER (car[+0x0C])
│      Reads: car[+0x0C], car[+0xFC]
│      Writes: car[+0x0C] (speed += accel_delta, floor at 0)
│              car[+0xE0] (clamped speed via gear lookup)
│              car[+0xE8] (speed headroom: max_avail - current)
│      Uses: gear ratio table at sym_060477BC
│
├─[19] JSR sym_0602D8BC         — POSITION WRITER (car[+0x10], car[+0x18])
│      Conditional on car[+0x250]:
│      ├─ if != 0 (drift/rotation): trig-based position delta
│      │   └─ BSR FUN_0602ECCC, JSR FUN_06027344, JSR FUN_06027348
│      └─ if == 0 (normal): straight velocity integration
│      Writes: car[+0x10] (X position), car[+0x18] (Z position)
│              car[+0x38], car[+0x3C] (previous/velocity)
│              car[+0x18C], car[+0x190] (velocity components)
│
└─ RETURN
```

## Call Details

### All JSR targets (ordered by call position)

| # | Target | Source File | Role (static hypothesis) | Field Access |
|---|--------|-------------|--------------------------|-------------|
| 1 | sym_0602FDA4 | FUN_0602F9A6.s | Initial state setup | Unknown |
| 2 | FUN_0602EFF0 | FUN_0602EFF0.s | Input/state dispatch | Calls FUN_0602ECCC (atan2) x3 |
| 4 | sym_0602F3EC | FUN_0602F270.s | Speed index + drag | R: +0x0C. W: +0x08, +0x48, +0x50 |
| 5 | sym_0602F7BC | FUN_0602F5B6.s | Effect counter ticks | RW: +0x152, +0x166, +0x208 |
| 6 | sym_0602F0E8 | FUN_0602EFF0.s | Collision state check | R: +0xB8, +0x1BC. W: +0x68, +0x74, +0x84, +0x90, +0xD0, +0x166 |
| 7a | sym_0602F17C | FUN_0602EFF0.s | Gear/section state machine | RW: +0xD8, +0xDC, +0xE0. Tables: sym_060477AC, sym_0604779C |
| 7b | FUN_0602F270 | FUN_0602F270.s | Track force application | R: +0xC0, +0xDC/DE, +0xE0, +0xE8. W: +0xC4, +0xE0, +0x84 |
| 8 | sym_0602F17C | (same as 7a) | Post-condition repeat | (same as 7a) |
| 9 | sym_0602F474 | FUN_0602F270.s | Animation counter | R: +0xD4. W: +0xD4, +0x114. Table: sym_060477D8 |
| 10 | sym_0602F4B4 | FUN_0602F270.s | Opponent proximity | R: +0x10, +0x18, +0x28. W: +0xD6 |
| 11 | FUN_0602F5B6 | FUN_0602F5B6.s | Surface/drag | W: +0xEC, +0xF0, +0xF4, +0x11C |
| 12 | sym_0602EFCC | FUN_0602EEB8.s | Rotation (inline) | Unknown |
| 13 | FUN_0602C690 | FUN_0602C690.s | Collision magnitude | R: +0x120-+0x12C |
| 14 | FUN_0602C8E2 | FUN_0602C8E2.s | Collision response | R: +0x40, +0x5C, +0x60, +0x64 |
| 15 | FUN_0602CA84 | FUN_0602CA84.s | Collision impact | R: +0x100, +0x104. W: +0xFC (accel delta) |
| 16a | FUN_0602D43C | FUN_0602D43C.s | Collision+steering (main) | Calls atan2 x3, ECCC x3. W: +0x166 |
| 16b | FUN_0602D08A | ? | Collision (alternate) | Unknown |
| 17 | FUN_0602CDF6 | ? | State finalize | Unknown |
| 18 | sym_0602D814 | FUN_0602D43C.s | **Speed writer** | R: +0x0C, +0xFC. W: +0x0C, +0xE0, +0xE8 |
| 19 | sym_0602D8BC | FUN_0602D89A.s | **Position writer** | R: +0x0C, +0x250. W: +0x10, +0x18, +0x38, +0x3C, +0x18C, +0x190 |

### Register Conventions

- **r14** = car pointer (preserved across all sub-calls)
- **r13** = indirect call register (loaded from pool before JSR)
- **r12** = secondary call register (used in some conditional paths)
- **r0** = car pointer source (loaded from sym_0607E944, saved to r14)

### Pipeline Architecture

The pipeline follows a clear pattern:

1. **Setup** (calls 1-2): Initialize state, dispatch input
2. **Drag + counters** (calls 4-5): Speed index computation, speed-dependent
   drag on +0x48/+0x50, frame-based effect timer decrements
3. **State checks** (calls 6-8): Collision detection → conditional track force
   application OR section state machine transition
4. **Display + proximity** (calls 9-10): Animation frame cycling, opponent
   distance/angle check
5. **Surface** (call 11): FUN_0602F5B6 writes surface fields (+0xEC/F0/F4/11C)
6. **Collision** (calls 12-16): Magnitude → response → impact → steering/damping
7. **Finalize** (call 17): State cleanup
8. **Accumulators** (calls 18-19): Apply deltas to speed and position

The accumulators always run last. All upstream computation feeds into
car[+0xFC] (accel delta) and directional state that the accumulators
integrate into car[+0x0C] (speed) and car[+0x10]/[+0x18] (position).

## Comparison with AI Pipeline

| Stage | Player (FUN_0602EEB8) | AI Normal (FUN_0600e71a) | AI Alt (FUN_0600e906) |
|-------|----------------------|--------------------------|----------------------|
| Speed calc | sym_0602D814 (call 18) | FUN_0600c4f8 | FUN_06027552 |
| Position | sym_0602D8BC (call 19) | inline velocity integration | inline |
| Collision | FUN_0602C690→CA84 | FUN_0600cf58 | NONE |
| Steering | FUN_0602F270 (conditional) | part of FUN_0600c5d6 | FUN_0600c970 (AI) |
| Surface/drag | FUN_0602F5B6 | FUN_0600ca96 | FUN_0600ca96 |
| Heading | embedded in stages | FUN_0600c8cc + c7d4 | FUN_0600c8cc + c7d4 |

### Functional Correspondence (field-access based)

The AI pipeline functions have known hypotheses (from `static_hypotheses.md`).
By matching field access patterns, we can propose player pipeline equivalents.

| Physics concept | AI function | Player equivalent | Evidence |
|----------------|------------|-------------------|----------|
| Speed index | FUN_0600c4f8 (R/W +0x08, +0x0C) | sym_0602F3EC (call 4) | Both R: +0x0C, W: +0x08 via ×0x480000 |
| Friction/drag | FUN_0600ca96 (R: +0x1F8/+0x1FC) | FUN_0602F5B6 (call 11) | Both write surface-related fields |
| Collision dispatch | FUN_0600cf58 (R: +0x04, +0x08) | FUN_0602C690→CA84 (calls 13-15) | Both involve collision detection |
| Track segment advance | FUN_0600ceba (R: +0x68, +0x6C) | NOT IN PLAYER PIPELINE? | May be called elsewhere for player |
| Heading/slip calc | FUN_0600c8cc (RW: +0x28) | Embedded in calls 13-16? | +0x28 (slip) writers in comprehensive map all in 0x0602Cxxx range |
| Airborne damping | FUN_0600c928 (W: +0x48, +0x50) | sym_0602F3EC (call 4) | Both modify +0x48/+0x50 with speed-scaled values |
| Gear shift | FUN_06008318 (R: +0xB8) | NOT IN PLAYER PIPELINE | Called from AI normal pipeline only? Or called separately for player |

Key insight: the player pipeline does NOT call the same shared functions as
the AI pipeline. It has its OWN implementations in the 0x0602xxxx address
range. This means the player physics is a **completely separate codebase**
from the AI physics — not a shared library with different entry points.

The player pipeline is significantly MORE complex than the AI pipeline:
- 19 ordered calls vs 6 for AI
- Dedicated collision sequence (3 functions) vs single collision dispatch
- Separate speed and position accumulator functions vs inline integration
- Two conditional branch points vs linear flow

This likely reflects the player needing fuller physics (collision response,
surface traction, gear ratios) while AI cars use simplified approximations.

## Validation Plan

The Explorer should validate this call tree by running `call_trace` on
FUN_0602EEB8 for 1 frame during `usa_tt_straight.mc0` straight_throttle.
The trace should confirm:
1. The 19-call ordering matches runtime execution
2. Which conditional paths are taken during straight-line driving
3. Whether any calls are skipped under normal conditions
4. The exact sub-calls within FUN_0602D43C
