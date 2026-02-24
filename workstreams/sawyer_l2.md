# Sawyer L2 — Relocatable Assembly Source

> **Status**: Active — Phase 3 COMPLETE (free build boots, races laps). Phase 4/5 next.
> **Created**: 2026-02-17
> **Predecessor**: DONE_function_audit.md, ICEBOX_gameplay_extraction.md (Sawyer annotations)

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
| **L3.5** (free placement) | SH-2 mnemonics | symbolic `mov.l` | Yes | boot test |
| **L4** (C reimpl) | C source | N/A (compiler pools) | Yes | boot test |

**L2 is the minimum work that breaks the cage.** Instructions stay as opaque bytes,
only the constant pool entries are symbolized. Because instruction bytes are identical,
we can verify the conversion with `cmp`. This is automatable.

**L3 is understanding.** Converting `.byte` pairs to real mnemonics. Pool loads
(`mov.l @(disp,PC)`) stay as `.byte` pairs when they reference pools in neighboring
sections. Validated by boot test.

**L3.5 is free placement.** All `mov.l @(disp,PC)` use symbolic pool labels (e.g.,
`mov.l .L_pool_xxx, r0`). Requires the entire translation unit to be consolidated
into one section so the assembler can compute displacements. The assembler auto-bumps
section alignment to 4 and uses a `(val + 2) / 4` integer division trick that handles
instructions at both 0 mod 4 and 2 mod 4 positions correctly. Pool entries need
`.balign 4` before them. See "Translation Unit Reconstruction" below.

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

**Completed 2026-02-17 (restructured 2026-02-21):**
- Original C source archived, then restructured: `reimpl/retail/` = Sega originals, `reimpl/src/` = reimplemented (auto-overrides by stem)
- Makefile discovers `retail/*.s` + `src/*.{s,c}`, assembles/compiles, links with `sh-elf-ld`
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
  - 1,341 DAT_ symbols (originally from linker_stubs.c, now baked into `sega.ld`/`free.ld`)
  - 1,749 synthetic sym_ symbols extracted from `build/aprog.s` disassembly comments
  - **4,348 total symbols**
- **7,236 pool entries symbolized** (from initial 1,146 — 6.3x improvement)
- Auto-generated linker script (now `reimpl/sega.ld` / `reimpl/free.ld`) with PROVIDE declarations for all symbols
- **Gate PASSED**: `cmp` — byte-identical to original (394,896 bytes)

**Key design decisions:**
- `.4byte` (not `.long`) for pool entries — avoids alignment enforcement for 2-mod-4 functions
- Each function in its own section (`.text.FUN_XXXXXXXX`) for SORT_BY_NAME ordering
- Synthetic symbols (sym_XXXXXXXX) created for addresses in 0x06000000-0x060FFFFF range
  that appear in disassembly comment annotations but aren't in FUN_/DAT_ tables

### Phase 3: Free Layout + Boot Test — DONE

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

Built with `free.ld` (+4 padding), injected, boot tested: **BLACK SCREEN**.
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

#### PROVIDE Fix — Applied, Verified, Necessary but Not Sufficient

**Root Cause (partial)**: `PROVIDE(sym_X = 0xABCDEF)` creates an absolute symbol.
The linker emits the literal value regardless of where the section ends up.

**Fix**: `tools/fix_provide_symbols.py` converts 1,543 in-binary PROVIDEs from
absolute to relative expressions: `PROVIDE(sym_X = FUN_parent + offset)`.

**Results** (commit `7f5310d`):
- sawyer.ld: 1,258 converted, `make validate` PASS (byte-identical)
- sawyer_free.ld: 1,543 converted, all 5,027 pool entries correctly shift +4
- 661 PROVIDEs kept absolute (runtime data outside binary, correct as-is)
- **Boot test: still BLACK SCREEN**

**Post-fix stale analysis**: Only 15 remaining "stale" values at 4-byte alignment,
ALL are data constants (bit masks like 0x0601FFFF, pattern data like 0x06010001).
**Zero genuine stale address references remain in the binary.**

The 2-byte alignment scan found 37 total, but the extras are overlapping byte windows
creating false positives (e.g., two adjacent 16-bit DAT_ values that coincidentally
form a 0x0600xxxx 32-bit value). Verified by reading the .s source — confirmed not
pool entries.

**Conclusion**: Address relocation within APROG.BIN is COMPLETE. The black screen
has a different root cause. The PROVIDE fix was necessary but not sufficient.

