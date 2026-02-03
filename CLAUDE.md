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
- `tools/gcc-2.6.3/` - Patched GCC source (3 Saturn-specific patches in config/sh/sh.c and sh.h)
- `build/aprog_syms.txt` - 1234 function symbols in linker script format
- `tools/verify_batch*.sh` - Verification scripts comparing GCC output to original binary

### Compiler Invocation
```bash
MSYS_NO_PATHCONV=1 wsl -d Ubuntu -- bash /path/to/script.sh
```
Inside scripts: `$CC1 -quiet -O2 input.c -o output.s` where CC1=/mnt/d/Projects/SaturnReverseTest/tools/gcc26-build/cc1

### Known Compiler Differences (from verification of 25 functions)
1. **Register allocation**: Our compiler prefers r1,r2 for caller-saved temps; original uses r3,r4
2. **No `dt` instruction**: GCC emits `add #-1 / tst` instead of SH-2's single `dt` insn
3. **No `bf/s` delayed branch**: GCC never fills branch delay slots with bf/s or bt/s
4. **No tail call optimization**: GCC always uses jsr/rts, never `bra`/`jmp` for tail calls
5. **No displacement store**: GCC doesn't emit `mov.w Rm,@(disp,Rn)`, computes addresses manually
6. **Extern vs constant pool**: Original embeds values directly in constant pool. C externs cost +1 insn
7. **rts/jsr delay slot**: GCC DOES fill rts and jsr delay slots in many cases
8. **Range check optimization**: GCC transforms `a<=x<=b` to `(unsigned)(x-a)<=(b-a)` with cmp/hi
9. **Multiply avoidance**: Must use `<< N` not `* power_of_2` to avoid ___mulsi3 library call
10. **No `bsr` direct calls**: GCC uses `jsr @rN` (2 insn) instead of `bsr label` (1 insn)
11. **R0-specific insns**: GCC uses `and #imm,r0` (1 insn) where original uses 4-insn sequence
12. **Callee-save vs stack params**: GCC preserves params across calls in callee-saved regs (more overhead); original saves on stack

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
