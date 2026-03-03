# Kill BSR Problem

> **Status**: ACTIVE — Solution proven, mass conversion pending

## The Problem

The free build has 653 cross-function BSR/BRA instructions encoded as raw `.byte` pairs:
```asm
.byte   0xB2, 0x17    /* bsr 0x06005DD4 (anim_frame_transform) */
```

These are **hardcoded PC-relative displacements**. If any function between the caller and
the target changes size, the displacement becomes wrong → crash. This means functions
early in the binary (~first 90%) cannot grow — the "free" build isn't actually free.

Goals 1-3 of the car flip benchmark worked because `mode_select_handler` sits at ~95%
through the binary (almost nothing after it). Goal 5 tried to grow `render_cs0_loop` at
~35% through and crashed immediately: "Illegal Instruction PC=00000002".

## The Root Cause

GNU `sh-elf-as` refuses to emit `R_SH_IND12W` relocations for BSR/BRA instructions.
When it encounters `bsr external_symbol`, it tries to resolve the 12-bit displacement at
assembly time and fails:

```
Error: displacement to undefined symbol anim_frame_transform overflows 12-bit field
```

This happens even with `.extern`, even with the symbol in a different section of the same
file. The assembler simply does not implement relocation emission for BSR/BRA. This is a
missing feature in GNU binutils' SH backend — the relocation type `R_SH_IND12W` (type 4)
exists in the ELF spec, and the **linker** handles it correctly, but the **assembler**
never emits it.

**Update**: Investigation of the Cygnus 2.7-96Q3 SDK (see below) revealed that even
Sega's original assembler didn't support this. BSR instructions were produced by the
**linker's relaxation pass**, not by the assembler. The assembler always emitted JSR
patterns; the linker optimized them to BSR when targets were within range.

## The Solution (PROVEN — byte-identical 2026-03-03)

Bypass the assembler using the `.reloc` directive to manually inject the relocation:

```asm
/* Before (frozen, hardcoded): */
.byte   0xB2, 0x17    /* bsr 0x06005DD4 (anim_frame_transform) */

/* After (relocatable, linker-resolved): */
.reloc ., R_SH_IND12W, anim_frame_transform - 4
.2byte  0xB000
```

For BRA instructions, use `.2byte 0xA000` instead.

### Why `-4`?

SH-2 BSR computes: `target = PC + 4 + displacement × 2`

The linker's `R_SH_IND12W` handler computes: `displacement = (S + A - P) / 2`
where S = symbol address, A = addend, P = relocation address (= instruction address).

But we need: `displacement = (S - P - 4) / 2`

So addend A = -4 compensates for the PC+4 pipeline offset.

### Proof

1. Converted one BSR in `anim_frame_counter.s` (line 72)
2. `sh-elf-readelf -r` confirmed `R_SH_IND12W` relocation in the .o file
3. Full `make validate` → **PASS: free build byte-identical to original**
4. Reverted to preserve clean working tree

## Scope

| Metric | Count |
|--------|-------|
| Total BSR/BRA byte pairs | 653 |
| Files affected | 314 |
| BSR (0xBxxx) | ~600 (estimated) |
| BRA (0xAxxx) | ~53 (estimated) |

Average ~2 per file. Some files have many (e.g., `vblank_dma_chain.s` has 21,
`cmd_dispatch_main.s` has 15).

## Conversion Plan

### Phase 1: Build the converter tool

Write `tools/convert_bsr_reloc.py` that:
1. Reads each `.s` file in `reimpl/src/`
2. Finds `.byte 0xBX, 0xYY /* bsr 0xADDRESS ... */` patterns
3. Resolves the target address to a symbol name (from the comment or from the symbol table)
4. Replaces with `.reloc ., R_SH_IND12W, SYMBOL - 4` + `.2byte 0xB000`
5. Same for BRA (0xAXXX) with `.2byte 0xA000`

The comments already contain the target address or symbol name in most cases.

