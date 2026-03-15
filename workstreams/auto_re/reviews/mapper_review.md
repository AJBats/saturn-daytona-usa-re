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

4. **[RESOLVED]** Dual position theory — fully closed by human re-test.

   The human re-ran the sym_0602D8BC NOP test and now agrees with the
   Mapper's explanation. The three original observations are explained:

   **(a)** Camera rotated → **EXPLAINED**: Camera follows heading (+0x20)
   which updates normally. With position frozen, the camera orbits a
   stationary car graphic. At rest, camera settles wherever heading
   stopped — looks like being elsewhere on the track but isn't.

   **(b)** "Grass" feel → **EXPLAINED**: NOT surface change. Steering
   (LEFT/RIGHT) applies lateral forces that tax the force accumulator,
   slowing acceleration. Releasing steering = all force goes forward =
   fast acceleration. Human mistook steering drag for surface friction.
   Track segments freezing at frame ~106 is a secondary effect but NOT
   what the human felt — the primary cause was steering force competition.

   **(c)** Virtual donuts → **EXPLAINED**: Physics computes full turning
   kinematics (heading changes, slip angle, lateral oscillation) but
   position never updates. Camera faithfully chases the heading changes,
   producing the appearance of donuts around a stationary car.

   **No further tests needed.** Tests A/B/C are cancelled — human
   observation directly confirmed the Mapper's no-dual-position conclusion.

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
