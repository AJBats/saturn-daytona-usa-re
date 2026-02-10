# Boot Test Results Workstream

> **Status**: COMPLETE — Superseded by reimplementation workstream

## New Approach: Functional Equivalence Testing (2026-02-06)

### The Insight

Our hybrid pipeline embeds original bytes as inline asm, solving the pool constant problem.
This means we can now test **functional equivalence** rather than **byte-perfect matching**.

A function that produces different assembly but does the same thing should work fine, as long as:
1. **Functional equivalence** - Same inputs produce same outputs
2. **ABI compliance** - Correct calling convention at function boundaries
3. **No size overflow** - Function fits in allocated space (or we handle linkage)

The opcode-matching test harness (53 PASS) was for decompilation verification.
For a **working game**, we only need functional correctness.

### Test Criteria (Relaxed)

| Criterion | Strict (old) | Relaxed (new) |
|-----------|--------------|---------------|
| Opcode match | 100% required | Not required |
| Instruction count | Must match | Can differ |
| Register choices | Must match | Can differ |
| Instruction order | Must match | Can differ |
| Functional result | Must match | **Must match** |
| Boot test | N/A | **Must pass** |

### Pipeline

```
gen_hybrid_funcs.py --use-c-funcs <list>
    ↓
For each function:
  - If in <list>: copy real C from src/
  - Otherwise: inline asm from original disc
    ↓
build_compiler_pipeline.sh
    ↓
build_disc_from_bin.sh
    ↓
test_boot.ps1 → compare_screenshot.py
    ↓
BOOT / CRASH / CORRUPT
```

### Function Categories for Testing

| Category | Count | Description | Test Priority |
|----------|-------|-------------|---------------|
| PASS (opcode match) | 53 | Already verified identical | Baseline |
| delta=0 | 44 | Same size, different order | HIGH |
| delta<0 (shorter) | ~400 | Our code is better | MEDIUM |
| delta>0 (longer) | ~400 | May overflow slot | LOW |
| Compile errors | 0 | All 886 compile | N/A |

### Test Strategy

1. **Baseline**: 53 PASS functions (already verified BOOT)
2. **Phase 1**: Add all delta=0 functions (same size, different instructions)
3. **Phase 2**: Add delta=-1 to -5 functions (slightly shorter)
4. **Phase 3**: Add remaining delta<0 functions
5. **Phase 4**: Carefully add delta>0 functions (check size fits)

---

## Session: 2026-02-06 - Functional Equivalence Tests

### Baseline (53 PASS functions)
- **Build**: Hybrid pipeline with 53 real C + 1546 inline asm
- **Binary**: IDENTICAL to original
- **Boot**: PASS (screenshot match)

### Phase 1: Delta=0 Functions (TODO)

Adding functions with same instruction count but different opcodes:

| # | Function | Insns | Delta | Diff Count | Result | Notes |
|---|----------|-------|-------|------------|--------|-------|
| | | | | | | |

### Phase 2: Small Delta Negative (TODO)

| # | Function | Insns | Delta | Result | Notes |
|---|----------|-------|-------|--------|-------|
| | | | | | |

---

## Historical Results (Patcher Approach - 2026-02-05)

*These used the old binary patching approach, not the new hybrid pipeline.*

### Verified BOOT (35 functions)

