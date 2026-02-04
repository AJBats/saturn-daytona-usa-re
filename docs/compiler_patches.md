# GCC 2.6.3 SH-2 Backend Patches

## Summary
Patches applied to `tools/gcc-2.6.3/config/sh/` to make GCC 2.6.3 produce code
closer to the original Daytona USA Saturn binary.

Test harness: `tools/test_harness.sh` (125 test functions after cleanup)
Compiler flags: `-O2 -m2 -mbsr`

## Current State: 38 PASS / 95 FAIL / 133 total (28% pass rate)

## Results by Phase (original 22 test functions)

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

## Test Suite Expansion (Session 3)

Expanded from 22 to 133 test functions using automated tooling:
- `tools/gen_expected.py` — extracts expected opcodes from `build/aprog.s`
- `tools/gen_test_skeleton.py` — drafts C source from Ghidra decompilations

After expansion + scheduling fix + C source fixes + swap.w: **31 PASS / 102 FAIL / 133 total**

Key C source fixes applied at scale:
- **Operator precedence**: 8 functions had missing parens around `<< N` in `+` context
- **movt loop**: 3 functions rewrote boolean materialization in loop condition
- **Constant pool extern→literal**: 37 extern declarations replaced with ROM values
  - 2 new PASS: FUN_0602853E, FUN_06028560
  - FUN_0600D336: delta +10→+2, FUN_06041310: +4→-1
  - FUN_0601164A/0602755C/0603F3DA: delta +1→0
  - 3 reverted (0xFFFFFF00 hw divide pointer caused regressions)
- See `docs/gcc26_internals.md` for details on each fix pattern

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

## Patch 11: swap.w Pre-DBR Optimization (sh.md + sh.c)
**Files**: `config/sh/sh.md` (new `swap_w` insn pattern), `config/sh/sh.c` (pre-dbr pass)
**Type**: Pre-delay-slot instruction rewrite

Replaces `mov rN,rM` + `ashrsi3_16(rM)` (3 asm insns: mov + shlr16 + exts.w) with
`swap.w rN,rM` + `exts.w rM,rM` (2 asm insns). The key insight is splitting the
two-instruction `ashrsi3_16` insn into two separate RTL insns BEFORE delay slot
scheduling, so the delay slot filler can move `exts.w` into an `rts` delay slot.

**Implementation**:
- Added `swap_w` define_insn in sh.md: `(rotate:SI ... (const_int 16))` → `swap.w %1,%0`
  with different src/dst register constraint ("r" not "0")
- Pre-dbr pass in `machine_dependent_reorg` scans for register copy followed by
  PARALLEL ashiftrt:SI by 16 with T clobber (ashrsi3_16 pattern)
- Replaces the copy with rotate:SI by 16 (matched by swap_w insn)
- Replaces the ashrsi3_16 with sign_extend:SI from HI (matched by extendhisi2 insn)
- Only fires when src != dst (swap.w allows Rm!=Rn; shlr16 does not)

**Effect**: FUN_0602754C → PASS (3 insns: `swap.w r4,r0 / rts / exts.w r0,r0`).
FUN_0603C0A0 delta +1→0 (swap.w saves the extra mov). Potentially helps any function
with `(int)(short)(x >> 16)` pattern where src/dst differ.

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

## Patch 12: add-to-shll Pre-DBR Pass (sh.c)
**File**: `config/sh/sh.c` (pre-dbr pass in `machine_dependent_reorg`)
**Type**: Pre-delay-slot instruction rewrite

Replaces `add rN,rN` (doubling) with `shll rN` (shift left 1) when the T flag is
dead after the instruction. The original Saturn compiler prefers `shll` for doubling;
GCC prefers `add` because it doesn't clobber T.

**Implementation**:
- Pre-dbr pass scans for `(set rN (plus:SI rN rN))` pattern
- Forward scan checks T-flag liveness: finds next insn that sets or reads T (reg 18)
- Handles unconditional jumps (T dead), conditional branches (T live), PARALLEL clobbers
- Replaces with `(parallel [(set rN (ashift:SI rN const1)) (clobber T)])`

**Effect**: Correct opcode substitution in ~10 functions. No new PASSes (scheduling diffs
remain) but opcodes now match original's `shll` preference.

## Patch 13: Indexed Addressing Pre-DBR Pass (sh.c)
**File**: `config/sh/sh.c` (pre-dbr pass in `machine_dependent_reorg`)
**Type**: Pre-delay-slot instruction rewrite

Combines `add rA,rB` + `mov.l @rB,rC` into `mov.l @(rA,rB),rC` when:
- One of rA/rB is r0 (SH-2 indexed addressing requires r0)
- rB's modified value is dead after the memory access
- The add and memory access are adjacent

Also handles stores (`mov.l rC,@rB` → `mov.l rC,@(rA,rB)`) and sign-extending
loads (`mov.w @rB,rC` → `mov.w @(rA,rB),rC`).

**Dead register check**: If rB == rC (load overwrites rB), it's trivially dead.
Otherwise scans forward for register references — caller-saved regs (r0-r7) are
considered dead at JUMP_INSN/CALL_INSN boundaries.

**Effect**: FUN_06027344 delta +1→0, FUN_06027348 delta +1→0.
Both now produce `mov.l @(r0,r4),r0` indexed loads matching the original binary.
Not a PASS due to constant pool load ordering (scheduling diff).

## Patch 14: Conditional Branch Delay Slot Unfilling — `-mnofill` (sh.h + sh.c)
**Files**: `config/sh/sh.h` (new target flag), `config/sh/sh.c` (post-dbr pass)
**Type**: Post-delay-slot-scheduling pass, activated by `-mnofill` flag

When `-mnofill` is active, this pass converts filled conditional branches
(`bf.s`/`bt.s`) back to non-delayed form (`bf`/`bt`). The delay slot instruction
is moved before the branch.

