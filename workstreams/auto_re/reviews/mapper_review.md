# Mapper Review — 2026-03-15

## Action Items

1. **[HIGH]** Under-producing NOP test recommendations. 8 functions at Tier 2
   but only 3 NOP tests recommended (2 confirmed, 1 blocked). The following
   are NOP-test-ready and should have recommendations NOW:

   - **FUN_0602EFF0** (steering processor, call 2): NOP the JSR in
     FUN_0602EEB8. Expected: D-pad has no effect, car goes straight.
     Use usa_tt_straight.mc0 with C + LEFT. Already Tier 2.
   - **FUN_0602CA84** (force accumulator, call 15): NOP the JSR. Expected:
     no acceleration or deceleration — speed drifts with zero force applied.
     Already Tier 2.
   - **FUN_0602F5B6** (surface writer, call 11): NOP the JSR. Expected:
     car doesn't recognize grass when driving off-track. Use
     usa_tt_offtrack_stop.mc0. Speed should NOT cap at 51 mph. Already Tier 2.
   - **FUN_0602CCEC** (speed convergence): NOP the call from FUN_0602CA84.
     Expected: speed accelerates without converging to gear max. This would
     validate the cycle 12 feedback loop discovery.

   For each, provide the exact poke address by reading the assembly and
   verifying against live memory (same method as the confirmed NOP tests).
   Do NOT use map-file addresses — the human verified addresses in live
   memory for the first two tests and this is the correct methodology.

2. **[HIGH]** The blocked +0xFC NOP test says "UNBLOCKED (NOP jsr @r13 at
   0x0602EF8E)" but this is a different test — it NOPs the entire force
   accumulator call, not the individual +0xFC write. The original test
   (NOP the specific write instruction) is still unresolved. Either:
   (a) derive the correct retail PC for the mov.l that writes +0xFC, or
   (b) explicitly document that this test is superseded by the FUN_0602CA84
   JSR-level NOP test and remove it.

3. **[MED]** The speed convergence feedback loop (cycle 12) is a significant
   discovery but rests entirely on static analysis + correlation. The pipeline
   diagram in struct_map.md states it as fact. Add confidence markers —
   the loop is "proposed" until a NOP test on FUN_0602CCEC confirms that
   removing it breaks speed convergence.

4. **[LOW]** Some priority list entries are stale. Priority 5 (throttle-to-speed
   pipeline gap) and Priority 6 (surface/terrain) overlap with work already
   done in Explorer cycles 4, 7, and 10. Mark resolved items and update the
   remaining gap description to reflect current knowledge.

## What's Working Well

- Struct map quality is excellent — 95+ offsets with writer PCs, consumers,
  pipeline positions, and behavioral data. Naming discipline is good
  (confirmed vs proposed? markers used consistently).
- Speed pipeline is traced end-to-end from C button to position. The
  convergence loop discovery (cycle 12) is genuine insight.
- Integration of NOP test results was immediate (cycle 9) — the dual
  position theory was captured and fed back into priorities.
- Priority list entries have specific investigation plans with scenarios,
  addresses, and expected outcomes. High quality.
