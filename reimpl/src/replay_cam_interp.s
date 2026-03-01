
    .section .text.FUN_0601AFA4


    .global replay_cam_interp
    .type replay_cam_interp, @function
replay_cam_interp:
    sts.l pr, @-r15
    .byte   0xB0, 0x97    /* bsr 0x0601B0D8 (external) */  ! call course_state_setup
    nop
    mov #0x60, r6
    mov.l   .L_pool_geom_dispatch, r3
    mov.l   .L_pool_tex_data_buf, r7
    mov r6, r5
    add #0x36, r5
    jsr @r3
    mov #0x8, r4
    mov.l   .L_pool_tex_data_buf, r7
    mov #0x60, r6
    mov.w   .L_w_ext_fill_offset, r5
    mov #0x8, r4
    mov.l   .L_pool_geom_dispatch, r3
    jmp @r3
    lds.l @r15+, pr
.L_w_ext_fill_offset:
    .2byte  0x0196                     /* [HIGH] extended fill offset */
    .4byte  sym_0608600F               /* [MEDIUM] phase_countdown_timer (global byte) */
    .4byte  sym_06086011               /* [MEDIUM] phase_index (global byte) */
.L_pool_tex_data_buf:
    .4byte  sym_0604A480               /* [MEDIUM] course texture data buffer */
.L_pool_geom_dispatch:
    .4byte  sym_060284AE               /* [HIGH] geom_dispatch_final fn */
