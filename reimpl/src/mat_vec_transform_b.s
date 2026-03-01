
    .section .text.FUN_060272C0


    .global mat_vec_transform_b
    .type mat_vec_transform_b, @function
mat_vec_transform_b:
    mov.l r14, @-r15
    mov.l   .L_pool_mat_b_stack_ptr, r0
    mov #0x24, r7
    mov.l @r0, r6
    mov.l   .L_pool_output_buf_b, r14
    add r6, r7
    mov #0x3, r3
.L_transform_row_loop:
    clrmac
    mac.l @r4+, @r6+
    mac.l @r4+, @r6+
    mov.l @r7+, r2
    mac.l @r4+, @r6+
    dt r3
    add #-0xC, r4
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    add r2, r1
    mov.l r1, @r14
    bf/s    .L_transform_row_loop
    add #0x4, r14
    add #-0xC, r14
    mov.l @r14+, r0
    mov.l @r14+, r1
    mov.l @r14+, r2
    mov.l r0, @r5
    mov.l r1, @(4, r5)
    mov.l r2, @(8, r5)
    rts
    mov.l @r15+, r14

    .4byte  0xD00BD60F
    .4byte  0x6202E303
    .4byte  0x0028024F
    .4byte  0x024F024F
    .4byte  0x431074F4
    .4byte  0x000A011A
    .4byte  0x210D2612
    .4byte  0x8FF47604
    .4byte  0x76F46062
    .4byte  0x51615262
    .4byte  0x25021511
    .4byte  0x000B1522
.L_pool_mat_b_stack_ptr:
    .4byte  sym_0608A52C
    .4byte  sym_0608A530
    .4byte  sym_0608A6B0
    .4byte  sym_0608A6C0
.L_pool_output_buf_b:
    .4byte  sym_0608A6F0
    .4byte  0x00010000

    .global cos_lookup
cos_lookup:
    .byte   0x90, 0xDA    /* mov.w .L_wpool_cos_phase, r0 ! r0 = 0x4000 (90 deg phase) */
    add r0, r4

    .global sin_lookup
sin_lookup:
    .byte   0x90, 0xD9    /* mov.w .L_wpool_trig_mask, r0 ! r0 = 0x3FFC (table mask) */
    shlr2 r4
    add #0x2, r4
    and r0, r4
    .byte   0xD0, 0x66    /* mov.l .L_pool_sincos_table, r0 ! r0 = 0x002F2F20 (ROM table) */
    rts
    mov.l @(r0, r4), r0
    .2byte  0x0009

    .global sincos_pair
sincos_pair:
    .byte   0x93, 0xD0    /* mov.w .L_wpool_cos_phase, r3 ! r3 = 0x4000 (cos phase) */
    add #0x8, r4
    .byte   0x91, 0xCF    /* mov.w .L_wpool_trig_mask, r1 ! r1 = 0x3FFC (table mask) */
    add r4, r3
    .byte   0xD0, 0x62    /* mov.l .L_pool_sincos_table, r0 ! r0 = 0x002F2F20 (table base) */
    shlr2 r4
    and r1, r4
    shlr2 r3
    mov.l @(r0, r4), r2
    and r1, r3
    mov.l r2, @r5
    nop
    mov.l @(r0, r3), r1
    rts
    mov.l r1, @r6
    .2byte  0x0009

    .global atan_piecewise
atan_piecewise:
    cmp/pz r4
    bt/s    .L_abs_done
    .word 0x0629
    neg r4, r4
.L_abs_done:
    mov #0x10, r0
    shll16 r0
    add #0x40, r4
    add #0x40, r4
    cmp/hi r4, r0
    bf      .L_large_angle
    .byte   0xD0, 0x58    /* mov.l .L_pool_atan_table, r0 ! r0 = 0x002F0000 (atan ROM table) */
    shlr8 r4
    shll r4
    tst r6, r6
    mov.w @(r0, r4), r0
    bf      .L_apply_sign
    rts
    neg r0, r0
.L_large_angle:
    .byte   0x90, 0xBB    /* mov.w .L_wpool_thresh_1000, r0 ! r0 = 0x03E8 (1000) */
    swap.w r4, r5
    extu.w r5, r5
    cmp/hi r5, r0
    bf      .L_over_1000
    .byte   0x90, 0xBB    /* mov.w .L_wpool_thresh_100, r0 ! r0 = 100 (0x0064) */
    cmp/hi r5, r0
    bt      .L_below_100
    .byte   0x90, 0xBA    /* mov.w .L_wpool_thresh_250, r0 ! r0 = 250 (0x00FA) */
    cmp/hi r5, r0
    bt      .L_range_100_250
    .byte   0x90, 0xB8    /* mov.w .L_wpool_thresh_500, r0 ! r0 = 500 (0x01F4) */
    cmp/hi r5, r0
    bt      .L_range_250_500
    .byte   0x93, 0xB5    /* mov.w .L_wpool_thresh_500, r3 ! r3 = 500 (segment base) */
    .byte   0xD1, 0x5B    /* mov.l .L_pool_slope_seg1, r1 ! r1 = slope for 500..1000 */
    .byte   0x92, 0xA2    /* mov.w .L_wpool_intercept_seg1, r2 ! r2 = intercept */
    bra     .L_interpolate
    swap.w r3, r3
