! ============================================================
! AUDIT: HIGH
! Mixed file covering camera, race state calc, interpolation, physics
! dispatch, race orchestrator, game state machine, and transitions.
! All major function addresses verified as real labels in aprog.s:
!   FUN_0600AFB2, FUN_0600B4D2, FUN_0600C010, FUN_0600CB90,
!   FUN_0600CDD0, FUN_0600D31C, FUN_0600D41C, FUN_0600E7C8,
!   FUN_0600F424, FUN_0600F870, FUN_0600FFD0 all confirmed.
! FUN_0600C170 and FUN_0600C286 also verified as real labels.
! Functions with C source (marked DONE) have highest confidence.
! Transition handler table (0x0600F650-0x0600FED0) is catalog-level
! with minimal interpretation -- appropriately conservative.
! ============================================================
!
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

! CONFIDENCE: HIGH — has C source, address verified, transform pipeline plausible
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

! CONFIDENCE: HIGH — address verified, lerp algorithm well-documented
! 50% convergence per frame (shar = divide by 2) is a standard smooth-follow technique.
! Data addresses for camera state dispatch (0x06063488 etc.) are plausible.
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

! CONFIDENCE: MEDIUM — address verified but internal details are summary-level
! The function is real and the flag bits at 0x0607EBC4 are confirmed elsewhere.
! But the pipeline description is high-level inference, not instruction-verified.
! FIXED: The 0x0608A52C counter (+0x30 per frame) is byte-verified from binary
! at 0x0600C066-0x0600C06C: mov #48,r6 / mov.l @r12,r2 / add #48,r2 / mov.l r2,@r12
! where r12=0x0608A52C (pool at 0x0600C098). Position calculation (shar + exts.w)
! at 0x0600C084-0x0600C08A also verified.
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

! CONFIDENCE: MEDIUM — address verified as real label, but description is minimal
! FIXED: FUN_0600C170 confirmed as labeled function in aprog.s (line 19476).
! First instruction is jsr to FUN_0603C000 (pool at 0x0600C1B0), then checks
! byte at 0x06083255 and conditionally calls FUN_0600B340, else calls FUN_0600AFB2.
! FUN_0600C170 — Race utility calculation (~30 insns, CALL)
!   Helper for race state. Called from FUN_0600C010.
!   Small calculation function.
! BYTES: VERIFIED — objdump-checked against prod ELF (sawyer.ld), 168 bytes (0x0600C170–0x0600C217)

FUN_0600C170:                           ! 0x0600C170
    sts.l   pr,@-r15                    ! 0x0600C170: 4F 22 — save return address
    mov.l   @(0x3C,PC),r3              ! 0x0600C172: D3 0F — r3 = [0x0600C1B0] = FUN_0603C000
    jsr     @r3                         ! 0x0600C174: 43 0B — call FUN_0603C000
    nop                                 ! 0x0600C176: 00 09
    mov.l   @(0x38,PC),r0              ! 0x0600C178: D0 0E — r0 = [0x0600C1B4] = 0x06083255
    mov.b   @r0,r0                      ! 0x0600C17A: 60 00 — r0 = byte at 0x06083255
    tst     r0,r0                       ! 0x0600C17C: 20 08 — test if zero
    bt      .C170_alt_camera            ! 0x0600C17E: 89 1B — if zero, skip to alternate camera
    bsr     FUN_0600B340                ! 0x0600C180: B8 DE — call FUN_0600B340 (alt camera path)
    nop                                 ! 0x0600C182: 00 09
    bra     .C170_post_camera           ! 0x0600C184: A0 1B — skip past alternate
    nop                                 ! 0x0600C186: 00 09

