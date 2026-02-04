# Session Log

Append-only log of detailed findings. Read when resuming a workstream.

---

## Session: C Source Fixes + Patch #23 + Scheduling Experiment

**Baseline**: 38 PASS / 95 FAIL / 133 total

### Compiler Patch #23: QImode byte displacement store
- Added `output_qi_disp_store()` in sh.c (~line 3868)
- Added peephole in sh.md: `mov rN,rM / add #D,rM / mov.b rK,@rM` -> `mov.b r0,@(D,rN)`
- Displacement range 0-15, prefixes `extu.b rK,r0` when source isn't r0
- Reduced FUN_060370C0 from 25 to 20 insns (combined with C fix)
- No regressions on full harness

### C Source Fix Results (11 functions attempted)

| Function | Before | After | Technique | Status |
|----------|--------|-------|-----------|--------|
| FUN_060370C0 | +7 | +2 | char* indexing + QImode peephole | improved |
| FUN_060122F4 | +3 | 0 | int* base with displacement indexing | improved |
| FUN_06018EC8 | +1 | 0 | `short val = 0x00E0` constant pool literal | improved |
| FUN_0603F4E0 | +1 | 0 | `volatile int saved_param` forces stack save | improved |
| FUN_0603F500 | +1 | 0 | struct `{ int val; int saved; char buf[8]; }` layout | improved |
| FUN_0603B878 | +1 | 0 | goto loop + `int *pp` pointer kept alive across loop | improved (pending harness confirm) |
| FUN_06011678 | +3 | -2 | Removed `& 0xFFFF` masking, `int i` counter | OVERSHOOT |
| FUN_0603A766 | +2 | -2 | goto check/loop pattern, `255` arg not `(char)0xFF` | OVERSHOOT |
| FUN_06040EEC | +7 | +8 | char* base with array indexing | REVERTED (regressed) |
| FUN_0602766C | +3 | +4 | Direct volatile ptr instead of extern | REVERTED (regressed) |
| FUN_06027476 | +2 | +2 | Signed int types, simplified casts | NO CHANGE |

### Confirmed Unfixable in C (compiler limitations)

| Function | Delta | Root Cause |
|----------|-------|-----------|
| FUN_06038044 | +6 | R0 register pressure in indexed loop |
| FUN_06012198 | +6 | Dual tail call (both if/else branches) |
| FUN_0600D336 | +2 | movt pattern + @(r0,rN) indexed addressing |
| FUN_060283B8 | +2 | Loop structure (pre-decrement vs indexed offset) |
| FUN_0601DB84 | +1 | GCC uses movt to derive 1 instead of mov #1 |
| FUN_06027358 | +1 | R0 indexed addressing constraint |
| FUN_0602E5E4 | +1 | R0 indexed addressing constraint |
| FUN_06038F34 | +1 | Constant CSE (reloads 0/1 between stores) |

Detailed analysis in `docs/csource_fixes_batch1.md`, `batch2.md`, `batch3.md`.

### Scheduling Experiment

**Hypothesis**: Post-reload scheduling (`-fno-schedule-insns2`) causes opcode ordering diffs.

**Result**: ZERO effect on ALL 133 functions. No output changed at all.

**Conclusion**: Ordering differences come from register allocation and instruction selection
passes, not from the scheduler. This closes the investigation.

Script: `tools/sched_experiment.sh`

### Remaining delta>0 functions (not yet attempted or unfixable)

Still at +7: FUN_06040EEC (R0 constraint, reverted fix)
Still at +6: FUN_06038044 (R0 pressure), FUN_06012198 (dual tail call)
Still at +3: FUN_0602766C (extern indirection + tst pattern, reverted fix)
Still at +2: FUN_060370C0 (partially fixed), FUN_06027476 (loop entry), FUN_0600D336 (movt),
             FUN_060283B8 (loop structure)
Still at +1: FUN_0601DB84 (movt), FUN_06027358 (R0), FUN_06038F34 (constant CSE),
             FUN_0603B878 (fix applied, confirmed delta=0 but 20 opcode diffs remain)

