
    .section .text.FUN_0602F5B6


    .global color_material_blend
    .type color_material_blend, @function
color_material_blend:
    sts.l pr, @-r15
    mov r0, r14
    mov.w   DAT_0602f5e8, r1
    mov.l @(r0, r1), r2
    .byte   0xD3, 0x0B    /* mov.l _pool_weight_table_a, r3 */
    shll2 r2
    .byte   0xD4, 0x0B    /* mov.l _pool_blend_factor, r4 */
    add r2, r3
    mov.l @r3, r5
    dmuls.l r4, r5
    .byte   0xD1, 0x0A    /* mov.l _pool_blend_bias, r1 */
    sts mach, r4
    sts macl, r5
    xtrct r4, r5
    sub r1, r5
    mov r5, r1
    mov.w   DAT_0602f5ea, r11
    mov.l @(r0, r11), r5
    .byte   0xD3, 0x07    /* mov.l _pool_clamp_lower, r3 */
    .byte   0xD4, 0x07    /* mov.l _pool_clamp_upper, r4 */
    cmp/gt r3, r5
    bt      .L_check_upper_clamp
    mov r3, r5
    bra     .L_after_clamp
    nop

    .global DAT_0602f5e8
DAT_0602f5e8:
    .2byte  0x0068                      /* car+0x68: heading index */

    .global DAT_0602f5ea
DAT_0602f5ea:
    .2byte  0x00E0                      /* car+0xE0: drive_speed (16.16 FP) */
_pool_weight_table_a:
    .4byte  sym_06045AEC               /* weight table (per-car type) */
_pool_blend_factor:
    .4byte  0x00016666                  /* ~1.4 in 16.16 FP (blend multiplier) */
_pool_blend_bias:
    .4byte  0x00006666                  /* ~0.4 in 16.16 FP (blend bias) */
_pool_clamp_lower:
    .4byte  0x00000000                  /* lower clamp bound (0) */
_pool_clamp_upper:
    .4byte  0x00002134                  /* upper clamp bound (8500 decimal) */
.L_check_upper_clamp:
    cmp/gt r5, r4
    bt      .L_after_clamp
    mov r4, r5
.L_after_clamp:
    shlr2 r5
    shlr2 r5
    shlr2 r5
    shlr r5
    mov.w   DAT_0602f6e0, r2
    mov.w @(r0, r2), r4
    mov.w   DAT_0602f6e2, r2
    mov.l @(r0, r2), r6
    shll2 r5
    .byte   0xD7, 0x37    /* mov.l _pool_material_table, r7 */
    shll2 r4
    add r5, r6
    add r4, r7
    mov.l @r6, r5
    mov.l @r7, r4
    dmuls.l r4, r5
    sts mach, r4
    sts macl, r0
    xtrct r4, r0
    dmuls.l r0, r1
    sts mach, r4
    sts macl, r2
    xtrct r4, r2
    mov r14, r0
    mov.w   DAT_0602f6e4, r1
    .byte   0xD5, 0x30    /* mov.l _pool_fog_divisor, r5 */
    mov.l @(r0, r1), r4
    shll16 r4
    .byte   0xD0, 0x30    /* mov.l _pool_fn_fpdiv, r0 */
    jsr @r0
    mov.l r2, @-r15
    mov r0, r4
    mov.l @r15+, r2
    mov r14, r0
    mov.w   DAT_0602f6e6, r1
    sub r4, r2
    mov.l r2, @(r0, r1)
    mov.w   DAT_0602f6e8, r1
    mov.l @(r0, r1), r2
    .byte   0xD3, 0x2B    /* mov.l _pool_weight_table_b, r3 */
    shll2 r2
    add r2, r3
    mov.l @r3, r4
    .byte   0xD7, 0x2A    /* mov.l _pool_weight_70pct, r7 */
    .byte   0xD8, 0x2B    /* mov.l _pool_weight_50pct, r8 */
    mov r4, r5
    dmuls.l r4, r5
    sts mach, r4
    sts macl, r0
    xtrct r4, r0
    mov r0, r10
    mov r0, r4
    mov r7, r5
    dmuls.l r4, r5
    sts mach, r4
    sts macl, r0
    xtrct r4, r0
    mov r10, r4
    mov r0, r10
    dmuls.l r4, r8
    sts mach, r8
    sts macl, r4
    xtrct r8, r4
    mov r14, r0
    mov.w   DAT_0602f6ea, r1
    mov.l r10, @(r0, r1)
    mov.w   DAT_0602f6ec, r2
    mov.l r4, @(r0, r2)
    mov #0x0, r10
    mov.w   DAT_0602f6ee, r1
    mov.l @(r0, r1), r4
    cmp/ge r4, r10
    bt      .L_after_vert_adjust
    shar r4
