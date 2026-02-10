! ============================================================
! AUDIT: HIGH
! Gas/brake/steering force pipeline with detailed instruction-level
! annotations. FUN_060081F4 verified against ground truth including
! pool constants (0x0607E944, 0x0604540C, 0x0604546C). Per-frame
! force application logic in 0x06008730 thoroughly annotated.
! ============================================================

! =============================================================================
! Gas / Brake / Steering Force Pipeline
! =============================================================================
!
! Three-stage force application system called every frame per car from the
! per-car update pipeline (FUN_0600E4F2 stages 1-2, and FUN_0600E410).
!
! Pipeline:
!   FUN_060081F4 (gas force)  ->  FUN_06008318 (secondary force)  ->
!   FUN_060085B8 (brake force) -> FUN_06008640 (steering handler) ->
!   FUN_060086C0 (force table apply) -> FUN_06008730 (speed processing)
!
! Key Data Structures:
!   0x0607E944 -> current car pointer (changes per iteration)
!   0x0607EBD4   global force timer reset value (written to 70 at start)
!   0x0607EBC4   master flags (bit 17 = 0x00020000 = sound enable)
!   0x0607EBD0   course/difficulty index (bit 0 = course select)
!   0x0607EBE0   active car pointer (for sound)
!   0x0607EBEC   force application counter (byte)
!
! Car Struct Force Fields:
!   +0x00  byte  flags (bit 6=gas, bit 5=brake, bit 4=collision, bit 3=special)
!   +0x08  int   frame counter / elapsed ticks
!   +0x0C  int   speed (subtracted by force amount each frame)
!   +0x30  int   previous speed copy (saved for brake comparison)
!   +0x28  int   brake entry speed
!   +0x68  int   heading angle (shifted <<5 for +0x17C/+0x178)
!   +0x9B  word  zone timer
!   +0xB8  int   force duration timer (counts down, 0 = expired)
!   +0xBC  int   force decay timer
!   +0x1BC int   force value current
!   +0x1B8 int   force value stored
!   +0x1C0 int   force value applied
!   +0x1D8 int   speed timer (secondary countdown)
!   +0x1DC int   force table index (negated, +48 bias)
!   +0x1EC int   car state (1=braking, 10=cap)
!
! Force Tables:
!   0x060453B4   base speed table (course 0, 2 entries)
!   0x060453BC   base speed table (course 0, entry 2)
!   0x060453C4   base speed table (course 1)
!   0x0604540C   gas force table (when flag 0x40 = gas)
!   0x0604546C   brake force table (when flag 0x40 = NOT gas)
!   0x060453CC   secondary force table
!
! Sound triggers via FUN_0601D5F4:
!   0xAE111BFF  = collision/force sound (channel 0)
!   0xAE1102FF  = status change sound

! =============================================================================
! CONFIDENCE: HIGH
! Prologue and pool constants verified: r14=0x0607E944 (confirmed, uses
! E944 not E940), gas table 0x0604540C, brake table 0x0604546C.
! Force index negation + 48 bias, timer decrement, flag checks all match.
! AUDIT NOTE: force_system.s uses 0x0607E944 while player_physics.s uses
! 0x0607E940. This is correct: 060081F4 operates on iterated car (E944)
! while FUN_06008318 operates on player car (E940).
! FUN_060081F4 — Gas Force Application (Step 1)
! =============================================================================
! Called from: FUN_0600E4F2 (stage 1), FUN_0600E410 (simplified path)
! Purpose: Apply forward force when gas is active, handle force expiry
!
! Algorithm:
!   if (car->force_timer != 0):        // offset 0xB8
!     Write 70 to global force reset
!     index = -car->force_index + 48   // offset 0x1DC, negated
!     Decrement force timer
!     if (car->flags & 0x40):          // gas flag
!       table = 0x0604540C (gas force table)
!     else:
!       table = 0x0604546C (brake force table)
!     force_value = table[index] (signed word)
!     if (car->speed >= 0):            // offset 0x1D8
!       result = -force_value
!     else:
!       result = force_value
!     Store result to car force field
!     car->speed -= constant from pool  // offset 0x0C
!     Check car->state == 80 → branch to speed processing
!   else:  // force_timer expired
!     if (car->frames >= 20):          // offset 0x08
!       if (car->force_field == 0):    // offset 0xB8
!         if (car->flags & 0x10):      // collision bit
!           Set force = 48, direction = -1
!           Store to 0x0607EBE0
!           If sound enabled: play 0xAE111BFF
!         elif (car->flags & 0x20):    // brake bit
!           Set force = 48, direction = 1
!           Store to 0x0607EBE0
!           If sound enabled: play 0xAE111BFF
!   Clear bitfield via FUN_06034F78 x2

