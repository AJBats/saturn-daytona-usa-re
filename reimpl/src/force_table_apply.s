
    .section .text.FUN_06008418


    .global force_steer_calc
    .type force_steer_calc, @function
force_steer_calc:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_car_state_ptr, r14
    mov.w   DAT_060084a2, r0
    mov.l @r14, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bf      .L_steer_calc_return
    mov.l   .L_race_flags, r3
    mov.l   .L_fp_two, r2
    mov.l @r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_steer_calc_set_flags
    mov.l   .L_snd_cmd_collision, r5
    mov.l   .L_fn_sound_dispatch, r3
    jsr @r3
    mov #0x0, r4
.L_steer_calc_set_flags:
    mov.l @r14, r3
    add #0x1, r3
    mov.b @r3, r0
    and #0xFE, r0
    or #0x1, r0
    mov.b r0, @r3
    mov.l @r14, r2
    mov.w   DAT_060084a4, r3
    mov.w   DAT_060084a6, r0
    mov.l r3, @(r0, r2)
    mov.l   .L_force_config_a, r4
    mov.l @r4, r4
    lds.l @r15+, pr
    bra     race_config_physics
    mov.l @r15+, r14
.L_steer_calc_return:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global force_steer_impact
    .type force_steer_impact, @function
force_steer_impact:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_car_state_ptr, r14
    mov.w   DAT_060084a2, r0
    mov.l @r14, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bf      .L_steer_impact_return
    mov.l   .L_race_flags, r3
    mov.l   .L_fp_two, r2
    mov.l @r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_steer_impact_set_flags
    mov.l   .L_snd_cmd_collision, r5
    mov.l   .L_fn_sound_dispatch, r3
    jsr @r3
    mov #0x0, r4
.L_steer_impact_set_flags:
    mov.l @r14, r3
    add #0x1, r3
    mov.b @r3, r0
    and #0xFE, r0
    or #0x1, r0
    mov.b r0, @r3
    mov.l @r14, r2
    mov.w   DAT_060084a4, r3
    mov.w   DAT_060084a6, r0
    mov.l r3, @(r0, r2)
    mov.l   .L_force_config_b, r4
    mov.l @r4, r4
    lds.l @r15+, pr
    bra     race_config_physics
    mov.l @r15+, r14

    .global DAT_060084a2
DAT_060084a2:
    .2byte  0x01BC                        /* car struct: collision timer offset */

    .global DAT_060084a4
DAT_060084a4:
    .2byte  0x00CC                        /* constant 0xCC (written to flags) */

    .global DAT_060084a6
DAT_060084a6:
    .2byte  0x0214                        /* car struct: flags word offset */
.L_car_state_ptr:
    .4byte  sym_0607E944               /* player car state pointer */
.L_race_flags:
    .4byte  sym_0607EBC4               /* race flags (32-bit) */
.L_fp_two:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */
.L_snd_cmd_collision:
    .4byte  0xAE1102FF                  /* sound command: collision */
.L_fn_sound_dispatch:
    .4byte  sound_cmd_dispatch         /* sound command dispatcher */
.L_force_config_a:
    .4byte  sym_060453B4               /* force config table A */
.L_force_config_b:
    .4byte  sym_060453BC               /* force config table B */
.L_steer_impact_return:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global race_config_physics
    .type race_config_physics, @function
race_config_physics:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_car_state_ptr_b, r14
    mov.w   DAT_0600855e, r0
    mov.l @r14, r3
    mov.l @(r0, r3), r2
    add #0x1, r2
    mov.l r2, @(r0, r3)
    mov #0x0, r2
    add #-0x10, r0
    mov.l @r14, r3
    mov.l r2, @(r0, r3)
    bsr     force_table_apply
    nop
    mov.l @r14, r2
    mov.l   .L_player_car_base, r3
    cmp/eq r3, r2
    bf      .L_config_physics_return
    mov.l   .L_race_flags_b, r3
    mov.l   .L_fp_two_b, r2
    mov.l @r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_config_physics_return
    mov.l   .L_demo_flag, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_end_race_display_setup
    mov.l   .L_special_render_flag, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bf      .L_config_physics_return
