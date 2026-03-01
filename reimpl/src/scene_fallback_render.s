
    .section .text.FUN_060064F2


    .global scene_fallback_render
    .type scene_fallback_render, @function
scene_fallback_render:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    sts.l pr, @-r15
    .byte   0xDB, 0x23    /* mov.l .L_fp_half, r11 */
    .byte   0xDC, 0x23    /* mov.l .L_target_eye_y_ptr, r12 */
    .byte   0xDD, 0x14    /* mov.l .L_camera_mode_ptr, r13 */
    .byte   0xDE, 0x17    /* mov.l .L_eye_y_ptr, r14 */
    .byte   0xD3, 0x20    /* mov.l .L_state_idx_ptr, r3 */
    .byte   0xD2, 0x22    /* mov.l .L_car_table_base, r2 */
    mov.l @r3, r3
    shll2 r3
    add r2, r3
    mov.l @r3, r1
    mov.l r1, @r12
    mov.l @r14, r3
    cmp/gt r11, r3
    bt/s    .L_skip_channel_5
    mov #0x1, r10
    .byte   0xD0, 0x1E    /* mov.l .L_camera_mode_byte_ptr, r0 */
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x4, r0
    bt      .L_skip_channel_5
    mov #0x5, r5
    .byte   0xD3, 0x0C    /* mov.l .L_fn_channel_nibble_config, r3 */
    jsr @r3
    mov #0x8, r4
    bra     .L_check_at_target
    nop
.L_skip_channel_5:
    mov #0x0, r5
    .byte   0xD3, 0x09    /* mov.l .L_fn_channel_nibble_config, r3 */
    jsr @r3
    mov #0x8, r4
.L_check_at_target:
    mov.l @r14, r2
    mov.l @r12, r3
    cmp/eq r3, r2
    bf      .L_interp_block
    .byte   0xD3, 0x11    /* mov.l .L_state_idx_ptr, r3 */
    mov.l @r3, r3
    mov.l r3, @r13
    bra     .L_finalize
    nop
    .4byte  0x00DCFFFF                     /* unreferenced alignment data */
    .4byte  sym_060620D0                   /* unreferenced — binary_final_func data */
.L_camera_mode_ptr:
    .4byte  sym_06063E1C                   /* &camera_mode (32-bit) */
    .4byte  sym_06059F30                   /* unreferenced — camera follow flag */
.L_fn_channel_nibble_config:
    .4byte  channel_nibble_config          /* display channel config function */
    .4byte  0x00058000                     /* unreferenced — 5.5 fp */
.L_eye_y_ptr:
    .4byte  sym_06063E24                   /* &camera_eye_y (16.16 fp) */
    .4byte  0x0000F300                     /* unreferenced — shared pool entry */
    .4byte  sym_06063E34                   /* unreferenced — near clip */
    .4byte  0x006E0000                     /* unreferenced — 110.0 fp */
    .4byte  sym_06063E28                   /* unreferenced — heading */
    .4byte  0x00100000                     /* unreferenced — 16.0 fp */
    .4byte  sym_06063E2C                   /* unreferenced — zoom factor */
    .4byte  sym_06063E30                   /* unreferenced — z offset */
    .4byte  sym_06063EEC                   /* unreferenced — camera target vec */
.L_state_idx_ptr:
    .4byte  sym_06063E20                   /* &camera_state_idx */
.L_fp_half:
    .4byte  0x00008000                     /* 0.5 (16.16 fixed-point) */
.L_target_eye_y_ptr:
    .4byte  sym_06063F4C                   /* &target_eye_y (result of table lookup) */
.L_car_table_base:
    .4byte  sym_060446B8                   /* car table base (palette_render_main data) */
.L_camera_mode_byte_ptr:
    .4byte  sym_06078654                   /* &camera mode byte */
