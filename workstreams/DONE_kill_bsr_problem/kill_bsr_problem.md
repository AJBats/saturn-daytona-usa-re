# Kill BSR Problem — `.reloc` Conversion

**Status: DONE** (2026-03-03)

Make all hardcoded BSR/BRA `.byte` pairs linker-resolved so functions can
change size without breaking cross-function branches.

## Background

BSR/BRA instructions use 12-bit PC-relative displacements (±4KB range).
In our source files, these were hardcoded as `.byte 0xBX, 0xYY` pairs with
displacement baked in at disassembly time. When a function changed size,
all BSR/BRA pairs that cross the changed region broke — the displacement
pointed to the wrong address.

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

## Results

- **606 BSR/BRA pairs** converted across ~300 src/ files
- **~100 `.global FUN_XXXXXXXX` sublabels** added to src/ and retail/
  (sub-functions within consolidated TUs that lacked labels)
- **Golden free+4shift updated** — old golden had 2 latent wrong BSR
  displacements in math_trig_lib (targeted garbage in MODS=1 layout)
- **Relocatability proven**: added +16 bytes to `system_init` (first
  function after `_start`), shifted entire binary, booted and raced laps

## Tools

- `tools/convert_bsr_reloc.py` — Batch converter (`.byte` → `.reloc`)
- `tools/add_sublabels.py` — Inserts missing `.global` labels at correct
  byte offsets for sub-functions within consolidated TUs

## Validation

All three tiers pass: retail match, free match, free+4shift golden + boot.

| Step | Status |
|------|--------|
| Study + pipeline selection | **DONE** |
| Single-file e2e test | **DONE** |
| Batch conversion (606 pairs) | **DONE** |
| Sublabel insertion (~100 labels) | **DONE** |
| Relocatability proof (+16 bytes, boot test) | **DONE** |
