! ================================================================
! LAP COUNTING AND RACE PROGRESSION SYSTEM
! ================================================================
!
! Complete flow for detecting when a car completes a lap:
!
!   Frame N:
!     FUN_0600CE66 -> FUN_0600CD40   checkpoint crossing detection
!     FUN_0600D780                    checkpoint change detector
!       -> FUN_0600D9BC              set lap flag when all checkpoints passed
!       -> FUN_0600D92C              record lap timing data
!
!   Frame N+1:
!     0x0600DB64                      lap check: test flag, increment counter
!     FUN_0600DBA0                    finish line display effects
!
! The lap flag is byte+2 bit 2 (0x04) of the car struct's first
! 32-bit word. It is SET by FUN_0600D9BC via the bitfield utility
! FUN_06034F78(value=1, param=0x1501, ptr=car_ptr). The parameter
! 0x1501 decodes as: bit_position=21 from MSB, bit_count=1,
! yielding actual bit 10 = byte+2 bit 2 in big-endian.
!
! Car struct offsets used by this system:
!   +0x0000  32-bit flags word (contains lap flag at byte+2 bit 2)
!   +0x0010  X position
!   +0x0018  Z position
!   +0x015C  LAP COUNTER (incremented each lap)
!   +0x01E0  checkpoint table base pointer
!   +0x01E4  current checkpoint index
!   +0x01E8  cumulative checkpoint count (progress toward lap)
!   +0x01EC  checkpoint parameter (from table entry[0x16])
!   +0x01F0  previous frame checkpoint parameter
!   +0x0228  some state counter (incremented on lap events)
!
! Global addresses:
!   0x0607E940  current car pointer
!   0x0607EA9C  total checkpoints per lap
!   0x0607EAAC  accumulated race time
!   0x0607EAA0  current lap time delta
!   0x0607EABC  lap display timer (set to 40 on lap complete)
!   0x0607EAC0  lap timing trigger (set to 40 on lap complete)
!   0x06063F1C  per-car lap completion bitmask
!   0x06063F18  previous per-car lap bitmask
!   0x06063F20  current segment reference
!   0x06063F24  cumulative segment counter
!   0x06063F28  max segments before reset
!   0x06078698  finish line proximity counter (word)
!   0x060786A8  finish line animation counter
!   0x0605DE3C  wrong-way flag (byte)
!
! ================================================================


! ================================================================
! FUN_0600CD40 — Checkpoint advance (angle-based crossing)
! ================================================================
!
! Called from: FUN_0600CE66 (via FUN_0600C74E spline tracking)
! Called from: FUN_0600C5D6 (alternate path)
!
! For each frame, computes the angle between the car and the
! current checkpoint. If the angular difference exceeds the
! checkpoint's half-width * 4, advances to the next checkpoint.
! When the checkpoint index exceeds total_checkpoints, wraps to 0
! (this is the lap boundary in checkpoint space).
!
! Does NOT set the lap flag directly — that happens in FUN_0600D780
! which detects the checkpoint parameter change.
!
! ----------------------------------------------------------------

    .global FUN_0600CD40
