# BSR Experiment Results

> **Status**: COMPLETE — Experiment concluded, findings documented

Tested all 44 functions with delta=-1 (26 functions) and delta=-2 (18 functions) to
determine whether the instruction count difference is caused by BSR (1 instruction)
vs JSR (2 instructions: mov.l + jsr).

## Method

For each function:
1. Compiled with `-O2 -m2 -mbsr` (current default, or per-function .flags)
2. Compiled with `-O2 -m2` (no -mbsr, forces JSR)
3. Compared both outputs against `tests/FUNC.expected`
4. Classified: PASS (no-BSR matches), IMPROVED (closer), NO CHANGE (identical output
   or BSR makes no difference), WORSE (removing BSR increases delta)

## Key Finding

**BSR is NOT the cause of delta=-1/-2 for any of these functions.**

- **0 functions** pass with no-BSR
- **1 function** improves with no-BSR (FUN_06041330: diffs 18 -> 11)
- **34 functions** produce identical output with or without -mbsr (leaf functions, no calls)
- **9 functions** produce worse output without -mbsr (BSR is actually helping)

The vast majority (34/44 = 77%) are leaf functions with zero function calls, so BSR
vs JSR is completely irrelevant. The delta=-1/-2 comes from other codegen differences.

## Functions that PASS with no-BSR

**(none)** -- No functions flip from FAIL to PASS when -mbsr is removed.

## Functions that IMPROVE with no-BSR

### FUN_06041330 (delta=-2 -> delta=+1 without BSR)

- With BSR: 13 insns (delta=-2), 3 BSR calls, 18 diff lines
- Without BSR: 16 insns (delta=+1), 3 JSR calls, 11 diff lines
- Expected: 15 insns, 2 JSR calls
- Analysis: The expected code uses JSR (not BSR), but only 2 calls vs our 3.
  The root cause is our compiler generating an extra call, not BSR vs JSR.
  Removing BSR improves diff count but does not fix the underlying issue.

## Functions where BSR output differs but removing BSR is WORSE

These functions use BSR and the expected binary also uses BSR, so BSR is correct.
The delta comes from other codegen differences alongside the calls.

| Function | BSR delta | no-BSR delta | BSR calls | Expected BSR/JSR | Root cause |
|----------|-----------|--------------|-----------|------------------|------------|
| FUN_0600D8A4 | -1 | 0 | 1 BSR | 1 BSR | Register allocation / mov ordering |
| FUN_06014A42 | -1 | +4 | 1 BSR, 1 BRA | 1 BSR | Tail call (bra) vs jmp, minor |
| FUN_0603B9A4 | -1 | 0 | 1 BSR | 1 BSR | Address calc differences (mov.l+add vs mov.w+add) |
| FUN_0603F520 | -1 | 0 | 1 BSR | 1 BSR | mov+add ordering difference |
| FUN_0600A4AA | -2 | +4 | 1 BSR, 1 BRA | 1 JSR | Original uses JSR but we use BSR+BRA (tail call) |
| FUN_06011678 | -2 | -1 | 1 BSR | 1 BSR | extu.w/shll2 vs mulu/sts pattern |
| FUN_0603307C | -2 | 0 | 2 BSR | 2 BSR | sts.l/lds.l ordering differs |
| FUN_0603A766 | -2 | 0 | 2 BSR | 2 BSR | mov.w/extu.b addressing differences |
| FUN_0604188C | -2 | +1 | 1 BSR | 1 BSR | Missing bra+nop -> different branch structure |

## Functions with IDENTICAL output (BSR has no effect) -- 34 functions

These are all leaf functions (no function calls) or functions where -mbsr does not
change the output. BSR is completely irrelevant to their failure.

### Delta=-1 leaf/no-change functions (22 functions)

