	.text
    .global util_wrapper
util_wrapper:
    sts.l pr, @-r15
    .byte   0xB2, 0x76    /* bsr 0x06014F34 (external) */
    nop
    .byte   0xD3, 0x09    /* mov.l .L_pool_06014A71, r3 */
    jmp @r3
    lds.l @r15+, pr
    .short  0x0260
    .long  0x25C00000
    .long  sym_06044B64
    .long  sym_06059FFC
    .long  memcpy_word_idx
    .long  vdp2_loop_ctrl
    .long  sym_0607EBF4
    .long  sym_06085F90
    .long  sym_06085F94
.L_pool_06014A71:
    .long  vdp2_util_loop
