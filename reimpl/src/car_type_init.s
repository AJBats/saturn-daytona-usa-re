/* car_type_init -- Per-car type initialization during race setup
 * Translation unit: 0x0600E1D4 - 0x0600E410
 *
 * Called once per car during race init (from car_array_init loop).
 * Reads the car's config from three lookup tables indexed by car index:
 *   - Primary table (sym_06047DE4, 12 bytes/entry): type, heading, indices, class
 *   - Secondary table (sym_06047DD0, 5 bytes/entry): position/lane data
 *   - Tertiary table (sym_06047D8C, 4 bytes/entry): additional parameters
 *
 * Sets car struct fields: type ID, physics model pointer, class value,
 * initial position (X,Z via elevation query), rotation/heading angles,
 * steering defaults, and speed parameters. Player vs AI cars get
 * different initial steering and speed values based on car index parity
 * and the player mode flag at sym_0607EAD8.
 *
 * Car struct pointer arrives via *sym_0607E940 (dereferenced into r14).
 * Car index is at car[0x04].
 *
 * Calls: fpmul, heading_smooth_gentle, sym_06006838 (elevation query),
 *        scene_render_alt (sprite/render update)
 */

    .section .text.FUN_0600E1D4


    .global car_type_init
    .type car_type_init, @function
