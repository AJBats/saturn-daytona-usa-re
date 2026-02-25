/* replay_cam_pos_select -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0601ABC8 - 0x0601AC7C
 *
 * FUN_0601ABC8 — replay_cam_pos_select (180 bytes)
 *
 * Stores the incoming camera position index (r4) into several state
 * variables, then calls the camera interpolation math function
 * (FUN_0601ADB0, via bsr), and performs two independent threshold
 * checks:
 *
 * Check 1 (race-time path):
 *   Indexes into cam_target_pos_arr using *race_end_state, reads the
 *   entry's frame threshold field (+4), and compares against *race_time.
 *   If race_time >= threshold (already expired) OR race_time <= 0
 *   (no time remaining), pos_index_s8 is clamped to 1.
 *
 * Check 2 (race-event path, tail of function):
 *   Checks race_event_flags (*sym_0607EBF4).  If zero, returns.
 *   Otherwise computes a second table index from *race_end_state and
 *   *render_state (race_end_state*6 + render_state*2, then *4), loads
 *   the corresponding table entry pointer, and compares *race_time
 *   against that entry's field at offset r0.  If race_time >= threshold,
 *   pos_index_s8 is forced to 1.
 *
 * Entry:
 *   r4 = camera position index (byte-sized, treated as signed/unsigned)
 * Callee:
 *   FUN_0601ADB0 via BSR (external — pool in next TU)
 *
 * Key state written:
 *   sym_06085FF8 (pos_index_u8)  — zero-extended index byte
 *   sym_06085FF9 (pos_index_s8)  — raw signed index byte
 *   sym_06085FFC (active_cam_entry) — full-word index stored as pointer
 *   sym_06086000 (cam_override_ptr) — full-word index stored as override
 */

    .section .text.FUN_0601ABC8


    .global replay_cam_pos_select
    .type replay_cam_pos_select, @function
replay_cam_pos_select:
    sts.l pr, @-r15                     ! save return address (PR) to stack
    extu.b r4, r3                       ! r3 = r4 zero-extended to byte (unsigned index)
    mov.l   .L_p_pos_index_u8, r2       ! r2 = &pos_index_u8 (sym_06085FF8)
    mov.b r3, @r2                       ! *pos_index_u8 = unsigned index byte
    mov.l   .L_p_pos_index_s8, r2       ! r2 = &pos_index_s8 (sym_06085FF9)
    mov.b r4, @r2                       ! *pos_index_s8 = raw (signed) index byte
    mov.l   .L_p_active_cam_entry, r2   ! r2 = &active_cam_entry (sym_06085FFC)
    mov.l r4, @r2                       ! *active_cam_entry = r4 (full word)
    mov.l   .L_p_cam_override_ptr, r2   ! r2 = &cam_override_ptr (sym_06086000)
    mov.l r4, @r2                       ! *cam_override_ptr = r4 (full word)
    .byte   0xB0, 0xE8    /* bsr 0x0601ADB0 (external) */ ! call camera interpolation math
    nop                                 ! (delay slot)
    mov.l   .L_p_race_end_state, r4     ! r4 = &race_end_state (sym_0607EAD8)
    mov.l   .L_p_cam_target_pos_arr, r3 ! r3 = cam_target position array base (sym_0605DE24)
    mov.l   .L_p_race_time, r5          ! r5 = &race_time (sym_06078638)
    mov.l @r4, r4                       ! r4 = *race_end_state (0/1/2)
    mov.l @r5, r2                       ! r2 = *race_time (32-bit)
    shll r4                             ! r4 = race_end_state * 2
    shll2 r4                            ! r4 = race_end_state * 8
    add r3, r4                          ! r4 = &cam_target_pos_arr[race_end_state]
    mov.l @r4, r4                       ! r4 = cam_target entry pointer
    mov.l @(4, r4), r3                  ! r3 = cam_target.frame_threshold (field at +4)
    cmp/ge r3, r2                       ! race_time >= frame_threshold? (signed)
    bt      .L_check_pos_override       ! yes: time already past threshold, skip clamp
    mov.l @r5, r3                       ! r3 = *race_time (reload)
    cmp/pl r3                           ! race_time > 0?
    bf      .L_check_pos_override       ! no (zero or negative): skip clamp
    mov #0x1, r3                        ! r3 = 1 (clamp value)
    mov.l   .L_p_pos_index_s8, r2       ! r2 = &pos_index_s8 (sym_06085FF9)
    mov.b r3, @r2                       ! *pos_index_s8 = 1 (clamp: time exceeded)
