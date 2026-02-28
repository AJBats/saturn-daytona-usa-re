# Data Annotation — Classification & Semantic Understanding

> **Status**: Active — Pool label rename COMPLETE. Depth annotation continues.
> **Created**: 2026-02-23
> **Updated**: 2026-02-27
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

### Confidence-Graded Naming

As you research what a pool value means, you'll arrive at a confidence level. That
confidence determines naming style. **A wrong semantic name is worse than a correct
mechanical name** — it actively misleads anyone who reads it later, including future
agents and human contributors. Mechanical names are boring but never wrong.

| Confidence | When to use | Label style | Inline comment style | Example |
|------------|-------------|-------------|---------------------|---------|
| **HIGH** | HW register map match, verified algorithm, cross-referenced with multiple sources | Semantic name | Full description | `.L_scu_dma_status` / `/* SCU DMA status register */` |
| **MEDIUM** | Reasonable inference from context, single source, plausible but unverified | Structural/typed name | Describe what you see, not what you think | `.L_fn_ptr_060284AE` / `/* function pointer (likely geom dispatch) */` |
| **LOW** | Unknown purpose, guessing, or value could mean multiple things | Mechanical name with value | State the raw facts only | `.L_pool_const_0x18` / `/* offset 0x18 into struct */` |

**How to gauge confidence:**

- **HIGH**: You looked up the value in a hardware register map and it matches exactly.
  Or you traced the code path and can prove what the value does (e.g., `0x00010000` used
  in a `dmuls.l` followed by `xtrct` → definitely 16.16 fixed-point 1.0). Multiple
  independent evidence sources agree.
- **MEDIUM**: The value looks like a struct field offset and the function name suggests
  a domain (e.g., `0x28` in a camera function → probably a camera struct field), but
  you haven't verified the struct layout. Or sawyer says it's X but you can't fully
  confirm from the L3 code alone.
- **LOW**: You're pattern-matching on vibes. The value could be an offset, a count, a
  flag, or something else entirely. You'd be guessing. Use the mechanical name.

**Naming patterns by type and confidence:**

| Value type | HIGH | MEDIUM | LOW |
|-----------|------|--------|-----|
| HW register (0x25XXXXXX) | `.L_vdp1_ptmr` | `.L_hw_reg_25D00010` | `.L_pool_const_25D00010` |
| Function pointer | `.L_ptr_sin_lookup` | `.L_fn_ptr_06026DBC` | `.L_pool_ptr_06026DBC` |
| Struct offset | `.L_car_velocity_y` | `.L_struct_offset_0x28` | `.L_pool_const_0x28` |
| Fixed-point constant | `.L_fp_one` | `.L_fp_const_00010000` | `.L_pool_const_00010000` |
| Bit mask | `.L_irq_enable_mask` | `.L_bitmask_0x80000000` | `.L_pool_const_80000000` |
| Unknown | — | — | `.L_pool_const_XXXXXXXX` |

**The rule: when in doubt, go one tier down.** You can always upgrade a mechanical
name later when you learn more. You can't easily undo a wrong semantic name that
other annotations have been built on top of.

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
   - Rename pool labels using confidence-graded naming (see above).
     Assess confidence for EACH label individually — a file can have a mix
     of HIGH, MEDIUM, and LOW confidence names. Don't force semantic names
     on values you don't understand just to make the file look "done."
   - Add file header with function catalog
   - Add function doc blocks
   - Add instruction-level comments (describe what you SEE, not what you
     THINK, unless confidence is HIGH)
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
2. **Pool data labels renamed** — all `.L_pool_` / `.L_wpool_` machine-address labels
   replaced with confidence-graded names. HIGH confidence → semantic names
   (`.L_sin_table_base`, `.L_scu_dsta`), MEDIUM → structural (`.L_fn_ptr_06026DBC`),
   LOW → mechanical (`.L_pool_const_0x18`). A file with all mechanical names is
   "done" — correctness beats aesthetics.
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

**Completed** (12 files depth-annotated):
- `reimpl/src/fpmul.s` — fpmul, fpdiv_setup, memcpy_byte_idx, memcpy_word_idx,
  memcpy_long_idx, dma_transfer. All pool labels renamed, function docs added.
  (Sawyer: `asm/math_helpers.s`)
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
- `reimpl/src/button_input_read.s` — 444 lines, 107 pool labels. Input dispatch
  including button mapping, channel events, system events. Full 32-bit input
  state word layout documented. Corrected 8 misclassified fp_ labels → evt_bit
  masks. (Sawyer: `asm/input_smpc.s`)
- `reimpl/src/smpc_response_handler.s` — Interrupt-disable wrapper for atomic
  SMPC reads. SR interrupt level save/restore pattern documented. 40 lines.
- `reimpl/src/smpc_peripheral_query.s` — CD HIRQ peripheral query with error
  code table (-1 through -6). All pool labels renamed.
- `reimpl/src/system_init.s` — 3-function boot TU: system_init (14-step Saturn
  boot sequence), sound_timer_init (SH-2 FRT configuration), vdp_init_dispatch
  (SCU interrupt vector installation for both CPUs). All pool labels renamed.
- `reimpl/src/palette_frame_effects.s` — Per-frame palette commit to VDP2 CRAM
  (5 palette groups with shadow buffer → CRAM mapping documented).
- `reimpl/src/framebuf_swap_ctrl.s` — FRT compare-match A interrupt handler.
  FTCSR flag clearing, frame tick counter, SCU interrupt control documented.
