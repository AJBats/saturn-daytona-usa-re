/* finish_proximity -- Finish line proximity detection and lap display
 * Translation unit: 0x0600DA7C - 0x0600DCC8
 *
 * Detects when the player car is near the start/finish line using
 * checkpoint geometry, and triggers the "LAP" text display animation.
 *
 * Functions:
 *   finish_proximity (0x0600DA7C)
 *     Checks car[0x00B8] proximity flag. If already set, sets the
 *     bitfield flag and increments the proximity counter. If zero,
 *     computes angular distance from checkpoint geometry -- within
 *     thresholds sets the flag, out of range clears everything.
 *
 *   sym_0600DB64 (0x0600DB64)
 *     Lap counter increment. Tests byte+2 bit 2 (lap flag set by
 *     the checkpoint system). If set: clears it, increments lap
 *     counter at car[0x015C], starts lap display timer, accumulates
 *     lap time, and tail-calls sound_notify_handler.
 *
 *   car_update_post (0x0600DB9C)
 *     Entry point that sets r3=4 threshold and falls through to
 *     finish_display.
 *
 *   finish_display (0x0600DBA0)
 *     Finish line display effects. When proximity counter & 7 >=
 *     threshold, triggers "LAP" text overlay via VDP sprite display.
 *     Plays countdown/lap SFX (0xAE1138FF or course-specific
 *     0xAE1139FF). Manages animation counter at 0x060786A8.
 *
 *   checkpoint_sound_trigger (0x0600DC74)
 *     Plays checkpoint crossing sound effects via the VDP number
 *     text renderer (sym_060284AE) with two screen positions.
 *
 * Key data:
 *   0x0607E940 = car object pointer
 *   0x06078698 = proximity counter (word)
 *   0x0607869A = proximity flag word
 *   0x060786A8 = animation frame counter
 *   0x06078644 = course type selector
 */

    .section .text.FUN_0600DA7C


    .global finish_proximity
    .type finish_proximity, @function
finish_proximity:
    mov.l r14, @-r15                    ! save r14
    sts.l pr, @-r15                     ! save pr
    add #-0x8, r15                      ! allocate 8 bytes on stack
    mov.l   .L_car_obj_ptr, r4         ! r4 = &car_ptr (sym_0607E940)
    mov.l   .L_prox_flag_ptr, r14      ! r14 = &prox_flag_word (sym_0607869A)
    mov.l   .L_prox_counter_ptr, r5    ! r5 = &prox_counter (sym_06078698)
    mov.w   DAT_0600db40, r0           ! r0 = 0x00B8 (car struct offset)
    mov.l @r4, r4                       ! r4 = car_ptr (deref)
    mov.l @(r0, r4), r0                ! r0 = car[0x00B8] (proximity state)
    tst r0, r0                          ! test if proximity state is zero
    bt/s    .L_compute_from_geometry   ! if zero -> compute from geometry
    mov #0x1, r6                        ! r6 = 1 (delay slot: set flag value)
    mov.w @r14, r0                      ! r0 = *prox_flag_word
    extu.w r0, r0                       ! zero-extend to 32-bit
    tst r0, r0                          ! test if prox flag is zero
    bt      .L_exit_early              ! if zero -> exit early (no flag set)
    mov r6, r0                          ! r0 = 1 (value to write)
    mov.w   .L_param_1C01, r1         ! r1 = 0x1C01 (bit_pos=28, count=1 -> bit 3)
    mov.l   .L_fn_bitfield_write, r3  ! r3 = bitfield_write fn (sym_06034F78)
    jsr @r3                             ! bitfield_write(1, 0x1C01, car_ptr)
    mov r4, r2                          ! r2 = car_ptr (delay slot)
    mov.w @r5, r2                       ! r2 = *prox_counter
    add #0x1, r2                        ! r2 = counter + 1
    mov.w r2, @r5                       ! *prox_counter = counter + 1
    add #0x8, r15                       ! free stack
    lds.l @r15+, pr                     ! restore pr
    bra     car_update_post            ! -> finish display with threshold=4
    mov.l @r15+, r14                    ! restore r14 (delay slot)
