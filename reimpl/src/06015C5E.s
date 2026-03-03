
    .section .text.FUN_06015C5E


    .global time_delta_format
    .type time_delta_format, @function
time_delta_format:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    add #-0x4, r15
    .byte   0xDC, 0x0E    /* mov.l .L_pool_06015CA2, r12 */
    mov.w   .L_wpool_06015C9E, r13
    mov #0x8, r14
    mov.b r4, @r15
    mov #0x0, r4
.L_06015C70:
    extu.b r4, r3
    mov r3, r2
    add #0x1, r4
    shll2 r3
    shll2 r2
    shll2 r2
    shll2 r2
    add r2, r3
    exts.w r3, r3
    add r12, r3
    mov.l r13, @(48, r3)
    extu.b r4, r3
    cmp/ge r14, r3
    bf      .L_06015C70
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    mov.l @r15+, r12
    mov.l @r15+, r13
    .byte   0xD3, 0x04    /* mov.l .L_pool_06015CAA, r3 */
    jmp @r3
    mov.l @r15+, r14
.L_wpool_06015C9E:
    .2byte  0xE000
    .2byte  0xFFFF
.L_pool_06015CA2:
    .4byte  sym_06084FC8
    .4byte  sym_0605B8B0
.L_pool_06015CAA:
    .4byte  sym_060172E4
