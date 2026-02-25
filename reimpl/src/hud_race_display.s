/* hud_race_display -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0600FFD0 - 0x060100A4
 *
 * Per-frame HUD race display controller. Called from the game state
 * dispatcher (FUN_0600F424) every frame during racing.
 *
 * Purpose:
 *   1. Iterate over 3 car slots (indices 0-2), calling sprite_anim_render
 *      for each car whose game state >= 4 (i.e., actively racing).
 *   2. Manage a display animation timer (sym_0605AA98):
 *      - When display_mode_flag (sym_06078663) == 0: decrement timer toward 0
 *        (fade-out / countdown behavior).
 *      - When display_mode_flag != 0: increment timer toward 0xC
 *        (fade-in / count-up behavior).
 *   3. Render the race HUD overlay via geom_dispatch_final (sym_060284AE):
 *      - State 9 (finish/special): uses X-position 0x06A2 with 0xC elements.
 *      - States 0-4 (normal race): uses X-position 0x0B22 with 0x8 elements.
 *      - States > 4 but not 9: skip HUD rendering (exit early).
 *      The two rendering paths differ in fade-in vs fade-out timer direction.
 *
 * Register usage:
 *   r9  = Y screen position constant (0x0090)
 *   r10 = car slot count (3)
 *   r11 = geom_dispatch_final function pointer (sym_060284AE)
 *   r12 = game state threshold (4)
 *   r13 = loop counter / car index (0-2)
 *   r14 = pointer to game_state byte (sym_0607887F)
 *
 * Calling convention for geom_dispatch_final (sym_060284AE):
 *   r4 = element count (0x8 normal, 0xC for state 9)
 *   r5 = X screen position (0x06A2 or 0x0B22)
 *   r6 = Y screen position (0x0090)
 *   r7 = display data buffer pointer (sym_0605ACE4)
 *
 * Data references:
 *   sym_0607887F = current game state byte (0-based state index)
 *   sym_0605AA98 = HUD display animation timer (long word, 0-0xC range)
 *   sym_06078663 = display mode flag byte (0 = fade-out, nonzero = fade-in)
 *   sym_0605ACE4 = primary HUD display data buffer
 *
 * Note: The .byte pairs encoding BSR/BRA and cross-pool mov.l/mov.w
 * at the bottom half of this function reference pool entries belonging
 * to the sprite_anim_render TU (next TU at 0x060100A4+).
 */

    .section .text.FUN_0600FFD0


    .global hud_race_display
    .type hud_race_display, @function
hud_race_display:
    mov.l r14, @-r15          ! save r14 (game_state_ptr) to stack
    mov.l r13, @-r15          ! save r13 (loop counter) to stack
    mov.l r12, @-r15          ! save r12 (state threshold) to stack
    mov.l r11, @-r15          ! save r11 (geom_dispatch_final ptr) to stack
    mov.l r10, @-r15          ! save r10 (car slot count) to stack
    mov.l r9, @-r15           ! save r9 (Y position) to stack
    sts.l pr, @-r15           ! save return address to stack
    mov.w   .L_wpool_y_position, r9 ! r9 = 0x0090 (HUD Y screen position)
    mov #0x3, r10             ! r10 = 3 (number of car slots to iterate)
    mov.l   .L_pool_geom_dispatch_final, r11 ! r11 = &geom_dispatch_final (sym_060284AE)
    mov #0x4, r12             ! r12 = 4 (game state threshold for racing)
    mov.l   .L_pool_game_state_ptr, r14 ! r14 = &game_state byte (sym_0607887F)
    mov #0x0, r13             ! r13 = 0 (initialize car index counter)
.L_car_loop:
    mov.b @r14, r3            ! r3 = current game_state byte
    extu.b r3, r3             ! zero-extend game_state to 32 bits
    cmp/ge r12, r3            ! compare: game_state >= 4? (is car actively racing?)
    .byte   0xB0, 0x58    /* bsr 0x060100A4 (sprite_anim_render) */ ! call sprite_anim_render (T = state >= 4)
    mov r13, r4               ! r4 = car index (delay slot: arg for sprite_anim_render)
    add #0x1, r13             ! increment car index
    extu.b r13, r2            ! zero-extend index to 32 bits
    cmp/ge r10, r2            ! compare: index >= 3? (looped all slots?)
    bf      .L_car_loop       ! if not done, loop back for next car
    mov.l   .L_pool_display_timer, r4 ! r4 = &display_timer (sym_0605AA98)
    mov.l   .L_pool_display_mode_flag, r0 ! r0 = &display_mode_flag (sym_06078663)
    mov.b @r0, r0             ! r0 = display_mode_flag byte value
    tst r0, r0                ! test: is display_mode_flag == 0?
    bf      .L_mode_fade_in   ! if nonzero, branch to fade-in (count-up) path
    /* --- Fade-out (countdown) path: display_mode_flag == 0 --- */
    mov.l @r4, r0             ! r0 = current timer value
    tst r0, r0                ! test: is timer already 0?
    bt      .L_timer_done     ! if zero, skip decrement
    mov.l @r4, r3             ! r3 = timer value (re-read)
    add #-0x1, r3             ! decrement timer by 1
    mov.l r3, @r4             ! store decremented timer back
.L_timer_done:
    mov.b @r14, r4            ! r4 = game_state byte
    extu.b r4, r4             ! zero-extend to 32 bits
    cmp/gt r12, r4            ! compare: game_state > 4?
    bf      .L_state_le_4_fadeout ! if game_state <= 4, go render HUD
    mov r4, r0                ! r0 = game_state
    cmp/eq #0x9, r0           ! compare: game_state == 9? (special/finish state)
    bf      .L_epilogue       ! if not state 9, skip HUD render entirely
