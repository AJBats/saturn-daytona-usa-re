# Session Progress — Compiler Accuracy Week

## Starting Point
- 39 PASS / 828 FAIL / 867 total tests
- 822/886 C source files compilable (92.8%)
- 8 compiler patches applied to GCC 2.6.3 SH-2 backend

## Changes This Session

### 1. ICE Crash Fix (extendhisi2 predicate)
- **Root cause**: `extendhisi2` insn pattern in sh.md used `arith_operand` predicate (rejects memory), but constraints include `m` (memory)
- **Fix**: Changed predicate from `arith_operand` to `general_movsrc_operand` (matching `extendqisi2`)
- **Impact**: 41 → 5 ICE crashes, 822 → 860 compilable files (97.1%)
- **Remaining 5 ICEs**: 2 DImode indexed load, 2 HImode out-of-range displacement, 1 QImode non-r0 displacement

### 2. Constant Pool Resolver Tool (resolve_pool_constants.py)
- Resolves `(int)PTR_DAT_ADDR` and `(int)DAT_ADDR` references to literal constants
- Reads 16-bit constant pool values from aprog.s disassembly
- Replaces references where the address falls within the function's constant pool range
- **Impact**: 938 replacements across 225 files
- **New PASS**: FUN_060148FC, FUN_0601492C, FUN_06014994, FUN_0601938C (4 functions)

### 3. Scheduling Experiment
- **Hypothesis**: Post-reload scheduling (`-fno-schedule-insns2`) causes instruction reordering
- **Result**: ZERO effect on any function — hypothesis disproven
- **Conclusion**: Instruction ordering differences come from RTL expansion/register allocation, not scheduling

## Current State (after all session work)
- **43 PASS / 824 FAIL / 867 total** (was 39/828 at session start)
- **867/886 compilable** (was 822)
- Pass rate: 4.96%

### Delta Distribution (after mul-to-shift + ptr-shift fixes)
| Category | Count | Notes |
|----------|-------|-------|
| PASS | 43 | Opcode-identical matches |
| delta=0 FAIL | 52 | Same length, different opcodes (was 50) |
| delta=+1 | 27 | 1 extra instruction (was 39, mul-to-shift improved 12) |
| delta=-1 | 42 | 1 fewer instruction (our code shorter) |
| delta<=-2 | ~308 | 2+ fewer instructions |
| delta>=+2 | ~388 | 2+ extra instructions |

### Tools Applied
1. **Constant pool resolver** (resolve_pool_constants.py): 938 replacements in 225 files → 4 new PASS
2. **Multiply-to-shift** (fix_mul_to_shift.py): 2445 replacements in 288 files → improved delta+1 from 39→27
3. **Pointer shift fix** (fix_ptr_shift.py): 402 casts in 65 files → fixed compiler errors from mul-to-shift

### Experiments & Findings
1. **Scheduling experiment** (`-fno-schedule-insns2`): ZERO effect — hypothesis disproven. Instruction ordering differences come from RTL expansion/register allocation, not post-reload scheduling.
2. **Intermediate return variable removal**: ZERO effect — GCC 2.6.3 already optimizes `uVar = func(); return uVar;` identically to `return func();`.
3. **C source restructuring for FUN_06038F34**: Register allocation differences (1 vs 2 const registers) — not fixable at C level.

### Functions Closest to PASS (not fixable at C level)
- **14 delta=0 with 2 diffs**: ALL instruction scheduling/reordering
  - FUN_0601164A, FUN_0601209E, FUN_060192CA, FUN_06026E0C, FUN_060270D0, FUN_06027344, FUN_06027348, FUN_060285E0, FUN_06028600, FUN_06035C80, FUN_0603C05C, FUN_0603F3DA, FUN_0603F4CC, FUN_06040954
- **5 delta=0 with 4 diffs**: Scheduling + constant pool encoding + optimization path differences
  - FUN_06005174, FUN_06018EC8, FUN_06033330, FUN_0603C0A0, FUN_0603F8B8
- **4 delta=-1 with 1 diff**: Our code 1 shorter (BSR/tail call/delay slot)
  - FUN_06018E70, FUN_06019324, FUN_0603B734, FUN_06042BEE
- **4 delta=+1 with 11 diffs**: Indirect tail call (jmp vs jsr+rts)
  - FUN_0603F8EE, FUN_0603F900, FUN_0603F90E, FUN_0603F91C

### Remaining 426 files with unresolved DAT/PTR_DAT references
Most are legitimate global variable references (RAM addresses 0x0606xxxx), not constant pool values. The constant pool resolver correctly skips these.

### Key Insight: Diminishing Returns
The remaining failures are dominated by:
1. **Instruction scheduling/ordering** — Compiler-internal, not C-level fixable
2. **Register allocation differences** — 1 vs 2 registers for constants, register numbering
3. **Constant pool encoding** — `mov.w` (16-bit) vs `mov.l` (32-bit) for same value
4. **Prolog ordering** — `sts.l pr,@-r15` before vs after argument setup
These are all deep GCC backend issues that would require compiler patches to address.

## Files Created/Modified This Session
### Compiler Changes
- `tools/gcc26-build/config/sh/sh.md` — extendhisi2 predicate fix (line 901)

### Automated Fix Tools
- `tools/resolve_pool_constants.py` — constant pool reference resolver
- `tools/fix_mul_to_shift.py` — multiply-by-power-of-2 to shift converter
- `tools/fix_ptr_shift.py` — fix pointer << N errors with (int) casts

### Analysis Tools
- `tools/find_easy_wins.sh` — find functions closest to PASS
- `tools/find_easy_wins2.sh` — enhanced version with more categories
- `tools/pattern_analysis.sh` — opcode diff pattern analysis
- `tools/delta_summary.sh` — delta distribution summary
- `tools/find_ice_files.sh` — find ICE-crashing files
- `tools/analyze_remaining_ice.sh` — analyze remaining ICE patterns
- `tools/categorize_dm1.sh` — categorize delta=-1 root causes
- `tools/analyze_2diff.sh` — analyze delta=0 2-diff functions
- `tools/analyze_4diff.sh` — analyze delta=0 4-diff functions
- `tools/analyze_dp1.sh` — analyze all delta=+1 functions
- `tools/analyze_dm1_1diff.sh` — analyze delta=-1 1-diff functions
- `tools/count_real_errors.sh` — count truly-failing compilations
- `tools/find_compile_errors.sh` — find all compile errors with messages
- `tools/test_38f34.sh` — test C restructuring for FUN_06038F34
- `tools/test_retvar.sh` — test intermediate return var removal

### Source Files Modified
- `src/*.c` — 225+ files by constant pool resolver
- `src/*.c` — 288 files by mul-to-shift converter
- `src/*.c` — 65 files by ptr-shift fix
