
    .section .text.FUN_06015AA4


    .global best_lap_display
    .type best_lap_display, @function
best_lap_display:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x8, r13
    mov.w   .L_wpool_06015B40, r14
    mov #0x2, r7
    mov.l   .L_pool_06015B44, r5
    extu.b r4, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r5, r3
    mov #0x1, r1
    mov r1, r0
    mov.b r0, @(1, r3)
    mov #0x0, r6
    extu.b r4, r12
    mov r12, r3
    shll2 r12
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r12
    exts.w r12, r12
    add r5, r12
.L_06015ADE:
    extu.b r6, r2
    mov #0x40, r0
    mov r2, r3
    shll2 r2
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r5, r2
    mov.l r14, @(48, r2)
    mov.b @(r0, r12), r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_06015B14
    extu.b r6, r2
    mov r2, r3
    shll2 r2
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r5, r2
    extu.b r7, r1
    mov r1, r0
    mov.b r0, @(2, r2)
.L_06015B14:
    add #0x1, r6
    extu.b r6, r3
    cmp/ge r13, r3
    bf      .L_06015ADE
    extu.b r4, r4
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r5, r4
    mov.b @(2, r4), r0
    mov r0, r2
    add #0x1, r2
    mov r2, r0
    mov.b r0, @(2, r4)
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_wpool_06015B40:
    .2byte  0xE000                                     /* [HIGH] cap/threshold constant for results display */
    .2byte  0xFFFF
.L_pool_06015B44:
    .4byte  sym_06084FC8
