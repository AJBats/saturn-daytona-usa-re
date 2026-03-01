
    .section .text.FUN_060327FE


    .global hud_besttime_idx_0
    .type hud_besttime_idx_0, @function
hud_besttime_idx_0:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x9C    /* mov.l .L_pool_06032A78, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x9C    /* mov.l .L_pool_06032A7C, r0 */
    add r12, r0
    mov.l @r0+, r4
    mov.l @r0+, r5
    mov.l @r0+, r6
    .byte   0xD0, 0x9A    /* mov.l .L_pool_06032A80, r0 */
