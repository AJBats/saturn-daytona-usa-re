# L3 Uplift Rules

Hard constraints for converting L2 byte blobs to L3 SH-2 mnemonics.

## Conventions

- **All immediates in hex.** `mov #0x4, r0`, `or #0x80, r0`, `mov #-0x1, r0`. No decimal.
- **Regenerate, don't hand-edit.** If the L3 output has a bug, fix `tools/generate_l3_tu.py`
  (or `tools/sh2_decode.py`) and regenerate. The generator is the source of truth for L3 files.
- **One TU = one file.** Both retail (multi-section) and src (single-section) use one file
  per translation unit. The filename is the TU's human name (e.g., `game_update_loop`).

## Pre-Generation Checklist

Before running the generator, verify the retail file has `.global` labels for ALL
functions in the TU:

1. **Cross-check with annotated ASM** (`asm/*.s`). Search for addresses in the TU's
   range — any `FUN_XXXXXXXX:` label in the annotations that doesn't have a
   corresponding `.global` in the retail file needs one added.
2. **The flow analyzer seeds from `.global` labels only.** Unlabeled functions will be
   silently emitted as `.4byte` data blobs instead of decoded instructions. The output
   will be byte-identical but unreadable.
3. **Name every function.** L3 is about human-readable mnemonics — never leave a
   `FUN_XXXXXXXX` behind. Use annotated ASM (`asm/*.s`) names, code context, or call
   patterns to derive a meaningful name. Only keep `FUN_XXXXXXXX` if completely stuck,
   and flag it for discussion.

## TU Boundaries

- **Verify before consolidating.** Confirm no cross-section `mov.l` references cross the
  proposed TU boundary in either direction. The function before the start and after the end
  must be fully self-contained.
- **Cross-TU calls use `jsr` via pool** (linker-resolved). BSR/BRA are always TU-internal
  (assembler-resolved). This is a property of SH-2's limited branch range, not a rule we
  enforce — the compiler already did it.

## mov.l Alignment Caveat

`mov.l @(disp,PC), Rn` requires the pool target to be 4-byte aligned. GNU as checks
section-relative alignment, assuming the section starts at a 4-byte boundary. When
`TU_START % 4 != 0`, the check fails — the assembler rejects valid pool references.

The generator handles this automatically: when `TU_START % 4 != 0`, `mov.l` pool
references are emitted as raw `.byte` pairs with a comment showing the decoded form.
This is safe because `mov.l @(disp,PC)` is PC-relative — the displacement is between
the instruction and its pool target, both of which move together in the same section.

## Agent Parallelism

**Maximum 7 annotation/uplift agents at a time.** Running more burns through API
capacity too fast and causes agents to hit rate limits mid-work, leaving files
partially annotated. Launch a batch of 7, wait for completion, then launch the next.

## Validation

3-class validation required before commit — same as all elevations:

```bash
python tools/validate_build.py
```

Run from **Windows** (not WSL) — the script invokes `wsl` internally.

1. Retail binary match (byte-identical)
2. Free build match (byte-identical)
3. Free+4shift golden match + boot test
