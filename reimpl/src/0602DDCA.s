
    .section .text.FUN_0602DDCA


    .global vdp1_polyline
    .type vdp1_polyline, @function
vdp1_polyline:
    sts.l pr, @-r15
    jsr @r12
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x35    /* mov.l .L_pool_0602DEA8, r0 */
    cmp/ge r0, r1
    bt      .L_0602DDDA
    neg r1, r1
.L_0602DDDA:
    .byte   0xD0, 0x37    /* mov.l .L_pool_0602DEB8, r0 */
    mov.l r1, @r0
    mov r3, r0
    .byte   0xD1, 0x36    /* mov.l .L_pool_0602DEBC, r1 */
    tst r1, r0
    .byte   0x89, 0x12    /* bt 0x0602DE0C (external) */
    .byte   0xD1, 0x2A    /* mov.l .L_pool_0602DE90, r1 */
    mov.l @r1, r1
    .byte   0xD2, 0x35    /* mov.l .L_pool_0602DEC0, r2 */
    mov.l @r2, r0
    extu.w r0, r0
    mov.l r0, @r2
    sub r0, r1
    mov r4, r0
    .byte   0xDC, 0x2B    /* mov.l .L_pool_0602DEA4, r12 */
