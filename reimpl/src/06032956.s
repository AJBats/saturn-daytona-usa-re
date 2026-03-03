	.text
    .global hud_speed_idx_2
hud_speed_idx_2:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x58    /* mov.l .L_pool_06032AC0, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x4B    /* mov.l .L_pool_06032A90, r0 */
