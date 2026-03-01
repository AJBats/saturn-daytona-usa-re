
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
    .byte   0xDB, 0x23    /* mov.l .L_0600658C, r11 */
    .byte   0xDC, 0x23    /* mov.l .L_06006590, r12 */
    .byte   0xDD, 0x14    /* mov.l .L_06006554, r13 */
    .byte   0xDE, 0x17    /* mov.l .L_06006564, r14 */
    .byte   0xD3, 0x20    /* mov.l .L_06006588, r3 */
    .byte   0xD2, 0x22    /* mov.l .L_06006594, r2 */
    mov.l @r3, r3
    shll2 r3
    add r2, r3
    mov.l @r3, r1
    mov.l r1, @r12
    mov.l @r14, r3
    cmp/gt r11, r3
    bt/s    .L_06006532
    mov #0x1, r10
    .byte   0xD0, 0x1E    /* mov.l .L_06006598, r0 */
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x4, r0
    bt      .L_06006532
    mov #0x5, r5
    .byte   0xD3, 0x0C    /* mov.l .L_0600655C, r3 */
    jsr @r3
    mov #0x8, r4
    bra     .L_0600653A
    nop
.L_06006532:
    mov #0x0, r5
    .byte   0xD3, 0x09    /* mov.l .L_0600655C, r3 */
    jsr @r3
    mov #0x8, r4
.L_0600653A:
    mov.l @r14, r2
    mov.l @r12, r3
    cmp/eq r3, r2
    bf      .L_0600659C
    .byte   0xD3, 0x11    /* mov.l .L_06006588, r3 */
    mov.l @r3, r3
    mov.l r3, @r13
    bra     .L_06006780
    nop
    .4byte  0x00DCFFFF                     /* unreferenced alignment data */
    .4byte  sym_060620D0                   /* unreferenced — binary_final_func data */
.L_06006554:
    .4byte  sym_06063E1C                   /* &camera_mode (32-bit) */
    .4byte  sym_06059F30                   /* unreferenced — camera follow flag */
.L_0600655C:
    .4byte  channel_nibble_config          /* display channel config function */
    .4byte  0x00058000                     /* unreferenced — 5.5 fp */
.L_06006564:
    .4byte  sym_06063E24                   /* &camera_eye_y (16.16 fp) */
    .4byte  0x0000F300                     /* unreferenced — shared pool entry */
    .4byte  sym_06063E34                   /* unreferenced — near clip */
    .4byte  0x006E0000                     /* unreferenced — 110.0 fp */
    .4byte  sym_06063E28                   /* unreferenced — heading */
    .4byte  0x00100000                     /* unreferenced — 16.0 fp */
    .4byte  sym_06063E2C                   /* unreferenced — zoom factor */
    .4byte  sym_06063E30                   /* unreferenced — z offset */
    .4byte  sym_06063EEC                   /* unreferenced — camera target vec */
.L_06006588:
    .4byte  sym_06063E20                   /* &camera_state_idx */
.L_0600658C:
    .4byte  0x00008000                     /* 0.5 (16.16 fixed-point) */
.L_06006590:
    .4byte  sym_06063F4C                   /* &target_eye_y (result of table lookup) */
.L_06006594:
    .4byte  sym_060446B8                   /* car table base (palette_render_main data) */
.L_06006598:
    .4byte  sym_06078654                   /* &camera mode byte */
.L_0600659C:
    .byte   0xD0, 0x33    /* mov.l .L_0600666C, r0 */
    .byte   0xD1, 0x34    /* mov.l .L_06006670, r1 */
    .byte   0xD7, 0x34    /* mov.l .L_06006674, r7 */
    .byte   0xD6, 0x35    /* mov.l .L_06006678, r6 */
    .byte   0xD5, 0x35    /* mov.l .L_0600667C, r5 */
    .byte   0xD4, 0x36    /* mov.l .L_06006680, r4 */
    mov.l @r12, r2
    mov.l @r14, r3
    cmp/ge r3, r2
    bt      .L_060066A0
    mov.l @r14, r3
    .byte   0xD2, 0x34    /* mov.l .L_06006684, r2 */
    cmp/gt r2, r3
    bf      .L_060065D6
    mov #0x4, r2
    mov.l r2, @r13
    mov.l @r14, r3
    sub r1, r3
    mov.l r3, @r14
    mov.w   .L_06006662, r2
    mov.l @r4, r3
    sub r2, r3
    mov.l r3, @r4
    .byte   0xD2, 0x2F    /* mov.l .L_06006688, r2 */
    mov.l @r5, r3
    sub r2, r3
    mov.l r3, @r5
    bra     .L_06006780
    nop
