# Explorer Review — 2026-03-15 (Review 2)

## Action Items

1. **[HIGH]** The FUN_0602EFF0 NOP test killed both steering AND throttle.
   The observation says "does NOT process throttle — only steering" but the
   NOP test proves it initializes state the force pipeline depends on. The
   observation file needs updating to reflect this — add a section noting the
   NOP result contradicts the "steering only" characterization. What state
   does FUN_0602EFF0 write that FUN_0602CA84 reads? Cross-reference the
   write set (+0xB0, +0xB4, +0x78, +0x94) against FUN_0602CA84's read set.

2. **[MED]** sym_0602FDA4 observation says "Per-frame field analysis deferred
   (body is 300+ instructions)." This is the THROTTLE INPUT HANDLER — the
   most important discovery this cycle. The field analysis should not be
   deferred. At minimum, sample car[+0x74] (throttle accumulator) across
   idle vs C-held to characterize the +10/frame ramp behavior.

3. **[LOW]** Duplicate observation files still exist: both FUN_0602D8BC_obs.md
   and sym_0602D8BC_obs.md. Previous review flagged this — still unresolved.

## What's Working Well

- The dual position NOP experiment (cycle 23) is exemplary methodology —
  full struct comparison, 200 frames, every field checked, clean explanation
  of the human's observations. This is the standard for future NOP analysis.
- sym_0602FDA4 discovery (throttle input handler) closes the biggest gap in
  the pipeline. Excellent call-chain tracing.
- Previous review action items addressed promptly (field analysis tables
  added to FUN_0602EFF0 and FUN_0602CCEC in cycle 17).
