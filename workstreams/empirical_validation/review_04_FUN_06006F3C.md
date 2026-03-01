# Review #4: button_input_read → FUN_06006F3C

**Verdict**: RENAMED — reverted to address-based name
**Date**: 2026-03-01

## Original Claim

Name `button_input_read` implied this function reads button input data.
VERIFIED tag said: "called during mode select C press transition (part of every-frame dispatch)."

## Evidence Against

### Watchpoint Experiments on sym_0605B6D8 (the flag word this function reads)

**Experiment 1** — Menu idle, 5 frames:
- 0 writes to sym_0605B6D8, value stays 0x00000000
- Nobody writes the flag during menu idle → function does nothing

**Experiment 2** — DOWN press on menu, 3 frames:
- 0 writes to sym_0605B6D8
- Button presses do NOT cause writes to this address
- This is NOT button data

**Experiment 3** — Racing idle, 3 frames:
- 3 writes per frame cycle:
  1. PC=frame_end_commit+0xDA: 0x00000000 → 0x20000004 (sets bits 29, 2)
  2. PC=frame_end_commit+0xEA: 0x20000004 → 0x28000004 (adds bit 27)
  3. PC=FUN_06006F3C+0x2B6: 0x28000004 → 0x00000000 (clears all)

### Cross-Reference Evidence

- Present in ALL 18 call graph scenarios (common core)
- Called from sym_06000358 (main dispatch loop) every frame
- Zero references to sym_06063D98+2 (the actual button word, written by controller_input_update)
- Outgoing calls during racing: dma_transfer, scene_data_dispatch, sym_06033354
- Outgoing calls during menu: only scene_data_dispatch (when flags set)

## What We Know

- Address: 0x06006F3C (retail), section .text.FUN_06006F3C
- 471 lines, large function with bit-testing dispatch logic
- Pattern: producer-consumer for deferred per-frame work
  - Producer: frame_end_commit sets flag bits in sym_0605B6D8
  - Consumer: FUN_06006F3C tests bits, dispatches DMA/display/scene work, clears word
- During menu (no rendering): flag is always 0, function does nothing
- During racing (active rendering): processes rendering-related flags every frame
- Called from: sym_06000358 (main loop), referenced in engine_init_global.s pool

## Why the Name Was Wrong

The real button input reader is controller_input_update, which writes to g_pad_state
(sym_06063D98+2) every frame via SMPC peripheral data. FUN_06006F3C has zero connection
to button data — it consumes rendering/DMA flags set by frame_end_commit.

The original VERIFIED tag ("called during mode select C press transition") was technically
true but misleading — it's called EVERY frame, not specifically during C press. The +2
call count during C was just the transition adding extra frames.

## Lesson

1. **Check the data source, not just the caller.** The function reads sym_0605B6D8, which
   is written by frame_end_commit (a rendering function), not by input handling code.
   Watchpoints on the consumed variable reveal the true producer.

2. **"Called during X" ≠ "handles X".** A function running during a button press may be
   coincidental if it runs every frame regardless. Call-trace differentials need baseline
   comparison — a +2 on a baseline of 10 is noise, not signal.

3. **Common core functions need extra scrutiny.** Present in all 18 scenarios means it's
   infrastructure, not input-specific. The name should reflect its actual role, not the
   context where it was first observed.
