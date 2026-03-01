# Community Repo Study — What We Can Steal

Research from studying libRetroReversing, beetle-saturn-libretro, and Saturn-SDK-SGL (2026-03-01).

## libRetroReversing (N64.cpp = gold standard, Saturn.cpp = stub)

### SDK Signature Matching
- Collects byte pattern from function start → return during emulated playback
- Stores as `word_pattern` (instruction-level) and `bytes_with_branch_delay` (raw)
- Three-tier matching: library_signatures → game_signatures → unknown
- **Fuzzy matching** via Jaro-Winkler distance: >=95% auto-rename, 90-95% = `_predict_` prefix
- Signature DB stored as JSON keyed by byte pattern → function name

**Our adaptation**: We don't need runtime collection. We have the full binary AND compiled .A archives.
Extract patterns with `sh-elf-objdump -d`, scan APROG.BIN directly. Simpler, faster.

### Hardware Register Function Tagging
- Hooks every register read/write in emulator core
- Appends semantic tag to current function name: `_vdp1DrawAccess`, `_soundRegAccess`
- Tags: `_cartRegAccess`, `_dmaSiRead`, `_serialInterfaceRegAccess`, `_audioRegAccess`,
  `_rspRegRead`, `_manyMemoryReads`, `_manyMemoryWrites`
- Accumulates during playthrough — after replay, every function has its HW profile

**Our adaptation**: Add `hw_trace` command to automation.cpp. During execution, log
`{pc, hw_addr, read/write}` tuples. Post-process in Python to build per-function HW profiles.
Saturn HW ranges: VDP1 (0x25C/D), VDP2 (0x25E/F8), SCSP (0x25B), SMPC (0x201), SCU (0x25FE).

### Per-Function Memory Tracking
- `cdl_log_mem_write(addr, pc)` records every write address per function
- `cdl_log_mem_read(addr, pc)` records every read address
- Functions with many writes get tagged `_manyMemoryWrites`
- Write address set becomes the function's "memory fingerprint"

**Our adaptation**: Extend watchpoint to multi-address mode, or use hw_trace to capture
all memory accesses in a range. Per-function aggregation done in Python.

### Function Discovery via Playback
- Record gameplay: save states + button_log.bin
- Replay with hooks: every JSR/BSR intercepted by `libRR_log_function_call(pc, target, sp)`
- Auto-creates `cdl_labels` struct per function: name, size, signature, call map, memory profile
- Tracks call depth, return offsets, first/last frame seen, calls per frame

**Our adaptation**: We already have `call_trace` and `frame_calls_diff`. Their playback-based
discovery is essentially our call-trace with more metadata. We could add per-function stats
(first frame, call count, callee set) to our call trace output.

### Fuzzy Matching Algorithm
Jaro-Winkler distance on byte patterns. Useful when game links a slightly different version
of an SDK function (debug vs release, different optimization flags). The 90-95% threshold
for `_predict_` is clever — flags uncertain matches for human review.

**Our adaptation**: Worth implementing for SGL matching since Daytona '95 may use prototype
SGL that differs from the shipped SDK. Exact match won't work; fuzzy will.

---

## beetle-saturn-libretro (Mednafen fork for libretro)

### Memory Map (14 regions)
Full Saturn address space exposed via libretro memory descriptors:
- BOOTROM, SMPC, BACKUPRAM, LOWWRAM, SLAVEFRT, MASTERFRT
- CARTRIDGE, CS1RAM
- VDP1VRAM, VDP1FB_VISIBLE, VDP1FB_HIDDEN
- VDP2VRAM, VDP2CRAM
- HIGHRAM (0x06000000, our main interest)

**Our adaptation**: We already have `dump_mem_bin`. Could add named region shortcuts:
`dump_wram`, `dump_vdp1`, `dump_vdp2` — just convenience wrappers.

