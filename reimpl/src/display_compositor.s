/* display_compositor -- Display layer composition subsystem
 * Translation unit: 0x06005AE8 - 0x06005C98
 *
 * Called every frame as the 4th subsystem in the per-frame dispatch chain
 * (frame_dispatch -> world_update -> input_events -> anim_timing -> THIS).
 *
 * Composes display list entries for multiple HUD/overlay layers by calling
 * the display list command writer (sym_06028430) with layer-specific params:
 *   r4 = 0x8 (VDP command mode / priority)
 *   r5 = X position or tile offset
 *   r6 = display list slot offset (0x0C, 0x24, 0x30, 0x6C, 0x18, 0x60)
 *   r7 = value/counter to write (often field from car state struct + 1)
 *
 * Layer composition sequence:
 *   1. Frame counter layer (offset 0x0C): car_state[+0x021C] + 1,
 *      clamped to max_frame_count. X = 0x0108.
 *   2. Y-axis layer (offset 0x24): car_state[+0x8] + 1.
 *      If 2p_mode_flag set, X = 0x0220; else X = 0x0320.
 *      If scale_mode enabled, applies perspective scale (0x9F1A * val >> 16).
 *   3. Z-axis layer (offset 0x30, conditional): only if extra_layer_flag clear.
 *      car_state[+0x0224] + 1, X = 0x0142.
 *   4. Effect layer (offset 0x6C): car_state[+0x00DE or +0x00DC] + 1.
 *      If 2p_mode_flag set, X = 0x0236; else X = 0x0336.
 *      Scale mode vs alt offset source selected by sym_0607EAB8 flag.
 *
 * 2-player split-screen path (2p_mode_flag clear):
 *   Checks game_state_bitmask bit 17 (0x00020000) for effect overlay.
 *   Manages an effect timer (sym_06063E0C) that counts down from 120 -> 0:
 *     - At 120: resets fade timer to 60, overlay counter to 8
 *     - While timer >= 120: skip effect
 *     - While overlay_counter > 0: decrements, calls sound_cmd_dispatch,
 *       decrements fade_timer by 3 (clamped to 8 min), computes
 *       brightness = fade_timer >> 3 + 1, stores to overlay_counter
 *     - When overlay_counter == 0: calls geom_dispatch_final (tail-call)
 *       with static text data (sym_0605ACF3) at offset 0x60, size 0xA6.
 *
 * Symbols:
 *   sym_06085FF4 = 2p_mode_flag (byte, 0=1P, 1=2P)
 *   sym_0607EAAC = effect_timer_ptr (dword, counts up to 120)
 *   sym_06063E10 = overlay_counter (dword, counts down)
 *   sym_06063E0C = fade_timer (dword, counts down by 3)
 *   sym_06028430 = display_list_cmd_writer (function)
 *   sym_0607E944 = car_state_ptr (pointer to car state struct)
 *   sym_06063F28 = max_frame_count (dword)
 *   sym_06078644 = scale_mode_flag (dword)
 *   sym_0607EAE0 = extra_layer_flag (dword)
 *   sym_0607EAB8 = alt_offset_flag (dword)
 *   sym_0607EBC4 = game_state_bitmask (dword)
 *   sym_06034FE0 = geometry_transform (function)
 *   sym_0605ACF3 = static_text_data (ROM data, spaces + terminator)
 *   sym_060284AE = geom_dispatch_final (function, VDP text+number renderer)
 *   sound_cmd_dispatch = sound command dispatcher
 */

    .section .text.FUN_06005AE8


    .global display_compositor
    .type display_compositor, @function