car_type_init:
    mov.l r14, @-r15             ! save r14
    mov #0x0, r3                 ! r3 = 0 (used to clear field below)
    mov.l r13, @-r15             ! save r13
    mov.l r12, @-r15             ! save r12
    mov.l r11, @-r15             ! save r11
    mov.l r10, @-r15             ! save r10
    sts.l pr, @-r15              ! save return address
    add #-0x4, r15               ! allocate 4 bytes on stack
    mov.l   .L_p_player_mode_ptr, r11  ! r11 = &player_mode (sym_0607EAD8)
    mov.l   .L_p_car_ptr_active, r14   ! r14 = &car_ptr (sym_0607E940)
    mov.l   .L_p_course_data_base, r13 ! r13 = course_data (sym_06078680)
    mov.w   DAT_0600e2ba, r0    ! r0 = 0x0244 (offset to car[0x244])
    mov.l @r14, r14              ! r14 = *car_ptr (dereference to car struct)
    mov.l r3, @(r0, r14)        ! car[0x244] = 0 (clear init flag)
    mov.l @(4, r14), r12        ! r12 = car[0x04] (car index)
    mov.l   .L_p_config_table_primary, r2  ! r2 = config_table (sym_06047DE4)
    mov r12, r3                  ! r3 = car_index
    shll2 r12                    ! r12 = index * 4
    shll2 r3                     ! r3 = index * 4
    shll r3                      ! r3 = index * 8
    add r3, r12                  ! r12 = index * 4 + index * 8 = index * 12
    add r2, r12                  ! r12 = &config_table[index] (12-byte entry)
    mov.w @(6, r12), r0         ! r0 = config[+6] (car type ID from tertiary idx)
    mov r0, r4                   ! r4 = type ID
    extu.w r4, r4               ! r4 = zero-extend to 32-bit
    mov.w   .L_w_off_car_type, r0  ! r0 = 0x01F0 (offset to car[0x1F0])
    mov.l r4, @(r0, r14)        ! car[0x1F0] = type ID
    add #-0x8, r0               ! r0 = 0x01E8
    mov.l r4, @(r0, r14)        ! car[0x1E8] = type ID (duplicate)
    mov.l @r11, r1               ! r1 = player_mode
    shll r1                      ! r1 = player_mode * 2 (word index)
    mov.l   .L_p_heading_offset_table, r3  ! r3 = heading_offset_table (sym_0605A220)
    mov.l   .L_p_car_count_ptr, r0   ! r0 = &car_count (sym_0607EA9C)
    mov.l   .L_p_mem_store_helper, r2  ! r2 = mem_store_helper (sym_06035C2C)
    add r3, r1                   ! r1 = &heading_offset_table[player_mode]
    mov.w @r1, r1               ! r1 = heading_offset (word)
    extu.w r1, r1               ! r1 = zero-extend offset
    add r4, r1                   ! r1 = heading_offset + type_id (combined key)
    jsr @r2                      ! call mem_store_helper(r0=car_count, r1=key)
    mov.l @r0, r0               ! (delay) r0 = *car_count
    mov.w   DAT_0600e2be, r1    ! r1 = 0x01EC (offset to car[0x1EC])
    add r14, r1                  ! r1 = &car[0x1EC]
    mov.l r0, @r1               ! car[0x1EC] = mem_store result (physics model ptr)
    mov.w @(4, r12), r0         ! r0 = config[+4] (secondary table index)
    mov r0, r3                   ! r3 = secondary index
    extu.w r3, r3               ! r3 = zero-extend
    shll2 r3                     ! r3 = index * 4 (long table stride)
    mov.l   .L_p_config_table_tertiary, r2  ! r2 = tertiary_table (sym_06085FD0)
    add r2, r3                   ! r3 = &tertiary_table[index]
    mov.l @r3, r1               ! r1 = tertiary_table[index] (physics param ptr)
    mov.w   DAT_0600e2c0, r0    ! r0 = 0x01E0 (offset to car[0x1E0])
    mov.l r1, @(r0, r14)        ! car[0x1E0] = physics param pointer
    mov.w @(8, r12), r0         ! r0 = config[+8] (car class: 2=player, 1=AI)
    mov r0, r3                   ! r3 = class value
    extu.w r3, r3               ! r3 = zero-extend
    mov.w   DAT_0600e2c2, r0    ! r0 = 0x0210 (offset to car[0x210])
    mov.l r3, @(r0, r14)        ! car[0x210] = car class value
    mov.l @r11, r0               ! r0 = player_mode
    exts.b r0, r0               ! r0 = sign-extend to byte
    mov r0, r3                   ! r3 = player_mode (signed)
    shll2 r0                     ! r0 = mode * 4
    add r3, r0                   ! r0 = mode * 5 (5-byte entry stride)
    exts.b r0, r0               ! r0 = sign-extend result
    mov.l   .L_p_lane_data_secondary, r2  ! r2 = lane_data_base (sym_06047DD0)
    add r2, r0                   ! r0 = &lane_data[mode] (5-byte entry)
    mov.l   .L_p_race_state_ptr, r3   ! r3 = &race_state (sym_0605AD04)
    mov.l @r3, r3               ! r3 = *race_state
    mov.b @(r0, r3), r10        ! r10 = lane_data[mode][race_state] (lane byte)
    extu.b r10, r10             ! r10 = zero-extend lane index
    mov.l   .L_p_render_state_ptr, r3  ! r3 = &render_state (sym_0605AD00)
    mov.l @r3, r3               ! r3 = *render_state
    mov.l   .L_p_debug_flag, r0      ! r0 = &debug_flag (sym_06086030)
    mov.b @r0, r0               ! r0 = debug_flag byte
    extu.b r0, r0               ! r0 = zero-extend
    tst r0, r0                   ! test if debug mode active
    bt/s    .L_use_normal_lane   ! if debug == 0, use normal lane
    add r3, r10                  ! (delay) r10 = lane_index + render_state base
    mov.l @r11, r10              ! debug: r10 = player_mode (as raw index)
    mov.l   .L_p_lane_data_debug, r3  ! r3 = debug_lane_data (sym_06047DDF)
    add r3, r10                  ! r10 = &debug_lane_data[player_mode]
    mov.b @r10, r10             ! r10 = debug lane byte
    extu.b r10, r10             ! r10 = zero-extend
