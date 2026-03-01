# Feature Harvest — Primary Source Analysis (Redo)

Date: 2026-03-01
Sources: local clones, actual code read (not READMEs)
- `D:\Projects\libRetroReversing` — full instrumentation framework
- `D:\Projects\beetle-saturn-libretro` — Saturn emulator fork
- `D:\Projects\Saturn-SDK-SGL` — SGL source for signature extraction

## beetle-saturn-libretro: Verdict

Mostly dead code. Exports raw memory pointers (WRAM, VRAM, CRAM) via libRetro
memory descriptors, but the registration call is never made. Debug cart UART stub
writes single bytes to stderr. No CDL, no call tracing, no memory logging.
Our Mednafen fork already exceeds this repo's capability.

Useful reference: their memory descriptor array documents which pointer gives
access to each Saturn memory region (14 entries). Informs our WRAM dump design.

## libRetroReversing: Features (from actual code)

### Code/Data Logging (CDL)
Source: `cdl/codeDataLogger.cpp`, `cdl/CDL_MemoryMapper.cpp`

Per-byte bitfield for entire address space:
- Bit 0: ExecFirst (executed as code)
- Bit 1: ExecOperand (instruction operand byte)
- Bit 2: Data (read or written as data)
- Bit 3: BlockEnd (function boundary)
- Bits 4-7: Graphics, BGMap, OAM, Sound (console-specific)

Tracks coverage %, produces diffs between snapshots, exports .cdl files.

### Function Call Tracing
Source: `cdl/CDL_interface.cpp`, `include/libRR.h`

Hooks JSR/BSR/JMP. Per-function record:
- callee set, caller set, call count, first/last frame
- read_addresses, write_addresses (every memory addr touched)
- function_bytes (raw bytecode = signature)
- return_offset_from_start (function size)

Uses `function_stack` vector + `previous_ra` for nesting/depth tracking.

### Memory Access Profiling
Source: `cdl/CDL_interface.cpp`

`cdl_log_mem_write(addr, pc)` / `cdl_log_mem_read(addr, pc)` count per-address
reads/writes. Produces heatmap. Threshold tags: `_manyMemoryReads` (>40 addrs),
`_manyMemoryWrites` (>40 addrs).

### DMA & Interrupt Logging
Source: `cdl/CDL_interface.cpp`

`libRR_log_dma(offset)` records DMA transfers. `libRR_log_interrupt_call(pc, target)`
logs ISR invocations. `cdl_dma` struct: source, dest, length, frame, function, type.
N64 impl also does audio DMA correlation (cross-ref SCSP addr range).

### Input Recording
Source: `cdl/InputLogger.cpp`

8 bytes/frame (64-bit button mask) → `button_log.bin`. Deterministic replay.
`libRR_resave_button_state_to_file()` for mid-stream edits.

### Save State + Screenshot
Source: `cdl/Setup.cpp`, `cdl/Image.cpp`

`libRR_create_save_state_c(name, frame, fast_save)` — serialize + PNG screenshot.
States named by frame, grouped by playthrough. lodepng for PNG encoding.

### SDK Signature Matching
Source: `consoles/N64.cpp:681-903`

At function return, collects bytes entry→return = `function_bytes`. Three-tier DB:
library_signatures (known SDK), game_signatures (already-IDed), function_signatures
(unknown). Jaro-Winkler fuzzy: >=95% auto-rename, 90-95% `_predict_` tag.

### Instruction Disassembly Logging
Source: `cdl/CDL_interface.cpp`

`libRR_log_instruction(pc, name, bytes, num_args, ...)` — logs every instruction.
Overloaded for 0-4 operands. Stored in `libRR_disassembly` JSON. Per-console formatters.

### CD/Disc Access Tracking
Source: `cdl/CD.cpp`

ISO 9660 parser. `libRR_log_cd_access(lba)` logs block reads. Tracks consecutive
reads (`consecutive_rom_reads`). Outputs file tree + access heatmap.

### Persistent Function Database
Source: `cdl/CDL_JSON.cpp`, `cdl/Setup.cpp`

JSON DB per game: `functions.json` (master catalog), `assembly.json`, `called_functions.json`,
`notes.json`. Per-playthrough: `function_usage.json`, `button_log.bin`, `overrides.json`.
Survives across sessions.

### HW Register Tagging
Source: `consoles/N64.cpp:946-1011`

`add_tag_to_function(tag, labelAddr)` — appends semantic tag when function accesses
HW registers. Tags: `_piRegRead`, `_rspRegWrite`, `_audioRegAccess`, `_serialInterfaceRegAccess`, etc.

### JavaScript Scripting
Source: `cdl/Interpreter.cpp`

Duktape (ES5.1) and MJS (lightweight + FFI). Exposes: `libRR_get_current_lba()`,
`libRR_memset()`, `libRR_replace_lba_buffer()`. Used for CD content override.