.L_compute_from_geometry:
    mov.w   DAT_0600db44, r0           ! r0 = 0x01E4 (checkpoint index offset)
    mov.l @(r0, r4), r7                ! r7 = car[0x01E4] (checkpoint index)
    add #-0x4, r0                       ! r0 = 0x01E0 (checkpoint table offset)
    mov r7, r3                          ! r3 = checkpoint_idx
    shll2 r7                            ! r7 = idx * 4
    shll2 r3                            ! r3 = idx * 4
    shll r7                             ! r7 = idx * 8
    shll2 r3                            ! r3 = idx * 16
    add r3, r7                          ! r7 = idx * 24 (stride = 24 bytes)
    mov.l @(r0, r4), r3                ! r3 = car[0x01E0] (checkpoint table base)
    add r3, r7                          ! r7 = &checkpoint_entry[idx]
    mov.w @(14, r7), r0                ! r0 = entry[14] (checkpoint angle)
    mov r0, r3                          ! r3 = angle
    shll2 r3                            ! r3 = angle * 4
    mov.l r3, @r15                      ! sp[0] = angle * 4
    mov.l @(40, r4), r2                ! r2 = car[0x28] (car angle X)
    sub r3, r2                          ! r2 = car_angle - checkpoint_angle*4
    extu.w r2, r2                       ! zero-extend to 16-bit (unsigned distance)
    mov r2, r0                          ! r0 = dist_x
    mov.w r0, @(4, r15)                ! sp[4] = dist_x (16-bit)
    mov.l @(32, r4), r7                ! r7 = car[0x20] (car angle Y)
    mov.l @r15, r3                      ! r3 = angle * 4
    mov.w @(4, r15), r0                ! r0 = dist_x
    sub r3, r7                          ! r7 = car_angle_y - checkpoint_angle*4
    mov r0, r2                          ! r2 = dist_x
    extu.w r2, r2                       ! zero-extend
    mov.l r2, @r15                      ! sp[0] = dist_x (32-bit)
    mov.w   DAT_0600db46, r1           ! r1 = 0x4000 (lower threshold)
    cmp/ge r1, r2                       ! if dist_x >= 0x4000
    bf/s    .L_out_of_range            ! if dist_x < threshold -> out of range
    extu.w r7, r7                       ! r7 = dist_y unsigned (delay slot)
    mov.l @r15, r3                      ! r3 = dist_x
    mov.l   .L_mask_0xC000, r2        ! r2 = 0xC000 (upper threshold)
    cmp/gt r2, r3                       ! if dist_x > 0xC000
    bt      .L_out_of_range            ! too far past -> out of range
    extu.w r7, r2                       ! r2 = dist_y
    mov.w   DAT_0600db46, r3           ! r3 = 0x4000 (lower threshold)
    cmp/ge r3, r2                       ! if dist_y >= 0x4000
    bf      .L_out_of_range            ! if dist_y < threshold -> out of range
    extu.w r7, r3                       ! r3 = dist_y
    mov.l   .L_mask_0xC000, r2        ! r2 = 0xC000 (upper threshold)
    cmp/gt r2, r3                       ! if dist_y > 0xC000
    bf      .L_within_range            ! dist_y in [0x4000..0xC000] -> near finish
.L_out_of_range:
    mov #0x0, r6                        ! r6 = 0 (clear flag value)
    mov.w   .L_param_1C01, r1         ! r1 = 0x1C01 (bit 3 proximity flag)
    mov.l   .L_fn_bitfield_write, r3  ! r3 = bitfield_write fn
    mov r6, r0                          ! r0 = 0 (clear proximity bit)
    jsr @r3                             ! bitfield_write(0, 0x1C01, car_ptr)
    mov r4, r2                          ! r2 = car_ptr (delay slot)
    mov.w r6, @r5                       ! *prox_counter = 0 (reset counter)
    extu.w r6, r6                       ! r6 = 0 (zero-extend)
    mov.w r6, @r14                      ! *prox_flag_word = 0 (clear flag)
    add #0x8, r15                       ! free stack
    lds.l @r15+, pr                     ! restore pr
    bra     checkpoint_sound_trigger   ! -> play checkpoint sound
    mov.l @r15+, r14                    ! restore r14 (delay slot)