.L_use_normal_lane:
    mov.l @r12, r5               ! r5 = config[+0] (heading angle from config)
    mov r10, r4                  ! r4 = lane_index (resolved above)
    mov.l   .L_p_param_table, r3     ! r3 = param_table (sym_06047D8C)
    mov.l   .L_p_fpmul, r2          ! r2 = fpmul function address
    shll2 r4                     ! r4 = lane_index * 4
    add r3, r4                   ! r4 = &param_table[lane_index]
    jsr @r2                      ! call fpmul(r4=param, r5=heading)
    mov.l @r4, r4               ! (delay) r4 = param_table[lane_index]
    mov.w   DAT_0600e2c4, r1    ! r1 = 0x0194 (offset to car[0x194])
    add r14, r1                  ! r1 = &car[0x194]
    mov.l r0, @r1               ! car[0x194] = fpmul result (scaled heading A)
    mov.w   .L_w_fpmul_scale, r5     ! r5 = 0x372F (fixed-point scale factor)
    mov.w   DAT_0600e2c4, r0    ! r0 = 0x0194 (offset)
    mov.l   .L_p_fpmul, r3          ! r3 = fpmul function address
    jsr @r3                      ! call fpmul(r4=car[0x194], r5=0x372F)
    mov.l @(r0, r14), r4        ! (delay) r4 = car[0x194] (first fpmul result)
    mov.w   DAT_0600e2c8, r1    ! r1 = 0x0198 (offset to car[0x198])
    mov #0x0, r2                 ! r2 = 0
    add r14, r1                  ! r1 = &car[0x198]
    mov.l r0, @r1               ! car[0x198] = fpmul result (scaled heading B)
    mov.l   .L_p_car_count_ptr, r3   ! r3 = &car_count (sym_0607EA9C)
    mov.w   DAT_0600e2be, r0    ! r0 = 0x01EC (offset to car[0x1EC])
    mov.l @r3, r3               ! r3 = car_count
    mov.l @(r0, r14), r1        ! r1 = car[0x1EC] (physics model ptr)
    cmp/gt r3, r2               ! T = (0 > car_count) — always false, clears T
    addc r2, r3                  ! r3 = car_count + 0 + T (rounding for divide)
    shar r3                      ! r3 = car_count / 2 (arithmetic shift right)
    cmp/ge r3, r1               ! T = (car[0x1EC] >= half_count)
    bt      .L_set_top_half      ! if in top half of field, set flag to -1
    mov #0x0, r2                 ! r2 = 0
    mov.w   DAT_0600e2ca, r0    ! r0 = 0x0228 (offset to car[0x228])
    bra     .L_after_track_progress  ! skip top-half path
    mov.l r2, @(r0, r14)        ! (delay) car[0x228] = 0 (bottom half)

    .global DAT_0600e2ba
DAT_0600e2ba:
    .2byte  0x0244               ! offset: car[0x244] (init flag)
.L_w_off_car_type:
    .2byte  0x01F0               ! offset: car[0x1F0] (car type ID)

    .global DAT_0600e2be
DAT_0600e2be:
    .2byte  0x01EC               ! offset: car[0x1EC] (physics model ptr)

    .global DAT_0600e2c0
DAT_0600e2c0:
    .2byte  0x01E0               ! offset: car[0x1E0] (physics param ptr)

    .global DAT_0600e2c2
DAT_0600e2c2:
    .2byte  0x0210               ! offset: car[0x210] (car class)

    .global DAT_0600e2c4
DAT_0600e2c4:
    .2byte  0x0194               ! offset: car[0x194] (scaled heading A)
.L_w_fpmul_scale:
    .2byte  0x372F               ! fixed-point scale factor for heading B

    .global DAT_0600e2c8
DAT_0600e2c8:
    .2byte  0x0198               ! offset: car[0x198] (scaled heading B)

    .global DAT_0600e2ca
DAT_0600e2ca:
    .2byte  0x0228               ! offset: car[0x228] (track progress flag)
.L_p_player_mode_ptr:
    .4byte  sym_0607EAD8         ! &player_mode (0=single, 2=attract)
.L_p_car_ptr_active:
    .4byte  sym_0607E940         ! &current_car_ptr (active)
.L_p_course_data_base:
    .4byte  sym_06078680         ! course/track data base