### Debug Mask System
Fine-grained logging via `ss_dbg_mask` bitfield:
- `SS_DBG_SH2`, `SS_DBG_SH2_REGW`, `SS_DBG_SH2_CACHE`
- `SS_DBG_SCU`, `SS_DBG_SCU_REGW`, `SS_DBG_SCU_INT`, `SS_DBG_SCU_DSP`
- `SS_DBG_VDP1`, `SS_DBG_VDP1_REGW`, `SS_DBG_VDP1_VRAMW`, `SS_DBG_VDP1_FBW`
- `SS_DBG_VDP2`, `SS_DBG_VDP2_REGW`
- `SS_DBG_SCSP`, `SS_DBG_SCSP_REGW`
- `SS_DBG_CDB`, `SS_DBG_CDB_REGW`
- `SS_DBG_SMPC`, `SS_DBG_SMPC_REGW`

**Our adaptation**: Our Mednafen fork could add similar category-based trace filtering.
When `hw_trace` is active, emit only categories the user cares about.

### Save State Infrastructure
Uses `SFORMAT` arrays — named variables with type info, versioned, per-module StateAction().
Functions: `MDFNSS_SaveSM()`, `MDFNSS_LoadSM()`.

**Our adaptation**: Mednafen already has this internally. We just need to expose
`save_state <path>` and `load_state <path>` in automation.cpp. Should be straightforward
since the serialization machinery exists.

### CPU Hook Infrastructure
`DBG_NeedCPUHooks()` and `DebugMode` template parameter in SH-2 step loop.
Currently disabled. When enabled, calls `DBG_CPUHandler<>()` every instruction.

**Our adaptation**: Our automation.cpp already has per-instruction hooks (breakpoints,
watchpoints, insn_trace). We're ahead here.

### Debug Cartridge
Maps 0x02100001 for character output. Game code writes bytes → appear on stderr.
Printf-style debugging from inside the game.

**Not useful for us**: We can't modify Daytona's ROM to add printf calls. This is for
homebrew development, not RE.

---

## Saturn-SDK-SGL (= tools/cygnus-2.7-96Q3/)

Already in our tree. Key finding: pre-compiled .A archives ready for extraction.

### Libraries with byte patterns we can extract:
- LIBSGL.A (342K) — master library
- LIBSPR.A (39K) — sprite/polygon rendering
- LIBSCL.A (67K) — scroll layers
- LIBMTH.A (19K) — math (sin/cos/matrix)
- LIBCD.A (113K) — CD access
- LIBGFS.A (51K) — file system
- SEGA_PER.A (8.9K) — input
- SEGA_SND.A (8.7K) — sound
- SEGA_DMA.A (9.2K) — DMA
- SEGA_INT.A (36K) — interrupts

### Function naming conventions (for matching):
SPR_, SCL_, MTH_, CDC_, GFS_, PER_, SND_, PCM_, DMA_, INT_, DSP_, DBG_, STM_

### Daytona caveat
AM2 first-party, 1995 launch title. May use:
- Prototype SGL (pre-release, different byte patterns)
- SBL (lower-level) for CD/input
- Completely custom rendering (AM2 was known for custom engines)
- Mix of SDK + custom code

Fuzzy matching (Jaro-Winkler from libRetroReversing) is essential here.

---

## Priority Actions (what to build)

### Tier 1: Low-effort, high-value
1. **Save states** in automation.cpp — unblocks everything else
2. **String detection** — scan APROG.BIN for ASCII, trivial Python script
3. **SDK signature extraction** — `sh-elf-objdump -d` on .A archives, build pattern DB
4. **Named memory dumps** — `dump_wram`, `dump_vdp1` convenience commands

### Tier 2: Medium-effort, high-value
5. **Memory scanner** — Python: scan WRAM dump for known values, delta scans
6. **HW register trace** — automation.cpp: log `{pc, hw_addr, r/w}` during execution
7. **SDK signature matcher** — Python: scan APROG.BIN against extracted patterns (exact + fuzzy)

### Tier 3: Higher-effort, exploratory
8. **Per-function memory profiling** — extend trace to record read/write sets per function
9. **Full-memory differential** — dump WRAM every frame, diff pipeline
10. **Playthrough recorder** — save state + input log for reproducible analysis sessions