**Implementation**:
- Added `NOFILL_BIT (1<<18)` and `TARGET_NOFILL` macro in sh.h
- Added `"nofill"` to `target_switches[]` in sh.h
- Post-dbr pass finds SEQUENCE-wrapped conditional JUMP_INSNs (IF_THEN_ELSE)
- Extracts delay slot insn, emits before the branch, converts branch to non-delayed
- Skips unconditional branches and conditional returns

**Effect**: Converts `bt.s label / add #1,r0` to `add #1,r0 / bt label`.
12 functions produce closer output but ZERO new PASSes — remaining diffs are
instruction scheduling, not delay slot filling.

## Patch 15: Sign Extension Preservation — `-mnosignext` (sh.h + sh.md + sh.c)
**Files**: `config/sh/sh.h` (new target flag), `config/sh/sh.md` (peephole gating),
`config/sh/sh.c` (optimization gating)
**Type**: Per-function flag to disable sign/zero extension elimination

When `-mnosignext` is active:
- 4 sign extension peepholes in sh.md are disabled (QI and HI, same/different reg)
- Delay slot sign-extend optimization in sh.c is disabled

**Implementation**:
- Added `NOSIGNEXT_BIT (1<<19)` and `TARGET_NOSIGNEXT` macro in sh.h
- Added `"nosignext"` to `target_switches[]` in sh.h
- Gated peepholes: `"!TARGET_NOSIGNEXT && REGNO(operands[0]) == REGNO(operands[2])"`
- Gated delay slot opt: `if (!TARGET_NOSIGNEXT) for (insn = first; ...)`

**Effect**: Preserves redundant `exts.w`/`exts.b` instructions that the original
compiler kept. Combined with `-mnofill` in exhaustive 8-flag-combo search on all
102 failing functions: ZERO new PASSes. Remaining differences are deep codegen.

## Remaining Failures Analysis (93 FAIL / 126 total)

### Current State: 33 PASS / 93 FAIL (26%)

### Failure Distribution by Delta

| Category | Count | Description |
|----------|-------|-------------|
| delta < 0 | 51 | Our code shorter (47% of failures) |
| delta = 0 | 21 | Same count, different ordering/opcodes (19%) |
| delta > 0 | 37 | Our code longer (34%) |

**Detailed delta breakdown**:

| Delta Range | Count | Description |
|-------------|-------|-------------|
| delta <= -5 | 12 | Our code much shorter (aggressive optimization) |
| delta = -3/-4 | 10 | Our code 3-4 insns shorter |
| delta = -2 | 10 | Our code 2 insns shorter |
| delta = -1 | 19 | Our code 1 insn shorter |
| **delta = 0** | **21** | Same count, different ordering/opcodes |
| delta = +1 | 15 | Our code 1 insn longer |
| delta = +2 | 6 | Our code 2 insns longer |
| delta >= +3 | 16 | Our code much longer (C source / codegen issues) |

### Delta=0 Functions (21 — closest to matching)

Of 21 delta=0 functions:
- **7 with diffs=2** (single opcode swap): FUN_0601164A, FUN_06026E0C, FUN_060270D0,
  FUN_06027344, FUN_06027348, FUN_0603C05C, FUN_0603F3DA, FUN_060285E0, FUN_06028600
  — All are pure instruction scheduling differences. The same opcodes in different order.
- **6 with diffs=4-6**: FUN_06005174, FUN_0602760C, FUN_0602761E, FUN_06027630,
  FUN_0603F8B8, FUN_06035C1C — Instruction scheduling within loops or register usage
- **8 with diffs>6**: FUN_0600C928, FUN_0600C970, FUN_06011494, FUN_0603C0A0,
  FUN_06033520, FUN_06040E88 — Deeper codegen strategy differences

### Scheduling Experiment Results

**Hypothesis**: Post-reload scheduling (`-fno-schedule-insns2`) causes the
delta=0 instruction ordering differences.

**Result**: NO CHANGE for any delta=0 function. The ordering differences come from
the instruction selector/expander and register allocator, not the scheduler.
Pre-reload scheduling was already disabled in sh.h (`flag_schedule_insns = 0`).

**Conclusion**: Delta=0 failures are intractable without modifying the RTL expansion
order or register allocator behavior. These are fundamental compiler internals.

### Exhaustive Per-Function Flag Search (Session 6)

Tested all 8 flag combinations on all 102 failing functions:
- normal, -mnofill, -mnosignext, -mnofill -mnosignext
- × with/without -mbsr (2 BSR variants)

**Result: ZERO new PASSes**. This definitively proves remaining failures have
deep compiler internal differences beyond what per-function flags can control.

### "Make Compiler Worse" Strategy (Session 6)

User directed shift from "our compiler is better" to matching the original's output,
even if it means producing less optimal code. Two new flags implemented:
- `-mnofill`: Unfills conditional branch delay slots (bf.s→bf, bt.s→bt)
- `-mnosignext`: Preserves redundant sign/zero extensions after loads

Both flags work correctly but don't produce new PASSes. The remaining gaps are:
- Instruction ordering within basic blocks
- Register allocation preferences (r0/r1 vs r1/r2 for temporaries)
- Multi-branch tail call detection (our optimizer only handles single-path tail calls)
- Zero extension elimination by RTL combiner (extu.w removed when provably unnecessary)
- Multiply instruction selection (mulu.w vs mul.l for 16-bit operands)

### C Source Fixes (Sessions 5-7)

**Copy loop functions** (FUN_0602760C, FUN_0602761E, FUN_06027630): Changed
parameter types from `int` to `char *`. All went from delta=+2 to delta=0.

**FUN_060322E8**: Changed return type from `int *` to `void`. The original doesn't
explicitly set a return value; Ghidra inferred one from r0's residual contents.
Removing the return eliminated an extra `mov r1,r0` instruction. **PASS restored**.

### Tractability Assessment

