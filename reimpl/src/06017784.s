
    .section .text.FUN_06017784


    .global geom_computation
    .type geom_computation, @function
geom_computation:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r8, @-r15
    sts.l macl, @-r15
    add #-0x4, r15
    mov.l   .L_pool_060177AC, r8
    mov #0x0, r11
    mov.w @r4, r13
    mov.w @(2, r4), r0
    mov r0, r3
    mov.w r3, @r15
    add #0x2, r7
    bra     .L_060177F8
    extu.w r11, r12
    .2byte  0xFFFF
    .4byte  sym_06028400
.L_pool_060177AC:
    .4byte  sym_06085640
.L_060177B0:
    extu.b r7, r10
    mulu.w r13, r12
    extu.w r13, r3
    shll r10
    sts macl, r1
    shll r1
    cmp/pl r3
    bf/s    .L_060177F0
    extu.w r11, r14
.L_060177C2:
    extu.b r6, r0
    mov #0x36, r3
    extu.w r14, r2
    muls.w r3, r0
    shll r2
    add #0x1, r14
    sts macl, r0
    mov #0x4, r3
    add r1, r2
    exts.w r0, r0
    add r4, r2
    add r8, r0
    add r2, r3
    mov.w @r3, r3
    extu.w r5, r2
    extu.w r3, r3
    add r2, r3
    mov.w r3, @(r0, r10)
    extu.w r13, r2
    extu.w r14, r3
    cmp/ge r2, r3
    bf/s    .L_060177C2
    add #0x1, r6
.L_060177F0:
    extu.w r13, r2
    sub r2, r6
    add #0x1, r7
    add #0x1, r12
.L_060177F8:
    extu.w r12, r3
    mov.w @r15, r2
    extu.w r2, r2
    cmp/ge r2, r3
    bf      .L_060177B0
    add #0x4, r15
    lds.l @r15+, macl
    mov.l @r15+, r8
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
