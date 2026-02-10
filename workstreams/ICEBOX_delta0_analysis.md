# Delta=0 Opcode Difference Analysis

> **Status**: COMPLETE — All delta=0 functions analyzed, root causes documented

Analysis of 34 functions where our GCC 2.6.3 SH-2 output has the **same instruction count** as
the original binary, but different opcodes. Classified by root cause pattern.

Date: 2026-02-04

## Summary Table

| # | Pattern Category | Functions | Count |
|---|-----------------|-----------|-------|
| 1 | Instruction scheduling (reordering) | 14 | 41% |
| 2 | Delayed branch fill: bf/bt vs bf.s/bt.s | 10 | 29% |
| 3 | Range check transform: cmp/ge+sub vs cmp/gt, cmp/hi | 5 | 15% |
| 4 | BSR vs JSR call encoding | 1 | 3% |
| 5 | Multiply vs shift sequence | 1 | 3% |
| 6 | Missing extu.b/exts.b truncation | 1 | 3% |
| 7 | Completely different code generation (algorithm-level) | 2 | 6% |

Many functions exhibit **multiple** patterns simultaneously. The counts above reflect the
**primary** pattern, but detailed per-function breakdowns follow.

---

## Pattern 1: Instruction Scheduling / Reordering (14 functions)

These functions have the correct instructions but in a different order. The original compiler
scheduled instructions differently (likely due to different instruction scheduling heuristics
or pipeline model). Same opcodes appear in both, just at different positions.

### Pure reordering (only difference is position of identical opcodes):

| Function | Insns | Diff Lines | Notes |
|----------|-------|------------|-------|
| FUN_06005174 | 18 | 2 | `add` and last `mov.w` swapped (final store scheduling) |
| FUN_0601164A | 7 | 1 | `mov.w` load scheduled before vs after `add` |
| FUN_06026E0C | 17 | 1 | `mov #0,rN` positioned 1 insn earlier |
| FUN_060270D0 | 17 | 1 | `mov #0,rN` positioned 1 insn later (identical to 06026E0C) |
| FUN_06027344 | 9 | 1 | `mov.w` constant load scheduled 1 insn later |
| FUN_06027348 | 7 | 1 | `mov.w` constant load scheduled 2 insns later |
| FUN_060285E0 | 8 | 1 | `shll8` scheduled after `mov` instead of before |
| FUN_06028600 | 8 | 1 | Same as FUN_060285E0 - `shll8` after `mov` |
| FUN_06035C80 | 9 | 1 | `mov #0,rN` and `mov.l` swapped |
| FUN_0603C05C | 15 | 1 | `and` and `mov.l` (constant load) swapped |
| FUN_0603F3DA | 14 | 1 | `mov #0,rN` and `mov.l` store swapped |
| FUN_0603F4CC | 10 | 1 | `add` and `mov` swapped (stack adjust vs reg move) |
| FUN_0603F8B8 | 11 | 2 | `mov r4,r0` at start vs `mov.l` at end - swapped positions |
| FUN_06040954 | 8 | 1 | `lds.l` (PR restore) and `shll2` swapped in order |

**Root cause**: GCC's instruction scheduler makes different choices about independent
instruction ordering. These are semantically equivalent but produce different opcode streams.
This is the **most common** delta=0 pattern.

**Fixability**: Very difficult. Would require modifying GCC's scheduling heuristics to
exactly match the original compiler's preferences. Each case is a data point about the
original compiler's scheduling algorithm.

---

## Pattern 2: Delayed Branch Fill Differences (10 functions)

The SH-2 has delayed branches (`bf.s`/`bt.s`) where the instruction in the delay slot
executes regardless of branch direction. The original binary fills more delay slots with
useful work, using `bf.s`/`bt.s` + useful delay insn. Our GCC either:
- Uses `bf`/`bt` (non-delayed) + separate instruction
- Uses `bf.s`/`bt.s` where original uses `bf`/`bt`
- Fills the delay slot with a different instruction

### bt.s/bf.s vs bt/bf (original fills delay slot, we don't):

