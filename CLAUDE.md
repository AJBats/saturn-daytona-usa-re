# Active Workstreams

> **READ THIS FIRST after compaction.** 
> Only your user will modify this file. you will never modify this file.
> All problems we face are sovlable with enough time and effort. Nothing is intractable, but they may be challenging!

| # | Workstream | Status | Notes |
|---|-----------|--------|-------|
| 1 | **Boot Test (Functional Equiv)** | **Active** | Testing relaxed criteria - see `workstreams/boot_test_results.md` |


# Autonomous Operation Rules

0. **Never delete uncommitted files** — If there are untracked/modified files, ASK before deleting them. They may contain work-in-progress or experimental code the user wants to review. Use `git stash` or commit them instead.
**Only delete files with safe word** Sometimes the user my imply, or indirectly give you the imperssion files should be deleted. But only  actually delete files discussed after giving a file listing, and a final confirmation with the safe word **pineapple**
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

## Skills
Refer to skills directory for useful skills on this project.
decomp.md - will teach you techniques for doing the actual decompilation and matching production asm.
dashboard.md - will teach you skills for updating dashboards.

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

## Dashboard
See `dashboard/` for current metrics:
- `dashboard/asm_matching.md` - Test harness, delta breakdown
- `dashboard/boot_testing.md` - Boot test results
- `dashboard/compilation.md` - C source coverage

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

See `workstreams/compiler_patches.md` for 23 patches applied.
See `workstreams/asm_matching_workstream.md` for failure analysis.

## SH backend source files (edit these for patches)
- `tools/gcc26-build/config/sh/sh.c` - backend implementation (57KB)
- `tools/gcc26-build/config/sh/sh.h` - target definitions/flags (50KB)
- `tools/gcc26-build/config/sh/sh.md` - machine description / RTL patterns (55KB)

---

# Reference: Architecture

- Main loop at `main` (0x06003000) is a **32-state machine** dispatching through jump table
- All arithmetic is **32-bit fixed-point integer** (no FPU on SH-2)
- Three courses with parallel code paths (CS0/CS1/CS2)
- Common object struct: X/Y/Z at +0x10/+0x14/+0x18, rotation at +0x1C/+0x20/+0x24
- See `docs/subsystem_map.md` for full details
- See `docs/gcc26_internals.md` for SH-2 calling convention
- ~40 game state handlers (0x060088CC-0x06009E60) missing from Ghidra export
