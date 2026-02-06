# CCE Transplant: Extraction Dependency Graph

> Which gameplay subsystems to extract from Daytona USA (1995),
> in what order, and what each depends on.

## Goal

Transplant the **gameplay code** (physics, steering, collision, AI) from
Daytona USA Saturn (1995) into Daytona USA CCE (1996). CCE has its own
menus, HUD, and rendering — we only need the gameplay engine.

## Extraction Tiers

### Tier 0: Data Structures (Extract First)

These are not code — they are the shared memory layouts that every
subsystem reads/writes. Get these wrong and nothing works.

| Structure | Address | Size | Documented In |
|-----------|---------|------|---------------|
| Car object array | 0x06078900 | 40 x 0x268 | gameplay_extraction.md, object_management.s |
| Force table A (gentle) | 0x0604508C | 64 x 12B | force_tables.s |
| Force table B (aggressive) | 0x06044C90 | 85 x 12B | force_tables.s |
| Speed curve table A | 0x060477EC | course-dep | speed_position.s |
| Speed curve table B | 0x060454CC | course-dep | speed_position.s |
| Steering deflection table | 0x060453CC | indexed | player_physics.s |
| Checkpoint tables | per-course | 24B/entry | lap_counting.s |
| Track segment data | 0x060C2000 | 512B/seg | collision.s, track_geometry.s |
| Sin/cos lookup | 0x06044000 | 1024 entries | math_helpers.s |
| Config table (car types) | 0x06047DE4 | 12B/car | object_management.s |
| Master flags | 0x0607EBC4 | 4 bytes | race_update.s |
| Car pointer storage | 0x0607E940-E944 | 8 bytes | race_update.s |
| Velocity outputs | 0x060786C0-C8 | 12 bytes | race_update.s |

**Key**: The car object struct at +0x00 through +0x350 is the central
data structure. Every gameplay function reads or writes fields in it.
See gameplay_extraction.md "Car Object Struct Layout" for complete map.

---

### Tier 1: Math Library (No Dependencies)

Pure computation, no game state, no side effects. Extract these first
as standalone functions.

| Function | Size | Purpose | Documented In |
|----------|------|---------|---------------|
| FUN_06027358 | 26 insns | sin/cos lookup (heading -> X/Z components) | math_helpers.s |
| FUN_06027552 | 44 insns | Fixed-point multiply (speed * direction) | math_helpers.s |
| FUN_060273D2 | 32 insns | atan2 (X,Z -> heading angle) | math_helpers.s |
| FUN_06027468 | ~30 insns | Square root (fixed-point) | math_helpers.s |
| FUN_06028400 | 8 insns | memcpy 8 bytes | math_helpers.s |
| FUN_06006838 | ~20 insns | World pos -> tile grid coordinates | race_update.s |
| FUN_06034F78 | 52 insns | Bitfield utility (packed position/count) | lap_counting.s, ai_opponents.s |

**Dependencies**: Only sin/cos table at 0x06044000.

---

### Tier 2: Position Integration (Depends on: Tier 1)

The core physics step: convert velocity to position change.

| Function | Size | Purpose | Documented In |
|----------|------|---------|---------------|
| FUN_0600C5D6 | ~150 insns | Collision detect + heading->position integration | collision.s, player_physics.s |
| FUN_0600EA18 | LEAF | Track-following velocity (AI path) | ai_behavior.s, race_update.s |
| Position integrator | inline at 0x0600E5B4 | car.X += vel_X, car.Z += vel_Z, car.heading += ang_vel | race_update.s |

**Pipeline**:
```
heading -> FUN_06027358(heading) -> (sin, cos)
speed * sin -> FUN_06027552 -> delta_X
speed * cos -> FUN_06027552 -> delta_Z
car.X += delta_X
car.Z += delta_Z
```

**Dependencies**: Tier 1 math, car object struct, track segment data.

---

### Tier 3: Speed & Force System (Depends on: Tier 1, Tier 2)

How controller input becomes car velocity.

