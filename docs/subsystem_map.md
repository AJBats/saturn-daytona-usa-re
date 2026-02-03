# Daytona USA Saturn - Subsystem Map

## Overview

The binary (aprog.bin, 394,896 bytes at 0x06003000) decompiles to 880 functions.
This document maps them into functional subsystems based on analysis of decompiled
code, cross-references, string references, and data access patterns.

**Critical gap**: ~40 game state handler functions (0x060088CC-0x06009E60) exist
in the assembly but are MISSING from the Ghidra decompiler export. These contain
the core game flow logic (attract mode, menus, in-race, results, etc.).

## Architecture

```
initial_program (0x06002E80)
  -> main (0x06003000)
       -> FUN_060030FC()           [one-time init: SMPC, BSS clear, subsystem init]
       -> infinite loop:
            FUN_0600A392()         [per-frame update: input, timers]
            state = *(game_state)  [read current state 0-31]
            jump_table[state]()    [dispatch to state handler]
```

The main loop is a **32-state machine**. Each state dispatches to a handler
function through a jump table at 0x0600307C.

## Game State Dispatch Table

| State | Handler    | Size (est.) | Purpose (inferred) |
|-------|------------|-------------|-------------------|
| 0     | 0x060088CC | ~62 insns   | Startup/init state |
| 1     | 0x0600890A | ~22 insns   | Transition |
| 2     | 0x06008938 | ~112 insns  | Attract mode setup |
| 3     | 0x06008A18 | ~114 insns  | Title/demo mode |
| 4     | 0x06008CCC | ~52 insns   | Mode select |
| 5     | 0x06008D74 | ~62 insns   | Course select |
| 6     | 0x06008B04 | ~24 insns   | Transition |
| 7     | 0x06008B34 | ~34 insns   | Transition |
| 8     | 0x06008B78 | ~18 insns   | Transition |
| 9     | 0x06008B9C | ~30 insns   | Transition |
| 10    | 0x06008BD8 | ~18 insns   | Transition |
| 11    | 0x06008BFC | ~14 insns   | Transition |
| 12    | 0x06008E00 | ~36 insns   | Pre-race setup |
| 13    | 0x06008E48 | ~58 insns   | Race countdown? |
| 14    | 0x06008EBC | ~188 insns  | **In-race gameplay** |
| 15    | 0x06009098 | ~202 insns  | **In-race gameplay** |
| 16    | 0x06009290 | ~32 insns   | Lap transition? |
| 17    | 0x060092D0 | ~228 insns  | **In-race gameplay** |
| 18    | 0x060096DC | ~86 insns   | Time extension? |
| 19    | 0x06009788 | ~298 insns  | **Complex race state** |
| 20    | 0x06009A60 | ~195 insns  | Race end / results |
| 21    | 0x06009C48 | ~74 insns   | Results display |
| 22    | 0x06009E60 | ~84 insns   | Game over |
| 23    | 0x06009F10 | ~?          | Name entry? |
| 24    | 0x06009CFC | ~40 insns   | Post-race |
| 25    | 0x06009D4E | ~56 insns   | Score tally |
| 26    | 0x06009DD0 | ~24 insns   | Transition |
| 27    | 0x06009E02 | ~26 insns   | Timer/counter (VERIFIED) |
| 28    | 0x06009508 | ~42 insns   | Special state |
| 29    | 0x0600955E | ~140 insns  | Special state |
| 30    | 0x06008C14 | ~48 insns   | Service menu? |
| 31    | 0x06008C76 | ~42 insns   | Diagnostics? |

Note: States 14, 15, 17, 19 are the largest handlers - likely the core gameplay states.

## Subsystem Regions

### 1. System Bootstrap & Security (0x06002100-0x06002FFF)
- **security_check** (0x06002100, 134 insns) - Copy protection, region check
  - Displays "PRODUCED BY or UNDER LICENSE FROM" / "SEGA ENTERPRISES LTD"
  - Reads hardware flags, waits for timer, returns security result
