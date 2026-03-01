
    .section .text.FUN_0601E770


    .global mat_transpose
    .type mat_transpose, @function
mat_transpose:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_smpc_sf, r13
    mov.w r0, @(4, r15)
    mov.l r6, @r15
    mov.l   .L_fn_strlen, r3
    jsr @r3
    mov r12, r4
    mov #0xB, r2
    cmp/gt r2, r0
    bf      .L_name_ok
    mov #0x0, r2
    mov r2, r0
    mov.b r0, @(11, r12)
.L_name_ok:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_name_ok
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
    mov r12, r5
    mov.w @(4, r15), r0
    mov.l @r15, r6
    mov.l @r3, r3
    mov r0, r4
    mov.l @(20, r3), r2
    extu.w r4, r4
    mov.l   .L_hud_element_array, r3
    shll2 r4
    shll2 r4
    shll r4
    add r3, r4
    mov.w @(28, r4), r0
    mov r0, r4
    jsr @r2
    extu.w r4, r4
    mov r0, r4
.L_poll_sf_set_resenab:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_poll_sf_set_resenab
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
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_smpc_sf:
    .4byte  0x20100063                  /* SMPC SF — status flag */
.L_fn_strlen:
    .4byte  sym_06035C1C
.L_smpc_comreg_ct:
    .4byte  0x2010001F                  /* SMPC COMREG (cache-through) */
.L_dispatch_table_ptr:
    .4byte  sym_06000354
.L_hud_element_array:
    .4byte  sym_06087094
