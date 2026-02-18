# Reimplementation Dashboard

## Symbol Coverage

| Metric | Value |
|--------|-------|
| Original binary functions | 1234 |
| Reimpl symbol coverage | 1234 (100%) |
| Healthy functions (90-110% fill) | 832/1233 (67.5%) |
| ASM byte imports (original binary) | 960 |
| Ghidra C lifts (active) | ~200 |
| Hand-written translations | ~140 |
| Remaining stubs | 203 (genuine tiny functions) |
| Overflows | 0 |

## Build Status

| Metric | Value |
|--------|-------|
| Compiler | sh-elf-gcc 13.3.0 |
| Build system | Sawyer L2 relocatable assembly |
| Binary size | 394,892 bytes (budget: 394,896) |
| Compilation errors | 0 |
| Linker errors | 0 |
| Overflows | 0 |
| C functions (mixed build) | 1 (FUN_060423CC — SCDQ bypass) |
| Linker stubs (external data) | ~1500 |

## L2 Progress

| Task | Count | Status |
|------|-------|--------|
| Hardware register defines (saturn.h) | 300+ | DONE |
| Game state defines (game.h) | 80+ | DONE |
| Address replacements in batch files | 638 | DONE |
| Car struct field offsets | 40+ | DONE |
| Function naming (from ASM annotations) | 220 mappings, 159 applied | DONE |
| Function naming tool | l2_rename_funcs.py | DONE |

## Function Quality Distribution

| Category | Count | Notes |
|----------|-------|-------|
| Good (90-110% fill) | 832 | Healthy — original bytes or correctly-sized C |
| Medium (50-90%) | 160 | C lifts that compile smaller than original |
| Small (25-50%) | 25 | Significantly undersized C lifts |
| Tiny (<25%) | 13 | Very undersized C lifts |
| ASM Stub (12B) | 150 | Genuine tiny functions (original is 12B) |
| RTS Stub (4B) | 53 | Genuine single-instruction returns |
| Data Region | 1 | FUN_06046E48 (117KB, not code) |

## Headers

| Header | Contents | Defines |
|--------|----------|---------|
| saturn.h | Saturn hardware registers | 300+ |
| game.h | Game state, car struct, globals | 80+ |

### saturn.h coverage:
- VDP1: I/O regs, VRAM, framebuffer (12 registers + constants)
- VDP2: All 70+ control registers, VRAM/CRAM layout
- SCU: DMA L0/L1/L2, timers, interrupts (20+ registers)
- SMPC: I/O, command codes (15 registers)
- SCSP: Sound RAM, mailbox, control (10 registers)
- CD Block: HIRQ, command registers (7 registers + HIRQ bits)
- SH-2: FRT, interrupts, division unit, bus control (18 registers)
- BIOS: Function pointers (4), vector numbers (2)

### game.h coverage:
- Car struct: 40+ field offsets (flags, position, physics, forces, checkpoints)
- Game state: state machine, frame counter, phase flags
- VBlank: counters, phase tracking, frame buffer state
- Input: button bit definitions
- Rendering: state, parameters, VDP1 command buffer
- Sound: timeout flag, mailbox mirror, channel state
- Course/session: CD state, course select

## L2 Function Naming Coverage

| Subsystem | Named Functions | Key Examples |
|-----------|----------------|--------------|
| System Init | 20 | master_init_dispatcher, global_engine_init |
| VBlank/Frame | 5 | vblank_in_handler, frame_end_display_commit |
| Race States | 11 | state_14_first_frame_race, state_15_main_race_loop |
| Collision | 15 | car_collision_response, collision_response_dispatcher |
| Physics/Force | 12 | gas_force_apply, steering_physics_update |
| Camera/Scene | 16 | camera_position_lerping, race_state_machine |
| Rendering | 25 | scene_setup_master, projection_manager |
| VDP1 Commands | 12 | vdp1_sprite_command_gen, vdp1_command_builder |
| VDP2/Palette | 8 | vdp2_register_setup, palette_init |
| Sound | 14 | sound_cmd_dispatch, engine_sound_generator |
| Math/DMA | 10 | math_sin_cos, scu_dma_transfer |
| HUD/Menu | 7 | race_hud_orchestrator, timer_display |
| Lap/Track | 17 | checkpoint_change_detect, track_geometry_processor |
| Object Mgmt | 12 | race_init_master, per_car_update_loop |
| Other | 6 | smpc_intback_trigger, replay_camera_controller |
| **Total** | **220** | |

## Boot Test

| Test | Result | Date |
|------|--------|------|
| Compilation | PASS | 2026-02-17 |
| Link | PASS | 2026-02-17 |
| Disc injection | PASS | 2026-02-17 |
| Mednafen boot (+0) | **Title screen** | 2026-02-17 |
| Mednafen boot (+4 free layout) | **Title screen** | 2026-02-17 |
| Attract mode (ICF bypass) | **3D demo playback** | 2026-02-18 |

## Source File Inventory

| Category | Files | Functions |
|----------|-------|-----------|
| batch_*.c (L1 lifts + ASM imports) | 31 | ~900 |
| asm_*.c (legacy stubs + imports) | 10 | ~200 |
| Hand-written translations | 36+ | ~140 |
| Stubs/linker | 3 | ~1500 |
| **Total** | **80+** | **1234** |

## L2 Tools

| Tool | Purpose |
|------|---------|
| tools/l2_replace_addrs.py | Replace raw hex addresses with named defines |
| tools/l2_rename_funcs.py | Rename FUN_XXXXXXXX to meaningful names (220 mappings) |

## Next Steps

1. Investigate attract mode behavior — does demo timer count down and cycle through states?
2. Fix slave SH-2 "Illegal Instruction" (PC=00000002) — non-fatal but indicates init gap
3. Reduce 198 medium/small/tiny functions — improve Ghidra C lifts or replace with ASM
4. Continue L2 naming/structure pass on highest-priority subsystems

---
*Last updated: 2026-02-18*
