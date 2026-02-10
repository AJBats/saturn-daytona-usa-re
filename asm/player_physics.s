! ============================================================
! AUDIT: HIGH
! Player car physics pipeline with correct call chain order
! verified against ground truth. Struct offsets and call targets
! confirmed. Minor annotation errors in FUN_06008318 store
! offset and inverted label/logic in FUN_0600E906.
! ============================================================

! ============================================================================
! player_physics.s — Player Car Physics Pipeline
! ============================================================================
!
! This file documents the PLAYER-SPECIFIC physics update chain, which runs
! every frame during in-race states (14/15/17/19). AI cars use a completely
! different path (track-following via FUN_0600EA18, documented in race_update.s).
!
! The branching point is FUN_0600E1D4, which checks the car index at
! 0x0607EAD8. Car index 0 = player car, all others = AI.
!
! PLAYER PHYSICS PIPELINE (FUN_0600E71A):
! ========================================
!
!   FUN_0600E71A — Player physics orchestrator
!     1. jsr FUN_06008318  — Controller input: gear shift, steering column
!     2. jsr FUN_06008640  — Gear/force table selection, force extraction
!     3. jsr FUN_0600D266  — (STUB: rts immediately, no-op placeholder)
!     4. jsr FUN_0600C4F8  — Speed computation & velocity clamping
!     5. jsr FUN_0600C5D6  — Collision detection, heading→position integration
!     6. (inline) Timer countdown, track segment index update
!     7. jsr FUN_0600CEBA  — Track segment advancement & heading interpolation
!     8. (inline) Score/ranking computation (multiply × car count + base)
!
! AI PHYSICS PIPELINE (FUN_0600E906, for comparison):
! ====================================================
!
!   FUN_0600E906 — AI physics orchestrator
!     1. Check car index != 0 (safety), clear car+0xC if player
!     2. jsr FUN_0600D266  — (same stub as player)
!     3. jsr FUN_0600C74E  — AI-specific processing
!     4. jsr FUN_06027552  — Fixed-point multiply (heading calculation)
!     5. jsr FUN_0600CEBA  — Same track segment advancement as player
!     6. Fall through to FUN_0600EA18 — Track-following velocity computation
!
! KEY DIFFERENCE: Player physics uses force lookup tables driven by controller
! input. AI physics uses track-segment chasing (velocity = (target-current)/16).
!
! CAR OBJECT STRUCT LAYOUT (partial):
! ===================================
!
!   +0x000: byte  — flags (bit 0x08=special_state, 0x10=shift_down, 0x20=shift_up)
!   +0x001: byte  — secondary flags
!   +0x004: long  — car sub-type / secondary car pointer
!   +0x008: long  — speed value (heading-relative scalar)
!   +0x00C: long  — acceleration / distance accumulator
!   +0x010: long  — X position (world coords)
!   +0x014: long  — Y position (world coords)
!   +0x018: long  — Z position (world coords)
!   +0x020: long  — heading (yaw angle, 16-bit precision stored as 32)
!   +0x028: long  — heading copy (secondary)
!   +0x030: long  — heading copy (tertiary)
!   +0x0B8: long  — steering input timer
!   +0x0BC: long  — some physics field
!   +0x0D4: long  — timer / mode field
!   +0x1BC: byte  — collision flags
!   +0x1DC: long  — gear shift countdown timer
!   +0x258: word  — gear shift sound parameter
!   +0x301: long  — gear direction (+1=up, -1=down)
!   +0x350: long  — steering deflection value
!
! KEY DATA ADDRESSES:
!   0x0607E940  — current game object pointer (player car base)
!   0x0607E944  — game object pointer (secondary, used during iteration)
!   0x0607EAD8  — current car index (0=player, 1+=AI)
!   0x0607EA9C  — total car count
!   0x0607EBC4  — game state bitmask (bit 0x8000=countdown, 0x800000=special)
!   0x0607EBD0  — player/race state variable
!   0x0607EBDC  — collision counter
!   0x0607EBEC  — steering event counter
!   0x060453B4  — steering/force table A (normal racing)
!   0x060453C4  — steering/force table B (special state)
!   0x060453CC  — gear steering lookup table
!   0x060477EC  — course speed table A
!   0x060454CC  — course speed table B
!   0x0607EB84  — track segment table pointer
!   0x06078680  — physics base / track collision data
!
! ============================================================================


! ============================================================================
! CONFIDENCE: DEFINITE
! All 5 jsr targets verified against pool constants in ground truth.
! Call order: 06008318, 06008640, 0600D266, 0600C4F8, 0600C5D6 confirmed.
! Timer logic, segment stride calc (24 bytes), and ranking formula match binary.
! FUN_0600E71A — Player Physics Orchestrator
! ============================================================================
! Called when car index == 0 (player car) during race states.
! Runs the full physics pipeline: input → forces → speed → collision → heading.
!
! Prologue saves: r14, pr, macl
! r14 = car object pointer (from 0x0607E940)

FUN_0600E71A:                            ! 0x0600E71A
    mov.l   r14,@-r15                    ! Save r14
    sts.l   pr,@-r15                     ! Save return address
    sts.l   macl,@-r15                   ! Save multiply accumulator (used later)
    mov.l   @(0x84,PC),r14              ! r14 = &0x0607E940 (car object pointer ptr)
    mov.l   @(0x88,PC),r3              ! r3 = 0x06008318 (input handler)
    jsr     @r3                          ! === STEP 1: Controller Input ===
    mov.l   @r14,r14                     ! (delay) r14 = *0x0607E940 (car object)

    mov.l   @(0x84,PC),r3              ! r3 = 0x06008640 (steering/gear processor)
    jsr     @r3                          ! === STEP 2: Force Table Selection ===
    nop

    mov.l   @(0x84,PC),r3              ! r3 = 0x0600D266 (friction stub)
    jsr     @r3                          ! === STEP 3: Friction (STUB: returns immediately) ===
    nop

    mov.l   @(0x80,PC),r3              ! r3 = 0x0600C4F8 (velocity clamp)
    jsr     @r3                          ! === STEP 4: Speed Computation & Clamping ===
    nop

    mov.l   @(0x80,PC),r3              ! r3 = 0x0600C5D6 (collision)
    jsr     @r3                          ! === STEP 5: Collision Detection & Position Update ===
    nop

