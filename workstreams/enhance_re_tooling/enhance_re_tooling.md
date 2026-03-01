# Enhanced RE Tooling

**Status**: Active
**Goal**: Build automated discovery tools that attach gameplay intent to code — data-driven, not guess-driven.

## Context

The VERIFIED review (empirical_validation) proved that naming functions from call patterns
doesn't work. We need techniques that start from observable data and trace back to code.

## Strategy

Three complementary approaches:

### A. Hardware Register Tagging (automated, static)
Grep disassembly for known HW register addresses. Functions that write VDP1 = rendering,
SMPC reads = input, SCSP writes = audio. No emulator needed.

- VDP1: 0x25D00000 range
- VDP2: 0x25F80000 range (also 0x25E00000 VRAM, 0x25F00000 color RAM)
- SCSP: 0x25B00000 range (sound)
- SMPC: 0x20100000 range (input/peripherals)
- SCU: 0x25FE0000 range (DMA, interrupts)

### B. Known-Value Memory Hunting (dynamic, Cheat Engine style)
Find gameplay values visible on screen (gear, speed, lap, position, timer) by scanning
Saturn WRAM. Watchpoint the found addresses to discover which functions write them.

Visible values during racing:
- Speed (displayed as MPH/KPH)
- Gear (1-4 + reverse)
- Lap count (1/2/3)
- Position (1st-8th)
- Timer (mm:ss:ms)
- Steering angle (visible from car rotation)

### C. Full-Memory Differential (dynamic, en masse)
Dump entire WRAM before/after gameplay events. Diff reveals which memory subsystems
respond to each event:
- Wall collision: find collision response system
- Gear shift: find transmission system
- Checkpoint crossing: find lap/timing system
- Steering input: find physics/handling system

## Infrastructure Needed

### Save States (high priority)
Add `save_state <path>` and `load_state <path>` to automation.cpp. Eliminates 4700-frame
replay to reach racing. Mednafen already has save state internals.

### Full WRAM Dump Helper
Convenience wrapper: dump 0x06000000-0x060FFFFF (1MB high WRAM) in one call.
Could also dump low WRAM (0x00200000, 1MB) and VDP1/VDP2 VRAM.

### Memory Scanner
Python tool: scan WRAM dump for a known value (e.g. search for 0x04 when in 4th gear).
Support different data widths (8/16/32-bit), endianness, and delta scans (value increased/
decreased between frames).

### SDK Signature Matching (exploratory)
Daytona '95 may predate standard SGL, or use prototype versions. Worth checking:
- Compile SGL/SBL from source, extract .o byte patterns
- Scan our binary for matches
- Even partial matches reveal library boundaries

### String Detection
Scan binary and WRAM for ASCII strings. Menu text, error messages, debug strings all
anchor code to specific game screens.

## Community References

Tools we're studying for reference (credit these in CREDITS.md):

| Project | What we're learning from | URL |
|---------|------------------------|-----|
| libRetroReversing | Function auto-tagging, SDK signatures, string detection | https://github.com/RetroReversing/libRetroReversing |
| beetle-saturn-libretro | Saturn RE emulator architecture | https://github.com/RetroReversing/beetle-saturn-libretro |
| Saturn-SDK-SGL | SGL source for generating byte signatures | https://github.com/SaturnSDK/Saturn-SDK-SGL |
| libyaul | Modern Saturn dev kit, HW register maps | https://github.com/yaul-org/libyaul |
| RetroReversing.com | Saturn RE guides and methodology | https://www.retroreversing.com/saturn/ |
| game-reversing | Cheat Engine / memory scanning tutorials | https://github.com/kovidomi/game-reversing |
| decomp.wiki | Matching decompilation community knowledge | https://decomp.wiki/ |

## Principles

- **Data first**: never name a function without observing what data it modifies
- **Claude-native**: build tools that Claude can use programmatically, not human-readable logs
- **Emulator is oracle**: the running game is ground truth, everything else is inference
