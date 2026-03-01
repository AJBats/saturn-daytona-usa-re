# Review #6: state_car_select_active → FUN_06008B9C

**Verdict**: RENAMED — VERIFIED claim contradicts its own data
**Date**: 2026-03-01

## Original Claim

Name `state_car_select_active` implied this is the per-frame handler for the car select screen.
VERIFIED tag said: "active during car select screen (called after mode select C press),
runs every frame during car select state. Not present in idle mode select frames,
appears only after transition."

## Structural Analysis

Simple dispatcher at section .text.FUN_06008B9C (retail 0x06008B9C, free 0x06008BA0):
1. Calls FUN_06019A48 (formerly car_select_input — renamed in review #5)
2. Calls FUN_06019928 (formerly track_seg_phys_init — renamed in review #3)
3. Calls sym_06026CE0
4. Writes 0 to sym_06059F44
5. Returns

Referenced from _start.s:70 — a game state function pointer dispatch table. The table
contains ~30 state_* entries indexed by g_game_state. This function sits at table index
that would correspond to one of the menu states.

Pool also contains unreferenced entries: g_game_state, car_select_setup, sym_0605A016.
These are constant pool data that happen to be in the section but are not loaded by
any instruction in this function.

## Evidence Against the Name

### 1. Breakpoint didn't fire at car select (from review #5, Experiment 4)

Breakpoint at 0x06008BA0, frame 3100 (g_game_state = 0x0D = car select):
- frame_advance(3) completed all 3 frames
- Function was NOT called at car select state

### 2. VERIFIED comment contradicts its own call-trace data

The VERIFIED tag says: "Not present in idle mode select frames"
Investigation_log line 88: `06008BA0 (state_car_select_active): 12x (baseline 10x, +2)`

Baseline 10x during 10 idle frames = called once per frame DURING idle mode select.
The function IS present in idle mode select frames. The VERIFIED comment is wrong
about its own evidence.

### 3. +2 delta is noise

Same +2 delta as ~25 other functions. C press causes a state transition which adds
~2 extra frames of processing. Not evidence of car-select-specific behavior.

### 4. Both primary callees already renamed

- FUN_06019A48 (review #5): could not observe input processing at any game state
- FUN_06019928 (review #3): no evidence of car select or track segment initialization

If the callees aren't car-select-related, the caller naming is doubly suspect.

## What We Know

- Address: 0x06008B9C (retail), 0x06008BA0 (free)
- Section: .text.FUN_06008B9C
- Dispatch table entry in _start.s:70
- Called every frame at g_game_state = 0x07 (mode select), NOT at 0x0D (car select)
- Simple dispatcher: calls 3 functions sequentially, clears one variable, returns

## Lesson

**Read your own data.** The VERIFIED comment says "not present in idle" but the call-trace
baseline is 10 — meaning exactly 10 calls in 10 idle frames. The LLM that wrote the
VERIFIED tag didn't check whether its data supported its conclusion.
