/* force_table_apply -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06008418 - 0x060088CC
 *
 * Collision force system for Daytona USA. When two cars collide, the game
 * plays a force animation: a pre-authored sequence of XYZ force vectors
 * applied over several frames to push the cars apart. This TU manages the
 * entire lifecycle: triggering the force sequence on impact, reading entries
 * from a force table, applying directional force vectors each frame, counting
 * down timers, and cleaning up when the sequence finishes.
 *
 * The force table is a flat array of 12-byte entries:
 *   [+0] 4-byte pointer to rendering/animation data
 *   [+4] 2-byte direction/magnitude control word
 *   [+6] 2-byte force X component
 *   [+8] 2-byte force Y component
 *   [+A] 2-byte force Z component
 * The car struct's force pointer (car[+0x1B8]) advances by 12 bytes per
 * frame, walking through the table until the collision timer expires.
 *
 * Functions (7):
 *
 * force_steer_calc (0x06008418):
 *   Collision entry point A. If collision timer is zero (no active collision),
 *   optionally plays a collision sound (if race_flags bit 17 set), sets car
 *   flags byte bit 0, writes 0xCC to car[+0x214], then tail-calls
 *   race_config_physics with force_config_a. Used for standard collisions.
 *
 * force_steer_impact (0x0600845E):
 *   Collision entry point B. Identical to force_steer_calc except it uses
 *   force_config_b. Used for harder impact collisions.
 *
 * race_config_physics (0x060084C8):
 *   Increments the collision count (car[+0x1D4]), clears force counter
 *   (car[+0x1C4]), calls force_table_apply to begin the force sequence.
 *   If the current car is the player, sets up end-of-race camera/display:
 *   display_mode=3, lap_count=7, camera_mode=2, view frustum parameters
 *   (near=0xF300, far=0x6E0000, z_scale=16.0).
 *
 * brake_force_apply (0x060085C8):
 *   Called during braking when a collision is active. Sets a 70-frame brake
 *   timeout, optionally copies position/velocity data when the secondary
 *   timer hits 1 and bit 7 of car[+0x160] is set. Calls the force tick
 *   handler, then checks lap threshold when the collision timer expires.
 *
 * sym_06008640 (force_dispatch):
 *   Dispatches force processing based on car flags. If bit 3 of car[+0x00]
 *   is set, clears it and either runs the force tick (if collision timer > 0)
 *   or sets up a 20-frame display timer and selects a force config based on
 *   race flags bit 23 or frame counter parity.
 *
 * force_table_apply (0x060086C4):
 *   Initializes a new force sequence. Commits force state to two display
 *   channels (via channel_commit), copies the force data pointer and timer
 *   values from the config entry into the car struct, then falls through
 *   to the force tick handler.
 *
 * force_tick_handler (0x06008730):
 *   Per-frame force application. Decrements collision timer (car[+0x1BC])
 *   and secondary timer (car[+0xBC]). Reads the next 12-byte force table
 *   entry, advances the force pointer, and applies XYZ force vectors to the
 *   car struct -- negating components based on direction flags (bit 6 negates
 *   Y/Z, bit 7 negates X/Y). When the collision timer reaches zero, clears
 *   all force state and optionally sets display_mode=4 for post-collision UI.
 *
 * Car struct offsets used:
 *   +0x001 = flags byte           +0x004 = car ID
 *   +0x028 = position copy dst    +0x030 = position copy src
 *   +0x0BC = secondary timer      +0x0D4 = display timer (16-bit)
 *   +0x160 = extended flags       +0x1AC = (cleared on init)
 *   +0x1B4 = force data ptr       +0x1B8 = force table read ptr
 *   +0x1BC = collision timer      +0x1C0 = direction flags
 *   +0x1C4 = force counter        +0x1C8 = force X
 *   +0x1CC = force Y              +0x1D0 = force Z
 *   +0x1D4 = collision count      +0x1E4 = velocity copy dst
 *   +0x1EC = velocity copy src    +0x208 = alt force data
 *   +0x214 = collision flags word
 *
 * Persistent registers:
 *   r14 = &car state pointer (sym_0607E944 in steer funcs, sym_0607E940 elsewhere)
 *   r4  = &car state pointer (in force_tick_handler)
 *   r5  = force table entry pointer (in force_tick_handler)
 *   r6  = zero constant (in force_tick_handler)
 *   r7  = direction/magnitude word (in force_tick_handler)
 */

    .section .text.FUN_06008418


    .global force_steer_calc
    .type force_steer_calc, @function
force_steer_calc:
    mov.l r14, @-r15                     ! push r14
    sts.l pr, @-r15                      ! push PR (return address)
    mov.l   .L_car_state_ptr, r14        ! r14 = &car_state_ptr
    mov.w   DAT_060084a2, r0             ! r0 = 0x01BC (collision timer offset)
    mov.l @r14, r3                       ! r3 = car struct base
    mov.l @(r0, r3), r0                  ! r0 = car[+0x1BC] (collision timer)
    tst r0, r0                           ! timer == 0?
    bf      .L_steer_calc_return         ! no -- collision already active, bail out
    mov.l   .L_race_flags, r3            ! r3 = &race_flags
    mov.l   .L_fp_two, r2               ! r2 = 0x20000 (bit 17 mask)
    mov.l @r3, r3                        ! r3 = race_flags value
    and r2, r3                           ! isolate bit 17
    tst r3, r3                           ! bit 17 set?
    bt      .L_steer_calc_set_flags      ! no -- skip collision sound
    mov.l   .L_snd_cmd_collision, r5     ! r5 = 0xAE1102FF (collision sound cmd)
    mov.l   .L_fn_sound_dispatch, r3     ! r3 = &sound_cmd_dispatch
    jsr @r3                              ! sound_cmd_dispatch(0, collision_snd)
    mov #0x0, r4                         ! r4 = 0 (delay slot: arg0 = channel 0)
