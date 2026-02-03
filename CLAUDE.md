# CRITICAL: Autonomous Operation Rules

**This section is active. Work continuously without user interaction.**

1. **Never stop to ask questions** - make reasonable assumptions and document them
2. **Never use the AskUserQuestion tool** - the user is away; decide autonomously and document your reasoning
3. **Never run git commands** (commit, push, branch, etc.) - the user will review and commit when they return
4. **Never trigger user prompts** - if a tool use is rejected/blocked, adjust approach and retry silently. Do not re-ask.
5. **Save all work to disk frequently** - write results to files after each major step
6. **Use TodoWrite aggressively** - plan before executing, mark tasks as you go
7. **If blocked, skip and move on** - document what blocked you and continue with next task

## WSL Gotchas
- **CRLF**: Files written on Windows have CRLF. Pipe through `tr -d '\r'` when reading
  Windows files in WSL. The test harness handles this for .c and .expected files.
- **grep tabs**: `grep '^\t...'` does NOT match tabs in basic regex. Use `grep -P '^\t...'`
  (Perl regex) to match literal tab characters.
- **Running scripts**: Strip CRLF from scripts first:
  `tr -d '\r' < script.sh > /tmp/clean.sh && bash /tmp/clean.sh`
  OR run directly: `bash /mnt/d/.../script.sh` (bash handles CRLF in scripts)

## Test Harness Status (after 6 patches)
Run: `MSYS_NO_PATHCONV=1 wsl -d Ubuntu -- bash /mnt/d/.../tools/test_harness.sh`
- **3 PASS / 19 FAIL / 22 total**: FUN_0600D266, FUN_06026DF8, FUN_06035C48
- Notable delta=0 (count matches but opcode diffs): FUN_06005174, FUN_06012E00, FUN_060192B4, FUN_06018EC8
- Several functions at delta=-1/-2 (our code SHORTER than original via BSR/tail call)
- Tests in `tests/*.c` with expected opcodes in `tests/*.expected`
- **Uses gcc26-build/cc1** (NOT gcc-2.6.3/cc1 which is stale)

## Current Session Task: Compiler Patch Loop ("Ralph Wiggum")

**Goal**: Build automated test harness, then iteratively patch GCC 2.6.3 SH backend until
test functions produce matching asm output. Each patch must never regress passing tests.

**Patch priority order**: ~~dt~~ → ~~bsr~~ → ~~tail calls~~ → ~~pure wrapper~~ → ~~disp stores~~ → ~~sign extension~~ → return dedup → delay slot sign ext

**Test harness**: `tools/test_harness.sh` - compiles C sources, extracts expected asm from
aprog.s, compares instruction streams, reports PASS/FAIL per function.

**Rebuilding cc1** (MUST run in WSL):
```bash
cd /mnt/d/Projects/SaturnReverseTest/tools/gcc26-build
make -j$(nproc) cc1 CFLAGS="-std=gnu89 -m32 -static -fcommon -DHAVE_STRERROR"
```

**SH backend source files** (edit these for patches):
- `tools/gcc26-build/config/sh/sh.c` - backend implementation (57KB)
- `tools/gcc26-build/config/sh/sh.h` - target definitions/flags (50KB)
- `tools/gcc26-build/config/sh/sh.md` - machine description / RTL patterns (55KB)

**dt patch specifics**: Original binary uses `dt rN` (119 occurrences) where our GCC emits
`add #-1,rN / tst rN,rN`. The dt instruction decrements and sets T flag in one opcode.
Usually followed by bf/s or bt/s. Look in sh.md for the decrement+test pattern.

---

# Daytona USA Saturn - Progressive Decomp Project

## Project Goal
Reverse engineer Sega Saturn Daytona USA (1995) to extract gameplay code (physics,
steering, collision, AI) for transplanting into Daytona USA CCE (1996).

## Documentation
- `docs/subsystem_map.md` - Full map of all 31 identified subsystems, game state machine, extraction priorities
- `docs/verification_results.md` - Side-by-side comparison of 25 functions (our GCC vs original binary)
- `docs/function_catalog.md` - Catalog of all 880 decompiled functions with size/type classification