- **initial_program** (0x06002E80, 4 insns) - Entry point, calls main
- **FUN_060023E6** (11 insns) - VBlank wait: writes 1 to flag, spins until cleared by interrupt
- **FUN_06002404** (22 insns) - Word copy loop (memcpy for 16-bit words)
- **FUN_06002348** (70 insns) - Memory initialization (dual BSS-like clear loops)

### 2. System Init Chain (0x060030FC-0x060033E6)
- **FUN_060030FC** (100 insns) - Master init:
  - SMPC initialization (writes INTBACK command 0x19 to SMPC_COMREG)
  - BSS segment clear (two loops zeroing memory ranges)
  - Calls subsystem init chain (10+ indirect calls)
  - Sets initial game state to 2
- **FUN_06003218** (46 insns) - Sub-init
- **FUN_06003274** (31 insns) - Sub-init
- **FUN_060033E6** (16 insns) - Sub-init

### 3. DMA / Resource Transfer Setup (0x06003A3C-0x06004670)
- **FUN_06003A3C** (1059 insns) - Massive DMA transfer table initialization
  - Sets up ~30 transfer descriptors via repeated PTR_FUN calls
  - Parameters: (data_ptr, element_size, source_ptr, count)
  - Likely configures DMA scatter-gather for VDP/sound/work RAM loading
- **FUN_06003578** (230 insns) - Related setup/config
- **FUN_060038D4** (70 insns) - Related setup
- **FUN_06004670** (500 insns, LEAF) - VDP2 scroll/tile map configuration
  - Fills structure array with tile grid parameters
  - Fields: pointer, dimensions (1x1, 2x2, 2x3), grid sizes
  - `(0x40 - width * count) * 2` pattern = tile stride calculations

### 4. Course Data Processing (0x06004A98-0x060067C8)
- **FUN_06004A98** (424 insns) - Course data processing
- **FUN_06004F14** (169 insns) - Course segment handling
- **FUN_0600508A** (64 insns) - Course utility
- **FUN_06005198** (120 insns), **FUN_06005294** (108 insns) - Related pair
- **FUN_060054EA** (12 insns, VERIFIED) - Init: store param, zero fields, copy value
- **FUN_060055BC** (199 insns) - Course data function
- **FUN_06005788** (162 insns) - Course rendering
- **FUN_060058FA**-**FUN_06005C98** - Course processing chain
- **FUN_06005DD4** (117 insns, LEAF) - Pure data computation
- **FUN_06005ECC** (302 insns) - Large course function
- **FUN_060061C8**-**FUN_060067C8** - Remaining course functions

### 5. Map/Coordinate System (0x06006838-0x06007BCC)
- **FUN_06006838** (19 insns, VERIFIED) - Map coordinate calculation:
  `((0x03FFFFFF - p2) >> 21) << 6 + ((0x04000000 + p1) >> 21)`
  Converts world coordinates to 64-column tile grid indices
- **FUN_06006868** (242 insns) - Coordinate transform chain
- **FUN_06006A9C** (257 insns) - Coordinate transform
- **FUN_06006CDC** (267 insns) - Coordinate transform
- **FUN_0600736C** (83 insns) - Small utility
- **FUN_06007540** (40 insns, LEAF), **FUN_06007590** (64 insns, LEAF) - Math utilities
- **FUN_06007658**-**FUN_06007BCC** - Transform pipeline functions

### 6. Per-Frame System (0x060081F4-0x060086C0)
- **FUN_060081F4** (125 insns) - Frame processing
- **FUN_06008318** (97 insns) - Frame update
- **FUN_06008418**, **FUN_06008460** (36 insns each) - Paired operations
- **FUN_060084CA** (74 insns) - Frame utility
- **FUN_060085B8** (54 insns) - Frame utility
- **FUN_06008640** (50 insns, LEAF) - Pure computation
- **FUN_060086C0** (42 insns) - Frame finalize

### 7. Animation / Replay Data (0x06008730)
- **FUN_06008730** (179 insns, LEAF) - Replay/animation data stream processor
  - Advances through a data stream (pointer + 3 words per frame)
  - Reads direction flags (bit 0x40, 0x80) to negate/mirror coordinates
  - Handles frame counters and end-of-data checks
  - Related to "REPLAY" string reference at 0x06003428

