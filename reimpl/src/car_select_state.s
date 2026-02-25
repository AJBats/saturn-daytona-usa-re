/* car_select_state -- car selection display state handler
 * Translation unit: 0x060197F4 - 0x060198E0
 *
 * Handles the car selection screen display state. When the player confirms
 * a car (Start/A button press detected via 0x0600 mask on button status),
 * this function:
 *   1. Clears the animation state (sym_06059F44) and display-active flag
 *      (sym_0605D242)
 *   2. Stores the callback parameter (r4) into the game state dispatch
 *      value (sym_0605AD10)
 *   3. Reads the current car slot index (sym_0605D244), looks up the
 *      car model entry from the car slot LUT (sym_06049AF4) and car
 *      object table (sym_06063750), then resolves display parameters
 *      from the car slot param table (sym_06049AEC)
 *   4. Computes a display list index from the car's color and model
 *      fields, calls the display list loader (sym_06028400)
 *   5. Tail-calls camera state finalization (sym_06026CE0)
 *
 * If no confirm button is detected, returns immediately.
 *
 * Entry points:
 *   car_select_state    -- main handler (r4 = mode/callback param)
 *   loc_060198A4        -- reset car + direction=0, then call with mode 0xC
 *   loc_060198B8        -- reset car + direction=1, then call with mode 0xC
 *   loc_060198CC        -- call with mode 0x8
 *   loc_060198D0        -- call with mode 0xA
 *
 * Calls: sym_06028400 (display list loader), sym_06026CE0 (camera finalize)
 */

    .section .text.FUN_060197F4


    .global car_select_state
    .type car_select_state, @function
car_select_state:
    sts.l pr, @-r15                          ! save PR (return address)
    add #-0xC, r15                           ! allocate 12 bytes of stack frame
    mov.l   _pool_button_status, r3          ! r3 -> &button status word (sym_06063D9A)
    mov.w @r3, r2                            ! r2 = current button status (16-bit)
    mov.w   _wpool_confirm_mask, r3          ! r3 = 0x0600 (Start/A button mask)
    extu.w r2, r2                            ! zero-extend button status to 32-bit
    and r3, r2                               ! isolate Start/A bits
    tst r2, r2                               ! Start or A pressed?
    bt      .L_no_confirm                    ! no -> early return
    mov #0x0, r5                             ! r5 = 0 (clear value)
    mov.l   _pool_anim_state, r3             ! r3 -> &animation state (sym_06059F44)
    mov.l r5, @r3                            ! animation_state = 0 (clear 32-bit)
    mov.l   _pool_display_active, r3         ! r3 -> &display-active flag (sym_0605D242)
    mov.b r5, @r3                            ! display_active = 0 (clear byte)
    mov.l   _pool_game_state_val, r3         ! r3 -> &game state dispatch value (sym_0605AD10)
    mov.l r4, @r3                            ! game_state_dispatch_val = r4 (callback/mode)
    mov.l   _pool_car_slot_idx, r7           ! r7 -> &car slot index byte (sym_0605D244)
    mov.b @r7, r7                            ! r7 = car_slot_index (0-7)
    shll r7                                  ! r7 = car_slot_index * 2 (LUT stride)
    mov.l r7, @(8, r15)                      ! [sp+8] = scaled slot index (saved)
    mov.l   _pool_car_slot_lut, r3           ! r3 -> car slot LUT base (sym_06049AF4)
    add r3, r7                               ! r7 -> &car_slot_lut[slot_index]
    mov.w @r7, r7                            ! r7 = car model entry (16-bit LUT value)
    extu.w r7, r7                            ! zero-extend to 32-bit
    shll2 r7                                 ! r7 *= 4
    shll r7                                  ! r7 *= 2 (total: * 8, object table stride)
    mov.l   _pool_car_obj_table, r2          ! r2 -> car object table base (sym_06063750)
    add r2, r7                               ! r7 -> &car_obj_table[model_entry]
    mov.l r7, @r15                           ! [sp+0] = &car_obj_table[model_entry]
    mov.l @(4, r7), r7                       ! r7 = car_obj[model].texture_base (field +4)
    mov.w   _wpool_texture_offset, r3        ! r3 = 0x4000 (texture data offset)
    add r3, r7                               ! r7 = texture_base + 0x4000
    mov.l @(8, r15), r6                      ! r6 = scaled slot index (from [sp+8])
    mov.l   _pool_car_slot_params, r3        ! r3 -> car slot param table (sym_06049AEC)
    add r3, r6                               ! r6 -> &car_slot_params[slot_index]
    mov.l r6, @(4, r15)                      ! [sp+4] = &car_slot_params[slot_index]
    mov.b @(1, r6), r0                       ! r0 = color_index (params byte +1)
    mov r0, r6                               ! r6 = color_index
    extu.b r6, r6                            ! zero-extend color to 32-bit
    shll2 r6                                 ! r6 *= 4
    shll2 r6                                 ! r6 *= 4
    shll2 r6                                 ! r6 *= 4 (total: * 64, color block stride)
    mov.l @(4, r15), r2                      ! r2 = &car_slot_params[slot_index]
    mov.l @r15, r5                           ! r5 = &car_obj_table[model_entry]
    mov.l   _pool_dlist_loader, r3           ! r3 -> display list loader (sym_06028400)
    mov.b @r2, r2                            ! r2 = model_variant (params byte +0)
    mov.l @r5, r5                            ! r5 = car_obj[model].dlist_base (field +0)
    extu.b r2, r2                            ! zero-extend variant to 32-bit
    add r2, r6                               ! r6 = color_block + variant (display index)
    shll r6                                  ! r6 *= 2 (final display list index)
    jsr @r3                                  ! call display_list_loader(0xC, r5, r6, r7)
    mov #0xC, r4                             ! (delay) r4 = 0xC (display layer count)
    add #0xC, r15                            ! deallocate stack frame
    mov.l   _pool_camera_finalize, r3        ! r3 -> camera state finalization (sym_06026CE0)
    jmp @r3                                  ! tail-call camera_finalize()
    lds.l @r15+, pr                          ! (delay) restore PR

    .global DAT_06019864
