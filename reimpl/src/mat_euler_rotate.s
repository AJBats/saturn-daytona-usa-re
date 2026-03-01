
    .section .text.FUN_0601E6E0


    .global mat_euler_rotate
    .type mat_euler_rotate, @function
mat_euler_rotate:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_smpc_sf, r13
    mov #0x1, r14
    mov.l r4, @r15
.L_poll_sf_pre_resdisa:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_poll_sf_pre_resdisa
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x1A, r3
    mov.l   .L_smpc_comreg_ct, r2
    mov.b r3, @r2
.L_poll_resdisa_done:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_poll_resdisa_done
    mov.l   .L_dispatch_table_ptr, r3
    mov.l @r15, r4
    mov.l @r3, r3
    shll2 r4
    mov.l @(24, r3), r2
    shll2 r4
    mov.l   .L_hud_element_array, r3
    shll r4
    add r3, r4
    mov.w @(28, r4), r0
    mov r0, r4
    jsr @r2
    extu.w r4, r4
    mov r0, r4
.L_poll_sf_pre_resenab:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_poll_sf_pre_resenab
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x19, r3
    mov.l   .L_smpc_comreg_ct, r2
    mov.b r3, @r2
.L_poll_resenab_done:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_poll_resenab_done
    mov r4, r0
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_smpc_sf:
    .4byte  0x20100063                  /* SMPC SF — status flag */
.L_smpc_comreg_ct:
    .4byte  0x2010001F                  /* SMPC COMREG (cache-through) */
.L_dispatch_table_ptr:
    .4byte  sym_06000354                /* function dispatch table pointer */
.L_hud_element_array:
    .4byte  sym_06087094                /* HUD element array (0x20 bytes per element) */
