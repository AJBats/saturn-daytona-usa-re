	.text
    .global race_utility_func
race_utility_func:
    sts.l pr, @-r15
    .byte   0xD4, 0x06    /* mov.l .L_0601937C, r4 */
    .byte   0xD3, 0x08    /* mov.l .L_06019384, r3 */
    mov.l @r4, r2
    or r3, r2
    .byte   0xD3, 0x07    /* mov.l .L_06019388, r3 */
    jsr @r3
    mov.l r2, @r4
    .byte   0xD3, 0x06    /* mov.l .L_06019388, r3 */
    jmp @r3
    lds.l @r15+, pr
    .long  0x0100FFFF
    .long  channel_nibble_config
.L_0601937C:
    .long  sym_0605B6D8
    .long  0x40000000
.L_06019384:
    .long  0x80000000
.L_06019388:
    .long  sym_06026CE0
