
    .section .text.FUN_0601228C


    .global lap_timer_ctrl
    .type lap_timer_ctrl, @function

lap_timer_ctrl:
    sts.l pr, @-r15
    mov.l   .L_pool_060122D8, r4
    mov.l @r4, r3
    cmp/ge r2, r3
    bf      .L_not_finishing
    .byte   0xB0, 0x2D    /* bsr 0x060122F4 (external) */
    nop
    .byte   0xB1, 0x37    /* bsr 0x0601250C (external) */
    nop
    .byte   0xA2, 0x37    /* bra 0x06012710 (external) */
    lds.l @r15+, pr
.L_not_finishing:
    mov #0x64, r3
    mov.l   .L_pool_060122DC, r6
    mov.l @r4, r2
    cmp/ge r3, r2
    bf/s    .L_below_100
    mov #0x0, r5
    exts.w r5, r5
    .byte   0xB1, 0x2C    /* bsr 0x0601250C (external) */
    mov.w r5, @r6
    .byte   0xA2, 0x2C    /* bra 0x06012710 (external) */
    lds.l @r15+, pr
.L_below_100:
    mov.l @r4, r2
    mov #0x28, r3
    cmp/ge r3, r2
    bf      .L_initialize
    exts.w r5, r5
    .byte   0xB1, 0x85    /* bsr 0x060125D0 (external) */
    mov.w r5, @r6
    .byte   0xA2, 0x23    /* bra 0x06012710 (external) */
    lds.l @r15+, pr
    .2byte  0xFFFF
    .4byte  sym_06078636
    .4byte  0xAE110FFF
    .4byte  sound_cmd_dispatch
.L_pool_060122D8:
    .4byte  sym_0607EBCC
.L_pool_060122DC:
    .4byte  sym_060788B2
.L_initialize:
    mov #0x1, r5
    mov #0x10, r2
    mov.l r5, @r4
    exts.b r5, r5
    .byte   0xD3, 0x10    /* mov.l .L_pool_0601232C, r3 */
    mov.l r2, @r3
    .byte   0xD3, 0x10    /* mov.l .L_pool_06012330, r3 */
    lds.l @r15+, pr
    rts
    mov.b r5, @r3
