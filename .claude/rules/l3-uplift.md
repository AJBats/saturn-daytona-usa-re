# L3 Uplift Rules

Hard constraints for converting L2 byte blobs to L3 SH-2 mnemonics.

## Conventions

- **All immediates in hex.** `mov #0x4, r0`, `or #0x80, r0`, `mov #-0x1, r0`. No decimal.
- **Regenerate, don't hand-edit.** If the L3 output has a bug, fix `tools/generate_l3_tu.py`
  (or `tools/sh2_decode.py`) and regenerate. The generator is the source of truth for L3 files.
- **One TU = one file.** Both retail (multi-section) and src (single-section) use one file
  per translation unit. The filename is the TU's human name (e.g., `game_update_loop`).

## TU Boundaries

- **Verify before consolidating.** Confirm no cross-section `mov.l` references cross the
  proposed TU boundary in either direction. The function before the start and after the end
  must be fully self-contained.
- **Cross-TU calls use `jsr` via pool** (linker-resolved). BSR/BRA are always TU-internal
  (assembler-resolved). This is a property of SH-2's limited branch range, not a rule we
  enforce — the compiler already did it.

## Validation

3-class validation required before commit — same as all elevations:

```bash
python tools/validate_build.py
```

1. Retail binary match (byte-identical)
2. Free build boots to menu
3. Free+4shift boots to menu
