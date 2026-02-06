# Gameplay Extraction via Direct ASM Analysis

> **The Sawyer Approach**: Study the assembly directly, trace from hardware interfaces backwards, build understanding through observation — not translation.

## Goal

Extract Daytona USA gameplay code (physics, steering, collision, AI) by analyzing the original SH-2 assembly directly. Skip C decompilation entirely.

## Why This Pivot

- The C was only a means to an end — a format for Claude to study
- **Claude can read assembly directly** — skip the middle step

## Approach

### 1. Hardware Interface Tracing

Saturn hardware has well-documented entry points. We trace backwards from these:

| Interface | Hardware | What It Reveals |
|-----------|----------|-----------------|
| **Input** | SMPC (0x20100001+) | Controller reads → menus, driving controls |
| **Sprites** | VDP1 (0x25C00000+) | Car/object rendering → position/transform data |
| **Backgrounds** | VDP2 (0x25E00000+) | Track graphics → course loading |
| **Sound** | SCSP (0x25B00000+) | Audio triggers → collision, events |
| **Interrupts** | SCU (0x25FE0000+) | VBlank/HBlank → game loop timing |

### 2. Observable Behavior Mapping

1. Identify something visible (e.g., "that's the car sprite")
2. Find where that data gets loaded in code
3. Trace backwards to find what manipulates it
4. Build call graph of related functionality

### 3. Subsystem Isolation

Once we understand enough, isolate subsystems:
- Physics engine (acceleration, braking, friction)
- Steering model (input → wheel angle → trajectory)
- Collision detection (car-car, car-wall, car-track)
- AI behavior (opponent racing logic)

---

## Milestones

### M1: Saturn Hardware Documentation ✓
- [x] Collect SMPC (peripheral) documentation
- [x] Document known memory map regions
- [x] Collect VDP1/VDP2 documentation — see asm/vdp_hardware.s
- [x] Collect SCU interrupt documentation — see asm/vblank_system.s

### M2: Input System Mapping ✓
- [x] Find SMPC polling pattern in aprog.s
- [x] Trace all call sites that read controller input
- [x] Map button assignments (see Research Notes below)
- [x] Identify which functions handle menu vs gameplay input — see asm/hud_ui.s (FUN_06011F1C/06011F92)

### M3: Game Loop Understanding ✓
- [x] Understand the 32-state machine at main (0x06003000)
- [x] Map state transitions (menu → race → results)
- [x] Find the per-frame update routine (FUN_0600A392)
- [x] Identify VBlank interrupt handler (FUN_06006F3C = VBlank-IN, FUN_06007268 = VBlank-OUT)

### M4: Car Rendering Chain (Mostly Complete)
- [x] Find VDP1 command list building code (FUN_0602C494-0x0602D43C, 7 functions)
- [x] Find VDP1 initialization (FUN_0600A140: clears 64KB VRAM at 0x25C80000)
- [x] Identify camera/viewport setup (FUN_0602EFF0: hardware division, clipping)
- [x] Identify VDP1 register usage (TVMR, FBCR, PTMR, EWDR/EWLR/EWRR)
- [x] Double-buffer mechanism (FBCR register swap during VBlank-IN/OUT handlers)
- [x] Identify polygon data format (52-byte entries at 0x060A6000, 4-vertex quads)
- [x] Identify 3D scene processor (FUN_06027CA4 — transforms, culls, generates commands)
- [x] Map data tables: polygon pool (0x060A6000), texture index (0x060BF000), course segments (0x060C2000)
- [x] Trace FUN_0602F0E8 — track position management (wrapping, segment boundaries, smoothing)
- [x] Trace sprite sorting/draw-order system — NO runtime sort, pre-baked order in course data

### M5: Physics Extraction ✓
- [x] Find velocity/acceleration calculations
- [x] Identify collision response code (FUN_0600C5D6 → FUN_0600CD40/CA96/CC38)
- [x] Locate friction/drag model (FUN_0600D266 = stub! Friction baked into force tables)
- [x] Extract steering angle → trajectory math (FUN_06008640 → FUN_060086C0)
- [x] Map complete player physics pipeline (FUN_0600E71A, 8-step chain)
- [x] Map gas/brake → acceleration path (car flag bits 0x40/0x80 → force table → speed)
- [x] Identify player vs AI branching (FUN_0600E1D4, car index 0 = player)
- [x] Trace force table data structures (0x060453B4, 0x060453C4 — COMPLETE)
- [x] Trace speed curve from course tables (0x060477EC, 0x060454CC) — COMPLETE
- [x] Trace position integration (FUN_0600C5D6 — sin/cos + 3D transform paths)
- [x] Created asm/speed_position.s with full annotated system

### M7: Sound System ✓
- [x] Find sound trigger mechanism (FUN_0601D5F4 — mailbox to 68000 via 0x25A02C20)
- [x] Trace initialization path (FUN_06018EE4 — SMPC SNDOFF/SNDON, DMA driver, handshake)
- [x] Identify command format (0xAAGGIIFF — prefix, group, ID, play flag)
- [x] Correct FUN_0602766C misidentification (SCU DMA, NOT sound dispatch)
- [x] Map gameplay sound trigger call sites (~30 locations)
- [x] Document SCSP register access (slots 16/17, common register at 0x25B00400)
- [x] Map remaining sound IDs to game events — see asm/sound_driver.s (SCSP 4-channel dispatcher)

### M6: AI Analysis (Mostly Complete)
- [x] Find opponent car update routines (FUN_0600E906 → FUN_0600EA18)
- [x] Identify pathfinding/racing line logic (track-following: velocity = (target-current) >> 4)
- [x] Trace FUN_0600C74E (AI-specific processing) — COMPLETE, see asm/ai_behavior.s
- [x] Document AI decision points — waypoint targeting, speed zones, heading damping
- [x] Locate difficulty scaling — segment-based speed modulation, NOT traditional rubber-banding

### M8: Race State Machine ✓
- [x] Decode State 14 (FUN_06008EBC) — first-frame race setup, → state 15
- [x] Decode State 15 (FUN_06009098) — main race loop, per-car iteration, → state 16/18
- [x] Decode State 16 (FUN_06009290) — post-countdown cleanup, → state 17
- [x] Decode State 17 (FUN_060092D0) — post-lap processing/results, → state 18/20/24/28
- [x] Decode State 18 (FUN_060096DC) — time extension setup (single frame), → state 19
- [x] Decode State 19 (FUN_06009788) — time extension active/input, → state 14/24/saved
- [x] Decode State 20 (FUN_06009508) — abort processing, → state 29
- [x] Map complete state transition graph (see asm/race_states.s)
- [x] Decode State 20 (FUN_06009A60) — race completion init, → state 21
- [x] Decode State 24 (FUN_06009CFC) — post-race init, → state 25
- [x] Decode State 25 (FUN_06009D4E) — post-race display loop
- [x] Decode State 28 (FUN_06009508) — abort processing, → state 29
- [x] Decode State 29 (FUN_0600955E) — post-race menu, → state 17/18/20
- [x] CORRECTED: State 20/28 were SWAPPED in prior M8 analysis (verified via jump table)
- [x] Trace FUN_0600DE54 (per-car race state update — physics/collision per frame)
- [x] Trace FUN_060078DC (frame timing/display commit — 12-step pipeline)
- [x] Created asm/frame_timing.s with FUN_060078DC + FUN_06007BCC annotated

### M9: Lap Counting System ✓
- [x] Trace checkpoint crossing detection (FUN_0600CD40)
- [x] Trace checkpoint change detection (FUN_0600D780)
- [x] Find the lap completion flag setter (FUN_0600D9BC via FUN_06034F78)
- [x] Trace lap counter increment (0x0600DB64)
- [x] Trace finish line display effects (FUN_0600DBA0)
- [x] Map complete per-frame lap counting flow
- [x] Decode FUN_06034F78 bitfield utility (packed bit position/count)
- [x] Created asm/lap_counting.s with full annotated system

### M10: Object Management System ✓
- [x] Discover car array memory layout (40 slots × 0x268 at 0x06078900)
- [x] Trace FUN_0600EB14 — master race initialization (zeroes array, calls subsystem inits)
- [x] Trace FUN_0600629C — car initialization loop (iterates car_count, calls E1D4 per car)
- [x] Trace FUN_0600E1D4 — per-car type init (config table lookup at 0x06047DE4)
- [x] Trace FUN_0600DE70 — per-frame car iteration loop (called from State 15)
- [x] Trace FUN_0600E4F2 — per-car per-frame update (THE BIG ONE: 9-stage pipeline)
- [x] Trace FUN_0600E410 — simplified update (mode 0, pre-race countdown)
- [x] Trace FUN_0600DF66 — update mode dispatcher (mode 0/1/2)
- [x] Decode config table format at 0x06047DE4 (12-byte entries per car: type, heading, indices)
- [x] Map player vs AI determination (car[0] == player, r12 flag)
- [x] Document demo/replay mode path (velocity playback from globals)
- [x] Created asm/object_management.s with complete annotated system

### M11: Scene Rendering & Camera System ✓
- [x] Trace Type A object renderer (FUN_0600AA98, additive transforms)
- [x] Trace Type B object renderer (FUN_0600AC44, absolute transforms)
- [x] Trace main scene object rendering loop (FUN_0600B914, 3 detail levels)
- [x] Trace multi-mode camera system (FUN_0600BB94, 7 camera modes)
- [x] Trace camera heading tracker with exponential smoothing (FUN_0600BF70)
- [x] Trace priority-based render batch processor (FUN_0600D50C)
- [x] Document render budget model (48 bytes per object from per-frame allocation)
- [x] Created asm/scene_camera.s with 18 functions documented

### M12: HUD/UI/Input/AI Integration ✓
- [x] Trace sprite/animation rendering (FUN_060100A4-06010760, 8 functions)
- [x] Trace controller input processing (FUN_06011F1C steering, FUN_06011F92 throttle/brake)
- [x] Trace race timing/lap progression state machine (FUN_0601228A)
- [x] Trace master game initialization (FUN_06012F80, 1892 bytes, 57 objects + 59 commands)
- [x] Trace AI decision tree (FUN_06014A74, 486 bytes)
- [x] Trace AI pathfinding (FUN_06014D2C, 454 bytes)
- [x] Created asm/hud_ui.s with 62 functions documented

### M13: VDP1/VDP2 Hardware Interface ✓
- [x] Map VDP1 framebuffer (0x25C00000, double-buffered, 512x224)
- [x] Map VDP1 VRAM command queue (0x25D00000, polygon modes 0-7)
- [x] Map VDP2 VRAM (0x25E00000, 400KB tilemap initialization via 40+ DMA)
- [x] Map VDP2 Color RAM (0x25F00000, 512 palette entries, dynamic cycling)
- [x] Map VDP2 Control Registers (0x25F80000, TVMD/EXTEN/RAMCTL)
- [x] Map SCU DMA Controller (0x25FE0000, synchronous bulk transfers)
- [x] Map SH-2 Hardware Divider (0xFFFFFF00, critical section for interrupts)
- [x] Created asm/vdp_hardware.s with complete hardware memory map

### M14: Track Geometry & Course Data ✓
- [x] Trace track segment construction (FUN_06016DD8, 740 bytes, vertex array builder)
- [x] Trace track state machine (FUN_06017CEC, 978 bytes, largest track function)
- [x] Trace geometry pipeline coordinator (FUN_060173AC, 794 bytes)
- [x] Trace 3-course physics initialization (3x 282-byte identical functions)
- [x] Trace course data loading pipeline (FUN_0601A940, ROM→VRAM)
- [x] Trace terrain collision mesh (FUN_0603449C-06034B9A, 6 functions)
- [x] Trace track object placement (FUN_06021450, 1447 insns, ROM object positions)
- [x] Created asm/track_geometry.s with complete track pipeline