.L_steer_calc_set_flags:                 ! --- Set car flags + collision config ---
    mov.l @r14, r3                       ! r3 = car struct base
    add #0x1, r3                         ! r3 = &car[+0x01] (flags byte)
    mov.b @r3, r0                        ! r0 = car[+0x01] flags byte
    and #0xFE, r0                        ! clear bit 0
    or #0x1, r0                          ! set bit 0 (collision active)
    mov.b r0, @r3                        ! write back flags
    mov.l @r14, r2                       ! r2 = car struct base
    mov.w   DAT_060084a4, r3             ! r3 = 0xCC (collision marker value)
    mov.w   DAT_060084a6, r0             ! r0 = 0x0214 (collision flags word offset)
    mov.l r3, @(r0, r2)                  ! car[+0x214] = 0xCC
    mov.l   .L_force_config_a, r4        ! r4 = &force_config_a pointer
    mov.l @r4, r4                        ! r4 = force config table A entry
    lds.l @r15+, pr                      ! pop PR (prepare for tail-call)
    bra     race_config_physics          ! tail-call race_config_physics(config_a)
    mov.l @r15+, r14                     ! pop r14 (delay slot)
.L_steer_calc_return:                    ! --- Early return: collision already active ---
    lds.l @r15+, pr                      ! pop PR
    rts                                  ! return
    mov.l @r15+, r14                     ! pop r14 (delay slot)

    .global force_steer_impact
    .type force_steer_impact, @function
force_steer_impact:
    mov.l r14, @-r15                     ! push r14
    sts.l pr, @-r15                      ! push PR
    mov.l   .L_car_state_ptr, r14        ! r14 = &car_state_ptr
    mov.w   DAT_060084a2, r0             ! r0 = 0x01BC (collision timer offset)
    mov.l @r14, r3                       ! r3 = car struct base
    mov.l @(r0, r3), r0                  ! r0 = car[+0x1BC] (collision timer)
    tst r0, r0                           ! timer == 0?
    bf      .L_steer_impact_return       ! no -- collision already active, bail out
    mov.l   .L_race_flags, r3            ! r3 = &race_flags
    mov.l   .L_fp_two, r2               ! r2 = 0x20000 (bit 17 mask)
    mov.l @r3, r3                        ! r3 = race_flags value
    and r2, r3                           ! isolate bit 17
    tst r3, r3                           ! bit 17 set?
    bt      .L_steer_impact_set_flags    ! no -- skip collision sound
    mov.l   .L_snd_cmd_collision, r5     ! r5 = collision sound command
    mov.l   .L_fn_sound_dispatch, r3     ! r3 = &sound_cmd_dispatch
    jsr @r3                              ! sound_cmd_dispatch(0, collision_snd)
    mov #0x0, r4                         ! r4 = 0 (delay slot: arg0 = channel 0)
.L_steer_impact_set_flags:               ! --- Set car flags + impact config ---
    mov.l @r14, r3                       ! r3 = car struct base
    add #0x1, r3                         ! r3 = &car[+0x01]
    mov.b @r3, r0                        ! r0 = car[+0x01] flags byte
    and #0xFE, r0                        ! clear bit 0
    or #0x1, r0                          ! set bit 0 (collision active)
    mov.b r0, @r3                        ! write back flags
    mov.l @r14, r2                       ! r2 = car struct base
    mov.w   DAT_060084a4, r3             ! r3 = 0xCC (collision marker)
    mov.w   DAT_060084a6, r0             ! r0 = 0x0214 offset
    mov.l r3, @(r0, r2)                  ! car[+0x214] = 0xCC
    mov.l   .L_force_config_b, r4        ! r4 = &force_config_b pointer
    mov.l @r4, r4                        ! r4 = force config table B (impact)
    lds.l @r15+, pr                      ! pop PR (prepare for tail-call)
    bra     race_config_physics          ! tail-call race_config_physics(config_b)
    mov.l @r15+, r14                     ! pop r14 (delay slot)

    .global DAT_060084a2
DAT_060084a2:
    .2byte  0x01BC                        /* car struct: collision timer offset */

    .global DAT_060084a4
DAT_060084a4:
    .2byte  0x00CC                        /* constant 0xCC (written to flags) */

    .global DAT_060084a6
DAT_060084a6:
    .2byte  0x0214                        /* car struct: flags word offset */
.L_car_state_ptr:
    .4byte  sym_0607E944               /* player car state pointer */
.L_race_flags:
    .4byte  sym_0607EBC4               /* race flags (32-bit) */
.L_fp_two:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */
.L_snd_cmd_collision:
    .4byte  0xAE1102FF                  /* sound command: collision */
.L_fn_sound_dispatch:
    .4byte  sound_cmd_dispatch         /* sound command dispatcher */
.L_force_config_a:
    .4byte  sym_060453B4               /* force config table A */
.L_force_config_b:
    .4byte  sym_060453BC               /* force config table B */
.L_steer_impact_return:                  ! --- Shared epilogue for steer_impact ---
    lds.l @r15+, pr                      ! pop PR
    rts                                  ! return
    mov.l @r15+, r14                     ! pop r14 (delay slot)

    .global race_config_physics
    .type race_config_physics, @function
race_config_physics:
    mov.l r14, @-r15                     ! push r14
    sts.l pr, @-r15                      ! push PR
    mov.l   .L_car_state_ptr_b, r14      ! r14 = &car_state_ptr
    mov.w   DAT_0600855e, r0             ! r0 = 0x01D4 (collision count offset)
    mov.l @r14, r3                       ! r3 = car struct base
    mov.l @(r0, r3), r2                  ! r2 = car[+0x1D4] (collision count)
    add #0x1, r2                         ! increment
    mov.l r2, @(r0, r3)                  ! car[+0x1D4]++ (collision count)
    mov #0x0, r2                         ! r2 = 0
    add #-0x10, r0                       ! r0 = 0x01D4 - 0x10 = 0x01C4 (force counter)
    mov.l @r14, r3                       ! r3 = car struct base
    mov.l r2, @(r0, r3)                  ! car[+0x1C4] = 0 (clear force counter)
    bsr     force_table_apply            ! initialize force sequence from config in r4
    nop
    mov.l @r14, r2                       ! r2 = car struct base (after force_table_apply)
    mov.l   .L_player_car_base, r3       ! r3 = player car array base address
    cmp/eq r3, r2                        ! is this the player car?
    bf      .L_config_physics_return     ! no -- skip end-of-race setup
    mov.l   .L_race_flags_b, r3          ! r3 = &race_flags
    mov.l   .L_fp_two_b, r2             ! r2 = 0x20000 (bit 17 mask)
    mov.l @r3, r3                        ! r3 = race_flags value
    and r2, r3                           ! isolate bit 17
    tst r3, r3                           ! bit 17 set?
    bt      .L_config_physics_return     ! no -- skip end-of-race setup
    mov.l   .L_demo_flag, r0             ! r0 = &demo_flag
    mov.b @r0, r0                        ! r0 = demo_flag byte
    extu.b r0, r0                        ! zero-extend to 32-bit
    tst r0, r0                           ! demo mode active?
    bf      .L_end_race_display_setup    ! yes -- skip special render check
    mov.l   .L_special_render_flag, r0   ! r0 = &special_render_flag
    mov.w @r0, r0                        ! r0 = special_render_flag (16-bit)
    extu.w r0, r0                        ! zero-extend to 32-bit
    tst r0, r0                           ! special render active?
    bf      .L_config_physics_return     ! yes -- skip end-of-race setup