#### Investigation Round 2 — Results

All internal relocation verified correct. Five tests to find the root cause of the
persistent black screen after the PROVIDE fix.

**RT1: Byte-Level Diff — PASS** (tools/byte_diff_test_v2.py)
- Compared every byte: `prod[i]` vs `free[i+4]` for all `i >= 0xFC`
- 100% of bytes accounted for. Zero unexpected differences.
- 5,062 relocated pool entries all show consistent +4 shift.
- Instruction bytes identical. No linker padding, no section reordering.

**RT2: Round-Trip Injection — PASS** (tools/rt2_injection_test.py)
- Extracted APROG.BIN from rebuilt disc image, compared to build output.
- Every byte matches. Injection is lossless.
- ISO 9660 directory entry correctly shows 394,900 bytes.

**RT3: IP.BIN Boot Header — PASS** (tools/analyze_boot_header.py)
- IP.BIN does NOT hardcode APROG.BIN file size anywhere.
- BIOS loads APROG using ISO 9660 directory entry (which inject_binary.py patches).
- IP.BIN sets up hardware, then jumps to 0x06003000 (the entry point — same in both).

**RT5: External Data File Scan — PASS** (tools/rt5_scan_data_files.py, rt5_classify_hits.py)
- Scanned all 25 data files on disc for 4-byte big-endian values in APROG range.
- 16,315 raw hits across all files — but cross-referencing against FUN_ addresses:
  - 37 match a FUN_ address, but 25 of 37 are at unaligned offsets in data files
  - 12 at 4-byte-aligned offsets — ratio (1/3) matches random chance for data
  - Values like 0x060401FC, 0x0600FDFE appear across unrelated file types (MUSICD, NAMD, OVERD)
  - Conclusion: ALL are coincidental byte patterns in texture/model/audio data
- No genuine external pointers into APROG.BIN code space.

**Comprehensive Pool Verification** (tools/verify_all_pools.py)
- Scanned both binaries at 2-byte stride (catches 2-mod-4 pool entries):
  - 5,027 correctly shifted +4 (in-binary addresses)
  - 3,226 correctly static (outside binary)
  - 23 anomalies at 2-mod-4 offsets — all verified as:
    - 18 data constants (0x06020002, 0x06040004, 0x06060006, etc.)
    - 4 instruction byte coincidences (straddling two instructions)
    - 1 overlapping pool boundary (two 4-byte entries read at 2-byte offset)
  - **ZERO genuine relocation errors**

**GT3: Function Call Trace Comparison — COMPLETE (2026-02-17)**

Built automated call tracing into Mednafen and ran both discs for 300 frames.

**Infrastructure built:**
- Modified `sh7095_ops.inc`: added `fprintf` logging to BSR, BSRF, JSR handlers
  (guarded by `MDFN_UNLIKELY(CallTraceFile != nullptr)` for zero overhead when off)
- Modified `sh7095.h`: added `FILE* CallTraceFile` member to SH7095 class
- Modified `ss.cpp`: added `Automation_EnableCallTrace(path)` and `Automation_DisableCallTrace()`
- Modified `automation.cpp`: added `call_trace` and `call_trace_stop` commands
- Log format: `M|S <caller_PC> <target_addr>` (M=primary SH-2, S=secondary SH-2)
- Tools: `tools/call_trace_compare.py`, `tools/call_trace_determinism.py`

**Determinism test** (two production runs side by side):
- Run A: 621,759 calls, Run B: 613,758 calls (~1.3% timing variance)
- **All 613,758 shared calls are IDENTICAL** — sequence is perfectly deterministic
- Confirmed: Mednafen call tracing is reliable for comparison

**Prod vs free-layout comparison** (300 frames each):
- Production: 594,870 primary calls, **0 secondary calls**
- Free-layout: 597,573 primary calls, **0 secondary calls**
- **Single-threaded boot confirmed** — no secondary SH-2 activity

**CRITICAL FINDING: Both traces show IDENTICAL raw hex addresses.**
- First APROG-range calls appear at line 95,309 (~frame 47)
- Every call address in the free trace matches the production trace exactly
- Example: both show `M 0601078A 06000794` — the free trace should show `0601078E` if shifted
- The +4 shift IS on disc (verified: `sh-elf-nm` shows FUN_06010760 at 0x06010764)
- The disc image IS correct (extracted APROG matches free-layout binary byte-for-byte)
- But in-memory execution happens at **production addresses**

