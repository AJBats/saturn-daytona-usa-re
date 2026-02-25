/* lap_complete_flag -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0600D9BC - 0x0600DA7C
 *
 * Lap completion flag manager — called when a car crosses the finish line.
 * Sets per-car completion bits in a shared bitmask, updates the car's
 * lap-complete count, and maintains the global lap counter / last-section
 * snapshot used for race-end detection.
 *
 * lap_complete_flag(r4 = car_index)
 *   Phase 1 (car_index == 0 only):
 *     If current section == lap boundary section, and the car's crossing
 *     counter (car[+0x228]) differs from the stored snapshot, latch the
 *     new value, increment the global lap counter, and clear the
 *     per-car completion bitmask when max laps is NOT yet reached.
 *   Phase 2 (all cars):
 *     Compute bitmask = 1 << car_index via shift_left_n.
 *     If this car's bit is not yet set in the completion bitmask, set it,
 *     write a 1-bit HUD flag at bit 21 via bitfield_insert, and bump
 *     car[+0x230] (per-car lap-complete count).
 *     If the race-end flag is set and this is an AI car (car_index != 0)
 *     without the 0x08 status bit, tail-call audio_dist_calc.
 *
 * Global variables:
 *   sym_06063F1C -- per-car lap completion bitmask (32-bit)
 *   sym_06063F18 -- section identifier snapshot (lap boundary section)
 *   sym_06063F20 -- last crossing counter snapshot
 *   sym_06063F24 -- global lap counter (incremented each full lap by car 0)
 *   sym_06063F28 -- maximum lap count for current race
 *   sym_0607E940 -- pointer to car struct array base
 *   sym_0607EAD8 -- race-end state flag (nonzero = race finishing)
 *
 * Car struct offsets:
 *   +0x003  = status byte (bit 3 = 0x08 flag)
 *   +0x021C = per-car lap counter (lap_counter - 0xC from crossing counter offset)
 *   +0x0228 = crossing counter (section boundary crossing count)
 *   +0x0230 = per-car lap-complete count
 */

    .section .text.FUN_0600D9BC


    .global lap_complete_flag
    .type lap_complete_flag, @function
lap_complete_flag:
    mov.l r14, @-r15                       ! save r14 (callee-saved)
    sts.l pr, @-r15                        ! save return address
    mov.l   .L_pool_completion_bitmask, r14 ! r14 = &completion_bitmask
    mov.l   .L_pool_car_struct_ptr, r5     ! r5 = &car_struct_ptr
    tst r4, r4                             ! car_index == 0? (player car)
    bf/s    .L_phase2_bitmask              ! if car_index != 0, skip phase 1
    mov.l @r5, r5                          ! (delay) r5 = car struct base ptr
    mov.l   .L_pool_section_id_snapshot, r3 ! r3 = &section_id_snapshot
    mov.l   .L_pool_completion_bitmask, r2 ! r2 = &completion_bitmask
    mov.l @r3, r3                          ! r3 = section_id_snapshot value
    mov.l @r2, r2                          ! r2 = completion_bitmask value
    cmp/eq r2, r3                          ! section_id == completion_bitmask?
    bf      .L_phase2_bitmask              ! if not equal, skip lap update
    mov.w   .L_wpool_crossing_ctr_off, r0  ! r0 = 0x0228 (crossing ctr offset)
    mov.l   .L_pool_crossing_snapshot, r3  ! r3 = &crossing_snapshot
    mov.l @(r0, r5), r2                   ! r2 = car[+0x228] (current crossing ctr)
    mov.l @r3, r3                          ! r3 = stored crossing snapshot
    cmp/eq r3, r2                          ! crossing ctr == snapshot?
    bt      .L_phase2_bitmask              ! if same, no new crossing — skip
    mov.w   .L_wpool_crossing_ctr_off, r0  ! r0 = 0x0228 (reload offset)
    mov.l   .L_pool_crossing_snapshot, r2  ! r2 = &crossing_snapshot
    mov.l @(r0, r5), r3                   ! r3 = car[+0x228] (new crossing ctr)
    add #-0xC, r0                          ! r0 = 0x021C (per-car lap counter offset)
    mov.l r3, @r2                          ! crossing_snapshot = new crossing ctr
    mov.l   .L_pool_lap_counter, r6        ! r6 = &global_lap_counter
    mov.l @r6, r3                          ! r3 = current lap counter
    add #0x1, r3                           ! r3 = lap_counter + 1
    mov.l r3, @r6                          ! store incremented lap counter
    mov.l r3, @(r0, r5)                   ! car[+0x21C] = new lap count
    mov.l @r6, r3                          ! r3 = lap counter (re-read)
    mov.l   .L_pool_max_laps, r2           ! r2 = &max_laps
    mov.l @r2, r2                          ! r2 = max lap count
    cmp/hs r2, r3                          ! lap_counter >= max_laps?
    bt      .L_phase2_bitmask              ! if at/past max, don't clear bitmask
    mov #0x0, r2                           ! r2 = 0
    mov.l r2, @r14                         ! completion_bitmask = 0 (reset for new lap)
