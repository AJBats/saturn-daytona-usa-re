# Scheduling Experiment: -fno-schedule-insns2

**Date**: 2026-02-04
**Hypothesis**: Post-reload instruction scheduling (`-fno-schedule-insns2`) may be causing instruction reordering differences between our compiler output and the original binary.

**Method**: For each test function, compile with two flag sets:
1. **Default**: per-function flags (typically `-O2 -m2 -mbsr`)
2. **No-sched2**: same flags + `-fno-schedule-insns2`

Compare each output against `tests/FUNC.expected` (original binary opcodes).

## Summary

### Delta=0 Functions (34 tested, 0 skipped)

| Metric | Count |
|--------|-------|
| Improved (FAIL -> PASS) | 0 |
| Unchanged | 34 |
| Regressed (PASS -> FAIL) | 0 |

### Currently-Passing Functions (39 tested, 0 skipped)

| Metric | Count |
|--------|-------|
| Still passing | 39 |
| Regressed | 0 |

## Detailed Results: Delta=0 Functions

| Function | Default | No-sched2 | Sched Changed? | Verdict |
|----------|---------|-----------|----------------|---------|
| FUN_06005174 | FAIL(ours=18,orig=18,delta=0) | FAIL(ours=18,orig=18,delta=0) | identical | no effect |
| FUN_0600C970 | FAIL(ours=18,orig=18,delta=0) | FAIL(ours=18,orig=18,delta=0) | identical | no effect |
| FUN_0600D12C | FAIL(ours=99,orig=99,delta=0) | FAIL(ours=99,orig=99,delta=0) | identical | no effect |
| FUN_06011494 | FAIL(ours=12,orig=12,delta=0) | FAIL(ours=12,orig=12,delta=0) | identical | no effect |
| FUN_0601164A | FAIL(ours=7,orig=7,delta=0) | FAIL(ours=7,orig=7,delta=0) | identical | no effect |
| FUN_060122F4 | FAIL(ours=25,orig=25,delta=0) | FAIL(ours=25,orig=25,delta=0) | identical | no effect |
| FUN_06018EC8 | FAIL(ours=7,orig=7,delta=0) | FAIL(ours=7,orig=7,delta=0) | identical | no effect |
| FUN_0601AB8C | FAIL(ours=29,orig=29,delta=0) | FAIL(ours=29,orig=29,delta=0) | identical | no effect |
| FUN_0601FD20 | FAIL(ours=20,orig=20,delta=0) | FAIL(ours=20,orig=20,delta=0) | identical | no effect |
| FUN_06026590 | FAIL(ours=150,orig=156,delta=-6) | FAIL(ours=150,orig=156,delta=-6) | identical | no effect |
| FUN_06026E0C | FAIL(ours=17,orig=17,delta=0) | FAIL(ours=17,orig=17,delta=0) | identical | no effect |
| FUN_060270D0 | FAIL(ours=17,orig=17,delta=0) | FAIL(ours=17,orig=17,delta=0) | identical | no effect |
| FUN_06027344 | FAIL(ours=9,orig=9,delta=0) | FAIL(ours=9,orig=9,delta=0) | identical | no effect |
| FUN_06027348 | FAIL(ours=7,orig=7,delta=0) | FAIL(ours=7,orig=7,delta=0) | identical | no effect |
| FUN_0602760C | FAIL(ours=9,orig=9,delta=0) | FAIL(ours=9,orig=9,delta=0) | identical | no effect |
| FUN_0602761E | FAIL(ours=9,orig=9,delta=0) | FAIL(ours=9,orig=9,delta=0) | identical | no effect |
| FUN_06027630 | FAIL(ours=9,orig=9,delta=0) | FAIL(ours=9,orig=9,delta=0) | identical | no effect |
| FUN_060285E0 | FAIL(ours=8,orig=8,delta=0) | FAIL(ours=8,orig=8,delta=0) | identical | no effect |
| FUN_06028600 | FAIL(ours=8,orig=8,delta=0) | FAIL(ours=8,orig=8,delta=0) | identical | no effect |
| FUN_0602F71C | FAIL(ours=64,orig=64,delta=0) | FAIL(ours=64,orig=64,delta=0) | identical | no effect |
| FUN_06033520 | FAIL(ours=19,orig=19,delta=0) | FAIL(ours=19,orig=19,delta=0) | identical | no effect |
| FUN_06035C1C | FAIL(ours=8,orig=8,delta=0) | FAIL(ours=8,orig=8,delta=0) | identical | no effect |
| FUN_06035C80 | FAIL(ours=9,orig=9,delta=0) | FAIL(ours=9,orig=9,delta=0) | identical | no effect |
| FUN_0603B878 | FAIL(ours=24,orig=24,delta=0) | FAIL(ours=24,orig=24,delta=0) | identical | no effect |
| FUN_0603C05C | FAIL(ours=15,orig=15,delta=0) | FAIL(ours=15,orig=15,delta=0) | identical | no effect |
| FUN_0603C0A0 | FAIL(ours=9,orig=9,delta=0) | FAIL(ours=9,orig=9,delta=0) | identical | no effect |
| FUN_0603F3DA | FAIL(ours=14,orig=14,delta=0) | FAIL(ours=14,orig=14,delta=0) | identical | no effect |
| FUN_0603F4CC | FAIL(ours=10,orig=10,delta=0) | FAIL(ours=10,orig=10,delta=0) | identical | no effect |
| FUN_0603F4E0 | FAIL(ours=16,orig=16,delta=0) | FAIL(ours=16,orig=16,delta=0) | identical | no effect |
| FUN_0603F500 | FAIL(ours=16,orig=16,delta=0) | FAIL(ours=16,orig=16,delta=0) | identical | no effect |
| FUN_0603F8B8 | FAIL(ours=11,orig=11,delta=0) | FAIL(ours=11,orig=11,delta=0) | identical | no effect |
| FUN_06040954 | FAIL(ours=8,orig=8,delta=0) | FAIL(ours=8,orig=8,delta=0) | identical | no effect |
| FUN_06040E88 | FAIL(ours=25,orig=25,delta=0) | FAIL(ours=25,orig=25,delta=0) | identical | no effect |
| FUN_06041128 | FAIL(ours=38,orig=38,delta=0) | FAIL(ours=38,orig=38,delta=0) | identical | no effect |