- `reimpl/src/vdp1_init.s` — VDP1 VRAM clear + framebuffer double-plane init.
  Fixed misclassified labels (fp_min→vdp1_end_cmd, fp_one→fb_clear_count).
  (Sawyer: `asm/vdp_hardware.s`)
- `reimpl/src/vdp2_course0_init.s` — Course 0 VDP2 VRAM/CRAM setup. Palette
  bank swap + 3 DMA transfers for tilemaps and character patterns.

**Priority roadmap** (user-directed):
1. ~~**Finish pool labels**~~ — DONE (2026-02-27). All `.L_pool_XXXXXXXX` / `.L_wpool_XXXXXXXX`
   definitions renamed across src/. Batches 134-151 (18 commits, ~200 files touched).
   Zero machine-generated pool label definitions remain.
2. **Classify data** — figure out what the literal values actually mean
3. **Unmask remaining retail files** — convert the 9 holdouts to L3 in src/
4. **Audit L3 completeness** — zero files in retail/ that aren't in src/

**Next annotation targets**:
- Sound/DMA TUs: sound_scsp_boot.s (SCSP init), dma_vram_init.s, sound_init_sequence.s
- More SMPC/input: smpc_cmd_builder.s, input_proc_*.s, input_event_handler.s
- Remaining VDP: vdp2_config_extended.s, display_mode_init.s, vdp1_cmd_list_reset.s
- Large high-value: master_menu_render.s (3,209 lines, 142 pools)
- Top data-heavy TUs: gameover_channel_setup (1431 literals), obj_render_setup (675)

### Phase 2b: Automated Pool Classification — DONE

Built `tools/classify_pool.py` with Saturn hardware register maps (VDP1, VDP2, SCU,
SMPC, SCSP, SH-2 peripherals), fixed-point patterns, and memory range heuristics.
Applied 1,017 MEDIUM+ confidence renames across 153 files. Covers 97% of all pool
labels (3,225/3,327 classified). 3-class validation passed. Committed as `feeabd2`.

**Second pass** (2026-02-24): Re-ran with complete pool sweep. Applied 650 additional
renames across 247 files: 324 HW registers, 236 fixed-point, 77 bit masks, 13 memory
regions. Total automated: **1,667 renames**. Committed as `965981c`.

**Known limitation**: Context-free classification can misidentify fixed-point constants
as bit masks (and vice versa). Example: 0x00010000 classified as `fp_one` (16.16 1.0)
but in button_input_read.s it's actually `evt_bit16` (event flag mask). These require
hand-correction during depth annotation.

### Phase 3: L2 Holdout Conversion — MOSTLY DONE

5 cross-TU pool holdouts converted to L3 with mnemonics (cross-TU `mov.l @(disp,PC)`
kept as raw `.byte` pairs): mat_scale_b, mat_scale_columns, bulk_struct_init,
hud_post_update, vdp2_loop_ctrl. Committed as `57dabe1`.

**Remaining retail-only files** (3):
- `_start.s` — converted to L3 in src/ (fully annotated main game loop), committed `ffe16ae`
- `cdb_wait_scdq.s` — overridden by `src/cdb_wait_scdq.c` (C reimpl)
- `binary_final_func.s` (1.3MB) — monolithic data+code blob, long-term extraction
- `palette_render_main.s` (192KB) — palette data tables + code, converted to L3 (16KB mixed TU)

**Effective holdout count**: 1 real file needs L3 extraction (binary_final_func).
palette_render_main was converted to L3 as commit `0c76ba2`.

### Phase 4: Semantic Enrichment — PENDING

### Phase 5: Cross-TU Fragment Resolution — PENDING

---

## Sawyer Cross-Reference Map

These sawyer annotation files have been audited and are usable as starting points.
Match by address range, not by filename.

| Sawyer File | Confidence | Address Range | L3 TU(s) |
|------------|------------|---------------|-----------|
| `asm/math_helpers.s` | HIGH/DEFINITE | 0x06027344-0x0602769C | `fpmul.s`, `sprite_anim_update.s` |
| `asm/input_smpc.s` | DEFINITE | (multiple) | `button_input_read.s`, `smpc_*.s`, `input_proc_*.s` |
| `asm/game_loop.s` | DEFINITE | 0x0600307C+ | game loop TUs |
| `asm/math_transform.s` | HIGH | 0x06026DBC-0x06027340 | `sprite_anim_update.s` |
| `asm/race_states.s` | (unchecked) | 0x06033xxx+ | `game_update_loop.s` |
| `asm/display_elements.s` | (unchecked) | 0x06033xxx+ | `game_update_loop.s` |
| `asm/vdp_hardware.s` | HIGH | 0x0600A140+ | `vdp1_init.s`, VDP register TUs |
| `asm/vdp_scene_rendering.s` | MEDIUM | 0x0602D89A+ | 72 VDP1 command builder TUs |
| `asm/vblank_system.s` | DEFINITE | 0x06006F3C+ | `framebuf_swap_ctrl.s`, vblank TUs |
| `asm/render_pipeline.s` | MEDIUM-HIGH | 0x0602382C+ | render/scene TUs |

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
*Last updated: 2026-02-24 — Phase 2b expanded (1,667 total auto-renames). 12 files depth-annotated (fpmul, cdb, sprite_anim, game_update_loop, 3 input/SMPC, system_init, 4 VDP/display). Phase 3 mostly done (5/7 holdouts converted). Remaining: 2 large data holdouts + continued manual annotation.*
