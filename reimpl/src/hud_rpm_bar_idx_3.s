
    .section .text.FUN_06032B8E


    .global hud_rpm_bar_idx_3
    .type hud_rpm_bar_idx_3, @function
hud_rpm_bar_idx_3:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x70    /* mov.l .L_pool_06032D58, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x68    /* mov.l .L_pool_06032D3C, r0 */
