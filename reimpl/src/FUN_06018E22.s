
    .section .text.FUN_06018E22


    .global FUN_06018E22
    .type FUN_06018E22, @function
FUN_06018E22:
    sts.l pr, @-r15
    mov r4, r0
    add #-0x8, r15
    mov r15, r3
    mov.l r2, @r3
    mov r15, r3
    mov.b r0, @(4, r3)
    mov r15, r3
    mov #0x1, r0
    mov.b r0, @(5, r3)
    .byte   0xD3, 0x04    /* mov.l .L_06018E48, r3 */
    jsr @r3
    mov r15, r4
    add #0x8, r15
    lds.l @r15+, pr
    rts
    nop
    .4byte  FUN_06034D1C
.L_06018E48:
    .4byte  FUN_06034DEA
