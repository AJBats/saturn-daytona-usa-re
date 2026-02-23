# Boot Testing Dashboard

## Summary

| Status | Count | Description |
|--------|-------|-------------|
| BOOT | 35 | Reaches title screen |
| CRASH | 18 | Black screen |
| CORRUPT | 6 | Visual issues |
| **Total Tested** | **59** | |

## Baseline

- **L2 build**: 23 functions patched (8 L3 byte-perfect + 15 L2 structural)
- **Boot status**: OK (title screen with "PRESS START BUTTON")

## Verified BOOT (35)

| Function | Insns | Type | Match% | Notes |
|----------|-------|------|--------|-------|
| FUN_0601164A | 7 | LEAF | 0% | |
| FUN_06018EC8 | 7 | LEAF | 14% | |
| FUN_0601AE2C | 20 | LEAF | 10% | |
| FUN_0601AEB6 | 7 | LEAF | 0% | |
| FUN_0601F87A | 18 | LEAF | 11% | |
| FUN_060192E8 | 16 | LEAF | 12% | |
| FUN_060285E0 | 8 | LEAF | 62% | |
| FUN_06028600 | 8 | LEAF | 62% | |
| FUN_0602761E | 9 | LEAF | 44% | |
| FUN_0602ECCC | 4 | LEAF | 0% | |
| FUN_0602ECF2 | 6 | LEAF | 0% | |
| FUN_060322E8 | 10 | LEAF | 40% | |
| FUN_0603316C | 2 | LEAF | 0% | |
| FUN_060336C8 | 2 | LEAF | 0% | |
| FUN_060336F2 | 2 | LEAF | 0% | |
| FUN_060337FC | 5 | LEAF | 40% | |
| FUN_06034560 | 14 | LEAF | 7% | |
| FUN_06035438 | 6 | LEAF | 0% | |
| FUN_06035C2C | 7 | LEAF | 0% | |
| FUN_06035C6E | 3 | LEAF | 0% | |
| FUN_06035C92 | 5 | LEAF | 0% | |
| FUN_0603C05C | 15 | LEAF | 33% | |
| FUN_0603C08C | 10 | LEAF | 0% | |
| FUN_0603EF54 | 7 | LEAF | 14% | |
| FUN_0603F1E0 | 7 | LEAF | 14% | |
| FUN_0603F1F0 | 8 | LEAF | 12% | |
| FUN_0603F216 | 10 | LEAF | 10% | |
| FUN_0603F8B8 | 11 | LEAF | 9% | |
| FUN_0603F8EE | 4 | LEAF | 0% | |
| FUN_0603F900 | 4 | LEAF | 0% | |
| FUN_0603F90E | 4 | LEAF | 0% | |
| FUN_0603F91C | 4 | LEAF | 0% | |
| FUN_0603FA00 | 5 | LEAF | 0% | |
| FUN_060409DE | 4 | LEAF | 50% | |
| FUN_06041014 | 11 | LEAF | 9% | |

## CRASH (18)

| Function | Insns | Match% | Notes |
|----------|-------|--------|-------|
| FUN_06012E62 | 4 | 100% | Const pool overflow into next func |
| FUN_0602760C | 9 | 44% | |
| FUN_06027630 | 9 | 44% | |
| FUN_06028560 | 9 | 100% | Crash not code-related |
| FUN_0602D88E | 2 | 0% | Ghidra boundary error |
| FUN_06035C08 | 7 | 62% | ABI mismatch |
| FUN_06038520 | 8 | 56% | extu.w removal, bf.s vs bf |
| FUN_06038A48 | 12 | 8% | |
| FUN_060394C2 | 7 | 0% | |
| FUN_0603BF5A | 12 | 0% | |
| FUN_0603EF34 | 11 | 0% | |
| FUN_0603F92C | 8 | 100% | Crash not code-related |
| FUN_0603F9DA | 8 | 0% | |
| FUN_0603FFE6 | 16 | 0% | |
| FUN_060400B4 | 10 | 0% | |
| FUN_06042BAC | 7 | 78% | Immediate OR optimization |
| FUN_06042BBE | 8 | 0% | |
| FUN_06042BEE | 6 | 86% | Immediate AND optimization |

## CORRUPT (6)

| Function | Insns | Match% | Notes |
|----------|-------|--------|-------|
| FUN_06033520 | 16 | 44% | `in_r2` implicit register param |
| FUN_06034708 | 11 | 0% | Ghidra boundary error |
| FUN_06034FE0 | 7 | 0% | `in_r0`/`in_r1` implicit params |
| FUN_06035C1C | 8 | 12% | strlen - rts delay slot diff |
| FUN_0603C0A0 | 9 | 11% | Constant loading strategy diff |
| FUN_0603F202 | 8 | 0% | Better optimization |

## Reimpl Boot Progress