.L_check_pos_override:
    mov.l   .L_p_race_event_flags, r0   ! r0 = &race_event_flags (sym_0607EBF4)
    mov.l @r0, r0                       ! r0 = *race_event_flags (bitfield)
    tst r0, r0                          ! any race events active?
    bf      .L_race_event_path          ! yes: proceed to event-based check
    lds.l @r15+, pr                     ! no events: restore return address
    rts                                 ! return
    nop                                 ! (delay slot)
    .2byte  0xFFFF                      /* alignment padding */
.L_p_race_end_state:
    .4byte  sym_0607EAD8                /* race end state (0/1/2 = attract cycle) */
.L_p_coord_extent_table:
    .4byte  sym_0605DE40                /* coordinate extent table */
.L_p_render_state:
    .4byte  sym_0605AD00                /* render state variable */
.L_p_replay_length_limit:
    .4byte  sym_06086004                /* replay length limit */
.L_p_attract_timer:
    .4byte  sym_0607EAE0                /* attract timer (32-bit) */
.L_p_cam_target_pos_arr:
    .4byte  sym_0605DE24                /* camera target position array base */
.L_p_total_race_frames:
    .4byte  sym_06086008                /* total recorded race frames (32-bit) */
.L_p_pos_index_u8:
    .4byte  sym_06085FF8                /* camera position index, unsigned byte */
.L_p_pos_index_s8:
    .4byte  sym_06085FF9                /* camera position index, signed byte */
.L_p_active_cam_entry:
    .4byte  sym_06085FFC                /* active camera cut-point entry pointer */
.L_p_cam_override_ptr:
    .4byte  sym_06086000                /* camera override pointer */
.L_p_race_time:
    .4byte  sym_06078638                /* race time storage (32-bit) */
.L_p_race_event_flags:
    .4byte  sym_0607EBF4                /* race event bitfield (bit 0 = race complete) */
.L_race_event_path:
    .byte   0xD4, 0x27    /* mov.l .L_pool_0601ACE8, r4 */  ! r4 = &race_end_state (external pool)
    .byte   0xD2, 0x28    /* mov.l .L_pool_0601ACEC, r2 */  ! r2 = &render_state (external pool)
    .byte   0x90, 0x4A    /* mov.w .L_wpool_0601ACE4, r0 */ ! r0 = cam entry field offset (word, external pool)
    mov.l @r4, r4                       ! r4 = *race_end_state
    mov.l @r2, r2                       ! r2 = *render_state
    mov r4, r3                          ! r3 = race_end_state (copy)
    shll r2                             ! r2 = render_state * 2
    shll r4                             ! r4 = race_end_state * 2
    shll2 r3                            ! r3 = race_end_state * 4
    add r3, r4                          ! r4 = race_end_state * 6
    add r2, r4                          ! r4 = race_end_state*6 + render_state*2
    .byte   0xD3, 0x24    /* mov.l .L_pool_0601ACF0, r3 */  ! r3 = cam entry table base (external pool)
    shll2 r4                            ! r4 = (race_end_state*6 + render*2) * 4 = byte index
    .byte   0xD2, 0x24    /* mov.l .L_pool_0601ACF4, r2 */  ! r2 = &race_time (external pool)
    add r3, r4                          ! r4 = cam entry table base + byte index
    mov.l @r2, r2                       ! r2 = *race_time
    mov.l @r4, r4                       ! r4 = cam_entry_table[index] pointer
    mov.l @(r0, r4), r3                 ! r3 = cam_entry[r0] threshold field
    cmp/hs r3, r2                       ! race_time >= cam threshold? (unsigned)
    bt      .L_no_event_override        ! yes: no override needed
    mov #0x1, r2                        ! r2 = 1 (override value)
    .byte   0xD3, 0x21    /* mov.l .L_pool_0601ACF8, r3 */  ! r3 = &pos_index_s8 (external pool)
    mov.b r2, @r3                       ! *pos_index_s8 = 1 (clamp: race time exceeded cam threshold)
.L_no_event_override:
    lds.l @r15+, pr                     ! restore return address
    rts                                 ! return
    nop                                 ! (delay slot)
