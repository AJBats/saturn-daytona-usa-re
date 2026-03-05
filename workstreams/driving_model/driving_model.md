# Driving Model Mapping Workstream

**Goal**: Perfect understanding of the Daytona USA driving model — every function name verified,
internal mechanisms understood. Required for transplanting gameplay code to Daytona USA CCE.

**Methodology**: See plan at `~/.claude/plans/silly-baking-origami.md`

## Status

| Phase | Description | Status |
|-------|-------------|--------|
| 1 | Car struct field map | **Active** |
| 2 | Core physics pipeline (12 functions) | Pending |
| 3 | AI pipeline delta | Pending |
| 4 | Surrounding systems | Pending |

## Function Scoreboard

Status: `UNNAMED` / `NAMED_GUESS` / `THEORY` / `OBSERVED` / `VERIFIED`

### Car Iteration & Dispatch

| Address | File | Current Name | Status | Method | Notes |
|---------|------|-------------|--------|--------|-------|
| 0600e0c0 | car_update_racing.s | car_update_racing | NAMED_GUESS | — | Ghidra: iterates cars 1..N, branches player/AI |
| 0600e71a | FUN_0600E71A.s | (was player_physics_main) | THEORY | Ghidra call graph | Calls 6 sub-functions + velocity integration |
| 0600e906 | ai_physics_main.s | ai_physics_main | NAMED_GUESS | — | AI equivalent of 0600e71a |

### Player Physics Pipeline (callees of 0600e71a)

| Address | File | Current Name | Status | Method | Notes |
|---------|------|-------------|--------|--------|-------|
| 0600d266 | heading_correct.s | (sublabel) | THEORY | Ghidra | Empty/NOP function |
| 0600c4f8 | FUN_0600C4F8.s | (was accel_response) | UNNAMED | — | Calls fpmul |
| 0600c5d6 | FUN_0600C5D6.s | (was player_collision) | THEORY | Ghidra call graph | CORE: 11 callees, steering/forces |
| 0600ceba | FUN_0600CEBA.s | (was track_segment_advance) | UNNAMED | — | Calls FUN_06035228 |
| 06008318 | FUN_06008318.s | (was gear_shift_handler) | UNNAMED | — | Calls FUN_06034f78 |
| 06008640 | (unnamed) | — | UNNAMED | — | Calls 060086c0, 06008730 |

### Shared Physics Subfunctions (callees of 0600c5d6)

| Address | File | Current Name | Status | Method | Notes |
|---------|------|-------------|--------|--------|-------|
| 0600cd40 | FUN_0600CD40.s | (was track_pos_query) | UNNAMED | — | Calls FUN_0602744c |
| 0600ca96 | (in ai_orchestrator?) | — | UNNAMED | — | Friction/drag candidate |
| 0600cf58 | collision_dispatch.s | collision_dispatch | NAMED_GUESS | — | 4 callees, player-only |
| 0600cc38 | (unnamed) | — | UNNAMED | — | Force application candidate |
| 0600c8cc | FUN_0600C8CC.s | (was ai_speed_trampoline) | UNNAMED | — | Speed calc candidate |
| 0600c928 | heading_correct.s | heading_correct | NAMED_GUESS | — | Heading correction candidate |
| 0600c7d4 | heading_speed_damping.s | heading_speed_damping | NAMED_GUESS | — | Damping candidate |

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
| 0600c74e | ai_orchestrator.s | ai_orchestrator | NAMED_GUESS | — | AI core (equiv of c5d6) |
| 0600c970 | (unnamed) | — | UNNAMED | — | AI-specific steering? |

### Rendering/Update Loops

| Address | File | Current Name | Status | Method | Notes |
|---------|------|-------------|--------|--------|-------|
| 0600b6a0 | FUN_0600B6A0.s | (was render_cs0_loop) | OBSERVED | NOP test | NOP removes rendering + collision |
| 0600b914 | FUN_0600B914.s | (was render_scene_loop) | OBSERVED | NOP test | Secondary CPU equivalent |
| 0600c010 | scene_render_body.s | scene_render_body | NAMED_GUESS | — | Frame orchestrator |
