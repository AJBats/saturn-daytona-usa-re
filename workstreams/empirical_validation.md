# Empirical Validation — Ground Truth Function Identification

> **Status**: Active
> **Created**: 2026-02-28
> **Predecessor**: Car Flip Benchmark (experiments 1-3 showed limits of poke-and-observe)

## The Goal

Confirm what functions actually do by observing them in the running game.
Static analysis and pattern matching produce guesses. The emulator produces facts.
Every VERIFIED annotation is a piece of ground truth that anchors the surrounding
annotations and makes future reverse engineering faster.

## Methodology

### Core Loop

1. **Get to a known game state** — replay the golden trace to reach menu, circuit
   select, car select, or racing
2. **Trigger a behavior** — press a button, wait for a game event
3. **Observe what changed** — memory diff, watchpoint hit, call trace
4. **Map to code** — PC that wrote the value → function in symbol table
5. **Annotate with VERIFIED tag** — update the source file with ground truth

### Tools

| Tool | Purpose |
|------|---------|
| `tools/record_trace.py` | Record interactive gameplay with frame-precise input logging |
| `tools/replay_trace.py` | Replay a trace headlessly, capture screenshots |
| `tools/investigate.py` | **Primary**: Replays to game states, runs watchpoint/call-trace/memory-diff experiments |
| `tools/investigate_targeted.py` | Targeted follow-up investigations for specific variables |
| `tools/prove_down_handler.py` | Template: watchpoint-based input handler discovery |
| `tools/find_menu_input.py` | Template: memory-diff + watchpoint approach |
| `build/golden_trace/` | Reference trace + 18 screenshots covering full arcade flow |
| `build/investigation_results/` | Output from investigate.py (logs, call traces, memory diffs) |

### Mednafen Automation Commands (Key Subset)

```
frame_advance N          — advance N frames, then pause
input BUTTON             — press button (START, A, B, C, UP, DOWN, LEFT, RIGHT)
input_release BUTTON     — release button
screenshot PATH          — capture framebuffer (queued, taken next frame)
dump_mem ADDR SIZE       — hex dump memory region
watchpoint ADDR          — watch for 4-byte writes (logs PC, PR, old/new values)
watchpoint_clear         — remove watchpoint
breakpoint ADDR          — add PC breakpoint
call_trace PATH          — log JSR/BSR calls with cycle count
dump_regs                — text dump of primary SH-2 registers
```

Full reference: `mednafen/DEBUGGING.md`

### Golden Trace — Game Flow Reference

Trace file: `build/golden_trace/arcade_full.txt` (62 input events, frames 174-5596)

| Stage | Screenshot | Frame | Confirm Button |
|-------|-----------|-------|----------------|
| Attract | 0010 | 1124 | — |
| Title | 0011 | 1308 | START |
| Mode Select | 0012 | 1483 | C selects, UP/DOWN navigates |
| Circuit Select | 0013-0017 | 1714-2508 | LEFT/RIGHT browses, C confirms |
| Car Select | 0018-0020 | 2981-3491 | LEFT/RIGHT = Auto/Manual, C confirms |
| Pre-Race | 0021 | 3870 | — |
| Racing | 0022-0027 | 4253-5323 | LEFT/RIGHT steers |

Note: ARCADE MODE and PRESS START BUTTON text blinks — screenshots may catch
the invisible frame. This is cosmetic, not a replay error.

---

## VERIFIED Annotation Convention

When a function's purpose is empirically confirmed, mark it with a `VERIFIED:`
comment block in the source file. This distinguishes ground truth from guesses.

### Format

```asm
/* VERIFIED: <what this function actually does>
 * Method: <how it was confirmed>
 * Date: <YYYY-MM-DD>
 */
function_name:
```

### Methods

- **watchpoint**: Set memory watchpoint, triggered action, observed writer PC
- **poke**: Modified value in binary, observed effect in game
- **memory-diff**: Dumped memory before/after action, identified changed variable
- **call-trace**: Used call_trace to observe call chain during specific game event
- **breakpoint**: Hit breakpoint during known game state, inspected registers/memory

### Example

```asm
/* VERIFIED: handles DOWN press on mode select menu
 * Method: watchpoint on sym_0605D244, observed PC write when DOWN pressed
 * Date: 2026-02-27
 */
mode_select_handler:
```

### Rules

1. **Only VERIFIED with direct emulator evidence.** Static analysis, Ghidra output,
   and pattern matching do NOT qualify — those remain HIGH confidence at best.

2. **Describe what you observed, not what you infer.** "PC 0x06019762 writes to
   sym_0605D244 when DOWN is pressed" is a fact. "This handles all menu navigation"
   is an inference.