### 8. Game State Handlers (0x060088CC-0x06009E60) **MISSING FROM EXPORT**
- ~40 functions handling all 32 game states
- Only FUN_06009E02 (state 27) is in the decompiled export and was verified
- These need to be re-exported from Ghidra with proper function boundaries
- Critical for understanding game flow and extracting gameplay logic

### 9. Per-Frame Input/Timing (0x0600A026-0x0600A4CA)
- **FUN_0600A392** (88 insns) - Called every frame from main loop
  - Handles input polling, frame counters, timing
- **FUN_0600A026** (34 insns), **FUN_0600A084** (30 insns, LEAF) - Input utilities
- **FUN_0600A0C0** (38 insns) - Input processing
- **FUN_0600A140** (45 insns) - Timer/counter management
- **FUN_0600A1F6** (57 insns, LEAF) - Pure computation
- **FUN_0600A294** (70 insns, LEAF) - Data processing
- **FUN_0600A4CA** (81 insns) - Complex input/state

### 10. Camera System (0x0600A76C-0x0600BF70) **HIGH PRIORITY FOR EXTRACTION**
- **FUN_0600A76C** (132 insns) - Camera utility (called from 0600BB94)
- **FUN_0600A8BC** (34 insns, LEAF) - Camera math
- **FUN_0600A914** (166 insns), **FUN_0600AA98** (166 insns) - Camera pair
- **FUN_0600AC44** (169 insns) - Camera positioning
- **FUN_0600AFB2** (164 insns) - Camera tracking
- **FUN_0600B340** (314 insns) - **Main camera system**
  - Reads 3D position from object structure (offsets 0x10, 0x14, 0x18 = X, Y, Z)
  - State machine for camera mode (0=normal, 1=follow, 2=cinematic)
  - Lerping: `pos += (target - pos) >> 1` (50% blend per frame)
  - Calls into transform pipeline (rotation, translation, projection)
- **FUN_0600B6A0** (259 insns) - Camera mode handler 2
- **FUN_0600B914** (265 insns) - Camera mode handler 3
- **FUN_0600BB94** (377 insns) - **Complex camera state machine**
  - States: 0 (idle), 1 (init), 4 (track car), 6 (transition), 7 (cinematic)
  - Time-based progression with nested range checks
  - Adjusts height/distance dynamically (`* 0x400`, `>> 4`, `>> 7` scaling)
  - Calls FUN_0600C3A8 for rotation computation
- **FUN_0600BF70** (57 insns, LEAF) - Camera helper math

### 11. Race Calculation / Timer System (0x0600C218-0x0600CF58)
- **FUN_0600C218** (55 insns) - Frame sync / VDP buffer swap
  - Waits for sync flag, clears it, calls update chain
  - Adjusts buffer pointer by +0x30/-0x30 (double buffer stride)
- **FUN_0600C302** (68 insns, LEAF) - Race data computation
- **FUN_0600C3A8** (133 insns, LEAF) - Called from camera; likely angle/rotation calc
- **FUN_0600C4F8** (89 insns) - Race timer update
- **FUN_0600C5D6** (156 insns) - Race position calculation
- **FUN_0600C74E** (56 insns) - Position update
- **FUN_0600C7D4** (113 insns) - Complex race state
- **FUN_0600C8CC** (46 insns) - Race utility
- **FUN_0600C928** (29 insns, LEAF) - Race data access
- **FUN_0600C970** (18 insns, VERIFIED) - Table lookup with range check
- **FUN_0600C994** (119 insns) - Complex race logic
- **FUN_0600CA96**-**FUN_0600CF58** - Race calculation chain

