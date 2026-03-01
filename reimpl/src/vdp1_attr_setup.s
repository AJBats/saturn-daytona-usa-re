
    .section .text.FUN_0602CCEC


    .global vdp1_attr_setup
    .type vdp1_attr_setup, @function
vdp1_attr_setup:
    sts.l pr, @-r15
    mov #0x0, r7
    mov.l @(8, r14), r3
    cmp/pl r3
    bf      .L_clamp_and_store
    mov.w   .L_max_speed_hi, r5
    mov.w   .L_off_drive_speed, r1
    shll16 r5
    mov.l @(r0, r1), r3
    shll16 r3
    mov r5, r4
    sub r3, r4
    mov.w   .L_off_decel_coeff, r2
    mov.l   .L_fpdiv_setup_ptr, r13
    jsr @r13
    mov.l @(r0, r2), r6
    dmuls.l r0, r6
    mov.w   .L_off_persp_scale, r1
    mov.w   .L_off_intensity, r2
    sts mach, r0
    sts macl, r4
    xtrct r0, r4
    add r14, r1
    add r14, r2
    mov.l @r1, r5
    mov.l @r2, r6
    dmuls.l r6, r5
    sts mach, r6
    sts macl, r5
    xtrct r6, r5
    mov.w   .L_off_display_flag, r1
    add r14, r1
    jsr @r13
    mov.w @r1, r7
    mov.w   .L_off_render_type, r4
    mov.l   .L_attr_table_base, r1
    add r14, r4
    mov.w @r4, r4
    mov #0xA, r5
    cmp/ge r5, r4
    bt      .L_check_scale_min
    mov #0x2, r5
    cmp/eq r5, r4
    bt      .L_check_scale_min
    add #0x1, r5
    cmp/eq r5, r4
    bf      .L_table_lookup
.L_check_scale_min:
    mov #0x2, r5
    cmp/ge r7, r5
    bt      .L_clamp_and_store
.L_table_lookup:
    shll2 r4
    shll r7
    shll r4
    add r1, r7
    add r4, r7
    mov.w @r7, r4
    mov #0x0, r7
    extu.w r4, r4
    mov r0, r5
    mov.l r4, @-r15
    jsr @r13
    mov.l r5, @-r15
    mov.w   .L_off_attr_result, r1
    add r14, r1
    mov.l r0, @r1
    mov.l @r15+, r5
    mov.l @r15+, r4
    cmp/gt r5, r4
    bt      .L_clamp_and_store
    .byte   0xB5, 0x35    /* bsr 0x0602D7E4 (external) */
    mov r14, r0
    mov.w   .L_off_render_mode, r1
    add r14, r1
    mov.w @r1, r2
    cmp/pl r2
    bt      .L_clamp_and_store
    mov.w   .L_off_drive_speed, r1
    add r14, r1
    mov.l @r1, r7
    mov r7, r4
    mov.l   .L_depth_scale_fp, r5
    shll r7
    shll16 r4
    mov.w   .L_off_depth_offset, r6
    jsr @r13
    add r14, r6
    mov.l r0, @r6
.L_clamp_and_store:
    mov r14, r0
    mov.w   .L_off_persp_scale, r1
    mov.w   .L_off_depth_offset, r2
    mov.l @(r0, r1), r3
    mov.l @(r0, r2), r4
    sub r4, r3
    mov #0x1, r5
    mov.w   .L_min_depth_threshold, r6
    shll16 r5
    cmp/gt r6, r3
    bt      .L_clamp_upper
    mov r6, r3
    bra     .L_apply_depth_offset
    nop
.L_max_speed_hi:
    .2byte  0x2134               /* 0x2134 = max drive speed (high 16 bits) */
.L_off_drive_speed:
    .2byte  0x00E0               /* car+0xE0 = drive_speed (longword, 16.16 FP) */
.L_off_decel_coeff:
    .2byte  0x011C               /* car+0x11C = decel_coeff (longword, 16.16 FP) */
.L_off_persp_scale:
    .2byte  0x010C               /* car+0x10C = perspective_scale (longword, 16.16 FP) */
.L_off_intensity:
    .2byte  0x0144               /* car+0x144 = color intensity (longword, 16.16 FP) */
.L_off_display_flag:
    .2byte  0x00DC               /* car+0xDC = display flag (word, table column index) */
.L_off_render_type:
    .2byte  0x007C               /* car+0x7C = render type (word, table row selector) */
.L_off_attr_result:
    .2byte  0x0264               /* car+0x264 = attr_result output (longword) */
.L_off_render_mode:
    .2byte  0x016C               /* car+0x16C = render_mode timer (word) */
.L_off_depth_offset:
    .2byte  0x0110               /* car+0x110 = depth_offset (longword, 16.16 FP) */
.L_min_depth_threshold:
    .2byte  0x2B85               /* 0x2B85 = 11141 (minimum net depth, signed) */
.L_fpdiv_setup_ptr:
    .4byte  fpdiv_setup          /* 16.16 fixed-point hardware divide (r4/r5 -> r0) */
.L_attr_table_base:
    .4byte  sym_0602E938         /* attr threshold table base (rows=type, cols=flag) */
.L_depth_scale_fp:
    .4byte  0x23280000           /* 0x23280000 = large FP denominator for depth calc */
.L_clamp_upper:
    cmp/ge r3, r5
    bt      .L_apply_depth_offset
    mov r5, r3
.L_apply_depth_offset:
    cmp/pz r4
    bf      .L_store_results
    mov.w   .L_depth_decay_step, r5
    sub r5, r4
    mov.l r4, @(r0, r2)
.L_store_results:
    mov.l r3, @(r0, r1)
    mov.w   .L_off_draw_param, r2
    lds.l @r15+, pr
    rts
    mov.l r7, @(r0, r2)
.L_depth_decay_step:
    .2byte  0x05C2               /* 0x05C2 = 1474 (depth offset decay per frame) */
.L_off_draw_param:
    .2byte  0x00C0               /* car+0xC0 = draw_param output (longword) */
