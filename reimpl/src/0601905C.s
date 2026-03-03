	.text
    .global state_snapshot_compare
state_snapshot_compare:
    sts.l pr, @-r15
    mov.l   .L_pool_0601909C, r14
    mov.l   .L_pool_060190A0, r2
    mov.l r3, @r2
    mov.l   .L_pool_060190A4, r5
    jsr @r14
    mov #0xF, r4
    mov.l   .L_pool_060190A8, r5
    jsr @r14
    mov #0xF, r4
    .byte   0xB1, 0x3A    /* bsr 0x060192E8 (external) */
    nop
    mov.l   .L_pool_060190A0, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_06019088
    mov.l   .L_pool_060190AC, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_pool_060190B0, r3
    mov.w r2, @r3
.L_06019088:
    mov.l   .L_pool_060190A4, r5
    jsr @r14
    mov #0xF, r4
    mov.l   .L_pool_060190B4, r5
    jsr @r14
    mov #0xF, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .short  0xFFFF
.L_pool_0601909C:
    .long  sound_cmd_dispatch
.L_pool_060190A0:
    .long  sym_06086050
.L_pool_060190A4:
    .long  0xAE0001FF
.L_pool_060190A8:
    .long  0xAE0005FF
.L_pool_060190AC:
    .long  sym_06012F10
.L_pool_060190B0:
    .long  0x25A02DBE
.L_pool_060190B4:
    .long  0xAE0600FF