### 12. Vehicle Physics / Car Data (0x0600D0B8-0x0600DC74) **HIGH PRIORITY FOR EXTRACTION**
- **FUN_0600D0B8** (45 insns, LEAF) - Physics data processing
- **FUN_0600D12C** (94 insns, LEAF) - Large physics calculation
- **FUN_0600D210** (43 insns, LEAF) - Physics helper
- **FUN_0600D266** (2 insns, VERIFIED) - Trivial return (rts/nop)
- **FUN_0600D280** (66 insns, LEAF) - Data table access
- **FUN_0600D31C** (13 insns) - Conditional + calls
- **FUN_0600D336** (26 insns, LEAF) - Data access
- **FUN_0600D37C** (36 insns, LEAF) - Data access
- **FUN_0600D3C4** (143 insns, LEAF) - **Large pure computation (physics calc?)**
- **FUN_0600D50C** (251 insns) - **Largest in cluster, complex with calls**
- **FUN_0600D780** (89 insns) - Vehicle state update
- **FUN_0600D84C** (36 insns, LEAF) - Physics helper
- **FUN_0600D8A4**-**FUN_0600DC74** - Vehicle update chain

### 13. Race State Update Chain (0x0600DE40-0x0600EC78)
- **FUN_0600DE40** (10 insns, VERIFIED) - Shift+store + 2 calls
- **FUN_0600DE54** (14 insns, VERIFIED) - Shift+store+copy + 2 calls
- **FUN_0600DE70** (102 insns) - Complex update
- **FUN_0600DF66** (30 insns) - Small update
- **FUN_0600E060** (48 insns) - Medium update
- **FUN_0600E0C0** (78 insns) - Common target (called by DE40 and DE54)
- **FUN_0600E1D4** (227 insns) - **Large state update function**
- **FUN_0600E410** (35 insns) - Called from DE40
- **FUN_0600E47C** (59 insns) - Update utility
- **FUN_0600E4F2** (171 insns) - Large update
- **FUN_0600E71A** (65 insns) - Update utility
- **FUN_0600E7C8** (137 insns) - Rendering update
- **FUN_0600E906** (54 insns) - Small update
- **FUN_0600E99C** (35 insns) - Called from DE54
- **FUN_0600EA18** (108 insns, LEAF) - Pure computation
- **FUN_0600EB14** (110 insns) - Medium update

### 14. 3D Object Setup / Scene Init (0x0600EC78, 0x06012F80, 0x0602382C)
Three large functions with IDENTICAL patterns - numbered object initialization:
- **FUN_0600EC78** (782 insns) - Scene setup variant A
- **FUN_06012F80** (946 insns) - Scene setup variant B
- **FUN_0602382C** (2242 insns) - Scene setup variant C (LARGEST function in binary)

All follow the pattern:
```c
func(1, size, mode, data_ptr);
func(2, size, mode, data_ptr);
...
func(0x39, size, mode, data_ptr);  // ~57 objects per scene
```
Likely: Course 0, 1, 2 or different game modes.

### 15. File Loading / CD System (0x06012B58-0x06012F80) **HIGH PRIORITY FOR UNDERSTANDING**
- **FUN_06012BDC** (48 insns) - File open (CD sector lookup)
- **FUN_06012C3C** (65 insns) - **Main file loader**
  - Waits for CD not busy, opens file by name, reads data with retry
  - Retry limit of 4, calls error handler on failure
- **FUN_06012CF4** (49 insns) - Course-specific data loader
- **FUN_06012D7C** (20 insns, LEAF) - File path setup
- **FUN_06012E00** (4 insns) - Tail call to file loader (loads 2 args + jump)
- **FUN_06012E08**-**FUN_06012F60** - ~15 tiny stubs (4-8 insns each)
  - These are file path table entries, each loading specific file strings

