
    .section .text.FUN_06018FFC


    .global restore_state_snapshot
    .type restore_state_snapshot, @function
restore_state_snapshot:
    sts.l pr, @-r15
    mov.l   .L_pool_snd_cmd_dispatch, r14
    mov.l   .L_pool_snd_timeout_flag, r2
    mov.l r3, @r2
    mov.l   .L_pool_cmd_stop, r5
    jsr @r14
    mov #0xF, r4
    mov.l   .L_pool_cmd_sys_variant, r5
    jsr @r14
    mov #0xF, r4
    .byte   0xB1, 0x6A    /* bsr 0x060192E8 (external) */  ! call wait_sound_driver_ready (polls Sound RAM)
    nop
    mov.l   .L_pool_snd_timeout_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_skip_sound_load
    mov.l   .L_pool_load_gamed_sndram, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_pool_snd_driver_ready, r3
    mov.w r2, @r3
.L_skip_sound_load:
    mov.l   .L_pool_cmd_start_bgm, r5
    jsr @r14
    mov #0xF, r4
    mov.l   .L_pool_cmd_stop, r5
    jsr @r14
    mov #0xF, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_pool_snd_cmd_dispatch:
    .4byte  sound_cmd_dispatch
.L_pool_snd_timeout_flag:
    .4byte  sym_06086050
.L_pool_cmd_stop:
    .4byte  0xAE0001FF
.L_pool_cmd_sys_variant:
    .4byte  0xAE0005FF
.L_pool_load_gamed_sndram:
    .4byte  sym_06012EBC
.L_pool_snd_driver_ready:
    .4byte  0x25A02DBE                  /* Sound RAM +0x02DBE */
.L_pool_cmd_start_bgm:
    .4byte  0xAE0600FF
