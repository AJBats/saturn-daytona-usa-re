/* speedometer_ctrl -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x060102EC - 0x060103B8
 *
 * Speedometer/gauge shutdown controller.
 *
 * Called periodically to manage the speedometer display teardown during
 * state transitions (e.g., end of race, attract mode exit). Decrements
 * a state countdown timer. When the countdown expires or specific button
 * inputs are detected, stops the speedometer sound effect via
 * sound_cmd_dispatch, resets the game state byte to 0x02 (post-race),
 * copies the race-end state into the course index, and clears the menu
 * overlay flag. If 2-player mode is inactive, no render state is pending,
 * and the start button (bit 12) is pressed, re-enables the overlay.
 *
 * Inputs:
 *   r4 = button state word (16-bit, from controller peripheral)
 *   r2 = secondary flags word (from caller, bit 8 = immediate abort)
 *
 * Globals:
 *   sym_0607EBCC  -- state countdown timer (32-bit, decremented per call)
 *   g_game_state  -- game state dispatch value (written 6 on abort)
 *   sym_0607EADC  -- current car/player index (dword, indexes sound table)
 *   sym_0604481C  -- sound command table base (4-byte entries)
 *   sym_0607887F  -- game state byte (written 0x02 = post-race)
 *   sym_0607887E  -- game sub-state byte (cleared)
 *   sym_0607EAD8  -- race end state (read, copied to course index)
 *   sym_06078648  -- course index byte (written from race end state)
 *   sym_0605AB18  -- menu overlay active flag (byte, cleared/set)
 *   sym_06085FF4  -- 2-player mode flag (byte, 0=1P)
 *   sym_0605AD00  -- render state variable (dword, 0=idle)
 *   g_pad_state  -- controller button state word (16-bit hw read)
 */

    .section .text.FUN_060102EC


    .global speedometer_ctrl
    .type speedometer_ctrl, @function
speedometer_ctrl:
    mov.l r14, @-r15                        ! save r14 (callee-saved)
    sts.l pr, @-r15                         ! save return address
    mov.l   _pool_countdown_ptr, r14        ! r14 = &state_countdown (sym_0607EBCC)
    mov.l @r14, r3                          ! r3 = current countdown value
    add #-0x1, r3                           ! r3-- (decrement countdown)
    mov.l r3, @r14                          ! store decremented countdown
    mov.w   _wpool_abort_mask, r3           ! r3 = 0x0100 (bit 8: immediate abort flag)
    and r3, r2                              ! r2 &= 0x0100 (isolate abort bit from caller flags)
    tst r2, r2                              ! test if abort bit is set
    bt      .L_no_abort                     ! if abort bit clear -> skip abort path
    mov #0x6, r3                            ! r3 = 6 (abort state value)
    mov.l   _pool_game_dispatch_ptr, r2     ! r2 = &game_state_dispatch (g_game_state)
    mov.l r3, @r2                           ! game_state_dispatch = 6 (force abort transition)
    bra     .L_exit                         ! jump to exit
    nop                                     ! (branch delay slot)
    .2byte  0x4000
_wpool_abort_mask:
    .2byte  0x0100                          /* bit 8: immediate abort flag */
    .2byte  0xFFFF
    .4byte  sym_0607EADC                    /* &car_index (dword, indexes sound table) */
    .4byte  0x00008000
    .4byte  sym_0607887E                    /* &game_sub_state (byte) */
    .4byte  sym_0607EAD8                    /* &race_end_state (dword, 0/1/2) */
_pool_countdown_ptr:
    .4byte  sym_0607EBCC                    /* &state_countdown (32-bit timer) */
_pool_game_dispatch_ptr:
    .4byte  g_game_state                    /* &game_state_dispatch value */
.L_no_abort:
    mov.l @r14, r2                          ! r2 = state_countdown (just decremented)
    cmp/pl r2                               ! T = (countdown > 0)?
    bf      .L_do_shutdown                  ! if countdown <= 0 -> proceed to shutdown
    extu.w r4, r4                           ! r4 = zero-extend button state to 32-bit
    mov.w   DAT_0601038c, r2               ! r2 = 0x0200 (button mask: view change btn)
    and r2, r4                              ! r4 &= 0x0200 (isolate view-change bit)
    tst r4, r4                              ! test if view-change button pressed
    bt      .L_exit                         ! if not pressed -> exit (countdown still active)
