
    .section .text.FUN_0603D9EC


    .global scene_invalidate_a
    .type scene_invalidate_a, @function
scene_invalidate_a:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   .L_fp_min, r3
    and r14, r3
    tst r3, r3
    bt/s    .L_sign_handled
    mov #0x0, r12
    mov #0x1, r12
    neg r14, r14
.L_sign_handled:
    mov.l   .L_fp_360, r0
    mov.l   .L_fn_fixed_mod, r3
    jsr @r3
    mov r14, r1
    mov r0, r14
    mov.l   .L_fn_sine_core, r13
    mov.l   .L_fp_270, r2
    cmp/ge r2, r14
    bf      .L_check_q3
    mov.l   .L_fp_360, r4
    jsr @r13
    sub r14, r4
    bra     .L_apply_sign
    neg r0, r4
.L_check_q3:
    mov.l   .L_fp_180, r2
    cmp/ge r2, r14
    bf      .L_check_q2
    mov.l   .L_fp_neg180, r4
    jsr @r13
    add r14, r4
    bra     .L_apply_sign
    neg r0, r4
.L_check_q2:
    mov.l   .L_fp_90, r2
    cmp/ge r2, r14
    bf      .L_q1_direct
    mov.l   .L_fp_180, r4
    bra     .L_call_sine_core
    sub r14, r4
.L_q1_direct:
    mov r14, r4
.L_call_sine_core:
    jsr @r13
    nop
    mov r0, r4
.L_apply_sign:
    mov.l   .L_mask_low16, r2
    cmp/eq r2, r4
    bf      .L_check_negate
    mov.l   .L_fp_one, r4
.L_check_negate:
    extu.w r12, r12
    tst r12, r12
    bt      .L_return_result
    neg r4, r4
.L_return_result:
    mov r4, r0
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_fp_min:
    .4byte  0x80000000                  /* min negative / sign bit */
.L_fp_360:
    .4byte  0x01680000                  /* 360.0 (16.16 fixed-point) */
.L_fn_fixed_mod:
    .4byte  sym_06036BE4                /* ! fixed-point modulo */
.L_fn_sine_core:
    .4byte  sym_060424A2                /* ! core sine computation */
.L_fp_270:
    .4byte  0x010E0000                  /* 270.0 (16.16 fixed-point) */
.L_fp_180:
    .4byte  0x00B40000                  /* 180.0 (16.16 fixed-point) */
.L_fp_neg180:
    .4byte  0xFF4C0000                  /* -180.0 (16.16 fixed-point) */
.L_fp_90:
    .4byte  0x005A0000                  /* 90.0 (16.16 fixed-point) */
.L_mask_low16:
    .4byte  0x0000FFFF                  /* low 16-bit mask */
.L_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */

    .global scene_invalidate_b
    .type scene_invalidate_b, @function
scene_invalidate_b:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    mov.l r12, @-r15
    sts.l pr, @-r15
    mov.l   .L_fp_min_0603DB00, r3
    and r14, r3
    tst r3, r3
    bt      .L_sign_done_b
    neg r14, r14
.L_sign_done_b:
    mov.l   .L_fp_360_b, r0
    mov.l   .L_fn_fixed_mod_b, r3
    jsr @r3
    mov r14, r1
    mov r0, r14
    tst r14, r14
    bf      .L_nonzero_angle
    mov.l   .L_fp_one_0603DB0C, r0
    bra     .L_return_cos
    nop
.L_nonzero_angle:
    mov.l   .L_fn_cosine_core, r13
    mov.l   .L_fp_270_b, r3
    cmp/ge r3, r14
    bf      .L_check_q3_b
    mov.l   .L_fp_360_b, r4
    jsr @r13
    sub r14, r4
    bra     .L_store_cos
    mov r0, r4
.L_check_q3_b:
    mov.l   .L_fp_180_b, r12
    cmp/gt r12, r14
    bf      .L_check_eq_180
    mov.l   .L_fp_neg180_b, r4
    jsr @r13
    add r14, r4
    bra     .L_store_cos
    neg r0, r4
.L_check_eq_180:
    cmp/eq r12, r14
    bf      .L_check_q2_b
    mov.l   .L_fp_neg_one, r4
    bra     .L_store_cos
    nop
.L_check_q2_b:
    mov.l   .L_fp_90_b, r2
    cmp/ge r2, r14
    bf      .L_q1_cos_direct
    mov r12, r4
    jsr @r13
    sub r14, r4
    bra     .L_store_cos
    neg r0, r4
.L_q1_cos_direct:
    jsr @r13
    mov r14, r4
    mov r0, r4
.L_store_cos:
    mov r4, r0
.L_return_cos:
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_fp_min_0603DB00:
    .4byte  0x80000000                  /* min negative / sign bit */
.L_fp_360_b:
    .4byte  0x01680000                  /* 360.0 (16.16 fixed-point) */
.L_fn_fixed_mod_b:
    .4byte  sym_06036BE4                /* ! fixed-point modulo */
.L_fp_one_0603DB0C:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_fn_cosine_core:
    .4byte  sym_0604249C                /* ! core cosine computation */
.L_fp_270_b:
    .4byte  0x010E0000                  /* 270.0 (16.16 fixed-point) */
.L_fp_180_b:
    .4byte  0x00B40000                  /* 180.0 (16.16 fixed-point) */
.L_fp_neg180_b:
    .4byte  0xFF4C0000                  /* -180.0 (16.16 fixed-point) */
.L_fp_neg_one:
    .4byte  0xFFFF0000                  /* -1.0 (16.16 fixed-point) */
.L_fp_90_b:
    .4byte  0x005A0000                  /* 90.0 (16.16 fixed-point) */

    .global controller_config
    .type controller_config, @function
controller_config:
    mov.l r14, @-r15
    mov r5, r0
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   .L_ctrl_config_state, r10
    mov.l r4, @r15
    mov.w r0, @(4, r15)
    mov r6, r0
    cmp/eq #0x1, r0
    bt/s    .L_cfg_type_valid
    mov #0x0, r13
    tst r6, r6
    bt      .L_cfg_type_valid
    mov.w   .L_ctrl_type_analog, r3
    cmp/eq r3, r6
    bf      .L_cfg_invalid_combo
    mov r7, r0
    cmp/eq #0x1, r0
    bt      .L_cfg_type_valid
.L_cfg_invalid_combo:
    bra     .L_cfg_return
    mov #0x2, r0
.L_cfg_type_valid:
    mov r7, r0
    cmp/eq #0x1, r0
    bt      .L_cfg_mode_valid
    mov r7, r0
    cmp/eq #0x2, r0
    bt      .L_cfg_mode_valid
    tst r7, r7
    bt      .L_cfg_mode_valid
    bra     .L_cfg_return
    mov #0x2, r0
.L_cfg_mode_valid:
    extu.b r6, r3
    mov.l   .L_ctrl_type_port_a, r2
    extu.b r7, r1
    mov r6, r0
    mov.b r3, @r2
    mov.l   .L_ctrl_type_port_b, r2
    cmp/eq #0x1, r0
    bf/s    .L_cfg_check_single
    mov.b r1, @r2
    mov r7, r0
    cmp/eq #0x1, r0
    bf      .L_cfg_check_single
    mov #0x2, r2
    bra     .L_cfg_write_state
    mov.w r2, @r10
.L_cfg_check_single:
    tst r6, r6
    bf      .L_cfg_default_state
    mov r7, r0
    cmp/eq #0x1, r0
    bf      .L_cfg_default_state
    bra     .L_cfg_single_mode
    mov #0x1, r2
.L_ctrl_type_analog:
    .2byte  0x0100                      /* analog pad type ID */
.L_ctrl_config_state:
    .4byte  sym_060A4C80                /* ! controller config state */
.L_ctrl_type_port_a:
    .4byte  sym_060A4C58                /* ! port A controller type byte */
.L_ctrl_type_port_b:
    .4byte  sym_060A4C59                /* ! port B controller type byte */
.L_cfg_default_state:
    extu.w r13, r2
.L_cfg_single_mode:
    mov.w r2, @r10
