
    .section .text.FUN_06018320


    .global vdp2_scroll_config
    .type vdp2_scroll_config, @function
vdp2_scroll_config:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_force_complete_flag, r9
    mov.l   .L_car_struct_ptr, r10
    mov.l   .L_fp_half, r11
    mov.l   .L_anim_phase_ptr, r13
    mov.l   .L_scroll_pos_ptr, r14
    mov.l   .L_scroll_shadow_ptr, r6
    mov.l   .L_scroll_active_flag, r4
    mov.b @r4, r3
    mov.b r3, @r6
    mov.l @r10, r5
    mov.w   DAT_060183ec, r0
    mov.w   DAT_060183ee, r3
    mov.l @(r0, r5), r5
    cmp/ge r3, r5
    bf/s    .L_clear_all_state
    mov #0x0, r12
    mov.w   DAT_060183f0, r3
    cmp/gt r3, r5
    bf      .L_begin_scroll_setup
.L_clear_all_state:
    mov.l r12, @r14
    mov.l r12, @(4, r14)
    mov.b r12, @r4
    mov.b r12, @r9
    bra     .L_early_exit
    mov.b r12, @r13
.L_begin_scroll_setup:
    mov #0x1, r7
    extu.b r7, r2
    mov.b r2, @r4
    mov.l   .L_vdp2_scroll_reg_src, r0
    mov.l   .L_scroll_config_reg, r3
    mov.w @r0, r0
    mov.w @r3, r3
    extu.w r0, r0
    extu.w r3, r3
    and #0x40, r0
    extu.w r0, r8
    xor r8, r3
    and r8, r3
    extu.w r3, r5
    mov.l   .L_scroll_config_reg, r3
    mov.w r8, @r3
    mov.l   .L_direction_flag_ptr, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_check_direction_change
    extu.b r7, r7
    bra     .L_check_boost_mode
    mov.b r7, @r9
.L_check_direction_change:
    mov.b @r4, r2
    mov.b @r6, r3
    mov.l @r10, r1
    extu.b r2, r2
    extu.b r3, r3
    mov r1, r0
    xor r3, r2
    mov.b @(3, r0), r0
    tst #0x8, r0
    .word 0x0329
    add #-0x1, r3
    neg r3, r3
    tst r3, r3
    .word 0x0029
    and r0, r2
    tst r2, r2
    bt      .L_check_boost_mode
    mov.l   .L_frame_counter_ptr, r0
    mov.l @r0, r0
    tst #0x3F, r0
    bf      .L_check_boost_mode
    extu.b r7, r7
    mov.b r7, @r9
.L_check_boost_mode:
    mov.l   .L_fp_one, r4
    mov.l   .L_boost_mode_flag, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bf      .L_boost_path_entry
    mov.l @r10, r3
    mov.l @(8, r3), r0
    tst r0, r0
    bt      .L_normal_check_active
    bra     .L_apply_transforms
    nop
.L_normal_check_active:
    extu.w r5, r5
    tst r5, r5
    bf      .L_normal_begin_anim
    bra     .L_apply_transforms
    nop
.L_normal_begin_anim:
    mov.w   DAT_060183f2, r5
    mov.b @r13, r0
    bra     .L_normal_phase_dispatch
    extu.b r0, r0

    .global DAT_060183ec
DAT_060183ec:
    .2byte  0x01EC                      /* car struct game state field offset */

    .global DAT_060183ee
DAT_060183ee:
    .2byte  0x0086                      /* minimum valid game state */

    .global DAT_060183f0
DAT_060183f0:
    .2byte  0x009F                      /* maximum valid game state */

    .global DAT_060183f2
DAT_060183f2:
    .2byte  0x1000                      /* normal animation fraction step */
.L_force_complete_flag:
    .4byte  sym_0605BE35                /* force-complete flag (byte) */
.L_car_struct_ptr:
    .4byte  sym_0607E940                /* current car struct pointer */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_anim_phase_ptr:
    .4byte  sym_0605BE32                /* animation phase counter (byte) */
.L_scroll_pos_ptr:
    .4byte  sym_06085FC0                /* scroll position struct (int+frac) */
.L_scroll_shadow_ptr:
    .4byte  sym_0605BE34                /* previous scroll_active shadow (byte) */