### M15: Master Rendering Pipeline ✓
- [x] Identify largest functions in binary: FUN_0603DDFC (2910B), FUN_0602382C (4484B)
- [x] Trace scene setup for 1-57 objects (FUN_0602382C)
- [x] Trace VDP1 command list generation (FUN_0602D08A/0602D43C/0602CDF6)
- [x] Trace VDP1 command builder (FUN_06037660, 2272B, low-level hardware)
- [x] Trace texture management (FUN_060370E4, 1168B, bank selection)
- [x] Trace render orchestrator (FUN_0603268C, per-course coordination)
- [x] Trace race initialization (FUN_060200A4, palette/tilemap/BGM)
- [x] Created asm/render_pipeline.s with complete pipeline hierarchy

### M16: Sound Driver ✓
- [x] Trace SCSP command dispatcher (FUN_0601D5F4, 7-command switch)
- [x] Trace 4-channel handler system (FUN_0601D6D4-0601D7D0)
- [x] Trace sound initialization (FUN_060302C6, SOUNDS.BIN/MUSICD.BIN loading)
- [x] Trace sound state dispatcher (FUN_0603072E, per-course sound banks)
- [x] Trace sound event handler (FUN_06030B68, collision/tire/engine sounds)
- [x] Created asm/sound_driver.s with complete SCSP interface

### M17: AI Opponent System (High-Level) ✓
- [x] Trace AI main loop (FUN_06035460, 662 bytes)
- [x] Trace AI physics integration (FUN_060359E4, 462 bytes)
- [x] Trace AI pathfinding (FUN_06034E58, waypoint navigation)
- [x] Trace AI state machine (FUN_06034FFC, 4 behavior modes)
- [x] Trace AI target tracking (FUN_06035844, player position tracking)
- [x] Trace AI initialization (FUN_06035D5A, difficulty-dependent params)
- [x] Created asm/ai_opponents.s with complete AI hierarchy

### M18: Replay Camera & Display ✓
- [x] Trace replay camera controller (FUN_0601DBB8, 236 insns, timer-based)
- [x] Trace largest LEAF functions (FUN_0601EFC4 930B, FUN_0601EBDA 854B vertex transforms)
- [x] Trace menu/display system (FUN_0603C1A8/0603C728/0603CD5C)
- [x] Trace race HUD system (FUN_0603268C + 30 digit renderers)
- [x] Trace race state handlers (FUN_06018DDC dispatcher + 18 segment handlers)
- [x] Trace game logic integration (FUN_0603A0B0, 1508B)
- [x] Created asm/replay_camera.s and asm/menu_display.s

### M19: Complete State Handler Catalog ✓
- [x] Document all 32 game state handlers (0x060088CC-0x06009F10)
- [x] Analyze menu flow: states 0-5 (startup, attract, input routing)
- [x] Analyze selection flow: states 6-12 (course select, car select, loading, resource check)
- [x] Analyze pre-race: state 13 (race prep) + state 31 (3-2-1-GO countdown)
- [x] Document time extension: states 18-19 (speed selection 1-99, A+B+C secret)
- [x] Document post-race: states 20-25 (results with cars still moving/colliding!)
- [x] Document abort: states 28-29 (abort processing + menu)
- [x] Map state transition graph (complete 32-state flow)
- [x] Identify key state variables (0x0605AD10, 0x0607EAAC, 0x0607EACC, etc.)
- [x] Created asm/state_handlers.s with complete catalog

### M20: Event Queue & State Management ✓
- [x] Analyze 0x0604xxxx range (70 functions, previously 0% coverage)
- [x] Identify 24-slot circular event queue (16 bytes/slot)
- [x] Map global game state structure at 0x060A5400
- [x] Document external validator chain (0x06034xxx-0x06036xxx)
- [x] Trace status code system (17+ distinct return codes)
- [x] Document bulk structure initialization (23 fields, per-race setup)
- [x] Created asm/event_queue.s with full subsystem documentation

### M21: System Bootstrap & Utilities ✓
- [x] Analyze low-address range 0x06003xxx-0x06005xxx (25 functions)
- [x] Document hardware init chain: SCU, VDP, DMA (6 functions)
- [x] Document game data init: object templates, engine setup (3 functions)
- [x] Document per-frame update chain: FUN_060058FA dispatcher (6 functions)
- [x] Document 3D math utilities: vector angle calc, perspective projection
- [x] Document background/texture layer init for 3 courses
- [x] Trace per-course DMA variants (3 functions, one per course)
- [x] Created asm/system_init.s with init sequence and per-frame loop

### M22: Extraction Dependency Graph ✓
- [x] Create 9-tier dependency hierarchy for CCE transplant
- [x] Identify ~51 gameplay functions as extraction targets
- [x] Identify 13 critical data tables to extract
- [x] Map subsystem dependencies (math -> physics -> collision -> AI -> pipeline)
- [x] Define extraction order (data first, math, then physics, then integration)
- [x] Cross-reference all 38 asm/ files to extraction tiers
- [x] Created workstreams/extraction_dependency_graph.md

### M23: Race Orchestration & Remaining Gameplay Gaps ✓
- [x] Analyze all 36 remaining undocumented 0x0600xxxx gameplay functions
- [x] Document camera positioning (FUN_0600AFB2 transform, FUN_0600B4D2 lerp)
- [x] Document race state calculation (FUN_0600C010 pipeline, 200+ insns)
- [x] Document race interpolation (FUN_0600CB90 bilinear, FUN_0600CDD0 heading)
- [x] Document physics dispatch chain (FUN_0600D31C 3-way dispatcher, FUN_0600D41C dynamics)
- [x] Document race frame orchestrator (FUN_0600E7C8, 6 subsystems)
- [x] Document game state machine (FUN_0600F424 dispatcher, FUN_0600F870 countdown, FUN_0600FFD0 HUD)
- [x] Document 19 transition handlers (FUN_0600F650-FUN_0600FED0)
- [x] Identify 3 functions needing urgent decompilation
- [x] Created asm/race_orchestration.s

### Gameplay Mapping: COMPLETE ✓
All gameplay-touching code in the binary has been mapped across 39 asm/ files.
Coverage: 500+ functions documented across all address ranges.
Remaining undocumented functions are rendering helpers and tiny stubs (not gameplay).

**3 functions flagged for decompilation** (needed for CCE transplant):
1. **FUN_0600B4D2** — Camera lerp (164 insns, self-contained, 50% convergence per frame)
2. **FUN_0600C010** — Race state machine (200+ insns, multi-stage pipeline)
3. **FUN_0600D41C** — Vehicle dynamics (140 insns, core physics chain)

---

## Key Resources

- `build/aprog.s` — Full disassembly (206K lines, 1234 functions)
- `build/aprog_syms.txt` — Function addresses
- `ghidra_project/` — Ghidra analysis (cross-reference, call graphs)
- `docs/subsystem_map.md` — Existing architecture notes

## Output Artifacts

**Annotated `.s` files only** in the `asm/` directory. No markdown, no docs — just assembly with inline comments.

These comments are written by Claude for Claude. They should capture everything needed to understand the code without re-doing any research. Optimize for:
- What each function/block achieves (not just what each instruction does)
- Data structure layouts and field meanings
- Hardware register purposes and addresses
- Cross-references to callers/callees
- Why the code works the way it does (intent, not mechanics)

Research notes and progress tracking go in THIS file (the workstream md), not in `asm/`.

**Format**: SH-2 mnemonics with `!` comments:
```asm
! === SMPC INTBACK Response Handler ===
! Reads controller data from Output Registers after INTBACK command completes.
! Called from the SMPC interrupt path. Stores raw peripheral data to 0x060A4C9C.
! This is the bottom of the input chain — everything above consumes the struct this builds.

    mov.l   @(0xE0,PC),r2   ! r2 = 0x060A4C9C (peripheral data struct base)
    mov.l   @(0xE4,PC),r3   ! r3 = 0x20100031 (SMPC OREG8)
    mov.b   @r3,r3           ! Read OREG8 — peripheral ID upper nibble
    mov.b   r3,@r2           ! Store to struct+0x00
```

## Saturn Documentation (to gather)

- Sega Saturn Hardware Manual
- SH-2 Programming Manual
- VDP1/VDP2 User's Manual
- SMPC User's Manual

---

## Research Notes

### SMPC Input System

Three-stage pipeline:
```
SMPC INTBACK (HW)  →  Raw OREG struct (0x060A4C9C)  →  Processed input (0x0605B6D8)  →  Game code
```

**SMPC registers used in aprog.s:**
| Address     | Register | Purpose |
|-------------|----------|---------|
| 0x2010001F  | COMREG   | Command register — write 0x19 for INTBACK |
| 0x20100021  | OREG0    | First output register |
| 0x20100031  | OREG8    | Peripheral ID upper |
| 0x20100033  | OREG9    | Peripheral ID lower / data size |
| 0x20100035  | OREG10   | Button data byte 1 |
| 0x20100037  | OREG11   | Button data byte 2 |
| 0x20100039-3F | OREG12-15 | Extended button/analog data |
| 0x20100061  | SR       | Status register |
| 0x20100063  | SF       | Status flag (bit 0 = busy) |

**Functions touching SMPC:**
| Function | Role |
|----------|------|
| FUN_060030FC (0x060030FC) | Sends INTBACK command (0x19) to COMREG, polls SF for completion |
| 0x06039924+ (inside FUN_0603953C) | INTBACK response handler — reads OREGs, writes to 0x060A4C9C |
| FUN_06006F3C (0x06006F3C) | Button input consumer — reads processed state from 0x0605B6D8 |

**Raw peripheral struct at 0x060A4C9C:**
```
+0x00: byte  — OREG8 (peripheral ID upper)
+0x01: byte  — OREG9 (peripheral ID lower)
+0x02: word  — OREG10<<8 | OREG11 (button data 1)
+0x04: long  — OREG12-15 combined (button data 2 + extended)
+0x08: byte  — OREG0 (additional peripheral data)
```

**Button bit assignments (from tst instructions in FUN_06006F3C):**
| Bit | Hex  | Likely Button | Context |
|-----|------|---------------|---------|
| 2   | 0x04 | Right?        | Calls 0x0602766C with sound params |
| 4   | 0x10 | Left?         | Similar dispatch pattern |
| 5   | 0x20 | Start?        | Similar dispatch pattern |
| 6   | 0x40 | A (gas)       | Loads data from 0x0605B710/0C area |
| 7   | 0x80 | B (brake)     | Longest handler, jumps to 0x0600713C |
| 29  | 0x20000000 | Special? | Tested separately before button checks |

### Game State Machine

32-state dispatch at main (0x06003000). Jump table at 0x0600307C.
State variable lives at 0x0605AD10.

**State handlers (from jump table):**
| State | Address    | Purpose |
|-------|------------|---------|
| 0     | 0x060088CC | Startup/init |
| 1     | 0x0600890A | Transition |
| 2     | 0x06008938 | Attract mode setup |
| 3     | 0x06008A18 | Title/demo |
| 4     | 0x06008CCC | Mode select |
| 5     | 0x06008D74 | Course select |
| 6-11  | various    | Transitions |
| 12    | 0x06008E00 | Pre-race setup |
| 13    | 0x06008E48 | Race countdown |
| **14**| 0x06008EBC | **In-race gameplay** (188 insns) |
| **15**| 0x06009098 | **In-race gameplay** (202 insns) |
| 16    | 0x06009290 | Lap transition |
| **17**| 0x060092D0 | **In-race gameplay** (228 insns) |
| 18    | 0x060096DC | Time extension |
| **19**| 0x06009788 | **Complex race state** (298 insns) |
| **20**| 0x06009A60 | **Race completion init** (→ state 21) |
| 21    | various    | Post-completion processing |
| 22-23 | various    | (unknown) |
| **24**| 0x06009CFC | **Post-race init** (→ state 25) |
| **25**| 0x06009D4E | **Post-race display loop** |
| 26-27 | various    | (unknown) |
| **28**| 0x06009508 | **Abort processing** (→ state 29) |
| **29**| 0x0600955E | **Post-race menu** (→ state 17/18/20) |
| 30-31 | various    | Post-race, menus, diagnostics |