| Function | Size | Purpose | Documented In |
|----------|------|---------|---------------|
| FUN_0600C4F8 | 178 insns | Speed curve lookup + clamping | speed_position.s, scene_camera.s |
| FUN_060086C0 | ~200 insns | Force vector extraction from steering table | player_physics.s |
| FUN_06008640 | inline | Gear/force table selection | player_physics.s |
| FUN_06008318 | ~100 insns | Controller: gear shift, steering column | player_physics.s |
| Force application | inline 0x06008730+ | Gas/brake flag -> force sign -> car struct | player_physics.s |

**Pipeline (player)**:
```
Controller buttons (A=gas, B=brake)
  -> FUN_06008318 (gear shift, steering)
  -> FUN_06008640/060086C0 (force table lookup)
  -> Force application (sign by gas/brake, store to car struct)
  -> FUN_0600C4F8 (speed curve: table_A[seg] - table_B[seg])
  -> FUN_0600C5D6 (position integration via Tier 2)
```

**Dependencies**: Force tables (0x0604508C, 0x06044C90), speed curve tables,
steering deflection table, car object flags byte (+0x00).

---

### Tier 4: Collision System (Depends on: Tier 2)

Car-car and car-track collision detection and response.

| Function | Size | Purpose | Documented In |
|----------|------|---------|---------------|
| FUN_0600CD40 | ~80 insns | Checkpoint crossing detection | collision.s, lap_counting.s |
| FUN_0600CA96 | ~100 insns | Collision response A | collision.s |
| FUN_0600CC38 | ~80 insns | Collision response B | collision.s |
| FUN_0600A914 | ~60 insns | Car-car collision detection | car_collision.s |
| FUN_0600CEBA | ~120 insns | Track segment advancement & heading interp | player_physics.s |
| FUN_0600D0B8 | ~60 insns | Position/velocity clamping | gameplay_extraction.md |

**Dependencies**: Car object positions (+0x10/14/18), track segment data,
checkpoint tables.

---

### Tier 5: AI System (Depends on: Tier 2, Tier 4)

Computer opponent behavior.

| Function | Size | Purpose | Documented In |
|----------|------|---------|---------------|
| FUN_0600C74E | 500+ insns | AI main processing (waypoints, speed, heading) | ai_behavior.s |
| FUN_06035460 | 331 insns | AI main loop (high-level brain) | ai_opponents.s |
| FUN_060359E4 | 231 insns | AI physics integration | ai_opponents.s |
| FUN_06034FFC | 85 insns | AI state machine (4 modes) | ai_opponents.s |
| FUN_060350B0 | 87 insns | AI decision logic | ai_opponents.s |
| FUN_06035844 | 80 insns | AI target tracking (player position) | ai_opponents.s |
| FUN_06034E58 | 72 insns | AI pathfinding (waypoint navigation) | ai_opponents.s |
| FUN_06034F78 | 52 insns | AI steering angle computation | ai_opponents.s |
| FUN_06035CBC | 43 insns | AI per-car init (difficulty params) | ai_opponents.s |
| FUN_06035D5A | 75 insns | AI core init (all cars) | ai_opponents.s |
| FUN_06035B34 | 70 insns | AI system init (waypoint tables) | ai_opponents.s |

**AI Pipeline (per AI car per frame)**:
```
FUN_06035460 (brain)
  -> FUN_06034E58 (pathfinding: where to go)
     -> FUN_06034F78 (steering angle to target)
  -> FUN_06034FFC (state machine: behavior mode)
     -> FUN_060350B0 (evaluate game state)
     -> FUN_06035844 (track player position)
  -> FUN_060359E4 (apply to physics)
```

**AI vs Player difference**:
- Player: force table -> speed curve -> position (Tier 3)
- AI: velocity = (target_pos - current_pos) >> 4 (simple tracking)
- Both merge at position integration (Tier 2)

**Dependencies**: Track segment data, waypoint tables, car object struct,
difficulty parameters, player car position.

---

### Tier 6: Lap & Race Logic (Depends on: Tier 4)

Lap counting, checkpoint tracking, race progression.