.L_interp_block:
    .byte   0xD0, 0x33    /* mov.l .L_fp_five_half, r0 */
    .byte   0xD1, 0x34    /* mov.l .L_fp_one, r1 */
    .byte   0xD7, 0x34    /* mov.l .L_z_offset_ptr, r7 */
    .byte   0xD6, 0x35    /* mov.l .L_zoom_factor_ptr, r6 */
    .byte   0xD5, 0x35    /* mov.l .L_heading_ptr, r5 */
    .byte   0xD4, 0x36    /* mov.l .L_near_clip_ptr, r4 */
    mov.l @r12, r2
    mov.l @r14, r3
    cmp/ge r3, r2
    bt      .L_inc_path
    mov.l @r14, r3
    .byte   0xD2, 0x34    /* mov.l .L_fp_seven_half, r2 */
    cmp/gt r2, r3
    bf      .L_dec_check_s3
    mov #0x4, r2
    mov.l r2, @r13
    mov.l @r14, r3
    sub r1, r3
    mov.l r3, @r14
    mov.w   .L_dec_clip_delta_s4, r2
    mov.l @r4, r3
    sub r2, r3
    mov.l r3, @r4
    .byte   0xD2, 0x2F    /* mov.l .L_dec_heading_delta_s4, r2 */
    mov.l @r5, r3
    sub r2, r3
    mov.l r3, @r5
    bra     .L_finalize
    nop
.L_dec_check_s3:
    mov.l @r14, r2
    cmp/gt r0, r2
    bf      .L_dec_check_s2
    mov #0x3, r2
    mov.l r2, @r13
    mov.w   .L_dec_eye_delta_s3, r3
    mov.l @r14, r2
    sub r3, r2
    mov.l r2, @r14
    mov #-0x80, r3
    mov.l @r4, r2
    sub r3, r2
    mov.l r2, @r4
    .byte   0xD3, 0x26    /* mov.l .L_dec_heading_delta_s3, r3 */
    mov.l @r5, r2
    sub r3, r2
    bra     .L_dec_done
    mov.l r2, @r5
.L_dec_check_s2:
    mov.l @r14, r2
    cmp/gt r11, r2
    bf      .L_dec_check_s1
    mov #0x2, r2
    mov.l r2, @r13
    .byte   0xD3, 0x22    /* mov.l .L_dec_eye_delta_s2, r3 */
    mov.l @r14, r2
    sub r3, r2
    mov.l r2, @r14
    mov.l @r4, r3
    add #0x40, r3
    mov.l r3, @r4
    mov.l @r5, r2
    sub r1, r2
    mov.l r2, @r5
    mov.w   DAT_06006666, r3
    mov.l @r7, r2
    sub r3, r2
    bra     .L_dec_done
    mov.l r2, @r7
.L_dec_check_s1:
    mov.l @r14, r2
    cmp/pl r2
    bf      .L_dec_stage_0
    mov.l r10, @r13
    mov.w   DAT_06006668, r2
    mov.l @r14, r3
    sub r2, r3
    mov.l r3, @r14
    mov.w   .L_dec_clip_delta_s1, r2
    mov.l @r4, r3
    sub r2, r3
    mov.l r3, @r4
    mov.l @r5, r2
    sub r0, r2
    mov.l r2, @r5
    .byte   0xD3, 0x14    /* mov.l .L_dec_zoom_delta_s1, r3 */
    mov.l @r6, r2
    sub r3, r2
    mov.l r2, @r6
    .byte   0xD0, 0x13    /* mov.l .L_terrain_flag_ptr_a, r0 */
    mov.b @r0, r0
    tst r0, r0
    bt      .L_dec_done
    .byte   0xD3, 0x12    /* mov.l .L_dec_zoom_extra_s1, r3 */
    mov.l @r6, r2
    sub r3, r2
    bra     .L_dec_done
    mov.l r2, @r6
.L_dec_stage_0:
    mov #0x0, r2
    mov.l r2, @r13
.L_dec_done:
    bra     .L_finalize
    nop
.L_dec_clip_delta_s4:
    .2byte  0xFDC0                         /* signed -576: near_clip += 576 */
.L_dec_eye_delta_s3:
    .2byte  0x4000                         /* 0.25 fp: eye_y delta */

    .global DAT_06006666
DAT_06006666:
    .2byte  0xE000                         /* signed -8192: z_offset += 8192 */

    .global DAT_06006668
