---
function: N/A (track data tables)
address: 0x060C6000 (surface table), 0x060D5840 (segment distance table)
explored: 2026-03-15
scenarios_tested: [usa_tt_straight save state, paused]
reachable: true
---

## Track Data Memory Dump

Human and DUSA Engineer dumped WRAM High during time trial (paused at
save state load) and analyzed two tables referenced by the driving model.

### Table 1: Surface/Waypoint Table

- **Pointer**: sym_0607EB88 = 0x060C6000
- **Location**: WRAM High, loaded from disc (NOT in APROG.BIN)
- **Entry size**: 16 bytes (4 fields × 4 bytes)
- **Entry count**: 784
- **Total size**: 12,544 bytes

Per-entry fields:
| Offset | Size | Range | Description |
|--------|------|-------|-------------|
| +0x00 | 4 | -24M to +20M (signed) | World X coordinate |
| +0x04 | 4 | -11M to +10M (signed) | World Z coordinate |
| +0x08 | 4 | -50M to +50M (signed) | UNKNOWN — near zero on straights, large oscillation in curves |
| +0x0C | 4 | 0 to ~4.5×10^9 (unsigned) | UNKNOWN — zero on straights, large values in curves |

### Table 2: Segment Distance Table

- **Pointer**: sym_0607EB84 = 0x060D5840
- **Entry size**: 4 bytes
- **Entry count**: 147
- **Total size**: 588 bytes
- **Pattern**: Incrementing values (0x8000, 0x18000... 0x1E8000)
- **Interpretation**: Track progress milestones, 147 segments

### Key Observations

1. **Zigzag X/Z pattern**: Consecutive waypoints alternate left/right,
   suggesting paired edge points (quad strip or track boundary definition),
   not a single centerline.

2. **784 points ÷ 2 = 392 edge pairs** for one oval track — reasonable
   density for a ~2km circuit.

3. **Field 3 (offset +0x08)**: Near zero on straight sections, oscillates
   with large positive/negative values in curves. 161 unique values total.
   Strongly correlated with track curvature.

4. **Field 4 (offset +0x0C)**: Zero on straights, jumps to ~4.5 billion
   in curves. 364 non-zero entries out of 784. Binary distribution: either
   zero or very large.

5. **No height/Y coordinate detected**: All data appears 2D. Three Seven
   Speedway may store elevation separately or assume flat.

6. **Data is disc-loaded**: Both tables live at 0x060Cxxxx–0x060Dxxxx,
   well past the binary end (0x06063690). Loaded from course data files
   at race initialization. Course-specific, not shared code.

### Visualization

Track plots saved as `tools/plot_track.py` (2D) and `tools/plot_track_3d.py`
(3D field interpretation). 2D top-down view confirms oval shape matching
Three Seven Speedway.

### WRAM Dumps

- `build/dumps/wram_high_tt.bin` — full 1MB WRAM High
- `build/dumps/wram_low_tt.bin` — full 1MB WRAM Low

## Questions for Mapper

1. **What is field 3 (+0x08)?** It's near zero on straights and oscillates
   in curves. Candidates: banking angle, curvature radius, lateral force
   constant, normal vector Y component, or centripetal acceleration target.
   Cross-reference: does FUN_0602CA84 (force accumulator) or FUN_0602F5B6
   (surface writer) read from the 0x060C6000 table? If so, which field
   do they index and what do they do with it?

2. **What is field 4 (+0x0C)?** Zero on straights, ~4.5 billion in curves.
   The binary on/off pattern suggests a flag or threshold, but the large
   magnitude suggests a physics constant. Could this be a fixed-point
   curvature value where zero = infinite radius (straight)?

3. **Is this the rendering geometry or the physics track?** The 784 zigzag
   points look like a quad strip for VDP1 sprite rendering. But it's
   referenced by sym_0607EB88 which the physics code reads. Is this table
   shared between rendering and physics, or does each system have its own?

4. **Where is the track width?** The edge-pair zigzag implies track
   boundaries, but we don't see an explicit width field. Is width encoded
   in the lateral distance between consecutive paired points?

5. **Is there elevation data elsewhere?** Three Seven has banked turns
   in-game. The car struct has +0x14 (Y position) and +0x1C (pitch angle).
   Where does the track's banking/elevation come from if not this table?

6. **How does car[+0x1E4] (segment index, values 37-93) map into this
   784-entry table?** The segment table has 147 entries but the waypoint
   table has 784. What's the indexing relationship?
