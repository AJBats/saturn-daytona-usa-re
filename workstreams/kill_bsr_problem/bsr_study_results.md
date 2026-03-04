# BSR/BRA Relocation Study — Experimental Results

> **Date**: 2026-03-03
> **Branch**: kill-bsr-problem
> **Purpose**: Re-prove solutions and capture evidence (prior proof was lost)

## Executive Summary

Three pipelines were tested end-to-end. Two work, one doesn't.

| Pipeline | BSR relocation? | 2-byte packing? | Relaxation? | Viable? |
|----------|----------------|-----------------|-------------|---------|
| GNU as + GNU ld (`.reloc`) | **YES** | **YES** (SUBALIGN) | No | **YES** |
| Cygnus AS + GNU ld (`-relax`) | **YES** | **YES** (SUBALIGN) | **YES** | **YES** |
| Cygnus AS + Cygnus LD (`-relax`) | **YES** | **NO** (4-byte pad) | **YES** | **NO** |

**Cygnus LD is ruled out** — it pads sections to 4-byte alignment with no override, breaking 22.8% of function placements. GNU ld with `SUBALIGN(2)` is required.

The remaining choice is between two assemblers (GNU as vs Cygnus AS), both feeding into GNU ld.

---

## Part 1: Assembler + Relocation Tests

### Experiment 1: `.reloc` with GNU sh-elf-as — PROVEN

Replace each `.byte 0xBX, 0xYY /* bsr target */` with:
```asm
.reloc ., R_SH_IND12W, target_func - 4
.2byte 0xB000    /* BSR placeholder — linker fills displacement */
```

**Relocation in .o file:**
```
 Offset     Info    Type            Sym.Value  Sym. Name + Addend
00000002  00000604 R_SH_IND12W       00000000   target_func - 4
```

**Linked output:**
```
 6010000:  4f 22        sts.l  pr,@-r15
 6010002:  b0 03        bsr    601000c <target_func>    ← CORRECT
 6010004:  00 09        nop
```

BSR displacement verified: `PC+4 + 3×2 = 0x601000C`. BRA (`.2byte 0xA000`) also works.

**Properties**: Zero code size change. Each `.byte` pair → `.reloc` + `.2byte`. Guaranteed byte-identical output. No DOSBox needed.

### Experiment 2: `.uses` + jsr with GNU sh-elf-as — DOES NOT WORK

GNU as accepts `.uses` but warns: `"Warning: .uses pseudo-op seen when not relaxing"`. It emits `R_SH_DIR32` (on pool entry) but NOT `R_SH_USES`. The linker's `-relax` has nothing to work with — output is identical with and without.

**Conclusion**: GNU sh-elf-as does not implement `.uses` relocation emission. The `-relax` flag is a no-op for ELF objects from GNU as.

### Experiment 3: Cygnus AS + GNU ld — WORKS (with SUBALIGN)

DOSBox-X **can** run Cygnus AS. Prior "DOSBox failed" note was a path bug — fix is `wslpath -w` for the conf path.

**Cygnus AS produces proper relaxation relocations:**
```
OFFSET   TYPE              VALUE
00000002 r_pcrelimm8by4    .text          ← mov.l PC-relative
00000004 r_uses            .text-6        ← .uses annotation
00000010 r_imm32           _func_b        ← pool entry (absolute)
00000010 r_count           *ABS*+1
0000000e r_align           *ABS*+2
```

**GNU ld with `-relax` and `SUBALIGN(2)` on these COFF objects:**
```
 6010000:  4f 22        sts.l  pr,@-r15
 6010002:  b0 03        bsr    601000c <_func_b>   ← RELAXED! Clean BSR.
 6010004:  00 09        nop
 ...
 601000c:  e0 02        mov    #2,r0               ← No residual bytes
```
Size: 20 bytes (vs 28 without relax). **Clean compaction, no dead bytes.**

Note: earlier test without `SUBALIGN(2)` showed residual bytes — that was a 16-byte alignment artifact, not a relaxation bug. With proper 2-byte packing, relaxation output is clean.

---

## Part 2: Cygnus LD Feasibility Tests

### TEST 1: Basic Linking — PASS
Cygnus LD links COFF .O → COFF .X. `sh-elf-objdump` reads it. `sh-elf-objcopy -O binary` converts to flat binary.

### TEST 2: Alignment — FAIL (fatal for Daytona)

| Linker | 3 functions (6+8+6 bytes) | Packing |
|--------|--------------------------|---------|
| Cygnus LD | **24 bytes** | 4-byte padding |
| GNU ld (no SUBALIGN) | **38 bytes** | 16-byte padding |
| GNU ld (SUBALIGN=2) | **20 bytes** | 2-byte (tight) |

**Daytona requires 2-byte packing.** 239 of 1,048 functions (22.8%) start at addresses that are NOT 4-byte aligned (e.g., `0x0600330A`, `0x060058FA`). Cygnus LD's 4-byte padding would misplace nearly a quarter of all functions.

**Root cause**: The COFF .text section flags (`0x00000020 = STYP_TEXT`) contain NO alignment field. Both linkers impose their own defaults:
- GNU ld BFD adapter: 16-byte (overridable with SUBALIGN)
- Cygnus LD: 4-byte (NO override mechanism)

Tested mitigations that FAILED:
- `.align 1` in source files — doesn't change COFF section alignment (still 2**4 in header)
- `objcopy --set-section-alignment` — doesn't work on COFF format
- Python COFF header patching — alignment isn't stored in the section header
- `-oformat binary` — Cygnus LD failed to produce output

