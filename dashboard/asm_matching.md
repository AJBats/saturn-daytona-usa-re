# ASM Matching Dashboard

## Test Harness Results
- **PASS**: 53 / 867 tested (6.1%)
- **FAIL**: 814

## Delta Breakdown
| Category | Count | Meaning |
|----------|-------|---------|
| delta=0 | 46 | Same count, different opcodes (scheduling) |
| delta<0 | 373 | Our code shorter (better optimization) |
| delta>0 | 386 | Our code longer (register allocation) |

## Failure Root Causes
- **Instruction scheduling**: GCC orders differently - challenging
- **Register allocation**: GCC prefers callee-saved r8-r14 - challenging
- **Better optimization**: Our GCC genuinely produces shorter code - intentional

## Binary Patcher
- **test_include.txt**: 79 functions
- **Patchable**: 65 (23 L2+ plus 42 DIFF that fit in slot)

---
*Last updated: 2026-02-05*
