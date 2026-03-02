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
2. **Swap A/B on course select** — A backs out (old B), B confirms (old A).
   Local to course select input handling only.
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
