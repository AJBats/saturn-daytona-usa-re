
    .section .text.FUN_06032C4C


    .global hud_gear_idx_1
    .type hud_gear_idx_1, @function
hud_gear_idx_1:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x47    /* mov.l .L_pool_06032D74, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x34    /* mov.l .L_pool_06032D2C, r0 */
