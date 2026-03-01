
    .section .text.FUN_060321EE


    .global display_element_table
    .type display_element_table, @function
display_element_table:
    sts.l pr, @-r15
    .byte   0xB6, 0x12    /* bsr 0x06032E18 (external) */
    nop
    lds.l @r15+, pr
    mov.l @r15+, r7
    .byte   0xD0, 0x15    /* mov.l .L_pool_06032250, r0 */
    mov r7, r1
    shll2 r1
    mov.l @(r0, r1), r2
    .byte   0xD1, 0x14    /* mov.l .L_pool_06032254, r1 */
    add r14, r1
    mov.l r7, @-r15
    .byte   0xD6, 0x14    /* mov.l .L_pool_06032258, r6 */
.L_copy_loop:
    mov.b @r2+, r7
    mov.b r7, @r1
    add #0x1, r1
    dt r6
    bf      .L_copy_loop
    mov.l @r15+, r7
    add #0x1, r7
    .byte   0xD0, 0x11    /* mov.l .L_pool_0603225C, r0 */
    cmp/gt r0, r7
    .byte   0x8B, 0xD9    /* bf 0x060321D0 (external) */
    xor r1, r1
    .byte   0xD0, 0x10    /* mov.l .L_pool_06032260, r0 */
    mov.l r1, @r0
    .byte   0xD0, 0x10    /* mov.l .L_pool_06032264, r0 */
    mov.b r1, @r0
    .byte   0xD0, 0x10    /* mov.l .L_pool_06032268, r0 */
    mov.b r1, @r0
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l @r15+, r14
    rts
    nop
    .4byte  sym_060623B0
    .4byte  0x000002DC
    .4byte  0x00000004
    .4byte  0x0000000E
    .4byte  0x00000000
.L_pool_06032257:
    .4byte  sym_06062464
.L_pool_0603225B:
    .4byte  0x000002DE
.L_pool_0603225F:
    .4byte  0x0000000D
.L_pool_06032263:
    .4byte  0x00000005
.L_pool_06032267:
    .4byte  sym_06082A20
.L_pool_0603226B:
    .4byte  sym_06082A24
.L_pool_0603226F:
    .4byte  sym_06082A25
