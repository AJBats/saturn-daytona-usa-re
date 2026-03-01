
    .section .text.FUN_06016410


    .global results_bonus_calc
    .type results_bonus_calc, @function
results_bonus_calc:
    mov.l r14, @-r15
    mov.l   .L_pool_0601645C, r0
    mov.b @r0, r0
    tst r0, r0
    bt/s    .L_early_return
    mov r4, r14
    mov.l   .L_pool_06016460, r5
    extu.b r14, r4
    mov.w   .L_w_countdown_step, r2
    mov r4, r3
    shll2 r4
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r4
    exts.w r4, r4
    add r5, r4
    mov.l @(48, r4), r3
    add r2, r3
    mov r3, r2
    mov.l r3, @(48, r4)
    cmp/pz r2
    bf      .L_commit_display
    extu.b r14, r2
    mov r2, r3
    shll2 r2
    shll2 r3
    shll2 r3
    shll2 r3
    add r3, r2
    exts.w r2, r2
    add r5, r2
    mov #0x0, r1
    mov.l r1, @(48, r2)
.L_commit_display:
    extu.b r14, r4
    .byte   0xA4, 0xBF    /* bra 0x06016DD8 (external: hud_sprite_vertex_project) */
    mov.l @r15+, r14
.L_w_countdown_step:
    .2byte  0x0800                     /* [HIGH] countdown step per frame */
.L_pool_0601645C:
    .4byte  sym_06085F89               /* [MEDIUM] results-active flag (byte) */
.L_pool_06016460:
    .4byte  sym_06084FC8               /* [HIGH] HUD element slot data array base */
.L_early_return:
    rts
    mov.l @r15+, r14
