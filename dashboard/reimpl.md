# Reimplementation Dashboard

## Symbol Coverage

| Metric | Value |
|--------|-------|
| Original binary functions | 1234 |
| Reimpl symbol coverage | 1234 (100%) |
| Decomp L1 lift (from Ghidra) | 842 |
| ASM-only stubs (no-op) | 729 |
| Hand-written translations | 96 |
| Disabled functions | 0 (all fixed) |

## Build Status

| Metric | Value |
|--------|-------|
| Compiler | sh-elf-gcc 13.3.0 |
| Binary size | 321KB code (padded to 385KB) |
| Compilation errors | 0 |
| Linker errors | 0 |
| Warnings | ~2255 |
| Linker stubs (external data) | 1526 |

## L2 Progress

| Task | Count | Status |
|------|-------|--------|
| Hardware register defines (saturn.h) | 300+ | DONE |
| Game state defines (game.h) | 80+ | DONE |
| Address replacements in batch files | 638 | DONE |
| Car struct field offsets | 40+ | DONE |
| Function naming (from ASM annotations) | 0 | In progress |

## Quality Levels (see workstreams/reimplementation.md)

| Level | Count | Description |
|-------|-------|-------------|
| L1 (Decomp Lift) | 842 | Raw Ghidra output, compiles |
| L1 (Stub) | 729 | No-op stubs for linker |
| L2 (Named) | 96+ | Has named defines, some structure |
| L3+ | 0 | Not started |

## Headers

| Header | Contents | Defines |
|--------|----------|---------|
| saturn.h | Saturn hardware registers | 300+ |
| game.h | Game state, car struct, globals | 80+ |

### saturn.h coverage:
- VDP1: I/O regs, VRAM, framebuffer (12 registers + constants)
- VDP2: All 70+ control registers, VRAM/CRAM layout
- SCU: DMA L0/L1/L2, timers, interrupts (20+ registers)
- SMPC: I/O, command codes (15 registers)
- SCSP: Sound RAM, mailbox, control (10 registers)
- CD Block: HIRQ, command registers (7 registers + HIRQ bits)
- SH-2: FRT, interrupts, division unit, bus control (18 registers)
- BIOS: Function pointers (4), vector numbers (2)

### game.h coverage:
- Car struct: 40+ field offsets (flags, position, physics, forces, checkpoints)
- Game state: state machine, frame counter, phase flags
- VBlank: counters, phase tracking, frame buffer state
- Input: button bit definitions
- Rendering: state, parameters, VDP1 command buffer
- Sound: timeout flag, mailbox mirror, channel state
- Course/session: CD state, course select

## Boot Test

| Test | Result | Date |
|------|--------|------|
| Compilation | PASS | 2026-02-10 |
| Link | PASS | 2026-02-10 |
| Disc injection | PASS | 2026-02-10 |
| Mednafen boot | Black screen (expected for L1) | 2026-02-10 |

## Source File Inventory

| Category | Files | Functions |
|----------|-------|-----------|
| batch_*.c (L1 lifts) | 31 | 742 |
| asm_*.c (no-op stubs) | 10 | 729 |
| Hand-written (init, math, etc.) | 27 | 96 |
| Stubs/linker | 3 | ~1500 |
| **Total** | **71** | **~3067** |

## Commits This Session

| Hash | Description |
|------|-------------|
| 8acc933 | fix: re-enable 10 disabled functions, add linker stubs and dashboard |
| ce788d5 | feat: comprehensive L2 headers -- Saturn hardware regs + game data structs |
| 6ce9ee5 | refactor: L2 pass -- replace 638 raw addresses with named defines |

## Next Steps

1. L2 function naming pass (apply ASM annotation names to 800+ functions)
2. Translate critical ASM-only functions (VBlank handlers, main loop)
3. Further address replacement (expand define coverage)
4. Boot test improvements (VDP init -> colored screen)

---
*Last updated: 2026-02-10*
