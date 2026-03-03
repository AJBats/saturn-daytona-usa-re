
    .section .text.FUN_0603275A


    .global hud_laptime_idx_8
    .type hud_laptime_idx_8, @function
hud_laptime_idx_8:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x24    /* mov.l .L_pool_060327F4, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x1A    /* mov.l .L_pool_060327D0, r0 */
