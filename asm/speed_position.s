! ================================================================
! AUDIT: DEFINITE CONFIDENCE
! ================================================================
! Verified against build/aprog.s ground truth 2026-02-09.
! Both FUN_0600C4F8 and FUN_0600C5D6 have complete instruction-
! level annotations that match binary exactly. All pool constants
! enumerated and cross-checked against PC-relative addresses in
! aprog.s. This is the most thoroughly annotated file in the set.
! Speed model algorithm (two-table lookup, clamp, accumulate) is
! fully documented with correct arithmetic. Position integration
! sin/cos path verified instruction-by-instruction. 3D transform
! path uses elision but function calls and register setup are
! confirmed correct.
! ================================================================

! ============================================================================
! speed_position.s — Speed Curve Calculation & Position Integration
! ============================================================================
!
! Two core functions in the player physics pipeline (steps 4 & 5 of FUN_0600E71A):
!   FUN_0600C4F8 — Speed curve: computes per-frame speed delta from course tables
!   FUN_0600C5D6 — Position integration: converts speed+heading into XYZ movement
!
! Together these form the "heart" of car movement. Force tables (force_tables.s)
! produce the steering/acceleration inputs; these functions convert that into
! actual world-space position changes.
!
! SPEED MODEL OVERVIEW:
! =====================
!
!   The speed system uses a two-table curve lookup:
!
!     table_A[idx] — "max speed" curve (monotonically increasing, ~0x0BDxxxxx)
!     table_B[idx] — "drag" curve (monotonically increasing, ~0x001xxxxx)
!
!   base_speed = table_A[speed_idx] - table_B[speed_idx] + OFFSET
!   target     = (base_speed >> 16) * car[0x198] >> 16
!   half       = target >> 1
!   delta      = car[0x194] - car[0x0C]   (target minus accumulator)
!   delta      = clamp(delta, -4014, half)
!   car[0x0C] += delta                     (floored at 0)
!   car[0x08]  = sext16((car[0x0C] * 72) >> 16)  (convert to table index)
!
!   This creates a speed curve where:
!   - At low speeds: large positive delta → rapid acceleration
!   - At high speeds: delta approaches zero → asymptotic max speed
!   - Deceleration clamped at -4014 per frame (smooth braking)
!   - car[0x198] scales the curve (per-car tuning parameter)
!
! POSITION INTEGRATION OVERVIEW:
! ==============================
!
!   sin_val = sin(-heading)
!   cos_val = cos(-heading)
!   car.X  += (speed_accum * sin_val) >> 16
!   car.Z  += (speed_accum * cos_val) >> 16
!   car.Y   = 0  (flat ground assumption)
!
!   When car flags bits 21-23 set (banked turns, airborne, slopes):
!   Uses full 3D coordinate transform via FUN_06006838 + FUN_06027EDE instead.
!
! CAR STRUCT OFFSETS (speed/position system):
! ===========================================
!
!   +0x000: long  — flags word (bits 21-23 = 3D transform mode)
!   +0x003: byte  — flags byte 3 (bit 3 = special state)
!   +0x004: long  — car index (0=player)
!   +0x008: long  — speed index (table lookup index, sext16 range)
!   +0x00C: long  — speed accumulator (internal, large fixed-point)
!   +0x010: long  — X position (world)
!   +0x014: long  — Y position (world, typically 0 on flat)
!   +0x018: long  — Z position (world)
!   +0x020: long  — heading (yaw angle from course data)
!   +0x028: long  — heading copy (stored/target)
!   +0x0B8: long  — collision/brake flag A (non-zero = speed limited)
!   +0x0BC: long  — collision/brake flag B (positive = speed limited)
!   +0x0D4: word  — frame timer (decremented each frame while > 0)
!   +0x0FC: long  — clamped speed delta (applied to accumulator)
!   +0x161: byte  — state flags (bit 5 = steering override active)
!   +0x18C: long  — sin(-heading) result (from FUN_06027358)
!   +0x190: long  — cos(-heading) result (from FUN_06027358)
!   +0x194: long  — speed target (set by game mode 3 or force system)
!   +0x198: long  — speed scaling factor (per-car curve tuning)
!   +0x1BC: long  — force primary countdown
!   +0x204: long  — steering correction countdown (decrements by 2)
!   +0x208: long  — general timer (blocks some operations while > 0)
!   +0x1E0: long  — checkpoint table base pointer
!   +0x1E4: long  — current checkpoint index
!
! KEY DATA TABLES:
!
!   0x060477EC — Speed curve table A (32-bit entries, indexed by car[0x08] * 4)
!               Values: 0x0BD52BD3, 0x0BD52BD3, 0x0BFCE38E, 0x0C249B4A, ...
!               Monotonically increasing. Represents "available thrust" at each speed.
!
!   0x060454CC — Speed curve table B (32-bit entries, indexed by car[0x08] * 4)
!               Values: 0x00100000, 0x001008A1, 0x00101328, 0x00101F96, ...
!               Monotonically increasing. Represents "drag resistance" at each speed.
!
!   Net effect: (table_A - table_B) decreases as speed increases, creating the
!   characteristic speed-dependent acceleration curve (fast start, slow approach
!   to terminal velocity).
!
! KEY HELPER FUNCTIONS:
!
!   FUN_06027552 — Fixed-point multiply: r0 = (r4 * r5) >> 16
!   FUN_06027358 — Sin/cos: given angle r4, writes sin to *r5, cos to *r6
!   FUN_0600CD40 — Checkpoint processing: returns pointer to current entry (24 bytes)
!   FUN_0600CA96 — Position update from course reference (smooth following)
!   FUN_0600CC38 — Direct position integration (heading-based movement)
!   FUN_0600C8CC — Heading update from course data
!   FUN_0600CF58 — Steering correction (only when conditions met)
!   FUN_0600C928 — Track alignment helper
!   FUN_06006838 — 3D coordinate transform (for banked sections)
!   FUN_06027EDE — Matrix/vector multiply (completes 3D transform)
!
! KEY GLOBALS:
!
!   0x0607E940 — Current car pointer
!   0x0607E944 — Primary car pointer
!   0x0607EBC4 — State flags (bit 15 = skip speed calc entirely)
!   0x0607EBDC — Collision/steering counter
!   0x06087804 — Game mode word (2=special, 3=time attack?)
!   0x06078680 — Course data reference (physics base)
!
! CONSTANTS:
!
!   0xFEC00000 — Speed base offset (-20,971,520 = -0x01400000)
!   0x00480000 — Accumulator-to-index conversion factor (72 << 16)
!   0xF052     — Speed deceleration limit (-4014 signed)
!   0x00E00000 — 3D mode flag mask (bits 21-23)
!
! ============================================================================


