
    .section .text.FUN_0601E636


    .global mat_multiply_helper
    .type mat_multiply_helper, @function
mat_multiply_helper:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    .byte   0xDD, 0x15    /* mov.l .L_smpc_sf, r13 */
    mov #0x1, r14
.L_poll_sf_resdisa:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_poll_sf_resdisa
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x1A, r3
    .byte   0xD2, 0x11    /* mov.l .L_smpc_comreg_ct, r2 */
    mov.b r3, @r2
.L_poll_resdisa_done:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_poll_resdisa_done
    .byte   0xD3, 0x0F    /* mov.l .L_dispatch_table_ptr, r3 — load &dispatch_table_ptr */
    .byte   0xD7, 0x0F    /* mov.l .L_dispatch_data_ptr, r7 — load data pointer for dispatch */
    mov.l @r3, r3
    mov.l @(28, r3), r2
    jsr @r2
    mov #0x10, r6
    mov r0, r6
.L_poll_sf_resenab:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_poll_sf_resenab
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x19, r3
    .byte   0xD2, 0x06    /* mov.l .L_smpc_comreg_ct, r2 */
    mov.b r3, @r2
.L_poll_resenab_done:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_poll_resenab_done
    mov r6, r0
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_smpc_sf:
    .4byte  0x20100063                  /* SMPC SF — status flag */
.L_smpc_comreg_ct:
    .4byte  0x2010001F                  /* SMPC COMREG (cache-through) */
.L_dispatch_table_ptr:
    .4byte  sym_06000354                /* function dispatch table pointer */
.L_dispatch_data_ptr:
    .4byte  sym_060870F4                /* data pointer passed as r7 to dispatch */
