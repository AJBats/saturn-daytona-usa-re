
    .section .text.FUN_060334DA


    .global split_position_disp
    .type split_position_disp, @function
split_position_disp:
    sts.l pr, @-r15
    bsr     .L_advance_disp_slot
    nop
    lds.l @r15+, pr
    rts
    nop
    .2byte  0x0000
    .4byte  sym_060338C4
    .4byte  sym_06033874
    .4byte  sym_06062970
    .4byte  sym_0603387C
    .4byte  sym_06033884
    .4byte  sym_060785FC
    .4byte  sym_060280F8
.L_advance_disp_slot:
    .byte   0xD0, 0x04    /* mov.l .L_pool_display_counter, r0 */
    mov.l @r0, r1
    add #0x1, r1
    mov.l r1, @r0
    .byte   0xD2, 0x03    /* mov.l .L_pool_vdp1_write_ptr, r2 */
    mov.l @r2, r1
    add #0x20, r1
    mov.l r1, @r2
    rts
    nop
.L_pool_display_counter:
    .4byte  sym_0605A008
.L_pool_vdp1_write_ptr:
    .4byte  sym_060785FC
    .4byte  0x2F06D409
    .4byte  0x60238143
    .4byte  0xD0081400
    .4byte  0x70018044
    .4byte  0xD0D26002
    .4byte  0x40094009
    .4byte  0x40098045
    .4byte  0xE016340C
    .4byte  0x60F6A15B
    .4byte  0x00090000
    .4byte  sym_06062970
    .4byte  0x00000000
    .4byte  0x2F06D0C8
    .4byte  0x60024008
    .4byte  0xD51F350C
    .4byte  0x655260F6
    .4byte  0x2F06D21E
    .4byte  0x032ED21E
    .4byte  0x042E334C
    .4byte  0xD21D042E
    .4byte  0x334C623B
    .4byte  0x325C2126