| Root Cause | Affected | Tractability |
|-----------|----------|--------------|
| Instruction ordering (delta=0) | 21 | Intractable — deep compiler internals |
| Our code shorter (delta<0) | 51 | Intractable — our code is genuinely better |
| Register allocation quality | ~15 | Intractable — allocator preference issue |
| C source quality / Ghidra errors | ~10 | Medium — manual C source rewrite needed |
| Multi-branch tail call | 3-5 | Hard — need compiler-level multi-path detection |
| Missing loop optimization (dt) | 2-3 | Hard — non-adjacent add/tst pattern |
| Callee-save register strategy | 5+ | Hard — GCC uses r8+ to preserve across calls |
| Zero ext elimination (extu.w) | 5+ | Hard — RTL combiner optimization |
| mulu.w vs mul.l selection | 3-5 | Medium — need 16-bit multiply detection |

### Test Suite Expansion (Session 7)

- Used `gen_test_skeleton.py` to batch-generate 40 new skeleton files
- Deleted 35 unfixable files (30 indirect calls, 5 other issues)
- Fixed 8 files with literal address derefs / parse errors
- Net result: 141 total tests (up from 133)
- 0 compile errors remaining

### Next Steps

1. **C source audit**: Review delta=+1/+2 functions for type/formulation fixes
2. **Multi-branch tail call**: Compiler enhancement to detect tail calls on all branches
3. **mulu.w generation**: Compiler enhancement or C source trick for 16-bit multiply
4. **Test expansion**: ~90 more functions have Ghidra decomps without C sources

## Patch 16: -mnofill Instruction Placement Fix (sh.c)
**File**: `config/sh/sh.c` (post-dbr pass)
**Type**: Bug fix in conditional branch delay slot unfilling

The `-mnofill` pass was placing the unfilled delay slot instruction BEFORE the branch
(`emit_insn_before`). The original Saturn compiler placed it AFTER the branch on the
fall-through path. Changed to `emit_insn_after`.

**Effect**: FUN_0600F870 → PASS (with `-O2 -m2 -mnofill` flags + void return C fix).

## Patch 17: Multiply Cost Reduction (sh.c)
**File**: `config/sh/sh.c` (`multcosts()`)
**Type**: Cost model adjustment

Reduced the shift-add cost cap from 5 to 2 in `multcosts()`. This makes GCC prefer
hardware multiply (`mul.l` / `mulu.w`) over shift-add sequences for non-power-of-2
constant multiplies.

```c
if (insn_cost > 2)
  return 2;
```

**Effect**: Generates `mul.l` instead of 6-insn shift-add for constants like `*44`.
4 fewer delta>0 functions. However, 4 functions (FUN_0603F1E0/F1F0/F202/F216) now
use `mul.l` where original uses shift sequences — makes our code shorter, not matching.

## Patch 18: Displacement Load Peephole (sh.md + sh.c)
**Files**: `config/sh/sh.md` (define_peephole), `config/sh/sh.c` (`output_hi_disp_load`)
**Type**: define_peephole + C output function

Folds `mov rN,r0 / add #D,r0 / mov.w @r0,r0` into `mov.w @(D,rN),r0`. Two peephole
variants: sign-extending form (explicit `sign_extend:SI`) and direct HImode form.

Required a C output function (`output_hi_disp_load`) because the `%O2,%1` template
format incorrectly printed `r0` instead of the base register. The C function uses
`reg_names[REGNO(operands[1])]`.

**Constraints**: R0-only destination, displacement 0-30 even bytes.

**Effect**: Works correctly for FUN_06035E3C but makes our code 3 insns shorter than
original (delta=-3) because we don't need the `mov r0,r3` copies the original uses.

## Session 8 Changes (Day 1 Evening)

### Deleted Tests
- FUN_060282C0, FUN_06028306: Severely broken Ghidra decompilations (decimal-to-string
  converters with Ghidra artifacts, delta=+12 each)
- FUN_060192E8: Hardware polling loop misread by Ghidra as pointer walk (delta=+8)

### C Source Fixes
- FUN_0600F870: Changed from `int` return to `void`, discarding func_06011094()'s return
  value. Created `.flags` file with `-O2 -m2 -mnofill`. → **NEW PASS**

### Multiply Function Investigation
4 functions (FUN_0603F1E0/F1F0/F202/F216) multiply by constants (12, 24). Original uses
two-register shift decomposition (e.g., *12 = *4 + *8 via parallel shifts). Replacing
`* 0xc` with `(p1 << 2) + (p1 << 3)` in C source improves delta from -3/-4 to -1/0
but doesn't fully match because GCC reuses intermediate shift results instead of
computing independent shifts on two registers.

## Build Directory Sync Issue

**CRITICAL BUG (Session 3)**: The build directory `gcc26-build/config/sh/` has its own
copies of sh.c, sh.h, sh.md (NOT symlinks). During the swap.w experiment, a sequence
of operations left the build dir files out of sync with the patched sources in
`gcc-2.6.3/config/sh/`. The build dir reverted to pre-patch state (missing 5+ patches).

**Symptom**: PASS count dropped from 28 to 13 and did NOT recover after reverting
the experiment change.

**Fix**: Manually copied all 4 files from `gcc-2.6.3/` to `gcc26-build/`:
- `sh.c` (3319 → 2525 lines overwritten)
- `sh.h` (1503 → 1498 lines overwritten)
- `sh.md` (1985 → 1929 lines overwritten)
- `toplev.c` (4083 → 4079 lines overwritten)

**Prevention**: See `docs/gcc26_internals.md` "Build Directory Sync" section for
the correct procedure. Always verify patches are present after rebuild.

## Session 9 (Day 2 Morning — Investigation & Cleanup)

### Test Suite Cleanup
Deleted 10 additional broken Ghidra decompilations with hidden parameters:
- FUN_0602F7BC (`in_r0` — hidden r0 parameter, non-standard calling convention)
- FUN_06032E6C (`unaff_r14` — callee-saved register used as uninitialized base)
- FUN_06035BC8 (`in_r0` + `in_stack_00000000` — multiple hidden params)
- FUN_06035C2C, FUN_06034FE0 (`in_r0`, `in_r1` — hidden register params)
- FUN_06031340 (`in_r1`), FUN_060336F2 (`in_r0`), FUN_06033520 (`in_r2`)
- FUN_0602ECCC (`in_r0`, `in_r1`), FUN_06034560 (`unaff_r10`, `unaff_r14`)