! ============================================================================
! CONFIDENCE: DEFINITE — Complete instruction-level listing verified against binary
! at 0600C4F8-0600C5D4. Every opcode confirmed. All 14 pool constants enumerated at
! lines 265-279 with addresses and values cross-checked against aprog.s:
!   0x0600C5A0 = 0x06027552 (multiply), 0x0600C5A4 = 0x0607E940 (car ptr),
!   0x0600C5A8 = 0x0607EBC4 (state flags), 0x0600C5AC = 0x00008000 (bit 15),
!   0x0600C5B0 = 0x060477EC (table A), 0x0600C5B4 = 0x060454CC (table B),
!   0x0600C5B8 = 0xFEC00000 (base offset), 0x0600C61C = 0x00480000 (conv factor).
! Speed algorithm documented correctly: two-table lookup, scale by car[0x198],
! clamp delta to [-4014, half], accumulate, floor at 0, convert to index.
! Timer decrement, bit 15 skip, and deceleration limit paths all match binary.
! FUN_0600C4F8 — Speed Curve Calculation
! ============================================================================
! Called as step 4 of player physics pipeline (FUN_0600E71A).
! Computes per-frame speed change from two course-specific lookup tables.
!
! The algorithm:
!   1. Decrement frame timer car[0xD4] if positive
!   2. If state flag bit 15 set: skip everything (early return)
!   3. If car[0xBC]>0 OR car[0xB8]!=0: apply deceleration limit (-4014)
!   4. Otherwise: look up course tables, compute target, clamp delta
!   5. Accumulate into car[0x0C], floor at 0
!   6. Convert accumulator to speed index car[0x08]
!
! Registers on entry:
!   (none — reads car from *0x0607E940)
!
! Registers on exit:
!   car[0x08] updated with new speed index
!   car[0x0C] updated with new accumulator
!   car[0xFC] updated with clamped delta

