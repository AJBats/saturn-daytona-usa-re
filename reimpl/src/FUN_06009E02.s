
    .section .text.FUN_06009E02


    .global FUN_06009E02
    .type FUN_06009E02, @function
FUN_06009E02:
    sts.l pr, @-r15
    .byte   0xD4, 0x0E    /* mov.l .L_pool_06009E46, r4 */
    mov.l @r4, r3
    add #-0x1, r3
    tst r3, r3
    bf/s    .L_06009E16
    mov.l r3, @r4
    mov #0x1E, r3
    .byte   0xD2, 0x0A    /* mov.l .L_pool_06009E42, r2 */
    mov.l r3, @r2
.L_06009E16:
    .byte   0xD3, 0x0F    /* mov.l .L_pool_06009E5A, r3 */
    jsr @r3
    nop
    .byte   0xD0, 0x07    /* mov.l .L_pool_06009E42, r0 */
    mov.l @r0, r0
    cmp/eq #0x1B, r0
    bt      .L_06009E2A
    .byte   0xD3, 0x0C    /* mov.l .L_pool_06009E5E, r3 */
    jsr @r3
    nop
.L_06009E2A:
    mov #0x1, r2
    .byte   0xD3, 0x0B    /* mov.l .L_pool_06009E62, r3 */
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
