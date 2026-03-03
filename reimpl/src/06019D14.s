
    .section .text.FUN_06019D14


    .global trans_select_at_mt
    .type trans_select_at_mt, @function
trans_select_at_mt:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l   .L_pool_06019DA8, r14
    mov.l   .L_pool_06019DAC, r6
    mov.l   .L_pool_06019DB0, r5
    mov.l   .L_pool_06019DB4, r4
    mov.w @(2, r5), r0
    mov r0, r3
    extu.w r3, r3
    and r6, r3
    tst r3, r3
    bt/s    .L_06019D3A
    mov #0x0, r13
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    exts.b r13, r2
    bra     .L_06019D8C
    mov.b r2, @r4
.L_06019D3A:
    mov.w   .L_wpool_06019DA6, r7
    mov.w @(2, r5), r0
    mov r0, r2
    extu.w r2, r2
    and r7, r2
    tst r2, r2
    bt      .L_06019D54
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
    exts.b r13, r2
    bra     .L_06019D8C
    mov.b r2, @r4
.L_06019D54:
    mov.w @r5, r2
    extu.w r2, r2
    and r6, r2
    tst r2, r2
    bt      .L_06019D72
    mov.b @r4, r0
    cmp/eq #0x19, r0
    bf      .L_06019D8C
    mov.l @r14, r2
    add #0x1, r2
    mov.l r2, @r14
    exts.b r13, r3
    mov.b r3, @r4
    bra     .L_06019D8C
    nop
.L_06019D72:
    mov.w @r5, r2
    extu.w r2, r2
    and r7, r2
    tst r2, r2
    bt      .L_06019D8C
    mov.b @r4, r0
    cmp/eq #0x19, r0
    bf      .L_06019D8C
    mov.l @r14, r2
    add #-0x1, r2
    mov.l r2, @r14
    exts.b r13, r3
    mov.b r3, @r4
.L_06019D8C:
    mov.l @r14, r2
    mov #0x2, r3
    cmp/gt r3, r2
    bf      .L_06019D96
    mov.l r13, @r14
.L_06019D96:
    mov.l @r14, r3
    cmp/pz r3
    bt      .L_06019DA0
    mov #0x2, r3
    mov.l r3, @r14
.L_06019DA0:
    mov.l @r15+, r13
    .byte   0xAF, 0x11    /* bra 0x06019BC8 (external) */
    mov.l @r15+, r14
.L_wpool_06019DA6:
    .2byte  0x4000
.L_pool_06019DA8:
    .4byte  sym_0605AD00
.L_pool_06019DAC:
    .4byte  0x00008000
.L_pool_06019DB0:
    .4byte  g_pad_state
.L_pool_06019DB4:
    .4byte  sym_0605D243
