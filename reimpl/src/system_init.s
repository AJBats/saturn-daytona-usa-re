
    .section .text.FUN_060030FC


    .global system_init
    .type system_init, @function
system_init:
    mov.l r14, @-r15
    mov #0x1, r14
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov #0x0, r12
    mov.l r10, @-r15
    sts.l pr, @-r15
    mov.l   .L_bss_end_a, r10
    mov.l   .L_bss_end_b, r11
    mov.l   .L_smpc_sf, r13
    mov.l   .L_fn_subsys_init, r3
    mov.l @r3, r3
    jsr @r3
    mov r14, r4

.L_smpc_wait_ready:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    cmp/eq r14, r2
    bt      .L_smpc_wait_ready
    extu.b r14, r2
    mov.b r2, @r13
    mov #0x19, r3
    mov.l   .L_smpc_comreg_ct, r2
    mov.b r3, @r2
.L_smpc_wait_done:
    mov.b @r13, r2
    extu.b r2, r2
    and r14, r2
    tst r2, r2
    bf      .L_smpc_wait_done

    mov.l   .L_bss_start_a, r4
    bra     .L_bss_a_test
    mov.l @r4, r4
.L_bss_a_store:
    mov.l r12, @r4
    add #0x4, r4
.L_bss_a_test:
    mov.l @r11, r2
    cmp/hs r2, r4
    bf      .L_bss_a_store

    mov.l   .L_bss_start_b, r4
    bra     .L_bss_b_test
    mov.l @r4, r4
    .2byte  0xFFFF

.L_bss_end_a:
    .4byte  sym_06059C58
.L_bss_end_b:
    .4byte  sym_06059C50
.L_smpc_sf:
    .4byte  0x20100063
.L_fn_subsys_init:
    .4byte  sym_06000320
.L_smpc_comreg_ct:
    .4byte  0x2010001F
.L_bss_start_a:
    .4byte  sym_06059C4C
.L_bss_start_b:
    .4byte  sym_06059C54
.L_bss_b_store:
    mov.l r12, @r4
    add #0x4, r4
.L_bss_b_test:
    mov.l @r10, r2
    cmp/hs r2, r4
    bf      .L_bss_b_store

    mov.l   .L_fn_bus_init, r3
    jsr @r3
    mov #0x0, r4
    mov.l   .L_fn_secondary_boot, r3
    jsr @r3
    nop
    mov.l   .L_fn_int_setup, r2
    mov.w   .L_int_mask_boot, r5
    mov.l @r2, r2
    jsr @r2
    mov #-0x1, r4
    mov.l   .L_fn_cd_init, r3
    jsr @r3
    nop
    bsr     vdp_init_dispatch
    nop
    mov.l   .L_fn_engine_init, r3
    jsr @r3
    nop
    mov.l   .L_fn_sound_boot, r3
    jsr @r3
    nop
    bsr     sound_timer_init
    nop
    mov.l   .L_fn_race_sound, r3
    jsr @r3
    nop
    mov.l   .L_fn_int_setup, r2
    mov.w   .L_int_mask_run, r4
    mov.l @r2, r2
    jsr @r2
    mov #0x0, r5
    mov.l   .L_fn_camera_init, r3
    jsr @r3
    nop
    mov.l   .L_fn_display_init, r3
    jsr @r3
    nop
    mov.l   .L_fn_channel_cfg, r3
    jsr @r3
    nop
    mov.l   .L_fn_special_init, r3
    jsr @r3
    nop
    mov #0x2, r2
    mov.l   .L_boot_state, r3
    mov.l r2, @r3
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

.L_int_mask_boot:
    .2byte  0x0083
.L_int_mask_run:
    .2byte  0xFF7C
    .2byte  0xFFFF

.L_fn_bus_init:
    .4byte  sym_0603BF7C
.L_fn_secondary_boot:
    .4byte  sym_06034E58
.L_fn_int_setup:
    .4byte  sym_06000344
