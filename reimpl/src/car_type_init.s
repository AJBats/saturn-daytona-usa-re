
    .section .text.FUN_0600E1D4


    .global car_type_init
    .type car_type_init, @function
car_type_init:
    mov.l r14, @-r15
    mov #0x0, r3
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_p_player_mode_ptr, r11
    mov.l   .L_p_car_ptr_active, r14
    mov.l   .L_p_course_data_base, r13
    mov.w   DAT_0600e2ba, r0
    mov.l @r14, r14
    mov.l r3, @(r0, r14)
    mov.l @(4, r14), r12
    mov.l   .L_p_config_table_primary, r2
    mov r12, r3
    shll2 r12
    shll2 r3
    shll r3
    add r3, r12
    add r2, r12
    mov.w @(6, r12), r0
    mov r0, r4
    extu.w r4, r4
    mov.w   .L_w_off_car_type, r0
    mov.l r4, @(r0, r14)
    add #-0x8, r0
    mov.l r4, @(r0, r14)
    mov.l @r11, r1
    shll r1
    mov.l   .L_p_heading_offset_table, r3
    mov.l   .L_p_car_count_ptr, r0
    mov.l   .L_p_mem_store_helper, r2
    add r3, r1
    mov.w @r1, r1
    extu.w r1, r1
    add r4, r1
    jsr @r2
    mov.l @r0, r0
    mov.w   DAT_0600e2be, r1
    add r14, r1
    mov.l r0, @r1
    mov.w @(4, r12), r0
    mov r0, r3
    extu.w r3, r3
    shll2 r3
    mov.l   .L_p_config_table_tertiary, r2
    add r2, r3
    mov.l @r3, r1
    mov.w   DAT_0600e2c0, r0
    mov.l r1, @(r0, r14)
    mov.w @(8, r12), r0
    mov r0, r3
    extu.w r3, r3
    mov.w   DAT_0600e2c2, r0
    mov.l r3, @(r0, r14)
    mov.l @r11, r0
    exts.b r0, r0
    mov r0, r3
    shll2 r0
    add r3, r0
    exts.b r0, r0
    mov.l   .L_p_lane_data_secondary, r2
    add r2, r0
    mov.l   .L_p_race_state_ptr, r3
    mov.l @r3, r3
    mov.b @(r0, r3), r10
    extu.b r10, r10
    mov.l   .L_p_render_state_ptr, r3
    mov.l @r3, r3
    mov.l   .L_p_debug_flag, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt/s    .L_use_normal_lane
    add r3, r10
    mov.l @r11, r10
    mov.l   .L_p_lane_data_debug, r3
    add r3, r10
    mov.b @r10, r10
    extu.b r10, r10
.L_use_normal_lane:
    mov.l @r12, r5
    mov r10, r4
    mov.l   .L_p_param_table, r3
    mov.l   .L_p_fpmul, r2
    shll2 r4
    add r3, r4
    jsr @r2
    mov.l @r4, r4
    mov.w   DAT_0600e2c4, r1
    add r14, r1
    mov.l r0, @r1
    mov.w   .L_w_fpmul_scale, r5
    mov.w   DAT_0600e2c4, r0
    mov.l   .L_p_fpmul, r3
    jsr @r3
    mov.l @(r0, r14), r4
    mov.w   DAT_0600e2c8, r1
    mov #0x0, r2
    add r14, r1
    mov.l r0, @r1
    mov.l   .L_p_car_count_ptr, r3
    mov.w   DAT_0600e2be, r0
    mov.l @r3, r3
    mov.l @(r0, r14), r1
    cmp/gt r3, r2
    addc r2, r3
    shar r3
    cmp/ge r3, r1
    bt      .L_set_top_half
    mov #0x0, r2
    mov.w   DAT_0600e2ca, r0
    bra     .L_after_track_progress
    mov.l r2, @(r0, r14)

    .global DAT_0600e2ba
DAT_0600e2ba:
    .2byte  0x0244
.L_w_off_car_type:
    .2byte  0x01F0

    .global DAT_0600e2be
DAT_0600e2be:
    .2byte  0x01EC

    .global DAT_0600e2c0
DAT_0600e2c0:
    .2byte  0x01E0

    .global DAT_0600e2c2
DAT_0600e2c2:
    .2byte  0x0210

    .global DAT_0600e2c4
DAT_0600e2c4:
    .2byte  0x0194
.L_w_fpmul_scale:
    .2byte  0x372F

    .global DAT_0600e2c8
DAT_0600e2c8:
    .2byte  0x0198

    .global DAT_0600e2ca
DAT_0600e2ca:
    .2byte  0x0228
.L_p_player_mode_ptr:
    .4byte  sym_0607EAD8
.L_p_car_ptr_active:
    .4byte  sym_0607E940
.L_p_course_data_base:
    .4byte  sym_06078680
.L_p_config_table_primary:
    .4byte  sym_06047DE4
.L_p_heading_offset_table:
    .4byte  sym_0605A220
.L_p_car_count_ptr:
    .4byte  sym_0607EA9C
.L_p_mem_store_helper:
    .4byte  sym_06035C2C
.L_p_config_table_tertiary:
    .4byte  sym_06085FD0
.L_p_lane_data_secondary:
    .4byte  sym_06047DD0
.L_p_race_state_ptr:
    .4byte  sym_0605AD04
