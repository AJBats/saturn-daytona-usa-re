! =============================================================================
! Race Orchestration & Remaining Gameplay Functions
! =============================================================================
!
! This file documents the remaining gameplay-critical functions in the
! 0x0600xxxx range that were not covered by other asm/ files.
!
! Subsystems covered:
!   1. Camera positioning (0x0600AFB2, 0x0600B4D2)
!   2. Race state calculation (0x0600C010, 0x0600C170, 0x0600C286)
!   3. Race interpolation (0x0600CB90, 0x0600CDD0)
!   4. Physics dispatch chain (0x0600D31C, 0x0600D41C)
!   5. Race frame orchestrator (0x0600E7C8)
!   6. Game state machine (0x0600F424, 0x0600F870, 0x0600FFD0)
!   7. Transition handlers (0x0600F650-0x0600FED0, 19 functions)


! =============================================================================
! CAMERA POSITIONING (0x0600AFB2-0x0600B4D2)
! =============================================================================

! FUN_0600AFB2 — Camera tracking & transform setup (164 insns, CALL)
!   C source: src/FUN_0600AFB2.c
!   Controls viewpoint during gameplay.
!   Reads camera object from 0x0607E944.
!   Transform pipeline:
!     1. FUN_06027080() - transform init
!     2. FUN_060270F2(obj.X, obj.Y, obj.Z) - set position
!     3. FUN_060271A2(0x8000 + obj[0x20]) - primary rotation
!     4. FUN_060271EE(-obj[0x24]) - secondary rotation
!     5. FUN_06027158(angle) - angle computation
!   Multi-player support:
!     If flag & 0x00800008 == 0: angle = (obj[0x78] - obj[0x1C]) + table_offset
!     Else: angle = table_offset - obj[0x1C]
!   Split-screen:
!     If *(0x06059F30) != 0: set up second player camera
!   Geometry rendering:
!     If flag & 0x20020000: call FUN_0601C3E4()
!   Double-buffer: adjusts 0x0608A52C -= 0x30

! FUN_0600B4D2 — Camera position lerping (164 insns, CALL)
!   NOT YET DECOMPILED - HIGH PRIORITY
!   Per-frame smooth camera tracking via 50% lerp.
!   3-way state dispatch:
!     State 0: data at 0x06063488/0x06063434
!     State 1: data at 0x060634A4/0x06063450
!     State 2: data at 0x060634C0/0x0606346C
!   Lerp algorithm (per axis):
!     delta = object.X - target.X
!     delta += 0x8000 (rounding)
!     delta >>= 1 (shar = signed divide by 2)
!     target.X += delta
!   Repeats for Y (+0x14) and Z (+0x18).
!   Result: camera smoothly tracks car with 50% convergence per frame.
!   Key addresses:
!     0x0607EB8C — camera base pointer
!     0x0607E944 — camera object pointer
!     0x06078670 — target position


! =============================================================================
! RACE STATE CALCULATION (0x0600C010-0x0600C286)
! =============================================================================

! FUN_0600C010 — Race state machine (~200+ insns, CALL)
!   NOT YET DECOMPILED - HIGH PRIORITY
!   Multi-stage race state orchestrator.
!   Pipeline:
!     1. Check race active/paused conditions
!     2. Dispatch to physics calculators:
!        - FUN_06034708 (data processing, conditional)
!        - FUN_0600D336 (physics variant A, conditional)
!        - FUN_0600D31C (physics dispatcher, always)
!     3. Sprite management: FUN_0602E610 (conditional)
!     4. Race buffer increment: counter += 0x30 per frame
!     5. Rendering: FUN_06027630
!     6. Position calculation: (value >> 1), sign-extended to 16-bit
!   Key flags at 0x0607EBC4:
!     bit 0x02000000 — physics enable
!     bit 0x00020000 — specific state check
!   Data structures:
!     0x0608A52C — race update counter (+0x30 per frame)
!     0x0605A1DD — race data pointer
!     0x0607EA98 — race position
!     0x06078664 — position output register

! FUN_0600C170 — Race utility calculation (~30 insns, CALL)
!   Helper for race state. Called from FUN_0600C010.
!   Small calculation function.

! FUN_0600C286 — Race utility function (~20 insns, CALL)
!   Helper for race calculations.
!   Small utility.


! =============================================================================
! RACE INTERPOLATION (0x0600CB90-0x0600CDD0)
! =============================================================================