! --- STEP 6: Timer countdown and track segment check ---
! If a timer at car+0x208 is positive, decrement car+0x1E4.
! When that sub-timer reaches zero, read the next track segment and update
! the car's segment data (car+0x1F8, car+0x400).
    mov.w   @(0x58,PC),r0              ! r0 = 0x0208 (timer offset)
    mov.l   @(r0,r14),r2              ! r2 = car[0x208] (timer value)
    cmp/pl  r2                           ! timer > 0?
    bf      .L_skip_timer                ! No → skip timer section

    mov.w   @(0x50,PC),r0              ! r0 = 0x01E4 (sub-timer offset)
    mov.l   @(r0,r14),r2              ! r2 = car[0x1E4]
    add     #-1,r2                       ! Decrement
    mov.l   r2,@(r0,r14)              ! Store back
    tst     r2,r2                        ! Reached zero?
    bf      .L_skip_timer                ! No → skip

    ! Timer hit zero: read next track segment data
    mov.w   @(0x46,PC),r0              ! r0 = 0x01F8 (segment index offset)
    mov.l   @(r0,r14),r4              ! r4 = segment_index
    mov     r4,r3                        ! r3 = segment_index (copy for stride calc)
    shll2   r4                           ! r4 = index * 4
    shll    r4                           ! r4 = index * 8
    shll2   r3                           ! r3 = index * 4
    shll2   r3                           ! r3 = index * 16
    add     r3,r4                        ! r4 = index * 24 (stride = 24 bytes per segment)
    add     #-4,r0                       ! r0 = 0x01F4 (base table pointer offset)
    mov.l   @(r0,r14),r3              ! r3 = track_segment_table_base
    add     r3,r4                        ! r4 = &segment_table[index]
    mov.w   @(0x14,r4),r0              ! r0 = segment_table[index].word_at_0x14
    mov     r0,r3
    mov.w   @(0x2E,PC),r0              ! Offset for storing result
    mov.l   r3,@(r0,r14)              ! Store segment value to car struct
    mov.w   @(0x2C,PC),r3              ! r3 = 0xFFFF (or another constant)
    add     #12,r0                       ! Offset for secondary storage
    mov.l   r3,@(r0,r14)              ! Store to car+offset+12

.L_skip_timer:                           ! 0x0600E778

! --- STEP 7: Track segment advancement ---
    mov.l   @(0x44,PC),r3              ! r3 = 0x0600CEBA (track segment handler)
    jsr     @r3                          ! FUN_0600CEBA: advance segment, update heading
    nop

! --- STEP 8: Score/ranking computation ---
! result = car[+0x228] * [0x0607EA9C] + car[+0x1CC]
! This computes a position/ranking value for the player.
    mov.w   @(0x22,PC),r0              ! r0 = 0x0228 (ranking field offset)
    mov.l   @(0x40,PC),r3              ! r3 = &0x0607EA9C (car count)
    mov.l   @(r0,r14),r2              ! r2 = car[0x228] (race position value)
    mov.l   @r3,r3                       ! r3 = total_car_count
    add     #-60,r0                      ! r0 → offset 0x1EC
    mul.l   r3,r2                        ! macl = position * car_count
    mov.l   @(r0,r14),r3              ! r3 = car[0x1EC] (base ranking)
    sts     macl,r2                      ! r2 = multiply result
    add     #8,r0                        ! r0 → offset 0x1F4
    add     r3,r2                        ! r2 = position*count + base
    mov.l   r2,@(r0,r14)              ! Store final ranking to car[0x1F4]

! --- Epilogue ---
    lds.l   @r15+,macl                   ! Restore macl
    lds.l   @r15+,pr                     ! Restore return address
    rts                                  ! Return
    mov.l   @r15+,r14                    ! (delay) Restore r14

! Pool constants for FUN_0600E71A:
!   0x0600E7A8 = 0x0607E940  (car object pointer)
!   0x0600E7AC = 0x06008318  (input handler)
!   0x0600E7B0 = 0x06008640  (steering/gear)
!   0x0600E7B4 = 0x0600D266  (friction stub)
!   0x0600E7B8 = 0x0600C4F8  (velocity clamp)
!   0x0600E7BC = 0x0600C5D6  (collision)
!   0x0600E7C0 = 0x0600CEBA  (track segment)
!   0x0600E7C4 = 0x0607EA9C  (car count)


! ============================================================================
! CONFIDENCE: HIGH
! Instruction sequence verified against ground truth 0x06008318-0x060083DE.
! Gear shift detection (bits 0x10/0x20), timer=32, direction +/-1 confirmed.
! AUDIT NOTE: Line 256 says r0=0x0201 but pool at 0x06008360 = 0x01D8.
! Store writes to car[0x01D8], NOT car[0x350]. Header also wrong about +0x350.
! FUN_06008318 — Controller Input Handler (Gear Shifting & Steering Column)
! ============================================================================
! Reads controller state from the car object and processes gear shift inputs.
! This is the first step in the player physics pipeline.
!
! Two main behaviors:
!   A) If car has an active steering timer (car+0x0B8 != 0):
!      - Decrement countdown at car+0x1DC
!      - Look up signed steering value from table at 0x060453CC
!      - Apply sign based on direction at car+0x301
!      - Store deflection to car+0x350
!
!   B) If no timer but race frame count > threshold (0x0607EBD0 > limit):
!      Check gear shift buttons in car flag byte:
!        - Bit 0x10 (shift down): Set direction=-1, timer=32, sound=40
!        - Bit 0x20 (shift up):   Set direction=+1, timer=32, sound=40
!      Store active car pointer to 0x0607EBE0
!
!   C) Always at end: Call FUN_06034F78 twice to interpolate/zero out
!      steering column values. This resets the column smoothly after input.
!
! The steering column value (car+0x350) feeds into FUN_06008640 which
! selects force vectors from lookup tables.

FUN_06008318:                            ! 0x06008318
    sts.l   pr,@-r15                     ! Save return address
    mov.l   @(0x54,PC),r4              ! r4 = &0x0607E940 (car object pointer ptr)

! --- Check if active steering timer ---
    mov.w   @(0x38,PC),r0              ! r0 = 0x00B8 (timer field offset in car)
    mov.l   @r4,r3                       ! r3 = car_object pointer
    mov.l   @(r0,r3),r0               ! r0 = car[0xB8] (steering timer)
    tst     r0,r0                        ! Timer active?
    bt      .L_no_active_steer           ! No → check gear shift buttons