.L_cfg_write_state:
    mov.w @r10, r3
    mov.l   .L_menu_status_word, r2
    mov.w r3, @r2
    mov.l   .L_view_transform_a, r4
    mov.l r13, @r4
    mov.l r13, @(4, r4)
    mov.l   .L_view_offset_a, r5
    mov.l r13, @r5
    mov.l   .L_view_offset_b, r4
    mov.l r13, @r4
    mov.l r13, @(4, r5)
    mov.l r13, @(4, r4)
    mov.l   .L_projection_params_a, r4
    mov.l   .L_screen_width_param, r0
    mov r4, r11
    mov.w @r0, r0
    add #-0x10, r15
    extu.w r0, r0
    mov.l   .L_fn_int_to_float, r3
    shlr r0
    jsr @r3
    mov.l r15, @-r15
    mov #0x0, r2
    mov.l r2, @-r15
    mov.l   .L_float_30, r2
    mov.l r2, @-r15
    mov r15, r3
    mov.l   .L_fn_float_div, r2
    add #0x10, r3
    jsr @r2
    mov.l r3, @-r15
    mov.l   .L_fn_float_to_fixed, r3
    jsr @r3
    nop
    mov.l r0, @r11
    mov.l   .L_projection_params_b, r5
    mov.l   .L_screen_height_param, r9
    mov r5, r12
    mov.w @r9, r0
    extu.w r0, r0
    add #-0x10, r15
    shlr r0
    mov.l   .L_fn_int_to_float, r3
    jsr @r3
    mov.l r15, @-r15
    mov #0x0, r2
    mov.l r2, @-r15
    mov.l   .L_float_30, r2
    mov.l r2, @-r15
    mov r15, r3
    mov.l   .L_fn_float_div, r2
    add #0x10, r3
    jsr @r2
    mov.l r3, @-r15
    mov.l   .L_fn_float_to_fixed, r3
    jsr @r3
    nop
    mov.l r0, @r12
    mov.l @r11, r2
    mov.l r2, @(4, r4)
    mov.l @r12, r3
    mov.l r3, @(4, r5)
    mov.l @r15, r2
    mov.l   .L_saved_input_state, r3
    mov.l r2, @r3
    mov.w @(4, r15), r0
    mov.l   .L_screen_mode_param, r3
    mov r0, r2
    mov.w r2, @r3
    mov.l   .L_fn_scene_update, r8
    mov.l   .L_view_matrix_base, r14
    mov.l @r11, r2
    mov.l r2, @(8, r15)
    bsr     scene_invalidate_b
    mov r13, r4
    mov r0, r4
    jsr @r8
    mov.l @(8, r15), r5
    mov.l @(8, r15), r3
    sub r0, r3
    mov.l r3, @-r15
    bsr     scene_invalidate_a
    mov r13, r4
    neg r0, r4
    jsr @r8
    mov.l @r12, r5
    mov.l @r15+, r2
    sub r0, r2
    mov.l r2, @r14
    bsr     scene_invalidate_a
    mov r13, r4
    mov r0, r4
    jsr @r8
    mov.l @r11, r5
    mov.l @r12, r2
    sub r0, r2
    mov.l r2, @-r15
    bsr     scene_invalidate_b
    mov r13, r4
    mov r0, r4
    jsr @r8
    mov.l @r12, r5
    mov.l @r15+, r2
    sub r0, r2
    mov.l r2, @(4, r14)
    mov.l r13, @(8, r14)
    bsr     scene_invalidate_a
    mov r13, r4
    neg r0, r0
    mov.l r0, @(12, r14)
    bsr     scene_invalidate_b
    mov r13, r4
    mov.l r0, @(16, r14)
    bsr     scene_invalidate_b
    mov r13, r4
    mov.l r0, @(20, r14)
    bsr     scene_invalidate_a
    mov r13, r4
    mov.l r0, @(24, r14)
    mov.l   .L_fp_one_0603DCFC, r4
    mov.l r4, @(28, r14)
    mov.l r13, @(32, r14)
    mov.l r13, @(36, r14)
    mov.l r13, @(40, r14)
    mov.l r4, @(44, r14)
    mov.l r13, @(48, r14)
    mov.l   .L_screen_width_param, r2
    mov.w @r2, r2
    extu.w r2, r2
    shlr r2
    exts.w r2, r2
    bra     .L_cfg_setup_viewport
    nop
    .2byte  0xFFFF
.L_menu_status_word:
    .4byte  sym_060A3E38                /* ! menu display status */
.L_view_transform_a:
    .4byte  sym_060A4C70                /* ! view transform array A */
.L_view_offset_a:
    .4byte  sym_060A4C60                /* ! view offset array A */
.L_view_offset_b:
    .4byte  sym_060A4C68                /* ! view offset array B */
.L_projection_params_a:
    .4byte  sym_060A53A8                /* ! projection param set A */
.L_screen_width_param:
    .4byte  sym_060635AE                /* ! screen width (ROM) */
.L_fn_int_to_float:
    .4byte  sym_060358EC                /* ! int-to-float conversion */
.L_float_30:
    .4byte  0x40F00000                  /* IEEE 754 float constant */
.L_fn_float_div:
    .4byte  sym_060359E4                /* ! float division */
.L_fn_float_to_fixed:
    .4byte  sym_060357B8                /* ! float-to-fixed conversion */
.L_projection_params_b:
    .4byte  sym_060A53B0                /* ! projection param set B */
.L_screen_height_param:
    .4byte  sym_060635B0                /* ! screen height (ROM) */
.L_saved_input_state:
    .4byte  sym_060A4C5C                /* ! saved input state */
.L_screen_mode_param:
    .4byte  sym_060635B2                /* ! screen mode (ROM) */
.L_fn_scene_update:
    .4byte  display_scene_update        /* ! scene update function */
.L_view_matrix_base:
    .4byte  sym_060A3E68                /* ! view matrix array base */
.L_fp_one_0603DCFC:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_cfg_setup_viewport:
    mov #0x34, r0
    mov.w r2, @(r0, r14)
    mov.w @r9, r3
    mov #0x36, r0
    extu.w r3, r3
    shlr r3
    exts.w r3, r3
    mov.w r3, @(r0, r14)
    mov.w   .L_view_depth_default, r3
    mov #0x38, r0
    mov.w r3, @(r0, r14)
    mov #0x3C, r0
    mov.l   .L_screen_width_param_b, r3
    mov.w @r3, r3
    extu.w r3, r3
    shlr r3
    mov.w r3, @(r0, r14)
    mov.w @r9, r3
    extu.w r3, r3
    shlr r3
    mov #0x3E, r0
    mov.w r3, @(r0, r14)
    exts.w r13, r3
    mov #0x40, r0
    mov.w r3, @(r0, r14)
    mov #0x44, r0
    mov.l r13, @(r0, r14)
    mov #0x48, r0
    mov.l r13, @(r0, r14)
    mov #0x4C, r0
    mov.l r4, @(r0, r14)
    mov #0x50, r0
    mov.l r4, @(r0, r14)
    mov.w @(4, r15), r0
    extu.w r0, r0
    cmp/eq #0x2, r0
    bf      .L_cfg_calc_vram
    mov.l   .L_split_view_matrix, r4
    mov r4, r5
    add #-0x80, r5
    mov.l @r5, r2
    mov.l r2, @r4
    mov.l @(4, r5), r3
    mov.l r3, @(4, r4)
    mov.l @(8, r5), r2
    mov.l r2, @(8, r4)
    mov.l @(12, r5), r3
    mov.l r3, @(12, r4)
    mov.l @(16, r5), r2
    mov.l r2, @(16, r4)
    mov.l @(20, r5), r3
    mov.l r3, @(20, r4)
    mov.l @(24, r5), r2
    mov.l r2, @(24, r4)
    mov.l @(28, r5), r3
    mov.l r3, @(28, r4)
    mov.l @(32, r5), r2
    mov.l r2, @(32, r4)
    mov.l @(36, r5), r3
    mov.l r3, @(36, r4)
    mov.l @(40, r5), r2
    mov.l r2, @(40, r4)
    mov.l @(44, r5), r3
    mov.l r3, @(44, r4)
    mov.l @(48, r5), r2
    mov.l r2, @(48, r4)
    mov #0x34, r0
    mov.w @(r0, r5), r3
    mov.w r3, @(r0, r4)
    mov #0x36, r0
    mov.w @(r0, r5), r3
    mov.w r3, @(r0, r4)
    mov #0x38, r0
    mov.w @(r0, r5), r3
    mov.w r3, @(r0, r4)
    mov #0x3C, r0
    mov.w @(r0, r5), r3
    mov.w r3, @(r0, r4)
    mov #0x3E, r0
    mov.w @(r0, r5), r3
    mov.w r3, @(r0, r4)
    mov #0x40, r0
    mov.w @(r0, r5), r3
    mov.w r3, @(r0, r4)
    mov #0x44, r0
    mov.l @(r0, r5), r3
    mov.l r3, @(r0, r4)
    mov #0x48, r0
    mov.l @(r0, r5), r3
    mov.l r3, @(r0, r4)
    mov #0x4C, r0
    mov.l @(r0, r5), r3
    mov.l r3, @(r0, r4)
    mov #0x50, r0
    mov.l @(r0, r5), r3
    mov.l r3, @(r0, r4)
.L_cfg_calc_vram:
    mov.l @r15, r4
    mov.l   .L_addr_align_mask, r3
    and r3, r4
    shlr r4
    mov.l @r15, r0
    and #0x3E, r0
    shlr2 r0
    add r0, r4
    mov.l   .L_vram_write_addr, r3
    mov.l r4, @r3
    mov #0x0, r0
.L_cfg_return:
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_view_depth_default:
    .2byte  0x0190                      /* default view depth = 400 */
.L_screen_width_param_b:
    .4byte  sym_060635AE                /* ! screen width (ROM) */
.L_split_view_matrix:
    .4byte  sym_060A3EE8                /* ! split-screen view matrix */
.L_addr_align_mask:
    .4byte  0x0007FF80                  /* VRAM address alignment mask */
.L_vram_write_addr:
    .4byte  sym_060A3E44                /* ! VRAM write target */

    .global scene_color_matrix
    .type scene_color_matrix, @function
scene_color_matrix:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_color_matrix_base, r10
    mov.l   .L_view_offset_b_cm, r11
    mov.l   .L_view_offset_a_cm, r12
    mov #0x0, r13
    mov.l r6, @r15
    mov.l   .L_display_mode_state, r0
    bra     .L_cm_dispatch
    mov.l @r0, r0
.L_cm_mode_1:
    bra     .L_cm_setup_identity
    extu.w r13, r14
.L_cm_mode_2:
    bra     .L_cm_setup_identity
    mov #0x1, r14
.L_cm_mode_default:
    bra     .L_cm_return
    nop
.L_cm_dispatch:
    cmp/eq #0x1, r0
    bt      .L_cm_mode_1
    cmp/eq #0x2, r0
    bt      .L_cm_mode_2
    bra     .L_cm_mode_default
    nop
.L_cm_setup_identity:
    exts.b r14, r6
    extu.w r14, r2
    mov.l   .L_fp_one_0603DEC4, r7
    mov r6, r3
    shll2 r2
    shll2 r6
    shll2 r3
    shll2 r3
    shll r3
    add r3, r6
    exts.b r6, r6
    add r10, r6
    mov.l r7, @r6
    mov.l r13, @(4, r6)
    mov.l r13, @(8, r6)
    mov.l r13, @(12, r6)
    mov.l r7, @(16, r6)
    mov.l r13, @(20, r6)
    mov.l r13, @(24, r6)
    mov.l r13, @(28, r6)
    mov.l r7, @(32, r6)
    mov.l   .L_scene_active_flags, r3
    add r3, r2
    mov.l @r2, r0
    tst r0, r0
    bt      .L_cm_clear_offset
    extu.w r14, r0
    shll2 r0
    mov.l @(r0, r12), r3
    add r4, r3
    mov.l r3, @(r0, r12)
    bra     .L_cm_update_scroll
    nop
