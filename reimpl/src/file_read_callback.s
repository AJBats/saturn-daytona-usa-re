/* file_read_callback -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x060120CC - 0x060121A8
 *
 * File-read completion callback and display state initialization.
 * Called after an async file load completes to set up the display
 * element positions for the HUD overlay (lap counter, position
 * indicator, etc.) and transition into the appropriate game state.
 *
 * file_read_callback:
 *   1. Stores the replay mode flag byte
 *   2. Clears menu scroll position
 *   3. Enables display channel 32 via display_channel_b
 *   4. Initializes position vector A (primary) = {0, 8.0fp, 15.2fp}
 *   5. Initializes position vector B (secondary) = {0, 2.0fp, 5.2fp}
 *   6. Copies vector B into vectors C, D, and E via memcpy_long
 *   7. Sets animation counter = 0x1000, rotation angle = 0, read-init flag = 0
 *   8. Branches on race end state:
 *        0     -> timer=60, state counter=0, return
 *        nonzero -> timer=1, state counter=20, tail-call lap_time_formatter
 *
 * sym_06012198 (race_state_dispatch):
 *   Dispatch stub called from state_post_lap / state_race_main / state_post_countdown.
 *   Routes to lap_time_formatter if race ended, else to hud_menu_logic.
 *
 * Args (file_read_callback): R3 = replay mode flag byte
 */

    .section .text.FUN_060120CC


    .global file_read_callback
    .type file_read_callback, @function
