# Feature Harvest — libRetroReversing + beetle-saturn-libretro

Exhaustive inventory from source code review (2026-03-01).
Organized by feature area. Each feature rated for our project.

Legend:
- **STEAL** = implement in our Mednafen fork / Python tools
- **SKIP** = not useful for us (wrong console, UI-only, etc.)
- **MAYBE** = worth considering but not priority

---

## 1. Function Discovery & Call Graph

### What they have (CDL_interface.cpp, N64.cpp)

**Runtime function discovery** — Every JSR/BSR is intercepted by `libRR_log_function_call(pc, target, sp)`.
Creates a `cdl_labels` struct per function with:
- `func_name`, `func_offset` — identity
- `function_calls` — map of addresses this function calls (callee set)
- `read_addresses`, `write_addresses` — every memory address read/written by this function
- `function_bytes` — raw bytecode from entry to return (signature)
- `return_offset_from_start` — function size (entry to furthest return)
- `caller_offset`, `stack_trace` — who called this and full stack at discovery time
- `first_frame_access`, `last_frame_access`, `number_of_calls`, `number_of_frames` — usage stats

**Call stack tracking** — `function_stack` vector + `previous_ra` return address stack.
Tracks nesting depth (`libRR_call_depth`), detects mismatched returns.

**Per-playthrough function stats** — `playthough_function_usage` JSON records which functions
are active in which frames, call frequency per frame, first/last frame seen.

| Feature | Verdict | Notes |
|---------|---------|-------|
| Runtime function discovery | **STEAL** | We have `call_trace` but don't build persistent function DB |
| Per-function callee set | **STEAL** | call_trace logs calls but doesn't aggregate per-function |
| Per-function memory R/W profile | **STEAL** | This is gold — reveals what each function touches |
| Function size measurement | **STEAL** | Entry-to-return offset = function boundary discovery |
| Per-playthrough usage stats | **MAYBE** | Useful for identifying "this function only runs in menus" |
| Call stack tracking with depth | SKIP | We have this in debugger_utils step_into/step_out |

### How to implement

Extend `call_trace` output format to include: caller PC, callee PC, return PC, frame number.
Python post-processor builds per-function profile: callees, callers, frame ranges, call counts.
Memory R/W profile requires new automation command (see section 3).

---

## 2. SDK Signature Matching

### What they have (N64.cpp:681-903, CDL_interface.cpp)

**Signature generation** — At every function return, collects bytes from entry to return.
Two formats: `function_bytes` (raw), `word_pattern` (instruction-level, with length suffix).

**Three-tier matching:**
1. `library_signatures` — known SDK (e.g., libultra). Exact match → auto-rename.
2. `game_signatures` — already-identified game functions. Cross-playthrough reuse.
3. `function_signatures` — unknown, collected for future matching.

**Fuzzy matching** — `find_most_similar_function()` uses Jaro-Winkler distance:
- >=95% → renamed immediately (high confidence)
- 90-95% → tagged `_predict_` + confidence percentage
- <90% → keep auto-generated name

**Signature DB** — JSON file (`libultra.json`) keyed by byte pattern → function name.

| Feature | Verdict | Notes |
|---------|---------|-------|
| Byte pattern extraction from .A archives | **STEAL** | `sh-elf-objdump -d` on our SGL .A files |
| Exact signature matching | **STEAL** | Simple binary search against APROG.BIN |
| Fuzzy matching (Jaro-Winkler) | **STEAL** | Critical — Daytona may use prototype SGL |
| Three-tier signature DB | **MAYBE** | Overkill for one game, but useful concept |
| Runtime signature generation | SKIP | We have the full binary, don't need runtime collection |

### How to implement

1. `sh-elf-objdump -d` each .o in the SGL .A archives → extract function byte patterns
2. Python scanner: slide each pattern across APROG.BIN, report matches
3. Jaro-Winkler for near-misses (different optimization level, prototype SDK)
4. Output: address → SGL function name mapping

---

## 3. Hardware Register Function Tagging

### What they have (N64.cpp:946-1011)

**`add_tag_to_function(tag, labelAddr)`** — Appends semantic tag to function name.
Called from emulator hardware hooks. Tags observed in N64 implementation:

- `_piRegRead` / `_piRegWrite` — Peripheral Interface (cart access)
- `_rspRegRead` / `_rspRegWrite` — Reality Signal Processor
- `_miRegRead` / `_miRegWrite` — Memory Interface
- `_audioRegAccess` — Audio Interface
- `_cartRegAccess` — Cartridge registers
- `_serialInterfaceRegAccess` — Serial Interface (controllers)
- `_dmaSiRead` — SI DMA (controller input polling)
- `_copyPifRdram` — PIF RAM copy (input data)
- `_updatesSPStatus` — SP status write
- `_manyMemoryReads` — >40 distinct read addresses
- `_manyMemoryWrites` — >40 distinct write addresses

**Per-function memory tracking:**
- `cdl_log_mem_write(addr, pc)` — records write address + PC offset in function's `write_addresses` map
- `cdl_log_mem_read(addr, pc)` — same for reads
- Threshold: `NUMBER_OF_MANY_WRITES` (40) triggers tag

### What beetle-saturn exposes (ss.h)

**Debug mask categories** — already defined for Saturn hardware:
- `SS_DBG_VDP1`, `SS_DBG_VDP1_REGW`, `SS_DBG_VDP1_VRAMW`, `SS_DBG_VDP1_FBW`
- `SS_DBG_VDP2`, `SS_DBG_VDP2_REGW`
- `SS_DBG_SCSP`, `SS_DBG_SCSP_REGW`
- `SS_DBG_SCU`, `SS_DBG_SCU_REGW`, `SS_DBG_SCU_INT`, `SS_DBG_SCU_DSP`
- `SS_DBG_SMPC`, `SS_DBG_SMPC_REGW`
- `SS_DBG_CDB`, `SS_DBG_CDB_REGW`
- `SS_DBG_SH2`, `SS_DBG_SH2_REGW`, `SS_DBG_SH2_CACHE`

| Feature | Verdict | Notes |
|---------|---------|-------|
| HW register tagging per function | **STEAL** | Core feature — auto-classify every function |
| Memory R/W tracking per function | **STEAL** | Reveals function's data footprint |
| Many-reads/many-writes threshold | **STEAL** | Identifies data-heavy functions |
| Saturn debug mask categories | **STEAL** | Already defined, map to our tag names |

### Saturn tag mapping

| Address Range | Saturn HW | Tag |
|---------------|-----------|-----|
| 0x25C00000-0x25C7FFFF | VDP1 VRAM | `_vdp1VramAccess` |
| 0x25C80000-0x25CFFFFF | VDP1 Framebuffer | `_vdp1FbAccess` |
| 0x25D00000-0x25D7FFFF | VDP1 Registers | `_vdp1RegAccess` |
| 0x25E00000-0x25EFFFFF | VDP2 VRAM | `_vdp2VramAccess` |
| 0x25F00000-0x25F7FFFF | VDP2 Color RAM | `_vdp2CramAccess` |
| 0x25F80000-0x25FBFFFF | VDP2 Registers | `_vdp2RegAccess` |
| 0x25B00000-0x25BFFFFF | SCSP (Sound) | `_soundAccess` |
| 0x20100000-0x2017FFFF | SMPC (Input) | `_inputAccess` |
| 0x25FE0000-0x25FEFFFF | SCU Registers | `_scuAccess` |
| 0x25A00000-0x25AFFFFF | SCU DSP | `_scuDspAccess` |

### How to implement

**Option A (emulator-side):** Add `hw_trace` command to automation.cpp. When active, log
`{frame, pc, hw_addr, read_or_write, value}` for every access to HW register ranges.
Python post-processor groups by calling function (use call_trace to know which function owns each PC).

**Option B (static):** Grep our L3 disassembly for `mov.l` pool entries pointing to HW ranges.
Faster, no emulator needed. Misses indirect accesses but catches most cases.

**Recommendation:** Do both. Static for bulk classification, dynamic for validation.

---

## 4. Memory Difference Tracking (Code Data Logger)

### What they have (codeDataLogger.cpp)