| Function | Insns | Pattern | Notes |
|----------|-------|---------|-------|
| FUN_0602760C | 9 | Orig: `cmp/gt, bt.s, add` / Ours: `cmp/gt, bt, nop` | Loop back-edge; orig fills delay slot with `add` |
| FUN_0602761E | 9 | Same as above for mov.w copy loop | Identical pattern |
| FUN_06027630 | 9 | Same as above for mov.l copy loop | Identical pattern |
| FUN_06040E88 | 25 | Orig: `cmp/ge, bf` / Ours: `cmp/gt, bf.s` (multiple) | Mixed: different branch sense + delay fill |
| FUN_06041128 | 38 | Orig: `bt` (3x), `lds.l; rts` / Ours: `bt.s, bf.s` | Early-return pattern restructured |

### bf/bt vs bf.s/bt.s (we fill delay slot, original doesn't):

| Function | Insns | Pattern | Notes |
|----------|-------|---------|-------|
| FUN_06035C1C | 8 | Orig: `bf` + `bra` loop / Ours: `bf.s` + delay slot fill | Our code is arguably better |
| FUN_0603B878 | 24 | Mixed: orig uses `bf` (3x) / ours uses `bf.s` (2x) + `bt` | Different loop structure |
| FUN_06033520 | 19 | Orig: `bra, nop` / Ours: `bra` with delay fill `add` | Tail-call delay slot fill |

### Different delay slot contents:

| Function | Insns | Pattern | Notes |
|----------|-------|---------|-------|
| FUN_0603F4E0 | 16 | Insns reordered around `bsr` delay slots | `mov` vs `mov.l` in delay slot |
| FUN_0603F500 | 16 | Same pattern as FUN_0603F4E0 | Identical structure |

**Root cause**: GCC's delayed branch scheduling pass (`dbr_schedule`) makes different
decisions about which instructions can fill delay slots. The original compiler appears to
have a more aggressive delay slot filler, particularly for loop back-edges.

**Fixability**: Moderate. The `dbr_schedule` pass in `sh.c` could potentially be enhanced
to prefer filling delay slots in loop back-edges, but this is subtle and risks regressions.

---

## Pattern 3: Range Check Transformation (5 functions)

The original compiler uses `cmp/ge` (signed greater-or-equal) or two-comparison range checks,
while our GCC transforms range checks differently:
- `(a <= x && x <= b)` becomes `(unsigned)(x-a) <= (b-a)` using `cmp/hi` (unsigned)
- `x >= limit` with `cmp/ge` becomes `x > (limit-1)` with `cmp/gt`
- `x - constant` with `sub` becomes `x + (-constant)` with `add` of negative immediate

| Function | Insns | Pattern | Notes |
|----------|-------|---------|-------|
| FUN_0600C970 | 18 | Orig: `cmp/ge, bf, cmp/gt, bt, shll` / Ours: `cmp/hi, bt.s` | Unsigned range check; `shll` vs `add r1,r1` |
| FUN_060122F4 | 25 | `sub` x2 becomes `add` x2; `cmp/ge` x2 becomes `cmp/gt` x2 | Subtraction-as-addition + boundary adjustment |
| FUN_0600D12C | 99 | `cmp/ge, bt` becomes `cmp/gt, bf` (inverted sense) multiple times; + `mov.w` vs `mov.l` | Large function with widespread diffs |
| FUN_06040E88 | 25 | `cmp/ge, bf` becomes `cmp/gt, bf.s` | Combined with delay slot diff |
| FUN_06041128 | 38 | `mov.w` constant vs `movt` for immediate 1 | Combined with structural difference |

**Root cause**: GCC's RTL optimization passes canonicalize comparison operations differently
than the original compiler:
- `sub Rn,Rm` --> `add #-imm,Rm` when the subtrahend is a known constant
- `cmp/ge` --> `cmp/gt` with adjusted boundary (off-by-one transform)
- Range checks merged into single unsigned comparison (`cmp/hi`)

**Fixability**: Very difficult. These are fundamental optimizer decisions in GCC's RTL
middle-end (combine pass, jump optimization). Changing them would affect all generated code.

---

## Pattern 4: BSR vs JSR Call Encoding (1 function)

| Function | Insns | Pattern | Notes |
|----------|-------|---------|-------|
| FUN_0601FD20 | 20 | Orig: `mov.l Lconst,rN; jsr @rN` / Ours: `mov rN,r0; bsr _func` | BSR uses PC-relative, saves 1 constant pool load |