3. **Include enough detail to reproduce.** Another session should be able to re-run
   the test and confirm.

4. **VERIFIED tags survive renames.** If you rename a function, carry the tag forward.

5. **Greppable progress**: `grep -r "VERIFIED:" reimpl/src/ | wc -l`

---

## Name Review Scoreboard

Reviewing all 22 VERIFIED functions for name accuracy. Each gets a critical
look: does the name match what the function *actually does* per the evidence?

| # | Function | File | Verdict | Notes |
|---|----------|------|---------|-------|
| 1 | ~~viewport_coord_calc~~ | controller_input_update.s | RENAMED | -> controller_input_update (+ 3 related renames) |
| 2 | mode_select_handler | mode_select_handler.s | GOOD | Name correct; fixed comments (0x0100=B back, not confirm). Renamed sym_0605AD10 -> g_game_state. |
| 3 | track_seg_phys_init | track_seg_phys_init.s | -- | |
| 4 | button_input_read | button_input_read.s | -- | |
| 5 | car_select_input | car_select_input.s | -- | |
| 6 | state_car_select_active | state_car_select_active.s | -- | |
| 7 | race_countdown_timer | race_countdown_timer.s | -- | |
| 8 | transition_medium_a | transition_medium_a.s | -- | |
| 9 | player_physics_main | player_physics_main.s | -- | |
| 10 | gear_shift_handler | gear_shift_handler.s | -- | |
| 11 | collision_passive (friction_stub) | collision_passive.s | -- | |
| 12 | accel_response | accel_response.s | -- | |
| 13 | player_collision | player_collision.s | -- | |
| 14 | track_position_calc (heading_smooth_gentle) | track_position_calc.s | -- | |
| 15 | ai_speed_trampoline | ai_speed_trampoline.s | -- | |
| 16 | track_segment_advance | track_segment_advance.s | -- | |
| 17 | track_pos_query | track_pos_query.s | -- | |
| 18 | per_frame_update | per_frame_update.s | -- | |
| 19 | clip_region_test | clip_region_test.s | -- | |
| 20 | render_orchestrator | render_orchestrator.s | -- | |
| 21 | vdp1_display_submit | vdp1_display_submit.s | -- | |
| 22 | ~~hud_element_draw~~ | hud_sound_trigger.s | RENAMED | → hud_sound_trigger. Only calls sound_cmd_dispatch. Zero drawing code. |
| 23 | ~~transform_matrix~~ | mat_rot_x.s | RENAMED | → mat_rot_x. X-axis rotation, same pattern as mat_rot_y/mat_rot_z. |
| 24 | ~~ai_section_transition~~ | game_update_loop.s | RENAMED | → cd_block_read_safe. Reads CD Block CR1-CR4 (0x25890018-24), not AI. |
| 25 | ~~ai_section_update~~ | game_update_loop.s | RENAMED | → cd_block_read_atomic. Inner interrupt-masked double-read helper. |

**Progress: 6/25** (5 renamed, 1 confirmed good, 19 pending)

### Working Theories (unverified, tracking as we go)

- **sym_06059F44**: Likely `g_vblank_out_count` — cleared to 0 by mode_select_handler on B press, written by vblank_out_handler. Needs direct watchpoint evidence to confirm.

---

## Investigation Targets

### Priority 1: Menu Input Handlers (known game states, easy to trigger)

- [x] Mode Select DOWN handler → `mode_select_handler` (2026-02-27, watchpoint)
- [x] Mode Select UP handler → `mode_select_handler` (2026-02-28, watchpoint)
- [ ] Mode Select C (confirm) → originally attributed to `car_select_setup` but PC trace shows 0 hits; VERIFIED tag struck
- [ ] Circuit Select LEFT/RIGHT handler — handler code reuses mode_select_handler, browsing done by dispatched renderer
- [x] Circuit Select C (confirm) → activates `race_countdown_timer` (2026-02-28, call-trace)
- [x] Car Select input → `car_select_input` writes sym_06085FF0 (2026-02-28, call-trace)
- [x] Car Select C (confirm) → activates `transition_medium_a` (2026-02-28, call-trace)

### Priority 2: Race Input Handlers (need to reach racing state)

- [x] Physics pipeline → `player_physics_main` + 6 sub-functions (2026-02-28, call-trace)
- [x] Button state writer → `controller_input_update` writes g_pad_state (2026-02-28, watchpoint)
- [ ] Steering input reader — which function reads LEFT/RIGHT and applies to heading
- [ ] Gas (acceleration) handler — targeted investigation pending
- [ ] Brake handler
- [ ] View change handler

### Priority 3: Game State Variables

