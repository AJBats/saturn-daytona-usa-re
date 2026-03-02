# Car Flip Benchmark

Escalating modifications that prove deepening understanding of the game code.
Each goal targets a specific subsystem. All changes are local to that subsystem —
no upstream input remapping, no global hacks.

## Goals

1. **Invert menu navigation** — UP goes down, DOWN goes up on mode select screen.
   Local to mode select input handling, not the button read layer.
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
