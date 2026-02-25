/* road_segment_check -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x06040C98 - 0x06040F16
 *
 * Road segment validation and slot management for the event queue system.
 * Contains four functions:
 *
 * road_segment_check (FUN_06040C98):
 *   Validates whether an entity can occupy a road segment. Initializes the
 *   game state structure at sym_060A5400, queries the road segment and track
 *   intersection geometry, checks surface type and mesh boundaries, and
 *   polls CD/SMPC status bits during the multi-step validation pipeline.
 *
 *   Args:  r4 = entity param, r5 = validation flags
 *   Returns: r0 = 0 (success), negative error codes:
 *     -2  = road query or intersection test failed, or poll timeout
 *     -10 = barrier surface type (type 9 or A)
 *     -13 = wall surface type (type 6)
 *     -14 = wall surface type (type 7)
 *     -15 = surface flag check failed (0x40000000 bit not set)
 *
 * sym_06040E88 -- slot_alloc_zone:
 *   Allocates a free slot in the 24-entry zone flag array at state[+0x18].
 *   Scans linearly for an empty slot, marks it active (1), and writes the
 *   slot index to the output pointer.
 *   Args:  r4 = output pointer (receives slot index)
 *   Returns: r0 = 0 (success), -3 (no free slot)
 *
 * sym_06040EBA -- slot_free_zone:
 *   Frees a previously allocated slot in the zone flag array at state[+0x18].
 *   Validates the index range [0..23] and that the slot is currently active.
 *   Args:  r4 = slot index to free
 *   Returns: r0 = 0 (success), -6 (out of range), -7 (not allocated)
 *
 * sym_06040EEC -- slot_alloc_direct:
 *   Allocates a free slot in the 24-entry direct array at state[+0x0].
 *   Same linear scan as slot_alloc_zone but uses the base array.
 *   Args:  r4 = output pointer (receives slot index)
 *   Returns: r0 = 0 (success), -4 (no free slot)
 */

    .section .text.FUN_06040C98


    .global road_segment_check
    .type road_segment_check, @function
road_segment_check:
    mov.l r14, @-r15                    ! save r14
    mov.l r13, @-r15                    ! save r13
    mov.l r12, @-r15                    ! save r12
    mov #0x0, r13                       ! r13 = 0 (constant zero)
    mov.l r11, @-r15                    ! save r11
    mov.l r10, @-r15                    ! save r10
    mov.l r9, @-r15                     ! save r9
    mov #0x1, r10                       ! r10 = 1 (constant one)
    mov.l r8, @-r15                     ! save r8
    sts.l pr, @-r15                     ! save return address
    add #-0x14, r15                     ! allocate 20 bytes of locals
    mov.l   .L_fn_ai_checkpoint_section, r11 ! r11 = &ai_checkpoint_section (reused)
    mov.w   DAT_06040d2c, r12           ! r12 = 0x00FF (low byte mask)
    mov.l   .L_game_state_ptr, r14      ! r14 = &game_state_ptr (indirect)
    mov.l r5, @r15                      ! local[0] = validation_flags
    mov.l   .L_fn_state_init, r3        ! r3 = &state_init (sym_0604231E)
    jsr @r3                             ! state_init() -- zero out game state arrays
    mov.l r4, @r14                      ! *game_state_ptr = entity_param (delay slot)
    mov.l @r15, r0                      ! r0 = validation_flags
    tst r0, r0                          ! flags == 0?
    bt      .L_flags_not_set            ! yes -> clear zone/active bytes
    mov.l @r14, r2                      ! r2 = state base
    add #0x17, r2                       ! r2 -> state[+0x17] (zone flag byte 23)
    mov.b r10, @r2                      ! state[+0x17] = 1 (zone active)
    mov.l @r14, r3                      ! r3 = state base
    add #0x2F, r3                       ! r3 -> state[+0x2F] (extended flag byte 23)
    exts.b r10, r2                      ! r2 = 1 (sign-extended)
    mov.b r2, @r3                       ! state[+0x2F] = 1 (extended active)
    bra     .L_flags_done
    nop