**State 15 call chain (in-race):**
```
FUN_06009098 (state 15)
  → FUN_060268B0  (UI/menu — only if flag at 0x0605AB18 set)
  → FUN_060033E6  (sub-init — only if flag at 0x0607ED8C set)
  → FUN_060302C6  (sound system update)
  → FUN_0602EFF0  (rendering)
  → FUN_0602F0E8  (rendering)
  → FUN_0600DE54  (RACE STATE UPDATE — the key call)
    → FUN_0600E99C  (pre-update)
    → FUN_0600E0C0  (main race update — calls 3D scene processing at FUN_06027CA4)
```

### Vehicle Physics Area (0x0600D0B8-0x0600DC74)

Key data pointers:
- 0x0607E940 — game object pointer (copied each frame)
- 0x0607E944 — game object pointer (current)
- 0x0607EA98 — race position / car count
- 0x0607EBC4 — frame/state counter
- 0x06078900 — object data base

FUN_0600D0B8 does position/velocity clamping:
- Reads flags via mask 0x00C00000 from object+0
- Compares values at offset 0x200 between two objects (player vs track?)
- Clamps result between 0 and 0x0800
- Uses constants: 0x0200 (offset), 0x01FC (alt offset), 0xFE00 (negative clamp), 0x01F8, 0x0800 (max)

FUN_0600D3C4 does car sorting/ordering by track position:
- Reads from 0x0607E9EC (object list)
- Compares track position values
- Swaps object pointers when out of order (bubble sort)
- Stores final count to object

### Velocity Calculation (FUN_0600EA18)

This LEAF function computes per-frame velocity from track segment data:
1. Reads 4 fields from car+0x120..0x12C (track segment flags)
2. OR of all 4 = "any data present"; AND with bit 0x80 = special case
3. Maintains approach counter at 0x0605A228 (max 160 frames = ~2.7 sec at 60fps)
4. Computes delta: target_pos (from track segment at 0x0607EB88) minus current_pos
5. Divides by 16 (4x shar): velocity = delta >> 4
6. Angular velocity = (target_heading * 4 - current_heading), sign-extended

Track segment indexing: index * 512 + 48 bytes into the table.
Each segment has: X (long), Z (long), heading (word at +0xA).

**Velocity outputs (consumed by position integrator):**
| Address    | Value | Update |
|------------|-------|--------|
| 0x060786C0 | vel_X | (target_X - car_X) >> 4 |
| 0x060786C4 | vel_Z | (target_Z - car_Z) >> 4 |
| 0x060786C8 | ang_vel | sign_ext(target_heading*4 - heading) |

### Position Integration (at 0x0600E5B4)

Runs each frame when timer > 0 and flag 0x06078635 == 0:
```
car.X     += velocity_X     (offset +0x10)
car.Z     += velocity_Z     (offset +0x18)
car.heading += angular_vel  (offset +0x20, read as word not long!)
car[+0x28] = car[+0x30] = heading  (copy to secondary fields)
```
Then calls FUN_06006838(car.X, car.Z) to update tile grid coordinates.

### RESOLVED: Player vs AI Physics Path

**Branching point**: FUN_0600E1D4 (per-car update dispatcher)
- Reads car index from `0x0607EAD8`
- Car index 0 = player → calls **FUN_0600E71A** (controller-driven physics)
- Car index != 0 = AI → calls **FUN_0600E906** (track-following physics)

**Player physics pipeline** (FUN_0600E71A):
```
1. FUN_06008318 — Controller input: gear shift, steering column
2. 0x06008640  — Gear/force table selection
3. FUN_0600D266 — (stub: rts immediately, friction placeholder?)
4. FUN_0600C4F8 — Speed computation & velocity clamping
5. FUN_0600C5D6 — Collision detection, heading→position integration
6. (inline)     — Timer countdown, track segment check
7. FUN_0600CEBA — Track segment advancement & heading interpolation
8. (inline)     — Score/ranking computation
```

**AI physics pipeline** (FUN_0600E906):
```
1. FUN_0600D266 — (same stub as player)
2. FUN_0600C74E — AI-specific processing
3. FUN_06027552 — Heading computation (fixed-point multiply)
4. FUN_0600CEBA — Same track segment advancement as player
5. FUN_0600EA18 — Track-following velocity (target - current) >> 4
```

**Key difference**: Player uses force lookup tables driven by controller
buttons (gas/brake/steering). AI uses simple track-segment chasing.

### Gas/Brake → Acceleration Path

The acceleration chain from controller to position:

1. **SMPC → car flags**: Controller buttons are written to car object byte 0.
   Bit 0x40 = gas (A button), bit 0x80 = brake (B button).

2. **FUN_06008318**: Handles gear shifting (bits 0x10/0x20). Sets gear
   direction (+1/-1) and countdown timer. Looks up steering deflection
   from table at `0x060453CC`.

3. **0x06008640 → FUN_060086C0**: Selects force table based on game state:
   - Normal: `0x060453B4` (indexed by player_state & 1)
   - Special: `0x060453C4` (countdown mode)
   Calls `FUN_06034F78` twice (interpolation), then reads a 12-byte record:
   - word +0x04: steering factor
   - word +0x06: X force (negated)
   - word +0x08: Z force (negated)
   - word +0x0A: angular force (negated)

4. **Post-force (0x06008730+)**: Reads the current steering record.
   Car flag bits 0x40 (gas) and 0x80 (brake) determine which forces apply:
   - Gas: full force application from record
   - Brake: alternative force path
   Forces stored into car struct fields.

5. **FUN_0600C4F8**: Computes speed scalar from course data tables.
   `base_speed = table_A[segment] - table_B[segment] + 0xFEC00000`.
   Clamps to valid range. Stores to car+0x08.

6. **FUN_0600C5D6**: Position integration:
   ```
   heading = track_data[segment].heading → FUN_06027358 → (sin,cos)
   car.X += FUN_06027552(car.speed, X_direction)
   car.Z += FUN_06027552(car.speed, Z_direction)
   ```

### Car Object Struct Layout (Partial)

```
+0x000: byte  — flags (0x08=special, 0x10=shift_down, 0x20=shift_up,
                        0x40=gas, 0x80=brake)
+0x001: byte  — secondary flags
+0x004: long  — car index (0=player, 1..N=AI) — set by FUN_0600629C
+0x008: long  — speed (heading-relative scalar)
+0x00C: long  — distance accumulator (used in speed calc, FUN_0600E410)
+0x010: long  — X position (world)
+0x014: long  — Y position (world, typically 0)
+0x018: long  — Z position (world)
+0x01C: long  — rotation component A (pitch?)
+0x020: long  — heading (primary yaw angle)
+0x024: long  — rotation component C (bank?)
+0x028: long  — heading copy A (set = [0x20] during init)
+0x030: long  — heading copy B (set = [0x20] during init)
+0x034: long  — heading copy C (set = [0x20] during init)
+0x074: long  — initial value 56 (set during init)
+0x090: long  — initial value 56 (set during init)
+0x00B8: long  — gear shift countdown timer (32 frames) / proximity override
+0x00BC: long  — force secondary timer (countdown-40, blocks gear shifts)
+0x00D4: word  — mode field (20=force init, 40=gear shift, 10=steering cap)
+0x00FC: long  — clamped speed delta (per-frame, from speed curve)
+0x0E0: long  — computed speed value (from FUN_0600E410)
+0x0E4: long  — computed speed value copy
+0x120..0x12C — activation flags (4 longs, set to 1 during init)
+0x015C: long  — LAP COUNTER (incremented each completed lap)
+0x0161: byte  — state flags (bit 5 = steering override active)
+0x184: long  — current track segment index
+0x018C: long  — sin(-heading) result (from FUN_06027358)
+0x0190: long  — cos(-heading) result (from FUN_06027358)
+0x0194: long  — speed target (force system or course mode 3)
+0x0198: long  — speed scaling factor (per-car tuning parameter)
+0x01B4: long  — force speed reference (from record[0])
+0x01B8: long  — force running pointer (advances 12 bytes/frame)
+0x01BC: long  — force primary countdown (decrements to 0)
+0x01C0: long  — state bits (bits 30-31 from game state)
+0x01C8: long  — X force (from record, signed by gas/brake)
+0x01CC: long  — Z force (from record, signed by gas/brake)
+0x01D0: long  — angular force (from record, signed by gas/brake)
+0x01D8: long  — gear steering deflection (from table, ± by direction)
+0x01DC: long  — gear shift direction (+1=up, -1=down)
+0x1E0: long  — checkpoint table base pointer (24 bytes per entry)
+0x1E4: long  — current checkpoint index (wraps to 0 at lap boundary)
+0x1E8: long  — cumulative checkpoint count (progress toward lap)
+0x1EC: long  — checkpoint parameter (from table entry[0x16])
+0x1F0: long  — previous frame checkpoint parameter (for change detection)
+0x1F4: long  — ranking/position value
+0x200: long  — track position comparison value
+0x204: long  — steering correction countdown (decrements by 2 per frame)
+0x208: long  — timer copy (same as 0x00BC)
+0x021C: long  — timing sub-counter (incremented on late lap)
+0x0228: long  — state counter (incremented on lap events)
+0x0230: long  — position snapshot (for split time calculation)
+0x258: word  — gear shift sound parameter
+0x301: long  — gear direction (+1=up, -1=down)
+0x350: long  — steering deflection value
```

### Key Data Tables

| Address | Purpose |
|---------|---------|
| 0x060453B4 | Steering/force table A (normal racing) |
| 0x060453C4 | Steering/force table B (special state) |
| 0x060453CC | Gear steering lookup (signed word per frame) |
| 0x060454CC | Course speed table B |
| 0x060477EC | Course speed table A |
| 0x06078680 | Track collision/physics data base |
| 0x0607EB84 | Track segment table pointer |

### Shared Functions (Used by Both Player and AI)

| Function | Purpose |
|----------|---------|
| FUN_0600D266 | Friction stub (rts — no-op, called by both) |
| FUN_0600CEBA | Track segment advancement & heading interpolation |
| FUN_06027552 | Fixed-point multiply: r0 = (r4 × r5) >> 16 |
| FUN_06027358 | Heading → direction vector (sin/cos) |
| FUN_06035228 | Heading interpolation toward target |
| FUN_06034F78 | General interpolation function |

### Force Table Data Structures — COMPLETE

The force system is a **keyframe animation**: pre-baked arrays of 12-byte force records,
one per frame. The system plays through the array, applying forces based on gas/brake state.

**3-level table hierarchy:**
```
Level 0: Table pointers (select based on game mode)
  0x060453B4 — Table A (normal racing), indexed by (state&1)*8
  0x060453C4 — Table B (countdown/special), single entry

Level 1: Force descriptors (8 bytes each)
  [0]: long — pointer to force record array
  [4]: long — frame countdown (number of frames to play)

Level 2: Force record array (12 bytes per record)
  [0x00]: long — cumulative speed reference (monotonically increasing)
  [0x04]: word — steering response factor (~128 = unity)
  [0x06]: word — X force component (signed)
  [0x08]: word — Z force component (signed)
  [0x0A]: word — angular force component (signed)
```

**Two force profiles:**
- Profile A: 64 records at 0x0604508C (gentle, ~1.07 sec, normal racing)
- Profile B: 85 records at 0x06044C90 (aggressive, ~1.42 sec, countdown mode)
- Profile B has ~12x larger X forces than Profile A

**Force sign convention (gas/brake):**
| Input   | X force      | Z force      | Angular      |
|---------|-------------|-------------|-------------|
| Gas     | +record[6]  | -record[8]  | -record[0xA] |
| Brake   | -record[6]  | -record[8]  | +record[0xA] |
| Neutral | record[6]   | record[8]   | record[0xA]  |

Physical interpretation: gas = forward thrust with drift/rotation resistance,
brake = deceleration with looser steering, neutral = coasting.

**Contiguous memory layout:**
```
0x06044C90: Profile B data (85 × 12 = 1020 bytes)
0x0604508C: Profile A data (64 × 12 = 768 bytes)
0x0604538C: Level 1 descriptors
0x060453B4: Table A pointers
0x060453C4: Table B pointer
0x060453CC: Gear steering lookup table
```