! --- Active steering: countdown and apply deflection ---
    mov.l   @r4,r3                       ! r3 = car_object
    mov.w   @(0x2C,PC),r0              ! r0 = 0x01DC (countdown offset)
    mov.l   @(r0,r3),r2               ! r2 = car[0x1DC] (countdown)
    add     #-1,r2                       ! Decrement
    mov.l   r2,@(r0,r3)               ! Store back

    mov.l   @r4,r5                       ! r5 = car_object
    mov.l   @(0x40,PC),r3              ! r3 = 0x060453CC (gear steering lookup table)
    mov.l   @r4,r2                       ! r2 = car_object (again)
    mov.l   @(r0,r5),r5               ! r5 = car[0x1DC] (new countdown value)
    mov     r2,r1                        ! r1 = car_object
    shll    r5                           ! r5 *= 2 (word index)
    mov.w   @(0x1A,PC),r0              ! r0 = 0x0301 (direction field offset)
    add     r3,r5                        ! r5 = &table[countdown] (word pointer)
    mov.l   @(r0,r1),r3               ! r3 = car[0x301] (direction: +1 or -1)
    cmp/pl  r3                           ! direction > 0?
    bf/s    .L_negate_steer              ! If direction <= 0, negate the table value
    mov.w   @r5,r5                       ! (delay) r5 = steering_table[countdown]

    ! Direction positive: use value as-is
    bra     .L_store_steer
    exts.w  r5,r3                        ! r3 = sign_extend(steering_value)

.L_negate_steer:                         ! 0x0600834C
    exts.w  r5,r1                        ! r1 = sign_extend(steering_value)
    neg     r1,r3                        ! r3 = -steering_value (flip for opposite dir)

.L_store_steer:                          ! 0x06008350
    mov.w   @(0xC,PC),r0               ! r0 = 0x0201 (offset → but likely 0x350 area)
    mov.l   r3,@(r0,r2)               ! car[offset] = steering_deflection
    bra     .L_input_finalize            ! Jump to finalization
    nop

! --- No active steering: check gear shift buttons ---
.L_no_active_steer:                      ! 0x06008378
    mov.l   @(0x8C,PC),r2              ! r2 = &0x0607EBD0 (race frame counter)
    mov.w   @(0x7C,PC),r3              ! r3 = threshold value
    mov.l   @r2,r2                       ! r2 = frame_count
    cmp/gt  r3,r2                        ! frame_count > threshold?
    bf      .L_input_finalize            ! No → too early for input, skip

    mov.l   @(0x88,PC),r3              ! r3 = &0x0607E940
    mov.w   @(0x74,PC),r0              ! r0 = offset for lock flag
    mov.l   @r3,r3                       ! r3 = car_object
    mov.l   @(r0,r3),r0               ! r0 = car[lock_flag]
    tst     r0,r0                        ! Input locked?
    bf      .L_input_finalize            ! Yes → skip all input

    ! Read the controller button byte from car flags
    mov     #40,r6                       ! r6 = 40 (sound parameter for gear shift)
    mov.l   @r4,r2                       ! r2 = car_object
    mov.l   @(0x7C,PC),r7              ! r7 = &0x0607EBE0 (active input car pointer)
    mov     r2,r0                        ! r0 = car base address
    mov.b   @r0,r0                       ! r0 = car[0] (flag byte with button state)

    ! Test bit 0x10 = shift DOWN
    tst     #0x10,r0                     ! Shift-down button pressed?
    bt/s    .L_check_shift_up            ! No → check shift-up
    mov     #32,r5                       ! (delay) r5 = 32 (timer duration)

    ! --- Shift DOWN ---
    mov.l   @r4,r3                       ! r3 = car_object
    mov.w   @(0x5A,PC),r0              ! r0 = 0x0301 (direction offset)
    mov.l   r5,@(r0,r3)               ! car[0x301] = 32 (timer value... or direction?)
    mov.l   @r4,r3                       ! r3 = car_object
    mov     #-1,r2                       ! r2 = -1 (DOWN direction)
    mov.w   @(0x54,PC),r0              ! r0 = 0x01DC (countdown offset)
    mov.l   r2,@(r0,r3)               ! car[0x1DC] = -1 (direction marker)
    mov.l   @r4,r3                       ! r3 = car_object
    mov.l   r3,@r7                       ! 0x0607EBE0 = car (mark as active shifting car)
    mov.l   @r4,r2                       ! r2 = car_object
    exts.w  r6,r6                        ! r6 = 40 (sign-extended)
    mov.w   @(0x4A,PC),r0              ! r0 = 0x0258 (sound param offset)
    bra     .L_input_finalize            ! Done with shift-down
    mov.w   r6,@(r0,r2)               ! (delay) car[0x258] = 40 (gear shift sound)

.L_check_shift_up:                       ! 0x060083BA
    mov.l   @r4,r2                       ! r2 = car_object
    mov     r2,r0
    mov.b   @r0,r0                       ! r0 = car[0] (re-read flags)
    tst     #0x20,r0                     ! Shift-up button pressed?
    bt      .L_input_finalize            ! No → skip

    ! --- Shift UP ---
    mov.l   @r4,r3                       ! r3 = car_object
    mov.w   @(0x34,PC),r0              ! r0 = 0x0301
    mov.l   r5,@(r0,r3)               ! car[0x301] = 32
    mov.l   @r4,r3
    mov     #1,r2                        ! r2 = +1 (UP direction)
    mov.w   @(0x2E,PC),r0              ! r0 = 0x01DC
    mov.l   r2,@(r0,r3)               ! car[0x1DC] = +1 (direction marker)
    mov.l   @r4,r3
    mov.l   r3,@r7                       ! 0x0607EBE0 = car (active shifting car)
    mov.l   @r4,r2
    exts.w  r6,r6                        ! r6 = 40
    mov.w   @(0x24,PC),r0              ! r0 = 0x0258
    mov.w   r6,@(r0,r2)               ! car[0x258] = 40 (gear shift sound)

! --- Finalization: zero out steering column (2 calls) ---
.L_input_finalize:                       ! 0x060083DE
    mov     #0,r5                        ! r5 = 0 (target value for interpolation)
    mov.l   @r4,r2                       ! r2 = car_object
    mov.w   @(0x1E,PC),r1              ! r1 = offset (first steering field)
    mov.l   @(0x2C,PC),r3              ! r3 = 0x06034F78 (interpolation function)
    jsr     @r3                          ! FUN_06034F78: interpolate field toward 0
    mov     r5,r0                        ! (delay) r0 = 0

    mov.l   @r4,r2                       ! r2 = car_object
    mov.w   @(0x16,PC),r1              ! r1 = offset (second steering field)
    mov.l   @(0x24,PC),r3              ! r3 = 0x06034F78
    jsr     @r3                          ! FUN_06034F78: interpolate second field
    mov     r5,r0                        ! (delay) r0 = 0

    lds.l   @r15+,pr                     ! Restore pr
    rts                                  ! Return
    nop