.L_end_race_display_setup:               ! === End-of-race camera/display config ===
    mov #0x3, r3                         ! display mode value
    mov.l   .L_display_mode_word, r2     ! r2 = &display_mode
    mov #0x0, r5                         ! r5 = 0 (channel_nibble_config arg1)
    mov.w r3, @r2                        ! display_mode = 3
    mov #0x7, r3                         ! lap count value
    mov.l   .L_lap_count, r2             ! r2 = &lap_count
    mov.b r3, @r2                        ! lap_count = 7
    mov #0x2, r3                         ! camera mode value
    mov.l   .L_camera_mode, r2           ! r2 = &camera_mode
    mov.l r3, @r2                        ! camera_mode = 2
    mov #0x1, r3                         ! camera follow enabled
    mov.l   .L_camera_follow, r2         ! r2 = &camera_follow
    mov.l r3, @r2                        ! camera_follow = 1
    mov.l   .L_fn_channel_config, r3     ! r3 = &channel_nibble_config
    jsr @r3                              ! channel_nibble_config(8, 0)
    mov #0x8, r4                         ! r4 = 8 (delay slot: arg0 = channel 8)
    mov.l   .L_z_near_start, r2          ! r2 = 0x58000 (view z start, 5.5 in 16.16)
    mov.l   .L_camera_yaw_ptr, r3        ! r3 = &camera_yaw
    mov.l r2, @r3                        ! camera_yaw = 0x58000
    mov.l   .L_z_near_clip, r2           ! r2 = 0xF300 (near clip distance)
    mov.l   .L_camera_near_store, r3     ! r3 = &camera_near_clip
    mov.l r2, @r3                        ! near_clip = 0xF300
    mov.l   .L_z_far_clip, r2            ! r2 = 0x6E0000 (far clip distance)
    mov.l   .L_camera_far_store, r3      ! r3 = &camera_far_clip
    mov.l r2, @r3                        ! far_clip = 0x6E0000
    mov.l   .L_fp_sixteen, r2            ! r2 = 0x100000 (16.0 in 16.16)
    mov.l   .L_camera_scale_store, r3    ! r3 = &camera_z_scale
    mov.l r2, @r3                        ! z_scale = 16.0
    mov #0x0, r2                         ! r2 = 0
    mov.l   .L_camera_clear, r3          ! r3 = &camera_clear
    mov.l r2, @r3                        ! camera_clear = 0
    mov.l @r14, r2                       ! r2 = car struct base
    mov.w   .L_off_collision_timer_b, r0 ! r0 = 0x01BC (collision timer offset)
    mov.l @(r0, r2), r3                  ! r3 = car[+0x1BC] (collision timer)
    exts.b r3, r3                        ! sign-extend low byte
    mov.l   .L_course_section_byte, r2   ! r2 = &course_section
    mov.b r3, @r2                        ! course_section = collision timer low byte
.L_config_physics_return:                ! --- Epilogue ---
    lds.l @r15+, pr                      ! pop PR
    rts                                  ! return
    mov.l @r15+, r14                     ! pop r14 (delay slot)

    .global DAT_0600855e
DAT_0600855e:
    .2byte  0x01D4                        /* car struct: collision count offset */
.L_off_collision_timer_b:
    .2byte  0x01BC                        /* car struct: collision timer offset */
    .2byte  0xFFFF
.L_car_state_ptr_b:
    .4byte  sym_0607E944               /* player car state pointer */
.L_player_car_base:
    .4byte  sym_06078900               /* player car array base */
.L_race_flags_b:
    .4byte  sym_0607EBC4               /* race flags (32-bit) */
.L_fp_two_b:
    .4byte  0x00020000                  /* 2.0 (16.16 fixed-point) */
.L_demo_flag:
    .4byte  sym_06078635               /* demo mode flag (byte) */
.L_special_render_flag:
    .4byte  sym_0607ED8C               /* special render enable (16-bit) */
.L_display_mode_word:
    .4byte  sym_0605A016               /* display mode (16-bit) */
.L_lap_count:
    .4byte  sym_06078654               /* lap count (byte) */
.L_camera_mode:
    .4byte  sym_06063E1C               /* camera mode (32-bit) */
.L_camera_follow:
    .4byte  sym_06059F30               /* camera follow flag (32-bit) */
.L_fn_channel_config:
    .4byte  channel_nibble_config      /* channel configuration function */
.L_z_near_start:
    .4byte  0x00058000                  /* view z near start (5.5 in 16.16) */
.L_camera_yaw_ptr:
    .4byte  sym_06063E24               /* camera yaw parameter */
.L_z_near_clip:
    .4byte  0x0000F300                  /* near clip distance */
.L_camera_near_store:
    .4byte  sym_06063E34               /* camera near clip store */
.L_z_far_clip:
    .4byte  0x006E0000                  /* far clip distance */
.L_camera_far_store:
    .4byte  sym_06063E28               /* camera far clip store */
.L_fp_sixteen:
    .4byte  0x00100000                  /* 16.0 (16.16 fixed-point) */