**Gear steering lookup** (0x060453CC):
- 33+ signed 16-bit words, forming an S-curve
- Indexed by countdown timer (word-indexed: `timer × 2 + base`)
- Profile: 0 → +29557 → -32768 → -158 → +64 (overshoot + settle)
- Timer starts at 32 frames (~0.53 sec), decrementing each frame
- For downshift: all values negated
- Creates momentary steering kick when shifting gears

**Gear shift detection** (FUN_06008318):
- Car[0] bit 0x10 = shift down, bit 0x20 = shift up
- Only when state > 600 frames (~10 sec into race)
- Only when car[0x00BC] == 0 (no force system active)
- Sets: car[0x00B8]=32 (timer), car[0x01DC]=±1 (direction)
- Button flags consumed via FUN_06034F78 (cleared each frame)

**Car struct fields for force system:**
```
+0x00B8: long — gear shift countdown (32 frames, decrements)
+0x00BC: long — force secondary timer (countdown - 40, blocks gear shift)
+0x00D4: word — mode field (20=force init, 40=gear shift, 10=steering cap)
+0x01B4: long — speed reference from record[0]
+0x01B8: long — running force pointer (advances 12 bytes/frame)
+0x01BC: long — primary countdown (from descriptor, decrements to 0)
+0x01C0: long — state bits (bits 30-31 from game state via FUN_06034F78)
+0x01C8: long — X force (signed by gas/brake)
+0x01CC: long — Z force (signed by gas/brake)
+0x01D0: long — angular force (signed by gas/brake)
+0x01D8: long — gear steering deflection (from table, ± by direction)
+0x01DC: long — gear direction (+1=upshift, -1=downshift)
+0x0208: long — timer copy (same as 0x00BC)
```

### Speed Curve & Position Integration

**Speed curve** (FUN_0600C4F8): Two course-specific tables define the speed envelope:
```
table_A at 0x060477EC — "thrust" curve (large values, ~0x0BD5xxxx)
table_B at 0x060454CC — "drag" curve (small values, ~0x0010xxxx)

base_speed = table_A[speed_idx] - table_B[speed_idx] + 0xFEC00000
target     = ((base_speed >> 16) * car[0x198]) >> 16
half       = target >> 1
delta      = car[0x194] - car[0x0C]
delta      = clamp(delta, -4014, half)
car[0x0C] += delta                       (floored at 0)
car[0x08]  = sext16((car[0x0C] * 72) >> 16)
```

The net force `(table_A - table_B)` decreases as speed increases, creating the characteristic
racing game acceleration curve: fast off the line, gradually approaching terminal velocity.

**Speed limiter**: When `car[0xBC] > 0` OR `car[0xB8] != 0` (collision/brake active),
the speed delta is forced to -4014 (0xF052), causing rapid deceleration regardless of tables.

**State flag bypass**: When `*0x0607EBC4 & 0x8000` (bit 15), speed calculation is skipped
entirely — used during countdown and special states.

**Table data samples** (first 5 entries):
| Index | Table A | Table B | Net (A - B) |
|-------|---------|---------|-------------|
| 0 | 0x0BD52BD3 | 0x00100000 | 0x0BC52BD3 |
| 1 | 0x0BD52BD3 | 0x001008A1 | 0x0BC52332 |
| 2 | 0x0BFCE38E | 0x00101328 | 0x0BECD066 |
| 3 | 0x0C249B4A | 0x00101F96 | 0x0C147BB4 |
| 4 | 0x0C249B4A | 0x00102DEC | 0x0C146D5E |

**Position integration** (FUN_0600C5D6): Converts speed accumulator into world movement.

Three paths based on car state:
1. **Course following** (CA96): When game_mode==2, force countdown active, or braking.
   Smooth position interpolation from course reference data.
2. **Flat ground sin/cos**: When car flags bits 21-23 all clear.
   ```
   car.X += (car[0x0C] * sin(-heading)) >> 16
   car.Z += (car[0x0C] * cos(-heading)) >> 16
   car.Y  = 0
   ```
3. **3D transform**: When car flags bits 21-23 set (banked turns, airborne).
   Full matrix transform via FUN_06006838 + FUN_06027EDE.

**Steering correction** (FUN_0600CF58): Applied only when:
- Car flags bit 3 and bit 5 clear
- General timer car[0x208] <= 0
- Collision counter (*0x0607EBDC) <= 10
- Track position car[0x204] < 102

When correction is active, car[0x204] counts down by 2 each frame (smooth return).

**Game mode 3 speed target**: In mode 3, the speed target car[0x194] is computed from
the next checkpoint's course data: `car[0x194] = (checkpoint[8] * car[0x198]) >> 16`.
This allows course geometry to directly control speed targets.

**New car struct offsets** (speed/position system):
```
+0x00FC: long  — clamped speed delta (written each frame)
+0x0161: byte  — state flags (bit 5 = steering override active)
+0x018C: long  — sin(-heading) result
+0x0190: long  — cos(-heading) result
+0x0194: long  — speed target (from force system or course data)
+0x0198: long  — speed scaling factor (per-car tuning parameter)
+0x0204: long  — steering correction countdown (decrements by 2)
```

### Object Management System

**Car array**: 40 slots at 0x06078900, each 0x268 (616) bytes. Total = 24640 bytes,
ending at 0x0607E940. The global pointer variables sit immediately after the array:

```
0x06078900 ┌──────────────┐
           │  car[0]      │  0x268 bytes (PLAYER)
0x06078B68 ├──────────────┤
           │  car[1]      │  0x268 bytes (AI #1)
0x06078DD0 ├──────────────┤
           │  car[2]      │  ...
           │  ...         │
           │  car[39]     │  (max capacity)
0x0607E940 ├──────────────┤
           │  cur_car_ptr │  4 bytes (working)
0x0607E944 ├──────────────┤
           │  car_ptr_pri │  4 bytes (primary/stored)
0x0607E948 ├──────────────┤
           │  car_ptr_sec │  4 bytes (secondary, typically car[1])
           └──────────────┘
```

**Initialization flow** (called from state handlers entering race):
```
State handler -> FUN_0600EB14 (master init)
  -> Zero entire car array (40 × 616 bytes)
  -> FUN_06026E02, FUN_060270C6 (subsystem inits)
  -> FUN_0600629C (car init loop)
       for i in 0..car_count:
         car[i] = base + i * 0x268
         car[i][0x04] = i              (store car index)
         FUN_0600E1D4(car[i])          (type-based init from config table)
  -> Set car[0] activation flags at +0x120..+0x12C = 1
  -> Zero ~30 global state variables
```

**Per-frame update flow** (called from State 15 main race loop):
```
State 15 -> FUN_0600DE70 (per-frame iteration)
  for each car (0 to *0x06078634):
    FUN_0600E4F2(car)                  (9-stage per-car update)
  -> FUN_0600A8BC (audio)
  -> FUN_0602F7EA / FUN_06034900 (render finalize)
  -> FUN_0602F99C (frame finalize)
```

**FUN_0600E4F2 — Per-car update pipeline** (9 stages):
1. Force system: FUN_060081F4, FUN_060085B8
2. Subsystem: FUN_06030A06, FUN_06030EE0
3. Physics integration (FUN_0602ECF2) OR demo velocity playback
4. 3D rendering: FUN_06027CA4 × 4 scene passes (normal mode only)
5. Lap counting: FUN_0600DB64 (PLAYER ONLY, when r12==0)
6. Proximity/checkpoint: FUN_0600DA7C, FUN_0600D780
7. Collision: FUN_0600CE66
8. Track position: FUN_0603053C, FUN_0600C994
9. AI behavior: FUN_0600EA18 (AI ONLY, normal mode)

Player/AI determination: `car == car[0]` → player (r12=0), else AI (r12=1).

**Config table at 0x06047DE4** (12-byte entries per car type):
```
+0x00: word16 — car type (3=standard, 4=extended)
+0x02: word16 — initial heading angle (signed, grid position)
+0x04: word16 — secondary table index (into 0x06047DD0)
+0x06: word16 — tertiary table index (into 0x06085FD0)
+0x08: word16 — car class (2=player, 1=AI)
+0x0A: word16 — reserved (0)
```

Decoded entries (first 7):
| Index | Type | Heading | Class | Notes |
|-------|------|---------|-------|-------|
| 0 | 3 | 0xF555 (-2731) | 2 | PLAYER — pole position |
| 1 | 3 | 0xE38E (-7282) | 1 | AI — grid row 1 |
| 2 | 3 | 0xEAAA (-5462) | 1 | AI — grid row 1 |
| 3 | 3 | 0xF1C7 (-3641) | 1 | AI — grid row 2 |
| 4 | 3 | 0xF8E3 (-1821) | 1 | AI — grid row 2 |
| 5 | 4 | 0x6000 (+24576) | 1 | AI — grid row 3 (type 4) |
| 6 | 4 | 0x71C7 (+29127) | 1 | AI — grid row 3 (type 4) |

**Update mode dispatch** (FUN_0600DF66, alternative to main loop):
- Mode 0 → FUN_0600E410 (simplified: force + physics + speed calc)
- Mode 1 → FUN_0600E47C (alternative update path)
- Mode 2 → FUN_0600E47C (same)
- Used during countdown, replay, and special states

**Demo/replay mode** (when *0x060786BC > 0):
- Bypasses physics integration entirely
- Applies pre-recorded velocities from globals:
  - car[0x10] += *0x060786C0 (X velocity)
  - car[0x18] += *0x060786C4 (Z velocity)
  - car[0x20] += *0x060786C8 (angular velocity)
- Skips 3D rendering passes
- Countdown decrements each frame

**Key global variables:**
| Address | Type | Purpose |
|---------|------|---------|
| 0x0607EA98 | long | Car count (active cars) |
| 0x06078634 | byte | Car count (byte copy, per-frame loop) |
| 0x06078635 | byte | Special mode flag (0=normal) |
| 0x0607E940 | long | Current car ptr (working) |
| 0x0607E944 | long | Current car ptr (primary) |
| 0x0607E948 | long | Secondary car ptr |
| 0x0607EAD8 | long | Player mode (0=single) |
| 0x060786BC | long | Demo/replay countdown |
| 0x060786CA | word | Half-car-count |
| 0x06083261 | byte | Update mode (0/1/2) |

### VDP1 Rendering System

**Rendering pipeline** (called every in-race frame from states 14/15/17/19):
```
FUN_0602EFF0 — Rendering Pass 1: Camera/viewport setup
  → Hardware DIVISION via FUN_0602ECCC (called 3× — NOT matrix multiply)
  → FUN_0602ECCC uses SH-2 divider at 0xFFFFFF00 (DVSR/DVDNT registers)
  → Disables interrupts during division (ldc #0xF0,sr)
  → Three divisions: horizontal, vertical, depth viewport dimensions
  → Viewport clipping against boundaries [0x38, 0xB8]

FUN_0602F0E8 — Rendering Pass 2: Frame buffer / command table
  → Read FBCR register (frame buffer swap control)
  → Build VDP1 command table entries
  → Sprite/polygon sorting by priority
  → Write draw-end marker
```

**VDP1 registers used:**
| Address | Register | Purpose |
|---------|----------|---------|
| 0x25C00000 | VDP1 base | Command list control |
| 0x25C80000 | VDP1 VRAM | 64KB command table buffer |
| 0x25D00000 | TVMR | TV mode (3-bit) |
| 0x25D00002 | FBCR | Frame buffer swap |
| 0x25D00004 | PTMR | Polygon timing (set to 2) |
| 0x25D00008 | EWDR | Erase/write data register |
| 0x25D0000A | EWLR | Erase window left |
| 0x25D0000E | EWRR | Erase window right |

**VDP1 initialization** (FUN_0600A140):
- Clears 64KB VRAM at 0x25C80000 (two passes for double-buffer)
- Sets TVMR register
- Calls FUN_06026CE0 (texture/palette setup)

**Double-buffer mechanism**: FBCR register alternates each frame between
two 32KB halves of VDP1 VRAM.

### Lap Counting System

Complete per-frame flow for detecting and counting lap completions:

