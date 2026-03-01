
    .section .text.FUN_0602DDF8


    .global vdp1_poly3
    .type vdp1_poly3, @function
vdp1_poly3:
    sts.l pr, @-r15
    jsr @r12
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x29    /* mov.l .L_pool_0602DEA8, r0 */
    cmp/ge r0, r1
    bt      .L_0602DE08
    neg r1, r1
.L_0602DE08:
    .byte   0xD0, 0x2E    /* mov.l .L_pool_0602DEC4, r0 */
    mov.l r1, @r0
    mov r3, r0
    .byte   0xD1, 0x1B    /* mov.l .L_pool_0602DE7C, r1 */
    tst r1, r0
    .byte   0x89, 0x10    /* bt 0x0602DE36 (external) */
    .byte   0xD1, 0x1F    /* mov.l .L_pool_0602DE94, r1 */
    mov.l @r1, r1
    .byte   0xD0, 0x2B    /* mov.l .L_pool_0602DEC8, r0 */
    mov.l @r0, r0
    sub r0, r1
    mov r4, r0
    .byte   0xDC, 0x20    /* mov.l .L_pool_0602DEA4, r12 */