**Byte classification bitmask** — Every byte in ROM/RAM tagged with:
- `ExecFirst` (bit 0) — executed as instruction
- `ExecOperand` (bit 1) — instruction operand
- `Data` (bit 2) — accessed as data
- `BlockEnd` (bit 3) — last byte of contiguous block
- `Graphics` (bit 4) — graphics/tile data
- `BGMap` (bit 5) — background map data
- `OAM` (bit 6) — sprite attribute data
- `Sound` (bit 7) — audio data

**Differential tracking:**
- `differenceBetweenCurrentAndPreviousMemory()` — Compares current memory snapshot against
  previous, outputs JSON of changed ranges with type classification
- `calculateCDLStatistics()` — Counts bytes by type, generates coverage percentages
- `resetDiff()` — Copies current state to backup for next comparison

**BizHawk CDL format:** Reads/writes `.cdl` files compatible with BizHawk emulator.

| Feature | Verdict | Notes |
|---------|---------|-------|
| Byte classification (code vs data vs graphics) | **STEAL** | We can build this from call_trace + memory dumps |
| Coverage statistics | **STEAL** | "What % of code have we exercised?" |
| BizHawk CDL format | SKIP | We don't use BizHawk |
| Differential memory tracking | **STEAL** | We have dump_mem_bin, need diff pipeline |
| Changed range JSON output | **STEAL** | Feed diffs into our analysis |

### How to implement

We already have `dump_mem_bin`. Build Python pipeline:
1. Dump WRAM at frame N
2. Advance/change input
3. Dump WRAM at frame N+1
4. Binary diff → JSON of changed addresses with surrounding context

---

## 5. Save State Management

### What they have (Setup.cpp, state.cpp)

**libRetroReversing:**
- `libRR_create_save_state(name, frame)` — serializes emulator + takes PNG screenshot
- `libRR_load_save_state(frame)` — restores state, resets input playback to that frame
- `libRR_delete_save_state(frame)` — removes state + screenshot, truncates button log
- States stored as `save_[frame].sav` with companion `.sav.png`

**beetle-saturn (Mednafen core):**
- Full state serialization via `StateAction()` per module
- Tagged binary format with 32-byte section headers
- Sections: MAIN (RAM, event state), SH2-M, SH2-S, SCU, SMPC, CDB, VDP1, VDP2, SOUND, CART, INPUT
- WorkRAML (1MB), WorkRAMH (1MB), BackupRAM (32KB) all serialized
- Version validation via `MEDNAFEN_CORE_VERSION_NUMERIC`

| Feature | Verdict | Notes |
|---------|---------|-------|
| Save/load state commands | **STEAL** | Top priority — unblocks everything |
| PNG screenshot with state | **MAYBE** | Nice for human review, not critical |
| State-aware input playback | **STEAL** | Load state → resume from that point |
| Frame-indexed state naming | **STEAL** | `save_4732.sav` = racing start |

### How to implement

Mednafen already has `MDFNSS_SaveSM()` and `MDFNSS_LoadSM()`. In our automation.cpp:
```cpp
case "save_state": MDFNSS_SaveSM(path); break;
case "load_state": MDFNSS_LoadSM(path); break;
```
May need to handle event list resyncing after load. Test carefully.

---

## 6. Input Recording & Playback

### What they have (Setup.cpp, libRR.h)

**Recording:** `libRR_save_button_state_to_file()` — writes 8 bytes per frame (64-bit button mask)
to `button_log.bin`. Frame-indexed.

**Playback:** `libRR_playback_next_input_state()` — reads next frame's button state from log.
Combined with save states: load state at frame N → play back input from frame N.

**Editing:** Web UI allows editing button state at specific frames. `change_input_buttons`
message modifies the log, then resaves.

| Feature | Verdict | Notes |
|---------|---------|-------|
| Button state recording | **MAYBE** | We have deterministic replay via GAME_STATES |
| Input playback from file | **MAYBE** | Could replace our fixed replay sequences |
| Input editing | SKIP | We control input programmatically |
| Save state + input resume | **STEAL** | Key workflow: save state → experiment → reload |

### How to implement

Our `input_press`/`input_release` commands already control input. The missing piece is
save states — once we have those, we can save → experiment → reload without 4700-frame replay.

---

## 7. Scripting Engine

### What they have (Interpreter.cpp)

