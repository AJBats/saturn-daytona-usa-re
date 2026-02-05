# GCC 2.6.3 SH-2 Backend — Internals Knowledge Base

This document captures deep technical knowledge about the GCC 2.6.3 SH-2 backend
internals, organized by subsystem. Intended to survive context resets across sessions.

---

## SH-2 Calling Convention

- r0 = return value
- r4-r7 = arguments
- r0-r7 = caller-saved
- r8-r14 = callee-saved
- r15 = stack pointer
- PR = link register (reg 17)

---

## Compilation Pass Order (toplev.c `rest_of_compilation`)

```
1.  jump_optimize()           (toplev.c ~2876)  - dead code elimination
2.  cse_main()               (~2914)  - common subexpression elimination
3.  loop_optimize()          (~2944)  - loop invariant hoisting
4.  cse_main() [2nd pass]    (~2975)  - re-run CSE after loop opt
5.  flow_analysis()          (~3032)  - control/dataflow analysis
6.  combine_instructions()   (~3053)  - RTL combiner (UNSIGNED RANGE CHECKS HERE)
7.  schedule_insns()         (~3082)  - pre-reload scheduling (DISABLED for SH)
8.  regclass()              (~3100)  - compute register classes
9.  local_alloc()           (~3101)  - single-block pseudo allocation
10. global_alloc()          (~3129)  - multi-block pseudo allocation
11. reload()               (~3131)  - fix constraint violations, spills
12. thread_prologue()       (~3152)  - function entry/exit
13. schedule_insns() [2]   (~3166)  - POST-RELOAD scheduling (ACTIVE at -O2)
14. MACHINE_DEPENDENT_REORG() (~3207)  - sh.c: const pool + tail calls
15. dbr_schedule()         (~3216)  - delay slot filling (reorg.c)
16. MACHINE_DEPENDENT_REORG_POST_DBR() (~3231)  - sh.c: return dedup, sign ext, reg compact
17. shorten_branches()     (~3238)  - adjust branch displacements
18. final()                (~3276)  - emit assembly
```

---

## Instruction Scheduler (sched.c — 4944 lines)

### Key Finding: Post-Reload Scheduling IS Active

**CRITICAL**: `sh.h` OVERRIDE_OPTIONS (line 216) sets `flag_schedule_insns = 0` to
disable PRE-reload scheduling. But `flag_schedule_insns_after_reload` is set by
`-O2` in `toplev.c` line 3443. **Post-reload scheduling IS running.**

### Scheduling Experiment Results (2026-02-03)

Compiled all 22 test functions with `-fno-schedule-insns2` appended:

| Function | Default diffs | No-sched2 diffs | Change |
|----------|--------------|-----------------|--------|
| FUN_06030EE0 | 4 | 2 | **-2 diffs** (scheduling caused 2 opcode reorderings) |
| FUN_0600C970 | 12 | 10 | **-2 diffs** |
| FUN_06033504 | 5 | 3 | **-2 diffs** |
| FUN_060192B4 | 8 | 8 | Changed but same count |
| FUN_06005174 | (2 diffs) | unchanged | NOT from sched2 |
| FUN_0601164A | (2 diffs) | unchanged | NOT from sched2 |
| FUN_06018EC8 | (4 diffs) | unchanged | NOT from sched2 |
| All 6 PASS | PASS | PASS | **No regressions** |

**Conclusions**:
- Post-reload scheduling accounts for 2 diffs each in FUN_06030EE0, FUN_0600C970, FUN_06033504
- FUN_06005174 and FUN_0601164A diffs come from ELSEWHERE (likely machine_dependent_reorg
  or initial RTL generation, not scheduling)
- FUN_06018EC8 byte extraction is a combiner issue (confirmed)
- Disabling sched2 globally has NO regressions on passing tests
- **Recommendation**: Disable post-reload scheduling globally in sh.h OVERRIDE_OPTIONS

### Scheduler Tie-Breaking (rank_for_schedule, sched.c ~2384)

1. **Priority** — longest dependency path to a use
2. **Conflict class** — data dep < anti/output dep < independent
3. **INSN_LUID** — original order as final tiebreaker

### SH Function Units (sh.md lines 131-133)