.L_060065D6:
    mov.l @r14, r2
    cmp/gt r0, r2
    bf      .L_060065FA
    mov #0x3, r2
    mov.l r2, @r13
    mov.w   .L_06006664, r3
    mov.l @r14, r2
    sub r3, r2
    mov.l r2, @r14
    mov #-0x80, r3
    mov.l @r4, r2
    sub r3, r2
    mov.l r2, @r4
    .byte   0xD3, 0x26    /* mov.l .L_0600668C, r3 */
    mov.l @r5, r2
    sub r3, r2
    bra     .L_0600665E
    mov.l r2, @r5
.L_060065FA:
    mov.l @r14, r2
    cmp/gt r11, r2
    bf      .L_06006622
    mov #0x2, r2
    mov.l r2, @r13
    .byte   0xD3, 0x22    /* mov.l .L_06006690, r3 */
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
    bra     .L_0600665E
    mov.l r2, @r7
.L_06006622:
    mov.l @r14, r2
    cmp/pl r2
    bf      .L_0600665A
    mov.l r10, @r13
    mov.w   DAT_06006668, r2
    mov.l @r14, r3
    sub r2, r3
    mov.l r3, @r14
    mov.w   .L_0600666A, r2
    mov.l @r4, r3
    sub r2, r3
    mov.l r3, @r4
    mov.l @r5, r2
    sub r0, r2
    mov.l r2, @r5
    .byte   0xD3, 0x14    /* mov.l .L_06006694, r3 */
    mov.l @r6, r2
    sub r3, r2
    mov.l r2, @r6
    .byte   0xD0, 0x13    /* mov.l .L_06006698, r0 */
    mov.b @r0, r0
    tst r0, r0
    bt      .L_0600665E
    .byte   0xD3, 0x12    /* mov.l .L_0600669C, r3 */
    mov.l @r6, r2
    sub r3, r2
    bra     .L_0600665E
    mov.l r2, @r6
.L_0600665A:
    mov #0x0, r2
    mov.l r2, @r13
.L_0600665E:
    bra     .L_06006780
    nop
.L_06006662:
    .2byte  0xFDC0                         /* signed -576: near_clip += 576 */
.L_06006664:
    .2byte  0x4000                         /* 0.25 fp: eye_y delta */

    .global DAT_06006666
DAT_06006666:
    .2byte  0xE000                         /* signed -8192: z_offset += 8192 */

    .global DAT_06006668
DAT_06006668:
    .2byte  0x1000                         /* 0.0625 fp: eye_y delta */
.L_0600666A:
    .2byte  0xFEA0                         /* signed -352: near_clip += 352 */
.L_0600666C:
    .4byte  0x00058000                     /* 5.5 (16.16 fp) — stage 3 threshold */
.L_06006670:
    .4byte  0x00010000                     /* 1.0 (16.16 fp) — stage 4 eye delta */
.L_06006674:
    .4byte  sym_06063E30                   /* &camera_z_offset */
.L_06006678:
    .4byte  sym_06063E2C                   /* &camera_zoom_factor */
.L_0600667C:
    .4byte  sym_06063E28                   /* &camera_heading */
.L_06006680:
    .4byte  sym_06063E34                   /* &camera_near_clip */
.L_06006684:
    .4byte  0x00078000                     /* 7.5 (16.16 fp) — stage 4 threshold */
.L_06006688:
    .4byte  0x0003C000                     /* 3.75 fp: heading delta (stage 4) */
.L_0600668C:
    .4byte  0x0001C000                     /* 1.75 fp: heading delta (stage 3) */
.L_06006690:
    .4byte  0x0000A000                     /* 0.625 fp: eye_y delta (stage 2) */
.L_06006694:
    .4byte  0x000D0000                     /* 13.0 fp: zoom delta (stage 1) */
.L_06006698:
    .4byte  sym_06083255                   /* &terrain_rendering_flag */
.L_0600669C:
    .4byte  0x000A0000                     /* 10.0 fp: extra zoom if terrain active */