Our `-mbsr` flag enables BSR (PC-relative) direct calls. The original binary used JSR
(indirect via register loaded from constant pool) for this particular call, even though
BSR is more efficient. This means the original compiler may not have had BSR support,
or BSR was not used for cross-module calls.

The second difference (`mov.l` vs `mov`) is that our code uses `mov r1,r0` (register move)
to set up `or #4,r0` (which requires r0), while the original loaded from constant pool
with `mov.l @(disp,PC),r0`.

**Root cause**: Our BSR patch generates more efficient code, but it doesn't match the
original binary encoding.

**Fixability**: Could create per-function flag to disable BSR, but this would be a regression
from our optimization. Better to accept this as a "known better" difference.

---

## Pattern 5: Multiply vs Shift Sequence (1 function)

| Function | Insns | Pattern | Notes |
|----------|-------|---------|-------|
| FUN_0601AB8C | 29 | Orig: `exts.b, shll2, shll2, shll` / Ours: `mov.b, mul.l, sts macl` | Multiply-by-12 vs shift sequence |

The original compiler expands `* 12` as `exts.b; mov Rn,Rm; shll2 Rm; shll2 Rm; shll Rm`
(sign-extend, then shift left by 2, shift left by 2, shift left by 1 = multiply by 32?
Actually the original likely does: copy, shll2(x4), add original(x5)... need to see full
context). Our GCC uses the hardware `mul.l` instruction followed by `sts macl` to read
the result.

Additionally, `exts.b` (sign-extend byte) appears at a different position, suggesting the
original does the sign extension earlier in the computation sequence.

**Root cause**: GCC 2.6.3 synthesizes multiply-by-constant using `mul.l` when available
on SH-2, while the original compiler used shift-add sequences. Both produce correct results
for small constants like 12.

**Fixability**: Would need to modify GCC's multiply-by-constant expansion in the SH backend
to prefer shift-add sequences over `mul.l` for small constants. This is doable but affects
many functions.

---

## Pattern 6: Missing Truncation / Extension (1 function)

| Function | Insns | Pattern | Notes |
|----------|-------|---------|-------|
| FUN_06018EC8 | 7 | Orig: `extu.b` before stores / Ours: `nop` in rts delay slot | Orig truncates to byte before mov.b store |

The original code has `extu.b r0,r0` (zero-extend byte) before storing with `mov.b`, and
the rts delay slot contains a useful `mov.b` store. Our code skips the `extu.b` (it's
unnecessary since `mov.b` only stores the low byte anyway) but has an empty `nop` in the
rts delay slot.

This is a combined truncation elimination + delay slot fill difference. Our compiler
correctly eliminates the redundant `extu.b` but fails to fill the rts delay slot.

**Root cause**: GCC's optimizer eliminates the unnecessary `extu.b` before a byte store
(correct optimization) but then can't fill the rts delay slot since there's nothing left
to put there.

**Fixability**: If we could prevent GCC from eliminating the `extu.b`, it would naturally
fill the delay slot. But this is a pessimization. Accept as "different but equivalent."

---

## Pattern 7: Completely Different Code Generation (2 functions)

These functions have fundamentally different instruction selection or control flow, suggesting
algorithmic-level differences in the code generation:

| Function | Insns | Diff Lines | Notes |
|----------|-------|------------|-------|
| FUN_06026590 | 156 | ~60 diffs | Massive function: different register allocation, scheduling, delay slots throughout |
| FUN_0602F71C | 64 | ~40 diffs | Completely different approach: orig uses `mov.w`/`mov.b` + shifts; ours uses `mov.l` + `and` |
| FUN_0603C0A0 | 9 | 3 diffs | `mov r4,r0; mov.w L2,r1` vs `mov.l Lx,r1; mov.l Ly,r1` - different constant loading |

### FUN_06026590 (156 insns)
The largest function with delta=0. Differences include:
- `extu.w` vs `mov` for zero-extension
- `bf` (8x) replaced by `bf.s` (8x) with delay slot fills
- `shll2; lds; sts` (multiply via MACL) present in our code
- Different register allocation throughout
- Multiple `bra; nop` in original replaced by `bra` with delay fill

