# Complete Function Map: 0x06034000-0x06037FFF

## Overview

| Metric | Value |
|--------|-------|
| Total functions (aprog_syms.txt) | 160 |
| Embedded sub-functions (no symbol) | ~12 |
| Already documented in asm/ files | 25 |
| Newly mapped | 135 |
| Range start | 0x06034036 |
| Range end | 0x0603806C (FUN_06037660 end) |
| Total bytes | ~16,438 |

### Source Files Referenced

Existing documentation checked:
- `asm/ai_opponents.s` -- AI opponent system (0x06034E58-0x060359E4)
- `asm/track_geometry.s` -- Terrain collision mesh (0x0603449C-0x06034B9A)
- `asm/collision.s` -- Collision response (references FUN_06035168)
- `asm/event_queue.s` -- Event queue (references FUN_060349B6, FUN_06034C68, FUN_06034D1C, FUN_06036A1C, FUN_06036BE4, FUN_06035C4E, FUN_06035C54, FUN_06035228)
- `asm/force_tables.s` -- Force feedback (references FUN_06034F78)
- `asm/force_system.s` -- Force system (references FUN_06034F78)
- `asm/lap_counting.s` -- Lap counting (references FUN_06034F78, FUN_06035280)
- `asm/object_management.s` -- Object system (references FUN_06035340, FUN_06034900)
- `asm/player_physics.s` -- Player physics (references FUN_06034F78, FUN_06035228)
- `asm/race_orchestration.s` -- Race orchestration (references FUN_06034708)
- `asm/replay_camera.s` -- Replay camera (references FUN_060350B0)
- `asm/render_pipeline.s` -- VDP1 rendering (FUN_060370E4, FUN_06037660, FUN_06037618)
- `asm/vblank_system.s` -- VBlank system (references FUN_060349C4, FUN_06034A10, FUN_06035E5E, FUN_06036F0C, FUN_06036E90)
- `asm/vdp_hardware.s` -- VDP hardware (references FUN_06036E90, FUN_060370E4)

---

## CATEGORY 1: Physics Computation Pipeline (0x06034036-0x060343AE)

32 functions forming a decomposed physics update pipeline. These operate on a
game object structure addressed via r14 (base pointer). Fields are accessed at
fixed offsets loaded from literal pools (e.g., +0x04, +0x08, +0x0C, +0x14,
+0x18, +0x1C, +0x20).

The pattern repeats in groups of ~5:
1. A "trampoline" that does: sts.l pr,@-r15 / jsr @r0 / nop / lds.l @r15+,pr
   then performs dmuls.l (32-bit multiply), adds to a struct field, stores result
2. A sub-call to external math functions (0x06026DBC, 0x06026DF8, 0x06026E2E,
   0x06026EDE, 0x06027344, 0x06027348, 0x0602755C, 0x0600A4CA, 0x0600A5B2)
3. Tiny accessors that read/write struct fields

The whole group forms a single inlined physics computation chain -- probably
a Ghidra artifact from aggressive function boundary detection on fall-through code.

Data structures referenced:
- 0x06089EDC: pointer to object state table
- 0x06083238-0x06083244: intermediate computation buffer (physics scratch area)
- 0x060631B4, 0x060631B8: animation frame tables (byte arrays)