.L_range_250_500:
    .byte   0x93, 0xAF    /* mov.w .L_wpool_thresh_250, r3 ! r3 = 250 (segment base) */
    .byte   0xD1, 0x59    /* mov.l .L_pool_slope_seg2, r1 ! r1 = slope for 250..500 */
    .byte   0x92, 0x9E    /* mov.w .L_wpool_intercept_seg2, r2 ! r2 = intercept */
    bra     .L_interpolate
    swap.w r3, r3
.L_range_100_250:
    .byte   0x90, 0xA9    /* mov.w .L_wpool_thresh_150, r0 ! r0 = 150 (0x0096) */
    cmp/hi r5, r0
    bt      .L_range_100_150
    .byte   0x93, 0xA6    /* mov.w .L_wpool_thresh_150, r3 ! r3 = 150 (segment base) */
    .byte   0xD1, 0x56    /* mov.l .L_pool_slope_seg3, r1 ! r1 = slope for 150..250 */
    .byte   0x92, 0x97    /* mov.w .L_wpool_intercept_seg3, r2 ! r2 = intercept */
    bra     .L_interpolate
    swap.w r3, r3
.L_range_100_150:
    .byte   0xD1, 0x55    /* mov.l .L_pool_slope_seg4, r1 ! r1 = slope for 100..150 */
    .byte   0x92, 0x94    /* mov.w .L_wpool_intercept_seg4, r2 ! r2 = intercept */
    mov #0x64, r3
    bra     .L_interpolate
    swap.w r3, r3
.L_below_100:
    .byte   0x90, 0x99    /* mov.w .L_wpool_thresh_50, r0 ! r0 = 50 (0x0032) */
    cmp/hi r5, r0
    bt      .L_below_50
    .byte   0x90, 0x97    /* mov.w .L_wpool_thresh_70, r0 ! r0 = 70 (0x0046) */
    cmp/hi r5, r0
    bt      .L_range_50_70
    .byte   0xD1, 0x51    /* mov.l .L_pool_slope_seg5, r1 ! r1 = slope for 70..100 */
    .byte   0x92, 0x8A    /* mov.w .L_wpool_intercept_seg5, r2 ! r2 = intercept */
    mov #0x46, r3
    bra     .L_interpolate
    swap.w r3, r3
.L_range_50_70:
    .byte   0xD1, 0x4F    /* mov.l .L_pool_slope_seg6, r1 ! r1 = slope for 50..70 */
    .byte   0x92, 0x86    /* mov.w .L_wpool_intercept_seg6, r2 ! r2 = intercept */
    mov #0x32, r3
    bra     .L_interpolate
    swap.w r3, r3
.L_below_50:
    .byte   0x90, 0x87    /* mov.w .L_wpool_thresh_30, r0 ! r0 = 30 (0x001E) */
    cmp/hi r5, r0
    bt      .L_range_16_30
    .byte   0x90, 0x85    /* mov.w .L_wpool_thresh_40, r0 ! r0 = 40 (0x0028) */
    cmp/hi r5, r0
    bt      .L_range_30_40
    .byte   0xD1, 0x4B    /* mov.l .L_pool_slope_seg7, r1 ! r1 = slope for 40..50 */
    .byte   0x92, 0x7C    /* mov.w .L_wpool_intercept_seg7, r2 ! r2 = intercept */
    mov #0x28, r3
    bra     .L_interpolate
    swap.w r3, r3
.L_range_30_40:
    .byte   0xD1, 0x49    /* mov.l .L_pool_slope_seg8, r1 ! r1 = slope for 30..40 */
    .byte   0x92, 0x78    /* mov.w .L_wpool_intercept_seg8, r2 ! r2 = intercept */
    mov #0x1E, r3
    bra     .L_interpolate
    swap.w r3, r3
.L_range_16_30:
    .byte   0xD1, 0x48    /* mov.l .L_pool_slope_seg9, r1 ! r1 = slope for 16..30 */
    .byte   0x92, 0x74    /* mov.w .L_wpool_intercept_seg9, r2 ! r2 = intercept */
    mov #0x10, r3
    swap.w r3, r3
.L_interpolate:
    sub r3, r4
    dmuls.l r4, r1
    sts mach, r0
    exts.w r0, r0
    tst r6, r6
    bf/s    .L_apply_sign
    add r2, r0
    neg r0, r0
.L_apply_sign:
    rts
    nop
.L_over_1000:
    .byte   0x90, 0x5B    /* mov.w .L_wpool_cos_phase, r0 ! r0 = 0x4000 (max atan = 90 deg) */
    tst r6, r6
    bf      .L_apply_sign
    rts
    neg r0, r0

    .global atan2
atan2:
    tst r5, r5
    .byte   0x8B, 0x05    /* bf 0x0602745C -- branch to atan2_full if y != 0 (external) */
    .byte   0x90, 0x54    /* mov.w .L_wpool_cos_phase, r0 ! r0 = 0x4000 (90 degrees) */
    cmp/pz r4
    bt      .L_atan2_return
    neg r0, r0
.L_atan2_return:
    rts
    nop