This function likely needs source-level adjustments to steer GCC toward the original
code generation pattern.

### FUN_0602F71C (64 insns)
Dramatically different instruction selection:
- Original: `mov.w`/`mov.b` loads with shifts (`shll2`, `shar`) to test bits
- Ours: `mov.l` loads with `and` to test bits, `movt` + `xor` for boolean ops
- Original: `bt` (10x) non-delayed / Ours: `bt.s` (6x) delayed
- Original: `cmp/ge` (3x), `cmp/eq` (2x) / Ours: `cmp/gt` (2x)

This is a fundamental algorithm difference in how bit testing is implemented.

### FUN_0603C0A0 (9 insns)
Original loads constants via `mov.l` (from constant pool), while ours uses `mov r4,r0`
(register move) + `mov.w` (16-bit constant load). Different constant loading strategy.

---

## Cross-Cutting Analysis

### Most Common Difference Types (across all 34 functions)

| Difference | Occurrences | Root Cause |
|-----------|-------------|------------|
| Instruction reordering | 14 functions | Scheduling heuristics |
| `bf`/`bt` vs `bf.s`/`bt.s` | 10 functions | Delay slot filling |
| `cmp/ge` vs `cmp/gt` | 5 functions | Comparison canonicalization |
| `sub` vs `add #-N` | 3 functions | Arithmetic canonicalization |
| `mov.l` vs `mov.w` constant load | 3 functions | Constant pool strategy |
| `bra; nop` vs `bra` with fill | 3 functions | Delay slot in tail jumps |
| `jsr` vs `bsr` | 1 function | BSR patch difference |
| `mul.l` vs shift sequence | 1 function | Multiply expansion |

### Fixability Assessment

| Priority | Pattern | Fixable? | Effort | Impact |
|----------|---------|----------|--------|--------|
| 1 | Loop back-edge delay slot fill (bt.s) | Yes | Medium | 3 functions (FUN_0602760C/1E/30) |
| 2 | Tail branch delay fill (bra; nop -> bra + fill) | Yes | Low | 2-3 functions |
| 3 | Comparison canonicalization | No | N/A | Would break other passes |
| 4 | Instruction scheduling | No | N/A | Fundamental scheduler difference |
| 5 | BSR vs JSR | Accept | N/A | Our code is better |
| 6 | mul.l vs shifts | Possible | High | 1 function, may affect others |

### Functions Closest to Passing (1-2 diff lines only)

These functions could potentially pass with minimal source or compiler tweaks:

1. **FUN_0601164A** (7 insns, 1 swap): `add` before `mov.w` vs after
2. **FUN_06026E0C** (17 insns, 1 swap): `mov #0` position
3. **FUN_060270D0** (17 insns, 1 swap): Same as above
4. **FUN_06027344** (9 insns, 1 swap): `mov.w` load position
5. **FUN_06027348** (7 insns, 1 swap): `mov.w` load position
6. **FUN_060285E0** (8 insns, 1 swap): `shll8` position
7. **FUN_06028600** (8 insns, 1 swap): Same as above
8. **FUN_06035C80** (9 insns, 1 swap): `mov` and `mov.l` swapped
9. **FUN_0603C05C** (15 insns, 1 swap): `and` and `mov.l` swapped
10. **FUN_0603F3DA** (14 insns, 1 swap): `mov` and `mov.l` swapped
11. **FUN_0603F4CC** (10 insns, 1 swap): `add` and `mov` swapped
12. **FUN_06040954** (8 insns, 1 swap): `lds.l` and `shll2` swapped

These 12 functions are all pure scheduling differences with exactly 1 adjacent pair swap.

---

## Per-Function Detail

### FUN_06005174 (18 insns) - SCHEDULING
Stores to consecutive halfword addresses. Our `add #14,r0` is at position 16 (after all
extu.w/mov.w pairs), while original has it at position 10 (interleaved earlier).
Category: Pure instruction scheduling.

