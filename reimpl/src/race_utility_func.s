
    .section .text.FUN_0601935E


    .global race_utility_func
    .type race_utility_func, @function
race_utility_func:
    sts.l pr, @-r15
    .byte   0xD4, 0x06    /* mov.l .L_display_flags_ptr, r4 */
    .byte   0xD3, 0x08    /* mov.l .L_bit31_mask, r3 */
    mov.l @r4, r2
    or r3, r2
    .byte   0xD3, 0x07    /* mov.l .L_display_update_fn, r3 */
    jsr @r3
    mov.l r2, @r4
    .byte   0xD3, 0x06    /* mov.l .L_display_update_fn, r3 */
    jmp @r3
    lds.l @r15+, pr
    .4byte  0x0100FFFF
    .4byte  channel_nibble_config
.L_display_flags_ptr:
    .4byte  sym_0605B6D8
    .4byte  0x40000000
.L_bit31_mask:
    .4byte  0x80000000
.L_display_update_fn:
    .4byte  sym_06026CE0
