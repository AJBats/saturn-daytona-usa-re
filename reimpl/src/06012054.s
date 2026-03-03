	.text
    .global file_seek
file_seek:
    sts.l pr, @-r15
    mov.l   .L_pool_0601207C, r14
    jsr @r14
    mov #0x10, r4
    mov #0x6, r5
    jsr @r14
    mov #0x8, r4
    mov.w   .L_wpool_0601207A, r4
    jsr @r14
    mov #0x5, r5
    mov #0x3, r5
    jsr @r14
    mov #0x20, r4
    mov #0x1, r5
    jsr @r14
    mov #0x4, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_wpool_0601207A:
    .short  0x0100
.L_pool_0601207C:
    .long  channel_nibble_config
