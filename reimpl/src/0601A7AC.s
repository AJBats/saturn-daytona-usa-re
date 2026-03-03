	.text
    .global preview_camera_target
preview_camera_target:
    sts.l pr, @-r15
    mov.l   .L_pool_0601A800, r5
    mov.l   .L_pool_0601A804, r4
    mov.w   .L_0601A7E2, r2
    mov.w @(2, r4), r0
    mov r0, r3
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_0601A7C8
    mov #0x0, r3
    mov.b r3, @r5
    bra     .L_0601A7DA
    nop
.L_0601A7C8:
    mov.w @(2, r4), r0
    mov.l   .L_pool_0601A808, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_0601A7DA
    mov #0x1, r3
    mov.b r3, @r5
.L_0601A7DA:
    .byte   0xBF, 0x40    /* bsr 0x0601A65E (external) */
    nop
    .byte   0xAF, 0xAE    /* bra 0x0601A73E (external) */
    lds.l @r15+, pr
.L_0601A7E2:
    .short  0x4000
    .long  sym_06085FF6
    .long  sym_06012EC4
    .long  sym_06012F00
    .long  sym_06085FF7
    .long  race_variant_e
    .long  0xAE0001FF
    .long  sound_cmd_dispatch
.L_pool_0601A800:
    .long  sym_0605D241
.L_pool_0601A804:
    .long  g_pad_state
.L_pool_0601A808:
    .long  0x00008000