### Phase 2: Mass conversion

Run the converter on all 314 files. Validate:
- `make validate` (free build byte-identical)
- `make retail-validate` (retail build byte-identical)
- `python tools/validate_build.py` (full validation including +4 shift boot test)

### Phase 3: Prove function growth works

Take `render_cs0_loop` and grow it by +4 bytes (the modification that crashed before).
With relocatable BSR/BRA, the linker should recalculate all displacements automatically.
If it boots and runs correctly, BSR/BRA is truly solved.

### Constraints

- **±4KB range limit**: BSR/BRA displacement is 12-bit signed (×2), giving ±4094 bytes
  of reach. If a function grows so much that a BSR target moves out of range, the linker
  will error (not silently produce wrong code). This is a hard limit — if a conversion
  exceeds range, that specific BSR must be converted to a JSR (pool-based call, +4 bytes).
- **Delay slots**: BSR/BRA have delay slots. The conversion only changes the instruction
  encoding, not the delay slot — no flow changes.
- **Section ordering**: The free.ld linker script must preserve section order for BSR/BRA
  range to hold. It already does this (SORT_BY_NAME on .text.* sections).

## Cygnus 2.7-96Q3 Assembler Investigation (2026-03-03)

The Sega Saturn SDK ships with `AS.EXE` (DOS executable) in
`tools/cygnus-2.7-96Q3/bin/`. This is the actual development assembler from 1996.

### Findings

**The Cygnus assembler also does NOT support `bsr external_symbol` directly.**

Evidence from examining all compiled objects in the SDK:

| Object | Relocation Types | BSR/BRA relocations? |
|--------|-----------------|---------------------|
| HELLO.O | r_imm32 (×3) | None |
| CRT0.O | r_imm32 (×5) | None |
| LIBC.A | r_imm32 (×1,251) | None |
| LIBSGL.A | r_imm32 (×1,350) | None |

Every cross-function call in the SDK uses pool-based `jsr @r1` with an `r_imm32`
relocation on the pool entry. Zero BSR-type relocations exist anywhere.

### How Sega's toolchain produced BSRs

`RELAX.TXT` in the SDK documents **linker relaxation** — the linker, NOT the
assembler, converts `mov.l pool,r1; jsr @r1` → `bsr target` when the target is
within ±4KB range:

```
.uses L3       <- assembler marks "jsr @r1 uses register load at L3"
jsr     @r1

L5:
    .long   func   <- r_imm32 relocation here
```

Compiled with `-mrelax` (compiler flag) and linked with `-relax` (linker flag),
the linker replaces the 6-byte `mov.l + jsr` with a 2-byte `bsr` and removes
the pool entry, saving 4 bytes per successful relaxation.

### Implications

1. **Both assemblers** (Cygnus 1996 and GNU 2024) lack direct BSR relocation support
2. **BSR was always a linker optimization**, never an assembly-time feature
3. Our `.reloc` directive approach is actually MORE direct than Sega's original method
   (we emit the BSR directly; they relied on the linker to discover JSR→BSR opportunities)
4. The CCE transplant can use either approach:
   - Our `.reloc` method for known BSR targets
   - Linker relaxation `-relax` for automatic BSR optimization of new C code

### DOSBox-X Status

Attempted to run `AS.EXE` via DOSBox-X (`C:\DOSBox-X\dosbox-x.exe`). The GO32 DOS
extender (DJGPP v1) programs fail to execute — likely a DPMI/VCPI compatibility gap.
All programs exit silently without producing output. However, our GNU `sh-elf-objdump`
can read the COFF-format `.O` and `.A` files directly, which provided all the evidence
needed.

## Impact

Once complete, functions throughout the binary can grow/shrink freely (within ±4KB BSR
range). This unlocks:
- Code modifications anywhere in the binary (not just the last ~10%)
- C reimplementations that generate different-sized code
- The CCE transplant (functions at completely different addresses)