```
Frame N:
  FUN_0600CE66 → FUN_0600CD40   checkpoint crossing detection (angle-based)
  FUN_0600D780                    checkpoint change detector
    → FUN_0600D9BC               set lap flag (via FUN_06034F78 bitfield utility)
    → FUN_0600D92C               record lap timing data

Frame N+1:
  0x0600DB64                     test flag, clear it, increment car[0x015C]
  FUN_0600DBA0                   finish line display effects
```

**Checkpoint system**: Track is divided into N checkpoints (24 bytes each, at car[0x01E0] base).
FUN_0600CD40 computes angle from car to checkpoint center using atan2. When angular
difference exceeds checkpoint half-width * 4, advances to next checkpoint. When index
exceeds total (stored at *0x0607EA9C), wraps to 0.

**Lap detection**: FUN_0600D780 compares car[0x01EC] (current checkpoint param) vs
car[0x01F0] (previous frame). Three paths:
- Path A: large backward jump (change < -1) — checkpoint wrap, if cumulative == total → lap
- Path B: large forward jump (change > 1) — if progress >= total/2 → lap
- Path C: single step (|change| <= 1) — normal advance, no lap trigger

**Lap flag mechanism**: One-shot flag at byte+2 bit 2 (bit 10 of 32-bit car flags word).
Set by FUN_0600D9BC via FUN_06034F78(value=1, param=0x1501, car_ptr). The parameter
0x1501 encodes bit_position=21 from MSB, bit_count=1. Consumed next frame at 0x0600DB64
which clears it and increments car[0x015C].

**FUN_06034F78 bitfield utility**: General-purpose read-modify-write for arbitrary bit
fields in 32-bit words. Parameters: r0=value, r1=packed(high_byte=bit_pos_from_MSB,
low_byte=bit_count), r2=pointer. Builds a mask, shifts to position, read-modify-writes.
Known parameter decodings:
| Param  | bit_pos | count | actual_bit | Meaning |
|--------|---------|-------|------------|---------|
| 0x1501 | 21      | 1     | 10         | byte+2 bit 2 (lap flag) |
| 0x1C01 | 28      | 1     | 3          | byte+3 bit 3 (finish proximity) |
| 0x0301 | 3       | 1     | 28         | byte+0 bit 4 |
| 0x0201 | 2       | 1     | 29         | byte+0 bit 5 |
| 0x0801 | 8       | 1     | 23         | byte+1 bit 7 |
| 0x0901 | 9       | 1     | 22         | byte+1 bit 6 |

**Per-car bitmask**: 0x06063F1C tracks which cars have completed a lap this cycle.
FUN_06035280 generates per-car bit (1 << car_index). Prevents double-counting.
Previous cycle bitmask saved at 0x06063F18, copied on lap completion.

**Finish line display**: FUN_0600DA7C detects proximity to finish line (sets bit 3 of
byte+3), increments counter at 0x06078698. When counter reaches threshold (4),
FUN_0600DBA0 triggers "LAP" text animation via FUN_0601D5F4 (VDP sprite display).

**Key discovery**: Pool constant 0x1501 at address 0x0600DA52 was disguised in the
disassembly as `.byte 0x15, 0x01 /* mov.l r0,@(0x4,r5) */` — the disassembler
interpreted pool data bytes as an instruction mnemonic. Found by tracing the code flow
in FUN_0600D9BC and manually computing the pool address from `mov.w @(0x17*2+PC),r1`.

### AI Processing Pipeline (FUN_0600C74E) — COMPLETE

The AI main processing function at FUN_0600C74E orchestrates all behavior for one AI car per frame. It's called from FUN_0600E906 after basic setup.

**9-step pipeline:**
1. **FUN_0600CD40** — Waypoint targeting: finds next waypoint using 24-byte records, computes atan2 approach angle, bumps "missed" counter if angle too far off
2. **0x0600CA96** — Course correction: smooths position tracking between waypoints, interpolates between adjacent records using weighted average (mul + shar×2)
3. **Inline speed zone check** — If track position in [46, 59]: override target speed with fixed value 0x4000; otherwise call FUN_0600C8CC
4. **FUN_0600C8CC** — Speed targeting: computes distance/angle to waypoint, adjusts speed based on approach angle mismatch
5. **Copy** target heading from +0x28 to +0x20
6. **0x0600C970** (conditional) — Speed boost lookup: 30-entry table at 0x0605A1E0, indexed by track position [69-98], adds signed word to acceleration
7. **0x0600C928** — Velocity/friction: computes drag proportional to speed (speed >> 9, then scale × 256), subtracts from both velocity components at +0x48 and +0x50
8. **FUN_0600C7D4** — Heading/steering: SPEED-BASED DAMPING is the key insight:
   - Speed > 280: shar×3 (heavy damping, sluggish at high speed)
   - Speed > 250: shar×2 (medium)
   - Speed > 220: shar×1 (light)
   - Speed ≤ 220: no damping (full steering)
   Then converts heading to X/Z via sin/cos lookup (0x06027358), multiplies by speed (0x06027552), updates position
9. **0x06006838 + FUN_06027EDE** — Grid index packing and sprite/rendering update

**Key AI data structures:**
| Address | Size | Description |
|---------|------|-------------|
| 0x0607E940 | ptr→struct | AI state pointer (indirected) |
| 0x06078680 | struct | Track/course data base |
| 0x0607EB88 | ptr→array | Waypoint table (24 bytes per record) |
| 0x0605A1E0 | 30 words | Speed boost table (for track positions 69-98) |

**Waypoint record layout (24 bytes):**
```
+0x00: long  — X position
+0x04: long  — Z position
+0x08: word  — turn rate
+0x0A: word  — scaled turn rate
+0x0C: word  — heading data
+0x0E: word  — steering factor
+0x16: word  — yaw angle (heading)
```

**AI decision points identified:**
1. Speed zone [46,59] — fixed override speed (perhaps a straight section)
2. Speed boost zone [69,98] — per-segment speed profile from table
3. Heading damping varies with speed — realistic physics: less agile at high speed
4. Waypoint "missed" counter resets after exceeding car_count — prevents permanent locking
5. Timeout at 160 frames in track-following (0x0600EA18) — resets if AI gets stuck

**AI vs Player comparison summary:**
| Aspect | Player | AI |
|--------|--------|----|
| Speed control | Force tables from gas/brake buttons | Waypoint distance + speed table |
| Steering | Controller input → force lookup | Heading delta with speed-based damping |
| Velocity | Force → speed → heading × speed | (target - current) >> 4 |
| Friction | Stub (FUN_0600D266 = nop) | Drag proportional to speed (0x0600C928) |
| Track advancement | FUN_0600CEBA (shared) | FUN_0600CEBA (shared) |

## Progress Log

### Session 2026-02-06
- Workstream created
- Pivot from C decompilation to direct ASM analysis
- Goal: trace from hardware interfaces to gameplay code
- Traced SMPC input chain end-to-end (HW → struct → game code)
- Mapped all 32 game state handlers from jump table
- Traced state 15 call chain to race update system
- Traced full velocity calculation chain:
  - FUN_0600EA18 computes velocity from track segment delta
  - velocity = (target_position - current_position) >> 4
  - Writes to 0x060786C0/C4/C8 (X vel, Z vel, angular vel)
  - Position integration at 0x0600E5B4: pos += vel each frame
- Created annotated .s files: input_smpc.s, game_loop.s, race_update.s
- Open question: FUN_0600EA18 appears to be a track-following "chase" behavior
  (approaching target positions along track segments). This may be the AI/demo
  path. Player input → acceleration path still needs to be traced separately.
- **RESOLVED**: Traced player vs AI branching at FUN_0600E1D4:
  - Car index 0 (player) → FUN_0600E71A (controller-driven, force tables)
  - Car index != 0 (AI) → FUN_0600E906 (track-following via FUN_0600EA18)
- Traced complete player physics pipeline (8 steps):
  FUN_06008318 → 0x06008640 → FUN_0600D266 → FUN_0600C4F8 → FUN_0600C5D6 → timers → FUN_0600CEBA → score
- Traced gas/brake → acceleration path:
  - Car flag byte 0: bit 0x40 = gas, bit 0x80 = brake
  - Force tables at 0x060453B4/C4 contain 12-byte records (steering, X/Z/angular forces)
  - FUN_060086C0 reads forces, negates, stores to car struct
  - FUN_0600C5D6 integrates: car.X/Z += FUN_06027552(speed, direction)
- Discovered FUN_0600D266 is a stub (rts only) — friction is NOT a separate step
- Created annotated asm/player_physics.s documenting full player + AI physics
- Documented partial car object struct (25+ fields identified)
- Identified 6 shared utility functions used by both player and AI
- Traced force table data structures:
  - 0x060453B4/C4 are pointers TO force records (not direct data)
  - Force records are 12 bytes: pointer + steering + X/Z/angular forces
  - 0x060453CC is the direct gear steering lookup (signed words)
- Traced VDP1 rendering chain:
  - FUN_0600A140 initializes VDP1 (clears 64KB VRAM at 0x25C80000)
  - FUN_0602EFF0: camera/viewport setup (3× matrix multiply, clipping)
  - FUN_0602F0E8: frame buffer management, command table building
  - Double-buffer via FBCR register at 0x25D00002
  - Identified 7 VDP1 registers used (TVMR, FBCR, PTMR, EWDR, EWLR, EWRR)
- Updated milestones: M4 (Rendering) now partial, M5 (Physics) complete, M6 (AI) partial
- Traced FUN_0600C74E complete AI processing pipeline (9 steps):
  - FUN_0600CD40: waypoint targeting with atan2 angle check
  - 0x0600CA96: waypoint interpolation (weighted average between adjacent records)
  - Inline speed zone [46,59] with override value
  - FUN_0600C8CC: speed targeting from waypoint distance
  - 0x0600C970: speed boost table (30 entries at 0x0605A1E0 for positions 69-98)
  - 0x0600C928: drag/friction proportional to speed
  - FUN_0600C7D4: heading with SPEED-BASED DAMPING (3 thresholds: 280/250/220)
  - 0x06006838: grid coordinate packing (64×N grid, 21-bit shift)
  - FUN_06027EDE: sprite/rendering update
- Traced 0x0600EA18 track-following velocity in detail:
  - 160-frame timeout mechanism (resets if AI stuck for ~2.7 seconds)
  - Flag checking: bits 0x80 and 0x33 control velocity reset
  - Velocity = (waypoint - car) >> 4 for X, Z, heading
  - Zeroes speed/acceleration fields, sets flag words to 1
- Waypoint records are 24 bytes each (not 20 as initially estimated)
- Created asm/ai_behavior.s with full annotated AI pipeline
- Updated M6: AI Analysis now mostly complete (only difficulty scaling remains)
- Key insight: AI speed-based heading damping creates realistic behavior —
  at high speed the car steers sluggishly, at low speed it's very responsive
- CORRECTED: FUN_0602ECCC is NOT a matrix multiply — it's HARDWARE DIVISION
  - Uses SH-2 divider unit at 0xFFFFFF00 (DVSR, DVDNT, quotient registers)
  - Disables all interrupts during division (SR = 0xF0) to protect registers
  - Three calls in FUN_0602EFF0: one per viewport dimension (H, V, depth)
- Camera pipeline detailed analysis:
  - Raw delta → |abs| → subtract deadzone 0xAC → clamp → sign restore
  - Scale by 0xFF → divide by base → store as viewport coordinate
  - Clamp to [0x38, 0xB8] (56-184 pixels on 320-wide display)
  - Exponential smoothing: (raw<<8 + running_avg) >> 1
  - Track position wrapping at 0x71C (1820 units = course length)
  - Course-aware boundaries from tables at 0x060477AC / 0x0604779C
