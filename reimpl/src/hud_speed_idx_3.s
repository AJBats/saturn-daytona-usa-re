
    .section .text.FUN_06032964


    .global hud_speed_idx_3
    .type hud_speed_idx_3, @function
hud_speed_idx_3:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x55    /* mov.l .L_pool_06032AC4, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x49    /* mov.l .L_pool_06032A98, r0 */