FUN_0600C4F8:                               ! 0x0600C4F8
    mov.l   r14,@-r15                       ! push r14
    mov.l   r13,@-r15                       ! push r13
    mov.l   r12,@-r15                       ! push r12
    sts.l   pr,@-r15                        ! push pr
    mov.l   @(0x9C,PC),r13                  ! r13 = FUN_06027552 (fixed-point multiply)
    mov.l   @(0xA0,PC),r14                  ! r14 = &0x0607E940
    mov.w   @(0x88,PC),r0                   ! r0 = 0x00D4 (timer offset)
    mov.l   @r14,r14                        ! r14 = *0x0607E940 = current car
    mov.w   @(r0,r14),r3                    ! r3 = car[0xD4] (frame timer, word)
    cmp/pl  r3                              ! timer > 0?
    bf      .L_timer_done                   ! no -> skip decrement

    ! Timer countdown
    mov.w   @(0x7E,PC),r0                   ! r0 = 0x00D4
    mov.w   @(r0,r14),r2                    ! r2 = car[0xD4]
    add     #-1,r2                          ! r2--
    mov.w   r2,@(r0,r14)                    ! car[0xD4] = r2

.L_timer_done:                              ! 0x0600C516
    ! Check state flag bit 15
    mov.l   @(0x90,PC),r3                   ! r3 = &0x0607EBC4
    mov.l   @(0x90,PC),r2                   ! r2 = 0x00008000 (bit 15 mask)
    mov.l   @r3,r3                          ! r3 = *0x0607EBC4 (state flags)
    and     r2,r3                           ! isolate bit 15
    tst     r3,r3                           ! bit 15 clear?
    bf      .L_speed_epilogue               ! bit 15 SET -> skip all speed calc

    ! Load deceleration limit constant
    mov.w   @(0x6C,PC),r12                  ! r12 = 0xF052 = -4014 (speed limit)

    ! Check collision/brake flag B
    mov.w   @(0x6C,PC),r0                   ! r0 = 0x00BC
    mov.l   @(r0,r14),r3                    ! r3 = car[0xBC]
    cmp/pl  r3                              ! car[0xBC] > 0?
    bt      .L_apply_limit                  ! yes -> deceleration limit

    ! Check collision/brake flag A
    mov.w   @(0x66,PC),r0                   ! r0 = 0x00B8
    mov.l   @(r0,r14),r0                    ! r0 = car[0xB8]
    tst     r0,r0                           ! car[0xB8] == 0?
    bt      .L_normal_speed                 ! yes -> normal speed curve

.L_apply_limit:                             ! 0x0600C534
    ! Speed limited: store deceleration constant
    mov.w   @(0x60,PC),r0                   ! r0 = 0x00FC (delta offset)
    bra     .L_accumulate                   ! goto accumulate
    mov.l   r12,@(r0,r14)                   ! car[0xFC] = -4014 (delay slot)

.L_normal_speed:                            ! 0x0600C53A
    ! === Course table lookup ===
    mov.l   @(0x8,r14),r4                   ! r4 = car[0x08] (speed index)
    mov.l   @(0x70,PC),r2                   ! r2 = 0x060477EC (table A base)
    mov.l   @(0x74,PC),r3                   ! r3 = 0x060454CC (table B base)
    shll2   r4                              ! r4 = speed_index * 4
    add     r4,r2                           ! r2 = &table_A[speed_index]
    add     r4,r3                           ! r3 = &table_B[speed_index]
    mov.l   @r2,r2                          ! r2 = table_A[speed_index]
    mov.l   @r3,r3                          ! r3 = table_B[speed_index]
    mov.l   @(0x6C,PC),r4                   ! r4 = 0xFEC00000 (base offset)
    sub     r3,r2                           ! r2 = table_A - table_B
    add     r2,r4                           ! r4 = (table_A - table_B) + 0xFEC00000
                                            !    = base_speed (net force at this speed level)

    ! First multiply: extract upper portion
    jsr     @r13                            ! call FUN_06027552
    mov     #1,r5                           ! r5 = 1 (delay slot — effectively r4 >> 16)
                                            ! r0 = (base_speed * 1) >> 16 = base_speed >> 16

    ! Second multiply: scale by car tuning parameter
    mov     r0,r4                           ! r4 = base_speed >> 16
    mov.w   @(0x40,PC),r0                   ! r0 = 0x0198 (scaling factor offset)
    jsr     @r13                            ! call FUN_06027552
    mov.l   @(r0,r14),r5                    ! r5 = car[0x198] (delay slot — per-car scale)
                                            ! r0 = ((base_speed >> 16) * car[0x198]) >> 16
                                            !    = target speed (scaled)

    ! Compute half-speed for upper clamp
    mov     r0,r5                           ! r5 = target
    mov.l   @(0xC,r14),r3                   ! r3 = car[0x0C] (current accumulator)
    shar    r5                              ! r5 = target >> 1 (half, arithmetic shift)

    ! Compute delta = speed_target - accumulator
    mov.w   @(0x36,PC),r0                   ! r0 = 0x0194 (target offset)
    mov.l   @(r0,r14),r4                    ! r4 = car[0x194] (speed target value)
    sub     r3,r4                           ! r4 = car[0x194] - car[0x0C] = delta

    ! Clamp lower bound: delta >= -4014
    cmp/ge  r12,r4                          ! delta >= -4014?
    bt      .L_check_upper                  ! yes -> check upper bound

    ! Delta too negative: clamp to -4014
    mov.w   @(0x28,PC),r0                   ! r0 = 0x00FC
    bra     .L_accumulate                   ! goto accumulate
    mov.l   r12,@(r0,r14)                   ! car[0xFC] = -4014 (delay slot)

