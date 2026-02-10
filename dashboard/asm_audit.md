# ASM Annotation Confidence Audit

Generated: 2026-02-10

## Summary

| Metric | Value |
|--------|-------|
| Total .s files audited | 46 |
| Per-function CONFIDENCE scores | 634 |
| DEFINITE (file-level) | 6 (13%) |
| HIGH (file-level) | 29 (63%) |
| MEDIUM (file-level) | 10 (22%) |
| SPECULATIVE (file-level) | 1 (2%) |

## Confidence Distribution

### DEFINITE (6 files) — Verified byte-for-byte against binary

| File | Per-func scores | Subsystem |
|------|----------------|-----------|
| frame_timing.s | 9 | Frame commit pipeline, sprite command builder |
| game_loop.s | 4 | Main loop, 32-state machine dispatch |
| input_smpc.s | 3 | SMPC controller input pipeline |
| pre_race_states.s | 19 | Pre-race state handlers (menu, course select) |
| speed_position.s | 2 | Speed computation, position integration |
| vblank_system.s | 9 | VBlank interrupt, frame sync, buffer swap |

### HIGH (29 files) — Strong evidence, minor ambiguity

| File | Per-func scores | Subsystem |
|------|----------------|-----------|
| ai_behavior.s | 10 | Track-following AI behavior |
| ai_physics_pipeline.s | 19 | AI physics update pipeline |
| car_collision.s | 1 | Car-to-car collision |
| collision.s | 10 | General collision detection |
| collision_response.s | 2 | Collision response/resolution |
| disc_loading_replay.s | 24 | CD-ROM loading, replay system |
| display_elements.s | 9 | On-screen display element interpreter |
| engine_sound.s | 5 | Engine RPM-based sound |
| event_queue.s | 17 | 24-slot event queue system |
| force_system.s | 5 | Force extraction pipeline |
| force_tables.s | 6 | Force lookup tables |
| lap_counting.s | 8 | Lap/checkpoint counting |
| math_helpers.s | 23 | Core math utilities (sin/cos, multiply, divide) |
| math_transform.s | 15 | 3D matrix/vector pipeline |
| object_management.s | 9 | Car object lifecycle |
| per_car_loop.s | 3 | Per-car update iteration |
| player_physics.s | 10 | Player car physics pipeline |
| race_orchestration.s | 13 | Camera/physics/race state orchestration |
| race_states.s | 11 | In-race state handlers (states 14-29) |
| race_update.s | 5 | Race update dispatch |
| remaining_subsystems.s | 30 | Catch-all: game loop helpers, misc subsystems |
| rendering.s | 6 | VDP1 rendering pipeline |
| replay_camera.s | 18 | Replay/cinematic camera |
| scene_camera.s | 32 | Camera positioning/projection |
| scene_renderer.s | 4 | Scene/3D rendering |
| sound.s | 10 | Main sound system interface |
| subsystem_updates.s | 13 | Per-frame subsystem dispatch |
| track_geometry.s | 25 | Track segment data, geometry |
| vdp_hardware.s | 10 | VDP1/VDP2 hardware register setup |

### MEDIUM (10 files) — Reasonable but details uncertain

| File | Per-func scores | Subsystem | Key Issue |
|------|----------------|-----------|-----------|
| hud_ui.s | 12 | HUD elements | Mixed subsystem file, varying per-section |
| menu_display.s | 24 | Menu rendering | Race HUD section has fabricated addresses |
| render_pipeline.s | 36 | Render pipeline stages | Catalog-style, many functions unverified |
| sound_driver.s | 8 | Low-level sound driver | Several misidentifications, busy-wait contradiction |
| state_handlers.s | 17 | 32-state handler catalog | 6 incorrect state-to-address mappings |
| system_init.s | 31 | System bootstrap, hardware init | Some hardware subsystem labels inaccurate |
| track_hud_extended.s | 11 | Track-specific HUD | Mixed file covering track/HUD/menus/camera |
| ui_event_extended.s | 26 | UI event handling | Some size/stub claims wrong |
| vdp_scene_rendering.s | 45 | VDP1/VDP2 rendering commands | High-level catalog of 72 functions |
| vertex_pipeline.s | 13 | Vertex transformation | Only FUN_0602ECCC verified DEFINITE |

### SPECULATIVE (1 file) — Major issues found

| File | Per-func scores | Subsystem | Key Issue |
|------|----------------|-----------|-----------|
| ai_opponents.s | 12 | AI opponent system | Most function addresses are mid-function offsets in SMPC handler, NOT real AI functions. Call tree fabricated. |

## Key Findings

### Critical Issues
1. **ai_opponents.s**: Most addresses (0x06035460, 0x060359E4, 0x06034F78, etc.) are NOT function labels — they're mid-function offsets within FUN_06034F08 (SMPC peripheral handler). The "AI opponent" descriptions are fabricated; actual code is SMPC I/O.

2. **state_handlers.s**: 6 incorrect state-to-address mappings found in the jump table catalog.

3. **menu_display.s**: Race HUD section (0x06030xxx) contains fabricated addresses — these don't correspond to real function entry points.

4. **sound_driver.s**: FUN_0601DB84 incorrectly described. "Fire and forget" claim contradicts the busy-wait protocol. FUN_060302C6 is engine sound generator, not sound init.

### Common Patterns
- **Mid-function offsets**: Several files cite addresses that are branch targets within larger functions, not independent function entry points. This is especially prevalent in the high-address ranges (0x06034xxx-0x06035xxx).
- **Sin/cos table size**: Originally annotated as 256 entries, actually 4096 (mask 0x3FFC).
- **SCU vs VDP1 DMA**: 0x25FE0000 is SCU DMA, not VDP1 DMA. Misidentified in multiple files.
- **VDP1 register labels**: Several files have VDP1 memory region labels confused.

### What We Got Right
- **Player physics pipeline**: 8-step call chain fully verified
- **Game loop**: Main loop and jump table verified byte-for-byte
- **Input system**: SMPC hardware registers confirmed
- **VBlank/timing**: Interrupt system verified instruction-by-instruction
- **Math library**: All 20 function addresses confirmed, sin/cos/multiply/divide correctly identified
- **Event queue**: 24-slot system with correct slot math
- **Pre-race states**: Jump table mappings extensively verified

---
*Last updated: 2026-02-10*