.L_camera_scale_store:
    .4byte  sym_06063E2C               /* camera z-scale store */
.L_camera_clear:
    .4byte  sym_06063E30               /* camera clear register */
.L_course_section_byte:
    .4byte  sym_0607866C               /* course section byte */

    .global brake_force_apply
    .type brake_force_apply, @function
brake_force_apply:
    mov.l r14, @-r15                     ! push r14
    sts.l pr, @-r15                      ! push PR
    mov.l   .L_active_car_ptr, r14       ! r14 = &active_car_ptr
    mov.w   DAT_06008624, r0             ! r0 = 0x01BC (collision timer offset)
    mov.l @r14, r3                       ! r3 = car struct base
    mov.l @(r0, r3), r0                  ! r0 = car[+0x1BC] (collision timer)
    tst r0, r0                           ! collision active?
    bt      .L_brake_force_return        ! no -- nothing to do, return
    mov #0x46, r3                        ! r3 = 0x46 (70 decimal)
    mov.l   .L_brake_timeout, r2         ! r2 = &brake_timeout
    mov.l r3, @r2                        ! brake_timeout = 70 frames
    mov.l @r14, r0                       ! r0 = car struct base
    mov.w   DAT_06008626, r1             ! r1 = 0x00BC (secondary timer offset)
    mov.l @(r0, r1), r0                  ! r0 = car[+0xBC] (secondary timer)
    cmp/eq #0x1, r0                      ! timer == 1? (last frame)
    bf      .L_brake_call_tick           ! no -- skip position snapshot
    mov.l @r14, r2                       ! r2 = car struct base
    mov.w   .L_off_car_flags_160, r0     ! r0 = 0x0160 (extended flags offset)
    mov.b @(r0, r2), r0                  ! r0 = car[+0x160] extended flags
    tst #0x80, r0                        ! bit 7 set? (position copy enabled)
    bt      .L_brake_call_tick           ! no -- skip position snapshot
    mov.l @r14, r3                       ! r3 = car struct base
    mov r3, r2                           ! r2 = car struct base (alias)
    mov.l @(48, r2), r1                  ! r1 = car[+0x30] (position source)
    mov.l r1, @(40, r3)                  ! car[+0x28] = car[+0x30] (copy position)
    mov.l @r14, r3                       ! r3 = car struct base
    mov r3, r2                           ! r2 = car struct base (alias)
    mov.w   DAT_0600862a, r0             ! r0 = 0x01EC (velocity source offset)
    mov.l @(r0, r2), r1                  ! r1 = car[+0x1EC] (velocity source)
    add #-0x8, r0                        ! r0 = 0x01E4 (velocity dest offset)
    mov.l r1, @(r0, r3)                  ! car[+0x1E4] = car[+0x1EC] (copy velocity)
.L_brake_call_tick:                      ! --- Run force tick + check lap threshold ---
    bsr     .L_force_tick_handler        ! call force_tick_handler
    nop
    mov #0x1, r4                         ! r4 = 1 (comparison value)
    mov.l @r14, r2                       ! r2 = car struct base
    mov.w   DAT_06008624, r0             ! r0 = 0x01BC (collision timer offset)
    mov.l @(r0, r2), r3                  ! r3 = car[+0x1BC] (collision timer)
    cmp/gt r4, r3                        ! timer > 1? (still counting)
    bt      .L_brake_force_return        ! yes -- not expired yet, return
    mov.l   .L_lap_count_b, r5           ! r5 = &lap_count
    mov.l   .L_race_flags_c, r2          ! r2 = &race_flags
    mov.l   .L_wram_low, r3             ! r3 = 0x200000 (WRAM Low sentinel)
    mov.l @r2, r2                        ! r2 = race_flags value
    cmp/eq r3, r2                        ! race_flags == 0x200000? (special sentinel)
    bf      .L_brake_set_lap_one         ! no -- set lap count to 1
    mov #0x4, r3                         ! r3 = 4
    mov.b r3, @r5                        ! lap_count = 4 (sentinel match)
    bra     .L_brake_force_return        ! done
    nop
.L_brake_set_lap_one:                    ! --- Default lap count ---
    extu.b r4, r4                        ! r4 = 1 (zero-extend)
    mov.b r4, @r5                        ! lap_count = 1
.L_brake_force_return:                   ! --- Epilogue ---
    lds.l @r15+, pr                      ! pop PR
    rts                                  ! return
    mov.l @r15+, r14                     ! pop r14 (delay slot)

    .global DAT_06008624
DAT_06008624:
    .2byte  0x01BC                        /* car struct: collision timer offset */

    .global DAT_06008626
DAT_06008626:
    .2byte  0x00BC                        /* car struct: timer offset */
.L_off_car_flags_160:
    .2byte  0x0160                        /* car struct: flags at +0x160 */

    .global DAT_0600862a
DAT_0600862a:
    .2byte  0x01EC                        /* car struct: velocity B offset */
.L_active_car_ptr:
    .4byte  sym_0607E940               /* active car state pointer */
.L_brake_timeout:
    .4byte  sym_0607EBD4               /* brake timeout counter (32-bit) */
.L_lap_count_b:
    .4byte  sym_06078654               /* lap count (byte) */
.L_race_flags_c:
    .4byte  sym_0607EBC4               /* race flags (32-bit) */
.L_wram_low:
    .4byte  0x00200000                  /* Work RAM Low base */

    .global sym_06008640
sym_06008640:                            ! === Force dispatch ===
    mov.l   .L_active_car_ptr_b, r4      ! r4 = &active_car_ptr
    mov.l @r4, r2                        ! r2 = car struct base
    mov r2, r0                           ! r0 = car struct base (for byte read)
    mov.b @r0, r0                        ! r0 = car[+0x00] flags byte
    tst #0x8, r0                         ! bit 3 set? (new collision trigger)
    bf      .L_dispatch_clear_bit3       ! yes -- clear bit 3, then check timer
    mov.l @r4, r3                        ! r3 = car struct base (bit 3 clear path)
    mov.w   .L_off_collision_timer, r0   ! r0 = 0x01BC (collision timer offset)
    mov.l @(r0, r3), r0                  ! r0 = car[+0x1BC] (collision timer)
    tst r0, r0                           ! timer active?
    bt      .L_dispatch_return           ! no -- nothing to process, return
    bra     .L_force_tick_handler        ! yes -- run per-frame force tick
    nop
