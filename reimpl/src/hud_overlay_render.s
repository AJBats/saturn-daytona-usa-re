
    .section .text.FUN_0601E2B4


    .global hud_overlay_render
    .type hud_overlay_render, @function
hud_overlay_render:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov #0x0, r12
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    sts.l pr, @-r15
    mov.l   .L_ptr_player_index, r9
    mov.l   .L_ptr_course_size_table, r10
    mov.l   .L_ptr_geom_output_buf, r11
    mov.l   .L_smpc_sf, r13
    mov.l   .L_ptr_geom_busy_flag, r3
    mov.b @r3, r3
    extu.b r3, r3
    tst r3, r3
    bf/s    .L_smpc_resdisa_poll
    mov #0x1, r14
    bra     .L_clear_loop_check
    mov r12, r4
.L_clear_store:
    mov.l @r11, r2
    add r4, r2
    extu.b r12, r3
    mov.b r3, @r2
    add #0x1, r4
.L_clear_loop_check:
    mov.b @r9, r0
    extu.b r0, r0
    shll2 r0
    mov.l @(r0, r10), r3
    cmp/hs r3, r4
    bf      .L_clear_store
.L_smpc_resdisa_poll:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_smpc_resdisa_poll
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x1A, r3
    mov.l   .L_smpc_comreg_ct, r2
    mov.b r3, @r2
.L_smpc_resdisa_wait:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_smpc_resdisa_wait
    mov.l   .L_ptr_dispatch_fn, r3
    mov.l   .L_hud_status_array, r6
    mov.l   .L_ptr_vdp1_param_b, r5
    mov.l   .L_ptr_vdp1_param_a, r4
    mov.l @r3, r3
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    .byte   0xB0, 0x2C    /* bsr 0x0601E37C (external) */
    nop
.L_smpc_resenab_poll:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_smpc_resenab_poll
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x19, r3
    mov.l   .L_smpc_comreg_ct, r2
    mov.b r3, @r2
.L_smpc_resenab_wait:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_smpc_resenab_wait
    lds.l @r15+, pr
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_ptr_player_index:
    .4byte  sym_060877D8
.L_ptr_course_size_table:
    .4byte  sym_0604A5C0
.L_ptr_geom_output_buf:
    .4byte  sym_0605E068
.L_smpc_sf:
    .4byte  0x20100063                  /* SMPC SF — status flag */
.L_ptr_geom_busy_flag:
    .4byte  sym_06087080
.L_smpc_comreg_ct:
    .4byte  0x2010001F                  /* SMPC COMREG (cache-through) */
.L_ptr_dispatch_fn:
    .4byte  sym_06000358
.L_hud_status_array:
    .4byte  sym_06087086
.L_ptr_vdp1_param_b:
    .4byte  sym_0605E064
.L_ptr_vdp1_param_a:
    .4byte  sym_0605E060