.L_p_render_state_ptr:
    .4byte  sym_0605AD00
.L_p_debug_flag:
    .4byte  sym_06086030
.L_p_lane_data_debug:
    .4byte  sym_06047DDF
.L_p_param_table:
    .4byte  sym_06047D8C
.L_p_fpmul:
    .4byte  fpmul
.L_set_top_half:
    mov #-0x1, r3
    mov.w   DAT_0600e3e8, r0
    mov.l r3, @(r0, r14)
.L_after_track_progress:
    mov.w   DAT_0600e3ea, r0
    mov.l @(r0, r14), r2
    add #-0x8, r0
    mov.l r2, @(r0, r14)
    mov.l @(4, r14), r0
    and #0x1, r0
    mov r0, r4
    mov.l @r11, r0
    tst r0, r0
    bt      .L_single_player_path
    tst r4, r4
    bt      .L_versus_even_car
    mov.w   DAT_0600e3ec, r3
    mov r3, r0
    add #0x7C, r0
    mov.l r3, @(r0, r14)
    bra     .L_clear_speed_fields
    nop
.L_versus_even_car:
    mov.w   .L_w_steer_init_wide, r3
    mov.w   DAT_0600e3f0, r0
    mov.l r3, @(r0, r14)
.L_clear_speed_fields:
    mov #0x0, r2
    mov.w   DAT_0600e3f2, r0
    mov.l r2, @(r0, r14)
    mov r2, r3
    add #-0x4, r0
    bra     .L_apply_heading
    mov.l r2, @(r0, r14)
.L_single_player_path:
    tst r4, r4
    bt      .L_single_player_car
    mov.w   .L_w_steer_init_wide, r3
    mov.w   DAT_0600e3f0, r0
    mov.l r3, @(r0, r14)
    mov.l   .L_p_speed_init_ai, r3
    mov.l r3, @(12, r14)
    bra     .L_apply_heading
    nop
.L_single_player_car:
    mov.w   DAT_0600e3ec, r2
    mov r2, r0
    add #0x7C, r0
    mov.l r2, @(r0, r14)
    mov.l   .L_p_speed_init_player, r3
    mov.l r3, @(12, r14)
    mov.w   DAT_0600e3f4, r2
    mov.w   DAT_0600e3f2, r0
    mov.l r2, @(r0, r14)
    mov r2, r3
    add #-0x4, r0
    mov.l r2, @(r0, r14)
.L_apply_heading:
    mov.w   DAT_0600e3f0, r0
    mov.l @(r0, r14), r3
    add #-0x4, r0
    mov.l r3, @(r0, r14)
    mov.l   .L_p_heading_smooth, r3
    jsr @r3
    mov r13, r4
    mov.l @r13, r2
    mov.l r2, @(16, r14)
    mov.l @(8, r13), r3
    mov.l r3, @(24, r14)
    mov.l @(4, r14), r0
    tst r0, r0
    bf      .L_position_setup
    mov.l @r11, r0
    cmp/eq #0x2, r0
    bf      .L_position_setup
    mov.w   DAT_0600e3f6, r2
    mov r2, r0
    mov.w r0, @(14, r13)
.L_position_setup:
    mov r15, r6
    mov r14, r5
    mov.l r6, @-r15
    add #0x10, r5
    mov.l r5, @-r15
    mov.l @(24, r14), r5
    mov.l   .L_p_elevation_query, r3
    jsr @r3
    mov.l @(16, r14), r4
    mov r0, r4
    mov.l @r15+, r5
    mov.l   .L_p_render_update, r3
    jsr @r3
    mov.l @r15+, r6
    mov.w @(12, r13), r0
    mov r0, r2
    mov.l r0, @(28, r14)
    mov.w @(14, r13), r0
    mov r0, r3
    mov.l r0, @(32, r14)
    mov.w @(16, r13), r0
    mov r0, r3
    mov.l r0, @(36, r14)
    mov.l @(32, r14), r3
    mov.l r3, @(48, r14)
    mov.l @(32, r14), r2
    mov.l r2, @(52, r14)
    mov.l @(32, r14), r3
    mov.l r3, @(40, r14)
    mov.l @(32, r14), r2
    mov.w   .L_w_off_heading_copy, r0
    mov.l r2, @(r0, r14)
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0600e3e8
DAT_0600e3e8:
    .2byte  0x0228

    .global DAT_0600e3ea
DAT_0600e3ea:
    .2byte  0x01EC

    .global DAT_0600e3ec
DAT_0600e3ec:
    .2byte  0x0180
.L_w_steer_init_wide:
    .2byte  0x0580

    .global DAT_0600e3f0
DAT_0600e3f0:
    .2byte  0x01FC

    .global DAT_0600e3f2
DAT_0600e3f2:
    .2byte  0x00E4

    .global DAT_0600e3f4
DAT_0600e3f4:
    .2byte  0x1A90

    .global DAT_0600e3f6
DAT_0600e3f6:
    .2byte  0x1EC0
.L_w_off_heading_copy:
    .2byte  0x01B0
    .2byte  0xFFFF
.L_p_speed_init_ai:
    .4byte  0x00042E38
.L_p_speed_init_player:
    .4byte  0x00042000
.L_p_heading_smooth:
    .4byte  heading_smooth_gentle
.L_p_elevation_query:
    .4byte  sym_06006838
.L_p_render_update:
    .4byte  scene_render_alt
