# Function Name Audit — Call Graph Evidence

Reviewed all named functions from 18 call graph scenarios against L3 assembly source.
Each investigation started assuming the name was wrong.

**Round 1**: Agents read L3 files with our annotations — found 2 wrong names, declared
~45 correct. **Round 2**: Spot-checked "correct" names by reading raw instructions,
ignoring our annotations. Found 6 more wrong/misleading names. Initial audit was too
trusting of our own comments.

---

## WRONG — Name does not match behavior

### hud_element_draw (0x06010B54)
**Actually does**: Dispatches HUD sound effects via `FUN_0601D5F4`. Two paths based
on hud_active_flag: plays 0xAB110AFF or 0xAB110BFF, or indexes a table for car-specific
sound. Zero drawing code — no VDP writes, no sprite commands, no coordinates.
**Rename to**: `FUN_06010B54` or `hud_sfx_dispatch`
**Evidence**: Only external call is `jsr FUN_0601D5F4`. No visual output.
**Confidence**: DEFINITE — verified by reading full function, only 55 instructions.

### transform_matrix (0x06026E94)
**Actually does**: X-axis rotation (YZ plane). Calls sincos, applies 2x2 rotation to
matrix columns 1,2. Identical pattern to `FUN_06026EDE` (Y rotation) and `FUN_06026F2A` (Z rotation).
**Rename to**: `FUN_06026E94`
**Evidence**: Same structure as FUN_06026EDE/FUN_06026F2A. Uses r5=#0x8 offset to sincos (X param).
Naming inconsistency — the other two follow `mat_rot_<axis>` convention.
**Confidence**: DEFINITE — code is 38 instructions, trivially verifiable.

### ai_section_transition (0x06033BC8)
**Actually does**: SMPC double-read for CD Block status registers (CR1-CR4 at
0x25890018-0x25890024). Disables interrupts (IMASK=0xF), reads registers twice,
compares for consistency, retries up to 100 times on mismatch. Validates response
byte against 0xFF and bit 0x20. Returns 0 (success) or -8 (error).
**Rename to**: `FUN_060349C4` or `smpc_cd_status_read`
**Evidence**: Reads hardware registers 0x25890018/1C/20/24 (SH7034 CD Block CR1-CR4).
Does interrupt-masked double-read for consistency. Nothing AI-related.
**Confidence**: HIGH — hardware register addresses are definitive.

### ai_section_update (0x06035E5E)
**Actually does**: The inner double-read helper for ai_section_transition. Saves IMASK,
sets IMASK=0xF (disable interrupts), reads CD registers to buffer AND stack, restores
IMASK. Compares both reads for consistency.
**Rename to**: `FUN_06034A10` or `cd_regs_double_read`
**Evidence**: Same CD Block register addresses. Part of the same misnamed family.
**Confidence**: HIGH — same hardware evidence as ai_section_transition.

### FUN_0603A0B0 (0x06035E06, inside FUN_0603990E.s)
**Actually does**: Button bit decoder + render mode dispatcher. ~800 lines but operates
on individual render table entries. Reads display mode byte, dispatches to 4 modes
(0x00/0x10/0x20/0xFF) for VRAM writes. Tests button bits (0x80, 0x40, 0x20, etc.)
and clears/sets flags in render table entries.
**Rename to**: `render_entry_decode` or `FUN_0603B058`
**Evidence**: Lives inside FUN_0603990E.s. Called 2x/frame. Operates on individual
entries, not the whole game state. Not "main" anything.
**Confidence**: HIGH — code structure is clear from raw instructions.

### FUN_06011DC0 (0x06011DC0)
**Actually does**: VDP1 sprite command builder loop. Iterates sprite table, calls
normal builder (sym_060280F8) or distorted builder (sym_060280C4) per entry based on
animation flag. Advances VDP1 write pointer by 32 bytes per sprite. Resets sprite
count to 0 at end.
**Rename to**: `vdp1_sprite_build_loop` or `sprite_cmd_builder`
**Evidence**: Calls two VDP1 command builders. Advances write pointer by VDP1 command
size (32 bytes). The "cleanup" is just resetting the count — 1 instruction out of ~50.
**Confidence**: HIGH — opcode analysis confirms building, not cleanup.

---

## MISLEADING — Name is partially right but gives wrong impression