.L_flags_not_set:
    mov.l @r14, r3                      ! r3 = state base
    add #0x17, r3                       ! r3 -> state[+0x17]
    mov.b r13, @r3                      ! state[+0x17] = 0 (zone inactive)
    mov.l @r14, r2                      ! r2 = state base
    add #0x2F, r2                       ! r2 -> state[+0x2F]
    exts.b r13, r3                      ! r3 = 0 (sign-extended)
    mov.b r3, @r2                       ! state[+0x2F] = 0 (extended inactive)
.L_flags_done:
    mov r15, r4                         ! r4 = &local buffer
    jsr @r11                            ! ai_checkpoint_section(local+8)
    add #0x8, r4                        ! r4 -> local[8] (delay slot)
    mov r15, r0                         ! r0 = &local buffer
    add #0x8, r0                        ! r0 -> local[8] (checkpoint result)
    mov.b @r0, r0                       ! r0 = result byte
    extu.b r0, r0                       ! zero-extend to 32 bits
    bra     .L_check_surface_type       ! go check surface type
    and #0xF, r0                        ! isolate low nibble (delay slot)
.L_err_wall_type6:
    bra     .L_return                   ! return error -13
    mov #-0xD, r0                       ! surface type 6 = wall
.L_err_wall_type7:
    bra     .L_return                   ! return error -14
    mov #-0xE, r0                       ! surface type 7 = wall
.L_err_barrier:
    bra     .L_return                   ! return error -10
    mov #-0xA, r0                       ! surface type 9/A = barrier
.L_check_surface_type:
    cmp/eq #0x6, r0                     ! surface type == 6 (wall)?
    bt      .L_err_wall_type6
    cmp/eq #0x7, r0                     ! surface type == 7 (wall)?
    bt      .L_err_wall_type7
    cmp/eq #0x9, r0                     ! surface type == 9 (barrier)?
    bt      .L_err_barrier
    cmp/eq #0xA, r0                     ! surface type == A (barrier)?
    bt      .L_err_barrier
    mov r12, r7                         ! r7 = 0x00FF (mask param)
    mov r12, r6                         ! r6 = 0x00FF (mask param)
    mov.l   .L_mask_low16, r5           ! r5 = 0x0000FFFF (16-bit mask)
    mov.l   .L_fn_road_segment_query, r3 ! r3 = &road_segment_query
    jsr @r3                             ! road_segment_query(0xFF, 0xFFFF, 0xFF, 0xFF)
    mov r12, r4                         ! r4 = 0x00FF (delay slot)
    mov r0, r4                          ! r4 = query result
    tst r4, r4                          ! result == 0?
    bt      .L_road_query_ok            ! yes -> query succeeded
    bra     .L_return                   ! no -> return -2
    mov #-0x2, r0                       ! error: road query failed
.L_road_query_ok:
    mov r13, r8                         ! r8 = 0 (poll counter)
    bra     .L_main_loop_top            ! enter main validation loop
    mov r13, r9                         ! r9 = 0 (end-marker flag, delay slot)

    .global DAT_06040d2c
DAT_06040d2c:
    .2byte  0x00FF                      /* byte mask constant loaded into r12 */
    .2byte  0xFFFF                      /* alignment padding */
.L_fn_ai_checkpoint_section:
    .4byte  ai_checkpoint_section       /* checkpoint section reader */
.L_game_state_ptr:
    .4byte  sym_060A5400                /* pointer to game state base structure */
.L_fn_state_init:
    .4byte  sym_0604231E               /* state initializer (zeros arrays) */
.L_mask_low16:
    .4byte  0x0000FFFF                  /* low 16-bit mask */
.L_fn_road_segment_query:
    .4byte  road_segment_query          /* road segment geometry query */