FUN_0600CD40:                           ! 0x0600CD40
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    sts.l   pr,@-r15
    mov.l   .L_cd40_car_ptr,r14         ! r14 = &car_ptr (0x0607E940)
    mov.w   .L_cd40_off_01E4,r0         ! r0 = 0x01E4
    mov.l   @r14,r14                    ! r14 = car_ptr
    mov.l   @(r0,r14),r13               ! r13 = car[0x01E4] (checkpoint index)
    add     #-4,r0                      ! r0 = 0x01E0
    mov     r13,r3
    shll2   r13                         ! r13 = index * 4
    shll2   r3                          ! r3 = index * 16
    shll    r13                         ! r13 = index * 8
    shll2   r3                          ! r3 = index * 64  (wait: 4*16=64? no, *4*4=16, *4 again=64, no...)
                                        ! Actually: r3 = index * (4+16) = index * 20? No...
                                        ! r13 = index<<2<<1 = index*8
                                        ! r3 = index<<2<<2<<2 = index*64
                                        ! r13 + r3 = index * (8+16) = index*24 ✓
    add     r3,r13                      ! r13 = index * 24 (checkpoint entry size)
    mov.l   @(r0,r14),r3               ! r3 = car[0x01E0] (checkpoint table base)
    add     r3,r13                      ! r13 = &checkpoint_table[index]

    ! Read checkpoint parameter, store for change detection
    mov.w   @(0x16,r13),r0             ! r0 = checkpoint_entry[0x16] (signed)
    mov     r0,r3
    extu.w  r3,r3                       ! r3 = unsigned parameter
    mov.w   .L_cd40_off_01EC,r0
    mov.l   r3,@(r0,r14)               ! car[0x01EC] = checkpoint parameter

    ! Compute angle from car position to checkpoint center
    mov.l   @(0x4,r13),r5              ! r5 = checkpoint_entry[4] (Z coordinate)
    mov.l   @(0x18,r14),r3             ! r3 = car[0x18] (car Z position)
    mov.l   @(0x10,r14),r4             ! r4 = car[0x10] (car X position)
    mov.l   @r13,r2                     ! r2 = checkpoint_entry[0] (X coordinate)
    sub     r3,r5                       ! r5 = checkpoint_Z - car_Z
    mov.l   .L_cd40_atan2,r3
    jsr     @r3                         ! FUN_0602744C(r4=dX, r5=dZ) → angle in r0
    sub     r2,r4                       ! r4 = checkpoint_X - car_X (delay slot)

    ! Compare angular difference against threshold
    exts.w  r0,r4                       ! r4 = angle (signed 16-bit)
    exts.w  r4,r6
    mov.w   @(0xE,r13),r0              ! r0 = checkpoint_entry[0x0E] (half-width)
    mov     r6,r7
    mov     r0,r5
    shll2   r5                          ! r5 = half_width * 4 (threshold)
    sub     r5,r7                       ! r7 = angle - threshold
    cmp/pz  r7                          ! if angle >= threshold
    bt      .L_cd40_check_abs
    mov     r5,r2                       ! abs(angle - threshold)
    bra     .L_cd40_compare
    sub     r6,r2
.L_cd40_check_abs:
    mov     r7,r2

.L_cd40_compare:
    mov.w   .L_cd40_threshold,r3        ! r3 = comparison threshold
    cmp/gt  r3,r2                       ! if angular_diff > threshold
    bf      .L_cd40_return              ! no crossing, return

    ! Checkpoint crossed — advance index
    mov.w   .L_cd40_off_01E4b,r0
    mov.l   @(r0,r14),r3               ! r3 = car[0x01E4]
    add     #1,r3                       ! r3 = next checkpoint
    mov.l   r3,@(r0,r14)               ! car[0x01E4] = next checkpoint

    ! Check for lap wrap
    mov.l   @(r0,r14),r3               ! reload
    mov.l   .L_cd40_total_ckpt,r2      ! r2 = &total_checkpoints
    mov.l   @r2,r2                      ! r2 = total_checkpoints
    cmp/gt  r2,r3                       ! if car[0x01E4] > total
    bf      .L_cd40_return
    mov     #0,r2
    mov.w   .L_cd40_off_01E4c,r0
    mov.l   r2,@(r0,r14)               ! car[0x01E4] = 0 (wrap to start)

.L_cd40_return:
    mov     r13,r0                      ! return checkpoint entry pointer
    lds.l   @r15+,pr
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14


! ================================================================
! FUN_0600D780 — Checkpoint change detection (per frame)
! ================================================================
!
! Called from: FUN_0600E4F2 (main per-car physics, last call)
! Parameter: r4 = player_flag (0 = player, non-zero = AI)
!
! Compares car[0x01EC] (current checkpoint param) with
! car[0x01F0] (previous frame). When the change indicates the
! car has traversed the full course (car[0x01E8] == total
! checkpoints), triggers the lap completion sequence.
!
! Two paths for lap detection:
!   Path A (r5 < -1): Backward checkpoint jump — if at start,
!                      it's a forward wrap completing a lap
!   Path B (r5 > 1):  Forward checkpoint jump — if past halfway,
!                      it's a lap completion
!   Path C (|r5|<=1): Normal single-step advance, calls D84C
!                      for player-specific checkpoint tracking
!
! ----------------------------------------------------------------

    .global FUN_0600D780