**SOLVED: Call traces show identical addresses — BIOS timing bug**

Previous traces (100-300 frames from frame 0) showed identical addresses because they
captured **BIOS code, not APROG**. The Saturn BIOS takes ~352 frames to load APROG from
disc. During boot, the BIOS copies its CD loading routines into Work RAM High
(0x06000000+), so BSR/JSR calls from 0x060xxxxx addresses in those traces were BIOS
calls, not game code. Same BIOS = same addresses = identical traces.

**Fix**: Set breakpoint at 0x06003000 (APROG entry), wait for BIOS to load, THEN
enable call trace. Post-entry traces show the +4 shift perfectly on every address.

**Cross-validation results (2026-02-17):**
- `tools/early_mem_dump.py --disc both` confirmed:
  - Production disc → RAM matches production binary (394,896/394,896 = 100%)
  - Reimpl disc → RAM matches reimpl binary (394,900/394,900 = 100%)
  - The +4 shifted binary IS correctly loaded into RAM
  - 324,916 byte differences between the two dumps (constant pool shifts)
- Post-entry call trace (breakpoint at 0x06003000, then 50 frames):
  - Production: 936,710 calls, reimpl: 911,274 calls
  - Every APROG address shows the expected +4 shift:
    - `_start+6 → FUN_060030FC` (prod) vs `_start+6 → 0x06003100` (reimpl)
    - Caller and target addresses both shift consistently
  - Sawyer annotations verified: `_start.s` line 54 has `.4byte FUN_060030FC`,
    corresponding to `JSR @R1` at offset +6 (0x410B). Trace confirms exactly this.
- All three earlier hypotheses ELIMINATED:
  1. ~~DMA self-modification~~ — memory dump at entry+50 frames shows code intact
  2. ~~Memory dump tooling bug~~ — early_mem_dump.py works correctly
  3. ~~Free binary not executing~~ — 100% binary match in RAM + shifted traces

**Remaining investigation: Why does the free-layout black screen?**
The binary is loaded correctly, the call trace shows shifted addresses, but the game
still doesn't boot. The remaining suspect: **unsymbolized constant pool entries** in
the `.byte` instruction blobs. These contain hardcoded production addresses that
did NOT get the +4 shift through the linker — they point to production-layout
code that no longer exists at those addresses.

**Next approaches:**
1. **Catalog unsymbolized pool references** — scan `.byte` blobs for 4-byte values
   that look like APROG addresses (0x0600xxxx) but aren't in `.4byte` entries
2. **Single-function enlargement** — instead of shifting everything, make ONE init
   function bigger and test if boot still works. Isolates shift vs specific function.
3. **Instruction-level divergence** — the traces show 936K vs 911K calls (25K fewer
   in reimpl). Find where the reimpl trace diverges/stops — that's the crash point.

**New finding: Section alignment (310 functions at 2-mod-4 addresses)**
- 948 functions at 0-mod-4 addresses, 310 at 2-mod-4 addresses.
- Verified: `sh-elf-as` produces sections with `2**0` (1-byte alignment).
- Linker map confirms no padding between any sections.
- Section alignment hypothesis ELIMINATED.

**BSRF/BRAF analysis — ELIMINATED**
- 1,593 BSRF + 79 BRAF = 1,672 PC-relative branch instructions in binary.
- Zero cross from FUN_ space to _start range.
- Both source and target shift by same +4, so relative displacement is unchanged.

**IP.BIN code scan — CLEAN**
- All 32KB of IP.BIN scanned for APROG addresses.
- Only 2 hits: both are 0x06003000 (header field + jump target).
- No references to APROG internals — IP.BIN is completely safe.

**Homebrew SDK Comparison (Jo Engine + libyaul)**

Examined two Saturn homebrew SDKs for linker/build differences:

| Feature | Our Sawyer Build | Jo Engine | libyaul |
|---------|-----------------|-----------|---------|
| Output format | `elf32-sh` | `coff-sh` | `elf32-sh` |
| Load address | `0x06003000` | `0x06004000` | `0x06004000` |
| Linker driver | `sh-elf-ld` (direct) | `sh-elf-gcc -Xlinker` | `sh-elf-gcc` |
| Section layout | 1,258 `.text.FUN_*` | Single `.text` | Single `.text` |
| PROVIDE symbols | 4,348 | None | None |
| Alignment | `2**0` (1-byte) | `ALIGN(0x20)` | Default |