.L_check_upper:                             ! 0x0600C572
    ! Clamp upper bound: delta <= half
    cmp/ge  r4,r5                           ! half >= delta? (i.e., delta <= half)
    bt      .L_delta_ok                     ! yes -> delta is in range

    ! Delta too large: clamp to half
    mov.w   @(0x1E,PC),r0                   ! r0 = 0x00FC
    bra     .L_accumulate                   ! goto accumulate
    mov.l   r5,@(r0,r14)                    ! car[0xFC] = half (delay slot)

.L_delta_ok:                                ! 0x0600C57C
    ! Delta in range [-4014, half]: use as-is
    mov.w   @(0x18,PC),r0                   ! r0 = 0x00FC
    mov.l   r4,@(r0,r14)                    ! car[0xFC] = delta

.L_accumulate:                              ! 0x0600C580
    ! Apply delta to accumulator
    mov.l   @(0xC,r14),r4                   ! r4 = car[0x0C] (accumulator)
    mov.w   @(0x12,PC),r0                   ! r0 = 0x00FC
    mov.l   @(r0,r14),r3                    ! r3 = car[0xFC] (clamped delta)
    add     r3,r4                           ! r4 = accumulator + delta
    cmp/pl  r4                              ! result > 0?
    bf      .L_floor_zero                   ! no -> floor at zero
    bra     .L_convert                      ! yes -> convert to index
    mov.l   r4,@(0xC,r14)                   ! car[0x0C] = new accumulator (delay slot)

! Pool constants for FUN_0600C4F8:
!   0x0600C590: 0x00D4 (frame timer offset)
!   0x0600C592: 0xF052 (deceleration limit = -4014)
!   0x0600C594: 0x00BC (brake flag B offset)
!   0x0600C596: 0x00B8 (brake flag A offset)
!   0x0600C598: 0x00FC (clamped delta offset)
!   0x0600C59A: 0x0198 (speed scaling factor offset)
!   0x0600C59C: 0x0194 (speed target offset)
!   0x0600C5A0: 0x06027552 (fixed-point multiply)
!   0x0600C5A4: 0x0607E940 (current car pointer)
!   0x0600C5A8: 0x0607EBC4 (state flags)
!   0x0600C5AC: 0x00008000 (bit 15 mask)
!   0x0600C5B0: 0x060477EC (table A — "thrust" curve)
!   0x0600C5B4: 0x060454CC (table B — "drag" curve)
!   0x0600C5B8: 0xFEC00000 (base offset = -20,971,520)