## Key Files
- `build/aprog.s` - Full binary disassembly (206K lines, 1234 function labels, SH-2 asm)
- `ghidra_project/decomp_all.txt` - Ghidra decompiler output for 880 functions (~40 game state handlers MISSING, need re-export)
- `tools/gcc26-build/cc1` - Patched GCC 2.6.3 compiler for SH-2 (runs in WSL)
- `tools/gcc-2.6.3/` - Patched GCC source (6 patches in config/sh/sh.c, sh.h, sh.md)
- `build/aprog_syms.txt` - 1234 function symbols in linker script format
- `tools/verify_batch*.sh` - Verification scripts comparing GCC output to original binary

### Compiler Invocation
```bash
MSYS_NO_PATHCONV=1 wsl -d Ubuntu -- bash /path/to/script.sh
```
Inside scripts: `$CC1 -quiet -O2 -m2 -mbsr input.c -o output.s` where CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1

**Required flags**: `-m2` (SH-2 features: dt, bf.s/bt.s), `-mbsr` (PC-relative calls, tail calls)

**Full rebuild** (required when sh.md/sh.c/sh.h change):
`MSYS_NO_PATHCONV=1 wsl -d Ubuntu -- bash /mnt/d/Projects/SaturnReverseTest/tools/final-rebuild.sh`

### Compiler Patches Applied (see docs/compiler_patches.md)
1. **dt peephole** (sh.md): `add #-1,rN / tst rN,rN` → `dt rN` - WORKING
2. **BSR fix** (sh.c): Fixed `bsr_operand()` to accept any SYMBOL_REF - WORKING
3. **Tail call** (sh.md + sh.c): Last call before return → `bra _func / lds.l @r15+,pr` - WORKING
4. **Pure wrapper** (sh.md + sh.c): Single-call wrapper functions → simple `bra` (no PR save/restore) - WORKING
5. **Disp store peephole** (sh.md + sh.c): `mov rN,rM / add #D,rM / mov.w rK,@rM` → `mov.w r0,@(D,rN)` - WORKING
6. **Sign ext elimination** (sh.md): `mov.w @...,rN / exts.w rN,rM` → `mov.w @...,rM` (+ fixed disabled QI peephole) - WORKING

### Remaining Known Compiler Differences
1. **Register allocation**: Our compiler prefers r1,r2 for caller-saved temps; original uses r3,r4
2. ~~No `dt` instruction~~: FIXED by dt peephole
3. **bf/s delayed branch**: GCC uses bf.s/bt.s with -m2 but not always where original does
4. ~~No tail call optimization~~: FIXED by tail call patch (bra+lds.l in delay slot)
5. ~~No displacement store~~: FIXED by disp store peephole (mov.w r0,@(disp,Rn))
6. **Extern vs constant pool**: Original embeds values directly in constant pool. C externs cost +1 insn
7. **rts/jsr delay slot**: GCC DOES fill rts and jsr delay slots in many cases
8. **Range check optimization**: GCC transforms `a<=x<=b` to `(unsigned)(x-a)<=(b-a)` with cmp/hi
9. **Multiply avoidance**: Must use `<< N` not `* power_of_2` to avoid ___mulsi3 library call
10. ~~No `bsr` direct calls~~: FIXED by BSR fix
11. **R0-specific insns**: GCC uses `and #imm,r0` (1 insn) where original uses 4-insn sequence
12. **Callee-save vs stack params**: GCC preserves params across calls in callee-saved regs (more overhead); original saves on stack
13. ~~Sign extension insertion~~: PARTIALLY FIXED by sign ext peephole (catches mov.w load+exts.w; can't fix delay slot or live-register cases)

### Verified Functions (25 total: 17 LEAF + 8 CALL)
See docs/verification_results.md for full details and summary table.
- 8 perfect/structural matches (32%)
- 7 functions where our code is shorter (28%, up to -4 insns)
- 4 functions +1 insn longer (16%)
- 6 functions +2-6 insns longer from missing patterns (24%)

### Architecture
- Main loop at `main` (0x06003000) is a **32-state machine** dispatching through jump table
- All arithmetic is **32-bit fixed-point integer** (no FPU on SH-2)
- Three courses with parallel code paths (CS0/CS1/CS2)
- Common object struct: X/Y/Z at +0x10/+0x14/+0x18, rotation at +0x1C/+0x20/+0x24
- See `docs/subsystem_map.md` for full details

### Known Gaps
- ~40 game state handler functions (0x060088CC-0x06009E60) missing from Ghidra export - need re-export

### SH-2 Calling Convention
- r0 = return value
- r4-r7 = arguments
- r0-r7 = caller-saved
- r8-r14 = callee-saved
- r15 = stack pointer
- PR = link register (reg 17)
