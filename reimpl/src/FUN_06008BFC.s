
    .section .text.FUN_06008BFC


    .global FUN_06008BFC
    .type FUN_06008BFC, @function
FUN_06008BFC:
    sts.l pr, @-r15
    .byte   0xD3, 0x13    /* mov.l .L_pool_06008C4C, r3 */
    jsr @r3
    nop
    tst r0, r0
    bt      .L_06008C0E
    mov #0x6, r3
    .byte   0xD2, 0x0B    /* mov.l .L_pool_06008C38, r2 */
    mov.l r3, @r2
.L_06008C0E:
    lds.l @r15+, pr
    rts
    nop
