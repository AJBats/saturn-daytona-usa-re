# Daytona USA (Sega Saturn) - Reverse Engineering & Gameplay Extraction

## Overview

This document captures research and planning for the reverse engineering of Daytona USA for the Sega Saturn, with the ultimate goal of extracting its gameplay code for transplant into Daytona USA Championship Circuit Edition (CCE).

This is **not** a traditional matching decompilation project. The goal is a functionally correct, non-matching decomp — a full understanding of the original codebase deep enough to isolate the gameplay layer (physics, steering, collision, AI) and port it into CCE's superior engine.

---

## Sega Saturn Hardware Architecture

The Saturn's multi-processor architecture is a key challenge:

| Component | Processor | Role |
|-----------|-----------|------|
| Master CPU | Hitachi SH7604 (SH-2) @ 28.6 MHz | Main game logic, 3D rendering |
| Slave CPU | Hitachi SH7604 (SH-2) @ 28.6 MHz | Secondary processing, geometry |
| Sound CPU | Motorola 68EC000 @ 11.3 MHz | Sound driver |
| VDP1 | Custom | Sprite/polygon rendering |
| VDP2 | Custom | Background/scroll planes |
| SCU | Custom + DSP | DMA, interrupt control, geometry DSP |

Daytona USA likely uses both SH-2 CPUs for its 3D engine, the 68K for sound, and possibly the SCU DSP for geometry processing. Each processor has separate code that may require different toolchains.

---

## Project Motivation

There are two Daytona USA releases on the Sega Saturn:

**Daytona USA (original, 1995)** — A Saturn launch title. Rushed to market, technically rough (low frame rate, pop-in, graphical compromises), but the gameplay is authentic Daytona. The steering feel, the drift mechanics, the speed — this is genuine AM2 arcade gameplay adapted for Saturn hardware. This is the version we are studying.

**Daytona USA Championship Circuit Edition (CCE, 1996)** — A rebuilt version by a different team (CS R&D Dept. 2 / AM Annex). Technically superior in every way: better frame rate, better graphics, more content. But the gameplay is fundamentally different and widely considered inferior. It doesn't feel like Daytona. It's not a fun racing game.

**The goal**: The original's gameplay code is the irreplaceable artifact — the "gold in these hills." It cannot be recreated from scratch because it embodies specific tuning decisions, edge cases, and feel that only exist in that binary. The moonshot is to extract this gameplay logic from the original, then decompile CCE and transplant the authentic gameplay into CCE's better engine. The result would be a game with CCE's technical quality and the original's driving feel.

**Known dragons**: The gameplay code may be tightly coupled to the graphics/rendering pipeline. There may be hardcoded assumptions about frame timing, memory layout, or data formats that differ between versions. Global mutable state from 1995-era game development under deadline pressure is likely pervasive. These will be tackled one at a time as they're discovered.

---

## About Daytona USA (Saturn)

