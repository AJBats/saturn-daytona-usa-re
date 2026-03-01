
    .section .text.FUN_0601E6E0


    .global mat_euler_rotate
    .type mat_euler_rotate, @function
mat_euler_rotate:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_0601E754, r13
    mov #0x1, r14
    mov.l r4, @r15
.L_0601E6EE:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_0601E6EE
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x1A, r3
    mov.l   .L_0601E758, r2
    mov.b r3, @r2
.L_0601E702:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_0601E702
    mov.l   .L_0601E75C, r3
    mov.l @r15, r4
    mov.l @r3, r3
    shll2 r4
    mov.l @(24, r3), r2
    shll2 r4
    mov.l   .L_0601E760, r3
    shll r4
    add r3, r4
    mov.w @(28, r4), r0
    mov r0, r4
    jsr @r2
    extu.w r4, r4
    mov r0, r4
.L_0601E728:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_0601E728
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x19, r3
    mov.l   .L_0601E758, r2
    mov.b r3, @r2
.L_0601E73C:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_0601E73C
    mov r4, r0
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_0601E754:
    .4byte  0x20100063                  /* SMPC SF — status flag */
.L_0601E758:
    .4byte  0x2010001F                  /* SMPC COMREG (cache-through) */
.L_0601E75C:
    .4byte  sym_06000354                /* function dispatch table pointer */
.L_0601E760:
    .4byte  sym_06087094                /* HUD element array (0x20 bytes per element) */
