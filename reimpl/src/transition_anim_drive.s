
    .section .text.FUN_060190F8


    .global transition_anim_drive
    .type transition_anim_drive, @function
transition_anim_drive:
    sts.l pr, @-r15
    mov.l   .L_pool_snd_cmd_dispatch, r14
    mov.l   .L_pool_snd_busy_flag, r2
    mov.l r3, @r2
    mov.l   .L_pool_cmd_stop, r5
    jsr @r14
    mov #0xF, r4
    mov.l   .L_pool_cmd_sys_variant, r5
    jsr @r14
    mov #0xF, r4
    .byte   0xB0, 0xEC    /* bsr 0x060192E8 (external) */  ! BSR to wait_sound_ready — polls 0x25A02DBE for 0xFFFF
    nop
    mov.l   .L_pool_snd_busy_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_timeout_skip
    mov.l   .L_pool_fn_load_musicd, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_pool_snd_ready_mailbox, r3
    mov.w r2, @r3
.L_timeout_skip:
    mov.l   .L_pool_cmd_stop, r5
    jsr @r14
    mov #0xF, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_pool_snd_cmd_dispatch:
    .4byte  sound_cmd_dispatch                  /* sound command dispatch function */
.L_pool_snd_busy_flag:
    .4byte  sym_06086050                        /* sound busy/timeout flag — nonzero = error */
.L_pool_cmd_stop:
    .4byte  0xAE0001FF                          /* sound stop command (channel 00, cmd 01) */
.L_pool_cmd_sys_variant:
    .4byte  0xAE0005FF                          /* system variant command (channel 00, cmd 05) */
    .4byte  sym_06012F20                        /* (unused in this TU) load_namd_sndram */
.L_pool_snd_ready_mailbox:
    .4byte  0x25A02DBE                          /* Sound RAM driver-ready mailbox */
.L_pool_fn_load_musicd:
    .4byte  sym_06012F50                        /* load_musicd_sndram — loads MUSICD.BIN to Sound RAM +0x3000 */
