# Transplant Manifest — DUSA Physics into CCE race.bin

**Status**: SKELETON — populated from existing knowledge. Explorer phases
1-6 will fill the gaps marked [PENDING].

**Strategy**: Option 3 — bring DUSA physics + AI + track data + collision
as a complete package. Thin adapter converts output to CCE rendering format.

---

## 1. FUNCTIONS

### 1a. Player Physics Pipeline (18 calls — ALL VERIFIED Tier 2)

| # | Address | Name | Size (est) | Role | Data Tables Referenced |
|---|---------|------|-----------|------|----------------------|
| 1 | 0x0602FDA4 | sym_0602FDA4 | ~750 | Input handler (throttle/brake/gear/steer) | sym_06081888 (button mapping) |
| 2 | 0x0602EFF0 | FUN_0602EFF0 | ~244 | Steering rotation (deadzone/clamp/3×atan2) | — |
| 4 | 0x0602F3EC | sym_0602F3EC | ~132 | Speed index + drag | — |
| 5 | 0x0602F7BC | sym_0602F7BC | ~38 | Timer decrements (3 counters) | — |
| 6 | 0x0602F0E8 | sym_0602F0E8 | ~148 | Collision state check + EMA | — |
| 7a | 0x0602F17C | sym_0602F17C | ~168 | Gear state machine | sym_060477AC, sym_0604779C, sym_060477CC |
| 7b | 0x0602F270 | FUN_0602F270 | ~380 | Track force application | sym_0602F3CC |
| 9 | 0x0602F474 | sym_0602F474 | ~60 | Animation counter | sym_060477D8 |
| 10 | 0x0602F4B4 | sym_0602F4B4 | ~170 | Opponent proximity detection | — |
| 11 | 0x0602F5B6 | FUN_0602F5B6 | ~340 | Surface writer | Surface table via sym_0607EB88 |
| 12 | 0x0602EFCC | sym_0602EFCC | ~60 | Sin/cos(roll) computation | — |
| 13 | 0x0602C690 | FUN_0602C690 | ~592 | Force magnitude X/Z | — |
| 14 | 0x0602C8E2 | FUN_0602C8E2 | ~418 | Oversteer detection | — |
| 15 | 0x0602CA84 | FUN_0602CA84 | ~616 | Force accumulator (includes FUN_0602CCEC) | sym_0602E938 (traction) |
| 16a | 0x0602D43C | FUN_0602D43C | ~920 | Collision+steering response | — |
| 16b | 0x0602D08A | FUN_0602D08A | ~TBD | Alternate collision (untested) | — |
| 17 | 0x0602CDF6 | FUN_0602CDF6 | ~660 | State finalize + heading convergence | — |
| 18 | 0x0602D814 | sym_0602D814 | ~120 | Speed writer | sym_060477BC (gear ratios) |
| 19 | 0x0602D8BC | sym_0602D8BC | ~480 | Position writer | sym_0602E8B8 (drift) |
| — | 0x0602EEB8 | FUN_0602EEB8 | ~270 | Dispatcher (calls all above) | — |
| — | 0x0602D89A | FUN_0602D89A | ~30 | Position writer prologue | — |

### 1b. AI Pipeline [PENDING Phase 2]

| Address | Name | Role | Shared with Player? |
|---------|------|------|-------------------|
| 0x0600E0C0 | FUN_0600E0C0 | AI car iteration loop (i=1..car_count) | No |
| 0x0600E71A | FUN_0600e71a | Normal mode physics | No (separate from player) |
| 0x0600E906 | FUN_0600e906 | AI mode physics | No |
| 0x0600C4F8 | FUN_0600c4f8 | Speed/accel calculator (AI) | No (player uses sym_0602D814) |
| 0x0600C5D6 | FUN_0600c5d6 | Core steering/force (AI) | No |
| 0x0600C74E | FUN_0600c74e | AI core physics | No |
| 0x0600C970 | FUN_0600c970 | AI-specific steering | No |
| 0x0600CA96 | FUN_0600ca96 | Friction/drag (shared surface lookup) | SHARED — also used by player |
| 0x0600CF58 | FUN_0600cf58 | Collision dispatch (AI) | No |
| 0x0600CC38 | FUN_0600cc38 | Force application (AI) | No |
| 0x0600C8CC | FUN_0600c8cc | Heading calculator (shared) | SHARED |
| 0x0600C928 | FUN_0600c928 | Heading correction (shared) | SHARED |
| 0x0600C7D4 | FUN_0600c7d4 | Heading/speed damping (shared) | SHARED |
| 0x0600CEBA | FUN_0600ceba | Track segment advance (shared) | SHARED |
| 0x0600CD40 | FUN_0600cd40 | Track position query (shared) | SHARED — reads car[+0x10] |
| [PENDING] | ... | Additional sub-calls from Phase 2 | ... |