! ============================================================================
! CONFIDENCE: HIGH
! Decision tree verified: bit 0x08, 0x1BC guard, table selection via
! 0x0607EBC4 bit 23. Pool constants 0x060453B4/0x060453C4 confirmed.
! 0x06008640 — Steering / Force Table Selection (no label in aprog.s)
! ============================================================================
! Called as step 2 of player physics. Selects which force lookup table to
! use based on game state, then falls through to FUN_060086C0 which reads
! force vectors from the selected table.
!
! Decision tree:
!   1. If car flag bit 0x08 (special state) is SET:
!      - Clear the bit
!      - Check car+0x1BC (another field): if zero → goto FUN_060086C0
!      - Otherwise → early return at 0x06008730 (skip force update)
!   2. If car flag bit 0x08 is CLEAR:
!      - Check car+0x0D4: if non-zero → goto 0x06008730 (skip)
!      - Set steering timer to 20
!      - Check game state bitmask 0x800000 at 0x0607EBC4:
!        * If set → use table at 0x060453C4 (special/countdown mode)
!        * If clear → use table at 0x060453B4 (normal racing, indexed by
!          player_state & 1 × 8)
!      - Fall through to FUN_060086C0 with r4 = selected table pointer

! 0x06008640:
    mov.l   @(0x64,PC),r4              ! r4 = &0x0607E940
    mov.l   @r4,r2                       ! r2 = car_object
    mov     r2,r0
    mov.b   @r0,r0                       ! r0 = car[0] (flag byte)
    tst     #0x08,r0                     ! Special state flag set?
    bf      .L_special_clear             ! Yes → handle special state

    ! Normal path: check if force update should be skipped
    mov.l   @r4,r3
    mov.w   @(0x52,PC),r0              ! r0 = offset for mode field
    mov.l   @(r0,r3),r0               ! r0 = car[mode_field]
    tst     r0,r0                        ! Zero?
    bt      .L_early_return              ! Yes → no steering needed, return
    bra     .L_post_force_update         ! No → skip to post-force section
    nop

.L_special_clear:                        ! 0x0600865A
    ! Clear bit 0x08 in flag byte
    mov.l   @r4,r3
    mov.b   @r3,r0                       ! Read flags
    and     #0xF7,r0                     ! Clear bit 0x08
    or      #0x00,r0                     ! (no-op OR, artifact)
    mov.b   r0,@r3                       ! Write back

    ! Check secondary condition
    mov.l   @r4,r2
    mov.w   @(0x3A,PC),r0              ! r0 = offset for secondary field
    mov.l   @(r0,r2),r0               ! r0 = car[secondary]
    tst     r0,r0
    bt      .L_setup_steering            ! Zero → proceed with steering setup
    bra     .L_post_force_update
    nop

.L_early_return:                         ! 0x060086A0
    rts
    nop

.L_setup_steering:                       ! 0x06008672
    mov     #20,r3                       ! Steering timer = 20 frames
    mov.w   @(0x2E,PC),r0              ! r0 = offset for timer field
    mov.l   @r4,r2
    mov.w   r3,@(r0,r2)               ! car[timer] = 20

    ! Select force table based on game state
    mov.l   @(0x30,PC),r3              ! r3 = &0x0607EBC4 (game state bitmask)
    mov.l   @(0x30,PC),r2              ! r2 = 0x00800000
    mov.l   @r3,r3                       ! r3 = game_state_bitmask
    and     r2,r3                        ! Test bit 0x800000
    tst     r3,r3
    bt      .L_normal_table              ! Not set → normal table

    ! Special state → use table B
    mov.l   @(0x2C,PC),r4              ! r4 = &0x060453C4
    bra     FUN_060086C0                 ! Use table B
    mov.l   @r4,r4                       ! (delay) r4 = table_B_pointer

.L_normal_table:                         ! 0x0600868C
    mov.l   @(0x28,PC),r0              ! r0 = &0x0607EBD0
    mov.l   @r0,r0                       ! r0 = player_state
    and     #0x01,r0                     ! r0 &= 1 (select sub-table 0 or 1)
    mov     r0,r4
    shll2   r4                           ! r4 = index * 4
    shll    r4                           ! r4 = index * 8
    mov.l   @(0x20,PC),r3              ! r3 = 0x060453B4 (table A base)
    add     r3,r4                        ! r4 = &table_A[index]
    bra     FUN_060086C0
    mov.l   @r4,r4                       ! (delay) r4 = table entry pointer


! ============================================================================
! CONFIDENCE: HIGH
! Pool constants 0x0607EBD0, 0x0607E940, 0x06034F78, 0x0607EBEC
! match ground truth at 0x060086C0-0x06008712.
! FUN_060086C0 — Force Vector Extraction from Steering Table
! ============================================================================
! Reads a selected force table entry (r4 = pointer) and applies the force
! vectors to the car object.
!
! The force table entry is a 12-byte record:
!   +0x00: long  — (indirect pointer to sub-record)
!   +0x04: word  — steering factor
!   +0x06: word  — X force component (negated when applied)
!   +0x08: word  — Z force component (negated when applied)
!   +0x0A: word  — angular force (negated when applied)
!
! This function:
!   1. Calls FUN_06034F78 twice (interpolation of steering state)
!   2. Reads force record from r4's data
!   3. Stores steering factor, -X_force, -Z_force, -angular_force to car struct
!   4. Increments steering event counter at 0x0607EBEC

FUN_060086C0:                            ! 0x060086C0
    sts.l   pr,@-r15                     ! Save return address
    mov     #1,r6
    mov.l   @(0x58,PC),r7              ! r7 = &0x0607EBD0
    mov.l   @(0x5C,PC),r5              ! r5 = &0x0607E940
    mov.w   @(0x48,PC),r3              ! r3 = first offset
    mov.l   @r7,r0                       ! r0 = player_state
    mov.l   @r5,r2                       ! r2 = car_object
    and     r6,r0                        ! r0 &= 1
    add     r3,r2                        ! r2 = car + offset
    mov.l   @(0x54,PC),r3              ! r3 = 0x06034F78
    jsr     @r3                          ! First interpolation call
    mov     r6,r1                        ! (delay) r1 = 1

    ! Second interpolation call
    mov.l   @r5,r2
    mov.l   @r7,r0
    mov.w   @(0x34,PC),r3              ! Different offset for second call
    mov.w   @(0x34,PC),r1
    shar    r0                           ! r0 >>= 1 (divide state by 2)
    add     r3,r2                        ! r2 = car + offset2
    mov.l   @(0x40,PC),r3              ! r3 = 0x06034F78
    jsr     @r3                          ! Second interpolation call
    and     r6,r0                        ! (delay) r0 &= 1

    ! Read force record pointed to by r4
    mov.l   @r5,r2                       ! r2 = car_object
    mov.l   @r4,r3                       ! r3 = indirect pointer from table
    mov.w   @(0x26,PC),r0              ! r0 = offset for steering field
    mov.l   r3,@(r0,r2)               ! car[steering_field] = table_ptr

    mov.l   @(0x4,r4),r4               ! r4 = table entry sub-record
    mov.l   @r5,r3
    mov.w   @(0x20,PC),r0
    mov.l   r4,@(r0,r3)               ! car[offset] = sub-record pointer
    add     #-40,r4                      ! r4 -= 40 (back up to force data)
    mov.l   @r5,r3
    mov.w   @(0x1A,PC),r0
    mov.l   r4,@(r0,r3)               ! car[offset] = adjusted pointer

    ! Stores force data pointer to additional fields
    mov.l   @r5,r3
    mov.w   @(0x16,PC),r0
    mov.l   r4,@(r0,r3)               ! car[offset] = force_data

    ! Increment steering event counter
    mov.l   @(0x20,PC),r4              ! r4 = &0x0607EBEC
    mov.b   @r4,r3                       ! r3 = counter
    add     r6,r3                        ! counter += 1
    mov.b   r3,@r4                       ! Store back

    bra     .L_post_force_update         ! Continue to post-force section
    lds.l   @r15+,pr                     ! (delay) Restore pr