! --- Constant pool (first block) ---  ! 0x0600C188–0x0600C1B7
    .4byte  FUN_0600C170                ! 0x0600C188: 06 00 C1 70 — self-reference
    .4byte  sym_06063574                ! 0x0600C18C: 06 06 35 74
    .byte   0x00, 0x00                  ! 0x0600C190: 00 00
    .byte   0xFF, 0xFF                  ! 0x0600C192: FF FF
    .byte   0x21, 0x00                  ! 0x0600C194: 21 00
    .byte   0x00, 0x00                  ! 0x0600C196: 00 00
    .byte   0x02, 0x80                  ! 0x0600C198: 02 80
    .byte   0x00, 0x08                  ! 0x0600C19A: 00 08
    .4byte  FUN_060058FA                ! 0x0600C19C: 06 00 58 FA
    .4byte  FUN_06006868                ! 0x0600C1A0: 06 00 68 68
    .byte   0x02, 0x00                  ! 0x0600C1A4: 02 00
    .byte   0x00, 0x00                  ! 0x0600C1A6: 00 00
    .4byte  FUN_0601BDEC                ! 0x0600C1A8: 06 01 BD EC
    .4byte  sym_0607EA98                ! 0x0600C1AC: 06 07 EA 98
    .4byte  sym_0603C000                ! 0x0600C1B0: 06 03 C0 00 — pool for mov.l @(0x3C,PC),r3
    .4byte  sym_06083255                ! 0x0600C1B4: 06 08 32 55 — pool for mov.l @(0x38,PC),r0

! --- Code resumes ---
.C170_alt_camera:                       ! 0x0600C1B8
    mov.l   @(0x38,PC),r3              ! 0x0600C1B8: D3 0E — r3 = [0x0600C1F4] = FUN_0600AFB2
    jsr     @r3                         ! 0x0600C1BA: 43 0B — call FUN_0600AFB2 (standard camera)
    nop                                 ! 0x0600C1BC: 00 09
.C170_post_camera:                      ! 0x0600C1BE
    bsr     FUN_0600B914                ! 0x0600C1BE: BB A9 — call FUN_0600B914
    nop                                 ! 0x0600C1C0: 00 09
    mov.l   @(0x34,PC),r0              ! 0x0600C1C2: D0 0D — r0 = [0x0600C1F8] = sym_06063E1C
    mov.l   @(0x34,PC),r3              ! 0x0600C1C4: D3 0D — r3 = [0x0600C1FC] = sym_06063E20
    mov.l   @r0,r0                      ! 0x0600C1C6: 60 02 — r0 = *sym_06063E1C
    mov.l   @r3,r3                      ! 0x0600C1C8: 63 32 — r3 = *sym_06063E20
    add     r3,r0                       ! 0x0600C1CA: 30 3C — r0 = r0 + r3
    cmp/eq  #8,r0                       ! 0x0600C1CC: 88 08 — compare sum to 8
    bf      .C170_path_b                ! 0x0600C1CE: 8B 04 — if != 8, take path B
    mov.l   @(0x2C,PC),r3              ! 0x0600C1D0: D3 0B — r3 = [0x0600C200] = FUN_06006A9C
    jsr     @r3                         ! 0x0600C1D2: 43 0B — call FUN_06006A9C (path A)
    nop                                 ! 0x0600C1D4: 00 09
    bra     .C170_post_dispatch         ! 0x0600C1D6: A0 03 — skip path B
    nop                                 ! 0x0600C1D8: 00 09
.C170_path_b:                           ! 0x0600C1DA
    mov.l   @(0x28,PC),r3              ! 0x0600C1DA: D3 0A — r3 = [0x0600C204] = FUN_06006CDC
    jsr     @r3                         ! 0x0600C1DC: 43 0B — call FUN_06006CDC (path B)
    nop                                 ! 0x0600C1DE: 00 09
.C170_post_dispatch:                    ! 0x0600C1E0
    mov.l   @(0x24,PC),r2              ! 0x0600C1E0: D2 09 — r2 = [0x0600C208] = sym_06059F40
    mov.l   @(0x24,PC),r3              ! 0x0600C1E2: D3 0A — r3 = [0x0600C20C] = sym_06059F4C
    mov.l   @r2,r2                      ! 0x0600C1E4: 62 22 — r2 = *sym_06059F40
    mov.l   r2,@r3                      ! 0x0600C1E6: 23 22 — *sym_06059F4C = r2
    mov.l   @(0x24,PC),r2              ! 0x0600C1E8: D2 09 — r2 = [0x0600C210] = 0x0000FFFF
    mov.l   @(0x28,PC),r3              ! 0x0600C1EA: D3 0A — r3 = [0x0600C214] = 0x21800000
    lds.l   @r15+,pr                    ! 0x0600C1EC: 4F 26 — restore return address
    rts                                 ! 0x0600C1EE: 00 0B — return
    mov.w   r2,@r3                      ! 0x0600C1F0: 23 21 — (delay slot) write 0xFFFF to 0x21800000

