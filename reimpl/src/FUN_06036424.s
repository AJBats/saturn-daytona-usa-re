
    .section .text.FUN_06036424


    .global FUN_06036424
    .type FUN_06036424, @function
FUN_06036424:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_pool_060364C8, r3
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x46, r3
    extu.b r14, r14
    extu.b r11, r11
    extu.b r13, r13
    extu.b r12, r12
    mov r15, r5
    mov.b r3, @r2
    mov r14, r0
    mov r15, r2
    mov r15, r3
    mov.b r0, @(1, r2)
    mov r11, r0
    mov.b r0, @(2, r3)
    mov r15, r3
    mov r13, r0
    mov.b r0, @(3, r3)
    mov r15, r3
    mov r12, r0
    mov.b r0, @(4, r3)
    .byte   0xD3, 0x1D    /* mov.l .L_pool_060364CC, r3 */
    jsr @r3
    mov #0x40, r4
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_0603646C
    .type FUN_0603646C, @function
FUN_0603646C:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    mov r6, r13
    mov.l r12, @-r15
    mov r5, r12

    .global FUN_06036478
    .type FUN_06036478, @function
FUN_06036478:
    sts.l pr, @-r15
    add #-0x10, r15
    mov r15, r4
    mov.l   .L_pool_060364C8, r3
    jsr @r3
    add #0x8, r4
    mov r15, r2
    mov #0x47, r3
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
    mov.l   .L_pool_060364D0, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    mov r15, r2
    mov.b @(2, r2), r0
    mov r0, r3
    extu.b r3, r3
    mov.l r3, @r12
    mov r15, r3
    mov.b @(3, r3), r0
    mov r0, r2
    extu.b r2, r2
    mov r4, r0
    mov.l r2, @r13
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_060364C8:
    .4byte  FUN_06035E90
    .4byte  FUN_06035EC8
.L_pool_060364D0:
    .4byte  FUN_06035EA2
