
    .section .text.FUN_060362B0


    .global FUN_060362B0
    .type FUN_060362B0, @function
FUN_060362B0:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_pool_06036374, r3
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x42, r3
    extu.b r13, r13
    mov r15, r5
    mov.b r3, @r2
    mov r15, r2
    mov.b @(1, r14), r0
    mov r0, r3
    mov.b r0, @(1, r2)
    mov r15, r3
    mov.b @(2, r14), r0
    mov.b r0, @(2, r3)
    mov r15, r3
    mov.b @(4, r14), r0
    mov r0, r2
    mov.b r0, @(3, r3)
    mov r15, r3
    mov r13, r0
    mov.b r0, @(4, r3)
    mov r15, r3
    mov.b @r14, r2
    mov r2, r0
    mov.b r0, @(5, r3)
    mov r15, r3
    mov.b @(3, r14), r0
    mov.b r0, @(6, r3)
    mov r15, r3
    mov.b @(5, r14), r0
    mov r0, r2
    mov.b r0, @(7, r3)
    mov.l   .L_pool_06036378, r3
    jsr @r3
    mov #0x40, r4
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_06036308
    .type FUN_06036308, @function
FUN_06036308:
    mov.l r14, @-r15
    mov r5, r14
    mov.l r13, @-r15
    mov r4, r13

    .global FUN_06036310
    .type FUN_06036310, @function
FUN_06036310:
    sts.l pr, @-r15
    add #-0x10, r15
    mov r15, r4
    mov.l   .L_pool_06036374, r3
    jsr @r3
    add #0x8, r4
    mov r15, r2
    mov #0x43, r3
    extu.b r13, r13
    mov r15, r6
    mov r15, r5
    add #0x8, r2
    mov r13, r0
    add #0x8, r5
    mov.b r3, @r2
    mov r15, r2
    add #0x8, r2
    mov.b r0, @(4, r2)
    mov.l   .L_pool_0603637C, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    mov r15, r2
    mov.b @(1, r2), r0
    mov r0, r3
    mov.b r0, @(1, r14)
    mov r15, r3
    mov.b @(2, r3), r0
    mov r15, r3
    mov.b r0, @(2, r14)
    mov.b @(3, r3), r0
    mov r15, r3
    mov.b r0, @(4, r14)
    mov.b @(5, r3), r0
    mov r15, r3
    mov r0, r2
    mov.b r2, @r14
    mov.b @(6, r3), r0
    mov r15, r3
    mov.b r0, @(3, r14)
    mov.b @(7, r3), r0
    mov r0, r2
    mov.b r0, @(5, r14)
    mov r4, r0
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_06036374:
    .4byte  FUN_06035E90
.L_pool_06036378:
    .4byte  FUN_06035EC8
.L_pool_0603637C:
    .4byte  FUN_06035EA2