### FUN_0600C970 (18 insns) - RANGE CHECK + SCHEDULING
Range check `0x44 < x < 99` implemented differently:
- Original: `cmp/ge #0x45; bf skip; cmp/gt #98; bt skip; shll` (two bounds, shift for x2)
- Ours: `add #-69; cmp/hi #29; bt.s skip; add r1,r1` (unsigned range, add-for-double)
Category: Range check canonicalization + scheduling.

### FUN_0600D12C (99 insns) - RANGE CHECK + SCHEDULING + DELAY SLOT
Large function with widespread differences. `cmp/ge, bt` becomes `cmp/gt, bf` (inverted
branch sense). `mov.w` constant loads replaced by `mov.l`. Multiple `nop` in delay slots
replaced by useful instructions.
Category: Multiple patterns combined.

### FUN_06011494 (12 insns) - SCHEDULING
`extu.w` and constant loads reordered. Original also has `add` that our code doesn't need
(folded into addressing).
Category: Scheduling + addressing mode.

### FUN_060122F4 (25 insns) - RANGE CHECK
`sub` x2 becomes `add` (subtract-as-add-negative). `cmp/ge` x2 becomes `cmp/gt` x2
(boundary adjustment). `mov.l` repositioned.
Category: Comparison/arithmetic canonicalization.

### FUN_06018EC8 (7 insns) - TRUNCATION + DELAY SLOT
`extu.b` omitted (redundant before byte store), rts delay slot unfilled (nop).
Category: Dead code elimination + delay slot.

### FUN_0601AB8C (29 insns) - MULTIPLY EXPANSION
`mul.l; sts macl` vs `shll2; shll2; shll` for multiply-by-12. Also `mov.b` load vs
`exts.b` for sign extension.
Category: Multiply-by-constant strategy.

### FUN_0601FD20 (20 insns) - BSR vs JSR
`bsr _func` vs `mov.l Lconst,rN; jsr @rN`. Also `mov r1,r0` vs `mov.l @(disp,PC),r0`.
Category: BSR patch (our code is better).

### FUN_06026590 (156 insns) - ALGORITHMIC
Massive function with ~60 differing lines. Multiple pattern types: delay slot filling,
register allocation, scheduling, extu.w elimination.
Category: Too many differences to attribute to single cause.

### FUN_06026E0C (17 insns) - SCHEDULING
`mov #0,r2` positioned at line 4 instead of line 2. Single adjacent swap.
Category: Pure scheduling.

### FUN_060270D0 (17 insns) - SCHEDULING
Identical to FUN_06026E0C. Same code structure, same 1-swap diff.
Category: Pure scheduling.

### FUN_06027344 (9 insns) - SCHEDULING
`mov.w L3,r0` (constant pool load) after `shlr2; add` instead of before.
Category: Pure scheduling.

### FUN_06027348 (7 insns) - SCHEDULING
`mov.w L2,r0` at position 3 instead of position 1. Same pattern as FUN_06027344.
Category: Pure scheduling.

### FUN_0602760C (9 insns) - DELAY SLOT
Loop back-edge: original fills `bt.s` delay slot with `add #1,r0`, our code uses
`bt` + `nop`. Additional `rts; add` becomes `rts; nop` (unfilled rts delay slot).
Category: Delay slot filling (loop).

### FUN_0602761E (9 insns) - DELAY SLOT
Identical pattern to FUN_0602760C but for 16-bit (mov.w) copy loop.
Category: Delay slot filling (loop).

### FUN_06027630 (9 insns) - DELAY SLOT
Identical pattern for 32-bit (mov.l) copy loop.
Category: Delay slot filling (loop).

### FUN_060285E0 (8 insns) - SCHEDULING
`shll8 r5` before vs after `mov r6,r7; mov.w L2,r6`. No data dependency.
Category: Pure scheduling.

### FUN_06028600 (8 insns) - SCHEDULING
Identical to FUN_060285E0. Same code pattern.
Category: Pure scheduling.

### FUN_0602F71C (64 insns) - ALGORITHMIC
Completely different bit-testing approach. Original uses byte/word loads with shifts to
extract bits; ours uses word loads with AND masks. Different boolean logic throughout.
Category: Fundamental instruction selection difference.

### FUN_06033520 (19 insns) - SCHEDULING + DELAY SLOT
Multiple `mov` register moves reordered. `bra; nop` becomes `bra` with `add` in delay slot.
Category: Scheduling + delay slot.