.L_end_race_display_setup:
    mov #0x3, r3
    mov.l   .L_display_mode_word, r2
    mov #0x0, r5
    mov.w r3, @r2
    mov #0x7, r3
    mov.l   .L_lap_count, r2
    mov.b r3, @r2
    mov #0x2, r3
    mov.l   .L_camera_mode, r2
    mov.l r3, @r2
    mov #0x1, r3
    mov.l   .L_camera_follow, r2
    mov.l r3, @r2
    mov.l   .L_fn_channel_config, r3
    jsr @r3
    mov #0x8, r4
    mov.l   .L_z_near_start, r2
    mov.l   .L_camera_yaw_ptr, r3
    mov.l r2, @r3
    mov.l   .L_z_near_clip, r2
    mov.l   .L_camera_near_store, r3
    mov.l r2, @r3
    mov.l   .L_z_far_clip, r2
    mov.l   .L_camera_far_store, r3
    mov.l r2, @r3
    mov.l   .L_fp_sixteen, r2
    mov.l   .L_camera_scale_store, r3
    mov.l r2, @r3
    mov #0x0, r2
    mov.l   .L_camera_clear, r3
    mov.l r2, @r3
    mov.l @r14, r2
    mov.w   .L_off_collision_timer_b, r0
    mov.l @(r0, r2), r3
    exts.b r3, r3
    mov.l   .L_course_section_byte, r2
    mov.b r3, @r2
.L_config_physics_return:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global DAT_0600855e
DAT_0600855e:
    .2byte  0x01D4                        /* car struct: collision count offset */
.L_off_collision_timer_b:
    .2byte  0x01BC                        /* car struct: collision timer offset */
    .2byte  0xFFFF
.L_car_state_ptr_b:
    .4byte  sym_0607E944               /* player car state pointer */
.L_player_car_base:
    .4byte  sym_06078900               /* player car array base */
.L_race_flags_b:
    .4byte  sym_0607EBC4               /* race flags (32-bit) */
.L_fp_two_b:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */
.L_demo_flag:
    .4byte  sym_06078635               /* demo mode flag (byte) */
.L_special_render_flag:
    .4byte  sym_0607ED8C               /* special render enable (16-bit) */
.L_display_mode_word:
    .4byte  sym_0605A016               /* display mode (16-bit) */
.L_lap_count:
    .4byte  sym_06078654               /* lap count (byte) */
.L_camera_mode:
    .4byte  sym_06063E1C               /* camera mode (32-bit) */
.L_camera_follow:
    .4byte  sym_06059F30               /* camera follow flag (32-bit) */
.L_fn_channel_config:
    .4byte  channel_nibble_config      /* channel configuration function */
.L_z_near_start:
    .4byte  0x00058000                  /* view z near start (5.5 in 16.16) */
.L_camera_yaw_ptr:
    .4byte  sym_06063E24               /* camera yaw parameter */
.L_z_near_clip:
    .4byte  0x0000F300                  /* near clip distance */
.L_camera_near_store:
    .4byte  sym_06063E34               /* camera near clip store */
.L_z_far_clip:
    .4byte  0x006E0000                  /* far clip distance */
.L_camera_far_store:
    .4byte  sym_06063E28               /* camera far clip store */
.L_fp_sixteen:
    .4byte  0x00100000                  /* 16.0 (16.16 fixed-point) */
.L_camera_scale_store:
    .4byte  sym_06063E2C               /* camera z-scale store */
.L_camera_clear:
    .4byte  sym_06063E30               /* camera clear register */
.L_course_section_byte:
    .4byte  sym_0607866C               /* course section byte */

    .global brake_force_apply
    .type brake_force_apply, @function
