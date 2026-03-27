
    .section .text.FUN_06015D30


    .global FUN_06015D30
    .type FUN_06015D30, @function
FUN_06015D30:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    add #-0x4, r15
    mov #0x5, r11
    mov #0x8, r12
    mov #0x0, r13
    .byte   0xDE, 0x27    /* mov.l .L_pool_06015DE0, r14 */
    mov.b r4, @r15
    extu.b r13, r4
.L_06015D46:
    extu.b r4, r5
    mov r5, r3
    shll2 r5
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r5
    exts.w r5, r5
    add r14, r5
    mov.l r13, @(48, r5)
    mov.b @(2, r5), r0
    extu.b r0, r0
    cmp/eq #0x2, r0
    bf      .L_06015D7A
    extu.b r4, r2
    mov r2, r3
    shll2 r2
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r14, r2
    extu.b r11, r1
    mov r1, r0
    mov.b r0, @(2, r2)
.L_06015D7A:
    add #0x1, r4
    extu.b r4, r3
    cmp/ge r12, r3
    bf      .L_06015D46
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xD3, 0x15    /* mov.l .L_pool_06015DE4, r3 */
    jmp @r3
    mov.l @r15+, r14


    .global FUN_06015D94
    .type FUN_06015D94, @function
FUN_06015D94:
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

    .global FUN_06015DE8
FUN_06015DE8:
    add #-0x4, r15
    mov.b r4, @r15
    mov.l   .L_pool_06015E72, r4
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
    mov.l   .L_pool_06015E76, r3
    jmp @r3
    add #0x4, r15


    .global FUN_06015E26
    .type FUN_06015E26, @function
FUN_06015E26:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    add #-0x4, r15
    mov.l   .L_pool_06015E72, r12
    mov #0x8, r13
    mov #0x0, r14
    mov.b r4, @r15
    extu.b r14, r5
.L_06015E38:
    extu.b r5, r4
    extu.b r13, r0
    mov r4, r3
    add #0x1, r5
    shll2 r4
    shll2 r3
    extu.b r5, r2
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r12, r4
    mov.b r0, @(2, r4)
    mov.l @(52, r4), r3
    mov.l r3, @(4, r4)
    mov.l r14, @(44, r4)
    cmp/ge r13, r2
    bf/s    .L_06015E38
    mov.l r14, @(48, r4)
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_pool_06015E76, r3
    jmp @r3
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_06015E72:
    .4byte  sym_06084FC8
.L_pool_06015E76:
    .4byte  sym_060172E4
