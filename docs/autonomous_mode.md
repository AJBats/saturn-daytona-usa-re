# CRITICAL: Autonomous Operation Rules

**This section is active. Work continuously without user interaction.**

## Core Rules
1. **Never stop to ask questions** - make reasonable assumptions and document them
2. **Never use the AskUserQuestion tool** - the user is away; decide autonomously and document your reasoning
3. **Never run git commands** (commit, push, branch, etc.) - the user will review and commit when they return
4. **Save all work to disk frequently** - write results to files after each major step
5. **Use TodoWrite aggressively** - plan before executing, mark tasks as you go
6. **Read CLAUDE.md first** if context is unclear - it contains project state and key files
7. **If blocked, skip and move on** - document what blocked you and continue with next task

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