.L_after_vert_adjust:
    .byte   0xD5, 0x1D    /* mov.l _pool_heading_factor, r5 */
    .byte   0xD0, 0x1D    /* mov.l _pool_fn_sin_lookup, r0 */
    jsr @r0
    nop
    dmuls.l r0, r5
    sts mach, r4
    sts macl, r0
    xtrct r4, r0
    shar r0
    mov r0, r8
    mov.w   DAT_0602f6f0, r1
    mov r14, r0
    mov.l r8, @(r0, r1)
    mov.l @(8, r0), r3
    .byte   0xD1, 0x18    /* mov.l _pool_accel_curve, r1 */
    shll2 r3
    add r3, r1
    mov.l @r1, r5
    mov.w   DAT_0602f6f2, r2
    mov.w @(r0, r2), r3
    cmp/pl r3
    bf      .L_skip_fog_scale
    mov.w   DAT_0602f6f4, r4
    dmuls.l r4, r5
    sts mach, r4
    sts macl, r5
    xtrct r4, r5
.L_skip_fog_scale:
    bsr     .L_activation_weight_calc
    nop
    add r4, r5
    shar r5
    mov.w   DAT_0602f6f6, r1
    lds.l @r15+, pr
    rts
    mov.l r5, @(r0, r1)

    .global DAT_0602f6e0
DAT_0602f6e0:
    .2byte  0x00DC                      /* car+0xDC: display_flag (table column index) */

    .global DAT_0602f6e2
DAT_0602f6e2:
    .2byte  0x00C8                      /* car+0xC8: color_base (row pointer) */

    .global DAT_0602f6e4
DAT_0602f6e4:
    .2byte  0x00E8                      /* car+0xE8: light_param (fog numerator) */

    .global DAT_0602f6e6
DAT_0602f6e6:
    .2byte  0x011C                      /* car+0x11C: decel_coeff (fog-adjusted output) */

    .global DAT_0602f6e8
DAT_0602f6e8:
    .2byte  0x0084                      /* car+0x84: secondary_speed index */

    .global DAT_0602f6ea
DAT_0602f6ea:
    .2byte  0x00EC                      /* car+0xEC: blend_result_a (70% output) */

    .global DAT_0602f6ec
DAT_0602f6ec:
    .2byte  0x00F0                      /* car+0xF0: blend_result_b (50% output) */

    .global DAT_0602f6ee
DAT_0602f6ee:
    .2byte  0x001C                      /* car+0x1C: vertical_pos */

    .global DAT_0602f6f0
DAT_0602f6f0:
    .2byte  0x00F4                      /* car+0xF4: force_aux (heading contribution) */

    .global DAT_0602f6f2
DAT_0602f6f2:
    .2byte  0x00D6                      /* car+0xD6: fog_timer (countdown) */

    .global DAT_0602f6f4
DAT_0602f6f4:
    .2byte  0x7333                      /* ~0.45 in 16.16 FP (fog scale factor) */

    .global DAT_0602f6f6
DAT_0602f6f6:
    .2byte  0x00F8                      /* car+0xF8: final blend output */
_pool_material_table:
    .4byte  sym_060477BC               /* material/reflectance lookup table */
_pool_fog_divisor:
    .4byte  0x00019999                  /* ~1.6 in 16.16 FP (fog divisor) */
_pool_fn_fpdiv:
    .4byte  fpdiv_setup                /* 16.16 fixed-point hardware divide */
_pool_weight_table_b:
    .4byte  sym_06045AEC               /* weight table (per-car type, 2nd ref) */
_pool_weight_70pct:
    .4byte  0x0B400000                  /* 70% blend factor (16.16 FP) */
_pool_weight_50pct:
    .4byte  0x07800000                  /* 50% blend factor (16.16 FP) */
_pool_heading_factor:
    .4byte  0x06400000                  /* heading angle factor (16.16 FP) */
_pool_fn_sin_lookup:
    .4byte  sin_lookup                 /* sine table lookup function */
_pool_accel_curve:
    .4byte  sym_060454CC               /* acceleration curve table B */
