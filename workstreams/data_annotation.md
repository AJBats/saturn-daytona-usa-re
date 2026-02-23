# Data Annotation — Classification & Semantic Understanding

> **Status**: Active — Direct annotation in progress (depth-first, DEFINITE TUs first).
> **Created**: 2026-02-23
> **Predecessor**: Sawyer L2 (L3 uplift at 98% — 448/457 files)

## The Goal

This project is approaching its close. We want to share it with the community, and
the value isn't "we can link the binary" — it's **"we understood it."** Every annotated
constant, every named label, every function doc comment is proof of understanding. The
annotation workstream turns mechanical L3 output into a documented, readable codebase
that demonstrates real reverse engineering.

## The Problem

L3 uplift converted 98% of functions from `.byte` blobs to SH-2 mnemonics. But two
problems remain:

1. **9 holdout files** can't auto-convert because data tables confuse the code/data
   classifier (it tries to decode data bytes as instructions, producing invalid opcodes).

2. **~11,500 literal data entries** across L3 files are emitted as raw `.4byte`/`.2byte`
   values with no semantic annotation. Understanding this data is prerequisite for L4
   (C reimplementation) and for community readability.

### Holdout Categories

| Category | Files | Why |
|----------|-------|-----|
| Entry point | `_start` (1) | Special — not a regular function |
| Data tables | `fixpt_div_full`, `palette_render_main`, `binary_final_func` (3) | Large inline data tables misclassified as code |
| Cross-TU pools | `bulk_struct_init`, `hud_post_update`, `vdp2_loop_ctrl`, `mat_scale_b`, `mat_scale_columns` (5) | `mov.l @(disp,PC)` reaches into adjacent function's pool |

### Data Entry Breakdown (from `tools/data_audit.py`)

| Category | Count | Notes |
|----------|-------|-------|
| Symbol references | 6,938 | Already named (`.4byte sym_XXXXXXXX`) |
| Literal values | 11,565 | Need annotation |
| UNKNOWN words | 4,495 | Zero-padding + holdout data |
| **Total** | **22,998** | |

---

## Annotation Workflow

This is the core methodology. If this chat is lost, a fresh agent should follow these
steps to continue the work.

### Philosophy: The Crossword Puzzle

Start with easy/definitive annotations, work toward harder ones. Each annotated
function provides context that makes adjacent functions easier to understand. Like a
crossword puzzle — the easy words give you letters for the hard ones.

**Priority order**:
1. DEFINITE-confidence sawyer TUs (math, input, game loop)
2. Hardware register pool entries (verifiable from Saturn memory map)
3. Fixed-point constants (pattern-recognizable: 0x00010000 = 1.0, etc.)
4. Game-domain data (struct arrays, lookup tables — need cross-reference)

### Annotation Style (Option A: Full Depth)

We chose **hand-picked meaningful names** for every pool label and inline comment.
This is slow but represents the real RE work. The goal is to dazzle, not just link.

**What gets annotated in each file**:
1. **File header** — TU address range, function catalog with one-line descriptions
2. **Pool labels** — rename `.L_pool_XXXXXXXX` / `.L_wpool_XXXXXXXX` to meaningful
   names like `.L_sin_table_base`, `.L_scu_dsta`, `.L_divu_base`
3. **Function documentation** — block comment before each function with signature,
   algorithm description, and calling convention notes
4. **Instruction comments** — end-of-line `/* */` comments on non-obvious instructions
5. **Data region comments** — explain what literal values mean (hardware registers,
   fixed-point constants, masks, etc.)

### Step-by-Step Process (Per TU)

```
1. IDENTIFY TARGET
   - Pick a TU from the priority list (DEFINITE confidence first)
   - Run: python tools/data_audit.py --detail <tu_name>
   - Note literal count, categories, uncommented entries

2. READ SAWYER ANNOTATION (if exists)
   - Find matching asm/*.s file by address range overlap
   - Read the sawyer ! comments for function names, confidence levels,
     algorithm descriptions
   - IMPORTANT: Sawyer annotations are GUESSES with gaps and inconsistencies.
     Use them as starting points, not conclusions. Revalidate against the
     actual L3 code.

3. CROSS-REFERENCE
   - Match sawyer addresses to L3 label addresses
   - Verify instruction patterns match sawyer's description
   - Check pool constants against Saturn hardware reference (platform-saturn-sh2 skill)
   - For 0x25XXXXXX values: look up in SCU/VDP/SCSP register maps
   - For 0x00XXXXXX small values: check if 16.16 fixed-point (0x00010000 = 1.0)
   - For 0xFFFFXXXX values: check if sign-extended negative or SH-2 peripheral

4. ANNOTATE THE L3 FILE (direct edit — no YAML intermediary)
   - Rename pool labels to meaningful names
   - Add file header with function catalog
   - Add function doc blocks
   - Add instruction-level comments
   - Keep raw .4byte data blobs (missed code regions) unchanged for now

5. VERIFY ASSEMBLY
   - Build: echo 'make -C /mnt/d/Projects/SaturnReverseTest/reimpl' | wsl -d Ubuntu -- bash
   - Any assembly error means a label was misspelled or syntax broken — fix immediately

6. BATCH AND VALIDATE
   - After annotating several files, run full validation:
     python tools/validate_build.py
   - All 3 classes must pass (retail match, free boot, free+4 boot)
   - Commit the batch
```