FUN_0600D780:                           ! 0x0600D780
    mov.l   r14,@-r15
    mov     r4,r14                      ! r14 = player_flag (0=player)
    mov.l   r13,@-r15
    sts.l   pr,@-r15
    mov.l   .L_d780_car_ptr,r4          ! r4 = &car_ptr
    mov.w   .L_d780_off_01EC,r0         ! r0 = 0x01EC
    mov.l   @r4,r4                      ! r4 = car_ptr
    mov.l   @(r0,r4),r5                ! r5 = car[0x01EC] (current param)
    add     #4,r0                       ! r0 = 0x01F0
    mov.l   @(r0,r4),r3                ! r3 = car[0x01F0] (previous param)
    sub     r3,r5                       ! r5 = change = current - previous
    tst     r5,r5
    bt      .L_d780_return              ! no change, return

    mov.l   .L_d780_seg_table,r7        ! r7 = 0x06063F1C
    mov     #-1,r3
    mov.l   .L_d780_total_ckpt,r6       ! r6 = &total_checkpoints
    cmp/ge  r3,r5                       ! if change >= -1
    bt/s    .L_d780_forward             ! then go forward path
    mov     #0,r13

    ! --- Path A: Large backward jump (change < -1) ---
    ! This happens when checkpoint wraps from max to 0
    mov.w   .L_d780_off_0228,r0
    mov.l   @(r0,r4),r3
    add     #1,r3                       ! car[0x0228]++ (increment counter)
    mov.l   r3,@(r0,r4)
    add     #-64,r0                     ! r0 = 0x01E8
    mov.l   @r6,r2                      ! r2 = total_checkpoints
    mov.l   @(r0,r4),r3                ! r3 = car[0x01E8] (cumulative count)
    cmp/eq  r2,r3                       ! if cumulative == total
    bf      .L_d780_return              ! not a full lap yet

    ! *** LAP COMPLETE (backward wrap) ***
    tst     r14,r14                     ! player check
    bf      .L_d780_return              ! AI cars skip
    mov.w   .L_d780_off_01E8,r0
    mov.l   r13,@(r0,r4)               ! car[0x01E8] = 0 (reset progress)
    mov.l   .L_d780_seg_prev,r3         ! r3 = &0x06063F18
    mov.l   @r3,r3
    mov.l   r3,@r7                      ! *0x06063F1C = *0x06063F18 (copy)
    bsr     FUN_0600D9BC                ! SET LAP FLAG
    mov     #0,r4                       ! r4 = 0 (player car index)
    bsr     FUN_0600D92C                ! record lap timing
    nop
    extu.b  r13,r13                     ! r13 = 0
    mov.l   .L_d780_wrongway,r3         ! r3 = &0x0605DE3C
    mov.b   r13,@r3                     ! clear wrong-way flag
    bra     .L_d780_return
    nop

