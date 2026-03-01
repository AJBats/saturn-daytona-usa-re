
    .section .text.FUN_0601BBDC


    .global replay_recorder
    .type replay_recorder, @function
replay_recorder:
    sts.l pr, @-r15
    add #-0x24, r15
    mov.w   DAT_0601bcba, r8
    mov r15, r1
    mov.l   _pool_replay_init_data_src, r2
    mov.l   _pool_fn_sprite_draw, r11
    mov.l   _pool_fn_vdp1_pos_draw, r12
    mov.l   _pool_fn_data_copy, r3
    add #0x20, r1
    jsr @r3
    mov #0x4, r0
    exts.b r5, r13
    exts.b r5, r5
    add #0x5, r5
    mov.l r5, @(16, r15)
    mov.l   _pool_model_table_a, r3
    mov.l r3, @(4, r15)
    mov.l   _pool_model_table_b, r3
    mov.l r3, @(8, r15)
    mov.l   _pool_model_table_c, r3
    mov.l r3, @(12, r15)
    extu.w r13, r3
    mov.l @(16, r15), r2
    cmp/ge r2, r3
    bf/s    .L_0601BC14
    mov r6, r14
    bra     .L_0601BDD2
    nop
.L_0601BC14:
    extu.w r13, r7
    mov #0x60, r6
    extu.w r14, r5
    mov.l   _pool_car_data_table, r3
    shll2 r7
    shll2 r5
    add r3, r7
    shll2 r5
    mov.l @r7, r7
    shll2 r5
    mov.l r5, @r15
    add #0x2, r5
    shll r5
    jsr @r12
    mov #0x8, r4
    extu.w r13, r10
    mov r15, r7
    mov #0x60, r6
    mov.l @r15, r5
    mov r10, r3
    add #0x20, r7
    add #0x9, r5
    shll2 r10
    shll2 r3
    shll r5
    shll r3
    add r3, r10
    add r9, r10
    jsr @r12
    mov #0x8, r4
    mov.b @r10, r3
    extu.b r3, r3
    tst r3, r3
    bt      .L_0601BC6C
    mov r10, r7
    mov #0x60, r6
    extu.w r14, r5
    shll2 r5
    shll2 r5
    shll2 r5
    add #0x9, r5
    shll r5
    jsr @r12
    mov #0x8, r4
.L_0601BC6C:
    extu.w r13, r10
    mov r10, r3
    shll2 r10
    shll2 r3
    shll r3
    add r3, r10
    add r9, r10
    mov.l   _pool_fn_anim_transform, r3
    jsr @r3
    mov.l @(4, r10), r4
    mov r0, r7
    mov #0x78, r6
    extu.w r14, r5
    shll2 r5
    shll2 r5
    shll2 r5
    add #0x10, r5
    shll r5
    jsr @r12
    mov #0x8, r4
    mov.b @(8, r10), r0
    mov #0x0, r3
    mov #0xC, r2
    mov r0, r10
    mov.b r3, @r15
    mov #0x1C, r0
    mov.b r3, @(r0, r15)
    extu.b r10, r3
    cmp/ge r2, r3
    bf      .L_0601BCB0
    add #-0xC, r10
    mov #0x1, r2
    mov #0x1C, r0
    mov.b r2, @(r0, r15)
.L_0601BCB0:
    extu.b r10, r3
    mov #0xA, r2
    cmp/ge r2, r3
    bra     .L_0601BCE0
    nop

    .global DAT_0601bcba
DAT_0601bcba:
    .2byte  0x7000
_pool_fn_sprite_draw:
    .4byte  sym_06028400
_pool_fn_vdp1_pos_draw:
    .4byte  sym_060284AE
_pool_replay_init_data_src:
    .4byte  sym_0605DF3E
_pool_fn_data_copy:
    .4byte  sym_06035228
_pool_model_table_a:
    .4byte  sym_06063918
_pool_model_table_b:
    .4byte  sym_06063D08
_pool_model_table_c:
    .4byte  sym_06063920
_pool_car_data_table:
    .4byte  sym_0605DE64
_pool_fn_anim_transform:
    .4byte  anim_frame_transform
.L_0601BCE0:
    bf      .L_0601BCE6
    mov #0x2, r2
    mov.b r2, @r15
.L_0601BCE6:
    extu.b r10, r7
    mov.b @r15, r3
    mov #0x1C, r0
    extu.w r14, r6
    shll8 r7
    extu.b r3, r3
    mov.b @(r0, r15), r2
    shll2 r6
    shll2 r7
    extu.b r2, r2
    shll2 r6
    shll2 r7
    add r2, r3
    shll2 r6
    mov r3, r2
    add #0x3C, r2
    mov r2, r3
    shll2 r3
    mov.l   _pool_model_geom_table, r2
    shll r3
    add r3, r2
    mov.l r2, @(20, r15)
    mov.l @(4, r2), r3
    mov.l r6, @(24, r15)
    add r3, r7
    add #0x21, r6
    mov.l @(20, r15), r5
    shll r6
    mov.l @r5, r5
    jsr @r11
    mov #0x8, r4
    mov.l   _pool_overlay_data, r7
    mov #0x60, r6
    mov.l @(24, r15), r5
    add #0x25, r5
    shll r5
    jsr @r12
    mov #0xC, r4
    extu.w r13, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r2
    add r2, r3
    add r9, r3
    mov.b @(10, r3), r0
    mov r0, r3
    extu.b r3, r3
    tst r3, r3
    bt      .L_0601BD8E
    mov.l   _pool_table_selector, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bf      .L_0601BD74
    extu.w r14, r6
    mov.l @(4, r15), r7
    shll2 r6
    mov.l @(4, r7), r7
    shll2 r6
    add r8, r7
    shll2 r6
    add #0x25, r6
    shll r6
    bra     .L_0601BD88
    mov.l @(4, r15), r5
_pool_model_geom_table:
    .4byte  sym_06063750
_pool_overlay_data:
    .4byte  sym_0604A4B8
_pool_table_selector:
    .4byte  sym_06078644
.L_0601BD74:
    mov.l @(8, r15), r7
    extu.w r14, r6
    mov.l @(4, r7), r7
    shll2 r6
    add r8, r7
    shll2 r6
    shll2 r6
    add #0x25, r6
    shll r6
    mov.l @(8, r15), r5
.L_0601BD88:
    mov.l @r5, r5
    jsr @r11
    mov #0xC, r4
.L_0601BD8E:
    extu.w r13, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r2
    add r2, r3
    add r9, r3
    mov.b @(9, r3), r0
    mov r0, r3
    extu.b r3, r3
    tst r3, r3
    bt      .L_0601BDC2
    mov.l @(12, r15), r7
    extu.w r14, r6
    mov.l @(12, r15), r5
    mov.l   .L_0601BDE8, r3
    mov.l @(4, r7), r7
    shll2 r6
    mov.l @r5, r5
    add r3, r7
    shll2 r6
    shll2 r6
    add #0x28, r6
    shll r6
    jsr @r11
    mov #0xC, r4
.L_0601BDC2:
    add #0x1, r13
    mov.l @(16, r15), r2
    extu.w r13, r3
    cmp/ge r2, r3
    bt/s    .L_0601BDD2
    add #0x3, r14
    bra     .L_0601BC14
    nop
.L_0601BDD2:
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
    .2byte  0xFFFF
.L_0601BDE8:
    .4byte  0x00008000