### Source Export
Source: `source_exporter/CommonSourceExport.cpp`

Generates per-function .asm files with labels, comments, section headers.
Template system per platform (GameBoy RGBDS, NES/SNES WLA-DX).

### Web UI
Source: `websrc/` (React + TypeScript)

13 pages including function list, hex viewer, data visualizer (8 render modes:
1bpp/2bpp/8bpp/16bpp-RGB/BGR/24bpp/32bpp/digraph), input editor, save state gallery.
Civetweb HTTP server bridges C++ backend to browser.

### Data Structure Parser
Source: `websrc/pages/DataVisualiser/`

Define structs in JSON, parse memory at address. Uses `binary-parser` JS library.

## Feature List: What to Build

### Already Built (have equivalent)

| Feature | Our equivalent | Status |
|---------|---------------|--------|
| String detection | tools/string_scan.py | Done |
| HW register tagging (static) | tools/hw_tag.py | Done |
| SDK signature matching | tools/sdk_match.py | Done |
| Save states | automation.cpp save_state/load_state | Done |
| Input replay | tools/investigate.py replay_to_state() | Done |
| Symbol DB | reimpl/build/daytona.map + pool labels | Done |
| Cross-references | tools/xref.py | Done |
| DMA analysis (static) | tools/dma_analysis.py | Done |

### To Build — Emulator-Side (C++ in Mednafen)

| # | Feature | What it does | Priority |
|---|---------|-------------|----------|
| E1 | ~~WRAM dump command~~ | ~~Dump 1MB high WRAM (0x06000000-0x060FFFFF) to file. Also low WRAM, VDP VRAM.~~ | **DONE** |
| E2 | ~~Code/Data Logging~~ | ~~Per-byte bitfield: code vs data. Hooks instruction fetch + memory access. Coverage %.~~ | **DONE** |
| E3 | ~~Runtime DMA logging~~ | ~~Hook SCU DMA start. Log source/dest/length/initiating-PC for every transfer.~~ | **DONE** |
| E4 | ~~Memory write profiling~~ | ~~Log {pc, target_addr, value} for writes to configurable address ranges.~~ | **DONE** |
| E5 | Interrupt logging | Log ISR entry: vector, PC at interrupt, frame number. | LOW (skipped — non-regular exceptions already logged to stderr) |
| E6 | ~~Full execution trace~~ | ~~Log every instruction (PC + opcode). Expensive, use for short windows.~~ | **DONE** (pre-existing: insn_trace, pc_trace_frame) |

### To Build — Host-Side (Python)

| # | Feature | What it does | Priority |
|---|---------|-------------|----------|
| H1 | ~~Memory scanner~~ | ~~Cheat Engine-style: scan WRAM dump for value. 8/16/32-bit, endian, delta.~~ | **DONE** |
| H2 | ~~Memory diff pipeline~~ | ~~Dump before/after event → diff → changed regions with symbol resolution.~~ | **DONE** |
| H3 | ~~Persistent function DB~~ | ~~JSON DB aggregating all tool outputs. Survives across sessions.~~ | **DONE** |
| H4 | ~~Coverage reporter~~ | ~~From CDL data: what % of binary is code, what % exercised.~~ | **DONE** |
| H5 | ~~Data structure parser~~ | ~~Define structs, parse WRAM dump at offset. Visualize game state.~~ | **DONE** |

### Skip (not useful for us)

| Feature | Why |
|---------|-----|
| Web UI | Claude is our UI |
| JS scripting | We have Python + C src/ overrides |
| Source export | We have full L3 assembly |
| CD access tracking | We know the disc layout |
| Input recording to file | We control input programmatically |
| libRetro memory descriptors | We use Mednafen directly |
| Debug cart | Can't modify Daytona ROM |
| Action Replay cart | Not needed |

## Recommended Build Order

**Phase 1: Unblock dynamic analysis** (E1 → H1 → H2)
1. E1: WRAM dump command — everything else depends on this
2. H1: Memory scanner — find speed/gear/lap/position by value
3. H2: Memory diff — find what changes when events happen

**Phase 2: Code coverage** (E2 → H4)
4. E2: Code/Data Logging in Mednafen
5. H4: Coverage reporter

**Phase 3: Deep instrumentation** (E3 → E4 → H3 → H5)
6. E3: Runtime DMA logging
7. E4: Memory write profiling
8. H3: Persistent function DB
9. H5: Data structure parser

**Phase 4: Nice-to-haves** (E5 → E6)
10. E5: Interrupt logging
11. E6: Full execution trace

## Total: 11 features (6 emulator + 5 host)
Phase 1 (3 features) unblocks Strategy B (known-value hunting) and Strategy C (memory differential).
