	.text
    .global hud_rpm_digit_1
hud_rpm_digit_1:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x8A    /* mov.l .L_pool_06032D30, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x8A    /* mov.l .L_pool_06032D34, r0 */