.L_dispatch_clear_bit3:                  ! --- Clear collision trigger bit ---
    mov.l @r4, r3                        ! r3 = car struct base
    mov.b @r3, r0                        ! r0 = car[+0x00] flags byte
    and #0xF7, r0                        ! clear bit 3
    or #0x0, r0                          ! (no-op OR, preserves flags)
    mov.b r0, @r3                        ! write back cleared flags
    mov.l @r4, r2                        ! r2 = car struct base
    mov.w   .L_off_collision_timer, r0   ! r0 = 0x01BC
    mov.l @(r0, r2), r0                  ! r0 = car[+0x1BC] (collision timer)
    tst r0, r0                           ! timer active?
    bt      .L_dispatch_setup_timer      ! no -- set up display timer + new force
    bra     .L_force_tick_handler        ! yes -- run per-frame force tick
    nop
.L_dispatch_setup_timer:                 ! --- New collision: set display timer ---
    mov #0x14, r3                        ! r3 = 0x14 (20 decimal)
    mov.w   .L_off_display_timer, r0     ! r0 = 0x00D4 (display timer offset)
    mov.l @r4, r2                        ! r2 = car struct base
    mov.w r3, @(r0, r2)                  ! car[+0xD4] = 20 (display countdown)
    mov.l   .L_race_flags_d, r3          ! r3 = &race_flags
    mov.l   .L_race_flag_bit, r2         ! r2 = 0x800000 (bit 23 mask)
    mov.l @r3, r3                        ! r3 = race_flags value
    and r2, r3                           ! isolate bit 23
    tst r3, r3                           ! bit 23 set?
    bt      .L_dispatch_frame_parity     ! no -- select config by frame parity
    mov.l   .L_force_config_c, r4        ! r4 = &force_config_c pointer
    bra     force_table_apply            ! begin force sequence with config C
    mov.l @r4, r4                        ! r4 = config C entry (delay slot)
.L_dispatch_frame_parity:                ! --- Select config by frame parity ---
    mov.l   .L_frame_counter, r0         ! r0 = &frame_counter
    mov.l @r0, r0                        ! r0 = frame_counter value
    and #0x1, r0                         ! r0 = frame & 1 (even/odd parity)
    mov r0, r4                           ! r4 = parity (0 or 1)
    shll2 r4                             ! r4 = parity * 4
    shll r4                              ! r4 = parity * 8 (config entry stride)
    mov.l   .L_force_config_table, r3    ! r3 = force_config_table base
    add r3, r4                           ! r4 = &config_table[parity]
    bra     force_table_apply            ! begin force sequence with selected config
    mov.l @r4, r4                        ! r4 = config entry (delay slot)
.L_dispatch_return:                      ! --- No-op return ---
    rts                                  ! return
    nop
.L_off_collision_timer:
    .2byte  0x01BC                        /* car struct: collision timer offset */
.L_off_display_timer:
    .2byte  0x00D4                        /* car struct: display timer offset */
.L_active_car_ptr_b:
    .4byte  sym_0607E940               /* active car state pointer */
.L_race_flags_d:
    .4byte  sym_0607EBC4               /* race flags (32-bit) */
.L_race_flag_bit:
    .4byte  0x00800000                  /* race flag bit 23 */
.L_force_config_c:
    .4byte  sym_060453C4               /* force config table C */
.L_frame_counter:
    .4byte  sym_0607EBD0               /* frame counter (32-bit) */
.L_force_config_table:
    .4byte  sym_060453B4               /* force config table base */

    .global force_table_apply
    .type force_table_apply, @function
force_table_apply:
    sts.l pr, @-r15                      ! push PR
    mov #0x1, r6                         ! r6 = 1 (constant, also channel ID)
    mov.l   .L_frame_counter_b, r7       ! r7 = &frame_counter (persistent)
    mov.l   .L_active_car_ptr_c, r5      ! r5 = &active_car_ptr (persistent)
    mov.w   .L_off_force_state, r3       ! r3 = 0x01C0 (force state offset)
    mov.l @r7, r0                        ! r0 = frame_counter value
    mov.l @r5, r2                        ! r2 = car struct base
    and r6, r0                           ! r0 = frame & 1 (parity bit)
    add r3, r2                           ! r2 = &car[+0x1C0] (force state addr)
    mov.l   .L_fn_channel_commit, r3     ! r3 = &channel_commit
    jsr @r3                              ! channel_commit(car+0x1C0, parity, 1)
    mov r6, r1                           ! r1 = 0x0001 (delay slot: channel ID)
    mov.l @r5, r2                        ! r2 = car struct base (reload)
    mov.l @r7, r0                        ! r0 = frame_counter value
    mov.w   .L_off_force_state, r3       ! r3 = 0x01C0
    mov.w   .L_channel_id_b, r1         ! r1 = 0x0101 (second channel ID)
    shar r0                              ! r0 = frame_counter >> 1 (half-rate parity)
    add r3, r2                           ! r2 = &car[+0x1C0]
    mov.l   .L_fn_channel_commit, r3     ! r3 = &channel_commit
    jsr @r3                              ! channel_commit(car+0x1C0, parity>>1, 0x0101)
    and r6, r0                           ! r0 = (frame>>1) & 1 (delay slot)
    mov.l @r5, r2                        ! r2 = car struct base
    mov.l @r4, r3                        ! r3 = config[+0] (force data pointer)
    mov.w   .L_off_force_ptr, r0         ! r0 = 0x01B8 (force table read ptr offset)
    mov.l r3, @(r0, r2)                  ! car[+0x1B8] = force data pointer
    mov.l @(4, r4), r4                   ! r4 = config[+4] (timer/duration value)
    mov.l @r5, r3                        ! r3 = car struct base
    mov.w   DAT_0600871a, r0             ! r0 = 0x01BC (collision timer offset)
    mov.l r4, @(r0, r3)                  ! car[+0x1BC] = timer (collision duration)
    add #-0x28, r4                       ! r4 = timer - 40 (secondary timer offset)
    mov.l @r5, r3                        ! r3 = car struct base
    mov.w   DAT_0600871c, r0             ! r0 = 0x00BC (secondary timer offset)
    mov.l r4, @(r0, r3)                  ! car[+0xBC] = timer - 40
    mov.l @r5, r3                        ! r3 = car struct base
    mov.w   .L_off_alt_force_ptr, r0     ! r0 = 0x0208 (alt force data offset)
    mov.l r4, @(r0, r3)                  ! car[+0x208] = timer - 40
    mov.l   .L_force_apply_count, r4     ! r4 = &force_apply_count
    mov.b @r4, r3                        ! r3 = current count
    add r6, r3                           ! r3++ (increment apply count)
    mov.b r3, @r4                        ! write back incremented count
    bra     .L_force_tick_handler        ! fall through to per-frame force tick
    lds.l @r15+, pr                      ! pop PR (delay slot, restores before bra)
