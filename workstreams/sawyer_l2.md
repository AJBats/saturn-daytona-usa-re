# Sawyer L2 — Relocatable Assembly Source

> **Status**: Active — primary workstream
> **Created**: 2026-02-17
> **Predecessor**: DONE_function_audit.md, ICEBOX_gameplay_extraction.md (Sawyer annotations)
> **Paused**: road_to_boot.md, reimplementation.md (resume after Sawyer L2 base is established)

## The Problem

The reimpl is 92% original binary bytes reimported. The fixed-address layout forces
every function into a size-constrained slot — if the C output is even 1 byte larger
than the original, it overflows into its neighbor. This created an endless cycle:

    C too large → overflow → ASM import → hardcoded addresses → fixed layout → C too large

We spent weeks on linker scripts, overflow sections, trampolines, and address mappings.
The fundamental architecture was wrong.

## The Insight

Sega AM2 shipped Daytona with a mix of C and hand-written assembly. They never had
the slot-size problem because their assembly was **source** — `.s` files with symbolic
labels, assembled into relocatable `.o` files, linked by the linker. The linker resolved
all addresses. No function knew its own address. No function knew anyone else's address.

Our "ASM imports" are fundamentally different — they're raw bytes extracted from the
**final linked binary**, with all addresses baked in. They can't be moved. They force
fixed layout. They're the root cause of the slot-size problem.

## The Approach

Produce real assembly source — the kind that existed before the linker ran. Start from
`build/aprog.s` (the full disassembly) and the 46 Sawyer annotation files (which document
what every function does), and convert hardcoded addresses to symbolic references.

### What "Relocatable" Means

Original disassembly (post-link, hardcoded):
```asm
FUN_0600E71A:
    mov.l   @(0x84,PC),r3        ! r3 = 0x06008318
    jsr     @r3
    ...
    .long   0x06008318            ! ← hardcoded address
```

Sawyer L2 source (pre-link, symbolic):
```asm
    .global _FUN_0600E71A
_FUN_0600E71A:
    mov.l   .L_E71A_pool_0,r3    ! r3 = &FUN_06008318 (input handler)
    jsr     @r3
    ...
    .align 2
.L_E71A_pool_0:
    .long   _FUN_06008318         ! ← symbolic reference, linker resolves
```

The assembler (`sh-elf-as`) encodes the `mov.l` displacement (distance from instruction
to pool entry) and emits a relocation record saying "fill in the address of
`_FUN_06008318` here." The linker resolves it at link time.

### Why This Kills the Slot Problem

When every reference is symbolic, the linker places functions wherever they fit.
If function A grows by 20 bytes, functions B, C, D shift — and their references
update automatically. No overflow, no trampolines, no corruption.

The only hard constraint is **total binary size** (must fit in work RAM), not
individual function sizes.

## Pipeline

```
build/aprog.s                    46 Sawyer annotation files
(206K lines, 1234 functions)     (asm/*.s — rich comments, struct docs)
         │                                │
         └──────────┬─────────────────────┘
                    │
         ┌──────────▼──────────┐
         │  symbolize_asm.py   │  Convert hardcoded addresses to labels
         │                     │  using symbol table + Sawyer knowledge
         └──────────┬──────────┘
                    │
         ┌──────────▼──────────┐
         │  sawyer_l2/src/*.s  │  Relocatable assembly source
         │  (one .s per func)  │  with symbolic references
         └──────────┬──────────┘
                    │
         ┌──────────▼──────────┐
         │   sh-elf-as → .o    │  Assemble to relocatable objects
         └──────────┬──────────┘
                    │
         ┌──────────▼──────────┐
         │   sh-elf-ld → BIN   │  Link all objects → APROG.BIN
         └──────────┬──────────┘
                    │
         ┌──────────▼──────────┐
         │    diff vs original │  Byte-for-byte comparison
         └─────────────────────┘
```

### Verification

The assembled + linked output should be **byte-identical** to the original APROG.BIN.
Same instructions, same constant pool values, same function order. If it's not identical,
the symbolization has a bug — fix it until it matches.

This gives us a **known-good baseline**: the binary is perfect because it's the same code,
just represented differently (source vs frozen bytes).

