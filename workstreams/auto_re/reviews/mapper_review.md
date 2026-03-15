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

   **Break this into three small tests.** Each proves or disproves one
   piece independently. Add these to Explorer priorities:

   **Test A — Camera follows heading (proves a and c):**
   NOP position writer (poke 0602EF9E 00 09). Hold C + LEFT for 60
   frames. Read car[+0x20] (heading). If heading changed from the
   initial value, camera rotation is explained: camera reads heading,
   heading changes normally, car graphic stays frozen. One `read_u32`
   at 0x06078920 proves or disproves it.

   **Test B — Surface fields freeze after segment boundary (proves link 2):**
   Two runs, both C held for 200 frames: baseline and NOPped position
   writer. Use `sample_memory` to capture +0xF4 and +0x1FC every frame
   in both runs. If surface fields go flat after frame ~106 in the
   NOPped run while baseline keeps changing, link 2 is proven. The
   existing CSVs (tt_baseline_200f.csv, tt_nopped_poswriter_200f.csv)
   may already contain this data — check before recapturing.

   **Test C — Stale surface causes acceleration change (proves link 3):**
   Compare +0xFC (accel delta) frame-by-frame between the NOP and
   baseline CSVs. Values should be IDENTICAL until the frame where
   surface fields diverge, then start differing. The first frame where
   +0xFC diverges should match (within 1-2 frames of) the frame where
   surface fields froze in Test B. If they match, the causal chain is
   proven. If +0xFC diverges at a different frame, something else
   caused the acceleration change.

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