### Example: Annotated Pool Label

Before:
```asm
.L_pool_0602768C:
    .4byte  0x25FE007C
```

After:
```asm
.L_scu_dsta:
    .4byte  0x25FE007C          /* SCU DSTA — DMA status register */
```

### Example: Function Documentation

```asm
    .global fpmul
    .type fpmul, @function
/* fpmul(r4=a, r5=b) -> r0 = (a * b) >> 16
 * 16.16 fixed-point multiply using 32x32->64 hardware multiplier.
 * xtrct extracts middle 32 bits of MACH:MACL = (a*b) >> 16.
 */
fpmul:
    dmuls.l r4, r5              /* signed 32x32->64 multiply */
    sts mach, r4                /* r4 = high 32 bits */
    sts macl, r0                /* r0 = low 32 bits */
    rts
    xtrct r4, r0                /* r0 = (r4<<16)|(r0>>16) = middle 32 bits */
```

### Annotation Standard — "When Is a File Done?"

A file is **annotation-complete** when:

1. **File header** — function catalog with one-line descriptions
2. **Pool data labels renamed** — all `.L_pool_` / `.L_wpool_` entries have semantic names
   (`.L_sin_table_base`, `.L_scu_dsta`, `.L_vdp1_ptmr`, `.L_car_stride`, etc.)
