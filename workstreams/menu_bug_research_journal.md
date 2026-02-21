# Menu Bug Research Journal

**Bug**: SATURN MODE text missing from mode select screen in free build.
**Build**: `make disc`

## Background

In the free build (+4 shift), the mode select screen shows RANKING and OPTIONS correctly,
but SATURN MODE is invisible. VDP2 VRAM dumps show that SATURN MODE pattern name entries
(0x2C06, 0x2C07, 0x2C08) end up at the wrong VDP2 VRAM bank:

- **Prod**: 0x05E7E50C (bank B1 — correct, pattern name table area)
- **Free**: 0x05E05F0A (bank A0 — wrong, character pattern data area)

All input data (tile sources, flags, VDP2 base addresses, WRAM structures) appears
identical between builds. Only SATURN MODE is affected.

## Theories

| # | Theory | Status | Notes |
|---|--------|--------|-------|
| A | Wrong R4 (plane index) to tile writer | Untested | Would select wrong VDP2 plane/bank |
| B | Timing/init — VDP2 base not set yet | Untested | Writes happen before base address populated |
| C | Hardcoded constant in FUN_060196B0 | Untested | Raw bytes in constant pool (ICF-class bug) |
| D | Shifted data variable (sym_0605D242/D244) | Untested | Wrong branch in renderer due to stale read |
| E | VDP2 register config differs | Untested | Bank partition or map registers different |
| F | Correct write gets overwritten | Untested | Something clears/overwrites after render |
| G | Different code path writes SATURN MODE | Untested | Not sym_06028400 at all (DMA, other func) |

## Test Plan

1. **Watchpoint on 0x05E05F0A** (wrong address, free build) — find what writes there
2. **Watchpoint on 0x05E7E50C** (correct address, free build) — does anything write there?
3. **Capture sym_06028400 R4/R5/R6/R7** during mode select in both builds
4. **Temporal VDP2 snapshots** — dump VDP2 VRAM at multiple timepoints
5. **VDP2 register investigation** — check bank config registers

---

## Test Results

### Test 1: Watchpoint on 0x05E05F0A (wrong address in free build)

**Goal**: Find exactly what code writes SATURN MODE tiles to the wrong VDP2 VRAM location.
**Status**: COMPLETE — FALSE POSITIVE DEBUNKED
**Script**: `tools/debug_watchpoint_wrong_addr.py`

**Results**:

Also watched 0x05E7E50C in prod for comparison.

**PROD** writes to 0x05E7E50C (correct address, bank B1):
- 33 writes of 0x0000 (clearing) from PC=0x06004AEC/0x06004AF2, PR=0x06004AC0
- 33 writes of 0x0020 (spaces) from PC=0x0602854E, PR=0x0600A03C
- 33 writes of SATURN MODE tile indices (0x0BFE, 0x0BB8, 0x0BFF, 0x0C00, 0x0C01..0x0C10) from **PC=0x0602841E** (sym_06028400 tile writer), **PR=0x06008DC0**

**FREE** writes to 0x05E05F0A (bank A0):
- 33 writes of 0x0000 (clearing) from PC=0x06004AF0/0x06004AF6 (= prod + 4, correct)
- 65 writes of **CHARACTER PIXEL DATA** (0x3322, 0x3333, 0x2233, 0x5555...) from PC=0x060286FC, PR=0x06004FB6
- **These are NOT pattern name entries!** They are 4bpp character tile pixels being written to bank A0.

**Conclusion**: The earlier byte search that found pattern 0x2C06 0x2C07 0x2C08 at 0x05E05F0A in the free build was a **FALSE POSITIVE**. Those byte values coincidentally appeared in character pixel data. The free build is NOT writing SATURN MODE pattern names to the wrong address — it's simply not writing them at all (to be confirmed by Test 2).

**Impact on theories**: This doesn't prove/disprove any theory directly, but it fundamentally reframes the problem. The question is no longer "why do tiles go to the wrong place?" but rather **"does the free build write SATURN MODE tiles to the correct place, and if not, why?"**

### Test 2: Watchpoint on 0x05E7E50C (correct address in FREE build)

**Goal**: Does the free build ever write SATURN MODE tile indices to the correct VDP2 VRAM address?
**Status**: COMPLETE — YES, TILES ARE WRITTEN CORRECTLY
**Script**: `tools/debug_watchpoint_correct_addr.py`

**Results**:

Both builds write **IDENTICAL data** to 0x05E7E50C-0x05E7E54C:
- 33 zeros (clearing): prod PC=0x06004AEC/AF2, free PC=0x06004AF0/AF6 (+4 correct)
- 99 spaces (0x0020): prod PC=0x0602854E, free PC=0x06028552 (+4 correct)
- 33 SATURN MODE tiles: prod PC=0x0602841E, free PC=0x06028422 (+4 correct)

Tile values are IDENTICAL: 0x0BB8, 0x0BFC, 0x0BFF, 0x0C00, 0x0C01..0x0C13.
PR values: prod 0x06008DC0, free 0x06008DC4 (+4 correct).

**Conclusion**: The free build's tile writer (sym_06028400) works perfectly. It writes
the correct SATURN MODE tiles to the correct VDP2 VRAM address. The bug is NOT in the
writing path.

**Impact on theories**:
- A (Wrong R4): **DISPROVED** — same VDP2 address written in both builds
- B (Timing/init): **DISPROVED** — tiles written successfully to correct address
- C (Hardcoded constant): **DISPROVED** — all parameters correct
- D (Shifted data variable): **DISPROVED** — rendering path executes identically
- G (Different code path): **DISPROVED** — same tile writer function, same PR caller

**Remaining theories**:
- **E (VDP2 register config)**: MOST LIKELY — VDP2 hardware reads pattern names from
  a different VRAM address in the free build, so tiles at 0x05E7E000 are ignored
- **F (Overwrite)**: POSSIBLE — tiles written but subsequently erased. Note: 99 space
  writes vs 33 tile writes suggests 3 passes of space-fill. If one runs AFTER tiles...

### Test 3: VDP2 VRAM final state + register investigation

**Goal**: Check if tiles are still present in VDP2 VRAM when screenshot is taken.
Also attempt to read VDP2 registers to check scroll plane configuration.
**Status**: Running
**Script**: `tools/debug_vdp2_final_state.py`

