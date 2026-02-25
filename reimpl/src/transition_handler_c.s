/* transition_handler_c -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0600F914 - 0x0600F98C
 *
 * Results screen transition initializer — called when a race ends to set up
 * the results/bonus display. Resets sprite buffers, initializes bonus sound,
 * configures a display channel for the results overlay, renders the position
 * element, and advances game_state to 7 (results). Tail-calls
 * sprite_batch_renderer to flush the initial frame.
 *
 * Sequence:
 *   1. sprite_buffer_init() — clear sprite command table
 *   2. sound_init_bonus()  — start results/bonus music
 *   3. Clear transition_state_word (sym_0607886E) = 0
 *   4. Set display_config_word (sym_0605AAA2) = 2
 *   5. Store fixed-point offset 0xFEA00000 into display_slot_ptr (sym_0607885C)
 *   6. display_channel_b(0x10, display_slot_ptr, 0) — enable channel for results
 *   7. render_position_elem_16px() — draw position overlay element
 *   8. Set game_state (sym_0607887F) = 7 (results screen)
 *   9. Clear transition_state_word again
 *  10. Tail-call sprite_batch_renderer(0) — flush sprites
 */

    .section .text.FUN_0600F914


    .global transition_handler_c
    .type transition_handler_c, @function
transition_handler_c:
    mov.l r14, @-r15                    ! save r14 (callee-saved)
    sts.l pr, @-r15                     ! save return address
    mov.l   _pool_fn_sprite_buffer_init, r3 ! r3 = &sprite_buffer_init
    jsr @r3                             ! sprite_buffer_init() — clear sprite cmd table
    nop                                 ! (delay slot)
    mov.l   _pool_fn_sound_init_bonus, r3   ! r3 = &sound_init_bonus
    jsr @r3                             ! sound_init_bonus() — start results music
    nop                                 ! (delay slot)
    mov #0x0, r14                       ! r14 = 0 (zero constant for clearing state)
    mov.l   _pool_transition_state_word, r3 ! r3 = &transition_state_word
    extu.w r14, r2                      ! r2 = 0 (zero-extended word)
    mov r14, r6                         ! r6 = 0 (arg3 for display_channel_b later)
    mov.w r2, @r3                       ! transition_state_word = 0 (clear)
    mov #0x2, r3                        ! r3 = 2
    mov.l   _pool_display_config_word, r1   ! r1 = &display_config_word
    mov.w r3, @r1                       ! display_config_word = 2 (results mode)
    mov.l   _pool_fixed_neg_offset, r2  ! r2 = 0xFEA00000 (fixed-point offset)
    mov.l   _pool_display_slot_ptr, r3  ! r3 = &display_slot_ptr
    mov.l r2, @r3                       ! *display_slot_ptr = 0xFEA00000
    mov r3, r5                          ! r5 = &display_slot_ptr
    mov.l @r5, r5                       ! r5 = *display_slot_ptr (= 0xFEA00000)
    mov.l   _pool_fn_display_channel_b, r3  ! r3 = &display_channel_b
    jsr @r3                             ! display_channel_b(0x10, 0xFEA00000, 0)
    mov #0x10, r4                       ! r4 = 0x10 (channel mask, delay slot)
    mov.l   _pool_fn_render_position_elem, r3 ! r3 = &render_position_elem_16px
    jsr @r3                             ! render_position_elem_16px()
    nop                                 ! (delay slot)
    mov #0x7, r2                        ! r2 = 7 (results screen state)
    mov.l   _pool_game_state_byte, r3   ! r3 = &game_state
    mov.b r2, @r3                       ! game_state = 7 (advance to results)
    mov.l   _pool_transition_state_word, r3 ! r3 = &transition_state_word
    mov.w r14, @r3                      ! transition_state_word = 0 (clear again)
    extu.w r14, r4                      ! r4 = 0 (arg1 for sprite_batch_renderer)
    lds.l @r15+, pr                     ! restore return address
    mov.l   _pool_fn_sprite_batch_renderer, r3 ! r3 = &sprite_batch_renderer
    jmp @r3                             ! tail-call sprite_batch_renderer(0)
    mov.l @r15+, r14                    ! restore r14 (delay slot)
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
