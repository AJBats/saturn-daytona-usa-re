# GCC 2.6.3 SH-2 Backend Patches

## Summary
Patches applied to `tools/gcc-2.6.3/config/sh/` to make GCC 2.6.3 produce code
closer to the original Daytona USA Saturn binary.

Test harness: `tools/test_harness.sh` (22 test functions)
Compiler flags: `-O2 -m2 -mbsr`

## Results by Phase

| Phase | PASS | FAIL | Notes |
|-------|------|------|-------|
| Baseline (-O2 only) | ~1 | 21 | No SH-2 features |
| + `-m2` flag | 3 | 19 | Enables bf.s/bt.s delayed branches |
| + dt peephole | 3 | 19 | dt emitting but functions have other diffs |
| + BSR fix | 3 | 19 | Instruction counts improved, exact matches unchanged |
| + Tail call | 3 | 19 | Further instruction count improvements |

## Patch 1: dt Peephole (sh.md)
**File**: `config/sh/sh.md`
**Type**: define_peephole

Combines `add #-1,rN / tst rN,rN` → `dt rN` (SH-2 decrement-and-test).

The existing `dect` define_insn in sh.md uses a parallel RTL pattern that the
combiner never matches (GCC generates sequential add/tst RTL). The peephole
matches the sequential pattern instead.

```lisp
(define_peephole
  [(set (match_operand:SI 0 "arith_reg_operand" "")
	(plus:SI (match_dup 0) (const_int -1)))
   (set (reg:SI 18)
	(eq:SI (match_dup 0) (const_int 0)))]
  "TARGET_SH2"
  "dt	%0")
```

**Verified**: dt appears in FUN_06009E02, FUN_060192B4 output.

## Patch 2: BSR Fix (sh.c)
**File**: `config/sh/sh.c`
**Type**: Modified `bsr_operand()` predicate

The original `bsr_operand()` only accepted SYMBOL_REFs for self-calls or
"previously seen" functions in the same compilation unit. Also had a bug where
it received MEM-wrapped operands from `expand_acall()` but only checked for
bare SYMBOL_REF.

Fix: Strip MEM wrapper and accept ANY SYMBOL_REF when TARGET_BSR is set.

```c
int
bsr_operand (op, mode)
     rtx op;
     enum machine_mode mode;
{
  if (TARGET_BSR)
    {
      if (GET_CODE (op) == MEM)
	op = XEXP (op, 0);
      if (GET_CODE (op) == SYMBOL_REF)
	return 1;
    }
  return 0;
}
```

**Effect**: `mov.l Ln,r1 / jsr @r1` (2 insns) → `bsr _func` (1 insn).
Saves 1 instruction per direct function call.

## Patch 3: Tail Call Optimization (sh.md + sh.c)
**Files**: `config/sh/sh.md` (new insn pattern), `config/sh/sh.c` (detection in machine_dependent_reorg)

When the last call before a function return is detected, replaces:
```
bsr _func / nop / lds.l @r15+,pr / rts / nop  (5 insns)
```
With:
```
bra _func / lds.l @r15+,pr  (2 insns, lds.l in delay slot of bra)
```

New insn pattern in sh.md:
```lisp
(define_insn "tail_call_bsr"
  [(set (pc) (match_operand 0 "bsr_operand" "i"))
   (set (reg:SI 17) (mem:SI (post_inc:SI (reg:SI 15))))]
  "TARGET_BSR"
  "bra	%O0\;lds.l	@r15+,pr"
  [(set_attr "in_delay_slot" "no")
   (set_attr "length" "4")])
```

Detection added to end of `machine_dependent_reorg()` in sh.c: scans backward
from function end, looking for `call_insn + lds.l @r15+,pr + return`. When
found, replaces with `tail_call_bsr` and deletes the original insns.

**Limitation**: Does not remove unnecessary PR save for pure wrapper functions
(e.g., FUN_06012E00 still has sts.l/lds.l pair).

## Remaining Patch Opportunities

### Priority 1: Displacement Word Stores
`mov.w R0,@(disp,Rn)` — would save ~6 insns in FUN_06005174 (array zeroing).
Currently GCC emits `mov Rn,Rm / add #disp,Rm / mov.w R0,@Rm` (3 insns)
instead of the 1-insn displacement form. Requires addressing mode pattern work
in sh.md.

### Priority 2: Pure Wrapper Optimization
Remove unnecessary PR save/restore when a function's only operation is a tail
call. Would fix FUN_06012E00 (delta 2 → 0).

### Priority 3: Sign Extension Elimination
GCC inserts `exts.w` to sign-extend shorts to ints even when unnecessary.
Affects FUN_06030EE0 and others.

### Priority 4: Return Block Deduplication
GCC sometimes generates duplicate return blocks (e.g., one for each branch
of an if/else). The original compiler shares a single return path.