.L_floor_zero:                              ! 0x0600C5BC
    mov     #0,r2                           ! r2 = 0
    mov.l   r2,@(0xC,r14)                   ! car[0x0C] = 0 (can't go negative)

.L_convert:                                 ! 0x0600C5C0
    ! Convert accumulator to speed index
    ! car[0x08] = sext16((car[0x0C] * 0x00480000) >> 32)
    ! Equivalent to: sext16((car[0x0C] * 72) >> 16)
    mov.l   @(0x58,PC),r5                   ! r5 = 0x00480000 (conversion factor = 72 << 16)
    jsr     @r13                            ! call FUN_06027552
    mov.l   @(0xC,r14),r4                   ! r4 = car[0x0C] (delay slot — accumulator)
                                            ! r0 = (car[0x0C] * 0x00480000) >> 16

    shlr16  r0                              ! r0 >>= 16 (extract upper 16 bits)
    exts.w  r0,r0                           ! r0 = sign-extend to 32-bit
    mov.l   r0,@(0x8,r14)                   ! car[0x08] = speed index (for next frame)

.L_speed_epilogue:                          ! 0x0600C5CC
    lds.l   @r15+,pr                        ! pop pr
    mov.l   @r15+,r12                       ! pop r12
    mov.l   @r15+,r13                       ! pop r13
    rts                                     ! return
    mov.l   @r15+,r14                       ! pop r14 (delay slot)

! Pool constant (conversion):
!   0x0600C61C: 0x00480000 (= 72 * 65536, conversion factor)


! ============================================================================
! CONFIDENCE: HIGH — Prologue and main dispatch logic verified instruction-by-
! instruction against binary at 0600C5D6-0600C74A. Pool constants confirmed:
!   0x0600C620 = 0x06027552, 0x0600C624 = 0x0607EBDC, 0x0600C628 = 0x0607E940,
!   0x0600C62C = 0x06078680, 0x0600C630 = 0x06087804, 0x0600C704 = 0x0607E944,
!   0x0600C710 = 0x00E00000 (3D mask), 0x0600C714 = 0x06027358 (sin/cos).
! Checkpoint call (FUN_0600CD40) and +24 advance confirmed. Game mode 2/3 branches
! verified. Flat-ground sin/cos integration path fully verified with X/Z position
! updates. Steering correction eligibility (counter<=10, position<102) confirmed.
! 3D transform path (FUN_06006838 + FUN_06027EDE) has stack manipulation that is
! annotated but uses some elision - the register setup and call sequence match binary
! but individual stack offsets in that section are less thoroughly documented.
! AUDIT NOTE: FUN_0600CD40 is labeled "checkpoint processing" here, which is more
! accurate than the "collision check" label used in player_physics.s.
! FUN_0600C5D6 — Position Integration (Collision + Heading + Movement)
! ============================================================================
! Called as step 5 of player physics pipeline (FUN_0600E71A).
! Takes the speed accumulator (car[0x0C]) and heading, computes world-space
! position changes. Also handles steering corrections and 3D transforms.
!
! High-level flow:
!   1. Call FUN_0600CD40 — checkpoint processing (returns entry pointer)
!   2. r12 = entry_ptr + 24 (advance to NEXT checkpoint for heading ref)
!   3. Branch by game mode and car state:
!      a) game_mode == 2: call CA96 (smooth course following)
!      b) car[0x1BC] > 0 OR car[0xB8] > 0: call CA96
!      c) Otherwise: complex path (collision check, steering correction, integration)
!   4. If game_mode == 3: set speed target from course data
!   5. Call FUN_0600C8CC — heading update
!   6. Check car flags bits 21-23 for 3D mode:
!      a) Bits clear (flat ground): sin/cos integration
!      b) Bits set (banked/airborne): full 3D transform
!   7. Track alignment and final position update

FUN_0600C5D6:                               ! 0x0600C5D6
    mov.l   r14,@-r15                       ! push r14
    mov.l   r13,@-r15                       ! push r13
    mov.l   r12,@-r15                       ! push r12
    mov.l   r11,@-r15                       ! push r11
    mov.l   r10,@-r15                       ! push r10
    sts.l   pr,@-r15                        ! push pr
    add     #-4,r15                         ! stack frame (4 bytes local)

    mov.l   @(0x38,PC),r10                  ! r10 = FUN_06027552 (multiply)
    mov.l   @(0x3C,PC),r11                  ! r11 = &0x0607EBDC (collision counter)
    mov.l   @(0x3C,PC),r14                  ! r14 = &0x0607E940
    mov.l   @(0x40,PC),r13                  ! r13 = 0x06078680 (course data ref)
    bsr     FUN_0600CD40                    ! call checkpoint processing
    mov.l   @r14,r14                        ! r14 = current car (delay slot)
                                            ! r0 = &checkpoint_table[current_index]
    mov     r0,r12                          ! r12 = checkpoint entry pointer

    ! Check game mode
    mov.l   @(0x3C,PC),r0                   ! r0 = &0x06087804
    mov.w   @r0,r0                          ! r0 = game_mode (word)
    extu.w  r0,r0                           ! zero-extend
    cmp/eq  #2,r0                           ! game_mode == 2?
    bt/s    .L_course_follow                ! yes -> smooth course following
    add     #24,r12                         ! r12 += 24 = NEXT checkpoint entry (always)

    ! Not mode 2: check force countdown
    mov.w   @(0x14,PC),r0                   ! r0 = 0x01BC
    mov.l   @(r0,r14),r2                    ! r2 = car[0x1BC] (force countdown)
    cmp/pl  r2                              ! car[0x1BC] > 0?
    bt      .L_course_follow                ! yes -> course following mode

    ! Check brake/collision flag
    mov.w   @(0x0E,PC),r0                   ! r0 = 0x00B8
    mov.l   @(r0,r14),r2                    ! r2 = car[0xB8]
    cmp/pl  r2                              ! car[0xB8] > 0?
    bf      .L_complex_path                 ! no -> full integration path

