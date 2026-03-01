
    .section .text.FUN_06032AF0


    .global hud_rpm_digit_0
    .type hud_rpm_digit_0, @function
hud_rpm_digit_0:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x8B    /* mov.l .L_pool_06032D28, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x8B    /* mov.l .L_pool_06032D2C, r0 */
