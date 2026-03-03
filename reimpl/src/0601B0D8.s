
    .section .text.FUN_0601B0D8


    .global course_state_setup
    .type course_state_setup, @function
course_state_setup:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_pool_0601B154, r8
    mov #0x5, r10
    mov.l   .L_pool_0601B158, r13
    mov.l   .L_pool_0601B15C, r14
    mov #0x0, r4
    extu.w r4, r11
    extu.w r4, r12
.L_0601B0F8:
    mov r8, r7
    mov #0x60, r6
    extu.w r12, r9
    mov.l r9, @r15
    add #0x6, r9
    shll2 r9
    shll2 r9
    shll2 r9
    mov r9, r5
    add #0x2, r5
    shll r5
    jsr @r14
    mov #0x8, r4
    mov r13, r7
    mov #0x60, r6
    mov.l @r15, r5
    add #0x7, r5
    shll2 r5
    shll2 r5
    shll2 r5
    add #0x21, r5
    shll r5
    jsr @r14
    mov #0x8, r4
    mov r13, r7
    mov #0x60, r6
    mov r9, r5
    add #0x25, r5
    shll r5
    jsr @r14
    mov #0xC, r4
    add #0x1, r11
    extu.w r11, r3
    cmp/ge r10, r3
    bf/s    .L_0601B0F8
    add #0x3, r12
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_pool_0601B154:
    .4byte  sym_0604A490
.L_pool_0601B158:
    .4byte  sym_0604A4B8
.L_pool_0601B15C:
    .4byte  sym_060284AE