file_read_callback:
    sts.l pr, @-r15                         ! save return address
    mov #0x0, r14                           ! r14 = 0 (used as zero constant throughout)
    mov.l   _pool_replay_mode_flag, r2      ! r2 = &replay_mode_flag
    mov r14, r6                             ! r6 = 0 (arg3 for display_channel_b)
    mov r14, r5                             ! r5 = 0 (arg2 for display_channel_b)
    mov.b r3, @r2                           ! replay_mode_flag = r3 (caller's byte arg)
    mov.l   _pool_menu_scroll_pos, r3       ! r3 = &menu_scroll_pos
    mov.l r14, @r3                          ! menu_scroll_pos = 0 (clear scroll state)
    mov.l   _pool_fn_display_channel_b, r3  ! r3 = &display_channel_b
    jsr @r3                                 ! display_channel_b(32, 0, 0) — enable channel 32
    mov #0x20, r4                           ! r4 = 0x20 (arg1 = channel 32, in delay slot)
    mov.l   _pool_position_vec_a, r4        ! r4 = &position_vec_a (XYZ triplet, 12 bytes)
    mov.l r14, @r4                          ! position_vec_a.x = 0
    mov.l   .L_fp_eight, r2                 ! r2 = 0x00080000 (8.0 in 16.16 fixed-point)
    mov.l r2, @(4, r4)                      ! position_vec_a.y = 8.0fp
    shlr2 r2                                ! r2 >>= 2 -> 0x00020000 (2.0 in 16.16 fp)
    mov.l   _pool_fp_fifteen_point_two, r3  ! r3 = 0x000F3333 (~15.2 in 16.16 fp)
    mov.l r3, @(8, r4)                      ! position_vec_a.z = 15.2fp
    mov.l   _pool_position_vec_b, r4        ! r4 = &position_vec_b (XYZ triplet, 12 bytes)
    mov.l r14, @r4                          ! position_vec_b.x = 0
    mov.l r2, @(4, r4)                      ! position_vec_b.y = 2.0fp
    mov r4, r2                              ! r2 = &position_vec_b (src for memcpy below)
    mov.l   _pool_fp_five_point_two, r3     ! r3 = 0x00053333 (~5.2 in 16.16 fp)
    mov.l r3, @(8, r4)                      ! position_vec_b.z = 5.2fp
    mov.l   _pool_position_vec_c, r1        ! r1 = &position_vec_c (dst)
    mov.l   _pool_fn_memcpy_long, r3        ! r3 = &memcpy_long
    jsr @r3                                 ! memcpy_long(12, vec_c, vec_b) — clone B into C
    mov #0xC, r0                            ! r0 = 12 bytes (delay slot)
    mov.l   _pool_position_vec_d, r1        ! r1 = &position_vec_d (dst)
    mov.l   _pool_fn_memcpy_long, r3        ! r3 = &memcpy_long
    jsr @r3                                 ! memcpy_long(12, vec_d, vec_b) — clone B into D
    mov #0xC, r0                            ! r0 = 12 bytes (delay slot)
    mov.l   _pool_position_vec_e, r1        ! r1 = &position_vec_e (dst)
    mov.l   _pool_fn_memcpy_long, r3        ! r3 = &memcpy_long
    jsr @r3                                 ! memcpy_long(12, vec_e, vec_b) — clone B into E
    mov #0xC, r0                            ! r0 = 12 bytes (delay slot)
    mov.w   DAT_0601214e, r2                ! r2 = 0x1000 (initial animation counter value)
    extu.b r14, r1                          ! r1 = 0 (zero-extended byte)
    mov.l   _pool_anim_counter, r3          ! r3 = &anim_counter (16-bit)
    mov.w r2, @r3                           ! anim_counter = 0x1000
    exts.w r14, r2                          ! r2 = 0 (sign-extended word)
    mov.l   _pool_rotation_angle, r3        ! r3 = &rotation_angle (16-bit)
    mov.w r2, @r3                           ! rotation_angle = 0
    mov.l   _pool_file_read_init_flag, r3   ! r3 = &file_read_init_flag (byte)
    mov.b r1, @r3                           ! file_read_init_flag = 0 (not yet initialized)
    mov.l   _pool_menu_state_counter, r5    ! r5 = &menu_state_counter
    mov.l   _pool_frame_timer, r4           ! r4 = &frame_timer
    mov.l   _pool_race_end_state, r0        ! r0 = &race_end_state
    mov.l @r0, r0                           ! r0 = race_end_state value
    tst r0, r0                              ! test if race_end_state == 0
    bf      .L_race_ended                   ! if nonzero (race ended), branch
    mov #0x3C, r3                           ! r3 = 60 (frame count for normal timer)
    mov.l r3, @r4                           ! frame_timer = 60
    bra     .L_return                       ! jump to normal return
    mov.l r14, @r5                          ! menu_state_counter = 0 (delay slot)
.L_race_ended:
    mov #0x1, r2                            ! r2 = 1 (single-frame timer for immediate transition)
    mov.l r2, @r4                           ! frame_timer = 1
    mov #0x14, r3                           ! r3 = 20 (state 20 = cleanup/transition)
    mov.l r3, @r5                           ! menu_state_counter = 20
    lds.l @r15+, pr                         ! restore return address
    .byte   0xA0, 0xA1    /* bra 0x0601228A (external) */  ! tail-call lap_time_formatter
    mov.l @r15+, r14                        ! restore r14 (delay slot)
.L_return:
    lds.l @r15+, pr                         ! restore return address
    rts                                     ! return to caller
    mov.l @r15+, r14                        ! restore r14 (delay slot)

    .global DAT_0601214e
DAT_0601214e:
    .2byte  0x1000                          /* initial animation counter value */
_pool_replay_mode_flag:
    .4byte  sym_06078636                    /* replay mode flag (byte) */
_pool_menu_scroll_pos:
    .4byte  sym_060788F8                    /* menu scroll position (dword) */
_pool_fn_display_channel_b:
    .4byte  display_channel_b               /* display channel enable function */
_pool_position_vec_a:
    .4byte  sym_060788B4                    /* position vector A: primary HUD element XYZ */
.L_fp_eight:
    .4byte  0x00080000                      /* 8.0 (16.16 fixed-point) */
_pool_fp_fifteen_point_two:
    .4byte  0x000F3333                      /* ~15.2 (16.16 fixed-point) */
_pool_position_vec_b:
    .4byte  sym_060788C0                    /* position vector B: secondary HUD element XYZ */
_pool_fp_five_point_two:
    .4byte  0x00053333                      /* ~5.2 (16.16 fixed-point) */
_pool_position_vec_c:
    .4byte  sym_060788CC                    /* position vector C (initialized as copy of B) */
_pool_fn_memcpy_long:
    .4byte  sym_06035168                    /* memcpy_long(r0=nbytes, r1=dst, r2=src) */
_pool_position_vec_d:
    .4byte  sym_060788D8                    /* position vector D (initialized as copy of B) */
_pool_position_vec_e:
    .4byte  sym_060788E4                    /* position vector E (initialized as copy of B) */
_pool_anim_counter:
    .4byte  sym_060788B0                    /* animation counter (16-bit) */
_pool_rotation_angle:
    .4byte  sym_060788B2                    /* Z rotation angle state (16-bit) */
_pool_file_read_init_flag:
    .4byte  sym_060788F0                    /* file read initialized flag (byte) */
_pool_menu_state_counter:
    .4byte  sym_060788F4                    /* menu state counter (dword) */
_pool_frame_timer:
    .4byte  sym_060788AC                    /* frame timer / state counter (dword) */
_pool_race_end_state:
    .4byte  sym_0607EAD8                    /* race end state (0=racing, nonzero=ended) */

    .global sym_06012198
sym_06012198:
    .byte   0xD0, 0x21    /* mov.l .L_pool_06012220, r0 */  ! r0 = &race_end_state (via pool in next TU)
    mov.l @r0, r0                           ! r0 = race_end_state value
    tst r0, r0                              ! test if race still active
    bt      .L_race_active                  ! if zero (still racing), go to menu logic
    .byte   0xA0, 0x73    /* bra 0x0601228A (external) */  ! branch to lap_time_formatter (race ended)
    nop                                     ! delay slot
.L_race_active:
    .byte   0xA3, 0x1C    /* bra 0x060127E0 (external) */  ! branch to hud_menu_logic (race active)
    nop                                     ! delay slot
