# Disc File Reverse Engineering

> **Status**: ACTIVE
> **Goal**: Understand what TABLE.BIN and SCROLL.BIN contain, how APROG.BIN uses their data,
> and whether offset-based references back into APROG.BIN break under the +4 shift.

---

## Motivation

The free build (+4 shift) boots with bypasses (SCDQ+ICF+CD_FIX) but has severely corrupt
graphics. Previous investigation focused on the SCDQ poll hang — 10+ sessions went in circles.

**New hypothesis**: The disc files (TABLE.BIN, SCROLL.BIN, etc.) may contain **offset-based
references** into APROG.BIN code/data. A simple grep for `0x060xxxxx` addresses found nothing,
but the values could be relative offsets that get combined with a base address at runtime.
If `base + table[i]` computes an APROG.BIN address, every lookup is wrong by +4 after the shift.

This is a different failure mode from the SCDQ timing issue — it would explain the **corrupt
graphics** even when boot succeeds.

---

## What We Know

### TABLE.BIN (28,448 bytes, 14 sectors)
- Array of **monotonically increasing 16-bit big-endian values**
- Starts at 0x0000, increments ~39-41 per entry
- Tail section (~last 640 bytes): switches to `FFFF xxxx` 32-bit pattern
- Name literally says "TABLE" — likely a lookup/index table
- Loaded at CDB command #2201 in the boot sequence (after SCROLL.BIN)
- Adjacent to SCROLL.BIN on disc (TABLE at FAD 0x06DE, SCROLL at 0x06EC)

### SCROLL.BIN (327,736 bytes, 161 sectors)
- Much larger — 320KB of data
- Loaded before TABLE.BIN in the boot sequence
- Likely VDP2 scroll plane graphics data (tile maps, patterns)

### Disc loading code in APROG.BIN
- FUN_0601B170 (680B): Main disc loading manager (state machine)
- FUN_06012BDC: CD sector lookup
- FUN_06012C3C: Main file loader (wait+open+read with retry)
- FUN_06012CF4: Course-specific loader
- FUN_06012E08+: ~15 file path stubs (one per asset)
- FUN_06012AC4: Course data table lookup
- FUN_06012AFA: Car parameter table lookup
- FUN_06012BE4: Track segment table lookup

### ASM annotation files (asm/ directory)
- `disc_loading_replay.s`: Disc loading system (0x0601B000-0x0601B6F0)
- `remaining_subsystems.s`: File I/O helpers and data table accessors
- `vdp_hardware.s`: VDP configuration (may show how SCROLL data is used)
- `render_pipeline.s`: Rendering pipeline
- `scene_renderer.s`: Scene rendering

---

## Investigation Plan

### Phase 1: Dump and decode TABLE.BIN structure
1. Full hex analysis — find section boundaries, entry sizes, value ranges
2. Check if 16-bit values are plausible offsets into SCROLL.BIN (327KB = 0x4FF28)
3. Check if values + any known base address point into APROG.BIN range (0x06003000-0x06063690)
4. Look for patterns: headers, record counts, sentinel values

### Phase 2: Trace how APROG.BIN loads and uses TABLE.BIN
1. Read the annotated ASM for the file loading functions
2. Find where TABLE.BIN data lands in RAM after loading
3. Trace the code that reads from that RAM — what operations does it do with the values?
4. Identify any `base + offset` patterns that resolve into APROG.BIN addresses

### Phase 3: Same analysis for SCROLL.BIN
1. Structure analysis of the binary data
2. Identify VDP2 tile/pattern data vs metadata
3. Look for any cross-references into APROG.BIN

### Phase 4: Test the hypothesis
1. If offsets found: build a tool to patch the offsets by +4 in the loaded data
2. Test whether patched offsets fix the corrupt graphics
3. If confirmed: implement proper runtime relocation in the free build

---

## Key Questions

1. **Where does TABLE.BIN land in RAM?** Which address does the loader place it at?
2. **What code reads TABLE.BIN data after loading?** Follow the call chain from loader completion.
3. **Are the monotonic 16-bit values offsets?** Into what? SCROLL.BIN? APROG.BIN data section?
4. **What about the FFFF tail section?** Signed 32-bit values? Sentinel-terminated?
5. **Does SCROLL.BIN contain any metadata?** Or is it pure pixel/tile data?

---

## Log

- 2026-02-19: Workstream created. Initial hex dump of TABLE.BIN shows offset table structure.
