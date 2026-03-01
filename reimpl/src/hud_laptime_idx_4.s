
    .section .text.FUN_060326D8


    .global hud_laptime_idx_4
    .type hud_laptime_idx_4, @function
hud_laptime_idx_4:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x3E    /* mov.l .L_pool_060327DC, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x3E    /* mov.l .L_pool_060327E0, r0 */
