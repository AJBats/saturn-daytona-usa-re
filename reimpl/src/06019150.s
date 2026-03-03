
    .section .text.FUN_06019150


    .global transition_fade_ctrl
    .type transition_fade_ctrl, @function
transition_fade_ctrl:
    sts.l pr, @-r15
    .byte   0xDE, 0x1C    /* mov.l .L_pool_060191C4, r14 */
    .byte   0xD2, 0x1C    /* mov.l .L_pool_060191C8, r2 */
    mov.l r3, @r2
    .byte   0xD5, 0x1C    /* mov.l .L_pool_060191CC, r5 */
    jsr @r14
    mov #0xF, r4
    .byte   0xD5, 0x1C    /* mov.l .L_pool_060191D0, r5 */
    jsr @r14
    mov #0xF, r4
    .byte   0xB0, 0xC0    /* bsr 0x060192E8 (external) */
    nop
    .byte   0xD0, 0x17    /* mov.l .L_pool_060191C8, r0 */
    mov.l @r0, r0
    tst r0, r0
    bf      .L_0601917C
    .byte   0xD3, 0x18    /* mov.l .L_pool_060191D4, r3 */
    jsr @r3
    nop
    mov #0x0, r2
    .byte   0xD3, 0x17    /* mov.l .L_pool_060191D8, r3 */
    mov.w r2, @r3
.L_0601917C:
    .byte   0xD5, 0x13    /* mov.l .L_pool_060191CC, r5 */
    jsr @r14
    mov #0xF, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
