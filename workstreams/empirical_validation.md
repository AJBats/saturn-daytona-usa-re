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
| `tools/prove_down_handler.py` | Template: watchpoint-based input handler discovery |
| `tools/find_menu_input.py` | Template: memory-diff + watchpoint approach |
| `build/golden_trace/` | Reference trace + 18 screenshots covering full arcade flow |

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

## Investigation Targets

### Priority 1: Menu Input Handlers (known game states, easy to trigger)

- [x] Mode Select DOWN handler → `mode_select_handler` (2026-02-27)
- [ ] Mode Select UP handler
- [ ] Mode Select C (confirm) handler
- [ ] Circuit Select LEFT/RIGHT handler
- [ ] Circuit Select C (confirm) handler
- [ ] Car Select LEFT/RIGHT handler
- [ ] Car Select C (confirm) handler

### Priority 2: Race Input Handlers (need to reach racing state)

- [ ] Steering LEFT/RIGHT handler
- [ ] Gas (acceleration) handler
- [ ] Brake handler
- [ ] View change handler

### Priority 3: Game State Variables

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
