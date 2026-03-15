# Verifier Review — 2026-03-15

## Action Items

1. **[HIGH]** The oracle test runner cannot test brake scenarios because it
   hardcodes `straight_throttle` (starting from 0 mph). Braking needs speed > 0.
   This blocks an entire input class. File a prominent note in results.tsv or
   a separate issue — the human needs to know the oracle has this limitation
   so it can be addressed.

2. **[MED]** FUN_0602EFF0 (steering processor, Tier 2) has only call_count and
   generic value_changes claims. The observation shows it writes +0xB0, +0xB4,
   +0x78, +0x94 — but no writes_to claims were attempted. Even if watchpoints
   fail on some addressing modes, at least attempt writes_to for +0xB0 (written
   via standard mov.l) — it may succeed where others failed.

3. **[MED]** FUN_0602CCEC (Tier 2) has no writes_to claims at all. The
   observation identifies +0x110 as the key output field with linear decay.
   Attempt a writes_to claim on +0x110 — if the write uses standard addressing,
   the watchpoint should catch it.

4. **[LOW]** Clean pass rate (94.7%) is good, but 6 failed claims are all
   watchpoint limitations, not incorrect hypotheses. Consider adding a note
   to results.tsv distinguishing "failed (wrong hypothesis)" from "failed
   (instrumentation limitation)" so the Mapper can weigh them differently.

## What's Working Well

- Zero tier gaming — no value_stable padding detected. All Tier 2 promotions
  are earned with function-specific evidence.
- Question filing is prompt and well-structured — both FUN_0602EEB8 and
  FUN_0602CA84 got timely questions that the Explorer answered.
- All questions have been resolved. No stale backlog.
