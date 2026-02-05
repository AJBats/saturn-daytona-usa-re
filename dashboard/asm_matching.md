# ASM Matching Dashboard

## Summary

| Metric | Value |
|--------|-------|
| Total tested | 867 |
| PASS | 53 (6.1%) |
| FAIL | 814 |

## Delta Breakdown

| Category | Count | Meaning | Tractability |
|----------|-------|---------|--------------|
| delta=0 | 46 | Same count, different opcodes | Scheduling - challenging |
| delta<0 | 373 | Our code shorter | Better optimization - intentional |
| delta>0 | 386 | Our code longer | Register allocation - challenging |

## PASS Functions (53)

| Function | Delta | Notes |
|----------|-------|-------|
| FUN_06005174 | 0 | Fixed displacement store |
| FUN_0600C4F8 | -1 | register asm for func/base |
| FUN_0600DFD0 | 0 | |
| FUN_0600E410 | 0 | |
| FUN_06012344 | +5 | register asm for func ptr |
| FUN_0601250C | +1 | Fixed shift precedence |
| FUN_06012CF4 | 0 | |
| FUN_06018278 | +4 | Fixed precedence, simplified |
| FUN_060192E8 | -2 | Simplified delay loop |
| FUN_06020B20 | +3 | Hoisted zero outside loop |
| FUN_060067C8 | 0 | Fixed SUB42, byte loads |
| <!-- TODO: Add remaining 42 PASS functions --> | | |

## Binary Patcher Status

| Metric | Value |
|--------|-------|
| test_include.txt | 79 functions |
| Patchable | 65 |
| L3 (byte-perfect) | 8 |
| L2 (structural) | 15 |
| DIFF (fits in slot) | 42 |

## Failure Root Causes

| Cause | Description | Fix Path |
|-------|-------------|----------|
| Instruction scheduling | GCC orders prologue/insns differently | Compiler change required |
| Register allocation | GCC prefers callee-saved r8-r14 | Compiler change required |
| Better optimization | Our GCC produces shorter code | Intentional - no fix |
| Ghidra boundaries | Fall-through functions merged | Manual split required |

---
*Last updated: 2026-02-05*
