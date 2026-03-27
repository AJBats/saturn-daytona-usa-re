
    .section .text.FUN_06018E4C


    .global FUN_06018E4C
    .type FUN_06018E4C, @function
FUN_06018E4C:
    sts.l pr, @-r15
    mov #0x3, r4
    mov #0x10, r0
    add #-0x14, r15
    mov r15, r3
    mov r15, r2
    mov.l r4, @r3
    mov r15, r3
    mov.l r4, @(8, r2)
    mov.w   .L_pool_06018EA0, r2
    mov.b r2, @(r0, r3)
    mov.l   .L_pool_06018EA4, r3
    jsr @r3
    mov r15, r4
    add #0x14, r15
    lds.l @r15+, pr
    rts
    nop


    .global FUN_06018E70
    .type FUN_06018E70, @function
FUN_06018E70:
    sts.l pr, @-r15
    mov #0x3, r2
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
.L_pool_06018EA0:
    .4byte  0x00FFFFFF
.L_pool_06018EA4:
    .4byte  FUN_06034D1C
.L_06018EA8:
    .4byte  FUN_06034DEA