| # | Address | Size (B) | Type | Documented | Description |
|---|---------|----------|------|------------|-------------|
| 1 | FUN_06034036 | 36 | CALL | no | Physics chain entry: jsr @r0, dmuls.l r12*r11, store result to struct+0x04 via r14 |
| 2 | FUN_0603405A | 102 | CALL | no | Physics with branch: dmuls, cmp/eq #2, struct+0x24 field compare, 3 branch paths |
| 3 | FUN_060340C0 | 14 | CALL | no | Trampoline: jsr @r0, save result to r9, load pool addr 0x06027344 |
| 4 | FUN_060340CE | 14 | CALL | no | Trampoline: jsr @r0, save to r5, reload r9->r4, load 0x0602755C |
| 5 | FUN_060340DC | 66 | CALL | no | Physics: jsr @r0, dmuls, store to struct+0x08, bra 0x0603413E continuation |
| 6 | FUN_0603411E | 16 | CALL | no | Trampoline: jsr @r0, result to r4, loads 0x06083238+0x06083244+0x06027EDE |
| 7 | FUN_0603412E | 68 | CALL | no | Physics: jsr @r0, reads 0x0608323C, stores to struct+0x08, rts at 0x0603413E |
| 8 | FUN_06034172 | 26 | CALL | no | Physics chain: jsr @r0, load 0x06089EDC ptr, read struct+0x04/+0x08/+0x0C into r4/r5/r6, load 0x06026E2E |
| 9 | FUN_0603418C | 14 | CALL | no | Trampoline: jsr @r0, read struct+0x02 (word), load 0x06026EDE |
| 10 | FUN_0603419A | 14 | CALL | no | Trampoline: jsr @r0, read struct+0x11 (byte), load 0x0600A5B2 |
| 11 | FUN_060341A8 | 10 | CALL | no | Trampoline: jsr @r0, load 0x06026DF8 |
| 12 | FUN_060341B2 | 72 | CALL | no | Physics: jsr @r0, load 0x06089EDC ptr, bra 0x06034468 (shared epilogue) |
| 13 | FUN_060341FA | 26 | CALL | no | Physics chain: jsr @r0, load 0x06089EDC, read struct+0x04/+0x08/+0x0C, load 0x06026E2E |
| 14 | FUN_06034214 | 20 | CALL | no | Trampoline: jsr @r0, read struct+0x02 (word), add 0x8000, exts.w (sign-extend), load 0x06026EDE |
| 15 | FUN_06034228 | 14 | CALL | no | Trampoline: jsr @r0, read struct+0x11 (byte), load 0x0600A4CA |
| 16 | FUN_06034236 | 10 | CALL | no | Trampoline: jsr @r0, load 0x06026DF8 |
| 17 | FUN_06034240 | 70 | CALL | no | Physics: jsr @r0, dmuls, cmp/eq #2, two-path with dmuls chains |
| 18 | FUN_06034286 | 26 | CALL | no | Physics chain: jsr @r0, load 0x06089EDC, read struct fields, load 0x06026E2E |
| 19 | FUN_060342A0 | 14 | CALL | no | Trampoline: jsr @r0, read struct+0x02, load 0x06026EDE |
| 20 | FUN_060342AE | 14 | CALL | no | Trampoline: jsr @r0, read struct+0x11 (byte), load 0x0600A5B2 |
| 21 | FUN_060342BC | 10 | CALL | no | Trampoline: jsr @r0, load 0x06026DF8 |
| 22 | FUN_060342C6 | 72 | CALL | no | Physics: jsr @r0, load 0x06089EDC, bra 0x06034468 |
| 23 | FUN_0603430E | 26 | CALL | no | Physics chain: jsr @r0, load 0x06089EDC, read struct, load 0x06026E2E |
| 24 | FUN_06034328 | 14 | CALL | no | Trampoline: jsr @r0, read struct+0x02, load 0x06026EDE |
| 25 | FUN_06034336 | 14 | CALL | no | Trampoline: jsr @r0, read struct+0x11, load 0x0600A4CA |
| 26 | FUN_06034344 | 10 | CALL | no | Trampoline: jsr @r0, load 0x06026DF8 |
| 27 | FUN_0603434E | 24 | CALL | no | Physics chain: partial computation, falls through |
| 28 | FUN_06034366 | 34 | CALL | no | Physics with compare: jsr @r0, field compare, bra continuation |
| 29 | FUN_06034388 | 14 | CALL | no | Trampoline: jsr @r0, read struct field |
| 30 | FUN_06034396 | 14 | CALL | no | Trampoline: jsr @r0, read struct field |
| 31 | FUN_060343A4 | 10 | CALL | no | Trampoline: jsr @r0, load address constant |
| 32 | FUN_060343AE | 24 | CALL | no | Physics chain: end of repeating group |

**Gameplay relevance**: HIGH. This is core physics computation for game objects.
The external math functions called (0x06026xxx, 0x06027xxx) are 3D vector/matrix
operations. These compute position updates using fixed-point dmuls.l (32-bit
signed multiply with 64-bit result, then shift for fixed-point extraction).

---

## CATEGORY 2: Object State Machine & Initialization (0x060343C6-0x06034526)

Continuation of physics pipeline transitioning into object lifecycle management.

| # | Address | Size (B) | Type | Documented | Description |
|---|---------|----------|------|------------|-------------|
| 33 | FUN_060343C6 | 34 | CALL | no | Physics trampoline with cmp/eq, branch paths |
| 34 | FUN_060343E8 | 16 | CALL | no | Trampoline: jsr @r0, read struct field |
| 35 | FUN_060343F8 | 14 | CALL | no | Trampoline: jsr @r0, read struct field |
| 36 | FUN_06034406 | 10 | CALL | no | Trampoline: jsr @r0, load 0x06026DF8 |
| 37 | FUN_06034410 | 236 | CALL | no | Object initializer: jsr @r0, loads 0x06089EDC ptr, bra to shared rts. Secondary body: 5-iter loop over 0x06082A7C (stride 0x2C = 44 bytes), clears byte at offset +0x26 for each slot. References 0x06026EDE, 0x0600A5B2, 0x0600A4CA. Computes distance-squared (dmuls.l self-multiply for X and Y separately, adds) at 0x06083238 scratch, compares result, calls 0x06027476 (square root). |
| 38 | FUN_060344FC | 42 | CALL | no | Trampoline: jsr @r0, bra continuation, shll r0 (multiply by 2) |
| 39 | FUN_06034526 | 118 | CALL | no | Distance threshold check: restores 6 regs from stack, compares to 0x00080000, sets flag byte at struct+0x26 if exceeded. Writes segment data (struct+0x28, +0x0C, +0x26). |

