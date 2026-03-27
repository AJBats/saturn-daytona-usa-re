
    .section .text.FUN_06014868


    .global FUN_06014868
    .type FUN_06014868, @function
FUN_06014868:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l r5, @r15
    mov.l   .L_pool_060148E4, r3
    jsr @r3
    mov.l r6, @(4, r15)
    mov.l @(4, r15), r5
    mov.l   .L_pool_060148E8, r3
    jsr @r3
    mov.l @r15, r4
    add #0x8, r15
    mov.l   .L_pool_060148EC, r3
    jmp @r3
    lds.l @r15+, pr


    .global FUN_06014884
    .type FUN_06014884, @function
FUN_06014884:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l r5, @r15
    mov.l   .L_pool_060148E4, r3
    jsr @r3
    mov.l r6, @(4, r15)
    mov #0x0, r6
    mov.l @(4, r15), r5
    mov.l   .L_pool_060148F0, r3
    jsr @r3
    mov.l @r15, r4
    add #0x8, r15
    mov.l   .L_pool_060148EC, r3
    jmp @r3
    lds.l @r15+, pr


    .global FUN_060148A2
    .type FUN_060148A2, @function
FUN_060148A2:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_060148F6, r13
    mov.l   .L_pool_060148FA, r14
    mov.w   .L_wpool_060148E4, r4
    jsr @r14
    mov.b @r13, r5
    mov.b @(1, r13), r0
    mov r0, r5
    jsr @r14
    mov #0x4, r4
    mov.b @(2, r13), r0
    mov r0, r5
    jsr @r14
    mov #0x8, r4
    mov.b @(3, r13), r0
    mov r0, r5
    jsr @r14
    mov #0x10, r4
    mov.b @(4, r13), r0
    mov r0, r5
    jsr @r14
    mov #0x20, r4
    mov.b @(5, r13), r0
    mov r0, r5
    jsr @r14
    mov #0x1, r4
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_wpool_060148E4:
    .2byte  0x0100
.L_pool_060148E4:
    .4byte  sym_0603850C
.L_pool_060148E8:
    .4byte  FUN_06038794
.L_pool_060148EC:
    .4byte  sym_06038520
.L_pool_060148F0:
    .4byte  FUN_0603853C
.L_pool_060148F6:
    .4byte  sym_0605B71C
.L_pool_060148FA:
    .4byte  FUN_06038BD4