**Files loaded** (from string references):
| File | Purpose | Load Address |
|------|---------|-------------|
| APROG.BIN | Program binary | Self-check |
| CS0POLY.BIN | Course 0 polygon mesh | 0x06012DA4 area |
| CS1POLY.BIN | Course 1 polygon mesh | Same dest |
| CS2POLY.BIN | Course 2 polygon mesh | Same dest |
| CS0_LINE.BIN | Course 0 spline/centerline | 0x06012E1C area |
| CS1_LINE.BIN | Course 1 spline/centerline | Same dest |
| CS2_LINE.BIN | Course 2 spline/centerline | Same dest |
| COURSE0.BIN | Course 0 definition data | Variable |
| COURSE1.BIN | Course 1 definition data | Variable |
| COURSE2.BIN | Course 2 definition data | Variable |
| TEX_PL.BIN | Palette/common textures | 0x06012E3C area |
| TEX_C0.BIN | Course 0 textures | 0x06012E44 area |
| TEX_C1.BIN | Course 1 textures | Same dest |
| TEX_C2.BIN | Course 2 textures | Same dest |
| SCROLL.BIN | VDP2 background scroll data | 0x06012E94 area |
| TABLE.BIN | Lookup table data | 0x06012E9C area |
| POLYGON.BIN | Generic polygon data | 0x06012EA4 area |
| PIT.BIN | Pit stop model/data | 0x06012EAC area |
| SOUNDS.BIN | Sound samples/data | 0x06012EB4 area |
| GAMED.BIN | Game data (loaded 2x!) | Two destinations |
| SLCTD.BIN | Selection screen data | Two destinations |
| OVERD.BIN | Game over screen data | 0x06012F38 area |
| NAMD.BIN | Name entry screen data | Same area |
| MUSICD.BIN | Music data track 1 | 0x06012F70 area |
| MUSIC2D.BIN | Music data track 2 | Same area |
| MUSIC3D.BIN | Music data track 3 | Same area |

### 16. Text Rendering (0x06014504-0x060146D2)
- **FUN_0601450C** (68 insns, LEAF) - Character-to-glyph mapping
  - Uses charset "ABCDEFGHIJKLMNOPQRSTUVWXYZ" at 0x06014504 and 0x060145AC
- **FUN_060145BC** (99 insns) - Text string renderer
- **FUN_060146D2** (57 insns) - Text display utility

### 17. Control/Input Subsystem (0x06014868-0x06014A74)
- **FUN_06014868** (14 insns, VERIFIED) - 3 calls with param passthrough
- **FUN_06014884** (15 insns) - Similar dispatch
- **FUN_060148A2** (32 insns) - Input handler
- **FUN_060148FC**, **FUN_0601492C**, **FUN_06014994** (24 insns each) - Input handlers
- **FUN_060149CC** (10 insns, VERIFIED) - Bit OR: `reg |= 0x8000; flag = 1`
- **FUN_060149E0** (10 insns, VERIFIED) - Bit AND: `reg &= mask; flag = 1`
- **FUN_06014A04** (31 insns) - Complex input
- **FUN_06014A42** (6 insns) - Tiny input utility

### 18. HUD/Overlay Rendering (0x06014A74-0x06015338)
- **FUN_06014A74** (243 insns) - HUD element rendering
- **FUN_06014D2C** (227 insns) - HUD element rendering
- **FUN_06014F34** (111 insns) - HUD element
- **FUN_06015338** (113 insns) - HUD overlay
- String: "FASTEST LAP" at 0x06013DF8

### 19. VDP2 Configuration / Background (0x06018320-0x060192B4)
- **FUN_06018320** (284 insns) - VDP2 setup
- **FUN_060185D8** (46 insns) - VDP2 utility
- **FUN_06018634** (50 insns, LEAF) - VDP2 register access
- **FUN_06018A3C** (324 insns) - Large VDP2 configuration
- **FUN_06018DCC**-**FUN_06018EC8** - VDP2 utilities
  - FUN_06018E70 (12 insns, VERIFIED) - Stack local + indirect call
  - FUN_06018EAC (14 insns, VERIFIED) - Stack array + call + mask
  - FUN_06018EC8 (7 insns, VERIFIED) - Big-endian byte extraction
- **FUN_06018EE4**-**FUN_06019248** - Many 30-33 insn functions (register config batch)
- **FUN_060192B4** (11 insns, VERIFIED) - Memory clear loop

### 20. Track/Course Geometry (0x060193F4-0x0601A3F4)
- **FUN_060193F4** (94 insns) - Course geometry processing
- **FUN_0601950C** (178 insns) - Large geometry handler
- **FUN_060196A4** (141 insns) - Geometry processing
- **FUN_060198E0** (23 insns) - Utility
- **FUN_06019928** (126 insns) - Track segment handler
- **FUN_06019A48** (169 insns) - Complex geometry
- **FUN_06019BC8**, **FUN_06019DB8**, **FUN_06019FB2** (141 insns each!) - Three identical-sized
  functions likely handling three courses (Beginner/Advanced/Expert)
