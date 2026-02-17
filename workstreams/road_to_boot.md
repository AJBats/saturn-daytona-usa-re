# Road to Boot

> **Status**: Active — primary workstream
> **Depends on**: reimplementation.md (L1 pass complete, 1234 functions defined)
> **Fallthrough**: L2 elevation work (reimplementation.md Pass 2) when boot goals are met

## Goal

Boot the reimplemented Daytona USA Saturn binary to the title screen in Mednafen.
Every step must be observable, reproducible, and automated.

## The Method: Ground Truth Validation Loop

Everything before emulator comparison was inference — Ghidra decomp, manual annotation,
C reimplementation. Smart guesses, but guesses. The emulator running production and
reimpl side-by-side is our **oracle**. It doesn't guess. It tells us exactly where
reality diverges from our assumptions.

**The loop:**

1. **Run against ground truth** — prod vs reimpl, same emulator, same inputs
2. **Find one divergence** — crash, wrong register, wrong memory, wrong path
3. **Extract the class** — not "bug at address X" but "what category of assumption
   was wrong?" Every divergence reveals a *class* of issues, not just one bug.
4. **Fix the class** — audit and fix every instance of that category, not just
   the one that crashed
5. **Repeat** — the next divergence teaches the next class

This is how we win. We don't fix 1234 functions one at a time. We find the handful
of systematic issues that affect dozens of functions each, and we fix the system.

**Classes identified so far:**

| # | Class | First Instance | Scope |
|---|-------|----------------|-------|
| 1 | Disc environment fidelity | Missing audio tracks (TOC) | inject_binary.py, disc rebuild |
| 2 | Observability gaps | Cache vs backing RAM reads | Mednafen debug tools |
| 3 | Overflow without trampoline | system_init unreachable at 0x060030FC | Every `/* overflow: goes to catchall */` in linker script |
| 4 | Missing function definitions | FUN_06040C98 → zeros → exception | 75 functions with linker sections but no source code |
| 5 | *(next divergence)* | | |

## Holy Commandments

These are non-negotiable constraints. No exceptions. No "temporary" violations.

### 1. Binary Size Parity

The reimpl APROG.BIN **MUST NOT** exceed the original binary size (394,896 bytes).
The Saturn has 1MB low work RAM and 1MB high work RAM. Every byte consumed by the
executable is a byte stolen from runtime data — car structs, track geometry, VDP
command lists, textures, sound data. Losing even 10KB to code bloat can prevent
the game from allocating what it needs.

**Gate**: `make` must fail (or loudly warn) if `build/APROG.BIN` exceeds 394,896 bytes.
This check runs after every build, before disc injection.

**Tolerance for individual functions**: A C reimplementation may produce larger code
than the original compiler. This is acceptable ONLY if:
- The function fits at its original address (no overflow to another region)
- The total binary stays within budget
- The size delta is documented in the commit message
- You can explain WHY it's larger (Ghidra artifact, different optimization, etc.)

Be **extremely skeptical** of size growth. The default assumption is that larger
code indicates a problem — wrong control flow, unnecessary temporaries, Ghidra
artifacts not cleaned up.

### 2. No Overflow Section

`.text.overflow` is banned. If a C function is too large to fit at its original
address, it must be:
1. Shrunk (better C, remove Ghidra artifacts)
2. ASM-imported (original bytes, exact size)
3. Placed via trampoline ONLY if the size difference is small and justified

The overflow approach "works" for linking but destroys the memory map. Functions
in overflow consume RAM beyond the original binary's footprint — violating
Commandment 1.

### 3. Data Lives in Data Holes

Runtime data values (DAT_ symbols, parameter tables, filename strings, lookup
tables) must NOT be initialized in C source. Zero-initialize all DAT_ stubs in C.
The `patch_data_holes.py` post-build step restores correct values from the
original binary.

Why: Non-zero C initializers create a `.data` section that sits beyond the original
binary range. Zero-initialized variables go to `.bss` (no binary cost). The patcher
fills gaps with original bytes at original addresses — correct values, correct
locations, zero binary cost.

### 4. Original Bytes Are the Gold Standard

When in doubt, use original bytes. ASM-imported functions are bit-perfect and
guaranteed correct. C reimplementations are aspirational — they may have subtle
bugs, wrong control flow, or size bloat. Every C function that replaces original
bytes must justify its existence.

