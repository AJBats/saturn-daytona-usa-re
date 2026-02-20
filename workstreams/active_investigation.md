# Free Build Emulator Compatibility

> **Status**: ACTIVE — cache line +7 cycle mechanism proven at one site; global impact TBD
> **Real hardware**: TESTED (2026-02-19) — confirmed FAILS without SCDQ_FIX
> **Mednafen**: Boots to menu with SCDQ_FIX=1 + ICF_FIX=1 + CD_FIX=1 (corrupt graphics)
> **Current build**: `make free-disc` (SCDQ_FIX=1 + ICF_FIX=1 + CD_FIX=1)

---

## Root Cause: SH-2 Cache Line Boundary Alignment (2026-02-20)

### The Problem

The +4 byte code shift changes the alignment of **data reads relative to
16-byte cache line boundaries**. This causes some literal pool loads that
were cache hits in retail to become cache misses in the free build (and
vice versa). Each extra cache miss costs exactly **7 cycles** on the shared
`SH7095_mem_timestamp` bus. These timing deltas compound throughout execution.

### Proof: FUN_060030FC Prologue

The first timing divergence after eliminating the BIOS copy loop difference
occurs at unified trace line 903,540 in the `FUN_060030FC` (system_init)
prologue. Four consecutive `MOV.L @(disp,PC),Rn` instructions load from
the literal pool:

| Instruction | Retail ea | Free ea | Cache line | Result |
|---|---|---|---|---|
| DA10 (R10) | 0x06003150 | 0x06003154 | 0x50-0x5F | Miss (both) |
| DB11 (R11) | 0x06003154 | 0x06003158 | 0x50-0x5F | Hit (both) |
| DD11 (R13) | 0x06003158 | 0x0600315C | 0x50-0x5F | Hit (both) |
| D312 (R3)  | 0x0600315C | **0x06003160** | 0x50-0x5F / **0x60-0x6F** | Hit/MISS |

In retail, all 4 loads fit in cache line 0x50-0x5F. In free, D312 crosses
into 0x60-0x6F — an extra cache miss costing +7 cycles.

**Evidence:**
- **CCR = 0x01** (cache enable bit) — BIOS enables cache before game code runs
- **Trace**: memts unchanged after DB11/DD11 (cache hits). After D312:
  retail memts +1 (hit), free memts +8 (miss).
- **Arithmetic**: `(PC & ~3) + disp*4` shifts by +4 when code shifts by +4,
  pushing D312's ea from 0x0600315C to 0x06003160 across the line boundary.

### Implications

This is NOT fixable by patching individual functions. The +4 shift changes
cache alignment for ALL literal pool accesses throughout the entire binary.
The cumulative timing drift is unpredictable and non-uniform:
- Some functions gain cache misses (slower)
- Some functions lose cache misses (faster)
- The net effect: execution timing drifts, CD timing races change, and
  time-sensitive code (like the SCDQ poll and TABLE.BIN loading) breaks.

### Possible Solutions

1. **Pad to 16-byte alignment**: Instead of +4, pad to the next 16-byte
   boundary so literal pool alignment is preserved. (Would need to verify
   this eliminates the cache effect — might shift alignment differently.)
2. **Cache-aware linker**: Place each function at an address that preserves
   its original cache line alignment for literal pool accesses.
3. **Accept the timing difference**: Some timing drift is inevitable with
   any code movement. The key question is whether the game can tolerate it.

### Previous Divergence: BIOS Copy Loop (line 901,455)

The very first divergence in the unified trace is a BIOS word-copy loop at
`0x00002F00` that does +1 iteration in the free build (+23 cycles). This is
caused by the +4 byte size difference in APROG.BIN being passed to the BIOS
loader. This was eliminated by using a "padded retail" binary (retail + 4
zero bytes at end) to match the free build size.

### Trace Files

- `build/traces/insn_padded_retail_903535_903545.txt` — padded retail with per-instruction detail (179 MB)
- `build/traces/insn_free_903535_903545.txt` — free build with per-instruction detail (182 MB)
- `build/traces/unified_padded_retail_1000f.txt` — padded retail call-level trace (144 MB)
- `build/traces/unified_free_nofixes_1000f.txt` — free call-level trace (157 MB)

### Tools

- `tools/capture_insn_traces.py` — capture per-instruction traces around divergence
- `tools/process_free_trace.py` — normalize free trace addresses for comparison

---

## Bypass Status

Three bypasses are needed to boot the free build to menu. All are workarounds,
not root-cause fixes.

| Bypass | What It Does | Root Cause |
|--------|-------------|------------|
| `ICF_FIX=1` | Skips slave SH-2 FUN_0600C170 init | Wrong init data from +4 shift |
| `SCDQ_FIX=1` | Shortens SCDQ poll (timeout 1000 iterations) | TABLE.BIN timing race (see below) |
| `CD_FIX=1` | Widens PAUSE→Calculate in FUN_0603B424 | Pre-buffered sectors in PAUSE state |

---

## SCDQ Root Cause (archived, 2026-02-19)

The SCDQ hang is a **latent bug in `FUN_0603B424`** (CD state machine).
When the +4 shift changes SH-2 execution phase relative to disc operations,
TABLE.BIN sectors get pre-buffered in PAUSE state. The PAUSE handler only
proceeds when `GetBufSize == 1` (empty buffer), creating an infinite retry loop.

`SCDQ_FIX=1` prevents this by shortening the SCDQ poll so the disc doesn't
advance past TABLE.BIN's end FAD. `CD_FIX=1` widens the PAUSE→Calculate
condition but has a secondary bug (fires during APROG.BIN load too — needs
`ctx[0x12]` guard). Both are workarounds.

Full analysis: `workstreams/research/03_bugs_found.md`,
`workstreams/scdq_hypothesis_2.md`, `workstreams/research/06_cd_fix_implementation.md`.

---

## Log

- 2026-02-18: SCDQ investigation reopened after make disc bug discovered
- 2026-02-18: Makefile hardened — `make disc` no longer rebuilds
- 2026-02-19: Real Saturn test — free build (ICF only) FAILS to boot (confirmed real bug)
- 2026-02-19: Root cause identified — FUN_0603B424 PAUSE handler, TABLE.BIN timing race
- 2026-02-19: CD_FIX attempt — has secondary bug (fires on APROG.BIN load)
- 2026-02-19: Comprehensive research directory created: `workstreams/research/`
- 2026-02-20: Deterministic trace infrastructure built (unified + per-instruction)
- 2026-02-20: First instruction-level divergence found — BIOS copy loop, +1 iteration in free build