! ============================================================================
! CONFIDENCE: MEDIUM
! Only partially annotated. Key behavior (12-byte records, gas/brake via
! 0x40/0x80) consistent with force_tables.s but gas=0x40/brake=0x80 SPECULATIVE.
! AUDIT NOTE: Header says timers car+0x208/0x1E4 but 0x06008730 decrements
! 0x01BC/0x00BC. The 0x208/0x1E4 timers are in FUN_0600E71A step 6 instead.
! 0x06008730 — Post-Force Update: Timer Decrements & Steering Angle Read
! ============================================================================
! After force selection (or if skipped), this section:
!   1. Decrements car+0x208 timer (if positive)
!   2. Decrements car+0x1E4 timer (if positive)
!   3. Checks car mode field for value 10 (special mode)
!   4. Reads a 12-byte steering record from the record list:
!      - Advances record pointer by 12
!      - Reads word at record+0x04 → steering factor
!      - If bit 0x40 set in car flags: direct steering apply
!        (read +0x06, +0x08, +0x0A → negate → store as X/Z/angular forces)
!      - If bit 0x80 set: alternative steering path
!      - Otherwise: zero steering forces
!
! This is where the actual force vectors enter the car struct, driving
! the position update in FUN_0600C5D6.

.L_post_force_update:                    ! 0x06008730
    ! (Large section ~120 instructions: timer management, steering record
    !  processing, force vector extraction. See aprog.s 0x06008730-0x0600881A)
    !
    ! Key behavior:
    !   - Reads 12-byte records sequentially from a force data list
    !   - Each record contains: word steering_factor, word X, word Z, word angular
    !   - If car flag bit 0x40 (gas pedal?):
    !       car[X_force] = -record.X
    !       car[Z_force] = -record.Z
    !       car[angular]  = -record.angular
    !   - If car flag bit 0x80 (brake pedal?):
    !       Alternative force application path
    !   - This is the gas/brake → acceleration path:
    !       Controller buttons set flags in car[0] → flag bits 0x40/0x80
    !       These bits select which forces get applied from the current
    !       steering/force table record


! ============================================================================
! CONFIDENCE: HIGH
! Prologue, timer, speed table lookups verified instruction-by-instruction.
! Pool: FUN_06027552, table_A=0x060477EC, table_B=0x060454CC, offset=0xFEC00000,
! scale=0x00480000 all confirmed.
! FUN_0600C4F8 — Speed Computation & Velocity Clamping
! ============================================================================
! Step 4 of player physics. Computes the car's speed scalar from course
! data and clamps it to valid range.
!
! Uses FUN_06027552 (fixed-point multiply: r0 = (r4 × r5) >> 16, signed)
! Reads from two course tables:
!   0x060477EC[car.track_segment] — speed factor A
!   0x060454CC[car.track_segment] — speed factor B
!   Computes: base_speed = factor_A - factor_B + 0xFEC00000
!
! The result is clamped between a minimum (which may be zero) and maximum.
! Final speed stored to car+0x08.
!
! Also handles: game state check (0x0607EBC4 bit 0x8000 → bypass clamp),
! timer decrements for speed-related fields.

FUN_0600C4F8:                            ! 0x0600C4F8
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    sts.l   pr,@-r15
    mov.l   @(0x9C,PC),r13             ! r13 = 0x06027552 (multiply function)
    mov.l   @(0xA0,PC),r14             ! r14 -> 0x0607E940
    mov.w   @(0x88,PC),r0              ! r0 = offset for speed timer
    mov.l   @r14,r14                     ! r14 = car_object
    mov.w   @(r0,r14),r3              ! r3 = car[speed_timer]
    cmp/pl  r3                           ! timer > 0?
    bf      .L_speed_no_timer
    mov.w   @(0x7E,PC),r0
    mov.w   @(r0,r14),r2              ! r2 = sub-timer
    add     #-1,r2                       ! Decrement
    mov.w   r2,@(r0,r14)              ! Store back

.L_speed_no_timer:                       ! 0x0600C516
    ! Check game state for speed bypass
    mov.l   @(0x90,PC),r3              ! r3 = &0x0607EBC4
    mov.l   @(0x90,PC),r2              ! r2 = 0x00008000 (countdown bit)
    mov.l   @r3,r3
    and     r2,r3
    tst     r3,r3
    bf      .L_speed_exit                ! Countdown active → skip speed calc

    ! Compute speed from course data
    mov.w   @(0x6C,PC),r12             ! r12 = offset constant
    mov.w   @(0x6C,PC),r0
    mov.l   @(r0,r14),r3              ! r3 = car[field] — check positive
    cmp/pl  r3
    bt      .L_speed_do_calc
    mov.w   @(0x66,PC),r0
    mov.l   @(r0,r14),r0              ! Check another field
    tst     r0,r0
    bt      .L_speed_from_tables         ! Both zero → compute from tables

.L_speed_do_calc:                        ! 0x0600C534
    mov.w   @(0x60,PC),r0
    bra     .L_speed_final               ! Use existing value
    mov.l   r12,@(r0,r14)

