
    .section .text.FUN_0600F822


    .global transition_small_a
    .type transition_small_a, @function
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
    .4byte  0x0800FFFF                   /* unreferenced pool data (padding) */
    .4byte  sym_06085FF4                 /* unreferenced pool: &2p_mode_flag */
    .4byte  g_pad_state                 /* unreferenced pool: &input_state */
    .4byte  sym_06078663                 /* unreferenced pool data */
.L_pool_0600F85E:
    .4byte  0xAB1101FF                   /* sound ID: transition sound */
.L_pool_0600F862:
    .4byte  sound_cmd_dispatch           /* sound command dispatcher */
.L_pool_0600F866:
    .4byte  anim_ui_transition           /* UI animation transition function */
.L_pool_0600F86A:
    .4byte  hud_course_render            /* HUD course rendering function */
.L_pool_0600F86E:
    .4byte  sym_0607887C                 /* &transition countdown timer (16-bit word) */
.L_pool_0600F872:
    .4byte  sym_0607887F                 /* &game state byte (0x3 = race setup) */
