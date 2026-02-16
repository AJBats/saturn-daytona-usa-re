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

### T1: Background Window (no focus steal)

**Problem**: Stock Mednafen opens an SDL window that grabs keyboard focus. Our
automated test pipeline (`test_boot.ps1`) breaks when another window is active.

**Requirements**:
- Window still renders (user can alt-tab to peek)
- Opens behind the active window, not on top
- Does not grab keyboard focus on startup
- Gameplay inputs and screenshots work without window focus

**Implementation approach**:
- Patch SDL window creation: remove `SDL_WINDOW_INPUT_GRABBED`, don't call
  `SDL_RaiseWindow()`
- Win32: call `SetWindowPos(hwnd, HWND_BOTTOM, ...)` after window creation
- All real input comes from the action file (T2), not keyboard

### T2: File-Based Action Interface

**Problem**: We need to control Mednafen programmatically — send inputs, take
screenshots, advance frames — without keyboard focus or interactive terminals.

**Design**: Two-file handshake protocol.

**Action file** (`mednafen_action.txt`): Written by Claude/scripts.
```
# Commands (one per line):
frame_advance <N>           # run N frames, then pause
screenshot <path>           # save framebuffer to file
input <button>              # press button (START, A, B, C, UP, DOWN, LEFT, RIGHT)
input_release <button>      # release button
run_to_frame <N>            # run until frame counter == N, then pause
quit                        # clean shutdown
```

**Acknowledgment file** (`mednafen_ack.txt`): Written by Mednafen after each command.
```
done frame_advance 300      # command completed
done screenshot /path/to/screenshot.png
error <message>             # command failed
```

**Protocol**:
1. Mednafen starts paused, polls action file every frame
2. Claude writes command to action file
3. Mednafen reads command, executes, writes ack
4. Claude reads ack, writes next command
5. Repeat

**Implementation**: ~100 lines in Mednafen's main loop. Check file mtime each
frame. Parse simple text commands. Write ack after execution.

### T3: Debug Trace Interface

**Problem**: When the reimpl binary shows a black screen, we need to find exactly
where execution diverges from the original. Currently we guess by reading
disassembly — this is slow and unreliable.

**Design**: Extension of the action file protocol with debug commands.

```
# Debug commands:
step <N>                    # execute N instructions, write trace
run_to <addr>               # run until PC == addr, then pause
breakpoint <addr>           # add breakpoint (pause when PC hits addr)
dump_regs                   # write all SH-2 registers to ack file
dump_mem <addr> <size>      # write memory contents to ack file
dump_pc_trace <N>           # record last N PC values
```

**Ack format for debug commands**:
```
regs PC=060030FC SR=000000F0 PR=06003058 R0=00000000 R1=06003000 ...
mem 06078900 00000000 00000000 00000000 00000001 ...
pc_trace 060030FC 060030FE 06003100 06003102 ...
```

**Usage pattern — side-by-side comparison**:
1. Launch Mednafen instance A with original APROG.BIN
2. Launch Mednafen instance B with reimpl APROG.BIN
3. Set breakpoint at function entry (e.g., 0x0603BF7C = course_system_init)
4. Both instances run to breakpoint
5. Dump registers from both — compare
6. Step both N instructions — compare
7. Find exact divergence point

**Implementation**: Hooks in the SH-2 CPU execution loop. Breakpoint is a simple
address check before each instruction. Register dump is trivial (read CPU struct).
Memory dump is a memcpy. PC trace is a circular buffer.

Estimated effort: ~200-300 lines of C++ in Mednafen's Saturn SH-2 core.

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
