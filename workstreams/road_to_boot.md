# Road to Boot

> **Status**: Active — primary workstream
> **Depends on**: reimplementation.md (L1 pass complete, 1234 functions defined)
> **Fallthrough**: L2 elevation work (reimplementation.md Pass 2) when boot goals are met

## Goal

Boot the reimplemented Daytona USA Saturn binary to the title screen in Mednafen.
Every step must be observable, reproducible, and automated.

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