.L_cm_clear_offset:
    extu.w r14, r0
    shll2 r0
    mov.l r13, @(r0, r12)
.L_cm_update_scroll:
    extu.w r14, r6
    shll2 r6
    mov r6, r3
    add r11, r3
    add r12, r6
    mov.l @r3, r2
    add r5, r2
    mov.l r2, @r3
    mov.l @r6, r0
    tst r0, r0
    bf      .L_cm_check_hud
    tst r4, r4
    bt      .L_cm_check_hud
    mov.l   .L_menu_status_word_cm, r4
    mov.l   .L_display_mode_state, r0
    bra     .L_cm_flags_dispatch
    mov.l @r0, r0
.L_cm_mask_high_byte:
    mov.l   .L_mask_byte1, r2
    mov.w @(4, r4), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    bra     .L_cm_write_flags
    nop
.L_cm_mask_low_byte:
    mov.w @(4, r4), r0
    and #0xFF, r0
.L_cm_write_flags:
    bra     .L_cm_check_hud
    mov.w r0, @(4, r4)
    .2byte  0xFFFF
.L_color_matrix_base:
    .4byte  sym_060A53B8
.L_view_offset_b_cm:
    .4byte  sym_060A4C68
.L_view_offset_a_cm:
    .4byte  sym_060A4C60
.L_display_mode_state:
    .4byte  sym_060635A8
.L_fp_one_0603DEC4:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_scene_active_flags:
    .4byte  sym_060A4C44
.L_menu_status_word_cm:
    .4byte  sym_060A3E38
.L_mask_byte1:
    .4byte  0x0000FF00                  /* byte 1 mask */
.L_cm_flags_dispatch:
    cmp/eq #0x1, r0
    bt      .L_cm_mask_high_byte
    cmp/eq #0x2, r0
    bt      .L_cm_mask_low_byte
.L_cm_check_hud:
    mov.l @r15, r0
    tst r0, r0
    bt      .L_cm_check_dirty
    bsr     hud_update_main
    mov.l @r15, r4
.L_cm_check_dirty:
    extu.w r14, r4
    mov.l   .L_scene_dirty_flags, r3
    shll2 r4
    add r4, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_cm_load_view
    mov.l   .L_view_transform_a_cm, r3
    add r4, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_cm_load_view
    extu.w r14, r0
    shll2 r0
    mov.l r13, @(r0, r12)
.L_cm_load_view:
    mov.l   .L_view_matrix_base_cm, r5
    extu.w r14, r4
    shll2 r4
    mov r4, r3
    add r12, r3
    mov.l @r3, r0
    tst r0, r0
    bf      .L_cm_apply_transform
    mov.l   .L_view_pending_flags, r3
    add r4, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_cm_check_flags
.L_cm_apply_transform:
    exts.b r14, r6
    extu.w r14, r4
    mov r6, r3
    shll2 r4
    shll2 r6
    shll2 r3
    shll2 r4
    shll2 r3
    shll2 r4
    shll r3
    add r3, r6
    exts.b r6, r6
    add r10, r6
    shll r4
    add r5, r4
    mov #0x4C, r0
    mov.l @(r0, r4), r3
    mov.l r3, @r6
    mov #0x50, r0
    mov.l @(r0, r4), r3
    mov.l r3, @(16, r6)
    bra     .L_cm_check_scroll
    nop
.L_scene_dirty_flags:
    .4byte  sym_060A4C4C
.L_view_transform_a_cm:
    .4byte  sym_060A4C70
.L_view_matrix_base_cm:
    .4byte  sym_060A3E68
.L_view_pending_flags:
    .4byte  sym_060A4C78
.L_cm_check_flags:
    extu.w r14, r4
    tst r4, r4
    bf      .L_cm_check_mode2
    mov.l   .L_menu_flags_word, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst #0xFF, r0
    bf      .L_cm_copy_projection
.L_cm_check_mode2:
    mov r4, r0
    cmp/eq #0x1, r0
    bf      .L_cm_check_scroll
    mov.l   .L_menu_flags_word, r2
    mov.l   .L_mask_byte1_0603E040, r3
    mov.w @r2, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_cm_check_scroll
.L_cm_copy_projection:
    exts.b r14, r6
    extu.w r14, r4
    mov r6, r3
    shll2 r4
    shll2 r6
    shll2 r3
    shll2 r4
    shll2 r3
    shll2 r4
    shll r3
    add r3, r6
    exts.b r6, r6
    add r10, r6
    shll r4
    add r5, r4
    mov #0x4C, r0
    mov.l @(r0, r4), r3
    mov.l r3, @r6
    mov #0x50, r0
    mov.l @(r0, r4), r3
    mov.l r3, @(16, r6)
    mov #0x4C, r0
    mov.l @(r0, r4), r3
    mov.l r3, @(28, r4)
    mov #0x50, r0
    mov.l @(r0, r4), r3
    mov.l r3, @(44, r4)
.L_cm_check_scroll:
    extu.w r14, r0
    shll2 r0
    mov.l @(r0, r11), r3
    tst r3, r3
    bt      .L_cm_check_pending
    extu.w r14, r0
    shll2 r0
    bsr     display_channel_handler
    mov.l @(r0, r11), r4
.L_cm_check_pending:
    extu.w r14, r4
    shll2 r4
    mov r4, r3
    add r12, r3
    mov.l @r3, r0
    tst r0, r0
    bf      .L_cm_render_dispatch
    mov.l   .L_view_pending_flags_cm, r3
    add r4, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_cm_return
.L_cm_render_dispatch:
    extu.w r14, r3
    mov.l   .L_scene_render_flags, r2
    shll r3
    add r2, r3
    mov.w @r3, r3
    extu.w r3, r3
    tst r3, r3
    bt      .L_cm_tail_sound_test
    extu.w r14, r3
    mov.l   .L_scene_dirty_flags_cm, r2
    shll2 r3
    add r2, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_cm_tail_options
.L_cm_tail_sound_test:
    extu.w r14, r0
    shll2 r0
    mov.l @(r0, r12), r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    bra     sound_test_player
    mov.l @r15+, r14
.L_cm_tail_options:
    extu.w r14, r0
    shll2 r0
    mov.l @(r0, r12), r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    bra     options_render
    mov.l @r15+, r14
.L_cm_return:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_menu_flags_word:
    .4byte  sym_060A3E3C
.L_mask_byte1_0603E040:
    .4byte  0x0000FF00                  /* byte 1 mask */
.L_view_pending_flags_cm:
    .4byte  sym_060A4C78
.L_scene_render_flags:
    .4byte  sym_060A4C54
.L_scene_dirty_flags_cm:
    .4byte  sym_060A4C4C

    .global sound_test_player
    .type sound_test_player, @function
sound_test_player:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x38, r15
    mov.w   .L_ctrl_type_analog_stp, r8
    mov.l   .L_fp_four, r9
    mov.l   .L_fp_half, r12
    mov.l   .L_fn_scene_update_stp, r13
    mov.l r4, @(8, r15)
    mov.l   .L_menu_status_stp, r4
    mov.l   .L_display_mode_stp, r0
    bra     .L_stp_dispatch
    mov.l @r0, r0
.L_stp_mode_1:
    mov #0x0, r14
    mov.l   .L_mask_byte1_0603E0C8, r2
    mov.w @(4, r4), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    mov.w r0, @(4, r4)
    mov.w @(4, r4), r0
    bra     .L_stp_write_flags
    or #0x3, r0
.L_stp_mode_2:
    mov #0x1, r14
    mov.w @(4, r4), r0
    and #0xFF, r0
    mov.w r0, @(4, r4)
    mov.w   DAT_0603e0b2, r3
    mov.w @(4, r4), r0
    mov r0, r2
    or r3, r2
    mov r2, r0
.L_stp_write_flags:
    bra     .L_stp_calc_sincos
    mov.w r0, @(4, r4)
.L_stp_mode_default:
    bra     .L_stp_return
    nop
.L_stp_dispatch:
    cmp/eq #0x1, r0
    bt      .L_stp_mode_1
    cmp/eq #0x2, r0
    bt      .L_stp_mode_2
    bra     .L_stp_mode_default
    nop
.L_ctrl_type_analog_stp:
    .2byte  0x0100

    .global DAT_0603e0b2
DAT_0603e0b2:
    .2byte  0x0300
.L_fp_four:
    .4byte  0x00040000                  /* 4.0 (16.16 fixed-point) */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_fn_scene_update_stp:
    .4byte  sym_0603C0A0                /* ! scene update dispatch */
.L_menu_status_stp:
    .4byte  sym_060A3E38                /* ! menu display status */
.L_display_mode_stp:
    .4byte  sym_060635A8                /* ! current display mode */
.L_mask_byte1_0603E0C8:
    .4byte  0x0000FF00                  /* byte 1 mask */