- Updated asm/rendering.s with corrected FUN_0602ECCC analysis + annotated code
- Began tracing speed curves from course tables (FUN_0600C4F8):
  - table_A at 0x060477EC and table_B at 0x060454CC are arrays of 32-bit values
  - Indexed by car[+0x08] × 4 (track segment index)
  - base_speed = table_A[segment] - table_B[segment] + 0xFEC00000
  - Result passed through FUN_06027552 (fixed-point multiply) twice
  - First multiply: base_speed × 1 (identity/sign normalization)
  - Second multiply: result × car[field] (some scaling factor)
  - Final clamping: value / 2, clamp between r12 and computed bounds
  - Accumulator at car[+0x0C] updated: acc += delta, floor at 0
  - Final speed = (acc × 0x00480000) >> 16, sign-extended to word
  - Stored to car[+0x08] — this IS the speed field
  - table_B data at 0x060454CC: starts with ascending values (0x0010, 0x0010, 0x08A1, ...)
    suggesting per-segment speed differentials
  - table_A data at 0x060477EC: values like 0x0BD5_2BD3 — large fixed-point numbers
  - 0x060454CC also referenced by FUN_0602F6B6 (rendering) — dual-use table
  - Speed curve = difference between two course profiles, creating hills/valleys of speed
- Traced VBlank interrupt system (M3 complete):
  - VBlank-IN handler: FUN_06006F3C (registered as SCU vector 0x40)
  - VBlank-OUT handler: FUN_06007268 (registered as SCU vector 0x41)
  - Registration via BIOS function at 0x06000300(vector, handler)
  - SCU interrupt mask at 0x25FE00A4 — bit 1 enables VBlank-OUT
  - VBlank counter at 0x0607864C (incremented every 1/60s)
  - Phase tracking at 0x06059F54: 1=IN, 3=OUT-start, 4=OUT-end
  - Frame buffer swap via VDP1 FBCR register (0x25D00002)
  - ADAPTIVE frame timing: per-state target table at 0x06059F58+state_index
  - VBlank-OUT handler compares OUT count vs target before swapping
  - Main loop does NOT explicitly wait for VBlank — sync is implicit
  - VBlank-IN also processes controller input (button -> sound dispatch)
  - Frame buffer state machine manages TVMR/FBCR writes during VBlank
- Traced CD block status reading chain:
  - FUN_06018EAC -> FUN_060349C4 -> FUN_06034A10 -> FUN_06035E5E
  - Reads CD response registers at 0x25890018-0x25890024 (CR1-CR4)
  - Uses consistent double-read (interrupts disabled, compare, retry 100x)
  - Per-frame check in FUN_0600A392: if CD status == 6 (tray open), call BIOS
- Traced sound system reset (FUN_06018EE4):
  - SMPC SNDOFF (command 7) -> halt 68000
  - SCSP master control write (0x25B00400 = 0x0200)
  - Sound data setup -> SMPC SNDON (command 6) -> restart 68000
  - Handshake: poll 0x25A02DBC until 68000 writes 0x4F4B ("OK")
  - SCSP volume init: 0x25B00217 = 0x25B00237 = 0xE0
- Updated BIOS function table understanding:
  - 0x06000300: interrupt handler registration (r4=vector, r5=handler)
  - 0x06000344: interrupt mask control (r4=mask, r5=flags)
  - 0x0600026C: BIOS service call (used when CD tray open)
- Created asm/vblank_system.s with full annotated VBlank system
- Traced 3D rendering pipeline data structures (M4):
  - Polygon data pool at 0x060A6000: 52-byte entries (0x34 per polygon)
    - 4-vertex quadrilaterals with per-vertex transform parameters
    - Bit flags: 0x01/02/04/08000000 control coordinate system transforms
    - Each entry: flags, multiply factors, add offsets, base color/material
  - Course segment lookup at 0x060C2000: maps course sections to polygon indices
    - 4-byte entries: polygon_index (word) + polygon_count (word)
  - Texture/material index at 0x060BF000: maps visual properties to texture resources
  - VDP1 command generation: 7 functions at 0x0602C494-0x0602D43C
    - Build standard 32-byte VDP1 command blocks (CMDCTRL, CMDLINK, CMDPMOD, etc.)
    - Write to 0x25C80000 (VDP1 VRAM command table)
    - Link commands via CMDLINK fields for hardware traversal
  - FUN_06027CA4: main 3D scene processor
    - Reads polygon data from 0x060A6000 pool
    - Transforms vertices using 32-bit fixed-point matrix math
    - Culls back-facing polygons
    - Outputs to VDP1 command builders
  - FUN_0602F0E8: track position management (NOT command building)
    - Exponential smoothing on obj[+0x68] = (obj[+0xB0] << 8 + old) >> 1
    - Position wrapping within course length (0x71C = 1820 units)
    - Segment boundary detection using tables at 0x060477AC/0x0604779C
    - Per-segment scaling via 0x060477CC table with fixed-point multiply
- Traced collision detection & response system (M5 collision complete):
  - FUN_0600C5D6: main player collision handler + position integration
    - Three paths: course correction, heading update, collision response
    - Position integration: X += speed*sin(heading), Z += speed*cos(heading), Y=0
  - FUN_0600CD40: track-relative position query
    - Computes angle to track segment center via FUN_0602744C (atan2)
    - Detects off-track condition (angle > segment_width * 4)
    - Off-track counter with global threshold at [0x0607EA9C]
  - FUN_0600CA96: gentle course correction (dead zone ±8, step ±4)
    - Sin/cos vector table at 0x0607EB88 with linear interpolation
    - 256-entry direction table indexed by heading byte
  - FUN_0600CC38: stronger heading correction (step ±8)
    - Same sin/cos lookup, wider correction for normal driving
  - FUN_0600CF58: collision response dispatcher (224 instructions)
    - Early exits: no partner, speed < 150 (0x96), no collision flags
    - Calls FUN_06035168 for geometry classification
    - Head-on (bit 0x02): speed comparison → passive or heading snap
    - Side hit (bit 0x01): mode 2 = aggressive, mode 1 = proportional heading
    - Default: passive response
  - FUN_0600D12C: passive collision response (position separation)
    - Z threshold: 0x80000, X threshold: 0x0F0000
  - FUN_0600D210: aggressive collision response (speed-based push)
    - Speed delta must be in [-768, 768] range
    - Push ±16 per frame, clamped to [0, 2048]
    - Sets 64-frame collision timer
  - FUN_0600C928: speed reduction during collision
    - Reduces car[+0x48] and car[+0x50] by computed deceleration
  - FUN_0600C970: AI-only speed boost from course table
    - Table at 0x0605A1E0, segments [69,98] only
    - This is likely rubber-banding / difficulty mechanism
  - Created asm/collision.s with full annotated assembly
- Traced VDP1 sprite sorting / draw-order system (M4 complete):
  - FUN_06027CA4: 3D scene processor (culling, transform, command generation)
  - **NO runtime sorting algorithm** — polygon draw order is pre-baked in course data
  - Course segment table at 0x060C2000: (polygon_start, polygon_count) per segment
  - Segments traversed back-to-front based on camera Z position
  - Camera position → segment range: (cam_Z + 0x04000000) >> 21
  - Per polygon: material lookup at 0x060BF000, data from 0x060A6000 (52-byte entries)
  - Matrix transform via dmuls.l (64-bit signed multiply)
  - Backface/frustum culling via sign tests on transformed coordinates
  - Flag bits control coordinate system (0x01/02/04/08000000)
  - VDP1 commands built incrementally in traversal order → painter's algorithm
  - 7 command builders at 0x0602C494-0x0602D43C create 32-byte VDP1 command blocks
  - CMDLINK field chains commands for VDP1 hardware linked-list traversal
  - FUN_0602DB22: per-frame command list reset (zeros state vars, sets depth scaling)
  - Mode 2 path uses overlay table at 0x06061270 for special segment rendering
  - Updated asm/rendering.s with scene processor documentation
- Traced difficulty scaling system (M6 complete):
  - **No traditional rubber-banding** — AI speed does NOT depend on race position
  - Speed boost table at 0x0605A1E0: 30 signed word entries, segments [69, 98]
    - Segments 69-73: deceleration (-200 to -800) — entering a major corner
    - Segments 74-75: neutral (0)
    - Segments 76-98: acceleration (+50 to +400) — exiting corner, progressively weaker
    - Profile: brake hard into corner, strong acceleration out, tapering off
  - FUN_0600C970: applies table values to car[+0x0C] (speed accumulator)
    - Only called for AI cars (from FUN_0600C74E)
    - Only when car[+4] == 0 (no active collision partner)
  - FUN_0600C74E segments [45, 60]: AI forced heading override
    - Cars get a fixed heading angle forced at specific turn
    - Prevents AI from computing its own racing line through this section
  - FUN_0600CD40: off-track detection with configurable threshold
    - Counter at car[+offset] incremented each frame when off-track
    - Threshold at [0x0607EA9C] controls max off-track frames before reset
  - Game mode/difficulty params around 0x0605AD00-0x0605AD20
    - 0x0605AD10: game state (32-state machine index)
    - Referenced by state handlers for configuration
  - **Summary**: difficulty comes from track geometry design + per-segment speed profiles,
    not from adaptive rubber-banding. All AI cars use the same speed table.
- Traced complete sound/SCSP system:
  - **Architecture**: SH-2 → shared sound RAM mailbox → 68000 sound driver → SCSP
  - **Command mailbox**: 0x25A02C20 in sound RAM
    - SH-2 writes 32-bit command, 68000 reads and clears to 0
    - FUN_0601DB84: busy-wait with 100K iteration timeout
  - **Sound command format**: 0xAAGGIIFF
    - 0xAE = sound trigger prefix, GG = group, II = ID, FF = play flag
    - Group 00 = system/stop, 06 = BGM, 11 = gameplay SFX
  - **Main API**: FUN_0601D5F4 (r4=type, r5=param) — 30+ call sites
    - type 0: direct command, type 1-5: channel volume/config, type 15: alias for 0
  - **Sound init** (FUN_06018EE4):
    - SMPC SNDOFF (cmd 7) → clear 512KB sound RAM → DMA driver code/data
    - SMPC SNDON (cmd 6) → wait for 68000 ready (0x25A02DBE == 0xFFFF)
    - SCSP common register config at 0x25B00400
    - Master volume: 0xE0 to slot 16/17 EFSDL registers
  - **CORRECTION**: FUN_0602766C is NOT sound dispatch — it's generic SCU DMA
    - Registers: D0R/D0W/D0C at 0x25FE0000, DSTA poll at 0x25FE007C
    - Used for VDP2 palette uploads, sound data, general transfers
  - **Known sound IDs from gameplay callers**:
    - 0xAE0001FF: system/stop sound (state transitions)
    - 0xAE0600FF: BGM start
    - 0xAE1114FF: periodic in-race SFX (engine? triggered at 120-frame intervals)
    - 0xAE111BFF: button-triggered SFX (controller bit 0x10)
    - 0xAE1138FF: race countdown beep (every 64 frames)
    - 0xAE1139FF: race countdown variant (course 1 specific)
  - Created asm/sound.s with full annotated assembly