! FUN_0600CB90 — Race position interpolation (~60 insns, CALL)
!   C source: src/FUN_0600CB90.c
!   Bilinear interpolation for smooth race progression.
!   Even param_2: direct waypoint lookup
!   Odd param_2: average between adjacent waypoints
!   Track table stride: index * 0x18 + base
!   Output fields:
!     param_1[0] = X position
!     param_1[2] = Z position
!     param_1[3] = rotation (short)
!     param_1[4] = track attribute (short)
!   Also copies heading data with <<2 scaling.

! FUN_0600CDD0 — Race heading/direction calculator (~40 insns, CALL)
!   C source: src/FUN_0600CDD0.c
!   Determines car facing direction relative to track.
!   Algorithm:
!     1. Get current track segment from car data
!     2. Load segment heading offset
!     3. Get next segment (wrapping at max)
!     4. Calculate angle to next segment via atan2 (FUN_0602744C)
!     5. If angle exceeds threshold: advance to next segment
!   Key variables:
!     DAT_0600ce86 — current track segment index
!     DAT_0600ce88 — current heading value
!     DAT_0600ce8c — angle threshold for segment change
!     0x0607EA9C — max track segments
!   This is how the game knows the car has passed a waypoint.


! =============================================================================
! PHYSICS DISPATCH CHAIN (0x0600D31C-0x0600D41C)
! =============================================================================

! FUN_0600D31C — Physics calculation dispatcher (13 insns, CALL)
!   C source: src/FUN_0600D31C.c
!   Three-way dispatch based on game flags:
!     if (!(0x0607EBC4 & 0x00200000)):
!       FUN_0600D37C() — vehicle acceleration/velocity
!     FUN_0600D3C4() — main physics (drag, gravity)
!     FUN_0600D50C() — collision/contact resolution
!   All three functions always run; D37C is conditional.

! FUN_0600D41C — Vehicle state/physics update (~140 insns, CALL)
!   NOT YET DECOMPILED - HIGH PRIORITY
!   Sits between dispatcher (D31C) and collision (D50C) in pipeline.
!   ~140 instructions. Core vehicle dynamics computation.
!   Handles: traction, handling, steering response.
!   Part of the critical physics chain:
!     D31C -> D37C -> D3C4 -> D41C -> D50C


! =============================================================================
! RACE FRAME ORCHESTRATOR (0x0600E7C8)
! =============================================================================

! FUN_0600E7C8 — Per-frame race state orchestrator (137 insns, CALL)
!   C source: src/FUN_0600E7C8.c
!   Called every frame during active racing.
!   Orchestrates 6 subsystems:
!     1. FUN_06008318() — frame processing / controller
!     2. FUN_06008640() — gear/force table
!     3. FUN_0600D266() — friction placeholder (stub)
!     4. FUN_0600C4F8() — speed curve + clamping
!     5. FUN_0602D88E() — sprite management
!     6. FUN_0600CEBA() — track segment advancement
!
!   Camera mode handling (3 modes at 0x06083261):
!     Mode 1: Lerp camera — (delta << 16 >> 18) convergence
!     Mode 2: Discrete jump — (delta + 0x8000) << 16 >> 17 convergence
!     Other: Default handling
!
!   Segment change logic:
!     When car_data[offset-0x54] != 0 AND segment_counter decrements to 0:
!       Load new segment from track table (stride 0x18)
!       Reset segment_timer = 0x400
!
!   Position calculation:
!     result = car[0x228] * max_segments + car[0x228 - 0x3C]
!     heading = track_table[segment * 0x18 + base + 0x14]


! =============================================================================
! GAME STATE MACHINE (0x0600F424-0x0600FFD0)
! =============================================================================

! FUN_0600F424 — Game state dispatcher (270 insns, CALL)
!   C source: src/FUN_0600F424.c
!   Central game flow controller.
!   State dispatch table at 0x0605AC2C (indexed by state << 2).
!   State-dependent behavior:
!     States 0-4: menu/setup rendering
!     State 9: special mode
!     States 8-12: race in-progress (rendering setup)
!   Input mode selection (states 9+):
!     Reads controller at 0x06063D98
!     Button masks at 0x06078656-0x0607865C
!     Sets mode at 0x06078648 (0-3)
!   Race rendering dispatch:
!     Mode 0: standard (FUN_060284AE)
!     Mode 1/2: variant (FUN_06028400 with offset)
!   Always calls:
!     FUN_06026DBC — color/palette setup
!     state_handler() — dispatch by state
!     FUN_0600FFD0 — HUD update
!     buffer -= 0x30
!     FUN_060078DC — frame finalize

! FUN_0600F870 — Race countdown timer (18 insns, CALL)
!   C source: src/FUN_0600F870.c
!   Called every frame during countdown.
!   Decrements counter at 0x0607887C.
!   When counter <= 0: sets flag at 0x0607887F = 4 (triggers race start).
!   Also calls:
!     FUN_060114AC(0) — clear state
!     FUN_06011094() — update timer display