.L_poll_cd_status:
    mov.w   DAT_06040dc0, r2           ! r2 = 0x0400 (CD status bit mask)
    mov.l   .L_fn_smpc_status_read, r3 ! r3 = &smpc_status_read
    jsr @r3                             ! r0 = smpc_status_read()
    mov.l r2, @r15                      ! local[0] = mask (delay slot, save for later)
    mov r0, r4                          ! r4 = raw status word
    mov.l @r15, r3                      ! r3 = 0x0400 (reload mask)
    exts.w r4, r5                       ! r5 = status sign-extended to 32 bits
    and r3, r5                          ! r5 = status & 0x0400 (CD ready bit)
    tst r5, r5                          ! CD ready bit clear?
    bt      .L_cd_bit_not_set           ! yes -> r5 = 0
    bra     .L_cd_bit_is_set            ! no -> r5 = 1
    mov #0x1, r5                        ! (delay slot)
.L_cd_bit_not_set:
    mov #0x0, r5                        ! r5 = 0 (CD not ready)
.L_cd_bit_is_set:
    tst r5, r5                          ! CD ready?
    bf      .L_cd_ready                 ! yes -> proceed to clear HIRQ
    bra     .L_main_loop_top            ! no -> loop back (check end marker flag)
    nop
.L_cd_ready:
    mov.l   .L_cd_hirq_clear_mask, r4  ! r4 = 0xFBFF (clear bit 10 in HIRQ)
    mov.l   .L_fn_smpc_cmd_helper_b, r3 ! r3 = &smpc_cmd_helper_b
    jsr @r3                             ! clear CD HIRQ bit
    nop
    add #0x1, r8                        ! r8++ (poll iteration counter)
    mov.w   DAT_06040dc2, r2           ! r2 = 0x0258 (600 = max poll count)
    cmp/gt r2, r8                       ! poll_count > 600?
    bf      .L_poll_not_exceeded        ! no -> continue
    bra     .L_return                   ! yes -> timeout, return -2
    mov #-0x2, r0                       ! error: poll timeout
.L_poll_not_exceeded:
    mov r15, r4                         ! r4 = &local buffer
    jsr @r11                            ! ai_checkpoint_section(local+8)
    add #0x8, r4                        ! r4 -> local[8] (delay slot)
    mov r15, r0                         ! r0 = &local buffer
    add #0x8, r0                        ! r0 -> local[8]
    mov.b @r0, r0                       ! r0 = checkpoint result byte
    extu.b r0, r0                       ! zero-extend
    bra     .L_check_next_surface       ! check surface type after CD poll
    and #0xF, r0                        ! isolate low nibble (delay slot)
.L_err_barrier_post_cd:
    bra     .L_return                   ! return error -10
    mov #-0xA, r0                       ! surface type 9/A = barrier
.L_found_end_marker:
    bra     .L_main_loop_top            ! set end flag and re-enter main loop
    mov r10, r9                         ! r9 = 1 (end marker found, delay slot)
.L_check_next_surface:
    cmp/eq #0x1, r0                     ! surface type == 1 (end marker)?
    bt      .L_found_end_marker
    cmp/eq #0x2, r0                     ! surface type == 2 (end marker)?
    bt      .L_found_end_marker
    cmp/eq #0x9, r0                     ! surface type == 9 (barrier)?
    bt      .L_err_barrier_post_cd
    cmp/eq #0xA, r0                     ! surface type == A (barrier)?
    bt      .L_err_barrier_post_cd
.L_main_loop_top:
    tst r9, r9                          ! end marker found yet?
    bt      .L_poll_cd_status           ! no -> keep polling CD status
    mov.l   .L_track_data_ptr, r9      ! r9 = &track_data_ptr (indirect)
    mov.w   .L_off_track_geom, r3      ! r3 = 0x043C (track geometry offset)
    mov.l @r9, r9                       ! r9 = track_data_base
    add r3, r9                          ! r9 -> track_data[+0x43C] (geometry block)
    mov.l   .L_fn_track_intersect_test, r3 ! r3 = &track_intersect_test
    jsr @r3                             ! track_intersect_test(geom_block)
    mov r9, r4                          ! r4 = geom_block (delay slot)
    mov r0, r4                          ! r4 = intersect result
    tst r4, r4                          ! result == 0 (success)?
    bt      .L_intersect_ok             ! yes -> continue to boundary check
    bra     .L_return                   ! no -> return -2
    mov #-0x2, r0                       ! error: intersection test failed

    .global DAT_06040dc0