- Traced complete in-race state machine (M8):
  - **State transition graph**:
    ```
    State 14 (first-frame setup) ──→ State 15 (main race loop)
                 ↑                          │
                 │                    ┌─────┴─────┐
                 │              countdown=0    start btn
                 │                    ↓           ↓
                 │              State 16 ──→ State 18 (time ext setup)
                 │              (cleanup)         │
                 │                    ↓           ↓
                 │              State 17 ──→ State 19 (time ext active)
                 │              (results)    │    │    │
                 │                │    │     │    │    └─→ saved_state
                 │            abort  timer=0 │   A+B+C held
                 │              ↓     ↓     │    ↓
                 │         State 20  State 24│   State 24 / State 14
                 │              │   (post)   │
                 │              ↓            │
                 │         State 29 ←────────┘
                 │              │
                 │              └─→ State 18 (start)
                 └──────────────────(A+B+C in state 19)
    ```
  - **State 14** (FUN_06008EBC): First-frame race setup
    - Clears phase flag [0x06078635]=0, sets race_active [0x06078634]=1, timer [0x0607ED88]=8
    - Button event mapping: reads masks from 0x06063D98, maps to event IDs 0-3 at [0x06078648]
    - Main pipeline: FUN_0600A0C0 → FUN_06018A3C → FUN_0601F784 → FUN_0600EB14 (race update)
    - HUD: FUN_06033AAC → FUN_060321C0 (display)
    - Sets display flag bit 30 (0x40000000) in [0x0605B6D8]
    - Immediate transition to state 15
  - **State 15** (FUN_06009098): Main race loop (CORE GAMEPLAY)
    - Start button check: save resume=15, → state 18 (time extension)
    - Decrements countdown at [0x0607EAAC] each frame
    - Per-car inner loop: r12 iterates 0 to [car_count]:
      - First iteration (r12==0): player car, sets [0x0607ED8C]=1
      - Each car: FUN_060302C6 (sound) → FUN_0602EFF0 (render) → FUN_0602F0E8 (render) → FUN_0600DE54 (RACE UPDATE)
    - Post-loop: FUN_0600C302 (if car object exists)
    - Race end: countdown→0 or [0x0607EAD0] set → state 16
    - Tail call FUN_060078DC (frame timing/sync)
  - **State 16** (FUN_06009290): Post-countdown cleanup
    - Immediate transition to state 17
    - If car object exists: call FUN_060121A8 (cleanup A), else FUN_06012198 (cleanup B)
    - Sets [0x0605A016] = 4 (phase flag)
  - **State 17** (FUN_060092D0): Post-lap processing / results display
    - Start button → save resume=17, → state 18
    - Calls FUN_0600A33C (general update)
    - Countdown timer: decrement, when expired → reset sound, read finish position from car_obj[0x82], store at [0x06078638], → state 24 (post-race)
    - Abort flag (bit 0 of [0x0607EBF4]): clear bit, reset sound, call FUN_06018E70, → state 20
    - Sound: plays 0xAE1134FF when countdown==200 (with 40-frame cooldown timer at [0x06086054])
    - Mode 1 check [0x0605A1C4]==1 → state 28
    - Update pipeline: FUN_0600DE70, FUN_0600A914, FUN_0600BB94, FUN_060053AC (display), FUN_0601D9B0 (sound), FUN_0600BFFC
    - Tail call FUN_060078DC
  - **State 18** (FUN_060096DC): Time extension setup (SINGLE FRAME)
    - Calls FUN_06009FFC (time extension UI initialization)
    - Immediate transition to state 19
    - Saves difficulty: [0x06078654] → [0x06078652], clears current to 0
    - Clears frame counter [0x06078650] = 0
    - Displays "TIME EXTENSION" overlay via VDP (FUN_060284AE, FUN_060283E0)
    - Sets display flag bit 2, calls FUN_06026CE0
    - Plays transition sound 0xAE0004FF
  - **State 19** (FUN_06009788): Time extension active/input (COMPLEX)
    - Mode byte [0x0607864A] controls speed selection UI:
      - Up button (0x8000): speed++ (max 99) at [0x06078649]
      - Down button: speed-- (min 1)
      - Displays speed number + label text
    - Start button confirmation (debounced: frame_counter >= 20):
      - Plays 0xAE0004FF, displays overlay, restores saved state from [0x0607EACC]
      - Restores difficulty from [0x06078652] → [0x06078654]
      - If mode set: calls FUN_06018DDC(speed) for difficulty setup, clears mode
    - Secret input: A+B+C held simultaneously (mask 0x70):
      - Calls FUN_0600A1B8, sets bit 31 in display_flags
      - If init_flag set: [0x0607EBF4]=1, state=24, [0x0607ED8C]=2
      - If init_flag clear: [0x0605AD08]=1, state=14 (BACK TO TITLE!)
    - Normal frame: counter++ at [0x06078650], blink text every 16 frames
  - **State 20** (FUN_06009508): Abort processing
    - Checks abort flag bit 0 in [0x0607EBF4]: if set, clear it, self-loop state=20
    - Otherwise: frame_counter++ (if no race end), → state 29
    - Simplified pipeline: FUN_0600DFD0, FUN_0600BB94, FUN_060053AC, FUN_0600C218
  - **Key memory map for race states**:
    - 0x0605AD10: game state variable (32-state machine index)
    - 0x0607EACC: resume state (saved before time extension detour)
    - 0x0607EAAC: countdown timer (decremented each frame)
    - 0x0607EAD0: race end flag (non-zero = race over)
    - 0x0607EAD8: car object pointer
    - 0x0607EBF4: flags word (bit 0 = abort, bit 1 = ?)
    - 0x0607EBD0: frame counter (incremented while waiting)
    - 0x0607ED8C: init/phase flag (controls per-car setup)
    - 0x06078634: car count (how many cars per frame)
    - 0x06078638: race result / finish position
    - 0x06078649: speed byte (time extension speed selection, 1-99)
    - 0x0607864A: mode byte (controls time extension behavior)
    - 0x06078650: frame counter word (time extension frame count)
    - 0x06078652/54: saved/current difficulty
    - 0x0605B6D8: display flags (bit 2 = update, bit 30 = race active, bit 31 = special)
    - 0x0605A016: phase flag (set to 4 on cleanup)
    - 0x06059F44: results flag
  - Created asm/race_states.s with complete annotated state machine
- Traced complete lap counting system (M9):
  - FUN_0600CD40: checkpoint crossing detection (angle-based, 24-byte entries)
  - FUN_0600D780: checkpoint change detection (3 paths: backward wrap, forward jump, single step)
  - FUN_0600D9BC: lap flag setter — calls FUN_06034F78(1, 0x1501, car_ptr)
  - 0x0600DB64: lap counter increment (tests flag, clears it, increments car[0x015C])
  - FUN_0600DA7C: finish line proximity (sets byte+3 bit 3 via 0x1C01 param)
  - FUN_0600DBA0: "LAP" text display animation
  - FUN_06034F78: fully decoded bitfield utility (packed bit_pos/count in r1)
  - FUN_0600D92C: lap timing recording (position snapshots, split times)
  - Key discovery: pool constant 0x1501 was disguised as instruction mnemonic in disassembly
  - Decoded one-shot flag pattern: set on frame N, consumed on frame N+1
  - Per-car bitmask at 0x06063F1C prevents double-counting
  - Created asm/lap_counting.s with full annotated system
  - Updated car struct: 8 new offsets (0x015C, 0x01E0-0x01F0, 0x021C, 0x0228, 0x0230)
- Traced complete force table and acceleration system:
  - Decoded 3-level table hierarchy: table pointers → descriptors → force record arrays
  - Two force profiles: A (64 records, gentle) at 0x0604508C, B (85 records, aggressive) at 0x06044C90
  - 12-byte force records: speed_ref(4) + steering(2) + X(2) + Z(2) + angular(2)
  - Gas/brake determines force sign convention (forward/brake/coast physics)
  - FUN_06008318: gear shift handler (S-curve steering kick over 32 frames)
  - 0x06008640: force table selection (bit 23 of state → table A or B)
  - FUN_060086C0: force initialization (loads descriptor → car struct fields)
  - 0x06008730: per-frame force application (read record, apply sign, advance ptr)
  - Gear steering table at 0x060453CC: 33-entry S-curve (0→+29557→-32768→-158→+64)
  - Created asm/force_tables.s with complete annotated system
  - Updated car struct: 13 new offsets (0x00B8-0x0208 force system)
  - Contiguous data block: 0x06044C90-0x0604540E (profiles + descriptors + tables)
- Traced complete object management system (M10):
  - **Car array memory layout**: 40 slots × 0x268 bytes at 0x06078900-0x0607E93F
    - Globals at 0x0607E940/E944/E948 sit immediately after the array
    - Total clear on init: 6160 × 4 = 24640 bytes (exactly 40 × 616)
  - **FUN_0600EB14** (race init master):
    - Called from 3 state handlers (0x06008956, 0x06008FAC, 0x06009EB2)
    - Zeros entire car array, calls FUN_06026E02/FUN_060270C6 subsystem inits
    - Calls FUN_0600629C (car iteration loop)
    - Sets car[0] activation flags at +0x120..+0x12C = 1
    - Zeros ~30 global variables, sets update mode to 0
  - **FUN_0600629C** (car init loop):
    - Reads car count from *0x0607EA98
    - For each car: base + i*0x268, stores index to car[4], calls FUN_0600E1D4
    - Special path when *0x06078635 != 0: inits car[1] before car[0]
    - Post-loop: car[0] fixup (sizes=56, reads from 0x0607ED90)
    - Calls FUN_0600D280 (sorting), FUN_0602E5E4
  - **FUN_0600E1D4** (per-car type init):
    - Config table at 0x06047DE4 with 12-byte entries (type, heading, indices, class)
    - Secondary table at 0x06047DD0 (5-byte entries for grid position)
    - Entry[0] = player (class=2), entries[1..N] = AI (class=1)
    - Initial heading angles form grid positions around starting line
    - Sets position (car[0x10/0x18]) and rotation (car[0x1C/0x20/0x24])
  - **FUN_0600DE70** (per-frame car iteration):
    - Called from State 15 at 0x06009436
    - Iterates *0x06078634 (byte count) cars
    - Calls FUN_0600E4F2 per car
    - Post-loop: FUN_0600A8BC (audio), render finalize, frame finalize
  - **FUN_0600E4F2** (per-car per-frame update — THE BIG ONE):
    - 9-stage pipeline: force → subsystems → physics/demo → 3D render → lap count → proximity → collision → track → AI
    - Player/AI determined by: car == car[0] → r12=0 (player), else r12=1 (AI)
    - Player-only: FUN_0600DB64 (lap counter)
    - AI-only: FUN_0600EA18 (behavior), called when NOT demo mode
    - Demo mode: bypasses physics, applies pre-recorded velocities from globals
    - Normal mode: 4 scene passes through FUN_06027CA4 (3D renderer)
    - Tail-calls FUN_0602D9F0 (render pipeline) in normal mode
  - **FUN_0600E410** (simplified update, mode 0):
    - Force + subsystems + physics pipeline + speed calculation
    - Used during pre-race countdown
  - **FUN_0600DF66** (mode dispatcher):
    - Reads *0x06083261: mode 0→E410, mode 1/2→E47C
  - **Config table decoded** (7 entries at 0x06047DE4):
    - Type 3/4, heading angles spacing cars around grid
    - Entry 0: player with heading 0xF555 (-2731)
    - Headings increase per-row (paired entries share similar angles)
  - Created asm/object_management.s with full annotated system
  - Updated car struct: +0x04 (car index), +0x0E0/0xE4 (speed values), +0x074/0x090 (init values)
- Traced complete speed curve and position integration system:
  - **FUN_0600C4F8** (speed curve calculation):
    - Two course tables: A at 0x060477EC ("thrust"), B at 0x060454CC ("drag")
    - Both tables indexed by car[0x08] (speed index), 32-bit entries
    - Net force = table_A[idx] - table_B[idx] + 0xFEC00000 (decreases at higher speed)
    - Table A first entries: 0x0BD52BD3, 0x0BD52BD3, 0x0BFCE38E, 0x0C249B4A...
    - Table B first entries: 0x00100000, 0x001008A1, 0x00101328, 0x00101F96...
    - Two fixed-point multiplies via FUN_06027552: (base>>16 * car[0x198])>>16
    - Delta = car[0x194] - car[0x0C], clamped to [-4014, half_target]
    - Accumulator: car[0x0C] += delta, floored at 0
    - Index conversion: car[0x08] = sext16((car[0x0C] * 72) >> 16)
    - Speed limiter: when car[0xBC]>0 or car[0xB8]!=0, delta forced to -4014
    - State flag bit 15 (*0x0607EBC4 & 0x8000): skip entire calculation
  - **FUN_0600C5D6** (position integration):
    - Gets next checkpoint entry from FUN_0600CD40 return + 24
    - Three update paths based on state:
      1. Course following (CA96): game_mode==2, force active, or braking
      2. Flat sin/cos: car.X += speed*sin(-heading), car.Z += speed*cos(-heading), car.Y = 0
      3. 3D transform: when car flags bits 21-23 set (banked turns, airborne)
    - Steering correction (FUN_0600CF58): only when counter<=10, position<102
    - Game mode 3: speed target from checkpoint[8] * car[0x198] >> 16
    - Heading update via FUN_0600C8CC from course data reference
    - Sin/cos computed by FUN_06027358(-heading) → car[0x18C] and car[0x190]
  - New car struct offsets: +0x00FC (clamped delta), +0x0161 (state byte),
    +0x018C/0x0190 (sin/cos), +0x0194 (speed target), +0x0198 (scale), +0x0204 (steer countdown)
  - Created asm/speed_position.s with full annotated system
  - M5 now fully complete (all sub-items checked)
