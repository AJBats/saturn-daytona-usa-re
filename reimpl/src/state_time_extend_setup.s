/* state_time_extend_setup -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x060096DC - 0x06009788
 *
 * Initializes the "time extend" state that activates when the player
 * reaches a checkpoint and earns bonus time. Sets game state to 0x13
 * (TIME_EXTEND), saves the current lap count into the extend-mode
 * backup byte, clears the extend timer and mode flag, renders the
 * initial time extend HUD elements (three sprite groups at different
 * screen positions), sets the render-flags bit for the extend overlay,
 * calls camera_finalize, clears animation state, and tail-calls
 * sound_cmd_dispatch to play the time extend jingle (0xAE0004FF).
 *
 * Called from the game state dispatch table when transitioning into
 * the time extend sequence. The companion state_time_extend_active
 * runs each subsequent frame to handle the countdown and input.
 */

    .section .text.FUN_060096DC


    .global state_time_extend_setup
    .type state_time_extend_setup, @function
state_time_extend_setup:
    mov.l r14, @-r15                        ! save r14 (callee-saved)
    sts.l pr, @-r15                         ! save return address
    add #-0x4, r15                          ! allocate 4 bytes on stack for local
    .byte   0xB4, 0x8B    /* bsr state_timeext_setup — frame setup helper */
    nop                                     ! delay slot
    mov #0x13, r2                           ! r2 = 0x13 (TIME_EXTEND state ID)
    mov.l   .L_pool_game_state, r3          ! r3 = &game_state
    mov #0x0, r14                           ! r14 = 0 (used as zero constant throughout)
    mov.l r2, @r3                           ! game_state = 0x13
    mov.l   .L_pool_lap_count, r4           ! r4 = &lap_count (current lap byte)
    mov.l   .L_pool_extend_lap_backup, r3   ! r3 = &extend_lap_backup
    mov.b @r4, r2                           ! r2 = lap_count
    mov.b r2, @r3                           ! extend_lap_backup = lap_count (save for restore)
    extu.b r14, r2                          ! r2 = 0 (zero-extended byte)
    mov.b r2, @r4                           ! lap_count = 0 (clear during extend)
    mov.l   .L_pool_extend_timer, r2        ! r2 = &extend_timer (16-bit)
    mov.w r14, @r2                          ! extend_timer = 0 (reset countdown)
    mov.l   .L_pool_extend_gfx_base, r7    ! r7 = extend gfx sprite data base
    mov.w   .L_wpool_sprite_coord_y, r6    ! r6 = 0x0090 (Y screen coordinate)
    mov.w   .L_wpool_sprite_param_a, r5    ! r5 = 0x051C (sprite parameter A)
    mov.l   .L_pool_fn_geom_render, r2     ! r2 = &geom_render function
    jsr @r2                                 ! geom_render(8, 0x051C, 0x0090, gfx_base)
    mov #0x8, r4                            ! r4 = 0x8 (delay slot: display priority)
    mov.l   .L_pool_extend_text_data, r3   ! r3 = extend text/sprite data base
    mov.l r3, @r15                          ! [sp] = text_data (save for reuse)
    mov r3, r7                              ! r7 = text_data
    mov.l   .L_mask_nibble3, r6            ! r6 = 0xF000 (nibble-3 mask for geom dispatch)
    mov.w   .L_wpool_sprite_param_b, r5    ! r5 = 0x061C (sprite parameter B)
    add #0x2E, r7                           ! r7 = text_data + 0x2E (second text element)
    mov.l   .L_pool_fn_geom_dispatch, r3   ! r3 = &geom_dispatch function
    jsr @r3                                 ! geom_dispatch(8, 0x061C, 0xF000, text+0x2E)
    mov #0x8, r4                            ! r4 = 0x8 (delay slot: display priority)
    mov.l @r15, r7                          ! r7 = text_data (reload from stack)
    mov.l   .L_mask_nibble3, r6            ! r6 = 0xF000 (nibble-3 mask)
    mov.w   .L_wpool_sprite_param_c, r5    ! r5 = 0x049C (sprite parameter C)
    mov.l   .L_pool_fn_geom_dispatch, r3   ! r3 = &geom_dispatch function
    add #0x2F, r7                           ! r7 = text_data + 0x2F (third text element)
    jsr @r3                                 ! geom_dispatch(8, 0x049C, 0xF000, text+0x2F)
    mov #0x8, r4                            ! r4 = 0x8 (delay slot: display priority)
    mov.l   .L_pool_render_flags, r4       ! r4 = &render_flags (32-bit)
    mov.l   .L_pool_fn_camera_finalize, r3 ! r3 = &camera_finalize function
    mov.l @r4, r0                           ! r0 = render_flags
    or #0x4, r0                             ! r0 |= 0x4 (set extend-overlay bit)
    jsr @r3                                 ! camera_finalize()
    mov.l r0, @r4                           ! render_flags |= 0x4 (delay slot: write back)
    mov.l   .L_pool_anim_state, r3         ! r3 = &anim_state (32-bit)
    mov.l r14, @r3                          ! anim_state = 0 (clear animation state)
    mov.l   .L_pool_snd_cmd_extend, r5    ! r5 = 0xAE0004FF (time extend sound command)
    mov r14, r4                             ! r4 = 0 (sound channel 0)
    add #0x4, r15                           ! free stack local
    lds.l @r15+, pr                         ! restore return address
    mov.l   .L_pool_fn_sound_dispatch, r3  ! r3 = &sound_cmd_dispatch
    jmp @r3                                 ! tail-call sound_cmd_dispatch(0, 0xAE0004FF)
    mov.l @r15+, r14                        ! restore r14 (delay slot)
