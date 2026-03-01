
    .section .text.FUN_06013C20


    .global bonus_multiplier
    .type bonus_multiplier, @function
bonus_multiplier:
    sts.l pr, @-r15
    mov #0x14, r6
    mov.l   .L_pool_frame_timer, r5
    mov.w @r5, r4
    extu.w r4, r4
    add #0x1, r4
    cmp/gt r6, r4
    bf      .L_under_max
    bra     .L_clamp_done
    mov r6, r3
.L_under_max:
    mov r4, r3
.L_clamp_done:
    extu.w r3, r3
    mov.w r3, @r5
    .byte   0xB1, 0xC3    /* bsr bg_obj_render_loop (external) */
    nop
    .byte   0xA2, 0x95    /* bra race_variant_setup_a (external — tail call) */
    lds.l @r15+, pr
    .2byte  0xFFFF
    .4byte  sym_06084B14
    .4byte  sym_0605B0FC
    .4byte  0xAB1102FF
    .4byte  sym_06084AF2
.L_pool_frame_timer:
    .4byte  sym_06084AF6
