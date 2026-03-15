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

4. **[HIGH]** Dual position theory disproval is accepted (the mechanism is
   wrong — there is no internal position field). BUT the alternative
   explanation for the human's observations has NOT been proven. The human
   observed three specific things during the sym_0602D8BC NOP test:

   **(a)** Camera rotated as if following a turn when LEFT/RIGHT pressed.
   **(b)** Acceleration behavior changed — felt like being on grass.
   **(c)** At rest, camera pointed in a direction consistent with being
   elsewhere on the track.

   The Explorer's data shows heading (+0x20) evolves identically in both
   runs. This plausibly explains (a) and (c) — camera follows heading, car
   graphic stays frozen, creating the illusion of turning. But this is an
   inference, not a proof. **Prove it**: show which fields the camera system
   reads, confirm it reads +0x20 (heading) and +0x10/+0x18 (position), and
   demonstrate that heading-change-with-frozen-position produces the observed
   camera behavior.

   For (b), the claim is "track segments freeze at frame ~106, which changes
   surface properties, which changes the acceleration curve." This is a
   three-link causal chain with zero proof at any link:
   - Link 1: Track segments freeze → SHOWN (fields diverge at frame 106)
   - Link 2: Frozen segments → surface fields stop updating → NOT PROVEN
   - Link 3: Stale surface fields → acceleration change → NOT PROVEN

   **Design an experiment** that proves links 2 and 3. For example: in the
   NOPped run, compare +0xEC/+0xF0/+0xF4/+0x1FC values before and after
   frame 106. If surface fields truly freeze when segments freeze, they
   should show constant values after frame 106 while the baseline continues
   changing. Then show that these stale surface values feed into the force
   accumulator differently — producing the acceleration change the human felt.

   Dismissing a human observation with "it's consistent with" is not
   sufficient. The alternative explanation must be empirically demonstrated.
   Root-cause this.

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
