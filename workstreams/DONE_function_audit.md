# Function Audit

> **Status**: COMPLETE — superseded by Sawyer L2 workstream
> **Created**: 2026-02-16
> **Completed**: 2026-02-17
> **Depends on**: reimplementation.md (L1 pass), road_to_boot.md (Class 4 discovery)

## Genesis

During Road to Boot Phase 4, we traced a crash to **Class 4: Missing function
definitions** — 75 functions existed in the original binary but had no source
in the reimpl. We imported 69 from Ghidra decomp and stubbed 6 orphans.

But a deeper size analysis revealed the problem is much larger than 75 functions:

```
=== Reimpl vs Original APROG.BIN Size Analysis (2026-02-16) ===

Original binary:     394,896 bytes
Reimpl compiled:     227,926 bytes  (sum of all ELF section content)
Reimpl binary out:   349,120 bytes  (includes zero-padded gaps)
Net deficit:          45,776 bytes  (code missing from the binary)
```

### Function Fill Distribution

| Category | Functions | Bytes Wasted | Description |
|----------|-----------|-------------|-------------|
| **good (90-110%)** | 771 | 1,016 | Correct size, healthy |
| **medium (50-90%)** | 173 | 16,166 | Compiles smaller than original |
| **small (25-50%)** | 47 | 6,938 | Significantly undersized |
| **tiny (<25%)** | 90 | 41,522 | Mostly stubs disguised as code |
| **stubs (<=4 bytes)** | 43 | 2,532 | Pure rts/nop stubs |
| **overflow (>110%)** | 107 | -(bloat) | Compiled LARGER than original |
| **data region** | 1 | 116,808 | FUN_06046E48 — not code, tables/strings |
| **Total** | **1,234** | | |

### By Source Category

| Category | Count | Stubs | Real | Slot Total | Compiled | Deficit |
|----------|-------|-------|------|-----------|----------|---------|
| **Existing L1/L2** | 1,158 | 252 | 906 | 215,328 | 201,582 | 13,746 (6%) |
| **Imported (69)** | 69 | 18 | 51 | 59,958 | 26,320 | 33,638 (56%) |
| **Orphans (6)** | 6 | 6 | 0 | 2,550 | 24 | 2,526 (99%) |

### Key Findings

1. **771 functions (63%) are healthy** — within 10% of original size. The L1 approach
   works for the majority of functions.

2. **252 existing ASM stubs** — functions Ghidra couldn't decompile, placed in
   `asm_*.c` as rts/nop stubs. These are the single biggest class of missing code.

3. **18 of the 69 imported functions became stubs** — the safe import script's
   artifact detector flagged them as too broken to compile. They need hand-rewriting.

4. **173 functions at 50-90% fill** — these compile but produce significantly less
   code than the original. Likely due to Ghidra simplifying complex control flow.

5. **109 functions overflow their slots** (143 overlap warnings) — modern GCC 13.3.0
   produces 1-10% larger code due to different constant pool layout, less aggressive
   delay slot scheduling, and inability to share registers across long call sequences.
   These need overflow trampolines or hand-optimization.

## Goal

100% validated function coverage. Every function in the reimpl must be accounted for,
categorized, and auditable against the original `aprog.s` at any time.

**"Buttoned up"** means:
- Every function has a known status (real code, known-stub, or overflow)
- An audit tool can validate the entire reimpl in seconds
- No surprises — we know exactly what boots and what doesn't
- Boot attempts are earned, not guessed at

## Audit Tooling

### Primary Tool: `tools/audit_functions.py`

Single-command validator that compares reimpl ELF against original `aprog.s`:

```bash
python tools/audit_functions.py           # Full report
python tools/audit_functions.py --summary # Quick summary only
python tools/audit_functions.py --stubs   # List all stubs
python tools/audit_functions.py --overflow # List all overflows
python tools/audit_functions.py --diff    # What changed since last audit
```

Outputs:
- Per-function: name, original slot size, compiled size, fill ratio, status
- Summary stats: total coverage, deficit, overflow count
- Machine-readable JSON for dashboards

### Dashboard: `dashboard/function_audit.md`

Auto-generated from audit tool. Shows:
- Function coverage percentage
- Stub count trending down
- Overflow count trending down
- Top 20 biggest gaps

## Work Categories

### Category A: Existing ASM Stubs (252 functions, ~10KB missing)

Functions in `reimpl/src/asm_*.c` that are rts/nop stubs. Ghidra couldn't decompile
them — likely hand-written SH-2 assembly (interrupt handlers, tight loops, state
machines, lookup tables with embedded data).

**Strategy**: Import original bytes from `aprog.s` as inline assembly. These functions
were NEVER C to begin with — they should stay as assembly.

### Category B: Failed Imports (18 functions, ~11KB missing)

The 69 imported functions where 18 had "severe Ghidra artifacts" and fell back to
stubs. The C source exists in `src/FUN_*.c` but needs hand-fixing.

