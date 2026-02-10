# Daytona USA Saturn — Faithful C Reimplementation

> **Status**: Active — prerequisite work
> **Depends on**: Completed ASM annotation audit (46 files, 634 confidence scores, 138 fixes)
> **Predecessor**: gameplay_extraction.md (The Sawyer Approach — mapping phase COMPLETE)

## Framing: Preservation

This is a **preservation project**. The goal is a faithful C translation of Daytona
USA Saturn — not an improvement, not a port, not a rewrite with modern design
patterns. Every function is translated from the annotated ASM to preserve the
original engineers' intent. Improvements can come later.

## Strategic Pivot

The original goal was binary-matching C decompilation. That hit a ceiling:
- 53/867 PASS (6%) — capped by GCC 2.6.3 register allocation and scheduling
- Compiler-level differences are unfixable at the C level

The Sawyer Approach produced something far more valuable: **a complete annotated map
of all 1234 functions in the binary**, with confidence scores verified against the
production disassembly. This map IS the specification. We translate it to C.

## Approach

Faithfully translate every function from annotated ASM into readable C. The original
APROG.BIN and annotated `.s` files are the specification. We are translating, not
designing.

### What "faithful C" means
- Readable C compiled with a modern SH-2 toolchain (sh-elf-gcc)
- Preserves the exact game logic, control flow, and fixed-point math
- Does NOT need to produce identical machine code
- DOES need to produce identical gameplay behavior
- Hardware register writes match the original exactly (same values, same order)
- Data structures match the original layout byte-for-byte

### Clean break — no hybrid fallback
The previous decomp approach used C-wrapped inline asm (tools/gen_hybrid_funcs.py)
to mix original binary bytes with recompiled C. This created persistent problems:
- Constant pool entries contain hardcoded absolute addresses that can't be relocated
- Functions must stay at exact original addresses or pool references break
- The `.naked` GCC hack suppresses epilogues but ties us to the patched GCC 2.6.3
- Any function that grows past its original slot overflows into neighbors

**Decision: complete clean break from the original binary.** We build Daytona USA
from scratch in C using a modern SH-2 toolchain. No original bytes in the build.
No hybrid pipeline. No constant pool archaeology. The compiler and linker handle
all address resolution through normal symbols.

### Boot infrastructure — use Daytona's own
The Saturn boot chain is: BIOS → IP.BIN (from disc) → loads binary → jumps to entry.
Daytona's IP.BIN on the original disc already handles this. We reuse it unchanged —
our reimplemented binary replaces APROG.BIN at the same disc offset, same load
address (0x06003000). IP.BIN boots it identically.

There is no separate "crt0" to write. The first code in APROG.BIN (annotated in
system_init.s) IS the startup: it sets the stack pointer, configures hardware, and
enters the main loop. Our C translation of system_init.s is the startup code.

### Translation, not engineering
Every function we implement is a direct translation of annotated ASM:
- system_init.s tells us exactly which hardware registers to write, in what order
- vblank_system.s tells us exactly how the interrupt handler works
- game_loop.s tells us exactly how the 32-state machine dispatches
- We don't design abstractions — we translate what Daytona does

The only new code is minimal `#define` names for hardware register addresses,
for readability. The logic is 100% from the original.

## Reimplementation Quality Levels

Translation happens in iterative passes. Each level builds on the previous one.
Not every function needs to reach L4 — the target level depends on the end goal.