---

## Session: Failure Triage + Flag Sweep + Near-Miss Fixes

**Baseline**: 38 PASS / 95 FAIL / 133 total → **39 PASS / 94 FAIL / 133 total**

### FUN_0603B878 Fix Confirmed
- goto-based loop + `int *pp` pointer: delta +1 → 0 (24 insns match count)
- Still FAIL: 20 opcode diffs (loop structure, branch fill, compare ordering)
- Technique: goto loop entry forces `bra check` instead of loop header duplication

### FUN_0603850C Fix: NEW PASS
- Changed `*(short *)0x060635AC == 1` to `*(unsigned short *)0x060635AC == 1`
- Forces `extu.w` emission after `mov.w` load (zero-extension for unsigned compare)
- Created `tests/FUN_0603850C.flags` with `-O2 -m2 -mnofill`
- Verified PASS on full harness

### BSR Experiment
- Script: `tools/bsr_experiment.sh`
- Found: FUN_060349B6 passes with `-O2 -m2` (no -mbsr) — already had .flags file
- 16 functions would REGRESS without -mbsr (currently PASS, need BSR)
- 5 functions improved but still fail without -mbsr

### Exhaustive Flag Sweep (24 combinations tested)
- Script: `tools/flag_sweep.sh`
- Tested all 95 failing functions with 24 flag combinations
- **Result: 0 new PASSes** from flag changes alone
- 25 functions improved (fewer diffs) but none reached exact match
- Best improvements: FUN_0603850C (1→0 diffs, PASS), FUN_06038520 (3→1), FUN_06041310 (9→5)

### Comprehensive Failure Categorization

| Category | Count | Description |
|----------|-------|-------------|
| delta > 0 | 14 | Our code LONGER — need C fixes or compiler patches |
| delta = 0 | 28 | Same count, different opcodes — ordering/selection diffs |
| delta < 0 | 53 | Our code SHORTER — our compiler produces better code |

### Delta=-1 Analysis (22 functions)
All delta=-1 functions are cases where our GCC produces genuinely more efficient code:
- **swap.w optimization**: FUN_0602755C uses `swap.w` (1 insn) where original uses `mov+shlr16` (2 insns)
- **Register allocation**: Many functions skip unnecessary register copies
- **Stack frame**: Our compiler avoids redundant stack frame adjustments
- **Conclusion**: None fixable without deliberately degrading our compiler output

### Delta=0 Analysis (28 functions)
Most delta=0 functions have 2-opcode diffs — two adjacent instructions swapped:
- `add/mov.w` vs `mov.w/add` (FUN_0601164A, FUN_0603F4CC)
- `mov.l/mov` vs `mov/mov.l` (FUN_06026E0C, FUN_060270D0, FUN_0603F3DA)
- `shll8/mov` vs `mov/shll8` (FUN_060285E0, FUN_06028600)
- `shll2/lds.l` vs `lds.l/shll2` (FUN_06040954)
- C source reordering attempted for several — **no effect** on instruction ordering
- **Root cause**: Instruction ordering determined by RTL expansion, not scheduling
- **Conclusion**: Intractable without undocumented original compiler heuristics

### Compiler Patch Research (Pattern Analysis)
Investigated three multi-function patterns for potential compiler patches:

1. **Memcpy loop compare interleaving** (FUN_0602760C/0602761E/06027630):
   - Original interleaves `cmp/gt` between load and store
   - Would need post-reload reordering pass tracking T register state
   - Status: **Intractable** — too risky for ~3 functions

2. **Adjacent instruction swaps** (~8 delta=0 functions):
   - Comes from RTL expansion order, confirmed not from scheduler
   - No peephole mechanism to control independent instruction ordering
   - Status: **Intractable**

3. **Redundant extu.w after mov.w** (FUN_06038520, FUN_060394C2):
   - Our compiler correctly eliminates redundant zero-extension before `tst`
   - Could add `-mforceextu` flag to preserve zero-extends
   - Would only help ~1 function (FUN_06038520 with -mnofill)
   - Status: **Low ROI** — not worth a compiler patch for 1 function

