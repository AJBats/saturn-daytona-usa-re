
    .section .text.FUN_06032816


    .global hud_besttime_idx_1
    .type hud_besttime_idx_1, @function
hud_besttime_idx_1:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x99    /* mov.l .L_pool_06032A84, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x99    /* mov.l .L_pool_06032A88, r0 */
