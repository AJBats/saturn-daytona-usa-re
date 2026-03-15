# Save States Catalog

Reference for all save states used in reverse engineering investigations.
Each entry documents the game state, constraints, and recommended use cases.

Renaming `.mc0` files is fine when loading by explicit path (e.g., via MCP
`load_state`). The hash in the filename is only used by Mednafen's auto-discovery.

## daytona_rebuilt.8180a74b2162ad4393a9630de58615e3.mc0

- **Mode**: Race (40 cars, 1P)
- **Course**: Three Seven Speedway (Beginner)
- **Speed**: Rolling start (~150 mph)
- **Position**: 40/40
- **Transmission**: AUTO
- **Build**: Vanilla (unmodified retail binary)
- **Location**: Start/finish line, race start after 3-2-1-GO
- **Known constraints**:
  TO BE DETERMINED ALONG WITH HUMAN USER.
- **Best for**: Multi-car observations (39 AI cars active), collision functions,
  per-car iteration studies, opponent rendering loops
- **Avoid for**: Clean throttle/brake speed tests (cars everywhere), manual
  transmission studies

## daytona_manual_trans.8180a74b2162ad4393a9630de58615e3.mc0

- **Mode**: Race (40 cars, 1P)
- **Course**: Three Seven Speedway (Beginner)
- **Speed**: Rolling start (~150 mph)
- **Position**: 40/40
- **Transmission**: MANUAL
- **Build**: Vanilla (unmodified retail binary)
- **Location**: Start/finish line, race start after 3-2-1-GO
- **Known constraints**:
  TO BE DETERMINED ALONG WITH HUMAN USER.
- **Best for**: Gear shift logic, manual transmission mechanics, RPM/speed
  relationship studies
- **Avoid for**: Clean physics tests where gear shifts add noise (use auto instead)

## usa_tt_straight.mc0

- **Mode**: Time Trial (solo, no AI cars)
- **Course**: Three Seven Speedway (Beginner)
- **Speed**: 0 mph (dead stop)
- **Position**: N/A (time trial)
- **Transmission**: AUTO
- **Build**: Vanilla (unmodified retail binary)
- **Location**: Long straightaway, mid-course
- **Known constraints**:
  - Full throttle (hold C) from standing start hits far corner wall at ~**frame 1314** (~22s)
  - ~1314 frames of clean straight-line physics available
  - 65 mph / gear 2 at wall impact
- **Best for**: Clean throttle/brake/coast speed tests, single-car physics observation,
  speed field identification, input response verification
- **Avoid for**: Multi-car or collision observations (no AI cars present)

### Scenarios (deterministic replay from usa_tt_straight.mc0)

All scenarios: load state → hold inputs → free run.

| Scenario | Inputs | Frames | Expected outcome |
|----------|--------|--------|------------------|
| **straight_throttle** | C (hold) | 1314 | Full-speed run down straight, wall strike at far corner, 65 mph gear 2 |
| **right_wall_strike** | C + RIGHT (hold) | 662 | Angled collision with right guardrail, 26 mph gear 1. Wall impact occurs before frame 662 — use earlier frames to catch the collision event |

## usa_tt_offtrack_stop.mc0

- **Mode**: Time Trial (solo, no AI cars)
- **Course**: Three Seven Speedway (Beginner)
- **Speed**: 0 mph (dead stop)
- **Position**: N/A (time trial)
- **Transmission**: AUTO
- **Build**: Vanilla (unmodified retail binary)
- **Location**: Before turn 1, facing grass from the road
- **Known constraints**:
  - Full throttle (hold C) from standing start, car crosses onto grass at ~**frame 109**, trial ends at **frame 566** (51 mph, stuck in gear 1, maxed RPM)
- **Best for**: Off-track driving, grass/surface handling, terrain response,
  car handling beyond on-track physics
- **Avoid for**: Clean straight-line speed tests (use usa_tt_straight instead)

### Scenarios (deterministic replay from usa_tt_offtrack_stop.mc0)

All scenarios: load state → hold inputs → free run.

| Scenario | Inputs | Frames | Expected outcome |
|----------|--------|--------|------------------|
| **offtrack_throttle** | C (hold) | 566 | Car reaches track/grass boundary at frame 109 (27 mph). Fully on grass by frame ~110+. By frame 566: 51 mph, stuck in gear 1 with maxed RPM — suggests tire slip/traction loss on grass prevents speed buildup and gear shift. Compare memory before/at/after frame 109 for surface transition |
