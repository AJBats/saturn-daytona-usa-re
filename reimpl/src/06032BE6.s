	.text
    .global hud_rpm_redline
hud_rpm_redline:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x5D    /* mov.l .L_pool_06032D64, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x50    /* mov.l .L_pool_06032D34, r0 */