.L_d780_forward:
    ! --- Path B/C: Forward change (change >= -1) ---
    mov     #1,r2
    cmp/gt  r2,r5                       ! if change > 1
    bf      .L_d780_single_step         ! single step, go path C

    ! Path B: Large forward jump (change > 1)
    mov.w   .L_d780_off_0228,r0
    mov.l   @(r0,r4),r2
    add     #-1,r2                      ! car[0x0228]-- (decrement counter)
    mov.l   r2,@(r0,r4)
    mov.l   @r6,r3                      ! r3 = total_checkpoints
    mov     #0,r2
    add     #-64,r0                     ! r0 = 0x01E8
    ! subc r2,r3                        ! r3 = total - borrow (complex calc)
    shar    r3                           ! r3 = total / 2
    mov.l   @(r0,r4),r1                ! r1 = car[0x01E8]
    cmp/ge  r3,r1                       ! if progress >= total/2
    bf      .L_d780_return              ! not enough progress

    ! *** LAP COMPLETE (forward jump past halfway) ***
    tst     r14,r14
    bf      .L_d780_return              ! AI skip
    mov.w   .L_d780_off_01E8,r0
    mov.l   r13,@(r0,r4)               ! car[0x01E8] = 0
    mov.l   .L_d780_seg_prev,r3
    mov.l   @r3,r3
    mov.l   r3,@r7
    bsr     FUN_0600D9BC                ! SET LAP FLAG
    mov     #0,r4
    bsr     FUN_0600D92C                ! record lap timing
    nop
    mov     #1,r2
    mov.l   .L_d780_wrongway,r3
    mov.b   r2,@r3                      ! set wrong-way flag (forward lap)
    bra     .L_d780_return
    nop

.L_d780_single_step:
    ! --- Path C: Single checkpoint change (|change| <= 1) ---
    tst     r14,r14
    bf      .L_d780_return              ! AI skip
    bsr     .L_d780_sub_D84C            ! player checkpoint tracking
    nop
    ! ... falls through to FUN_0600D8A4 (AI car processing)

.L_d780_return:
    lds.l   @r15+,pr
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14


! ================================================================
! FUN_0600D9BC — Set lap completion flag
! ================================================================
!
! Called from: FUN_0600D780 when all checkpoints have been passed
! Parameter: r4 = car_index (0 for player)
!
! Sets byte+2 bit 2 (the lap flag) in the car struct's first
! 32-bit word using FUN_06034F78(value=1, param=0x1501, ptr=car).
!
! Also maintains a per-car bitmask at 0x06063F1C to prevent
! double-counting laps within the same cycle.
!
! ----------------------------------------------------------------

    .global FUN_0600D9BC
FUN_0600D9BC:                           ! 0x0600D9BC
    mov.l   r14,@-r15
    sts.l   pr,@-r15
    mov.l   .L_d9bc_bitmask,r14         ! r14 = &0x06063F1C (lap bitmask)
    mov.l   .L_d9bc_car_ptr,r5          ! r5 = &car_ptr
    tst     r4,r4                       ! test car_index
    bf/s    .L_d9bc_skip_check          ! if not player, skip
    mov.l   @r5,r5                      ! r5 = car_ptr

    ! Player path: verify consistency before setting flag
    mov.l   .L_d9bc_seg_prev,r3         ! r3 = &0x06063F18
    mov.l   .L_d9bc_bitmask,r2          ! r2 = &0x06063F1C
    mov.l   @r3,r3                      ! r3 = previous bitmask
    mov.l   @r2,r2                      ! r2 = current bitmask
    cmp/eq  r2,r3
    bf      .L_d9bc_skip_check          ! if different, skip

    ! Additional position verification...
    ! (checks car[0x01E8] against 0x06063F20 for match)
    ! (increments 0x06063F24, checks against 0x06063F28 for reset)

