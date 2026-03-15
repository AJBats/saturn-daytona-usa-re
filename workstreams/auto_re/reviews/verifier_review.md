# Verifier Review — 2026-03-15 (Review 2)

## Action Items

1. **[MED]** Oracle still can't test brake scenarios (hardcoded straight_throttle
   from 0 mph). Previous review flagged this. sym_0602FDA4 observation now
   confirms brake pipeline exists (B button → car[+0x90]). Brake testing is
   increasingly important — escalate to human if oracle tool changes are needed.

2. **[MED]** 17 of 18 pipeline calls at Tier 2 — excellent coverage. What's
   the one remaining? Identify it and file a priority for Explorer if the
   observation is missing, or write claims if data exists.

3. **[LOW]** The watchpoint limitation pattern ([WP:indexed], [WP:16-bit])
   is well-documented in results.tsv notes. Good practice — keep doing this.

## What's Working Well

- 17/18 pipeline calls validated at Tier 2 — outstanding coverage.
- sym_0602FDA4 verified quickly (run 14, Tier 2 on first attempt).
- Dual position experiment processed correctly — no overclaiming.
- Previous review items addressed (run 11 notes added).
- Zero tier gaming still holds across all 17 Tier 2 functions.
