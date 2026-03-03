
    .section .text.FUN_06032B0C


    .global hud_rpm_digit_2
    .type hud_rpm_digit_2, @function
hud_rpm_digit_2:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x88    /* mov.l .L_pool_06032D38, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x88    /* mov.l .L_pool_06032D3C, r0 */