.L_speed_from_tables:                    ! 0x0600C53A
    ! r14+0x08 = track segment index
    mov.l   @(0x8,r14),r4              ! r4 = segment_index
    mov.l   @(0x70,PC),r2              ! r2 = 0x060477EC (speed table A)
    mov.l   @(0x74,PC),r3              ! r3 = 0x060454CC (speed table B)
    shll2   r4                           ! r4 = index * 4
    add     r4,r2                        ! r2 = &table_A[index]
    add     r4,r3                        ! r3 = &table_B[index]
    mov.l   @r2,r2                       ! r2 = table_A[index]
    mov.l   @r3,r3                       ! r3 = table_B[index]
    mov.l   @(0x6C,PC),r4              ! r4 = 0xFEC00000 (base offset)
    sub     r3,r2                        ! r2 = A - B
    add     r2,r4                        ! r4 = A - B + 0xFEC00000
    jsr     @r13                         ! FUN_06027552(r4, r5=1) — normalize
    mov     #1,r5

    ! Apply clamping
    mov     r0,r4                        ! r4 = result
    mov.w   @(0x40,PC),r0
    jsr     @r13                         ! Second multiply for range check
    mov.l   @(r0,r14),r5              ! r5 = car[offset] (current speed)
    mov     r0,r5                        ! r5 = clamped_result
    mov.l   @(0xC,r14),r3              ! r3 = car[0xC] (acceleration)
    shar    r5                           ! r5 >>= 1 (halve)
    mov.w   @(0x36,PC),r0
    mov.l   @(r0,r14),r4              ! r4 = car[speed field]
    sub     r3,r4                        ! r4 = speed - accel
    cmp/ge  r12,r4                       ! r4 >= minimum?
    bt      .L_speed_check_max
    ! Below minimum → clamp to minimum
    mov.w   @(0x28,PC),r0
    bra     .L_speed_final
    mov.l   r12,@(r0,r14)

.L_speed_check_max:
    cmp/ge  r4,r5                        ! max >= speed?
    bt      .L_speed_store
    mov.w   @(0x1E,PC),r0
    bra     .L_speed_final
    mov.l   r5,@(r0,r14)              ! Clamp to max

.L_speed_store:
    mov.w   @(0x18,PC),r0
    mov.l   r4,@(r0,r14)              ! Store computed speed

.L_speed_final:                          ! 0x0600C580
    ! Final speed → heading scalar
    mov.l   @(0xC,r14),r4              ! r4 = car[0xC] (acceleration)
    mov.w   @(0x12,PC),r0
    mov.l   @(r0,r14),r3              ! r3 = car[speed_field]
    add     r3,r4                        ! r4 = accel + speed
    cmp/pl  r4                           ! Positive?
    bf      .L_speed_zero                ! No → zero it
    bra     .L_speed_output
    mov.l   r4,@(0xC,r14)              ! Store to car+0xC

.L_speed_zero:
    mov     #0,r2
    mov.l   r2,@(0xC,r14)              ! car[0xC] = 0 (no negative speed)

.L_speed_output:                         ! 0x0600C5C0
    ! Convert to heading-relative scalar via fixed-point multiply
    mov.l   @(0x58,PC),r5              ! r5 = 0x00480000 (scale factor)
    jsr     @r13                         ! FUN_06027552(r4=accel, r5=0x480000)
    mov.l   @(0xC,r14),r4              ! (delay) r4 = car[0xC]
    shlr16  r0                           ! r0 >>= 16 (take upper 16 bits)
    exts.w  r0,r0                        ! Sign extend
    mov.l   r0,@(0x8,r14)              ! car[0x08] = heading_speed

.L_speed_exit:                           ! 0x0600C5CC
    lds.l   @r15+,pr
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14


! ============================================================================
! CONFIDENCE: HIGH
! Prologue, pool constants, branching logic verified against ground truth.
! AUDIT NOTE: FUN_0600CD40 is more accurately checkpoint processing (returns
! track entry pointer), not collision detection per se.
! FUN_0600C5D6 — Collision Detection & Position Integration
! ============================================================================
! Step 5 of player physics. Detects collisions and integrates force vectors
! into actual X/Z position changes.
!
! Flow:
!   1. Call FUN_0600CD40 — collision check (returns collision_data in r0)
!   2. Read course type from 0x06087804
!   3. If course type == 2: special collision path
!   4. Otherwise: check multiple conditions (timers, flags)
!   5. Call FUN_0600CA96 or FUN_0600CC38 — collision response
!   6. Read heading from track data at 0x06078680+offset
!   7. Convert heading → direction vector via FUN_06027358
!   8. Position integration:
!        car.X += FUN_06027552(heading_speed, X_force)
!        car.Z += FUN_06027552(heading_speed, Z_force)
!        car.Y = 0 (flat ground assumed)
!
! This is where the forces extracted by FUN_060086C0 actually move the car.

FUN_0600C5D6:                            ! 0x0600C5D6
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    mov.l   r10,@-r15
    sts.l   pr,@-r15
    add     #-4,r15                      ! Local variable on stack

    mov.l   @(0x38,PC),r10             ! r10 = 0x06027552 (multiply)
    mov.l   @(0x3C,PC),r11             ! r11 = &0x0607EBDC (collision counter)
    mov.l   @(0x3C,PC),r14             ! r14 -> 0x0607E940
    mov.l   @(0x40,PC),r13             ! r13 = 0x06078680 (track collision data)

    bsr     FUN_0600CD40                 ! Collision detection
    mov.l   @r14,r14                     ! (delay) r14 = car_object

    mov     r0,r12                       ! r12 = collision_result
    mov.l   @(0x3C,PC),r0              ! r0 = &0x06087804 (course type)
    mov.w   @r0,r0                       ! Read course type
    extu.w  r0,r0
    cmp/eq  #2,r0                        ! Course type 2?
    bt/s    .L_collision_direct          ! Yes → direct collision path
    add     #24,r12                      ! r12 += 24 (adjust collision data offset)

    ! Check multiple timer/flag conditions
    mov.w   @(0x14,PC),r0
    mov.l   @(r0,r14),r2              ! Check timer field
    cmp/pl  r2
    bt      .L_collision_direct          ! Timer positive → proceed

    mov.w   @(0xE,PC),r0
    mov.l   @(r0,r14),r2              ! Check another field
    cmp/pl  r2
    bf      .L_collision_alt             ! Both non-positive → alternative path

.L_collision_direct:                     ! 0x0600C60E
    bsr     FUN_0600CA96                 ! Direct collision response
    mov     r13,r4                       ! r4 = track_data_base

    bra     .L_position_integrate
    nop

.L_collision_alt:                        ! 0x0600C634
    ! Alternative collision path (no active timers)
    ! Checks additional flags and calls FUN_0600CF58 or FUN_0600CC38
    ! ...
    ! (see aprog.s 0x0600C634-0x0600C690 for full logic)
    ! Eventually falls through to position integration

