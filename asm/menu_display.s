! ================================================
! AUDIT: MEDIUM -- Verified addresses exist for most functions; Race HUD section (0x06030xxx) has FABRICATED addresses; high-address functions verified
! Audited: 2026-02-10
! ================================================
! =============================================================================
! Menu/Display System & Race HUD (High Address)
! =============================================================================
!
! This file documents the menu screens, HUD rendering, and display
! system functions in the high-address range.
!
! Address range: 0x06030EE0-0x06032FD4 (race HUD)
!                0x0603C1A8-0x0603CD5C (menu/display system)
!                0x0601E2B4-0x0601E810 (HUD overlays)
!
! NOTE: This supplements asm/hud_ui.s which covers the mid-range
! HUD functions (0x06010000-0x06014F34).

! =============================================================================
! RACE HUD SYSTEM (0x06030EE0-0x06032FD4)
! =============================================================================
!
! The race HUD displays: lap counter, position indicator, speedometer,
! timer, score, and race status messages.
!
! Architecture: 6 large renderers + 30+ tiny digit/counter functions.

! FUN_0603268C — Race HUD orchestrator (1486 bytes, 743 insns)
! CONFIDENCE: SPECULATIVE -- FABRICATED ADDRESS
! AUDIT NOTE: FIXED: FABRICATED ADDRESS confirmed. FUN_0603268C does NOT exist as a label in build/aprog.s. Description retained for reference but address is not a real function boundary.
!   *** LARGEST HUD FUNCTION ***
!   Manages the complete race HUD layout.
!   Coordinates all HUD elements per course.
!   Course-specific HUD variations (different layouts per track).

! FUN_06030FC0 — Speed/position display (792 bytes, 396 insns)
! CONFIDENCE: SPECULATIVE -- FABRICATED ADDRESS
! AUDIT NOTE: FIXED: FABRICATED ADDRESS confirmed. FUN_06030FC0 does NOT exist in build/aprog.s.
!   Renders speedometer and position indicator.
!   Speed displayed in km/h (fixed-point to integer conversion).
!   Position shown as ordinal (1st, 2nd, 3rd, 4th).

! FUN_0603136E — Timer display (756 bytes, 378 insns)
! CONFIDENCE: SPECULATIVE -- FABRICATED ADDRESS
! AUDIT NOTE: FIXED: FABRICATED ADDRESS confirmed. FUN_0603136E does NOT exist in build/aprog.s.
!   Renders race timer with minutes:seconds:hundredths.
!   Handles lap time display and best lap highlighting.

! FUN_06030EE0 — Lap counter display (132 insns)
! CONFIDENCE: SPECULATIVE -- FABRICATED ADDRESS
! AUDIT NOTE: FIXED: FABRICATED ADDRESS confirmed. FUN_06030EE0 does NOT exist as a labeled function in build/aprog.s. (Note: 0x06030EE0 IS a valid jsr target in subsystem_updates.s, but not a labeled function.)
!   Shows current lap / total laps.
!   Triggers lap-complete animation.

! 30+ Digit/Counter Rendering Functions (4-16 insns each)
! CONFIDENCE: SPECULATIVE -- No individual addresses given; claim of 30+ tiny digit functions is unverifiable.
!   Tiny functions that render individual digit sprites.
!   Called by the larger HUD renderers to display numbers.
!   Pattern: read digit value, compute sprite index, write VDP1 command.


! =============================================================================
! MENU/DISPLAY SYSTEM (0x0603C1A8-0x0603CD5C)
! =============================================================================
!
! Full-screen menu rendering — title screen, course select,
! options, and results screen.

! FUN_0603C1A8 — Major HUD/menu system (1282 bytes, 641 insns)
! CONFIDENCE: MEDIUM -- Address verified. Large function. Specific menu screen claims speculative.
!   Menu screen rendering and state management.
!   Handles:
!     - Title screen layout
!     - Course selection screen
!     - Difficulty selection
!     - Results/scoreboard display

! FUN_0603C728 — Extended display system (1212 bytes, 606 insns)
! CONFIDENCE: MEDIUM -- Address verified. Large function. Fade effect claims speculative.
!   Additional HUD logic and multi-screen menu handling.
!   Transitions between menu screens with fade effects.

! FUN_0603CD5C — Large display orchestrator (1252 bytes, 626 insns)
! CONFIDENCE: MEDIUM -- Address verified. Description generic.
!   Comprehensive display coordination.
!   State-dependent rendering based on current game mode.


! =============================================================================
! HUD OVERLAYS (0x0601E2B4-0x0601E810)
! =============================================================================

! FUN_0601E2B4 — HUD overlay renderer (158 bytes, 79 insns)
! CONFIDENCE: SPECULATIVE -- Address exists but descriptions unverified.
!   Renders semi-transparent HUD overlays on top of 3D scene.

! FUN_0601E4D4 — HUD state machine (306 bytes, 153 insns)
! CONFIDENCE: SPECULATIVE -- Address exists. Animation state claims speculative.
!   Controls HUD animation states:
!     - Normal display (steady)
!     - Flash/blink (warning)
!     - Slide in/out (transitions)

! FUN_0601E37C — Large HUD element (248 bytes, 124 insns)
! CONFIDENCE: SPECULATIVE -- Address exists. Mini-map/gear claims have no evidence.
!   Renders complex HUD elements (mini-map, gear indicator, etc.)

! FUN_0601E810 — HUD handler main (284 bytes, 142 insns)
! CONFIDENCE: MEDIUM -- Address verified. Entry point claim plausible.
!   Main HUD rendering entry point — called from the per-frame
!   render pipeline.

