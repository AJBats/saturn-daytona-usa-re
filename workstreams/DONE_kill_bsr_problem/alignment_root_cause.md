# The Real Alignment Problem: One Function Per .O File

> **Date**: 2026-03-03
> **Status**: Root cause identified — changes everything about the build approach

## The Discovery

Every linker hack we've ever done — `SUBALIGN(2)`, COFF hybrid pipeline, section
ordering tricks — exists to work around a single self-inflicted problem:

**We have 1,048 .O files, one per function. Sega had ~30-80 .O files with
many functions each.**

The linker pads each input `.text` section to an alignment boundary before
concatenating the next one. With 1,048 .O files, that's 1,047 padding points.
With Sega's ~50 files, it was ~50 padding points (and most fell on natural
4-byte boundaries anyway).

## Why 2-Byte Packing Is Natural (Within a TU)

SH-2 instructions are all 16-bit (2 bytes). When a compiler or assembler emits
multiple functions into a single `.text` section, each function starts exactly
where the previous one ended:

```
.text section from one .c file (one .O):

func_a:          ← offset 0x00
  mov #1, r0       2 bytes
  rts              2 bytes
  nop              2 bytes
func_b:          ← offset 0x06 (NOT 4-byte aligned — and that's fine)
  mov #2, r0       2 bytes
  mov #3, r1       2 bytes
  rts              2 bytes
  nop              2 bytes
func_c:          ← offset 0x0E (NOT 4-byte aligned — and that's fine)
  ...
```

No alignment directives. No padding. No linker involvement. The assembler just
writes one instruction after another. `func_b` is at offset 6 because `func_a`
is 6 bytes. The linker never even knows where one function ends and the next
begins — it sees one contiguous `.text` section.

**22.8% of Daytona's functions (239 of 1,048) start at non-4-byte addresses.**
These are functions that follow an odd-sized predecessor within the same
original translation unit. This is completely normal — it's how every SH-2
program works.

## Why Padding Happens (Between .O Files)

When the linker merges `.text` from different .O files, it aligns each input
section to a boundary:

```
file1.O .text:  6 bytes  [func_a: mov, rts, nop]
                          ← LINKER INSERTS PADDING HERE
file2.O .text:  8 bytes  [func_b: mov, mov, rts, nop]
```

Different linkers pad differently:
- **Cygnus LD**: 4-byte alignment (2 bytes padding after a 6-byte section)
- **GNU ld default**: 16-byte alignment (10 bytes padding after a 6-byte section)
- **GNU ld SUBALIGN(2)**: 2-byte alignment (0 bytes padding — tight pack)

With 1,048 .O files, we hit this padding at every function boundary. With Sega's
~50 files, they hit it ~50 times (negligible, and relaxation shifts things
to 2-byte boundaries afterward anyway).

## What SUBALIGN(2) Actually Does

`SUBALIGN(2)` tells GNU ld: "when merging input sections, use 2-byte alignment
instead of the default." This forces tight packing — exactly what happens
naturally within a single TU.

**SUBALIGN(2) is a workaround for our unnatural one-function-per-file split.**
If we consolidate functions back into multi-function TUs (which is how Sega
built them), the alignment is natural and no linker override is needed.

## What This Means for Cygnus LD

Cygnus LD was ruled out because it pads to 4 bytes with no override. But if
functions are consolidated into larger TUs, there are far fewer section
boundaries, and the padding only occurs between TUs — not between every
function.

With full consolidation (~50 TUs matching Sega's original file structure),
the 4-byte padding at ~50 boundaries would add at most ~100 bytes. That
wouldn't break the binary — it would just be slightly larger than Sega's
original (which had the same ~50 boundaries but potentially less padding
due to relaxation shrinking sections to odd sizes).

**Consolidation doesn't eliminate the problem — but it reduces it from
1,047 padding points to ~50, which may be tolerable for a free build that
doesn't need byte-identical output.**

## How Sega's Build Probably Worked

```
game_physics.c  ──→  GCC -mrelax  ──→  game_physics.O  (many functions, one .text)
game_render.c   ──→  GCC -mrelax  ──→  game_render.O   (many functions, one .text)
game_input.c    ──→  GCC -mrelax  ──→  game_input.O    (many functions, one .text)
...~30-80 files...
                ──→  LD -relax -T daytona.cmd  ──→  APROG.BIN
```

1. Compiler places functions sequentially in `.text` (2-byte packed, natural)
2. Compiler marks JSR calls with `.uses` for relaxation (`-mrelax` flag)
3. Linker merges ~50 `.text` sections (minimal padding at boundaries)
4. Linker `-relax` converts JSR→BSR where possible (shrinks code, can shift
   subsequent functions to any 2-byte boundary)

The result: functions at 2-byte alignment throughout, with relaxation
producing BSR instructions wherever targets are within ±4KB.

## Implications for Our Project

### The consolidation path
We've already consolidated 22 multi-function TUs based on BSR/BRA evidence.
Further consolidation would reduce padding points and potentially allow
Cygnus LD as the linker (no SUBALIGN needed).

But we don't know Sega's original file boundaries. BSR/BRA cross-references
prove proximity (±4KB) but not same-file. We'd need other evidence (shared
static variables, compilation unit markers, code style boundaries) to
reconstruct the original TU structure.

### The SUBALIGN path (current approach)
Keep one function per .O file, use GNU ld SUBALIGN(2) to force tight packing.
This works perfectly and is what the current build system does. It's a hack,
but a correct one that produces byte-identical output.

### The hybrid path
Consolidate where evidence supports it (reducing padding points), use
SUBALIGN(2) for the rest. This is what the project is already doing
incrementally.

## Why This Wasn't Obvious

1. We never questioned WHY alignment padding exists — we just fixed it
2. The SUBALIGN(2) fix worked so well that the root cause was never investigated
3. The one-function-per-file approach seemed natural for RE (easy to override
   individual functions), but it created an artificial problem
4. Sega's original build system is lost — we can't directly observe how they
   structured their source files
5. The COFF section alignment field is empty (just STYP_TEXT flag) — the
   alignment is imposed by the linker, making it seem like a linker bug
   rather than a file-structure issue
