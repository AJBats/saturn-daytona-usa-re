# Free Build Emulator Compatibility

> **Status**: ACTIVE — all bypasses eliminated or made permanent
> **Real hardware**: TESTED (2026-02-19) — confirmed FAILS without SCDQ timeout
> **Mednafen**: Boots to title screen, mode select works, can race laps
> **Current build**: `make disc` (free-layout default, FUN_060423CC reimplemented in C)

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

## Call-Level Trace Analysis (2026-02-20)

Compared 5.34M retail vs 5.83M free master SH-2 call events across 1000 frames.

### Phase 1: Identical (calls 0 – 918,440)

918K calls with zero structural divergence. Only cycle timing differs.

### Phase 2: SCDQ Timing Jitter (calls 918,440 – 2,052,177)

177 events where free does 1-3 extra iterations of the HIRQREQ bit 10 (SCDQ)
polling loop in FUN_060423CC. Always reconverges. Cumulative drift: ~451 extra
poll iterations across 1.1M calls. **Entirely benign** — hardware timing jitter
from the asynchronous CD block.

FUN_060423CC decoded: polls HIRQREQ (0x25890008) via sym_06035C4E (MOV.W @R0,R0),
masks with 0x0400 (SCDQ bit), loops until set, then calls FUN_06035C54 to clear
SCDQ and returns. R14=0x0400 (mask), R13=0xFBFF (~mask).

### Phase 3: The SCDQ Hang (call 2,052,177)

At retail call 2,052,177: retail calls `(06040B64 -> 060411A0)` and continues booting.
Free enters `(0603BDCE -> 0603EFD8)` — the CD command handler near FUN_0603B424.
Three calls later, free enters FUN_060423CC's SCDQ poll and **never exits**.

Root cause chain:
1. +4 shift causes cumulative timing jitter (cache misses + SCDQ poll drift)
2. CD block is in a different state when free reaches the critical CD operation
3. FUN_0603B424's PAUSE handler has a latent bug (only proceeds when buffer empty)
4. Free enters the bug path, retail avoids it by timing
5. SCDQ never fires in PAUSE state — infinite hang

**SCDQ_FIX patches this exact path.** With the fix, free boots past this point.

### Deprioritized Divergences

Things we've examined in traces and set aside — real but not the boot failure cause.

- **Cache timing drift**: +7/-12/-13/-2 over 579K insns — bounces both directions, nearly washes out. Not systematic.
- **BIOS SLEEP loop** at 0x0000052E: retail does +1 iteration vs free. Same class as BIOS copy loop (timing-dependent iteration count, not structural).
- **BIOS copy loop** at 0x00002F00: +1 iteration in free (+23 cycles). Eliminated by padding retail binary.
- **Opcode streams**: structurally identical across 579K instructions in window 903535-903545 (only BIOS SLEEP differs).

---

## Bypass Status

All bypasses eliminated or made permanent. ICF_FIX, SATURN MODE bug, and CD_FIX have been **eliminated**. SCDQ timeout is now a permanent C reimplementation.

| Issue | What Was Done | Root Cause | Status |
|-------|-------------|------------|--------|
| ~~`ICF_FIX=1`~~ | ~~NOPs master's FTCSR poll BF~~ | Missed cache-through relocation in FUN_06034F08 | **FIXED** (2026-02-20), patch deleted |
| (no bypass) | SATURN MODE missing from mode select | False-positive pointer at sym_06049AEC | **FIXED** (2026-02-20) |
| FUN_060423CC | SCDQ poll timeout (1000 iterations) | FUN_0603B424 PAUSE handler bug — SCDQ never fires in PAUSE | **PERMANENT** C reimpl in `src/` |
| ~~`CD_FIX=1`~~ | ~~Widens PAUSE→Calculate in FUN_0603B424~~ | Redundant with SCDQ timeout (same timing issue) | **RETIRED** (2026-02-21), patch deleted |

### ICF_FIX Root Cause Fix

The slave's main loop (FUN_06034F08) reads the callback pointer from sym_06063574
using a **hardcoded cache-through address** `0x26063574` in its constant pool. This was
encoded as raw `.byte` directives and was NOT processed by the relocation scanner (which
only detected `0x06xxxxxx`-range pointers).

