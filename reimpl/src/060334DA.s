	.text
    .global split_position_disp
split_position_disp:
    sts.l pr, @-r15
    bsr     .L_06033504
    nop
    lds.l @r15+, pr
    rts
    nop
    .short  0x0000
    .long  sym_060338C4
    .long  sym_06033874
    .long  sym_06062970
    .long  sym_0603387C
    .long  sym_06033884
    .long  sym_060785FC
    .long  sym_060280F8
.L_06033504:
    .byte   0xD0, 0x04    /* mov.l .L_pool_0603351A, r0 */
    mov.l @r0, r1
    add #0x1, r1
    mov.l r1, @r0
    .byte   0xD2, 0x03    /* mov.l .L_pool_0603351E, r2 */
    mov.l @r2, r1
    add #0x20, r1
    mov.l r1, @r2
    rts
    nop
.L_pool_0603351A:
    .long  sym_0605A008
.L_pool_0603351E:
    .long  sym_060785FC
    .long  0x2F06D409
    .long  0x60238143
    .long  0xD0081400
    .long  0x70018044
    .long  0xD0D26002
    .long  0x40094009
    .long  0x40098045
    .long  0xE016340C
    .long  0x60F6A15B
    .long  0x00090000
    .long  sym_06062970
    .long  0x00000000
    .long  0x2F06D0C8
    .long  0x60024008
    .long  0xD51F350C
    .long  0x655260F6
    .long  0x2F06D21E
    .long  0x032ED21E
    .long  0x042E334C
    .long  0xD21D042E
    .long  0x334C623B
    .long  0x325C2126