| Function | Size | Purpose | Documented In |
|----------|------|---------|---------------|
| FUN_0600CD40 | ~80 insns | Checkpoint crossing detection | lap_counting.s |
| FUN_0600D780 | ~150 insns | Checkpoint change detection | lap_counting.s |
| FUN_0600D9BC | ~40 insns | Lap completion flag setter | lap_counting.s |
| 0x0600DB64 | inline | Lap counter increment | lap_counting.s |
| FUN_0600DBA0 | ~30 insns | Finish line display trigger | lap_counting.s |

**Dependencies**: Checkpoint tables (per-course), car object lap fields
(+0x15C, +0x1E0-1F4), one-shot flag at byte+2 bit 2.

---

### Tier 7: Per-Car Update Pipeline (Integrates Tiers 2-6)

The master per-car-per-frame update that ties everything together.

| Function | Size | Purpose | Documented In |
|----------|------|---------|---------------|
| FUN_0600E4F2 | ~200 insns | Mode 1: full 9-stage pipeline | object_management.s |
| FUN_0600E71A | ~300 insns | Player physics pipeline (8 steps) | player_physics.s |
| FUN_0600E906 | ~150 insns | AI physics pipeline (5 steps) | ai_behavior.s, race_update.s |
| FUN_0600DF66 | ~30 insns | Update mode dispatcher (0/1/2) | object_management.s |
| FUN_0600E410 | ~50 insns | Mode 0: simplified pre-race | object_management.s |
| FUN_0600E1D4 | ~80 insns | Per-car type init (player vs AI) | object_management.s |

**The Big Pipeline (FUN_0600E4F2, mode 1)**:
```
9-stage per-car per-frame:
  1. FUN_06008318  — Controller input / gear shift
  2. FUN_06008640  — Gear/force table selection
  3. FUN_0600D266  — (stub: friction placeholder)
  4. FUN_0600C4F8  — Speed curve + clamping
  5. FUN_0600C5D6  — Collision + position integration
  6. inline        — Timer countdown, segment check
  7. FUN_0600CEBA  — Track segment advancement
  8. inline        — Score/ranking computation
  9. FUN_0600D780  — Checkpoint/lap tracking
```

---

### Tier 8: Race State Machine (Integrates Tier 7)

The outer loop that drives everything per-frame.

| Function | Size | Purpose | Documented In |
|----------|------|---------|---------------|
| FUN_0600DE54 | ~20 insns | Race state update dispatcher | race_update.s |
| FUN_0600E0C0 | ~100 insns | Main race frame update (car loop) | per_car_loop.s, race_update.s |
| FUN_0600E99C | ~40 insns | Pre-update camera/AI setup | per_car_loop.s |
| FUN_0600DE70 | ~60 insns | Per-car iteration loop (master) | object_management.s |
| FUN_0600C302 | ~30 insns | Car state finalize | per_car_loop.s |

**Per-frame flow**:
```
State 15 (FUN_06009098)
  -> FUN_0600DE54 (race state update)
    -> FUN_0600E99C (pre-update)
    -> FUN_0600E0C0 (main loop)
      for each car:
        -> FUN_0600DF66 (mode dispatch)
          -> FUN_0600E4F2 (full pipeline, Tier 7)
        -> FUN_06027CA4 x4 (3D scene, NOT needed for CCE)
      -> FUN_0600C302 (finalize)
      -> FUN_0600A914 (collision, Tier 4)
```

---

### Tier 9: Object Lifecycle (Init/Teardown)

Setup and teardown for car objects.

| Function | Size | Purpose | Documented In |
|----------|------|---------|---------------|
| FUN_0600EB14 | ~80 insns | Master race init (zero array, subsystem inits) | object_management.s |
| FUN_0600629C | ~60 insns | Car init loop (iterate car_count, init each) | object_management.s |
| FUN_0600E1D4 | ~80 insns | Per-car type init (config table lookup) | object_management.s |

**Dependencies**: Config table at 0x06047DE4, car object array.

---

