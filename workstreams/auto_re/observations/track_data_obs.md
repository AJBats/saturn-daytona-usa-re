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
- **Entry size**: 16 bytes (4 fields x 4 bytes)
- **Entry count**: 784
- **Total size**: 12,544 bytes

Per-entry fields:
| Offset | Size | Range | Description |
|--------|------|-------|-------------|
| +0x00 | 4 | -24M to +20M (signed) | World X coordinate |
| +0x04 | 4 | -11M to +10M (signed) | World Z coordinate |
| +0x08 | 4 | -50M to +50M (signed) | UNKNOWN — near zero on straights, large oscillation in curves |
| +0x0C | 4 | 0 to ~4.5x10^9 (unsigned) | UNKNOWN — zero on straights, large values in curves |

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

2. **784 points / 2 = 392 edge pairs** for one oval track — reasonable
   density for a ~2km circuit.

3. **Field 3 (offset +0x08)**: Near zero on straight sections, oscillates
   with large positive/negative values in curves. 161 unique values total.
   Strongly correlated with track curvature.

4. **Field 4 (offset +0x0C)**: Zero on straights, jumps to ~4.5 billion
   in curves. 364 non-zero entries out of 784. Binary distribution: either
   zero or very large.

5. **No height/Y coordinate detected**: All data appears 2D. Three Seven
   Speedway may store elevation separately or assume flat.

6. **Data is disc-loaded**: Both tables live at 0x060Cxxxx-0x060Dxxxx,
   well past the binary end (0x06063690). Loaded from course data files
   at race initialization. Course-specific, not shared code.

7. **No spline data**: Track is piecewise-linear. 80% of consecutive
   waypoints have identical heading. Heading changes are discrete steps,
   not smooth curves. 24 unique inter-point distances = uniform subdivision.
   25 zero-length segments mark section boundaries.

### Visualization

Tools: `tools/plot_track.py` (2D), `tools/plot_track_3d.py` (3D).
Run against `build/dumps/wram_high_tt.bin`.

Screenshots for reference (read these with the Read tool):
- `C:\Users\albat\Pictures\Screenshots\Screenshot 2026-03-15 162617.png` — 2D top-down: heading change (left) and field 4 coloring (right). Oval track clearly visible.
- `C:\Users\albat\Pictures\Screenshots\Screenshot 2026-03-15 163040.png` — Zoomed 2D: zigzag pattern visible in both plots. Points alternate left/right = edge pairs.
- `C:\Users\albat\Pictures\Screenshots\Screenshot 2026-03-15 163453.png` — 3D head-on: field 3 spikes in curves (left), field 4 jumps to ~4.5e9 in curves (right). Both flat/zero on straights.

### WRAM Dumps (gitignored, regenerate from save state)

- `build/dumps/wram_high_tt.bin` — full 1MB WRAM High
- `build/dumps/wram_low_tt.bin` — full 1MB WRAM Low

---

## Mapper Analysis (2026-03-15, static + cross-reference)

**Status: HYPOTHESES ONLY. None of the below is empirically confirmed.**
These are the Mapper's best interpretations based on static analysis,
cross-referencing the physics pipeline, and visual inspection of the plots.
Each hypothesis needs empirical testing before it can be treated as fact.

### Q1: Field 3 (+0x08) — banking/cross-slope angle (HYPOTHESIS)

The oscillation pattern — near zero on straights, alternating positive/negative
in curves — matches alternating left/right edge points on a banked curve.
Inner edge tilts down (negative), outer edge tilts up (positive).

**Cross-reference chain**: FUN_0600CA96 reads from sym_0607EB88 (this table)
and writes to a surface buffer at sym_06078680. FUN_0602F5B6 (pipeline call 11)
then writes car struct surface fields +0xEC, +0xF0, +0xF4, +0x11C from that
buffer. The Explorer observed +0xF4 oscillates wildly on grass (-2.9M to +2.7M)
— consistent with a terrain slope/banking readout. Field 3 may feed +0xF4
through this chain.

**To test**: Set watchpoint on car[+0xF4] during a curve. If the written
value correlates with field 3 of the nearest table entry, the chain is confirmed.

### Q2: Field 4 (+0x0C) — curvature magnitude (HYPOTHESIS)

Zero = infinite radius (straight). Non-zero = fixed-point curvature constant.
The ~4.5 billion values are likely 16.16 or 8.24 fixed-point. Within curved
sections the magnitude varies (not purely binary) — tighter curves have larger
values.

**Proposed mechanism**: Curvature feeds into the traction model. Higher
curvature = more centripetal force demand = more traction consumed by cornering
= less available for acceleration. This matches the FUN_0602CCEC NOP test
result — traction limits force throughput, and curves consume traction.

**To test**: Compare field 4 values between the two turns of Three Seven.
If one turn is tighter, its field 4 values should be larger.

### Q3: Physics track, not rendering geometry (HYPOTHESIS)

sym_0607EB88 is read by FUN_0600CA96 (friction/surface computation in the
physics pipeline). The rendering loops (FUN_0600B6A0/B914) don't reference
sym_0607EB88 directly — they use car struct position/orientation to submit
VDP1 sprites from a separate geometry source.

The edge-pair zigzag format makes sense for physics: track edges define
collision boundaries and interpolation surfaces. Rendering geometry would
need UV coordinates, texture indices, and vertex colors — not this 16-byte
format.

**To test**: Trace which code reads from the 0x060C6000 region. If only
physics functions read it, it's physics-only. If rendering functions also
read it, it's shared.

### Q4: Track width — implicit in edge-pair spacing (HYPOTHESIS)

Width = distance between point[2n] and point[2n+1]. No explicit width field
needed. The engine interpolates the car's lateral position between edge
points to compute surface properties. This naturally handles variable-width
sections.

**To test**: Compute width = dist(even, odd) for each pair. Plot width
along the track — should show wider straights, possibly narrower at certain
curves.

### Q5: Elevation — field 3 may be sufficient (HYPOTHESIS)

If field 3 is banking angle, that IS the elevation data expressed as slope
rather than height. For a flat oval like Three Seven, banking is the only
elevation variation. car[+0x14] (Y position) stays at 0 because the racing
surface is the reference plane, with banking applied as rotation.

Other tracks (Dinosaur Canyon, Seaside Street Galaxy) may have additional
height tables. Testing with a different course's WRAM dump would reveal
this.

### Q6: Two independent indexing systems (HYPOTHESIS)

- **Segment table** (147 entries, sym_0607EB84): Longitudinal progress
  milestones. Indexed by car[+0x1E4]. Used for lap counting and gear ratio
  selection.
- **Surface table** (784 entries, sym_0607EB88): Detailed track geometry.
  Indexed by car[+0x1FC] which adjusts continuously. 784 entries / 2 edges
  = 392 cross-sections. +0x1FC ranges 0x000-0x600 and maps via interpolation.

The tables are independent: segments are coarse (147 milestones for game
logic), surface is fine (784 points for physics). They advance at different
rates.

**To test**: Watch car[+0x1FC] change as the car drives. Compute which
surface table entry it maps to and verify the table entry's X/Z matches the
car's approximate position.

---

## Status

This investigation produced strong structural observations (table locations,
sizes, entry format, zigzag pattern, curve correlation) and plausible
hypotheses from the Mapper. Nothing is confirmed empirically.

**Next steps** (any of these would advance understanding):
- Watchpoint car[+0xF4] during a curve to test the field 3 -> banking chain
- Compute edge-pair widths to test the implicit-width hypothesis
- Dump a different course's WRAM to compare table structure
- Trace reads from 0x060C6000 to determine physics-only vs shared usage