.L_060066A0:
    mov.l @r12, r2
    mov.l @r14, r3
    cmp/gt r3, r2
    bf      .L_06006780
    mov.l @r14, r3
    cmp/ge r11, r3
    bt      .L_060066E2
    mov #0x0, r3
    mov.l r3, @r13
    mov.w   DAT_06006752, r2
    mov.l @r14, r3
    add r2, r3
    mov.l r3, @r14
    mov.w   .L_06006754, r2
    mov.l @r4, r3
    add r2, r3
    mov.l r3, @r4
    mov.l @r5, r2
    add r0, r2
    mov.l r2, @r5
    .byte   0xD3, 0x24    /* mov.l .L_0600675C, r3 */
    mov.l @r6, r2
    add r3, r2
    mov.l r2, @r6
    .byte   0xD0, 0x23    /* mov.l .L_06006760, r0 */
    mov.b @r0, r0
    tst r0, r0
    bt      .L_06006780
    .byte   0xD3, 0x22    /* mov.l .L_06006764, r3 */
    mov.l @r6, r2
    add r3, r2
    bra     .L_06006780
    mov.l r2, @r6
.L_060066E2:
    mov.l @r14, r2
    cmp/ge r0, r2
    bt      .L_0600670A
    mov.l r10, @r13
    .byte   0xD2, 0x1F    /* mov.l .L_06006768, r2 */
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
    bra     .L_06006780
    nop
.L_0600670A:
    mov.l @r14, r2
    .byte   0xD3, 0x17    /* mov.l .L_0600676C, r3 */
    cmp/ge r3, r2
    bt      .L_0600672E
    mov #0x2, r3
    mov.l r3, @r13
    mov.w   DAT_06006758, r2
    mov.l @r14, r3
    add r2, r3
    mov.l r3, @r14
    mov.l @r4, r2
    add #-0x80, r2
    mov.l r2, @r4
    .byte   0xD3, 0x12    /* mov.l .L_06006770, r3 */
    mov.l @r5, r2
    add r3, r2
    bra     .L_06006780
    mov.l r2, @r5
.L_0600672E:
    mov.l @r14, r2
    .byte   0xD3, 0x10    /* mov.l .L_06006774, r3 */
    cmp/ge r3, r2
    bt      .L_0600677C
    mov #0x3, r3
    mov.l r3, @r13
    mov.l @r14, r2
    add r1, r2
    mov.l r2, @r14
    mov.w   .L_0600675A, r3
    mov.l @r4, r2
    add r3, r2
    mov.l r2, @r4
    .byte   0xD3, 0x0B    /* mov.l .L_06006778, r3 */
    mov.l @r5, r2
    add r3, r2
    bra     .L_06006780
    mov.l r2, @r5

    .global DAT_06006752
DAT_06006752:
    .2byte  0x1000                         /* 0.0625 fp: eye_y delta (stage 0) */
.L_06006754:
    .2byte  0xFEA0                         /* signed -352: near_clip -= 352 */

    .global DAT_06006756
DAT_06006756:
    .2byte  0xE000                         /* signed -8192: z_offset -= 8192 */

    .global DAT_06006758
DAT_06006758:
    .2byte  0x4000                         /* 0.25 fp: eye_y delta (stage 2) */
.L_0600675A:
    .2byte  0xFDC0                         /* signed -576: near_clip -= 576 */
.L_0600675C:
    .4byte  0x000D0000                     /* 13.0 fp: zoom delta (stage 0) */
.L_06006760:
    .4byte  sym_06083255                   /* &terrain_rendering_flag */
.L_06006764:
    .4byte  0x000A0000                     /* 10.0 fp: extra zoom if terrain active */
.L_06006768:
    .4byte  0x0000A000                     /* 0.625 fp: eye_y delta (stage 1) */
.L_0600676C:
    .4byte  0x00078000                     /* 7.5 fp: stage 2 threshold */
.L_06006770:
    .4byte  0x0001C000                     /* 1.75 fp: heading delta (stage 2) */
.L_06006774:
    .4byte  0x00178000                     /* 23.5 fp: stage 3 threshold */
.L_06006778:
    .4byte  0x0003C000                     /* 3.75 fp: heading delta (stage 3) */
.L_0600677C:
    mov #0x4, r2
    mov.l r2, @r13
.L_06006780:
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
    bt      .L_060067B0
    mov.l @r13, r0
    cmp/eq #0x1, r0
    bf      .L_060067B8
    mov #0x1, r3
    .byte   0xD2, 0x1B    /* mov.l .L_pool_06006818, r2 */
    mov.l @r2, r2
    cmp/hi r3, r2
    bt      .L_060067B8
.L_060067B0:
    mov #0x0, r3
    mov.l r3, @r4
    bra     .L_060067BA
    nop
.L_060067B8:
    mov.l r10, @r4
.L_060067BA:
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
