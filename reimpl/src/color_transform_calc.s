
    .section .text.FUN_06039100


    .global color_transform_calc
    .type color_transform_calc, @function
color_transform_calc:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   .L_fn_vblank_color_apply, r11
    mov.l   .L_color_buf_ptr, r14
    mov.l r5, @(4, r15)
    mov r6, r13
    mov.l r7, @r15
    mov #0x0, r5
    bra     .L_channel_dispatch
    extu.b r4, r0
.L_setup_scene_a:
    mov.l r5, @(24, r14)
    mov r14, r4
    add r5, r4
    mov r14, r2
    add #0x4, r2
    add r2, r5
    mov #0x2, r3
    mov r3, r0
    mov.b r0, @(8, r15)
    mov.w   DAT_0603918c, r8
    mov #0x1, r9
    mov r8, r10
    bra     .L_store_color_words
    add #0x1, r10
.L_setup_scene_b:
    mov.l r5, @(28, r14)
    mov r14, r4
    add #0x8, r4
    add r5, r4
    mov r14, r2
    add #0xC, r2
    add r2, r5
    mov #0x8, r3
    mov r3, r0
    mov.b r0, @(8, r15)
    mov.w   DAT_0603918e, r8
    mov #0x4, r9
    mov r8, r10
    bra     .L_store_color_words
    add #0x4, r10
.L_early_exit:
    bra     .L_epilogue
    nop
.L_channel_dispatch:
    cmp/eq #0x0, r0
    bt      .L_setup_scene_a
    cmp/eq #0x1, r0
    bt      .L_setup_scene_b
    bra     .L_early_exit
    nop
.L_store_color_words:
    mov r14, r12
    mov.l   .L_screen_width_ptr, r2
    mov.w   .L_hires_threshold, r3
    mov.w @r2, r2
    extu.w r2, r2
    cmp/gt r3, r2
    bf/s    .L_normal_res_double
    add #0x10, r12
    mov #0x2E, r0
    mov.w @(r0, r15), r3
    mov.w r3, @r4
    mov #0x36, r0
    mov.w @(r0, r15), r3
    mov.w r3, @r5
    bra     .L_store_second_pair
    nop

    .global DAT_0603918c
DAT_0603918c:
    .2byte  0x00FD

    .global DAT_0603918e
DAT_0603918e:
    .2byte  0x00F7
.L_hires_threshold:
    .2byte  0x0160
    .2byte  0xFFFF
.L_fn_vblank_color_apply:
    .4byte  vblank_color_apply
.L_color_buf_ptr:
    .4byte  sym_060A3E48
.L_screen_width_ptr:
    .4byte  sym_060635AE
.L_normal_res_double:
    mov #0x2E, r0
    mov.w @(r0, r15), r2
    mov #0x36, r0
    extu.w r2, r2
    shll r2
    extu.w r2, r2
    mov.w r2, @r4
    mov.w @(r0, r15), r3
    extu.w r3, r3
    shll r3
    extu.w r3, r3
    mov.w r3, @r5
.L_store_second_pair:
    mov #0x32, r0
    mov.w @(r0, r15), r0
    mov.w r0, @(2, r4)
    mov #0x3A, r0
    mov.w @(r0, r15), r0
    mov.w r0, @(2, r5)
    mov.l @(4, r15), r3
    or r13, r3
    tst r3, r3
    bt      .L_skip_first_apply
    mov #0x7F, r3
    mov r12, r6
    mov r13, r5
    mov.l r3, @-r15
    mov.w   .L_or_value_0x80, r7
    jsr @r11
    mov.l @(8, r15), r4
    add #0x4, r15
.L_skip_first_apply:
    mov.l @r15, r3
    or r13, r3
    tst r3, r3
    bt      .L_skip_second_apply
    mov r9, r7
    mov r12, r6
    mov r13, r5
    mov.l r10, @-r15
    jsr @r11
    mov.l @(4, r15), r4
    add #0x4, r15
.L_skip_second_apply:
    mov r12, r6
    mov #-0x1, r5
    mov.l r8, @-r15
    mov.b @(12, r15), r0
    mov r0, r7
    jsr @r11
    mov r13, r4
    mov.l   .L_enable_flags_ptr, r4
    mov.l   .L_fp_one_mask, r3
    and r3, r13
    tst r13, r13
    bt/s    .L_copy_enable_flags
    add #0x4, r15
    mov #0x3, r3
    mov.w r3, @r4
    bra     .L_check_ready_flag
    nop
.L_copy_enable_flags:
    mov.l   .L_ctrl_config_ptr, r2
    mov.w @r2, r2
    mov.w r2, @r4
.L_check_ready_flag:
    mov.l   .L_scene_ready_flag_ptr, r4
    mov.w @r4, r3
    extu.w r3, r3
    tst r3, r3
    bf      .L_epilogue
    mov #0x1, r3
    mov.w r3, @r4
.L_epilogue:
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
.L_or_value_0x80:
    .2byte  0x0080
    .2byte  0xFFFF
.L_enable_flags_ptr:
    .4byte  sym_060A3E38
.L_fp_one_mask:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) / bit 16 mask */
.L_ctrl_config_ptr:
    .4byte  sym_060A4C80
.L_scene_ready_flag_ptr:
    .4byte  sym_060635AC