.L_within_range:
    mov r6, r0                          ! r0 = 1 (set proximity bit)
    mov.w   .L_param_1C01, r1         ! r1 = 0x1C01 (bit 3 proximity flag)
    mov.l   .L_fn_bitfield_write, r3  ! r3 = bitfield_write fn
    jsr @r3                             ! bitfield_write(1, 0x1C01, car_ptr)
    mov r4, r2                          ! r2 = car_ptr (delay slot)
    mov.w @r5, r2                       ! r2 = *prox_counter
    add #0x1, r2                        ! r2 = counter + 1
    mov.w r2, @r5                       ! *prox_counter++ (increment)
    extu.w r6, r6                       ! r6 = 1 (zero-extend)
    mov.w r6, @r14                      ! *prox_flag_word = 1 (set flag)
    add #0x8, r15                       ! free stack
    lds.l @r15+, pr                     ! restore pr
    bra     car_update_post            ! -> finish display with threshold=4
    mov.l @r15+, r14                    ! restore r14 (delay slot)

    .global DAT_0600db40
DAT_0600db40:
    .2byte  0x00B8                      /* car struct offset: proximity state */
.L_param_1C01:
    .2byte  0x1C01                      /* bitfield param: bit_pos=28, count=1 -> bit 3 (proximity) */

    .global DAT_0600db44
DAT_0600db44:
    .2byte  0x01E4                      /* car struct offset: checkpoint index */

    .global DAT_0600db46
DAT_0600db46:
    .2byte  0x4000                      /* angular distance lower threshold */
.L_car_obj_ptr:
    .4byte  sym_0607E940                /* -> car object pointer */
.L_prox_flag_ptr:
    .4byte  sym_0607869A                /* -> proximity flag word */
.L_prox_counter_ptr:
    .4byte  sym_06078698                /* -> proximity counter */
.L_fn_bitfield_write:
    .4byte  sym_06034F78                /* -> bitfield write utility */
.L_mask_0xC000:
    .4byte  0x0000C000                  /* angular distance upper threshold */
.L_exit_early:
    add #0x8, r15                       ! free stack
    lds.l @r15+, pr                     ! restore pr
    rts                                 ! return (prox flag word was zero)
    mov.l @r15+, r14                    ! restore r14 (delay slot)

    .global sym_0600DB64