- **FUN_0601A3F4** (164 insns) - Track data finalize

### 21. 3D Geometry Engine (0x0601B160-0x0601F9CC) **HIGH PRIORITY FOR EXTRACTION**
- **FUN_0601B160** (252 insns) - Geometry pipeline start
- **FUN_0601B6DC** (122 insns) - Geometry utility
- **FUN_0601B7F4** (253 insns) - Geometry transform
- **FUN_0601BA50** (155 insns) - Geometry processing
- **FUN_0601BBCC** (244 insns) - Geometry batch
- **FUN_0601C3E4** (507 insns) - **Large rendering function**
- **FUN_0601C978** (132 insns) - Render pipeline
- **FUN_0601CAEE** (306 insns) - Render processing
- **FUN_0601D12C** (191 insns, LEAF) - **Pure matrix/vector computation**
- **FUN_0601D5F4** (169 insns) - Transform
- **FUN_0601D7D0** (200 insns) - Transform
- **FUN_0601D9B0** (195 insns) - Transform
- **FUN_0601DBB8** (236 insns) - Large computation
- **FUN_0601DE50** (115 insns) - Transform
- **FUN_0601DF88** (142 insns) - Transform
- **FUN_0601E100** (133 insns) - Render output
- **FUN_0601EBDA** (427 insns, LEAF!) - **Large pure geometry computation**
- **FUN_0601EFC4** (465 insns, LEAF!) - **Large pure geometry computation**
  - These two LEAF functions are likely matrix multiply or vertex transform

### 22. Game Object System (0x06020366-0x060210F6)
- **FUN_06020366** (76 insns) - Object management
- **FUN_06020414** (74 insns) - Object update
- **FUN_06020946** (45 insns) - Object utility
- **FUN_06020E74** (242 insns) - Complex object processing
- **FUN_060210F6** (14 insns, VERIFIED) - 3 calls + flag set

### 23. Rendering Pipeline Core (0x06021450-0x06025148) **HIGH PRIORITY FOR EXTRACTION**
- **FUN_06021450** (1447 insns) - **Core per-frame rendering pipeline**
  - Processes all visible objects
  - Many return-value extractions (extraout_r3 pattern)
  - References matrix data, object lists
- **FUN_06022140** (756 insns) - **Large render pass**
- **FUN_0602382C** (2242 insns) - **LARGEST function: scene object setup**
- **FUN_06025070** (99 insns, LEAF) - Math utility
- **FUN_06025148** (100 insns, LEAF) - Math utility

### 24. Menu/UI System (0x06025224-0x06026E94) **LOW PRIORITY FOR EXTRACTION**
- **FUN_06025224** (248 insns) - Menu screen A
- **FUN_06025478** (248 insns) - Menu screen B (same size!)
- **FUN_060256CC** (580 insns) - Complex menu handler
- **FUN_06025BF4** (570 insns) - Complex menu handler
- **FUN_06026110** (198 insns) - Menu utility
- **FUN_06026590** (150 insns) - Menu display
- **FUN_060266CC** (207 insns) - Menu with string display
- **FUN_060268B0** (444 insns) - Complex menu/settings
- Strings: "PRESS START TO EXIT", "PRESS A OR C TO DECIDE", "TYPE A", "CANCEL"

### 25. Math Library (0x06026DBC-0x0602766C)
- **FUN_06026DF8** (5 insns, VERIFIED) - Simple return
- **FUN_06026E0C** (17 insns, LEAF) - Small math
- **FUN_06026E2E** (25 insns, LEAF) - Math utility
- **FUN_06026E60** (26 insns, LEAF) - Math utility
- **FUN_06026E94** (37 insns), **FUN_06026EDE** (38 insns), **FUN_06026F2A** (36 insns)
  - Three similar-sized functions (sin/cos/atan table lookups?)
- **FUN_06026F72** (69 insns, LEAF) - Fixed-point multiply?
- **FUN_06027080** (30 insns, LEAF) - Math helper
- **FUN_06027158**, **FUN_060271A2**, **FUN_060271EE** - Another triad
- **FUN_06027378** (106 insns, LEAF) - Larger math (vector operations?)
- **FUN_0602744C** (21 insns) - Utility
- Small utilities in 0x0602754C-0x0602766C range