.L_off_force_state:
    .2byte  0x01C0                        /* car struct: force state offset */
.L_channel_id_b:
    .2byte  0x0101                        /* channel ID 0x0101 */
.L_off_force_ptr:
    .2byte  0x01B8                        /* car struct: force pointer offset */

    .global DAT_0600871a
DAT_0600871a:
    .2byte  0x01BC                        /* car struct: collision timer offset */

    .global DAT_0600871c
DAT_0600871c:
    .2byte  0x00BC                        /* car struct: timer offset */
.L_off_alt_force_ptr:
    .2byte  0x0208                        /* car struct: alt force pointer offset */
.L_frame_counter_b:
    .4byte  sym_0607EBD0               /* frame counter (32-bit) */
.L_active_car_ptr_c:
    .4byte  sym_0607E940               /* active car state pointer */
.L_fn_channel_commit:
    .4byte  sym_06034F78               /* channel data commit */
.L_force_apply_count:
    .4byte  sym_0607EBEC               /* force apply count (byte) */
.L_force_tick_handler:                   ! === Per-frame force timer + vector application ===
    mov.l   .L_active_car_ptr_d, r4      ! r4 = &active_car_ptr (persistent for this block)
    mov.w   DAT_060087e8, r0             ! r0 = 0x01BC (collision timer offset)
    mov.l @r4, r3                        ! r3 = car struct base
    mov.l @(r0, r3), r2                  ! r2 = car[+0x1BC] (collision timer)
    cmp/pl r2                            ! timer > 0?
    bf/s    .L_tick_check_secondary      ! no -- skip decrement (timer already 0)
    mov #0x0, r6                         ! r6 = 0 (delay slot: zero constant)
    mov.l @r4, r2                        ! r2 = car struct base
    mov.w   DAT_060087e8, r0             ! r0 = 0x01BC
    mov.l @(r0, r2), r3                  ! r3 = car[+0x1BC]
    add #-0x1, r3                        ! r3-- (decrement collision timer)
    mov.l r3, @(r0, r2)                  ! car[+0x1BC] = timer - 1
.L_tick_check_secondary:                 ! --- Decrement secondary timer ---
    mov.l @r4, r3                        ! r3 = car struct base
    mov.w   DAT_060087ea, r0             ! r0 = 0x00BC (secondary timer offset)
    mov.l @(r0, r3), r2                  ! r2 = car[+0xBC] (secondary timer)
    cmp/pl r2                            ! timer > 0?
    bf      .L_tick_check_display        ! no -- skip decrement
    mov.l @r4, r2                        ! r2 = car struct base
    mov.w   DAT_060087ea, r0             ! r0 = 0x00BC
    mov.l @(r0, r2), r3                  ! r3 = car[+0xBC]
    add #-0x1, r3                        ! r3-- (decrement secondary timer)
    mov.l r3, @(r0, r2)                  ! car[+0xBC] = timer - 1
.L_tick_check_display:                   ! --- Trigger display at timer == 10 ---
    mov.l @r4, r0                        ! r0 = car struct base
    mov.w   DAT_060087ea, r1             ! r1 = 0x00BC
    mov.l @(r0, r1), r0                  ! r0 = car[+0xBC] (secondary timer)
    cmp/eq #0xA, r0                      ! timer == 10?
    bf      .L_tick_read_entry           ! no -- skip display timer set
    mov.l @r4, r2                        ! r2 = car struct base
    mov #0xA, r3                         ! r3 = 10
    mov.w   DAT_060087ec, r0             ! r0 = 0x00D4 (display timer offset)
    mov.w r3, @(r0, r2)                  ! car[+0xD4] = 10 (start display countdown)
.L_tick_read_entry:                      ! === Read next 12-byte force table entry ===
    mov.l @r4, r5                        ! r5 = car struct base (temp)
    mov.w   .L_off_force_ptr_b, r0       ! r0 = 0x01B8 (force read ptr offset)
    mov.l @(r0, r5), r3                  ! r3 = car[+0x1B8] (current force table ptr)
    add #0xC, r3                         ! advance ptr by 12 bytes (next entry)
    mov.l r3, @(r0, r5)                  ! car[+0x1B8] = ptr + 12 (store advanced)
    add #-0xC, r3                        ! rewind to current entry
    add #-0x4, r0                        ! r0 = 0x01B4 (force data ptr offset)
    mov r3, r5                           ! r5 = current force table entry (persistent)
    mov.l @r4, r3                        ! r3 = car struct base
    mov.l @r5, r2                        ! r2 = entry[+0] (force anim/render data ptr)
    mov.l r2, @(r0, r3)                  ! car[+0x1B4] = force render data pointer
    mov.w @(4, r5), r0                   ! r0 = entry[+4] (direction/magnitude word)
    mov.l @r4, r2                        ! r2 = car struct base
    mov r0, r7                           ! r7 = direction word (persistent)
    mov.w   .L_off_direction_flags, r0   ! r0 = 0x01C0 (direction flags offset)
    mov.b @(r0, r2), r0                  ! r0 = car[+0x1C0] direction flags byte
    tst #0x40, r0                        ! bit 6 set? (negate Y/Z path)
    bt      .L_tick_check_bit7           ! no -- check bit 7 instead
    mov.l @r4, r3                        ! --- Bit 6 path: +X, -Y, -Z ---
    mov.w @(6, r5), r0                   ! r0 = entry[+6] (force X component)
    mov r0, r2                           ! r2 = force X value
    mov.w   .L_off_force_x, r0           ! r0 = 0x01C8 (force X offset)
    mov.l r2, @(r0, r3)                  ! car[+0x1C8] = +force_X (unchanged)
    mov.l @r4, r3                        ! r3 = car struct base
    mov.w @(8, r5), r0                   ! r0 = entry[+8] (force Y component)
    mov r0, r2                           ! r2 = force Y value
    neg r2, r2                           ! r2 = -force_Y (negate)
    mov.w   DAT_060087f4, r0             ! r0 = 0x01CC (force Y offset)
    mov.l r2, @(r0, r3)                  ! car[+0x1CC] = -force_Y
    mov.l @r4, r3                        ! r3 = car struct base
    mov.w @(10, r5), r0                  ! r0 = entry[+10] (force Z component)
    mov r0, r2                           ! r2 = force Z value
    neg r2, r2                           ! r2 = -force_Z (negate)
    mov.w   .L_off_force_z, r0           ! r0 = 0x01D0 (force Z offset)
    mov.l r2, @(r0, r3)                  ! car[+0x1D0] = -force_Z
    bra     .L_tick_check_car_id         ! done applying vectors
    nop