```scheme
(define_function_unit "memory" 1 0 (eq_attr "type" "load,pcloadsi,pcloadhi") 2 0)
(define_function_unit "mpy"    1 0 (eq_attr "type" "smpy") 3 0)
(define_function_unit "mpy"    1 0 (eq_attr "type" "dmpy") 5 0)
```

- Memory loads: 2-cycle latency (result available after 2 cycles)
- Multiply (single): 3-cycle latency
- Multiply (double): 5-cycle latency

---

## RTL Combiner (combine.c — 10,820 lines)

### Unsigned Range Check Transform

`fold-const.c` `range_test()` (lines 2514-2619) transforms:
```c
if (val >= A && val <= B)
```
into:
```c
if ((unsigned)(val - A) <= (B - A))
```

This is called from `fold_truthop()` (line 2646-2715) when it sees `TRUTH_AND_EXPR`
with two comparisons on the same variable. **No target hook to disable it.**

**Workaround**: Use nested `if` statements in C source:
```c
if (val >= A) { if (val <= B) { ... } }
```
GCC 2.6.3 does NOT re-merge nested ifs into a range test.

### Byte Load Optimization

The combiner recognizes that `(and:SI (sign_extend:SI (mem:HI addr)) 0xFF)` is
equivalent to `(zero_extend:SI (mem:QI addr))` and emits a direct `mov.b` instead
of `mov.w` + `extu.b`. **No target hook to disable.**

**Workaround**: Use `volatile` on the 16-bit load to prevent optimization through it.

---

## Register Allocator

### Allocation Order (sh.h line 561)

```c
#define REG_ALLOC_ORDER  \
  { 1,2,3,7,6,5,4,0,14,13,12,11,10,9,8,15,16,17,18,19,20,21 }
```

Priority: r1→r2→r3→r7→r6→r5→r4→r0→r14...r8→r15→specials

r0 is allocated LAST among caller-saved registers because `SMALL_REGISTER_CLASSES`
restricts r0 usage (many SH instructions require R0 specifically, causing conflicts).
The `compact_leaf_regs()` post-DBR pass recovers r0 for leaf functions.

### Two-Stage Process

1. **Local allocation** (`local-alloc.c` ~2372 lines): Single basic block pseudos
   - Hook: `ORDER_REGS_FOR_LOCAL_ALLOC` — SH does NOT define this (could be used)
2. **Global allocation** (`global.c` ~1713 lines): Cross-block pseudos
   - Uses graph coloring with REG_ALLOC_ORDER preferences
3. **Reload** (`reload.c` ~5780 lines): Fix constraint violations, generate spills
   - Checks `HARD_REGNO_MODE_OK(REGNO, MODE)` (sh.h line 393)

---

## Delay Slot Filler (reorg.c — 4356 lines)

Entry: `dbr_schedule(first, file)` at line 4139.

Runs after `machine_dependent_reorg` (which does const pool + tail calls).
Fills delay slots of branches, jumps, and returns with useful instructions.

### What Can Fill a Delay Slot (sh.md)

```scheme
(define_attr "in_delay_slot" "maybe,yes,no"
  (cond [(eq_attr "type" "cbranch") (const_string "no")
         (eq_attr "type" "jump")    (const_string "no")
         (eq_attr "type" "pload")   (const_string "no")
         (eq_attr "type" "pcloadsi")(const_string "no")
         (eq_attr "type" "pcloadhi")(const_string "no")
         (eq_attr "type" "return")  (const_string "no")
         (eq_attr "length" "2")     (const_string "yes")
         ...] ...))
```

Only 2-byte instructions can fill delay slots. Branches, jumps, PR loads,
PC-relative loads, and returns CANNOT be in delay slots.

### Delay Types

- `rts` delay slot: filled from preceding instructions
- `bra`/`jmp` delay slot: filled from preceding instructions
- `bf.s`/`bt.s` delay slot (SH-2): conditional branch with delay slot

---

## machine_dependent_reorg (sh.c — runs BEFORE dbr_schedule)

### PC-Relative Constant Pooling (lines 1881-1934)

For each `broken_move()` insn (constants too large for immediate):
1. `find_barrier()` walks forward looking for existing CODE_BARRIER
2. If no barrier within range, creates synthetic jump+barrier+label
3. Constants pooled into literal table behind the barrier
4. Range limits: SI constants max 1010, HI constants max 500

### Tail Call Optimization (lines 1936-2049)

