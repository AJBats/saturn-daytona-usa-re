
    .section .text.FUN_06014884


    .global display_channel_b
    .type display_channel_b, @function
display_channel_b:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l r5, @r15
    .byte   0xD3, 0x16    /* mov.l .L_pool_060148E4, r3 */
    jsr @r3
    mov.l r6, @(4, r15)
    mov #0x0, r6
    mov.l @(4, r15), r5
    .byte   0xD3, 0x16    /* mov.l .L_pool_060148F0, r3 */
    jsr @r3
    mov.l @r15, r4
    add #0x8, r15
    .byte   0xD3, 0x13    /* mov.l .L_pool_060148EC, r3 */
    jmp @r3
    lds.l @r15+, pr
