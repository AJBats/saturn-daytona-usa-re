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

### Disc Structure (from string analysis)

The data track (Track 01) contains the boot code plus first file. Tracks 02-22 are CD-DA audio (the Daytona soundtrack). The game loads additional files from the CD filesystem at runtime:

| File | Purpose |
|------|---------|
| `APROG.BIN` | Main game program (loaded after boot) |
| `CS0POLY.BIN`, `CS1POLY.BIN`, `CS2POLY.BIN` | Polygon data for 3 courses |
| `CS0_LINE.BIN`, `CS1_LINE.BIN`, `CS2_LINE.BIN` | Racing line data |
| `COURSE0.BIN`, `COURSE1.BIN`, `COURSE2.BIN` | Course data |
| `TEX_PL.BIN`, `TEX_C1.BIN`, `TEX_C2.BIN` | Textures (player, course 1, course 2) |
| `POLYGON.BIN` | Additional polygon data |
| `SCROLL.BIN` | Scroll/background data |
| `TABLE.BIN` | Data tables |
| `PIT.BIN` | Pit stop data |
| `SOUNDS.BIN` | Sound effects |
| `GAMED.BIN`, `GAME0.BIN`, `GAME1.BIN` | Game logic data |
| `SLCTD.BIN` | Select screen data |
| `OVERD.BIN`, `OVER0.BIN` | Game over screen data |
| `NAMD.BIN` | Name entry screen data |
| `MUSICD.BIN`, `MUSIC2D.BIN`, `MUSIC3D.BIN` | Music sequencing data |

Hidden features found in strings: `MIRROR MODE`, `DAYTONA UMA` / `HORSE` (secret horse mode).

**Note**: The Ghidra Saturn Loader only loads the IP.BIN (boot code) + first file from the ISO. `APROG.BIN` and all data files above would need to be extracted separately from the ISO filesystem for complete analysis.

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

### Phase 1: Binary Mapping & Codebase Understanding

Map the full binary structure and begin categorizing the codebase. The gameplay code cannot be understood in isolation — it exists within a specific engine with specific data layouts, calling patterns, and shared state. Broad codebase understanding is required before gameplay extraction is meaningful.

- [ ] Map out the binary layout (code, data, BSS sections, memory addresses)
- [ ] Identify the main loop and top-level program flow
- [ ] Map the overlay loading system (GAMED.BIN, SLCTD.BIN, etc. — which overlay runs during actual racing?)
- [ ] Identify and document Saturn hardware access patterns (VDP1/VDP2 register writes, DMA setup, interrupt handlers)
- [ ] Begin categorizing functions: **gameplay**, **rendering**, **system/hardware**, **sound**, **data loading**, **UI/menus**
- [ ] Identify core data structures (car state struct, track data, input state, game state)
- [ ] Map global variable usage — which globals does the gameplay code read/write?

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

**Phase 0 is complete.** Key findings:

- **Compiler confirmed**: Cygnus GCC for SH-2 (GCC 2.6 era, ~`cygnus-2.6-95q1`). Only GCC 2.7 binaries (`cygnus-2.7-96q3`) are preserved. Byte-matching is infeasible due to register allocator changes between GCC versions, but this is irrelevant to the project goal.

- **Approach decided**: Non-matching decomp using cygnus-2.7-96Q3 for compilation/testing. The focus is functional correctness and codebase understanding, not binary reproduction.

- **Tooling in place**: Ghidra 12.0.2 with Saturn Loader. DOSBox-X with cygnus-2.7-96Q3 for test compilation.

- **No standard SDK used**: AM2 wrote entirely custom code. No SGL/SBL functions detected. Every function must be identified through behavioral analysis.

- **Overlay architecture identified**: Seven 436KB overlay programs swapped into the same memory region at runtime, forming a state machine for game modes. The racing gameplay overlay is the primary target.

**The approach requires broad codebase understanding.** Gameplay code from this era is not a clean separable layer — it's a web of shared mutable state, global structs, and implicit dependencies on engine context. Extracting the gameplay subsystems requires understanding the surrounding engine (data structures, main loop, memory layout, frame timing) well enough to identify the interface boundaries. This is close to a full decomp in analysis depth, but freed from the tedious compiler-matching work that a byte-identical build would require.

**Next step**: Phase 1 — map the binary layout and begin categorizing the codebase.