| Date | Build | Screenshot | Notes |
|------|-------|------------|-------|
| 2026-02-10 | L1 pass complete (no-op stubs) | Black screen | Expected: 729 ASM stubs are no-ops |
| 2026-02-12 | ASM import (630/729 real bytes) | **SEGA logo** | Past black screen — but may be hung at SEGA logo |
| 2026-02-12 | ASM import (675/729 real bytes) | Saturn BIOS menu | Disc builder corrupt — overflowed into COURSE0 |
| 2026-02-12 | -Os build + disc fix | Black screen (SEGA logo appears & disappears) | Disc builder fixed. SEGA logo boot normal. Game reaches init then hangs. |
| 2026-02-16 | Sawyer L2 +0 (fixed layout) | Black screen → init | Functionally identical RAM at frame 60-200. Crash at ~frame 1200 |
| 2026-02-17 | Sawyer L2 +0 (SCDQ bypass) | **Title screen** | Full title: logo, "PRESS START BUTTON", (C) SEGA. Stalls before attract mode |
| 2026-02-17 | Sawyer L2 +4 (free layout) | **Title screen** | Identical to +0. Proves all pool symbolization correct. SCDQ bypass required |
| 2026-02-18 | ICF NOP bypass | **Full attract loop** | 3D demo → high scores → loops. Complete attract cycle runs stable for 90s+ |

### 2026-02-12: Size Optimization & Disc Fix
- Switched Makefile from -O2 → -Os (batch_cd_system_34.c uses -O2 fallback for ICE)
- Binary: 564KB → 530KB (-35KB). Still 135KB over original (395KB).
- GCC 13 is actually 12.5% MORE efficient than GCC 2.6.3 on same source
- **Root cause of bloat**: Ghidra decompiled C is 2.3x more verbose than original source
- **Fix**: L2 elevation of all batch_*.c files will shrink code toward original size
- Disc builder (inject_binary.py) now shifts all files when APROG overflows,
  patches ISO 9660 directory LBAs + PVD volume size + sector MSF headers

### 2026-02-12: ASM Import Progress
- Imported 675 ASM-only functions as raw binary bytes via `__asm__()` blocks
- Binary: 552KB (675 blocks) → now 564KB (675 blocks, named stubs resolved)
- 3 stubs remain: FUN_060302C6 (no aprog.s entry), 2 already implemented elsewhere
- HWRAM expanded from 512KB to 896KB to fit larger binary

### 2026-02-16: Sawyer L2 Relocatable Assembly
- Full reimpl rebuilt as relocatable assembly (sawyer.ld) with proper pool symbolization
- 5,062 constant pool entries symbolized (`.4byte SYMBOL` instead of `.byte` blobs)
- 1,807 sym_/loc_ labels for internal branch targets
- 371 fall-through chains merged into contiguous sections
- Binary: 394,892 bytes (~395KB, within original size budget)
- +0 build: byte-identical RAM contents at frame 60-200 vs production

### 2026-02-17: SCDQ Bypass & Title Screen
- FUN_060423CC: unbounded SCDQ poll hangs with non-zero shifts (emulator timing)
- C replacement with 50M iteration timeout — boots +4 free-layout build
- **Title screen reached**: Both +0 and +4 builds render full Daytona title
- Production comparison: prod → 3D attract mode; reimpl → stalls at title (L1 limitation)
- "Illegal Instruction! PC=00000002" is non-fatal (secondary SH-2, game continues)
- Stall point: loop at 0x0600C11E — L1 stubs can't advance game state machine

### 2026-02-18: ICF NOP Bypass & Attract Mode
- Root cause: FUN_0600C010 polls FTCSR bit 7 (ICF = Input Capture Flag) in unbounded loop
- ICF is set by FRT FTCI pin edge (connected to VDP VBLANK); FRT init stubs don't configure timer
- Demo timer at 0x0607EBCC decremented once (920→919) then state 3 handler hung in FUN_0600BFFC
- **Fix**: NOP'd backward branch in FUN_0600C010.s polling loop (2 bytes: `bf -7` → `nop`)
- Binary size: 394,888 bytes (8 bytes under original, within budget)
- **Attract mode reached**: Full 3D demo playback — highway, mountains, billboard, cars
- Scene matches production build closely (same geometry, textures, UI)
- Timing differs (no vblank sync = free-running frame rate)

## Current Reimpl Boot Status

| Metric | Value |
|--------|-------|
| Build | Sawyer L2, +4 free layout |
| Binary size | 394,888 bytes (budget: 394,896) |
| Boot result | **Full attract loop** |
| Furthest point | Complete attract cycle: title → 3D demo → high scores → loops |
| Hardware bypasses | SCDQ (FUN_060423CC.c), ICF poll (FUN_0600C010.s NOP) |
| Non-fatal issues | "Illegal Instruction! PC=00000002" (secondary SH-2) |

---
*Last updated: 2026-02-18*
