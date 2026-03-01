
    .section .text.FUN_0600D9BC


    .global lap_complete_flag
    .type lap_complete_flag, @function
lap_complete_flag:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_0600DA58, r14
    mov.l   .L_pool_0600DA5C, r5
    tst r4, r4
    bf/s    .L_0600DA04
    mov.l @r5, r5
    mov.l   .L_pool_0600DA60, r3
    mov.l   .L_pool_0600DA58, r2
    mov.l @r3, r3
    mov.l @r2, r2
    cmp/eq r2, r3
    bf      .L_0600DA04
    mov.w   .L_wpool_0600DA50, r0
    mov.l   .L_pool_0600DA64, r3
    mov.l @(r0, r5), r2
    mov.l @r3, r3
    cmp/eq r3, r2
    bt      .L_0600DA04
    mov.w   .L_wpool_0600DA50, r0
    mov.l   .L_pool_0600DA64, r2
    mov.l @(r0, r5), r3
    add #-0xC, r0
    mov.l r3, @r2
    mov.l   .L_pool_0600DA68, r6
    mov.l @r6, r3
    add #0x1, r3
    mov.l r3, @r6
    mov.l r3, @(r0, r5)
    mov.l @r6, r3
    mov.l   .L_pool_0600DA6C, r2
    mov.l @r2, r2
    cmp/hs r2, r3
    bt      .L_0600DA04
    mov #0x0, r2
    mov.l r2, @r14
.L_0600DA04:
    mov #0x1, r7
    mov.l   .L_pool_0600DA70, r3
    mov r7, r0
    jsr @r3
    mov r4, r1
    mov r0, r6
    mov.l @r14, r2
    and r6, r2
    tst r2, r2
    bf      .L_0600DA4A
    mov r7, r0
    mov.l @r14, r3
    or r6, r3
    mov.l r3, @r14
    mov.w   .L_wpool_0600DA52, r1
    mov.l   .L_pool_0600DA74, r3
    jsr @r3
    mov r5, r2
    mov.w   .L_wpool_0600DA54, r0
    mov.l @(r0, r5), r2
    add #0x1, r2
    mov.l r2, @(r0, r5)
    mov.l   .L_pool_0600DA78, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_0600DA4A
    tst r4, r4
    bt      .L_0600DA4A
    mov r5, r0
    mov.b @(3, r0), r0
    tst #0x8, r0
    bf      .L_0600DA4A
    lds.l @r15+, pr
    .byte   0xA1, 0x9F    /* bra 0x0600DD88 (external) */
    mov.l @r15+, r14
.L_0600DA4A:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_wpool_0600DA50:
    .2byte  0x0228
.L_wpool_0600DA52:
    .2byte  0x1501
.L_wpool_0600DA54:
    .2byte  0x0230
    .2byte  0xFFFF
.L_pool_0600DA58:
    .4byte  sym_06063F1C
.L_pool_0600DA5C:
    .4byte  sym_0607E940
.L_pool_0600DA60:
    .4byte  sym_06063F18
.L_pool_0600DA64:
    .4byte  sym_06063F20
.L_pool_0600DA68:
    .4byte  sym_06063F24
.L_pool_0600DA6C:
    .4byte  sym_06063F28
.L_pool_0600DA70:
    .4byte  sym_06035280
.L_pool_0600DA74:
    .4byte  sym_06034F78
.L_pool_0600DA78:
    .4byte  sym_0607EAD8
