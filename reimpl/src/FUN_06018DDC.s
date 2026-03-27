
    .section .text.FUN_06018DDC


    .global FUN_06018DDC
    .type FUN_06018DDC, @function
FUN_06018DDC:
    sts.l pr, @-r15
    mov #0x2, r7
    extu.b r4, r4
    extu.b r5, r5
    extu.b r6, r6
    add #-0x14, r15
    mov r4, r0
    mov r15, r3
    mov r15, r2
    mov.l r7, @r3
    mov.b r0, @(4, r2)
    mov r15, r3
    mov #0x1, r2
    mov r2, r0
    mov.b r0, @(5, r3)
    mov r15, r2
    mov r15, r3
    mov r5, r0
    mov.l r7, @(8, r3)
    mov r15, r3
    mov.b r0, @(12, r2)
    mov #0x63, r0
    mov.b r0, @(13, r3)
    mov r15, r3
    mov #0x10, r0
    mov.b r6, @(r0, r3)
    mov.l   .L_pool_06018E44, r3
    jsr @r3
    mov r15, r4
    add #0x14, r15
    lds.l @r15+, pr
    rts
    nop

    .global sym_06018E1E
sym_06018E1E:
    mov #0x2, r2
    extu.b r4, r4


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
    mov.l   .L_06018E48, r3
    jsr @r3
    mov r15, r4
    add #0x8, r15
    lds.l @r15+, pr
    rts
    nop
.L_pool_06018E44:
    .4byte  FUN_06034D1C
.L_06018E48:
    .4byte  FUN_06034DEA