display_compositor:
    mov.l r14, @-r15                        ! save r14
    mov.l r13, @-r15                        ! save r13
    mov.l r12, @-r15                        ! save r12
    mov.l r11, @-r15                        ! save r11
    mov.l r10, @-r15                        ! save r10
    mov.l r9, @-r15                         ! save r9
    mov.l r8, @-r15                         ! save r8
    sts.l pr, @-r15                         ! save return address
    sts.l macl, @-r15                       ! save macl (function uses mul.l)
    mov.l   _pool_2p_mode_flag, r8          ! r8 -> &2p_mode_flag (sym_06085FF4)
    mov.l   _pool_effect_timer_ptr, r9      ! r9 -> &effect_timer (sym_0607EAAC)
    mov.l   _pool_overlay_counter, r11      ! r11 -> &overlay_counter (sym_06063E10)
    mov.l   _pool_fade_timer, r12           ! r12 -> &fade_timer (sym_06063E0C)
    mov.l   _pool_dlist_cmd_writer, r13     ! r13 -> &display_list_cmd_writer (sym_06028430)
    mov.l   _pool_car_state_ptr, r14       ! r14 -> &car_state_ptr (sym_0607E944)
    mov.w   DAT_06005b7c, r0               ! r0 = 0x021C (frame counter field offset)
    mov.l   _pool_max_frame_count, r3      ! r3 -> &max_frame_count (sym_06063F28)
    mov.l @r14, r14                         ! r14 = *car_state_ptr (deref to struct)
    mov.l @r3, r3                           ! r3 = max_frame_count value
    mov.l @(r0, r14), r7                    ! r7 = car_state[+0x021C] (frame counter)
    add #0x1, r7                            ! r7 = frame_counter + 1
    cmp/hi r3, r7                           ! if (r7 > max_frame_count)
    bt/s    .L_layer1_done                  !   skip layer 1 write (value too large)
    mov #0x8, r10                           ! r10 = 8 (constant: min overlay counter)
    mov #0xC, r6                            ! r6 = 0x0C (display list slot: frame counter)
    mov.w   _wpool_x_pos_frame, r5         ! r5 = 0x0108 (X position for frame counter)
    jsr @r13                                ! call dlist_cmd_writer(r4=8, r5=0x108, r6=0xC, r7=count)
    mov #0x8, r4                            ! (delay) r4 = 0x8 (VDP command mode)
.L_layer1_done:
    mov.b @r8, r0                           ! r0 = 2p_mode_flag
    tst r0, r0                              ! test if 1-player mode
    bt      .L_1p_y_offset                  ! if 1P: use wider X offset
    mov.w   DAT_06005b80, r5               ! r5 = 0x0220 (2P Y-axis X position)
    bra     .L_y_layer_common               ! continue to Y-axis layer
    nop                                     ! delay slot
.L_1p_y_offset:
    mov.w   DAT_06005b82, r5               ! r5 = 0x0320 (1P Y-axis X position)
.L_y_layer_common:
    mov.l   _pool_scale_mode_flag, r0     ! r0 -> &scale_mode_flag (sym_06078644)
    mov.l @r0, r0                           ! r0 = scale_mode_flag value
    tst r0, r0                              ! test if scale mode disabled
    bt      .L_apply_perspective            ! if disabled: apply perspective scaling
    bra     .L_y_write                      ! if enabled: skip scaling, use raw value
    mov.l @(8, r14), r7                     ! (delay) r7 = car_state[+0x8] (Y-axis value)
.L_apply_perspective:
    mov.l @(8, r14), r7                     ! r7 = car_state[+0x8] (Y-axis value)
    mov.l   _pool_perspective_scale, r3    ! r3 = 0x00009F1A (perspective scale ~0.621)
    mul.l r3, r7                            ! macl = scale * y_value
    sts macl, r7                            ! r7 = full 32-bit product
    shlr16 r7                               ! r7 >>= 16 (fixed-point 16.16 -> integer)
.L_y_write:
    mov #0x24, r6                           ! r6 = 0x24 (display list slot: Y-axis)
    jsr @r13                                ! call dlist_cmd_writer(r4=8, r5, r6=0x24, r7)
    mov #0x8, r4                            ! (delay) r4 = 0x8 (VDP command mode)
    mov.l   _pool_extra_layer_flag, r0     ! r0 -> &extra_layer_flag (sym_0607EAE0)
    mov.l @r0, r0                           ! r0 = extra_layer_flag value
    tst r0, r0                              ! test if extra layer disabled
    bf      .L_z_layer_done                 ! if enabled (nonzero): skip Z-axis layer
    mov.w   DAT_06005b84, r0               ! r0 = 0x0224 (Z-axis field offset in car_state)
    mov #0x30, r6                           ! r6 = 0x30 (display list slot: Z-axis)
    mov.w   _wpool_x_pos_z, r5            ! r5 = 0x0142 (X position for Z-axis layer)
    mov.l @(r0, r14), r7                    ! r7 = car_state[+0x0224] (Z-axis value)
    add #0x1, r7                            ! r7 = z_value + 1
    jsr @r13                                ! call dlist_cmd_writer(r4=8, r5=0x142, r6=0x30, r7)
    mov #0x8, r4                            ! (delay) r4 = 0x8 (VDP command mode)
.L_z_layer_done:
    mov.b @r8, r0                           ! r0 = 2p_mode_flag
    tst r0, r0                              ! test if 1-player mode
    bt      .L_1p_effect_offset             ! if 1P: use wider effect X offset
    mov.w   DAT_06005b88, r5               ! r5 = 0x0236 (2P effect X position)
    bra     .L_effect_layer_common          ! continue to effect layer
    nop                                     ! delay slot