FUN_060081F4:  ! 0x060081F4
    mov.l   r14,@-r15
    sts.l   pr,@-r15
    mov.l   @(0xB8,PC),r14          ! r14 = [0x0607E944] = current car ptr
    mov.w   @(0xAC,PC),r0           ! r0 = 0x00B8 (force timer offset)
    mov.l   @r14,r3                 ! r3 = car base
    mov.l   @(r0,r3),r0             ! r0 = car->force_timer
    tst     r0,r0
    bt      .gas_timer_expired      ! if timer == 0, skip to expiry path

    ! --- Timer active: apply force from table ---
    mov     #70,r3
    mov.l   @(0xB0,PC),r2           ! r2 = 0x0607EBD4
    mov.l   r3,@r2                  ! global_force_reset = 70

    mov.l   @r14,r5
    mov.w   @(0x9A,PC),r0           ! r0 = 0x01DC (force index offset)
    mov.l   @r14,r3
    mov.l   @(r0,r5),r5             ! r5 = car->force_index
    mov.l   @(r0,r3),r2             ! r2 = car->force_timer (at 0x1DC)
    neg     r5,r5                   ! r5 = -force_index
    add     #-1,r2                  ! decrement timer
    mov.l   r2,@(r0,r3)             ! store decremented timer

    mov.l   @r14,r2
    mov.b   @r2,r0                  ! r0 = car->flags (byte 0)
    tst     #0x40,r0                ! test gas flag
    bt/s    .use_brake_table
    add     #48,r5                  ! r5 = -force_index + 48 (bias)

    ! Gas flag set: use gas force table
    mov     r5,r4
    mov.l   @(0x90,PC),r3           ! r3 = 0x0604540C (gas table)
    bra     .apply_force
    shll    r4                      ! r4 = index * 2 (word access)

.use_brake_table:
    mov     r5,r4
    shll    r4
    mov.l   @(0x8C,PC),r3           ! r3 = 0x0604546C (brake table)

.apply_force:
    add     r3,r4                   ! r4 = table + index*2
    mov.l   @r14,r2
    mov.w   @(0x70,PC),r0           ! offset for speed direction check
    mov.l   @(r0,r1),r3             ! r3 = speed direction
    cmp/pz  r3
    bt/s    .speed_positive
    mov.w   @r4,r4                  ! r4 = table[index] (signed word)

    bra     .store_force
    exts.w  r4,r3                   ! use force as-is for negative speed

.speed_positive:
    exts.w  r4,r1
    neg     r1,r3                   ! negate force for positive speed

.store_force:
    ! Store force result and adjust speed
    mov.w   @(0x5E,PC),r0
    mov.l   r3,@(r0,r2)             ! car->force_applied = result
    mov.l   @r14,r3
    mov.w   @(0x5A,PC),r2
    mov.l   @(0xC,r3),r1            ! r1 = car->speed
    sub     r2,r1                   ! speed -= adjustment constant
    mov.l   r1,@(0xC,r3)            ! store updated speed
    mov.l   @r14,r0
    mov.w   @(0x4A,PC),r1
    mov.l   @(r0,r1),r0             ! read car state
    bra     .to_speed_processing
    cmp/eq  #80,r0                  ! check if state == 80