.L_state_le_4_fadeout:
    /* Render HUD for states 0-4 or state 9 (fade-out timer direction) */
    mov.b @r14, r0            ! r0 = game_state byte
    extu.b r0, r0             ! zero-extend to 32 bits
    cmp/eq #0x9, r0           ! compare: game_state == 9?
    bf      .L_normal_hud_fadeout ! if not state 9, render normal HUD
    /* State 9 (special/finish): wider display with more elements */
    mov.l   .L_pool_display_data, r7 ! r7 = &display data buffer (sym_0605ACE4)
    mov r9, r6                ! r6 = 0x0090 (Y screen position)
    mov.w   DAT_06010044, r5  ! r5 = 0x06A2 (X position for state 9 layout)
    bra     .L_call_geom_fadeout ! branch to geom_dispatch_final call
    mov #0xC, r4              ! r4 = 0xC element count (delay slot)
.L_normal_hud_fadeout:
    /* States 0-4: standard race HUD rendering */
    mov.l   .L_pool_display_data, r7 ! r7 = &display data buffer (sym_0605ACE4)
    mov r9, r6                ! r6 = 0x0090 (Y screen position)
    mov.w   DAT_06010046, r5  ! r5 = 0x0B22 (X position for normal layout)
    mov #0x8, r4              ! r4 = 0x8 element count
.L_call_geom_fadeout:
    jsr @r11                  ! call geom_dispatch_final(r4, r5, r6, r7)
    nop                       ! delay slot (no-op)
    bra     .L_epilogue       ! done rendering, jump to function exit
    nop                       ! delay slot (no-op)
.L_wpool_y_position:
    .2byte  0x0090

    .global DAT_06010044
DAT_06010044:
    .2byte  0x06A2

    .global DAT_06010046
DAT_06010046:
    .2byte  0x0B22
.L_pool_geom_dispatch_final:
    .4byte  sym_060284AE
.L_pool_game_state_ptr:
    .4byte  sym_0607887F
.L_pool_display_timer:
    .4byte  sym_0605AA98
.L_pool_display_mode_flag:
    .4byte  sym_06078663
.L_pool_display_data:
    .4byte  sym_0605ACE4
.L_mode_fade_in:
    /* --- Fade-in (count-up) path: display_mode_flag != 0 --- */
    mov.l @r4, r0             ! r0 = current timer value
    cmp/eq #0xC, r0           ! compare: timer already at max (0xC)?
    bt      .L_timer_maxed    ! if at max, skip increment
    mov.l @r4, r3             ! r3 = timer value (re-read)
    add #0x1, r3              ! increment timer by 1
    mov.l r3, @r4             ! store incremented timer back
.L_timer_maxed:
    mov.b @r14, r4            ! r4 = game_state byte
    extu.b r4, r4             ! zero-extend to 32 bits
    cmp/gt r12, r4            ! compare: game_state > 4?
    bf      .L_state_le_4_fadein ! if game_state <= 4, go render HUD
    mov r4, r0                ! r0 = game_state
    cmp/eq #0x9, r0           ! compare: game_state == 9?
    bf      .L_epilogue       ! if not state 9, skip HUD render entirely
.L_state_le_4_fadein:
    /* Render HUD for states 0-4 or state 9 (fade-in timer direction) */
    mov.b @r14, r0            ! r0 = game_state byte
    extu.b r0, r0             ! zero-extend to 32 bits
    cmp/eq #0x9, r0           ! compare: game_state == 9?
    bf      .L_normal_hud_fadein ! if not state 9, render normal HUD
    /* State 9 (special/finish): wider display with more elements */
    .byte   0xD7, 0x1F    /* mov.l .L_pool_060100FC, r7 */ ! r7 = &display data (cross-TU pool)
    mov r9, r6                ! r6 = 0x0090 (Y screen position)
    .byte   0x95, 0x36    /* mov.w .L_wpool_060100F2, r5 */ ! r5 = X position for state 9 (cross-TU pool)
    bra     .L_call_geom_fadein ! branch to geom_dispatch_final call
    mov #0xC, r4              ! r4 = 0xC element count (delay slot)
.L_normal_hud_fadein:
    /* States 0-4: standard race HUD rendering */
    .byte   0xD7, 0x1C    /* mov.l .L_pool_060100FC, r7 */ ! r7 = &display data (cross-TU pool)
    mov r9, r6                ! r6 = 0x0090 (Y screen position)
    .byte   0x95, 0x32    /* mov.w .L_wpool_060100F4, r5 */ ! r5 = X position normal (cross-TU pool)
    mov #0x8, r4              ! r4 = 0x8 element count
.L_call_geom_fadein:
    jsr @r11                  ! call geom_dispatch_final(r4, r5, r6, r7)
    nop                       ! delay slot (no-op)
.L_epilogue:
    lds.l @r15+, pr           ! restore return address from stack
    mov.l @r15+, r9           ! restore r9 (Y position)
    mov.l @r15+, r10          ! restore r10 (car slot count)
    mov.l @r15+, r11          ! restore r11 (geom_dispatch_final ptr)
    mov.l @r15+, r12          ! restore r12 (state threshold)
    mov.l @r15+, r13          ! restore r13 (loop counter)
    rts                       ! return to caller
    mov.l @r15+, r14          ! restore r14 (game_state_ptr) (delay slot)
