! ============================================================
! AUDIT: HIGH
! Per-car loop alternative path. FUN_0600E0C0 verified as real label
! with prologue and register assignments matching ground truth exactly.
! FUN_0600E99C verified as real label. FUN_0600C302 has NO label in
! aprog.s -- it is mid-function code (address 0x0600C302 follows the
! rts at 0x0600C2FE of the previous function). The annotation correctly
! notes this ("no label in aprog.s").
! FUN_06030A06 and FUN_06030EE0 have no labels but ARE real function
! entry points (called via jsr from pool constants). The "wheel/tire"
! and "suspension" labels for these are SPECULATIVE -- FUN_06030EE0 is
! just a 6-instruction timer decrement function.
! Player vs AI branch logic verified correct in ground truth.
! ============================================================
!
! =============================================================================
! Per-Car Racing Loop (Alternative Path)
! =============================================================================
!
! FUN_0600E0C0 — Main per-car update loop (called from FUN_0600DE54)
! FUN_0600E99C — Pre-update camera/AI setup (called from FUN_0600DE54)
! FUN_0600C302 — Car state finalize (called from State 15)
!
! These are the "alternative" paths through the per-car iteration.
! FUN_0600DE70 (in object_management.s) is the master iteration loop.
! FUN_0600E0C0 is the inner loop that runs physics+rendering per car.
!
! Call chain:
!   State 15 (FUN_06009098)
!     -> FUN_0600DE70 (per-car iteration, object_management.s)
!       -> FUN_0600DF66 (mode dispatcher)
!         -> FUN_0600E4F2 (mode 1: full 9-stage pipeline)
!         -> FUN_0600E410 (mode 0: simplified pre-race)
!         -> FUN_0600E47C (mode 2: replay)
!     -> FUN_0600C302 (car finalize)
!     -> FUN_0600A914 (collision detection, car_collision.s)
!     -> FUN_060302C6 (engine sound, engine_sound.s)
!     -> FUN_0600A8BC (audio phase, engine_sound.s)
!
! FUN_0600E0C0 is an ALTERNATIVE per-car loop used from FUN_0600DE54
! (the race state update path), not from the main State 15 loop.

! =============================================================================
! CONFIDENCE: HIGH — prologue, register map, and loop structure verified
! Ground truth confirms: r8=0x0607EBC4, r9=0x06078900, r10=word pool,
! r11=0x00008000, r12=0x0607E940, r14=FUN_06027CA4. Demo mode skip
! via 0x0607EAE0 confirmed. Loop starts at car index 1 (not 0).
! AUDIT NOTE: FUN_06030A06 called "subsystem A (wheel/tire?)" and
! FUN_06030EE0 called "subsystem B (suspension?)" are SPECULATIVE labels.
! FUN_06030EE0 is a tiny timer decrement (6 insns: read word at car+0x150,
! decrement if positive, write back, return). Not clearly "suspension."
! FUN_06030A06 is slightly larger but still a timer-like function.
! The 4 scene buffer addresses (0x06063EB0, 0x06063E9C, 0x06063ED8,
! 0x06063EC4) and the "buffer 0-3" interpretation as different view
! angles is SPECULATIVE but structurally plausible.
! FUN_0600E0C0 — Per-Car Update (Racing Mode, Alternative)
! =============================================================================
! Called from: FUN_0600DE54 inner path
! Purpose: Iterate all cars, run subsystem updates + physics + rendering
!
! Register map:
!   r8  = 0x0607EBC4 (master flags)
!   r9  = 0x06078900 (car array base)
!   r10 = 0x0268 (car struct size, loaded from pool)
!   r11 = 0x00008000 (player flag bitmask)
!   r12 = 0x0607E940 (current car pointer storage)
!   r13 = loop counter (car index)
!   r14 = FUN_06027CA4 (3D scene renderer — called 4x per car)
!
! Algorithm:
!   if (*0x0607EAE0 != 0): return  (skip in demo/replay mode)
!   r13 = 1  (start at car index 1, not player)
!
!   for each car:
!     car_ptr = r13 * 0x268 + 0x06078900
!     *0x0607E940 = car_ptr
!
!     call FUN_06030A06(car_ptr)   -- subsystem A (wheel/tire?)
!     call FUN_06030EE0()          -- subsystem B (suspension?)
!
!     if (*r8 & 0x00008000):       -- player flag
!       call FUN_0600E906()        -- AI update path
!     else:
!       call FUN_0600E71A()        -- player physics pipeline
!
!     if (car->byte[1] & 0x80):    -- render flag
!       call FUN_060061C8()        -- pre-render setup
!       call FUN_06027CA4(0x06063EB0, 0)  -- scene buffer 0
!       call FUN_06027CA4(0x06063E9C, 1)  -- scene buffer 1
!       call FUN_06027CA4(0x06063ED8, 2)  -- scene buffer 2
!       call FUN_06027CA4(0x06063EC4, 3)  -- scene buffer 3
!       call FUN_0603053C(1)       -- finalize render
!
!     r13++ until r13 >= car_count
!
! The 4 scene buffers correspond to different view angles or LODs.
! Scene buffer addresses:
!   0x06063EB0 — buffer 0 (primary/front)
!   0x06063E9C — buffer 1 (rear-view mirror?)
!   0x06063ED8 — buffer 2 (side view?)
!   0x06063EC4 — buffer 3 (shadow/overlay?)