brake_force_apply:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_active_car_ptr, r14
    mov.w   DAT_06008624, r0
    mov.l @r14, r3
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_brake_force_return
    mov #0x46, r3
    mov.l   .L_brake_timeout, r2
    mov.l r3, @r2
    mov.l @r14, r0
    mov.w   DAT_06008626, r1
    mov.l @(r0, r1), r0
    cmp/eq #0x1, r0
    bf      .L_brake_call_tick
    mov.l @r14, r2
    mov.w   .L_off_car_flags_160, r0
    mov.b @(r0, r2), r0
    tst #0x80, r0
    bt      .L_brake_call_tick
    mov.l @r14, r3
    mov r3, r2
    mov.l @(48, r2), r1
    mov.l r1, @(40, r3)
    mov.l @r14, r3
    mov r3, r2
    mov.w   DAT_0600862a, r0
    mov.l @(r0, r2), r1
    add #-0x8, r0
    mov.l r1, @(r0, r3)
.L_brake_call_tick:
    bsr     .L_force_tick_handler
    nop
    mov #0x1, r4
    mov.l @r14, r2
    mov.w   DAT_06008624, r0
    mov.l @(r0, r2), r3
    cmp/gt r4, r3
    bt      .L_brake_force_return
    mov.l   .L_lap_count_b, r5
    mov.l   .L_race_flags_c, r2
    mov.l   .L_wram_low, r3
    mov.l @r2, r2
    cmp/eq r3, r2
    bf      .L_brake_set_lap_one
    mov #0x4, r3
    mov.b r3, @r5
    bra     .L_brake_force_return
    nop
.L_brake_set_lap_one:
    extu.b r4, r4
    mov.b r4, @r5
.L_brake_force_return:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global DAT_06008624
DAT_06008624:
    .2byte  0x01BC                        /* car struct: collision timer offset */

    .global DAT_06008626
DAT_06008626:
    .2byte  0x00BC                        /* car struct: timer offset */
.L_off_car_flags_160:
    .2byte  0x0160                        /* car struct: flags at +0x160 */

    .global DAT_0600862a
DAT_0600862a:
    .2byte  0x01EC                        /* car struct: velocity B offset */
.L_active_car_ptr:
    .4byte  sym_0607E940               /* active car state pointer */
.L_brake_timeout:
    .4byte  sym_0607EBD4               /* brake timeout counter (32-bit) */
.L_lap_count_b:
    .4byte  sym_06078654               /* lap count (byte) */
.L_race_flags_c:
    .4byte  sym_0607EBC4               /* race flags (32-bit) */
.L_wram_low:
    .4byte  0x00200000                  /* Work RAM Low base */

    .global sym_06008640
sym_06008640:
    mov.l   .L_active_car_ptr_b, r4
    mov.l @r4, r2
    mov r2, r0
    mov.b @r0, r0
    tst #0x8, r0
    bf      .L_dispatch_clear_bit3
    mov.l @r4, r3
    mov.w   .L_off_collision_timer, r0
    mov.l @(r0, r3), r0
    tst r0, r0
    bt      .L_dispatch_return
    bra     .L_force_tick_handler
    nop
.L_dispatch_clear_bit3:
    mov.l @r4, r3
    mov.b @r3, r0
    and #0xF7, r0
    or #0x0, r0
    mov.b r0, @r3
    mov.l @r4, r2
    mov.w   .L_off_collision_timer, r0
    mov.l @(r0, r2), r0
    tst r0, r0
    bt      .L_dispatch_setup_timer
    bra     .L_force_tick_handler
    nop
.L_dispatch_setup_timer:
    mov #0x14, r3
    mov.w   .L_off_display_timer, r0
    mov.l @r4, r2
    mov.w r3, @(r0, r2)
    mov.l   .L_race_flags_d, r3
    mov.l   .L_race_flag_bit, r2
    mov.l @r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_dispatch_frame_parity
    mov.l   .L_force_config_c, r4
    bra     force_table_apply
    mov.l @r4, r4
.L_dispatch_frame_parity:
    mov.l   .L_frame_counter, r0
    mov.l @r0, r0
    and #0x1, r0
    mov r0, r4
    shll2 r4
    shll r4
    mov.l   .L_force_config_table, r3
    add r3, r4
    bra     force_table_apply
    mov.l @r4, r4