DAT_06006668:
    .2byte  0x1000                         /* 0.0625 fp: eye_y delta */
.L_dec_clip_delta_s1:
    .2byte  0xFEA0                         /* signed -352: near_clip += 352 */
.L_fp_five_half:
    .4byte  0x00058000                     /* 5.5 (16.16 fp) — stage 3 threshold */
.L_fp_one:
    .4byte  0x00010000                     /* 1.0 (16.16 fp) — stage 4 eye delta */
.L_z_offset_ptr:
    .4byte  sym_06063E30                   /* &camera_z_offset */
.L_zoom_factor_ptr:
    .4byte  sym_06063E2C                   /* &camera_zoom_factor */
.L_heading_ptr:
    .4byte  sym_06063E28                   /* &camera_heading */
.L_near_clip_ptr:
    .4byte  sym_06063E34                   /* &camera_near_clip */
.L_fp_seven_half:
    .4byte  0x00078000                     /* 7.5 (16.16 fp) — stage 4 threshold */
.L_dec_heading_delta_s4:
    .4byte  0x0003C000                     /* 3.75 fp: heading delta (stage 4) */
.L_dec_heading_delta_s3:
    .4byte  0x0001C000                     /* 1.75 fp: heading delta (stage 3) */
.L_dec_eye_delta_s2:
    .4byte  0x0000A000                     /* 0.625 fp: eye_y delta (stage 2) */
.L_dec_zoom_delta_s1:
    .4byte  0x000D0000                     /* 13.0 fp: zoom delta (stage 1) */
.L_terrain_flag_ptr_a:
    .4byte  sym_06083255                   /* &terrain_rendering_flag */
.L_dec_zoom_extra_s1:
    .4byte  0x000A0000                     /* 10.0 fp: extra zoom if terrain active */
.L_inc_path:
    mov.l @r12, r2
    mov.l @r14, r3
    cmp/gt r3, r2
    bf      .L_finalize
    mov.l @r14, r3
    cmp/ge r11, r3
    bt      .L_inc_check_s1
    mov #0x0, r3
    mov.l r3, @r13
    mov.w   DAT_06006752, r2
    mov.l @r14, r3
    add r2, r3
    mov.l r3, @r14
    mov.w   .L_inc_clip_delta_s1, r2
    mov.l @r4, r3
    add r2, r3
    mov.l r3, @r4
    mov.l @r5, r2
    add r0, r2
    mov.l r2, @r5
    .byte   0xD3, 0x24    /* mov.l .L_inc_zoom_delta_s1, r3 */
    mov.l @r6, r2
    add r3, r2
    mov.l r2, @r6
    .byte   0xD0, 0x23    /* mov.l .L_terrain_flag_ptr_b, r0 */
    mov.b @r0, r0
    tst r0, r0
    bt      .L_finalize
    .byte   0xD3, 0x22    /* mov.l .L_inc_zoom_extra_s1, r3 */
    mov.l @r6, r2
    add r3, r2
    bra     .L_finalize
    mov.l r2, @r6
.L_inc_check_s1:
    mov.l @r14, r2
    cmp/ge r0, r2
    bt      .L_inc_check_s2
    mov.l r10, @r13
    .byte   0xD2, 0x1F    /* mov.l .L_inc_eye_delta_s1, r2 */
    mov.l @r14, r3
    add r2, r3
    mov.l r3, @r14
    mov.l @r4, r2
    add #-0x40, r2
    mov.l r2, @r4
    mov.l @r5, r3
    add r1, r3
    mov.l r3, @r5
    mov.w   DAT_06006756, r2
    mov.l @r7, r3
    add r2, r3
    mov.l r3, @r7
    bra     .L_finalize
    nop
.L_inc_check_s2:
    mov.l @r14, r2
    .byte   0xD3, 0x17    /* mov.l .L_fp_seven_half_b, r3 */
    cmp/ge r3, r2
    bt      .L_inc_check_s3
    mov #0x2, r3
    mov.l r3, @r13
    mov.w   DAT_06006758, r2
    mov.l @r14, r3
    add r2, r3
    mov.l r3, @r14
    mov.l @r4, r2
    add #-0x80, r2
    mov.l r2, @r4
    .byte   0xD3, 0x12    /* mov.l .L_inc_heading_delta_s2, r3 */
    mov.l @r5, r2
    add r3, r2
    bra     .L_finalize
    mov.l r2, @r5