! --- Constant pool (second block) ---  ! 0x0600C1F2–0x0600C217
    .byte   0xFF, 0xFF                  ! 0x0600C1F2: FF FF
    .4byte  FUN_0600AFB2                ! 0x0600C1F4: 06 00 AF B2 — pool for .C170_alt_camera
    .4byte  sym_06063E1C                ! 0x0600C1F8: 06 06 3E 1C
    .4byte  sym_06063E20                ! 0x0600C1FC: 06 06 3E 20
    .4byte  FUN_06006A9C                ! 0x0600C200: 06 00 6A 9C — pool for path A
    .4byte  FUN_06006CDC                ! 0x0600C204: 06 00 6C DC — pool for path B
    .4byte  sym_06059F40                ! 0x0600C208: 06 05 9F 40
    .4byte  sym_06059F4C                ! 0x0600C20C: 06 05 9F 4C
    .byte   0x00, 0x00                  ! 0x0600C210: 00 00 — upper half of 0x0000FFFF
    .byte   0xFF, 0xFF                  ! 0x0600C212: FF FF — lower half of 0x0000FFFF
    .byte   0x21, 0x80                  ! 0x0600C214: 21 80 — upper half of 0x21800000
    .byte   0x00, 0x00                  ! 0x0600C216: 00 00 — lower half of 0x21800000

! CONFIDENCE: MEDIUM — address verified as real label, but description is minimal
! FIXED: FUN_0600C286 confirmed as labeled function in aprog.s (line 19629).
! Calls FUN_0603C000 (pool at 0x0600C2DC), then FUN_0600AFB2 (pool at 0x0600C2E0),
! then conditionally calls FUN_06006CDC based on byte at 0x06082A26.
! FUN_0600C286 — Race utility function (~20 insns, CALL)
!   Helper for race calculations.
!   Small utility.


! =============================================================================
! RACE INTERPOLATION (0x0600CB90-0x0600CDD0)
! =============================================================================

! CONFIDENCE: DEFINITE — has C source, address verified
! Bilinear interpolation with stride 0x18 track table confirmed by C source.
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

! CONFIDENCE: DEFINITE — has C source, address verified
! Track segment advancement via atan2 (FUN_0602744C) confirmed.
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

! CONFIDENCE: DEFINITE — has C source, address verified
! Three-way dispatch confirmed. Flag check at 0x0607EBC4 & 0x00200000 confirmed.
! FUN_0600D31C — Physics calculation dispatcher (13 insns, CALL)
!   C source: src/FUN_0600D31C.c
!   Three-way dispatch based on game flags:
!     if (!(0x0607EBC4 & 0x00200000)):
!       FUN_0600D37C() — vehicle acceleration/velocity
!     FUN_0600D3C4() — main physics (drag, gravity)
!     FUN_0600D50C() — collision/contact resolution
!   All three functions always run; D37C is conditional.

! CONFIDENCE: MEDIUM — address verified but no C source or detailed analysis
! The function is real (label confirmed in aprog.s) but the "traction, handling,
! steering response" description is inference from its position in the call chain.
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

! CONFIDENCE: HIGH — has C source, address verified
! Six subsystem calls confirmed. Camera mode handling description is detailed
! and consistent with the C source.
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

! CONFIDENCE: HIGH — has C source, address verified
! State dispatch table at 0x0605AC2C, button masks at 0x06078656-0x0607865C
! all consistent with other verified files.
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

! CONFIDENCE: DEFINITE — has C source, address verified, small function
! FUN_0600F870 — Race countdown timer (18 insns, CALL)
!   C source: src/FUN_0600F870.c
!   Called every frame during countdown.
!   Decrements counter at 0x0607887C.
!   When counter <= 0: sets flag at 0x0607887F = 4 (triggers race start).
!   Also calls:
!     FUN_060114AC(0) — clear state
!     FUN_06011094() — update timer display

! CONFIDENCE: HIGH — has C source, address verified
! Three-player HUD loop and display mode selection confirmed.
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

