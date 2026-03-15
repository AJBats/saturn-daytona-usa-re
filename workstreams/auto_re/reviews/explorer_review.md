# Explorer Review — 2026-03-15

## Action Items

1. **[HIGH]** FUN_0602CCEC observation is missing Per-Frame Field Analysis table.
   The observation has specific values (+0xE0 track force, +0x110 linear decay
   -1474/frame) but no systematic field classification table. The explorer
   program says "an observation without this table is incomplete." Add the
   table — classify +0xE0, +0x110, +0xFC behavior across idle vs throttle.

2. **[HIGH]** FUN_0602EFF0 observation is missing Per-Frame Field Analysis table.
   This is the steering processor — the most interesting fields (+0xAC raw input,
   +0xB0/+0xB4 rotation output) should be sampled across idle vs LEFT-held
   scenarios and classified. Without this, the Verifier can only write
   call_count claims.

3. **[MED]** FUN_0600C010 observation has no field analysis, but this may be
   appropriate (it's a frame orchestrator, not a car struct writer). If it
   does read/write car fields, add a field table. If not, add a brief note
   explaining why field analysis doesn't apply.

4. **[MED]** Duplicate observation files: both `FUN_0602D8BC_obs.md` and
   `sym_0602D8BC_obs.md` exist with the same content. Pick one canonical name
   (sym_0602D8BC matches the NOP test and results.tsv) and remove the duplicate.

## What's Working Well

- Priority compliance is excellent — all Phase 1 high priorities completed in order.
- Verifier questions answered promptly (cycles 5 and 9).
- FUN_0602EEB8 and sym_0602D8BC observations are exemplary — rich 4-scenario
  field analysis tables with clear behavioral classifications.
- The brake scenario observation (cycle 11) was proactive and produced useful
  deceleration curve data even though it wasn't on the priority list.