.L_phase2_bitmask:
    mov #0x1, r7                           ! r7 = 1 (base value for bitmask)
    mov.l   .L_pool_fn_shift_left, r3     ! r3 = &shift_left_n
    mov r7, r0                             ! r0 = 1 (value to shift)
    jsr @r3                                ! r0 = shift_left_n(1, car_index)
    mov r4, r1                             ! (delay) r1 = car_index (shift amount)
    mov r0, r6                             ! r6 = car_bit = 1 << car_index
    mov.l @r14, r2                         ! r2 = completion_bitmask
    and r6, r2                             ! r2 = bitmask & car_bit
    tst r2, r2                             ! this car's bit already set?
    bf      .L_exit                        ! if already set, nothing to do
    mov r7, r0                             ! r0 = 1 (unused, but sets r0 for return)
    mov.l @r14, r3                         ! r3 = completion_bitmask
    or r6, r3                              ! r3 = bitmask | car_bit (set this car's bit)
    mov.l r3, @r14                         ! store updated bitmask
    mov.w   .L_wpool_hud_flag_param, r1    ! r1 = 0x1501 (width=1, pos=21 packed param)
    mov.l   .L_pool_fn_bitfield_insert, r3 ! r3 = &bitfield_insert
    jsr @r3                                ! bitfield_insert(r0=1, r1=0x1501, r2=car)
    mov r5, r2                             ! (delay) r2 = car struct ptr (dest)
    mov.w   .L_wpool_lap_done_count_off, r0 ! r0 = 0x0230 (lap-done count offset)
    mov.l @(r0, r5), r2                   ! r2 = car[+0x230] (lap-done count)
    add #0x1, r2                           ! r2 = lap_done_count + 1
    mov.l r2, @(r0, r5)                   ! car[+0x230] = incremented count
    mov.l   .L_pool_race_end_flag, r0     ! r0 = &race_end_flag
    mov.l @r0, r0                          ! r0 = race_end_flag value
    tst r0, r0                             ! race ending?
    bt      .L_exit                        ! if race_end == 0, just return
    tst r4, r4                             ! car_index == 0? (player car)
    bt      .L_exit                        ! if player car, just return
    mov r5, r0                             ! r0 = car struct ptr
    mov.b @(3, r0), r0                    ! r0 = car[+0x03] (status byte)
    tst #0x8, r0                           ! status bit 3 set? (0x08 flag)
    bf      .L_exit                        ! if flag set, skip tail-call
    lds.l @r15+, pr                        ! restore pr (pre-tail-call epilogue)
    .byte   0xA1, 0x9F    /* bra 0x0600DD88 (external) — tail-call audio_dist_calc */
    mov.l @r15+, r14                       ! (delay) restore r14
.L_exit:
    lds.l @r15+, pr                        ! restore return address
    rts                                    ! return to caller
    mov.l @r15+, r14                       ! (delay) restore r14
.L_wpool_crossing_ctr_off:
    .2byte  0x0228                         ! car struct offset: crossing counter
.L_wpool_hud_flag_param:
    .2byte  0x1501                         ! bitfield_insert param: width=1, pos=21
.L_wpool_lap_done_count_off:
    .2byte  0x0230                         ! car struct offset: lap-done count
    .2byte  0xFFFF                         ! alignment padding
.L_pool_completion_bitmask:
    .4byte  sym_06063F1C                   ! per-car lap completion bitmask (32-bit)
.L_pool_car_struct_ptr:
    .4byte  sym_0607E940                   ! pointer to car struct array base
.L_pool_section_id_snapshot:
    .4byte  sym_06063F18                   ! section identifier snapshot (lap boundary)
.L_pool_crossing_snapshot:
    .4byte  sym_06063F20                   ! last crossing counter snapshot
.L_pool_lap_counter:
    .4byte  sym_06063F24                   ! global lap counter
.L_pool_max_laps:
    .4byte  sym_06063F28                   ! maximum lap count for current race
.L_pool_fn_shift_left:
    .4byte  sym_06035280                   ! shift_left_n: r0 = r0 << r1
.L_pool_fn_bitfield_insert:
    .4byte  sym_06034F78                   ! bitfield_insert(val, width|pos, dest)
.L_pool_race_end_flag:
    .4byte  sym_0607EAD8                   ! race-end state flag (nonzero = finishing)
