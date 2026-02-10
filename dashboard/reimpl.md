# Reimplementation Dashboard

## Symbol Coverage

| Metric | Value |
|--------|-------|
| Original binary functions | 1234 |
| Reimpl symbol coverage | 1234 (100%) |
| Decomp L1 lift (from Ghidra) | 842 |
| ASM-only stubs (no-op) | 729 |
| Hand-written translations | 96 |
| Disabled (broken Ghidra output) | 10 |

## Build Status

| Metric | Value |
|--------|-------|
| Compiler | sh-elf-gcc 13.3.0 |
| Binary size | 319KB code (padded to 385KB) |
| Compilation errors | 0 |
| Linker errors | 0 |
| Warnings | ~2255 |
| Linker stubs (external data) | 1482 |

## Quality Levels (see workstreams/reimplementation.md)

| Level | Count | Description |
|-------|-------|-------------|
| L1 (Decomp Lift) | 842 | Compiles but raw Ghidra output |
| L1 (Stub) | 729 | No-op stubs for linker resolution |
| L2 (Named) | 96 | Hand-written with some structure |
| L3+ | 0 | Not started |

## Warning Breakdown

| Category | Count |
|----------|-------|
| Parentheses suggestions | ~855 |
| Array bounds (Ghidra addresses) | ~399 |
| Pointer/integer casts | ~174 |
| Uninitialized Ghidra vars | ~100 |
| Other | ~727 |

## Boot Test

| Test | Result | Date |
|------|--------|------|
| Compilation | PASS | 2026-02-10 |
| Link | PASS | 2026-02-10 |
| Disc injection | PASS | 2026-02-10 |
| Mednafen boot | Black screen (expected for L1) | 2026-02-10 |

## Source File Inventory

| Category | Files | Functions |
|----------|-------|-----------|
| batch_*.c (L1 lifts) | 31 | 742 |
| asm_*.c (no-op stubs) | 10 | 729 |
| Hand-written (init, math, etc.) | 27 | 96 |
| Stubs/linker | 3 | ~1500 |
| **Total** | **71** | **~3067** |

## Next Steps

1. Fix 10 disabled functions (severe Ghidra artifacts)
2. L2 pass: hardware register defines, struct definitions
3. L2 pass: name functions from annotated ASM
4. Translate ASM-only stubs from production disassembly
5. Boot test improvements (VDP init, state machine)

---
*Last updated: 2026-02-10*