.L_p_config_table_primary:
    .4byte  sym_06047DE4         ! config table (12 bytes/entry)
.L_p_heading_offset_table:
    .4byte  sym_0605A220         ! heading offset table (per mode)
.L_p_car_count_ptr:
    .4byte  sym_0607EA9C         ! &car_count (total active cars)
.L_p_mem_store_helper:
    .4byte  sym_06035C2C         ! memory store helper function
.L_p_config_table_tertiary:
    .4byte  sym_06085FD0         ! tertiary config table (4 bytes/entry)
.L_p_lane_data_secondary:
    .4byte  sym_06047DD0         ! secondary lane data (5 bytes/entry)
.L_p_race_state_ptr:
    .4byte  sym_0605AD04         ! &race_state variable
.L_p_render_state_ptr:
    .4byte  sym_0605AD00         ! &render_state variable
.L_p_debug_flag:
    .4byte  sym_06086030         ! &debug_flag byte
.L_p_lane_data_debug:
    .4byte  sym_06047DDF         ! debug lane data override
.L_p_param_table:
    .4byte  sym_06047D8C         ! param table (4 bytes/entry)
.L_p_fpmul:
    .4byte  fpmul                ! 16.16 fixed-point multiply
.L_set_top_half:
    mov #-0x1, r3                ! r3 = -1 (top-half flag)
    mov.w   DAT_0600e3e8, r0    ! r0 = 0x0228 (offset to car[0x228])
    mov.l r3, @(r0, r14)        ! car[0x228] = -1 (mark as top half of grid)
.L_after_track_progress:
    mov.w   DAT_0600e3ea, r0    ! r0 = 0x01EC (offset to car[0x1EC])
    mov.l @(r0, r14), r2        ! r2 = car[0x1EC] (physics model ptr)
    add #-0x8, r0               ! r0 = 0x01E4
    mov.l r2, @(r0, r14)        ! car[0x1E4] = car[0x1EC] (copy physics ptr)
    mov.l @(4, r14), r0         ! r0 = car[0x04] (car index)
    and #0x1, r0                ! r0 = index & 1 (0=even/player, 1=odd/AI)
    mov r0, r4                   ! r4 = parity flag
    mov.l @r11, r0               ! r0 = player_mode
    tst r0, r0                   ! test player_mode == 0 (single player)
    bt      .L_single_player_path  ! if single player, branch
    tst r4, r4                   ! versus mode: test parity
    bt      .L_versus_even_car   ! if even index in versus mode
    mov.w   DAT_0600e3ec, r3    ! r3 = 0x0180 (narrow steering init)
    mov r3, r0                   ! r0 = 0x0180
    add #0x7C, r0               ! r0 = 0x01FC
    mov.l r3, @(r0, r14)        ! car[0x1FC] = 0x0180 (steering range narrow)
    bra     .L_clear_speed_fields  ! clear speed fields
    nop                          ! (delay)
.L_versus_even_car:
    mov.w   .L_w_steer_init_wide, r3  ! r3 = 0x0580 (wide steering init)
    mov.w   DAT_0600e3f0, r0    ! r0 = 0x01FC (offset to car[0x1FC])
    mov.l r3, @(r0, r14)        ! car[0x1FC] = 0x0580 (steering range wide)
.L_clear_speed_fields:
    mov #0x0, r2                 ! r2 = 0
    mov.w   DAT_0600e3f2, r0    ! r0 = 0x00E4 (offset to car[0xE4])
    mov.l r2, @(r0, r14)        ! car[0xE4] = 0 (clear speed field)
    mov r2, r3                   ! r3 = 0
    add #-0x4, r0               ! r0 = 0x00E0
    bra     .L_apply_heading     ! go to heading setup
    mov.l r2, @(r0, r14)        ! (delay) car[0xE0] = 0 (clear speed field)