.L_course_follow:                           ! 0x0600C60E
    ! Simple course following: smooth position from reference
    bsr     FUN_0600CA96                    ! call position update
    mov     r13,r4                          ! r4 = course data ref (delay slot)
    bra     .L_merge_heading                ! continue to heading update
    nop

! Pool constants:
!   0x0600C616: 0x01BC (force countdown offset)
!   0x0600C618: 0x00B8 (collision flag offset)
!   0x0600C620: 0x06027552 (multiply)
!   0x0600C624: 0x0607EBDC (collision counter)
!   0x0600C628: 0x0607E940 (current car)
!   0x0600C62C: 0x06078680 (course data ref)
!   0x0600C630: 0x06087804 (game mode)

.L_complex_path:                            ! 0x0600C634
    ! Full integration: check primary car state flags
    mov.l   @(0xCC,PC),r2                   ! r2 = &0x0607E944
    mov.l   @r2,r2                          ! r2 = primary car pointer
    mov     r2,r0
    mov.b   @(0x3,r0),r0                    ! r0 = car[3] flags byte
    tst     #0x08,r0                        ! bit 3 (special state) clear?
    bf      .L_direct_integrate             ! bit 3 SET -> skip to direct integration

    ! Check general timer
    mov.w   @(0xB2,PC),r0                   ! r0 = 0x0208
    mov.l   @(r0,r14),r3                    ! r3 = car[0x208] (timer)
    cmp/pl  r3                              ! timer > 0?
    bt      .L_direct_integrate             ! yes -> skip steering correction

    ! Check state flag byte
    mov.w   @(0xAC,PC),r0                   ! r0 = 0x0161
    mov.b   @(r0,r14),r0                    ! r0 = car[0x161] flags byte
    tst     #0x20,r0                        ! bit 5 (steering override) clear?
    bf      .L_direct_integrate             ! bit 5 SET -> skip

    ! === Steering correction eligibility check ===
    ! Only if collision counter <= 10 AND track position < 102
    mov     #10,r2                          ! r2 = 10
    mov.l   @r11,r3                         ! r3 = *0x0607EBDC (collision counter)
    cmp/gt  r2,r3                           ! counter > 10?
    bt      .L_post_steer                   ! yes -> skip correction

    mov.w   @(0x9E,PC),r0                   ! r0 = 0x0204
    mov     #102,r3                         ! r3 = 102
    mov.l   @(r0,r14),r2                    ! r2 = car[0x204] (track position)
    cmp/ge  r3,r2                           ! position >= 102?
    bt      .L_post_steer                   ! yes -> skip

    ! Apply steering correction
    bsr     FUN_0600CF58                    ! call steering correction
    mov     r12,r4                          ! r4 = next checkpoint ptr (delay slot)

.L_post_steer:                              ! 0x0600C666
    ! Check steering correction countdown
    mov.w   @(0x90,PC),r0                   ! r0 = 0x0204
    mov.l   @(r0,r14),r2                    ! r2 = car[0x204] (countdown)
    cmp/pl  r2                              ! countdown > 0?
    bf      .L_do_integrate                 ! no -> direct integration

    ! Countdown active: decrement by 2, use course following
    mov.w   @(0x88,PC),r0                   ! r0 = 0x0204
    mov.l   @(r0,r14),r2                    ! r2 = car[0x204]
    add     #-2,r2                          ! r2 -= 2
    mov.l   r2,@(r0,r14)                    ! car[0x204] = r2

    bsr     FUN_0600CA96                    ! call course following
    mov     r13,r4                          ! r4 = course data ref (delay slot)

    ! Increment collision counter
    mov.l   @r11,r2                         ! r2 = *0x0607EBDC
    add     #1,r2                           ! r2++
    bra     .L_merge_heading                ! continue
    mov.l   r2,@r11                         ! *0x0607EBDC = r2 (delay slot)