.L_d9bc_skip_check:
    ! --- Generate per-car bitmask ---
    mov     #1,r7
    mov.l   .L_d9bc_bitmask_fn,r3       ! r3 = FUN_06035280
    mov     r7,r0                        ! r0 = 1
    jsr     @r3                          ! FUN_06035280(1, car_index)
    mov     r4,r1                        ! r1 = car_index (delay slot)
    mov     r0,r6                        ! r6 = per-car bit (e.g., 1<<car_index)

    ! Check if lap already counted for this car
    mov.l   @r14,r2                     ! r2 = *0x06063F1C (current lap bits)
    and     r6,r2                        ! r2 = bit for this car
    tst     r2,r2
    bf      .L_d9bc_done                ! already set, don't double-count

    ! *** SET THE LAP FLAG ***
    mov     r7,r0                        ! r0 = 1
    mov.l   @r14,r3                     ! r3 = current bitmask
    or      r6,r3                        ! set this car's bit
    mov.l   r3,@r14                     ! *0x06063F1C = updated bitmask

    mov.w   .L_d9bc_param_1501,r1       ! r1 = 0x1501 (bit_pos=21, count=1)
                                        ! actual_bit = 32-1-21 = 10
                                        ! = byte+2, bit 2 = 0x04
    mov.l   .L_d9bc_bitfield_fn,r3      ! r3 = FUN_06034F78
    jsr     @r3                          ! FUN_06034F78(1, 0x1501, car_ptr)
    mov     r5,r2                        ! r2 = car_ptr (delay slot)

    ! Increment car[0x0228]
    mov.w   .L_d9bc_off_0228,r0
    mov.l   @(r0,r5),r2
    add     #1,r2
    mov.l   r2,@(r0,r5)                ! car[0x0228]++

    ! Check for additional processing
    mov.l   .L_d9bc_flag_EAD8,r0        ! r0 = &0x0607EAD8
    mov.l   @r0,r0
    tst     r0,r0
    bt      .L_d9bc_done                ! if zero, done
    tst     r4,r4
    bt      .L_d9bc_done                ! if player, done
    mov     r5,r0
    mov.b   @(0x3,r0),r0               ! check car[3] bit 3
    tst     #0x08,r0
    bf      .L_d9bc_done
    ! ... tail-call to FUN_0600DD88 for AI notification
    lds.l   @r15+,pr
    bra     FUN_0600DD88
    mov.l   @r15+,r14

.L_d9bc_done:
    lds.l   @r15+,pr
    rts
    mov.l   @r15+,r14

.L_d9bc_param_1501:
    .word   0x1501                      ! bit_position=0x15(21), bit_count=1
                                        ! actual bit = 32 - 1 - 21 = 10
                                        ! = byte+2 bit 2 = lap flag (0x04)


! ================================================================
! 0x0600DB64 — Lap counter increment (not a labeled function)
! ================================================================
!
! Called from: FUN_0600E4F2 (player car only, via bsr)
! Called from: 0x0602E188
!
! Tests byte+2 bit 2 (the lap flag set by FUN_0600D9BC).
! If set: clears it, increments the lap counter, starts display.
! The flag is a one-shot: set on one frame, consumed on the next.
!
! ----------------------------------------------------------------

.sDB_entry:                             ! 0x0600DB64
    mov.l   .L_db64_car_ptr,r4          ! r4 = &car_ptr (0x0607E940)
    mov.l   @r4,r4                      ! r4 = car_ptr
    mov     r4,r0
    mov.b   @(0x2,r0),r0               ! r0 = car[byte+2] (flags)
    tst     #0x04,r0                    ! test bit 2 = lap flag
    bt      .sDB_no_lap                 ! not set, skip

    ! --- Lap flag is set: consume it ---
    mov     r4,r3
    add     #2,r3                       ! r3 = &car[byte+2]
    mov.b   @r3,r0
    and     #0xFB,r0                    ! clear bit 2
    or      #0x00,r0                    ! (no-op, original compiler artifact)
    mov.b   r0,@r3                      ! store back

    ! Increment lap counter
    mov.w   .L_db64_off_015C,r0         ! r0 = 0x015C
    mov.l   @(r0,r4),r2                ! r2 = car[0x015C] (lap count)
    add     #1,r2                       ! r2 = lap_count + 1
    mov.l   r2,@(r0,r4)                ! car[0x015C] = new lap count

    ! Start lap display timer
    mov     #40,r3                      ! 40 frames (~0.67 sec at 60fps)
    mov.l   .L_db64_disp_timer,r2       ! r2 = &0x0607EABC
    mov.l   r3,@r2                      ! *0x0607EABC = 40

    ! Accumulate lap time
    mov.l   .L_db64_accum_time,r4       ! r4 = &0x0607EAAC (total time)
    mov.l   .L_db64_lap_delta,r3        ! r3 = &0x0607EAA0 (this lap)
    mov.l   @r3,r3                      ! r3 = lap_delta
    mov.l   @r4,r2                      ! r2 = total_time
    add     r3,r2                       ! r2 = total + delta

    ! Jump to lap display function
    mov.l   .L_db64_display_fn,r3       ! r3 = FUN_0601D7D0
    jmp     @r3                          ! tail-call to lap display
    mov.l   r2,@r4                      ! *0x0607EAAC = new total (delay slot)