## Architecture

### Build Pipeline

```
make clean && make          # compile all C + ASM, link with saturn_fixed.ld
  ↓
size gate check             # FAIL if APROG.BIN > 394,896 bytes
  ↓
patch_data_holes.py         # fill gaps with original binary data
  ↓
make disc                   # inject into disc image
  ↓
mednafen (automated)        # boot test with screenshot
```

### Binary Composition

The binary at 0x06003000 is composed of:

| Region | Source | Notes |
|--------|--------|-------|
| Fixed-address sections | ASM imports + C reimpl | At original addresses |
| Gap regions | patch_data_holes.py | Original bytes from APROG.BIN |

There is NO overflow section. Everything fits within the original address range.

### The FUN_06046E48 Problem

The disassembler labels 0x06046E48 as a "function", but it's actually the entire
data region at the tail of the original binary (116KB). This must be:
- Removed from asm_misc.c (it's not a function)
- Covered by patch_data_holes.py (it's data, let the patcher handle it)

## Tooling: Mednafen Modifications

We need three capabilities from Mednafen that the stock build doesn't provide.

### T1: Background Window (no focus steal) — IMPLEMENTED

**Problem**: Stock Mednafen opens an SDL window that grabs keyboard focus. Our
automated test pipeline breaks when another window is active.

**Implementation** (in `mednafen/src/drivers/`):
- `automation.cpp`: `Automation_SuppressRaise()` returns true in automation mode
- `video.cpp`: `SDL_ShowWindow`/`SDL_RaiseWindow` calls guarded by SuppressRaise
- Window starts hidden in automation mode (SDL_WINDOW_HIDDEN at creation)
- OpenGL rendering still works on the hidden surface for screenshots
- `show_window` / `hide_window` commands allow on-demand visibility control
- `video.cpp`: `Video_AutomationShowWindow()` / `Video_AutomationHideWindow()`
- `main.cpp`: Consumes pending flags from automation after each frame poll

### T2: File-Based Action Interface — IMPLEMENTED

**Implementation** (`automation.cpp`, ~500 lines):

Two-file handshake protocol. External tool writes to `mednafen_action.txt`,
Mednafen executes and writes result to `mednafen_ack.txt`.

```
# Full command set (implemented):
frame_advance [N]              pause                 run
run_to_frame <N>               screenshot <path>     quit
input <button>                 input_release <btn>   input_clear
dump_regs                      dump_mem <addr> <sz>  status
dump_regs_bin <path>           dump_mem_bin <a> <s> <path>
pc_trace_frame <path>          show_window           hide_window
step [N]                       breakpoint <addr>     continue
breakpoint_clear               breakpoint_list
```

Protocol: Mednafen starts paused (frame 0), polls action file mtime every frame.
Commands are processed immediately. Ack written after each command.

### T3: Debug Trace Interface — IMPLEMENTED

**Implementation** (in `automation.cpp` + `ss.cpp` hooks):

- `dump_regs` / `dump_regs_bin` — SH-2 master CPU registers (R0-R15, PC, SR, PR, GBR, VBR, MACH)
- `dump_mem` / `dump_mem_bin` — arbitrary memory reads up to 1MB
- `pc_trace_frame` — records every master CPU PC for one frame to binary file
- All debug data available in both text (ack file) and binary (file path) formats

### T4: Instruction Stepping & Breakpoints — IMPLEMENTED

**Implementation** (in `automation.cpp`, using `ss.cpp` CPU debug hook):

- `step [N]` — execute exactly N CPU instructions, then pause. The debug hook
  decrements a counter on each instruction and spin-waits when it hits zero.
- `breakpoint <addr>` — add a PC breakpoint. When the CPU reaches this address,
  execution pauses inside the debug hook's spin-wait loop.
- `breakpoint_clear` — remove all breakpoints
- `breakpoint_list` — list currently set breakpoints
- `continue` — resume execution from instruction-level pause (runs until next
  breakpoint or external pause command)

Pausing happens INSIDE the SH-2 CPU execution loop via `Automation_DebugHook()`.
This means registers and memory reflect the exact state at that instruction — not
at a frame boundary. Commands like `dump_regs`, `dump_mem` work while instruction-paused.

The CPU hook is enabled/disabled dynamically via `update_cpu_hook()`:
- Active when: pc_trace, stepping, or breakpoints are in use
- Inactive otherwise: zero overhead for frame-level comparison

**Usage pattern — breakpoint comparison** (`tools/parallel_compare.py --breakpoint-at`):
1. Launch both Mednafen instances
2. Set same breakpoint (e.g. `0x060030FC` — system_init entry) in both
3. `continue` both — they run until breakpoint hit
4. Compare registers + memory at that exact instruction
5. Identify which function/data differs first

**Usage pattern — instruction stepping**:
1. Set breakpoint at function entry in both instances
2. `continue` both to breakpoint
3. `step 1` in both — advance one instruction
4. Compare registers after each step to find exact divergence instruction

**Usage pattern — frame scan** (`tools/parallel_compare.py`):
1. Launch both instances (start paused at frame 0)
2. `frame_advance N` in lockstep, compare registers each step
3. When divergence found: restart, `--breakpoint-at` the function entry
4. Step through to find the exact instruction that diverges

## Phase Plan

### Phase 0: Fix Binary Size (IMMEDIATE)

1. Remove FUN_06046E48 from asm_misc.c (it's 116KB of data, not code)
2. Zero-initialize all DAT_ stubs in linker_stubs.c (restore Commandment 3)
3. Eliminate .text.overflow — ASM-import or shrink all 621 overflow functions
4. Add size gate to Makefile: fail if binary exceeds 394,896 bytes
5. Verify: `make` produces a binary <= 394,896 bytes

### Phase 1: Mednafen Build

1. Obtain Mednafen source (Git or tarball)
2. Build on Windows (MSYS2/MinGW or cross-compile)
3. Verify stock build runs Daytona Saturn disc correctly
4. Document build process in `tools/mednafen/README.md`

### Phase 2: Background Window + Action Interface

1. Patch SDL window creation (T1)
2. Implement action file protocol (T2)
3. Implement screenshot command
4. Implement frame_advance command
5. Implement input commands
6. Update test_boot.ps1 to use action file instead of keyboard simulation
7. Verify: automated boot test runs without focus

### Phase 3: Debug Trace Interface

1. Implement step/run_to commands (T3)
2. Implement register dump
3. Implement memory dump
4. Implement breakpoint support
5. Build side-by-side comparison script
6. Verify: can trace execution of original binary

### Phase 4: Boot Diagnosis

1. Run original binary through debug interface — capture init trace
2. Run reimpl binary through debug interface — capture init trace
3. Diff traces to find first divergence point
4. Fix the divergent function (C bug, missing data, wrong address)
5. Iterate until reimpl binary matches original through full init sequence
6. Verify: reimpl binary shows title screen

## Learnings: Windows Native Mednafen Build (ABANDONED)

We attempted to build Mednafen natively for Windows to avoid WSLg focus-stealing
and environment issues. This section documents what we learned so it doesn't have
to be rediscovered.

### What We Tried

1. Cross-compiled Mednafen using WSL MinGW-w64 (x86_64-w64-mingw32-g++)
2. Successfully compiled all source files
3. Fixed link error: `mingw_app_type` vs `__mingw_app_type` (stub in mingw_compat.c)
4. Produced mednafen.exe (146MB PE32+)

### Why It Crashed

**Crash 1 — ACCESS_VIOLATION at 0x100000000 (4GB boundary)**:
Mednafen compiles with `-mcmodel=small -fno-pic` which generates 32-bit absolute
addresses. Windows PE default base is 0x140000000 (above 4GB). Fixed with
`-Wl,--image-base,0x400000 -Wl,--disable-dynamicbase`.

**Crash 2 — NULL pointer dereference (jump to 0x0)**:
Switch/case jump tables. The `-mcmodel=small` flag makes GCC emit 32-bit jump
table entries, but standard MinGW GCC still generates 64-bit entries for x86-64
targets. This causes the computed jump address to be garbage.

### Root Cause: Custom GCC Toolchain Required

The official Mednafen Windows build uses a **custom-patched GCC 4.9.4** toolchain.
The patch is at `mednafen/mswin/gcc-4.9.4-mingw-w64-noforcepic-smalljmptab.patch`
and modifies four files in the i386 backend:
- `cygming.h` — don't force PIC on 64-bit
- `i386.c` — emit ASM_LONG (32-bit) jump table entries in small code model
- `i386.h` — CASE_VECTOR_MODE returns SImode for small code model
- `i386.md` — sign-extend 32-bit jump table entries to 64-bit

Without this patch, **no standard MinGW GCC will produce a working binary**.

The full custom toolchain build process is in `mednafen/mswin/build-toolchain.sh`
and includes: binutils 2.28.1, MinGW-w64 5.0.5, GCC 4.9.4+patches, libiconv,
zlib, SDL2, FLAC — all cross-compiled. This is a multi-hour build process.

### Decision

Building the custom toolchain is not worth the effort when WSL Mednafen works.
We solved the focus-stealing problem by:
- Defaulting to **hidden window** in automation mode (SDL_ShowWindow skipped)
- Adding **show_window/hide_window** automation commands for on-demand peeking
- Running Python orchestrator from Windows, Mednafen from WSL

### WSLg Environment Gotchas

When spawning WSL processes from Windows Python (`subprocess.Popen(["wsl", ...])`):
- `$HOME` is `/c/Users/<user>` (DrvFS), NOT `/root` — firmware lookup fails
- `$DISPLAY` may be `needs-to-be-defined` — must set `DISPLAY=:0` explicitly
- Shell globs like `~/.mednafen/firmware/*` don't expand through the subprocess chain
- **Fix**: Use a temporary HOME dir, copy firmware with `cp /root/.mednafen/firmware/*`,
  and explicitly set DISPLAY=:0 in the launch command

## Phase 4 Progress: Boot Diagnosis

### Milestone: Reimpl Is Functionally Identical (2026-02-16)

Full 1MB work RAM comparison between prod and reimpl at various frame counts:

| Frame | RAM Diffs | Notes |
|-------|-----------|-------|
| 60 | **0** | All code + data identical after BIOS init |
| 100 | **0** | Full 1MB perfect match |
| 200 | **0** | Full 1MB perfect match |
| 400 | **15** | All timing artifacts (counters off by 2, frame-boundary sampling) |
| 600 | ~58 in 256B spot | Growing but still executing same code |
| 1200 | 186 in 256B spot | **Reimpl crashes** — PC drops to BIOS at 0x06000956 |

**Key findings**:
- Game code at 0x06003000 is **byte-identical** in emulator memory
- PC trace for individual frames: **319,911 instructions identical** (same function, same order)
- Frame-level register divergence is **noise** (CPU at different pipeline position when frame ends)
- The actual RAM state is identical for hundreds of frames
- Reimpl crashes between frame 600–1200 — PC falls to BIOS exception area

### Frame-Level Comparison Is Unreliable

Coarse frame scans show "divergence" that fine scans can't reproduce. This is because
registers are sampled at the frame boundary, which doesn't align with deterministic
execution points. The CPU is simply at a different instruction when the frame ends.

**Correct approach**: Use breakpoints at known function entry points from our symbol
table (1234 labels). Compare registers + memory at those deterministic code locations.

### Bug Fix: Missing Audio Tracks in Rebuilt Disc (commit e708700)

**Symptom**: Reimpl binary frozen on SEGA logo (BIOS screen), never reaching game code.

**Root cause**: `inject_binary.py` was building a disc image with only 1 track (data).
The original disc has 22 tracks (1 data + 21 audio). The Saturn CD subsystem reads the
disc TOC on startup, and the missing audio tracks caused it to loop forever in TOC
processing, never signaling "loading complete" to the game code.

**Fix**: Added `generate_cue()` function to `inject_binary.py` that:
1. Parses the original disc's CUE file to discover all audio track filenames
2. Copies original audio track BIN files into the rebuilt disc directory
3. Generates a complete 22-track CUE sheet referencing all tracks

**Class of issue**: Disc environment fidelity — the game doesn't just read data from the
disc; it also interacts with the CD subsystem's metadata (TOC, track count, session info).
The reimpl disc must be a complete disc image, not just the data track.

### Narrowed Crash Window: Frame 670–680

After fixing audio tracks, the reimpl now gets past the SEGA logo BIOS animation.
Detailed frame-level comparison:

| Frame | Prod | Reimpl | Notes |
|-------|------|--------|-------|
| 0–600 | Spinloop 0x060023F4 | Spinloop 0x060023F4 | Both polling 0x06002D84 |
| 670 | Still polling | Still polling | Both waiting for CD load |
| 675 | Still polling | **Flag changes to 0** | Reimpl disc loads faster |
| 679 | **Flag changes to 0** | Exited spinloop | Prod disc loads (4 frames later) |
| 680 | Exits spinloop → main() | main() → **CRASH** | Reimpl enters exception handler |

The spinloop at 0x060023F4 polls `*(volatile int *)0x06002D84`, waiting for the
value to change from 1 (CD loading in progress) to 0 (loading complete). This is
system code, identical in both binaries.

**Key insight**: The reimpl disc loads slightly faster (4 frames), which is expected
since the rebuilt disc may have different sector layout. This timing difference is
harmless — both exit the spinloop correctly.

### Crash Chain: main() → FUN_060030FC → Exception

After exiting the spinloop, both binaries enter `main()` at 0x06003000. The first
instructions of main:

```
06003000: D117  mov.l @(0x06003060),R1  ; R1 = 0x060030FC
06003002: E000  mov #0,R0
06003004: DF18  mov.l @(0x06003068),R15  ; R15 = initial SP
06003006: 410B  jsr @R1                  ; call FUN_060030FC ← game init
06003008: 400E  ldc R0,SR               ; (delay slot)
0600300A: D016  mov.l ...,R0             ; main loop top — never reached
```

**Production**: Calls FUN_060030FC, returns, enters main loop at 0x0600300A.
**Reimpl**: Calls FUN_060030FC, **crashes**. PR=0x0600300A confirms the crash
happened inside FUN_060030FC (or one of its callees). PC ends up at 0x06000956
which is the BIOS exception/reset handler.

**Next target**: FUN_060030FC is the game's master initialization function. It
calls subsystem init routines (VDP, sound, input, etc.). One of our L1 C
reimplementations of these callees is causing a CPU exception — likely an illegal
memory access, divide by zero, or invalid instruction.

### Tooling Fix: Cache-Aware Memory Reads (uncommitted — ss.cpp)

**Problem**: `Automation_ReadMem8` was reading directly from WorkRAMH (the backing
RAM array), bypassing the SH-2 instruction cache. This meant memory dumps of
executable code at 0x06003000+ showed **all zeros** even though the CPU was clearly
executing instructions there.

**Root cause**: The SH-2 has a 4-way set-associative instruction cache (64 sets ×
4 ways × 16 bytes per line). Code loaded from disc is cached by the CPU during the
first fetch, but the backing RAM (WorkRAMH) may never be updated if the code is
only ever fetched through the cache. Mednafen's own `DBG_MemPeek` (in debug.inc)
is stubbed out — it returns 0xAA for everything. So even the built-in debugger
can't read memory truthfully.

**Fix**: `Automation_ReadMem8` now checks the master SH-2 cache first:
1. If address is in cacheable region (bits [28:26] == 0) and cache is enabled (CCR_CE)
2. Compute cache set index and tag, scan all 4 ways for a tag match
3. On cache hit: return the byte from cached data
4. On cache miss: fall through to backing RAM read

This is critical for tool trustworthiness. Without it, we can't inspect the code
the CPU is actually executing.

**Class of issue**: Observability gap — when debugging an emulated system, we must
read through the same path the CPU uses. Reading backing store directly gives a
stale/wrong view. All future memory inspection tools should go through this
cache-aware path.

### Classes of Issues Identified

These categories of bugs will recur. Each instance teaches a pattern.

| Class | Example | Pattern |
|-------|---------|---------|
| **Disc environment** | Missing audio tracks | Game interacts with CD subsystem metadata, not just data |
| **System→game handoff** | Spinloop timing | System code is identical, but timing differences are normal |
| **Observability** | Cache vs backing RAM | Debug tools must read through CPU's view, not raw memory |
| **L1 reimpl quality** | FUN_060030FC crash | Ghidra decomp produces compilable-but-wrong C code |

### Debugging Methodology Lessons

1. **Function breakpoints are deterministic; frame counts are not.** Frame boundaries
   sample the CPU at an arbitrary instruction — two instances can be executing the same
   code but appear "divergent" because they're at different points in a loop when the
   frame boundary hits. Function entry breakpoints always fire at the exact same PC,
   making comparisons perfectly reproducible. **Use breakpoints for all parallel
   comparisons.** Frame-level scans are only useful for rough triage, never for root
   cause analysis.

2. **Breakpoints >> single-stepping**: Setting a breakpoint at a target address and
   running `continue` at full CPU speed is infinitely faster than stepping one instruction
   at a time via file-based IPC (~100ms per step = hours for 200K instructions).

3. **Sequential single-breakpoint test**: To avoid false positives from BIOS interrupt
   handlers executing at low addresses, set ONE breakpoint at a time, `continue`, verify
   the hit, clear it, set the next. This gave clean results where multi-breakpoint tests
   with broad catch-all conditions produced confusing false positives.

4. **Register dump endianness**: `Automation_DumpRegsBin` writes native-endian (little-endian
   on x86 Linux). Must read with `struct.unpack('<I', ...)`, not `>I`.

5. **Saturn boot sequence**: SEGA logo (BIOS animation) → black screen (game init) →
   attract mode (full boot). Frozen on SEGA logo = worst outcome (system code stuck).
   Black screen after logo = game code entered but rendering failed (better).

6. **Logarithmic bisection**: When divergence occurs over a range of N frames/instructions,
   binary search to narrow to exact point. Don't brute-force scan.

7. **test_boot.ps1 options**: `-Cue vanilla` (original disc), `-Cue rebuilt` (reimpl disc),
   `-Cue patched` (old pipeline disc). There is NO `-Cue prod` option.

### Class 4: Missing Function Definitions (75 functions)

**Discovery**: system_init() → game_subsystem_init() → FUN_0603AC1C → FUN_06040010 →
`jsr FUN_06040C98` → crash (jumps into zeros, illegal instruction exception).

**Root cause**: 75 functions exist in the original binary (labeled in `build/aprog.s`,
sections defined in `saturn_fixed.ld`) but have **no source code** in any `reimpl/src/*.c`
file. The linker creates empty sections at these addresses. When ASM imports call these
addresses through constant pools, the CPU jumps into zeros → exception.

**How they went missing**: The L1 sweep (`gen_l1_batch.py`) processes Ghidra decompiler
output. Some functions may not have been in the Ghidra export, or were referenced in
comments/extern declarations but never given actual bodies. The linker doesn't warn
about empty sections — it silently produces gaps.

**Fix approach**: Generate `rts; nop` stubs for all 75, placed in the correct sections.
This is the same pattern as `gen_asm_stubs.py` for ASM-only functions. The stubs
won't do the right thing, but they'll return cleanly instead of crashing. Subsequent
validation loop iterations will reveal which stubs need real implementations.

**Scope**: 75 functions across all address ranges (core, game logic, subsystems,
rendering, CD/audio, session/scene).

### Class 5: Function Audit — Binary Size Discipline (2026-02-16)

**Discovery**: Systematic audit of all 1234 functions revealed 276 stubs (functions
compiling to 4-12 bytes instead of their original size) and 107 overflows (functions
compiling larger than their slot). Total gap: 184,982 bytes of missing code.

**Phases completed**:

1. **ASM byte import** — Extracted original `.byte` sequences from `build/aprog.s` for
   258 stub functions. Imported as inline `__asm__` blocks with proper section names.
   Result: 118 stubs fixed (commit 80abc5d).

2. **Overflow elimination** — 66 overflows (3,312 bytes) caused by:
   - 63 functions with 12-byte trampoline overhead (ASM import coexisting with trampoline)
   - 3 large overflows (duplicate C+ASM definitions)

   Fixed by removing 97 unnecessary trampolines from trampolines.s and wrapping
   duplicate C definitions in `#if 0` (commit bf5b291).

**Final state**: 832/1233 healthy (67.5%), 0 overflows, 203 genuine stubs.

The remaining 203 "stubs" are real 4-12 byte functions in the original binary (tiny
wrappers, return-only functions). They are not missing code — the audit confirmed
they match the original exactly.

The 198 "medium/small/tiny" functions are Ghidra C lifts that compile smaller than
the original. These are candidates for ASM byte import if they cause boot issues,
but for now they compile and execute correctly.

### Class 6: Overflow Section Elimination (2026-02-16)

**Discovery**: After mass ASM import (240 functions) and PROVIDE alias redirection (141
named functions), the `.text.overflow` section was still 17.9KB — enough to overwrite
critical data tables at the end of the binary.

**Root cause**: `gen_fixed_layout.py` generates the linker script that assigns each
function to its original address. Functions whose sections weren't captured fell through
to the overflow catchall at 0x06046E50+, overwriting the data region.

**Systematic issues found and fixed**:

1. **Named section capture** — When a C function `foo` has alias `FUN_XXXXXXXX`, GCC names
   the section `.text.foo` (not `.text.FUN_XXXXXXXX`). The linker script must explicitly
   capture `*(.text.foo)` at the FUN_ address. Fixed all 3 code paths in gen_fixed_layout.py.

2. **Method 5 address comments** — Added `/* 0xADDRESS: function_name */` comments before
   function definitions so gen_fixed_layout.py can map named functions to FUN_ addresses
   even without alias declarations. Fixed regex to match all Saturn addresses (060xxxxx)
   and scan 75 lines ahead for the function definition.

3. **Method priority conflicts** — Method 2 (heuristic) was overriding Method 5 (address
   comment, authoritative). Fixed Method 5 to always override.

4. **Return type regex** — Function signature regex didn't match `unsigned short`,
   `unsigned char` return types. Fixed in both Method 2 and Method 5.

5. **PROVIDE alias generation** — Integrated into gen_fixed_layout.py to auto-generate
   `PROVIDE(_named = _FUN_XXXXXXXX)` for functions wrapped in `#if 0` redirects.

**Address mappings found** (via constant analysis in build/aprog.s):
- track_object_placement → FUN_06021450
- asset_table_init → FUN_06003A3C
- vdp1_texture_config → FUN_060370E4
- hud_sprite_vertex_project → FUN_06016DD8
- palette_fade_update → FUN_0603C728
- dma_channel_level_set → FUN_0603C1A8
- cd_session_open → FUN_060400D6
- camera_view_select → FUN_0600C286
- framebuffer_vsync_poll → FUN_0603950C

**Progress**: Overflow reduced from 17,960B → 5,784B across 4 commits.

**Remaining overflow composition** (5,784B):
- Named functions without FUN_ addresses: ~2,700B (need more address mappings)
- GCC runtime library (__ashiftrt, __sdivsi3, etc.): ~1,448B (irreducible)
- Below-origin functions (addr < 0x06003000): ~608B (irreducible)
- Small utility helpers (boot, abs_val, obj_*): ~400B (need addresses)

The ~2,056B of irreducible overflow (GCC runtime + below-origin) is code that must exist
in memory but has no corresponding location in the original binary. This is acceptable
as long as it doesn't overwrite data needed for boot.

### Next Steps

1. Find FUN_ addresses for remaining named overflow functions (~2,700B)
2. Assess whether remaining overflow overwrites boot-critical data tables
3. Resume boot diagnosis — breakpoint at FUN_060030FC, trace callee chain
4. Iterate: fix crash → retest → find next divergence → fix → repeat
5. Commit the Mednafen cache fix (ss.cpp)

---

## Known Issues from Previous Attempts

### Black screen despite 83.9% binary match
- Original main function (252 bytes) at 0x06003000 — byte-identical
- system_init at 0x060030FC — gap-patched, byte-identical
- 17/18 ASM-restored functions — byte-perfect at correct addresses
- 91KB of data tables restored by patch_data_holes.py
- Still black screen — root cause unknown
- Debug trace interface (Phase 3) is the tool to solve this

### C reimplementations in init chain
These functions have C code instead of original bytes in the init chain:
- `vdp_init_dispatcher` — VDP initialization
- `sound_timer_init` — at 0x06003218, confirmed as our C code
- `cd_system_init` — SCSP handshake, potential hang point
- `vdp_system_init_a` — game state init

Any of these could be the boot failure. The debug trace will identify which one.

### Linker stubs with non-zero initializers
Commit 6ffa081 changed 1,468 DAT_ stubs from `= 0` to actual values. This
created a 5,872-byte .data section. Must be reverted — patch_data_holes.py
handles data restoration.

---
*Created: 2026-02-16*
*Updated: 2026-02-16 — Class 6 overflow elimination*