### Remaining Opportunities
1. **Test suite expansion**: Adding more small leaf functions (2-12 insns) would likely PASS
2. **FUN_06038520**: 1 diff remaining with `-mnofill` (missing extu.w before tst)
3. **Delta>0 functions**: Most confirmed unfixable in C, some might benefit from new compiler patterns

---

## Session: Deep Failure Categorization & Exhaustive Flag Sweep

**Baseline**: 39 PASS / 100 FAIL / 140 total (after FUN_0603C08C added)

### Comprehensive Failure Categorization (categorize_failures.py)

Created `tools/categorize_failures.py` — compiles all tests, compares against expected,
categorizes by root cause pattern. Key patterns found:

| Pattern | Count | Description |
|---------|-------|-------------|
| mov_size_diff | 35 | mov.l vs mov.w or count differences in mov instructions |
| pure_reorder | 16 | Delta=0, identical opcode multiset in different order |
| different_opcodes | 13 | Delta=0 with different opcode choices |
| expected_bra | 12 | Original has bra tail call, we don't |
| bsr_vs_jsr | 6 | Our bsr where original uses jsr |
| our_bra_tail | 5 | Our bra tail call where original doesn't |
| delay_slot_fill | 3 | We fill delay slot, original uses nop |

### BSR Flag Experiments

Tested all BSR-affected functions with `-O2 -m2` (no -mbsr):
- **None fixable by simply removing -mbsr** — differences are more complex
- FUN_060349B6 already had .flags file from previous session
- FUN_0600F870 drops to 1 diff (bt.s vs bt) but already has .flags with -mnofill
- 16 currently-passing functions would REGRESS without -mbsr

### bt.s/bf.s Neutralization Analysis

Tested converting bt.s→bt / bf.s→bf across all functions:
- 2 functions would match (FUN_0600F870 with -O2 -m2, FUN_0603850C)
- BUT 2 passing functions (FUN_0602853E, FUN_06028560) use bt.s/bf.s correctly
- **Net gain = 0** globally — would need per-function flag (not implemented)

### Exhaustive 8-Flag-Combination Sweep (scan_all_flags.py)

Tested 8 flag combinations across ALL 100 failing functions:
- normal, -mnofill, -mnosignext, -mnofill -mnosignext
- × with/without -mbsr
- **Result: ZERO new matches** — all easy wins already captured by previous session

28 functions showed partial improvements (fewer diffs) but none reached exact match.

### Pre-Existing .flags Files Discovery

Found that the previous session had already created 8 .flags files with custom flags:
- FUN_0600DE40, FUN_0600DE54: `-O2 -m2 -mbsr -mno-bsr-fill`
- FUN_0600F870: `-O2 -m2 -mnofill`
- FUN_06018E70, FUN_06018EAC, FUN_06040964: `-O2 -m2`
- FUN_06033504: `-O2 -m2 -mbsr -mno-rts-fill`
- FUN_0603850C: `-O2 -m2 -mnofill`

### New Test Function Attempts

**FUN_0601A5F8**: Expected file exists (8 opcodes), but function uses `bf` to branch
to shared code at 0x0601A658 (outside function boundary). **Not standalone compilable**.

**FUN_0603C08C**: Has .c source, created .expected (9 opcodes: sts sts dmuls.l sts sts
lds lds rts xtrct). Uses `dmuls.l` + `xtrct` for middle 32-bit extraction from 64-bit
multiply. Our GCC lacks `xtrct` instruction pattern — produces 10 insns vs 9 expected.

### Conclusion

The per-function flag approach has reached saturation. All 100 remaining failures are
caused by deep compiler codegen differences (instruction ordering, register allocation,
instruction selection) that no flag combination can resolve. The remaining opportunities
are:
1. Post-processing assembly peephole for delta=0 instruction reordering (16 functions)
2. Investigation of mov_size_diff pattern (35 functions — most common category)
3. Adding xtrct instruction pattern to GCC machine description (1-2 functions)