- [x] Mode select index → sym_0605D244 at runtime 0x0605D1FC (2026-02-28, watchpoint)
- [x] Mode select counter → sym_0605D242 (2026-02-28, memory-diff)
- [x] Mode select animation timer → sym_0605D243 (2026-02-28, memory-diff)
- [x] Player car struct → sym_06078900 (87 bytes change during steering) (2026-02-28, memory-diff)
- [ ] Lap counter — what writes it, what triggers increment
- [ ] Position display (39/40 etc.) — what computes it
- [ ] Speed display — what feeds the speedometer
- [ ] Timer — what decrements it

### Priority 4: Rendering Pipeline (harder, need poke methodology)

- [ ] Which function actually draws the car sprite on screen
- [ ] VDP1 command list builder for car rendering
- [ ] HUD rendering (speed, position, lap, timer)

---

## Completed Investigations

### mode_select_handler (2026-02-27)

**Method**: Watchpoint on sym_0605D244 (menu selection index)
**Result**: PC at mode_select_handler writes to selection variable when DOWN pressed
**Action**: Renamed course_select_render → mode_select_handler
**Status**: VERIFIED, committed

### orientation_sincos → audio panning (2026-02-27)

**Method**: Poke — forced orientation angle to zero in render_orchestrator
**Result**: Car engine sound stopped, no visual change
**Conclusion**: sym_0602EFCC feeds audio system (spatial sound panning), not rendering
**Status**: VERIFIED (documented in car_flip_benchmark.md, not yet tagged in source)

---

### Batch investigation run (2026-02-28)

**Tool**: `tools/investigate.py all` — 4 game states, watchpoints + call trace diffs + memory diffs
**Critical fix**: Symbol address resolution — retail addresses in symbol names (e.g. sym_0605D244)
differ from runtime addresses in free build (e.g. 0x0605D1FC). All lookups now use the linker map.

#### Mode Select (watchpoint evidence)

| Finding | Method | Evidence |
|---------|--------|----------|
| mode_select_handler handles DOWN + UP | watchpoint on sym_0605D244 | DOWN: PC=0x0601975A writes index; UP: PC=0x060197B8 writes index |
| ~~car_select_setup sets init flag on C~~ | ~~watchpoint on sym_06085FF1~~ | STRUCK — PC trace shows 0 hits in 441K instructions. Watchpoint evidence was at wrong address or misattributed. |
| track_seg_phys_init clears init flag | watchpoint on sym_06085FF1 | PC=0x06019A16 writes 1→0 after loading display lists |
| sym_06028400 called 13x more during DOWN | call-trace | Only function with increased calls during DOWN press |

#### Circuit Select (call-trace evidence)

| Finding | Method | Evidence |
|---------|--------|----------|
| race_countdown_timer activated on C | call-trace | 9 calls during C, 0 during idle [NEW] |
| Memory scan 0x0605D100-0x0605D300 found nothing for RIGHT | memory-diff | Circuit index not in this region |
| fpmul/sincos_pair/sprite_anim_render increase during RIGHT | call-trace | 3D preview animation response |

#### Car Select (call-trace evidence)

| Finding | Method | Evidence |
|---------|--------|----------|
| transition_medium_a activated on C | call-trace | 13 calls during C, 0 during idle [NEW] |
| loc_06031CC4+0x56 massive increase during RIGHT | call-trace | +2344 calls — likely car model rendering |
| Memory scan 0x0605D100-0x0605D300 found nothing for RIGHT | memory-diff | Car index (sym_06085FF0) is elsewhere |

#### Racing (call-trace + watchpoint + memory-diff evidence)

| Finding | Method | Evidence |
|---------|--------|----------|
| player_physics_main pipeline: 6 sub-functions run 3x more during steering | call-trace | All show +78 delta (39→117 calls during LEFT) |
| Physics sub-functions: gear_shift_handler, friction_stub, accel_response, player_collision, heading_smooth_gentle, ai_speed_trampoline, track_segment_advance, track_pos_query | call-trace | Same +78 delta confirms batch invocation |
| controller_input_update writes button state struct | watchpoint on g_pad_state | 4 PCs within function write during LEFT |
| sym_06078900 = player car struct | memory-diff | 87 bytes change during LEFT steering |
| Rendering pipeline increase during steering | call-trace | transform_pipeline, scene_render_alt, mat_vec_transform, render_list_builder all increase |
| Math functions spike during steering | call-trace | fpmul +496, fpdiv_setup +196, atan_piecewise +186, atan2 +182 |

**Total VERIFIED tags added**: 19 files (was 1)
**Status**: All tags validated — 3-class build validation PASS
