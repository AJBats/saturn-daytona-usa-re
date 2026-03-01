
    .section .text.FUN_06011DC0


    .global post_sprite_cleanup
    .type post_sprite_cleanup, @function
post_sprite_cleanup:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_06011E64, r8
    mov.l   .L_pool_06011E68, r10
    mov #0x0, r11
    mov.l   .L_pool_06011E6C, r12
    mov.l   .L_pool_06011E70, r14
    bra     .L_06011E44
    extu.w r11, r13
.L_06011DDE:
    mov r13, r2
    mov r13, r3
    shll2 r2
    shll2 r3
    shll r2
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r12, r2
    mov.b @(5, r2), r0
    mov r0, r2
    extu.b r2, r2
    tst r2, r2
    bf      .L_06011E16
    mov.l @r14, r5
    mov r13, r4
    mov r13, r3
    shll2 r4
    shll2 r3
    shll r4
    shll2 r3
    add r3, r4
    exts.w r4, r4
    mov.l   .L_pool_06011E74, r3
    jsr @r3
    add r12, r4
    bra     .L_06011E36
    nop
.L_06011E16:
    mov r13, r9
    mov r13, r3
    mov.l @r14, r5
    shll2 r9
    shll2 r3
    shll r9
    shll2 r3
    add r3, r9
    exts.w r9, r9
    mov.l   .L_pool_06011E78, r3
    add r12, r9
    jsr @r3
    mov r9, r4
    extu.b r11, r2
    mov r2, r0
    mov.b r0, @(5, r9)
.L_06011E36:
    mov.l @r10, r3
    add #0x1, r3
    mov.l r3, @r10
    mov.l @r14, r2
    add #0x20, r2
    mov.l r2, @r14
    add #0x1, r13
.L_06011E44:
    extu.w r13, r3
    mov.w @r8, r2
    extu.w r2, r2
    cmp/ge r2, r3
    bf      .L_06011DDE
    mov.w r11, @r8
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
.L_pool_06011E64:
    .4byte  sym_0605AAA0
.L_pool_06011E68:
    .4byte  sym_0605A008
.L_pool_06011E6C:
    .4byte  sym_060786CC
.L_pool_06011E70:
    .4byte  sym_060785FC
.L_pool_06011E74:
    .4byte  sym_060280F8
.L_pool_06011E78:
    .4byte  sym_060280C4
