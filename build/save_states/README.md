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

### Scenarios (deterministic replay from daytona_rebuilt save state)

**car_graze** — chase and graze AI car ahead

| Frame | Event | Notes |
|-------|-------|-------|
| 0 | PRESS C | Throttle from rolling start (~179 mph, pos 40/40) |
| 33 | PRESS LEFT | First steer toward AI car ahead |
| 38 | RELEASE LEFT | |
| 75 | PRESS LEFT | Second steer — commits to collision line |
| 106 | RELEASE LEFT | |
| 131 | PRESS START | Pause after graze — sparks visible |
| 135 | RELEASE C | |
| 137 | RELEASE START | |

Car-to-car contact (graze with sparks) occurs around frames 100-130.

**Input recording**: `build/save_states/daytona_rebuilt_car_graze.input.txt`

**Automated replay** (using input playback):
```
load_state  build/save_states/daytona_rebuilt.8180a74b2162ad4393a9630de58615e3.mc0
input_playback_start  build/save_states/daytona_rebuilt_car_graze.input.txt
sample_memory 0x06078900 616 140 <output_path>
```
The input playback injects all button events at the correct frames while
sample_memory captures data. No manual frame-stepping needed.

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
| **offtrack_donut** | C (hold entire), LEFT (frame 133–439) | 439 | Throttle into grass then left turn at frame 133. Car does donuts on grass, 33 mph gear 1, no collision. Tests off-track steering + surface handling. Replay: load state → hold C → advance 133 frames → press LEFT → advance 306 frames |

## usa_tt_manual_straight.mc0

- **Mode**: Time Trial (solo, no AI cars)
- **Course**: Three Seven Speedway (Beginner)
- **Speed**: 0 mph (dead stop)
- **Position**: N/A (time trial)
- **Transmission**: MANUAL
- **Build**: Vanilla (unmodified retail binary)
- **Location**: Long straightaway, mid-course
- **Known constraints**:
  - Full throttle (hold C) from standing start, 3 manual upshifts (DOWN), wall strike at far corner ~frame 641
  - ~641 frames of clean straight-line acceleration with manual gear shifts
- **Best for**: Manual gear shift logic, UP/DOWN gear input tracing,
  RPM/speed/gear relationship studies, +0xDE behavior
- **Avoid for**: Clean physics tests where gear shifts add noise (use
  usa_tt_straight with auto instead)

### Scenarios (deterministic replay from usa_tt_manual_straight.mc0)

| Frame | Event | Notes |
|-------|-------|-------|
| 0 | PRESS C | Throttle from standstill |
| 190 | PRESS DOWN | Gear shift up #1 (1st → 2nd) |
| 195 | RELEASE DOWN | |
| 337 | PRESS DOWN | Gear shift up #2 (2nd → 3rd) |
| 342 | RELEASE DOWN | |
| 494 | PRESS DOWN | Gear shift up #3 (3rd → 4th) — shifted early to reach 4th before wall |
| 500 | RELEASE DOWN | |
| 641 | PRESS START | Wall strike at far corner |
| 643 | RELEASE C | Throttle released |
| 647 | RELEASE START | |

Replay: load state → hold C → advance to frame 190 → tap DOWN → advance
to frame 337 → tap DOWN → advance to frame 494 → tap DOWN → run to ~641
for wall strike. DOWN = upshift in Daytona USA manual transmission.