.sDB_no_lap:
    rts
    nop


! ================================================================
! FUN_0600D92C — Record lap timing data
! ================================================================
!
! Called from: FUN_0600D780 immediately after FUN_0600D9BC
!
! Records position and timing data for the completed lap.
! Stores reference points for split time calculation.
! Triggers FUN_0600DCC8 for checkpoint-based timing updates.
!
! ----------------------------------------------------------------

    .global FUN_0600D92C
FUN_0600D92C:                           ! 0x0600D92C
    mov.l   r14,@-r15
    sts.l   pr,@-r15
    mov.l   .L_d92c_car_ptr,r14         ! r14 = &car_ptr
    mov.l   .L_d92c_seg_max,r3          ! r3 = &0x06063F28 (max segments)
    mov.w   .L_d92c_off_01EC,r0         ! r0 = 0x01EC
    mov.l   @r14,r14                    ! r14 = car_ptr
    mov.l   @r3,r3                      ! r3 = max_segments
    mov.l   @(r0,r14),r2               ! r2 = car[0x01EC]
    add     #-1,r3                      ! r3 = max - 1
    cmp/hi  r3,r2                       ! if car[0x01EC] > max-1
    bf      .L_d92c_store

    ! Car past max segment — store timing flag
    mov     #3,r2
    mov.l   .L_d92c_timing_flag,r3      ! r3 = &0x0607EBF4
    mov.l   r2,@r3                      ! *0x0607EBF4 = 3
    mov.w   .L_d92c_off_021C,r0         ! r0 = 0x021C
    mov.l   @(r0,r14),r2               ! r2 = car[0x021C]
    add     #1,r2

.L_d92c_store:
    mov.l   r2,@(r0,r14)               ! car[offset] = updated value
    mov     #40,r3
    mov.l   .L_d92c_timer,r2            ! r2 = &0x0607EAC0
    mov.l   r3,@r2                      ! *0x0607EAC0 = 40 (start timer)

    bsr     FUN_0600DCC8                ! checkpoint timing update
    nop

    ! Store position data for split times
    mov.l   .L_d92c_pos_ref,r5          ! r5 = &0x060786B0
    mov.w   .L_d92c_off_0230,r0
    mov.l   @r5,r4                      ! r4 = current position
    mov.l   @r5,r3
    mov.l   @(r0,r14),r2               ! r2 = car[0x0230] (prev position)
    mov.l   r3,@(r0,r14)               ! car[0x0230] = current position
    sub     r2,r4                        ! r4 = position_delta
    mov.l   @(r0,r14),r3
    mov.l   .L_d92c_pos_store,r2
    add     #-12,r0
    mov.l   r3,@r2                      ! store position reference
    mov.l   r4,@(r0,r14)               ! car[offset] = delta
    ! ... (continues with more timing storage)
    lds.l   @r15+,pr
    rts
    mov.l   @r15+,r14


! ================================================================
! FUN_0600DA7C — Finish line proximity detection
! ================================================================
!
! Called from: FUN_0600E4F2 (before FUN_0600CE66)
!
! Detects when the player car is near the start/finish line
! using checkpoint geometry. Sets bit 3 of car[byte+3] via
! FUN_06034F78(value, 0x1C01, car_ptr) as a proximity flag.
!
! Two paths:
!   car[0x00B8] != 0: Already near finish, just set flag
!   car[0x00B8] == 0: Compute from checkpoint geometry
!     - Gets checkpoint entry from car[0x01E4] index
!     - Calculates angular distance to checkpoint
!     - If within thresholds: sets proximity flag, increments
!       counter at 0x06078698
!     - If out of range: clears proximity flag, clears counters
!
! The proximity counter at 0x06078698 feeds into FUN_0600DBA0
! which triggers the "LAP" text display animation.
!
! ----------------------------------------------------------------

    .global FUN_0600DA7C