.L_stp_calc_sincos:
    bsr     scene_invalidate_a
    mov.l @(8, r15), r4
    mov.l r0, @r15
    bsr     scene_invalidate_b
    mov.l @(8, r15), r4
    exts.b r14, r10
    mov.l r0, @(8, r15)
    mov r10, r3
    shll2 r10
    shll2 r3
    shll2 r3
    shll r3
    add r3, r10
    exts.b r10, r10
    mov.l   .L_color_matrix_base_stp, r2
    add r2, r10
    mov r10, r3
    add #0x4, r3
    mov.l r3, @(48, r15)
    mov.l @r3, r1
    mov.l r1, @(12, r15)
    mov r10, r1
    add #0x8, r1
    mov.l r1, @(44, r15)
    mov.l @r1, r3
    mov.l r3, @(52, r15)
    mov r10, r3
    add #0x10, r3
    mov.l r3, @(40, r15)
    mov.l @r3, r2
    mov.l r2, @(36, r15)
    mov r10, r2
    add #0x14, r2
    mov.l r2, @(28, r15)
    mov.l @r2, r1
    mov.l r1, @(32, r15)
    mov r10, r1
    add #0x1C, r1
    mov.l r1, @(20, r15)
    mov.l @r1, r3
    mov.l r3, @(24, r15)
    mov r10, r3
    add #0x20, r3
    mov.l r3, @(4, r15)
    mov.l @r3, r2
    mov.l r2, @(16, r15)
    mov.l   .L_fn_scene_update_stp2, r11
    mov.l @(48, r15), r2
    mov.l r2, @-r15
    mov.l @(12, r15), r5
    jsr @r11
    mov.l @(16, r15), r4
    mov.l r0, @-r15
    mov.l @(8, r15), r5
    jsr @r11
    mov.l @(60, r15), r4
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @(44, r15), r3
    mov.l r3, @-r15
    mov.l @(4, r15), r5
    jsr @r11
    mov.l @(16, r15), r4
    neg r0, r0
    mov.l r0, @-r15
    mov.l @(16, r15), r5
    jsr @r11
    mov.l @(60, r15), r4
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @(40, r15), r3
    mov.l r3, @-r15
    mov.l @(12, r15), r5
    jsr @r11
    mov.l @(40, r15), r4
    mov.l r0, @-r15
    mov.l @(8, r15), r5
    jsr @r11
    mov.l @(40, r15), r4
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @(28, r15), r3
    mov.l r3, @-r15
    mov.l @(4, r15), r5
    jsr @r11
    mov.l @(40, r15), r4
    neg r0, r0
    mov.l r0, @-r15
    mov.l @(16, r15), r5
    jsr @r11
    mov.l @(40, r15), r4
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @(20, r15), r3
    mov.l r3, @-r15
    mov.l @(12, r15), r5
    jsr @r11
    mov.l @(28, r15), r4
    mov.l r0, @-r15
    mov.l @(8, r15), r5
    bra     .L_stp_matrix_continue
    mov.l @(24, r15), r4
.L_color_matrix_base_stp:
    .4byte  sym_060A53B8
.L_fn_scene_update_stp2:
    .4byte  display_scene_update
.L_stp_matrix_continue:
    jsr @r11
    nop
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @(4, r15), r3
    mov.l r3, @-r15
    mov.l @(4, r15), r5
    jsr @r11
    mov.l @(28, r15), r4
    neg r0, r0
    mov.l r0, @-r15
    mov.l @(16, r15), r5
    jsr @r11
    mov.l @(24, r15), r4
    mov.l @r15+, r3
    extu.w r14, r4
    add r3, r0
    mov.l @r15+, r2
    shll2 r4
    mov.l r0, @r2
    shll2 r4
    shll2 r4
    shll r4
    mov.l   .L_view_matrix_stp, r3
    add r3, r4
    mov.l @r10, r2
    mov.l r2, @(28, r4)
    mov.l @(48, r15), r3
    mov.l @r3, r2
    mov.l r2, @(32, r4)
    mov.l @(44, r15), r3
    mov.l @r3, r2
    mov.l r2, @(36, r4)
    mov.l @(40, r15), r3
    mov.l @r3, r2
    mov.l r2, @(44, r4)
    mov.l @(28, r15), r3
    mov.l @r3, r2
    mov.l r2, @(48, r4)
    mov.l @(24, r10), r7
    mov #0x34, r0
    mov.w @(r0, r4), r6
    mov #0x3C, r0
    mov.w @(r0, r4), r3
    mov r6, r11
    sub r3, r11
    mul.l r11, r7
    mov.l @(20, r15), r3
    mov #0x36, r0
    sts macl, r11
    mov.l @r3, r3
    mov.w @(r0, r4), r2
    mov #0x3E, r0
    mov.w @(r0, r4), r1
    mov #0x38, r0
    sub r1, r2
    mul.l r2, r3
    mov.l @(4, r15), r2
    sts macl, r3
    add r3, r11
    mov.l @r2, r3
    mov.l r3, @(8, r15)
    mov.w @(r0, r4), r3
    mov #0x40, r0
    mov.l r3, @r15
    mov.w @(r0, r4), r5
    mov.l @(8, r15), r1
    sub r5, r3
    mov r5, r0
    add #-0x10, r15
    mul.l r3, r1
    exts.w r0, r0
    sts macl, r1
    mov.l   .L_fn_int_to_float_stp, r3
    add r1, r11
    jsr @r3
    mov.l r15, @-r15
    mov #0x0, r2
    mov.l r2, @-r15
    mov.l   .L_float_30_stp, r2
    mov.l r2, @-r15
    mov r15, r3
    mov.l   .L_fn_float_div_stp, r2
    add #0x10, r3
    jsr @r2
    mov.l r3, @-r15
    mov.l   .L_fn_float_to_fixed_stp, r3
    jsr @r3
    nop
    add r0, r11
    extu.w r14, r3
    mul.l r7, r6
    shll2 r3
    sts macl, r6
    mov.l r3, @(12, r15)
    neg r6, r6
    mov.l   .L_view_pending_stp, r2
    add r3, r2
    mov.l @r2, r1
    mov.l @r15, r2
    add r1, r11
    mov.l @(8, r15), r1
    mul.l r1, r2
    sts macl, r2
    sub r2, r6
    mov.l r6, @(8, r15)
    mov.l @(12, r15), r2
    mov.l   .L_view_transform_stp, r0
    mov.l @(r0, r2), r2
    tst r2, r2
    bf      .L_stp_has_transform
    bra     .L_stp_no_transform
    nop
.L_stp_has_transform:
    extu.w r14, r10
    shll2 r10
    shll2 r10
    shll2 r10
    shll r10
    mov.l   .L_view_matrix_stp, r3
    add r3, r10
    mov.l @(4, r10), r2
    mov.l   .L_fp_300, r3
    add r3, r2
    mov #0x54, r0
    mov.l r2, @(r0, r10)
    extu.w r14, r4
    shll2 r4
    mov.l r4, @r15
    mov.l   .L_view_transform_stp, r3
    add r3, r4
    bra     .L_stp_calc_angles
    nop
.L_view_matrix_stp:
    .4byte  sym_060A3E68
.L_fn_int_to_float_stp:
    .4byte  sym_060358EC
.L_float_30_stp:
    .4byte  0x40F00000
.L_fn_float_div_stp:
    .4byte  sym_060359E4
.L_fn_float_to_fixed_stp:
    .4byte  sym_060357B8
.L_view_pending_stp:
    .4byte  sym_060A4C78
.L_view_transform_stp:
    .4byte  sym_060A4C70
.L_fp_300:
    .4byte  0x012C0000                  /* 300.0 (16.16 fixed-point) */
.L_stp_calc_angles:
    mov.l r4, @(4, r15)
    bsr     scene_invalidate_b
    mov.l @r4, r4
    mov #0x58, r1
    add r10, r1
    mov.l r0, @r1
    mov.l @(4, r15), r4
    bsr     scene_invalidate_a
    mov.l @r4, r4
    mov #0x5C, r1
    add r10, r1
    mov #0x0, r10
    mov.l r0, @r1
    mov.l @r15, r3
    mov.l   .L_render_slot_flags, r2
    mov.w   DAT_0603e3b6, r1
    add r2, r3
    mov.l r1, @r3
    extu.w r14, r3
    exts.b r14, r1
    shll2 r3
    mov r1, r0
    add r2, r3
    shll2 r1
    shll2 r0
    mov.l r3, @(12, r15)
    shll2 r0
    extu.w r14, r3
    shll r0
    shll2 r3
    add r0, r1
    shll2 r3
    exts.b r1, r1
    mov.l   .L_color_matrix_base_stp2, r0
    shll2 r3
    add r0, r1
    add #0x1C, r1
    mov.l r1, @(16, r15)
    shll r3
    mov.l   .L_view_matrix_stp2, r0
    add r0, r3
    mov.l r3, @(20, r15)
    mov.w   DAT_0603e3b8, r2
    muls.w r2, r14
    sts macl, r2
    exts.w r2, r2
    mov.l   .L_color_palette_table, r0
    add r0, r2
    bra     .L_stp_palette_check
    mov.l r2, @(4, r15)
.L_stp_palette_loop:
    mov.l @(16, r15), r2
    mov #0x36, r0
    mov r10, r1
    mov.l @(20, r15), r3
    mov.l @r2, r2
    mov.w @(r0, r3), r3
    sub r3, r1
    mov.w   DAT_0603e3ba, r3
    add r3, r1
    mul.l r1, r2
    mov.l @(8, r15), r3
    sts macl, r1
    add r3, r1
    mov.l r1, @r15
    mov.l   .L_fn_visibility_check, r2
    jsr @r2
    mov r8, r0
    tst r0, r0
    bt      .L_stp_not_visible
    mov.l @r15, r5
    jsr @r13
    mov r11, r4
    neg r0, r0
    cmp/gt r9, r0
    bt      .L_stp_out_of_range
    mov.l @r15, r5
    jsr @r13
    mov r11, r4
    neg r0, r0
    cmp/pz r0
    bt      .L_stp_calc_color
.L_stp_out_of_range:
    mov r10, r0
    shll r0
    mov.l @(4, r15), r3
    add r3, r0
    bra     .L_stp_write_default
    nop