.L_inc_check_s3:
    mov.l @r14, r2
    .byte   0xD3, 0x10    /* mov.l .L_fp_twenty_three_half, r3 */
    cmp/ge r3, r2
    bt      .L_inc_stage_4
    mov #0x3, r3
    mov.l r3, @r13
    mov.l @r14, r2
    add r1, r2
    mov.l r2, @r14
    mov.w   .L_inc_clip_delta_s3, r3
    mov.l @r4, r2
    add r3, r2
    mov.l r2, @r4
    .byte   0xD3, 0x0B    /* mov.l .L_inc_heading_delta_s3, r3 */
    mov.l @r5, r2
    add r3, r2
    bra     .L_finalize
    mov.l r2, @r5

    .global DAT_06006752
DAT_06006752:
    .2byte  0x1000                         /* 0.0625 fp: eye_y delta (stage 0) */
.L_inc_clip_delta_s1:
    .2byte  0xFEA0                         /* signed -352: near_clip -= 352 */

    .global DAT_06006756
DAT_06006756:
    .2byte  0xE000                         /* signed -8192: z_offset -= 8192 */

    .global DAT_06006758
DAT_06006758:
    .2byte  0x4000                         /* 0.25 fp: eye_y delta (stage 2) */
.L_inc_clip_delta_s3:
    .2byte  0xFDC0                         /* signed -576: near_clip -= 576 */
.L_inc_zoom_delta_s1:
    .4byte  0x000D0000                     /* 13.0 fp: zoom delta (stage 0) */
.L_terrain_flag_ptr_b:
    .4byte  sym_06083255                   /* &terrain_rendering_flag */
.L_inc_zoom_extra_s1:
    .4byte  0x000A0000                     /* 10.0 fp: extra zoom if terrain active */
.L_inc_eye_delta_s1:
    .4byte  0x0000A000                     /* 0.625 fp: eye_y delta (stage 1) */
.L_fp_seven_half_b:
    .4byte  0x00078000                     /* 7.5 fp: stage 2 threshold */
.L_inc_heading_delta_s2:
    .4byte  0x0001C000                     /* 1.75 fp: heading delta (stage 2) */
.L_fp_twenty_three_half:
    .4byte  0x00178000                     /* 23.5 fp: stage 3 threshold */
.L_inc_heading_delta_s3:
    .4byte  0x0003C000                     /* 3.75 fp: heading delta (stage 3) */
.L_inc_stage_4:
    mov #0x4, r2
    mov.l r2, @r13
.L_finalize:
    .byte   0x95, 0x3F    /* mov.w .L_wpool_06006802, r5 */
    .byte   0xD3, 0x21    /* mov.l .L_pool_06006808, r3 */
    jsr @r3
    mov.l @r14, r4
    .byte   0xD3, 0x20    /* mov.l .L_pool_0600680C, r3 */
    mov.l r0, @r3
    .byte   0x95, 0x39    /* mov.w .L_wpool_06006802, r5 */
    .byte   0xD3, 0x1E    /* mov.l .L_pool_06006808, r3 */
    jsr @r3
    mov.l @r14, r4
    .byte   0xD3, 0x1E    /* mov.l .L_pool_06006810, r3 */
    mov.l r0, @r3
    .byte   0xD4, 0x1E    /* mov.l .L_pool_06006814, r4 */
    mov.l @r13, r1
    tst r1, r1
    bt      .L_set_inactive
    mov.l @r13, r0
    cmp/eq #0x1, r0
    bf      .L_set_active
    mov #0x1, r3
    .byte   0xD2, 0x1B    /* mov.l .L_pool_06006818, r2 */
    mov.l @r2, r2
    cmp/hi r3, r2
    bt      .L_set_active
.L_set_inactive:
    mov #0x0, r3
    mov.l r3, @r4
    bra     .L_epilogue
    nop
.L_set_active:
    mov.l r10, @r4
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
