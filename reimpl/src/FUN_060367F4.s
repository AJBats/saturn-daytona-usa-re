
    .section .text.FUN_060367F4


    .global FUN_060367F4
    .type FUN_060367F4, @function
FUN_060367F4:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_06036834, r3
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x61, r3
    extu.w r14, r14
    extu.b r12, r12
    extu.w r13, r13
    mov.b r3, @r2
    mov r14, r0
    mov r15, r2
    mov r15, r3
    mov.w r0, @(2, r2)
    mov r12, r0
    mov.b r0, @(4, r3)
    mov r15, r3
    mov r13, r0
    mov.w r0, @(6, r3)
    mov.w   .L_06036832, r4
    mov.l   .L_06036838, r3
    jsr @r3
    mov r15, r5
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_06036832:
    .2byte  0x0080
.L_06036834:
    .4byte  FUN_06035E90
.L_06036838:
    .4byte  FUN_06035EC8
