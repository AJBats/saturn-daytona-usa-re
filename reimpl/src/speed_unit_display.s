
    .section .text.FUN_06015E26


    .global speed_unit_display
    .type speed_unit_display, @function
speed_unit_display:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    add #-0x4, r15
    .byte   0xDC, 0x10    /* mov.l .L_pool_06015E72, r12 */
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
    .byte   0xD3, 0x02    /* mov.l .L_pool_06015E76, r3 */
    jmp @r3
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_06015E72:
    .4byte  sym_06084FC8
.L_pool_06015E76:
    .4byte  sym_060172E4