DAT_06019864:
    mov.l r0, @(0, r0)
_wpool_confirm_mask:
    .2byte  0x0600
_wpool_texture_offset:
    .2byte  0x4000
    .2byte  0xFFFF
    .4byte  sym_0605D243
    .4byte  sym_0605D250
_pool_button_status:
    .4byte  sym_06063D9A
_pool_anim_state:
    .4byte  sym_06059F44
_pool_display_active:
    .4byte  sym_0605D242
_pool_game_state_val:
    .4byte  sym_0605AD10
_pool_car_slot_idx:
    .4byte  sym_0605D244
_pool_car_slot_lut:
    .4byte  sym_06049AF4
_pool_car_obj_table:
    .4byte  sym_06063750
_pool_car_slot_params:
    .4byte  sym_06049AEC
_pool_dlist_loader:
    .4byte  sym_06028400
_pool_camera_finalize:
    .4byte  sym_06026CE0
.L_no_confirm:
    add #0xC, r15                            ! deallocate stack frame
    lds.l @r15+, pr                          ! restore PR
    rts                                      ! return (no confirm button pressed)
    nop                                      ! (delay)

    .global loc_060198A4
loc_060198A4:
    mov #0x0, r4                             ! r4 = 0 (clear value)
    mov.l   _pool_camera_dir_flip, r2        ! r2 -> &camera direction flip (sym_06078663)
    mov.b r4, @r2                            ! camera_dir_flip = 0 (forward)
    mov.l   _pool_select_timer, r2           ! r2 -> &selection timer (sym_0605AA98)
    mov.l r4, @r2                            ! selection_timer = 0 (clear 32-bit)
    exts.b r4, r4                            ! r4 = 0 (sign-extended for byte store)
    mov.l   _pool_2p_mode_flag, r2           ! r2 -> &2-player mode flag (sym_06085FF4)
    mov.b r4, @r2                            ! 2p_mode_flag = 0 (single player)
    bra     car_select_state                 ! tail-call car_select_state(0xC)
    mov #0xC, r4                             ! (delay) r4 = 0xC (mode: full display)

    .global loc_060198B8
loc_060198B8:
    mov #0x0, r4                             ! r4 = 0 (clear value)
    mov.l   _pool_camera_dir_flip, r2        ! r2 -> &camera direction flip (sym_06078663)
    mov.b r4, @r2                            ! camera_dir_flip = 0 (forward)
    mov.l   _pool_select_timer, r2           ! r2 -> &selection timer (sym_0605AA98)
    mov.l r4, @r2                            ! selection_timer = 0 (clear 32-bit)
    mov #0x1, r1                             ! r1 = 1 (direction flag value)
    mov.l   _pool_2p_mode_flag, r2           ! r2 -> &2-player mode flag (sym_06085FF4)
    mov.b r1, @r2                            ! 2p_mode_flag = 1 (two-player mode)
    bra     car_select_state                 ! tail-call car_select_state(0xC)
    mov #0xC, r4                             ! (delay) r4 = 0xC (mode: full display)

    .global loc_060198CC
loc_060198CC:
    bra     car_select_state                 ! tail-call car_select_state(0x8)
    mov #0x8, r4                             ! (delay) r4 = 0x8 (mode: abbreviated)

    .global loc_060198D0
loc_060198D0:
    bra     car_select_state                 ! tail-call car_select_state(0xA)
    mov #0xA, r4                             ! (delay) r4 = 0xA (mode: results)
_pool_camera_dir_flip:
    .4byte  sym_06078663
_pool_select_timer:
    .4byte  sym_0605AA98
_pool_2p_mode_flag:
    .4byte  sym_06085FF4