.L_scroll_active_flag:
    .4byte  sym_0605BE33                /* scroll active flag (byte) */
.L_vdp2_scroll_reg_src:
    .4byte  g_pad_state                /* VDP2 scroll direction source register */
.L_scroll_config_reg:
    .4byte  sym_0605BE30                /* scroll config register (16-bit) */
.L_direction_flag_ptr:
    .4byte  sym_0605DE3C                /* transition state flag (byte) */
.L_frame_counter_ptr:
    .4byte  sym_0605A010                /* global frame counter (32-bit) */
.L_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_boost_mode_flag:
    .4byte  sym_06085FF4                /* boost/extended mode flag (byte) */
.L_normal_phase_0:
    mov.l r12, @r14
    mov.l @(4, r14), r2
    add r5, r2
    mov r2, r3
    mov.l r2, @(4, r14)
    cmp/ge r4, r3
    bf      .L_normal_anim_done
    mov.l r11, @r14
    mov.l r11, @(4, r14)
    mov.b @r13, r3
    add #0x1, r3
    mov.b r3, @r13
    bra     .L_normal_anim_done
    nop
.L_normal_phase_1:
    mov.l r11, @r14
    mov.l @(4, r14), r2
    add r5, r2
    mov r2, r3
    mov.l r2, @(4, r14)
    mov.l   .L_fp_one_point_five, r2
    cmp/ge r2, r3
    bf      .L_normal_anim_done
    mov.l r12, @r14
    mov.l r12, @(4, r14)
    mov.b @r13, r2
    add #0x1, r2
    bra     .L_normal_anim_done
    mov.b r2, @r13
.L_normal_phase_default:
    mov.l r12, @r14
    bra     .L_normal_anim_done
    mov.l r12, @(4, r14)
.L_normal_phase_dispatch:
    cmp/eq #0x0, r0
    bt      .L_normal_phase_0
    cmp/eq #0x1, r0
    bt      .L_normal_phase_1
    bra     .L_normal_phase_default
    nop
.L_normal_anim_done:
    bra     .L_apply_transforms
    nop
.L_boost_path_entry:
    mov.w   .L_fast_int_step, r7
    mov.w   .L_fast_frac_step, r6
    mov.b @r13, r0
    bra     .L_boost_phase_dispatch
    extu.b r0, r0
.L_boost_phase_0:
    mov.l r12, @r14
    mov.l r12, @(4, r14)
    mov.l @r10, r2
    mov.l @(8, r2), r0
    tst r0, r0
    bf      .L_apply_transforms
    extu.w r5, r5
    tst r5, r5
    bt      .L_apply_transforms
    mov.b @r13, r3
    add #0x1, r3
    mov.b r3, @r13
    bra     .L_apply_transforms
    nop
.L_boost_phase_1:
    mov.l @(4, r14), r2
    add r6, r2
    mov.l r2, @(4, r14)
    mov r2, r3
    cmp/ge r4, r3
    bf      .L_apply_transforms
    mov.l r4, @(4, r14)
    mov.b @r13, r3
    add #0x1, r3
    mov.b r3, @r13
    bra     .L_apply_transforms
    nop
.L_boost_phase_2:
    mov.l @r14, r2
    add r7, r2
    mov.l r2, @r14
    mov r2, r3
    cmp/ge r11, r3
    bf      .L_apply_transforms
    mov.l r11, @r14
    mov.b @r13, r3
    add #0x1, r3
    mov.b r3, @r13
    bra     .L_apply_transforms
    nop
.L_boost_phase_3:
    mov.l @(4, r14), r2
    add r6, r2
    mov.l r2, @(4, r14)
    mov r2, r3
    mov.l   .L_fp_two, r4
    cmp/ge r4, r3
    bf      .L_apply_transforms
    mov.l r4, @(4, r14)
    mov.b @r13, r3
    add #0x1, r3
    mov.b r3, @r13
    bra     .L_apply_transforms
    nop
.L_boost_phase_4:
    mov.l @r14, r2
    add r7, r2
    mov r2, r3
    mov.l r2, @r14
    cmp/ge r4, r3
    bf      .L_apply_transforms
    mov.l r12, @r14
    mov.b @r13, r3
    add #0x1, r3
    mov.b r3, @r13
    bra     .L_apply_transforms
    nop