.L_tick_check_bit7:                      ! --- Check bit 7: negate X/Y path ---
    mov.l @r4, r2                        ! r2 = car struct base
    mov.w   .L_off_direction_flags, r0   ! r0 = 0x01C0
    mov.b @(r0, r2), r0                  ! r0 = car[+0x1C0] direction flags
    tst #0x80, r0                        ! bit 7 set? (negate X/Y path)
    bt      .L_tick_default_vectors      ! no -- use vectors unchanged
    mov.l @r4, r3                        ! --- Bit 7 path: -X, -Y, +Z ---
    mov.w @(6, r5), r0                   ! r0 = entry[+6] (force X)
    mov r0, r2                           ! r2 = force X value
    neg r2, r2                           ! r2 = -force_X (negate)
    mov.w   .L_off_force_x, r0           ! r0 = 0x01C8
    mov.l r2, @(r0, r3)                  ! car[+0x1C8] = -force_X
    mov.l @r4, r3                        ! r3 = car struct base
    mov.w @(8, r5), r0                   ! r0 = entry[+8] (force Y)
    mov r0, r2                           ! r2 = force Y value
    neg r2, r2                           ! r2 = -force_Y (negate)
    mov.w   DAT_060087f4, r0             ! r0 = 0x01CC
    mov.l r2, @(r0, r3)                  ! car[+0x1CC] = -force_Y
    mov.l @r4, r3                        ! r3 = car struct base
    mov.w @(10, r5), r0                  ! r0 = entry[+10] (force Z)
    mov r0, r2                           ! r2 = force Z value
    mov.w   .L_off_force_z, r0           ! r0 = 0x01D0
    mov.l r2, @(r0, r3)                  ! car[+0x1D0] = +force_Z (unchanged)
    bra     .L_tick_check_car_id         ! done applying vectors
    nop

    .global DAT_060087e8
DAT_060087e8:
    .2byte  0x01BC                        /* car struct: collision timer */

    .global DAT_060087ea
DAT_060087ea:
    .2byte  0x00BC                        /* car struct: timer */

    .global DAT_060087ec
DAT_060087ec:
    .2byte  0x00D4                        /* car struct: display timer */
.L_off_force_ptr_b:
    .2byte  0x01B8                        /* car struct: force pointer */
.L_off_direction_flags:
    .2byte  0x01C0                        /* car struct: direction flags */
.L_off_force_x:
    .2byte  0x01C8                        /* car struct: force X vector */

    .global DAT_060087f4
DAT_060087f4:
    .2byte  0x01CC                        /* car struct: force Y vector */
.L_off_force_z:
    .2byte  0x01D0                        /* car struct: force Z vector */
.L_active_car_ptr_d:
    .4byte  sym_0607E940               /* active car state pointer */
.L_tick_default_vectors:                 ! --- Default: apply vectors unchanged ---
    mov.l @r4, r2                        ! r2 = car struct base
    mov.w @(6, r5), r0                   ! r0 = entry[+6] (force X)
    mov r0, r3                           ! r3 = force X value
    mov.w   .L_off_force_x_b, r0         ! r0 = 0x01C8
    mov.l r3, @(r0, r2)                  ! car[+0x1C8] = +force_X
    mov.l @r4, r3                        ! r3 = car struct base
    mov.w @(8, r5), r0                   ! r0 = entry[+8] (force Y)
    mov r0, r2                           ! r2 = force Y value
    mov.w   DAT_060088ac, r0             ! r0 = 0x01CC
    mov.l r2, @(r0, r3)                  ! car[+0x1CC] = +force_Y
    mov.l @r4, r3                        ! r3 = car struct base
    mov.w @(10, r5), r0                  ! r0 = entry[+10] (force Z)
    mov r0, r2                           ! r2 = force Z value
    mov.w   .L_off_force_z_b, r0         ! r0 = 0x01D0
    mov.l r2, @(r0, r3)                  ! car[+0x1D0] = +force_Z
