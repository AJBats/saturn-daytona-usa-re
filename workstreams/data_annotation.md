# Data Annotation — Classification & Semantic Understanding

> **Status**: Active — Phase 0 (Decoder Completion) in progress.
> **Created**: 2026-02-23
> **Predecessor**: Sawyer L2 (L3 uplift at 98% — 448/457 files)

## The Problem

L3 uplift converted 98% of functions from `.byte` blobs to SH-2 mnemonics. But two
problems remain:

1. **9 holdout files** can't auto-convert because data tables confuse the code/data
   classifier (it tries to decode data bytes as instructions, producing invalid opcodes).

2. **~4,500 data entries** across 203 L3 files are emitted as raw `.word`/`.4byte`
   literals with `/* UNKNOWN */` comments or no semantic annotation. Understanding
   this data is prerequisite for L4 (C reimplementation).

### Holdout Categories

| Category | Files | Why |
|----------|-------|-----|
| Entry point | `_start` (1) | Special — not a regular function |
| Data tables | `fixpt_div_full`, `palette_render_main`, `binary_final_func` (3) | Large inline data tables misclassified as code |
| Cross-TU pools | `bulk_struct_init`, `hud_post_update`, `vdp2_loop_ctrl`, `mat_scale_b`, `mat_scale_columns` (5) | `mov.l @(disp,PC)` reaches into adjacent function's pool |

## Plan

### Phase 0: Decoder Completion (Quick Win)

The `/* UNKNOWN */` entries break down as:

| Pattern | Count | % | Root Cause |
|---------|-------|---|------------|
| `0x0000` zero padding | ~4,150 | 92% | Data regions, not instructions — correct behavior |
| Missing SH-2 opcodes | ~250 | 6% | `movt`, `mova`, `stc`, `trapa` not in decoder |
| Exotic values (0xFFxx etc.) | ~90 | 2% | Data bytes decoded as code — holdout class |

**Action**: Add missing opcodes to `tools/sh2_decode.py`, regenerate all L3 files.
Zero-padding UNKNOWNs in data regions are expected and stay as-is.

**Files**: `tools/sh2_decode.py`, then regenerate `reimpl/src/*.s`
**Gate**: 3-class validation passes; zero UNKNOWN entries that are real SH-2 instructions

### Phase 1: Metadata Infrastructure

Create `reimpl/meta/<tu_name>.yaml` files as annotation overlays. The generator reads
these and emits inline comments in L3 output. Annotations survive regeneration because
they live in metadata, not in the generated files.

**Key decision**: Generator reads metadata → emits comments. Hand-editing L3 files
is forbidden (they're regenerated). Metadata is the source of truth for annotations.

**New files**:
- `reimpl/meta/` directory with YAML schema
- `tools/data_audit.py` — coverage dashboard (total unknowns, annotated %, top files)

### Phase 2: Automated Classification

Build `tools/classify_data.py` — scans L3 files and produces initial YAML metadata
with automated guesses based on heuristics:

| Pattern | Classification | Confidence |
|---------|---------------|------------|
| Run of `.word 0x0000` | BSS buffer (zeroed at runtime) | High |
| `.4byte 0x25XXXXXX` | VDP1/VDP2 VRAM address | High |
| `.4byte 0x25EXXXXX` / `0x25FXXXXX` | Hardware register address | High |
| ASCII byte sequences | String data | High |
| Monotonic 32-bit values | Cumulative lookup table | Medium |
| Repeated N-byte stride | Struct array (compute stride) | Medium |

Cross-reference with `asm/*.s` Sawyer annotations — extract `!` comments for matching addresses.

**Gate**: Every data region has at minimum: type, size, confidence score

### Phase 3: L2 Holdout Conversion

**3A: fixpt_div_full** (847 lines, 3 functions) — most tractable. Clear code/data
boundaries. Math lookup tables (reciprocal, trig). Enhance generator to accept
"force data" address ranges from metadata.

**3B: palette_render_main** (8,745 lines) — palette config, disc filenames ("GAME1.BIN"
etc), index arrays, VDP2 register addresses. Mixed code + data.

**3C: binary_final_func** (59,768 lines) — the monolith. 116K, 1,196 globals.
Iterative extraction: identify code islands, classify data between them, split into
sub-files. This shrinks over time, not in one pass.

**Gate**: Each holdout either fully L3'd or split into L3 sub-units. 3-class validation.

### Phase 4: Semantic Enrichment

Add game-domain meaning to classified data. Build `tools/xref_data.py` — for each
data region, find all functions that reference it. Use function names + asm annotations
to infer meaning. Priority: data tables referenced by the most functions first.

Examples of target annotations:
- "force_profile: 64 keyframes at 12 bytes (speed, steering, forces)"
- "course_segment_table: array of 0x44-byte track segment descriptors"

**Gate**: Top 20 data-heavy files have semantic annotations

### Phase 5: Cross-TU Fragment Resolution

Absorb the 5 cross-TU fragment functions into their parent TUs:
- `bulk_struct_init` → player_vehicle_interp TU
- `hud_post_update` → adjacent TU
- `vdp2_loop_ctrl` → adjacent TU
- `mat_scale_b`, `mat_scale_columns` → adjacent math TU

Expand parent TU boundary, regenerate, delete fragment. Mechanical work.

**Gate**: Zero standalone L2 files (except `_start`). 3-class validation.

### Sequencing

```
Phase 0 (decoder fix)  →  Phase 1 (metadata infra)  →  Phase 2 (auto-classify)
                                    │                           │
                                    ├→  Phase 3 (holdouts)  ────┤
                                    │                           │
                                    └→  Phase 5 (fragments)  →  │
                                                                │
                                                         Phase 4 (semantic)
```

## Definition of Done

- Zero UNKNOWN entries that are real SH-2 instructions (data UNKNOWNs are fine)
- Every data region has metadata classification (type + size)
- All 3 holdouts converted to L3 or split into L3 sub-units
- All 5 cross-TU fragments absorbed
- Top 20 data-heavy files have semantic annotations
- Coverage dashboard maintained
- 3-class validation passes at every commit

"Done" does NOT mean every literal has a comment or full struct definitions — that's L4 work.

## Resources

| What | Where |
|------|-------|
| SH-2 decoder | `tools/sh2_decode.py` |
| L3 generator | `tools/generate_l3_tu.py` |
| Batch L3 tool | `tools/batch_l3_modules.py` |
| L3 source files | `reimpl/src/*.s` |
| Retail ASM (L2) | `reimpl/retail/*.s` |
| Sawyer annotations | `asm/*.s` (human `!` comments) |
| Metadata (future) | `reimpl/meta/*.yaml` |
| Coverage dashboard (future) | `tools/data_audit.py` |

---
*Created: 2026-02-23*
