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
| + Pure wrapper | 3 | 19 | FUN_06012E00 delta 2→0 |
| + Disp store peephole | 3 | 19 | FUN_06005174 delta 6→0 |
| + Sign ext elimination | 3 | 19 | FUN_06030EE0 delta 6→5, FUN_0600C970 delta 2→1 |
| + Return block dedup | 4 | 18 | FUN_060322E8 → PASS! FUN_0600C970 delta 1→0 |
| + Delay slot sign ext | 5 | 17 | FUN_06035C4E → PASS! |
| + extu.w disp store | 5 | 17 | FUN_06005174 diffs 6→4 (extu.w vs mov fixed) |
| + C source fixes | 6 | 16 | FUN_06012E00 → PASS! FUN_0601164A delta 2→0 |
| + Register compaction | 6 | 16 | Phase 2 liveness merge; no new PASS but L2 matches |
| + FUN_06030EE0 C fix | 6 | 16 | Delta +3→+2 (literal base pointer) |
| + FUN_06030EE0 int val | 6 | 16 | Delta +2→0 (int val enables extendhisi2) |

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

## Patch 4: Pure Wrapper Optimization (sh.md + sh.c)
**Files**: `config/sh/sh.md` (new insn pattern), `config/sh/sh.c` (detection in machine_dependent_reorg)

Extends the tail call detection to identify "pure wrapper" functions where:
- Only one call_insn exists (the tail call)
- Only one stack push exists (the PR save)

In this case, removes both the `sts.l pr,@-r15` push and the `lds.l @r15+,pr`
pop, replacing the call with a simple `bra` via the `tail_jump_bsr` pattern.

**Effect**: FUN_06012E00 delta reduced from 2 to 0 (4 insns matching 4).

## Patch 5: Displacement Word Store Peephole (sh.md + sh.c)
**File**: `config/sh/sh.md` (define_peephole), `config/sh/sh.c` (output helper)
**Type**: define_peephole + C output function

Matches the 3-instruction sequence GCC emits for HImode stores with
displacement: `mov rN,rM / add #D,rM / mov.w rK,@rM` and replaces with
the SH displacement store form `mov.w r0,@(D,rN)`. When the source register
is not R0, a `mov rK,r0` is prepended (2 insns total, saving 1 per store).

**Background**: The SH ISA's `mov.w R0,@(disp,Rn)` requires R0 as the source
register. GCC 2.6.3 has displacement addressing disabled for HImode
(MODE_DISP_OK_2 gated behind TARGET_TRYR0, also has a paren precedence bug).
Enabling it causes reload failures (no SECONDARY_RELOAD_CLASS defined).
The peephole approach sidesteps both issues by operating after register
allocation.

Fixed paren bug in MODE_DISP_OK_2: `(!INTVAL(X) &1)` → `!(INTVAL(X) &1)`
(corrected but still gated behind TARGET_TRYR0).

**Effect**: FUN_06005174 delta reduced from 6 to 0 (24→18 insns).
Saves 1 instruction per 16-bit displacement store across all functions.

## Patch 6: Sign Extension Elimination (sh.md)
**File**: `config/sh/sh.md` (define_peepholes)
**Type**: define_peephole (2 new HI peepholes + fix disabled QI peephole)

SH `mov.w` from memory sign-extends 16→32 bits automatically. GCC inserts
redundant `exts.w rN,rM` after `mov.w @...,rN` loads. Two peepholes added:

1. **Same-register**: `mov.w @...,rN / exts.w rN,rN` → `mov.w @...,rN`
   (no-op elimination — mov.w already sign-extended)
2. **Different-register**: `mov.w @...,rN / exts.w rN,rM` → `mov.w @...,rM`
   (redirect load to target register, requires rN dead and rM not in address)

Also fixed the disabled QI sign-extend peephole (removed `&& 0` guard,
restricted source to `memory_operand`, added `reg_overlap_mentioned_p` check).

**Effect**: FUN_06030EE0 delta reduced from 6 to 5 (16→15 insns, 1 exts.w
eliminated; second survives due to register liveness). FUN_0600C970 delta
reduced from 2 to 1.

**Limitation**: Cannot catch exts.w in rts delay slot (FUN_06035C4E) since
peepholes can't match across delay-slot scheduling boundaries. Also cannot
eliminate exts.w when the source register is still live (FUN_06030EE0 second
case: r2 used by later `mov r2,r1`).

## Patch 7: Return Block Deduplication (sh.c + toplev.c)
**Files**: `config/sh/sh.c` (new post-dbr pass), `config/sh/sh.h` (macro),
`toplev.c` (hook call)
**Type**: Post-delay-slot-scheduling reorg pass

