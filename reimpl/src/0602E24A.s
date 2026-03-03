
    .section .text.FUN_0602E24A


    .global vdp2_priority_b
    .type vdp2_priority_b, @function
vdp2_priority_b:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    .byte   0xD0, 0x1B    /* mov.l .L_pool_0602E2C4, r0 */
    mov.l @r0, r0
    .byte   0xDD, 0x1B    /* mov.l .L_pool_0602E2C8, r13 */