- Decoded post-race state handlers (States 20, 24, 25, 28, 29):
  - **CORRECTION**: States 20 and 28 were SWAPPED in prior analysis. Verified via jump table:
    - State 20 = FUN_06009A60 (race completion init), NOT FUN_06009508
    - State 28 = FUN_06009508 (abort processing), NOT State 20
  - **State 20** (FUN_06009A60): Race completion initialization
    - Reads finish position from car[+0x82] → [0x06078637] and car[+0x9E] → [0x06078638]
    - Calls FUN_06018DDC(button_event+10) for difficulty setup
    - Complex overlay flag dispatch based on player mode (0/1/2) at *0x0607EAD8
    - Sets bits 1/2/4 in [0x0605AB16] and [0x0605AB17] per player mode
    - Determines update mode from car position (Z >= -4718592 or X > -1286144)
    - Transitions to state 21, sets timer=86, difficulty=4, phase=4
  - **State 24** (FUN_06009CFC): Post-race init (single frame)
    - Sets phase=3, calls cleanup (FUN_06014A74, FUN_06019058)
    - Calls FUN_0600A1B8 (special input), transitions to state 25
    - Sets difficulty=6, clears car speed to 0, sets display flag bit 30
    - Clears results flag [0x06059F44] = 0
  - **State 25** (FUN_06009D4E): Post-race display loop
    - Calls FUN_06014D2C (results display logic) every frame
    - Conditionally runs display pipeline based on [0x06085F8A] flag
    - Unconditionally tail-calls FUN_060078DC (frame sync)
    - Stays in state 25 until external state change
  - **State 28** (FUN_06009508): Abort processing
    - If abort flag re-set: clears it (dead write state=20, immediately overwritten)
    - Always transitions to state 29
    - Simplified pipeline: FUN_0600DFD0, FUN_0600BB94, FUN_060053AC, FUN_0600C218
  - **State 29** (FUN_0600955E): Post-race menu (complex)
    - Start button → save resume=29, state=18 (time extension)
    - Abort flag → clear, state=20 (race completion)
    - Mode flag [0x0605A1C4] == 0 → state=17 (loop back to results)
    - Otherwise stays in state 29
    - Update pipeline: FUN_0600E060, FUN_0600BB94, FUN_060053AC, FUN_0600C218
    - Overlay rendering from 0x06063798 when car[+0xBC] bits 0xCC clear
    - Scoring: FUN_0600A084 when car[+0x82] > 0
  - Updated asm/race_states.s with all 5 new state handlers + corrected graph
  - M8 now fully complete (all race states 14-29 decoded)

### Session 2026-02-06 (continued) — Full Binary Mapping

Completed comprehensive mapping of the entire binary (0x06003000-0x06044000).

**New asm/ files created this session (9 total):**

| File | Functions | Address Range | Key Discovery |
|------|-----------|--------------|---------------|
| asm/vdp_hardware.s | 17+ | Various | Complete Saturn hardware memory map |
| asm/scene_camera.s | 18 | 0x0600AA98-0x0600DD88 | 7-mode camera, render budget model |
| asm/hud_ui.s | 62 | 0x06010000-0x06014F34 | 16-sample steering smooth, master init |
| asm/track_geometry.s | 35+ | 0x06015000-0x06034B9A | 3-course physics (3x 282B identical) |
| asm/sound_driver.s | 15+ | 0x0601D5F4-0x06030EE0 | 4-channel SCSP fire-and-forget |
| asm/render_pipeline.s | 30+ | 0x06021450-0x06037876 | Top 10 largest functions in binary |
| asm/ai_opponents.s | 10+ | 0x06034E58-0x06035D5A | AI state machine with 4 behavior modes |
| asm/replay_camera.s | 20+ | 0x0601DBB8-0x0601FFB8 | Timer-based cinematic camera |
| asm/menu_display.s | 40+ | 0x06030EE0-0x0603CD5C | Race HUD + menu system |

**Key architectural discoveries:**
1. **Master state machine** (FUN_0603DDFC, 2910 bytes) is the largest function — orchestrates ALL subsystems
2. **Scene setup** (FUN_0602382C, 4484 bytes) handles 1-57 objects per frame
3. **Three-course architecture** confirmed by 3 identical 282-byte physics init functions
4. **SCSP sound** uses fire-and-forget 4-channel protocol — no handshaking needed
5. **Render budget** allocates 48 bytes per object from per-frame pool
6. **Track objects** loaded from ROM (0x00200000+offset), Z-negated for world space
7. **Replay camera** uses timer-based position table with course-dependent multipliers

**Complete asm/ file inventory (35 files):**
```
asm/ai_behavior.s        — AI processing pipeline (mid-range, detailed)
asm/ai_opponents.s        — AI state machine & init (high-range)
asm/car_collision.s       — Car-car collision detection
asm/collision.s           — Collision system core
asm/collision_response.s  — Collision response logic
asm/engine_sound.s        — Engine sound effects
asm/force_system.s        — Force table animation system
asm/force_tables.s        — Force table data structures
asm/frame_timing.s        — Per-frame timing pipeline
asm/game_loop.s           — 32-state machine dispatcher
asm/hud_ui.s              — HUD/UI/input/AI (mid-range)
asm/input_smpc.s          — SMPC controller input
asm/lap_counting.s        — Lap detection & counting
asm/math_helpers.s        — Fixed-point math utilities
asm/math_transform.s      — Matrix/vector transforms
asm/menu_display.s        — Menu screens & race HUD
asm/object_management.s   — Car object lifecycle
asm/per_car_loop.s        — Per-car update pipeline
asm/player_physics.s      — Player physics (force-driven)
asm/pre_race_states.s     — Pre-race state handlers
asm/race_states.s         — In-race state machine
asm/race_update.s         — Per-frame race updates
asm/rendering.s           — VDP1 rendering pipeline
asm/render_pipeline.s     — Master rendering pipeline
asm/replay_camera.s       — Replay/cinematic camera
asm/scene_camera.s        — Scene rendering & camera
asm/scene_renderer.s      — 3D scene processor
asm/sound.s               — Sound system core
asm/sound_driver.s        — SCSP driver & channels
asm/speed_position.s      — Speed curves & integration
asm/subsystem_updates.s   — Subsystem coordination
asm/track_geometry.s      — Track segments & terrain
asm/vblank_system.s       — VBlank interrupt system
asm/vdp_hardware.s        — VDP1/VDP2 hardware map
asm/vertex_pipeline.s     — Vertex transform pipeline
```

**Coverage summary:**
- ~1100+ functions documented across 38 asm/ files
- All major subsystems mapped: physics, rendering, AI, sound, input, camera, HUD, track
- All milestones M1-M22 complete
- Remaining unmapped functions are small utilities (<30 insns) and data accessors

### Session 2026-02-06 (continued #2) — Coverage Gap Fill & Dependency Graph

Filled remaining coverage gaps and created extraction plan.

**New asm/ files created (3):**

| File | Functions | Address Range | Key Discovery |
|------|-----------|--------------|---------------|
| asm/event_queue.s | 70 | 0x0604000C-0x06046E48 | 24-slot event queue at 0x060A5400 |
| asm/system_init.s | 25 | 0x06003218-0x06005DD4 | Per-frame update chain (4-function dispatch) |
| asm/state_handlers.s | 32 | 0x060088CC-0x06009F10 | Complete 32-state machine catalog |

**New workstream doc:**
- `workstreams/extraction_dependency_graph.md` — 9-tier dependency graph for CCE transplant

**Key findings:**
1. **0x0604xxxx range** is a gameplay event/state management subsystem with 24-slot circular queue
2. **State 21** (post-race) keeps cars moving and colliding — not a static results screen!
3. **Time extension** (states 18-19) has A+B+C secret input combo (0x0070)
4. **States 22/26 and 23/27** share handlers (alias pairs)
5. **Per-frame utility chain** dispatches 4 subsystems: world, input, animation, display
6. **Low-address DMA init** has 3 variants — one per course (Beginner/Advanced/Expert)
7. **~51 functions + 13 data tables** identified as CCE extraction targets

**Complete asm/ file inventory (39 files):**
```
asm/ai_behavior.s         — AI processing pipeline (mid-range, detailed)
asm/ai_opponents.s        — AI state machine & init (high-range)
asm/car_collision.s       — Car-car collision detection
asm/collision.s           — Collision system core
asm/collision_response.s  — Collision response logic
asm/engine_sound.s        — Engine sound effects
asm/event_queue.s         — Gameplay event queue & state management
asm/force_system.s        — Force table animation system
asm/force_tables.s        — Force table data structures
asm/frame_timing.s        — Per-frame timing pipeline
asm/game_loop.s           — 32-state machine dispatcher
asm/hud_ui.s              — HUD/UI/input/AI (mid-range)
asm/input_smpc.s          — SMPC controller input
asm/lap_counting.s        — Lap detection & counting
asm/math_helpers.s        — Fixed-point math utilities
asm/math_transform.s      — Matrix/vector transforms
asm/menu_display.s        — Menu screens & race HUD
asm/object_management.s   — Car object lifecycle
asm/per_car_loop.s        — Per-car update pipeline
asm/player_physics.s      — Player physics (force-driven)
asm/pre_race_states.s     — Pre-race state handlers
asm/race_orchestration.s  — Race orchestration & remaining gameplay [NEW]
asm/race_states.s         — In-race state machine
asm/race_update.s         — Per-frame race updates
asm/rendering.s           — VDP1 rendering pipeline
asm/render_pipeline.s     — Master rendering pipeline
asm/replay_camera.s       — Replay/cinematic camera
asm/scene_camera.s        — Scene rendering & camera
asm/scene_renderer.s      — 3D scene processor
asm/sound.s               — Sound system core
asm/sound_driver.s        — SCSP driver & channels
asm/speed_position.s      — Speed curves & integration
asm/state_handlers.s      — Complete 32-state handler catalog
asm/subsystem_updates.s   — Subsystem coordination
asm/system_init.s         — System bootstrap & utilities
asm/track_geometry.s      — Track segments & terrain
asm/vblank_system.s       — VBlank interrupt system
asm/vdp_hardware.s        — VDP1/VDP2 hardware map
asm/vertex_pipeline.s     — Vertex transform pipeline
```

### Session 2026-02-06 (continued #3) — Gameplay Mapping Complete

Completed final mapping of all gameplay-touching code in the binary.

**New asm/ file:**

| File | Functions | Address Range | Key Discovery |
|------|-----------|--------------|---------------|
| asm/race_orchestration.s | 14 core + 19 transitions | 0x0600AFB2-0x0600FFD0 | Camera lerp uses 50% convergence; physics chain D31C->D37C->D3C4->D41C->D50C |

**Key findings:**
1. **Camera lerp** (FUN_0600B4D2): 3-way state dispatch, 50% per-frame convergence via `shar` (signed right shift)
2. **Race state machine** (FUN_0600C010): Multi-stage pipeline with +0x30/frame buffer increment, physics enable at bit 0x02000000
3. **Physics dispatch chain**: FUN_0600D31C -> D37C (conditional on 0x00200000) -> D3C4 (always) -> D41C -> D50C
4. **Race orchestrator** (FUN_0600E7C8): 6 subsystems per frame + 3 camera modes
5. **19 transition handlers** (4-245 insns each): manage menu flow, race start/end, mode changes
6. **3 functions need urgent decompilation** for CCE transplant: B4D2 (camera), C010 (race state), D41C (dynamics)

**Mapping status: COMPLETE.** 39 asm/ files covering 500+ gameplay functions across all address ranges. All gameplay subsystems fully documented. Remaining undocumented functions are rendering-only helpers and tiny stubs.