### Then: Introduce C

Once the ASM base links and matches, replace functions with C one at a time:

1. Pick a function (start with the 93 hand-written L2+ files we already have)
2. Remove its `.s` file, add the `.c` file to the build
3. Rebuild and link
4. Boot test
5. If it works → commit. If not → the C has a bug, fix it or revert.

Because everything is relocatable, a C function that's 20% larger than the original
**just works** — the linker shifts everything else. No overflow. No trampolines.

## Resources

### Symbol Table

- `build/aprog_syms.txt` — 1,234 function addresses (FUN_ labels)
- `reimpl/src/linker_stubs.c` — ~1,482 data symbols (DAT_, PTR_DAT_)
- Hardware registers (0x25XXXXXX) — not relocatable, stay as literal constants

### Sawyer Annotations (46 files in asm/)

These document what each function does, struct layouts, call chains, and data addresses.
They contain the knowledge needed to classify each constant pool entry:

- Function pointer → `.long _FUN_XXXXXXXX` (symbolic)
- Data address → `.long _DAT_XXXXXXXX` (symbolic)
- Hardware register → `.long 0x25XXXXXX` (literal, keep as-is)
- Numeric constant → `.long 0x00000FFF` (literal, keep as-is)

### Existing C Source (keep for Phase 2)

- 93 hand-written L2+ files (257 functions) — real reverse engineering work
- 624 disabled Ghidra L1 lifts — starting points for future C conversion
- These stay in the repo, ready to swap in once the ASM base is stable

## Constant Pool Classification

The core challenge. Every `.long` in a constant pool must be classified:

| Address Range | Type | Action |
|---------------|------|--------|
| 0x06003000–0x06063C10 | Code/data in binary | Check symbol table, symbolize |
| 0x06064000–0x060FFFFF | Runtime data region | Symbolize as data label |
| 0x00200000–0x002FFFFF | Low work RAM | Symbolize as data label |
| 0x25XXXXXX | Hardware MMIO | Keep as literal |
| 0x20XXXXXX | SMPC registers | Keep as literal |
| 0xFFFFFEXX | On-chip registers | Keep as literal |
| Other | Numeric constants | Keep as literal |

Values in the 0x0600XXXX range that match a known FUN_ or DAT_ symbol get replaced.
Values that don't match any symbol are likely mid-function addresses or computed offsets —
these need investigation (potentially new labels).

## Open Questions

1. **Link order**: The linker places functions in the order they appear. We need to match
   the original order (by address) to get byte-identical output. This means the linker
   script or the link command must list objects in address order.

2. **Data regions**: The binary has interleaved code and data. Data regions between
   functions must also be represented in the source (as `.byte`/`.long` directives)
   or handled by the gap patcher.

3. **Constant pool placement**: The assembler decides where to place literal pools.
   The original compiler may have placed them differently (inline vs end-of-function).
   We may need `.ltorg` directives to match original pool positions.

4. **Branch targets within functions**: Internal labels (loop heads, if/else branches)
   are PC-relative and don't need symbolization — the assembler handles them. But we
   need to verify the disassembler generated correct local labels.

5. **Total binary size budget**: Need a work RAM audit to determine actual wiggle room
   beyond the original 394,896 bytes.

## Milestones

### M1: Proof of Concept (1 function)

Take one well-understood function (e.g., FUN_0600E71A — player physics orchestrator,
fully annotated in Sawyer), convert to relocatable source, assemble, link, verify
bytes match the original.

### M2: Symbolization Tool

Build `symbolize_asm.py` that processes `build/aprog.s`:
- Splits into per-function `.s` files
- Replaces constant pool addresses with symbol references
- Adds `.global` directives for function entry points
- Generates a linker script that orders functions by address

### M3: Full Binary Build

All 1,234 functions as relocatable `.s` source. Assemble, link, diff against original.
Goal: byte-identical output.

### M4: First C Swap

Replace one ASM function with its C equivalent. Rebuild, boot test. Prove the
incremental replacement workflow works.

### M5: Mass C Introduction

Systematically swap in the 93 hand-written C files. Each swap: rebuild, test,
commit. Track which C functions boot-test clean.

---
*Created: 2026-02-17*