When the delay slot scheduler fills a return's delay slot by stealing an
instruction from before a branch target label, it creates a duplicate bare
return for the branch path. This undoes that optimization when it's
counterproductive: extracts the delay slot insn, makes the return bare, and
redirects all branches (including SEQUENCE-wrapped bf.s/bt.s) to the shared
return label.

Added `MACHINE_DEPENDENT_REORG_POST_DBR` hook in toplev.c that runs after
`dbr_schedule()`. Handles the case of exactly 2 returns (one SEQUENCE-wrapped,
one bare).

**Effect**: FUN_060322E8 delta reduced from 1 to 0 (new PASS).
FUN_0600C970 delta 1→0, FUN_06030EE0 delta 5→4.

## Patch 8: Delay Slot Sign Extension Fix (sh.c)
**File**: `config/sh/sh.c` (in `machine_dependent_reorg_post_dbr`)
**Type**: Post-delay-slot-scheduling optimization

When the delay slot scheduler fills a return's delay slot with a redundant
`exts.w rN,rN` (sign-extend of same register after `mov.w` load), this
optimization replaces it with the preceding `mov.w` memory load instruction.

Detects SEQUENCE `[return, sign_extend:SI (reg:HI rN)]` where the sign_extend
source and destination are the same register. Finds the preceding HImode memory
load to that register and swaps it into the delay slot, deleting the original
load from its pre-return position.

Transforms:
```
mov.l   L2,r1         mov.l   L2,r1
mov.w   @r1,r0   →    rts
rts                    mov.w   @r1,r0
exts.w  r0,r0
```

**Effect**: FUN_06035C4E delta reduced from 1 to 0 (new PASS, 3 insns).

## Patch 9: EXTU.W in Displacement Store (sh.c)
**File**: `config/sh/sh.c` (`output_hi_disp_store`)
**Type**: Peephole output change

The displacement store peephole (`mov.w r0,@(disp,Rn)`) copies the source
register to r0 when needed. Changed from `mov Rm,r0` to `extu.w Rm,r0` to
match the original compiler's behavior of zero-extending before 16-bit stores.

**Effect**: FUN_06005174 diffs reduced from 6 to 4 lines (extu.w vs mov
differences eliminated; only instruction ordering `add` placement remains).

## Patch 10: Register Compaction — Phase 2 Liveness Merge (sh.c)
**File**: `config/sh/sh.c` (`compact_leaf_regs`, in `machine_dependent_reorg_post_dbr`)
**Type**: Post-delay-slot-scheduling optimization

Extends the register compaction pass for leaf functions (no branches) with a
liveness-based merge phase. Phase 1 (existing) fills gaps in r0-r3 usage by
simple compaction. Phase 2 (new) merges registers with non-overlapping live
ranges into the same slot.

**Implementation details**:
- Scans all insns to build first_def/last_use arrays for r0-r3
- Marks r0 as implicitly live at RETURN insns (return value)
- Dead definitions (defined but never read) treated as single-point ranges
- Asymmetric non-overlap check: `last_use[i] <= tgt_first[j]` (reads-before-
  writes OK at same insn) but `tgt_last[j] < first_def[i]` (strict, to prevent
  clobbering return value when delay slot def and implicit r0 use coincide)
- Accumulated target ranges for safe transitive merges

**Effect**: FUN_06035C4E now uses r0 for both pool address and return value
(r1→r0 merge), matching original register choice. Promoted from L1 to L2 in
binary diff. No regressions.

## C Source Improvements

Several test functions had extern variables that are actually constants in the
original binary (embedded in the constant pool via PC-relative addressing).
Replacing these with literal constants eliminates the address+dereference
overhead, matching how the original accesses these values.

### FUN_06012E00: Literal constant argument
`dest_addr_002a0000` (value 0x002A0000, Work RAM Low address) was an extern
but is a constant in the original binary. Replaced with literal `0x002A0000`.
**Result**: Delta 0→0, diffs 2→0 → **NEW PASS** (4 insns).

### FUN_0601164A: All-literal VDP2 hardware writes
All three externs (`val_long`, `dst_long`, `val_short`) are constants in the
original binary (VDP2 register address 0x25F800A4, values 0x12F2FC00 and
0x0200). Replaced with literal pointer arithmetic.
**Result**: Delta +2→0, diffs 4→2 (scheduling order only).