.L_tick_check_car_id:                    ! === Check if this car matches force target ===
    mov.l @r4, r3                        ! r3 = car struct base
    mov.l   .L_force_direction_byte, r2  ! r2 = &force_direction
    mov.l @(4, r3), r3                   ! r3 = car[+0x04] (car ID)
    mov.b @r2, r2                        ! r2 = force_direction target byte
    extu.b r2, r2                        ! zero-extend to 32-bit
    cmp/eq r2, r3                        ! car ID == force target?
    bf      .L_tick_check_cleanup        ! no -- skip counter/threshold logic
    exts.w r7, r7                        ! sign-extend direction word to 32-bit
    mov.l @r4, r3                        ! r3 = car struct base
    mov.w   DAT_060088b0, r0             ! r0 = 0x01C4 (force counter offset)
    mov.l @(r0, r3), r2                  ! r2 = car[+0x1C4] (force counter)
    add #0x1, r2                         ! increment force counter
    mov.l r2, @(r0, r3)                  ! car[+0x1C4]++
    mov.w   DAT_060088b2, r3             ! r3 = 0x0100 (threshold = 256)
    cmp/gt r3, r7                        ! direction magnitude > 256? (strong force)
    bf      .L_tick_check_expired        ! no -- skip counter reset logic
    mov.l @r4, r3                        ! r3 = car struct base (strong force path)
    mov.w   DAT_060088b0, r0             ! r0 = 0x01C4
    mov.l @(r0, r3), r2                  ! r2 = car[+0x1C4] (force counter)
    mov #0x50, r3                        ! r3 = 80 (upper threshold)
    cmp/ge r3, r2                        ! counter >= 80?
    bf      .L_tick_check_counter_40     ! no -- check lower threshold
    bra     .L_tick_clear_counter        ! yes -- clear counter immediately
    nop
.L_tick_check_counter_40:               ! --- Check lower threshold ---
    mov.l @r4, r2                        ! r2 = car struct base
    mov.w   DAT_060088b0, r0             ! r0 = 0x01C4
    mov.l @(r0, r2), r3                  ! r3 = car[+0x1C4] (force counter)
    mov #0x28, r2                        ! r2 = 40 (lower threshold)
    cmp/ge r2, r3                        ! counter >= 40? (sets T bit for fall-through)
.L_tick_clear_counter:                   ! --- Reset force counter to zero ---
    mov.l @r4, r2                        ! r2 = car struct base
    mov.w   DAT_060088b0, r0             ! r0 = 0x01C4
    mov.l r6, @(r0, r2)                  ! car[+0x1C4] = 0 (reset counter)
.L_tick_check_expired:                   ! === Check if collision timer expired ===
    mov.l @r4, r3                        ! r3 = car struct base
    mov.w   DAT_060088b4, r0             ! r0 = 0x01BC (collision timer offset)
    mov.l @(r0, r3), r0                  ! r0 = car[+0x1BC] (collision timer)
    tst r0, r0                           ! timer == 0? (expired)
    bf      .L_tick_check_cleanup        ! no -- still active, skip cleanup
    exts.b r6, r3                        ! r3 = 0 (sign-extend zero)
    mov.l   .L_course_section, r2        ! r2 = &course_section
    mov.b r3, @r2                        ! course_section = 0 (reset)
    mov.l   .L_demo_flag_b, r0           ! r0 = &demo_flag
    mov.b @r0, r0                        ! r0 = demo_flag
    extu.b r0, r0                        ! zero-extend
    tst r0, r0                           ! demo mode?
    bf      .L_tick_set_display_4        ! yes -- set display mode 4
    mov.l   .L_special_render_flag_b, r0 ! r0 = &special_render_flag
    mov.w @r0, r0                        ! r0 = special_render_flag (16-bit)
    extu.w r0, r0                        ! zero-extend
    tst r0, r0                           ! special render active?
    bf      .L_tick_check_cleanup        ! yes -- skip display mode change
.L_tick_set_display_4:                   ! --- Post-collision display mode ---
    mov #0x4, r3                         ! display mode value
    mov.l   .L_display_mode_word_b, r2   ! r2 = &display_mode
    mov.w r3, @r2                        ! display_mode = 4 (post-collision)
.L_tick_check_cleanup:                   ! === Zero force state when timer expired ===
    mov.l @r4, r3                        ! r3 = car struct base
    mov.w   DAT_060088b4, r0             ! r0 = 0x01BC (collision timer offset)
    mov.l @(r0, r3), r0                  ! r0 = car[+0x1BC] (collision timer)
    tst r0, r0                           ! timer == 0?
    bf      .L_tick_return               ! no -- still active, return without cleanup
    mov.l @r4, r3                        ! r3 = car struct base (cleanup path)
    mov.w   DAT_060088b6, r0             ! r0 = 0x01B4 (force data ptr offset)
    mov.l r6, @(r0, r3)                  ! car[+0x1B4] = 0 (clear force data ptr)
    mov.l @r4, r3                        ! r3 = car struct base
    add #0x14, r0                        ! r0 = 0x01C8 (force X offset)
    mov.l r6, @(r0, r3)                  ! car[+0x1C8] = 0 (clear force X)
    mov.l @r4, r3                        ! r3 = car struct base
    add #0x4, r0                         ! r0 = 0x01CC (force Y offset)
    mov.l r6, @(r0, r3)                  ! car[+0x1CC] = 0 (clear force Y)
    mov.l @r4, r3                        ! r3 = car struct base
    add #0x4, r0                         ! r0 = 0x01D0 (force Z offset)
    mov.l r6, @(r0, r3)                  ! car[+0x1D0] = 0 (clear force Z)
.L_tick_return:                          ! --- Return ---
    rts                                  ! return
    nop
.L_off_force_x_b:
    .2byte  0x01C8                        /* car struct: force X vector */

    .global DAT_060088ac
DAT_060088ac:
    .2byte  0x01CC                        /* car struct: force Y vector */
.L_off_force_z_b:
    .2byte  0x01D0                        /* car struct: force Z vector */

    .global DAT_060088b0
DAT_060088b0:
    .2byte  0x01C4                        /* car struct: force counter */

    .global DAT_060088b2
DAT_060088b2:
    .2byte  0x0100                        /* force threshold (256) */

    .global DAT_060088b4
DAT_060088b4:
    .2byte  0x01BC                        /* car struct: collision timer */

    .global DAT_060088b6
DAT_060088b6:
    .2byte  0x01B4                        /* car struct: force data pointer */
.L_force_direction_byte:
    .4byte  sym_0607EBBC               /* force direction byte */
.L_course_section:
    .4byte  sym_0607866C               /* course section byte */
.L_demo_flag_b:
    .4byte  sym_06078635               /* demo mode flag (byte) */
.L_special_render_flag_b:
    .4byte  sym_0607ED8C               /* special render enable (16-bit) */
.L_display_mode_word_b:
    .4byte  sym_0605A016               /* display mode (16-bit) */