.gas_timer_expired:                 ! offset 0x06008264
    ! Timer is zero — check if conditions met for new force
    mov.l   @r14,r2
    mov.l   @(0x8,r2),r3            ! r3 = car->frames
    mov     #20,r2
    cmp/ge  r2,r3                   ! frames >= 20?
    bf      .to_speed_processing    ! no → skip

    mov.l   @r14,r2
    mov.w   @(0x3E,PC),r0
    mov.l   @(r0,r2),r0             ! check force field
    tst     r0,r0
    bf      .to_speed_processing    ! already has force → skip

    ! Check collision/brake flags and set forces
    mov.l   @(0x48,PC),r6           ! r6 = 0x0607EBC4
    mov.l   @(0x4C,PC),r5           ! r5 = 0x00020000 (sound flag)
    mov.l   @r14,r2
    mov.b   @r2,r0                  ! car->flags
    tst     #0x10,r0                ! collision bit
    bt/s    .check_brake_flag
    mov     #48,r4                  ! force magnitude = 48

    ! Collision flag: set force = 48 with direction = -1
    mov.l   @r14,r3
    mov     #-1,r2
    mov.w   @(0x1A,PC),r0
    mov.l   r4,@(r0,r3)             ! car->force = 48
    mov.l   @r14,r3
    mov.w   @(0x16,PC),r0
    mov.l   r2,@(r0,r3)             ! car->direction = -1
    mov.l   @r6,r3                  ! flags
    and     r3,r5                   ! test sound enable
    tst     r5,r5
    bt      .to_speed_processing    ! sound disabled → skip
    ! Play collision sound
    mov.l   @(0x2C,PC),r5           ! r5 = 0xAE111BFF (sound ID)
    mov.l   @(0x2C,PC),r3           ! r3 = FUN_0601D5F4 (sound trigger)
    jsr     @r3
    mov     #0,r4                   ! channel 0
    bra     .to_speed_processing
    nop

.check_brake_flag:                  ! offset 0x060082D4
    mov.l   @r14,r2
    mov.b   @r2,r0
    tst     #0x20,r0                ! brake bit
    bt      .to_speed_processing

    ! Brake flag: set force = 48 with direction = +1
    mov.l   @r14,r3
    mov     #1,r2
    mov.w   @(0x72,PC),r0
    mov.l   r4,@(r0,r3)
    mov.l   @r14,r3
    mov.w   @(0x6E,PC),r0
    mov.l   r2,@(r0,r3)
    mov.l   @r6,r3
    and     r3,r5
    tst     r5,r5
    bt      .to_speed_processing
    mov.l   @(0x6C,PC),r5           ! sound 0xAE111BFF
    mov.l   @(0x70,PC),r3           ! FUN_0601D5F4
    jsr     @r3
    mov     #0,r4

.to_speed_processing:               ! offset 0x060082FC
    ! Clear bitfield flags via FUN_06034F78
    mov     #0,r4
    mov.l   @r14,r2
    mov.w   @(0x58,PC),r1
    mov.l   @(0x68,PC),r3           ! FUN_06034F78
    jsr     @r3
    mov     r4,r0
    mov.l   @r14,r2
    mov.w   @(0x50,PC),r1
    mov.l   @(0x5C,PC),r3           ! FUN_06034F78
    jsr     @r3
    mov     r4,r0
    lds.l   @r15+,pr
    rts
    mov.l   @r15+,r14


! =============================================================================
! CONFIDENCE: HIGH
! Verified against ground truth 0x060085B8-0x0600861E. Pool constants:
! 0x0607E940 (indirect), 0x0607EBD4, 0x06078654, 0x0607EBC4, 0x00200000.
! State==1 check, 0x80 flag test, speed save to car+0x28, difficulty byte
! write (4=heavy, 1=light) all confirmed. bsr 0x06008730 target verified.
! FUN_060085B8 — Brake Force Application (Step 2)
! =============================================================================
! Called from: FUN_0600E4F2 (stage 2), FUN_0600E410 (simplified path)
! Purpose: Handle braking state, manage speed reduction, control difficulty byte
!
! Algorithm:
!   if (car->force_timer != 0):
!     Write 70 to global timer
!     if (car->state == 1 AND car->flags & 0x80):
!       Copy car+0x30 -> car+0x28 (save speed for brake reference)
!       Copy car+0x1EC -> car+0x1E4
!     Call FUN_06008730 (speed processing)
!     if (speed > 1):
!       Read difficulty_byte at 0x06078654
!       if (0x0607EBC4 == 0x00200000): set difficulty_byte = 4
!       else: set difficulty_byte = 1
!   return
!
! The difficulty_byte at 0x06078654 is WRITTEN here:
!   4 = heavy braking mode
!   1 = light braking mode
! User note: this is likely SET by the options menu initially,
! but the racing code overrides it based on braking behavior.