**Two JavaScript engines:**
1. **mjs** (default) — lightweight ES6 subset, 50KB, FFI to C via `ffi('int foo(int)')`.
   No closures, no exceptions, strict mode only. Byte strings not Unicode.
2. **Duktape** — full ECMAScript 5.1 + some ES6. Proxy, TypedArray, CBOR, regex.
   Bigger but more capable.

**FFI functions exposed:** `libRR_get_current_lba()`, `libRR_get_current_buffer()`,
`libRR_memset()`, `libRR_replace_lba_buffer()`.

**Use case:** CD content override — scripts intercept CD reads and modify data in flight.

| Feature | Verdict | Notes |
|---------|---------|-------|
| JavaScript scripting engine | SKIP | We have Python — more capable, already integrated |
| CD content override via script | SKIP | Not relevant for our RE approach |
| FFI to emulator internals | SKIP | We access internals via automation commands |

---

## 8. Source Export & Assembly Generation

### What they have (CommonSourceExport.cpp, export_templates/)

**Assembly generation** — Exports discovered functions as assembly files per platform:
- GameBoy → RGBDS format
- NES/SNES → WLA-DX format
- Per-function .asm files with caller comments and section headers

**Template system** — `export_templates/<platform>/` contains Makefile, README, linker scripts,
constants. Template variables (`{{ GAME_NAME }}`) rendered at export time.

**WLA-DX directives** — `.memorymap`, `.rombankmap`, `.SNESHEADER`, `.SNESNATIVEVECTOR`

| Feature | Verdict | Notes |
|---------|---------|-------|
| Per-function assembly export | SKIP | We already have full L3 disassembly |
| Build template generation | SKIP | We have our own Makefile/linker infrastructure |
| Bank-switching directives | SKIP | Saturn doesn't use ROM banking |
| Caller/callee comments in export | **MAYBE** | Useful annotation pattern |

---

## 9. Web UI Features

### What they have (websrc/)

**Pages (13 total, 3 stubs):**
- Function list — sortable table with metrics (first/last frame, call count)
- Function detail — edit name, view disassembly, export path
- Input history — frame-by-frame button visualization, editable
- Memory viewer — hex view with 7 tabs (hex, disasm, visual, override, notes, strings, parser)
- Hex viewer — 16-byte rows, ASCII/pixel hover, color-coded
- Disassembler — instruction mnemonics + pseudo-code
- Data visualizer — **8 visualization modes**: 1bpp, 2bpp, 8bpp, 16bpp (RGB/BGR), 24bpp, 32bpp, digraph, printable
- Code override — JavaScript injection for CD content
- Notes — Markdown annotations per memory region
- Resources — CD file tree browser with access counts
- Main state — save state history with screenshots

**Binary parser** — Uses `binary-parser` JS library for defining struct layouts over memory regions.

| Feature | Verdict | Notes |
|---------|---------|-------|
| Function list with usage metrics | **MAYBE** | Nice for human review, we'd use Python |
| Memory hex viewer | SKIP | We dump and analyze in Python |
| Data visualizer (8 modes) | **MAYBE** | 16bpp visualization could help identify textures in VRAM |
| Binary struct parser | **MAYBE** | We could build struct definitions in Python |
| CD file browser with access stats | SKIP | Not our bottleneck |
| Save state screenshot gallery | SKIP | We use test_boot_auto for screenshots |

---

## 10. Consecutive ROM Read Tracking

### What they have (CDL_interface.cpp)

`libRR_log_rom_read(bank, offset, type, byte_size, bytes)` — Tracks sequential memory reads.
When reads are consecutive (previous_offset + 1 == current_offset), merges into a block.
Stored in `libRR_consecutive_rom_reads[bank][start_offset]` with total length and values.

**Purpose:** Discovers data structures and string accesses. A function that reads 256
consecutive bytes is probably loading a data table or processing a string.

| Feature | Verdict | Notes |
|---------|---------|-------|
| Consecutive read tracking | **MAYBE** | Interesting for discovering data table accesses |
| Block merging | **MAYBE** | Pattern: merge adjacent reads into data structure hints |

---

## 11. DMA Tracking

### What they have (N64.cpp)

