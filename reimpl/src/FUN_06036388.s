
    .section .text.FUN_06036388


    .global FUN_06036388
    .type FUN_06036388, @function
FUN_06036388:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_pool_06036408, r3
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x44, r3
    extu.b r14, r14
    extu.b r13, r13
    mov r15, r5
    mov.b r3, @r2
    mov r14, r0
    mov r15, r2
    mov r15, r3
    mov.b r0, @(1, r2)
    mov r13, r0
    mov.b r0, @(4, r3)
    .byte   0xD3, 0x18    /* mov.l .L_pool_0603640C, r3 */
    jsr @r3
    mov #0x40, r4
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_060363BC
    .type FUN_060363BC, @function
FUN_060363BC:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    mov r5, r13

    .global FUN_060363C4
    .type FUN_060363C4, @function
FUN_060363C4:
    sts.l pr, @-r15
    add #-0x10, r15
    mov r15, r4
    mov.l   .L_pool_06036408, r3
    jsr @r3
    add #0x8, r4
    mov r15, r2
    mov #0x45, r3
    extu.b r14, r14
    mov r15, r6
    mov r15, r5
    add #0x8, r2
    mov r14, r0
    add #0x8, r5
    mov.b r3, @r2
    mov r15, r2
    add #0x8, r2
    mov.b r0, @(4, r2)
    mov.l   .L_pool_06036410, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    mov r15, r2
    mov.b @(1, r2), r0
    mov r0, r3
    extu.b r3, r3
    mov r4, r0
    mov.l r3, @r13
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_06036408:
    .4byte  FUN_06035E90
    .4byte  FUN_06035EC8
.L_pool_06036410:
    .4byte  FUN_06035EA2