| Function | Insns | Expected | Actual diff cause |
|----------|-------|----------|-------------------|
| FUN_060054EA | 11 | 12 | mov ordering, missing mov.l |
| FUN_060149CC | 9 | 10 | mov.l vs mov.w addressing |
| FUN_060149E0 | 9 | 10 | mov.w addressing, mov.l vs mov |
| FUN_06018E70 | 11 | 12 | Missing mov (already has .flags -O2 -m2) |
| FUN_060192B4 | 10 | 11 | exts.b+dt+bf.s vs tst+bf.s+add loop pattern |
| FUN_0602755C | 9 | 10 | shlr16 vs swap.w |
| FUN_0603446C | 14 | 15 | mulu.w vs mul.l (multiply instruction choice) |
| FUN_06034560 | 13 | 14 | mov.l addressing vs mov+add+mov.w |
| FUN_06035438 | 6 | 7 | cmp/pl+bf+bra vs cmp/pl+bt (branch sense) |
| FUN_06038520 | 8 | 9 | extu.w+bf vs bf.s (missing delay slot fill) |
| FUN_0603B734 | 11 | 12 | Missing add instruction |
| FUN_0603B96A | 25 | 26 | Loop structure: bra vs mov.w+cmp/ge+bt |
| FUN_0603BF5A | 12 | 13 | extu.b vs and, rts vs bra+mov.l |
| FUN_0603EF54 | 7 | 8 | mov ordering |
| FUN_0603EFD4 | 8 | 9 | sts.l+mov.l+lds.l vs mov.l+mov |
| FUN_0603F1E0 | 7 | 8 | shll2+shll vs add addressing |
| FUN_0603F1F0 | 8 | 9 | shll2 ordering |
| FUN_0603F216 | 10 | 11 | shll2+add addressing, extu.b vs mov.b |
| FUN_06040964 | 10 | 11 | mov+mov vs nop delay slot (has .flags -O2 -m2) |
| FUN_06041310 | 15 | 16 | bt+mov.l vs bt.s+mov, bf vs bf.s (delay slots) |
| FUN_06042BBE | 8 | 9 | mov+mov vs mov |
| FUN_06042BEE | 6 | 7 | Missing mov |

### Delta=-2 leaf/no-change functions (12 functions)

| Function | Insns | Expected | Actual diff cause |
|----------|-------|----------|-------------------|
| FUN_06006838 | 17 | 19 | shlr16+shlr2+shlr vs different shift sequence |
| FUN_0600A8BC | 32 | 34 | bt vs bf.s, cmp/ge vs cmp/gt (branch/compare) |
| FUN_0601476C | 117 | 119 | extu.b/extu.w addressing, mov.w differences |
| FUN_060172E4 | 34 | 36 | shll2 x4 vs mulu+sts (multiply avoidance) |
| FUN_06020DEE | 34 | 36 | shll2 x4 vs mulu+sts (same as FUN_060172E4) |
| FUN_06035C92 | 5 | 7 | Missing extu.w+mov.l |
| FUN_06038A48 | 12 | 14 | tst+bt.s vs cmp/hs+bt+add (range check) |
| FUN_060394C2 | 7 | 9 | Missing mov+extu.w |
| FUN_060394F0 | 10 | 12 | bt vs bf.s, bra+nop vs rts (branch structure) |
| FUN_0603F202 | 8 | 10 | shll2+shll vs add, extu.b vs mov.b addressing |
| FUN_0603FA00 | 5 | 7 | Missing mov+mov, mov.b addressing |
| FUN_06042BAC | 7 | 9 | Missing mov+mov |

## Root Cause Categories

The actual delta=-1/-2 causes fall into these buckets:

1. **Multiply instruction choice** (2 functions): Our compiler uses `shll2` x4 (shift-based
   multiply by 16) which is 4 insns; original uses `mulu.w` + `sts` which is 2 insns.
   This is the "multiply avoidance" issue -- GCC avoids the hardware multiplier.

2. **Branch structure / delay slots** (6 functions): Different branch sense (bt vs bf.s),
   missing delay slot fills, or different branch chain optimization.

3. **Address calculation** (8 functions): Different addressing modes -- `shll2+shll` vs
   `add`, `mov.l` vs `mov.w`, constant pool vs inline constants.

4. **Sign/zero extension** (5 functions): Missing or extra `extu.w`, `extu.b`, `exts.b`
   instructions from incomplete sign extension optimization.

5. **Register allocation / mov ordering** (8 functions): Different register choices
   leading to different mov sequences.

6. **Miscellaneous** (6 functions): Various one-off differences.

## Recommendations

1. **No .flags files needed** -- No functions benefit from removing -mbsr.
2. **FUN_06018E70 and FUN_06040964** already correctly have `.flags` with `-O2 -m2`
   (no -mbsr), and this is correct for their expected output (which uses JSR).
3. The delta=-1/-2 functions need codegen improvements in other areas, not BSR changes:
   - Multiply avoidance fix (use mulu.w where original does)
   - Better delay slot filling
   - Address mode optimization
   - Sign extension elimination improvements