FUN_0600DA7C:                           ! 0x0600DA7C
    mov.l   r14,@-r15
    sts.l   pr,@-r15
    add     #-8,r15
    mov.l   .L_da7c_car_ptr,r4          ! r4 = &0x0607E940
    mov.l   .L_da7c_prox_flag,r14       ! r14 = &0x0607869A (proximity word)
    mov.l   .L_da7c_prox_counter,r5     ! r5 = &0x06078698 (proximity counter)
    mov.w   .L_da7c_off_00B8,r0         ! r0 = 0x00B8
    mov.l   @r4,r4                      ! r4 = car_ptr
    mov.l   @(r0,r4),r0                ! r0 = car[0x00B8]
    tst     r0,r0
    bt/s    .L_da7c_compute             ! if zero, compute from geometry
    mov     #1,r6

    ! Quick path: car[0x00B8] != 0 (already flagged)
    mov.w   @r14,r0
    extu.w  r0,r0
    tst     r0,r0
    bt      .L_da7c_exit_early          ! if proximity word zero, exit

    ! Set proximity flag
    mov     r6,r0                        ! r0 = 1
    mov.w   .L_da7c_param_1C01,r1       ! r1 = 0x1C01
    mov.l   .L_da7c_bitfield,r3         ! r3 = FUN_06034F78
    jsr     @r3                          ! FUN_06034F78(1, 0x1C01, car_ptr)
    mov     r4,r2                        ! → sets bit 3 of car[byte+3]
    mov.w   @r5,r2                      ! r2 = *0x06078698 (counter)
    add     #1,r2
    mov.w   r2,@r5                      ! counter++
    ! ... branches to FUN_0600DBA0 area

.L_da7c_compute:
    ! Compute proximity from checkpoint geometry
    ! (reads checkpoint table, computes angles, compares thresholds)
    ! If within range: r6=1, set flag, increment counter → DBA0
    ! If out of range: r6=0, clear flag, clear counters → DC74

.L_da7c_exit_early:
    add     #8,r15
    lds.l   @r15+,pr
    rts
    mov.l   @r15+,r14


! ================================================================
! FUN_0600DBA0 — Finish line display effects
! ================================================================
!
! Called from: continuation of FUN_0600DA7C (falls through via bra)
! Parameter: r3 = threshold (4 from normal path)
!
! When the proximity counter at 0x06078698 reaches the threshold,
! triggers the "LAP" text display animation using FUN_0601D5F4
! (VDP sprite display). Also checks the course type at
! *0x06078644 to select the correct animation frame.
!
! Counter at 0x060786A8 tracks cumulative animation progress.
! When counter reaches 7 or more, triggers the full lap
! animation. Reset counter when finished.
!
! ----------------------------------------------------------------

    .global FUN_0600DBA0
FUN_0600DBA0:                           ! 0x0600DBA0
    mov.l   r14,@-r15
    mov.l   r13,@-r15
    sts.l   pr,@-r15
    add     #-4,r15
    mov.l   .L_dba0_anim_counter,r14    ! r14 = &0x060786A8
    mov.l   .L_dba0_prox_counter,r0     ! r0 = &0x06078698
    mov.w   @r0,r0                      ! r0 = proximity counter
    extu.w  r0,r0
    and     #0x07,r0                    ! r0 = counter & 7
    cmp/ge  r3,r0                       ! if (counter & 7) >= threshold
    bt      .L_dba0_show_sprite         ! show the sprite

    ! Check course type and display appropriate animation
    ! ...

.L_dba0_show_sprite:
    ! Increment animation counter, reset on overflow
    ! Display lap text via FUN_0601D5F4 with color params
    ! Set *0x06086054 = 40 (display timer)
    ! Reset *0x060786A8 = 0

    add     #4,r15
    lds.l   @r15+,pr
    mov.l   @r15+,r13
    rts
    mov.l   @r15+,r14


