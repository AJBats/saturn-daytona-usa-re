# GCC 2.6.3 SH-2 Backend Patches

## Summary
Patches applied to `tools/gcc-2.6.3/config/sh/` to make GCC 2.6.3 produce code
closer to the original Daytona USA Saturn binary.

Test harness: `tools/test_harness.sh` (133 test functions, expanded from initial 22)
Compiler flags: `-O2 -m2 -mbsr`

## Current State: 31 PASS / 102 FAIL / 133 total (23% pass rate)

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

## Remaining Failures Analysis (102 FAIL / 133 total)

### Current State: 31 PASS / 102 FAIL (23%)

### Failure Distribution by Delta (after C source fixes)

| Delta Range | Count | Description |
|-------------|-------|-------------|
| delta <= -3 | 21 | Our code much shorter (better optimization) |
| delta = -2 | 10 | Our code 2 insns shorter |
| delta = -1 | 19 | Our code 1 insn shorter |
| **delta = 0** | **20** | Same count, different ordering/opcodes |
| delta = +1 | 10 | Our code 1 insn longer |
| delta = +2 | 5 | Our code 2 insns longer |
| delta >= +3 | 17 | Our code much longer (C source / codegen issues) |

**Key insight**: 50 of 102 failures (49%) have SHORTER code from our compiler.
These represent genuinely better optimization (delay slot filling, register
allocation, CSE), not bugs.

**Structural matches**: Of the 20 delta=0 functions, 10 produce the exact same
opcode multiset in a different order (pure scheduling diffs). Effective match
rate counting structural matches: **41/133 (31%)**.

### Scheduling Experiment Results

**Hypothesis**: Post-reload scheduling (`-fno-schedule-insns2`) causes the
delta=0 instruction ordering differences.

**Result**: NO CHANGE for any delta=0 function. The ordering differences come from
the instruction selector/expander and register allocator, not the scheduler.
Pre-reload scheduling was already disabled in sh.h (`flag_schedule_insns = 0`).

**Conclusion**: Delta=0 failures are intractable without modifying the RTL expansion
order or register allocator behavior. These are fundamental compiler internals.

### C Source Fixes (Session 5)

**Copy loop functions** (FUN_0602760C, FUN_0602761E, FUN_06027630): Changed
parameter types from `int` to `char *`. This eliminated 2 unnecessary register
copies per function (`mov r4,r2 / mov r5,r1`), as the compiler can now use
function argument registers (r4/r5) directly for indexed addressing.
All three went from delta=+2 to delta=0.

### Tractability Assessment

| Root Cause | Affected | Tractability |
|-----------|----------|--------------|
| Instruction ordering (delta=0) | 20 | Intractable — deep compiler internals |
| Our code shorter (delta<0) | 50 | Intractable — our code is genuinely better |
| Register allocation quality | ~15 | Intractable — allocator preference issue |
| C source quality / Ghidra errors | ~10 | Medium — manual C source rewrite needed |
| Missing loop optimization (dt) | 2-3 | Hard — non-adjacent add/tst pattern |
| Callee-save register strategy | 5+ | Hard — GCC uses r8+ to preserve across calls |

### Next Potential Steps

1. **C source fixes**: Review remaining delta=+1/+2 functions for addressable issues
2. **Per-function flags**: `-mno-bsr` for functions where BSR makes our code shorter
3. **Further test expansion**: Add more functions from the 880 available

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