DAT_06040dc0:
    .2byte  0x0400                      /* CD status bit 10 mask */

    .global DAT_06040dc2
DAT_06040dc2:
    .2byte  0x0258                      /* 600 = max CD poll iterations */
.L_off_track_geom:
    .2byte  0x043C                      /* offset to track geometry block */
    .2byte  0xFFFF                      /* alignment padding */
.L_fn_smpc_status_read:
    .4byte  sym_06035C4E                /* SMPC status word reader */
.L_cd_hirq_clear_mask:
    .4byte  0x0000FBFF                  /* ~0x0400: clears CD HIRQ bit 10 */
.L_fn_smpc_cmd_helper_b:
    .4byte  smpc_cmd_helper_b           /* CD HIRQ acknowledge helper */
.L_track_data_ptr:
    .4byte  sym_060A4D14                /* pointer to track data base */
.L_fn_track_intersect_test:
    .4byte  track_intersect_test        /* track intersection geometry test */
.L_intersect_ok:
    mov r15, r5                         ! r5 = &local buffer
    mov.l   .L_fn_mesh_boundary_check, r3 ! r3 = &mesh_boundary_check
    add #0x4, r5                        ! r5 -> local[4] (output param)
    jsr @r3                             ! mesh_boundary_check(0, &local[4])
    mov #0x0, r4                        ! r4 = 0 (direction = first pass, delay slot)
    mov r15, r5                         ! r5 = &local buffer
    mov r15, r4                         ! r4 = &local buffer
    mov.l   .L_fn_mesh_boundary_check, r3 ! r3 = &mesh_boundary_check
    add #0x4, r5                        ! r5 -> local[4]
    add #0x4, r4                        ! r4 -> local[4]
    mov.b @r4, r4                       ! r4 = local[4] byte (first-pass result)
    jsr @r3                             ! mesh_boundary_check(result, &local[4])
    extu.b r4, r4                       ! zero-extend (delay slot)
    mov r15, r0                         ! r0 = &local buffer
    mov.l   .L_fp_surface_flag_bit, r2  ! r2 = 0x40000000 (surface validity flag)
    add #0x4, r0                        ! r0 -> local[4]
    mov.b @r0, r0                       ! r0 = boundary result byte
    extu.b r0, r0                       ! zero-extend
    add #-0x1, r0                       ! convert to 0-based index
    shll2 r0                            ! r0 *= 4 (dword offset into geom table)
    mov.l @(r0, r9), r3                 ! r3 = geom_table[index] (surface flags)
    and r2, r3                          ! r3 &= 0x40000000
    tst r3, r3                          ! surface flag bit set?
    bf      .L_surface_flag_ok          ! yes -> surface is valid
    bra     .L_return                   ! no -> return -15
    mov #-0xF, r0                       ! error: surface flag not set
.L_surface_flag_ok:
    mov.w   DAT_06040e72, r4           ! r4 = 0x00FC (surface type query param)
    mov.l   .L_fn_track_surface_type_a, r3 ! r3 = &track_surface_type_a
    jsr @r3                             ! track_surface_type_a(0xFC, 0xFF)
    mov r12, r5                         ! r5 = 0x00FF (byte mask, delay slot)
    mov.l @r14, r2                      ! r2 = state base
    mov.l   .L_fp_half, r3             ! r3 = 0x8000 (0.5 in 16.16 fixed-point)
    mov.l r3, @(60, r2)                 ! state[+0x3C] = 0x8000 (countdown init)
    bra     .L_poll_smpc_status         ! enter SMPC polling loop
    nop
.L_countdown_decrement:
    mov.l @r14, r2                      ! r2 = state base
    mov.l @(60, r2), r3                 ! r3 = state[+0x3C] (countdown)
    add #-0x1, r3                       ! countdown--
    tst r3, r3                          ! countdown == 0?
    bf/s    .L_poll_smpc_status         ! no -> keep polling
    mov.l r3, @(60, r2)                 ! state[+0x3C] = countdown (delay slot)
    bra     .L_return                   ! yes -> timeout, return -2
    mov #-0x2, r0                       ! error: SMPC poll timeout