! FUN_0601E764 — HUD rendering stage (150 bytes, 75 insns)
! CONFIDENCE: SPECULATIVE -- Addresses exist. Descriptions generic.
! FUN_0601E488 — HUD text handler (76 bytes, 38 insns)
! FUN_0601E6A4 — HUD utility (56 bytes, 28 insns)
! FUN_0601E26C — HUD element positioning (58 bytes, 29 insns)
! AUDIT NOTE: FIXED: Added cross-reference note. Primary documentation for FUN_0601E26C is in replay_camera.s (verified bsr from FUN_0601DBB8). Listed here as secondary reference only.


! =============================================================================
! RACE STATE HANDLERS (0x06018DDC-0x060193F4)
! =============================================================================
!
! State handlers for race progression — the sequence of events
! from starting grid to finish line.

! FUN_06018DDC — Handler dispatcher (66 bytes, 33 insns)
! CONFIDENCE: HIGH -- Address verified. 10+ call sites. Role as dispatcher confirmed.
!   Dispatches to specific state handlers based on parameters.
!   r4=handler ID, r5=sub-handler, r6=parameter.
!   Central dispatch point referenced from asm/pre_race_states.s.

! FUN_06018E70 — General init/reset (24 bytes, 12 insns)
! CONFIDENCE: HIGH -- Address verified. 12+ call sites. Starts with sts.l pr; mov #3; add #-8 -- larger than 24 bytes.
! AUDIT NOTE: FIXED: Size of 24 bytes IS correct. Binary shows 0x06018E70-0x06018E86 = 24 bytes (12 insns). Stack frame (add #-8/+8) is allocated and freed within those 24 bytes. AUDIT NOTE was itself incorrect about the size being wrong.
!   Called at start of each state transition. Resets state variables.

! FUN_06018EE4 — Race state handler (144 bytes, 72 insns)
! CONFIDENCE: MEDIUM -- Address verified. Called from main loop (0x06003200). Position/lap claims unverified.
!   Updates position and lap data during active racing.

! Track Segment State Handlers (18 similar-sized functions):
! CONFIDENCE: HIGH -- Addresses verified for checked samples (FUN_06018FF8, FUN_06019058, FUN_060190B8). Pattern of paired functions confirmed. "Track segment" labeling is speculative; these are state-machine handlers.
! These handle different phases of the race:
!   FUN_06018FF8/06018FFC — Segment handler pair 1 (66B each)
!   FUN_06019058/0601905C — Segment handler pair 2 (66B each)
!   FUN_060190B8/060190BC — Race variant A pair (60B each)
!   FUN_060190F4/060190F8 — Race variant B pair (60B each)
!   FUN_0601914C/06019150 — Race variant C pair (60B each)
!   FUN_06019188/0601918C — Race variant D pair (60B each)
!   FUN_060191E0/060191E4 — Race variant E pair (66B each)
!   FUN_06019248/0601924C — Race variant F pair (66B each)
!
! Each pair has a setup function and an execution function.
! The paired structure suggests a command pattern:
!   Even address = register/configure the handler
!   Odd address (+4) = execute the handler

! FUN_06019324 — Race data handler (58 bytes, 29 insns)
! CONFIDENCE: SPECULATIVE -- Generic description.
! FUN_0601935E — Race utility (28 bytes, 14 insns)
! FUN_0601938C — Race state handler (56 bytes, 28 insns)
! FUN_060193F4 — Track polygon start (188 bytes, 94 insns)
! CONFIDENCE: SPECULATIVE -- Track polygon rendering claim unverified.
!   Initiates track polygon rendering for the current race state.
!   Called from pre-race states for course selection display.


! =============================================================================
! SCENE DATA CHANNEL SYSTEM (0x0603850C-0x060388BE)
!   + GAME LOGIC (0x06038000-0x0603A0B0)
! =============================================================================
!
! CORRECTION (2026-02-20, L3 crossword uplift):
!   Original section title "Game Logic Integration" is misleading for the
!   0x0603850C-0x06038E4A range. Binary analysis proves these functions
!   implement a SCENE DATA CHANNEL SYSTEM — writing position, rotation,
!   and color/intensity data to scene rendering structs via a 6-channel
!   command queue. Also: "State machine" / "Game state update" labels for
!   FUN_06038642 / FUN_06038794 were wrong (additive scene writer / color
!   intensity processor respectively).
!
!   Called from: hud_ui.s Section 12 display channel functions.
!   Call chain: FUN_06014868 → sym_0603850C → FUN_06038794 → sym_06038520
!               FUN_06014884 → sym_0603850C → FUN_0603853C → sym_06038520
!
!   Data structures:
!     0x060635A8 = command slot (stores channel ID for next operation)
!     0x060635AC = ready flag (0=idle, 1=command pending)
!     0x060A3DF8 = scene transform struct:
!                   [0/4]=primary XY, [16/20]=secondary XY,
!                   [32/34]=rotation A yaw/pitch, [36/38]=rotation B,
!                   [8/12]=color A, [24/28]=color B
!     0x060A3E38 = scene enable flags (word at offset 4 = render enable mask)
!     0x060A3E68 = scene view struct A (offsets 68/72=view position, 76/80=color)
!     0x060A3EE8 = scene view struct B (same layout, alternate viewpoint)
!     0x060A4C78 = render dirty flags ([0]=scene A, [4]=scene B)
!     0x060A4C44/48 = scene A/B primary enable
!     0x060A4C4C/50 = scene A/B secondary enable
!     0x060A4C70/74 = scene A/B override disable
!
!   Channel assignments (6 channels via command slot):
!     Channel 1:  scene A view position + color (struct@0x060A3E68)
!     Channel 2:  scene B view position + color (struct@0x060A3EE8)
!     Channel 4:  transform primary position/color (struct@0x060A3DF8)
!     Channel 8:  transform secondary position/color (struct@0x060A3DF8)
!     Channel 16: rotation A yaw/pitch (struct@0x060A3DF8 16-bit words)
!     Channel 32: rotation B yaw/pitch (struct@0x060A3DF8 16-bit words)
!
! Corrected function list (address order):
!   FUN_06038120 — pending decode (430 bytes)
!   FUN_06038300 — pending decode (446 bytes)
!   sym_0603850C — command queue: write channel ID (24 bytes, LEAF)
!   sym_06038520 — command queue: commit (18 bytes, LEAF)
!   FUN_0603853C — scene data write, absolute (262 bytes, CALL)
!   FUN_06038642 — scene data write, additive (300 bytes, CALL)
!   FUN_06038794 — scene color/intensity processor (294 bytes, CALL)
!   FUN_060388C0 — scene data block copy orchestrator (228 bytes, CALL)
!   FUN_060389A6 — scene data orchestrator top-level (158 bytes, CALL)
!   FUN_06038BD4 — channel config nibble-pack setter (632 bytes, CALL)
!   FUN_0603950C — pending decode (658 bytes)
!   FUN_0603A0B0 — pending decode (1508 bytes)
!
! Original labels (preserved for reference):
!   FUN_06038642 was "State machine (284 bytes, 142 insns)"
!   FUN_06038794 was "Game state update (258 bytes, 129 insns)"
!   FUN_06038BD4 was "Complex state integration (570 bytes, 285 insns)"


! ---- sym_0603850C — Command Queue: Write Channel ID (24 bytes, LEAF) ----
! BYTES: VERIFIED — objdump-checked against prod ELF (0x0603850C-0x06038523)
! Writes r4 (channel ID) to command slot at 0x060635A8.
! If a previous command was pending (ready=1), clears it first.
! Called as first step of FUN_06014868/FUN_06014884 display update sequence.
!
sym_0603850C:                            ! 0x0603850C
    mov.l   @(POOL),r5                  ! r5 = &sym_060635AC (ready flag)
    mov.w   @r5,r0                      ! r0 = ready_flag (16-bit)
    extu.w  r0,r0                       ! zero-extend to 32-bit
    cmp/eq  #1,r0                       ! previous command still pending?
    bf      .cmd_write_store            ! no → skip clear
    mov     #0,r2                       ! r2 = 0
    mov.w   r2,@r5                      ! ready_flag = 0 (consume stale command)
.cmd_write_store:
    mov.l   @(POOL),r3                  ! r3 = &sym_060635A8 (command slot)
    rts                                  ! return
    mov.l   r4,@r3                      ! (delay) command_slot = r4 (channel ID)
! Pool: sym_060635AC, sym_060635A8


! ---- sym_06038520 — Command Queue: Commit (18 bytes, LEAF) ----
! BYTES: VERIFIED — objdump-checked against prod ELF (0x06038520-0x06038531)
! Sets ready flag at 0x060635AC to 1, signaling command is ready.
! Only sets if not already set (prevents double-commit).
! Called as final step of FUN_06014868/FUN_06014884 display update sequence.
!
sym_06038520:                            ! 0x06038520
    mov.l   @(POOL),r4                  ! r4 = &sym_060635AC (ready flag)
    mov.w   @r4,r3                      ! r3 = ready_flag
    extu.w  r3,r3                       ! zero-extend
    tst     r3,r3                       ! ready_flag == 0? (idle)
    bf      .commit_done                ! already set → don't double-commit
    mov     #1,r3                       ! r3 = 1
    mov.w   r3,@r4                      ! ready_flag = 1 (command ready)
.commit_done:
    rts                                  ! return
    nop
! Pool: sym_060635AC, sym_060635A8


! ---- FUN_0603853C — Scene Data Write: Absolute (262 bytes, CALL) ----
! BYTES: VERIFIED — objdump-checked against prod ELF (0x0603853C-0x06038641)
! Reads channel ID from command slot 0x060635A8, then writes r4/r5 to
! the appropriate scene struct fields. ABSOLUTE write — overwrites values.
! Called from FUN_06014884 (display channel update B) via action slot.
!
! After channel 1/2 writes: checks 3-flag enable pattern to decide if
! FUN_0603DDFC(0,0,0) should be called for scene render invalidation.
! Enable logic: if (primary_enable && (!secondary_enable || override_disable))
!                 → mark dirty → call FUN_0603DDFC
!
FUN_0603853C:                            ! 0x0603853C
    mov.l   r14,@-r15                   ! save r14
    mov.l   @(POOL),r14                 ! r14 = &sym_060A4C78 (render dirty flags)
    mov.l   @(POOL),r7                  ! r7 = &sym_060A3DF8 (scene transform struct)
    mov.l   @(POOL),r0                  ! r0 = &sym_060635A8 (command slot)
    bra     .abs_dispatch               ! jump to channel dispatch
    mov.l   @r0,r0                      ! (delay) r0 = channel_id from command slot
! ---- Channel 4: scene transform primary position ----
.abs_ch4:
    mov.l   r4,@r7                      ! struct[0] = r4 (primary X position)
    bra     .abs_done                   ! done
    mov.l   r5,@(4,r7)                 ! (delay) struct[4] = r5 (primary Y position)
! ---- Channel 8: scene transform secondary position ----
.abs_ch8:
    mov.l   r4,@(16,r7)                ! struct[16] = r4 (secondary X)
    bra     .abs_done                   ! done
    mov.l   r5,@(20,r7)                ! (delay) struct[20] = r5 (secondary Y)
! ---- Channel 16: scene rotation A (upper 16 bits of r4/r5 → 16-bit words) ----
.abs_ch16:
    shlr16  r4                          ! r4 >>= 16 (extract rotation angle from high half)
    exts.w  r4,r4                       ! sign-extend to handle negative angles
    extu.w  r4,r4                       ! zero-extend for clean 16-bit store
    mov     #32,r0                      ! offset 32 in transform struct
    mov.w   r4,@(r0,r7)                ! struct[32] = rotation_A_yaw (16-bit)
    shlr16  r5                          ! r5 >>= 16
    exts.w  r5,r5                       ! sign-extend
    extu.w  r5,r5                       ! zero-extend
    bra     .abs_rot_store              ! go store second angle
    mov     #34,r0                      ! (delay) offset 34
! ---- Channel 32: scene rotation B ----
.abs_ch32:
    shlr16  r4                          ! extract rotation from high half
    exts.w  r4,r4
    extu.w  r4,r4
    mov     #36,r0                      ! offset 36
    mov.w   r4,@(r0,r7)                ! struct[36] = rotation_B_yaw
    shlr16  r5
    exts.w  r5,r5
    extu.w  r5,r5
    mov     #38,r0                      ! offset 38
.abs_rot_store:
    bra     .abs_done                   ! done
    mov.w   r5,@(r0,r7)                ! (delay) struct[r0] = rotation pitch
! ---- Channel 1: scene A view position + render invalidation ----
.abs_ch1:
    mov     #68,r0                      ! offset 68 = view X position
    mov.l   @(POOL),r7                  ! r7 = &sym_060A3E68 (scene view struct A)
    mov.l   r4,@(r0,r7)                ! view_A[68] = r4 (view X)
    mov     #72,r0                      ! offset 72 = view Y position
    mov.l   r5,@(r0,r7)                ! view_A[72] = r5 (view Y)
    mov.l   @(POOL),r3                  ! r3 = &sym_060A4C44 (scene A primary enable)
    mov.l   @r3,r0                      ! r0 = primary_enable
    tst     r0,r0                       ! rendering enabled?
    bt      .abs_ch1_no_render          ! no → skip invalidation
    mov.l   @(POOL),r3                  ! r3 = &sym_060A4C4C (secondary enable)
    mov.l   @r3,r0
    tst     r0,r0
    bt      .abs_ch1_set_dirty          ! no secondary → set dirty
    mov.l   @(POOL),r3                  ! r3 = &sym_060A4C70 (override disable)
    mov.l   @r3,r0
    tst     r0,r0
    bf      .abs_ch1_no_render          ! override active → skip
.abs_ch1_set_dirty:
    bra     .abs_ch1_check              ! set dirty flag
    mov.l   r6,@r14                     ! (delay) dirty_flag[0] = r6
.abs_ch1_no_render:
    mov     #0,r2
    mov.l   r2,@r14                     ! dirty_flag[0] = 0 (not dirty)
.abs_ch1_check:
    mov.l   @r14,r0                     ! r0 = dirty_flag
    tst     r0,r0                       ! dirty?
    bt      .abs_done                   ! no → done
    ! tail-call FUN_0603DDFC(0,0,0) — invalidate scene A rendering
    mov     #0,r6
    mov     r6,r5
    mov     r6,r4
    mov.l   @(POOL),r3                  ! r3 = FUN_0603DDFC
    jmp     @r3                         ! tail-call: scene invalidation
    mov.l   @r15+,r14                   ! (delay) restore r14
! ---- Channel 2: scene B view position + render invalidation ----
.abs_ch2:
    mov     #68,r0
    mov.l   @(POOL),r7                  ! r7 = &sym_060A3EE8 (scene view struct B)
    mov.l   r4,@(r0,r7)                ! view_B[68] = r4
    mov     #72,r0
    mov.l   r5,@(r0,r7)                ! view_B[72] = r5
    mov.l   @(POOL),r3                  ! r3 = &sym_060A4C48 (scene B primary enable)
    mov.l   @r3,r0
    tst     r0,r0
    bt      .abs_ch2_no_render
    mov.l   @(POOL),r3                  ! r3 = &sym_060A4C50 (secondary enable)
    mov.l   @r3,r0
    tst     r0,r0
    bt      .abs_ch2_set_dirty
    mov.l   @(POOL),r3                  ! r3 = &sym_060A4C74 (override disable)
    mov.l   @r3,r0
    tst     r0,r0
    bf      .abs_ch2_no_render
.abs_ch2_set_dirty:
    bra     .abs_ch2_check
    mov.l   r6,@(4,r14)                ! (delay) dirty_flag[4] = r6
.abs_ch2_no_render:
    mov     #0,r2
    mov.l   r2,@(4,r14)                ! dirty_flag[4] = 0
.abs_ch2_check:
    mov.l   @(4,r14),r0
    tst     r0,r0
    bt      .abs_done
    mov     #0,r6
    mov     r6,r5
    mov     r6,r4
    mov.l   @(POOL),r3                  ! r3 = FUN_0603DDFC
    jmp     @r3                         ! tail-call: scene B invalidation
    mov.l   @r15+,r14                   ! (delay) restore r14
! ---- Channel dispatch (at end of function, jumped to first) ----
.abs_dispatch:
    cmp/eq  #1,r0                       ! channel 1? → scene A view
    bt      .abs_ch1
    cmp/eq  #2,r0                       ! channel 2? → scene B view
    bt      .abs_ch2
    cmp/eq  #4,r0                       ! channel 4? → transform primary
    bt      .abs_ch4
    cmp/eq  #8,r0                       ! channel 8? → transform secondary
    bt      .abs_ch8
    cmp/eq  #16,r0                      ! channel 16? → rotation A
    bt      .abs_ch16
    cmp/eq  #32,r0                      ! channel 32? → rotation B
    bt      .abs_ch32
.abs_done:
    rts                                  ! no matching channel or done
    mov.l   @r15+,r14                   ! (delay) restore r14
! Pool: sym_060A4C78, sym_060A3DF8, sym_060635A8, sym_060A3E68, sym_060A4C44,
!       sym_060A4C4C, sym_060A4C70, FUN_0603DDFC, sym_060A3EE8, sym_060A4C48,
!       sym_060A4C50, sym_060A4C74


! ---- FUN_06038642 — Scene Data Write: Additive/Delta (300 bytes, CALL) ----
! BYTES: VERIFIED — objdump-checked against prod ELF (0x06038642-0x06038793)
! Same 6-channel dispatch as FUN_0603853C but ADDS r4/r5 to existing
! struct values instead of overwriting. Used for incremental scene updates
! (e.g., camera panning, rotation animation).
! Same 3-flag render-dirty logic for channels 1/2.
!
FUN_06038642:                            ! 0x06038642
    mov.l   r14,@-r15                   ! save r14
    mov.l   @(POOL),r14                 ! r14 = &sym_060A4C78 (render dirty flags)
    mov.l   @(POOL),r7                  ! r7 = &sym_060A3DF8 (scene transform struct)
    mov.l   @(POOL),r0                  ! r0 = &sym_060635A8 (command slot)
    bra     .delta_dispatch             ! jump to dispatch
    mov.l   @r0,r0                      ! (delay) r0 = channel_id
! ---- Channel 4: add to primary position ----
.delta_ch4:
    mov.l   @r7,r2                      ! r2 = current struct[0] (X)
    add     r4,r2                       ! r2 += delta_X
    mov.l   r2,@r7                      ! struct[0] = updated X
    mov.l   @(4,r7),r3                  ! r3 = current struct[4] (Y)
    add     r5,r3                       ! r3 += delta_Y
    mov.l   r3,@(4,r7)                 ! struct[4] = updated Y
    bra     .delta_done
    nop
! ---- Channel 8: add to secondary position ----
.delta_ch8:
    mov.l   @(16,r7),r2                ! r2 = struct[16] (secondary X)
    add     r4,r2                       ! += delta
    mov.l   r2,@(16,r7)
    mov.l   @(20,r7),r3                ! r3 = struct[20] (secondary Y)
    add     r5,r3
    mov.l   r3,@(20,r7)
    bra     .delta_done
    nop
! ---- Channel 16: add to rotation A (16-bit word fields) ----
.delta_ch16:
    shlr16  r4                          ! extract angle delta from high half
    exts.w  r4,r4                       ! sign-extend (delta can be negative)
    mov     #32,r0
    mov.w   @(r0,r7),r2                ! r2 = current rotation_A_yaw
    add     r4,r2                       ! r2 += delta_yaw
    mov.w   r2,@(r0,r7)                ! store updated yaw
    shlr16  r5
    exts.w  r5,r5
    mov     #34,r0
    mov.w   @(r0,r7),r3                ! r3 = current rotation_A_pitch
    add     r5,r3                       ! += delta_pitch
    mov.w   r3,@(r0,r7)
    bra     .delta_done
    nop
! ---- Channel 32: add to rotation B (16-bit word fields) ----
.delta_ch32:
    shlr16  r4
    exts.w  r4,r4
    mov     #36,r0
    mov.w   @(r0,r7),r2                ! rotation_B_yaw
    add     r4,r2
    mov.w   r2,@(r0,r7)
    shlr16  r5
    exts.w  r5,r5
    mov     #38,r0
    mov.w   @(r0,r7),r3                ! rotation_B_pitch
    add     r5,r3
    mov.w   r3,@(r0,r7)
    bra     .delta_done
    nop
! ---- Channel 1: add to scene A view + dirty check ----
.delta_ch1:
    mov.l   @(POOL),r7                  ! r7 = &sym_060A3E68 (scene view A)
    mov     #68,r0
    mov.l   @(r0,r7),r2                ! r2 = current view_A[68] (X)
    add     r4,r2                       ! += delta_X
    mov.l   r2,@(r0,r7)                ! store
    mov     #72,r0
    mov.l   @(r0,r7),r3                ! r3 = current view_A[72] (Y)
    add     r5,r3                       ! += delta_Y
    mov.l   r3,@(r0,r7)                ! store
    ! -- 3-flag render enable check (same as absolute variant) --
    mov.l   @(POOL),r3                  ! &sym_060A4C44 (primary enable)
    mov.l   @r3,r0
    tst     r0,r0
    bt      .delta_ch1_no_render
    mov.l   @(POOL),r3                  ! &sym_060A4C4C (secondary enable)
    mov.l   @r3,r0
    tst     r0,r0
    bt      .delta_ch1_dirty
    mov.l   @(POOL),r3                  ! &sym_060A4C70 (override disable)
    mov.l   @r3,r0
    tst     r0,r0
    bf      .delta_ch1_no_render
.delta_ch1_dirty:
    mov.l   @r14,r3                     ! accumulate: dirty += r6
    add     r6,r3
    mov.l   r3,@r14
    bra     .delta_ch1_check
    nop
.delta_ch1_no_render:
    mov     #0,r2
    mov.l   r2,@r14                     ! dirty = 0
.delta_ch1_check:
    mov.l   @r14,r0
    tst     r0,r0
    bt      .delta_done                 ! not dirty → done
    mov     #0,r6                       ! tail-call FUN_0603DDFC(0,0,0)
    mov     r6,r5
    mov     r6,r4
    mov.l   @(POOL),r3                  ! FUN_0603DDFC (scene invalidation)
    jmp     @r3
    mov.l   @r15+,r14                   ! (delay) restore r14
! ---- Channel 2: add to scene B view + dirty check ----
.delta_ch2:
    mov     #68,r0
    mov.l   @(POOL),r7                  ! r7 = &sym_060A3EE8 (scene view B)
    mov.l   @(r0,r7),r2                ! view_B[68] current X
    add     r4,r2
    mov.l   r2,@(r0,r7)
    mov     #72,r0
    mov.l   @(r0,r7),r3                ! view_B[72] current Y
    add     r5,r3
    mov.l   r3,@(r0,r7)
    ! -- 3-flag render enable check for scene B --
    mov.l   @(POOL),r3                  ! &sym_060A4C48
    mov.l   @r3,r0
    tst     r0,r0
    bt      .delta_ch2_no_render
    mov.l   @(POOL),r3                  ! &sym_060A4C50
    mov.l   @r3,r0
    tst     r0,r0
    bt      .delta_ch2_dirty
    mov.l   @(POOL),r3                  ! &sym_060A4C74
    mov.l   @r3,r0
    tst     r0,r0
    bf      .delta_ch2_no_render
.delta_ch2_dirty:
    mov.l   @(4,r14),r3                ! dirty_B += r6
    add     r6,r3
    mov.l   r3,@(4,r14)
    bra     .delta_ch2_check
    nop
.delta_ch2_no_render:
    mov     #0,r2
    mov.l   r2,@(4,r14)
.delta_ch2_check:
    mov.l   @(4,r14),r0
    tst     r0,r0
    bt      .delta_done
    mov     #0,r6
    mov     r6,r5
    mov     r6,r4
    mov.l   @(POOL),r3                  ! FUN_0603DDFC
    jmp     @r3
    mov.l   @r15+,r14                   ! (delay) restore r14
! ---- Channel dispatch ----
.delta_dispatch:
    cmp/eq  #1,r0                       ! channel 1? → scene A (additive)
    bt      .delta_ch1
    cmp/eq  #2,r0                       ! channel 2? → scene B (additive)
    bt      .delta_ch2
    cmp/eq  #4,r0                       ! channel 4?
    bf      .delta_not4
    bra     .delta_ch4                  ! → primary position (additive)
    nop
.delta_not4:
    cmp/eq  #8,r0                       ! channel 8?
    bf      .delta_not8
    bra     .delta_ch8                  ! → secondary position (additive)
    nop
.delta_not8:
    cmp/eq  #16,r0                      ! channel 16? → rotation A (additive)
    bt      .delta_ch16
    cmp/eq  #32,r0                      ! channel 32? → rotation B (additive)
    bt      .delta_ch32
.delta_done:
    rts
    mov.l   @r15+,r14                   ! (delay) restore r14
! Pool: sym_060A4C78, sym_060A3DF8, sym_060635A8, sym_060A3E68, sym_060A4C44,
!       sym_060A4C4C, sym_060A4C70, FUN_0603DDFC, sym_060A3EE8, sym_060A4C48,
!       sym_060A4C50, sym_060A4C74


! ---- FUN_06038794 — Scene Color/Intensity Processor (294 bytes, CALL) ----
! BYTES: VERIFIED — objdump-checked against prod ELF (0x06038794-0x060388B9)
! Clamps r4/r5 intensity values, processes through sym_0603C0A0 (fixed-point
! color scaling), then writes results to scene struct color fields per channel.
!
! Intensity clamping (channels 4/8 only, signed comparison):
!   Max: 0xFF0000 (255.0 in 16.16 fixed-point)
!   Min: 0x4000 (0.25 in 16.16 fixed-point)
!   Zero special: replaced with 0x10000 (1.0 = full intensity default)
! Channels 1/2: skip clamping, process directly.
!
! Color processing: sym_0603C0A0(r4=0x10000, r5=value) for each value.
! After processing, per-channel store:
!   Channel 4: struct@0x060A3DF8[8/12]  (transform color A)
!   Channel 8: struct@0x060A3DF8[24/28] (transform color B)
!   Channel 1: struct@0x060A3E68[76/80] (scene A view color) + render check
!   Channel 2: struct@0x060A3EE8[76/80] (scene B view color) + render check
!
FUN_06038794:                            ! 0x06038794
    mov.l   r14,@-r15                   ! save callee-saved registers
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    mov.l   r10,@-r15
    mov.l   r9,@-r15
    sts.l   pr,@-r15                    ! save return address
    mov.l   @(POOL),r9                  ! r9 = 0xFF0000 (max: 255.0 in fp16.16)
    mov.l   @(POOL),r10                 ! r10 = sym_0603C0A0 (color scale function)
    mov.w   @(POOL),r11                 ! r11 = 0x4000 (min: 0.25 in fp16.16)
    mov.l   @(POOL),r12                 ! r12 = 0x10000 (default: 1.0 in fp16.16)
    mov     r4,r14                      ! r14 = first intensity value to process
    mov     r5,r13                      ! r13 = second intensity value to process
    mov.l   @(POOL),r0                  ! r0 = &sym_060635A8 (command slot)
    bra     .color_dispatch1            ! jump to channel-based clamp decision
    mov.l   @r0,r0                      ! (delay) r0 = channel_id
! ---- Intensity clamp for r14 (channels 4/8 only) ----
.color_clamp:
    cmp/gt  r9,r14                      ! r14 > 0xFF0000? (signed: over max)
    bf      .clamp14_check_min
    bra     .clamp_r13                  ! above max → clamp to 0xFF0000
    mov     r9,r14                      ! (delay) r14 = 0xFF0000
.clamp14_check_min:
    cmp/ge  r11,r14                     ! r14 >= 0x4000? (signed: above minimum)
    bt      .clamp14_check_zero         ! yes → check zero case
    bra     .clamp_r13                  ! below min → clamp to 0x4000
    mov     r11,r14                     ! (delay) r14 = 0x4000
.clamp14_check_zero:
    tst     r14,r14                     ! r14 == 0? (zero intensity)
    bf      .clamp_r13                  ! no → value is valid, keep it
    mov     r12,r14                     ! zero → replace with 1.0 (default intensity)
! ---- Intensity clamp for r13 (same logic) ----
.clamp_r13:
    cmp/gt  r9,r13                      ! r13 > max?
    bf      .clamp13_min
    bra     .color_process              ! clamp to max
    mov     r9,r13
.clamp13_min:
    cmp/ge  r11,r13                     ! r13 >= min?
    bt      .clamp13_zero
    bra     .color_process              ! clamp to min
    mov     r11,r13
.clamp13_zero:
    tst     r13,r13                     ! zero?
    bf      .color_process
    mov     r12,r13                     ! zero → 1.0
! ---- Process both through color scaling function ----
.color_process:
    mov     r14,r5                      ! r5 = (clamped) intensity 1
    jsr     @r10                        ! call sym_0603C0A0(0x10000, intensity1)
    mov     r12,r4                      ! (delay) r4 = 0x10000 (1.0 scale factor)
    mov     r0,r14                      ! r14 = processed color 1 (return value)
    mov     r13,r5                      ! r5 = (clamped) intensity 2
    jsr     @r10                        ! call sym_0603C0A0(0x10000, intensity2)
    mov     r12,r4                      ! (delay) r4 = 0x10000
    bra     .color_store_setup          ! go to per-channel store
    mov     r0,r13                      ! (delay) r13 = processed color 2
! ---- First dispatch: clamp decision based on channel ----
.color_dispatch1:
    cmp/eq  #1,r0                       ! channels 1/2: skip clamp
    bt      .color_process
    cmp/eq  #2,r0
    bt      .color_process
    cmp/eq  #4,r0                       ! channels 4/8: clamp first
    bt      .color_clamp
    cmp/eq  #8,r0
    bt      .color_clamp
! ---- Load struct pointers for per-channel store ----
.color_store_setup:
    mov.l   @(POOL),r6                  ! r6 = &sym_060A3E38 (enable flags)
    mov.l   @(POOL),r5                  ! r5 = &sym_060A3E68 (scene view A)
    mov.l   @(POOL),r4                  ! r4 = &sym_060A3DF8 (transform struct)
    mov.l   @(POOL),r0                  ! r0 = &sym_060635A8
    bra     .color_dispatch2            ! second dispatch for store target
    mov.l   @r0,r0                      ! (delay) r0 = channel_id
! ---- Channel 4: store to transform color A ----
.color_ch4:
    mov.l   r14,@(8,r4)                ! struct[8] = processed color 1
    bra     .color_epilogue
    mov.l   r13,@(12,r4)               ! (delay) struct[12] = processed color 2
! ---- Channel 8: store to transform color B ----
.color_ch8:
    mov.l   r14,@(24,r4)               ! struct[24] = processed color 1
    bra     .color_epilogue
    mov.l   r13,@(28,r4)               ! (delay) struct[28] = processed color 2
! ---- Channel 1: store to scene A view color + render check ----
.color_ch1:
    mov     r5,r4                       ! r4 = &sym_060A3E68 (scene view A)
    mov     #76,r0
    mov.l   r14,@(r0,r4)               ! view_A[76] = processed color 1
    mov     #80,r0
    mov.l   r13,@(r0,r4)               ! view_A[80] = processed color 2
    mov.w   @(4,r6),r0                  ! r0 = enable_flags word at offset 4
    extu.w  r0,r0
    tst     #255,r0                     ! low byte: scene A render enable bits?
    bt      .color_epilogue             ! all zero → no invalidation needed
    ! tail-call FUN_0603DDFC(0,0,0) — invalidate scene A
    mov     #0,r6
    mov     r6,r5
    mov     r6,r4
    lds.l   @r15+,pr
    mov.l   @r15+,r9
    mov.l   @r15+,r10
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    mov.l   @(POOL),r3                  ! r3 = FUN_0603DDFC
    jmp     @r3                         ! tail-call invalidation
    mov.l   @r15+,r14                   ! (delay) restore r14
! ---- Channel 2: store to scene B view color (offset +0x80) ----
.color_ch2:
    mov.w   @(POOL),r4                  ! r4 = 0x80 (scene B struct offset)
    add     r5,r4                       ! r4 = 0x060A3E68 + 0x80 = 0x060A3EE8
    mov     #76,r0
    mov.l   r14,@(r0,r4)               ! view_B[76] = processed color 1
    mov     #80,r0
    mov.l   r13,@(r0,r4)               ! view_B[80] = processed color 2
    mov.w   @(4,r6),r0                  ! enable_flags word at offset 4
    mov.l   @(POOL),r2                  ! r2 = 0xFF00 (high byte mask)
    mov     r0,r3
    extu.w  r3,r3
    and     r2,r3                       ! isolate high byte: scene B enable bits
    tst     r3,r3                       ! any scene B enable bits set?
    bt      .color_epilogue             ! no → skip
    ! tail-call FUN_0603DDFC(0,0,0) — invalidate scene B
    mov     #0,r6
    mov     r6,r5
    mov     r6,r4
    lds.l   @r15+,pr
    mov.l   @r15+,r9
    mov.l   @r15+,r10
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    mov.l   @(POOL),r3                  ! r3 = FUN_0603DDFC
    jmp     @r3
    mov.l   @r15+,r14
! ---- Store dispatch ----
.color_dispatch2:
    cmp/eq  #1,r0                       ! channel 1? → scene A color
    bt      .color_ch1
    cmp/eq  #2,r0                       ! channel 2? → scene B color
    bt      .color_ch2
    cmp/eq  #4,r0                       ! channel 4? → transform color A
    bt      .color_ch4
    cmp/eq  #8,r0                       ! channel 8? → transform color B
    bt      .color_ch8
.color_epilogue:
    lds.l   @r15+,pr                    ! restore all callee-saved registers
    mov.l   @r15+,r9
    mov.l   @r15+,r10
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14
! Pool: 0xFF0000, sym_0603C0A0, 0x4000, 0x10000, sym_060635A8,
!       sym_060A3E38, sym_060A3E68, sym_060A3DF8, 0x80, 0xFF00, FUN_0603DDFC


! ---- FUN_060388C0 — Scene Data Block Copy Orchestrator (228 bytes, CALL) ----
! BYTES: VERIFIED — objdump-checked against prod ELF (0x060388C0-0x060389A5)
! Orchestrates bulk scene data copies between internal buffers.
! Structure: Two independent copy stages + channel-based routing + 6 memcpy calls.
!
! Stage 1: if word@sym_060A4C40 != 0 AND dword@sym_060A4C44 != 0:
!   copy sym_060A4C38[0]*2 bytes from @sym_060A4C44 to @sym_060A3F68
!   via sym_06038A48 (block copy helper). Then clear word@sym_060A4C40.
!
! Stage 2: if word@(sym_060A4C40+2) != 0 AND dword@sym_060A4C48 != 0:
!   copy sym_060A4C3C[0]*2 bytes from @sym_060A4C48 to @sym_060A45D0.
!   Then clear word@(sym_060A4C40+2).
!
! Channel routing: reads word@sym_060635B2, dispatches on channel 1/2
!   to set up a copy from sym_060A4C5C with size 0x80 or 0x100 to sym_060A3E68.
!
! Final: 6 fixed-size block copies into scene rendering pipeline:
!   sym_060A3D84[0]+0   →(40 bytes)→ sym_060A3D88
!   sym_060A3D84[0]+40  →(72 bytes)→ sym_060A3DB0
!   sym_060A3D84[0]+112 →(64 bytes)→ sym_060A3DF8
!   sym_060A3D84[0]+176 →(16 bytes)→ sym_060A3E38
!   sym_060A3D84[0]+192 →(32 bytes)→ sym_060A3E48
!
! This is the per-frame "publish" step — snapshot of internal scene state
! into the rendering pipeline's working buffers.


! ---- FUN_060389A6 — Scene Data Top-Level Orchestrator (158 bytes, CALL) ----
! BYTES: VERIFIED — objdump-checked against prod ELF (0x060389A6-0x06038A47)
! Reads ready flag at sym_060635AC, dispatches:
!   flag==1: call FUN_060388C0 (block copy)
!   flag==2: DMA-style indexed copy from sym_060A3D70/74 using sym_060635A0 as
!            index × 12 byte stride, then second copy from sym_060A3D78/7C
!            using sym_060635A2 × 4 byte stride, then call FUN_060388C0.
!   Then clear ready flag to 0.


! ---- FUN_06038BD4 — Channel Config Nibble-Pack Setter (632 bytes, CALL) ----
! BYTES: VERIFIED — objdump-checked against prod ELF (0x06038BD4-0x06038E4B)
! CONFIDENCE: HIGH -- Address verified. 20+ call sites. Core subsystem dispatcher.
! Writes display channel configuration as packed nibbles into config words.
!
! Args: r4 = bitmask (which fields to set), r5 = value (nibble to pack)
! Each bit in r4 selects a 4-bit field in one of several packed config words:
!
!   Config word array at sym_060A4D28 (3 words, offsets 0/2/4):
!     Bit 0x0100: word[0] low nibble  = r5        (via sym_06034F78 r1=0x101)
!     Bit 0x0200: word[0] high nibble = r5 << 8
!     Bit 0x0400: word[2] low nibble  = r5
!     Bit 0x0800: word[2] high nibble = r5 << 8
!     Bit 0x1000: word[4] low nibble  = r5
!     Bit 0x2000: word[4] high nibble = r5 << 8
!
!   Config word array at sym_060A4D30 (3 words, offsets 0/2/4):
!     Bit 0x0004: word[0] low nibble  = r5        (via sym_06034F78 r1=0x201)
!     Bit 0x0002: word[0] high nibble = r5 << 8
!     Bit 0x0008: word[0] low nibble  = r5 (alternate mask)
!     Bit 0x0080: word[0] high nibble = r5 << 8
!     Bit 0x0010: word[2] low nibble  = r5
!     Bit 0x0020: word[2] high nibble = r5 << 8
!
!   Final field at sym_060A4D58+4: r4 & r7 (remaining bits) → write r5
!
! Each field update calls sym_06034F78(r0=value, r1=bit_pos|count, r2=&target)
! which is a bitfield read-modify-write utility (see lap_counting.s, DEFINITE).
!
! Masks used: 0xFF00 (clear low), 0x00FF (clear high), 0xF0FF, 0xFFF0
!
! Called from hud_ui.s: FUN_0601492C/FUN_06014964/FUN_06014994 pass
! per-channel bitmasks to configure all 6 display channels.


! ---- Unverified functions (descriptions from original, pending decode) ----

! FUN_06038120 — pending decode (430 bytes)
! CONFIDENCE: SPECULATIVE -- Addresses not individually verified. Generic descriptions.

! FUN_06038300 — pending decode (446 bytes)
! CONFIDENCE: SPECULATIVE -- Addresses not individually verified. Generic descriptions.

! FUN_0603950C — pending decode (658 bytes)
! CONFIDENCE: MEDIUM -- Address verified. Called from 0x06004BF0.

! FUN_0603A0B0 — pending decode (1508 bytes)
! CONFIDENCE: MEDIUM -- Address verified. Very large function. Multi-course claim plausible.


! =============================================================================
! EXTRACTION PRIORITY FOR CCE TRANSPLANT
! =============================================================================
!
! | Priority | Components | Notes |
! |----------|-----------|-------|
! | LOW      | Menu/display | CCE has its own menus |
! | LOW      | Race HUD | CCE has different HUD layout |
! | MEDIUM   | Race state handlers | May share logic with CCE |
! | HIGH     | Game logic integration | Core gameplay mechanics |
