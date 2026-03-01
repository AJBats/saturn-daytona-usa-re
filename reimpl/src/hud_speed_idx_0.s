
    .section .text.FUN_06032930


    .global hud_speed_idx_0
    .type hud_speed_idx_0, @function
hud_speed_idx_0:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x4F    /* mov.l .L_pool_06032A78, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x5E    /* mov.l .L_pool_06032AB8, r0 */
    add r12, r0
    mov.l @r0+, r4
    mov.l @r0+, r5
    mov.l @r0+, r6
    .byte   0xD0, 0x4E    /* mov.l .L_pool_06032A80, r0 */
