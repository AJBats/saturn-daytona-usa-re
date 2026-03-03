
    .section .text.FUN_060204B4


    .global obj_list_iterate
    .type obj_list_iterate, @function
obj_list_iterate:
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD3, 0x16    /* mov.l .L_pool_06020514, r3 */
    jsr @r3
    mov.b r4, @r15
    .byte   0xD3, 0x16    /* mov.l .L_pool_06020518, r3 */
    jsr @r3
    nop
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    .byte   0xA4, 0x90    /* bra 0x06020DEE (external) */
    lds.l @r15+, pr

    .global sym_060204CE
sym_060204CE:
    mov #0x0, r5
