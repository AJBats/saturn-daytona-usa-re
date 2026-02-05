# Active Workstreams

> **READ THIS FIRST after compaction.** This is your current assignment.
> Everything below this section is reference material — do NOT treat it as a call to action.

| # | Workstream | Status | Notes |
|---|-----------|--------|-------|
| 1 | **ASM Matching to Boot** | **decision point** | See `docs/asm_matching_workstream.md` |

## Current State

**Reality**: Only 23 functions actually get patched (8 L3 + 15 L2). Most FAIL→PASS conversions are intractable.

**Findings (session 2026-02-05)**:
- Fixed build_disc.sh to use `--include-funcs`
- Patcher only patches L2+ functions (DIFF ignored even if in test_include.txt!)
- Most failures: scheduling, register allocation, better optimization — intractable
- Baseline boots with 23 patched functions

**Options**:
1. **Patcher enhancement** — add unsafe mode for DIFF patching
2. **More compiler work** — peephole passes for specific patterns
3. **Pivot** — accept 23 patched as milestone, focus on game code extraction

**Key docs**:
- `docs/asm_matching_workstream.md` — full findings + conclusion
- `decomp.md` — C fix patterns for assembly matching

---

# Autonomous Operation Rules

1. **NEVER STOP WORKING** — work continuously until the user returns. No "session summaries".
   - When a batch finishes, IMMEDIATELY start the next batch
   - Never write "Session Summary" or "Session Complete" — these are stop signals
   - Always keep at least one todo as `in_progress`
   - Milestones are checkpoints, not endpoints
2. **Commit at logical stopping points** — don't mix workstreams in one commit. Finish, commit, move on.
3. **No destructive git** — no force-push, no reset --hard, no branch -D. Regular commits and branches are fine.
4. **Never stop to ask questions** — make reasonable assumptions and document them
5. **Save all work to disk frequently** — write results to files after each major step
6. **Use TodoWrite aggressively** — plan before executing, mark tasks as you go
7. **If blocked, skip and move on** — document what blocked you and continue with next task
8. **Update this file** — when starting/finishing a workstream, update the table above


## WSL Gotchas
- **CRLF**: Files written on Windows have CRLF. Pipe through `tr -d '\r'` when reading
  Windows files in WSL. The test harness handles this for .c and .expected files.
- **grep tabs**: `grep '^\t...'` does NOT match tabs in basic regex. Use `grep -P '^\t...'`
  (Perl regex) to match literal tab characters.
- **Running scripts**: Strip CRLF from scripts first:
  `tr -d '\r' < script.sh > /tmp/clean.sh && bash /tmp/clean.sh`
  OR run directly: `bash /mnt/d/.../script.sh` (bash handles CRLF in scripts)
- **cc1 vs cpp**: `cc1` is the compiler proper — it does NOT handle C comments.
  C files must not contain `/* ... */` or `//` comments. Comments are stripped by `cpp`
  (the preprocessor) which is a separate binary we don't have. Keep generated .c files
  comment-free.

---

# Daytona USA Saturn - Progressive Decomp Project

## Project Goal
Reverse engineer Sega Saturn Daytona USA (1995) to extract gameplay code (physics,
steering, collision, AI) for transplanting into Daytona USA CCE (1996).

## Scoreboard
- **Test harness**: 48 PASS / 819 FAIL / 867 tested (5.5% match) - ceiling reached
- **C sources**: 886 / ~880 Ghidra decomps (100% coverage)
- **Compilable**: 886/886 functions compile (100%!)
- **Failure breakdown**: 46 delta=0 (scheduling), 373 delta<0 (better opt), 386 delta>0 (reg alloc)
- **Binary patcher**: 79 functions in test_include.txt (48 PASS + 31 verified BOOT)
- **Compiler patches**: 23 applied, all low-hanging peepholes done
- **Boot testing**: 59 tested, 35 BOOT, 18 CRASH, 6 CORRUPT
- **Conclusion**: All failure patterns documented as intractable without compiler changes

## Directory Layout
- `src/*.c` - Reconstructed C source files (886 functions, 100% compilable)
- `tests/*.expected` - Expected opcode mnemonics from original binary (one per line)
- `tests/*.flags` - Per-function compiler flag overrides (optional)
- `tools/` - Build scripts, test harness, GCC source, toolchain
- `build/` - Binary artifacts (aprog.s, aprog.bin, disc images)
- `docs/` - Project documentation

## Key Files
- `build/aprog.s` - Full binary disassembly (206K lines, 1234 function labels, SH-2 asm)
- `ghidra_project/decomp_all.txt` - Ghidra decompiler output for 880 functions
- `tools/gcc26-build/cc1` - Patched GCC 2.6.3 compiler for SH-2 (runs in WSL)
- `tools/gcc-2.6.3/` - Patched GCC source (23 patches in config/sh/sh.c, sh.h, sh.md, toplev.c)
- `build/aprog_syms.txt` - 1234 function symbols in linker script format
- `tools/build_disc.sh` - One-command build script for patched CUE+BIN disc
- `tools/patch_binary.py` - Full compile->assemble->link->patch pipeline (supports --level, --max-addr, --min-addr)
- `tools/test_boot.ps1` - Automated Mednafen boot test with F9 screenshot (~20s per trial)
- `tools/compare_screenshot.py` - Screenshot comparison (phash, histogram, pixels, RMSE)
- `docs/boot_test_automation.md` - Full docs for boot test pipeline (READ THIS FOR CONTEXT)
- `tools/binary_diff.py` - Per-function binary comparison (L1/L2/L3 matching)
- `tools/test_harness.sh` - Opcode-level test harness (compares mnemonics)

