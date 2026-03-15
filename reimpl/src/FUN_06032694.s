
    .section .text.FUN_06032694


    .global FUN_06032694
    .type FUN_06032694, @function
FUN_06032694:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x43    /* mov.l .L_pool_060327AC, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x45    /* mov.l .L_pool_060327B8, r0 */
