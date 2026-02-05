# Compilation Dashboard

## Summary

| Metric | Value |
|--------|-------|
| C source files | 886 |
| Compile success | 886 (100%) |
| Ghidra decomps | ~880 |
| Coverage | 100% |

## Compiler

| Property | Value |
|----------|-------|
| Compiler | GCC 2.6.3 |
| Backend | SH-2 (patched) |
| Patches applied | 23 |
| Flags | `-O2 -m2 -mbsr` |

## Compiler Patches

See [workstreams/compiler_patches.md](../workstreams/compiler_patches.md) for detailed patch list.

| Category | Count |
|----------|-------|
| Peephole patterns | 8 |
| Delay slot fixes | 5 |
| Tail call optimization | 3 |
| Per-function flags | 4 |
| Other | 3 |

---
*Last updated: 2026-02-05*