### FUN_06011B08 (0x06011978+)
**Actually does**: Generic rotated-quad writer with **variable** half-extents (cx/cy from
caller). Reads no damage state whatsoever. Computes 4-corner rotation via sincos_pair +
FUN_06027552, writes to shared HUD record array at sym_060786CC.
**Better name**: `hud_quad_rotated_variable`
**Evidence**: No damage-related globals read. Takes arbitrary dimensions from caller.
Paired with FUN_060116BC which does the same thing but with hardcoded 56x30 size.
**Confidence**: HIGH — function reads no damage state, purely geometric.

### FUN_060116BC (0x06011A2E+)
**Actually does**: Rotated-quad writer with **hardcoded** 56x30 pixel dimensions. Same
mechanism as FUN_06011B08 but fixed-size. Not a "main draw" orchestrator — it's
one specific HUD element template. Only appears in car/circuit states.
**Better name**: `hud_quad_rotated_56x30`
**Evidence**: Hardcoded 0xFFC80000 (-56) and 0x001E0000 (+30). Doesn't call other HUD
functions. Called BY higher-level HUD renderers, not the orchestrator.
**Confidence**: HIGH — hardcoded dimensions are undeniable.

### FUN_0602843A (0x06028430+)
**Actually does**: Tile-map pixel compositor with color bias. Reads a template from
sym_06063690 (source ptr, color_bias, tile_width, row_count, tile_stride, tiles_per_row,
VRAM_row_skip). Reads tile indices from a map, multiplies by stride, copies pixels with
color bias added to each word.
**Better name**: `vram_tile_composite` or `vram_overlay_tinted`
**Evidence**: Three-loop structure (rows → tiles → pixels). Color bias added per pixel.
Not a simple brightness fade — it's tile-indexed compositing.
**Confidence**: MEDIUM-HIGH — mechanism is clear but "fade" may describe intended use.

### FUN_06018EAC (0x06018EAC)
**Actually does**: Thin wrapper around ai_section_transition. Calls it to fill a 12-byte
buffer, reads first byte, masks to 5 bits (& 0x1F), returns masked value. Does NOT
directly read CD hardware.
**Better name**: `cd_status_masked` or just fold into per_frame_update
**Evidence**: One JSR + one AND + one RTS. All the real work is in ai_section_transition.
The "cdb_" prefix implies direct CD Block access, which this function doesn't do.
**Confidence**: MEDIUM — the chain DOES ultimately read CD status, name isn't wildly wrong.

### FUN_0603A01C (inside FUN_0603990E.s)
**Actually does**: Animation frame data transfer. Calls FUN_0603AA82 first, then
copies byte-by-byte from source to destination with special-case handling for space
character (0x20). Not a generic "data table copy."
**Better name**: `anim_data_transfer` or `menu_frame_copy`
**Evidence**: Calls FUN_0603AA82 before copying. Special-cases 0x20. The "table"
in the name is vague — it's specifically animation frame data.
**Confidence**: MEDIUM — it does copy from a table, just not generically.

### FUN_0601BDEC (attract-only)
**Actually does**: Playback frame synchronizer. Advances frame counter by 33, compares
scroll accumulator vs car heading, adjusts sub-index ±2 based on whether playback is
ahead or behind. Wraps counters at 80 and 160. Calls geometry_transform with car speed.
**Better name**: `replay_frame_sync` or `playback_state_tracker`
**Evidence**: No replay data decoding. Just counter management and sync logic. "Engine"
dramatically overstates the scope (~30 instructions).
**Confidence**: MEDIUM — it IS part of replay playback, just not an "engine."

---

## CORRECT — Name matches behavior (verified)