.L_stp_calc_color:
    mov r10, r0
    mov.l @(4, r15), r3
    shll r0
    add r3, r0
    mov.l r0, @-r15
    mov.l @(4, r15), r5
    jsr @r13
    mov r11, r4
    neg r0, r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    extu.w r0, r0
    mov.w   DAT_0603e3bc, r3
    and r3, r0
    extu.w r0, r0
    mov.l @r15+, r2
    bra     .L_stp_next_entry
    mov.w r0, @r2

    .global DAT_0603e3b6
DAT_0603e3b6:
    .2byte  0x0333

    .global DAT_0603e3b8
DAT_0603e3b8:
    .2byte  0x0668

    .global DAT_0603e3ba
DAT_0603e3ba:
    .2byte  0xFED4

    .global DAT_0603e3bc
DAT_0603e3bc:
    .2byte  0x7FFF
    .2byte  0xFFFF
.L_render_slot_flags:
    .4byte  sym_060A4C38
.L_color_matrix_base_stp2:
    .4byte  sym_060A53B8
.L_view_matrix_stp2:
    .4byte  sym_060A3E68
.L_color_palette_table:
    .4byte  sym_060A3F68
.L_fn_visibility_check:
    .4byte  sym_06034FFC
.L_stp_not_visible:
    mov r10, r0
    shll r0
    mov.l @(4, r15), r3
    add r3, r0
.L_stp_write_default:
    extu.w r12, r2
    mov.w r2, @r0
.L_stp_next_entry:
    add #0x1, r10
.L_stp_palette_check:
    mov.l @(12, r15), r3
    mov.l @r3, r3
    cmp/hs r3, r10
    bf      .L_stp_palette_loop
    bra     .L_stp_mark_ready
    nop
.L_stp_no_transform:
    extu.w r14, r0
    mov.l   .L_scene_dirty_stp, r5
    shll2 r0
    mov.l @(r0, r5), r4
    mov r4, r0
    cmp/eq #-0x1, r0
    bt      .L_stp_use_default_pos
    tst r4, r4
    bt      .L_stp_use_default_pos
    extu.w r14, r4
    extu.w r14, r0
    mov.l   .L_view_matrix_stp3, r3
    shll2 r4
    shll2 r0
    shll2 r4
    mov.l @(r0, r5), r0
    shll2 r4
    add #-0x10, r15
    shll r4
    mov.l   .L_fn_int_to_float_stp2, r2
    add r3, r4
    mov #0x0, r3
    cmp/gt r0, r3
    addc r3, r0
    shar r0
    jsr @r2
    mov.l r15, @-r15
    mov.l r3, @-r15
    mov.l   .L_float_30_stp2, r3
    mov.l r3, @-r15
    mov r15, r2
    mov.l   .L_fn_float_div_stp2, r3
    add #0x10, r2
    jsr @r3
    mov.l r2, @-r15
    mov.l   .L_fn_float_to_fixed_stp2, r2
    jsr @r2
    nop
    mov.l @(4, r4), r3
    add r3, r0
    mov #0x54, r1
    add r4, r1
    bra     .L_stp_setup_palette_b
    mov.l r0, @r1
    .2byte  0xFFFF
.L_scene_dirty_stp:
    .4byte  sym_060A4C4C
.L_view_matrix_stp3:
    .4byte  sym_060A3E68
.L_fn_int_to_float_stp2:
    .4byte  sym_060358EC
.L_float_30_stp2:
    .4byte  0x40F00000
.L_fn_float_div_stp2:
    .4byte  sym_060359E4
.L_fn_float_to_fixed_stp2:
    .4byte  sym_060357B8
.L_stp_use_default_pos:
    extu.w r14, r4
    shll2 r4
    shll2 r4
    shll2 r4
    shll r4
    mov.l   .L_view_matrix_stp4, r3
    add r3, r4
    mov.l @(4, r4), r2
    mov #0x54, r0
    mov.l r2, @(r0, r4)
.L_stp_setup_palette_b:
    extu.w r14, r3
    mov.l   .L_view_matrix_stp4, r2
    shll2 r3
    shll2 r3
    shll2 r3
    shll r3
    add r2, r3
    mov #0x58, r2
    mov.l r3, @r15
    add r3, r2
    mov.l r2, @-r15
    bsr     scene_invalidate_b
    mov #0x0, r4
    mov.l @r15+, r3
    mov.l r0, @r3
    mov #0x5C, r3
    mov.l @r15, r2
    add r2, r3
    mov.l r3, @-r15
    bsr     scene_invalidate_a
    mov #0x0, r4
    extu.w r14, r3
    mov #0x0, r10
    mov.l @r15+, r2
    shll2 r3
    mov.l r0, @r2
    mov.l   .L_render_slot_flags_stp, r2
    mov.l   .L_screen_height_stp, r1
    add r2, r3
    mov.w @r1, r1
    extu.w r1, r1
    add #-0x1, r1
    mov.l r1, @r3
    extu.w r14, r3
    exts.b r14, r1
    shll2 r3
    mov r1, r0
    add r2, r3
    shll2 r1
    shll2 r0
    mov.l r3, @(16, r15)
    shll2 r0
    shll r0
    add r0, r1
    exts.b r1, r1
    mov.l   .L_color_matrix_stp, r0
    add r0, r1
    add #0x1C, r1
    mov.l r1, @(12, r15)
    extu.w r14, r3
    shll2 r3
    shll2 r3
    shll2 r3
    shll r3
    mov.l   .L_view_matrix_stp4, r0
    add r0, r3
    mov.l r3, @(20, r15)
    mov.w   .L_palette_stride, r2
    muls.w r2, r14
    sts macl, r2
    exts.w r2, r2
    mov.l   .L_palette_table_stp, r0
    add r0, r2
    bra     .L_stp_palette_check_b
    mov.l r2, @(4, r15)
.L_stp_palette_loop_b:
    mov #0x36, r0
    mov r10, r1
    mov.l @(12, r15), r2
    mov.l @(20, r15), r3
    mov.w @(r0, r3), r3
    sub r3, r1
    mov.l @r2, r3
    mov.l @(8, r15), r2
    mul.l r1, r3
    sts macl, r1
    add r2, r1
    mov.l r1, @r15
    mov.l   .L_fn_visibility_stp, r3
    jsr @r3
    mov r8, r0
    tst r0, r0
    bt      .L_stp_not_visible_b
    mov.l @r15, r5
    jsr @r13
    mov r11, r4
    neg r0, r0
    cmp/gt r9, r0
    bt      .L_stp_out_of_range_b
    mov.l @r15, r5
    jsr @r13
    mov r11, r4
    neg r0, r0
    cmp/pz r0
    bt      .L_stp_calc_color_b
.L_stp_out_of_range_b:
    mov r10, r0
    shll r0
    mov.l @(4, r15), r3
    add r3, r0
    bra     .L_stp_write_default_b
    nop
.L_palette_stride:
    .2byte  0x0668
    .2byte  0xFFFF
.L_view_matrix_stp4:
    .4byte  sym_060A3E68
.L_render_slot_flags_stp:
    .4byte  sym_060A4C38
.L_screen_height_stp:
    .4byte  sym_060635B0
.L_color_matrix_stp:
    .4byte  sym_060A53B8
.L_palette_table_stp:
    .4byte  sym_060A3F68
.L_fn_visibility_stp:
    .4byte  sym_06034FFC
.L_stp_calc_color_b:
    mov r10, r0
    mov.l @(4, r15), r3
    shll r0
    add r3, r0
    mov.l r0, @-r15
    mov.l @(4, r15), r5
    jsr @r13
    mov r11, r4
    neg r0, r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    extu.w r0, r0
    mov.w   DAT_0603e61e, r3
    and r3, r0
    extu.w r0, r0
    mov.l @r15+, r2
    bra     .L_stp_next_entry_b
    mov.w r0, @r2
.L_stp_not_visible_b:
    mov r10, r0
    shll r0
    mov.l @(4, r15), r3
    add r3, r0
.L_stp_write_default_b:
    extu.w r12, r2
    mov.w r2, @r0
.L_stp_next_entry_b:
    add #0x1, r10
.L_stp_palette_check_b:
    mov.l @(16, r15), r3
    mov.l @r3, r3
    cmp/hs r3, r10
    bf      .L_stp_palette_loop_b
.L_stp_mark_ready:
    extu.w r14, r14
    shll r14
    mov.l   .L_scene_ready_flags, r3
    add r3, r14
    mov #0x1, r2
    mov.w r2, @r14
.L_stp_return:
    add #0x38, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global options_render
    .type options_render, @function
options_render:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    add #-0x34, r15
    mov.l   .L_fp_four_0603E628, r8
    mov.w   DAT_0603e61e, r9
    mov r9, r12
    add #0x1, r12
    mov.l   .L_fn_scene_update_opt, r14
    mov.l r4, @(8, r15)
    mov.l   .L_menu_status_opt, r4
    mov.l   .L_display_mode_opt, r0
    bra     .L_opt_dispatch
    mov.l @r0, r0
.L_opt_mode_1:
    mov #0x0, r13
    mov.l   .L_mask_byte1_0603E638, r2
    mov.w @(4, r4), r0
    mov r0, r3
    and r2, r3
    mov r3, r0
    mov.w r0, @(4, r4)
    mov.w @(4, r4), r0
    bra     .L_opt_write_flags
    or #0x3, r0
.L_opt_mode_2:
    mov #0x1, r13
    mov.w @(4, r4), r0
    and #0xFF, r0
    mov.w r0, @(4, r4)
    mov.w   .L_display_flags_opt, r3
    mov.w @(4, r4), r0
    mov r0, r2
    or r3, r2
    mov r2, r0
.L_opt_write_flags:
    bra     .L_opt_calc_sincos
    mov.w r0, @(4, r4)
.L_opt_mode_default:
    bra     .L_opt_return
    nop
