# Memory Diff Pipeline — Integration Test Results

Feature: H2 (Wire memory diff to WRAM dumps)
Tools: `tools/mem_diff.py` + `tools/mem_scan.py` + dump_region command

## Pipeline

1. Boot to game state (menu)
2. `dump_region wram_high` → before.bin
3. Advance frames + press DOWN
4. `dump_region wram_high` → after.bin
5. `mem_diff.py before.bin after.bin --map daytona.map` → diff report

## Results: PASS

Pressing DOWN on mode select menu → 16 change ranges, 29 bytes modified:

| Address | Type | Before | After | Notes |
|---------|------|--------|-------|-------|
| 0x06085FF4 | byte | 0x00 | 0x01 | Adjacent to car_select_input lock flag |
| sym_0605D242 | raw | 18 b3 00 | 0e c2 01 | VDP2 scroll-related area |
| sym_06059F40+2 | word | 0x45F4 | 0x4FBF | Timer/counter (+2507) |
| sym_0605A010+2 | word | 0x41BB | 0x4203 | Timer/counter (+72) |
| 0x0607864F | byte | 0x99 | 0xA8 | Frame counter |
| 0x060A4C* | bytes | various | various | Sound/rendering state |

mem_scan delta mode also found 21 changed 16-bit locations.

## End-to-End Workflow Confirmed

```bash
# Strategy C: Full-Memory Differential
# 1. Dump before
dump_region wram_high /tmp/before.bin
# 2. Perform game action (frame_advance + input)
# 3. Dump after
dump_region wram_high /tmp/after.bin
# 4. Diff with symbol resolution
python tools/mem_diff.py before.bin after.bin -b 0x06000000 --map reimpl/build/daytona.map
# 5. Identify changed variables → set watchpoints to find writing functions
```

## Verdict: PASS

Full E1→H1→H2 pipeline works. dump_region captures WRAM, mem_diff produces
symbol-resolved change reports, mem_scan finds value changes.
