
    .section .text.FUN_06015D94


    .global lap_progress_bar
    .type lap_progress_bar, @function
lap_progress_bar:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    add #-0x4, r15
    mov.l   .L_pool_06015DE0, r11
    mov #0x8, r12
    mov #0x3, r13
    mov #0x9, r14
    mov.b r4, @r15
    mov #0x0, r4
.L_06015DAA:
    extu.b r4, r5
    extu.b r14, r0
    mov r5, r3
    add #0x1, r4
    shll2 r5
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r5
    exts.w r5, r5
    extu.b r4, r3
    add r11, r5
    mov.b r0, @(2, r5)
    mov #0x41, r0
    cmp/ge r12, r3
    bf/s    .L_06015DAA
    mov.b r13, @(r0, r5)
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_pool_06015DE4, r3
    jmp @r3
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_06015DE0:
    .4byte  sym_06084FC8
.L_pool_06015DE4:
    .4byte  sym_060172E4

    .global loc_06015DE8
loc_06015DE8:
    add #-0x4, r15
    mov.b r4, @r15
    .byte   0xD4, 0x20    /* mov.l .L_pool_06015E70, r4 */
    mov.b @r15, r3
    extu.b r3, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r4, r3
    mov #0x40, r0
    mov.b @(r0, r3), r3
    extu.b r3, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r4, r3
    mov #0x5, r0
    mov.b r0, @(2, r3)
    mov.b @r15, r4
    extu.b r4, r4
    .byte   0xD3, 0x14    /* mov.l .L_pool_06015E74, r3 */
    jmp @r3
    add #0x4, r15
