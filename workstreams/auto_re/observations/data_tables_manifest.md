---
function: N/A (data table catalog)
explored: 2026-03-17
scenarios_tested: [source_analysis]
reachable: N/A
---

## Phase 4: Data Table Catalog

1,245 data table references extracted from all source files in reimpl/src/.
References are .4byte pool constants pointing to addresses in the
0x0604xxxx-0x0608xxxx data regions.

### Known Physics Tables (dumped in cycle 32)

| Table | Address | Size | Purpose | Dumped? |
|-------|---------|------|---------|---------|
| Gear ratios | sym_060477BC | 32 bytes | Speed→force scaling per gear | YES |
| Gear-up thresholds | sym_060477AC | 16 bytes | Section advance trigger | YES |
| Gear-down thresholds | sym_0604779C | 16 bytes | Section retreat trigger | YES |
| Section scaling | sym_060477CC | 16 bytes | Speed recomp on shift | YES |
| Animation states | sym_060477D8 | 20 bytes | 4-state display lookup | YES |
| Traction force | sym_0602E938 | 128 bytes | Gear × section constants | YES |
| Track force bounds | sym_0602F3CC | 32 bytes | Force clamp per gear | YES |
| Drift scaling | sym_0602E8B8 | 64 bytes | Velocity multiplier 0-10 | YES |
| Button mapping | sym_06081888 | 12 bytes | Controller button masks | YES |

### Known Undumped Tables (from priorities)

| Table | Address | Size | Purpose |
|-------|---------|------|---------|
| Surface table | [sym_0607EB88] | ~12544 bytes | Track physics geometry |
| Segment table | [sym_0607EB84] | ~588 bytes | Track progress milestones |
| Speed tables (AI) | 0x060477EC | TBD | AI acceleration lookup |
| Speed tables (AI) #2 | 0x060454CC | TBD | AI second accel table |
| Collision speed | 0x060453B4 | TBD | Collision bounce magnitude |
| Collision speed #2 | 0x060453C4 | TBD | Collision bounce #2 |
| Gear shift timing | 0x060453CC | TBD | Gear shift animation |

### Data Region Distribution (from 1,245 references)

| Region | References | Description |
|--------|-----------|-------------|
| 0x0604xxxx | ~350 | Game data tables (gear, physics, AI) |
| 0x0605xxxx | ~500 | Track geometry, surface data, display config |
| 0x0606xxxx | ~250 | Runtime state, VDP config, input state |
| 0x0607xxxx | ~100 | Car struct metadata, globals |
| 0x0608xxxx | ~45 | Car data, button mapping, runtime buffers |

### Transplant Size Estimate

The physics data tables span roughly:
- 0x06044xxx-0x060499xx: ~22 KB of physics/AI tables
- 0x0604A0xx-0x0604CFxx: ~12 KB of additional game tables
- 0x0605xxxx region: ~40 KB of track/surface data (largest block)
- 0x0606xxxx region: ~8 KB of runtime state templates

Total estimated data footprint: **~80 KB** of data tables that must be
transplanted alongside the ~50 KB of physics code.

### Surface and Track Tables (Critical — Largest)

The surface table at [sym_0607EB88] and segment table at [sym_0607EB84]
are the largest data dependencies. These are POINTERS — they point to
track-specific data loaded from the disc for each course. The transplant
must either:
1. Load the same track data format from CCE's disc
2. Convert DUSA track data to CCE format
3. Include the raw track data in the transplant binary

This is a track-dependent transplant decision, not a physics code issue.