.L_dispatch_return:
    rts
    nop
.L_off_collision_timer:
    .2byte  0x01BC                        /* car struct: collision timer offset */
.L_off_display_timer:
    .2byte  0x00D4                        /* car struct: display timer offset */
.L_active_car_ptr_b:
    .4byte  sym_0607E940               /* active car state pointer */
.L_race_flags_d:
    .4byte  sym_0607EBC4               /* race flags (32-bit) */
.L_race_flag_bit:
    .4byte  0x00800000                  /* race flag bit 23 */
.L_force_config_c:
    .4byte  sym_060453C4               /* force config table C */
.L_frame_counter:
    .4byte  sym_0607EBD0               /* frame counter (32-bit) */
.L_force_config_table:
    .4byte  sym_060453B4               /* force config table base */

    .global force_table_apply
    .type force_table_apply, @function
force_table_apply:
    sts.l pr, @-r15
    mov #0x1, r6
    mov.l   .L_frame_counter_b, r7
    mov.l   .L_active_car_ptr_c, r5
    mov.w   .L_off_force_state, r3
    mov.l @r7, r0
    mov.l @r5, r2
    and r6, r0
    add r3, r2
    mov.l   .L_fn_channel_commit, r3
    jsr @r3
    mov r6, r1
    mov.l @r5, r2
    mov.l @r7, r0
    mov.w   .L_off_force_state, r3
    mov.w   .L_channel_id_b, r1
    shar r0
    add r3, r2
    mov.l   .L_fn_channel_commit, r3
    jsr @r3
    and r6, r0
    mov.l @r5, r2
    mov.l @r4, r3
    mov.w   .L_off_force_ptr, r0
    mov.l r3, @(r0, r2)
    mov.l @(4, r4), r4
    mov.l @r5, r3
    mov.w   DAT_0600871a, r0
    mov.l r4, @(r0, r3)
    add #-0x28, r4
    mov.l @r5, r3
    mov.w   DAT_0600871c, r0
    mov.l r4, @(r0, r3)
    mov.l @r5, r3
    mov.w   .L_off_alt_force_ptr, r0
    mov.l r4, @(r0, r3)
    mov.l   .L_force_apply_count, r4
    mov.b @r4, r3
    add r6, r3
    mov.b r3, @r4
    bra     .L_force_tick_handler
    lds.l @r15+, pr
.L_off_force_state:
    .2byte  0x01C0                        /* car struct: force state offset */
.L_channel_id_b:
    .2byte  0x0101                        /* channel ID 0x0101 */
.L_off_force_ptr:
    .2byte  0x01B8                        /* car struct: force pointer offset */

    .global DAT_0600871a
DAT_0600871a:
    .2byte  0x01BC                        /* car struct: collision timer offset */

    .global DAT_0600871c
DAT_0600871c:
    .2byte  0x00BC                        /* car struct: timer offset */
.L_off_alt_force_ptr:
    .2byte  0x0208                        /* car struct: alt force pointer offset */
.L_frame_counter_b:
    .4byte  sym_0607EBD0               /* frame counter (32-bit) */
.L_active_car_ptr_c:
    .4byte  sym_0607E940               /* active car state pointer */
.L_fn_channel_commit:
    .4byte  sym_06034F78               /* channel data commit */
.L_force_apply_count:
    .4byte  sym_0607EBEC               /* force apply count (byte) */
.L_force_tick_handler:
    mov.l   .L_active_car_ptr_d, r4
    mov.w   DAT_060087e8, r0
    mov.l @r4, r3
    mov.l @(r0, r3), r2
    cmp/pl r2
    bf/s    .L_tick_check_secondary
    mov #0x0, r6
    mov.l @r4, r2
    mov.w   DAT_060087e8, r0
    mov.l @(r0, r2), r3
    add #-0x1, r3
    mov.l r3, @(r0, r2)
