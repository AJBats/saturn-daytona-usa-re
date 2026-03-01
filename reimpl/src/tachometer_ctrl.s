
    .section .text.FUN_06010AA4


    .global tachometer_ctrl
    .type tachometer_ctrl, @function

tachometer_ctrl:
    mov.l r14, @-r15
    extu.w r4, r2
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov.l   .L_countdown_timer_ptr, r14
    mov.l @r14, r3
    add #-0x1, r3
    mov.l r3, @r14
    mov.w   .L_wpool_06010ACC, r3
    and r3, r2
    tst r2, r2
    bt/s    .L_button_not_pressed
    mov #0x0, r13
    extu.b r13, r3
    mov.l   .L_game_state_ptr, r2
    mov.b r3, @r2
    bra     .L_epilogue
    nop
    .4byte  0x00C00800                      /* [LOW] unreferenced from this TU — preceding function's pool residue */
.L_wpool_06010ACC:
    .2byte  0x0100
    .2byte  0xFFFF                          /* [LOW] unreferenced from this TU — padding or adjacent pool entry */
    .4byte  sym_0605D05C                    /* [LOW] unreferenced from this TU — ptr to unknown data */
    .4byte  sym_06059FFC                    /* [MEDIUM] unreferenced from this TU — ptr to VDP1 cmd index (game state index) */
    .4byte  sym_06063F5C                    /* [MEDIUM] unreferenced from this TU — ptr to VDP1 cmd buffer base */
    .4byte  memcpy_word_idx                 /* [HIGH] unreferenced from this TU — fn ptr to memcpy_word_idx */
    .4byte  sym_0607EAE0                    /* [MEDIUM] unreferenced from this TU — ptr to demo/hud_active flag */
.L_countdown_timer_ptr:
    .4byte  sym_0607EBCC
.L_game_state_ptr:
    .4byte  sym_0607887F

.L_button_not_pressed:
    .byte   0x95, 0x40    /* mov.w .L_wpool_06010B70, r5 — countdown threshold [HIGH] */
    mov.l @r14, r3
    cmp/gt r5, r3
    bt      .L_epilogue
    mov.l @r14, r3
    cmp/pl r3
    bf      .L_update_display_mode
    extu.w r4, r4
    .byte   0x93, 0x39    /* mov.w .L_wpool_06010B72, r3 — button B bit mask [HIGH] */
    and r3, r4
    tst r4, r4
    bt      .L_epilogue

.L_update_display_mode:
    .byte   0xD5, 0x1D    /* mov.l .L_pool_06010B7C, r5 — &hud_element_index [HIGH] */
    .byte   0xD3, 0x1E    /* mov.l .L_pool_06010B80, r3 — &game_mode_word [HIGH] */
    mov.w @r3, r2
    mov.w r2, @r5
    mov.w @r5, r4
    .byte   0x93, 0x31    /* mov.w .L_wpool_06010B74, r3 — invalid mode sentinel A [MEDIUM] */
    extu.w r4, r4
    cmp/eq r3, r4
    bt      .L_reset_mode_to_zero
    .byte   0x93, 0x2E    /* mov.w .L_wpool_06010B76, r3 — invalid mode sentinel B [MEDIUM] */
    cmp/eq r3, r4
    bt      .L_reset_mode_to_zero
    mov r4, r0
    cmp/eq #0x4, r0
    bf      .L_call_hud_draw

.L_reset_mode_to_zero:
    extu.w r13, r2
    mov.w r2, @r5

.L_call_hud_draw:
    .byte   0xB0, 0x15    /* bsr 0x06010B54 (external) */
    mov.l r13, @r14
    mov #0xA, r4
    .byte   0xD3, 0x15    /* mov.l .L_pool_06010B84, r3 — &game_state_byte [HIGH] */
    extu.b r4, r2
    mov.b r2, @r3
    .byte   0xD1, 0x15    /* mov.l .L_pool_06010B88, r1 — &frame_index [MEDIUM] */
    mov.l @r1, r1
    cmp/hs r4, r1
    bt      .L_epilogue
    .byte   0xD7, 0x14    /* mov.l .L_pool_06010B8C, r7 — display_channel_base [MEDIUM] */
    .byte   0x96, 0x1C    /* mov.w .L_wpool_06010B78, r6 — display byte count [MEDIUM] */
    .byte   0x95, 0x1C    /* mov.w .L_wpool_06010B7A, r5 — VRAM target offset [MEDIUM] */
    mov #0xC, r4
    lds.l @r15+, pr
    mov.l @r15+, r13
    .byte   0xD3, 0x12    /* mov.l .L_pool_06010B90, r3 — &display_elem_renderer [HIGH] */
    jmp @r3
    mov.l @r15+, r14

.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