.L_poll_smpc_status:
    mov #0x40, r3                       ! r3 = 0x40 (SMPC status bit 6)
    mov.l r3, @r15                      ! local[0] = mask
    mov.l   .L_fn_smpc_status_read_2, r3 ! r3 = &smpc_status_read
    jsr @r3                             ! r0 = smpc_status_read()
    nop
    mov r0, r5                          ! r5 = raw status word
    mov.l @r15, r3                      ! r3 = 0x40 (reload mask)
    exts.w r5, r4                       ! r4 = status sign-extended
    and r3, r4                          ! r4 = status & 0x40
    tst r4, r4                          ! SMPC bit 6 clear?
    bt      .L_smpc_bit_not_set         ! yes -> r4 = 0
    bra     .L_smpc_bit_is_set          ! no -> r4 = 1
    mov #0x1, r4                        ! (delay slot)
.L_smpc_bit_not_set:
    mov #0x0, r4                        ! r4 = 0 (SMPC not ready)
.L_smpc_bit_is_set:
    tst r4, r4                          ! SMPC ready?
    bt      .L_countdown_decrement      ! no -> decrement countdown and retry
    mov.l @r14, r3                      ! r3 = state base
    mov.l r13, @(60, r3)                ! state[+0x3C] = 0 (clear countdown)
    mov.l @r14, r4                      ! r4 = state base
    jsr @r11                            ! ai_checkpoint_section(state+0x40)
    add #0x40, r4                       ! r4 -> state[+0x40] (delay slot)
    mov r13, r0                         ! r0 = 0 (success)
.L_return:
    add #0x14, r15                      ! deallocate locals
    lds.l @r15+, pr                     ! restore return address
    mov.l @r15+, r8                     ! restore r8
    mov.l @r15+, r9                     ! restore r9
    mov.l @r15+, r10                    ! restore r10
    mov.l @r15+, r11                    ! restore r11
    mov.l @r15+, r12                    ! restore r12
    mov.l @r15+, r13                    ! restore r13
    rts                                 ! return
    mov.l @r15+, r14                    ! restore r14 (delay slot)

    .global DAT_06040e72
DAT_06040e72:
    .2byte  0x00FC                      /* surface type query param (0xFC) */
.L_fn_mesh_boundary_check:
    .4byte  mesh_boundary_check         /* mesh boundary validator */
.L_fp_surface_flag_bit:
    .4byte  0x40000000                  /* surface validity flag bit (bit 30) */
.L_fn_track_surface_type_a:
    .4byte  track_surface_type_a        /* surface type classification */
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) -- SMPC countdown init */
.L_fn_smpc_status_read_2:
    .4byte  sym_06035C4E                /* SMPC status word reader (same as above) */

/* -----------------------------------------------------------------------
 * slot_alloc_zone (sym_06040E88)
 * Allocates a free slot in the 24-entry zone flag array at state[+0x18].
 * r4 = output pointer, returns r0 = 0 (ok) or -3 (full).
 * ----------------------------------------------------------------------- */
    .global sym_06040E88
sym_06040E88:
    mov #0x1, r1                        ! r1 = 1 (active marker)
    mov #0x18, r7                       ! r7 = 24 (max slot count)
    mov.l   .L_game_state_ptr_2, r6    ! r6 = &game_state_ptr (indirect)
    mov #0x0, r5                        ! r5 = 0 (scan index)
.L_zone_scan_loop:
    mov.l @r6, r3                       ! r3 = state base
    add #0x18, r3                       ! r3 -> state[+0x18] (zone flags array)
    add r5, r3                          ! r3 -> zone_flags[index]
    mov.b @r3, r2                       ! r2 = zone_flags[index]
    tst r2, r2                          ! slot empty?
    bf      .L_zone_slot_occupied       ! no -> try next slot
    mov.l @r6, r3                       ! r3 = state base
    add #0x18, r3                       ! r3 -> zone_flags array
    add r5, r3                          ! r3 -> zone_flags[index]
    mov.b r1, @r3                       ! zone_flags[index] = 1 (mark active)
    mov.l r5, @r4                       ! *output = slot index
    rts                                 ! return success
    mov #0x0, r0                        ! r0 = 0 (delay slot)
