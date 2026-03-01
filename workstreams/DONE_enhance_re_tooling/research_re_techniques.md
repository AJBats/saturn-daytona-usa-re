# RE Techniques Research

Compiled from web research on game decompilation projects and RE communities (2026-03-01).

## Key Lesson: Data First, Not Code First

Every successful game RE project follows the same pattern: start with data you can
observe, trace back to the code that produces it. NOT: start with code, guess what it does.

## Technique 1: Known-Value Memory Scanning (Cheat Engine style)

The core loop:
1. Observe a gameplay value on screen (speed = 180, gear = 4, lap = 2)
2. Scan memory for that value (try 8/16/32-bit, signed/unsigned, fixed-point)
3. Change the value in-game (shift to 3rd gear)
4. Rescan — eliminate addresses that didn't change
5. Found address = the variable. Watchpoint it.
6. The function that writes it IS the function's identity. No guessing.

Works for: speed, gear, lap, position, timer, health, score, menu selection index.

Our advantage: we can dump entire WRAM and search programmatically. Humans use Cheat
Engine one value at a time. We can scan for dozens of values in parallel.

Source: https://github.com/kovidomi/game-reversing

## Technique 2: Struct Discovery via Offset Chains

Once you find one field (e.g. speed at 0x06078920), the surrounding memory is likely
a struct. Dump 256 bytes around it, correlate other fields with gameplay:
- Offset +0x00 might be X position
- Offset +0x04 might be Y position
- Offset +0x08 might be Z position
- Offset +0x0C might be heading angle
- etc.

Name fields by their offsets until proven: `car_struct+0x10`, `car_struct+0x38`.
The struct pointer itself reveals the object system — who allocates it, who iterates it.

Our advantage: we can dump the same struct region across multiple frames and correlate
changes with inputs. Steer left → which offsets change? Accelerate → which offsets change?

## Technique 3: Full-Memory Differential

Instead of searching for one value, capture everything:
1. Save state at frame N
2. Advance 1 frame (or perform an action)
3. Dump entire WRAM
4. Load state, advance 1 frame with different input
5. Diff the two dumps

Every byte that differs is responding to the input. Group by address range to identify
which subsystems are involved.

Our advantage: deterministic replay + save states make this perfectly reproducible.

## Technique 4: Hardware Register Function Tagging

Functions reveal their subsystem by which hardware they touch:
- Writes to VDP1 command table (0x25C00000) = sprite/polygon rendering
- Writes to VDP2 registers (0x25F80000) = background/scroll layer config
- Reads SMPC peripheral data (0x20100001) = input polling
- Writes SCSP registers (0x25B00000) = sound/music
- Configures SCU DMA (0x25FE0000) = bulk memory transfer

Can be done statically by grepping disassembly for these address ranges.

Source: https://www.retroreversing.com/Sega-Saturn-Reversing-Emulator

## Technique 5: SDK Function Signature Matching

Compile known SDK libraries (SGL, SBL), extract byte patterns from .o files,
scan the game binary for matches. Even partial matches identify library code
vs game-specific code.

Daytona '95 caveat: AM2 first-party title, may predate finalized SGL. Likely
uses SBL for low-level (CD, input) but custom code for rendering/physics.

Source: https://www.retroreversing.com/sega-saturn-sdk/

## Technique 6: String Anchoring

Scan binary for ASCII strings. "ARCADE", "TIME ATTACK", course names, error
messages — each string is referenced by specific code, anchoring that code to
a known game screen or feature.

## Technique 7: Matching Decompilation

Write C that compiles to byte-identical assembly. The C itself reveals intent
because you have to understand the algorithm to reproduce it. Community platform:
decomp.me provides collaborative scratch pads for this.

We already do this (our free build is byte-identical). The next step is converting
FUN_ functions to C once we know what they do.

Source: https://decomp.wiki/

## What OoT/SM64 Projects Had

- OoT: debug symbols leaked on GameCube Master Quest disc. Lucky break.
- SM64: massive community effort, years of matching decompilation.
- Both: hundreds of contributors, each person tackling small pieces.

We don't have debug symbols or a community. But we have an AI that can run
experiments 24/7 and a programmatic emulator interface. Different strengths.

Source: https://github.com/zeldaret/oot

## Our Tooling Gap Summary

| Technique | Do we have it? | Priority |
|-----------|---------------|----------|
| Known-value scanning | No (need memory scanner) | HIGH |
| Save states | No (need automation commands) | HIGH |
| Full-memory differential | Partial (have dump_mem_bin, need convenience) | HIGH |
| HW register tagging | No (need grep tool) | MEDIUM |
| SDK signature matching | No (need to compile SGL, build scanner) | LOW |
| String detection | No (simple to build) | MEDIUM |
| Matching decompilation | Yes (free build infra) | -- |