**Cygnus LD has no SUBALIGN equivalent. No way to get 2-byte packing.**

### TEST 3: Linker Script Features — PASS
Cygnus LD accepted: `ENTRY(_func_a)`, section placement at absolute address, symbol assignment (`my_sym1 = 0x06063D98`, `my_sym2 = _func_a + 0x10`). Both symbols correctly resolved.

### TEST 4: Linker Relaxation — PASS (clean)
Cygnus LD `-relax` converts JSR→BSR: 28 bytes → 20 bytes (saved 8). Clean output, no residual bytes. Identical result to GNU ld `-relax`.

### TEST 5: `-oformat binary` — FAIL
Cygnus LD could not produce direct binary output.

### Cygnus LD Capabilities (from --help)
- Supported targets: `coff-sh coff-shl srec symbolsrec tekhex binary ihex`
- Has: `-relax`, `-T`, `-Map`, `-defsym`, `-Ttext`, `-oformat`
- Missing: SUBALIGN, PROVIDE, ASSERT, /DISCARD/, EXCLUDE_FILE

### Why Cygnus LD Was Passed Over

**The alignment problem is a hard blocker.** Cygnus LD pads input sections to 4-byte boundaries with no override. 22.8% of Daytona's functions start at non-4-byte addresses. No linker script trick or source-level change can fix this — the alignment is hardcoded in the linker.

Other issues (solvable but moot given the blocker):
- `PROVIDE()` → plain `sym = expr` works in Cygnus LD scripts
- `ASSERT()` → post-link size check script
- `/DISCARD/` → not needed for COFF output
- `EXCLUDE_FILE()` → .O file command-line ordering

---

## Part 3: Option Comparison

### Option A: GNU sh-elf-as + GNU sh-elf-ld with `.reloc`

**How it works**: Convert each `.byte 0xBX, 0xYY /* bsr target */` to `.reloc ., R_SH_IND12W, target - 4` + `.2byte 0xB000`. The linker resolves the displacement at link time. No code size change.

| Property | Value |
|----------|-------|
| Assembler | GNU sh-elf-as (native, fast) |
| Linker | GNU sh-elf-ld with SUBALIGN(2) |
| DOSBox needed? | **No** |
| Code size change | **None** (2 bytes → 2 bytes) |
| Byte-identical? | **Yes** (conversion is a no-op at binary level) |
| Conversion scope | 653 BSR/BRA pairs in 314 files |
| Automation | Regex script: `.byte 0xBX,0xYY /*bsr ADDR*/` → `.reloc`+`.2byte` |
| New C code BSR? | No — C code emits JSR, which works fine (4 bytes larger) |
| Build pipeline | Same as main branch (no changes needed) |

### Option B: Cygnus AS (DOSBox) + GNU sh-elf-ld with `-relax`

**How it works**: Convert BSR `.byte` pairs to `.uses`+`jsr` patterns. Cygnus AS emits `r_uses` relocations in COFF objects. GNU ld `-relax` converts JSR→BSR when target is within ±4KB.

| Property | Value |
|----------|-------|
| Assembler | Cygnus AS via DOSBox-X (~0.5s/file) |
| Linker | GNU sh-elf-ld with `-relax` and SUBALIGN(2) |
| DOSBox needed? | **Yes** (every assembly step) |
| Code size change | Grows 6 bytes/BSR then shrinks back via relaxation |
| Byte-identical? | **Yes** (with SUBALIGN=2, relaxation compacts cleanly) |
| Conversion scope | All 653 BSR/BRA pairs |
| Automation | Source rewrite: `.byte` pair → `.uses`+`jsr`+pool entry |
| New C code BSR? | **Yes** — compiler `-mrelax` auto-optimizes JSR→BSR |
| Build pipeline | Cygnus AS (DOSBox) → COFF .O → GNU ld → ELF → binary |

### Option C: Hybrid (both pipelines)

Use GNU sh-elf-as with `.reloc` for the 653 existing BSR/BRA pairs. Keep `-relax` in linker flags so future Cygnus-assembled COFF objects (if any) get automatic relaxation.

---

## Key Corrections to Prior Workstream Doc

1. **DOSBox-X works** — the "programs fail to execute" note was a WSL path bug. Fix: `wslpath -w` for the `-conf` argument.
2. **GNU ld relaxation DOES work** — but only with Cygnus COFF objects (which have `r_uses` relocations), not with GNU ELF objects. The earlier claim that "GNU ld -relax does nothing" was only true for ELF inputs.
3. **Relaxation output IS clean** — the "residual dead bytes" seen earlier were caused by 16-byte alignment padding (no SUBALIGN), not by incomplete relaxation. With SUBALIGN(2), relaxation compacts perfectly.

---

## Reproduction

All test scripts in `workstreams/kill_bsr_problem/`:

| Script | What it tests |
|--------|--------------|
| `run_reloc_test.sh` | `.reloc` BSR/BRA + `.uses` with GNU as + BRA test |
| `test_dosbox3.sh` | Cygnus AS `.uses` + GNU ld `-relax` linking |
| `test_cygnus_ld.sh` | Full Cygnus LD feasibility (linking, alignment, scripts, relaxation) |
| `test_alignment_fix.sh` | COFF alignment patching attempts |
| `test_cygnus_binary.sh` | Cygnus LD `-oformat binary` test |
| `patch_coff_align.py` | COFF header analysis tool |

Run via WSL: `MSYS_NO_PATHCONV=1 wsl -d Ubuntu -- bash <script>`
