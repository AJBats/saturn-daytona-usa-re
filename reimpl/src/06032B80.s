	.text
    .global hud_rpm_bar_idx_2
hud_rpm_bar_idx_2:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x72    /* mov.l .L_pool_06032D54, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x69    /* mov.l .L_pool_06032D34, r0 */