.L_single_player_path:
    tst r4, r4                   ! test parity (0=player car, 1=AI car)
    bt      .L_single_player_car ! if even index (player car)
    mov.w   .L_w_steer_init_wide, r3  ! r3 = 0x0580 (wide steering for AI)
    mov.w   DAT_0600e3f0, r0    ! r0 = 0x01FC (offset to car[0x1FC])
    mov.l r3, @(r0, r14)        ! car[0x1FC] = 0x0580 (AI steering range)
    mov.l   .L_p_speed_init_ai, r3   ! r3 = 0x00042E38 (AI initial speed)
    mov.l r3, @(12, r14)        ! car[0x0C] = AI initial speed
    bra     .L_apply_heading     ! go to heading setup
    nop                          ! (delay)
.L_single_player_car:
    mov.w   DAT_0600e3ec, r2    ! r2 = 0x0180 (narrow steering init)
    mov r2, r0                   ! r0 = 0x0180
    add #0x7C, r0               ! r0 = 0x01FC
    mov.l r2, @(r0, r14)        ! car[0x1FC] = 0x0180 (player steering range)
    mov.l   .L_p_speed_init_player, r3  ! r3 = 0x00042000 (player initial speed)
    mov.l r3, @(12, r14)        ! car[0x0C] = player initial speed
    mov.w   DAT_0600e3f4, r2    ! r2 = 0x1A90 (initial throttle value)
    mov.w   DAT_0600e3f2, r0    ! r0 = 0x00E4 (offset to car[0xE4])
    mov.l r2, @(r0, r14)        ! car[0xE4] = 0x1A90 (throttle)
    mov r2, r3                   ! r3 = 0x1A90
    add #-0x4, r0               ! r0 = 0x00E0
    mov.l r2, @(r0, r14)        ! car[0xE0] = 0x1A90 (throttle copy)
.L_apply_heading:
    mov.w   DAT_0600e3f0, r0    ! r0 = 0x01FC (offset to car[0x1FC])
    mov.l @(r0, r14), r3        ! r3 = car[0x1FC] (steering value)
    add #-0x4, r0               ! r0 = 0x01F8
    mov.l r3, @(r0, r14)        ! car[0x1F8] = car[0x1FC] (copy steering)
    mov.l   .L_p_heading_smooth, r3  ! r3 = heading_smooth_gentle
    jsr @r3                      ! call heading_smooth_gentle(r4=course_data)
    mov r13, r4                  ! (delay) r4 = course_data base
    mov.l @r13, r2               ! r2 = course_data[0] (initial X position)
    mov.l r2, @(16, r14)        ! car[0x10] = X position
    mov.l @(8, r13), r3         ! r3 = course_data[8] (initial Z position)
    mov.l r3, @(24, r14)        ! car[0x18] = Z position
    mov.l @(4, r14), r0         ! r0 = car[0x04] (car index)
    tst r0, r0                   ! test if car index == 0
    bf      .L_position_setup    ! if not car 0, skip heading override
    mov.l @r11, r0               ! r0 = player_mode
    cmp/eq #0x2, r0             ! test if player_mode == 2 (attract mode)
    bf      .L_position_setup    ! if not attract mode, skip
    mov.w   DAT_0600e3f6, r2    ! r2 = 0x1EC0 (special heading for attract)
    mov r2, r0                   ! r0 = 0x1EC0
    mov.w r0, @(14, r13)        ! course_data[14] = 0x1EC0 (override heading)
