# Free Build Emulator Compatibility

> **Status**: ACTIVE — first instruction-level divergence found via deterministic tracing
> **Real hardware**: TESTED (2026-02-19) — confirmed FAILS without SCDQ_FIX
> **Mednafen**: Boots to menu with SCDQ_FIX=1 + ICF_FIX=1 + CD_FIX=1 (corrupt graphics)
> **Current build**: `make free-disc` (SCDQ_FIX=1 + ICF_FIX=1 + CD_FIX=1)

---

## Current Focus: BIOS Copy Loop Divergence (2026-02-20)

### What We Found

Deterministic per-instruction tracing shows the first 901,454 unified trace
lines are **byte-identical** between retail and free builds. At line 901,455,
a **23-cycle timing delta** appears — the first observable difference.

The source: a **BIOS word-copy loop at `0x00002F00`** executes one extra
iteration in the free build.

```
00002F00: ADD  #4, R14      ; dest pointer += 4
00002F02: ADD  #1, R4       ; counter++
00002F04: MOV.L @R5, R3     ; load word from source
00002F06: MOV.L R3, @R14    ; store word to dest
00002F08: CMP/GE R11, R4    ; counter >= limit?
00002F0A: BF/S 00002F00     ; no -> loop
```

- **Retail**: Loop exits at cycle 72820 (BF/S falls through)
- **Free**: One more iteration, exits at cycle 72843 (+23 cycles)

**This is a DATA divergence.** The BIOS code is identical in both builds —
but some value in memory (the loop bound or source data) differs due to the
+4 byte shift. This is not a cache/timing artifact.

### Next Steps

1. **Identify the caller** — trace back from the loop to find who invoked this
   BIOS routine and what parameters (R4, R5, R11, R14) were passed
2. **Dump registers** — breakpoint at 0x00002F08 during this invocation,
   compare R11 (loop limit) between retail and free
3. **Find the source data** — R11 was loaded from some address; determine if
   it's in APROG.BIN shifted space or derived from shifted data
4. **Assess scope** — is this the root cause of corrupt graphics, or just the
   first of many cascading divergences?

### Trace Files

- `build/traces/retail_clean_run1_1000f.txt` — golden retail unified trace (146 MB)
- `build/traces/unified_free_nofixes_1000f.txt` — golden free unified trace (158 MB)
- `build/traces/insn_retail_wide.txt` — retail per-instruction trace, lines 901450-901460 (3.3 MB)
- `build/traces/insn_free_wide.txt` — free per-instruction trace, same window (3.3 MB)

### Tools

- `tools/unified_trace.py` — capture unified trace for any build
- `tools/capture_insn_traces.py` — capture per-instruction traces around divergence

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