3. **Function doc comments** — block comment on every non-trivial function (name, args, algorithm)
4. **Hardware addresses commented** — inline `/* VDP1 PTMR */` on every pool 0x25XXXXXX entry
5. **Instruction comments** — end-of-line on non-obvious lines (the ones where you'd go "why?")

**Explicitly NOT required** (these stay machine-generated and that's fine):

- `.L_XXXXXXXX` branch targets — these are code flow labels, not data. Renaming them
  would require understanding every branch destination, for zero readability gain.
- `.L_sym_XXXXXXXX` pool references — these just hold the address of a global. The global
  itself may get renamed later (Phase 4), but the pool entry inherits that name automatically.
- `sym_XXXXXXXX` globals — progressive renaming via PROVIDE aliases in free.ld. These get
  renamed as understanding grows, but not blocking "done" status.
- 100% instruction coverage — some instructions are self-documenting (`mov r4, r8`).

This standard matches what mature decomps (SM64, OoT) look like: functions named, data
classified, but not every label hand-named. Machine names for branch targets and sub-labels
are normal and expected.

### Key Gotchas

- **Sawyer has errors**: The asm/*.s files have inconsistencies, weird gaps, and some
  outright fabrications. Always verify against the actual L3 code and binary.
- **Missed code**: Many "data-heavy" TU files contain SH-2 instructions the flow
  analysis couldn't reach (functions without global labels). These appear as runs of
  `.4byte` values that decode to valid instructions. Don't annotate these as data —
  they're code waiting to be decoded. Leave them for Phase 3.
- **Pool label syntax**: `.L_` prefix is required by GNU as for local labels. They
  don't appear in the symbol table and won't conflict with globals.
- **Word pool labels**: `.L_wpool_XXXXXXXX` are for `.2byte` entries referenced by
  `mov.w @(disp,PC)`. Rename these too (e.g., `.L_cos_phase_offset`).
- **BSR/BRA in L3**: sh-elf-as cannot generate 12-bit PC-relative relocations for
  external symbols. These stay as `.byte` pairs. Don't try to convert them.
- **No regeneration expected**: We annotate L3 files directly. The generator is unlikely
  to be re-run on already-converted files. If it is, annotations would be lost — but
  that's a known tradeoff we accepted over YAML complexity.

---

## Phase Status

### Phase 0: Decoder Completion — DONE

Added 20+ missing opcodes to `tools/sh2_decode.py` (movt, mova, trapa, stc, ldc,
clrmac, mac.w, tas.b, bsrf, braf, etc.). Regenerated all 448 L3 files with improved
pool labels (content-based naming via `_make_pool_label()`). 3-class validation passed.
Committed as `5ca2585`.

### Phase 1: Metadata Infrastructure — SKIPPED

Decided to annotate L3 files directly instead of building YAML metadata infrastructure.
Regeneration is unlikely, and the YAML plumbing adds complexity without proportional
value at this stage.

### Phase 2: Direct Annotation — IN PROGRESS

Annotating L3 files by hand, depth-first on high-value TUs.

**Completed**:
- `reimpl/src/fpmul.s` — fpmul, fpdiv_setup, memcpy_byte_idx, memcpy_word_idx,
  memcpy_long_idx, dma_transfer. All pool labels renamed, function docs added.
- `reimpl/src/cdb_read_status.s` — cdb_read_status, scsp_set_master_volume.
  All pool labels renamed, function docs added.
- `reimpl/src/sprite_anim_update.s` — **MAJOR** (1900+ lines, 30+ functions).
  Full 3D matrix pipeline (stacks A+B), trig/math library, sprite animation.
  All pool labels renamed to semantic names (.L_sin_table_base, .L_fp_one, etc).
  9 data symbols renamed (mat_stack_ptr_a/b, mat_temp_a/b, etc) with PROVIDE
  aliases in free.ld. Function docs + instruction comments throughout.
  (Sawyer: `asm/math_helpers.s`, `asm/math_transform.s`)
- `reimpl/src/game_update_loop.s` — 3000+ lines, 100+ functions. Camera init,
  display thunk dispatch (38 thunks), physics velocity integration pipeline,
  full AI subsystem (velocity integration, pathfinding, collision, drafting,
  brake zones, throttle control), ranking/checkpoint system. File header with
  full function catalog + car data struct layout. Key physics/AI functions
  documented with algorithm descriptions.
  (Sawyer: `asm/game_loop.s`, `asm/race_states.s`, `asm/display_elements.s`)

**Priority roadmap** (user-directed):
1. **Finish pool labels** — rename all `.L_pool_`/`.L_wpool_` across remaining src/ files
2. **Classify data** — figure out what the literal values actually mean
3. **Unmask remaining retail files** — convert the 9 holdouts to L3 in src/
4. **Audit L3 completeness** — zero files in retail/ that aren't in src/

**Next annotation targets** (DEFINITE confidence from sawyer):
- Input / SMPC TUs (Sawyer: `asm/input_smpc.s` — DEFINITE)
- Hardware register pool entries (verifiable from Saturn memory map)
- Top data-heavy TUs: gameover_channel_setup (1431 literals), obj_render_setup (675)

### Phase 3: L2 Holdout Conversion — PENDING

### Phase 4: Semantic Enrichment — PENDING

### Phase 5: Cross-TU Fragment Resolution — PENDING

---

## Sawyer Cross-Reference Map

These sawyer annotation files have been audited and are usable as starting points.
Match by address range, not by filename.

| Sawyer File | Confidence | Address Range | L3 TU(s) |
|------------|------------|---------------|-----------|
| `asm/math_helpers.s` | HIGH/DEFINITE | 0x06027344-0x0602769C | `fpmul.s`, `sprite_anim_update.s` |
| `asm/input_smpc.s` | DEFINITE | (multiple) | input-related TUs |
| `asm/game_loop.s` | DEFINITE | 0x0600307C+ | game loop TUs |
| `asm/math_transform.s` | HIGH | 0x06026DBC-0x06027340 | `sprite_anim_update.s` |
| `asm/race_states.s` | (unchecked) | 0x06033xxx+ | `game_update_loop.s` |
| `asm/display_elements.s` | (unchecked) | 0x06033xxx+ | `game_update_loop.s` |

More sawyer files exist but haven't been audited yet. Check `asm/` directory for
files with `! AUDIT:` headers — those have confidence ratings.

---

## Resources

| What | Where |
|------|-------|
| SH-2 decoder | `tools/sh2_decode.py` |
| L3 generator | `tools/generate_l3_tu.py` |
| Data audit tool | `tools/data_audit.py` |
| Batch L3 tool | `tools/batch_l3_modules.py` |
| L3 source files | `reimpl/src/*.s` |
| Retail ASM (L2) | `reimpl/retail/*.s` |
| Sawyer annotations | `asm/*.s` (human `!` comments) |
| Saturn HW reference | `.claude/skills/platform-saturn-sh2/` |
| Validation | `python tools/validate_build.py` |

---
*Created: 2026-02-23*
*Last updated: 2026-02-23 — Phase 2 in progress: 4 TUs annotated (fpmul, cdb_read_status, sprite_anim_update, game_update_loop)*
