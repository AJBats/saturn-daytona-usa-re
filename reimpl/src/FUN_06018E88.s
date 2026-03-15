
    .section .text.FUN_06018E88


    .global FUN_06018E88
    .type FUN_06018E88, @function
FUN_06018E88:
    sts.l pr, @-r15
    mov #0x0, r2
    add #-0x8, r15
    mov r15, r3
    mov.l r2, @r3
    mov.l   .L_06018EA8, r3
    jsr @r3
    mov r15, r4
    add #0x8, r15
    lds.l @r15+, pr
    rts
    nop
    .4byte  0x00FFFFFF
    .4byte  FUN_06034D1C
.L_06018EA8:
    .4byte  FUN_06034DEA