.L_position_setup:
    mov r15, r6                  ! r6 = stack pointer (for later restore)
    mov r14, r5                  ! r5 = car struct base
    mov.l r6, @-r15             ! push original SP
    add #0x10, r5               ! r5 = &car[0x10] (position block)
    mov.l r5, @-r15             ! push &car[0x10]
    mov.l @(24, r14), r5        ! r5 = car[0x18] (Z position)
    mov.l   .L_p_elevation_query, r3  ! r3 = elevation_query (sym_06006838)
    jsr @r3                      ! call elevation_query(r4=X, r5=Z)
    mov.l @(16, r14), r4        ! (delay) r4 = car[0x10] (X position)
    mov r0, r4                   ! r4 = elevation query result
    mov.l @r15+, r5             ! r5 = &car[0x10] (pop)
    mov.l   .L_p_render_update, r3  ! r3 = scene_render_alt
    jsr @r3                      ! call scene_render_alt(r4=result, r5=pos, r6=sp)
    mov.l @r15+, r6             ! (delay) r6 = original SP (pop)
    mov.w @(12, r13), r0        ! r0 = course_data[12] (heading X component)
    mov r0, r2                   ! r2 = heading X
    mov.l r0, @(28, r14)        ! car[0x1C] = heading X
    mov.w @(14, r13), r0        ! r0 = course_data[14] (heading Y component)
    mov r0, r3                   ! r3 = heading Y
    mov.l r0, @(32, r14)        ! car[0x20] = heading Y
    mov.w @(16, r13), r0        ! r0 = course_data[16] (heading Z component)
    mov r0, r3                   ! r3 = heading Z
    mov.l r0, @(36, r14)        ! car[0x24] = heading Z
    mov.l @(32, r14), r3        ! r3 = car[0x20] (heading Y)
    mov.l r3, @(48, r14)        ! car[0x30] = heading Y (copy to target)
    mov.l @(32, r14), r2        ! r2 = car[0x20] (heading Y)
    mov.l r2, @(52, r14)        ! car[0x34] = heading Y (copy to velocity)
    mov.l @(32, r14), r3        ! r3 = car[0x20] (heading Y)
    mov.l r3, @(40, r14)        ! car[0x28] = heading Y (copy to prev heading)
    mov.l @(32, r14), r2        ! r2 = car[0x20] (heading Y)
    mov.w   .L_w_off_heading_copy, r0  ! r0 = 0x01B0 (offset to car[0x1B0])
    mov.l r2, @(r0, r14)        ! car[0x1B0] = heading Y (extra copy)
    add #0x4, r15               ! free 4-byte stack allocation
    lds.l @r15+, pr             ! restore return address
    mov.l @r15+, r10            ! restore r10
    mov.l @r15+, r11            ! restore r11
    mov.l @r15+, r12            ! restore r12
    mov.l @r15+, r13            ! restore r13
    rts                          ! return
    mov.l @r15+, r14            ! (delay) restore r14

    .global DAT_0600e3e8
DAT_0600e3e8:
    .2byte  0x0228               ! offset: car[0x228] (track progress, alt ref)

    .global DAT_0600e3ea
DAT_0600e3ea:
    .2byte  0x01EC               ! offset: car[0x1EC] (physics model ptr, alt ref)

    .global DAT_0600e3ec
DAT_0600e3ec:
    .2byte  0x0180               ! narrow steering init value
.L_w_steer_init_wide:
    .2byte  0x0580               ! wide steering init value

    .global DAT_0600e3f0
DAT_0600e3f0:
    .2byte  0x01FC               ! offset: car[0x1FC] (steering range)

    .global DAT_0600e3f2
DAT_0600e3f2:
    .2byte  0x00E4               ! offset: car[0xE4] (speed/throttle)

    .global DAT_0600e3f4
DAT_0600e3f4:
    .2byte  0x1A90               ! player initial throttle value

    .global DAT_0600e3f6
DAT_0600e3f6:
    .2byte  0x1EC0               ! attract mode heading override
.L_w_off_heading_copy:
    .2byte  0x01B0               ! offset: car[0x1B0] (heading copy)
    .2byte  0xFFFF               ! padding
.L_p_speed_init_ai:
    .4byte  0x00042E38           ! AI initial speed (16.16 fixed-point)
.L_p_speed_init_player:
    .4byte  0x00042000           ! player initial speed (16.16 fixed-point)
.L_p_heading_smooth:
    .4byte  heading_smooth_gentle  ! heading calculation function
.L_p_elevation_query:
    .4byte  sym_06006838         ! elevation/terrain query function
.L_p_render_update:
    .4byte  scene_render_alt     ! sprite/render update function