### FUN_06030EE0: Literal constants + int val type fix
Three C source improvements:
1. `idx_06030ef4` (value 0x0150) replaced with literal `0x0150`
2. `base_ptr_06030ef8` replaced with literal `*(int *)0x0607E940`
3. Changed `short val` to `int val` — this lets GCC use the `extendhisi2`
   pattern with memory constraint, combining the `mov.w` load + sign extension
   into a single instruction instead of separate `mov.w @(r0,r3),r2` +
   `exts.w r2,r1`
**Result**: Delta +4→+3→+2→0, diffs 6→5→4→2 (scheduling + bf.s/bf only).

## Remaining Failures Analysis (16 FAIL)

### Current State: 6 PASS / 16 FAIL (27%)
All 16 remaining failures are either instruction-count-matched (delta=0) or
our code is SHORTER than the original. **No functions where our code is longer.**

### Binary Diff Summary
| Level | Count | Description |
|-------|-------|-------------|
| L3: Byte-perfect | 2/22 | FUN_0600D266, FUN_060322E8 |
| L2: Structural | 4/22 | FUN_06012E00, FUN_06026DF8, FUN_06035C48, FUN_06035C4E |
| DIFF | 16/22 | Different instruction sequences or operands |

L2→L3 promotion blocked by pool constant displacement differences due to
isolated compilation. Original binary shares pool entries across adjacent
functions (e.g., FUN_06026DF8 pool entry at displacement 0x26C, shared with
neighboring functions). Would require full binary build system to fix.

### Categorized by Root Cause

**Our code SHORTER — BSR/tail-call (4 functions)**:
GCC uses `bsr` (1 insn) where original uses `mov.l pool,rN / jsr @rN` (2 insns).
Global `-mbsr` flag; can't selectively disable per-function.
- FUN_0600F870 (delta=-2): 2 BSR saves
- FUN_06018E70 (delta=-2): BSR + register alloc
- FUN_0600DE40 (delta=-1): BSR delay slot fill
- FUN_0600DE54 (delta=-1): BSR delay slot fill

**Our code SHORTER — delay slot fill (2 functions)**:
GCC fills rts/branch delay slots that the original left as nop.
- FUN_06033504 (delta=-1): rts delay slot filled with final store
- FUN_060054EA (delta=-1): constant propagation eliminates readback

**Our code SHORTER — better optimization (4 functions)**:
GCC generates fundamentally better code through different strategies.
- FUN_060149CC (delta=-1): keeps address in register, smaller pool entries
- FUN_060149E0 (delta=-1): same — different addressing, objectively better
- FUN_06006838 (delta=-2): sequential shifts vs original's interleaved (2 fewer)
- FUN_06009E02 (delta=-2): dt + BSR combined savings

**Same count, different opcodes — scheduling (4 functions)**:
Instruction ordering differs due to GCC's scheduler making different choices.
All have delta=0 but 2-4 opcode differences from instruction reordering.
- FUN_06005174 (delta=0, 2 diffs): add/mov.w order swapped
- FUN_0601164A (delta=0, 2 diffs): mov.w/add order swapped
- FUN_06030EE0 (delta=0, 2 diffs): pool load order + bf.s vs bf
- FUN_06018EC8 (delta=0, 4 diffs): byte extraction strategy (mov.b direct vs
  mov.w pool load + extu.b; GCC optimizes cast to direct byte load)

**Same count, different codegen strategy (2 functions)**:
Fundamentally different code generation approaches at the RTL/combiner level.
- FUN_0600C970 (delta=0, 6 diffs): GCC transforms `a<=x<=b` to unsigned
  subtraction + cmp/hi; original uses cmp/ge + cmp/gt pair
- FUN_060192B4 (delta=0, 6 diffs): original has exts.b + pointer copy in
  loop body (less efficient); our loop is tighter but uses more setup insns
  for extern dereference. Making externs literal makes us shorter (delta=-2)

### Tractability Assessment

All 16 remaining failures fall into categories that are **intractable without
fundamental changes** to GCC 2.6.3's core optimization passes:

| Root Cause | Functions | Would Require |
|-----------|-----------|--------------|
| BSR optimization | 4 | Disable `-mbsr` (regresses all) |
| Better delay slot fill | 2 | Disable delay slot scheduler |
| Better addressing/shifts | 4 | Deliberately worse codegen |
| Instruction scheduling | 4 | Rewrite GCC scheduler |
| RTL combiner strategy | 2 | Rewrite GCC combiner/expander |

The compiler patch loop has **converged**. Further improvements would require:
1. **Full binary build system** — to get pool constant sharing for L2→L3
2. **Deep GCC surgery** — register allocator, scheduler, or combiner changes
   with high risk of regressions across all functions
3. **Selective optimization control** — per-function flags to disable BSR or
   delay slot fill (not supported by GCC 2.6.3)