**Result**: 33 PASS / 93 FAIL / 126 total (26%)

### Investigation Results

**Investigation 2 (Delay Slot Filling)**: Analyzed reorg.c thoroughly. Root cause for
loop functions (760C/761E/7630): GCC puts test after store (bottom-of-loop), preventing
delay slot fill. Original tests before store, enabling bt.s with add in delay slot.
Tested 5 C source variants — none change instruction order. Fixing requires modifying
GCC's loop optimizer — **too risky, deferred**.

**Investigation 3 (Register Allocation)**: REG_ALLOC_ORDER is IDENTICAL between our
compiler and original GCC 2.6.3: `{ 1,2,3,7,6,5,4,0,14,...,8,15-21 }`. Register naming
differences come from internal compiler version differences, not allocation preference.
**CLOSED — not actionable**.

**Investigation 4 (add vs sub)**: On SH-2, `sub` is register-register only. Both
`add Rm,Rn` (neg constant from pool) and `sub Rm,Rn` (pos constant from pool) cost
2 instructions. **CLOSED — no benefit**.

**Exhaustive Flag Search**: Tested 11 flag combinations across ALL 103 failing functions.
**ZERO matches found**. Remaining differences cannot be resolved with compiler flags.

### Delta Analysis Summary (Day 2)

**Delta=+1 functions (8)**: All analyzed in detail. Causes: delay slot filling (2),
register allocation (3), callee-save strategy (2), loop compilation (1). Tried C source
rewrites for FUN_06038F34 (constant reloading) — 4 variants, all produce same output.
**None fixable from C source**.

**Delta=+2 functions (5)**: Analyzed. Causes: dt peephole across labels (FUN_0601DB84),
displacement store non-consecutive (FUN_06035E5E), loop compilation (FUN_0603A766,
FUN_0600D336), register allocation (FUN_0603BF5A). **None fixable from C source**.

**Delta=0 functions (21)**: 8 have pure instruction reordering (2 diffs each — one
instruction in a different position). 3 are known loop delay slot issues. 10 have deeper
codegen strategy differences. **All intractable without deep compiler changes**.

## Session 10 (Day 2 Afternoon — Large-Delta Analysis & C Source Fixes)

### Test Suite Cleanup
- **Deleted FUN_060424A2**: Wrong function boundary (entry at 0604249C, not 060424A2),
  missing `lds r3,macl` instruction in expected file (encoded as `.word 0x431A` and not
  decoded by disassembler). Also saves/restores MACL which can't be expressed in C.

### C Source Fixes
- **FUN_060283B8 (delta +6 → +2)**: Ghidra's `bVar1 = iVar4 != 0; iVar4 += -2; while(bVar1)`
  pattern causes GCC to materialize the boolean with `cmp/eq + movt + xor + tst` (4 insns)
  instead of a simple `tst` check. Restructured to `do { iVar4 -= 2; body; } while(iVar4)`,
  changed param_3 from `short` to `int`, removed intermediate unsigned short temp.
  Remaining +2 delta from `cmp/eq` (pointer comparison) instead of `tst` (counter test).

### Large Positive-Delta Analysis (delta=+6 and +7)

Compiled and analyzed all 6 functions with delta >= +6:

**FUN_06012198 (delta=+6)**: Conditional dual tail call. Original uses two `bra` (no PR
save/restore) for both if/else branches. Our compiler saves PR (`sts.l`) and uses `bsr`
for both calls, plus `lds.l/rts` epilogue. Requires multi-branch pure wrapper detection —
**not fixable from C**, would need compiler enhancement.

**FUN_060370C0 (delta=+7)**: Zero-fill struct (2 int stores + 7 byte stores). Original
keeps zero in a register and uses `mov.b r0,@(disp,r4)` displacement byte stores (each
preceded by redundant `extu.b`). Our compiler clobbers r0 for address computation after
the int stores, then uses `mov r4,r0 / add #disp,r0 / mov.b r1,@r0` (3 insns per byte
vs 2 in original). **Not fixable from C** — register allocation issue (R0 constraint).

**FUN_06038044 (delta=+6)**: Copy loop (8 shorts). Original recomputes both source and
dest addresses from index each iteration (18 insns). GCC aggressively optimizes to auto-
increment (`@r4+`) and walking pointers, producing 14-insn code (delta=-4) or 24-insn
code with stack spills depending on types. All 6 variants tested (int/ushort types, with/
without `-fno-strength-reduce`, count up/down, pointer types). **Not fixable** — our
optimizer is either too good (shorter than original) or register allocation causes spills.

**FUN_060424A2 (delta=+6)**: Deleted (see above).

**FUN_06040EEC (delta=+7)**: Search loop with early return. Complex control flow
differences — loop entry, exit handling, byte store patterns all differ. GCC generates
stack frame and spills. **Not fixable from C**.

### Delta=+3 Analysis

**FUN_06011678 (delta=+3)**: `and r2,r0` (mask 0xffff) instead of `extu.w`. GCC loads
mask from pool constant and uses register-register AND. Converting to unsigned short types
causes massive stack spills (52 insns!). **Not fixable from C**.

**FUN_060122F4 (delta=+3)**: `add` instead of `sub` for constant subtraction, `cmp/gt`
instead of `cmp/ge` for comparison. Pure instruction selection differences.
**Not fixable from C**.

**FUN_0602766C (delta=+3)**: `and + tst` instead of combined `tst Rm,Rn`. GCC doesn't
fold the AND into the TST. `rts/nop` instead of filling delay slot with last store.
**Not fixable from C** — would need tst-folding peephole in sh.md.

### Potential Compiler Patches Evaluated

