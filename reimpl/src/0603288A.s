	.text
    .global hud_speed_tens
hud_speed_tens:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x84    /* mov.l .L_pool_06032AA4, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x7E    /* mov.l .L_pool_06032A90, r0 */