Scans backward from function end looking for pattern:
```
CALL_INSN → lds.l @r15+,pr → RETURN
```

Two cases:
- **Pure wrapper** (1 call, 1 PR push): bare `bra _func` (no PR handling)
- **Multiple calls**: `bra _func / lds.l @r15+,pr` (lds.l in delay slot)

---

## machine_dependent_reorg_post_dbr (sh.c — runs AFTER dbr_schedule)

### Return Block Deduplication (lines 2072-2171)

When dbr_schedule steals an instruction from before a branch label into a return's
delay slot, it creates duplicate bare returns. This pass:
1. Detects exactly 2 returns (1 SEQUENCE-wrapped, 1 bare)
2. Extracts delay insn from SEQUENCE
3. Redirects branches (including bf.s/bt.s SEQUENCE wrappers) to shared return
4. Deletes duplicate

### Delay Slot Sign Extension Fix (lines 2173-2248)

Replaces no-op `exts.w rN,rN` in rts delay slot with the preceding `mov.w` load:
```
mov.w @r1,r0  →  rts
rts               mov.w @r1,r0
exts.w r0,r0
```

### Leaf Register Compaction (lines 2250-2678)

Two phases for leaf functions (no CALL_INSN, no internal branches except returns):

**Phase 1** (simple): Map used r0-r3 to consecutive lower slots
**Phase 2** (liveness merge): Merge registers with non-overlapping live ranges

Liveness tracking:
- `first_def[r]`: earliest write (SET destination)
- `last_use[r]`: latest read
- Asymmetric overlap check protects implicit r0 use at RETURN

---

## aprog.s Format (for gen_expected.py)

Each instruction: `.byte 0xXX, 0xYY  /* XXXXXXXX: MNEMONIC operands {pool} */`

Function boundaries: `/* FUN_XXXXXXXX (0xXXXXXXXX) */` + `.global` + label

After rts+delay slot: constant pool data (`.word` entries — SKIP these)

Normalize: `bf/s` → `bf.s`, `bt/s` → `bt.s`

---

## Target Flags (sh.h)

| Flag | Bit | Purpose |
|------|-----|---------|
| TARGET_SH2 | `SH2_BIT` (1<<9) | Enable SH-2 insns (dt, bf.s/bt.s) |
| TARGET_BSR | `BSR_BIT` (1<<26) | Enable BSR calls + tail calls |
| TARGET_DT | `DT_BIT` (1<<5) | Enable dt instruction |
| flag_schedule_insns | global | Pre-reload scheduling (DISABLED in sh.h) |
| flag_schedule_insns_after_reload | global | Post-reload scheduling (SET by -O2) |
| flag_delayed_branch | global | Delay slot filling (SET to 1 in sh.h) |

### OVERRIDE_OPTIONS (sh.h ~198-227)

```c
optimize = 1;                                    /* Always optimize */
flag_delayed_branch = 1;                         /* Enable delay slot filling */
flag_schedule_insns = 0;                         /* NEVER schedule before reload */
flag_schedule_insns_after_reload = 0;            /* ALSO disable post-reload scheduling */
if (TARGET_BSR) flag_no_function_cse = 1;        /* No CSE of function addresses */
```

Note: `flag_schedule_insns_after_reload = 0` was added based on the scheduling experiment
(see Scheduler section). Without this, `-O2` enables post-reload scheduling via `toplev.c`
line 3443, causing 2-diff instruction reorderings in 3+ functions.

---

## Build Directory Sync (gcc26-build vs gcc-2.6.3)

**CRITICAL**: The build directory `tools/gcc26-build/config/sh/` has its OWN copies of
`sh.c`, `sh.h`, `sh.md`. The patched source lives in `tools/gcc-2.6.3/config/sh/`. These
are NOT symlinks — they must be manually synced after edits.

The `Makefile` references `aux-output.c` which is a symlink to `./config/sh/sh.c` in
the build directory. When `make` runs, it compiles `gcc26-build/config/sh/sh.c`, NOT
`gcc-2.6.3/config/sh/sh.c`.

