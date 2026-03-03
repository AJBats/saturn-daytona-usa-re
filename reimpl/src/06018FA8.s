	.text
    .global save_state_snapshot
save_state_snapshot:
    sts.l pr, @-r15
    mov.l   .L_pool_06018FE0, r14
    mov.l   .L_pool_06018FE4, r2
    mov.l r3, @r2
    mov.l   .L_pool_06018FE8, r5
    jsr @r14
    mov #0xF, r4
    mov.l   .L_pool_06018FEC, r5
    jsr @r14
    mov #0xF, r4
    .byte   0xB1, 0x94    /* bsr 0x060192E8 (external) */
    nop
    mov.l   .L_pool_06018FE4, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_06018FD4
    mov.l   .L_pool_06018FF0, r3
    jsr @r3
    nop
    mov #0x0, r2
    mov.l   .L_pool_06018FF4, r3
    mov.w r2, @r3
.L_06018FD4:
    mov.l   .L_pool_06018FE8, r5
    jsr @r14
    mov #0xF, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_pool_06018FE0:
    .long  sound_cmd_dispatch
.L_pool_06018FE4:
    .long  sym_06086050
.L_pool_06018FE8:
    .long  0xAE0001FF
.L_pool_06018FEC:
    .long  0xAE0005FF
.L_pool_06018FF0:
    .long  sym_06012EDC
.L_pool_06018FF4:
    .long  0x25A02DBE
