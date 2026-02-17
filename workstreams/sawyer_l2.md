# Sawyer L2 — Relocatable Assembly Source

> **Status**: Active — primary workstream
> **Created**: 2026-02-17
> **Predecessor**: DONE_function_audit.md, ICEBOX_gameplay_extraction.md (Sawyer annotations)
> **Paused**: road_to_boot.md, reimplementation.md (resume after bootable ASM base)

## The Problem

The reimpl is 92% original binary bytes reimported as frozen `.byte` blobs. The
fixed-address layout forces every function into a size-constrained slot — if C output
is even 1 byte larger, it overflows into its neighbor. This created an endless cycle:

    C too large → overflow → ASM import → hardcoded addresses → fixed layout → C too large

The root cause: our "ASM imports" are post-link bytes with baked-in addresses. They
can't be moved. They force fixed layout.

## The Insight

Sega AM2 shipped Daytona with a mix of C and hand-written assembly. They never had
the slot problem because their ASM was **source** — `.s` files with symbolic labels,
assembled into relocatable `.o` files, linked by the linker. No function knew its own
address or anyone else's. The linker decided everything.

We need to reconstruct that pre-link source from the post-link binary.

## Quality Levels

| Level | Instructions | Pool entries | Relocatable | Validation |
|-------|-------------|-------------|-------------|------------|
| **L1** (current reimpl) | `.byte` blobs in C | hardcoded bytes | No | N/A |
| **L2** (byte-perfect) | `.byte` blobs in `.s` | `.4byte _SYMBOL` | **Yes** | `cmp` vs original |
| **L3** (real source) | SH-2 mnemonics | `.4byte _SYMBOL` | Yes | boot test |
| **L4** (C reimpl) | C source | N/A (compiler pools) | Yes | boot test |

**L2 is the minimum work that breaks the cage.** Instructions stay as opaque bytes,
only the constant pool entries are symbolized. Because instruction bytes are identical,
we can verify the conversion with `cmp`. This is automatable.

**L3 is understanding.** Converting `.byte` pairs to real mnemonics. Done incrementally
using the 46 Sawyer annotation files as reference. Validated by boot test.

**L4 is the endgame.** Replacing ASM functions with C. No slot constraints because
the linker handles placement. The 93 hand-written C files and 624 Ghidra lifts are
the starting material.

## POC Results (2026-02-17)

Three experiments validated the approach:

1. **Symbolic pool → byte-identical**: Replaced `.byte` pool entries with `.4byte _SYMBOL`,
   linked at original addresses. Output: **174 bytes, byte-identical to original.** ✓

2. **Symbolic pool → relocation works**: Same `.o` file linked at different addresses.
   Instructions identical, pool values updated to new addresses. **Relocation confirmed.** ✓

3. **Real mnemonics assemble correctly**: Full function rewritten as SH-2 mnemonics.
   Assembles and links. 4 byte differences traced to transcription errors in mov.w
   label targets, not toolchain issues. **Mechanism proven.** ✓

## Plan

### Phase 1: Build Pipeline Setup

**Goal**: Fresh build system in `reimpl/` that assembles `.s` files and links them.

1. Archive old C source: `reimpl/src/` → `reimpl/src_c_archive/`
2. Create `reimpl/src/` for new `.s` source files
3. Write new Makefile:
   - Discovers `src/*.s` files
   - Assembles each with `sh-elf-as -big` → `.o`
   - Links all `.o` files with `sh-elf-ld -EB` → `APROG.BIN`
   - Runs `cmp` against original as validation gate
4. Linker script: sequential placement starting at 0x06003000, functions in address order
5. Verify: empty build compiles and links (even if the binary is wrong)

### Phase 2: Sawyer L2 — Automated Symbolization

**Goal**: All 1,234 functions as `.s` files with symbolic pool entries. Byte-identical output.

1. Build `tools/symbolize_pools.py`:
   - Input: `build/aprog.s` (full disassembly)
   - Input: symbol table (1,234 FUN_ + ~1,482 DAT_ addresses)
   - For each function:
     a. Extract the `.byte` block
     b. Identify the constant pool region (4-byte-aligned entries after the last instruction)
     c. For each 4-byte value: check against symbol table
     d. Match → `.4byte _FUN_XXXX` or `.4byte _DAT_XXXX`
     e. No match → keep as `.byte` (numeric constant or unknown)
   - Output: one `.s` file per function in `reimpl/src/`
   - Output: linker script with function ordering + symbol PROVIDE declarations

2. Handle data gaps between functions:
   - The original binary has data interleaved with code
   - `patch_data_holes.py` already handles this — fill gaps post-link
   - OR: emit gap data as `.byte` blocks in the `.s` files

3. Handle FUN_06046E48 (the 116KB data tail):
   - Not a function — it's parameter tables, strings, lookup tables
   - Emit as a data `.s` file or let gap patcher handle it

4. Validation loop:
   - `make` → assemble + link → `cmp build/APROG.BIN build/original_aprog.bin`
   - Fix mismatches: wrong symbol classification, missed pool entries, alignment issues
   - Iterate until byte-identical

5. **Gate**: `cmp` passes. The relocatable source produces the exact original binary.

### Phase 3: Free Layout + Boot Test

**Goal**: Prove the binary works without fixed addresses.

