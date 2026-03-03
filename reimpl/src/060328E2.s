
    .section .text.FUN_060328E2


    .global hud_speed_decimal
    .type hud_speed_decimal, @function
hud_speed_decimal:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x70    /* mov.l .L_pool_06032AAC, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x68    /* mov.l .L_pool_06032A90, r0 */
