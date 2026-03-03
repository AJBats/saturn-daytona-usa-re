# Car Flip Benchmark

Escalating modifications that prove deepening understanding of the game code.
Each goal targets a specific subsystem. All changes are local to that subsystem —
no upstream input remapping, no global hacks.

## Goals

1. ~~**Invert menu navigation**~~ DONE (2026-03-01) — UP goes down, DOWN goes up on mode select screen.
   Local to mode select input handling, not the button read layer.
   - File: `reimpl/src/mods/re_tests/mode_select_handler.s`
   - Build: `make RE_TESTS=1 MODS=1 disc`
   - Method: swapped button masks in pool entries (DOWN handler checks UP mask 0x1000,
     UP handler checks DOWN mask 0x2000). Added local pool entries for 3 cross-TU
     references that the original borrowed from neighboring functions.
   - **Key discovery — split prologue/epilogue**: `course_select_input` (12 bytes at
     FUN_060196A4) pushes r10-r14 and falls through into `mode_select_handler` with no
     return. The handler's epilogue pops all 5 registers. This means C reimplementation
     is NOT possible without accounting for the shared stack — the C compiler generates
     its own isolated prologue/epilogue, leaving 20 bytes of caller-pushed registers
     stranded on the stack (SP corruption -> Address Error). A C attempt crashed at
     PC=0x060281F8 (DMA interrupt handler hit with misaligned SP).
   - **Lesson: MODS=1 required for ANY resized build**, not just +4 shift. Changing
     function size shifts cache-line timing and triggers the SCDQ infinite poll bug
     (black screen on boot).
2. ~~**Swap C/B on circuit select**~~ DONE (2026-03-01) — B confirms (old C), C backs out (old B).
   Local to circuit select confirm/back handler only. Mode select C-confirm is unaffected.
   - File: `reimpl/src/mods/re_tests/circuit_confirm_handler.s` (NOTE: misnamed — see learnings)
   - Build: `make RE_TESTS=1 MODS=1 disc`
   - Method: swapped two button masks in pool constants:
     - BACK mask at 0x0601030C: 0x0100 (B) → 0x0200 (C)
     - CONFIRM mask at 0x0601038C: 0x0200 (C) → 0x0100 (B)
   - **Call chain**: `game_state_dispatch` → `transition_handler_a` → `circuit_confirm_handler` (FUN_060102EA)
     - `transition_handler_a` reads button word from `g_pad_state+2`, passes to two inline handlers
     - FUN_060102A8: circuit LEFT/RIGHT (increments/decrements circuit index 0-2)
     - FUN_060102EA: circuit confirm/back (checks button masks from pool constants)
   - **Button bit mapping** (empirically confirmed from `g_pad_state+2`):
     A=0x0400, B=0x0100, C=0x0200, START=0x0800, LEFT=0x4000, RIGHT=0x8000, UP=0x1000, DOWN=0x2000
   - **Key discovery — per-screen button handling**: Each screen has its OWN handler with its
     own pool constants. C confirms on mode select but backs out on circuit select — different
     functions, different masks. There is no global "confirm button" setting.
   - **Key discovery — `circuit_confirm_handler` is misnamed**: FUN_060102EA handles circuit select
     confirm/back, not speedometer anything. Better name: `circuit_confirm_handler`.
     Similarly FUN_060102A8 handles circuit LEFT/RIGHT navigation. Both are named from blind
     LLM annotation — the function names are guesses that turned out wrong.
   - **Lesson — Ghidra C reference is essential**: Reading Ghidra decompilation output
     (`ghidra_reference/FUN_060102EA.c`) made the control flow and mask values immediately
     clear. Without it, decoding unelevated SH-2 opcodes (raw `.4byte` data blobs) took
     hours. With it, the mod was a 5-minute job.
   - **Lesson — save states overwrite WRAM code**: Can't use vanilla save states to test
     code mods. The save state restores original code into WRAM, overwriting the mod.
     Must boot from scratch or create a new save state from the modded build.
   - Investigation scripts: `workstreams/car_flip_benchmark/`
   - Trace: `call_graphs/circuit/full_interactive_trace.txt`