| Function | Evidence |
|----------|----------|
| FUN_060072E6 | FRT OCRA interrupt handler, increments tick counter, clears flags, RTE |
| FUN_06007268 | VBlank-OUT handler, adaptive frame timing, FBCR swap |
| button_input_read | Reads input state word, dispatches to scene/DMA handlers |
| FUN_0603990E | Render state machine, SMPC polling, display list iteration |
| FUN_0603AA82 | Mode-switched animation buffer filler (7 display modes) |
| FUN_06039808 | SMPC buffer manager, polling, 5-way circular buffer swap |
| FUN_060103B8 | Handles brake input (0x8000/0x4000 bits), DMAs brake tiles |
| mode_select_handler | D-pad UP/DOWN + B button handler for mode select menu |
| FUN_06008B34 | Calls FUN_060196A4/draw/display per frame |
| FUN_060197F4 | Confirm button → set game state, load display list |
| FUN_06008D74 | Title screen handler: attract countdown, button check |
| FUN_0601D3C0 | Render init for mode select: button combos, DMA setup |
| per_frame_update | CD status polling, frame sync state machine, reset combo check |
| FUN_060389A6 | Top-level scene data orchestrator, flag-dispatched copy |
| FUN_060388C0 | Publishes scene state to render pipeline working buffers |
| dma_transfer | SCU DMA level 0 transfer with busy-wait |
| FUN_06038AC8 | VDP2 channel dispatcher (6 channels via bitmask) |
| FUN_0603C728 | Extended HUD state machine (interpolate, animate, palette fade) |
| FUN_06027552 | 16.16 fixed-point multiply via dmuls.l + xtrct |
| memcpy_long_idx | Forward longword copy with indexed addressing |
| memcpy_word_idx | Forward word copy with indexed addressing |
| render_cs0_loop | Course Scenery 0 object iteration + transform pipeline |
| FUN_0600AA98 | Hierarchical scene objects with additive (push) matrix transforms |
| FUN_06026EDE | Y-axis rotation (XZ plane columns) |
| FUN_06026F2A | Z-axis rotation (XY plane columns) |
| FUN_0600C010 | Primary SH-2 render orchestrator, triggers secondary SH-2 |
| FUN_0600F424 | Main per-frame state machine dispatcher |
| FUN_0600FB78 | Results screen transition (car stats, names) |
| FUN_0600F794 | State transition handler (anim + course HUD) |
| FUN_06011310 | Race position indicator (1st/2nd/3rd) sprites |
| FUN_06011094 | Course name HUD renderer (sprite commands) |
| FUN_0600FFD0 | Per-frame race HUD controller (sprite anims) |
| FUN_060114B8 | HUD layer position interpolation + sprite render |
| FUN_0601198C | Pre-computed 4-corner coordinate writer for HUD quads |
| FUN_06008E48 | Pre-race state handler (init → FUN_0600F424) |
| swap_sign_ext | 16.16 fixed-point → int16 extraction (swap.w + exts) |
| FUN_06010BC4 | 3D render pipeline config for race mode |
| FUN_0603853C | Sets scene buffers to absolute values by mode |

## NOT FULLY VERIFIED (prologue only or not found in src/)

- sincos_pair — not found in reimpl/src/, used externally
- FUN_06007BCC — candidates are sym_060280F8 / sym_060280C4
- FUN_060078DC — likely FUN_060078DC
- FUN_0601D5F4 — found in sound_channel_dispatch.s (name is accurate)
- FUN_0601D9B0 — in same TU as FUN_0601D5F4
- FUN_06011AF4 — prologue only, cannot verify
- FUN_06011978 — prologue only, cannot verify
- FUN_060116A8 — prologue only, cannot verify
- FUN_060100A4 — prologue only, cannot verify
- FUN_06010AA4 — partially verified (teardown logic confirmed)
- circuit_confirm_handler (was speedometer_ctrl) — VERIFIED: circuit select confirm/back handler. Swapped C/B masks as RE_TEST #2 to prove understanding.
- steering_input_dispatch (was coord_grid_pack) — VERIFIED: writes LEFT/RIGHT masks to sym_06063F48/4A for downstream physics. Swapped masks as RE_TEST #3 to prove inverted steering. Also calls unverified display setup.

## Bad Inline Comments (name is right, comments are wrong)

### controller_input_update (0x06005198)
Lines 85-141 say "primary rect X1 word", "secondary rect coordinates", "decoded width1"
etc. These should say "held buttons (port 1)", "edge-triggered presses (port 1)",
"status byte (port 1)". The VERIFIED header at the top has the correct descriptions.
The comments were likely auto-generated by an annotation tool that guessed wrong about
the data format.

---

## Methodology Note

Round 1 agents read our L3 files (which include our annotations) and compared names
against our own comments — circular reasoning. Round 2 focused on raw instructions,
ignoring comments. The biggest catches (ai_section_transition, FUN_06011B08,
FUN_060116BC) were all functions whose annotations reinforced the wrong name.

Lesson: annotations written during initial naming can calcify wrong guesses. Always
cross-check names against raw opcode behavior, not against our own comments.