.L_1p_effect_offset:
    mov.w   DAT_06005b8a, r5               ! r5 = 0x0336 (1P effect X position)
.L_effect_layer_common:
    mov.l   _pool_alt_offset_flag, r0     ! r0 -> &alt_offset_flag (sym_0607EAB8)
    mov.l @r0, r0                           ! r0 = alt_offset_flag value
    tst r0, r0                              ! test if alt offset disabled
    bt      .L_use_default_offset           ! if disabled: use default field offset
    mov.w   _wpool_alt_field_offset, r0   ! r0 = 0x00DE (alternate field offset)
    bra     .L_effect_write                 ! continue to effect write
    nop                                     ! delay slot

    .global DAT_06005b7c
DAT_06005b7c:
    .2byte  0x021C
_wpool_x_pos_frame:
    .2byte  0x0108

    .global DAT_06005b80
DAT_06005b80:
    .2byte  0x0220

    .global DAT_06005b82
DAT_06005b82:
    .2byte  0x0320

    .global DAT_06005b84
DAT_06005b84:
    .2byte  0x0224
_wpool_x_pos_z:
    .2byte  0x0142

    .global DAT_06005b88
DAT_06005b88:
    .2byte  0x0236

    .global DAT_06005b8a
DAT_06005b8a:
    .2byte  0x0336
_wpool_alt_field_offset:
    .2byte  0x00DE
    .2byte  0xFFFF
_pool_2p_mode_flag:
    .4byte  sym_06085FF4
_pool_effect_timer_ptr:
    .4byte  sym_0607EAAC
_pool_overlay_counter:
    .4byte  sym_06063E10
_pool_fade_timer:
    .4byte  sym_06063E0C
_pool_dlist_cmd_writer:
    .4byte  sym_06028430
_pool_car_state_ptr:
    .4byte  sym_0607E944
_pool_max_frame_count:
    .4byte  sym_06063F28
_pool_scale_mode_flag:
    .4byte  sym_06078644
_pool_perspective_scale:
    .4byte  0x00009F1A
_pool_extra_layer_flag:
    .4byte  sym_0607EAE0
_pool_alt_offset_flag:
    .4byte  sym_0607EAB8
.L_use_default_offset:
    mov.w   DAT_06005c74, r0               ! r0 = 0x00DC (default field offset)
.L_effect_write:
    mov #0x6C, r6                           ! r6 = 0x6C (display list slot: effect layer)
    mov.w @(r0, r14), r7                    ! r7 = car_state[+offset] (effect value, word)
    add #0x1, r7                            ! r7 = effect_value + 1
    jsr @r13                                ! call dlist_cmd_writer(r4=8, r5, r6=0x6C, r7)
    mov #0x8, r4                            ! (delay) r4 = 0x8 (VDP command mode)
    mov.b @r8, r0                           ! r0 = 2p_mode_flag
    tst r0, r0                              ! test if 1-player mode
    bf      .L_epilogue_rts                 ! if 2P: skip overlay effect, return
    mov.l   _pool_game_state_bitmask, r3   ! r3 -> &game_state_bitmask (sym_0607EBC4)
    mov.l   .L_fp_two, r2                  ! r2 = 0x00020000 (bit 17 mask)
    mov.l @r3, r3                           ! r3 = game_state_bitmask value
    and r2, r3                              ! r3 = bitmask & 0x00020000 (isolate bit 17)
    tst r3, r3                              ! test if effect overlay bit clear
    bt/s    .L_no_effect_overlay            ! if clear: no overlay effect
    mov #0x1, r4                            ! (delay) r4 = 1 (effect active flag init)
    mov.l @r9, r0                           ! r0 = *effect_timer
    cmp/eq #0x78, r0                        ! if effect_timer == 120 (init trigger)
    bf      .L_check_timer_active           ! if not 120: check ongoing timer
    mov #0x3C, r2                           ! r2 = 60 (initial fade timer value)
    mov.l r2, @r12                          ! *fade_timer = 60
    mov.l r10, @r11                         ! *overlay_counter = 8