.L_tick_check_secondary:
    mov.l @r4, r3
    mov.w   DAT_060087ea, r0
    mov.l @(r0, r3), r2
    cmp/pl r2
    bf      .L_tick_check_display
    mov.l @r4, r2
    mov.w   DAT_060087ea, r0
    mov.l @(r0, r2), r3
    add #-0x1, r3
    mov.l r3, @(r0, r2)
.L_tick_check_display:
    mov.l @r4, r0
    mov.w   DAT_060087ea, r1
    mov.l @(r0, r1), r0
    cmp/eq #0xA, r0
    bf      .L_tick_read_entry
    mov.l @r4, r2
    mov #0xA, r3
    mov.w   DAT_060087ec, r0
    mov.w r3, @(r0, r2)
.L_tick_read_entry:
    mov.l @r4, r5
    mov.w   .L_off_force_ptr_b, r0
    mov.l @(r0, r5), r3
    add #0xC, r3
    mov.l r3, @(r0, r5)
    add #-0xC, r3
    add #-0x4, r0
    mov r3, r5
    mov.l @r4, r3
    mov.l @r5, r2
    mov.l r2, @(r0, r3)
    mov.w @(4, r5), r0
    mov.l @r4, r2
    mov r0, r7
    mov.w   .L_off_direction_flags, r0
    mov.b @(r0, r2), r0
    tst #0x40, r0
    bt      .L_tick_check_bit7
    mov.l @r4, r3
    mov.w @(6, r5), r0
    mov r0, r2
    mov.w   .L_off_force_x, r0
    mov.l r2, @(r0, r3)
    mov.l @r4, r3
    mov.w @(8, r5), r0
    mov r0, r2
    neg r2, r2
    mov.w   DAT_060087f4, r0
    mov.l r2, @(r0, r3)
    mov.l @r4, r3
    mov.w @(10, r5), r0
    mov r0, r2
    neg r2, r2
    mov.w   .L_off_force_z, r0
    mov.l r2, @(r0, r3)
    bra     .L_tick_check_car_id
    nop
.L_tick_check_bit7:
    mov.l @r4, r2
    mov.w   .L_off_direction_flags, r0
    mov.b @(r0, r2), r0
    tst #0x80, r0
    bt      .L_tick_default_vectors
    mov.l @r4, r3
    mov.w @(6, r5), r0
    mov r0, r2
    neg r2, r2
    mov.w   .L_off_force_x, r0
    mov.l r2, @(r0, r3)
    mov.l @r4, r3
    mov.w @(8, r5), r0
    mov r0, r2
    neg r2, r2
    mov.w   DAT_060087f4, r0
    mov.l r2, @(r0, r3)
    mov.l @r4, r3
    mov.w @(10, r5), r0
    mov r0, r2
    mov.w   .L_off_force_z, r0
    mov.l r2, @(r0, r3)
    bra     .L_tick_check_car_id
    nop

    .global DAT_060087e8
DAT_060087e8:
    .2byte  0x01BC                        /* car struct: collision timer */

    .global DAT_060087ea
DAT_060087ea:
    .2byte  0x00BC                        /* car struct: timer */

    .global DAT_060087ec
DAT_060087ec:
    .2byte  0x00D4                        /* car struct: display timer */
.L_off_force_ptr_b:
    .2byte  0x01B8                        /* car struct: force pointer */
.L_off_direction_flags:
    .2byte  0x01C0                        /* car struct: direction flags */
.L_off_force_x:
    .2byte  0x01C8                        /* car struct: force X vector */

    .global DAT_060087f4
DAT_060087f4:
    .2byte  0x01CC                        /* car struct: force Y vector */
.L_off_force_z:
    .2byte  0x01D0                        /* car struct: force Z vector */
.L_active_car_ptr_d:
    .4byte  sym_0607E940               /* active car state pointer */
.L_tick_default_vectors:
    mov.l @r4, r2
    mov.w @(6, r5), r0
    mov r0, r3
    mov.w   .L_off_force_x_b, r0
    mov.l r3, @(r0, r2)
    mov.l @r4, r3
    mov.w @(8, r5), r0
    mov r0, r2
    mov.w   DAT_060088ac, r0
    mov.l r2, @(r0, r3)
    mov.l @r4, r3
    mov.w @(10, r5), r0
    mov r0, r2
    mov.w   .L_off_force_z_b, r0
    mov.l r2, @(r0, r3)
