
    .section .text.FUN_0600F914


    .global transition_handler_c
    .type transition_handler_c, @function
transition_handler_c:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   _pool_fn_sprite_buffer_init, r3
    jsr @r3
    nop
    mov.l   _pool_fn_sound_init_bonus, r3
    jsr @r3
    nop
    mov #0x0, r14
    mov.l   _pool_transition_state_word, r3
    extu.w r14, r2
    mov r14, r6
    mov.w r2, @r3
    mov #0x2, r3
    mov.l   _pool_display_config_word, r1
    mov.w r3, @r1
    mov.l   _pool_fixed_neg_offset, r2
    mov.l   _pool_display_slot_ptr, r3
    mov.l r2, @r3
    mov r3, r5
    mov.l @r5, r5
    mov.l   _pool_fn_display_channel_b, r3
    jsr @r3
    mov #0x10, r4
    mov.l   _pool_fn_render_position_elem, r3
    jsr @r3
    nop
    mov #0x7, r2
    mov.l   _pool_game_state_byte, r3
    mov.b r2, @r3
    mov.l   _pool_transition_state_word, r3
    mov.w r14, @r3
    extu.w r14, r4
    lds.l @r15+, pr
    mov.l   _pool_fn_sprite_batch_renderer, r3
    jmp @r3
    mov.l @r15+, r14
    .2byte  0xFFFF                              /* alignment padding */
    .4byte  sym_0602853E                        /* display layer configuration (unreferenced pool) */
_pool_game_state_byte:
    .4byte  sym_0607887F                        /* &game_state byte (7 = results) */
_pool_fn_sprite_buffer_init:
    .4byte  sprite_buffer_init                  /* sprite command table reset */
_pool_fn_sound_init_bonus:
    .4byte  sound_init_bonus                    /* results/bonus music init */
_pool_transition_state_word:
    .4byte  sym_0607886E                        /* &transition_state_word (16-bit) */
_pool_display_config_word:
    .4byte  sym_0605AAA2                        /* &display_config_word (16-bit) */
_pool_fixed_neg_offset:
    .4byte  0xFEA00000                          /* fixed-point negative offset */
_pool_display_slot_ptr:
    .4byte  sym_0607885C                        /* &display_slot_ptr (32-bit) */
_pool_fn_display_channel_b:
    .4byte  display_channel_b                   /* display channel B enable */
_pool_fn_render_position_elem:
    .4byte  sym_06011450                        /* render_position_elem_16px */
_pool_fn_sprite_batch_renderer:
    .4byte  sprite_batch_renderer               /* sprite batch flush/render */
