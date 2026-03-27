
    .section .text.FUN_06009DD0


    .global FUN_06009DD0
    .type FUN_06009DD0, @function
FUN_06009DD0:
    sts.l pr, @-r15
    .byte   0xD3, 0x19    /* mov.l .L_pool_06009E38, r3 */
    jsr @r3
    nop
    mov #0x1B, r2
    mov.l   .L_pool_06009E42, r3
    mov.l r2, @r3
    .byte   0x92, 0x29    /* mov.w .L_wpool_06009E34, r2 */
    mov.l   .L_pool_06009E46, r3
    mov.l r2, @r3
    .byte   0xD3, 0x17    /* mov.l .L_pool_06009E44, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x17    /* mov.l .L_pool_06009E48, r3 */
    jsr @r3
    nop
    mov #0x3, r2
    .byte   0xD3, 0x16    /* mov.l .L_pool_06009E4C, r3 */
    mov.w r2, @r3
    mov #0x0, r6
    mov #0x13, r5
    mov r5, r4
    .byte   0xD3, 0x14    /* mov.l .L_pool_06009E50, r3 */
    jmp @r3
    lds.l @r15+, pr


    .global FUN_06009E02
    .type FUN_06009E02, @function
FUN_06009E02:
    sts.l pr, @-r15
    mov.l   .L_pool_06009E46, r4
    mov.l @r4, r3
    add #-0x1, r3
    tst r3, r3
    bf/s    .L_06009E16
    mov.l r3, @r4
    mov #0x1E, r3
    mov.l   .L_pool_06009E42, r2
    mov.l r3, @r2
.L_06009E16:
    mov.l   .L_pool_06009E5A, r3
    jsr @r3
    nop
    mov.l   .L_pool_06009E42, r0
    mov.l @r0, r0
    cmp/eq #0x1B, r0
    bt      .L_06009E2A
    mov.l   .L_pool_06009E5E, r3
    jsr @r3
    nop
.L_06009E2A:
    mov #0x1, r2
    mov.l   .L_pool_06009E62, r3
    lds.l @r15+, pr
    rts
    mov.b r2, @r3
    .4byte  0x0258FFFF
    .4byte  FUN_060190B8
.L_pool_06009E42:
    .4byte  FUN_0605ACC4
.L_pool_06009E46:
    .4byte  sym_0607EBCC
    .4byte  sym_06028560
    .4byte  FUN_06012F80
    .4byte  sym_0605A016
    .4byte  FUN_06018DDC
.L_pool_06009E5A:
    .4byte  FUN_0601389E
.L_pool_06009E5E:
    .4byte  FUN_06018E70
.L_pool_06009E62:
    .4byte  sym_0607864B
