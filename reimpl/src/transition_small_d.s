
    .section .text.FUN_0600FDFE


    .global transition_small_d
    .type transition_small_d, @function
transition_small_d:
    mov.l r14, @-r15
    sts.l pr, @-r15
    .byte   0xDE, 0x09    /* mov.l .L_pool_countdown_ptr, r14 */
    mov.l @r14, r3
    add #-0x1, r3
    cmp/pz r3
    bt/s    .L_epilogue
    mov.l r3, @r14
    .byte   0xD5, 0x07    /* mov.l .L_pool_sound_id, r5 */
    .byte   0xD3, 0x07    /* mov.l .L_pool_fn_sound_cmd, r3 */
    jsr @r3
    mov #0x0, r4
    mov.w   .L_wpool_countdown_reset, r2
    mov.l r2, @r14
    mov #0xF, r3
    .byte   0xD2, 0x05    /* mov.l .L_pool_game_state, r2 */
    mov.b r3, @r2
.L_epilogue:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_wpool_countdown_reset:
    .2byte  0x00B4                           /* [HIGH] countdown reset value: 180 frames */
.L_pool_countdown_ptr:
    .4byte  sym_0607EBCC                     /* [HIGH] &state countdown timer (dword) */
.L_pool_sound_id:
    .4byte  0xAB110DFF                       /* [MEDIUM] sound ID: transition-end sound */
.L_pool_fn_sound_cmd:
    .4byte  sound_cmd_dispatch               /* [HIGH] sound command dispatcher function */
.L_pool_game_state:
    .4byte  sym_0607887F                     /* [HIGH] &game state byte */