.L_position_integrate:                   ! ~0x0600C692
    ! Course type 3 special handling
    mov.l   @(0x74,PC),r0              ! r0 = &0x06087804
    mov.w   @r0,r0
    extu.w  r0,r0
    cmp/eq  #3,r0                        ! Course type 3?
    bf      .L_do_heading

    ! Course 3: extra multiply for heading
    mov.w   @(0x5C,PC),r0
    mov.l   @(r0,r14),r5              ! r5 = force value from car struct
    jsr     @r10                         ! FUN_06027552
    mov.l   @(0x8,r12),r4              ! (delay) r4 = collision_data[8]
    mov.w   @(0x56,PC),r1
    add     r14,r1
    mov.l   r0,@r1                       ! Store heading result

.L_do_heading:
    ! Apply heading from track data
    bsr     FUN_0600C8CC                 ! Heading calculation subroutine
    mov     r14,r4                       ! r4 = car_object

    ! Read object flags to check if position update allowed
    mov.l   @(0x58,PC),r2              ! r2 = &0x0607E940
    mov.l   @r2,r2
    mov.l   @r2,r3                       ! r3 = object_flags
    mov.l   @(0x58,PC),r2              ! r2 = 0x00E00000 (mask)
    and     r2,r3
    tst     r3,r3
    bf      .L_collision_done            ! Flags set → skip position update

    ! Read heading from track data → car+0x20
    mov.w   @(0xE,r13),r0              ! r0 = track_heading (from 06078680+0xE)
    mov     r0,r3
    mov.l   r0,@(0x20,r14)             ! car.heading = track_heading

    ! Convert heading to direction vector
    ! FUN_06027358: heading → (sin, cos) direction components
    mov.w   ...,r6                       ! r6 = destination offset (car + X_force)
    mov.w   ...,r5                       ! r5 = destination offset (car + Z_force)
    mov.l   @(0x28,r14),r4             ! r4 = current heading
    mov.l   @(0x48,PC),r3              ! r3 = 0x06027358
    add     r14,r6
    add     r14,r5
    jsr     @r3                          ! FUN_06027358(heading → direction)
    neg     r4,r4                        ! (delay) negate heading for direction

    ! === POSITION INTEGRATION ===
    ! car.X += FUN_06027552(car.speed, X_direction)
    mov.w   @(0x2A,PC),r0
    mov.l   @(r0,r14),r5              ! r5 = X_force (direction component)
    jsr     @r10                         ! FUN_06027552(r4=speed, r5=X_force)
    mov.l   @(0xC,r14),r4              ! (delay) r4 = car.speed
    mov.l   @(0x10,r14),r3             ! r3 = car.X
    add     r0,r3                        ! X += delta_X
    mov.l   r3,@(0x10,r14)             ! car.X = new_X

    ! car.Z += FUN_06027552(car.speed, Z_direction)
    mov.w   ...,r0
    mov.l   @(r0,r14),r5              ! r5 = Z_force
    jsr     @r10                         ! FUN_06027552(r4=speed, r5=Z_force)
    mov.l   @(0xC,r14),r4              ! (delay) r4 = car.speed
    mov.l   @(0x18,r14),r3             ! r3 = car.Z
    add     r0,r3                        ! Z += delta_Z
    mov.l   r3,@(0x18,r14)             ! car.Z = new_Z

    ! car.Y = 0 (2D racing, flat ground)
    mov     #0,r2
    bra     .L_collision_done
    mov.l   r2,@(0x14,r14)             ! car.Y = 0

.L_collision_done:
    ! ... (remainder: final cleanup, epilogue)
    ! (See aprog.s 0x0600C718+ for full epilogue)


! ============================================================================
! CONFIDENCE: HIGH
! Instruction sequence verified 0x0600CEBA-0x0600CF34. Segment table via
! 0x0607EB84, stride=4, heading interpolation via FUN_06035228 confirmed.
! FUN_0600CEBA — Track Segment Advancement & Heading Interpolation
! ============================================================================
! Step 7 of player physics. Checks if the car has moved past the current
! track segment boundary and advances to the next segment if so.
!
! Uses the track segment table at 0x0607EB84. Each segment has:
!   - X position, Z position, heading (word at +0x0A)
!   - Segment stride = 4 bytes per index (segment index * 4 = offset into table)
!
! Logic:
!   1. Read current segment index from car+0x184
!   2. Look up segment heading from table: segment_table[index].heading
!   3. Store as car's target heading (car+0x168, car+0x16C)
!   4. Call FUN_06035228 twice: interpolate car heading toward target
!   5. Compute delta = new_heading - old_heading
!   6. If delta > 0 AND delta > (car_count - 16):
!      → Car passed segment boundary
!      → Increment segment counters (car+0x1F0, car+0x1E4)
!      → Compute distance_remaining = [0x0607EBD0] - car[0x1F4]
!      → Store to car+0x1E0, car+0x1EC
!
! This drives the "progress around track" metric that determines race position.

