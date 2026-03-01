
    .section .text.FUN_06041180


    .global queue_helper
    .type queue_helper, @function
queue_helper:
    sts.l pr, @-r15
    .byte   0xD3, 0x1E    /* mov.l .L_pool_game_state_ptr, r3 */
    mov.l @r3, r3
    mov.l @(56, r3), r2
    cmp/eq r5, r2
    bt      .L_06041192
    lds.l @r15+, pr
    rts
    mov #-0x9, r0
.L_06041192:
    .byte   0xD3, 0x1B    /* mov.l .L_pool_06041200, r3 */
    jsr @r3
    nop
    mov #0x0, r0
    lds.l @r15+, pr
    rts
    nop