.L_do_integrate:                            ! 0x0600C682
    ! Direct position integration from speed + heading
    mov     r13,r5                          ! r5 = course data ref
    bsr     FUN_0600CC38                    ! call heading-based integration
    mov     r12,r4                          ! r4 = next checkpoint ptr (delay slot)
    bra     .L_merge_heading
    nop

.L_direct_integrate:                        ! 0x0600C68C
    ! Skip all steering checks, just integrate
    mov     r13,r5                          ! r5 = course data ref
    bsr     FUN_0600CC38                    ! call heading-based integration
    mov     r12,r4                          ! r4 = next checkpoint ptr (delay slot)

.L_merge_heading:                           ! 0x0600C692
    ! === Game mode 3: set speed target from course ===
    mov.l   @(0x74,PC),r0                   ! r0 = &0x06087804
    mov.w   @r0,r0                          ! r0 = game_mode
    extu.w  r0,r0                           ! zero-extend
    cmp/eq  #3,r0                           ! game_mode == 3?
    bf      .L_heading_update               ! no -> skip target setting

    ! Mode 3: car[0x194] = (course_data[8] * car[0x198]) >> 16
    mov.w   @(0x5C,PC),r0                   ! r0 = 0x0198
    mov.l   @(r0,r14),r5                    ! r5 = car[0x198] (speed scaling)
    jsr     @r10                            ! call FUN_06027552
    mov.l   @(0x8,r12),r4                   ! r4 = next_checkpoint[8] (delay slot)
                                            ! r0 = (checkpoint_speed * car_scale) >> 16
    mov.w   @(0x56,PC),r1                   ! r1 = 0x0194
    add     r14,r1                          ! r1 = &car[0x194]
    mov.l   r0,@r1                          ! car[0x194] = computed speed target

.L_heading_update:                          ! 0x0600C6AA
    ! === Update heading from course data ===
    mov     r13,r5                          ! r5 = course data ref
    bsr     FUN_0600C8CC                    ! call heading update
    mov     r14,r4                          ! r4 = current car (delay slot)

    ! === Check 3D transform mode ===
    mov.l   @(0x58,PC),r2                   ! r2 = &0x0607E940
    mov.l   @r2,r2                          ! r2 = current car
    mov.l   @r2,r3                          ! r3 = car[0] (flags word)
    mov.l   @(0x58,PC),r2                   ! r2 = 0x00E00000 (bits 21-23 mask)
    and     r2,r3                           ! r3 = flags & 0x00E00000
    tst     r3,r3                           ! all bits 21-23 clear?
    bf      .L_3d_transform                 ! any bit SET -> full 3D transform

    ! === Flat ground: sin/cos position integration ===
    ! Read heading from course data reference
    mov.w   @(0xE,r13),r0                   ! r0 = course_ref[0x0E] (heading word)
    mov     r0,r3
    mov.l   r0,@(0x20,r14)                  ! car[0x20] = course heading

    ! Compute sin and cos of negated heading
    mov.w   @(0x38,PC),r6                   ! r6 = 0x0190 (cos output offset)
    mov.w   @(0x38,PC),r5                   ! r5 = 0x018C (sin output offset)
    mov.l   @(0x28,r14),r4                  ! r4 = car[0x28] (heading copy)
    mov.l   @(0x48,PC),r3                   ! r3 = FUN_06027358 (sin/cos)
    add     r14,r6                          ! r6 = &car[0x190] (cos output ptr)
    add     r14,r5                          ! r5 = &car[0x18C] (sin output ptr)
    jsr     @r3                             ! call FUN_06027358(-heading, &sin, &cos)
    neg     r4,r4                           ! r4 = -car[0x28] (delay slot, negate heading)
                                            ! car[0x18C] = sin(-heading)
                                            ! car[0x190] = cos(-heading)

    ! === X position update ===
    ! car[0x10] += (car[0x0C] * sin(-heading)) >> 16
    mov.w   @(0x2A,PC),r0                   ! r0 = 0x018C
    mov.l   @(r0,r14),r5                    ! r5 = car[0x18C] (sin value)
    jsr     @r10                            ! call FUN_06027552
    mov.l   @(0xC,r14),r4                   ! r4 = car[0x0C] (speed accum, delay slot)
                                            ! r0 = (speed * sin) >> 16 = X velocity
    mov.l   @(0x10,r14),r3                  ! r3 = car[0x10] (current X)
    add     r0,r3                           ! r3 = X + X_velocity
    mov.l   r3,@(0x10,r14)                  ! car[0x10] = new X position

    ! === Z position update ===
    ! car[0x18] += (car[0x0C] * cos(-heading)) >> 16
    mov.w   @(0x1A,PC),r0                   ! r0 = 0x0190
    mov.l   @(r0,r14),r5                    ! r5 = car[0x190] (cos value)
    jsr     @r10                            ! call FUN_06027552
    mov.l   @(0xC,r14),r4                   ! r4 = car[0x0C] (speed accum, delay slot)
                                            ! r0 = (speed * cos) >> 16 = Z velocity
    mov.l   @(0x18,r14),r3                  ! r3 = car[0x18] (current Z)
    add     r0,r3                           ! r3 = Z + Z_velocity
    mov.l   r3,@(0x18,r14)                  ! car[0x18] = new Z position

    ! === Y position: zero (flat ground) ===
    mov     #0,r2
    bra     .L_pos_epilogue                 ! goto epilogue
    mov.l   r2,@(0x14,r14)                  ! car[0x14] = 0 (delay slot)