FUN_0600CEBA:                            ! 0x0600CEBA
    sts.l   pr,@-r15
    mov.l   @(0x88,PC),r4              ! r4 = &0x0607E940
    mov.w   @(0x78,PC),r0              ! r0 = 0x0184 (segment index offset)
    mov.l   @(0x80,PC),r3              ! r3 = &0x0607EB84 (track segment table)
    mov.l   @r4,r4                       ! r4 = car_object
    mov.l   @r3,r3                       ! r3 = segment_table_base
    mov.l   @(r0,r4),r5               ! r5 = car[0x184] (current segment index)
    add     #104,r0                      ! r0 += 104 → offset 0x1EC
    shll2   r5                           ! r5 = index * 4
    mov.l   @(r0,r4),r2               ! r2 = car[0x1EC] (distance_remaining backup)
    add     r3,r5                        ! r5 = &segment_table[index]
    add     #4,r0                        ! r0 → offset 0x1F0
    mov.l   r2,@(r0,r4)               ! car[0x1F0] = distance backup
    mov.w   @r5,r3                       ! r3 = segment_table[index].heading
    add     #-4,r0                       ! r0 → offset 0x1EC
    extu.w  r3,r3                        ! Zero-extend heading
    mov.l   r3,@(r0,r4)               ! car[0x1EC] = target_heading

    ! Interpolate heading via FUN_06035228 (twice, for X and Z components)
    mov.w   @(0x5C,PC),r1
    mov.w   @(0x5C,PC),r2
    mov.l   @(0x68,PC),r3              ! r3 = 0x06035228 (heading interpolation)
    add     r4,r1                        ! r1 = &car[offset_A]
    add     r4,r2                        ! r2 = &car[offset_B]
    jsr     @r3                          ! FUN_06035228: interpolate heading A
    mov     #2,r0                        ! (delay) r0 = interpolation speed

    mov     r5,r2                        ! r2 = segment_table pointer
    mov.l   @(0x5C,PC),r3              ! r3 = 0x06035228
    mov.w   @(0x4C,PC),r1
    add     #2,r2                        ! r2 → next field in segment
    add     r4,r1
    jsr     @r3                          ! FUN_06035228: interpolate heading B
    mov     #2,r0

    ! Compute heading delta and check segment crossing
    mov.w   @(0x44,PC),r0
    mov.l   @(r0,r4),r6               ! r6 = car[new_heading]
    add     #-4,r0
    mov.l   @(r0,r4),r3               ! r3 = car[old_heading]
    sub     r3,r6                        ! r6 = delta (new - old)
    exts.w  r6,r6                        ! Sign extend
    exts.w  r6,r5                        ! r5 = delta (copy)
    cmp/pl  r5                           ! delta > 0? (moving forward)
    bf      .L_no_segment_cross          ! No → no crossing

    mov.l   @(0x44,PC),r2              ! r2 = &0x0607EA9C (car count)
    mov.l   @r2,r2                       ! r2 = car_count
    add     #-16,r2                      ! r2 = car_count - 16 (threshold)
    cmp/gt  r2,r5                        ! delta > threshold?
    bf      .L_no_segment_cross          ! No → not enough progress

    ! === SEGMENT CROSSED ===
    mov.w   @(0x2A,PC),r0
    mov.l   @(r0,r4),r2               ! r2 = car[segment_counter]
    add     #1,r2                        ! Increment
    mov.l   r2,@(r0,r4)               ! Store back
    add     #-12,r0
    mov.l   r2,@(r0,r4)               ! Copy to secondary counter

    ! Update distance remaining
    mov.l   @(0x30,PC),r5              ! r5 = &0x0607EBD0 (total distance)
    mov.l   @r5,r3                       ! r3 = total_distance
    add     #16,r0
    mov.l   @(r0,r4),r2               ! r2 = car[current_position]
    sub     r2,r3                        ! r3 = total - current = remaining
    add     #-12,r0
    mov.l   r3,@(r0,r4)               ! car[dist_offset_A] = remaining
    mov.l   @r5,r3                       ! r3 = total_distance (again)
    add     #12,r0
    mov.l   r3,@(r0,r4)               ! car[dist_offset_B] = total

.L_no_segment_cross:                     ! 0x0600CF34
    lds.l   @r15+,pr
    rts
    nop


! ============================================================================
! CONFIDENCE: MEDIUM
! AUDIT NOTE: Branch logic labels INVERTED. bt/s to 0x0600E948 (main AI
! processing) fires when car_index==0. Fall-through clears car[0xC] and exits.
! Label .L_ai_exit actually points to processing body, not exit path.
! FUN_0600E906 — AI Car Physics (for comparison)
! ============================================================================
! The AI counterpart to FUN_0600E71A. Much simpler — no controller input,
! no force tables. Instead uses track-following "chase" algorithm.
!
! If car_index == 0 (shouldn't happen for AI, safety check):
!   Clear car+0xC, branch to epilogue
! Otherwise:
!   1. jsr FUN_0600D266  — (stub, same as player)
!   2. jsr FUN_0600C74E  — AI-specific processing
!   3. Compute heading via FUN_06027552(car+0xC, 0x00480000)
!   4. Store heading to car+0x08 and car+0x30
!   5. jsr FUN_0600CEBA  — Track segment advancement (same as player!)
!   6. Score computation (same formula as player)
!   7. Check a flag: if zero, clear car+0x228 and car+0x1EC
!   8. Fall through to FUN_0600EA18 (track-following velocity, see race_update.s)

FUN_0600E906:                            ! 0x0600E906
    mov.l   r14,@-r15
    sts.l   pr,@-r15
    sts.l   macl,@-r15
    mov.l   @(0x30,PC),r14             ! r14 -> 0x0607E940
    mov.l   @(0x34,PC),r0              ! r0 = &0x0607EAD8 (car index)
    mov.l   @r0,r0                       ! r0 = car_index
    tst     r0,r0                        ! Is this car 0 (player)?
    bt/s    .L_ai_exit                   ! Yes (shouldn't happen) → exit
    mov.l   @r14,r14                     ! (delay) r14 = car_object

    ! Safety: clear acceleration if player car somehow entered AI path
    mov     #0,r3
    bra     .L_ai_epilogue
    mov.l   r3,@(0xC,r14)              ! car[0xC] = 0

    ! ... (exits through common epilogue) ...

.L_ai_exit:                              ! 0x0600E948
    ! Normal AI physics:
    mov.l   @(0xA4,PC),r3              ! r3 = 0x0600D266 (friction stub)
    jsr     @r3
    nop

    mov.l   @(0xA4,PC),r3              ! r3 = 0x0600C74E (AI processing)
    jsr     @r3
    nop

    ! Heading computation
    mov.l   @(0xA0,PC),r5              ! r5 = 0x00480000 (scale factor)
    mov.l   @(0xA4,PC),r3              ! r3 = 0x06027552 (multiply)
    jsr     @r3
    mov.l   @(0xC,r14),r4              ! (delay) r4 = car[0xC] (acceleration)
    shlr16  r0                           ! r0 >>= 16
    exts.w  r0,r0                        ! Sign extend
    mov.l   r0,@(0x8,r14)              ! car[0x08] = heading_speed

    ! Copy heading
    mov.l   @(0x20,r14),r2             ! r2 = car.heading
    mov.l   @(0xA0,PC),r3              ! r3 = 0x0600CEBA
    jsr     @r3                          ! Track segment advancement
    mov.l   r2,@(0x30,r14)             ! (delay) car[0x30] = heading copy

    ! Score computation (same as player)
    mov.w   ...,r0
    mov.l   @(r0,r14),r2
    ! ... multiply, add, store ...

    ! Falls through to FUN_0600EA18 (track-following velocity)
    ! See race_update.s for that function.

.L_ai_epilogue:                          ! 0x0600E994
    lds.l   @r15+,macl
    lds.l   @r15+,pr
    rts
    mov.l   @r15+,r14


! ============================================================================
! CONFIDENCE: DEFINITE
! Ground truth: rts + nop at 0x0600D266. Unambiguously a stub.
! FUN_0600D266 — Friction Stub (No-op)
! ============================================================================
! Both player and AI physics call this function. It immediately returns.
! This may be a placeholder for a friction/drag model that was removed or
! disabled. The address sits between two other functions in the binary.
!
! Speculation: friction may be baked into the force tables rather than
! computed as a separate step, making this function unnecessary.

FUN_0600D266:                            ! 0x0600D266
    rts
    nop
