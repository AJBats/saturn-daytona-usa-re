# Deep GCC 2.6.3 Compiler Work — Week Plan

## Documentation Strategy

3 active files for context management:

| File | Role | Why |
|------|------|-----|
| `docs/compiler_patches.md` | Patch log (keep as-is) | What we did, in chronological order. Append-only. |
| `docs/gcc26_internals.md` | GCC knowledge base | Survives context resets. Organized by subsystem. Every insight that took >5min to discover goes here. |
| `gcc26_reconstruction_strategy.md` | High-level strategy (update) | Already exists. Add progress tracking. Ties compiler work back to Daytona. |

Additional catalogs:
- `docs/test_suite_catalog.md` — function-level match status, root cause per failure
- `docs/failure_taxonomy.md` — named codegen patterns, affected functions, tractability

Key principle: **anything that took effort to discover gets written down before the context window ends.**

---

## Starting Point: 6 PASS / 16 FAIL / 22 tests

All 16 failures are delta<=0 (our code is same length or shorter):
- 4 BSR (our bsr vs original jsr, delta -1 to -2)
- 2 delay slot fill (we fill, original uses nop, delta -1)
- 4 better codegen (genuinely tighter code, delta -1 to -2)
- 4 scheduling (delta=0, 2-4 opcode diffs in ordering)
- 2 RTL combiner (delta=0, 6 diffs in codegen strategy)

---

## Stage 1: Expand Test Suite (Day 1-2)

**Goal**: Go from 22 to 100+ test functions.

### Tasks
1. Write `tools/gen_expected.py` — extract expected opcodes from `build/aprog.s`
2. Write `tools/gen_test_skeleton.py` — draft C from Ghidra decompilation
3. Select 80+ new test functions (Tier A: LEAF <=15 insns, Tier B: CALL <=15, Tier C: medium)
4. Manual cleanup pass on generated C files
5. Run full harness, establish new baseline

### Key Files
- `build/aprog.s`, `build/aprog_syms.txt`, `ghidra_project/decomp_all.txt`

---

## Stage 2: The Scheduling Experiment (Day 2-3)

**Goal**: Test hypothesis that post-reload scheduling causes 4 scheduling-diff functions.

Post-reload scheduling (`flag_schedule_insns_after_reload`) is enabled by `-O2`. The original compiler may not have had it.

### Tasks
1. Compile all tests with `-fno-schedule-insns2`
2. Compare: if scheduling-diff functions improve → confirmed
3. If confirmed: global disable in sh.h OVERRIDE_OPTIONS
4. If rejected: RTL dump analysis

---

## Stage 3: Per-Function Optimization Control (Day 3)

**Goal**: Add `-mno-bsr` flag for 4 BSR-affected functions.

Add to `target_switches[]` in sh.h, modify `bsr_operand()` in sh.c. Test harness gets `.flags` file support per function.

---

## Stage 4: RTL Combiner Adjustments (Day 4-5)

**Goal**: Fix FUN_0600C970 (range check) and FUN_06018EC8 (byte extraction) via C source rewrites.
- Nested ifs prevent range_test() folding
- volatile short prevents byte load optimization

---

## Stage 5: Full Binary Build System (Day 5-6)

**Goal**: MVP compile-assemble-link pipeline for 10-20 verified functions.
- Pool constant sharing, BSR range selection
- Linker script with fixed addresses from aprog_syms.txt

---

## Stage 6: Convergence at Scale (Day 6-7)

**Goal**: Run 100+ test suite, identify new patterns, implement quick wins.
- Target: 40%+ PASS rate, complete failure taxonomy

---

## Stage Dependencies

```
Stage 1 (test expansion) ─────────────────→ Stage 6 (convergence)
                                                 ↑
Stage 2 (scheduling experiment) ────────────────/
Stage 3 (per-function flags) ──────────────────/
Stage 4 (combiner adjustments) ───────────────/
Stage 5 (full binary build) ─────────────────/
```

**Highest ROI order**: 1 → 2 → 3 → 4 → 5 → 6

---

## Verification

```bash
MSYS_NO_PATHCONV=1 wsl -d Ubuntu -- bash /mnt/d/Projects/SaturnReverseTest/tools/test_harness.sh
```

Rebuild cc1: `cd gcc26-build && make -j$(nproc) cc1 CFLAGS="-std=gnu89 -m32 -static -fcommon -DHAVE_STRERROR"`

**Regression rule**: No patch may reduce PASS count.
