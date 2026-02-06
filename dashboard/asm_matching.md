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
| delta=0 | 44 | Same count, different opcodes | Scheduling - challenging |
| delta<0 | 401 | Our code shorter | Better optimization - intentional |
| delta>0 | 355 | Our code longer | Register allocation - challenging |

## PASS Functions (53)

| Function | Insns | Notes |
|----------|-------|-------|
| FUN_060058FA | 9 | |
| FUN_0600D266 | 2 | |
| FUN_0600DE40 | 10 | |
| FUN_0600DE54 | 14 | |
| FUN_0600F870 | 20 | |
| FUN_0601143E | 9 | |
| FUN_06011450 | 9 | |
| FUN_0601164A | 7 | |
| FUN_060122F4 | 25 | |
| FUN_06012E00 | 4 | |
| FUN_06012E62 | 4 | |
| FUN_06012E6A | 9 | |
| FUN_06012E7C | 4 | |
| FUN_06012E84 | 4 | |
| FUN_06012EBC | 4 | |
| FUN_06012EC4 | 4 | |
| FUN_06012EDC | 4 | |
| FUN_06012F00 | 4 | |
| FUN_06012F10 | 4 | |
| FUN_06012F20 | 4 | |
| FUN_06012F50 | 4 | |
| FUN_06012F58 | 4 | |
| FUN_06012F60 | 4 | |
| FUN_060148FC | 24 | |
| FUN_0601492C | 24 | |
| FUN_06014994 | 24 | |
| FUN_0601938C | 28 | |
| FUN_0601E0DE | 2 | |
| FUN_0601F8BC | 2 | |
| FUN_06026DF8 | 5 | |
| FUN_06026E0C | 17 | |
| FUN_060270D0 | 17 | |
| FUN_06027344 | 9 | |
| FUN_06027348 | 7 | |
| FUN_0602754C | 3 | |
| FUN_0602853E | 12 | |
| FUN_06028560 | 9 | |
| FUN_060322E8 | 10 | |
| FUN_06033504 | 10 | |
| FUN_060349B6 | 7 | |
| FUN_06035C48 | 3 | |
| FUN_06035C4E | 3 | |
| FUN_06035C6E | 3 | |
| FUN_06035C80 | 9 | |
| FUN_0603850C | 10 | |
| FUN_0603F4B0 | 9 | |
| FUN_0603F4CC | 10 | |
| FUN_0603F92C | 8 | |
| FUN_0603F9F2 | 2 | |
| FUN_0603F9F6 | 2 | |
| FUN_060401E4 | 2 | |
| FUN_060409DE | 4 | |
| FUN_06041884 | 4 | |

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