**Sync procedure** (after editing gcc-2.6.3 sources):
```bash
# Files may be read-only — fix permissions first
wsl -d Ubuntu -- chmod u+w /mnt/d/.../tools/gcc26-build/config/sh/sh.c
wsl -d Ubuntu -- chmod u+w /mnt/d/.../tools/gcc26-build/config/sh/sh.h
wsl -d Ubuntu -- chmod u+w /mnt/d/.../tools/gcc26-build/config/sh/sh.md
wsl -d Ubuntu -- chmod u+w /mnt/d/.../tools/gcc26-build/toplev.c

# Copy patched sources to build dir
wsl -d Ubuntu -- cp /mnt/d/.../tools/gcc-2.6.3/config/sh/sh.c  /mnt/d/.../tools/gcc26-build/config/sh/sh.c
wsl -d Ubuntu -- cp /mnt/d/.../tools/gcc-2.6.3/config/sh/sh.h  /mnt/d/.../tools/gcc26-build/config/sh/sh.h
wsl -d Ubuntu -- cp /mnt/d/.../tools/gcc-2.6.3/config/sh/sh.md /mnt/d/.../tools/gcc26-build/config/sh/sh.md
wsl -d Ubuntu -- cp /mnt/d/.../tools/gcc-2.6.3/toplev.c        /mnt/d/.../tools/gcc26-build/toplev.c
```

**Symptom of desync**: PASS count drops suddenly (e.g., 28→13) after a rebuild.
The build dir files revert to pre-patch state if overwritten by `configure --force`
or other operations.

**Verification**: After rebuild, check key patches are present:
```bash
wsl -d Ubuntu -- grep 'flag_schedule_insns_after_reload' /mnt/d/.../tools/gcc26-build/config/sh/sh.h
wsl -d Ubuntu -- grep 'machine_dependent_reorg_post_dbr' /mnt/d/.../tools/gcc26-build/config/sh/sh.c
```

---

## Ghidra Decompiler Pitfalls

### Operator Precedence Bugs (C shift vs addition)

In C, `<<` (bitwise shift) has **LOWER** precedence than `+` (addition). Ghidra's
decompiler often outputs expressions like:
```c
*(int *)(puVar1 + uVar2 << 2)          // WRONG: parses as (puVar1 + uVar2) << 2
*(int *)(puVar1 + (uVar2 << 2))        // CORRECT
```

This is the most common Ghidra decompilation bug. It produces code that compiles but
generates wildly wrong assembly (shifts the entire address left instead of just the index).

**Pattern to watch for**: Any expression with `<< N` that also has `+` at the same level.
Add explicit parentheses around the shift: `(expr << N)`.

**Affected files in test suite**: FUN_06011494, FUN_0603B96A, FUN_06038044, FUN_06006838,
FUN_06011678, FUN_0601AB8C, FUN_0603B9A4, FUN_06042BAC.

**Impact**: FUN_0603B96A went from delta +21 to +1 just from this fix. FUN_0601AB8C
from delta +8 to +1.

### movt Boolean Materialization

When Ghidra decompiles a loop as:
```c
bVar1 = iVar2 < param_3 + -4;
/* ... loop body ... */
while (bVar1 != 0);
```

GCC materializes the boolean with `cmp/gt + movt` (2 extra instructions per iteration).
The fix is to put the comparison directly in the `while()` condition and pre-compute
the limit:
```c
param_3 = param_3 + -4;      // pre-compute limit
do {
    /* ... loop body ... */
    iVar2 = iVar2 + 4;
} while (param_3 > iVar2);   // comparison form generates cmp/gt + bt
```

**Key**: Use `param_3 > iVar2` (not `iVar2 < param_3`) to generate `cmp/gt Rm,Rn`
matching the expected output. The SH-2 `cmp/gt` compares the operands in a specific
order determined by the register positions.

**Affected functions**: FUN_0602760C, FUN_0602761E, FUN_06027630 (all copy loops).
Reduced from 13 to 11 insns each (delta +4 → +2). Remaining +2 is from register
allocation (extra `mov r4,r3` / `mov r5,r2` copies).

---

## swap.w vs shlr16 — Constraint Experiment

### Background

The `ashrsi3_16` pattern in sh.md emits `shlr16 + exts.w` for arithmetic right shift
by 16. This is a single RTL insn (length=4) that produces two assembly instructions.
Because `shlr16` operates in-place, it uses a `"0"` constraint (output must be same
register as input).