.L_opt_dispatch:
    cmp/eq #0x1, r0
    bt      .L_opt_mode_1
    cmp/eq #0x2, r0
    bt      .L_opt_mode_2
    bra     .L_opt_mode_default
    nop

    .global DAT_0603e61e
DAT_0603e61e:
    .2byte  0x7FFF
.L_display_flags_opt:
    .2byte  0x0300
    .2byte  0xFFFF
.L_scene_ready_flags:
    .4byte  sym_060A4C40
.L_fp_four_0603E628:
    .4byte  0x00040000                  /* 4.0 (16.16 fixed-point) */
.L_fn_scene_update_opt:
    .4byte  sym_0603C0A0
.L_menu_status_opt:
    .4byte  sym_060A3E38
.L_display_mode_opt:
    .4byte  sym_060635A8
.L_mask_byte1_0603E638:
    .4byte  0x0000FF00                  /* byte 1 mask */
.L_opt_calc_sincos:
    bsr     scene_invalidate_a
    mov.l @(8, r15), r4
    mov.l r0, @r15
    bsr     scene_invalidate_b
    mov.l @(8, r15), r4
    exts.b r13, r10
    mov.l r0, @(8, r15)
    mov r10, r3
    shll2 r10
    shll2 r3
    shll2 r3
    shll r3
    add r3, r10
    exts.b r10, r10
    mov.l   .L_color_matrix_opt, r2
    add r2, r10
    mov.l @r10, r3
    mov.l r3, @(40, r15)
    mov r10, r3
    add #0x8, r3
    mov.l r3, @(24, r15)
    mov.l @r3, r1
    mov.l r1, @(16, r15)
    mov r10, r1
    add #0xC, r1
    mov.l r1, @(32, r15)
    mov.l @r1, r2
    mov.l r2, @(12, r15)
    mov r10, r2
    add #0x14, r2
    mov.l r2, @(28, r15)
    mov.l @r2, r3
    mov.l r3, @(44, r15)
    mov r10, r3
    add #0x18, r3
    mov.l r3, @(20, r15)
    mov.l @r3, r1
    mov.l r1, @(48, r15)
    mov r10, r1
    add #0x20, r1
    mov.l r1, @(4, r15)
    mov.l @r1, r2
    mov.l r2, @(36, r15)
    mov.l   .L_fn_scene_update_opt2, r11
    mov.l @(8, r15), r5
    jsr @r11
    mov.l @(40, r15), r4
    mov.l r0, @-r15
    mov.l @(4, r15), r5
    jsr @r11
    mov.l @(20, r15), r4
    mov.l @r15+, r3
    sub r0, r3
    mov.l r3, @r10
    mov.l @(24, r15), r2
    mov.l r2, @-r15
    mov.l @(4, r15), r5
    jsr @r11
    mov.l @(44, r15), r4
    mov.l r0, @-r15
    mov.l @(16, r15), r5
    jsr @r11
    mov.l @(24, r15), r4
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @(32, r15), r3
    mov.l r3, @-r15
    mov.l @(12, r15), r5
    jsr @r11
    mov.l @(16, r15), r4
    mov.l r0, @-r15
    mov.l @(8, r15), r5
    jsr @r11
    mov.l @(52, r15), r4
    mov.l @r15+, r3
    sub r0, r3
    mov.l @r15+, r2
    mov.l r3, @r2
    mov.l @(28, r15), r3
    mov.l r3, @-r15
    mov.l @(4, r15), r5
    jsr @r11
    mov.l @(16, r15), r4
    mov.l r0, @-r15
    mov.l @(16, r15), r5
    jsr @r11
    mov.l @(52, r15), r4
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @(20, r15), r3
    mov.l r3, @-r15
    mov.l @(12, r15), r5
    jsr @r11
    mov.l @(52, r15), r4
    mov.l r0, @-r15
    mov.l @(8, r15), r5
    jsr @r11
    mov.l @(44, r15), r4
    mov.l @r15+, r3
    sub r0, r3
    mov.l @r15+, r2
    mov.l r3, @r2
    mov.l @(4, r15), r3
    mov.l r3, @-r15
    mov.l @(4, r15), r5
    bra     .L_opt_matrix_continue
    mov.l @(52, r15), r4
    .2byte  0xFFFF
.L_color_matrix_opt:
    .4byte  sym_060A53B8
.L_fn_scene_update_opt2:
    .4byte  display_scene_update
.L_opt_matrix_continue:
    jsr @r11
    nop
    mov.l r0, @-r15
    mov.l @(16, r15), r5
    jsr @r11
    mov.l @(44, r15), r4
    mov.l @r15+, r3
    extu.w r13, r4
    add r3, r0
    mov.l @r15+, r2
    shll2 r4
    mov.l r0, @r2
    shll2 r4
    shll2 r4
    shll r4
    mov.l   .L_view_matrix_opt, r3
    add r3, r4
    mov.l @r10, r2
    mov.l r2, @(28, r4)
    mov.l @(24, r15), r3
    mov.l @r3, r2
    mov.l r2, @(36, r4)
    mov.l @(32, r15), r3
    mov.l @r3, r2
    mov.l r2, @(40, r4)
    mov.l @(16, r10), r3
    mov.l r3, @(44, r4)
    mov.l @(28, r15), r2
    mov.l @r2, r3
    mov.l r3, @(48, r4)
    mov.l @(20, r15), r11
    mov #0x34, r0
    mov.w @(r0, r4), r3
    mov #0x3C, r0
    mov.w @(r0, r4), r2
    sub r2, r3
    mov.l @r11, r11
    mul.l r3, r11
    sts macl, r11
    mov.l @(28, r10), r3
    mov.l r3, @r15
    mov #0x36, r0
    mov.w @(r0, r4), r3
    mov.l r3, @(8, r15)
    mov #0x3E, r0
    mov.w @(r0, r4), r2
    sub r2, r3
    mov.l @r15, r2
    mul.l r3, r2
    sts macl, r2
    add r2, r11
    mov.l @(4, r15), r6
    mov.l @r6, r6
    mov #0x38, r0
    mov.w @(r0, r4), r7
    mov #0x40, r0
    mov.w @(r0, r4), r3
    mov r3, r0
    mov.w r0, @(12, r15)
    mov.w @(12, r15), r0
    mov r0, r3
    mov r7, r2
    sub r3, r2
    mul.l r2, r6
    sts macl, r3
    add r3, r11
    add #-0x8, r15
    mov.w @(20, r15), r0
    add #-0x8, r15
    mov.l   .L_fn_int_to_float_opt, r2
    jsr @r2
    mov.l r15, @-r15
    mov #0x0, r3
    mov.l r3, @-r15
    mov.l   .L_float_30_opt, r3
    mov.l r3, @-r15
    mov r15, r2
    mov.l   .L_fn_float_div_opt, r3
    add #0x10, r2
    jsr @r3
    mov.l r2, @-r15
    mov.l   .L_fn_float_to_fixed_opt, r2
    jsr @r2
    nop
    add r0, r11
    extu.w r13, r5
    mov.l   .L_view_pending_opt, r3
    shll2 r5
    add r5, r3
    mov.l @r3, r2
    mov.l @(8, r15), r3
    add r2, r11
    mov.l @r15, r2
    mul.l r2, r3
    sts macl, r3
    neg r3, r3
    mul.l r6, r7
    sts macl, r7
    sub r7, r3
    mov.l r3, @(8, r15)
    mov.l   .L_view_transform_opt, r1
    add r1, r5
    mov.l @r5, r0
    tst r0, r0
    bf      .L_opt_has_transform
    bra     .L_opt_no_transform
    nop
.L_opt_has_transform:
    extu.w r13, r10
    mov.l   .L_view_matrix_opt, r3
    mov #0x54, r0
    extu.w r13, r4
    shll2 r10
    shll2 r4
    shll2 r10
    shll2 r10
    shll r10
    add r3, r10
    mov.l @r10, r2
    mov.l   .L_fp_300_opt, r3
    add r3, r2
    mov.l r2, @(r0, r10)
    mov.l r4, @(4, r15)
    mov.l   .L_view_transform_opt, r3
    add r3, r4
    mov.l r4, @r15
    mov.l @r4, r4
    mov.l   .L_fp_90_opt, r2
    add r2, r4
    bsr     scene_invalidate_b
    nop
    mov #0x58, r1
    add r10, r1
    mov.l r0, @r1
    mov.l @r15, r4
    mov.l @r4, r4
    bra     .L_opt_calc_angles
    nop
    .2byte  0xFFFF
.L_view_matrix_opt:
    .4byte  sym_060A3E68
.L_fn_int_to_float_opt:
    .4byte  sym_060358EC
.L_float_30_opt:
    .4byte  0x40F00000
.L_fn_float_div_opt:
    .4byte  sym_060359E4
.L_fn_float_to_fixed_opt:
    .4byte  sym_060357B8
.L_view_pending_opt:
    .4byte  sym_060A4C78
.L_view_transform_opt:
    .4byte  sym_060A4C70
.L_fp_300_opt:
    .4byte  0x012C0000                  /* 300.0 (16.16 fixed-point) */
.L_fp_90_opt:
    .4byte  0x005A0000                  /* 90.0 (16.16 fixed-point) */
.L_opt_calc_angles:
    mov.l   .L_fp_90_opt2, r3
    add r3, r4
    bsr     scene_invalidate_a
    nop
    mov #0x5C, r1
    add r10, r1
    mov.l r0, @r1
    mov #0x0, r10
    mov.l @(4, r15), r3
    mov.l   .L_render_slot_opt, r2
    mov.w   DAT_0603e93a, r1
    add r2, r3
    mov.l r1, @r3
    extu.w r13, r3
    exts.b r13, r1
    shll2 r3
    mov r1, r0
    add r2, r3
    shll2 r1
    shll2 r0
    mov.l r3, @(20, r15)
    shll2 r0
    extu.w r13, r3
    shll r0
    shll2 r3
    add r0, r1
    shll2 r3
    exts.b r1, r1
    mov.l   .L_color_matrix_opt2, r0
    shll2 r3
    add r0, r1
    add #0x18, r1
    mov.l r1, @(16, r15)
    shll r3
    mov.l   .L_view_matrix_opt2, r0
    add r0, r3
    mov.l r3, @(12, r15)
    mov.w   DAT_0603e93c, r2
    muls.w r2, r13
    sts macl, r2
    exts.w r2, r2
    mov.l   .L_palette_table_opt, r0
    add r0, r2
    bra     .L_opt_palette_check
    mov.l r2, @(4, r15)
