
    .section .text.FUN_06018E70


    .global FUN_06018E70
    .type FUN_06018E70, @function
FUN_06018E70:
    sts.l pr, @-r15
    mov #0x3, r2
    add #-0x8, r15
    mov r15, r3
    mov.l r2, @r3
    .byte   0xD3, 0x0B    /* mov.l .L_pool_06018EA8, r3 */
    jsr @r3
    mov r15, r4
    add #0x8, r15
    lds.l @r15+, pr
    rts
    nop
