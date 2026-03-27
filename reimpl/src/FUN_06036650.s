
    .section .text.FUN_06036650


    .global FUN_06036650
    .type FUN_06036650, @function
FUN_06036650:
    mov.l r14, @-r15
    mov r4, r14
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_060366F4, r3
    jsr @r3
    mov r5, r13
    mov r0, r4
    extu.w r4, r0
    tst #0x40, r0
    bf      .L_0603666A
    bra     .L_06036676
    mov #-0x1, r0
.L_0603666A:
    mov r13, r6
    mov r14, r5
    mov.l   .L_060366F8, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r4
.L_06036676:
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14


    .global FUN_0603667E
    .type FUN_0603667E, @function
FUN_0603667E:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov r6, r14
    mov.l r12, @-r15
    mov r5, r13


    .global FUN_06036688
    .type FUN_06036688, @function
FUN_06036688:
    sts.l pr, @-r15
    mov r4, r12
    add #-0x10, r15
    mov r15, r4
    mov.l   .L_060366FC, r3
    jsr @r3
    add #0x8, r4
    mov r15, r2
    mov #0x54, r3
    extu.w r13, r13
    extu.b r12, r12
    mov r15, r6
    mov r15, r5
    add #0x8, r2
    mov r13, r0
    add #0x8, r5
    mov.b r3, @r2
    mov r15, r2
    mov r15, r3
    add #0x8, r2
    add #0x8, r3
    mov.w r0, @(2, r2)
    mov r12, r0
    mov.b r0, @(4, r3)
    mov.l   .L_060366F8, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    mov r15, r2
    mov.l @r2, r3
    mov.l   .L_06036700, r2
    and r2, r3
    mov.l r3, @r14
    mov r15, r2
    mov.b @(4, r2), r0
    mov r0, r3
    mov.b r0, @(4, r14)
    mov r15, r3
    mov.b @(5, r3), r0
    mov r15, r3
    mov.b r0, @(5, r14)
    mov.b @(6, r3), r0
    mov r15, r3
    mov.b r0, @(6, r14)
    mov.b @(7, r3), r0
    mov r0, r2
    mov.b r0, @(7, r14)
    mov r4, r0
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_pool_060366F4:
    .4byte  sym_06035C4E
.L_060366F8:
    .4byte  FUN_06035EA2              /* [HIGH] jsr target: digital input processor */
.L_060366FC:
    .4byte  FUN_06035E90               /* [HIGH] jsr target: analog input processor */
.L_06036700:
    .4byte  0x00FFFFFF