3. ~~**Invert steering**~~ DONE (2026-03-02) — LEFT steers right, RIGHT steers left.
   Local to the steering dispatch in `steering_input_dispatch`, not the input read layer.
   - File: `reimpl/src/mods/re_tests/steering_input_dispatch.s`
   - Build: `make RE_TESTS=1 MODS=1 disc`
   - Method: swapped two button masks in pool constants:
     - `DAT_06006804`: 0x4000 (LEFT) → 0x8000 (RIGHT)
     - `.L_06006830`: 0x00008000 (RIGHT) → 0x00004000 (LEFT)
   - **Steering pipeline**: `steering_input_dispatch` writes LEFT/RIGHT masks to `sym_06063F48`
     and `sym_06063F4A`. Downstream physics reads those addresses to steer.
     The game already has a built-in swap flag (`sym_06078663`) for split-screen/viewport
     side — we bypassed it and swapped the masks feeding into it instead.
   - **`sym_06078663` is a player-side flag**: Referenced by 15+ functions (camera,
     rendering, track geometry, perspective projection, HUD). Not just steering — it
     controls which side of the screen a player is on.
   - **Technique locked in**: Same playbook as Goals 1 & 2 — call-trace differential →
     Ghidra C to read candidates → find pool constants → swap → first-try success.
     Three for three.
