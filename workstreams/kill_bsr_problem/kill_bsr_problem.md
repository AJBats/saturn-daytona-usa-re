# Kill BSR Problem — `.reloc` Conversion

Make all hardcoded BSR/BRA `.byte` pairs linker-resolved so functions can
change size without breaking cross-function branches.

## Background

BSR/BRA instructions use 12-bit PC-relative displacements (±4KB range).
In our source files, these are hardcoded as `.byte 0xBX, 0xYY` pairs with
displacement baked in at disassembly time. When a function changes size,
all BSR/BRA pairs that cross the changed region break — the displacement
points to the wrong address.

This blocked Car Flip Benchmark goals that required function size changes.
Only size-neutral modifications (pool constant swaps) were safe.

## Solution: `.reloc` Directive

GNU sh-elf-as supports `.reloc` for emitting arbitrary relocations:

```asm
# Before (hardcoded, breaks if layout shifts):
.byte 0xB2, 0x17    /* bsr 0x06005DD4 (anim_frame_transform) */

# After (linker-resolved, survives layout changes):
.reloc ., R_SH_IND12W, anim_frame_transform - 4
.2byte 0xB000       /* BSR placeholder — linker fills displacement */
```

Properties:
- Zero code size change (2 bytes → 2 bytes)
- Byte-identical output (linker computes same displacement as hardcoded)
- No build pipeline changes (same assembler, same linker)
- If target moves beyond ±4KB, linker errors (clear signal to convert to JSR)

Proven in `workstreams/kill_bsr_problem/run_reloc_test.sh`.
Full study: `workstreams/kill_bsr_problem/bsr_study_results.md`.

## Scope

653 BSR/BRA `.byte` pairs across 314 source files (both `src/` and `retail/`).
Analysis tool: `tools/analyze_bsr_bra.py`.

## Plan

1. **Single-file e2e test** — Convert one file, full build, validate byte-identical
2. **Batch conversion script** — Regex-based: `.byte 0xBX, 0xYY /* bsr ADDR */` →
   `.reloc` + `.2byte 0xB000` (and 0xA000 for BRA)
3. **Convert all 314 files** — Run script, validate byte-identical
4. **Prove relocatability** — Grow a function, verify BSR auto-adjusts,
   boot-test the modified binary

## Status

| Step | Status |
|------|--------|
| Study + pipeline selection | **DONE** |
| Single-file e2e test | Pending |
| Batch conversion script | Pending |
| Full conversion (653 pairs) | Pending |
| Relocatability proof | Pending |