**DMA transfer records** (`cdl_dma` struct):
- Source/dest addresses, length, frame number
- Associated function address
- ASCII header extraction (first bytes as text)
- Type guessing (assembly, audio, texture)
- TLB mapping for virtual addresses

**Functions:** `log_dma_write()`, `cdl_log_cart_rom_dma_write()`, `cdl_log_dma_sp_write()`,
`cdl_finish_pi_dma()`, `cdl_finish_si_dma()`, `cdl_finish_ai_dma()`.

**Audio DMA correlation:** `find_audio_sections()` cross-references DMA target addresses
with known audio buffer regions to auto-tag audio data.

| Feature | Verdict | Notes |
|---------|---------|-------|
| DMA transfer logging | **STEAL** | We have DMA-aware watchpoints, could log all DMA |
| DMA source/dest/length recording | **STEAL** | Reveals data flow patterns |
| Audio DMA correlation | **STEAL** | Cross-reference SCSP address range with DMA targets |
| DMA-to-function association | **STEAL** | Which function initiates each DMA? |

### Saturn DMA types to track

- **SH-2 DMA** (2 channels per CPU) — internal peripheral DMA
- **SCU DMA** (3 levels: L0, L1, L2) — main system DMA
- **VDP1 DMA** — texture/command VRAM transfers
- **CD block DMA** — disc data to WRAM

We already catch SCU DMA writes in watchpoints. Extend to log all DMA transfers
with source, destination, length, initiating PC.

---

## 12. String Detection

### What they have

**`get_strings_for_web(memory_name, offset, length)`** — Scans memory region for printable
ASCII sequences. Returns JSON of found strings.

**Consecutive ROM read tracking** (above) also surfaces string reads indirectly.

| Feature | Verdict | Notes |
|---------|---------|-------|
| ASCII string scanner | **STEAL** | Trivial to implement, high value for menu/UI code |

### How to implement

```python
def find_strings(data, min_length=4):
    """Scan binary data for ASCII strings."""
    strings = []
    current = bytearray()
    start = 0
    for i, b in enumerate(data):
        if 0x20 <= b <= 0x7E:
            if not current: start = i
            current.append(b)
        else:
            if len(current) >= min_length:
                strings.append((start, current.decode('ascii')))
            current = bytearray()
    return strings
```

---

## 13. Linker Map Import

### What they have (Setup.cpp)

**`upload_linker_map(linker_map)`** — Bulk-renames functions from symbol map. Two parsers:
1. Simple SYM format: `address = name`
2. GCC MAP format: section-based symbol tables

Looks up function by offset in existing `functions` map, updates name.

| Feature | Verdict | Notes |
|---------|---------|-------|
| Linker map import | SKIP | We already have daytona.map and symbol resolution |

---

## 14. Code Override / Patching

### What they have (Setup.cpp)

**`modify_override`** — JavaScript code patches stored in `overrides.json`. Each override has:
name, code, start address, end address, enabled flag, type.

Used for intercepting CD reads and replacing data.

| Feature | Verdict | Notes |
|---------|---------|-------|
| Runtime code patching | SKIP | We modify source directly (L3 override system) |
| CD data interception | SKIP | Not relevant for our approach |

---

## 15. Project Structure & Persistence

### What they have (Setup.cpp)

**Directory hierarchy:** `RE_projects/[Console]/[Game]/playthroughs/[name]/`

**JSON files per game:**
- `functions.json` — function catalog (persistent across playthroughs)
- `assembly.json` — disassembly data
- `called_functions.json` — call graph
- `long_jumps.json` — cross-module calls
- `notes.json` — annotations
- `consecutive_rom_reads.json` — ROM access patterns

**JSON files per playthrough:**
- `playthrough.json` — metadata, save states, last frame
- `function_usage.json` — per-playthrough function statistics
- `resources.json` — CD file listing
- `overrides.json` — code patches
- `button_log.bin` — input recording

| Feature | Verdict | Notes |
|---------|---------|-------|
| Persistent function database | **STEAL** | We have daytona.map but no per-function metadata DB |
| Per-function annotation storage | **STEAL** | Better than comments in .s files |
| Per-playthrough function usage stats | **MAYBE** | "Which functions are menu-only vs race-only" |
| Cross-session persistence | **STEAL** | We lose context between sessions |

