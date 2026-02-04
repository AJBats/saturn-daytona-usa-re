# Compiler Investigation Plans — Day 2+ of 7

**Status**: 33 PASS / 93 FAIL / 126 total (26%)
**Last updated**: Day 2 (early morning)

## In-Progress Work (interrupted)

### Multiply Shift Decomposition (4 functions)
FUN_0603F1E0, FUN_0603F1F0, FUN_0603F202, FUN_0603F216

**Problem**: Our compiler uses `mul.l` where original uses shift-add sequences.
Replacing `* 0xc` with `(p1 << 2) + (p1 << 3)` improves delta from -3/-4 to -1/0.

**Remaining gap**: GCC reuses intermediate shift results (computes *4 then doubles
to *8) instead of making two independent copies and shifting each. The original does:
```
mov r4,r0     ; copy 1
mov r4,r1     ; copy 2
shll2 r0      ; r0 = p1*4
shll2 r1      ; r1 = p1*4 (independent!)
shll r1       ; r1 = p1*8
add r0,r1     ; r1 = p1*12
```

**Status**: DONE. Applied shift rewrites. Results:
- FUN_0603F1E0: delta -3 → -1 (7 vs 8 insns)
- FUN_0603F1F0: delta -4 → -1 (8 vs 9 insns)
- FUN_0603F202: delta -3 → -2 (8 vs 10 insns)
- FUN_0603F216: delta -4 → -1 (10 vs 11 insns)

Remaining gap: GCC reuses intermediate shifts (computes *4 then doubles). Original
uses independent parallel shifts on two register copies. Not fixable from C — would
need changes to `synth_mult()` in expmed.c to generate independent decompositions.

---

## Investigation 1: Post-Reload Scheduling

**Hypothesis**: Post-reload scheduling reorders instructions, creating delta=0 mismatches.
**Affects**: ~21 delta=0 functions (instruction ordering diffs)

**NOTE**: The plan doc says this experiment was done and showed NO CHANGE. The
compiler_patches.md confirms: "Post-reload scheduling experiment: NO CHANGE for any
delta=0 function." So this investigation is COMPLETE and the hypothesis was REJECTED.
The ordering comes from RTL expansion/register allocation, not scheduling.

**Status**: CLOSED — not scheduling. Ordering differences are from instruction
selection and register allocation phases.

### Mini-milestones
- [x] Run `-fno-schedule-insns2` experiment
- [x] Document results
- [ ] Investigate RTL expansion order (dump with `-dr` to see pre-scheduling RTL)
- [ ] Compare RTL at sched dump vs. final dump for specific delta=0 functions

---

## Investigation 2: Delay Slot Filling Strategy

**Problem**: Original fills delay slots more aggressively than our compiler.
**Affects**: ~15-20 functions (including several delta=0 loop functions)

**Specific patterns**:
1. **Store in branch delay slot**: Original moves `mov.X rN,@rM` into `bt.s` delay slot
   (after compare). Our filler doesn't move memory operations past flag-setting insns.
2. **Instruction duplication**: Original duplicates `add #N,r0` into both `bt.s` and `rts`
   delay slots. Our filler doesn't duplicate.
3. **Cross-BB movement**: Original moves insns from the target BB into the branch delay
   slot. Our filler is conservative about this.

**Key file**: `tools/gcc-2.6.3/reorg.c` (NOT `dbr.c` — this is GCC 2.6.3, the delay
branch reorganization is in `reorg.c`)

**Status**: INVESTIGATED. Key findings:
- `fill_simple_delay_slots` searches backward for insns to move into delay slots
- `fill_eager_delay_slots` handles conditional branches (bf.s/bt.s)
- `fill_slots_from_thread` is the core algorithm for pulling insns from branch targets
- Only 2-byte instructions can go in delay slots
- Resource conflict tracking prevents reordering past compare instructions

**Root cause for loop diffs (FUN_0602760C/761E/7630)**: GCC emits `load; store; add;
cmp; bt` but original has `load; cmp; store; bt.s; add(delay)`. The original tests the
COUNTER value BEFORE the store, enabling the add to go in the bt.s delay slot. Our
compiler tests AFTER the store (bottom-of-loop pattern), preventing delay slot fill.

