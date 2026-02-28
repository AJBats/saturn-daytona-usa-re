/* render_setup_dispatch — render pipeline initialization and state dispatch
 * Translation unit: 0x0601D3C0 - 0x0601D478
 *
 * Called from mode-select to initialize the render pipeline before a race.
 * On first entry (DMA not pending), checks controller button state for
 * specific combos that select render quality modes:
 *
 *   - 0xAAA8: sets render flags bits 0-2 on game_mode byte
 *   - 0x5D50: sets render flags on both game_mode AND overlay_flags bytes
 *
 * Then configures display channel 32, loads tilemap data via display list
 * loader, sets state countdown timer to 12, game_state to 4, and marks
 * DMA as pending.
 *
 * On every call (including re-entry), tail-dispatches through a jump table
 * indexed by game_state byte: [sound_cmd_queue_write, sound_channel_alloc,
 * loc_0601D50C, loc_0601D546, loc_0601D568].
 *
 * Registers on entry:
 *   (none — called with no arguments)
 *
 * Registers used:
 *   r14 = &game_mode byte (sym_0605AB16), kept across subroutine calls
 *
 * Calls: display_channel_b, display_list_loader (sym_06028400)
 */

    .section .text.FUN_0601D3C0


    .global render_setup_dispatch
    .type render_setup_dispatch, @function
render_setup_dispatch:
    mov.l r14, @-r15                         ! save r14 (callee-saved)
    sts.l pr, @-r15                          ! save return address
    mov.l   _pool_game_mode_ptr, r14         ! r14 = &game_mode byte (kept for duration)
    mov.l   _pool_dma_pending_flag, r0       ! r0 = &dma_pending_flag
    mov.l @r0, r0                            ! r0 = dma_pending_flag value
    tst r0, r0                               ! is DMA already pending?
    bf      .L_tail_dispatch                 ! yes: skip init, go straight to dispatch
    mov.l   _pool_button_state_ptr, r3       ! r3 = &button_state word (sym_06063D9A)
    mov.w @r3, r2                            ! r2 = current button state (16-bit)
    mov.w   DAT_0601d444, r3                 ! r3 = 0x0800 (start button mask)
    extu.w r2, r2                            ! zero-extend button state to 32-bit
    and r3, r2                               ! isolate start button bit
    tst r2, r2                               ! start button pressed?
    bt      .L_tail_dispatch                 ! no: skip init, go to dispatch
    mov.l   _pool_input_struct_ptr, r3       ! r3 = &input_struct base (g_pad_state)
    mov.w @r3, r2                            ! r2 = input word at struct base (16-bit)
    mov.l   _pool_combo_value_a, r3          ! r3 = 0x0000AAA8 (button combo A)
    extu.w r2, r2                            ! zero-extend input word to 32-bit
    cmp/eq r3, r2                            ! input == combo A (0xAAA8)?
    bf      .L_check_combo_b                 ! no: try combo B
    mov.b @r14, r0                           ! r0 = game_mode byte
    or #0x7, r0                              ! set render flags bits 0-2
    mov.b r0, @r14                           ! write back to game_mode
.L_check_combo_b:
    mov.l   _pool_input_struct_ptr, r3       ! r3 = &input_struct base (reload)
    mov.w @r3, r2                            ! r2 = input word (16-bit)
    extu.w r2, r2                            ! zero-extend to 32-bit
    mov.w   DAT_0601d446, r3                 ! r3 = 0x5D50 (button combo B)
    cmp/eq r3, r2                            ! input == combo B (0x5D50)?
    bf      .L_setup_display                 ! no: proceed to display setup
    mov.b @r14, r0                           ! r0 = game_mode byte
    or #0x7, r0                              ! set render flags bits 0-2
    mov.b r0, @r14                           ! write back to game_mode
    mov.l   _pool_overlay_flags_ptr, r4      ! r4 = &overlay_flags byte (sym_0605AB17)
    mov.b @r4, r0                            ! r0 = overlay_flags byte
    or #0x7, r0                              ! set render flags bits 0-2
    mov.b r0, @r4                            ! write back to overlay_flags