**Gameplay relevance**: HIGH. FUN_06034410 initializes 5 game object slots at
0x06082A7C with stride 0x2C. The distance-squared + square root computation
is collision proximity detection.

---

## CATEGORY 3: Terrain Surface Properties (0x0603459C-0x060345F2)

Small terrain data accessors and field writers.

| # | Address | Size (B) | Type | Documented | Description |
|---|---------|----------|------|------------|-------------|
| 40 | FUN_0603459C | 28 | CALL | no | Terrain field write: reads r10+0x28, stores word to r14+0x02; reads r10+0x0C, shal (x2), stores to r14+0x28; sets byte r14+0x26 = 2 |
| 41 | FUN_060345B8 | 42 | CALL | no | Terrain accessor with shift: reads struct fields, applies shal, stores |
| 42 | FUN_060345E2 | 16 | CALL | no | Small trampoline for terrain calc |
| 43 | FUN_060345F2 | 80 | CALL | no | Terrain data copy: copies 4 fields from r10 to r14 struct (+0x04/+0x08/+0x0C/+0x18), calls 0x06026EDE |

**Gameplay relevance**: MEDIUM. Surface property accessors used during ground contact.

---

## CATEGORY 4: Terrain State Machine & Sound Triggers (0x06034642-0x060348E6)

Functions managing terrain-dependent animation cycling and sound playback.

| # | Address | Size (B) | Type | Documented | Description |
|---|---------|----------|------|------------|-------------|
| 44 | FUN_06034642 | 26 | CALL | no | Trampoline: jsr @r0, pool loads |
| 45 | FUN_0603465C | 14 | CALL | no | Trampoline: jsr @r0, read struct field |
| 46 | FUN_0603466A | 14 | CALL | no | Trampoline: jsr @r0, read struct field |
| 47 | FUN_06034678 | 10 | CALL | no | Trampoline: jsr @r0, load 0x06026DF8 |
| 48 | FUN_06034682 | 134 | CALL | no | Animation frame counter: jsr @r0, loads 0x06089EDC ptr, rts. Secondary body: reads byte tables at 0x060631B4 (max frames A) and 0x060631B8 (max frames B), indexed by (struct+0x01 - 1). Increments counter A at struct+0x10, wraps at max_A; increments counter B at struct+0x11, wraps at max_B. Two nested counters = animation frame cycling for terrain-dependent effects. |
| 49 | FUN_06034708 | 24 | CALL | partial | Data processing entry: pushes r8-r14 (5 callee-saved regs). Referenced by race_orchestration.s. |
| 50 | FUN_06034720 | 8 | LEAF | no | Tiny accessor: load constant + rts |
| 51 | FUN_06034728 | 8 | LEAF | no | Tiny accessor: load constant + rts |
| 52 | FUN_06034730 | 50 | CALL | no | Timer state: jsr @r0, adds result to struct+0x08, clamps to 0x00060000, shlr16+AND 0x07 extracts 3-bit state to struct+0x0C |
| 53 | FUN_06034762 | 388 | CALL | no | **Sound trigger state machine**: jsr @r0, computes timer state. Checks master enable at 0x06083255, checks button state at 0x0607EBC4 (bit 0x00028000 = some input flag). Reads 0x0607E944 car struct, checks speed at +0x08 vs threshold 0x0104. Reads state at struct+0x0C, dispatches: cmp/eq #0, #3, #4, #5. State-dependent sound IDs: state 3 -> 0xAE113BFF, state 4 -> 0xAE113CFF, state 0/5 -> 0xAE113DFF. Two mod-3 counters at struct+0x02 and +0x05. Calls FUN_0601D5F4 (sound driver) with sound ID in r5. |
| 54 | FUN_060348E6 | 26 | CALL | no | Sound call trampoline: jsr @r0, rts. Fall-through from FUN_06034762. |

**Gameplay relevance**: HIGH. FUN_06034762 triggers engine/skid sounds based on
terrain state, vehicle speed, and player input. The 0xAE11xxFF pattern suggests
SCSP (Saturn Sound Processor) command words with channel/bank encoding.

---

## CATEGORY 5: Terrain Collision Mesh & Track Queries (0x06034900-0x06034B9A)

Track/terrain collision detection. Partially documented in `asm/track_geometry.s`.