.L_check_timer_active:
    mov.l @r9, r3                           ! r3 = *effect_timer
    .2byte  0xE278                          ! mov #0x78, r2 (r2 = 120 threshold)
    .4byte  0x33238916                      ! cmp/ge r2,r3 / bt .L_no_effect_overlay
    .4byte  0x62B272FF                      ! mov.l @r11,r2 / add #-1,r2
    .4byte  0x22288F12                      ! tst r2,r2 / bf/s .L_no_effect_overlay
    .4byte  0x2B22D522                      ! mov.l r2,@r11 / mov.l @(0x88,PC),r5 {sound params}
    .4byte  0xD322430B                      ! mov.l @(0x88,PC),r3 {sound_cmd_dispatch} / jsr @r3
    .4byte  0xE40062C2                      ! mov #0,r4 / mov.l @r12,r2
    .4byte  0x72FD2C22                      ! add #-3,r2 / mov.l r2,@r12
    .4byte  0x632333A3                      ! mov r2,r3 / cmp/ge r10,r3
    .4byte  0x89002CA2                      ! bt +0 / mov.l r10,@r12
    .4byte  0x63C24321                      ! mov.l @r12,r3 / shar r3
    .4byte  0x43214321                      ! shar r3 / shar r3
    .4byte  0x73012B32                      ! add #1,r3 / mov.l r3,@r11
    .2byte  0xE400                          ! mov #0, r4 (clear effect flag)
.L_no_effect_overlay:
    tst r4, r4                              ! test effect flag (0 = active, 1 = inactive)
    bt      .L_tail_call_static             ! if zero (active): render static text overlay
    mov.l @r9, r1                           ! r1 = *effect_timer (param for geometry_transform)
    mov.l   _pool_geometry_transform, r3   ! r3 -> &geometry_transform (sym_06034FE0)
    jsr @r3                                 ! call geometry_transform(r0=0x14, r1=timer)
    mov #0x14, r0                           ! (delay) r0 = 0x14 (transform mode)
    mov r0, r7                              ! r7 = transform result (brightness)
    mov.w   DAT_06005c76, r4               ! r4 = 0x03E7 (999 max clamp)
    cmp/gt r4, r7                           ! if (brightness > 999)
    bf      .L_brightness_ok                !   clamp to 999
    mov r4, r7                              ! r7 = 999 (clamped)
.L_brightness_ok:
    mov #0x18, r6                           ! r6 = 0x18 (display list slot: overlay)
    mov.w   _wpool_x_pos_overlay, r5      ! r5 = 0x00A6 (X position for overlay)
    jsr @r13                                ! call dlist_cmd_writer(r4=8, r5=0xA6, r6=0x18, r7)
    mov #0x8, r4                            ! (delay) r4 = 0x8 (VDP command mode)
    bra     .L_epilogue_rts                 ! done, return
    nop                                     ! delay slot
.L_tail_call_static:
    mov.l   _pool_static_text_data, r7    ! r7 -> static_text_data (sym_0605ACF3)
    mov #0x60, r6                           ! r6 = 0x60 (display list slot: static text)
    mov r6, r5                              ! r5 = 0x60
    add #0x46, r5                           ! r5 = 0xA6 (X position for static text)
    mov #0x8, r4                            ! r4 = 0x8 (VDP command mode)
    lds.l @r15+, macl                       ! restore macl
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r8                         ! restore r8
    mov.l @r15+, r9                         ! restore r9
    mov.l @r15+, r10                        ! restore r10
    mov.l @r15+, r11                        ! restore r11
    mov.l @r15+, r12                        ! restore r12
    mov.l @r15+, r13                        ! restore r13
    mov.l   _pool_geom_dispatch_final, r3  ! r3 -> &geom_dispatch_final (sym_060284AE)
    jmp @r3                                 ! tail-call geom_dispatch_final(r4=8, r5=0xA6, r6=0x60, r7=text_data)
    mov.l @r15+, r14                        ! (delay) restore r14
.L_epilogue_rts:
    lds.l @r15+, macl                       ! restore macl
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r8                         ! restore r8
    mov.l @r15+, r9                         ! restore r9
    mov.l @r15+, r10                        ! restore r10
    mov.l @r15+, r11                        ! restore r11
    mov.l @r15+, r12                        ! restore r12
    mov.l @r15+, r13                        ! restore r13
    rts                                     ! return
    mov.l @r15+, r14                        ! (delay) restore r14

    .global DAT_06005c74
DAT_06005c74:
    .2byte  0x00DC

    .global DAT_06005c76
DAT_06005c76:
    .2byte  0x03E7
_wpool_x_pos_overlay:
    .2byte  0x00A6
    .2byte  0xFFFF
_pool_game_state_bitmask:
    .4byte  sym_0607EBC4
.L_fp_two:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */
    .4byte  0xAE1114FF
    .4byte  sound_cmd_dispatch
_pool_geometry_transform:
    .4byte  sym_06034FE0
_pool_static_text_data:
    .4byte  sym_0605ACF3
_pool_geom_dispatch_final:
    .4byte  sym_060284AE