.L_tick_check_car_id:
    mov.l @r4, r3
    mov.l   .L_force_direction_byte, r2
    mov.l @(4, r3), r3
    mov.b @r2, r2
    extu.b r2, r2
    cmp/eq r2, r3
    bf      .L_tick_check_cleanup
    exts.w r7, r7
    mov.l @r4, r3
    mov.w   DAT_060088b0, r0
    mov.l @(r0, r3), r2
    add #0x1, r2
    mov.l r2, @(r0, r3)
    mov.w   DAT_060088b2, r3
    cmp/gt r3, r7
    bf      .L_tick_check_expired
    mov.l @r4, r3
    mov.w   DAT_060088b0, r0
    mov.l @(r0, r3), r2
    mov #0x50, r3
    cmp/ge r3, r2
    bf      .L_tick_check_counter_40
    bra     .L_tick_clear_counter
    nop
.L_tick_check_counter_40:
    mov.l @r4, r2
    mov.w   DAT_060088b0, r0
    mov.l @(r0, r2), r3
    mov #0x28, r2
    cmp/ge r2, r3
.L_tick_clear_counter:
    mov.l @r4, r2
    mov.w   DAT_060088b0, r0
    mov.l r6, @(r0, r2)
.L_tick_check_expired:
    mov.l @r4, r3
    mov.w   DAT_060088b4, r0
    mov.l @(r0, r3), r0
    tst r0, r0
    bf      .L_tick_check_cleanup
    exts.b r6, r3
    mov.l   .L_course_section, r2
    mov.b r3, @r2
    mov.l   .L_demo_flag_b, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_tick_set_display_4
    mov.l   .L_special_render_flag_b, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bf      .L_tick_check_cleanup
.L_tick_set_display_4:
    mov #0x4, r3
    mov.l   .L_display_mode_word_b, r2
    mov.w r3, @r2
.L_tick_check_cleanup:
    mov.l @r4, r3
    mov.w   DAT_060088b4, r0
    mov.l @(r0, r3), r0
    tst r0, r0
    bf      .L_tick_return
    mov.l @r4, r3
    mov.w   DAT_060088b6, r0
    mov.l r6, @(r0, r3)
    mov.l @r4, r3
    add #0x14, r0
    mov.l r6, @(r0, r3)
    mov.l @r4, r3
    add #0x4, r0
    mov.l r6, @(r0, r3)
    mov.l @r4, r3
    add #0x4, r0
    mov.l r6, @(r0, r3)
.L_tick_return:
    rts
    nop
.L_off_force_x_b:
    .2byte  0x01C8                        /* car struct: force X vector */

    .global DAT_060088ac
DAT_060088ac:
    .2byte  0x01CC                        /* car struct: force Y vector */
.L_off_force_z_b:
    .2byte  0x01D0                        /* car struct: force Z vector */

    .global DAT_060088b0
DAT_060088b0:
    .2byte  0x01C4                        /* car struct: force counter */

    .global DAT_060088b2
DAT_060088b2:
    .2byte  0x0100                        /* force threshold (256) */

    .global DAT_060088b4
DAT_060088b4:
    .2byte  0x01BC                        /* car struct: collision timer */

    .global DAT_060088b6
DAT_060088b6:
    .2byte  0x01B4                        /* car struct: force data pointer */
.L_force_direction_byte:
    .4byte  sym_0607EBBC               /* force direction byte */
.L_course_section:
    .4byte  sym_0607866C               /* course section byte */
.L_demo_flag_b:
    .4byte  sym_06078635               /* demo mode flag (byte) */
.L_special_render_flag_b:
    .4byte  sym_0607ED8C               /* special render enable (16-bit) */
.L_display_mode_word_b:
    .4byte  sym_0605A016               /* display mode (16-bit) */
