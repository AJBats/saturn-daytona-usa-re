	.text
    .global position_suffix_render
position_suffix_render:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x05    /* mov.l .L_pool_06032675, r13 */
    mov.l @r13, r13
    rts
    nop
    .short  0x0000
    .long  0x000002D4
    .long  0x0000000D
    .long  sym_06026DBC
.L_pool_06032675:
    .long  sym_06089EDC
    .long  sym_06026F72
    .long  0x000002DE
    .long  camera_push_save
    .long  0x00000030
    .long  sym_06026DF8
    .long  0xDD476DD2
    .long  0xDC47D048
