
    .section .text.FUN_0600579C


    .global vdp_mode_setup
    .type vdp_mode_setup, @function
vdp_mode_setup:
    sts.l pr, @-r15
    mov r14, r6
    add #-0x4, r15
    mov.l   .L_pool_06005858, r8
    mov.l   .L_pool_0600585C, r9
    mov.w   .L_wpool_0600584E, r10
    mov.l   .L_pool_06005860, r13
    mov r9, r7
    add #0x20, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.l @r15, r5
    mov.l   .L_pool_06005864, r3
    mov.l @r5, r5
    jsr @r3
    mov #0x8, r4
    mov.b @r8, r0
    tst r0, r0
    bt      .L_skip_texture_copy
    mov r14, r12
    mov.w   .L_wpool_06005850, r7
.L_copy_outer_loop:
    mov.l @r13, r5
    add r7, r5
    add #0x18, r5
    mov.l @r13, r6
    add r12, r6
    add #0x18, r6
    mov r11, r4
.L_copy_inner_loop:
    mov.w @r5+, r1
    add #-0x3, r4
    mov.w r1, @r6
    add #0x2, r6
    mov.w @r5+, r1
    mov.w r1, @r6
    add #0x2, r6
    mov.w @r5+, r1
    mov r6, r3
    add #0x2, r6
    tst r4, r4
    bf/s    .L_copy_inner_loop
    mov.w r1, @r3
    add r14, r7
    cmp/ge r10, r7
    bf/s    .L_copy_outer_loop
    add r14, r12
    mov #0x60, r6
    mov.w   .L_wpool_06005852, r5
    mov.l   .L_pool_06005868, r7
    mov.l   .L_pool_0600586C, r3
    jsr @r3
    mov #0x8, r4
.L_skip_texture_copy:
    mov.b @r8, r0
    tst r0, r0
    bt      .L_set_1p_course_index
    bra     .L_course_index_ready
    mov #0x5, r12
.L_set_1p_course_index:
    mov #0x7, r12
.L_course_index_ready:
    mov.l   .L_pool_06005870, r0
    mov.l @r0, r0
    tst #0x1, r0
    bf      .L_skip_overlay_layer
    mov r9, r7
    mov r12, r6
    add #0x28, r7
    shll2 r6
    mov.l r7, @r15
    shll2 r6
    mov.l @(4, r7), r7
    mov.l @r15, r5
    mov.l   .L_pool_06005864, r3
    shll2 r6
    mov.l @r5, r5
    add #0x19, r6
    shll r6
    jsr @r3
    mov #0x8, r4
.L_skip_overlay_layer:
    mov.l   .L_pool_06005874, r12
    mov #0xA, r3
    mov.l @r12, r2
    cmp/hs r3, r2
    bt      .L_wide_frame_layer
    mov.l @r12, r7
    mov #0x0, r6
    mov.w   .L_wpool_06005854, r5
    mov.l   .L_pool_06005878, r3
    jsr @r3
    mov #0x8, r4
    bra     .L_check_extra_layer
    nop
.L_wpool_0600584E:
    .2byte  0x0480
.L_wpool_06005850:
    .2byte  0x0180
.L_wpool_06005852:
    .2byte  0x0318
.L_wpool_06005854:
    .2byte  0x0110
    .2byte  0xFFFF
.L_pool_06005858:
    .4byte  sym_06085FF4
.L_pool_0600585C:
    .4byte  sym_06063750
.L_pool_06005860:
    .4byte  sym_0606129C
.L_pool_06005864:
    .4byte  sym_06028400
.L_pool_06005868:
    .4byte  sym_0605ACDF
.L_pool_0600586C:
    .4byte  sym_060284AE
.L_pool_06005870:
    .4byte  sym_0607EAB8
.L_pool_06005874:
    .4byte  sym_06063F28
.L_pool_06005878:
    .4byte  sym_06028430
.L_wide_frame_layer:
    mov.l @r12, r7
    mov #0xC, r6
    .byte   0x95, 0x44    /* mov.w .L_wpool_0600590C, r5 */
    .byte   0xD3, 0x24    /* mov.l .L_pool_06005914, r3 */
    jsr @r3
    mov #0x8, r4
.L_check_extra_layer:
    .byte   0xD0, 0x23    /* mov.l .L_pool_06005918, r0 */
    mov.l @r0, r0
    tst r0, r0
    bf      .L_skip_extra_layer
    mov #0x30, r6
    .byte   0x95, 0x3C    /* mov.w .L_wpool_0600590E, r5 */
    .byte   0xD7, 0x21    /* mov.l .L_pool_0600591C, r7 */
    .byte   0xD3, 0x1F    /* mov.l .L_pool_06005914, r3 */
    mov.l @r7, r7
    jsr @r3
    mov #0x8, r4
.L_skip_extra_layer:
    .byte   0xD0, 0x20    /* mov.l .L_pool_06005920, r0 */
    mov.l @r0, r0
    tst r0, r0
    bf      .L_epilogue_rts
    mov.b @r8, r0
    tst r0, r0
    bt      .L_set_1p_bg_index
    bra     .L_bg_index_ready
    mov #0x4, r12
.L_set_1p_bg_index:
    mov #0x6, r12
.L_bg_index_ready:
    mov r9, r7
    mov r12, r6
    add #0x30, r7
    shll2 r6
    mov.l r7, @r15
    shll2 r6
    mov.l @(4, r7), r7
    .byte   0x93, 0x26    /* mov.w .L_wpool_06005910, r3 */
    shll2 r6
    add r3, r7
    add #0x16, r6
    shll r6
    mov.l @r15, r5
    mov.l @r5, r5
    mov #0x8, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xD3, 0x10    /* mov.l .L_pool_06005924, r3 */
    jmp @r3
    mov.l @r15+, r14
.L_epilogue_rts:
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