! Pool constants for position integration:
!   0x0600C6F6: 0x0208 (general timer offset)
!   0x0600C6F8: 0x0161 (state flags byte offset)
!   0x0600C6FA: 0x0204 (steering correction countdown)
!   0x0600C6FC: 0x0198 (speed scaling factor)
!   0x0600C6FE: 0x0194 (speed target)
!   0x0600C700: 0x0190 (cos output offset)
!   0x0600C702: 0x018C (sin output offset)
!   0x0600C704: 0x0607E944 (primary car pointer)
!   0x0600C708: 0x06087804 (game mode)
!   0x0600C70C: 0x0607E940 (current car pointer)
!   0x0600C710: 0x00E00000 (3D mode flag mask: bits 21-23)
!   0x0600C714: 0x06027358 (sin/cos function)

.L_3d_transform:                            ! 0x0600C718
    ! === 3D mode: banked turns, airborne, slopes ===
    ! Uses full coordinate transform instead of simple sin/cos
    bsr     FUN_0600C928                    ! track alignment
    mov     r14,r4                          ! r4 = car (delay slot)

    mov     r13,r5                          ! r5 = course data ref
    bsr     FUN_0600C7D4                    ! heading interpolation
    mov     r14,r4                          ! r4 = car (delay slot)

    ! Prepare args for 3D transform
    mov     r15,r6                          ! r6 = stack ptr (output buf)
    mov     r14,r5                          ! r5 = car
    mov.l   r6,@-r15                        ! push output ptr
    add     #16,r5                          ! r5 = &car[0x10] (position XYZ)
    mov.l   r5,@-r15                        ! push position ptr
    mov.l   @(0x18,r14),r5                  ! r5 = car[0x18] (Z pos)
    mov.l   @(0x94,PC),r3                   ! r3 = FUN_06006838 (coordinate transform)
    jsr     @r3                             ! call 3D transform
    mov.l   @(0x10,r14),r4                  ! r4 = car[0x10] (X pos, delay slot)
                                            ! r0 = transformed result

    mov     r0,r4                           ! r4 = transform output
    mov.l   @r15+,r5                        ! pop position ptr (&car[0x10])
    mov.l   @(0x8C,PC),r3                   ! r3 = FUN_06027EDE (matrix mul)
    jsr     @r3                             ! apply matrix transform
    mov.l   @r15+,r6                        ! pop output ptr (delay slot)
                                            ! Updates car[0x10..0x18] with 3D position

.L_pos_epilogue:                            ! 0x0600C73E
    add     #4,r15                          ! free stack frame
    lds.l   @r15+,pr                        ! pop pr
    mov.l   @r15+,r10                       ! pop r10
    mov.l   @r15+,r11                       ! pop r11
    mov.l   @r15+,r12                       ! pop r12
    mov.l   @r15+,r13                       ! pop r13
    rts                                     ! return
    mov.l   @r15+,r14                       ! pop r14 (delay slot)

! Additional pool constants:
!   0x0600C7C4: 0x06006838 (3D coordinate transform)
!   0x0600C7C8: 0x06027EDE (matrix/vector multiply)