| # | Address | Size (B) | Type | Documented | Description |
|---|---------|----------|------|------------|-------------|
| 55 | FUN_06034900 | 58 | CALL | **YES** | Terrain data lookup (track_geometry.s): reads 0x0607E944 car struct, compares +0xB8 vs #44, +0x1BC vs #40 |
| 56 | FUN_0603493A | 34 | CALL | no | Terrain validator: struct field compare, branch on result |
| 57 | FUN_0603495C | 40 | CALL | no | Terrain boundary check: struct field access, distance compare |
| 58 | FUN_06034984 | 50 | CALL | no | Terrain query with distance compare, multi-field access |
| 59 | FUN_060349B6 | 14 | CALL | **YES** | External processor (event_queue.s): jsr @r0 trampoline |
| 60 | FUN_060349C4 | 76 | CALL | **YES** | CD response validator (vblank_system.s): calls FUN_06034A10, validates response byte (mask 0x80/0x20), returns -8 on failure |
| 61 | FUN_06034A10 | 140 | CALL | **YES** | CD double-read (vblank_system.s): saves/restores SR interrupt mask, calls FUN_06035E5E twice, compares 8-byte responses, retries 100x. Returns 0 (match) or -3 (timeout). |
| 62 | FUN_06034A9C | 4 | CALL | no | Entry wrapper: push r14, mov r4->r14 |
| 63 | FUN_06034AA0 | 78 | CALL | no | CD command builder: calls FUN_06035E90, FUN_06035EA2, builds 8-byte command packet on stack |
| 64 | FUN_06034AEE | 102 | CALL | **YES** | Track intersection test (track_geometry.s) |
| 65 | FUN_06034B54 | 8 | LEAF | **YES** | Mesh boundary check (track_geometry.s): tiny, push r14 fall-through |
| 66 | FUN_06034B5C | 62 | CALL | no | Extended boundary check: struct field reads, threshold compares |
| 67 | FUN_06034B9A | 14 | CALL | **YES** | Road segment query (track_geometry.s): entry point, pushes r14/r13, saves args |

**Gameplay relevance**: HIGH for terrain collision (FUN_06034900-06034984).
MEDIUM for CD I/O (FUN_060349B6-06034AA0).

---

## CATEGORY 6: CD Block Command Protocol (0x06034BA8-0x06034F08)

CD subsystem command building and response handling. These construct SCSI-style
command packets and exchange them with the Saturn CD block.

Command bytes observed in literal pools: 0x04, 0x05, 0x06, 0x10, 0x11, 0x12.
All commands call primitives FUN_06035E90/FUN_06035EA2/FUN_06035EC8/FUN_06035E00.