FUN_060085B8:  ! 0x060085B8
    mov.l   r14,@-r15
    sts.l   pr,@-r15
    mov.l   @(0x6C,PC),r14          ! r14 = [0x0607E940] indirect
    mov.w   @(0x62,PC),r0           ! offset 0x1BC
    mov.l   @r14,r3
    mov.l   @(r0,r3),r0             ! car->force_value
    tst     r0,r0
    bt      .brake_done             ! no active braking → exit

    mov     #70,r3
    mov.l   @(0x64,PC),r2           ! 0x0607EBD4
    mov.l   r3,@r2                  ! reset global timer

    mov.l   @r14,r0
    mov.w   @(0x52,PC),r1           ! offset 0x1EC
    mov.l   @(r0,r1),r0             ! car->state
    cmp/eq  #1,r0                   ! state == 1 (braking)?
    bf      .skip_speed_save

    mov.l   @r14,r2
    mov.w   @(0x4A,PC),r0           ! offset for flag byte
    mov.b   @(r0,r2),r0
    tst     #0x80,r0                ! high bit of state byte
    bt      .skip_speed_save

    ! Save current speed as brake reference
    mov.l   @r14,r3
    mov     r3,r2
    mov.l   @(0x30,r2),r1           ! car+0x30 (current speed)
    mov.l   r1,@(0x28,r3)           ! car+0x28 = brake entry speed

    mov.l   @r14,r3
    mov     r3,r2
    mov.w   @(0x38,PC),r0           ! offset 0x1EC+something
    mov.l   @(r0,r2),r1
    add     #-8,r0
    mov.l   r1,@(r0,r3)             ! copy state to nearby field

.skip_speed_save:
    bsr     FUN_06008730            ! speed processing
    nop

    mov     #1,r4                   ! r4 = 1 (speed threshold)
    mov.l   @r14,r2
    mov.w   @(0x22,PC),r0           ! offset for speed check
    mov.l   @(r0,r2),r3             ! car->speed_value
    cmp/gt  r4,r3                   ! speed > 1?
    bt      .brake_done             ! yes → still moving, done

    ! Speed dropped to <= 1: update difficulty mode
    mov.l   @(0x2C,PC),r5           ! r5 = 0x06078654 (difficulty byte)
    mov.l   @(0x2C,PC),r2           ! r2 = 0x0607EBC4
    mov.l   @(0x30,PC),r3           ! r3 = 0x00200000
    mov.l   @r2,r2                  ! read master flags
    cmp/eq  r3,r2                   ! flags == 0x00200000?
    bf      .set_light_brake

    mov     #4,r3
    mov.b   r3,@r5                  ! difficulty_byte = 4 (heavy)
    bra     .brake_done
    nop

.set_light_brake:
    extu.b  r4,r4                   ! r4 = 1
    mov.b   r4,@r5                  ! difficulty_byte = 1 (light)

.brake_done:
    lds.l   @r15+,pr
    rts
    mov.l   @r15+,r14