FUN_0600E0C0:  ! 0x0600E0C0
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    mov.l   r12,@-r15
    mov.l   r11,@-r15
    mov.l   r10,@-r15
    mov.l   r9,@-r15
    mov.l   r8,@-r15
    sts.l   pr,@-r15
    sts.l   macl,@-r15

    mov.l   @(0x58,PC),r8           ! r8 = 0x0607EBC4 (master flags)
    mov.l   @(0x58,PC),r9           ! r9 = 0x06078900 (car array base)
    mov.w   @(0x10,PC),r10          ! r10 = 0x0268 (struct size)
    mov.l   @(0x58,PC),r11          ! r11 = 0x00008000 (player mask)
    mov.l   @(0x1C,PC),r12          ! r12 = 0x0607E940
    mov.l   @(0x34,PC),r14          ! r14 = FUN_06027CA4

    mov.l   @(0x58,PC),r0           ! 0x0607EAE0
    mov.l   @r0,r0
    tst     r0,r0
    bf      .loop_exit              ! demo mode → skip
    bra     .loop_check
    mov     #1,r13                  ! start at car 1

.loop_body:
    ! Compute car pointer
    mul.l   r10,r13                 ! index * 0x268
    mov.l   @(0x70,PC),r3           ! r3 = FUN_06030A06
    sts     macl,r2
    add     r9,r2                   ! r2 = &car_array[index]
    mov.l   r2,@r12                 ! *0x0607E940 = car_ptr

    ! Subsystem A update
    jsr     @r3                     ! call FUN_06030A06
    nop

    ! Subsystem B update
    mov.l   @(0x68,PC),r3           ! FUN_06030EE0
    jsr     @r3
    nop

    ! Player vs AI branch
    mov.l   @r8,r2                  ! master flags
    and     r11,r2                  ! & 0x00008000
    tst     r2,r2
    bt      .player_path

    ! AI car: call AI update
    bsr     FUN_0600E906
    nop
    bra     .check_render
    nop

.player_path:
    ! Player car: call player physics
    bsr     FUN_0600E71A
    nop

.check_render:
    ! Check if car needs rendering
    mov.l   @r12,r2                 ! car pointer
    mov.b   @(0x1,r2),r0            ! car->byte[1]
    tst     #0x80,r0                ! render flag
    bt      .loop_next              ! no render → next car

    ! Pre-render setup
    mov.l   @(0x48,PC),r3           ! FUN_060061C8
    jsr     @r3
    nop

    ! Render 4 scene buffers
    mov.l   @(0x48,PC),r4           ! 0x06063EB0 (buffer 0)
    jsr     @r14                    ! FUN_06027CA4
    mov     #0,r5

    mov.l   @(0x44,PC),r4           ! 0x06063E9C (buffer 1)
    jsr     @r14
    mov     #1,r5

    mov.l   @(0x44,PC),r4           ! 0x06063ED8 (buffer 2)
    jsr     @r14
    mov     #2,r5

    mov.l   @(0x40,PC),r4           ! 0x06063EC4 (buffer 3)
    jsr     @r14
    mov     #3,r5

    ! Finalize render
    mov.l   @(0x40,PC),r3           ! FUN_0603053C
    jsr     @r3
    mov     #1,r4

.loop_next:
    add     #1,r13                  ! car index++

.loop_check:
    mov.l   @(0x3C,PC),r2           ! 0x0607EA98 (car count)
    mov.l   @r2,r2
    cmp/hs  r2,r13                  ! index >= count?
    bf      .loop_body

.loop_exit:
    lds.l   @r15+,macl
    lds.l   @r15+,pr
    mov.l   @r15+,r8
    mov.l   @r15+,r9
    mov.l   @r15+,r10
    mov.l   @r15+,r11
    mov.l   @r15+,r12
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14


