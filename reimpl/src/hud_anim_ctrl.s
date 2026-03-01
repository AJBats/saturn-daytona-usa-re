
    .section .text.FUN_06015482


    .global hud_anim_ctrl
    .type hud_anim_ctrl, @function
hud_anim_ctrl:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.b r4, @r15
    mov #0x0, r4
    .byte   0xD2, 0x18    /* mov.l .L_pool_display_enable_byte, r2 */  ! r2 -> display enable flag (byte)
    exts.b r4, r3
    extu.w r4, r4
    mov.b r3, @r2
    .byte   0xD2, 0x17    /* mov.l .L_pool_hud_status_word, r2 */  ! r2 -> HUD status word
    mov.w r4, @r2
    .byte   0xD4, 0x17    /* mov.l .L_pool_display_flags, r4 */  ! r4 -> display flags (32-bit)
    mov.l @r4, r0
    or #0x1, r0
    mov.l r0, @r4
    .byte   0xD0, 0x16    /* mov.l .L_pool_attract_timer, r0 */  ! r0 -> attract timer
    mov.l @r0, r0
    tst r0, r0
    bf      .L_set_post_race_state
    .byte   0xD3, 0x15    /* mov.l .L_pool_car_array_base, r3 */  ! r3 -> car array base pointer
    mov.w   .L_wpool_car_lap_offset, r0
    mov.l @r3, r3
    mov.l @(r0, r3), r2
    mov #0x3, r3
    cmp/ge r3, r2
    bf      .L_check_display_status
.L_set_post_race_state:
    .byte   0xD2, 0x12    /* mov.l .L_pool_display_status_word, r2 */  ! r2 -> display status word
    mov.w @r2, r3
    mov.w   .L_wpool_status_bit_mask, r2
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt      .L_use_display_init_state
.L_check_display_status:
    mov #0x16, r3
    .byte   0xD2, 0x0F    /* mov.l .L_pool_game_state, r2 */  ! r2 -> game state variable
    mov.l r3, @r2
    bra     .L_call_stub_and_exit
    nop
.L_use_display_init_state:
    mov #0x18, r3
    .byte   0xD2, 0x0D    /* mov.l .L_pool_game_state, r2 */  ! r2 -> game state variable
    mov.l r3, @r2
.L_call_stub_and_exit:
    .byte   0xD3, 0x0D    /* mov.l .L_pool_fn_transition_stub, r3 */  ! r3 -> transition stub (rts/nop)
    jsr @r3
    nop
    mov.b @r15, r4
    extu.b r4, r4
    add #0x4, r15
    .byte   0xD3, 0x02    /* mov.l .L_pool_fn_clear_vdp2_regs, r3 */  ! r3 -> clear_vdp2_registers
    jmp @r3
    lds.l @r15+, pr
.L_wpool_car_lap_offset:
    .2byte  0x0224
.L_wpool_status_bit_mask:
    .2byte  0x0400
.L_pool_fn_clear_vdp2_regs:
    .4byte  sym_060172E4
.L_pool_display_enable_byte:
    .4byte  sym_06085F8A
.L_pool_hud_status_word:
    .4byte  sym_06085F92
.L_pool_display_flags:
    .4byte  sym_0607EBF4
.L_pool_attract_timer:
    .4byte  sym_0607EAE0
.L_pool_car_array_base:
    .4byte  sym_0607E944
.L_pool_display_status_word:
    .4byte  sym_06063DA0
.L_pool_game_state:
    .4byte  g_game_state
.L_pool_fn_transition_stub:
    .4byte  sym_0601E0DE