### 1c. Collision Detection [PENDING Phase 3]

| Address | Name | Role |
|---------|------|------|
| [PENDING] | ... | Wall/car contact detection |
| [PENDING] | ... | Sets car[+0x04] and car[+0x9E] |

### 1d. Frame Orchestration [PENDING Phase 1]

| Address | Name | Role |
|---------|------|------|
| 0x0600C010 | FUN_0600C010 | Racing orchestrator (per-frame entry) |
| 0x0600DF20 | FUN_0600DF20 | Player physics caller wrapper |
| ~0x0600E526 | FUN_0600E526 | Within wrapper chain |
| [PENDING] | ... | Additional orchestration from Phase 1 |

### 1e. Shared Math Functions [PENDING Phase 6]

| Address | Name | Size | Purpose |
|---------|------|------|---------|
| 0x06027344 | cos variant | ~4 | Cosine lookup |
| 0x06027348 | cos_lookup | ~16 | Cosine table entry |
| 0x0602734C | sin_lookup | ~16 | Sine table entry |
| 0x0602735C | FUN_06027358 | ~32 | Sin/cos pair |
| 0x0602737C | FUN_06027378 | ~212 | Inverse trig |
| 0x06027450 | atan2 | ~16 | atan2 entry |
| 0x0602744C | FUN_0602744C | ~4+ | atan2 variant |
| 0x0602749C | isqrt | ~34 | Integer sqrt |
| 0x06027550 | swap_sign_ext | ~6 | Sign extension |
| 0x06027552 | FUN_06027552 | ~10+ | Fixed-point multiply |
| 0x06027560 | fpdiv_setup | ~24 | FP divide |
| 0x0602755C | FUN_0602755C | TBD | Clamp/normalize |
| 0x0602ECCC | FUN_0602ECCC | TBD | atan2/rotation |
| [PENDING] | ... | Sin/cos lookup TABLES (data) |

---

## 2. DATA TABLES

### 2a. Physics Lookup Tables (CONFIRMED — values dumped)

| Address | Size | Entries | Name | Referenced By |
|---------|------|---------|------|--------------|
| sym_060477BC | 32 | 8 (4 active) | Gear ratios | sym_0602D814 |
| sym_060477AC | 16 | 4 | Gear-up thresholds | sym_0602F17C |
| sym_0604779C | 16 | 4 | Gear-down thresholds | sym_0602F17C |
| sym_060477CC | 16 | 4 | Section scaling | sym_0602F17C |
| sym_060477D8 | 20 | 5 | Animation states | sym_0602F474 |
| sym_0602E938 | 128 | 16 | Traction force constants | FUN_0602CCEC |
| sym_0602F3CC | 32 | 8 | Track force bounds | FUN_0602F270 |
| sym_0602E8B8 | 64 | 16 | Drift velocity scaling | sym_0602D8BC |
| sym_06081888 | 12 | 6 | Button mapping masks | sym_0602FDA4 |

### 2b. Track Data (disc-loaded, in WRAM at race start)

| Address | Size | Entries | Name | Loaded From |
|---------|------|---------|------|------------|
| 0x060C6000 | 12,544 | 784×16 | Surface/waypoint table | Course disc file |
| 0x060D5840 | 588 | 147×4 | Segment distance table | Course disc file |

### 2c. AI/Shared Tables [PENDING Phase 4]

| Address | Size | Name | Referenced By |
|---------|------|------|--------------|
| 0x060477EC | TBD | AI speed table 1 | FUN_0600C4F8 |
| 0x060454CC | TBD | AI speed table 2 | FUN_0600C4F8 |
| 0x060453B4 | TBD | Collision speed 1 | FUN_06008640 |
| 0x060453C4 | TBD | Collision speed 2 | FUN_06008640 |
| 0x060453CC | TBD | Gear shift timing | FUN_06008318 |
| [PENDING] | ... | Additional tables from Phase 2+4 |

### 2d. Sin/Cos Lookup Tables [PENDING Phase 6]

| Address | Size | Name |
|---------|------|------|
| [PENDING] | TBD | Sin lookup data |
| [PENDING] | TBD | Cos lookup data |

---

## 3. GLOBAL VARIABLES

### 3a. Known Globals (from globals_writer_map + struct_map)