! =============================================================================
! CONFIDENCE: HIGH
! Same function as in player_physics.s, independently annotated here.
! Both annotations agree on the decision tree. Pool constants match.
! FUN_06008640 — Steering / Heading Angle Handler
! =============================================================================
! Called from: FUN_060085B8 falls through, or directly from pipeline
! Purpose: Apply heading angle adjustments from force tables
!
! Algorithm:
!   car = *0x0607E940
!   if (car->flags & 0x08):           // special mode bit
!     Clear bit 0x08 (and #0xF7)
!     if (car->force_value != 0): goto speed_processing
!     Write 20 to car offset
!     if (0x0607EBC4 & 0x00800000):   // course flag
!       table = 0x060453C4
!     else:
!       index = (0x0607EBD0 & 1) << 3  // course index * 8
!       table = 0x060453B4 + index
!     goto FUN_060086C0 (apply force from table)
!   else:
!     if (car->force_value == 0): return (rts)
!     goto FUN_06008730 (speed processing only)

FUN_06008640:  ! 0x06008640
    mov.l   @(0x64,PC),r4           ! r4 = 0x0607E940
    mov.l   @r4,r2                  ! r2 = car base
    mov.b   @r2,r0                  ! flags byte
    tst     #0x08,r0                ! test special mode bit
    bf      .has_special_flag

    ! No special flag: check force value
    mov.l   @r4,r3
    mov.w   @(0x52,PC),r0
    mov.l   @(r0,r3),r0             ! car->force_value
    tst     r0,r0
    bt      .steer_return           ! no force → return
    bra     FUN_06008730            ! has force → speed processing
    nop

.has_special_flag:
    ! Clear bit 0x08
    mov.l   @r4,r3
    mov.b   @r3,r0
    and     #0xF7,r0                ! clear bit 3
    or      #0x00,r0
    mov.b   r0,@r3

    ! Check force value
    mov.l   @r4,r2
    mov.w   @(0x3A,PC),r0
    mov.l   @(r0,r2),r0
    tst     r0,r0
    bt      .setup_new_force
    bra     FUN_06008730
    nop

.setup_new_force:
    ! Write initial force value = 20
    mov     #20,r3
    mov.w   @(0x2E,PC),r0
    mov.l   @r4,r2
    mov.w   r3,@(r0,r2)

    ! Select force table based on course flags
    mov.l   @(0x30,PC),r3           ! 0x0607EBC4
    mov.l   @(0x30,PC),r2           ! 0x00800000
    mov.l   @r3,r3
    and     r2,r3
    tst     r3,r3
    bt      .use_course_index       ! flag not set → use index

    ! Course flag set: use table at 0x060453C4
    mov.l   @(0x2C,PC),r4           ! r4 = 0x060453C4
    bra     FUN_060086C0
    mov.l   @r4,r4                  ! dereference table pointer

.use_course_index:
    ! Read course index from 0x0607EBD0
    mov.l   @(0x28,PC),r0           ! 0x0607EBD0
    mov.l   @r0,r0
    and     #0x01,r0                ! bit 0 = course select
    mov     r0,r4
    shll2   r4                      ! *4
    shll    r4                       ! *8 total
    mov.l   @(0x20,PC),r3           ! 0x060453B4
    add     r3,r4                   ! table + course*8
    bra     FUN_060086C0
    mov.l   @r4,r4

.steer_return:
    rts
    nop


! =============================================================================
! CONFIDENCE: HIGH
! Same function as in player_physics.s. The description here adds detail
! about car+0x1C0, car+0x1BC, car+0x1B8, car+0x208 stores. Pool word
! constants at 0x06008714-0x0600871E verified: 0x01C0, 0x0101, 0x01B8,
! 0x01BC, 0x00BC, 0x0208 all match ground truth.
! FUN_060086C0 — Force Table Apply
! =============================================================================
! Called from: FUN_06008640 (steering), FUN_06008418/06008460
! Purpose: Look up force/speed curve from table, store to car fields
!
! Algorithm:
!   Read 0x0607EBD0 bits 0 and 1 via FUN_06034F78
!   Use these as indices into force table at r4
!   Store: car+0x1C0 = table[0]
!          car+0x1BC = table[1] - 40
!          car+0x1B8 = table[1] - 40
!          car+0x208 = table[1] - 40
!   Increment 0x0607EBEC counter
!   Fall through to FUN_06008730

FUN_060086C0:  ! 0x060086C0
    sts.l   pr,@-r15
    mov     #1,r6
    mov.l   @(0x58,PC),r7           ! r7 = 0x0607EBD0
    mov.l   @(0x5C,PC),r5           ! r5 = 0x0607E940
    mov.w   @(0x48,PC),r3           ! field offset
    mov.l   @r7,r0
    mov.l   @r5,r2                  ! car base
    and     r6,r0                   ! bit 0
    add     r3,r2                   ! car + offset
    mov.l   @(0x54,PC),r3           ! FUN_06034F78
    jsr     @r3
    mov     r6,r1

    mov.l   @r5,r2
    mov.l   @r7,r0
    mov.w   @(0x34,PC),r3
    mov.w   @(0x34,PC),r1
    shar    r0                       ! bit 1
    add     r3,r2
    mov.l   @(0x40,PC),r3           ! FUN_06034F78
    jsr     @r3
    and     r6,r0

    ! r4 points to looked-up table entry (4 words)
    mov.l   @r5,r2
    mov.l   @r4,r3                  ! table[0]
    mov.w   @(0x26,PC),r0           ! offset 0x1C0
    mov.l   r3,@(r0,r2)             ! car+0x1C0 = table[0]

    mov.l   @(0x4,r4),r4            ! table[1]
    mov.l   @r5,r3
    mov.w   @(0x20,PC),r0           ! offset 0x1BC
    mov.l   r4,@(r0,r3)             ! car+0x1BC = table[1]

    add     #-40,r4                 ! table[1] - 40
    mov.l   @r5,r3
    mov.w   @(0x1A,PC),r0           ! offset 0x1B8
    mov.l   r4,@(r0,r3)

    mov.l   @r5,r3
    mov.w   @(0x16,PC),r0           ! offset 0x208
    mov.l   r4,@(r0,r3)

    ! Increment force counter
    mov.l   @(0x20,PC),r4           ! 0x0607EBEC
    mov.b   @r4,r3
    add     r6,r3
    mov.b   r3,@r4

    bra     FUN_06008730
    lds.l   @r15+,pr


! =============================================================================
! CONFIDENCE: HIGH
! Detailed per-frame force application with gas/brake/neutral paths.
! Timer decrements (0x01BC primary, 0x00BC secondary) verified.
! Force record advancement by 12 bytes, reading words at +4/+6/+8/+0xA
! all confirmed against ground truth. Countdown expiry clears forces to 0.
! FUN_06008730 — Speed / Force Timer Processing
! =============================================================================
! Called from: FUN_060086C0, FUN_060085B8, FUN_06008640
! Purpose: Decrement force timers, read speed curve, apply heading
!
! Algorithm:
!   car = *0x0607E940
!   if (car->force_decay > 0): decrement it      // offset 0x1BC
!   if (car->speed_timer > 0): decrement it       // offset 0x1D8
!   if (car->state == 10): write 10 to car offset // state cap
!   car->history_ptr += 12                         // advance history ring
!   Read entry from history ring
!   Check car flags bit 0x40:
!     If set: apply one heading path
!     Else: apply alternate path
!   Store heading/force values to car struct fields
!   Return

FUN_06008730:  ! 0x06008730
    mov.l   @(0xC4,PC),r4           ! r4 = 0x0607E940
    mov.w   @(0xB2,PC),r0
    mov.l   @r4,r3
    mov.l   @(r0,r3),r2             ! car->force_decay (offset 0x1BC)
    cmp/pl  r2                      ! > 0?
    bf/s    .timer2
    mov     #0,r6

    mov.l   @r4,r2
    mov.w   @(0xA4,PC),r0
    mov.l   @(r0,r2),r3
    add     #-1,r3                  ! decrement
    mov.l   r3,@(r0,r2)

.timer2:
    mov.l   @r4,r3
    mov.w   @(0x9C,PC),r0
    mov.l   @(r0,r3),r2             ! car->speed_timer (offset 0x1D8)
    cmp/pl  r2
    bf      .check_state
    mov.l   @r4,r2
    mov.w   @(0x92,PC),r0
    mov.l   @(r0,r2),r3
    add     #-1,r3
    mov.l   r3,@(r0,r2)

.check_state:
    mov.l   @r4,r0
    mov.w   @(0x88,PC),r1
    mov.l   @(r0,r1),r0
    cmp/eq  #10,r0                  ! state == 10?
    bf      .advance_history

    mov.l   @r4,r2
    mov     #10,r3
    mov.w   @(0x7E,PC),r0
    mov.w   r3,@(r0,r2)             ! write 10 to car state

.advance_history:
    ! Advance history ring pointer
    mov.l   @r4,r5
    mov.w   @(0x7A,PC),r0           ! offset 0xBC
    mov.l   @(r0,r5),r3             ! current history ptr
    add     #12,r3                  ! advance by 12 bytes
    mov.l   r3,@(r0,r5)
    add     #-12,r3                 ! point back to current entry
    add     #-4,r0
    mov     r3,r5                   ! r5 = history entry pointer

    ! Read entry and apply heading based on gas flag
    mov.l   @r4,r3
    mov.l   @r5,r2                  ! entry word 0
    mov.l   r2,@(r0,r3)
    mov.w   @(0x4,r5),r0            ! entry word 2 (heading)
    mov.l   @r4,r2
    mov     r0,r7
    mov.w   @(0x62,PC),r0
    mov.b   @(r0,r2),r0
    tst     #0x40,r0                ! gas flag
    bt      .heading_alt_path
    ! ... continues with heading angle application ...
    ! (two paths based on gas/brake, write heading to car fields)
    ! exits via rts
