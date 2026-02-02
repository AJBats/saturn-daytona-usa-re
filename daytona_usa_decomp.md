# Daytona USA (Sega Saturn) - Matching Decompilation Research

## Overview

This document captures research into the feasibility and approach for a matching decompilation of Daytona USA for the Sega Saturn. A matching decomp means writing C source code that, when compiled with the original toolchain, produces a byte-identical binary to the original game.

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

## About Daytona USA (Saturn)

- **Developer**: Sega AM2 (Yu Suzuki's division) / AM Annex (porting team)
- **Release**: April 1, 1995 (JP), May 11, 1995 (US) - Saturn launch title
- **Arcade original**: Ran on Sega Model 2 hardware (Intel i960 CPU) - completely different architecture
- **Saturn port**: Written specifically for SH-2, not a direct port of arcade code
- **Variant**: Daytona USA Championship Circuit Edition was a later improved version
- **TCRF**: Categorized as having debugging functions - https://tcrf.net/Daytona_USA_(Sega_Saturn)
- **No existing decomp project found** as of this research

---

## Original Development Toolchains

There were two compiler toolchains available to Saturn developers:

### 1. Cygnus GCC for SH2 (GNU Toolchain)

- Supplied by Sega to licensed developers
- Based on GCC 2.7 from Cygnus Solutions (enterprise GNU support company)
- Sega recommended against using C++ due to larger code size
- SDK files suffixed with `_G` are for the GNU toolchain
- The sotn-decomp project uses **cygnus-2.7-96Q3** for its Saturn target
- Compiler binaries available at: https://github.com/sozud/saturn-compilers

### 2. Hitachi SH-C (SHC) - Proprietary Compiler

- Custom SH-2 compiler developed by Hitachi
- Build commands: `ASMSH.EXE STRT1_H.SRC -cpu=7600` and `SHC.EXE -sub=LIB.SHC STRT2_H.C`
- Includes: SHC (C compiler), ASMSH (assembler), LNK (linker), librarian
- Output format: .ABS files (compiled and linked Saturn programs)
- Object format: SYSROF (File Header: `80 21 00 80`)
- SDK files suffixed with `_H` are for the Hitachi toolchain
- Can be found bundled with some Dreamcast SDK distributions

### Determining Which Compiler Was Used for Daytona USA

This is the **critical first step**. Methods to identify:

1. **Code generation patterns**: GCC and SHC produce recognizably different assembly idioms (register allocation, function prologues/epilogues, optimization patterns)
2. **String artifacts**: Compiler-specific strings may be embedded in the binary
3. **Debug info**: TCRF notes the game has debugging functions - these may contain compiler identification
4. **Library linkage**: Check if linked SDK code matches `_G` or `_H` variants
5. **Comparison**: Compile a simple test function with both compilers and compare output patterns to what's in the Daytona binary

As an internal Sega AM2 title from 1995, either toolchain is plausible.

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

### Phase 0: Identify the Toolchain

- [ ] Extract binary from Daytona USA disc image
- [ ] Load into Ghidra with Saturn Loader
- [ ] Apply library signatures to identify SGL/SBL functions
- [ ] Analyze code generation patterns to determine GCC vs Hitachi SHC
- [ ] Look for compiler identification strings in the binary
- [ ] Obtain the matching compiler version

### Phase 1: Get a Non-Matching Build Working

- [ ] Map out the binary layout (code, data, BSS sections, memory addresses)
- [ ] Write a linker script that reassembles raw sections into a byte-identical binary
- [ ] Set up the build system (Makefile)
- [ ] Verify byte-identical output from the raw reassembly
- [ ] This proves the build pipeline before writing any C

### Phase 2: Function-Level Splitting

- [ ] Identify all function boundaries in Ghidra
- [ ] Split code sections into individual functions (as .s files or raw object blobs)
- [ ] Handle data references and relocations between functions
- [ ] Verify the build still matches after splitting

### Phase 3: Incremental Decompilation

- [ ] Start with simple/small functions (utility functions, math helpers)
- [ ] Write C that compiles to matching assembly
- [ ] Use asm-differ to compare output
- [ ] Replace assembly blobs with compiled C in the build
- [ ] Verify full binary match after each replacement
- [ ] Tackle library identification (mark SDK functions as known)
- [ ] Progress to larger, more complex functions

### Phase 4: Full Source Build

- [ ] All functions decompiled to C
- [ ] Full binary built entirely from C source
- [ ] Byte-identical to original
- [ ] Document build process and dependencies

---

## Major Challenges Specific to This Project

### 1. Multi-Processor Architecture
The Saturn has dual SH-2 CPUs, a 68K sound CPU, and SCU DSP microcode. Each may need:
- Separate binary extraction
- Different toolchains (SH-2 compiler for main CPUs, 68K assembler for sound, SCU DSP assembler)
- Understanding of how code is distributed between processors

### 2. No Existing Decomp Community for This Game
Unlike SM64, OoT, or SotN, there's no existing community or infrastructure. You'd be pioneering the tooling.

### 3. Compiler Identification Uncertainty
If AM2 used the Hitachi SHC compiler (rather than Cygnus GCC), the toolchain is harder to obtain and less documented in the decomp community.

### 4. Saturn-Specific Tooling Gaps
- No Saturn-specific equivalent of decomp-toolkit (binary splitter)
- No SH2-to-C decompiler equivalent of mips2c
- Ghidra's SH-2 decompiler output will need manual cleanup

### 5. Library Code Volume
A significant portion of the binary will be SGL/SBL library code. This needs to be identified and separated from game logic. The Ghidra Saturn Loader's library signature support helps here.

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

### Recommended Strategy

**Try matching first, fall back to non-matching if needed:**

1. Load the binary into Ghidra and identify the compiler
2. If it's Cygnus GCC (available via sozud/saturn-compilers), pursue matching
3. If it's Hitachi SHC and unobtainable, pivot to non-matching with modern `sh2-elf-gcc`
4. No work is wasted in the pivot - Ghidra analysis, function identification, linker scripts, and data extraction all carry over

### Hybrid Approach

A practical middle ground: keep performance-critical or hard-to-verify sections (3D engine core, inner loops) as original assembly, and decompile the higher-level game logic (menus, AI, course data, game state management) to C. This gives moddability where it matters most without needing to perfectly nail every optimization in the rendering pipeline.

| Approach | Verification | Toolchain Requirement | Moddability |
|----------|-------------|----------------------|-------------|
| Matching decomp | Binary diff (definitive) | Exact original compiler | After completion |
| Non-matching decomp | Functional testing | Any SH-2 compiler | Immediate |
| Hybrid (asm + C) | Mix of both | Any SH-2 compiler | Partial, where it counts |

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

A decompilation of Daytona USA for Sega Saturn is feasible in principle, with multiple viable approaches depending on goals and constraints:

- **Matching decomp** is the gold standard and should be attempted first. The methodology is proven (see sotn-decomp), the analysis tools exist (Ghidra + Saturn Loader), and period-correct compilers are obtainable. The main risk is identifying the exact compiler AM2 used.

- **Non-matching decomp** with a modern SH-2 GCC toolchain is a pragmatic fallback. It sacrifices binary-diff verification but gains toolchain accessibility and immediate moddability. The SM64 community demonstrates that this approach has legs, though ideally it builds on verified source.

- **Differential testing** fills the verification gap when byte-matching isn't available. By treating original binary functions as oracles and comparing against decompiled C across thousands of inputs, you get high (though not absolute) confidence in correctness.

- **Hybrid approaches** (keeping critical assembly, decompiling game logic) offer a practical middle ground for a solo or small-team effort.

The recommended first step regardless of approach is loading the binary into Ghidra, applying library signatures, and analyzing code patterns to determine the original compiler. That answer determines which path is most practical. No work is wasted if the approach changes - analysis, function identification, and build infrastructure carry over between strategies.