.L_opt_palette_loop:
    mov #0x34, r0
    mov r10, r1
    mov.l @(16, r15), r2
    mov.l @(12, r15), r3
    mov.l @r2, r2
    mov.w @(r0, r3), r3
    sub r3, r1
    mov.w   DAT_0603e93e, r3
    add r3, r1
    mul.l r1, r2
    mov.l @(8, r15), r3
    sts macl, r1
    add r3, r1
    mov.l r1, @r15
    mov.w   .L_ctrl_type_analog_opt, r0
    mov.l   .L_fn_visibility_opt, r2
    jsr @r2
    nop
    tst r0, r0
    bt      .L_opt_not_visible
    mov.l @r15, r5
    jsr @r14
    mov r11, r4
    neg r0, r0
    cmp/gt r8, r0
    .word 0x0029
    mov.l r0, @-r15
    mov.l @(4, r15), r5
    jsr @r14
    mov r11, r4
    neg r0, r0
    cmp/pz r0
    .word 0x0029
    xor #0x1, r0
    mov.l @r15+, r3
    or r3, r0
    tst r0, r0
    bt      .L_opt_calc_color
    mov r10, r0
    shll r0
    mov.l @(4, r15), r3
    add r3, r0
    bra     .L_opt_write_default
    nop
.L_opt_calc_color:
    mov r10, r0
    mov.l @(4, r15), r3
    shll r0
    add r3, r0
    mov.l r0, @-r15
    mov.l @(4, r15), r5
    jsr @r14
    mov r11, r4
    neg r0, r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    extu.w r0, r0
    and r9, r0
    extu.w r0, r0
    mov.l @r15+, r3
    mov.w r0, @r3
    bra     .L_opt_next_entry
    nop

    .global DAT_0603e93a
DAT_0603e93a:
    .2byte  0x0333

    .global DAT_0603e93c
DAT_0603e93c:
    .2byte  0x0668

    .global DAT_0603e93e
DAT_0603e93e:
    .2byte  0xFED4
.L_ctrl_type_analog_opt:
    .2byte  0x0100
    .2byte  0xFFFF
.L_fp_90_opt2:
    .4byte  0x005A0000                  /* 90.0 (16.16 fixed-point) */
.L_render_slot_opt:
    .4byte  sym_060A4C38
.L_color_matrix_opt2:
    .4byte  sym_060A53B8
.L_view_matrix_opt2:
    .4byte  sym_060A3E68
.L_palette_table_opt:
    .4byte  sym_060A3F68
.L_fn_visibility_opt:
    .4byte  sym_06034FFC
.L_opt_not_visible:
    mov r10, r0
    shll r0
    mov.l @(4, r15), r3
    add r3, r0
.L_opt_write_default:
    extu.w r12, r2
    mov.w r2, @r0
.L_opt_next_entry:
    add #0x1, r10
.L_opt_palette_check:
    mov.l @(20, r15), r3
    mov.l @r3, r3
    cmp/hs r3, r10
    bf      .L_opt_palette_loop
    bra     .L_opt_mark_ready
    nop
.L_opt_no_transform:
    extu.w r13, r10
    mov.l   .L_view_matrix_opt3, r3
    mov #0x54, r0
    mov.l   .L_fp_90_opt3, r4
    shll2 r10
    shll2 r10
    shll2 r10
    shll r10
    add r3, r10
    mov.l @r10, r2
    bsr     scene_invalidate_b
    mov.l r2, @(r0, r10)
    mov #0x58, r1
    mov.l   .L_fp_90_opt3, r4
    add r10, r1
    bsr     scene_invalidate_a
    mov.l r0, @r1
    mov #0x5C, r1
    extu.w r13, r3
    add r10, r1
    shll2 r3
    mov.l r0, @r1
    mov #0x0, r10
    mov.l   .L_render_slot_opt2, r2
    mov.l   .L_screen_width_opt, r1
    add r2, r3
    mov.w @r1, r1
    extu.w r1, r1
    add #-0x1, r1
    mov.l r1, @r3
    extu.w r13, r3
    exts.b r13, r1
    shll2 r3
    mov r1, r0
    add r2, r3
    shll2 r1
    shll2 r0
    mov.l r3, @(20, r15)
    shll2 r0
    shll r0
    add r0, r1
    exts.b r1, r1
    mov.l   .L_color_matrix_opt3, r0
    add r0, r1
    add #0x18, r1
    mov.l r1, @(16, r15)
    extu.w r13, r3
    shll2 r3
    shll2 r3
    shll2 r3
    shll r3
    mov.l   .L_view_matrix_opt3, r0
    add r0, r3
    mov.l r3, @(12, r15)
    mov.w   DAT_0603ea46, r2
    muls.w r2, r13
    sts macl, r2
    exts.w r2, r2
    mov.l   .L_palette_table_opt2, r0
    add r0, r2
    bra     .L_opt_palette_check_b
    mov.l r2, @(4, r15)
.L_opt_palette_loop_b:
    mov #0x34, r0
    mov r10, r1
    mov.l @(16, r15), r2
    mov.l @(12, r15), r3
    mov.w @(r0, r3), r3
    sub r3, r1
    mov.l @r2, r3
    mov.l @(8, r15), r2
    mul.l r1, r3
    sts macl, r1
    add r2, r1
    mov.l r1, @r15
    mov.w   .L_ctrl_type_analog_opt2, r0
    mov.l   .L_fn_visibility_opt2, r3
    jsr @r3
    nop
    tst r0, r0
    bt      .L_opt_not_visible_b
    mov.l @r15, r5
    jsr @r14
    mov r11, r4
    neg r0, r0
    cmp/gt r8, r0
    .word 0x0029
    mov.l r0, @-r15
    mov.l @(4, r15), r5
    jsr @r14
    mov r11, r4
    neg r0, r0
    cmp/pz r0
    .word 0x0029
    xor #0x1, r0
    mov.l @r15+, r3
    or r3, r0
    tst r0, r0
    bt      .L_opt_calc_color_b
    mov r10, r0
    shll r0
    mov.l @(4, r15), r3
    add r3, r0
    bra     .L_opt_write_default_b
    nop

    .global DAT_0603ea46
DAT_0603ea46:
    .2byte  0x0668
.L_ctrl_type_analog_opt2:
    .2byte  0x0100
    .2byte  0xFFFF
.L_view_matrix_opt3:
    .4byte  sym_060A3E68
.L_fp_90_opt3:
    .4byte  0x005A0000                  /* 90.0 (16.16 fixed-point) */
.L_render_slot_opt2:
    .4byte  sym_060A4C38
.L_screen_width_opt:
    .4byte  sym_060635AE
.L_color_matrix_opt3:
    .4byte  sym_060A53B8
.L_palette_table_opt2:
    .4byte  sym_060A3F68
.L_fn_visibility_opt2:
    .4byte  sym_06034FFC
.L_opt_calc_color_b:
    mov r10, r0
    mov.l @(4, r15), r3
    shll r0
    add r3, r0
    mov.l r0, @-r15
    mov.l @(4, r15), r5
    jsr @r14
    mov r11, r4
    neg r0, r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    shar r0
    extu.w r0, r0
    and r9, r0
    extu.w r0, r0
    mov.l @r15+, r3
    mov.w r0, @r3
    bra     .L_opt_next_entry_b
    nop
.L_opt_not_visible_b:
    mov r10, r0
    shll r0
    mov.l @(4, r15), r3
    add r3, r0
.L_opt_write_default_b:
    extu.w r12, r2
    mov.w r2, @r0
.L_opt_next_entry_b:
    add #0x1, r10
.L_opt_palette_check_b:
    mov.l @(20, r15), r3
    mov.l @r3, r3
    cmp/hs r3, r10
    bf      .L_opt_palette_loop_b
.L_opt_mark_ready:
    extu.w r13, r13
    shll r13
    mov.l   .L_scene_ready_opt, r3
    add r3, r13
    mov #0x1, r2
    mov.w r2, @r13
.L_opt_return:
    add #0x34, r15
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global display_channel_handler
    .type display_channel_handler, @function
display_channel_handler:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x24, r15
    mov.l r4, @r15
    mov.l   .L_display_mode_dch, r0
    bra     .L_dch_dispatch
    mov.l @r0, r0
.L_dch_mode_1:
    bra     .L_dch_build_matrix
    mov #0x0, r10
.L_dch_mode_2:
    bra     .L_dch_build_matrix
    mov #0x1, r10
.L_dch_mode_default:
    bra     .L_dch_return
    nop
.L_dch_dispatch:
    cmp/eq #0x1, r0
    bt      .L_dch_mode_1
    cmp/eq #0x2, r0
    bt      .L_dch_mode_2
    bra     .L_dch_mode_default
    nop
    .2byte  0xFFFF
.L_scene_ready_opt:
    .4byte  sym_060A4C40
.L_display_mode_dch:
    .4byte  sym_060635A8