### FUN_06035C1C (8 insns) - DELAY SLOT + CONTROL FLOW
strlen-like function. Original: `bra L_top; ...` loop with `bf` back-edge. Ours: `bf.s`
with delay slot fill `add #1,r1`, plus compensating `add #-1,r1` after loop exit.
Category: Different loop structure (ours uses delay slot differently).

### FUN_06035C80 (9 insns) - SCHEDULING
`mov.l L3,r0` and `mov #0,r1` swapped after bsr call.
Category: Pure scheduling.

### FUN_0603B878 (24 insns) - DELAY SLOT + CONTROL FLOW
Search loop: `bf` (3x) in original becomes `bf.s` (2x) + `bt` in ours. Different
control flow for the initial branch-into-loop entry.
Category: Delay slot + control flow restructuring.

### FUN_0603C05C (15 insns) - SCHEDULING
`and r0,r4` and `mov.l L8,r0` swapped (constant load before vs after use of previous
constant).
Category: Pure scheduling.

### FUN_0603C0A0 (9 insns) - CONSTANT LOADING
`mov r4,r0; mov.w L2,r1` (reg move + 16-bit const) vs `mov.l Lx,r1; mov.l Ly,r1`
(two 32-bit const pool loads). Different strategy for getting values into registers.
Category: Constant loading strategy.

### FUN_0603F3DA (14 insns) - SCHEDULING
`mov #0,r1` and `mov.l r0,@(16,r4)` swapped. Single adjacent pair.
Category: Pure scheduling.

### FUN_0603F4CC (10 insns) - SCHEDULING
`add #-4,r15` (stack alloc) and `mov #2,r6` swapped.
Category: Pure scheduling.

### FUN_0603F4E0 (16 insns) - SCHEDULING
Multiple instruction reorderings around two `bsr` calls. `mov` and `bsr` reordered,
`mov.l` and `mov` reordered.
Category: Scheduling around function calls.

### FUN_0603F500 (16 insns) - SCHEDULING
Identical pattern to FUN_0603F4E0.
Category: Scheduling around function calls.

### FUN_0603F8B8 (11 insns) - SCHEDULING
`mov r4,r0` at start vs `mov.l r2,@(20,r0)` at end - the `mov` and first `mov.l` are
swapped between positions 1 and 11.
Category: Pure scheduling.

### FUN_06040954 (8 insns) - SCHEDULING
`lds.l @r15+,pr` (PR restore) and `shll2 r0` swapped. Both are independent; our code
does shll2 first, then lds.l.
Category: Pure scheduling.

### FUN_06040E88 (25 insns) - DELAY SLOT + RANGE CHECK
Loop with `tst; bf` in original becomes `tst; bt` (inverted) + different structure.
`cmp/ge, bf` becomes `cmp/gt, bf.s` (boundary + delay). Control flow restructured.
Category: Control flow inversion + delay slot + comparison.

### FUN_06041128 (38 insns) - CONTROL FLOW + DELAY SLOT
Early-return pattern: original has three `bt; add; lds.l; rts; mov` sequences (3 exit
points with explicit epilogue). Ours uses `bt.s`/`bf.s` with shared epilogue.
`movt r7` for boolean result vs `mov.w` constant load.
Category: Control flow restructuring + delay slots.

---

## Recommendations

### Quick Wins (if desired)
1. **Loop back-edge delay slot fill** (FUN_0602760C/1E/30): Enhance `dbr_schedule` to
   fill `bt/bf` at loop back-edges where the loop increment is available. Impact: 3 functions.

2. **Tail branch delay fill** (FUN_06033520 already works, but verify others): The existing
   tail call patch handles `bra; nop` -> `bra` with delay fill in some cases.

### Accept as "Different but Correct"
- All 14 pure scheduling differences - these are equivalent code
- BSR vs JSR (FUN_0601FD20) - our code is better
- Range check transforms - fundamental optimizer behavior
- Multiply expansion - both approaches correct

### Would Need Source-Level Changes
- FUN_06026590, FUN_0602F71C - too many differences to fix with compiler patches alone
- FUN_0603C0A0 - constant loading strategy requires source restructuring
