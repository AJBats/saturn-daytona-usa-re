
    .section .text.FUN_0601B418


    .global disc_load_complete_check
    .type disc_load_complete_check, @function
disc_load_complete_check:
    sts.l pr, @-r15
    mov.l   .L_pool_disc_load_phase, r3
    mov.l   .L_pool_disc_state_table, r2
    mov.b @r3, r3
    extu.b r3, r3
    shll2 r3
    add r2, r3
    mov.l @r3, r3
    jsr @r3
    nop
    mov.w   .L_wpool_display_config_flags, r2
    mov.l r2, @-r15
    mov.l   .L_pool_fp_one, r3
    mov.l r3, @-r15
    mov.l   .L_pool_fp_half, r2
    mov.l r2, @-r15
    mov.l   .L_pool_wram_low_base, r7
    mov.l   .L_pool_minit_comm, r5
    mov.l   .L_pool_fn_rigid_body_transform, r3
    mov r7, r6
    jsr @r3
    mov r5, r4
    mov.l   .L_pool_fn_frame_end_commit, r3
    jsr @r3
    add #0xC, r15
    mov.l   .L_pool_tex_load_progress, r4
    mov.w @r4, r2
    add #0x1, r2
    mov.w r2, @r4
    mov.l   .L_pool_disc_load_status, r0
    lds.l @r15+, pr
    rts
    mov.b @r0, r0
.L_wpool_display_config_flags:
    .2byte  0x0101                      /* [MEDIUM] display config: flags byte pair (0x01, 0x01) */
.L_pool_disc_load_status:
    .4byte  sym_0608600C
    .4byte  sym_0608600E
    .4byte  handler_dispatch
.L_pool_disc_load_phase:
    .4byte  sym_0608600D
.L_pool_disc_state_table:
    .4byte  sym_0605DEB4
.L_pool_fp_one:
    .4byte  0x00010000                  /* 1.0 (16.16 fixed-point) */
.L_pool_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_pool_wram_low_base:
    .4byte  0x00200000                  /* Work RAM Low base */
.L_pool_minit_comm:
    .4byte  0x01000000                  /* MINIT — primary SH-2 init comm */
.L_pool_fn_rigid_body_transform:
    .4byte  rigid_body_transform
.L_pool_fn_frame_end_commit:
    .4byte  frame_end_commit
.L_pool_tex_load_progress:
    .4byte  sym_0605D4F8