In the free build (+4 shift), sym_06063574 relocates to `0x06063578`, but the hardcoded
`0x26063574` stays stale. The slave reads from the wrong address, gets garbage, jumps to
data at `0x06000250`, hits SLOT_ILLEGAL in the BIOS table area, and enters the exception
handler's panic loop — never writing SINIT. The master waits forever.

**Fix**: Replace `.byte 0x26, 0x06 / .byte 0x35, 0x74` with `.4byte sym_06063574 + 0x20000000`.
This is byte-identical in retail (`0x06063574 + 0x20000000 = 0x26063574`) and correctly
relocates in free build (`0x06063578 + 0x20000000 = 0x26063578`).

**Result**: Clean title screen with no ICF_FIX. Slave completes per-frame geometry work
and writes SINIT correctly.

---

## ICF Root Cause: Cross-CPU MINIT/SINIT Sync (2026-02-20)

### The Mechanism (NOT VBLANK)

ICF (FTCSR bit 7) in Daytona USA is **not driven by VDP VBLANK**. It is a
**cross-CPU synchronization flag** using the MINIT/SINIT hardware:

```
Master (FUN_0600BFFC):                 Slave (FUN_06034F08):
  Store FUN_0600C170 → sym_06063574      Polling own FTCSR ICF...
  Write 0xFFFF to 0x21000000 (MINIT) ──→ Slave ICF fires!
  Poll own FTCSR ICF...                  Call FUN_0600C170 (callback)
                                         ... per-frame slave work ...
                                         Write 0xFFFF to 0x21800000 (SINIT)
  Master ICF fires! ←──────────────────
  Continue to next frame
```

**Mednafen implementation** (ss.cpp:322-341): Writes to 0x01000000-0x01FFFFFF
trigger `CPU[c].SetFTI(true)` then `SetFTI(false)`. The CPU index is determined
by address bit 23: MINIT (bit 23=0) → slave, SINIT (bit 23=1) → master.
SetFTI edge-triggers ICF based on TCR bit 7 (edge direction).

### Evidence

1. **FUN_0600BFFC** (WIP decompile, line 93): `*(volatile short *)0x21000000 = 0xFFFF`
   This is the MINIT write. Cache-through 0x21000000 = physical 0x01000000.

2. **FUN_06034F08** (slave main loop): Polls FTCSR ICF (offset 0x2C-0x38),
   reads callback pointer from sym_06063574 via cache-through (0x26063574),
   calls callback, clears pointer, loops.

3. **FUN_0600C170** (slave callback): Returns with `MOV.W R2, @R3` in delay slot
   where R2=0xFFFF, R3=0x21800000 (SINIT). This is the write that sets master ICF.

### Why ICF Hangs in Free Build

The master's ICF poll hangs because the **slave SH-2 never writes SINIT**.
FUN_0600C170 (the slave callback) calls several functions during its execution.
If any of them hangs on the slave (due to timing differences from the +4 shift),
SINIT is never written and the master waits forever.

The slave executes the SAME shifted binary from HWRAM but with its own
independent cache. Different cache warm-up on the slave could cause different
timing behaviors than the master.

### Why ICF_FIX Causes Corrupt Graphics

ICF_FIX NOPs the `BF` in the master's ICF poll (FUN_0600C010:127), making it
fall through immediately instead of waiting. This means the master proceeds
to the next frame **before the slave finishes its per-frame work**. Since the
slave handles geometry calculations and other frame prep, the master rendering
with incomplete data produces visual corruption.

### Resolution (2026-02-20)

Root cause was NOT a timing race or slave hang — it was a **missed relocation**.
The constant pool in FUN_06034F08 contained a hardcoded cache-through address
`0x26063574` (raw `.byte` directives) that was not caught by the relocation scanner.
Fixed by replacing with `.4byte sym_06063574 + 0x20000000`.

### Lessons Learned

1. **Cache-through pointers are a relocation class.** The `0x26xxxxxx` mirror of WRAM
   High (`0x06xxxxxx`) must be relocated when code shifts. The relocation scanner only
   caught `0x06xxxxxx`-range values; `0x26xxxxxx` was invisible to it.