! =============================================================================
! CONFIDENCE: HIGH — fully verified against ground truth
! Prologue (r14 push, pr push), pool load of 0x0607E944 into r14,
! bsr FUN_0600E906 confirmed. Camera projection call to FUN_06027552
! with constant 0x066505B3 confirmed. shlr16 + exts.w pipeline confirmed.
! Offsets 0x228 and 0x21C for camera target storage confirmed.
! State cleanup (offset 0x1EC check, clear 0x1EC and 0xE0) confirmed.
! AUDIT NOTE: The comment says 0x0607EAD8 check means "not in special
! camera mode" -- this is reasonable since 0x0607EAD8 is used elsewhere
! as a player/mode indicator, but the exact semantics are MEDIUM confidence.
! FUN_0600E99C — Pre-Update Camera/AI Setup
! =============================================================================
! Called from: FUN_0600DE54 (before per-car loop)
! Purpose: Set up AI camera target position for the current frame
!
! Algorithm:
!   car = *0x0607E944
!   call FUN_0600E906()   -- run AI update for current car
!
!   if (*0x0607EAD8 == 0):  -- not in special camera mode
!     r4 = car->position[0xC]  (Y position)
!     Call FUN_06027552(r4, 0x066505B3)  -- coordinate projection
!     result >>= 16, sign-extend
!     car->camera_target_x = result   (offset 0x228)
!     car->camera_target_y = result   (offset 0x21C)
!
!   if (car->offset_0x1EC == 0):
!     *0x0607EAD0 = 0
!     car->offset_0x1EC = 0
!     car->offset_0xE0 = 0

FUN_0600E99C:  ! 0x0600E99C
    mov.l   r14,@-r15
    sts.l   pr,@-r15
    mov.l   @(0x64,PC),r14          ! r14 = [0x0607E944]
    bsr     FUN_0600E906            ! AI update
    mov.l   @r14,r14                ! r14 = car base

    ! Check camera mode
    mov.l   @(0x64,PC),r0           ! 0x0607EAD8
    mov.l   @r0,r0
    tst     r0,r0
    bf      .camera_done            ! special mode → skip

    ! Calculate camera target via projection
    mov.l   @(0x60,PC),r5           ! r5 = 0x066505B3 (projection constant)
    mov.l   @(0x48,PC),r3           ! r3 = FUN_06027552
    jsr     @r3
    mov.l   @(0xC,r14),r4           ! r4 = car->Y position

    shlr16  r0                      ! result >> 16
    exts.w  r0,r0                   ! sign extend to 32-bit
    mov.w   @(0x2A,PC),r1           ! offset 0x228
    add     r14,r1
    mov.l   r0,@r1                  ! car->camera_target_x = result
    mov.w   @(0x26,PC),r1           ! offset 0x21C
    add     r14,r1
    mov.l   r0,@r1                  ! car->camera_target_y = result

.camera_done:
    ! Check car state for cleanup
    mov.w   @(0x22,PC),r0           ! offset 0x1EC
    mov.l   @(r0,r14),r0
    tst     r0,r0
    bf      .setup_return           ! state != 0 → done

    ! State 0: clear related fields
    mov     #0,r4
    mov.l   @(0x40,PC),r3           ! 0x0607EAD0
    mov.l   r4,@r3                  ! clear global
    mov.w   @(0xA,PC),r0            ! offset 0x1EC
    mov.l   r4,@(r0,r14)            ! car->state = 0
    add     #-12,r0                 ! offset 0xE0
    mov.l   r4,@(r0,r14)            ! car->field_E0 = 0

.setup_return:
    lds.l   @r15+,pr
    rts
    mov.l   @r15+,r14


