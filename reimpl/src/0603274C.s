
    .section .text.FUN_0603274C


    .global hud_laptime_idx_7
    .type hud_laptime_idx_7, @function
hud_laptime_idx_7:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x26    /* mov.l .L_pool_060327F0, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x21    /* mov.l .L_pool_060327E0, r0 */