## Dependency Graph (Visual)

```
Tier 0: DATA STRUCTURES
  |
  v
Tier 1: MATH LIBRARY (sin/cos, multiply, sqrt, atan2)
  |
  v
Tier 2: POSITION INTEGRATION (velocity -> position)
  |          |
  v          v
Tier 3:   Tier 4:
SPEED &   COLLISION
FORCE     SYSTEM
  |          |
  |    +-----+-----+
  |    |           |
  v    v           v
Tier 5:         Tier 6:
AI SYSTEM       LAP/RACE
                LOGIC
  |               |
  +-------+-------+
          |
          v
Tier 7: PER-CAR UPDATE PIPELINE
          |
          v
Tier 8: RACE STATE MACHINE
          |
          v
Tier 9: OBJECT LIFECYCLE (init/teardown)
```

---

## What CCE Already Has (Do NOT Extract)

| Subsystem | Why Skip |
|-----------|----------|
| VDP1/VDP2 rendering | CCE has its own renderer (likely improved) |
| Menu/HUD system | CCE has different menus and HUD |
| Sound driver | CCE has its own SCSP interface |
| Frame timing | CCE has its own VBlank/frame system |
| Replay camera | CCE has different replay modes |
| Track geometry loading | CCE loads different course data |

---

## What MUST Be Extracted

| Priority | Subsystem | Functions | Tier |
|----------|-----------|-----------|------|
| CRITICAL | Math library | 7 functions | 1 |
| CRITICAL | Position integration | 3 functions | 2 |
| CRITICAL | Speed/force system | 5 functions | 3 |
| CRITICAL | Collision system | 6 functions | 4 |
| CRITICAL | Per-car pipeline | 6 functions | 7 |
| HIGH | AI system | 11 functions | 5 |
| HIGH | Lap/race logic | 5 functions | 6 |
| HIGH | Race state machine | 5 functions | 8 |
| HIGH | Object lifecycle | 3 functions | 9 |
| MEDIUM | Data tables | 13 tables | 0 |

**Total: ~51 functions + 13 data tables**

---

## Extraction Order (Recommended)

1. Copy data tables verbatim (Tier 0)
2. Port math library as standalone C functions (Tier 1)
3. Port position integration — test with fixed inputs (Tier 2)
4. Port speed/force system — test with mock controller (Tier 3)
5. Port collision system — test with 2-car scenario (Tier 4)
6. Port AI system — test with single AI car (Tier 5)
7. Port lap counting — test with 1-lap circuit (Tier 6)
8. Integrate into per-car pipeline (Tier 7)
9. Wire up race state machine (Tier 8)
10. Add object lifecycle init/teardown (Tier 9)

Each tier can be tested independently before integration.

---

## Cross-Reference: ASM File -> Tier

| ASM File | Tier(s) | Priority |
|----------|---------|----------|
| math_helpers.s | 1 | CRITICAL |
| speed_position.s | 2, 3 | CRITICAL |
| collision.s | 4 | CRITICAL |
| collision_response.s | 4 | CRITICAL |
| car_collision.s | 4 | CRITICAL |
| player_physics.s | 3, 7 | CRITICAL |
| force_tables.s | 3 | CRITICAL |
| force_system.s | 3 | CRITICAL |
| ai_behavior.s | 5 | HIGH |
| ai_opponents.s | 5 | HIGH |
| lap_counting.s | 6 | HIGH |
| race_update.s | 7, 8 | HIGH |
| per_car_loop.s | 7, 8 | HIGH |
| object_management.s | 7, 9 | HIGH |
| race_states.s | 8 | HIGH |
| input_smpc.s | 3 | MEDIUM (adapt for CCE) |
| track_geometry.s | 0, 4 | MEDIUM (different courses) |
| scene_camera.s | - | LOW (CCE has own) |
| render_pipeline.s | - | LOW (CCE has own) |
| menu_display.s | - | LOW (CCE has own) |
| sound_driver.s | - | LOW (CCE has own) |
| vdp_hardware.s | - | LOW (CCE has own) |
