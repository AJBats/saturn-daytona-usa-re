	.text
    .global transition_small_a
transition_small_a:
    sts.l pr, @-r15
    .byte   0xD5, 0x0C    /* mov.l .L_pool_0600F85E, r5 */
    .byte   0xD3, 0x0D    /* mov.l .L_pool_0600F862, r3 */
    jsr @r3
    mov #0x0, r4
    .byte   0xD3, 0x0C    /* mov.l .L_pool_0600F866, r3 */
    jsr @r3
    mov #0x0, r4
    .byte   0xD3, 0x0C    /* mov.l .L_pool_0600F86A, r3 */
    jsr @r3
    nop
    mov #0x78, r2
    .byte   0xD3, 0x0B    /* mov.l .L_pool_0600F86E, r3 */
    mov.w r2, @r3
    mov #0x3, r2
    .byte   0xD3, 0x0A    /* mov.l .L_pool_0600F872, r3 */
    lds.l @r15+, pr
    rts
    mov.b r2, @r3
    .long  0x0800FFFF
    .long  sym_06085FF4
    .long  g_pad_state
    .long  sym_06078663
.L_pool_0600F85E:
    .long  0xAB1101FF
.L_pool_0600F862:
    .long  sound_cmd_dispatch           /* sound command dispatcher */
.L_pool_0600F866:
    .long  anim_ui_transition
.L_pool_0600F86A:
    .long  hud_course_render
.L_pool_0600F86E:
    .long  sym_0607887C
.L_pool_0600F872:
    .long  sym_0607887F