! =============================================================================
! CONFIDENCE: MEDIUM — code at address verified but NOT a labeled function
! AUDIT NOTE: FUN_0600C302 has NO function label in aprog.s. The address
! 0x0600C302 is valid code (mov #104,r0) that follows the rts of the
! previous function ending at 0x0600C300. It appears to be a fall-through
! entry point or a function whose label was not emitted by the disassembler.
! The heading << 5 calculation, timer decrements, and speed zone logic
! are structurally plausible from the instruction sequence.
! The "zone system controls speed bands" interpretation is SPECULATIVE --
! the threshold comparisons and zone_mode=18 assignment could serve
! other purposes (e.g., gear transitions, visual effects).
! AUDIT NOTE: offset math at line 308: "r0 = 0x68, add #124 -> 0xE4"
! is actually 104 + 124 = 228 = 0xE4. The annotation notes this seems
! wrong but the math is correct (it just looks unusual).
! FUN_0600C302 — Car State Finalize / Post-Frame Cleanup
! =============================================================================
! Called from: State 15 (FUN_06009098) after per-car physics
! Purpose: Post-frame timer ticks, heading angle computation, speed zone check
!
! This is a LEAF function (no jsr) except for the zone transition at the end.
!
! Algorithm:
!   car = *0x0607E944
!   heading = car->offset_0x68 (heading raw)
!   heading_expanded = heading << 5  (shll2 + shll2 + shll)
!   car->offset_0x17C = heading_expanded
!   car->offset_0x178 = heading_expanded
!
!   Decrement timers:
!   if (car->timer_172 > 0): car->timer_172--  (word)
!   if (car->timer_174 > 0): car->timer_174--  (word)
!
!   if (car->zone_timer_9B != 0): return  (still in zone)
!
!   === Speed Zone Transition ===
!   speed = car->offset_0x68
!   if (speed >= threshold_low):         // ~0xFFFF
!     car->zone_mode = 18
!     car->zone_timer = 0
!     return
!   if (speed < threshold_high):         // from pool
!     return  (no zone change)
!
!   === Extended Zone Check ===
!   if (speed > high_limit AND speed < very_high):
!     car->zone_timer = 0
!     car->zone_mode = 18
!   return
!
! The zone system controls when the car transitions between speed
! "bands" that affect sound and visual feedback. timer_172 and timer_174
! are generic cooldown timers (used for invincibility frames, etc.)

FUN_0600C302:  ! 0x0600C302 (no label in aprog.s — address-only)
    mov     #104,r0                 ! 0x68 = heading offset
    mov.l   @(0x7C,PC),r4           ! r4 = [0x0607E944]
    mov.l   @r4,r4                  ! car base
    mov.l   @(r0,r4),r3             ! r3 = car->heading
    add     #124,r0                 ! r0 = 0xE4 (seems wrong? actually 104+124=228→0xE4)

    ! heading << 5 = heading * 32
    shll2   r3                      ! << 2
    shll2   r3                      ! << 4
    shll    r3                       ! << 5 total

    mov.l   r3,@(r0,r4)             ! car+0x17C = heading*32
    add     #-4,r0
    mov.l   r3,@(r0,r4)             ! car+0x178 = heading*32

    ! Timer decrements
    mov.w   @(0x4E,PC),r0           ! offset 0x172
    mov.w   @(r0,r4),r3             ! timer_172
    cmp/pl  r3
    bf      .timer2_check
    mov.w   @(0x46,PC),r0
    mov.w   @(r0,r4),r2
    add     #-1,r2                  ! decrement
    mov.w   r2,@(r0,r4)

.timer2_check:
    mov.w   @(0x40,PC),r0           ! offset 0x174
    mov.w   @(r0,r4),r3
    cmp/pl  r3
    bf      .zone_check
    mov.w   @(0x38,PC),r0
    mov.w   @(r0,r4),r2
    add     #-1,r2
    mov.w   r2,@(r0,r4)

.zone_check:
    mov.w   @(0x32,PC),r0           ! offset 0x9B (zone timer)
    mov.w   @(r0,r4),r0
    tst     r0,r0
    bt      .do_zone_transition
    rts                             ! timer still active → return
    nop

.do_zone_transition:
    ! Speed zone checking
    mov     #18,r7                  ! zone mode = 18
    mov     #104,r0                 ! heading offset
    mov.w   @(0x24,PC),r2           ! low threshold
    mov.l   @(r0,r4),r3             ! car->heading
    cmp/ge  r2,r3
    bf/s    .high_range_check
    mov     #0,r6

    ! Speed >= low threshold
    mov.w   @(0x14,PC),r0
    mov.w   r7,@(r0,r4)             ! zone_mode = 18
    add     #2,r0
    rts
    mov.w   r6,@(r0,r4)             ! zone_timer = 0

.high_range_check:
    mov.w   @(0x12,PC),r0           ! offset for high range
    mov.w   @(0x12,PC),r2           ! high threshold
    mov.l   @(r0,r4),r3
    cmp/ge  r2,r3
    bt      .extended_zone          ! speed in high range
    rts
    nop

.extended_zone:
    ! Extended check for very high speed zone
    ! ... continues with more threshold comparisons ...
    ! Eventually writes zone_mode and zone_timer
    rts
    nop