! ================================================================
! FUN_06034F78 — Bitfield write utility
! ================================================================
!
! General-purpose function for writing values into specific bit
! fields of 32-bit words. Used extensively for car struct flags.
!
! Parameters:
!   r0 = value to write (truncated to bit_count bits)
!   r1 = packed parameter: high_byte = bit_position (from MSB)
!                           low_byte = bit_count
!   r2 = pointer to 32-bit word
!
! Decoding: actual_bit = 32 - bit_count - bit_position
!
! Examples:
!   r1 = 0x1501 → bit_pos=21, count=1, bit 10 = byte+2 bit 2 (lap flag)
!   r1 = 0x1C01 → bit_pos=28, count=1, bit  3 = byte+3 bit 3 (proximity)
!   r1 = 0x0301 → bit_pos= 3, count=1, bit 28 = byte+0 bit 4
!   r1 = 0x0201 → bit_pos= 2, count=1, bit 29 = byte+0 bit 5
!   r1 = 0x0801 → bit_pos= 8, count=1, bit 23 = byte+1 bit 7
!   r1 = 0x0901 → bit_pos= 9, count=1, bit 22 = byte+1 bit 6
!
! ----------------------------------------------------------------

    .global FUN_06034F78
FUN_06034F78:                           ! 0x06034F78
    mov.l   r1,@-r15                   ! save registers
    mov.l   r3,@-r15
    swap.b  r1,r3                       ! r3 = bit_position (high byte of r1)
    extu.b  r1,r1                       ! r1 = bit_count (low byte)
    mov.l   r4,@-r15
    extu.b  r3,r3
    mov.l   r5,@-r15
    mov     r1,r4                       ! r4 = loop counter = bit_count
    mov.l   r6,@-r15
    mov     #0,r5                       ! r5 = value_mask (builds from 0)
    mov     #-1,r6                      ! r6 = clear_mask (builds from 0xFFFFFFFF)

    ! Build bit_count-wide mask at bit 0
.sF78_loop1:
    shll    r5                          ! r5 <<= 1
    shll    r6                          ! r6 <<= 1
    add     #-1,r4
    add     #1,r5                       ! r5 = (r5<<1)|1
    cmp/pl  r4
    bf      .sF78_mask_done
    shll    r5                          ! (unrolled x2)
    shll    r6
    add     #-1,r4
    add     #1,r5
    cmp/pl  r4
    bt      .sF78_loop1

.sF78_mask_done:
    and     r5,r0                       ! r0 = value & mask (truncate)
    mov     #32,r4
    sub     r1,r4                       ! r4 = 32 - bit_count
    sub     r3,r4                       ! r4 = 32 - bit_count - bit_position
    mov     r0,r5                       ! r5 = truncated value
    tst     r4,r4
    bt      .sF78_apply                 ! if shift=0, skip

    ! Shift mask and value to target position
.sF78_loop2:
    shll    r6                          ! r6 <<= 1
    shll    r5                          ! r5 <<= 1
    add     #-1,r4
    add     #1,r6                       ! r6 = (r6<<1)|1 (fill with 1s)
    cmp/pl  r4
    bf      .sF78_apply
    shll    r6                          ! (unrolled x2)
    shll    r5
    add     #-1,r4
    add     #1,r6
    cmp/pl  r4
    bt      .sF78_loop2

.sF78_apply:
    mov.l   @r2,r4                      ! r4 = *ptr (read current word)
    and     r4,r6                       ! r6 = current & clear_mask (clear field)
    or      r6,r5                       ! r5 = cleared | new_value (merge)
    mov.l   r5,@r2                      ! *ptr = result (write back)

    ! Restore and return
    mov.l   @r15+,r6
    mov.l   @r15+,r5
    mov.l   @r15+,r4
    mov.l   @r15+,r3
    rts
    mov.l   @r15+,r1