| # | Address | Size (B) | Type | Documented | Description |
|---|---------|----------|------|------------|-------------|
| 68 | FUN_06034BA8 | 160 | CALL | no | CD cmd 0x04: 6-arg command with retry loop, calls FUN_06035C92/FUN_06035EC8/FUN_06035C80 |
| 69 | FUN_06034C48 | 32 | CALL | no | CD cmd 0x05: simple, calls FUN_06035E90 + FUN_06035EC8 |
| 70 | FUN_06034C68 | 96 | CALL | **YES** | CD transfer handler (event_queue.s): arg-dependent cmd (0x82 vs 0x02), calls FUN_06035E00, checks bit 0x80, error path via FUN_06034CC8, clears with FUN_06035C6E mask 0xFFFD |
| 71 | FUN_06034CC8 | 4 | CALL | no | Entry wrapper: push r14, mov r4->r14 |
| 72 | FUN_06034CCC | 80 | CALL | no | CD response parser: cmd 0x06, calls FUN_06035E90/FUN_06035EA2, masks with 0x00FFFFFF, stores to *r14 |
| 73 | FUN_06034D1C | 4 | CALL | **YES** | Entry wrapper (event_queue.s): push r14, mov r4->r14 |
| 74 | FUN_06034D20 | 62 | CALL | no | CD cmd 0x10: calls FUN_06035E90, calls FUN_06034D5E twice (sub-packet builder), calls FUN_06035EC8 |
| 75 | FUN_06034D5E | 140 | CALL | no | CD data packer: 4-way state machine (cmp/eq #0/#1/#2/#3). States 0,3: calls FUN_06035228 with buffers 0x06059CA4/0x06059CA7. States 1,2: byte packing with OR 0x80. |
| 76 | FUN_06034DEA | 54 | CALL | no | CD cmd 0x11: calls FUN_06035E90 + FUN_06034D5E + FUN_06035EC8 |
| 77 | FUN_06034E20 | 4 | CALL | no | Entry wrapper: push r14, mov r4->r14 |
| 78 | FUN_06034E24 | 228 | CALL | no | CD cmd 0x12: calls FUN_06035E90/FUN_06035EC8, param byte from r14 |

**Gameplay relevance**: LOW. CD block infrastructure for disc loading.

---

## CATEGORY 7: AI Engine Mega-Block (0x06034F08-0x06035A08)

Single symbol table entry spanning 2816 bytes. Contains the entire AI opponent
system plus several shared utility functions. Thoroughly documented in existing
asm files.

| # | Address | Size (B) | Type | Documented | Description |
|---|---------|----------|------|------------|-------------|
| 79 | FUN_06034F08 | 2816 | CALL | **YES** | AI engine mega-block containing ~11 internal sub-functions |

Internal sub-functions (not separate symbol table entries):

| Internal Addr | Size (est.) | Doc Source | Description |
|---------------|-------------|-----------|-------------|
| 0x06034F08 | ~112 | ai_opponents.s | AI interrupt setup: writes to SR, sets SMPC polling state at 0x06063574 |
| 0x06034F78 | ~132 | ai_opp + lap + force + physics | Bitfield write utility: writes value to bitfield at ptr+offset. Most-called utility in range. |
| 0x06034FFC | ~180 | ai_opponents.s | AI state machine: 4-mode dispatch (normal/chase/defensive/recovery) |
| 0x060350B0 | ~184 | ai_opp + replay_cam | AI decision logic / random position selection |
| 0x06035168 | ~192 | collision.s | Collision geometry classification |
| 0x06035228 | ~88 | event_queue + physics | Value interpolation handler |
| 0x06035280 | ~192 | lap_counting.s | Bitmask utility for lap completion state |
| 0x06035340 | ~288 | object_mgmt.s | Divisor calculation for object LOD/distance |
| 0x06035460 | ~996 | ai_opponents.s | AI main loop: largest AI function, per-frame per-car update |
| 0x06035844 | ~416 | ai_opponents.s | AI target tracking: relative position/velocity/angle to player |
| 0x060359E4 | ~36 | ai_opponents.s | AI physics integration: converts decisions to steering/throttle/brake |

**Gameplay relevance**: CRITICAL. This is the AI opponent brain. Already fully documented.

---

## CATEGORY 8: Fixed-Point Math Library (0x06035A08-0x06035C08)

| # | Address | Size (B) | Type | Documented | Description |
|---|---------|----------|------|------------|-------------|
| 80 | FUN_06035A08 | 512 | LEAF | no | **Core fixed-point 20.12 multiply**: Pure arithmetic, no function calls. Uses dmulu.l (unsigned 64-bit multiply) with extensive bit manipulation. Inputs: r4/r5 = first operand pair, r6/r7 = second pair. Extracts exponents via shlr16+shlr2x2, checks for overflow (exp == 0x7FF) and underflow (exp == 0), handles sign via XOR of inputs. Result normalized with rotcl shift loop. Special-case branches for zero, max, and negative overflow. This is THE fixed-point multiply used throughout the game engine. |

**Gameplay relevance**: CRITICAL. Every physics calculation chains through this function.

---

## CATEGORY 9: Hardware Interface Utilities (0x06035C08-0x06035CBC)

Small utility functions for CD block and VDP hardware register access.
Many of these are embedded (no separate symbol table entry) between labeled functions.

| # | Address | Size (B) | Type | Documented | Description |
|---|---------|----------|------|------------|-------------|
| 81 | FUN_06035C08 | 16 | CALL | no | String handler: calls 0x06035FEC (internal string copy) |
| -- | (0x06035C1C) | 18 | LEAF | no | strlen: byte loop until null terminator, returns count in r0 |
| -- | (0x06035C2C) | 24 | LEAF | no | Hardware division wrapper: writes to Saturn divider at 0xFF000000 area |
| -- | (0x06035C48) | 6 | LEAF | no | VDP2 status: loads address 0x25818000, rts |
| -- | (0x06035C4E) | 6 | LEAF | **YES** | SMPC status read (event_queue.s): loads word from 0x25890008, rts |
| 82 | FUN_06035C54 | 44 | CALL | **YES** | SMPC config validator (event_queue.s): reads 0x25890008, ORs with 0x06063590 state, sets bit 0x01, writes back to SMPC register |
| 83 | FUN_06035C80 | 60 | CALL | no | SMPC clear+setup: calls write at 0x06035C6E, zeros 0x06063590, reads 0x2589000C |
| -- | (0x06035C92) | 14 | CALL | no | SMPC register write: ORs param into 0x06063590, writes to 0x25890008. Called from many CD functions. |
| -- | (0x06035CA0) | 6 | LEAF | no | SMPC read: returns word from 0x2589000C |
| -- | (0x06035CB0) | 6 | CALL | no | SMPC write: writes r4 to 0x2589000C |
| -- | (0x06035CB6) | 6 | LEAF | no | Returns constant address 0x25818028 |

**Gameplay relevance**: LOW. Hardware register utilities, not game logic.

---

## CATEGORY 10: CD/SCSI Init & AI Init (0x06035CBC-0x06035E00)

| # | Address | Size (B) | Type | Documented | Description |
|---|---------|----------|------|------------|-------------|
| 84 | FUN_06035CBC | 102 | CALL | **YES** | AI/SCSI setup (ai_opponents.s): reads SCSI registers at 0x25898000, multi-step init with retry loop |
| 85 | FUN_06035D22 | 56 | CALL | no | CD command dispatcher: pushes r13/r12/r11, manages state through function pointer table, handles SMPC state |
| 86 | FUN_06035D5A | 166 | CALL | **YES** | AI core initialization (ai_opponents.s): sets up initial state for all opponent cars at race start |
| 87 | FUN_06035E00 | 144 | CALL | no | CD data transfer: manages multi-sector reads, tracks transfer count, calls FUN_06035D22 |

**Gameplay relevance**: MEDIUM for FUN_06035D5A (AI init), LOW for rest.

---

## CATEGORY 11: CD Response Handling & Math Primitives (0x06035E90-0x06036144)

Functions that send/receive individual CD commands, parse responses, plus
embedded math utility functions.

| # | Address | Size (B) | Type | Documented | Description |
|---|---------|----------|------|------------|-------------|
| 88 | FUN_06035E90 | 18 | CALL | no | CD SCSI send: calls FUN_06035168 with buffer 0x06059CB0, size 8 |
| 89 | FUN_06035EA2 | 38 | CALL | no | CD response: calls FUN_06035D22, stores status byte to 0x06063594 |
| 90 | FUN_06035EC8 | 60 | CALL | no | CD cmd+response: calls FUN_06035D22, then response parser at 0x06035F16 |
| 91 | FUN_06035F04 | 50 | CALL | no | CD SCSI send variant: calls FUN_06035168 with buffer 0x06063594, size 12 |
| -- | (0x06035F16) | 30 | LEAF | no | CD response parser: copies 5 bytes r4->r5, masks word with 0x00FFFFFF |
| -- | (0x06035F44) | 152 | LEAF | no | **32-bit unsigned divide** (__udivsi3): 32 unrolled div1 iterations. Handles zero divisor (stores error to 0x060A246C, returns 0). Standard SH-2 division. |
| -- | (0x06035FEC) | -- | CALL | no | String copy: 4-byte-at-a-time with masking, called from FUN_06035C08 |

**Gameplay relevance**: LOW for CD primitives. The division routine is used everywhere.

---

## CATEGORY 12: CD Block SCSI Command Set (0x06036144-0x06036BA6)

66 functions implementing the Saturn CD block command API. Each function pair:
- "Outer" wrapper pushes extra register args, falls through
- "Inner" function constructs SCSI command packet, sends, receives response

This is Sega's standard CDB (CD Block) library compiled into the binary.

| # | Address | Size (B) | Type | Documented | Cmd | Description |
|---|---------|----------|------|------------|-----|-------------|
| 92 | FUN_06036144 | 4 | CALL | no | -- | Wrapper: push r14, fall through |
| 93 | FUN_06036148 | 42 | CALL | no | 0x30 | Status query, result via FUN_06035EC8 |
| 94 | FUN_06036172 | 70 | CALL | no | 0x31 | Status query, stores masked word to *r14 |
| 95 | FUN_060361B8 | 4 | CALL | no | -- | Wrapper |
| 96 | FUN_060361BC | 64 | CALL | no | 0x32 | Status query, stores byte to *r14 |
| 97 | FUN_060361FC | 12 | CALL | no | -- | Wrapper (3-arg: r14/r13/r12) |
| 98 | FUN_06036208 | 54 | CALL | no | 0x40 | Command with response |
| 99 | FUN_0603623E | 10 | CALL | no | -- | Wrapper (2-arg) |
| 100 | FUN_06036248 | 96 | CALL | no | 0x41 | Command, 2 response words masked 0x00FFFFFF -> *r13, *r14 |
| 101 | FUN_060362A8 | 8 | CALL | no | -- | Wrapper |
| 102 | FUN_060362B0 | 88 | CALL | no | var | CD command variant |
| 103 | FUN_06036308 | 8 | CALL | no | -- | Wrapper |
| 104 | FUN_06036310 | 112 | CALL | no | var | CD command (large) |
| 105 | FUN_06036380 | 8 | CALL | no | -- | Wrapper |
| 106 | FUN_06036388 | 52 | CALL | no | var | CD command |
| 107 | FUN_060363BC | 8 | CALL | no | -- | Wrapper |
| 108 | FUN_060363C4 | 80 | CALL | no | var | CD command |
| 109 | FUN_06036414 | 16 | CALL | no | -- | Wrapper (param setup) |
| 110 | FUN_06036424 | 72 | CALL | no | var | CD command |
| 111 | FUN_0603646C | 12 | CALL | no | -- | Wrapper |
| 112 | FUN_06036478 | 92 | CALL | no | var | CD command |
| 113 | FUN_060364D4 | 8 | CALL | no | -- | Wrapper |
| 114 | FUN_060364DC | 60 | CALL | no | var | CD command |
| 115 | FUN_06036518 | 12 | CALL | no | -- | Wrapper |
| 116 | FUN_06036524 | 78 | CALL | no | var | CD command |
| 117 | FUN_06036572 | 6 | CALL | no | -- | Wrapper |
| 118 | FUN_06036578 | 76 | CALL | no | var | CD command |
| 119 | FUN_060365C4 | 12 | CALL | no | -- | Wrapper |
| 120 | FUN_060365D0 | 62 | CALL | no | var | CD command |
| 121 | FUN_0603660E | 66 | CALL | no | var | Standalone CD command |
| 122 | FUN_06036650 | 46 | CALL | no | var | Standalone CD command |
| 123 | FUN_0603667E | 10 | CALL | no | -- | Wrapper |
| 124 | FUN_06036688 | 124 | CALL | no | var | CD command (large, extended) |
| 125 | FUN_06036704 | 12 | CALL | no | -- | Wrapper |
| 126 | FUN_06036710 | 58 | CALL | no | var | CD command |
| 127 | FUN_0603674A | 10 | CALL | no | -- | Wrapper |
| 128 | FUN_06036754 | 88 | CALL | no | var | CD command |
| 129 | FUN_060367AC | 8 | CALL | no | -- | Wrapper |
| 130 | FUN_060367B4 | 52 | CALL | no | var | CD command |
| 131 | FUN_060367E8 | 12 | CALL | **YES** | -- | Validator (event_queue.s) |
| 132 | FUN_060367F4 | 72 | CALL | no | var | CD command |
| 133 | FUN_0603683C | 12 | CALL | no | -- | Wrapper |
| 134 | FUN_06036848 | 62 | CALL | no | var | CD command |
| 135 | FUN_06036886 | 10 | CALL | no | -- | Wrapper |
| 136 | FUN_06036890 | 76 | CALL | no | var | CD command |
| 137 | FUN_060368DC | 8 | CALL | no | -- | Wrapper |
| 138 | FUN_060368E4 | 52 | CALL | no | var | CD command |
| 139 | FUN_06036918 | 16 | CALL | no | -- | Wrapper |
| 140 | FUN_06036928 | 84 | CALL | no | var | CD command |
| 141 | FUN_0603697C | 16 | CALL | no | -- | Wrapper |
| 142 | FUN_0603698C | 72 | CALL | no | var | CD command |
| 143 | FUN_060369D4 | 4 | CALL | no | -- | Wrapper |
| 144 | FUN_060369D8 | 68 | CALL | no | var | CD command |
| 145 | FUN_06036A1C | 8 | CALL | **YES** | -- | Validator (event_queue.s) |
| 146 | FUN_06036A24 | 48 | CALL | no | var | CD command |
| 147 | FUN_06036A54 | 8 | CALL | no | -- | Wrapper |
| 148 | FUN_06036A5C | 60 | CALL | no | var | CD command |
| 149 | FUN_06036A98 | 12 | CALL | no | -- | Wrapper |
| 150 | FUN_06036AA4 | 78 | CALL | no | var | CD command |
| 151 | FUN_06036AF2 | 6 | CALL | no | -- | Wrapper |
| 152 | FUN_06036AF8 | 108 | CALL | no | var | CD command (large) |
| 153 | FUN_06036B64 | 12 | CALL | no | -- | Wrapper |
| 154 | FUN_06036B70 | 54 | CALL | no | var | CD command |
| 155 | FUN_06036BA6 | 566 | CALL | no | 0x75 | CD extended: calls FUN_06035C92/FUN_06035EC8, includes div1 division loop |

**Gameplay relevance**: NONE. Standard Saturn CD block driver library.

---

## CATEGORY 13: String/Memory Library (0x06036DDC-0x06036E90)

Standard C library functions compiled into the binary.

| # | Address | Size (B) | Type | Documented | Description |
|---|---------|----------|------|------------|-------------|
| 156 | FUN_06036DDC | 58 | LEAF | no | **strncpy**: copies bytes r13->r7 up to count r6, zero-pads remainder. Returns dest (r4) in r0. |
| -- | (0x06036E18) | 118 | LEAF | no | **memcmp**: word-at-a-time (4x unrolled), byte fallback. Returns byte difference (r3-r4). Also tests for null terminator (doubles as strcmp). |

**Gameplay relevance**: NONE. Standard library functions.

---

## CATEGORY 14: VDP DMA & Display List Management (0x06036E90-0x060370E4)

VDP hardware management for DMA transfers and display list setup.

| # | Address | Size (B) | Type | Documented | Description |
|---|---------|----------|------|------------|-------------|
| 157 | FUN_06036E90 | 124 | CALL | **YES** | VDP DMA setup (vblank/vdp_hw): writes addr+flags to 0x060A3DF8+0x3C, ORs 0x25E00000 (VDP2 DMA base), calls FUN_06038A48, manages 0x060635AC/0x060635B0 flags |
| 158 | FUN_06036F0C | 472 | CALL | **YES** | VDP init (vblank): 3-state machine. State 0: display list select. State 1: mode config. State 2: double-buffer pointer swap at 0x060635AE. Manages 0x060A3D88, 0x060A3E38, 0x06000324 (frame counter). |

**Gameplay relevance**: LOW. VDP rendering infrastructure.

---

## CATEGORY 15: VDP1 Texture & Command Pipeline (0x060370E4-end)

The rendering backend.

| # | Address | Size (B) | Type | Documented | Description |
|---|---------|----------|------|------------|-------------|
| 159 | FUN_060370E4 | 1404 | CALL | **YES** | Texture management (render_pipeline.s): 702 insns. Texture bank, UV coords, CLUT config, palette. State at 0x060A3D88/0x060A3E38/0x060A4C44. |
| 160 | FUN_06037660 | 2572 | CALL | **YES** | VDP1 command builder (render_pipeline.s): 1286 insns. Pushes r8-r14+pr. Builds polygon/sprite display commands. Processes vertices, textures, gouraud shading. Loop over 64 entries (r14=63 as counter). VDP1 at 0xDA200000. Display list base 0x060A3D88. |

**Gameplay relevance**: LOW. Rendering backend, not game logic.

---

## Summary by Gameplay Relevance

### CRITICAL (must extract for gameplay transplant)

| Address | Size | Category | Description |
|---------|------|----------|-------------|
| FUN_06034F08 block | 2816 | AI Engine | Complete AI opponent system (11 sub-functions) |
| FUN_06035A08 | 512 | Math | Core fixed-point 20.12 multiply |

### HIGH (physics, collision, sound -- needed for gameplay)

| Address | Size | Category | Description |
|---------|------|----------|-------------|
| FUN_06034036-060343AE | ~1400 | Physics | 32 functions: physics computation pipeline |
| FUN_06034410 | 236 | Objects | Object array initializer (5 slots at 0x06082A7C) |
| FUN_06034526 | 118 | Objects | Distance threshold check |
| FUN_0603459C-060345F2 | ~166 | Terrain | Terrain surface property accessors |
| FUN_06034682 | 134 | Animation | Dual animation frame counter |
| FUN_06034730 | 50 | Timer | Timer->3-bit state extractor |
| FUN_06034762 | 388 | Sound | Sound trigger state machine (engine/skid) |
| FUN_06034900-06034984 | ~182 | Terrain | Track collision mesh queries |

### MEDIUM (supporting systems)

| Address | Size | Category | Description |
|---------|------|----------|-------------|
| FUN_06035D5A | 166 | AI Init | AI opponent initialization |
| FUN_06035CBC | 102 | HW Init | SCSI/hardware initialization |
| FUN_060349C4 | 76 | CD | CD response validator |
| FUN_06034A10 | 140 | CD | CD double-read with interrupt mask |

### LOW / NONE (infrastructure, not gameplay)

| Category | Count | Total Bytes | Description |
|----------|-------|-------------|-------------|
| CD SCSI Commands | 66 | ~4,300 | Saturn CDB driver library |
| CD Protocol | 11 | ~1,000 | CD command building/response |
| HW Utilities | ~11 | ~200 | SMPC/VDP register access |
| String/Memory | 2 | ~176 | strncpy, memcmp/strcmp |
| VDP DMA | 2 | ~596 | Display list DMA management |
| VDP1 Rendering | 2 | ~3,976 | Texture + polygon command builder |

---

## Key Data Structures Referenced

| Address | Size | Description |
|---------|------|-------------|
| 0x0607E940 | 4 | Player car struct pointer |
| 0x0607E944 | 4 | Secondary car struct pointer |
| 0x0607EBC4 | 4 | Button/input state word |
| 0x06082A7C | 5x0x2C | Object slot array (5 slots, 44 bytes each) |
| 0x06083238-44 | 12 | Physics scratch workspace (XYZ) |
| 0x06083255 | 1 | Master sound enable byte |
| 0x06089EDC | 4 | Pointer to active object state table |
| 0x060631B4 | N | Animation max-frame table A (byte array) |
| 0x060631B8 | N | Animation max-frame table B (byte array) |
| 0x06059CA4 | 3 | CD command buffer A |
| 0x06059CA7 | 3 | CD command buffer B |
| 0x06059CB0 | 8 | CD SCSI command FIFO buffer |
| 0x06063574 | 4 | AI polling function pointer |
| 0x06063590 | 2 | SMPC status shadow register |
| 0x06063594 | N | CD response buffer |
| 0x060635AC | 2 | VDP display list flag A |
| 0x060635AE | 2 | VDP display list select |
| 0x060635B0 | 2 | VDP display list flag B |
| 0x060A246C | 4 | Division error result |
| 0x060A3D88 | N | VDP1 display list base state |
| 0x060A3DF8 | N | VDP DMA configuration area |