.L_setup_display:
    mov #0x0, r6                             ! r6 = 0 (arg3: dst = 0)
    mov.l   _pool_fn_display_channel_b, r3   ! r3 = &display_channel_b
    mov r6, r5                               ! r5 = 0 (arg2: src = 0)
    jsr @r3                                  ! call display_channel_b(0x20, 0, 0)
    mov #0x20, r4                            ! (delay) r4 = 0x20 (arg1: channel 32)
    mov #0x0, r7                             ! r7 = 0 (will become arg4)
    mov.l   _pool_tilemap_source, r5         ! r5 = &tilemap_source (arg2: src data)
    mov.l   _pool_fn_dlist_loader, r3        ! r3 = &display_list_loader
    mov r7, r6                               ! r6 = 0 (arg3: offset = 0)
    jsr @r3                                  ! call dlist_loader(0xC, tilemap_src, 0, 0)
    mov #0xC, r4                             ! (delay) r4 = 0xC (arg1: layer count)
    mov #0xC, r2                             ! r2 = 0xC (timer initial value = 12)
    mov.l   _pool_countdown_timer, r3        ! r3 = &countdown_timer
    mov.l r2, @r3                            ! countdown_timer = 12
    mov #0x4, r2                             ! r2 = 0x4 (game_state = 4)
    mov.l   _pool_game_state_ptr, r3         ! r3 = &game_state byte
    mov.b r2, @r3                            ! game_state = 4
    mov #0x1, r2                             ! r2 = 1 (mark DMA as pending)
    mov.l   _pool_dma_pending_flag, r3       ! r3 = &dma_pending_flag
    mov.l r2, @r3                            ! dma_pending_flag = 1
.L_tail_dispatch:
    mov.l   _pool_game_state_ptr, r2         ! r2 = &game_state byte
    mov.b @r2, r2                            ! r2 = game_state (signed byte)
    extu.b r2, r2                            ! zero-extend to unsigned 32-bit index
    shll2 r2                                 ! r2 *= 4 (index to 4-byte table offset)
    mov.l   _pool_state_jump_table, r3       ! r3 = &state_jump_table base
    add r3, r2                               ! r2 = &jump_table[game_state]
    mov.l @r2, r2                            ! r2 = handler address from table
    lds.l @r15+, pr                          ! restore return address
    jmp @r2                                  ! tail-call state handler
    mov.l @r15+, r14                         ! (delay) restore r14

    .global DAT_0601d444
DAT_0601d444:
    .2byte  0x0800                           ! start button mask (bit 11)

    .global DAT_0601d446
DAT_0601d446:
    .2byte  0x5D50                           ! button combo B value
_pool_game_mode_ptr:
    .4byte  sym_0605AB16                     ! -> game_mode byte (1 byte, WRAM High)
_pool_dma_pending_flag:
    .4byte  sym_06086024                     ! -> DMA pending flag (32-bit, 0 = idle)
_pool_button_state_ptr:
    .4byte  sym_06063D9A                     ! -> button state word (16-bit)
_pool_input_struct_ptr:
    .4byte  g_pad_state                     ! -> input struct base (16-bit word at +0)
_pool_combo_value_a:
    .4byte  0x0000AAA8                       ! button combo A constant
_pool_overlay_flags_ptr:
    .4byte  sym_0605AB17                     ! -> overlay_flags byte (adjacent to game_mode)
_pool_fn_display_channel_b:
    .4byte  display_channel_b                ! -> display channel setup function
_pool_tilemap_source:
    .4byte  sym_06094FA8                     ! -> tilemap source data in WRAM
_pool_fn_dlist_loader:
    .4byte  sym_06028400                     ! -> display list loader function
_pool_countdown_timer:
    .4byte  sym_0607EBCC                     ! -> state countdown timer (32-bit)
_pool_game_state_ptr:
    .4byte  sym_0607887F                     ! -> game_state byte (8-bit, jump table index)
_pool_state_jump_table:
    .4byte  sym_0605DF80                     ! -> state handler jump table (5 entries)