! FUN_0600FFD0 — HUD race display (114 insns, CALL)
!   C source: src/FUN_0600FFD0.c
!   Per-frame HUD rendering.
!   Updates HUD for 3 players/splits:
!     Loop: FUN_060100A4(player_idx) for idx = 0,1,2
!   Display mode selection via flag at 0x06078663:
!     Normal: countdown at 0x0605AA98 (decrement)
!     Alternate: count-up at 0x0605AA98 (increment to 0xC)
!   State-dependent rendering:
!     States 0-4, 9: menu/special mode renders
!     Other states: race display
!   Output buffers:
!     0x0605ACE4 — primary display
!     0x0605AB19 — alternate display


! =============================================================================
! TRANSITION HANDLERS (0x0600F650-0x0600FED0)
! =============================================================================
!
! 19 small-to-medium functions handling game state transitions.
! These manage menu flow, race start/end sequences, and mode changes.
! All are assembly-only (no decompiled C source yet).
!
! | Function     | Size  | Purpose |
! |--------------|-------|---------|
! | FUN_0600F650 | 170   | Post-race transition |
! | FUN_0600F794 | 80    | Transition handler |
! | FUN_0600F822 | 46    | Small transition |
! | FUN_0600F898 | 26    | Minimal transition |
! | FUN_0600F8BE | 50    | Transition handler |
! | FUN_0600F914 | 60    | Transition handler |
! | FUN_0600F98C | 4     | Stub/redirect |
! | FUN_0600F990 | 30    | Small transition |
! | FUN_0600F9C6 | 220   | Large transition (menu?) |
! | FUN_0600FB78 | 245   | Large transition (results?) |
! | FUN_0600FD54 | 34    | Small transition |
! | FUN_0600FD8A | 65    | Medium transition |
! | FUN_0600FDFE | 36    | Small transition |
! | FUN_0600FE38 | 83    | Medium transition |
! | FUN_0600FED0 | 135   | Medium transition |
!
! These are MEDIUM priority for CCE transplant. The transitions
! manage game flow that CCE will likely replace with its own logic.


! =============================================================================
! DECOMPILATION STATUS
! =============================================================================
!
! | Function     | Status | Priority | Notes |
! |--------------|--------|----------|-------|
! | FUN_0600AFB2 | DONE   | 1 | Camera tracking - has C source |
! | FUN_0600B4D2 | NEEDED | 1 | Camera lerping - 164 insns |
! | FUN_0600C010 | NEEDED | 1 | Race state machine - 200+ insns |
! | FUN_0600C170 | -      | 3 | Small helper |
! | FUN_0600C286 | -      | 3 | Small helper |
! | FUN_0600CB90 | DONE   | 2 | Race interpolation - has C source |
! | FUN_0600CDD0 | DONE   | 2 | Race heading calc - has C source |
! | FUN_0600D31C | DONE   | 1 | Physics dispatcher - has C source |
! | FUN_0600D41C | NEEDED | 1 | Vehicle dynamics - 140 insns |
! | FUN_0600DC74 | DONE   | 2 | Physics output - has C source |
! | FUN_0600E7C8 | DONE   | 1 | Race orchestrator - has C source |
! | FUN_0600F424 | DONE   | 1 | Game state - has C source |
! | FUN_0600F870 | DONE   | 1 | Countdown - has C source |
! | FUN_0600FFD0 | DONE   | 1 | HUD display - has C source |
!
! 3 functions need urgent decompilation:
!   FUN_0600B4D2 (camera lerp, ~164 insns, self-contained)
!   FUN_0600C010 (race state, ~200 insns, moderate deps)
!   FUN_0600D41C (vehicle dynamics, ~140 insns, physics chain)


! =============================================================================
! EXTRACTION PRIORITY FOR CCE TRANSPLANT
! =============================================================================
!
! | Priority | Component | Notes |
! |----------|-----------|-------|
! | CRITICAL | Physics dispatch (D31C/D41C) | Core vehicle dynamics |
! | CRITICAL | Race orchestrator (E7C8) | Per-frame gameplay |
! | CRITICAL | Race state calc (C010) | Race progression |
! | HIGH     | Camera system (AFB2/B4D2) | Gameplay camera |
! | HIGH     | Race interp (CB90/CDD0) | Smooth progression |
! | HIGH     | Game state (F424/FFD0) | Game flow |
! | MEDIUM   | Countdown (F870) | Race start sequence |
! | LOW      | Transitions (F650-FED0) | CCE has own flow |

