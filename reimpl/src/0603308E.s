	.text
    .global disp_util_stub_b
disp_util_stub_b:
    sts.l pr, @-r15
    bsr     .L_060330A0
    nop
    lds.l @r15+, pr
    rts
    nop
    .short  0x0000
    .long  sym_06033864
.L_060330A0:
    .byte   0xD0, 0x28    /* mov.l .L_pool_06033144, r0 */
    mov.l @r0, r0
