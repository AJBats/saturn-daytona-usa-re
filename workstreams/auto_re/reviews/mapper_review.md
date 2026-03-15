# Mapper Review — 2026-03-15 (Review 2)

## Action Items

1. **[HIGH]** FUN_0602CCEC NOP test still has no poke address. The
   recommendation says "ask human to disassemble at 0x0602CC4C area."
   This is the Mapper's job — read the assembly in reimpl/src/, compute
   the BSR target address, and verify in live memory (same methodology as
   the confirmed NOP tests). Don't punt address derivation to the human.

2. **[MED]** The FUN_0602EFF0 and FUN_0602F5B6 NOP tests revealed unexpected
   pipeline dependencies (both killed throttle). The Mapper noted this in
   cycle 27 and 30 but hasn't traced the dependency chains:
   - What does FUN_0602EFF0 write that the force accumulator reads?
   - What does FUN_0602F5B6 write that the force accumulator reads?
   Cross-reference the write sets against FUN_0602CA84's read set. This
   reveals the pipeline coupling architecture — critical for transplant.

3. **[LOW]** 17/18 pipeline calls at Tier 2. Identify the remaining call
   and prioritize it for the Explorer if observation is missing.

## Dual Position Theory — Review

**The disproval is SOUND.** The Explorer's methodology (200-frame full struct
comparison, NOP vs baseline) is rigorous. Key evidence:

- ALL physics fields identical with/without position writer
- Position is write-only terminal output (not read by upstream pipeline)
- +0x140/+0x144 confirmed NOT internal position (identical in both runs)
- Track segment freeze at frame ~106 explains the human's observation of
  changed acceleration behavior (surface data stops advancing, not a ghost car)

The Mapper correctly integrated this: removed dual position from struct map,
replaced with "position is write-only output" finding. The camera rotation
the human observed is explained by heading (+0x20) updating normally — camera
follows heading, creating the illusion of turning while the car graphic stays
fixed. No dual position system needed.

**One nuance to document**: The human's "surface changed as if on grass"
observation is more precisely "surface properties stopped advancing because
track segments froze." The car didn't reach grass — the segment freeze at
frame ~106 changed the acceleration curve. This distinction matters for
understanding the track segment system's role.

## What's Working Well

- Dual position integration was immediate and correctly scoped (cycle 30).
- 4 new NOP test recommendations produced (addressing previous review's
  #1 HIGH item). All had verified poke addresses except FUN_0602CCEC.
- sym_0602FDA4 identification as throttle input handler was a breakthrough.
  Pipeline is now traced end-to-end: button → throttle accumulator → force
  → accel delta → speed → position.
- Previous review action items addressed in cycle 21 (NOP tests, stale
  priorities, +0xFC test superseded).
- Phase progression: solidly in Phase 2 (pipeline tracing), approaching
  Phase 3 (sim-level understanding) for the speed pipeline.
