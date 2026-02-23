# Disc File Reverse Engineering

> **Status**: COMPLETE — hypothesis disproven
> **Goal**: Understand what TABLE.BIN and SCROLL.BIN contain, how APROG.BIN uses their data,
> and whether offset-based references back into APROG.BIN break under the +4 shift.
>
> **Result**: No offset-based references found. All internal APROG.BIN pointers are properly
> relocated (5,027 correct, 0 real bugs). The disc files contain pure game data (track geometry,
> VDP2 scroll graphics) with no back-references into APROG.BIN code or data.

---

## Findings Summary

### Hypothesis: DISPROVEN

The disc files do NOT contain offset-based references into APROG.BIN. The corrupt graphics
in the free build are NOT caused by unrelocated disc file references.

Evidence:
1. TABLE.BIN entries are 16-bit indices into track geometry arrays — NOT APROG.BIN offsets
2. SCROLL.BIN data is VDP2 scroll plane graphics loaded to fixed addresses — no metadata
3. All 5,027 internal APROG.BIN pointer references are properly relocated via `.4byte SYM_`
4. `find_unrelocated.py` confirms: 15 "unrelocated" values are all false positives (bitmasks, packed constants)
5. The lookup arrays that TABLE.BIN indexes into contain Work RAM Low addresses (0x002xxxxx), not APROG.BIN addresses

### What's Still Unknown: Corrupt Graphics Root Cause

The free build boots to menu with corrupt graphics. Since relocation is confirmed clean,
the remaining hypotheses for corrupt graphics are:

1. **Bypass side effects** — SCDQ_FIX skips CD data waits → data may not be fully loaded when used
2. **ICF bypass race conditions** — secondary SH-2 runs unsynchronized → VDP writes may conflict
3. **Timing-dependent initialization** — bypasses change the frame timing of when data becomes available
4. **VDP register setup timing** — scroll plane init at FUN_06012F80 may run before SCROLL.BIN is loaded

**Key test needed**: Force SCDQ+ICF bypasses into production binary (no +4 shift). If production
ALSO shows corrupt graphics with bypasses → it's the bypasses, not the shift. If production is
clean with bypasses → something specific to the +4 shift causes corruption.

---

## TABLE.BIN: Complete Analysis

### Structure (28,448 bytes)

Three distinct sections:

| Section | Offset | Size | Content |
|---------|--------|------|---------|
| 1 | 0x0000-0x1FFF | 8,192 bytes | 4,096 monotonically increasing 16-bit values (stride ~39) |
| 2 | 0x2000-0x4F23 | 12,068 bytes | Complex sub-arrays, oscillating 0→0xFFxx→0 |
| 3 | 0x4F24-0x6F1F | 8,188 bytes | 2,047 signed 32-bit values (-100, -201, -301...) |

### Load Destination

**TABLE.BIN → 0x002F0000** (Work RAM Low)

Loaded by `FUN_06012E6A`:
```asm
mov.l  r5, 0x2F0000       ; dest = Work RAM Low
mov.l  r4, sym_0604499C   ; "TABLE.BIN"
bsr    FUN_06012C3C        ; load file
```

### Consumer 1: FUN_06006CDC — Tile/Segment Renderer

**Address range**: 0x06006CDC - 0x06006F2C (593 bytes)
**Section used**: Section 2 (offset +0x2000)
**Row stride**: 242 bytes (0xF2)

This is a **VDP2 scroll tile rendering function** that:
1. Computes a row pointer: `0x002F0000 + 0x2000 + row_index * 242`
2. Iterates over an 11×11 grid (with boundary clamping at 5/59/69)
3. Reads 16-bit entries from the grid
4. Uses non-zero entries as indices into lookup arrays at `0x06062248` and `0x06062260`
5. The lookup arrays contain **Work RAM Low addresses** (0x002xxxxx) pointing into SCROLL.BIN data
6. Dispatches to `FUN_0602ABB8` or `FUN_0602B9E0` for actual drawing (selected by state index)

**Key data flow**:
```
TABLE.BIN entry (16-bit) → index into 0x06062248 array → Work RAM Low pointer → draw routine
```
No APROG.BIN addresses are computed. The TABLE.BIN values are pure geometry indices.

### Consumer 2: FUN_06011AF4 — Block Transfer/Conversion

**Address range**: 0x06011AF4 - 0x06011DBC (~712 bytes)
**Uses TABLE.BIN base (0x002F0000) for pointer arithmetic**

This function:
1. Takes TABLE.BIN base as argument (r6 = 0x002F0000)
2. Computes relative offsets: `neg r8, r4` → `r4 = -0x002F0000`
3. Calls `FUN_06027552` with both raw base and negated base for offset calculations
4. Extracts 6 coordinate fields per call, stores as 16-bit values in 24-byte records at `0x060786CC`
5. Increments record counter at `0x0605AAA0`

