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
3. **Invert steering** — D-pad LEFT steers right, RIGHT steers left.
   Local to the driving model, not input processing.
4. *(more goals TBD as we learn)*
5. **Flip car graphics upside down** — all cars appear to drive on their roofs.

## Prior Art

Three blind experiments (2026-02-27) targeting the car flip directly all failed:
1. Negated Y base constants in `perspective_project` — no effect
2. Forced orientation angle to zero in `render_orchestrator` — killed audio, not visual
3. Swapped `mat_rot_y` to `mat_rot_z` in `pre_render_transform` — no effect

Lesson: static analysis guesses about the rendering pipeline were wrong.
This time we use instrumentation (CDL, call traces, watchpoints, mem_profile)
to observe the actual code before modifying anything.