## Detailed Results: Currently-Passing Functions

| Function | Default | No-sched2 | Sched Changed? | Verdict |
|----------|---------|-----------|----------------|---------|
| FUN_060058FA | PASS | PASS | identical | OK |
| FUN_0600D266 | PASS | PASS | identical | OK |
| FUN_0600DE40 | PASS | PASS | identical | OK |
| FUN_0600DE54 | PASS | PASS | identical | OK |
| FUN_0600F870 | PASS | PASS | identical | OK |
| FUN_06012E00 | PASS | PASS | identical | OK |
| FUN_06012E62 | PASS | PASS | identical | OK |
| FUN_06012E6A | PASS | PASS | identical | OK |
| FUN_06012E7C | PASS | PASS | identical | OK |
| FUN_06012E84 | PASS | PASS | identical | OK |
| FUN_06012EBC | PASS | PASS | identical | OK |
| FUN_06012EC4 | PASS | PASS | identical | OK |
| FUN_06012EDC | PASS | PASS | identical | OK |
| FUN_06012F00 | PASS | PASS | identical | OK |
| FUN_06012F10 | PASS | PASS | identical | OK |
| FUN_06012F20 | PASS | PASS | identical | OK |
| FUN_06012F50 | PASS | PASS | identical | OK |
| FUN_06012F58 | PASS | PASS | identical | OK |
| FUN_06012F60 | PASS | PASS | identical | OK |
| FUN_0601E0DE | PASS | PASS | identical | OK |
| FUN_0601F8BC | PASS | PASS | identical | OK |
| FUN_06026DF8 | PASS | PASS | identical | OK |
| FUN_0602754C | PASS | PASS | identical | OK |
| FUN_0602853E | PASS | PASS | identical | OK |
| FUN_06028560 | PASS | PASS | identical | OK |
| FUN_060322E8 | PASS | PASS | identical | OK |
| FUN_06033504 | PASS | PASS | identical | OK |
| FUN_060349B6 | PASS | PASS | identical | OK |
| FUN_06035C48 | PASS | PASS | identical | OK |
| FUN_06035C4E | PASS | PASS | identical | OK |
| FUN_06035C6E | PASS | PASS | identical | OK |
| FUN_0603850C | PASS | PASS | identical | OK |
| FUN_0603F4B0 | PASS | PASS | identical | OK |
| FUN_0603F92C | PASS | PASS | identical | OK |
| FUN_0603F9F2 | PASS | PASS | identical | OK |
| FUN_0603F9F6 | PASS | PASS | identical | OK |
| FUN_060401E4 | PASS | PASS | identical | OK |
| FUN_060409DE | PASS | PASS | identical | OK |
| FUN_06041884 | PASS | PASS | identical | OK |

## Diff Details

### Functions where -fno-schedule-insns2 improved the result

None.

### Functions where -fno-schedule-insns2 changed output but still fails

None.

### Currently-passing functions that regressed

None.

## Conclusion

- **0 out of 34** delta=0 functions improved to PASS with -fno-schedule-insns2
- **0 out of 39** currently-passing functions regressed
- Hypothesis **NOT SUPPORTED**: Post-reload scheduling is not a significant source of opcode differences

