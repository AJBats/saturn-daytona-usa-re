# CRITICAL: Autonomous Operation Rules

**This section is active. Work continuously without user interaction.**

## Core Rules
1. **Never stop to ask questions** - make reasonable assumptions and document them
2. **Never use the AskUserQuestion tool** - the user is away; decide autonomously and document your reasoning
3. **Never run git commands** (commit, push, branch, etc.) - the user will review and commit when they return
4. **Never trigger user prompts** - if a tool use is rejected/blocked, adjust approach and retry silently. Do not re-ask.
5. **Save all work to disk frequently** - write results to files after each major step
6. **Use TodoWrite aggressively** - plan before executing, mark tasks as you go
7. **Read CLAUDE.md first** if context is unclear - it contains project state and key files
8. **If blocked, skip and move on** - document what blocked you and continue with next task

## CRLF Warning
Files written on Windows have CRLF line endings. All bash scripts run via WSL must
handle this. Always pipe through `tr -d '\r'` when reading files from the Windows
filesystem, or use `dos2unix`. This applies to test .c files, .expected files, and
the scripts themselves.

## Work Patterns
- Run verification scripts in WSL: `MSYS_NO_PATHCONV=1 wsl -d Ubuntu -- bash /path/to/script.sh`
- Compiler: `$CC1 -quiet -O2 input.c -o output.s` where CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1
- Write C source to /tmp/*.c, compile, compare output against original asm in build/aprog.s
- Use K&R-style function declarations (required by GCC 2.6.3)
- Use `<< N` not `* power_of_2` to avoid ___mulsi3 library calls

## Saving Results
- Append verification results to `docs/verification_results.md`
- Update `docs/function_catalog.md` with newly verified functions
- Update `docs/subsystem_map.md` if new subsystem patterns found
- Create/update `tools/verify_batch*.sh` scripts for reproducibility
- Update CLAUDE.md summary stats when verification counts change

## Error Recovery
- If WSL fails: retry once, then skip to a task that doesn't need compilation
- If a function doesn't match: document the differences and move on
- If decompiler output is unclear: check raw asm in build/aprog.s
- If context is getting large: write current state to docs, summarize, continue

## Quality Standards
- Every verified function needs side-by-side comparison (our asm vs original)
- Note instruction count delta and which compiler differences explain the gap
- Flag any NEW compiler differences not yet documented

## Current Session: Compiler Patch Loop

### The Loop
1. Run `tools/test_harness.sh` → get PASS/FAIL counts
2. Pick first FAIL that matches current patch target
3. Read the asm diff, identify what GCC codegen needs to change
4. Edit SH backend files in `tools/gcc26-build/config/sh/` (sh.c, sh.h, or sh.md)
5. Rebuild cc1: `cd /mnt/d/Projects/SaturnReverseTest/tools/gcc26-build && make -j$(nproc) cc1 CFLAGS="-std=gnu89 -m32 -static -fcommon -DHAVE_STRERROR"`
6. Re-run test harness
7. If regression (previously passing test now fails): REVERT patch, try different approach
8. If progress (new passes, no regressions): keep patch, save state, continue
9. Document each patch attempt and result in `docs/compiler_patches.md`

### Patch Priority
1. **dt** - `add #-1,rN / tst rN,rN` → `dt rN`. Peephole in sh.md or reorg pass.
2. **tail calls** - detect last call before return, emit `bra`/`jmp` instead of `jsr`/`rts`
3. **bf/s delayed branch** - fill branch delay slots with bf/s and bt/s
4. **bsr** - emit `bsr label` for nearby calls (±4KB) instead of `mov.l/jsr`
5. **displacement stores** - emit `mov.w Rm,@(disp,Rn)` addressing mode

### Key Build Info
- cc1 is in `tools/gcc26-build/cc1` (2.4MB, 32-bit Linux ELF, runs in WSL)
- SH backend: `tools/gcc26-build/config/sh/sh.c` + `sh.h` + `sh.md`
- aux-output.o is built from sh.c (symlinked as aux-output.c)
- Build uses `--target=sh-hms` (Hitachi SH)
- 119 `dt` instructions in original binary (aprog.s)