.L_do_shutdown:
    mov.l   _pool_car_index_ptr, r5         ! r5 = &car_index (sym_0607EADC)
    mov.l   _pool_snd_table_base, r3        ! r3 = sound_cmd_table base (sym_0604481C)
    mov.l   _pool_snd_dispatch, r2          ! r2 = &sound_cmd_dispatch (function ptr)
    mov.l @r5, r5                           ! r5 = car_index value
    shll2 r5                                ! r5 *= 4 (index -> byte offset in 4-byte table)
    add r3, r5                              ! r5 = &sound_cmd_table[car_index]
    mov.l @r5, r5                           ! r5 = sound_cmd_table[car_index] (sound param)
    jsr @r2                                 ! call sound_cmd_dispatch(r4=0, r5=snd_param)
    mov #0x0, r4                            ! r4 = 0 (cmd=stop) [delay slot]
    mov #0x0, r5                            ! r5 = 0
    mov #0x2, r3                            ! r3 = 2 (game state: post-race)
    mov.l r5, @r14                          ! state_countdown = 0 (reset timer)
    mov.l   _pool_game_state_ptr, r2        ! r2 = &game_state (sym_0607887F)
    exts.b r5, r5                           ! r5 = sign-extend 0 -> 0 (byte value)
    mov.b r3, @r2                           ! game_state = 0x02 (post-race)
    mov.l   _pool_race_end_ptr, r3          ! r3 = &race_end_state (sym_0607EAD8)
    mov.l   _pool_course_idx_ptr, r2        ! r2 = &course_index (sym_06078648)
    mov.l @r3, r3                           ! r3 = race_end_state value
    exts.b r3, r3                           ! r3 = sign-extend to byte
    mov.b r3, @r2                           ! course_index = race_end_state (copy)
    mov.l   _pool_overlay_flag_ptr, r4      ! r4 = &overlay_active (sym_0605AB18)
    mov.b r5, @r4                           ! overlay_active = 0 (clear overlay flag)
    mov.l   _pool_2p_mode_ptr, r0           ! r0 = &2p_mode_flag (sym_06085FF4)
    mov.b @r0, r0                           ! r0 = 2p_mode_flag value (byte)
    tst r0, r0                              ! test if 2-player mode active
    bf      .L_exit                         ! if 2P mode active -> exit (skip overlay re-enable)
    mov.l   _pool_render_state_ptr, r0      ! r0 = &render_state (sym_0605AD00)
    mov.l @r0, r0                           ! r0 = render_state value
    tst r0, r0                              ! test if render state is idle (0)
    bf      .L_exit                         ! if render busy -> exit
    mov.l   _pool_button_hw_ptr, r3         ! r3 = &button_state_hw (g_pad_state)
    mov.w @r3, r2                           ! r2 = button_state_hw (16-bit read)
    mov.w   DAT_0601038e, r3               ! r3 = 0x1000 (bit 12: start button mask)
    extu.w r2, r2                           ! r2 = zero-extend button word
    and r3, r2                              ! r2 &= 0x1000 (isolate start button bit)
    tst r2, r2                              ! test if start button pressed
    bt      .L_exit                         ! if not pressed -> exit
    mov #0x1, r3                            ! r3 = 1 (overlay active)
    mov.b r3, @r4                           ! overlay_active = 1 (re-enable overlay)
.L_exit:
    lds.l @r15+, pr                         ! restore return address
    rts                                     ! return to caller
    mov.l @r15+, r14                        ! restore r14 [delay slot]

    .global DAT_0601038c
DAT_0601038c:
    .2byte  0x0200                          /* view-change button mask (bit 9) */

    .global DAT_0601038e
DAT_0601038e:
    .2byte  0x1000                          /* start button mask (bit 12) */
_pool_car_index_ptr:
    .4byte  sym_0607EADC                    /* &car_index (dword, player/car slot) */
_pool_snd_table_base:
    .4byte  sym_0604481C                    /* sound command table base (4-byte entries) */
_pool_snd_dispatch:
    .4byte  sound_cmd_dispatch              /* &sound_cmd_dispatch function */
_pool_game_state_ptr:
    .4byte  sym_0607887F                    /* &game_state byte (0x02=post-race) */
_pool_race_end_ptr:
    .4byte  sym_0607EAD8                    /* &race_end_state (dword, 0/1/2) */
_pool_course_idx_ptr:
    .4byte  sym_06078648                    /* &course_index byte */
_pool_overlay_flag_ptr:
    .4byte  sym_0605AB18                    /* &overlay_active flag (byte) */
_pool_2p_mode_ptr:
    .4byte  sym_06085FF4                    /* &2p_mode_flag (byte, 0=1P) */
_pool_render_state_ptr:
    .4byte  sym_0605AD00                    /* &render_state (dword, 0=idle) */
_pool_button_hw_ptr:
    .4byte  g_pad_state                    /* &button_state_hw (16-bit word) */
