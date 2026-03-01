
    .section .text.FUN_060148A2


    .global display_channels_load
    .type display_channels_load, @function
display_channels_load:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    .byte   0xDD, 0x12    /* mov.l .L_pool_060148F6, r13 */
    .byte   0xDE, 0x13    /* mov.l .L_pool_060148FA, r14 */
    mov.w   .L_wpool_060148E4, r4
    jsr @r14
    mov.b @r13, r5
    mov.b @(1, r13), r0
    mov r0, r5
    jsr @r14
    mov #0x4, r4
    mov.b @(2, r13), r0
    mov r0, r5
    jsr @r14
    mov #0x8, r4
    mov.b @(3, r13), r0
    mov r0, r5
    jsr @r14
    mov #0x10, r4
    mov.b @(4, r13), r0
    mov r0, r5
    jsr @r14
    mov #0x20, r4
    mov.b @(5, r13), r0
    mov r0, r5
    jsr @r14
    mov #0x1, r4
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_wpool_060148E4:
    .2byte  0x0100                      /* [HIGH] channel bitmask: array_a[0] low nibble (primary) */
    .4byte  sym_0603850C
    .4byte  scene_color_intensity
    .4byte  sym_06038520
    .4byte  scene_data_write_abs
.L_pool_060148F6:
    .4byte  sym_0605B71C
.L_pool_060148FA:
    .4byte  channel_nibble_config