### 26. 3D Scene Processing (0x06027CA4-0x0602B5D2)
- **FUN_06027CA4** (240 insns) - Scene graph processing
- **FUN_06027EDE** (199 insns, LEAF) - Pure scene computation
- **FUN_06029BF4** (595 insns) - **Large 3D pipeline A**
- **FUN_0602A134** (32 insns, LEAF) - Pipeline utility A
- **FUN_0602A214** (595 insns) - **Large 3D pipeline B** (SAME SIZE as 29BF4!)
- **FUN_0602A754** (32 insns, LEAF) - Pipeline utility B (SAME SIZE as A134!)
- **FUN_0602A834** (223 insns) - Pipeline handler
- **FUN_0602AAA0** (45 insns, LEAF) - Pipeline data
- **FUN_0602AB00** (27 insns, LEAF) - Pipeline data
- **FUN_0602ABB8** (223 insns) - Pipeline handler (SAME SIZE as A834!)
- **FUN_0602AF3C** (223 insns) - Pipeline handler (SAME SIZE!)
- **FUN_0602B328** (258 insns) - Complex pipeline
- **FUN_0602B5D2** (327 insns) - Pipeline output

Note: The repeated identical sizes strongly suggest **parallel processing paths**
for multiple viewpoints or objects using the same algorithm.

### 27. VDP1 Command List (0x0602C494-0x0602D43C)
- **FUN_0602C494** (236 insns) - VDP1 command list builder
- **FUN_0602C690** (151 insns) - Command processing
- **FUN_0602C7FC** (99 insns) - Command utility
- **FUN_0602C8E2** (182 insns) - Command handler
- **FUN_0602CA84** (247 insns) - Complex command processing
- **FUN_0602CDF6** (276 insns) - Command list finalization
- **FUN_0602D08A** (399 insns) - **Large VDP1 handler**
- **FUN_0602D43C** (394 insns) - **Large VDP1 handler**

### 28. Sprite / 2D Objects (0x0602D7E4-0x0602F99C)
- **FUN_0602DC18** (272 insns) - Sprite management
- **FUN_0602E610** (242 insns) - Sprite setup (references "DAYTONA_00" save string)
- **FUN_0602F17C** (101 insns) - Sprite rendering
- **FUN_0602F4B4** (104 insns) - Sprite utility
- **FUN_0602F5B6** (137 insns) - Sprite processing
- **FUN_0602F7EA** (172 insns) - Sprite handler
- **FUN_0602F99C** (353 insns) - **Large sprite function**

### 29. Sound/Music System (0x060302C6-0x06030DFE)
- **FUN_060302C6** (235 insns) - Sound system init/update
- **FUN_0603053C** (206 insns) - Sound effect handler
- **FUN_0603072E** (271 insns) - Music handler
- **FUN_06030A06** (28 insns, LEAF) - Sound utility
- **FUN_06030A9C** (79 insns) - Sound channel management
- **FUN_06030B68** (289 insns) - **Large sound processing**
- **FUN_06030DFE** (92 insns) - Sound finalize
- Data files: SOUNDS.BIN, MUSICD.BIN, MUSIC2D.BIN, MUSIC3D.BIN

### 30. HUD/Race Display (0x06030EE0-0x060337FC)
- **FUN_06030EE0** (10 insns, VERIFIED) - Index read from word array
- **FUN_06030FC0** (396 insns) - **Large HUD renderer**
- **FUN_0603136E** (378 insns) - **Lap counter/timer display**
- **FUN_060316C4** (383 insns) - **Position/score display**
- **FUN_06031A28** (280 insns) - HUD element (dual variant)
- **FUN_06031DF4** (280 insns) - HUD element (SAME SIZE as 31A28!)
- **FUN_060321C0** (62 insns) - HUD utility
- **FUN_0603268C** (743 insns) - **Very large HUD master renderer**
- **FUN_06032EA4** (155 insns) - HUD overlay
- **FUN_06033188** (56 insns) - HUD utility
- **FUN_06033BC8** (314 insns) - HUD finalize