**Tested 5 C source variants**: None changed instruction ordering. The mid-break variant
(`if (n <= i) break; i++;`) proved GCC CAN fill bt.s delay slots but peels the first
iteration (13 insns vs 9). Fixing this requires modifying GCC's loop optimizer — too
risky for the time box.

### Mini-milestones
- [x] Read `reorg.c` to understand delay slot filling heuristics
- [x] Analyze instruction flow for copy-loop functions
- [x] Test 5 C source variants (none worked)
- [ ] ~Modify reorg.c to allow store in bt.s delay slot~ (TOO RISKY — deferred)

**Risk**: HIGH. Changing loop compilation or delay slot filling strategy would affect
ALL loops. Deferred to later phases.

---

## Investigation 3: Register Allocation Preferences

**Problem**: Our compiler picks different registers than original.
**Affects**: ~15 functions (register names differ but logic is identical)

**Specific pattern**: Original uses r3/r4/r5 for caller-saved temps, ours uses r0/r1/r2.
This is particularly visible in leaf functions where registers are mapped differently.

**Key files**:
- `tools/gcc-2.6.3/local-alloc.c` — local register allocation
- `tools/gcc-2.6.3/global-alloc.c` — global register allocation
- `tools/gcc-2.6.3/config/sh/sh.h` — `REG_ALLOC_ORDER` macro

**Status**: INVESTIGATED. Key finding:

**REG_ALLOC_ORDER is IDENTICAL** between our patched compiler and the original GCC 2.6.3
source: `{ 1,2,3,7,6,5,4,0,14,13,12,11,10,9,8,15,16,17,18,19,20,21 }`. This means the
Daytona compiler had the same allocation preference as ours.

The register naming differences in the binary come from OTHER factors:
- Different RTL expansion order (how the compiler constructs intermediate representation)
- Different instruction selection (which patterns are chosen for the same RTL)
- Different versions of the compiler (Cygnus-specific changes to local/global alloc)

### Mini-milestones
- [x] Check `REG_ALLOC_ORDER` in sh.h — same as original
- [x] Compare with unpatched GCC 2.6.3 source — IDENTICAL
- [ ] ~Test changing allocation order~ (NOT NEEDED — same order already)

**Conclusion**: Not an allocation ORDER issue. The register differences are from internal
compiler version differences. CLOSED.

---

## Investigation 4: Constant Representation (add vs sub)

**Problem**: GCC canonicalizes `x - C` to `x + (-C)`. Original loads positive C and
uses `sub` instruction.
**Affects**: FUN_060122F4 (delta=+3) and likely others

**Root cause**: GCC's `fold_truthop` / `fold` in `fold-const.c` transforms
`(plus:SI reg (const_int -N))` which generates `add` with negative pool constant,
instead of `(minus:SI reg (const_int N))` which would generate `sub`.

**Key files**:
- `tools/gcc-2.6.3/fold-const.c` — constant folding
- `tools/gcc-2.6.3/combine.c` — RTL instruction combining
- `tools/gcc-2.6.3/config/sh/sh.md` — instruction patterns for add/sub

**Status**: INVESTIGATED — NOT WORTH IT.

Found 715 `sub` instructions across 248 expected files. But on SH-2, `sub Rm,Rn` is
register-register only (no `sub #imm,Rn`). Both approaches cost the same:
- `add`: load negative constant from pool (mov.w/mov.l) + add Rm,Rn = 2 insns
- `sub`: load positive constant from pool (mov.w/mov.l) + sub Rm,Rn = 2 insns

Same instruction count, just different opcodes. A peephole could convert one to the
other, but it wouldn't change the instruction count or bring functions closer to PASS.

### Mini-milestones
- [x] Count `sub` usage in expected files (715 across 248 files)
- [x] Check if `sub #imm` exists on SH-2 (NO — register-register only)
- [x] Determine instruction count impact (NONE — same 2-insn cost)

**Conclusion**: CLOSED. No benefit from implementing this.

---

## Investigation 5: mul.l vs Shift-Add Decomposition

**Problem**: GCC's `expmed.c` `synth_mult()` decides how to decompose constant multiplies.
With patch 17 (cost=2), it always prefers `mul.l`. Without it (cost=5), it still prefers
`mul.l` for most constants. The original compiler always used shift-add sequences.
**Affects**: 4 functions directly (FUN_0603F1E0/F1F0/F202/F216), potentially more

