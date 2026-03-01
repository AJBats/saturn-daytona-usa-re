
    .section .text.FUN_060326BC


    .global hud_laptime_idx_2
    .type hud_laptime_idx_2, @function
hud_laptime_idx_2:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x41    /* mov.l .L_pool_060327CC, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x41    /* mov.l .L_pool_060327D0, r0 */