**No APROG.BIN addresses computed.** Pure data extraction from TABLE.BIN.

### 0x60274F0 Reference: FALSE POSITIVE

The `002F` bytes at 0x60274F0 are MAC instruction encodings in a math library function, not a TABLE.BIN pointer.

---

## SCROLL.BIN: Complete Analysis

### Structure (327,736 bytes)

Pure VDP2 scroll plane graphics data — tile patterns, color data, scroll maps.

### Load Destination

**SCROLL.BIN → 0x002A0000** (Work RAM Low)

### 8 Reference Locations in APROG.BIN

| # | Address | Type | Usage |
|---|---------|------|-------|
| 1 | 0x06003654 | Init param table | Base address in early init structure |
| 2 | 0x06003B1C | DMA/file table | Source address among other 0x002Axxxx entries |
| 3 | 0x06007444 | Constant pool | DMA copy: source=0x002A3457 → dest=0x0606B178 |
| 4 | 0x0600EDC4 | Constant pool | Offset-based reads: +0x3027, +0x325B with size 0x738 |
| 5 | 0x06012E3C | Constant pool | File registration with loader FUN_06012C3C |
| 6 | 0x06012E94 | Constant pool | File registration (different dest struct) |
| 7 | 0x060130BC | Constant pool | **Main consumer**: FUN_06012F80 scroll plane init |
| 8 | 0x0601B288 | Config table | Alternate game state scroll config |

### Primary Consumer: FUN_06012F80 — Scroll Plane Initialization

The main scroll init routine:
1. Stores `0x002A0000` in r14 as persistent base
2. Repeatedly calls `FUN_06007658` with: `r7 = base + offset`, `r5 = size`, `r4 = plane_index`
3. Loads scroll plane data at offsets: 0x299B, 0x29A3, 0x2A53, 0x2B27, 0x2E73, 0x2F93...
4. Each chunk has a specific size (0x108, 0x810, 0x512, 0x83C, 0x519...)

**All offsets are into SCROLL.BIN (0x002A0000 base), not into APROG.BIN.**

---

## Relocation Verification

### find_unrelocated.py Results (production vs free binary)

```
Relocated +4:      5,027 (correct)
Unrelocated:          15 (ALL false positives)
Data/constant:    93,619 (not in code range, fine)
```

The 15 "unrelocated" values:
- 3 bitmask constants in code: `0x0601FFFF`, `0x0600FFFF`, `0x0602FFFF`
- 9 packed block IDs in data: `0x06010001`, `0x06030003`, `0x06050005` (×3 each)
- 3 packed constants: `0x06050605`, `0x06060C0D`, `0x06020007`

**Zero real unrelocated pointers.** The linker script properly relocates all 5,027 internal references.

### Data Section Deep Scan

Scanned FUN_06046E48.s (59,764 lines, 116KB data section):
- 1,060 `.4byte SYM_/FUN_/DAT_/loc_` references (properly relocatable)
- 5 `.4byte dat_` references (also symbolic, just lowercase)
- 957 binary values in APROG.BIN range → 940 are already `.4byte SYM_`, 17 are false positives

---

## File Name Table

Discovered at 0x060448C8 in APROG.BIN — complete filename table for all disc assets:

```
sym_060448C8: "APROG.BIN"      sym_060448E8: "CS1POLY.BIN"
sym_06044924: "COURSE1.BIN"    sym_06044938: "CS1_LINE.BIN"
sym_06044948: "TEX_C1.BIN"     sym_06044958: "COURSE2.BIN"
sym_06044960: "CS2POLY.BIN"    sym_06044970: "CS2_LINE.BIN"
sym_06044980: "TEX_C2.BIN"     sym_06044990: "SCROLL.BIN"
sym_0604499C: "TABLE.BIN"      sym_060449A8: "POLYGON.BIN"
sym_060449B4: "PIT.BIN"        sym_060449BC: "SOUNDS.BIN"
sym_060449C8: "GAMED.BIN"
```

File loader: `FUN_06012C3C(r4=filename_ptr, r5=dest_address)`

---

## Log

- 2026-02-19: Workstream created. Initial hex dump of TABLE.BIN shows offset table structure.
- 2026-02-19: Phase 1 complete. TABLE.BIN has 3 sections: monotonic indices, oscillating sub-arrays, signed 32-bit tail.
- 2026-02-19: Phase 2 complete. Traced all consumers. TABLE.BIN entries are geometry indices, not APROG.BIN offsets.
- 2026-02-19: SCROLL.BIN analysis complete. 8 references found — all load to fixed 0x002A0000, no APROG.BIN back-refs.
- 2026-02-19: Relocation verification: 5,027 correct, 0 real bugs. Data section fully symbolized.
- 2026-02-19: **HYPOTHESIS DISPROVEN.** Corrupt graphics not caused by disc file offset references.