1. Switch linker script from address-ordered to simple sequential:
   ```
   . = 0x06003000;
   .text : { *(.text) }
   ```
   Functions placed in link order. Addresses will differ from original.

2. Build disc image with the new binary

3. Boot test in Mednafen:
   - If it boots → relocatable build works, addresses don't matter
   - If it crashes → some reference wasn't symbolized (hardcoded address in a pool
     entry that we left as `.byte`). The crash location tells us which function, and
     we fix the missed symbol.

4. **Gate**: game boots to at least the same point as the previous reimpl (black screen
   or better).

### Phase 4: Sawyer L3 — Real ASM Source (Incremental)

**Goal**: Convert opaque `.byte` instructions to readable SH-2 mnemonics.

1. Priority order:
   - Functions with Sawyer annotations (46 files covering gameplay subsystems)
   - Boot-critical init chain (FUN_060030FC and callees)
   - Large functions (more value per conversion)

2. Per-function workflow:
   - Read Sawyer annotation for understanding
   - Replace `.byte` pairs with mnemonics
   - Boot test (not byte-compare — mnemonics may produce different pool layouts)
   - Commit

3. This is ongoing work. No gate — L3 conversion happens continuously alongside
   other work. A function at L2 (`.byte` + symbolic pools) is already relocatable
   and correct. L3 adds readability, not correctness.

### Phase 5: C Introduction (The Payoff)

**Goal**: Replace ASM functions with C, one at a time. No slot constraints.

1. Start with the 93 hand-written L2+ C files (257 functions)
   - These are already understood and documented
   - Move from `reimpl/src_c_archive/` back into `reimpl/src/`
   - Remove the corresponding `.s` file

2. Makefile builds `.s` and `.c` together:
   - `.s` files → `sh-elf-as` → `.o`
   - `.c` files → `sh-elf-gcc` → `.o`
   - All `.o` → `sh-elf-ld` → `APROG.BIN`

3. Per-function validation: rebuild, boot test
   - If boot breaks → the C has a bug. Fix or revert.
   - If binary too large → optimize the C or accept the growth (see RAM audit)

4. Eventually: tackle the 624 disabled Ghidra lifts as starting points for more C

5. **No slot size constraints.** A C function that's 20% larger just shifts everything
   after it. The linker resolves all references. This is why we did all of this.

## Constant Pool Classification

The core challenge of L2. Every 4-byte value in a constant pool must be classified:

| Value Range | Type | Action |
|-------------|------|--------|
| Matches known FUN_ symbol | Code pointer | `.4byte _FUN_XXXXXXXX` |
| Matches known DAT_ symbol | Data pointer | `.4byte _DAT_XXXXXXXX` |
| 0x0600XXXX but no symbol match | Unknown addr | Keep as `.byte`, flag for review |
| 0x25XXXXXX | VDP/SCSP MMIO | Keep as `.byte` (literal) |
| 0x20XXXXXX | SMPC registers | Keep as `.byte` (literal) |
| 0xFFFFFEXX | On-chip I/O | Keep as `.byte` (literal) |
| Everything else | Numeric constant | Keep as `.byte` (literal) |

**Conservative approach**: only symbolize values that exactly match a known symbol.
Leave everything else as literal bytes. This guarantees byte-identical output.
Unknown 0x0600XXXX values get flagged — they might be mid-function addresses,
computed offsets, or symbols we haven't catalogued.

## Resources

- `build/aprog.s` — full disassembly (206K lines, 1,234 function labels)
- `build/aprog_syms.txt` — symbol table (function addresses)
- `reimpl/src/linker_stubs.c` — ~1,482 data symbol addresses
- `asm/*.s` — 46 Sawyer annotation files (rich comments, struct layouts)
- `reimpl/src_c_archive/` — archived C source (93 hand-written + 624 Ghidra lifts)
- `experiments/` — POC validation (2026-02-17), all use FUN_0600E71A (player physics orchestrator, 174 bytes):
  - `poc_original.s` / `poc_link.ld` / `poc_test.sh` — baseline: function as raw `.byte` directives
  - `poc_symbolic.s` / `poc_relocated.ld` / `poc_reloc_test.sh` — L2 test: `.4byte _SYMBOL` pool entries, proves relocation works
  - `poc_real_asm.s` / `poc_real_link.ld` / `poc_real_test.sh` — L3 test: real SH-2 mnemonics, proves assembler produces correct output

## Open Questions

1. **RAM budget**: Need a work RAM audit to determine actual wiggle room beyond
   394,896 bytes. If there's headroom, C functions that compile larger are fine.

2. **Data gaps**: Should interleaved data be emitted in `.s` files or handled by
   the gap patcher post-link? Gap patcher is simpler but less self-contained.

3. **Alignment**: Functions starting at 2 mod 4 need pool entries at 4-byte boundaries.
   The L2 approach (`.byte` instructions + `.4byte` pools) handles this with `.4byte`
   which doesn't enforce section-relative alignment. L3 (real mnemonics) needs explicit
   padding — manageable but needs care.

4. **Unknown addresses**: Pool values in 0x0600XXXX that don't match any symbol.
   These need new labels created, or they stay as literals and we accept that those
   specific references won't relocate. Phase 3 boot testing will expose any that matter.

---
*Created: 2026-02-17*
*Updated: 2026-02-17 — POC results, full phase plan*