.L_boost_phase_default:
    mov.l r12, @r14
    bra     .L_apply_transforms
    mov.l r12, @(4, r14)
.L_fast_int_step:
    .2byte  0x0200                      /* boost mode integer step per frame */
.L_fast_frac_step:
    .2byte  0x0100                      /* boost mode fraction step per frame */
.L_fp_one_point_five:
    .4byte  0x00018000                  /* 1.5 (16.16 fixed-point) */
.L_fp_two:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */
.L_boost_phase_dispatch:
    cmp/eq #0x0, r0
    bt      .L_boost_phase_0
    cmp/eq #0x1, r0
    bt      .L_boost_phase_1
    cmp/eq #0x2, r0
    bt      .L_boost_phase_2
    cmp/eq #0x3, r0
    bt      .L_boost_phase_3
    cmp/eq #0x4, r0
    bt      .L_boost_phase_4
    bra     .L_boost_phase_default
    nop
.L_apply_transforms:
    mov.b @r9, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_begin_transform_chain
    mov.l r11, @r14
    mov.l r11, @(4, r14)
.L_begin_transform_chain:
    mov.l   .L_fn_pre_transform_setup, r3
    jsr @r3
    nop
    mov.l   .L_camera_pos_params, r8
    mov.l   .L_fn_transform_dispatch, r3
    mov.l @(8, r8), r6
    mov.l @(4, r8), r5
    jsr @r3
    mov.l @r8, r4
    mov.l @(4, r14), r4
    mov.w   DAT_060185a0, r2
    mov.l   .L_fn_mat_rot_y, r3
    jsr @r3
    add r2, r4
    mov.l   .L_fn_mat_rot_x, r3
    jsr @r3
    mov.l @r14, r4
    mov.w   .L_rotation_angle, r5
    mov.l   .L_wram_low, r2
    mov.l   .L_wram_obj_offset, r3
    mov r2, r4
    add r3, r4
    mov.l   .L_fn_transform_chain_a, r3
    jsr @r3
    mov.l r2, @r15
    mov.w   .L_display_scale, r6
    mov.l   .L_scale_factor_table, r5
    mov.l @r15, r4
    mov.l   .L_wram_display_offset, r2
    mov.l   .L_fn_transform_chain_b, r3
    mov.w @r5, r5
    jsr @r3
    add r2, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_fn_post_transform, r3
    jmp @r3
    mov.l @r15+, r14
.L_early_exit:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_060185a0
DAT_060185a0:
    .2byte  0x38E3                      /* Y rotation bias (added to fraction) */
.L_rotation_angle:
    .2byte  0x0178                      /* rotation angle parameter (376 deg units) */
.L_display_scale:
    .2byte  0x0145                      /* display scale parameter (325) */
    .2byte  0xFFFF                      /* padding / alignment */
.L_fn_pre_transform_setup:
    .4byte  sym_06026DBC                /* pre-transform setup function */
.L_camera_pos_params:
    .4byte  sym_06048140                /* camera position parameters (X/Y/Z) */
.L_fn_transform_dispatch:
    .4byte  sym_06026E2E                /* transform dispatch function */
.L_fn_mat_rot_y:
    .4byte  mat_rot_y                   /* Y-axis rotation matrix builder */
.L_fn_mat_rot_x:
    .4byte  mat_rot_x            /* matrix transform function */
.L_wram_low:
    .4byte  0x00200000                  /* Work RAM Low base */
.L_wram_obj_offset:
    .4byte  0x000BABE0                  /* object data offset in WRAM Low */
.L_fn_transform_chain_a:
    .4byte  sym_06031D8C                /* transform chain A dispatch */
.L_scale_factor_table:
    .4byte  sym_06089E98                /* per-mode scale factor table (16-bit) */
.L_wram_display_offset:
    .4byte  0x000BBD80                  /* display data offset in WRAM Low */
.L_fn_transform_chain_b:
    .4byte  sym_06031A28                /* transform chain B dispatch */
.L_fn_post_transform:
    .4byte  sym_06026DF8                /* post-transform cleanup function */
