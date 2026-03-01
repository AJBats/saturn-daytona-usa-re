
    .section .text.FUN_0602DDA0


    .global vdp1_line_draw
    .type vdp1_line_draw, @function
vdp1_line_draw:
    sts.l pr, @-r15
    jsr @r12
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x3F    /* mov.l .L_pool_0602DEA8, r0 */
    cmp/ge r0, r1
    bt      .L_0602DDB0
    neg r1, r1
.L_0602DDB0:
    .byte   0xD0, 0x3E    /* mov.l .L_pool_0602DEAC, r0 */
    mov.l r1, @r0
    mov r3, r0
    .byte   0xD1, 0x3E    /* mov.l .L_pool_0602DEB0, r1 */
    tst r1, r0
    .byte   0x89, 0x10    /* bt 0x0602DDDE (external) */
    .byte   0xD1, 0x33    /* mov.l .L_pool_0602DE8C, r1 */
    mov.l @r1, r1
    .byte   0xD0, 0x3C    /* mov.l .L_pool_0602DEB4, r0 */
    mov.l @r0, r0
    sub r0, r1
    mov r4, r0
    .byte   0xDC, 0x36    /* mov.l .L_pool_0602DEA4, r12 */
