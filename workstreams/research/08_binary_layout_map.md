# APROG.BIN: Complete Binary Layout Map

## Overview

```
Binary: 394,896 bytes
Load address: 0x06003000
End address:  0x060638D0 (approximate)
BSS start:    0x06063690
```

The binary contains 1,818 `.s` source files + 1 `_start.s` startup section.
All data after 0x06063690 is runtime RAM (BSS/heap), not in the binary.

## Startup Section (0x06003000 – 0x060030FB)

`reimpl/src/_start.s` — `.section .text.startup`

- 54 bytes of SH-2 machine code (prologue, init calls)
- ~40 pool entries as `.4byte SYMBOL` references (ALL symbolized, no raw bytes)
- Sets up stack, clears BSS, calls main init chain
- Dispatch table: 24 function pointers for state machine handlers and interrupt vectors

**This section is IDENTICAL in production and free builds.** The +4 pad comes after.

## Subsystem Map

### 0x06003100 – 0x060030FF: System Bootstrap

```
FUN_060030FC  Master init (SMPC, BSS clear, subsystem init chain, state=2)
FUN_06003218  Sub-init
FUN_06003274  Sub-init
FUN_060033E6  Sub-init
```

### 0x06003A3C – 0x0600466F: DMA/Resource Setup

```
FUN_06003A3C  DMA scatter-gather table init (~30 DMA descriptors)
FUN_06003578  Related config
FUN_06004670  VDP2 scroll/tile map configuration
```

### 0x06004A98 – 0x060067C7: Course Data Processing

```
FUN_06004A98  Course data processing
FUN_06004F14  Course segment handling
...
FUN_060067C8  End of course functions
```

### 0x06006838 – 0x06007BCC: Map/Coordinate System

```
FUN_06006838  World coords → tile grid (verified formula)
FUN_06006868  Coordinate transform chain
FUN_06006A9C  Coordinate transform
FUN_06006CDC  Coordinate transform
```

### 0x06007658 – 0x060086C0: Per-Frame System + Animation

```
FUN_060081F4  Frame processing
FUN_06008640  Pure computation
FUN_06008730  Replay/animation data stream processor
```

### 0x060088CC – 0x06009E60: Game State Handlers (THE MAIN GAME LOOP)

```
States 0-31 dispatch table. State handlers for:
  0-1: Startup/transition
  2:   Attract mode setup
  3:   Title/demo mode
  4:   Mode select
  5:   Course select
  6-11: Transitions
  12:  Pre-race setup
  13:  Race countdown
  14,15,17,19: IN-RACE GAMEPLAY (largest handlers)
  16:  Lap transition
  18:  Time extension
  20:  Race end/results
  21:  Results display
  22:  Game over
  23:  Name entry
  24-27: Post-race/score/timer
  28-29: Special states
  30-31: Service menu/diagnostics
```

### 0x0600A026 – 0x0600A4CA: Per-Frame Input/Timing

```
FUN_0600A392  Called EVERY FRAME from main loop (input, counters, timing)
```

### 0x0600A76C – 0x0600BF70: Camera System (HIGH PRIORITY FOR EXTRACTION)

```
FUN_0600B340  Main camera system (3-mode state machine, lerp)
FUN_0600BB94  Complex camera state machine (6 states, cinematic)
```

### 0x0600C218 – 0x0600CF58: Race Calculation/Timer

```
FUN_0600C218  Frame sync / VDP double-buffer swap
FUN_0600C4F8  Race timer
FUN_0600C5D6  Race position calculation
```

### 0x0600D0B8 – 0x0600DC74: Vehicle Physics (HIGH PRIORITY)

```
FUN_0600D50C  Largest in cluster (physics, collision)
```

### 0x0600DE40 – 0x0600EC78: Race State Update Chain

### 0x0600EC78 – 0x0600FFFF: 3D Object Setup (~44KB, 3 massive functions)

```
FUN_0600EC78  Scene setup A (782 insns)
FUN_06012F80  Scene setup B (946 insns)
FUN_0602382C  Scene setup C (2242 insns, LARGEST function in binary)
```

### 0x06012B58 – 0x06012F60: File Loading / CD Asset Manager

```
FUN_06012BDC  CD sector lookup
FUN_06012C3C  Main file loader (wait+open+read with retry)
FUN_06012CF4  Course-specific loader
FUN_06012DB4  APROG.BIN self-check
FUN_06012E08+  ~15 file path stubs (one per asset: SCROLL.BIN, TABLE.BIN, etc.)
```

### 0x06014504 – 0x06015338: Text/Input/HUD

### 0x06018320 – 0x060192B4: VDP2 Configuration

### 0x060193F4 – 0x0601A3F4: Track/Course Geometry

### 0x0601B160 – 0x0601F9CC: 3D Geometry Engine (HIGH PRIORITY)

### 0x06020366 – 0x06025148: Rendering Pipeline

### 0x06025224 – 0x06026E94: Menu/UI System

### 0x06026DBC – 0x0602766C: Math Library

### 0x06027CA4 – 0x0602B5D2: 3D Scene Processing