.L_zone_slot_occupied:
    add #0x1, r5                        ! index++
    cmp/ge r7, r5                       ! index >= 24?
    bf      .L_zone_scan_loop           ! no -> keep scanning
    mov #-0x1, r2                       ! r2 = -1
    mov.l r2, @r4                       ! *output = -1 (no slot)
    mov #-0x3, r0                       ! r0 = -3 (error: no free slot)
    rts                                 ! return failure
    nop

/* -----------------------------------------------------------------------
 * slot_free_zone (sym_06040EBA)
 * Frees a slot in the zone flag array at state[+0x18].
 * r4 = slot index, returns r0 = 0 (ok), -6 (range), -7 (not active).
 * ----------------------------------------------------------------------- */
    .global sym_06040EBA
sym_06040EBA:
    cmp/pz r4                           ! index >= 0?
    bf      .L_free_out_of_range        ! no -> out of range
    mov #0x18, r2                       ! r2 = 24
    cmp/ge r2, r4                       ! index >= 24?
    bf      .L_free_index_valid         ! no -> valid range
.L_free_out_of_range:
    rts                                 ! return error
    mov #-0x6, r0                       ! r0 = -6 (index out of range)
.L_free_index_valid:
    mov.l   .L_game_state_ptr_2, r5    ! r5 = &game_state_ptr
    mov.l @r5, r0                       ! r0 = state base
    add #0x18, r0                       ! r0 -> zone_flags array
    mov.b @(r0, r4), r0                 ! r0 = zone_flags[index]
    cmp/eq #0x1, r0                     ! slot currently active?
    bt      .L_free_slot_active         ! yes -> proceed to free
    rts                                 ! return error
    mov #-0x7, r0                       ! r0 = -7 (slot not allocated)
.L_free_slot_active:
    mov.l @r5, r3                       ! r3 = state base
    add #0x18, r3                       ! r3 -> zone_flags array
    add r3, r4                          ! r4 = &zone_flags[index]
    mov #0x0, r2                        ! r2 = 0
    mov.b r2, @r4                       ! zone_flags[index] = 0 (freed)
    mov r2, r0                          ! r0 = 0 (success)
    rts                                 ! return
    nop
.L_game_state_ptr_2:
    .4byte  sym_060A5400                /* pointer to game state base structure */

/* -----------------------------------------------------------------------
 * slot_alloc_direct (sym_06040EEC)
 * Allocates a free slot in the 24-entry direct array at state[+0x0].
 * r4 = output pointer, returns r0 = 0 (ok) or -4 (full).
 * ----------------------------------------------------------------------- */
    .global sym_06040EEC
sym_06040EEC:
    mov #0x1, r1                        ! r1 = 1 (active marker)
    mov #0x18, r7                       ! r7 = 24 (max slot count)
    .byte   0xD6, 0x12    /* mov.l .L_pool_06040F3C, r6 */
    mov #0x0, r5                        ! r5 = 0 (scan index)
.L_direct_scan_loop:
    mov.l @r6, r0                       ! r0 = state base (direct array at +0x0)
    mov.b @(r0, r5), r3                 ! r3 = direct_flags[index]
    tst r3, r3                          ! slot empty?
    bf      .L_direct_slot_occupied     ! no -> try next slot
    mov.l @r6, r0                       ! r0 = state base
    mov.b r1, @(r0, r5)                 ! direct_flags[index] = 1 (mark active)
    mov.l r5, @r4                       ! *output = slot index
    rts                                 ! return success
    mov #0x0, r0                        ! r0 = 0 (delay slot)
.L_direct_slot_occupied:
    add #0x1, r5                        ! index++
    cmp/ge r7, r5                       ! index >= 24?
    bf      .L_direct_scan_loop         ! no -> keep scanning
    mov #-0x1, r3                       ! r3 = -1
    mov.l r3, @r4                       ! *output = -1 (no slot)
    mov #-0x4, r0                       ! r0 = -4 (error: no free slot)
    rts                                 ! return failure
    nop
