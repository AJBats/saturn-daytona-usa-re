
    .section .text.FUN_0601950C


    .global course_select_draw
    .type course_select_draw, @function
course_select_draw:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0xC, r15
    mov.l   _pool_course_slot_lut, r8
    mov.l   _pool_dlist_loader, r9
    mov.l   _pool_obj_table_base, r10
    mov.l   _pool_course_index, r12
    mov.l   _pool_slot_param_table, r13
    mov.l   _pool_last_drawn_course, r0
    mov.b @r0, r0
    tst r0, r0
    bt/s    .L_0601959E
    mov #0x0, r11
    mov #0x14, r6
    mov.w   DAT_060195ac, r7
    add r10, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_060195ae, r3
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r9
    mov #0xC, r4
    exts.b r11, r14
.L_0601954A:
    exts.b r14, r3
    mov.b @r12, r2
    cmp/eq r2, r3
    bt      .L_0601958E
    exts.b r14, r0
    shll r0
    mov.l r0, @(4, r15)
    mov.w @(r0, r8), r7
    extu.w r7, r7
    shll2 r7
    shll r7
    add r10, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   _wpool_tex_offset_2000, r3
    mov.l @(4, r15), r6
    add r3, r7
    add r13, r6
    mov.l r6, @(8, r15)
    mov.b @(1, r6), r0
    mov.l @(8, r15), r3
    mov.l @r15, r5
    mov r0, r6
    mov.b @r3, r3
    mov.l @r5, r5
    extu.b r6, r6
    extu.b r3, r3
    shll2 r6
    shll2 r6
    shll2 r6
    add r3, r6
    shll r6
    jsr @r9
    mov #0xC, r4
.L_0601958E:
    exts.b r11, r3
    mov.l   _pool_last_drawn_course, r2
    add #0x1, r14
    mov.b r3, @r2
    exts.b r14, r1
    mov #0x4, r2
    cmp/ge r2, r1
    bf      .L_0601954A
.L_0601959E:
    mov.l   _pool_highlight_flag, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_060195D0
    bra     .L_06019680
    nop

    .global DAT_060195ac
DAT_060195ac:
    .2byte  0x03B0

    .global DAT_060195ae
DAT_060195ae:
    .2byte  0x1000
_wpool_tex_offset_2000:
    .2byte  0x2000
    .2byte  0xFFFF
_pool_course_slot_lut:
    .4byte  sym_06049AF4
_pool_dlist_loader:
    .4byte  sym_06028400
_pool_obj_table_base:
    .4byte  sym_06063750
_pool_course_index:
    .4byte  sym_0605D244
_pool_slot_param_table:
    .4byte  sym_06049AEC
_pool_last_drawn_course:
    .4byte  sym_06085FF1
_pool_highlight_flag:
    .4byte  sym_06085FF5
.L_060195D0:
    mov.l   _pool_blink_timer, r14
    mov #0xF, r2
    mov.b @r14, r3
    extu.b r3, r3
    cmp/gt r2, r3
    bt      .L_0601961C
    mov.b @r12, r0
    shll r0
    mov.l r0, @(4, r15)
    mov.w @(r0, r8), r7
    extu.w r7, r7
    shll2 r7
    shll r7
    add r10, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_06019694, r3
    mov.l @(4, r15), r6
    add r3, r7
    add r13, r6
    mov.l r6, @(8, r15)
    mov.b @(1, r6), r0
    mov.l @(8, r15), r3
    mov.l @r15, r5
    mov r0, r6
    mov.b @r3, r3
    mov.l @r5, r5
    extu.b r6, r6
    extu.b r3, r3
    shll2 r6
    shll2 r6
    shll2 r6
    add r3, r6
    shll r6
    jsr @r9
    mov #0xC, r4
    bra     .L_06019680
    nop
.L_0601961C:
    mov.l   _pool_blink_geom_data, r7
    mov.w   _wpool_blink_param_offset, r6
    mov.b @r12, r5
    mov.l @r7, r7
    shll r5
    add r13, r5
    mov.l r5, @r15
    mov.b @(1, r5), r0
    mov.l @r15, r3
    mov r0, r5
    mov.b @r3, r3
    extu.b r5, r5
    extu.b r3, r3
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    shll r5
    mov.l   _pool_vdp_num_text, r3
    jsr @r3
    mov #0xC, r4
    mov.l   _pool_blink_geom_data, r7
    mov.w   _wpool_blink_param_offset, r6
    mov.b @r12, r5
    mov.l @r7, r7
    shll r5
    add r13, r5
    mov.l r5, @r15
    mov.b @(1, r5), r0
    mov.l @r15, r3
    mov r0, r5
    mov.b @r3, r3
    extu.b r5, r5
    extu.b r3, r3
    add #0x2, r5
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    shll r5
    mov.l   _pool_vdp_num_text, r3
    jsr @r3
    mov #0xC, r4
    mov #0x1E, r3
    mov.b @r14, r2
    extu.b r2, r2
    cmp/gt r3, r2
    bf      .L_06019680
    extu.b r11, r3
    mov.b r3, @r14
.L_06019680:
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

    .global DAT_06019694
DAT_06019694:
    .2byte  0x4000
_wpool_blink_param_offset:
    .2byte  0x0090
_pool_blink_timer:
    .4byte  sym_0605D242
_pool_blink_geom_data:
    .4byte  sym_0605D4EC
_pool_vdp_num_text:
    .4byte  sym_060284AE