Key differences that could matter:
1. **Per-function sections**: Neither SDK uses this. Both have a single `.text`.
2. **PROVIDE symbols**: Neither SDK has any. This is unique to our approach.
3. **Linker driver**: Both SDKs use `sh-elf-gcc` (passes `-relax` and implicit flags).
   We call `sh-elf-ld` directly.
4. **No MEMORY regions**: We don't define MEMORY{} blocks (libyaul does).

None of these differences directly explain the black screen, but the per-function
section approach and massive PROVIDE count are unusual and worth further investigation.

**Daytona Memory Architecture (studied 2026-02-17)**

See `workstreams/overlay_system_study.md` for full analysis.

Key findings relevant to Sawyer L2:
- **APROG code stays intact in High RAM** — overlays load to Low RAM and Sound RAM
- BSS clearing only zeros 0x06063690-0x060A5404 (ABOVE APROG, not within it)
- 26 data files on disc; 7 are state overlays (446KB each) swapped in Low RAM / Sound RAM
- The game uses ISO9660 filename-based loading via `FUN_06012C3C`
- **APROG is the complete game engine** — all 1234 functions stay resident
- The identical-trace mystery remains unsolved (see above)

**Gate**: ~~game boots with +4 padding (attract mode or better).~~ **PASSED (2026-02-20)**. Free build boots to title screen, mode select works, can race laps. Root cause fixes in `DONE_free_build_compat.md`.

### Phase 4: Sawyer L3 — Real ASM Source (Incremental)

**Goal**: Convert opaque `.byte` instructions to readable SH-2 mnemonics.

#### Translation Unit Reconstruction (2026-02-23)

**Key discovery**: Sega's compiler shared constant pools across neighboring functions
within the same `.c` file. A small function's `mov.l @(disp,PC)` instruction can
reach into a neighboring function's pool — a cross-section reference that proves both
functions were compiled together. By tracing these references, we can reconstruct
the boundaries of Sega's original translation units.

**The assembler constraint**: `mov.l @(disp,PC)` and `bf/bt/bra/bsr` are resolved at
assembly time using section-relative offsets. They CANNOT cross section boundaries.
When we split a TU into separate sections, these instructions must stay as `.byte` pairs
(L3) or the sections must be merged (L3.5). The assembler enforces this — it errors on
cross-section `mov.l` ("negative offset") and `bf/bt` ("overflow 8-bit field").

**First TU mapped: the game update loop** (0x06033BC8 – 0x06034E20, ~4,700 bytes, ~100 functions).
Contains display thunks, score rendering, physics integration, AI steering, axis damping,
rotation helpers, waypoint following, braking, throttle, and recovery. Sega crammed the
entire per-frame car update into one C file — classic 90s game dev.

Boundaries confirmed by absence of cross-section references:
- **Start**: `camera_attract_init` (0x06033BC8). Prior function `hud_subsystem_init`
  (0x06033AAC) is fully self-contained.
- **End**: `ai_recovery_handler` (0x06034DEA). Next function `smpc_cmd_init`
  (0x06034E20) is a different subsystem with zero cross-references.

Internal structure — the compiler placed pool holders at intervals, with clusters
of small functions borrowing from them:

| Pool holder | Cluster functions | Address range |
|------------|-------------------|---------------|
| `time_extend_digits` | camera_attract_init, disp_timeext_digit_{0,1,2} | 0x06033BC8–0x06033C6E |
| `selector_group_render` | 19× disp_sel_thunk | 0x06033C6E–0x06033D76 |
| `bonus_points_display` | 19× disp_selext_thunk, score_display_render, disp_score_* | 0x06033D76–0x06033F80 |
| `display_frame_flush` | 9× disp_end_stub, display_frame_mgr | 0x06033F80–0x06034036 |
| `phys_velocity_integrate` | phys_position_load | 0x06034036–0x060340C0 |
| `phys_final_integrate` | phys_result_store, phys_perspective | 0x060340C0–0x0603411E |
| `ai_steering_response` | phys_lighting_setup | 0x0603411E–0x06034172 |
| `xaxis_integrate_damp` | ai_vel_x_{entry,step_a,step_b,step_c} | 0x06034172–0x060341FA |
| `yaxis_integrate` | ai_vel_x_cleanup_{entry,a,b,c} | 0x060341FA–0x06034286 |
| `zaxis_integrate` | ai_vel_y_{entry,step_a,step_b,step_c} | 0x06034286–0x0603430E |
| `ai_decision_dispatch` | ai_vel_z_{entry,step_a,step_b,step_c}, ai_rot_* (11 fn) | 0x0603430E–0x060344FC |
| `ai_car_full_init` | ai_speed_limit through ai_spawn_helper_d | 0x060344FC–0x06034708 |
| More clusters... | vblank_handler through ai_recovery_handler | 0x06034708–0x06034E20 |

