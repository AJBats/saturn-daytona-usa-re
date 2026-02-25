/* race_update_abort -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0600DFD0 - 0x0600E060
 *
 * Race abort update — called when the race is aborted (e.g., player
 * quits mid-race). Sets up per-car state for the abort sequence:
 *
 *   1. Load car array base pointer, compute half-car-count for
 *      visibility state, store current car and data table pointers.
 *   2. Call register-save prologue (sym_0602DB00: pushes r8-r13).
 *   3. Query terrain elevation via coord_grid_pack using car
 *      position fields (Z at offset +24, X at offset +16).
 *   4. Store elevation result to car state flags.
 *   5. Call segment_position_track to update track segment.
 *   6. Submit 4 geometry channels to scene_3d_processor (channels 0-3).
 *   7. Tail-branch to car_update_racing for the main car loop.
 *
 * Persistent registers:
 *   r14 = car array base pointer (loaded from sym_0607E944)
 *
 * Tail call: BRA to car_update_racing (0x0600E0C0)
 */

    .section .text.FUN_0600DFD0


    .global race_update_abort
    .type race_update_abort, @function
race_update_abort:
    mov.l r14, @-r15                       ! save r14 (callee-saved)
    sts.l pr, @-r15                        ! save return address
    mov.l   .L_pool_car_array_base_ptr, r14 ! r14 = &car_array_base_ptr
    mov.l   .L_pool_total_car_count, r3    ! r3 = &total_car_count
    mov.l   .L_pool_car_visibility_state, r2 ! r2 = &car_visibility_state (half-count word)
    mov.l @r14, r14                        ! r14 = car_array_base (deref pointer-to-pointer)
    mov.l @r3, r3                          ! r3 = total_car_count value
    shar r3                                ! r3 = total_car_count >> 1 (arithmetic shift right)
    mov.w r3, @r2                          ! car_visibility_state = half car count (16-bit store)
    mov.l   .L_pool_cur_car_ptr, r2        ! r2 = &current_car_ptr
    mov.l r14, @r2                         ! current_car_ptr = car_array_base
    mov.l   .L_pool_car_data_table, r1     ! r1 = car_data_table (sym_06078B68)
    mov.l   .L_pool_car_data_slot, r2      ! r2 = &car_data_slot
    mov.l r1, @r2                          ! car_data_slot = car_data_table
    mov.l   .L_pool_fn_reg_save_prologue, r2 ! r2 = register-save prologue (sym_0602DB00)
    jsr @r2                                ! call reg_save_prologue — pushes r8-r13
    nop                                    ! (delay slot)
    mov.l @(0x18, r14), r5                 ! r5 = car.pos_z (offset +0x18 from car base)
    mov.l   .L_pool_fn_coord_grid_pack, r3 ! r3 = coord_grid_pack function
    jsr @r3                                ! call coord_grid_pack(pos_x, pos_z) — terrain query
    mov.l @(0x10, r14), r4                 ! r4 = car.pos_x (offset +0x10, delay slot)
    mov.l   .L_pool_car_state_flags, r3    ! r3 = &car_state_flags
    mov.l r0, @r3                          ! car_state_flags = elevation result (r0)
    mov.l   .L_pool_fn_seg_pos_track, r3   ! r3 = segment_position_track function
    jsr @r3                                ! call segment_position_track() — update track segment
    nop                                    ! (delay slot)
    mov.l   .L_pool_fn_scene_3d_proc, r14  ! r14 = scene_3d_processor (reuse r14 for repeated calls)
    mov.l   .L_pool_geom_channel_0, r4     ! r4 = geometry channel 0 data ptr
    jsr @r14                               ! call scene_3d_processor(channel_0, 0)
    mov #0x0, r5                           ! r5 = 0x0 (channel index 0, delay slot)
    mov.l   .L_pool_geom_channel_1, r4     ! r4 = geometry channel 1 data ptr
    jsr @r14                               ! call scene_3d_processor(channel_1, 1)
    mov #0x1, r5                           ! r5 = 0x1 (channel index 1, delay slot)
    mov.l   .L_pool_geom_channel_2, r4     ! r4 = geometry channel 2 data ptr
    jsr @r14                               ! call scene_3d_processor(channel_2, 2)
    mov #0x2, r5                           ! r5 = 0x2 (channel index 2, delay slot)
    mov.l   .L_pool_geom_channel_3, r4     ! r4 = geometry channel 3 data ptr
    jsr @r14                               ! call scene_3d_processor(channel_3, 3)
    mov #0x3, r5                           ! r5 = 0x3 (channel index 3, delay slot)
    lds.l @r15+, pr                        ! restore return address
    .byte   0xA0, 0x4E    /* bra 0x0600E0C0 (external) */  ! tail-branch to car_update_racing
    mov.l @r15+, r14                       ! restore r14 (delay slot of BRA)
.L_pool_car_array_base_ptr:
    .4byte  sym_0607E944               ! &car_array_base_ptr (pointer-to-pointer)
.L_pool_total_car_count:
    .4byte  sym_0607EA98               ! &total_car_count (number of cars in race)
.L_pool_car_visibility_state:
    .4byte  sym_060786CA               ! &car_visibility_state (half-count word)
.L_pool_cur_car_ptr:
    .4byte  sym_0607E940               ! &current_car_struct_ptr
.L_pool_car_data_table:
    .4byte  sym_06078B68               ! car additional data table base
.L_pool_car_data_slot:
    .4byte  sym_0607E948               ! &car_data_slot (stores data table ptr)
.L_pool_fn_reg_save_prologue:
    .4byte  sym_0602DB00               ! register-save prologue (pushes r8-r13)
.L_pool_fn_coord_grid_pack:
    .4byte  sym_06006838               ! coord_grid_pack — terrain elevation query
.L_pool_car_state_flags:
    .4byte  sym_060786B8               ! &car_state_flags (elevation result store)
.L_pool_fn_seg_pos_track:
    .4byte  segment_position_track     ! track segment position updater
.L_pool_fn_scene_3d_proc:
    .4byte  scene_3d_processor         ! 3D scene geometry processor
.L_pool_geom_channel_0:
    .4byte  sym_06063EB0               ! geometry channel 0 data
.L_pool_geom_channel_1:
    .4byte  sym_06063E9C               ! geometry channel 1 data
.L_pool_geom_channel_2:
    .4byte  sym_06063ED8               ! geometry channel 2 data
.L_pool_geom_channel_3:
    .4byte  sym_06063EC4               ! geometry channel 3 data