The SH-2 `swap.w Rm,Rn` instruction swaps upper/lower 16 bits and allows different
source/dest registers. This would eliminate register copies in patterns like
FUN_0602754C (`(int)(short)(param >> 16)`).

### Experiment

Changed `ashrsi3_16`:
- Constraint `"0"` → `"r"` (any register for input)
- Output `shlr16` → `swap.w`

**Result: MASSIVE REGRESSION** — PASS dropped from 28 to 13.

### Root Cause

The `"r"` constraint gives the register allocator MORE freedom, which paradoxically
produces WORSE code globally. With `"0"`, the allocator MUST place source and dest
in the same register, which constrains allocation in a way that turns out to be
beneficial for surrounding code. With `"r"`, the allocator makes different choices
that ripple through the entire function.

### Lesson

In GCC 2.6.3, changing RTL constraints has non-local effects on register allocation.
A change that seems strictly better (more flexible) can cause global regressions.
Always test with the FULL harness, not just the target function.

The correct approach would be a post-allocation peephole that converts
`mov rN,rM / shlr16 rM / exts.w rM,rM` → `swap.w rN,rM / exts.w rM,rM` after
register choices are frozen.

### Successful Implementation (Patch 11)

The safe approach was implemented as a **pre-dbr pass** (not a define_peephole):

1. Added `swap_w` define_insn in sh.md: `(rotate:SI Rm (const_int 16))` → `swap.w`
   with "r" constraint (different src/dst OK)
2. In `machine_dependent_reorg` (runs BEFORE delay slot filling), scan for:
   - `(set rM rN)` followed by `(parallel [(set rM (ashiftrt:SI rM 16)) (clobber T)])`
   - Where rN != rM
3. Replace:
   - The mov with `(set rM (rotate:SI rN (const_int 16)))` → matched by swap_w insn
   - The ashrsi3_16 with `(set rM (sign_extend:SI (reg:HI rM)))` → matched by extendhisi2

**Why pre-dbr, not define_peephole**: The peephole would produce a single RTL insn
outputting `swap.w + exts.w` (2 asm instructions). The delay slot filler can't split
a single RTL insn, so the exts.w couldn't be moved into an rts delay slot. By splitting
BEFORE dbr_schedule, the delay slot filler naturally picks up the separate exts.w.

**Key safety checks**:
- `next_nonnote_insn` skips NOTEs but stops at CODE_LABELs → no jump target between
- Shift amount checked via `INTVAL(...) == 16` → won't match ashrsi3_k (shift by 1)
- Only fires when src != dst → no-op for already-same-register cases

**Result**: +1 PASS (FUN_0602754C), FUN_0603C0A0 delta +1→0, no regressions.

---

## Constant Pool Width Analysis

### How Constants Are Pooled

The SH backend uses PC-relative constant pools. Each constant gets either a 16-bit
or 32-bit pool entry:

| Load | Pool width | Max displacement | Instruction |
|------|-----------|-----------------|-------------|
| HI (16-bit) | `.word` | 510 bytes | `mov.w @(disp,PC),rN` |
| SI (32-bit) | `.long` | 1020 bytes | `mov.l @(disp,PC),rN` |

### Key Functions (sh.c)

**`hi_const(src)`** (lines 1763-1778): Returns true if constant fits in 16 bits.
```c
return (GET_CODE (src) == CONST_INT
        && INTVAL (src) >= -32768
        && INTVAL (src) <= 32767);
```

**`broken_move(insn)`** (lines 1780-1828): Returns true if insn needs pool constant.
Calls `hi_const()` to decide 16-bit vs 32-bit. Only examines `CONST_INT` — `SYMBOL_REF`
always returns false from `hi_const()`, forcing 32-bit.

**`add_constant(x, mode)`** (lines 1835-1860): Adds constant to pool, deduplicating.
Uses `mode` to select HI vs SI pool entry.

**`dump_table(scan)`** (lines 1862-1878): Emits pool entries. HImode → `.word`,
SImode → `.long`.

### The extern Problem

When C code declares `extern int DAT_0600c9e4;`, GCC creates a `SYMBOL_REF` for the
address. This ALWAYS gets a 32-bit pool entry (`mov.l @(disp,PC),rN`) followed by
a dereference (`mov.l @rN,rN`). Total: 2 instructions.

The original binary often has the VALUE directly in a 16-bit pool entry:
`mov.w @(disp,PC),rN`. Total: 1 instruction.

