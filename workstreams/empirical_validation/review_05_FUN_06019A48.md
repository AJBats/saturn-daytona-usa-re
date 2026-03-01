# Review #5: car_select_input → FUN_06019A48

**Verdict**: RENAMED — cannot reproduce VERIFIED claim
**Date**: 2026-03-01

## Original Claim

Name `car_select_input` implied this function handles button input on the car select screen.
VERIFIED tag said: "active during car select screen (called after mode select C press),
runs every frame during car select state."

## Structural Analysis

The code HAS input handler characteristics:
- Reads g_pad_state+2 (the confirmed button word)
- Checks button masks: 0x0100 (B), 0x2000 (DOWN), unknown third mask
- Modifies sym_06085FF0 as a selection index (0-7, wrapping)
- Can write g_game_state for state transitions
- Lock flag (sym_06085FF3) gates input processing
- Called from state_car_select_active (pool reference)

## Experiments

### Experiment 1: Watchpoint on sym_06085FF0 at car select (frame 3100-3130)

- g_game_state = 0x0D (same value as circuit select)
- Lock flag (sym_06085FF3) = 0 (unlocked)
- DOWN press: **0 watchpoint hits**, sym_06085FF0 unchanged
- LEFT press: **0 watchpoint hits**
- RIGHT press: **0 watchpoint hits**
- C press: g_game_state unchanged (0 hits)
- Memory diff 0x06085F00-0x06086100: **zero changes** during RIGHT

### Experiment 2: Breakpoint on car_select_input at car select (frame 3100)

- Breakpoint at 0x06019A4C (free build address)
- frame_advance(3) completed all 3 frames
- **Function was NOT called** at g_game_state=0x0D

### Experiment 3: Pad state verification

- DOWN press at car select: g_pad_state+2 = 0x2000 (correct bit set)
- RIGHT press at car select: g_pad_state+0 = 0x8000, g_pad_state+2 = 0x0000
  (RIGHT bit not present at offset +2 which the function reads)
- Buttons ARE working — the function just isn't consuming them

### Experiment 4: Watchpoint at mode select (frame 1537)

- g_game_state = 0x07 at mode select
- Investigation_log says car_select_input called 10x/10 idle frames here
- Watchpoint on sym_06085FF0 during DOWN: **2 hits, but from OTHER functions**
  - mode_select_handler+0x9C: sets sym_06085FF1 = 1
  - course_select_draw+0x8C: clears sym_06085FF1 = 0
  - car_select_input did NOT write to this word
- Memory diff 0x06085F00-0x06086100 during idle: **zero changes**

### Experiment 5: Game state mapping

- g_game_state = 0x07 at mode select
- g_game_state = 0x0D at circuit select, car select, AND after circuit C press
- Circuit select and car select share the same g_game_state value

## What We Know

- Address: 0x06019A48 (retail), 0x06019A4C (free build)
- Section: .text.FUN_06019A48
- Called from: state_car_select_active (pool reference)
- The function has input handler code structure but we could NOT observe it
  actually processing any button input at any game state
- The investigation_log showed it called during mode select, but even there
  it didn't write to sym_06085FF0 during button presses
- The function always tail-calls through a function pointer table indexed by sym_06085FF0

## Why the Name Was Wrong

1. **Could not observe input processing.** Despite trying DOWN, LEFT, RIGHT, and C at
   both mode select and car select states, the function never wrote to sym_06085FF0.
2. **Function may not be active at car select.** Breakpoint at car select didn't fire.
   The investigation_log evidence was from mode select (g_game_state=0x07), not car select.
3. **VERIFIED tag's evidence was weak.** "+2 calls during C press" means "runs every
   frame, 2 extra frames from state transition." Not evidence of input handling.
4. **g_game_state doesn't distinguish circuit/car select.** Both use 0x0D. Sub-state
   routing is via a different variable.

## Lesson

1. **"Called from X" doesn't mean "handles X".** Being called from state_car_select_active
   doesn't prove it handles car select input — especially when both the caller name and
   the function name are LLM guesses.

2. **Call-trace call count deltas need context.** A +2 delta on a baseline of 10 is
   within the noise of state transition frame count variance. Only large deltas or
   NEW-only functions are strong signals.

3. **Test at the actual screen.** The golden trace shows LEFT/RIGHT used at car select,
   but RIGHT doesn't even set the button bit at g_pad_state+2 where this function reads.
   The function may be designed for a different input offset or button mapping.

4. **Shared game state values complicate state identification.** g_game_state=0x0D covers
   multiple screens. Need additional variables to distinguish sub-states.
