
    .section .text.FUN_0603273E


    .global hud_laptime_idx_6
    .type hud_laptime_idx_6, @function
hud_laptime_idx_6:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x29    /* mov.l .L_pool_060327EC, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x23    /* mov.l .L_pool_060327D8, r0 */
