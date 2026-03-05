# Driving Model Mapping Workstream

**Goal**: Perfect understanding of the Daytona USA driving model — every function name verified,
internal mechanisms understood. Required for transplanting gameplay code to Daytona USA CCE.

**Methodology**: See plan at `~/.claude/plans/silly-baking-origami.md`

## Status

| Phase | Description | Status |
|-------|-------------|--------|
| 1 | Car struct field map | **Active** — static map done, empirical validation in progress |
| 2 | Core physics pipeline (12 functions) | **Active** — FUN_0600d266 VERIFIED empty |
| 3 | AI pipeline delta | Pending |
| 4 | Surrounding systems | Pending |

### Resolved Questions

1. **C button = throttle** — CONFIRMED via watchpoint on car[+0xFC]. C shifts accel delta
   +70 units/update vs idle drift of -1 to -7. See struct_map.md.
2. **Car 0 = player** — CONFIRMED. HUD speedometer reads car 0's speed field (ratio 1,467
   stable). Car 0 is processed by FUN_0602D814, separate from the AI loop.
3. **sym_0607EBC4 bit 15 = global mode flag** — when clear, ALL cars in the loop use
   FUN_0600e71a (player physics). The loop (i=1..N) processes AI cars only. Player car 0
   has its own code path rooted at ~0x0602EF00.

### Open Questions

1. **Player physics entry point** — FUN_0602D814/0x0602EF4E writes car 0's acceleration
   and speed. This is a separate code path from FUN_0600c4f8 (which handles AI cars).
   Need to map the full player-specific physics pipeline.
2. **sym_0607EBC4** — what sets bit 15? When is it non-zero? Controls AI vs player pipeline
   for the car iteration loop.

## Function Scoreboard

Status: `UNNAMED` / `NAMED_GUESS` / `THEORY` / `OBSERVED` / `VERIFIED`

### Car Iteration & Dispatch

| Address | File | Current Name | Status | Method | Notes |
|---------|------|-------------|--------|--------|-------|
| 0600e0c0 | car_update_racing.s | car_update_racing | THEORY | Ghidra + watchpoint | THEORY: ai_car_loop — iterates cars 1..N, skips car 0 (player). Branches on sym_0607EBC4 & 0x8000 |
| 0600e71a | FUN_0600E71A.s | FUN_0600E71A | THEORY | Ghidra call graph | THEORY: car_physics_pipeline — 6 callees + velocity integration |
| 0600e906 | ai_physics_main.s | ai_physics_main | THEORY | Ghidra call graph | THEORY: ai_physics_main — AI equivalent, shares d266/fpmul/ceba |

### Player Physics Pipeline (callees of 0600e71a)

| Address | File | Current Name | Status | Method | Notes |
|---------|------|-------------|--------|--------|-------|
| 0600d266 | (retail only) | — | **VERIFIED** | Breakpoint + disasm | `rts; nop` — confirmed empty |
| 0600c4f8 | FUN_0600C4F8.s | FUN_0600C4F8 | THEORY | Ghidra decompilation | THEORY: speed_update — car[+0x0C] += car[+0xFC], car[+0x08] = fpmul(speed, 0x480000) |
| 0600c5d6 | FUN_0600C5D6.s | FUN_0600C5D6 | THEORY | Ghidra decompilation | THEORY: car_forces_main — 11 callees, ground/airborne paths |
| 0600ceba | FUN_0600CEBA.s | FUN_0600CEBA | THEORY | Ghidra decompilation | THEORY: track_segment_advance — heading change detection, car[+0x228]++ |
| 06008318 | FUN_06008318.s | FUN_06008318 | THEORY | Ghidra + struct_map | THEORY: gear_shift_handler — car[+0xB8] countdown, UP/DOWN pad, table at 0x060453CC |
| 06008640 | (unnamed) | — | UNNAMED | — | Calls 060086c0, 06008730 |

### Shared Physics Subfunctions (callees of 0600c5d6)

| Address | File | Current Name | Status | Method | Notes |
|---------|------|-------------|--------|--------|-------|
| 0600cd40 | FUN_0600CD40.s | FUN_0600CD40 | THEORY | Ghidra decompilation | THEORY: track_position_query — reads car[+0x1E4], calls FUN_0602744c |
| 0600ca96 | FUN_0600C994.s | FUN_0600CA96 (sublabel) | THEORY | Ghidra decompilation | THEORY: surface_friction — car[+0x1EC] table lookup, ±4 step |
| 0600cf58 | collision_dispatch.s | collision_dispatch | THEORY | Ghidra decompilation | THEORY: collision_dispatch — 4 callees, player-only |
| 0600cc38 | FUN_0600CC38.s | FUN_0600CC38 | THEORY | Ghidra decompilation | THEORY: force_application — car[+0x01F8]/[+0x01FC] deltas (was heading_correct — reverted) |
| 0600c8cc | FUN_0600C8CC.s | FUN_0600C8CC | THEORY | Ghidra decompilation | THEORY: steering_toward_track — car[+0x28] steered toward track, max ±0x600 |
| 0600c928 | ai_speed_target.s | FUN_0600C928 (sublabel) | THEORY | Ghidra decompilation | THEORY: heading_correction — car[+0x48] decremented, copied to car[+0x50] |
| 0600c7d4 | heading_speed_damping.s | heading_speed_damping | THEORY | Ghidra decompilation | THEORY: heading_speed_damping — airborne damping, speed brackets |

### Math Library (shared)

| Address | File | Current Name | Status | Method | Notes |
|---------|------|-------------|--------|--------|-------|
| 06006838 | atan2_full.s | atan2_full | NAMED_GUESS | — | atan2 candidate |
| 06027ede | (unnamed) | — | UNNAMED | — | Vector rotation candidate |
| 06027358 | (unnamed) | — | UNNAMED | — | Sin/cos application candidate |
| 06027552 | fpmul.s | fpmul | NAMED_GUESS | — | Fixed-point multiply |

### AI-Specific

| Address | File | Current Name | Status | Method | Notes |
|---------|------|-------------|--------|--------|-------|
| 0600c74e | ai_orchestrator.s | ai_orchestrator | THEORY | Ghidra call graph | THEORY: ai_orchestrator — AI equiv of c5d6, has c970 instead of cf58/cc38 |
| 0600c970 | (unnamed) | — | UNNAMED | — | AI-specific steering? |

### Rendering/Update Loops

| Address | File | Current Name | Status | Method | Notes |
|---------|------|-------------|--------|--------|-------|
| 0600b6a0 | FUN_0600B6A0.s | FUN_0600B6A0 | OBSERVED | NOP test | THEORY: opponent_update_primary — NOP removes rendering + collision |
| 0600b914 | FUN_0600B914.s | FUN_0600B914 | OBSERVED | NOP test | THEORY: opponent_update_secondary — secondary CPU equivalent |
| 0600c010 | scene_render_body.s | scene_render_body | NAMED_GUESS | — | Frame orchestrator |