**Impact**: 32 functions affected (largest single pattern in failure taxonomy).

### Fix Approaches

1. **C source rewrite** (lowest risk): Replace `extern` with literal constant where
   the ROM value is known. E.g., `extern int DAT_0600c9e4;` → `0x0150` (if that's
   the value at that ROM address). Requires cross-referencing with `aprog.s` or
   binary dump to find actual values.

2. **Compiler change** (higher risk): Modify `hi_const()` to also accept `SYMBOL_REF`
   when the address fits in 16 bits. Would need new addressing mode support.

3. **Linker script trick**: Place extern symbols at their ROM addresses and let the
   linker resolve. But GCC still emits 32-bit pool entry for SYMBOL_REF.

---

## Key Source File Locations

| File | Lines | Purpose |
|------|-------|---------|
| `config/sh/sh.c` | 3319 | Backend implementation |
| `config/sh/sh.h` | 1498 | Target macros/flags |
| `config/sh/sh.md` | 1985 | Machine description (98 insns, 10 peepholes) |
| `toplev.c` | ~3600 | Pass orchestration |
| `sched.c` | 4944 | Instruction scheduler |
| `combine.c` | 10820 | RTL combiner |
| `fold-const.c` | ~9000 | Tree-level constant folding |
| `reorg.c` | 4356 | Delay slot filler |
| `local-alloc.c` | 2372 | Local register allocation |
| `global.c` | 1713 | Global register allocation |
| `reload.c` | 5780 | Reload pass |

---

## Session 5 Findings (2026-02-03)

### add-to-shll Pre-DBR Pass (Patch 12)

Replaces `add rN,rN` with `shll rN` when T flag is dead. Requires forward
scanning for T-flag liveness:
- `NOTE` insns: skip (no effect on T)
- `CODE_LABEL` / `BARRIER`: conservative stop
- `JUMP_INSN`: check if T (reg 18) is referenced in PATTERN — if not, it's an
  unconditional jump and T is dead; if yes, it's a conditional branch and T is live
- `INSN` with PARALLEL: check for T clobber vs T read in individual elements
- `INSN` with SET to T: T is set (dead from previous use)

### Indexed Addressing Pre-DBR Pass (Patch 13)

Combines adjacent `add rA,rB` + memory access through `@rB` into indexed addressing
`@(rA,rB)`:
- SH-2 constraint: one of rA/rB must be r0 (REG_OK_FOR_INDEX_P requires REGNO==0)
- `print_operand_address` (sh.c:312) handles PLUS with REG+REG by printing `@(r0,rN)`
  where rN = `reg_names[MAX(REGNO(base), REGNO(index))]`
- Works for loads (SI, HI, QI modes) and stores
- Dead register check: rB==rC (load overwrites), or forward scan for register liveness
- Deletes add insn via `PUT_CODE(scan, NOTE); NOTE_LINE_NUMBER(scan) = NOTE_INSN_DELETED`

### Full-Scale Scheduling Experiment

With 133 test functions, tested `-fno-schedule-insns2` against ALL 20 delta=0 failures:
**Zero change for any function.** This definitively proves that instruction ordering
differences are NOT caused by the post-reload scheduler.

The differences come from:
1. **RTL expansion order** in `expand_expr()`: GCC evaluates sub-expressions in a fixed
   order determined by the expression tree, which differs from the original compiler
2. **Reload pass**: constant pool loads are inserted by the reload pass at specific points
   in the instruction stream, and their position determines the final instruction order
3. **Register allocator preferences**: GCC prefers lower-numbered registers for certain
   roles, which influences instruction ordering through register selection

These are fundamental compiler internals that cannot be changed without rewriting
core GCC passes.

### C Source Type Fixes

Using `char *` instead of `int` for pointer parameters in copy loop functions
(FUN_0602760C, FUN_0602761E, FUN_06027630) eliminated unnecessary register copies.
The compiler copies `int` params to different registers for indexed addressing but
keeps `char *` params in their original argument registers (r4/r5).

### Failure Distribution Insight

Of 102 failures: 50 have shorter code from our compiler (delta<0), meaning half of
all "failures" are actually cases where our GCC generates genuinely better code than
the original 1995 compiler. Only 32 failures (31%) have longer code that could
potentially be improved.