sym_0600DB64:
    mov.l   .L_lap_car_obj_ptr, r4    ! r4 = &car_ptr (sym_0607E940)
    mov.l @r4, r4                       ! r4 = car_ptr (deref)
    mov r4, r0                          ! r0 = car_ptr
    mov.b @(2, r0), r0                 ! r0 = car[byte+2] (flag byte)
    tst #0x4, r0                        ! test bit 2 = lap flag
    bt      .L_no_lap_flag             ! if not set -> skip
    mov r4, r3                          ! r3 = car_ptr
    add #0x2, r3                        ! r3 = &car[byte+2]
    mov.b @r3, r0                       ! r0 = car[byte+2]
    and #0xFB, r0                       ! clear bit 2 (lap flag consumed)
    or #0x0, r0                         ! no-op (compiler artifact)
    mov.b r0, @r3                       ! store cleared flag byte
    mov.w   DAT_0600dbda, r0           ! r0 = 0x015C (lap counter offset)
    mov.l @(r0, r4), r2                ! r2 = car[0x015C] (lap count)
    add #0x1, r2                        ! r2 = lap_count + 1
    mov.l r2, @(r0, r4)                ! car[0x015C] = new lap count
    mov #0x28, r3                       ! r3 = 40 (display timer frames)
    mov.l   .L_lap_disp_timer, r2     ! r2 = &lap_disp_timer (sym_0607EABC)
    mov.l r3, @r2                       ! *lap_disp_timer = 40
    mov.l   .L_accum_time_ptr, r4     ! r4 = &accum_time (sym_0607EAAC)
    mov.l   .L_lap_delta_ptr, r3      ! r3 = &lap_delta (sym_0607EAA0)
    mov.l @r3, r3                       ! r3 = lap_delta (this lap's time)
    mov.l @r4, r2                       ! r2 = accum_time (total so far)
    add r3, r2                          ! r2 = total + delta
    mov.l   .L_fn_sound_notify, r3    ! r3 = sound_notify_handler
    jmp @r3                             ! tail-call -> sound_notify_handler
    mov.l r2, @r4                       ! *accum_time = new total (delay slot)
.L_no_lap_flag:
    rts                                 ! return (no lap flag set)
    nop                                 ! delay slot

    .global car_update_post
    .type car_update_post, @function
car_update_post:
    mov #0x4, r3                        ! r3 = 4 (display threshold, falls through)

    .global finish_display
    .type finish_display, @function
finish_display:
    mov.l r14, @-r15                    ! save r14
    mov.l r13, @-r15                    ! save r13
    sts.l pr, @-r15                     ! save pr
    add #-0x4, r15                      ! allocate 4 bytes on stack
    mov.l   .L_anim_counter_ptr, r14   ! r14 = &anim_counter (sym_060786A8)
    mov.l   .L_disp_prox_counter, r0  ! r0 = &prox_counter (sym_06078698)
    mov.w @r0, r0                       ! r0 = *prox_counter (16-bit)
    extu.w r0, r0                       ! zero-extend
    and #0x7, r0                        ! r0 = counter & 0x7 (modulo 8)
    cmp/ge r3, r0                       ! if (counter & 7) >= threshold
    bt      .L_threshold_reached       ! -> play checkpoint sound only
    mov.l   .L_course_type_ptr, r0    ! r0 = &course_type (sym_06078644)
    mov.l @r0, r0                       ! r0 = *course_type
    cmp/eq #0x1, r0                    ! if course_type == 1
    bf      .L_other_course            ! if not course 1 -> other path
    mov.l   .L_overlay_data_course1, r2 ! r2 = overlay data (course 1, sym_060637F8)
    mov.l r2, @r15                      ! sp[0] = overlay_ptr (save for later)
    mov r2, r7                          ! r7 = overlay_ptr
    mov r2, r5                          ! r5 = overlay_ptr
    mov.w   DAT_0600dbdc, r3           ! r3 = 0x4000 (Y offset for VDP)
    mov.w   .L_screen_pos_y_course1, r6 ! r6 = 0x0AC0 (screen position Y)
    mov.l @(4, r7), r7                 ! r7 = overlay[1] (texture data ptr)
    mov.l @r5, r5                       ! r5 = overlay[0] (base data ptr)
    add r3, r7                          ! r7 += 0x4000 (add VDP offset)
    mov.l   .L_fn_overlay_render, r3  ! r3 = overlay_render fn (sym_06028400)
    jsr @r3                             ! overlay_render(8, base, y, texture, ...)
    mov #0x8, r4                        ! r4 = 8 (VDP layer/priority, delay slot)
    bra     .L_after_overlay           ! -> post-overlay processing
    nop                                 ! delay slot

    .global DAT_0600dbda
DAT_0600dbda:
    .2byte  0x015C                      /* car struct offset: lap counter */

    .global DAT_0600dbdc
DAT_0600dbdc:
    .2byte  0x4000                      /* VDP Y offset for overlay */
.L_screen_pos_y_course1:
    .2byte  0x0AC0                      /* screen position Y (course 1) */
.L_lap_car_obj_ptr:
    .4byte  sym_0607E940                /* -> car object pointer */
.L_lap_disp_timer:
    .4byte  sym_0607EABC                /* -> lap display timer (frames) */
.L_accum_time_ptr:
    .4byte  sym_0607EAAC                /* -> accumulated race time */
.L_lap_delta_ptr:
    .4byte  sym_0607EAA0                /* -> current lap time delta */
.L_fn_sound_notify:
    .4byte  sound_notify_handler        /* -> lap complete sound handler */
.L_anim_counter_ptr:
    .4byte  sym_060786A8                /* -> animation frame counter */
.L_disp_prox_counter:
    .4byte  sym_06078698                /* -> proximity counter (word) */
.L_course_type_ptr:
    .4byte  sym_06078644                /* -> course type selector */
.L_overlay_data_course1:
    .4byte  sym_060637F8                /* -> overlay sprite data (course 1) */
.L_fn_overlay_render:
    .4byte  sym_06028400                /* -> overlay rendering function */
.L_other_course:
    mov.l   .L_overlay_data_other, r2  ! r2 = overlay data (other courses, sym_06063808)
    mov.l r2, @r15                      ! sp[0] = overlay_ptr (save for later)
    mov r2, r7                          ! r7 = overlay_ptr
    mov r2, r5                          ! r5 = overlay_ptr
    mov.w   DAT_0600dc98, r3           ! r3 = 0x4000 (Y offset for VDP)
    mov.w   DAT_0600dc9a, r6           ! r6 = 0x0B3C (screen position Y, other courses)
    mov.l @(4, r7), r7                 ! r7 = overlay[1] (texture data ptr)
    mov.l @r5, r5                       ! r5 = overlay[0] (base data ptr)
    add r3, r7                          ! r7 += 0x4000 (add VDP offset)
    mov.l   .L_fn_overlay_render_2, r3 ! r3 = overlay_render fn (sym_06028400)
    jsr @r3                             ! overlay_render(8, base, y, texture, ...)
    mov #0x8, r4                        ! r4 = 8 (VDP layer/priority, delay slot)
    bra     .L_after_overlay           ! -> post-overlay processing
    nop                                 ! delay slot
.L_threshold_reached:
    bsr     checkpoint_sound_trigger   ! play checkpoint crossing sound
    nop                                 ! delay slot
.L_after_overlay:
    mov.l   .L_frame_counter_ptr, r0  ! r0 = &prox_counter (sym_06078698)
    mov.w @r0, r0                       ! r0 = *prox_counter (16-bit)
    extu.w r0, r0                       ! zero-extend
    tst #0x3F, r0                       ! test if (counter & 0x3F) == 0
    bf      .L_disp_epilogue           ! if non-zero -> skip SFX trigger
    mov.l @r14, r3                      ! r3 = *anim_counter
    add #0x1, r3                        ! r3 = anim_counter + 1
    mov.l r3, @r14                      ! *anim_counter = incremented
    mov r3, r2                          ! r2 = new counter value
    mov.l   .L_fn_sound_cmd, r13      ! r13 = sound_cmd_dispatch
    mov #0x7, r3                        ! r3 = 7 (animation threshold)
    cmp/hs r3, r2                       ! if counter >= 7 (unsigned)
    bt      .L_counter_ge_7           ! -> full animation + course check
    mov.l   .L_sfx_standard_lap, r5   ! r5 = 0xAE1138FF (standard lap SFX)
    jsr @r13                            ! sound_cmd_dispatch(0, sfx_data)
    mov #0x0, r4                        ! r4 = 0 (command type, delay slot)
    bra     .L_disp_epilogue           ! -> epilogue
    nop                                 ! delay slot
.L_counter_ge_7:
    mov.l   .L_course_type_ptr_2, r0  ! r0 = &course_type (sym_06078644)
    mov.l @r0, r0                       ! r0 = *course_type
    cmp/eq #0x1, r0                    ! if course_type == 1
    bf      .L_use_standard_sfx        ! if not course 1 -> use standard SFX
    mov.l   .L_sfx_course1_variant, r5 ! r5 = 0xAE1139FF (course 1 variant SFX)
    bra     .L_play_sfx                ! -> play the selected SFX
    nop                                 ! delay slot
.L_use_standard_sfx:
    mov.l   .L_sfx_standard_lap, r5   ! r5 = 0xAE1138FF (standard lap SFX)
.L_play_sfx:
    jsr @r13                            ! sound_cmd_dispatch(0, sfx_data)
    mov #0x0, r4                        ! r4 = 0 (command type, delay slot)
    mov #0x28, r2                       ! r2 = 40 (reset timer value)
    mov.l   .L_sound_timer_ptr, r3    ! r3 = &sound_timer (sym_06086054)
    mov.w r2, @r3                       ! *sound_timer = 40 (display duration)
    mov #0x0, r2                        ! r2 = 0
    mov.l r2, @r14                      ! *anim_counter = 0 (reset)
.L_disp_epilogue:
    add #0x4, r15                       ! free stack
    lds.l @r15+, pr                     ! restore pr
    mov.l @r15+, r13                    ! restore r13
    rts                                 ! return
    mov.l @r15+, r14                    ! restore r14 (delay slot)

    .global checkpoint_sound_trigger
    .type checkpoint_sound_trigger, @function
checkpoint_sound_trigger:
    sts.l pr, @-r15                     ! save pr
    mov #0x60, r6                       ! r6 = 0x60 (screen width/position param)
    add #-0x4, r15                      ! allocate 4 bytes on stack
    mov.l   .L_chkpt_sfx_data, r3    ! r3 = sfx data ptr (sym_0605ACE8)
    mov.l r3, @r15                      ! sp[0] = sfx_data_ptr (save for 2nd call)
    mov r3, r7                          ! r7 = sfx_data_ptr
    mov.w   DAT_0600dc9c, r5           ! r5 = 0x0ABC (screen position 1)
    mov.l   .L_fn_vdp_num_text, r3    ! r3 = vdp_num_text fn (sym_060284AE)
    jsr @r3                             ! vdp_num_text(8, pos1, 0x60, sfx_data)
    mov #0x8, r4                        ! r4 = 8 (VDP layer/priority, delay slot)
    mov.l @r15, r7                      ! r7 = sfx_data_ptr (reload from stack)
    mov #0x60, r6                       ! r6 = 0x60 (screen width/position param)
    mov.w   DAT_0600dc9e, r5           ! r5 = 0x0BBC (screen position 2)
    mov #0x8, r4                        ! r4 = 8 (VDP layer/priority)
    add #0x4, r15                       ! free stack
    mov.l   .L_fn_vdp_num_text, r3    ! r3 = vdp_num_text fn (sym_060284AE)
    jmp @r3                             ! tail-call -> vdp_num_text(8, pos2, 0x60, sfx_data)
    lds.l @r15+, pr                     ! restore pr (delay slot)

    .global DAT_0600dc98
DAT_0600dc98:
    .2byte  0x4000                      /* VDP Y offset (other courses) */

    .global DAT_0600dc9a
DAT_0600dc9a:
    .2byte  0x0B3C                      /* screen position Y (other courses) */

    .global DAT_0600dc9c
DAT_0600dc9c:
    .2byte  0x0ABC                      /* checkpoint sound screen position 1 */

    .global DAT_0600dc9e
DAT_0600dc9e:
    .2byte  0x0BBC                      /* checkpoint sound screen position 2 */
.L_overlay_data_other:
    .4byte  sym_06063808                /* -> overlay sprite data (other courses) */
.L_fn_overlay_render_2:
    .4byte  sym_06028400                /* -> overlay rendering function */
.L_frame_counter_ptr:
    .4byte  sym_06078698                /* -> proximity counter (word) */
.L_fn_sound_cmd:
    .4byte  sound_cmd_dispatch          /* -> sound command dispatcher */
.L_sfx_standard_lap:
    .4byte  0xAE1138FF                  /* standard lap/countdown SFX data */
.L_course_type_ptr_2:
    .4byte  sym_06078644                /* -> course type selector */
.L_sfx_course1_variant:
    .4byte  0xAE1139FF                  /* course 1 specific SFX variant */
.L_sound_timer_ptr:
    .4byte  sym_06086054                /* -> sound/display timer */
.L_chkpt_sfx_data:
    .4byte  sym_0605ACE8                /* -> checkpoint SFX data block */
.L_fn_vdp_num_text:
    .4byte  sym_060284AE                /* -> VDP number+text renderer */