### 31. Save/Load & CD System (0x06034168-0x06035C48)
- **FUN_06034168** (278 insns) - Save game handler
- **FUN_06034848** (61 insns) - Save utility
- **FUN_06034900** (52 insns) - Save verification
- **FUN_06035460** (331 insns, LEAF) - **Large data processing (save format?)**
- **FUN_060359D2** (4 insns, VERIFIED) - Tiny getter
- **FUN_060359DA** (5 insns) - Tiny utility
- **FUN_060359E4** (231 insns, LEAF) - **CD interface**
- **FUN_06035B34** (70 insns, LEAF) - CD utility
- **FUN_06035BC8** (29 insns, LEAF) - CD utility
- **FUN_06035C08** (8 insns) - CD control
- **FUN_06035C48** (3 insns, VERIFIED) - Byte return

## Extraction Priority for CCE Transplant

### Tier 1: Core Gameplay (must extract)
1. **Vehicle Physics** (0x0600D0B8-0x0600DC74) - Steering, acceleration, collision response
2. **Race Logic** (0x0600C218-0x0600CF58) - Position tracking, lap counting, timing
3. **Race State Updates** (0x0600DE40-0x0600EC78) - Per-frame race state management
4. **Game State Handlers** (0x060088CC-0x06009E60) - IN-RACE STATES 14, 15, 17, 19

### Tier 2: Supporting Systems (needed for gameplay)
5. **Camera System** (0x0600A76C-0x0600BF70) - All viewpoint management
6. **Course/Track Geometry** (0x060193F4-0x0601A3F4) - Track data processing
7. **File Loading** (0x06012B58-0x06012F80) - Data pipeline understanding
8. **Math Library** (0x06026DBC-0x0602766C) - Fixed-point math, trig tables

### Tier 3: Rendering (may need adaptation)
9. **3D Geometry Engine** (0x0601B160-0x0601F9CC) - Vertex transforms
10. **Rendering Pipeline** (0x06021450-0x06025148) - Scene rendering
11. **3D Scene Processing** (0x06027CA4-0x0602B5D2) - Object culling/sorting
12. **VDP1 Commands** (0x0602C494-0x0602D43C) - Hardware-specific

### Tier 4: Peripheral (low priority)
13. **Menu/UI** (0x06025224-0x06026E94) - Different between games
14. **Sound** (0x060302C6-0x06030DFE) - Different sound system
15. **HUD** (0x06030EE0-0x060337FC) - May differ in CCE
16. **Save/CD** (0x06034168-0x06035C48) - Platform-specific

## Key Architectural Patterns

### 1. Function Pointer Dispatch
Most subsystems use indirect calls through constant pool pointers (PTR_FUN_*).
This suggests the original code uses function pointer tables extensively,
possibly for hardware abstraction or module boundaries.

### 2. Object Structure Layout
The camera system reveals the common game object structure:
- Offset 0x10: X position (int, fixed-point)
- Offset 0x14: Y position
- Offset 0x18: Z position
- Offset 0x1C: Rotation/heading
- Offset 0x20: Pitch
- Offset 0x24: Roll/bank
- Offset 0x0C: Mode/state selector

### 3. Three-Course Pattern
Many subsystems have three parallel functions/paths:
- FUN_06019BC8 / FUN_06019DB8 / FUN_06019FB2 (identical sizes)
- FUN_06029BF4 / FUN_0602A214 (identical sizes)
- CS0/CS1/CS2 file naming pattern
This confirms 3 race courses: Beginner (Three Seven Speedway),
Advanced (Dinosaur Canyon), Expert (Seaside Street Galaxy).

### 4. Fixed-Point Arithmetic
Extensive use of `>> 1` (divide by 2), `>> 4` (divide by 16),
`>> 7` (divide by 128), `<< 8` (multiply by 256), `* 0x400` (multiply by 1024).
All arithmetic appears to be 32-bit integer fixed-point, no floating point.

### 5. Double Buffering
FUN_0600C218 shows explicit double-buffer management with +-0x30 stride,
consistent with VDP2 scroll buffer swapping during VBlank.