### 0x0602C494 – 0x0602F99C: VDP1 Commands + Sprites

### 0x060302C6 – 0x06030DFE: Sound/Music System

### 0x06030EE0 – 0x060337FC: HUD/Race Display

---

## ← THE ENGINE CORE BLOCK (0x06034036 – 0x06047048, ~75KB) →

This is the key address range. Contains 375 functions. See below.

---

### 0x06034036 – 0x060343AE: Physics Computation Pipeline

32 functions forming a decomposed physics update pipeline.
Core per-object physics with dmuls.l fixed-point multiplies.
**THIS IS GAMEPLAY CODE, not CD code.**

### 0x060344FC – 0x06034641: Object State Machine

Distance-squared + sqrt proximity detection (object slot initialization).

### 0x06034642 – 0x060348E5: Terrain Surface + Sound Triggers

Animation frame cycling, sound trigger state machine (engine/skid sounds).
SCSP command words: `0xAE11xxFF` pattern.

### 0x06034900 – 0x06034AA0: Terrain Collision Mesh

Track intersection tests, mesh boundary checks.

### 0x06034BA8 – 0x06034E24: CD Block Command Protocol

CD cmd 0x04/0x05/0x06/0x10/0x11/0x12 builders.
**FIRST CD-SPECIFIC code in this range.**

### 0x06034F08 – 0x060359FF: AI ENGINE (2816 bytes!)

The complete AI opponent system. 11 internal sub-functions:
- AI interrupt setup
- Bitfield write utility (most-called utility in range)
- AI state machine: normal/chase/defensive/recovery
- AI decision logic / position selection
- Collision geometry classification
- Value interpolation
- Lap completion bitmask
- Object LOD divisor
- AI main loop: per-frame per-car update (996 bytes)
- AI target tracking (416 bytes)
- AI physics integration: steering/throttle/brake

**THIS IS GAMEPLAY CODE.**

### 0x06035A08 – 0x06035C07: Fixed-Point 20.12 Multiply (512 bytes)

Core arithmetic used by ALL physics. dmulu.l with normalization.
**THIS IS GAMEPLAY CODE.**

### 0x06035C08 – 0x06035CBB: Hardware Interface Utilities

```
sym_06035C4E  HIRQ reader (6 bytes: mov.l @pool, R0; rts; mov.w @R0, R0)
FUN_06035C54  SCDQ acknowledge
FUN_06035C80  SMPC clear+setup
```

### 0x06035CBC – 0x06036143: CD/SCSI Init + AI Init

### 0x06036144 – 0x06036BA5: CD Block SCSI Command Set (66 commands)

Complete Saturn CDB driver library compiled in.
Commands: status, seek, read, play, get sector, calculate, etc.

### 0x06036DDC – 0x06037659: String Library + VDP DMA + Renderer

```
FUN_06036DDC  strncpy
FUN_06036E18  memcmp/strcmp
FUN_06036E90  VDP DMA setup
FUN_06036F0C  VDP init (3-state machine)
FUN_060370E4  Texture management (1404 bytes)
FUN_06037660  VDP1 command builder (2572 bytes — the renderer)
```

### 0x0603806C – 0x06042BFF: Large Unsegmented Block

Includes more CD command handlers, more gameplay code, the event queue
subsystem (FUN_0604000C – FUN_06046E48, 70 functions).

Key functions in this range:
```
FUN_0603B21C  CD retry loop wrapper (calls FUN_0603B424)
FUN_0603B424  CD COMMAND STATE MACHINE ← THE CRITICAL FUNCTION
FUN_060423CC  SCDQ POLL ← THE CRITICAL FUNCTION
FUN_06040C98  CD command handlers using sym_060A5400
FUN_060422F0  Validator that calls FUN_06035C4E
FUN_060423A0  Bulk structure initialization
```

---

### 0x06047048 – 0x06063690: Large Data Section

`FUN_06046E48` (one huge symbol, 116KB). Contains static game data:
- Sector descriptor tables
- Level/course configuration
- Asset manifest tables
- Misc game constants

No code, all data. The `loc_06052698`, `loc_0605519C`, `loc_06057DF8`
tables here are game-internal data (block IDs), NOT function pointers.
`find_unrelocated.py` falsely flags them — verified false positives.

---

## The sym_060A5400 Mystery

`sym_060A5400` is defined in both linker scripts as:
```ld
PROVIDE(sym_060A5400 = 0x060A5400);
```

It's a FIXED address in BSS (runtime RAM, not in binary). It's a POINTER to
the game state structure (confirmed from event_queue.s analysis):
```
GameState struct fields:
  +0x54: queue_counter (0-23)
  +0x58: queue_active_flag
  +0x5C: queue base (24 slots × 16 bytes)
  +0x80: condition_flag
  etc.
```

20+ CD command handler functions (FUN_06040C98 and related) reference
`sym_060A5400` as a pool entry. They load the game state pointer from there
and interact with the event queue. This is NOT a function pointer to the
HIRQ reader (that was an early incorrect hypothesis).