## Build Commands
```bash
# Build patched disc (CUE+BIN):
wsl -d Ubuntu -- bash tools/build_disc.sh

# Launch patched disc in Mednafen:
run_patched.bat

# Automated boot test (screenshot at title screen):
powershell -ExecutionPolicy Bypass -File tools\test_boot.ps1 -Cue patched

# Run test harness:
wsl -d Ubuntu -- bash tools/test_harness.sh

# Rebuild compiler (after sh.c/sh.h/sh.md changes):
wsl -d Ubuntu -- bash tools/final-rebuild.sh
```

Inside scripts: `$CC1 -quiet -O2 -m2 -mbsr input.c -o output.s`
- `-m2` = SH-2 features (dt, bf.s/bt.s)
- `-mbsr` = PC-relative calls, tail calls
- Per-function flags in `tests/*.flags` override defaults

---

# Reference: Compiler Work

## Patches Applied (23 total, see docs/compiler_patches.md)
1. **dt peephole** (sh.md): `add #-1,rN / tst rN,rN` -> `dt rN`
2. **BSR fix** (sh.c): Fixed `bsr_operand()` to accept any SYMBOL_REF
3. **Tail call** (sh.md + sh.c): Last call before return -> `bra _func / lds.l @r15+,pr`
4. **Pure wrapper** (sh.md + sh.c): Single-call wrapper -> simple `bra`
5. **Disp store peephole** (sh.md + sh.c): `mov+add+mov.w` -> `mov.w r0,@(D,rN)`
6. **Sign ext elimination** (sh.md): `mov.w+exts.w` -> `mov.w` direct
7. **Return block dedup** (sh.c + toplev.c): Undoes delay slot fills creating dup returns
8. **Delay slot sign ext** (sh.c): Replaces no-op exts.w in rts delay slot
9. **EXTU.W disp store** (sh.c): `extu.w` for displacement store r0 copy
10. **Register compaction** (sh.c): Liveness-based register merge for leaf functions
11. **swap.w** (sh.md + sh.c): `mov+shlr16+exts.w` -> `swap.w+exts.w`
12. **add-to-shll** (sh.c): `add rN,rN` -> `shll rN` when T dead
13. **Indexed addressing** (sh.c): `add+mov.l` -> `mov.l @(rA,rB),rC`
14. **-mnofill** (sh.h + sh.c): Unfill conditional branch delay slots
15. **-mnosignext** (sh.h + sh.md + sh.c): Preserve sign extensions after loads
16. **Multiply cost** (sh.c): Reduced shift-add cost to prefer hw multiply
17. **Disp load peephole** (sh.md + sh.c): `mov+add+mov.w` -> `mov.w @(D,rN),r0`
18. **-mnofill placement fix** (sh.c): Delay slot insn moved AFTER branch
19. **dt combining** (sh.c): Pre-dbr pass for `add+tst` -> dt
20. **Redundant exts.w elimination** (sh.c): Post-dbr removes exts.w after mov.w HI load
21. **lds.l reordering** (sh.c): Pre-dbr moves lds.l earlier for rts delay slot filling
22. **-mno-bsr-fill / -mno-rts-fill** (sh.h + sh.c): Per-function delay slot unfill
23. **QImode disp store** (sh.md + sh.c): `mov+add+mov.b` -> `mov.b r0,@(D,rN)` byte stores

## SH backend source files (edit these for patches)
- `tools/gcc26-build/config/sh/sh.c` - backend implementation (57KB)
- `tools/gcc26-build/config/sh/sh.h` - target definitions/flags (50KB)
- `tools/gcc26-build/config/sh/sh.md` - machine description / RTL patterns (55KB)

## Remaining Known Compiler Differences
1. **Instruction scheduling**: GCC orders insns differently — intractable
2. **Register allocation**: Different register preferences — intractable
3. **Multi-branch tail calls**: Only single-path optimized
4. **Delay slot fill**: GCC fills slots original leaves as nop (-mnofill helps partially)
5. **Extern vs constant pool**: Ghidra externs -> use literal constants in C
6. **Range check optimization**: GCC transforms `a<=x<=b` to cmp/hi
7. **Multiply**: Must use `<< N` not `* power_of_2`; GCC uses mul.l where original uses mulu.w
8. **Zero extension**: GCC's RTL combiner removes extu.w when provably unnecessary
9. **Unfilled rts delay slots**: 14 functions remaining, all intractable
10. **Callee-save vs stack spill**: GCC uses callee-saved regs where original spills to stack

## Investigation Results (closed)
1. Post-reload scheduling — no effect
2. Delay slot filling (reorg.c) — too risky
3. Register allocation order — identical to original
4. Constant representation (add vs sub) — same count
5. Multiply decomposition — shift rewrites applied, remaining gap intractable

## Failure Patterns (reference)
- **delta=0**: Same count, different opcodes — scheduling/register allocation (intractable)
- **delta>0**: Our code longer — usually callee-saved register overhead (intractable)
- **delta<0**: Our code shorter — GCC optimizes better than original (intractable)
- Ghidra decompilations are NOT sacred — correcting C to match original intent is valid

---

# Reference: Architecture

- Main loop at `main` (0x06003000) is a **32-state machine** dispatching through jump table
- All arithmetic is **32-bit fixed-point integer** (no FPU on SH-2)
- Three courses with parallel code paths (CS0/CS1/CS2)
- Common object struct: X/Y/Z at +0x10/+0x14/+0x18, rotation at +0x1C/+0x20/+0x24
- See `docs/subsystem_map.md` for full details
- ~40 game state handlers (0x060088CC-0x06009E60) missing from Ghidra export

## SH-2 Calling Convention
- r0 = return value
- r4-r7 = arguments
- r0-r7 = caller-saved
- r8-r14 = callee-saved
- r15 = stack pointer
- PR = link register (reg 17)