```
FUN_06003A3C (3,112 bytes missing)
FUN_060370E4 (1,392 bytes missing)
FUN_060256CC (1,308 bytes missing)
FUN_06025BF4 (1,296 bytes missing)
FUN_06004670 (1,052 bytes missing)
FUN_0601B7F4 (592 bytes missing)
FUN_060400D6 (278 bytes missing)
FUN_06005294 (268 bytes missing)
FUN_060409E6 (262 bytes missing)
FUN_0604077C (244 bytes missing)
FUN_06025148 (208 bytes missing)
FUN_06025070 (204 bytes missing)
FUN_06018278 (156 bytes missing)
FUN_0603A01C (136 bytes missing)
FUN_0603FC60 (120 bytes missing)
FUN_06034C68 (84 bytes missing)
FUN_060423CC (64 bytes missing)
FUN_0601B6DC (8 bytes missing)
```

**Strategy**: Hand-rewrite from `src/FUN_*.c` + `build/aprog.s` assembly reference.
Fix Ghidra artifacts, make it compile. These have C source — it's mechanical work.

### Category C: Undersized Functions (173 at 50-90%, ~16KB missing)

Functions that compile but produce less code than the original. Usually because:
- Ghidra simplified complex switch/case into if/else chains
- Ghidra collapsed loop unrolling
- Ghidra lost embedded data tables (treated as dead code)

**Strategy**: Compare against `aprog.s` to find what's missing. Usually it's an
embedded constant table or a code path Ghidra didn't see.

### Category D: Overflow Functions (109 functions, 143 overlap warnings)

Functions that compile LARGER than their original slot. Causes:
- Modern GCC constant pool layout (separate entries vs shared pools)
- Less aggressive delay slot scheduling
- No register caching of function pointers across call sequences

**Strategy**: Overflow trampoline system (Class 3 fix from road_to_boot).
Move bloated functions to free space, put `jmp` at original address.
Long-term: hand-optimize hot functions to fit.

### Category E: True Orphans (6 functions, ~2.5KB missing)

Functions with no source anywhere — not in `src/*.c`, not in Ghidra export.

```
FUN_06006F3C (812 bytes)
FUN_06007268 (126 bytes)
FUN_06008EBC (84 bytes)
FUN_06009098 (504 bytes)
FUN_06009290 (64 bytes)
FUN_060092D0 (568 bytes)
```

**Strategy**: Import original bytes from `aprog.s` as inline assembly, same as
Category A. These were likely hand-written ASM by Sega AM2.

### Category F: Data Region (1 "function", ~117KB slot)

FUN_06046E48 is not a function — it's the 116KB data tail of the binary
(parameter tables, lookup tables, strings). The disassembler mislabeled it
as a function. Handled by `tools/patch_data_holes.py` post-build.
Excluded from audit scoring.

## Priority

Boot-blocking issues first:
1. **Category D** (overflows) — these corrupt adjacent functions, actively breaking boot
2. **Category A+E** (ASM stubs) — import original bytes, guaranteed correct
3. **Category B** (failed imports) — hand-fix the 18 broken Ghidra outputs
4. **Category C** (undersized) — lower priority, functions work but may be incomplete

## Relationship to Other Workstreams

- **Road to Boot**: This workstream feeds into Road to Boot. We earn boot attempts
  by fixing function coverage issues found here.
- **Reimplementation**: The L2 pass should prioritize functions flagged by the audit
  tool as problematic (undersized, overflow).

## Final State (2026-02-17)

### Coverage Breakdown

| Category | Count | Notes |
|----------|-------|-------|
| ASM-imported (original bytes) | 536 | Bit-perfect `.byte` arrays from `build/aprog.s` |
| C reimpl disabled (`#if 0`) | 624 | Redirected to ASM imports via PROVIDE aliases |
| Active C reimpl | ~98 | Ghidra L1 lifts + hand-written L2+ |
| Empty (zeros) | 1 | FUN_06040954 — needs investigation |
| Data stub | 1 | FUN_06046E48 — not real code, it's the data region |
| **Total** | **1,258** | (1,234 FUN_ labels + some named functions) |

### Binary Match Quality (866 functions tested by binary_diff)

| Level | Count | % |
|-------|-------|---|
| L3 Byte-perfect | 9 | 1.0% |
| L2 Structural | 20 | 2.3% |
| L1 Mnemonic | 24 | 2.8% |
| DIFF (wrong opcodes) | 813 | 93.9% |
| (no link) — size mismatch | 34 | can't compare at address |

### Binary Size

- Code: 283,360 bytes (within 394,896B budget)
- Overflow: 4,880 bytes (down from 17,960B)

### Conclusion

The function audit achieved its goal: every function is accounted for and categorized.
However, the audit revealed that the reimpl is **92% original binary bytes reimported**
and only **~8% actual C reimplementation**. The fixed-address layout approach creates
an inherent slot-size constraint that forces ASM imports whenever C output doesn't
match the original function size.

**Superseded by**: sawyer_l2.md — a fundamentally different approach that produces
relocatable assembly source (pre-link), eliminating the fixed-slot constraint entirely.