#### Consolidation approach

1. **Retail**: Merge all ~100 files into one `retail/game_update_loop.s` with individual
   `.section .text.FUN_XXXXXXXX` directives per function. Mechanical, zero risk. The linker
   sees identical sections. Validate with `make validate` (byte-identical).

2. **Src L3**: Build one `src/game_update_loop.s` with a SINGLE section. Add clusters
   incrementally — each cluster up to its pool holder. When a cluster is added, all its
   `mov.l @(disp,PC)` become symbolic. Cross-cluster `bf/bt/bra/bsr` at the seam become
   symbolic as the next cluster is merged. Validate with `python tools/validate_build.py`.

3. **Stub files**: When a function's code lives inside `src/game_update_loop.s`, create an
   empty `src/<original_name>.s` stub so the Makefile doesn't link the retail `.o`. The
   global symbol is defined in `game_update_loop.s`.

4. **Self-correcting**: If we miss a function, the assembler errors on cross-section
   references. If we include an extra function, no harm — it just works in the bigger section.

#### L3 conversion details

- Non-pool instructions: convert `.byte` pairs to SH-2 mnemonics (`sts.l`, `jsr`, `mov.l @Rm, Rn`, etc.)
- `mov.l @(disp,PC)`: use symbolic pool labels (`mov.l .L_pool_xxx, rN`) — requires same section
- `bf/bt`: use symbolic labels for intra-section targets; `.byte` for cross-section
- `bra/bsr`: use symbolic labels for intra-section; `.byte` for cross-section (12-bit relocation unsupported)
- Pool entries: `.balign 4` before first entry, then `.4byte` with labels
- The assembler's `(val + 2) / 4` trick handles `mov.l` displacement correctly regardless of
  instruction alignment within the section

### Phase 5: C Introduction (The Payoff)

**Goal**: Replace ASM functions with C, one at a time. No slot constraints.

1. Add a `.c` file to `reimpl/src/` — Makefile auto-discovers it and overrides the retail `.s`
   - First C reimpl done: `src/FUN_060423CC.c` (SCDQ poll timeout — latent bug fix)
   - Archived Ghidra lifts in `reimpl/src_c_archive/` can serve as starting material

2. Per-function validation: `make validate` (retail byte-identical), `make disc` (boot test)
   - If boot breaks → the C has a bug. Fix or revert.
   - If binary too large → optimize the C or accept the growth (see RAM audit)

3. **No slot size constraints.** A C function that's 20% larger just shifts everything
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

- `reimpl/retail/` — 1,259 `.s` files (L2 relocatable ASM, symbolic pools)
- `reimpl/src/` — reimplemented functions (C or ASM) — auto-override retail by stem name
- `reimpl/free.ld` / `reimpl/sega.ld` — linker scripts with PROVIDE declarations
- `reimpl/Makefile` — build system (see for all targets and flags)
- `build/aprog.s` — full disassembly (206K lines, 1,234 function labels)
- `build/aprog_syms.txt` — symbol table (function addresses)
- `asm/*.s` — 46 Sawyer annotation files (rich comments, struct layouts)
- `reimpl/src_c_archive/` — archived Ghidra lifts (93 hand-written + 624 auto, starting material for Phase 5)
- `experiments/` — POC validation (2026-02-17), FUN_0600E71A proof-of-concept for L2/L3 approaches

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
*Updated: 2026-02-17 — PROVIDE fix applied (commit 7f5310d), relocation complete but black screen persists.*
*Updated: 2026-02-17 — Investigation Round 2: RT1/RT2/RT3/RT5 all PASS. Zero relocation errors. Section alignment ELIMINATED.*
*Updated: 2026-02-17 — GT3 Call trace: identical traces unexplained. Overlay hypothesis DISPROVED (overlays go to Low RAM/Sound RAM, APROG stays intact). See overlay_system_study.md.*
*Updated: 2026-02-21 — Phase 3 gate PASSED. Build restructured: retail/ + src/ layout, linker scripts renamed, +4 shift made optional. Phase 5 mechanism live (first C reimpl: FUN_060423CC).*