**dt-across-labels**: Analyzed in detail for FUN_0601DB84. The `add #-1,r1` is placed
BEFORE the loop label, `tst r1,r1` is AFTER the label, and a second `add #-1` is in the
delay slot of `bf.s` looping back. Converting to `dt` would save 1 insn but the function
has other structural differences (movt vs mov #1, bf.s vs bf, different timeout path).
Only 2 functions have the pattern; FUN_060192B4 already has delta=-1 so dt would make it
more negative. **NOT WORTH IMPLEMENTING** — 1 function benefiting, still won't PASS.

**tst Rm,Rn peephole**: Only 2 functions (FUN_0600D336, FUN_0602766C) have the
`and Rm,Rn / tst Rn,Rn` pattern. Neither would PASS even with the optimization.
**NOT WORTH IMPLEMENTING**.

### Broken Expected File Investigation

Scanned all test function address ranges for `.word`-encoded instructions that gen_expected
might miss. Most `.word` entries are legitimate constant pool data. The only confirmed
case of a missed instruction encoding was FUN_060424A2 (`lds r3,macl` = `.word 0x431A`),
which was deleted.

Two skipped functions (FUN_06027552, FUN_0603C08C) compile OK but use `dmuls.l`+`xtrct`
(64-bit multiply with middle extraction). Our compiler doesn't generate `xtrct` and the
expected files would be incomplete due to `.word` encodings. Not added as tests.

### Result: 33 PASS / 92 FAIL / 125 total (26%)

**Changes from previous session**:
- -1 test (FUN_060424A2 deleted)
- FUN_060283B8 improved from delta=+6 to delta=+2

### Conclusions

After exhaustive analysis of ALL positive-delta functions, the remaining failures fall into
clear categories:

| Root Cause | Fixable? | Count |
|-----------|----------|-------|
| Register allocation (R0 constraints, spills) | No | ~15 |
| Instruction selection (add/sub, cmp/ge/gt) | No | ~10 |
| Loop optimization (test placement, strength reduction) | No | ~10 |
| Multi-branch tail call | Compiler patch needed | 3-5 |
| Missing xtrct/mova/swap.w patterns | Compiler patch needed | 3-5 |
| Delay slot filling strategy | No | ~8 |
| Our code genuinely shorter | No (already better) | 41 |

**The compiler patch phase has reached diminishing returns.** All remaining failures require
either deep compiler internals changes (register allocation, instruction selection) or
represent genuinely better code from our compiler. No simple peepholes or C source fixes
remain to be found.

## Session 11 (Day 2 Evening — Expected File Fixes & C Source Improvements)

### Broken Expected File Discovery

Found that `gen_expected.py` produces incorrect expected files when functions contain
**constant pool data in the middle** of the function body. Two types of errors:

1. **Constant pool bytes decoded as instructions**: When the disassembler decodes constant
   pool data as valid SH-2 instructions (e.g., address bytes 0x060A decode as `sts mach,rN`,
   or data bytes decode as `mov.b`). These fake instructions inflate the expected count.

2. **Missing tail instructions**: When a forward branch (`bra`) jumps past a constant pool,
   the gen_expected.py tool sometimes stops at the pool instead of continuing to capture
   instructions after it (the `else` branch, epilogue, etc.).

### Fixed Expected Files

| Function | Old Expected | Real Count | Change | New Delta |
|----------|-------------|------------|--------|-----------|
| FUN_0603BF5A | 10 | 13 | Missing tail (mov,rts,mov) | +2 → -1 |
| FUN_0603B878 | 21 | 24 | 3 fake pool entries + missing tail | +4 → +1 |
| FUN_0603B96A | 24 | 26 | 1 fake sts + missing tail (mov,rts,mov) | +1 → -1 |
| FUN_0604188C | 24 | 21 | 3 fake pool entries (sts,mov.l,mov.b) | -5 → -2 |

Pattern: `sts mach,rN` (opcode 0x0n0A) is a common false decode because Saturn ROM addresses
starting with 0x060A are frequent in constant pools.

### C Source Improvements

| Function | Old Delta | New Delta | Fix |
|----------|-----------|-----------|-----|
| FUN_06027476 | +4 | +2 | Replaced `char *` types with proper `int`/`unsigned int`, `bit > 0` loop condition generates `cmp/pl` + `shlr` |
| FUN_06030EE0 | +9 | +4 | Rewrote to use `short *p` pointer (single deref), avoids stack spill from double `*(int *)0x0607E940` dereference |

### Delta=0 Function Analysis

All 20 delta=0 functions checked with `-fno-schedule-insns2`: **NO CHANGE** for any of them.
The instruction ordering differences originate in instruction selection / register allocation,
not the post-reload scheduler. Intractable from both C source and compiler flags.

### Final Delta Distribution

```
delta=-10: 1    delta=+1: 8
delta=-7:  3    delta=+2: 6
delta=-5:  4    delta=+3: 3
delta=-4:  1    delta=+4: 1
delta=-3:  5    delta=+6: 2
delta=-2: 12    delta=+7: 2
delta=-1: 24    delta=+9: 0 (was 1, improved)
delta=0:  20
```

### Result: 33 PASS / 92 FAIL / 125 total (26%)

No new PASS functions, but delta accuracy significantly improved. Multiple functions
moved from positive delta to negative delta after correcting expected files.

## Patch 19: dt Combining Pre-DBR Pass (sh.c)
**File**: `config/sh/sh.c` (in `machine_dependent_reorg`, pre-dbr section)
**Type**: Pre-delay-slot instruction combining

The dt peephole in sh.md (Patch 1) only fires during final assembly output, AFTER the
delay slot filler has rearranged instructions. In loop contexts, the delay slot filler
inserts labels between `add #-1,rN` and `tst rN,rN`, preventing the peephole from matching.

This pass runs BEFORE delay slot filling (`dbr_schedule`), while `add #-1` and `tst` are
still adjacent. It scans for the pattern and replaces with the dt parallel RTL pattern.

**RTL pattern**: `(parallel [(set reg:SI 18 (eq:SI rN const1)) (set rN (plus:SI rN -1))])`
Note: tests `rN==1` BEFORE decrement, equivalent to `rN-1==0` AFTER.

**Implementation** (~70 lines):
- Only fires when `TARGET_SH2` is set
- Matches `(set rN (plus rN -1))` followed by `(set reg:18 (eq rN 0))`
- Skips non-physical registers (REGNO > 15)
- Uses `next_nonnote_insn()` to find adjacent tst, skipping NOTEs
- Replaces add insn's PATTERN with dt parallel RTL, resets INSN_CODE
- Converts tst insn to NOTE (NOTE_INSN_DELETED)

**Relationship to existing dt**:
- The RTL combiner already handles `dt` for non-loop cases (add+tst in same basic block)
- This pass handles loop cases where add and tst are adjacent before delay slot filling
  separates them with labels

**Effect**: FUN_0601DB84 delta improved from +2 to +1.
44 functions in the test suite's expected files contain `dt`.
Full harness: 33 PASS / 92 FAIL (no regressions, 1 delta improvement).

## Session 12 (Day 3 — dt Pass, Test Expansion, Scheduling Experiment)

### Patch 19: dt Combining Pass
See Patch 19 section above. Key discovery: the dt peephole (Patch 1) NEVER fired in loop
contexts because the delay slot filler separates `add` and `tst` with labels before
peepholes run. The new pre-dbr pass catches these cases.

### Test Suite Expansion

Added 8 new test functions:

| Function | Insns | Pattern | Result | Notes |
|----------|-------|---------|--------|-------|
| FUN_060349B6 | 7 | call + return 0 | **PASS** | jsr call with -O2 -m2 (no -mbsr) |
| FUN_0603F4B0 | 9 | stack + bsr + read byte | **PASS** | I/O read wrapper |
| FUN_06040954 | 8 | bsr + shll8/shll2/shll | FAIL (delta=0) | lds.l position differs |
| FUN_0603F4CC | 10 | stack + bsr + read word | FAIL (delta=0) | add/mov order + exts.w |
| FUN_0603F520 | 10 | stack + bsr + read long | FAIL (delta=-1) | auto-increment optimization |
| FUN_06040964 | 11 | call + clamp >=0 | FAIL (delta=-1) | keeps result in r0 directly |
| FUN_06018E70 | 12 | stack local + call | FAIL (delta=-1) | stores via @r15 not r3 copy |
| FUN_06018EAC | 14 | stack + call + mask byte | FAIL (delta=-4) | much shorter code |

**Analysis of new failures**:
- FUN_06040954: `shll8 / shll2 / lds.l` vs original `shll8 / lds.l / shll2` — instruction
  emission order difference, not scheduling (scheduler already disabled)
- FUN_0603F4CC: `add` before `mov` vs `mov` before `add` — same emission order issue.
  Also has redundant `exts.w` in rts delay slot (mov.w already sign-extends)
- FUN_0603F520: Our compiler uses `mov.l @r15+,r0` (auto-increment post-decrement
  addressing) instead of `mov.l @r15,r0 / add #4,r15` — saves 1 instruction
- FUN_06040964: Our compiler keeps return value in r0 and tests directly with `cmp/pz r0`,
  avoiding the `mov r0,r4 / ... / mov r4,r0` copy the original does

### Scheduling Experiment (Plan Stage 2)

**Hypothesis**: Post-reload scheduling causes delta=0 instruction ordering differences.

**Method**: Compiled all 11 delta=0 functions with `-fno-schedule-insns2`.

**Result**: NO CHANGE for any function. Both `flag_schedule_insns` (line 226) and
`flag_schedule_insns_after_reload` (line 231) are already set to 0 in sh.h
OVERRIDE_OPTIONS. The scheduling passes are completely disabled.

**Conclusion**: Delta=0 ordering differences originate in instruction emission order
(the expand/RTL generation phase) and the delay slot filler, not from scheduling passes.
This definitively closes the scheduling hypothesis.

### bt.s/bf.s Analysis

Investigated the `bt/bf` (non-delayed) vs `bt.s/bf.s` (delayed) conditional branch
differences across failing functions.

**Key finding**: The original binary uses BOTH forms:
- `bt.s/bf.s` in loop bodies (with `add` in delay slot for counter increment)
- `bt/bf` in non-loop contexts

2 passing functions (FUN_0602853E, FUN_06028560) use `bf.s` in their expected output,
so globally disabling delayed conditional branches would cause regressions.

**Loop scheduling difference**: For FUN_0602760C/761E/7630, the original interleaves
instructions within the loop body: `load / compare / store / bt.s / add(delay slot)`.
Our compiler generates sequential order: `load / store / add / compare / bt`. This is
a fundamental instruction emission order difference, not a delay slot filling issue.

`define_delay` for conditional branches on SH-2 is at sh.md line 152-155:
```lisp
(define_delay
  (and (eq_attr "type" "cbranch")
       (eq_attr "cpu" "sh2"))
  [(eq_attr "in_delay_slot" "yes") (nil) (nil)])
```

### 2-Instruction Expected File Investigation

Found 59 untested 2-instruction expected files. Analysis:
- 52 have pattern `mov.l, mov` — function prologues that fall through to next function
  (no `rts`). NOT standalone functions.
- 3 have `rts, nop` — trivial empty functions, already tested variants pass
- 3 have `rts, mov.l` — struct field accessors, already tested variants pass
- 1 has `rts, mov.w` — already tested variant passes

### Result: 35 PASS / 98 FAIL / 133 total (26%)

**Changes from previous session**:
- +2 new PASS (FUN_060349B6, FUN_0603F4B0)
- +8 new test functions (133 total, up from 125)
- dt combining pass implemented (Patch 19)
- Scheduling experiment completed and closed
- bt.s/bf.s patterns analyzed and documented

## Patch 20: Redundant Sign Extension Elimination in Delay Slot (sh.c)

**Problem**: After the delay slot filler runs, `rts / exts.w r0,r0` sequences can occur
where the `exts.w` is redundant because a preceding `mov.w @...,r0` already sign-extended
the value. The existing Patch 8 only catches the case where the mov.w is immediately
before the SEQUENCE, but the delay slot filler can place them far apart.

**Fix**: Added a new post-dbr pass section that scans backward from `rts / exts.w rN,rN`
SEQUENCES, looking past intervening instructions that don't modify rN. If a preceding
`mov.w @...,rN` (HI-mode memory load) is found, the exts.w is provably redundant and the
SEQUENCE is converted to a bare return (effectively replacing exts.w with nop).

**Safety checks**:
- Stops at labels, barriers, calls, and non-INSN nodes
- Stops when any instruction modifies the target register
- Only matches when the register-setting instruction is a HI-mode memory load
- Respects `-mnosignext` flag (preserves sign extensions when active)

**Impact**: Removes 1 redundant opcode diff from FUN_0603F4CC (4 diffs → 2 diffs).
Does not convert any FAILs to PASS (remaining diffs are instruction ordering).
4 functions had exts.w in rts delay slot:
- FUN_0603F4CC: Fixed (exts.w → nop, matching expected)
- FUN_0602754C: Preserved correctly (preceding instruction is swap.w not mov.w)
- FUN_0600245C: Preserved correctly (branch in scan path stops backward search)
- FUN_060024D8: Preserved correctly (preceding mov.w is a store, not a load)

**File**: `tools/gcc26-build/config/sh/sh.c`, in `machine_dependent_reorg_post_dbr()`

## Session 13 (Day 3 — Delta Analysis, Exhaustive Test Search, Patch 20)

### Delta=+1 Analysis

Analyzed all 7 delta=+1 functions (where our code is 1 instruction LONGER) for potential
C-level fixes. All are caused by deep compiler codegen issues, none fixable from C:

| Function | Root Cause |
|----------|------------|
| FUN_0603F4E0 (+1) | Callee-save r8 vs stack spill |
| FUN_0603F500 (+1) | Callee-save r8 vs stack spill |
| FUN_06038F34 (+1) | Individual address loads vs base+displacement |
| FUN_0601DB84 (+1) | bf.s/movt delay slot fill vs bf/bra pattern |
| FUN_06027358 (+1) | Duplicate shlr2 vs shared computation |
| FUN_0603B878 (+1) | Different loop structure/code organization |
| FUN_06018EC8 (+1) | Byte extraction (combiner transforms) |

### Exhaustive Test Function Search

Conducted thorough search of all 1424 untested expected files. Key findings:

**By pattern**:
- 52 untested 2-insn files: All `mov.l/mov` prologues without rts. Not testable.
- 100+ untested 4-6 insn files: Almost all are either fall-through prologues (no rts)
  or call wrappers (`sts.l/bsr/nop/lds.l`) that our compiler tail-call optimizes.
- 0 remaining simple field accessor patterns (all already have C files).

**By Ghidra decomp coverage**:
- Only 30 functions have both Ghidra decomps AND expected files AND no C files AND rts
- Of those, most use non-standard calling conventions:
  - `jsr @r0`, `jsr @r12` (indirect register calls — not reproducible in C)
  - Non-standard arg passing (r0/r1 instead of r4-r7)
  - Fall-through to next function with callee-saved register manipulation

**Compilation tests on best candidates**:
- FUN_06041180 (16 insns): delta=-2, different control flow layout (bf vs bt)
- FUN_06034C48 (16 insns): delta=-1, fewer register copies
- FUN_06041014 (16 insns): delta=-5, movt optimization makes code much shorter
- FUN_06035F16 (16 insns): delta=+14, can't generate byte displacement addressing
- FUN_0601AF8C (12 insns): delta=+1, delay slot fill difference
- FUN_06018E88 (12 insns): delta=-1, direct @r15 store vs register copy

**Conclusion**: The search for new testable functions is exhausted. All remaining untested
functions are either non-standalone, use indirect calls, or have non-standard conventions.

### Unfilled rts Delay Slot Analysis

Found 17 functions where expected has a filled rts delay slot but our compiler leaves nop:
- FUN_06009E02, FUN_0600C928, FUN_06017372, FUN_06018EC8 (byte stores in delay slot)
- FUN_0602760C, FUN_0602761E, FUN_06027630 (add in delay slot — loop counter)
- FUN_0602766C, FUN_06035C80, FUN_06036DDC (mov.l/mov.w in delay slot)
- FUN_0603B878, FUN_0603B96A, FUN_060400B4, FUN_06040964 (mov in delay slot)
- FUN_06040680, FUN_06040EBA, FUN_06041310 (mov in delay slot)

Root cause: Our compiler places `lds.l @r15+,pr` immediately before `rts`, which
prevents the delay slot filler from finding eligible instructions. The original compiler
schedules `lds.l` earlier, enabling the last operation to fill the rts delay slot.
This would require complex instruction reordering in the post-dbr pass (moving lds.l
earlier and verifying no r15/PR dependencies).

### Patch 20: Redundant exts.w Removal

See Patch 20 section above. Removes 1 redundant opcode from FUN_0603F4CC's diff.

### Result: 35 PASS / 98 FAIL / 133 total (26%)

**No pass count change** — this session was primarily analytical. Key achievements:
- Delta=+1 functions fully analyzed: all intractable from C source
- Test function search comprehensively exhausted
- Unfilled delay slot root cause identified (lds.l placement)
- Patch 20 implemented (redundant exts.w elimination)
- Failure taxonomy refined with concrete root causes

---

## Session 14: Delay Slot Fill Investigation + Per-Function Unfill Flags

### Patch 21: lds.l Reordering in Pre-DBR Pass (sh.c)

**File**: `config/sh/sh.c` — `machine_dependent_reorg()`
**Type**: Pre-delay-slot-filler instruction reordering

For CALL functions, the epilogue places `lds.l @r15+,pr` immediately before `rts`.
This prevents the delay slot filler (reorg.c) from finding eligible instructions
for the rts delay slot, because `lds.l` sets PR which `rts` reads.

The patch scans for `<insn> / lds.l @r15+,pr / rts` patterns in the pre-dbr pass
and swaps the candidate instruction past `lds.l` when:
- The candidate doesn't reference r15 (stack pointer) or PR (reg 17)
- No labels, barriers, or jumps exist between the candidate and lds.l

```
Before: mov.b r0,@r1 / lds.l @r15+,pr / rts / nop
After:  lds.l @r15+,pr / mov.b r0,@r1 / rts / nop
Then filler: lds.l @r15+,pr / rts / mov.b r0,@r1
```

**Verified**: FUN_06009E02 (rts/mov.b filled), FUN_06035C80 (rts/mov.w filled),
FUN_0600C928 (rts/mov.l filled). Some functions (e.g., FUN_06040680) correctly
not reordered due to shared labels between candidate and lds.l.

**Result**: No new PASSes (affected functions have other diffs), but delay slot
improvement is prerequisite for future matches.

### Unfilled RTS Delay Slot Deep Investigation

Categorized 14 remaining functions with unfilled rts delay slots:

1. **Loop-exit pattern** (5 functions: FUN_0602760C, _61E, _630, FUN_06017372,
   FUN_06036DDC): Backward branch (JUMP_INSN) in loop blocks `stop_search_p()`
   in reorg.c. Original compiler uses bt.s/bf.s for loop branches. Intractable
   without major changes to delay slot filler algorithm.

2. **lds.l with shared labels** (2 functions: FUN_06040680, FUN_06040964):
   Patch 21 can't reorder due to labels/barriers between candidate and lds.l.

3. **Complex control flow** (5 functions): Multiple conditional branches before
   rts create too many paths for the filler to analyze.

4. **Codegen strategy differences** (2 functions: FUN_06018EC8, FUN_0602766C):
   Different instruction selection (mov.w vs mov.l, extu.b vs direct load),
   not just delay slot.

**Conclusion**: All remaining unfilled rts cases are intractable from compiler
side. Would require fundamental changes to the delay slot filling algorithm.

### Delta=-1 Function Analysis

Analyzed 27 functions where our code is 1 instruction shorter than original.
Categorized by root cause:

- **BSR delay slot fill** (2): FUN_0600DE40, FUN_0600DE54 — our compiler fills
  bsr delay slot but original uses `bsr / nop`
- **RTS delay slot fill** (1): FUN_06033504 — our compiler fills rts delay slot
  but original uses `rts / nop`
- **Register allocation** (8): Different register choices, instruction ordering
- **Instruction selection** (7): Different shift sequences, byte extraction,
  sign extension, pool load sizes
- **Control flow** (5): Different branch structure, bf.s vs bf
- **Callee-save strategy** (4): Different PR save/restore decisions

### Patch 22: Per-Function Delay Slot Unfill Flags (sh.h + sh.c)

**Files**: `config/sh/sh.h` (flag definitions), `config/sh/sh.c` (post-dbr pass)
**Type**: Target flags + post-delay-slot-filler SEQUENCE unfilling

Added two new target flags for per-function control:
- `-mno-bsr-fill`: Unfills BSR call delay slots in post-dbr pass
- `-mno-rts-fill`: Unfills RTS return delay slots in post-dbr pass

Implementation in `machine_dependent_reorg_post_dbr()`:
- For BSR: Finds SEQUENCE-wrapped CALL_INSNs with SYMBOL_REF (BSR, not JSR),
  extracts the delay instruction, emits it before the call, replaces SEQUENCE
  with bare CALL_INSN (which outputs `bsr / nop` via `%#` template).
- For RTS: Finds SEQUENCE-wrapped RETURN JUMP_INSNs, extracts delay instruction,
  emits before return, replaces with bare RETURN.

Required unwrapping BSR's PARALLEL pattern:
`(parallel [(call (mem (symbol_ref ...)) ...) (clobber pr)])` → extract element 0
to reach the CALL node.

**Per-function .flags files created**:
- `FUN_0600DE40.flags`: `-O2 -m2 -mbsr -mno-bsr-fill`
- `FUN_0600DE54.flags`: `-O2 -m2 -mbsr -mno-bsr-fill`
- `FUN_06033504.flags`: `-O2 -m2 -mbsr -mno-rts-fill`

**Result**: 38 PASS / 95 FAIL / 133 total (28% pass rate) — 3 new PASSes

### Exhaustive Flag Search

Tested every remaining FAIL function with all flag combinations:
- `-mnofill`, `-mnosignext`, `-mno-bsr-fill`, `-mno-rts-fill`
- All pairwise and triple combinations
- Without `-mbsr`

**Result**: Zero additional matches. All 95 remaining failures are caused by
instruction scheduling/ordering, register allocation, or fundamental codegen
strategy differences that no flag combination can address.

### Remaining Failure Analysis (95 functions)

**By delta (our count minus expected count)**:
- delta < -3: 15 functions (our code much shorter — aggressive optimization)
- delta = -2 to -3: 15 functions
- delta = -1: 24 functions (our code 1 insn shorter)
- delta = 0: 23 functions (same count, opcode ordering diffs)
- delta = +1 to +2: 13 functions (our code slightly longer)
- delta > +2: 5 functions (our code much longer)

**Delta=0 breakdown (23 functions)**:
- 12 with only 2 mnemonic diffs: All are adjacent instruction swaps (scheduling)
- 4 with 4 diffs: Mix of scheduling and instruction selection
- 7 with 6+ diffs: Deeper structural differences (loop layout, branch strategy)

**Conclusion**: The 28% pass rate represents the practical ceiling achievable through
compiler flags and peephole patches. Further progress requires either:
1. Changes to GCC's register allocator (global.c, local-alloc.c) — high risk
2. Changes to the delay slot filler algorithm (reorg.c) — high risk
3. Full instruction scheduler tuning — moderate risk but limited impact
4. C source rewriting to match original coding patterns — case-by-case