2. **This was the ONLY cache-through pool pointer in the codebase.** All other `.byte 0x26, 0x0X`
   occurrences are SH-2 instructions (AND, OR, XOR) or data table entries.
3. **The fix is byte-identical in retail.** `sym + 0x20000000` produces the same bytes
   when the symbol resolves to its original address.

---

## SCDQ Root Cause (archived, 2026-02-19)

The SCDQ hang is a **latent bug in `FUN_0603B424`** (CD state machine).
When the +4 shift changes SH-2 execution phase relative to disc operations,
TABLE.BIN sectors get pre-buffered in PAUSE state. The PAUSE handler only
proceeds when `GetBufSize == 1` (empty buffer), creating an infinite retry loop.

`SCDQ_FIX=1` prevents this by shortening the SCDQ poll so the disc doesn't
advance past TABLE.BIN's end FAD. `CD_FIX=1` was an alternate attempt that
widened the PAUSE→Calculate condition, but was redundant with SCDQ_FIX and
had a secondary bug (fires during APROG.BIN load). **CD_FIX retired 2026-02-21.**

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
- 2026-02-20: Cache line +7 cycle mechanism proven at FUN_060030FC D312
- 2026-02-20: Call-level trace analysis: 177 benign SCDQ jitter events, then permanent hang at call 2,052,177
- 2026-02-20: SCDQ hang fully traced: FUN_060423CC polls HIRQREQ bit 10 (0x25890008), CD block in PAUSE state
- 2026-02-20: SCDQ_FIX argument width mismatch (0xFFFFFBFF vs 0x0000FBFF) — verified HARMLESS (MOV.W truncates)
- 2026-02-20: **ICF BREAKTHROUGH**: ICF is NOT VDP VBLANK — it's cross-CPU sync via MINIT/SINIT
- 2026-02-20: Decoded slave main loop (FUN_06034F08) and callback (FUN_0600C170)
- 2026-02-20: ICF hang = slave never writes SINIT; ICF_FIX = skip wait → corrupt graphics
- 2026-02-20: **ICF ROOT CAUSE FOUND**: Missed cache-through relocation at FUN_06034F08 pool[0x6C]
- 2026-02-20: **ICF FIX**: `.4byte sym_06063574 + 0x20000000` — byte-identical retail, correct free
- 2026-02-20: **ICF_FIX ELIMINATED**: Free build boots to clean title screen with SCDQ_FIX=1 + CD_FIX=1 only
- 2026-02-20: ICF hang = slave never writes SINIT; ICF_FIX = skip wait → corrupt graphics
- 2026-02-20: Mednafen FTI trigger: ss.cpp:322-341, SetFTI edge-detection in sh7095.inc:1046-1076
- 2026-02-20: **SATURN MODE FIX**: .4byte loc_0606060A at sym_06049AEC was byte data, not a pointer
- 2026-02-20: Root cause: bytes `06 06 06 0A` = VDP2 tile coords, read by MOV.B; relocation changed 0A→FE
- 2026-02-20: Fix: `.byte 0x06, 0x06, 0x06, 0x0A` prevents relocation; mode select now shows all 4 items
- 2026-02-21: **CD_FIX RETIRED**: Redundant with SCDQ_FIX — tested SCDQ_FIX=1 alone, raced laps successfully
- 2026-02-21: **ICF_FIX patch deleted**: Root cause was fixed in ASM (cache-through relocation), patch obsolete
- 2026-02-21: Build simplified to `make free-disc SCDQ_FIX=1` — one bypass remains
- 2026-02-21: **BUILD SYSTEM RESTRUCTURED**: `retail/` for Sega originals, `src/` for reimpl. Default `make` = free build.
- 2026-02-21: SCDQ_FIX flag eliminated — FUN_060423CC.c moved to `src/` as permanent C reimplementation
- 2026-02-21: Linker scripts renamed: sawyer.ld → sega.ld, sawyer_free.ld → free.ld
- 2026-02-21: +4 shift made optional: `make disc` = no shift (default), `make disc-4shift` = +4 validation