| # | Function | Insns | Type | Match% | Result | Notes |
|---|----------|-------|------|--------|--------|-------|
| 1 | FUN_0603316C | 2 | LEAF | 0% | BOOT | |
| 2 | FUN_060336C8 | 2 | LEAF | 0% | BOOT | |
| 3 | FUN_060336F2 | 2 | LEAF | 0% | BOOT | |
| 4 | FUN_06035C6E | 3 | LEAF | 0% | BOOT | |
| 5 | FUN_0602ECCC | 4 | LEAF | 0% | BOOT | |
| 6 | FUN_0603F8EE | 4 | LEAF | 0% | BOOT | |
| 7 | FUN_0603F900 | 4 | LEAF | 0% | BOOT | |
| 8 | FUN_0603F90E | 4 | LEAF | 0% | BOOT | |
| 9 | FUN_0603F91C | 4 | LEAF | 0% | BOOT | |
| 10 | FUN_060409DE | 4 | LEAF | 50% | BOOT | |
| 11 | FUN_060337FC | 5 | LEAF | 40% | BOOT | |
| 12 | FUN_06035C92 | 5 | LEAF | 0% | BOOT | |
| 13 | FUN_0603FA00 | 5 | LEAF | 0% | BOOT | |
| 14 | FUN_0602ECF2 | 6 | LEAF | 0% | BOOT | |
| 15 | FUN_06035438 | 6 | LEAF | 0% | BOOT | |
| 16 | FUN_0601164A | 7 | LEAF | 0% | BOOT | |
| 17 | FUN_06018EC8 | 7 | LEAF | 14% | BOOT | |
| 18 | FUN_0601AEB6 | 7 | LEAF | 0% | BOOT | |
| 19 | FUN_06035C2C | 7 | LEAF | 0% | BOOT | |
| 20 | FUN_0603EF54 | 7 | LEAF | 14% | BOOT | |
| 21 | FUN_0603F1E0 | 7 | LEAF | 14% | BOOT | |
| 22 | FUN_060285E0 | 8 | LEAF | 62% | BOOT | |
| 23 | FUN_06028600 | 8 | LEAF | 62% | BOOT | |
| 24 | FUN_0603F1F0 | 8 | LEAF | 12% | BOOT | |
| 25 | FUN_0602761E | 9 | LEAF | 44% | BOOT | |
| 26 | FUN_060322E8 | 10 | LEAF | 40% | BOOT | |
| 27 | FUN_0603C05C | 15 | LEAF | 33% | BOOT | |
| 28 | FUN_060192E8 | 16 | LEAF | 12% | BOOT | |
| 29 | FUN_0601F87A | 18 | LEAF | 11% | BOOT | |
| 30 | FUN_0601AE2C | 20 | LEAF | 10% | BOOT | |
| 31 | FUN_06034560 | 14 | LEAF | 7% | BOOT | |
| 32 | FUN_0603F8B8 | 11 | LEAF | 9% | BOOT | |
| 33 | FUN_0603F216 | 10 | LEAF | 10% | BOOT | |
| 34 | FUN_0603C08C | 10 | LEAF | 0% | BOOT | |
| 35 | FUN_06041014 | 11 | LEAF | 9% | BOOT | |

### Failed - CRASH (18 functions)

| # | Function | Insns | Match% | Notes |
|---|----------|-------|--------|-------|
| 1 | FUN_06042BEE | 6 | 86% | immediate AND optimization |
| 2 | FUN_06042BAC | 7 | 78% | immediate OR optimization |
| 3 | FUN_06038520 | 8 | 56% | extu.w removal, bf.s vs bf |
| 4 | FUN_0602D88E | 2 | 0% | Ghidra boundary error |
| 5 | FUN_06012E62 | 4 | 100% | Const pool overflow |
| 6 | FUN_06035C08 | 7 | 62% | ABI mismatch |
| 7 | FUN_0603F92C | 8 | 100% | Crash not code-related |
| 8 | FUN_0603F9DA | 8 | 0% | |
| 9 | FUN_06042BBE | 8 | 0% | |
| 10 | FUN_06028560 | 9 | 100% | Crash not code-related |
| 11 | FUN_0602760C | 9 | 44% | |
| 12 | FUN_06027630 | 9 | 44% | |
| 13 | FUN_060394C2 | 7 | 0% | |
| 14 | FUN_0603BF5A | 12 | 0% | |
| 15 | FUN_0603EF34 | 11 | 0% | |
| 16 | FUN_060400B4 | 10 | 0% | |
| 17 | FUN_0603FFE6 | 16 | 0% | |
| 18 | FUN_06038A48 | 12 | 8% | |

### Failed - CORRUPT (6 functions)

| # | Function | Insns | Match% | Notes |
|---|----------|-------|--------|-------|
| 1 | FUN_06034FE0 | 7 | 0% | `in_r0`/`in_r1` implicit params |
| 2 | FUN_06035C1C | 8 | 12% | rts delay slot diff |
| 3 | FUN_0603F202 | 8 | 0% | better optimization |
| 4 | FUN_06033520 | 16 | 44% | `in_r2` implicit param |
| 5 | FUN_06034708 | 11 | 0% | Ghidra boundary error |
| 6 | FUN_0603C0A0 | 9 | 11% | Constant loading diff |

---

## Notes

- **BOOT** = title screen reached, NOT functional correctness
- Functions may work during boot but fail during gameplay
- Hybrid pipeline allows testing without worrying about pool constants
- Delta=0 functions are highest priority (same size, should fit)