4. ~~**Flip car select models upside down**~~ DONE (2026-03-02) — both spinning car models on
   the car select screen tumble around the X axis (head-over-tail) instead of the normal Y
   turntable spin. Demonstrates understanding of the 3D matrix pipeline across both CPUs.
   - Files: `reimpl/src/mods/re_tests/vdp_mode_select.s` (primary SH-2),
     `reimpl/src/mods/re_tests/race_position_track.s` (secondary SH-2),
     `reimpl/src/mods/re_tests/graphics_mode_setup.s` (spin setup)
   - Build: `make RE_TESTS=1 MODS=1 disc`
   - Method: swapped rotation function pointers in pool constants (zero-cost, same as Goals 1-3):
     - `vdp_mode_select.s` `.L_06010EB0`: `mat_rot_y` → `mat_rot_x` (primary SH-2)
     - `race_position_track.s` `.L_06011030`: `mat_rot_xy_b` → `mat_rot_xz_b` (secondary SH-2)
   - **Key discovery — corrected rotation function naming**:
     - `mat_rot_y` (FUN_06026EDE) = Y-axis turntable rotation (modifies cols 0,2). This is what
       the vanilla car select calls for the normal left/right spin.
     - `mat_rot_x` (FUN_06026E94) = X-axis rotation (modifies cols 1,2). Causes forward/backward
       tumble, showing car underside and top.
     - Prior VERIFIED tags had mat_rot_x and mat_rot_y naming correct, but the _b variants
       (secondary SH-2) follow the same axis convention.
   - **Key discovery — screenshot methodology was broken**: ALL prior "zero pixel difference"
     results (Tests 4C-4G) were invalid. Two bugs:
     1. Screenshot overwrite: `os.path.exists()` found pre-existing files and reported "saved"
        without capturing new screenshots. Both baseline and modified used the SAME stale files.
     2. RE_TESTS navigation: With Goal 2 active, C backs out on circuit select → game returned
        to mode select → screenshots showed wrong screen.
     Fixed in `tools/test_car_select_screenshot.py`: pre-deletes old screenshots, `--re-tests`
     flag uses B to confirm on circuit select.
   - **Lesson — size-neutral modifications are the only viable approach**: Binary is exactly at
     the 394,896-byte limit. Function pointer swaps and pool constant changes are zero-cost.
     Adding even 4 bytes of code causes boot failure.

   **Pipeline (discovered via call graph + Ghidra C):**
   ```
   PRIMARY SH-2:
     FUN_06010BC4 (graphics_mode_setup) — sets camera params, spins angle, triggers secondary
       → sym_06078850/54/58 = camera X/Y/Z for secondary SH-2
       → sym_06078878 += 0x0100 each frame (spin angle, ~1.4°/frame)
       → sym_06063574 = race_position_track (secondary SH-2 callback)
       → FUN_06010D94 = primary SH-2 camera/matrix setup

   SECONDARY SH-2:
     race_position_track — 4 passes per frame
       → sym_060270F2(X, Y, Z) — camera offset × rotation matrix → translation
       → mat_rot_xy_b(angle) — apply spin rotation
       → sym_06032158 — vertex transform setup
       → sym_06031DF4 → FUN_060320E6 (×364/frame) — per-polygon vertex transform
       → sym_06027080 — matrix push, next sub-object
       → VDP1 end command 0xFFFF
   ```

   **Key pool constants in graphics_mode_setup.s (unlocked path):**
   | Label | Value | Meaning |
   |-------|-------|---------|
   | `.L_06010D84` | 0x00038000 | Camera X for secondary SH-2 (+3.5) |
   | `.L_06010D88` | 0xFFFF0000 | Camera Y (-1.0) — shared with FUN_06010D94 |
   | `.L_06010D8C` | 0x0006B333 | Camera Z (+6.7) — shared with FUN_06010D94 |
   | `.L_06010D90` | 0xFFFC8000 | Camera X for FUN_06010D94 (-3.5) |
   | `.L_06010C50` | 0x0100 | Spin angle increment per frame |

   **Car select state variable:** `sym_0607EADC` (car index, 0-N depending on mode).
   Handled by FUN_060104E0: RIGHT (0x8000) increments, LEFT (0x4000) decrements.

   ### Coordinate system (mapped via experiments 4A-4D)

   | Axis | Direction | Value | Notes |
   |------|-----------|-------|-------|
   | X | Horizontal (car placement) | ±3.5 (0x00038000/0xFFFC8000) | Positive = right |
   | Y | Vertical | -1.0 (0xFFFF0000) | Negative = normal height |
   | Z | Depth (viewing distance) | +6.7 (0x0006B333) | Positive = away from camera |
   | Spin | Counter-clockwise | +0x0100/frame (~1.4°/frame) | 0x10000 = 360° |

   ### Dual-CPU rendering (discovered via test 4F)

   The two cars on the arcade car select screen are rendered by DIFFERENT CPUs:
   - **Left car (auto transmission)**: Primary SH-2 via `FUN_06010D94`
   - **Right car (manual transmission)**: Secondary SH-2 via `race_position_track`

   Each has its own rotation call and camera params. Modifying `race_position_track`
   only affects the right car.

   ### Rotation function variants (discovered via static analysis + empirical test)

   **Primary SH-2** (called by `vdp_mode_select` for left car):
   | Function | Address | Modifies cols | Leaves col | Rotation axis |
   |----------|---------|--------------|------------|---------------|
   | `mat_rot_x` | FUN_06026E94 | 1,2 (Y,Z) | 0 (X) | Around X (tumble) |
   | `mat_rot_y` | FUN_06026EDE | 0,2 (X,Z) | 1 (Y) | Around Y (turntable) |
   | FUN_06026F2A | FUN_06026F2A | 0,1 (X,Y) | 2 (Z) | Around Z |

   **Secondary SH-2** (called by `race_position_track` for right car):
   | Function | Modifies cols | Leaves col | Rotation axis |
   |----------|--------------|------------|---------------|
   | `mat_rot_xy_b` | 0,2 (X,Z) | 1 (Y) | Around Y (turntable spin) |
   | `mat_rot_yz_b` | 0,1 (X,Y) | 2 (Z) | Around Z |
   | `mat_rot_xz_b` | 1,2 (Y,Z) | 0 (X) | Around X (tumble) |

   ### Experiments

   **Test 4A: Negate camera Y** — `.L_06010D88`: 0xFFFF0000 → 0x00010000
   Result: **Cars moved WAY higher on screen.** Y controls vertical position. ✓

   **Test 4B: Negate camera Z** — `.L_06010D8C`: 0x0006B333 → 0xFFF94CCD
   Result: **Cars disappeared.** Z is depth — negating it put models behind the camera. ✓

   **Test 4C: Reverse spin** — `.L_06010C50`: 0x0100 → 0xFF00
   Result: **Cars spin clockwise** (retail is counter-clockwise). Spin direction confirmed. ✓

   **Test 4D: Swap camera X** — `.L_06010D84`: 0x00038000 ↔ `.L_06010D90`: 0xFFFC8000
   Result: **Two cars swapped positions.** Auto (yellow) appeared under manual's spot and
   vice versa. X controls horizontal car placement. ✓

   **Test 4E: Zero camera Y** — `.L_06010D88`: 0xFFFF0000 → 0x00000000
   Not tested (superseded by 4A result).

   **Test 4F: X-axis tumble** — `race_position_track` pool: `mat_rot_xy_b` → `mat_rot_xz_b`
   Result: **Right car (manual) tumbles forward/backward around X axis.** Left car (auto)
   still spins normally — confirmed dual-CPU rendering. ✓

   **Test 4G: Spin + flip (wrapper function)** — New `mat_rot_xy_flipped` wrapper
   Result: **Crash.** New function placed at 0x0606368c (past original binary end) — that
   memory is used for runtime data and gets overwritten. Identity wrapper also crashed,
   confirming the address is the problem, not the logic.

   **Test 4G v2: Inline matrix flip** — Added 24 bytes to `race_position_track` to negate
   rows 1+2 of the transform matrix after Y-spin.
   Result: **Black screen.** Growing the function shifted the binary layout, likely triggering
   the SCDQ boot hang or breaking section placement.

   **Test 4H: X-axis tumble (both CPUs)** — PRIMARY: `mat_rot_y` → `mat_rot_x`, SECONDARY: `mat_rot_xy_b` → `mat_rot_xz_b`
   Result: **Both cars tumble forward/backward around X axis.** Dramatic visual change — cars show
   their undersides and tops during each revolution. All 3 screenshot frames different from vanilla.
   Size-neutral (pool constant swap only). **This is the final Goal 4 configuration.** ✓

   **Test 4I: Static 180° upside-down** — `graphics_mode_setup.s`: spin_speed=0x8000, `add r6,r3` → `mov r6,r3`
   Result: **Cars are statically upside-down.** Frozen at 180° X rotation. Both screenshot frames
   identical (angle freeze works). Demonstrates precise angle control. Size-neutral (`mov` = 2 bytes
   like `add`). Reverted in favor of 4H as primary demonstration. ✓

   ### Key constraint — Binary size limit (root-caused 2026-03-02)

   **The binary cannot exceed 394,896 bytes (0x60690).** The original APROG.BIN loads
   into WRAM at 0x06003000-0x06063690. The first runtime data variable is `sym_06063690`.
   CD sector zero-padding after the binary serves as zero-initialization for runtime
   variables. If the binary grows past 394,896 bytes, code overwrites runtime variables
   (sym_06063690 = motion blur, obj template init, screen fade) → black screen on boot.

   **Empirical evidence (binary search):**
   | Config | Size | vs Original | Result |
   |--------|------|-------------|--------|
   | MODS only | 394,880 | -16 | PASS |
   | 4-byte NOP | 394,884 | -12 | PASS |
   | 16-byte NOP / SHIFT=16 | 394,896 | 0 | PASS |
   | 20-byte NOP / SHIFT=20 | 394,900 | +4 | FAIL |
   | 24-byte NOP | 394,904 | +8 | FAIL |

   **SHIFT=20 also fails** — uniform shift, no non-uniform distortion. Pure size issue.

   **Guard added**: `free.ld` ASSERT catches overflow at link time.

   **Size budget**: SCDQ fix (MODS=1) saves 16 bytes. Net headroom for code growth: 16 bytes.
   Goals 1-3 used 12 bytes (local pool entries in mode_select_handler), leaving 4 bytes.
   Goal 4 inline flip needs ~24+ bytes — exceeds budget by 8+ bytes.

   **Implication**: Goals 1-3 succeeded by changing pool CONSTANTS — same size, no layout shift.
   Goal 4 requires either:
   1. A size-neutral approach (constant-only, like Goals 1-3)
   2. Compressing another function to create headroom
   3. Hijacking an existing code path (no new code)

5. **Flip car graphics upside down** — all cars appear to drive on their roofs.

## Prior Art

Three blind experiments (2026-02-27) targeting the car flip directly all failed:
1. Negated Y base constants in `perspective_project` — no effect
2. Forced orientation angle to zero in `render_orchestrator` — killed audio, not visual
3. Swapped `mat_rot_y` to `mat_rot_z` in `pre_render_transform` — no effect

Lesson: static analysis guesses about the rendering pipeline were wrong.
This time we use instrumentation (CDL, call traces, watchpoints, mem_profile)
to observe the actual code before modifying anything.