**Two sub-problems**:
1. Making GCC prefer shifts over mul.l (cost model)
2. Making GCC use the SAME shift decomposition as the original (two independent copies)

**Key files**:
- `tools/gcc-2.6.3/expmed.c` — `synth_mult()`, `expand_mult()`
- `tools/gcc-2.6.3/config/sh/sh.c` — `multcosts()`

### Mini-milestones
- [ ] Read `synth_mult()` in expmed.c to understand decomposition algorithm
- [ ] Check what cost threshold makes GCC prefer shifts for *12 and *24
- [ ] Test reverting patch 17 (cost back to 5) — does it change behavior?
- [ ] Test cost=999 (force shifts always) — measure full suite impact
- [ ] If shift sequences differ from original, investigate `synth_mult()` heuristics
- [ ] Check if the original compiler had a different `multcosts()` or disabled `mul.l`

**Risk**: Medium. Cost model changes are global and affect many functions.

---

## Completed Quick Wins

### C Source Fixes Applied
- [x] Apply shift rewrites to 4 multiply functions (delta improved by 2-3 each)
- [x] Scan high-delta functions for Ghidra errors (found and deleted 10 broken tests)

### Test Deletions (Day 1-2)
- [x] FUN_060282C0, FUN_06028306, FUN_060192E8 (broken Ghidra, day 1)
- [x] FUN_0602F7BC, FUN_06032E6C, FUN_06035BC8 (hidden params: in_r0, unaff_r14)
- [x] FUN_06035C2C, FUN_06034FE0, FUN_06031340, FUN_060336F2 (hidden params: in_r0/r1)
- [x] FUN_06033520, FUN_0602ECCC, FUN_06034560 (hidden params: in_r2, unaff_r10/r14)

---

## Day 2 Key Finding: Flag Exhaustion

**Tested ALL 11 flag combinations across ALL 103 failing functions**: ZERO matches.
No combination of `-mbsr`, `-mnosignext`, `-mnofill`, `-fno-schedule-insns2` produces
a match for any currently-failing function. The remaining differences are ALL from:
1. Register allocation choices (same REG_ALLOC_ORDER, different internal decisions)
2. Instruction scheduling/selection order (RTL expansion phase)
3. Loop compilation strategy (test-at-top vs test-at-bottom)
4. Delay slot filling aggressiveness
5. Constant canonicalization (add vs sub, cmp/gt vs cmp/ge)

---

## Delta Distribution (Day 2)

| Delta | Count | Root Cause |
|-------|-------|-----------|
| +6 to +9 | 7 | Complex C / deep compiler diffs |
| +3 to +5 | 8 | Compiler control flow + canonicalization |
| +2 | 5 | Delay slot + addressing mode diffs |
| +1 | 8 | Register alloc, delay slot, callee-save |
| 0 | 21 | Instruction reordering (8), loop delay (3), known diffs (10) |
| -1 | 23 | BSR delay fill, better codegen, tail calls |
| -2 to -10 | 21 | BSR, tail calls, fundamentally better code |

---

## Remaining Investigation Priorities

1. **dt peephole across labels** (new finding): `add #-1; LABEL; tst rN,rN` pattern
   can't be matched by current peephole (label breaks adjacency). Would need a post-dbr
   pass similar to our existing sign-ext and return-dedup passes. Affects FUN_0601DB84
   and potentially other loop functions.

2. **tst #imm,R0 peephole**: Replace `and #imm,r0; tst r0,r0` with `tst #imm,r0` when
   r0 is dead after test. Only FUN_0603BF5A benefits in current suite (delta +2 → +1).
   Low impact for now.

3. **Displacement store non-consecutive**: Current peephole requires `mov+add+store` to
   be consecutive. In FUN_06035E5E, value loads are interleaved between address computation
   and store. Would need a more sophisticated pattern matcher. Affects 1-2 functions.

4. **Loop entry strategy**: GCC jumps into mid-loop for while loops, original uses simple
   bottom-test. Fundamental compiler difference affecting ~5 functions. Would require
   changes to loop.c or jump.c — too risky.

5. **expmed.c synth_mult decomposition**: GCC reuses intermediate shifts, original uses
   independent parallel copies. Would need changes to synthesis algorithm — medium risk,
   affects 4 multiply functions.