.L_dch_build_matrix:
    mov.l   .L_fn_scene_inv_a, r3
    jsr @r3
    mov.l @r15, r4
    mov r0, r13
    mov.l   .L_fn_scene_inv_b, r3
    jsr @r3
    mov.l @r15, r4
    mov r0, r11
    exts.b r10, r12
    mov r12, r3
    shll2 r12
    shll2 r3
    shll2 r3
    shll r3
    add r3, r12
    exts.b r12, r12
    mov.l   .L_color_matrix_dch, r2
    add r2, r12
    mov.l @r12, r9
    mov r12, r8
    add #0x4, r8
    mov.l @r8, r3
    mov.l r3, @(12, r15)
    mov r12, r3
    add #0xC, r3
    mov.l r3, @r15
    mov.l @r3, r1
    mov.l r1, @(24, r15)
    mov r12, r1
    add #0x10, r1
    mov.l r1, @(16, r15)
    mov.l @r1, r2
    mov.l r2, @(20, r15)
    mov r12, r2
    add #0x18, r2
    mov.l r2, @(32, r15)
    mov.l @r2, r3
    mov.l r3, @(8, r15)
    mov r12, r3
    add #0x1C, r3
    mov r11, r5
    mov.l r3, @(28, r15)
    mov.l @r3, r1
    mov.l r1, @(4, r15)
    mov.l   .L_fn_scene_update_dch, r14
    jsr @r14
    mov r9, r4
    mov.l r0, @-r15
    mov r13, r5
    jsr @r14
    mov.l @(16, r15), r4
    mov.l @r15+, r3
    mov r13, r5
    add r3, r0
    mov.l r0, @r12
    jsr @r14
    mov r9, r4
    neg r0, r0
    mov r11, r5
    mov.l r0, @-r15
    jsr @r14
    mov.l @(16, r15), r4
    mov r11, r5
    mov.l @r15+, r3
    add r3, r0
    mov.l r0, @r8
    mov.l @r15, r2
    mov.l r2, @-r15
    jsr @r14
    mov.l @(28, r15), r4
    mov r13, r5
    mov.l r0, @-r15
    jsr @r14
    mov.l @(28, r15), r4
    mov r13, r5
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @(16, r15), r3
    mov.l r3, @-r15
    jsr @r14
    mov.l @(28, r15), r4
    neg r0, r0
    mov r11, r5
    mov.l r0, @-r15
    jsr @r14
    mov.l @(28, r15), r4
    mov r11, r5
    mov.l @r15+, r3
    add r3, r0
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @(32, r15), r3
    mov.l r3, @-r15
    jsr @r14
    mov.l @(12, r15), r4
    mov.l r0, @-r15
    mov r13, r5
    jsr @r14
    mov.l @(12, r15), r4
    mov.l @r15+, r3
    mov r13, r5
    add r3, r0
    mov.l @r15+, r2
    mov.l r0, @r2
    mov.l @(28, r15), r3
    mov.l r3, @-r15
    jsr @r14
    mov.l @(12, r15), r4
    neg r0, r0
    mov r11, r5
    mov.l r0, @-r15
    jsr @r14
    mov.l @(12, r15), r4
    mov.l @r15+, r3
    extu.w r10, r4
    add r3, r0
    mov.l @r15+, r2
    shll2 r4
    mov.l r0, @r2
    shll2 r4
    shll2 r4
    shll r4
    mov.l   .L_view_matrix_dch, r3
    add r3, r4
    mov.l @r12, r2
    mov.l r2, @(28, r4)
    mov.l @r8, r3
    mov.l r3, @(32, r4)
    mov.l @r15, r2
    mov.l @r2, r3
    mov.l r3, @(40, r4)
    mov.l @(16, r15), r2
    mov.l @r2, r3
    mov.l r3, @(44, r4)
.L_dch_return:
    add #0x24, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_fn_scene_inv_a:
    .4byte  scene_invalidate_a
.L_fn_scene_inv_b:
    .4byte  scene_invalidate_b
.L_color_matrix_dch:
    .4byte  sym_060A53B8
.L_fn_scene_update_dch:
    .4byte  display_scene_update
.L_view_matrix_dch:
    .4byte  sym_060A3E68

    .global hud_update_main
    .type hud_update_main, @function
hud_update_main:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    mov #0x0, r8
    mov.l   .L_view_transform_hud, r11
    mov.l   .L_display_mode_hud, r0
    bra     .L_hud_dispatch
    mov.l @r0, r0
.L_hud_mode_1:
    bra     .L_hud_check_active
    extu.w r8, r14
.L_hud_mode_2:
    bra     .L_hud_check_active
    mov #0x1, r14
.L_hud_mode_default:
    bra     .L_hud_return
    nop
.L_hud_dispatch:
    cmp/eq #0x1, r0
    bt      .L_hud_mode_1
    cmp/eq #0x2, r0
    bt      .L_hud_mode_2
    bra     .L_hud_mode_default
    nop
.L_hud_check_active:
    extu.w r14, r5
    mov.l   .L_scene_dirty_hud, r3
    shll2 r5
    add r5, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_hud_add_rotation
    mov.l   .L_view_offset_hud, r3
    add r5, r3
    mov.l @r3, r0
    tst r0, r0
    bf      .L_hud_clear_transform
    mov.l   .L_view_pending_hud, r3
    add r5, r3
    mov.l @r3, r0
    tst r0, r0
    bt      .L_hud_add_rotation
.L_hud_clear_transform:
    extu.w r14, r0
    shll2 r0
    bra     .L_hud_return
    mov.l r8, @(r0, r11)
    .2byte  0xFFFF
.L_view_transform_hud:
    .4byte  sym_060A4C70
.L_display_mode_hud:
    .4byte  sym_060635A8
.L_scene_dirty_hud:
    .4byte  sym_060A4C4C
.L_view_offset_hud:
    .4byte  sym_060A4C60
.L_view_pending_hud:
    .4byte  sym_060A4C78
.L_hud_add_rotation:
    extu.w r14, r5
    shll2 r5
    add r11, r5
    mov.l @r5, r3
    add r4, r3
    mov r3, r2
    mov.l r3, @r5
    mov.l   .L_fp_360_hud, r3
    cmp/ge r3, r2
    bf      .L_hud_check_negative
    extu.w r14, r0
    shll2 r0
    mov.l   .L_fp_360_hud, r3
    mov.l @(r0, r11), r2
    sub r3, r2
    mov.l r2, @(r0, r11)
.L_hud_check_negative:
    extu.w r14, r0
    shll2 r0
    mov.l @(r0, r11), r3
    cmp/pz r3
    bt      .L_hud_build_matrix
    extu.w r14, r0
    shll2 r0
    mov.l   .L_fp_360_hud, r3
    mov.l @(r0, r11), r2
    add r3, r2
    mov.l r2, @(r0, r11)
.L_hud_build_matrix:
    extu.w r14, r12
    mov.l   .L_view_matrix_hud, r3
    extu.w r14, r9
    mov.l   .L_fn_scene_update_hud, r10
    shll2 r12
    shll2 r9
    shll2 r12
    mov r9, r13
    shll2 r12
    add r11, r13
    shll r12
    add r3, r12
    mov.l   .L_projection_params_hud, r3
    add r9, r3
    mov.l r3, @(4, r15)
    mov.l @r3, r2
    mov.l r2, @(8, r15)
    mov.l   .L_fn_scene_inv_b_hud, r2
    jsr @r2
    mov.l @r13, r4
    mov r0, r4
    jsr @r10
    mov.l @(8, r15), r5
    mov.l @(8, r15), r3
    sub r0, r3
    mov.l r3, @-r15
    mov.l   .L_projection_params_hud2, r3
    add r9, r3
    mov.l r3, @(4, r15)
    mov.l @r3, r1
    mov.l r1, @-r15
    mov.l   .L_fn_scene_inv_a_hud, r2
    jsr @r2
    mov.l @r13, r4
    neg r0, r4
    jsr @r10
    mov.l @r15+, r5
    mov.l @r15+, r3
    sub r0, r3
    mov.l r3, @r12
    mov.l @r15, r2
    mov.l @r2, r3
    mov.l r3, @-r15
    mov.l @(8, r15), r5
    mov.l @r5, r1
    mov.l r1, @-r15
    mov.l   .L_fn_scene_inv_a_hud, r3
    jsr @r3
    mov.l @r13, r4
    mov r0, r4
    jsr @r10
    mov.l @r15+, r5
    mov.l @r15+, r2
    sub r0, r2
    mov.l r2, @-r15
    mov.l @(4, r15), r5
    mov.l @r5, r1
    mov.l r1, @-r15
    mov.l   .L_fn_scene_inv_b_hud, r3
    jsr @r3
    mov.l @r13, r4
    mov r0, r4
    jsr @r10
    mov.l @r15+, r5
    mov.l @r15+, r3
    sub r0, r3
    mov.l r3, @(4, r12)
    mov.l r8, @(8, r12)
    mov.l   .L_fn_scene_inv_a_hud, r3
    jsr @r3
    mov.l @r13, r4
    neg r0, r0
    mov.l r0, @(12, r12)
    mov.l   .L_fn_scene_inv_b_hud, r3
    jsr @r3
    mov.l @r13, r4
    mov.l r0, @(16, r12)
    mov.l   .L_fn_scene_inv_b_hud, r3
    jsr @r3
    mov.l @r13, r4
    mov.l r0, @(20, r12)
    mov.l   .L_fn_scene_inv_a_hud, r3
    jsr @r3
    mov.l @r13, r4
    mov.l r0, @(24, r12)
.L_hud_return:
    add #0xC, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_fp_360_hud:
    .4byte  0x01680000                  /* 360.0 (16.16 fixed-point) */
.L_fn_scene_update_hud:
    .4byte  display_scene_update
.L_view_matrix_hud:
    .4byte  sym_060A3E68
.L_projection_params_hud:
    .4byte  sym_060A53A8
.L_fn_scene_inv_b_hud:
    .4byte  scene_invalidate_b
.L_projection_params_hud2:
    .4byte  sym_060A53B0
.L_fn_scene_inv_a_hud:
    .4byte  scene_invalidate_a