### L1: Decomp Lift
- Direct copy from Ghidra output / src/*.c, fixed to compile under modern sh-elf-gcc
- Hardcoded addresses everywhere: `*(int *)0x060280F4`
- All functions named `FUN_XXXXXXXX`
- Raw pointer casts, no structs, no named constants
- **Value**: compiles and runs, but no more readable than the disassembly
- **Effort**: low — mostly mechanical syntax fixes

### L2: Named & Structured
- Hardware registers replaced with `#define` names (`VDP2_TVMD`, `SCSP_SLOT0_VOL`)
- Known data structures expressed as C structs (`CarState`, `CameraParams`)
- Functions given meaningful names based on annotated ASM (`update_car_physics`)
- Named constants for magic numbers (`STATE_RACE_INIT`, `MAX_CARS`)
- Game globals given descriptive names (`g_frame_counter`, `g_active_car_count`)
- **Value**: a developer can read a function and understand what it does
- **Effort**: moderate — requires cross-referencing ASM annotations with code

### L3: Clean Reimpl
- Code restructured for clarity while preserving exact logic
- Helper functions extracted where the original used repeated inline patterns
- Comments explaining *why* (game design intent), not just *what*
- Control flow simplified where Ghidra produced unnecessarily tangled output
- **Value**: someone unfamiliar with the project could understand the game logic
- **Effort**: high — requires deep understanding of each subsystem

### L4: Preservation-Tier ("Time Travel")
- Written as if you were a Sega AM2 engineer in 1994 writing Daytona from scratch
- Idiomatic C of the era — no modern patterns, no over-abstraction
- Function and variable naming consistent with known Sega conventions
- Could serve as a reference implementation for game preservation archives
- **Value**: the definitive readable version of Daytona USA Saturn's source
- **Effort**: very high — requires holistic understanding of the entire codebase

### Current Strategy: Iterative Passes

**Pass 1 (current)**: L1 decomp lift of all ~1200 functions. Get everything compiling
and linked. This is the "rough cut" — quantity over quality. The goal is complete
coverage so we can boot and test.

**Pass 2 (next)**: Promote critical-path functions to L2. Priority order:
1. Hardware init (system_init, VDP, sound) — needed to understand boot
2. Game loop and state machine — needed to understand flow
3. Physics and collision — needed for CCE transplant
4. Rendering pipeline — needed to understand visual output

**Pass 3 (if pursuing preservation)**: Promote gameplay-critical functions to L3/L4.
This is the "time travel" pass. Only worth doing if we decide the reimpl itself
is a preservation goal, not just a stepping stone to CCE.

**For CCE transplant**: L2 is the minimum viable level. We need to understand what
each function does well enough to adapt it for CCE's different memory layout and
hardware configuration. L1 code with raw addresses can't be transplanted — the
addresses are different in CCE.

## Key Hypotheses

### H1: Cycle count matching is NOT required
The real constraints are:
1. **Frame budget** — all work must complete before VBlank (~33ms at 30fps)
2. **Hardware timing** — DMA transfers, VDP1 command submission, SCSP mailbox
   writes must happen at correct moments (not with identical duration)
3. **Numerical identity** — fixed-point math must produce bit-identical results
   (same precision, same rounding, same overflow behavior)
4. **Busy-wait self-regulation** — polling loops (sound mailbox, VBlank sync)
   naturally adapt to timing differences

A modern compiler producing 30% fewer instructions is fine — it means more idle
time per frame, not different behavior. The game is VBlank-locked anyway.

### H2: Data structure fidelity is critical
The car struct (40 slots x 0x268 bytes at 0x06078900) must have identical layout.
Every offset (+0x10 = X, +0x14 = Y, +0x18 = Z, etc.) must match because:
- The original code uses hardcoded offsets, not field names
- Multiple subsystems access the same struct with different offsets
- Getting one offset wrong cascades through physics, rendering, AI

### H3: The annotation confidence scores predict reimplementation risk
- DEFINITE functions (6 files): can reimplement with high confidence
- HIGH functions (29 files): can reimplement, may need binary verification
- MEDIUM functions (10 files): need additional reverse engineering
- SPECULATIVE (ai_opponents.s): needs complete rework before reimplementation

### H4: Growing from zero is safer than incremental replacement
The previous plan considered replacing functions one-at-a-time against original
binary fallbacks. This creates constant pool address dependencies and ABI
compatibility risks. Instead, growing the game from scratch means:
- Every function call resolves through the linker — no hardcoded addresses
- No ABI mismatch risk — all code compiled by the same modern toolchain
- Each milestone is independently testable without the original binary
- Debugging is straightforward — all code is readable C, no opaque byte blobs

Risk: we can't play the "full game" until late milestones. But each milestone
produces a concrete, testable artifact (VBlank firing, sprite drawn, menu working).

## Open Questions

### Q1: Which modern toolchain?
- Modern GCC for SH-2 (sh-elf-gcc) — closest to what we know, Saturn homebrew uses it
- Clang/LLVM with SH-2 backend — better optimization, but less tested for SH
- Saturn homebrew community toolchains: libyaul, Jo Engine — proven to work
- Need: bare-metal SH-2, custom linker scripts, runs on WSL Ubuntu
- Key test: compile a trivial program, link for Saturn memory map, boot in Mednafen

### Q2: How to verify "identical gameplay behavior"?
- Screenshot comparison at key frames (existing test_boot.ps1 pipeline)
- Game state dumps: compare car positions, speeds, lap counts between original
  and reimplemented versions at matching frame numbers
- Input replay: record controller inputs on original, play back on reimplemented,
  compare state divergence
- What emulator hooks are available in Mednafen for state inspection?

### Q3: Fixed-point math — compiler gotchas?
- Original uses 32-bit integer arithmetic for everything (no FPU on SH-2)
- `(a * b) >> 16` — does the compiler preserve 64-bit intermediate? (SH-2 has
  dmuls.l which gives 64-bit result in MACH:MACL)
- Modern GCC may optimize fixed-point idioms differently
- May need `__attribute__((noinline))` or explicit asm for critical math paths
- The sin/cos table (4096 entries, mask 0x3FFC) must be bit-identical

### Q4: What's the minimum set of functions for first boot?
- system_init.s functions set up VDP, SCU, SCSP — translate these first
- vblank_system.s installs interrupt handler
- game_loop.s runs the 32-state machine
- state 0 is the initial state — what does it need?
- How many functions does state 0 call before reaching "PRESS START BUTTON"?
- Trace the actual call graph from entry point through first visible frame

### Q5: Daytona's IP.BIN — any surprises?
- Need to analyze the IP.BIN from the original disc
- Does it do anything beyond loading APROG.BIN and jumping to 0x06003000?
- Does it set up any hardware state that APROG.BIN depends on?
- Does it configure the slave SH-2 (SH-1)?

### Q6: How to handle the SPECULATIVE ai_opponents.s?
- The annotations are largely fabricated (mid-function SMPC offsets, not AI)
- Real AI behavior is in ai_behavior.s (HIGH confidence) and ai_physics_pipeline.s
- Need fresh analysis of the 0x06034xxx-0x06035xxx range before reimplementing
- This is the biggest annotation gap remaining

## Milestone Plan

### M1: Saturn Bootstrap
**Goal**: Boot to steady VBlank cadence
**Source**: system_init.s (31 functions), vblank_system.s (9 functions),
frame_timing.s (9 functions)
**Annotation confidence**: MEDIUM / DEFINITE / DEFINITE
**Proof**: Emulator shows VBlank interrupt firing at 60Hz, no crash

### M2: Display Pipeline
**Goal**: VDP1 + VDP2 initialized, draw something on screen
**Source**: vdp_hardware.s (10 functions), rendering.s (6 functions),
vdp_scene_rendering.s (45 functions)
**Annotation confidence**: HIGH / HIGH / MEDIUM
**Proof**: Colored background or static sprite visible

### M3: Input + State Machine
**Goal**: 32-state machine running, controller input working
**Source**: input_smpc.s (3 functions), game_loop.s (4 functions),
state_handlers.s (17 functions)
**Annotation confidence**: DEFINITE / DEFINITE / MEDIUM
**Proof**: State transitions responding to button presses

### M4: Menu Flow
**Goal**: Navigate menus, select course
**Source**: pre_race_states.s (19 functions), menu_display.s (24 functions),
sound.s (10 functions), sound_driver.s (8 functions)
**Annotation confidence**: DEFINITE / MEDIUM / HIGH / MEDIUM
**Proof**: Full menu navigation, course selection, transition to race

### M5: Race Init
**Goal**: Enter race state, car objects allocated, track loaded
**Source**: object_management.s (9 functions), track_geometry.s (25 functions),
per_car_loop.s (3 functions)
**Annotation confidence**: HIGH / HIGH / HIGH
**Proof**: Race state entered, car structs initialized, track data present

### M6: 3D Rendering
**Goal**: Track and cars visible on screen
**Source**: math_transform.s (15 functions), math_helpers.s (23 functions),
vertex_pipeline.s (13 functions), scene_camera.s (32 functions),
scene_renderer.s (4 functions), render_pipeline.s (36 functions)
**Annotation confidence**: HIGH across all
**Proof**: 3D track geometry rendering, camera positioned behind car

### M7: Player Physics
**Goal**: Drive the car around the track
**Source**: player_physics.s (10 functions), force_system.s (5 functions),
force_tables.s (6 functions), speed_position.s (2 functions),
collision.s (10 functions), collision_response.s (2 functions),
car_collision.s (1 function), lap_counting.s (8 functions)
**Annotation confidence**: HIGH / HIGH / HIGH / DEFINITE / HIGH / HIGH / HIGH / HIGH
**Proof**: Car responds to input, drives on track, collides with walls

### M8: AI + Full Race
**Goal**: Complete race with opponents
**Source**: ai_behavior.s (10 functions), ai_physics_pipeline.s (19 functions),
race_states.s (11 functions), race_update.s (5 functions),
race_orchestration.s (13 functions), event_queue.s (17 functions),
hud_ui.s (12 functions), display_elements.s (9 functions)
**Annotation confidence**: HIGH / HIGH / HIGH across race systems
**Proof**: Full 3-lap race with AI opponents, timer, HUD, results screen

## Prerequisites Before M1

### P1: Toolchain
- Install sh-elf-gcc on WSL (Saturn homebrew community standard)
- Linker script placing code at 0x06003000 (matching APROG.BIN load address)
- Build script: compile → link → inject into disc image → CUE+BIN for Mednafen
- Verify: compile trivial program, boot in Mednafen, confirm no crash

### P2: Analyze Daytona's boot chain
- Extract and analyze IP.BIN from the original disc
- Confirm it just loads APROG.BIN to 0x06003000 and jumps to entry
- Identify any hardware state IP.BIN sets up before APROG runs
- Document the exact entry conditions our code inherits

### P3: Register name headers (readability only)
- `#define` names for Saturn hardware registers used by system_init.s
- NOT an abstraction layer — just named constants so the C reads clearly
- Derived directly from the annotated ASM, not from Saturn documentation
- Example: `#define VDP2_TVMD (*(volatile short*)0x25F80000)`

### P4: Data structures (translated from ASM offsets)
- Car object struct: translate every offset from annotations into C struct fields
- Game state globals: translate 0x0605xxxx references into named variables
- These emerge naturally during function translation — don't pre-engineer
- Build the struct incrementally as we translate functions that use it

---
*Created: 2026-02-10*
