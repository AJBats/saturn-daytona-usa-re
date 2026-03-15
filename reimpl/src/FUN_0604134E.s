
    .section .text.FUN_0604134E


    .global FUN_0604134E
    .type FUN_0604134E, @function
FUN_0604134E:
    sts.l pr, @-r15
    .byte   0xD3, 0x04    /* mov.l .L_pool_06041365, r3 */
    mov.l @r3, r3
    mov.l @(56, r3), r2
    cmp/eq r5, r2
    bt      .L_06041374
    lds.l @r15+, pr
    rts
    mov #-0x9, r0
    .4byte  0x0338033C
.L_pool_06041365:
    .4byte  sym_060A5400
    .4byte  FUN_060349C4
    .4byte  FUN_06034984
    .4byte  sym_06035C4E
.L_06041374:
    .byte   0xD3, 0x1E    /* mov.l @cross-TU pool (FUN_060349B6), r3 */
    jsr @r3
    nop
    mov #0x0, r0
    lds.l @r15+, pr
    rts
    nop