.L_fn_cd_init:
    .4byte  cd_progress_notify
.L_fn_engine_init:
    .4byte  engine_init_global
.L_fn_sound_boot:
    .4byte  sound_scsp_boot
.L_fn_race_sound:
    .4byte  race_sound_handler
.L_fn_camera_init:
    .4byte  sym_06005174
.L_fn_display_init:
    .4byte  sym_0601F936
.L_fn_channel_cfg:
    .4byte  channel_config_a
.L_fn_special_init:
    .4byte  sym_060149E0
.L_boot_state:
    .4byte  g_game_state

    .global sound_timer_init
    .type sound_timer_init, @function
sound_timer_init:
    sts.l pr, @-r15
    mov.l   .L_fn_vector_setup, r3
    mov.l   .L_fn_frt_handler, r5
    mov.l @r3, r3
    jsr @r3
    mov #0x65, r4
    mov.w   .L_frt_tier, r5
    mov.b @r5, r4
    mov #0xF, r2
    and r2, r4
    extu.b r4, r0
    or #0x8, r0
    extu.b r0, r0
    mov.b r0, @r5
    mov.w   .L_frt_ftcsr, r6
    mov.b @r6, r4
    mov #0x1, r5
    extu.b r4, r4
    or r5, r4
    extu.b r4, r4
    mov.b r4, @r6
    mov.w   .L_frt_tcr, r4
    mov.b @r4, r3
    extu.b r3, r3
    mov #-0x4, r2
    and r2, r3
    mov.b r3, @r4
    add #0x1, r4
    mov.b @r4, r3
    extu.b r3, r3
    mov #-0x11, r2
    and r2, r3
    extu.b r3, r3
    mov.b r3, @r4
    mov.w   .L_frt_ocra, r3
    mov.b r5, @r3
    mov #0x66, r2
    add #0x1, r3
    mov #0x0, r4
    mov.b r2, @r3
    add #-0x3, r3
    mov.b r4, @r3
    add #0x1, r3
    lds.l @r15+, pr
    rts
    mov.b r4, @r3

    .global vdp_init_dispatch
    .type vdp_init_dispatch, @function
vdp_init_dispatch:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_fn_vector_setup, r14

    mov.l   .L_fn_vblank_in, r5
    mov.l @r14, r3
    jsr @r3
    mov #0x4, r4
    mov.l @r14, r2
    mov.l   .L_fn_vblank_out, r5
    jsr @r2
    mov #0x6, r4
    mov.l @r14, r3
    mov.l   .L_fn_sprite_end, r5
    jsr @r3
    mov #0x9, r4

    mov.l @r14, r2
    mov.l   .L_fn_vblank_in, r5
    mov.w   .L_vec_vbi_secondary, r4
    jsr @r2
    nop
    mov.l @r14, r3
    mov.l   .L_fn_vblank_out, r5
    mov.w   .L_vec_vbo_secondary, r4
    jsr @r3
    nop
    mov.l @r14, r2
    mov.l   .L_fn_sprite_end, r5
    mov.w   .L_vec_sde_secondary, r4
    lds.l @r15+, pr
    jmp @r2
    mov.l @r15+, r14

.L_frt_tier:
    .2byte  0xFE10
.L_frt_ftcsr:
    .2byte  0xFE11
.L_frt_tcr:
    .2byte  0xFE16
.L_frt_ocra:
    .2byte  0xFE14
.L_vec_vbi_secondary:
    .2byte  0x0104
.L_vec_vbo_secondary:
    .2byte  0x0106
.L_vec_sde_secondary:
    .2byte  0x0109

.L_fn_vector_setup:
    .4byte  sym_06000310
.L_fn_frt_handler:
    .4byte  sym_060072E4
.L_fn_vblank_in:
    .4byte  sym_06028218
.L_fn_vblank_out:
    .4byte  sym_06028230
.L_fn_sprite_end:
    .4byte  sym_06028248
