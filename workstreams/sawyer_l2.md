# Sawyer L2 — Relocatable Assembly Source

> **Status**: Active — Phase 3 root cause FOUND (1,544 absolute PROVIDEs; fix pending)
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

### Phase 1: Build Pipeline Setup — DONE

**Goal**: Fresh build system in `reimpl/` that assembles `.s` files and links them.

**Completed 2026-02-17:**
- Archived old C source: `reimpl/src/` → `reimpl/src_c_archive/` (git mv)
- New Makefile: discovers `src/*.s`, assembles with `sh-elf-as --isa=sh2 -big`, links with `sh-elf-ld`
- `SORT_BY_NAME(.text.FUN_*)` linker ordering — section names sort lexicographically in address order
- `make validate` target runs `cmp` against original binary
- `make disc` target injects into disc image for Mednafen testing

### Phase 2: Sawyer L2 — Automated Symbolization — DONE

**Goal**: All 1,234 functions as `.s` files with symbolic pool entries. Byte-identical output.

**Completed 2026-02-17:**
- Built `tools/symbolize_pools.py` — reads `build/aprog.bin` directly, generates all `.s` files + linker script
- **1,259 `.s` files** generated (1,258 functions + `_start.s`)
- Symbol sources:
  - 1,258 FUN_ symbols from `build/aprog_syms.txt`
  - 1,341 DAT_ symbols from `reimpl/src_c_archive/linker_stubs.c`
  - 1,749 synthetic sym_ symbols extracted from `build/aprog.s` disassembly comments
  - **4,348 total symbols**
- **7,236 pool entries symbolized** (from initial 1,146 — 6.3x improvement)
- Auto-generated `reimpl/sawyer.ld` with PROVIDE declarations for all symbols
- **Gate PASSED**: `cmp` — byte-identical to original (394,896 bytes)

**Key design decisions:**
- `.4byte` (not `.long`) for pool entries — avoids alignment enforcement for 2-mod-4 functions
- Each function in its own section (`.text.FUN_XXXXXXXX`) for SORT_BY_NAME ordering
- Synthetic symbols (sym_XXXXXXXX) created for addresses in 0x06000000-0x060FFFFF range
  that appear in disassembly comment annotations but aren't in FUN_/DAT_ tables

### Phase 3: Free Layout + Boot Test — IN PROGRESS

**Goal**: Prove the binary works without fixed addresses.

#### Experiment Results (2026-02-17)

Four binary-shift experiments confirmed the approach (details in road_to_boot.md):

| Experiment | Shift? | Boot? | Conclusion |
|------------|--------|-------|------------|
| Pad prod binary +4 at end | No | YES | Disc pipeline handles size changes |
| Re-inject prod binary | No | YES | Injection pipeline is lossless |
| Insert 4 zeros mid-binary | Yes (+4) | **NO** | Shifting content breaks boot |
| Free-layout LD, 0-pad | No (identical) | YES | Linker script itself is harmless |

**Key finding**: Experiment 3 proved that shifting binary content by even 4 bytes —
inserting zeros into a 4,116-byte zero run — causes a black screen. This confirms
unsymbolized absolute addresses are the root cause, and validates that Phase 2's
pool symbolization work is exactly the right fix.

#### Free-Layout Boot Test Result (2026-02-17)

Built with `sawyer_free.ld` (+4 padding), injected, boot tested: **BLACK SCREEN**.
Binary is 394,900 bytes (394,896 + 4). The symbolized pools were expected to fix
this — but they didn't. Initial tool-based analysis (find_stale_addresses.py,
find_unsymbolized_pool.py) suggested pools were 99.4% symbolized and the remaining
unsymbolized entries were runtime data addresses that don't need relocation.

**Problem**: We were trusting tool output as ground truth. The tools themselves
could have bugs. We need to verify with independent ground truth before theorizing.

#### Ground Truth Validation Results (2026-02-17)

Three independent tests to establish facts before theorizing about root cause.
Each uses a different evidence source to avoid compounding tool bugs.

**GT1: Linker Map Diff** -- PASSED (linker is correct)

Compared `reimpl/build/daytona_prod.map` (sawyer.ld) vs `reimpl/build/daytona_free.map`
(sawyer_free.ld). Checked every symbol's address in both maps.

| Category | Count | Result |
|----------|-------|--------|
| FUN_ symbols shifted +4 | 1,258 | All correct |
| sym_/DAT_ PROVIDEs shifted | 0 | **Expected: they're PROVIDE (absolute)** |
| sym_/DAT_ PROVIDEs unchanged | 3,141 | All stayed at fixed addresses |
| Total symbols compared | 4,399 | No anomalies |

**Conclusion**: The linker is doing exactly what we told it to. FUN_ labels (defined
in .s files) are section-relative and shift correctly. PROVIDE symbols are absolute
and don't shift. The linker is not buggy — *our PROVIDEs are*.

**GT2: Manual Hex Verification + Stale Entry Classification** -- ROOT CAUSE FOUND

