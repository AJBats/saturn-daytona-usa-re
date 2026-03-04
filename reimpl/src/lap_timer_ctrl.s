
    .section .text.FUN_0601228C


    .global lap_timer_ctrl
    .type lap_timer_ctrl, @function

lap_timer_ctrl:
    sts.l pr, @-r15
    mov.l   .L_pool_060122D8, r4
    mov.l @r4, r3
    cmp/ge r2, r3
    bf      .L_060122A2
    .reloc ., R_SH_IND12W, position_vel_limiter - 4
    .2byte 0xB000    /* bsr position_vel_limiter (linker-resolved) */
    nop
    .reloc ., R_SH_IND12W, hud_lap_gfx_update - 4
    .2byte 0xB000    /* bsr hud_lap_gfx_update (linker-resolved) */
    nop
    .reloc ., R_SH_IND12W, race_progress_check - 4
    .2byte 0xA000    /* bra race_progress_check (linker-resolved) */
    lds.l @r15+, pr
.L_060122A2:
    mov #0x64, r3
    mov.l   .L_pool_060122DC, r6
    mov.l @r4, r2
    cmp/ge r3, r2
    bf/s    .L_060122B8
    mov #0x0, r5
    exts.w r5, r5
    .reloc ., R_SH_IND12W, hud_lap_gfx_update - 4
    .2byte 0xB000    /* bsr hud_lap_gfx_update (linker-resolved) */
    mov.w r5, @r6
    .reloc ., R_SH_IND12W, race_progress_check - 4
    .2byte 0xA000    /* bra race_progress_check (linker-resolved) */
    lds.l @r15+, pr
.L_060122B8:
    mov.l @r4, r2
    mov #0x28, r3
    cmp/ge r3, r2
    bf      .L_060122E0
    exts.w r5, r5
    .reloc ., R_SH_IND12W, lap_display_anim - 4
    .2byte 0xB000    /* bsr lap_display_anim (linker-resolved) */
    mov.w r5, @r6
    .reloc ., R_SH_IND12W, race_progress_check - 4
    .2byte 0xA000    /* bra race_progress_check (linker-resolved) */
    lds.l @r15+, pr
    .2byte  0xFFFF
    .4byte  sym_06078636
    .4byte  0xAE110FFF
    .4byte  sound_cmd_dispatch
.L_pool_060122D8:
    .4byte  sym_0607EBCC
.L_pool_060122DC:
    .4byte  sym_060788B2
.L_060122E0:
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