- **Developer**: Sega AM2 (Yu Suzuki's division) / AM Annex (porting team)
- **Release**: April 1, 1995 (JP), May 11, 1995 (US) - Saturn launch title
- **Arcade original**: Ran on Sega Model 2 hardware (Intel i960 CPU) - completely different architecture
- **Saturn port**: Written specifically for SH-2, not a direct port of arcade code
- **Variant**: Daytona USA Championship Circuit Edition (CCE) was a later rebuilt version (see Project Motivation)
- **TCRF**: Categorized as having debugging functions - https://tcrf.net/Daytona_USA_(Sega_Saturn)
- **Compiler**: Cygnus GCC for SH-2 (confirmed via function prologue analysis)
- **Product code**: MK-81200, Build date: 1995-03-17
- **No existing decomp project found** as of this research

### Disc Structure

The data track (Track 01) contains the boot code plus first file. Tracks 02-22 are CD-DA audio (the Daytona soundtrack). 26 files on disc, loaded at runtime via `FUN_06012E6A`:

| File(s) | Purpose | Loaded During |
|---------|---------|---------------|
| `APROG.BIN` | Main game program (all executable code) | Boot |
| `GAMED.BIN` | Racing mode data overlay (446KB) | Race start |
| `COURSE0/1/2.BIN` | Course-specific data (per track) | Race start |
| `CS0/1/2POLY.BIN` | Course polygon/3D data (per track) | Race start |
| `CS0/1/2_LINE.BIN` | Racing line data (per track — AI paths) | Race start |
| `TEX_PL.BIN` | Player car textures | Race start |
| `TEX_C0/C1/C2.BIN` | Course textures (per track) | Race start |
| `POLYGON.BIN` | Shared polygon data | Race start |
| `SCROLL.BIN` | Background/scroll plane data | Race start |
| `TABLE.BIN` | Lookup / data tables | Race start |
| `PIT.BIN` | Pit stop data | Race start |
| `SOUNDS.BIN` | Sound effects → loaded to SCSP (0x25A00000) | Boot |
| `SLCTD.BIN` | Car/track selection screen data | Mode change |
| `OVERD.BIN` | Game over screen data | Mode change |
| `NAMD.BIN` | Name entry screen data | Mode change |
| `MUSICD.BIN`, `MUSIC2D/3D.BIN` | Music data | Mode change |

Hidden features found in strings: `MIRROR MODE`, `DAYTONA UMA` / `HORSE` (secret horse mode).

**Ghost filenames**: The code's filename table references 5 additional files that do NOT exist on the US disc: `GAME0.BIN`, `GAME1.BIN`, `SLCT0.BIN`, `OVER0.BIN`, `NAM0.BIN`. These were likely planned/cut content or exist on other regional variants.

### File Loading System (`FUN_06012E6A`)

ALL file loading from CD goes through a single function at `0x06012E6A` (`scripts/find_overlays.py`, `scripts/analyze_overlay_loader.py`). Key findings:

- **Called from `hw_init`** (`0x060030FC` → `0x06012E6A`) — files are loaded during initialization and mode transitions.
- **Load destinations** vary by file type:
  - Work RAM High (`0x06xxxxxx`) — game data, overlays, textures
  - Work RAM Low (`0x00200000`) — additional data space
  - SCSP sound RAM (`0x25A00000`, `0x25A03000`) — sound effects and music
- **Pattern**: The function uses repeating `mov.l filename,r4 / mov.l dest_addr,r5 / bsr cd_read_func` sequences to load files.
- **Mode-dependent loading**: The function contains conditional branches (BRA) that select different file sets based on the current game mode.

**For racing gameplay**: When a race starts, the game loads `GAMED.BIN` (common racing data) plus track-specific files (`COURSEn.BIN`, `CSnPOLY.BIN`, `CSn_LINE.BIN`, `TEX_Cn.BIN`) where `n` = track number (0 = Three Seven Speedway, 1 = Dinosaur Canyon, 2 = Sea-Side Street Galaxy).

### Binary Layout (APROG.BIN) — preliminary, needs Ghidra verification

APROG.BIN is the main game program. All executable game code lives here. The base address was determined from the entry point's constant pool (self-referencing addresses in the first 256 bytes).

**Load address**: `0x06003000` (Work RAM High)

**Entry sequence** (at offset 0x0000):
1. Sets stack pointer (r15) to `0x06003000` (grows downward into IP.BIN area)
2. Clears status register (enables interrupts)
3. Calls `0x060030FC` (offset 0xFC — hardware initialization)
4. Calls `0x0600A392` (offset 0x7392 — main game function, previously identified in Ghidra)

**Memory map** (from heuristic analysis with `scripts/analyze_binary.py` — boundaries approximate):

| Region | Address Range | Size | Contents |
|--------|-------------|------|----------|
| Code (main) | `0x06003000` - `0x06045000` | 264KB | ~611 functions, GCC 2.6 prologues |
| Data | `0x06045000` - `0x0604B000` | 24KB | Embedded data tables |
| Code (misc) | `0x0604B000` - `0x0604D000` | 8KB | Small code section (may be data — verify in Ghidra) |
| Data | `0x0604D000` - `0x0605A000` | 52KB | Data tables |
| Code (misc) | `0x0605A000` - `0x0605D000` | 12KB | Small code section (may be data — verify in Ghidra) |
| Data | `0x0605D000` - `0x06062000` | 20KB | Data tables |
| Code (tail) | `0x06062000` - `0x06063690` | 6KB | Trailing code (may be data — verify in Ghidra) |
| BSS | `0x06063690` - `0x060FE570` | 619KB | ~758 referenced global variable addresses |

**Total memory footprint**: ~1MB — fills essentially all of Work RAM High (`0x06000000` - `0x060FFFFF`).

**How this was determined**: Python script scanned for GCC function prologue opcodes (`2F E6` = `mov.l r14,@-r15`) and `rts` instructions per 4KB block. Regions with many prologues/rts classified as code, others as data. The "misc" code blocks late in the file may be false positives (data containing byte patterns that resemble instructions). The BSS range was estimated by scanning for 32-bit constants that reference addresses beyond the file's end but within Work RAM High.

**Key finding: overlays are DATA, not CODE.** The seven 446KB overlay files (GAMED.BIN, SLCTD.BIN, MUSICD.BIN, MUSIC2D.BIN, MUSIC3D.BIN, OVERD.BIN, NAMD.BIN) contain 0-2 function prologues each, vs 611 in APROG.BIN. The "D" suffix = data. These swap in different datasets (graphics, lookup tables, UI assets) for different game modes. All executable game code — including all gameplay logic — lives in APROG.BIN.

### Top-Level Program Flow (from `scripts/trace_flow.py`)

```
main() @ 0x06003000  [never returns — infinite loop]
│
├── hw_init() @ 0x060030FC  [called once at startup]
│   ├── 115 instructions, saves r14/r13/r12/r11/r10/pr
│   ├── Memory clearing loops (BSS initialization)
│   ├── Calls BIOS functions (0x06000320, 0x06000344)
│   └── Calls 15 initialization sub-functions:
│       0x0603BF7C, 0x06034E58, 0x06012CF4, 0x06003274,
│       0x06004A98, 0x06012E6A, 0x06003218, 0x06018EE4,
│       0x06005174, 0x0601F936, 0x0601492C, 0x060149E0, ...
│
└── MAIN LOOP (0x0600300A → 0x0600305C, 82-byte loop body)
    │
    └── main_game_func() @ 0x0600A392  [called every frame, returns normally]
        ├── Saves r14/r13/r12/pr — standard GCC prologue
        ├── Checks game state variables and dispatches conditionally
        ├── Calls 8 functions:
        │   ├── 0x06018EAC → 0x060349C4  (early-frame setup / timer?)
        │   ├── 0x060349C4                 (CD/data loading related?)
        │   ├── 0x06012B58                 (loops 5 iterations — per-car?)
        │   ├── 0x06009FFC                 (calls 0x0601D5F4 x5 with args 0-3 — mode init)
        │   ├── 0x0600A1B8                 (state checking, no sub-calls)
        │   ├── 0x06020BCE                 (tail-calls via jmp — state dispatcher)
        │   └── 0x0600026C [BIOS] x2       (IP.BIN area — system call)
        │
        └── FUN_06020BCE ends with jmp @r3 (tail call to game-mode handler)
            This is likely the game state machine dispatch point.
            The target function depends on current game mode.
```

**Key observations:**
- The entry point (`main`) runs an infinite loop that calls `main_game_func` once per frame, with frame control logic between calls.
- `main_game_func` is a **per-frame dispatcher**, not the racing loop itself. It checks game state and routes to the appropriate handler.
- `FUN_06020BCE` (called from `main_game_func`) ends with a **tail call** (`jmp @r3` after restoring `pr`). This is the game-mode dispatch — it jumps to a function pointer determined by the current game state without returning to `main_game_func`. The target function returns directly to `main`.
- Calls to `0x0600026C` (in the IP.BIN area) are BIOS system calls — likely vblank wait or controller read.

**Main loop candidate functions** (functions with many sub-calls AND backward branches — likely game-mode-specific update handlers):

| Address | Calls | Loops | Instructions | Likely Role |
|---------|-------|-------|-------------|-------------|
| `0x0601F9CC` | 46 | 6 | 426 | Highest call count — complex mode handler |
| `0x0601B160` | 44 | 2 | 381 | |
| `0x060116A8` | 41 | 1 | 354 | |
| `0x06011AF4` | 41 | 1 | 358 | |
| `0x06003578` | 40 | 4 | 390 | Close to entry point — could be boot/title sequence |
| `0x060092D0` | 37 | 5 | 470 | |
| `0x06012DB4` | 37 | 25 | 500 | Many loops — rendering or data processing? |

One of these candidates is the **racing mode per-frame handler** — the function that updates physics, steering, collision, and AI each frame during actual gameplay. Identifying which one requires tracing the dispatch chain from `FUN_06020BCE` or finding gameplay-specific references (controller input, car state structs).

### Hardware Access Patterns (from `scripts/find_hw_access.py`)

Scanning constant pool entries for Saturn hardware register addresses reveals which functions touch hardware directly vs. which are pure game logic.

| Hardware Region | Refs | Functions | Key Addresses |
|----------------|------|-----------|---------------|
| VDP2 VRAM | 111 | 26 | `0x25E00000`+ (backgrounds, HUD) |
| VDP2 color RAM | 119 | 38 | `0x25F00000`+ (palette management) |
| VDP2 registers | 7 | 5 | `0x25F80000`+ (display control) |
| VDP1 registers | 18 | 7 | `0x25D00000`+ (sprite/polygon draw) |
| VDP1 VRAM | 5 | 5 | `0x25C00000`+ (polygon data) |
| VDP1 framebuffer | 3 | 2 | `0x25C80000`+ (frame management) |
| SCSP sound RAM | 40 | 22 | `0x25A00000`+ (sound effects/music) |
| SMPC (controller) | 41 | 12 | `0x20100001`+ (input, system control) |
| SCU (DMA/interrupt) | 7 | 3 | `0x25FE0000`+ (DMA transfers) |
| SH2 on-chip | 24 | 13 | `0xFFFFFF00`+ (timers, interrupts) |

**Functional clusters identified:**

- **Rendering (61 functions)**: All VDP1/VDP2-accessing functions. These are the low-level graphics functions — exactly what we do NOT need for gameplay extraction. Key cluster: `0x06038E54`-`0x0603931C` (VDP1 register setup), many VDP2 functions scattered through `0x06003468`-`0x060429F2`.

- **Sound (22 functions)**: SCSP-accessing functions clustered at `0x06018EAC`-`0x06019250` and `0x0601D3C2`-`0x0601D6B2`. Note: `0x06018EAC` is called from `main_game_func` — this is the per-frame sound/audio update.

- **Controller input (12 functions)**: SMPC-accessing functions at `0x0601E2C2`-`0x0601E826`. These read controller state (digital buttons, analog steering). The gameplay code reads input through these functions — they're at the boundary between gameplay and hardware.

- **System/DMA (16 functions)**: SCU DMA at `0x06004AAC`, `0x0602749A`, `0x0603FE84`. SH2 on-chip at `0x06029C00`-`0x06034762`.

**Implication for gameplay extraction**: Any function that does NOT appear in the hardware access lists above is a candidate for pure game logic (physics, AI, collision, state management). The rendering and sound functions can be identified and separated — the gameplay code should be calling wrapper functions rather than touching hardware directly.

### Function Categorization (from `scripts/categorize_functions.py`)

**1234 total functions** identified (prologue scan including both `mov.l r14,@-r15` and `sts.l pr,@-r15` starters).

| Category | Count | Description |
|----------|-------|-------------|
| **unknown (gameplay candidates)** | 1096 | No direct hardware access — game logic, math, utilities |
| **rendering** | 70 | Direct VDP1/VDP2 register/VRAM access |
| **sound** | 38 | Direct SCSP access (clustered at `0x06018EE4`-`0x06019250`, `0x0601D3C0`-`0x0601D7A0`) |
| **input** | 13 | SMPC controller access (clustered at `0x0601E2B4`-`0x0601E810`) |
| **system_hw** | 12 | SH2 on-chip registers (timers, interrupts) |
| **system_dma** | 1 | SCU DMA setup |
| **sound_helper** | 2 | Wrapper functions that only call sound functions |

**Key finding: main loop candidate refinement.** Cross-referencing the main loop candidates (functions with many calls + loops) against hardware categories eliminates several:

| Address | Calls/Loops | Category | Status |
|---------|-------------|----------|--------|
| `0x0601F9CC` | 46/6 | rendering | Eliminated — VDP access |
| `0x0601B160` | 44/2 | rendering | Eliminated — VDP access |
| **`0x060116A8`** | **41/1** | **unknown** | **Gameplay candidate** |
| **`0x06011AF4`** | **41/1** | **unknown** | **Gameplay candidate** |
| `0x06003578` | 40/4 | rendering | Eliminated — VDP access |
| **`0x060092D0`** | **37/5** | **unknown** | **Gameplay candidate** (calls 5 non-hw functions) |
| `0x06012DB4` | 37/25 | sound | Eliminated — SCSP access |

The **three strongest candidates for the racing mode handler** are `0x060116A8`, `0x06011AF4`, and `0x060092D0`. These are large functions with many sub-calls and loops, no direct hardware access, and in the same general code region as `main_game_func` (`0x0600A392`).

**Unknown functions by address range:**

| Range | Unknown | Total | HW-accessing | Notes |
|-------|---------|-------|-------------|-------|
| `0x06003`-`0x06010` | 166 | 185 | 19 | Early code — entry point, init, core game logic |
| `0x06010`-`0x06020` | 227 | 311 | 84 | Mixed — more rendering/sound here |
| `0x06020`-`0x06030` | 142 | 156 | 14 | Mostly game logic |
| `0x06030`-`0x06040` | 493 | 511 | 18 | **Almost entirely non-HW** — likely utility/math library |
| `0x06040`-`0x06064` | 68 | 71 | 3 | Late code — data-adjacent utilities |

The `0x06030000`-`0x06040000` range (493 of 511 functions are non-HW) is likely the utility/math library section — linked last by the compiler. The gameplay-specific code is more likely in the `0x06003`-`0x06020` range near `main_game_func`.

### Global Variables & Data Structures (from `scripts/find_structs.py`)

**Global variable summary**: 642 BSS (uninitialized) globals referenced 3433 times, 738 data (initialized) globals referenced 1869 times, 347 Work RAM Low globals referenced 415 times.

**Most-referenced globals** (likely core game state):

| Address | Refs | Likely Role |
|---------|------|-------------|
| `0x0607EAD8` | 92 | Highest-ref global — game mode/frame counter? |
| `0x06089EDC` | 84 | Race state variable? |
| `0x0607E944` | 80 | Core state |
| `0x0607E940` | 76 | Core state |
| `0x06084FC8` | 55 | Subsystem state |
| `0x060A5400` | 46 | Data pointer/buffer? |
| `0x06063750` | 42 | Near BSS start — early-init variable |
| `0x06063D9A` | 39 | Part of control struct (see cluster #20) |

**Major struct clusters** (groups of nearby globals suggesting C structs):

| Base Address | Size | Fields | Refs | Likely Identity |
|-------------|------|--------|------|----------------|
| `0x060A4C38` | ~372B | 88 | 410 | **Largest struct** — car state? Has byte-level fields at +0x20/+0x21 |
| `0x06063DF8` | ~368B | 50 | 302 | **Near BSS start** — main game context? Fields +0x24 (18 refs), +0x28 (24 refs) heavily used |
| `0x06085F88` | ~214B | 53 | 291 | Dense byte fields at +0x00-+0x0A, +0x68-+0x6B — player/car data? |
| `0x060785FC` | ~212B | 51 | 230 | Mixed int/byte fields — game subsystem state |
| `0x0607884C` | ~184B | 38 | 212 | Field +0x33 has 31 refs — flag byte? |
| `0x0607EA8C` | ~100B | 17 | 252 | **Hottest per-field** — contains the 92-ref global at +0x4C |
| `0x0607EB84` | ~120B | 17 | 141 | Contains 38-ref global at +0x48 |
| `0x06089E96` | ~78B | 16 | 178 | Contains 84-ref global at +0x46 — 2-byte fields, race timing? |
| `0x06063D90` | ~28B | 8 | 99 | Small control struct — +0x08 (37 refs), +0x0A (39 refs) |

**Observations for gameplay extraction:**
- The cluster at `0x0607EA8C` (100 bytes, 252 refs) with the single most-referenced variable at +0x4C is almost certainly a **core game state struct** — something polled every frame by many subsystems.
- The large cluster at `0x060A4C38` (372 bytes, 88 fields) has the complexity of a **car/vehicle state struct** — position, velocity, rotation, steering, gear, etc. The byte-level field access (+0x20, +0x21) suggests flags or small counters.
- The cluster at `0x06063DF8` being near the start of BSS (first uninitialized memory after the file data) suggests it's a **primary context struct** — likely declared early in the source code.
- Fields with 2-byte access patterns (at `0x06089E96`) suggest **fixed-point 16-bit values** — common for physics calculations on SH-2.

These struct addresses are the next targets for Ghidra analysis — applying struct types in Ghidra and tracing cross-references from these fields to functions will reveal the gameplay subsystem boundaries.

---

## Original Development Toolchains

There were two compiler toolchains available to Saturn developers:

### 1. Cygnus GCC for SH2 (GNU Toolchain)

- Supplied by Sega to licensed developers via SOA (Sega of America)
- Maintained by **Toshiyasu Morita at SOA**, who applied Saturn-specific patches on top of quarterly Cygnus base releases
- Cygnus Solutions was an enterprise GNU support company that shipped quarterly toolchain builds (95q1, 95q2, 95q3, 95q4, 96q1, 96q2, 96q3)
- SOA releases followed a naming convention: `cygnus-{gcc_ver}-{quarter} SOA-{date}` (e.g., `cygnus-2.7-96q3 SOA-960904`)
- **GCC 2.6 era** (Oct 1994 - Aug 1995): Base `cygnus-2.6.0-941014`, used for early/launch Saturn titles including Daytona USA
- **GCC 2.7 era** (Aug 1995 onward): Migration happened with 95q3 release. Most preserved compiler builds are from this era
- Sega recommended against using C++ due to larger code size
- SDK files suffixed with `_G` are for the GNU toolchain
- The sotn-decomp project uses **cygnus-2.7-96Q3** for its Saturn target (GCC 2.7 era)
- Compiler binaries available at: https://github.com/sozud/saturn-compilers
- **Only cygnus-2.7-96Q3 binaries are known to be preserved** - earlier GCC 2.6 era builds have not been found

### 2. Hitachi SH-C (SHC) - Proprietary Compiler

- Custom SH-2 compiler developed by Hitachi
- Build commands: `ASMSH.EXE STRT1_H.SRC -cpu=7600` and `SHC.EXE -sub=LIB.SHC STRT2_H.C`
- Includes: SHC (C compiler), ASMSH (assembler), LNK (linker), librarian
- Output format: .ABS files (compiled and linked Saturn programs)
- Object format: SYSROF (File Header: `80 21 00 80`)
- SDK files suffixed with `_H` are for the Hitachi toolchain
- Can be found bundled with some Dreamcast SDK distributions

### Compiler Identified: Cygnus GCC

**CONFIRMED: Daytona USA (Saturn) was compiled with Cygnus GCC for SH-2.**

This was determined through analysis of function prologues in the binary. Example from `FUN_0600a392`:

```
0600a392  2f e6       mov.l   r14,@-r15      ; push r14
0600a394  2f d6       mov.l   r13,@-r15      ; push r13
0600a396  2f c6       mov.l   r12,@-r15      ; push r12
0600a398  4f 22       sts.l   pr,@-r15       ; push pr (return address)
0600a39a  7f f4       add     -0xc,r15       ; allocate local stack space
```

This pattern is characteristic of GCC's SH-2 calling convention:
1. Callee-saved registers pushed in descending order (r14, r13, r12) via `mov.l rN,@-r15`
2. `sts.l pr,@-r15` to save the return address placed **after** register saves
3. `add` to allocate local variable space

The Hitachi SHC compiler uses a different convention (saves `pr` first, different register ordering, distinct frame layout). This pattern unambiguously identifies GCC.

**No compiler identification strings** were found in the binary (no "GCC", "GNU", "cygnus" strings) - the release was stripped clean, which is standard for commercial Saturn titles.

**Compiler Version Analysis:**

The SOA compiler changelog (GCC.LOG, maintained by Toshiyasu Morita) documents every release from October 1994 through September 1996. Cross-referencing with Daytona's build date (1995-03-17):

| SOA Release | Date | GCC Base | Notes |
|---|---|---|---|
| `cygnus-2.6.0-941014-SOA-950201` | Feb 1, 1995 | GCC 2.6 | Earliest documented SOA patch |
| `cygnus-2.6.0-941014-SOA-950208` | Feb 8, 1995 | GCC 2.6 | |
| `cygnus-2.6.0-941014-SOA-950215` | Feb 15, 1995 | GCC 2.6 | |
| `cygnus-2.6-95q1-SOA-950317` | Mar 17, 1995 | GCC 2.6 | Migrated to 95q1 base — **matches Daytona build date** |
| **Daytona USA ships** | **~Apr 1995** | | |
| `cygnus-2.6-95q1-SOA-950406` | Apr 6, 1995 | GCC 2.6 | |
| ... | ... | ... | ... |
| `cygnus-95q3-SOA-950822` | Aug 22, 1995 | GCC 2.6→2.7 | **Migration to GCC 2.7 base** |
| ... | ... | ... | ... |
| `cygnus-2.7-96q3 SOA-960904` | Sep 4, 1996 | GCC 2.7 | Latest preserved build |

**Key finding**: Daytona was compiled with a **GCC 2.6**-based compiler (~`cygnus-2.6-95q1` era), while the only preserved compiler binaries are **GCC 2.7**-based (`cygnus-2.7-96q3`). The GCC backend changed between these versions (new optimizations, different code generation patterns documented in the changelog).

**Caveat**: AM2 was Sega Japan, not SOA. They may have used an internal Japanese build rather than the SOA distribution. The SOA changelog represents third-party developer releases. AM2's internal toolchain may differ in patch level or configuration.

**Implications:**
- The only preserved compiler (cygnus-2.7-96Q3) is from 18 months after Daytona shipped and uses a different GCC major version
- **Codegen testing confirms byte-matching with 96Q3 is infeasible** (see Codegen Comparison below)
- Many high-level code patterns (prologue/epilogue structure, delay slot filling, switch tables) are shared between GCC 2.6 and 2.7
- The sotn-decomp project uses 96Q3 successfully for later Saturn titles compiled with GCC 2.7
- **Recommended approach**: Pursue non-matching decomp with 96Q3 while searching for the original GCC 2.6 compiler. If GCC 2.6 is recovered, the C source can be recompiled for a byte-match

#### Identification Methods Used

| Method | Result |
|--------|--------|
| String search (GCC, GNU, Cygnus, Hitachi, SHC) | No compiler strings found (binary stripped) |
| Function prologue analysis | **GCC calling convention confirmed** |
| Library signature matching | **No SGL/SBL functions found** (0 matches across all 6 sig files) |

#### Codegen Comparison: cygnus-2.7-96Q3 vs Daytona Binary

Test C functions were compiled with `GCC.EXE -S -O2 -m2 -fsigned-char` using the cygnus-2.7-96Q3 compiler (via DOSBox-X) and compared against patterns in the Daytona binary. The compiler self-identifies as `Hitachi SH cc1 (cygnus-2.7-96q3 SOA-960904)`.

**What matches:**

| Pattern | 96Q3 Output | Daytona Binary |
|---------|-------------|----------------|
| pr save placement | After register saves | After register saves |
| Delay slot filling | Used (bt.s, bf.s, bra+delay) | Used identically |
| Switch jump tables | mova + relative .word offsets | Same structure |
| Frame pointer setup | `mov.l r14,@-r15` then `mov r15,r14` | Same |
| Leaf function style | Minimal prologue/epilogue | Same |
| Struct field access | `@(offset,rN)` displacement loads | Same |

**What differs — the critical blocker:**

Register save ordering in non-leaf function prologues is fundamentally different:

```
Daytona binary (GCC 2.6):          96Q3 output (GCC 2.7):
  mov.l  r14,@-r15  ; descending    mov.l  r8,@-r15   ; ascending
  mov.l  r13,@-r15                   mov.l  r9,@-r15
  mov.l  r12,@-r15                   mov.l  r10,@-r15
  sts.l  pr,@-r15                    mov.l  r14,@-r15
                                     sts.l  pr,@-r15
```

GCC 2.6 saves callee-saved registers in **descending** order (r14, r13, r12, ...) while GCC 2.7 saves in **ascending** order (r8, r9, r10, ..., r14). This is a fundamental change in the register allocator between GCC major versions. It affects every non-leaf function in the binary and cannot be worked around with compiler flags.

**Conclusion**: Byte-perfect matching with cygnus-2.7-96Q3 is **not feasible**. The register allocation ordering difference permeates the entire binary. However, the high-level codegen patterns (control flow, memory access, calling convention structure) are similar enough that 96Q3 is viable for a non-matching or near-matching decomp.

---

## Saturn SDK Libraries

### Sega Basic Library (SBL)

- Low-level API, close to bare metal hardware access
- Ideal for 2D pixel-based games or developers wanting full control
- Latest known version: 6.01 (earlier) / 6.21 (newest SDK dump from Sept 1997)
- Comes with source code

### Sega 3D Game Library (SGL)

- High-level API designed for 3D games
- Also called "Sega Graphics Library" in some documentation
- Latest known version: 3.02 (earlier) / 3.20 (newest SDK dump)
- Can be used alongside SBL

### Newest Known SDK

Released to Japanese developers in September 1997. Contents:
- SBL Ver.6.21
- SGL Ver.3.20 (PC and IRIX)
- Sound Tools (Mac)
- Graphics Tools (Windows/Mac)
- Cinepak Library Ver.1.21
- Online Manual Ver.2.50 (HTML)

Available on Internet Archive: https://archive.org/details/segasaturn-toolkit

---

## Matching Decompilation Methodology

### The Incremental Build Process

1. **Start with the original binary** extracted from the disc image
2. **Split** the binary into relocatable object files (one per function/data section)
3. **Create a linker script** that places everything at the original memory addresses
4. **Build** a binary from those objects - verify it matches the original (proves the pipeline works)
5. **Decompile** a function: write C code that compiles to matching assembly
6. **Replace** the assembly/object blob for that function with your compiled C object
7. **Verify** the full binary still matches after replacement
8. **Repeat** until all functions are decompiled

### Key Concept: Linking Decompiled C Alongside Original Binary Blobs

The critical insight is that you don't need to decompile everything before you can build. You create relocatable objects from the original binary, then replace each object one at a time with a decompiled C version. If the linker still generates a byte-identical binary, your decompilation is correct.

---

## Existing Reference Projects

### sotn-decomp (Castlevania: Symphony of the Night)

- **Repo**: https://github.com/Xeeynamo/sotn-decomp
- **THE key reference project** - includes Saturn, PSX, and PSP targets
- Achieves byte-for-byte matching builds
- Uses **GCCSH from cygnus-2.7-96Q3** for Saturn
- Saturn compiler binaries from: https://github.com/sozud/saturn-compilers
- Study their Makefile, build scripts, and CI pipeline for the Saturn target

### Reverse-Engineer-Azel (Panzer Dragoon Saga)

- **Repo**: https://github.com/Aeonitis/Reverse-Engineer-Azel
- Reverse engineering effort (not a strict matching decomp)
- Uses Ghidra with SH-2 processor support (added in Ghidra v9.1)
- Useful for understanding Saturn-specific RE challenges

### decomp-toolkit (dtk)

- **Repo**: https://github.com/encounter/decomp-toolkit
- Built for GameCube/Wii but the **methodology is directly applicable**
- Automates: binary splitting into relocatable objects, linker script generation, incremental replacement
- Writes object files directly (no assembler required)
- The concept would need to be adapted for SH-2/Saturn

---

## Required Tooling

| Tool | Purpose | Link |
|------|---------|------|
| Ghidra + Saturn Loader | Disassembly and static analysis | https://github.com/VGKintsugi/Ghidra-SegaSaturn-Loader |
| Original compiler | Byte-matching compilation | Cygnus GCC: https://github.com/sozud/saturn-compilers |
| asm-differ | Compare decompiled output to target | https://github.com/simonlindholm/asm-differ |
| decomp-permuter | Find matching C variations | https://github.com/simonlindholm/decomp-permuter |
| mips2c (concept) | Auto-decompile assembly to C (MIPS-specific, SH2 equivalent needed) | Used by sotn-decomp |
| Saturn emulator | Testing (Mednafen, Kronos, SSF) | - |
| Custom Makefile + linker script | Incremental build system | Build custom, reference sotn-decomp |

### Ghidra Saturn Loader Features

- Loads Saturn ISOs and emulator save states
- Creates functions for `main`, initial program (Sega logo code), and `security_check`
- Supports applying Sega Saturn library signatures (ApplySig script)
- Library signatures help distinguish SDK code from game-specific code

---

## Practical Roadmap

### Phase 0: Toolchain Identification & Feasibility [COMPLETE]

- [x] Extract binary from Daytona USA disc image (setup.ps1 converts BIN/CUE Track 01 to ISO)
- [x] Load into Ghidra with Saturn Loader (Ghidra 12.0.2 + Saturn Loader with version bump)
- [x] Analyze code generation patterns to determine GCC vs Hitachi SHC -> **Cygnus GCC confirmed**
- [x] Look for compiler identification strings in the binary -> No strings found (binary stripped), but prologue analysis was conclusive
- [x] Apply library signatures to identify SGL/SBL functions -> **No matches (0/197 SBL, 0/311 SGL)** - AM2 used entirely custom code, no standard SDK
- [x] Extract ISO 9660 filesystem and analyze contents (26 files: APROG.BIN + overlays + data)
- [x] Pin the Cygnus GCC version -> **Original is GCC 2.6 era (~cygnus-2.6-95q1), only preserved build is GCC 2.7 (cygnus-2.7-96q3 SOA-960904)**
- [x] Test cygnus-2.7-96Q3 codegen against Daytona binary patterns -> **Register allocation order differs (ascending in 2.7 vs descending in 2.6), byte-matching infeasible with 96Q3**
- [x] Decision: Pursue non-matching decomp with cygnus-2.7-96Q3. Byte-matching is not needed for gameplay extraction goal.

### Phase 1: Binary Mapping & Codebase Understanding [COMPLETE]

Map the full binary structure and begin categorizing the codebase. The gameplay code cannot be understood in isolation — it exists within a specific engine with specific data layouts, calling patterns, and shared state. Broad codebase understanding is required before gameplay extraction is meaningful.

- [x] Map out the binary layout (code, data, BSS sections, memory addresses) — see Binary Layout below. **Needs Ghidra verification.**
- [x] Identify the main loop and top-level program flow — see "Top-Level Program Flow" above. Entry point loops calling `main_game_func` per frame; `FUN_06020BCE` tail-calls game-mode-specific handlers.
- [x] Map the overlay loading system — All loading via `FUN_06012E6A`. GAMED.BIN = racing data overlay. Track-specific files (COURSEn, CSnPOLY, CSn_LINE, TEX_Cn) loaded per course. See "File Loading System" section.
- [x] Identify and document Saturn hardware access patterns — see "Hardware Access Patterns" section. 61 rendering functions, 22 sound, 12 controller input, 16 system/DMA identified.
- [x] Begin categorizing functions — 1234 functions: 70 rendering, 38 sound, 13 input, 12 system, 1096 unknown/gameplay candidates. Three racing handler candidates identified: `0x060116A8`, `0x06011AF4`, `0x060092D0`.
- [x] Identify core data structures — 9 major struct clusters found. Largest: 372B/88 fields at `0x060A4C38` (likely car state). Hottest: 100B/252 refs at `0x0607EA8C` (core game state). See "Global Variables & Data Structures" section.
- [x] Map global variable usage — 642 BSS globals (3433 refs), 738 data globals (1869 refs). Top global `0x0607EAD8` has 92 refs. Struct cluster analysis reveals likely car state, game state, race state, and control structs.

### Phase 2: Gameplay Subsystem Identification

Focus on finding and understanding the gameplay-critical code clusters.

- [ ] Identify the racing main loop (the per-frame update during actual gameplay)
- [ ] Map the physics subsystem: acceleration, braking, steering response, drift mechanics
- [ ] Map the collision subsystem: track boundaries, car-to-car, wall hits
- [ ] Map the AI subsystem: opponent behavior, rubber-banding, line selection
- [ ] Map race state management: lap counting, position tracking, timing
- [ ] Document fixed-point math conventions (Q format, shared math routines)
- [ ] Identify the interface boundary between gameplay and rendering (what does gameplay write that rendering reads?)
- [ ] Document frame timing assumptions (vblank-driven? fixed timestep?)

### Phase 3: Non-Matching Decompilation

Decompile broadly across the codebase, prioritizing gameplay functions but including enough surrounding context (data structures, utility functions, main loop) to make the gameplay code comprehensible and portable.

- [ ] Decompile core data structures to C structs (car state, track data, game state)
- [ ] Decompile shared utility/math functions
- [ ] Decompile gameplay subsystems to C (physics, collision, AI, race state)
- [ ] Decompile the main loop and game state management
- [ ] Validate decompiled functions via differential testing against emulator traces
- [ ] Document any coupling between gameplay and rendering discovered during decompilation

### Phase 4: CCE Analysis & Gameplay Transplant

Apply the same analysis to Championship Circuit Edition and plan the transplant.

- [ ] Obtain and extract CCE disc image
- [ ] Load CCE into Ghidra, identify compiler and structure
- [ ] Map CCE's equivalent subsystems (physics, collision, AI, race state)
- [ ] Identify interface differences between original and CCE (data formats, struct layouts, calling conventions)
- [ ] Design the transplant strategy: which original gameplay functions replace which CCE functions
- [ ] Handle coupling issues (frame timing, fixed-point formats, global state layout differences)
- [ ] Build and test a modified CCE with transplanted gameplay code

---

## Major Challenges Specific to This Project

### 1. Multi-Processor Architecture
The Saturn has dual SH-2 CPUs, a 68K sound CPU, and SCU DSP microcode. Each may need:
- Separate binary extraction
- Different toolchains (SH-2 compiler for main CPUs, 68K assembler for sound, SCU DSP assembler)
- Understanding of how code is distributed between processors

### 2. No Existing Decomp Community for This Game
Unlike SM64, OoT, or SotN, there's no existing community or infrastructure. This project is pioneering the tooling.

### 3. Gameplay/Engine Coupling
1990s game code under deadline pressure rarely has clean architectural boundaries. Expected coupling issues:
- Gameplay functions reading/writing global structs at hardcoded offsets
- Fixed-point math conventions shared between gameplay and rendering
- Frame timing assumptions baked into physics calculations
- Implicit dependencies on engine initialization order

### 4. Two-Game Transplant Complexity
The ultimate goal requires understanding not just the original, but also CCE — and mapping the interface differences between them. Data structures, memory layouts, calling conventions, and frame timing may all differ between versions.

### 5. Saturn-Specific Tooling Gaps
- No Saturn-specific equivalent of decomp-toolkit (binary splitter)
- No SH2-to-C decompiler equivalent of mips2c
- Ghidra's SH-2 decompiler output will need manual cleanup

### 6. No Standard SDK Functions Detected
FLIRT signature matching against all available SGL (2.0a, 2.1, 3.00, 3.02j) and SBL (6.0, 6.01) libraries produced **zero matches** (verified: byte conversion confirmed working via debug output).

**Confidence: High but not absolute.** Possible explanations:

1. **AM2 wrote entirely custom code** (most likely) - AM2 was Sega's elite internal arcade team. Daytona is a Model 2 arcade port; they would have brought their own engine rather than adopting the consumer-facing SGL/SBL. SGL was developed primarily for third-party developers.

2. **Pre-release / internal SDK variant** - As a launch title (March 1995), Daytona was developed against pre-release tools. AM2 may have used an earlier internal version of SBL (pre-6.0) or an AM2-specific internal library that was never distributed and therefore never signatured.

3. **Different compilation flags** - If AM2 compiled SDK source code themselves with different optimization settings than the libraries CyberWarriorX signatured, the byte patterns would not match even if the source was identical.

**Practical impact is the same regardless**: no function labels from signature matching. All identification must come from behavioral analysis, hardware register access patterns, and string cross-references. The codebase likely shares patterns with other AM2 Saturn titles (Virtua Fighter, Virtua Cop, etc.) which could help with future cross-referencing.

---

## Why NOT Jo Engine or libyaul

**Jo Engine** and **libyaul** are homebrew development SDKs that use modern GCC. They are **NOT suitable for matching decompilation** because:

- Modern GCC produces completely different code generation patterns than 1990s-era Cygnus GCC or Hitachi SHC
- Different register allocation, instruction scheduling, optimization passes
- Different C runtime startup code and library implementations
- The resulting binary would never match the original

These tools are great for writing new Saturn homebrew games, but useless for reproducing an original commercial binary.

However, a modern GCC-based toolchain **does** become relevant if pursuing a non-matching decompilation (see below).

---

## Matching vs Non-Matching Decompilation

There are two fundamentally different approaches to a decomp project, each with different goals, tradeoffs, and toolchain requirements.

### Matching Decompilation

The goal is to produce C source that compiles to a **byte-identical** binary using the original compiler. This is the gold standard used by projects like sm64, oot, and sotn-decomp.

**Advantages:**
- Automated, definitive verification: your output either matches or it doesn't
- Incremental progress is provable - each function can be independently verified
- The compiler itself catches subtle bugs (signed/unsigned errors, wrong operator precedence, off-by-one)

**Disadvantages:**
- Requires the exact original compiler, down to the version
- Tedious "compiler matching" work - fighting the compiler to emit specific instruction sequences
- If the original compiler can't be identified or obtained, this approach is blocked

### Non-Matching Decompilation

The goal is to produce **functionally equivalent** C source that compiles with any suitable toolchain (e.g., modern `sh2-elf-gcc`) and produces a working game. The binary will not be byte-identical to the original.

**Advantages:**
- No dependency on the exact original compiler
- Can use modern toolchains with better optimization (potentially faster-running output)
- More accessible to contributors who don't want to fight vintage compiler quirks
- Opens the door to modifications, enhancements, and ports from the start

**Disadvantages:**
- No automated binary-diff verification - correctness must be validated through other means
- Subtle bugs can hide: wrong signedness, off-by-one errors, edge case behavior differences
- These bugs may only manifest in specific gameplay scenarios (e.g., a collision edge case on one particular track corner)

### The SM64 Precedent

The SM64 community illustrates both approaches and their relationship:

1. The **matching decomp** (sm64 decomp) was completed first, producing verified-correct C source
2. **Then** that verified source was recompiled with modern GCC, `-O2`, and different flags
3. This produced enhanced builds (sm64-port, sm64ex, PC ports) that run faster and support mods

The key insight: the non-matching/enhanced builds were built **on top of** source whose correctness was already proven via matching. They didn't skip the verification step - they built on it.

### Decision: Non-Matching Decomp for Gameplay Extraction

This project pursues a **non-matching decompilation** using cygnus-2.7-96Q3. This decision was driven by two factors:

1. **Byte-matching is infeasible** — The original was compiled with GCC 2.6 (register saves in descending order), and only GCC 2.7 binaries are preserved (ascending order). This difference affects every non-leaf function.

2. **Byte-matching is unnecessary for the goal** — The project's purpose is extracting gameplay logic for transplant into CCE, not reproducing the original binary. Functional correctness matters; binary identity does not.

The compiler (96Q3) remains useful for compiling and testing decompiled C against SH-2 in an emulator, but the analysis depth is the same regardless of compiler — understanding the codebase's data structures, calling patterns, and global state is the real work.

**Note on GCC 2.6 recovery**: GCC 2.6.3 source code exists at the [GNU old-releases archive](https://gcc.gnu.org/pub/gcc/old-releases/gcc-2/) and [decompals/old-gcc](https://github.com/decompals/old-gcc) already builds GCC 2.6.3 from source on modern systems. Building a vanilla GCC 2.6.3 for `sh-hms` target is feasible if byte-matching ever becomes desirable (e.g., for verifying decompiled functions). The SOA-specific patches from Toshiyasu Morita would still be missing, but the register allocator behavior (the critical difference) comes from the GCC version itself.

---

## Differential Testing as a Validation Strategy

When a byte-matching build isn't possible (or as a complement to matching), **differential testing** can validate decompiled functions by treating the original binary as an oracle.

### Concept

Run both the original binary function and your C implementation through the same inputs, then compare:

1. **Return values** - given identical arguments, do both produce the same output?
2. **Memory side effects** - do both write the same values to the same addresses?
3. **Register state** - does the function leave the CPU in the same state?

This is essentially **black-box equivalence testing** at the function level.

### Test Harness Architecture

Two execution environments are needed:

**Original function execution:**
- Run in a Saturn emulator with scripting/debugging support, or a standalone SH-2 CPU interpreter
- Set up registers and memory to the function's expected input state
- Execute the function
- Capture outputs (return value, modified memory, register state)

**Decompiled function execution:**
- Option A: Compile natively (x86/ARM) with a thin shim mimicking the Saturn memory model
- Option B: Cross-compile for SH-2 and run in the same SH-2 interpreter (avoids platform-specific numeric differences)

A test harness feeds identical inputs to both and diffs the results.

### Where This Works Well

- **Pure functions**: Math, physics calculations, data transformations, lookup tables. A racing game has many of these (steering calculations, speed curves, collision math, matrix operations).
- **State machine logic**: AI decisions, game state transitions. Snapshot input state, compare output state.
- **Data parsing**: Track data loaders, asset decoders, configuration parsers.

### Where It Gets Harder

- **Hardware side effects**: Functions that write to VDP registers, trigger DMA, or interact with Saturn hardware need mocked hardware or captured register writes as part of the comparison.
- **Deep global state dependencies**: If a function reads from many global variables scattered across memory, all must be set up identically in both environments for every test case.
- **Floating point / fixed point edge cases**: SH-2 has specific behavior for overflow, rounding, and division by zero. Native x86 testing may not reproduce these exactly. Cross-compiling for SH-2 and running in an interpreter avoids this.
- **Input space coverage**: Some functions have enormous input spaces. Exhaustive testing is impossible, so there's always a gap. Fuzzing helps but doesn't guarantee every edge case is covered.

### Concrete Examples for Daytona USA

| Function Type | Test Approach |
|--------------|--------------|
| `calculate_steering(angle, speed)` | Feed 10,000+ angle/speed combinations, compare outputs |
| `check_collision(pos, bbox)` | Throw every plausible position/bounding box pair at both |
| `matrix_multiply(a, b)` | Random matrices in, compare transformed output |
| `ai_decide_next_action(state)` | Snapshot AI state, compare decision outputs |
| `decode_track_data(raw)` | Feed raw track segments, compare parsed structures |

### Confidence Levels

| Validation Method | Confidence | Effort | Automation |
|---|---|---|---|
| Byte-matching binary diff | Definitive (100%) | Requires exact compiler | Fully automated |
| Differential unit testing | High for tested paths | Requires test harness + emulator scripting | Automated once built |
| Fuzz testing (random inputs) | Good coverage, not exhaustive | Requires harness + fuzzer | Automated |
| Manual play testing | Low (misses edge cases) | Easy but unreliable | Manual |

### Related Work

- **N64 recompilation projects** (Zelda, Rocket Robot on Wheels) recompile original binaries to x86 and face similar equivalence validation problems. Their validation approaches are directly applicable.
- **decomp-permuter** explores C code variations to find matches, which is a form of automated search over the equivalence space.

### Recommendation

Differential testing is most valuable as:
- The **primary validation method** if pursuing a non-matching decomp with modern GCC
- A **complementary method** alongside binary matching, to catch logic-level bugs even when bytes match (matching proves compiler equivalence, but differential testing can validate semantic intent across a range of inputs)

Building the test harness is an upfront investment, but it pays off across every function decompiled afterward.

---

## Key Community Resources

- **RetroReversing** - Saturn-specific guides and documentation
  - https://www.retroreversing.com/saturn-reversing
  - https://www.retroreversing.com/sega-saturn-sdk/
  - https://www.retroreversing.com/sega-saturn-hitachi-compiler/
  - https://www.retroreversing.com/sega-saturn-compiling-samples/
- **SegaXtreme** - Saturn development community and forums
  - https://segaxtreme.net/
- **Decompedia** - General matching decomp knowledge base
  - https://decomp.wiki/
- **antime.kapsi.fi** - Archive of Saturn documentation and libraries
  - http://antime.kapsi.fi/sega/docs.html
- **The Cutting Room Floor** - Daytona USA Saturn page
  - https://tcrf.net/Daytona_USA_(Sega_Saturn)
- **Internet Archive** - Saturn SDK dumps
  - https://archive.org/details/segasaturn-toolkit

---

## Summary

The goal of this project is to extract the authentic Daytona USA gameplay code (physics, steering, collision, AI) and ultimately transplant it into Daytona USA Championship Circuit Edition, combining CCE's superior engine with the original's superior driving feel.

**Phases 0 and 1 are complete.**

Phase 0 findings: Cygnus GCC confirmed, non-matching decomp with 96Q3, no standard SDK (AM2 custom code), overlay architecture mapped.

Phase 1 findings:

- **1234 functions identified** and categorized: 70 rendering, 38 sound, 13 input, 12 system, 1096 unknown/gameplay candidates.

- **Program flow mapped**: Entry point → `hw_init` (one-time) → infinite main loop calling `main_game_func` per frame → `FUN_06020BCE` tail-calls game-mode-specific handlers.

- **File loading centralized**: All CD file loading via `FUN_06012E6A`. GAMED.BIN = racing data overlay. Track-specific data: COURSEn, CSnPOLY, CSn_LINE, TEX_Cn.

- **Hardware access isolated**: 61 VDP-touching rendering functions, 22 sound functions, 12 input functions identified. Functions NOT in these sets are pure game logic.

- **Three racing handler candidates**: `0x060116A8`, `0x06011AF4`, `0x060092D0` — large functions with many calls, loops, and no direct hardware access.

- **9 major data structures found**: Largest struct 372 bytes/88 fields at `0x060A4C38` (likely car state). Most-referenced global `0x0607EAD8` (92 refs) in a 100-byte struct at `0x0607EA8C` (likely core game state).

- **642 BSS globals** (3433 total references) and **738 data globals** (1869 refs) mapped.

**The approach requires broad codebase understanding.** Gameplay code from this era is not a clean separable layer — it's a web of shared mutable state, global structs, and implicit dependencies on engine context. Extracting the gameplay subsystems requires understanding the surrounding engine well enough to identify the interface boundaries.

**Next step**: Phase 2 — identify the racing main loop, map physics/collision/AI subsystems, and document fixed-point math conventions.