.L_activation_weight_calc:
    mov #0x0, r4
    mov.w   _wpool_flag_bit_mask, r3
    mov.w   _wpool_flag_base_offset, r1
    add r0, r1
    mov.l @r1, r2
    tst r3, r2
    mov r2, r12
    bt      .L_check_slot_1
    add #0x1, r4
.L_check_slot_1:
    mov.l @(4, r1), r2
    tst r3, r2
    or r2, r12
    bt      .L_check_slot_2
    add #0x1, r4
.L_check_slot_2:
    mov.l @(8, r1), r2
    tst r3, r2
    or r2, r12
    bt      .L_check_slot_3
    add #0x1, r4
.L_check_slot_3:
    mov.l @(12, r1), r2
    tst r3, r2
    or r2, r12
    bt      .L_after_flag_scan
    add #0x1, r4
.L_after_flag_scan:
    tst r4, r4
    bt      .L_return_halved
    mov #0x10, r1
    tst r1, r12
    bf      .L_return_zero_weight
    mov.w   _wpool_render_type_offset, r1
    mov.w @(r0, r1), r2
    mov #0xA, r1
    cmp/ge r1, r2
    bt      .L_return_zero_weight
    mov #0x8, r1
    cmp/ge r1, r2
    bt      .L_return_doubled_weight
    mov #0x4, r1
    cmp/eq r1, r2
    bt      .L_return_zero_weight
    mov #0x5, r1
    cmp/eq r1, r2
    bt      .L_return_zero_weight
    mov #0x2, r7
    cmp/ge r4, r7
    bt      .L_use_table_b
    mov.l @(8, r0), r2
    .byte   0xD3, 0x04    /* mov.l _pool_weight_tbl_a, r3 */
    shll2 r2
    add r2, r3
    mov.l @r3, r4
    rts
    shar r4
_wpool_flag_bit_mask:
    .2byte  0x0004                      /* bit mask: activation flag bit 2 */
_wpool_flag_base_offset:
    .2byte  0x0120                      /* car+0x120: activation flag array base */
_wpool_render_type_offset:
    .2byte  0x007C                      /* car+0x7C: render type selector */
_pool_weight_tbl_a:
    .4byte  sym_0604679C               /* weight table A (high-count path) */
.L_use_table_b:
    mov.l @(8, r0), r2
    .byte   0xD3, 0x03    /* mov.l _pool_weight_tbl_b, r3 */
    shll2 r2
    add r2, r3
    mov.l @r3, r4
.L_return_halved:
    rts
    shar r4
    .2byte  0x0000                      /* alignment padding */
_pool_weight_tbl_b:
    .4byte  sym_06046F9C               /* weight table B (low-count path) */
.L_return_zero_weight:
    rts
    mov #0x0, r4
.L_return_doubled_weight:
    mov.l @(8, r0), r2
    .byte   0xD3, 0x03    /* mov.l _pool_weight_tbl_a_dup, r3 */
    shll2 r2
    add r2, r3
    mov.l @r3, r4
    rts
    shll r4
    .2byte  0x0000                      /* alignment padding */
_pool_weight_tbl_a_dup:
    .4byte  sym_0604679C               /* weight table A (doubled path, dup) */

    .global sym_0602F7BC
sym_0602F7BC:
    mov.w   DAT_0602f7e4, r1
    mov.w @(r0, r1), r2
    tst r2, r2
    bt      .L_check_timer_b
    add #-0x1, r2
    mov.w r2, @(r0, r1)
.L_check_timer_b:
    mov.w   DAT_0602f7e6, r1
    mov.w @(r0, r1), r2
    tst r2, r2
    bt      .L_check_timer_c
    add #-0x1, r2
    mov.w r2, @(r0, r1)
.L_check_timer_c:
    mov.w   DAT_0602f7e8, r1
    mov.l @(r0, r1), r2
    tst r2, r2
    bt      .L_timers_done
    add #-0x1, r2
    mov.l r2, @(r0, r1)
.L_timers_done:
    rts
    nop

    .global DAT_0602f7e4
DAT_0602f7e4:
    .2byte  0x0166                      /* car+0x166: timer A (anim frame counter) */

    .global DAT_0602f7e6
DAT_0602f7e6:
    .2byte  0x0152                      /* car+0x152: timer B (effect duration) */

    .global DAT_0602f7e8
DAT_0602f7e8:
    .2byte  0x0208                      /* car+0x208: timer C (extended cooldown) */
