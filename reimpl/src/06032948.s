
    .section .text.FUN_06032948


    .global hud_speed_idx_1
    .type hud_speed_idx_1, @function
hud_speed_idx_1:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x5A    /* mov.l .L_pool_06032ABC, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x4C    /* mov.l .L_pool_06032A88, r0 */