Phase 1: Verified 5 known _start pool entries (offsets 0x60-0x80) by reading raw
bytes from both binaries. All correctly showed `.4byte FUN_X` → shifted +4.
This confirmed the symbolized pool entries work perfectly.

Phase 2: Exhaustive 4-byte comparison of both binaries found entries where a code-range
value (0x06xxxxxx) appeared in the prod binary but didn't shift in the free binary.
Previous tool (`find_stale_addresses.py`) reported only 15 such entries — the real
count is much higher. **The tool was wrong.**

Phase 3: Classification of all stale entries using `tools/classify_stale_entries.py`:

| Classification | Count | Meaning |
|---------------|-------|---------|
| **ABS_SYMBOL** | 2,961 | `.4byte sym_X` where PROVIDE is absolute — linker resolves to fixed address |
| **DATA_CONSTANT** | 184 | Values like 0x0601FFFF (masks), not real addresses |
| **PATTERN_DATA** | 59 | Game data tables with coincidental 0x06 byte patterns |
| **GENUINE_STALE** | 12 | Unsymbolized `.byte` entries referencing in-binary addresses |

**The 2,961 ABS_SYMBOL entries are the smoking gun.** These are `.4byte sym_XXXXXXXX`
references that the linker resolved to absolute addresses. Analysis of the PROVIDE
addresses reveals:

| PROVIDE Address Range | Count | In Binary? | Needs Fix? |
|----------------------|-------|------------|------------|
| Below 0x06003000 (BIOS/vectors) | 19 | No | No |
| 0x06003000-0x06063690 (IN BINARY) | **1,544** | **YES** | **YES** |
| 0x06063690-0x06070000 (BSS/init data) | 103 | No | No |
| 0x06070000+ (work RAM, MMIO) | 538 | No | No |
| **Total** | **2,204** | | |

**70% of all PROVIDE symbols (1,544 of 2,204) point into the binary's own address
range.** When the binary shifts +4, these absolute addresses become stale — they
point to the old location while the actual content moved. This is the root cause
of the free-layout black screen.

The 12 GENUINE_STALE `.byte` entries are a secondary issue — they're unsymbolized
pool entries that also need fixing, but the 1,544 absolute PROVIDEs affect far more
references throughout the binary.

**GT3: Mednafen Debugger Trace** -- SUPERSEDED

GT1 and GT2 together provide a complete diagnosis. The linker map proves the
mechanism (PROVIDE = absolute, no relocation). The hex verification proves the
effect (1,544+ stale values in the binary). GT3 would only confirm what we
already know — a CPU trace would show execution jumping to a stale address.
Skipping GT3 in favor of building and testing the fix directly.

#### Root Cause

The `.4byte SYMBOL` pool entries are correctly symbolized. The linker correctly
resolves them. But `PROVIDE(sym_X = 0xABCDEF)` creates an **absolute** symbol.
The linker emits the literal value 0xABCDEF regardless of where the section
containing that address ends up. This is by design — PROVIDE with a constant
creates an absolute symbol.

**Fix**: For the 1,544 in-binary PROVIDEs, change from absolute:
```
PROVIDE(DAT_06003366 = 0x06003366);
```
to relative (parent function + offset):
```
PROVIDE(DAT_06003366 = FUN_0600330A + 0x5C);
```
Since `FUN_0600330A` is a section label (defined in its `.s` file), the expression
`FUN_0600330A + 0x5C` is relocatable. When FUN_0600330A shifts, DAT_06003366 shifts
with it. In production layout (no shift), the result is identical to the absolute form.

Script: `tools/fix_provide_symbols.py`

#### Validation Plan

1. Run `fix_provide_symbols.py` to update both `sawyer.ld` and `sawyer_free.ld`
2. Build with `sawyer.ld` (production) → `make validate` must PASS (byte-identical)
3. Build with `sawyer_free.ld` (+4 shift) → `make disc` → boot test
4. **Gate**: game boots with +4 padding (attract mode or better)

**Gate**: game boots with +4 padding (attract mode or better).

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

2. ~~**Data gaps**~~: RESOLVED — symbolize_pools.py emits all bytes including inter-function
   gaps as part of the `.s` files. No separate gap patcher needed.

3. ~~**Alignment**~~: RESOLVED — using `.4byte` (not `.long`) avoids alignment enforcement.
   Functions at 2-mod-4 addresses work correctly because `.4byte` just emits 4 bytes.

4. ~~**Unknown addresses**~~: LARGELY RESOLVED — synthetic symbols (sym_XXXXXXXX) cover
   1,749 additional addresses extracted from disassembly comments. Remaining unsymbolized
   pool entries are numeric constants, MMIO addresses, or addresses outside work RAM.
   Phase 3 boot test will validate.

---
*Created: 2026-02-17*
*Updated: 2026-02-17 — Phase 3 root cause found: 1,544 absolute PROVIDE symbols. Fix script ready.*