### How to implement

JSON file: `build/function_db.json` — keyed by address, stores:
- name (current best guess)
- tags (hw_access, sdk_match, etc.)
- callers, callees
- memory read/write addresses
- frame ranges (which game states is it active in)
- notes/annotations
- confidence level

Updated by each tool run. Persists across sessions. Claude reads it at session start.

---

## 16. beetle-saturn Hardware Features

### Register access (sh7095.h, vdp1.h, vdp2.h, scu.h, scsp.h)

**Every register in the Saturn is individually readable/writable** via GetRegister/SetRegister:

**SH-2 CPU (per CPU):**
- R0-R15, PC, SR, GBR, VBR, MACH, MACL, PR
- IPRA, IPRB (interrupt priority)
- CCR (cache control)
- FRC, OCR0/1, FICR, TIER, FTCSR, TCR, TOCR (free-running timer)
- WTCSR, WTCNT, RSTCSR (watchdog timer)
- DMA0/1: SAR, DAR, TCR, CHCR, VCR, DRCR
- DVSR, DVDNT, DVDNTH, DVDNTL (divider unit)
- Pipeline: PC_ID, PC_IF, PID, PIF, EP, RPC

**SCU:**
- Interrupt levels, vectors, masks
- Timer T0/T1 count, compare, met flags
- DSP execution, pause, PC, end flags

**VDP1:**
- System/user clipping coords
- Local transform X/Y

**VDP2:**
- Line counter, display on, border mode, interlace
- Resolution (VRES, HRES)
- RAMCTL, BGON, MZCTL, SFSEL, SFCODE
- Per-layer scroll: SCXIN, SCXDN, SCYIN, SCYDN (x4 layers)
- Per-layer zoom: ZMXIN, ZMXDN, ZMYIN, ZMYDN
- Cycle control: CYCA0/1, CYCB0/1

**SCSP (Sound):**
- 32 voice channels with full AHDSR envelope
- LFO, DSP routing, slot monitor

| Feature | Verdict | Notes |
|---------|---------|-------|
| Full register access API | SKIP | Our automation has dump_regs already |
| VDP2 scroll position registers | **STEAL** | Live camera/viewport tracking during gameplay |
| SCSP slot monitoring | **MAYBE** | Could identify which sounds play when |
| SCU timer state | SKIP | Not useful for RE |

---

## 17. Debug Cart

### What they have (cart/debug.cpp)

Writes to 0x02100001 output characters to stderr. Printf-style debugging from game code.

| Feature | Verdict | Notes |
|---------|---------|-------|
| Debug cart | SKIP | Can't modify Daytona ROM |

---

## 18. Cartridge Types

### What they have (cart.h)

CART_BACKUP_MEM, CART_EXTRAM_1M/4M, CART_KOF95, CART_ULTRAMAN, CART_AR4MP, CART_CS1RAM_16M,
CART_NLMODEM, CART_MDFN_DEBUG.

| Feature | Verdict | Notes |
|---------|---------|-------|
| Action Replay cart emulation | **MAYBE** | AR codes are essentially watchpoint-and-patch |
| Extended RAM carts | SKIP | Daytona doesn't use them |

---

## Priority Summary

### STEAL (implement these)

1. **Save states** — automation.cpp commands, unblocks everything
2. **HW register function tagging** — static (grep L3) + dynamic (trace)
3. **Per-function memory R/W profile** — reveals each function's data footprint
4. **SDK signature extraction + matching** — extract from .A archives, scan binary
5. **Fuzzy matching (Jaro-Winkler)** — for prototype SDK differences
6. **String detection** — trivial, high value
7. **Memory differential pipeline** — dump → action → dump → diff
8. **DMA transfer logging** — source/dest/length/initiating-PC
9. **Persistent function database** — JSON, survives across sessions
10. **Coverage statistics** — "what % of code have we exercised"

### MAYBE (revisit later)

- Per-playthrough function usage stats
- Data visualizer (16bpp for VDP1 texture identification)
- Consecutive ROM read tracking
- VDP2 scroll register monitoring
- Binary struct parser
- Input recording/playback from file
- Action Replay cart for memory patching experiments