| Address | Size | Name | Role | Read By | Written By |
|---------|------|------|------|---------|------------|
| 0x0607E940 | 4 | sym_0607E940 | Current car pointer | All pipeline funcs | FUN_0600E0C0, FUN_0600A918, etc. |
| 0x0607E944 | 4 | sym_0607E944 | Player car pointer | Player pipeline | Init code |
| 0x0607E948 | 4 | sym_0607E948 | Car[1] base | FUN_0600E0C0 | FUN_0600E4F6 |
| 0x0607EA98 | 4 | sym_0607EA98 | Car count | FUN_0600E0C0 | Init code |
| 0x0607EAAC | 4 | sym_0607EAAC | Race countdown timer | HUD, state machine | FUN_0600932E |
| 0x0607EBC4 | 4 | sym_0607EBC4 | Pipeline mode flag | FUN_0600E0C0 | FUN_06003052 |
| 0x0607EBD0 | 4 | sym_0607EBD0 | Speed threshold | FUN_06008318 | FUN_06009396 |
| 0x0607EBDC | 4 | sym_0607EBDC | Car iteration index | Physics loop | FUN_0600C694 |
| 0x0607EB84 | 4 | sym_0607EB84 | Segment table pointer | FUN_0600CD40 | Init (disc load) |
| 0x0607EB88 | 4 | sym_0607EB88 | Surface table pointer | FUN_0600CA96 | Init (disc load) |
| 0x06063D98 | 4 | sym_06063D98 | g_pad_state (buttons) | sym_0602FDA4 | Input polling |
| 0x06078680 | TBD | sym_06078680 | Surface buffer | FUN_0602F5B6 | FUN_0600CA96 |
| 0x060635C4 | 4 | (unnamed) | VBlank semaphore | slSynch | VBlank ISR |
| [PENDING] | ... | Additional globals from Phase 5 |

### 3b. Globals Read But Not in Writer Map [PENDING Phase 5]

---

## 4. STRUCTS

| Base | Stride | Count | Name | Purpose |
|------|--------|-------|------|---------|
| 0x06078900 | 0x268 (616) | 40 | Car struct array | All car state (player + AI) |
| 0x060C6000 | 0x10 (16) | 784 | Surface table | Track physics geometry |
| 0x060D5840 | 0x04 (4) | 147 | Segment table | Track progress milestones |
| sym_06081888 | 0x02 (2) | 6 | Button mapping | Controller masks |
| [PENDING] | ... | ... | Collision result structs? | From Phase 3 |

---

## 5. CCE INTERFACE ADAPTER

The adapter sits between DUSA physics output and CCE rendering input.

### 5a. Output Mapping (DUSA → CCE)

| DUSA Field | CCE Field | Conversion |
|------------|-----------|-----------|
| car[+0x10] (X pos) | car[+0x00] | TBD scalar (coordinate space diff) |
| car[+0x18] (Z pos) | car[+0x08] | TBD scalar |
| car[+0x20] (heading) | car[+0x38] | Direct (both 32-bit angle) |
| car[+0x20] (heading) | car[+0x0E] | Truncate to 16-bit |
| car[+0x0C] (speed) | car[+0x24] | TBD scalar (different units) |
| car[+0x08] (speed idx) | car[+0x34] | Recompute: +0x24 × 0x006C0000 >> 16 |
| (none — flat) | car[+0x04] | CCE terrain system fills Y from X/Z |
| car[+0x00] (flags) | car[+0x30] | TBD flag mapping |

### 5b. Input Mapping (CCE → DUSA)

| CCE Source | DUSA Field | Notes |
|-----------|------------|-------|
| CCE pad state | sym_06063D98 | Copy CCE controller state to DUSA global |
| CCE VBlank | DUSA frame tick | Trigger DUSA physics at appropriate rate |

### 5c. Coordinate Space

| Space | X Range | Z Range | Notes |
|-------|---------|---------|-------|
| DUSA car space | ~±10M signed | ~±10M signed | From surface table |
| CCE car space | ~±10M signed | ~±10M signed | Similar range |
| CCE polygon space | car × 16 | car × 16 | For polygon lookup only |

[PENDING: exact scalar between DUSA and CCE world coordinates.
Both use Three Seven Speedway — compare car[+0x10] at the same
track position in both games to derive the conversion factor.]

---

## 6. TOTAL SIZE ESTIMATE

| Category | Items | Estimated Bytes |
|----------|-------|----------------|
| Player pipeline functions | ~20 | ~6,000 |
| AI pipeline functions | ~15 | ~4,000 |
| Shared math functions | ~15 | ~800 |
| Collision detection | TBD | TBD |
| Frame orchestration | ~5 | ~1,000 |
| Shared track/surface functions | ~8 | ~2,000 |
| Physics lookup tables | 9 | ~320 |
| AI/collision tables | ~6 | ~TBD |
| Track data (per course) | 2 | ~13,200 |
| Car struct array | 1 | 24,640 (40×616) |
| Globals region | ~15 | ~100 |
| **ESTIMATED TOTAL** | | **~52,000 + TBD** |

[PENDING: accurate sizes from Phase 1+2+4 outputs]
