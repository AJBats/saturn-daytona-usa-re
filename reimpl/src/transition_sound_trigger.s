
    .section .text.FUN_0601918C


    .global transition_sound_trigger
    .type transition_sound_trigger, @function
transition_sound_trigger:
    sts.l pr, @-r15
    mov.l   .L_pool_060191C4, r14
    mov.l   .L_pool_060191C8, r2
    mov.l r3, @r2
    mov.l   .L_pool_060191CC, r5
    jsr @r14
    mov #0xF, r4
    mov.l   .L_pool_060191D0, r5
    jsr @r14
    mov #0xF, r4
    .byte   0xB0, 0xA2    /* bsr 0x060192E8 (external) */  ! call wait_sound_driver_ready
    nop
    mov.l   .L_pool_060191C8, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_skip_music_load
    mov.l   .L_pool_060191DC, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_pool_060191D8, r3
    mov.w r2, @r3
.L_skip_music_load:
    mov.l   .L_pool_060191CC, r5
    jsr @r14
    mov #0xF, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_pool_060191C4:
    .4byte  sound_cmd_dispatch
.L_pool_060191C8:
    .4byte  sym_06086050
.L_pool_060191CC:
    .4byte  0xAE0001FF
.L_pool_060191D0:
    .4byte  0xAE0005FF
    .4byte  sym_06012F58
.L_pool_060191D8:
    .4byte  0x25A02DBE                  /* Sound RAM +0x02DBE */
.L_pool_060191DC:
    .4byte  sym_06012F60