.L_wpool_sprite_coord_y:
    .2byte  0x0090                          /* Y screen coordinate for extend sprite */
.L_wpool_sprite_param_a:
    .2byte  0x051C                          /* sprite parameter A (first HUD element) */
.L_wpool_sprite_param_b:
    .2byte  0x061C                          /* sprite parameter B (second text element) */
.L_wpool_sprite_param_c:
    .2byte  0x049C                          /* sprite parameter C (third text element) */
.L_pool_game_state:
    .4byte  sym_0605AD10                    /* game state dispatch value (32-bit) */
.L_pool_lap_count:
    .4byte  sym_06078654                    /* current lap count (byte) */
.L_pool_extend_lap_backup:
    .4byte  sym_06078652                    /* extend-mode lap backup (byte) */
.L_pool_extend_timer:
    .4byte  sym_06078650                    /* time extend countdown timer (16-bit) */
.L_pool_extend_gfx_base:
    .4byte  sym_060446CC                    /* time extend sprite/graphics data base */
.L_pool_fn_geom_render:
    .4byte  sym_060284AE                    /* geom_render — VDP number+text renderer */
.L_pool_extend_text_data:
    .4byte  sym_0605AC9C                    /* time extend text/sprite data base */
.L_mask_nibble3:
    .4byte  0x0000F000                      /* nibble-3 mask for geom dispatch */
.L_pool_fn_geom_dispatch:
    .4byte  sym_060283E0                    /* geom_dispatch — display command writer */
.L_pool_render_flags:
    .4byte  sym_0605B6D8                    /* render mode flags (32-bit bitmask) */
.L_pool_fn_camera_finalize:
    .4byte  sym_06026CE0                    /* camera_finalize — commit camera state */
.L_pool_anim_state:
    .4byte  sym_06059F44                    /* animation state (32-bit, cleared to 0) */
.L_pool_snd_cmd_extend:
    .4byte  0xAE0004FF                      /* sound command: time extend jingle */
.L_pool_fn_sound_dispatch:
    .4byte  sound_cmd_dispatch              /* sound command dispatcher (tail-call target) */
