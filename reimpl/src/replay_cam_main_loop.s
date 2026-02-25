/* replay_cam_main_loop -- L3 assembly (SH-2 mnemonics)
 * Translation unit: 0x0601AC88 - 0x0601AE80
 *
 * Replay camera main loop for Daytona USA replay playback.
 *
 * Functions:
 *   replay_cam_main_loop (0x0601AC88, 504 bytes)
 *     Selects the correct camera cut-point entry for the current replay frame.
 *     Camera cut-points are stored as 0xC-byte records in a table (up to 20
 *     entries, indices 0x00..0x13). The function scans backwards from entry 19
 *     to find the first entry whose frame threshold <= the current frame counter
 *     (sym_060786A4). When found, it stores the entry's parameters (frame value,
 *     camera type byte, direction byte, cut index) into the active camera state
 *     (sym_06085FFC) and updates the cam cut index (sym_06086012).
 *     Also checks the race time (sym_06078638) against the cam target array
 *     entry's threshold and stores an override if exceeded.
 *
 *   FUN_0601ADB0 (0x0601ADB0, 124 bytes) -- retained as .4byte retail blob
 *     Pure math computation function (LEAF). Computes camera interpolation
 *     parameters for smooth replay transitions.
 *
 *   cam_table_base_select (0x0601AE2C, 38 bytes, LEAF)
 *     Selects the camera cut-point table base address. If the secondary SH-2
 *     processing flag (sym_06083255) is set, uses an offset from frame_output
 *     (sym_0607EAB8) + 0xA. Otherwise loads the default table pointer. If
 *     a secondary flag (sym_0605DE40) is also set, adds an extra +0xC offset.
 *     Returns the table base in r0.
 *
 * Key data structures:
 *   Camera cut-point entry (0xC bytes):
 *     +0x00: camera type (byte)
 *     +0x04: frame threshold (32-bit)
 *     +0x08: direction/flags byte
 *     +0x09: secondary flag byte
 *     +0x0A: cut index byte
 *
 * Callee: sym_06035168 (memcpy_long -- unrolled longword copy)
 */

    .section .text.FUN_0601AC88


    .global replay_cam_main_loop
    .type replay_cam_main_loop, @function
replay_cam_main_loop:
    sts.l pr, @-r15                         ! save return address
    mov.l   .L_p_frame_counter, r13         ! r13 = &frame_counter (sym_060786A4)
    mov.l   .L_p_race_end_state, r5         ! r5 = &race_end_state (sym_0607EAD8)
    mov.l   .L_p_render_state, r2           ! r2 = &render_state (sym_0605AD00)
    mov.l @r5, r4                           ! r4 = race_end_state
    mov.l @r5, r11                          ! r11 = race_end_state (kept for target lookup)
    mov.l @r2, r2                           ! r2 = render_state
    mov r4, r3                              ! r3 = race_end_state
    shll r2                                 ! r2 = render_state * 2
    shll r4                                 ! r4 = race_end_state * 2
    shll2 r3                                ! r3 = race_end_state * 4
    add r3, r4                              ! r4 = race_end_state * 6
    add r2, r4                              ! r4 += render_state * 2
    mov.l   .L_p_cam_target_array, r3       ! r3 = cam_target_array base (sym_0605DD6C)
    shll2 r4                                ! r4 = (end_state*6 + render*2) * 4 = table index
    add r3, r4                              ! r4 = &cam_target_array[index]
    mov.l @r4, r4                           ! r4 = cam cut-point table pointer
    shll r11                                ! r11 = race_end_state * 2
    shll2 r11                               ! r11 = race_end_state * 8
    mov.l   .L_p_cam_target_offset, r2      ! r2 = cam target offset base (sym_0605DE24)
    add r2, r11                             ! r11 = &cam_target[race_end_state]
    mov.l @r11, r11                         ! r11 = cam_target[race_end_state] (threshold struct)
    mov.l @r13, r3                          ! r3 = current frame counter
    mov.w   .L_w_last_entry_frame_off, r0   ! r0 = 0xE8 (offset to last entry's frame field)
    mov.l @(r0, r4), r2                     ! r2 = table[last].frame_threshold
    cmp/hs r2, r3                           ! frame_counter >= last threshold?
    bt/s    .L_no_matching_entry            ! yes: frame is past all cuts, skip scan
    mov #0x13, r14                          ! r14 = 0x13 (19 = max entry index)
    mov.l   .L_p_race_event_flags, r0       ! r0 = &race_event_flags (sym_0607EBF4)
    mov.l @r0, r0                           ! r0 = race_event_flags
    tst r0, r0                              ! flags == 0?
    bt      .L_no_matching_entry            ! no race events active: skip scan
.L_scan_loop:
    extu.b r14, r3                          ! r3 = current scan index (unsigned)
    mov.l @r13, r1                          ! r1 = current frame counter
    add #-0x1, r3                           ! r3 = index - 1 (previous entry)
    mov r3, r2                              ! r2 = index - 1
    shll2 r3                                ! r3 = (index-1) * 4
    shll2 r2                                ! r2 = (index-1) * 4
    shll r2                                 ! r2 = (index-1) * 8
    add r2, r3                              ! r3 = (index-1) * 12 = byte offset
    add r4, r3                              ! r3 = &table[index-1]
    mov.l @(4, r3), r3                      ! r3 = table[index-1].frame_threshold
    cmp/hs r3, r1                           ! frame_counter >= prev threshold?
    bf      .L_no_match_copy_prev           ! no: copy entry down and keep scanning
    bra     .L_entry_found                  ! yes: found the matching entry
    nop
.L_w_last_entry_frame_off:
    .2byte  0x00E8                          /* 0xE8 = 232 = 0x13 * 0xC + 4 (last entry frame offset) */
    .2byte  0xFFFF                          /* alignment padding */
.L_p_race_end_state:
    .4byte  sym_0607EAD8                    /* race end state (0/1/2 = attract cycle) */
.L_p_render_state:
    .4byte  sym_0605AD00                    /* render state variable */
.L_p_cam_target_array:
    .4byte  sym_0605DD6C                    /* camera target array base */
.L_p_frame_counter:
    .4byte  sym_060786A4                    /* replay frame counter (32-bit) */
    .4byte  sym_06085FF8                    /* fastest lap flag (byte) -- unused pool slot */
.L_p_cam_target_offset:
    .4byte  sym_0605DE24                    /* camera target position array */
.L_p_race_event_flags:
    .4byte  sym_0607EBF4                    /* race event bitfield (bit 0 = complete) */
.L_no_match_copy_prev:
    extu.b r14, r1                          ! r1 = current index (unsigned)
    extu.b r14, r2                          ! r2 = current index
    mov r1, r3                              ! r3 = current index
    add #-0x1, r2                           ! r2 = index - 1 (destination entry)
    shll2 r1                                ! r1 = index * 4
    shll2 r3                                ! r3 = index * 4
    shll r3                                 ! r3 = index * 8
    add r3, r1                              ! r1 = index * 12 (source byte offset)
    add r4, r1                              ! r1 = &table[index] (memcpy source)
    mov r2, r3                              ! r3 = (index-1)
    shll2 r2                                ! r2 = (index-1) * 4
    shll2 r3                                ! r3 = (index-1) * 4
    shll r3                                 ! r3 = (index-1) * 8
    add r3, r2                              ! r2 = (index-1) * 12 (dest byte offset)
    add r4, r2                              ! r2 = &table[index-1] (memcpy dest)
    mov.l   .L_p_fn_memcpy_long, r3         ! r3 = memcpy_long fn (sym_06035168)
    jsr @r3                                 ! memcpy_long(0xC, dst, src) -- copy entry down
    mov #0xC, r0                            ! r0 = 0xC bytes to copy (delay slot)
    add #-0x1, r14                          ! r14-- (move to next lower index)
    extu.b r14, r2                          ! r2 = remaining index (unsigned)
    cmp/pl r2                               ! index > 0?
    bt      .L_scan_loop                    ! yes: continue scanning backwards
.L_entry_found:
    extu.b r14, r12                         ! r12 = matched entry index (unsigned)
    mov.l @r13, r2                          ! r2 = current frame counter
    mov r12, r3                             ! r3 = entry index
    shll2 r12                               ! r12 = index * 4
    shll2 r3                                ! r3 = index * 4
    shll r3                                 ! r3 = index * 8
    add r3, r12                             ! r12 = index * 12 (entry byte offset)
    add r4, r12                             ! r12 = &table[index] (matched entry ptr)
    bsr     .L_cam_table_base_select        ! call cam_table_base_select -> r0 = cam type
    mov.l r2, @(4, r12)                     ! entry.frame_threshold = frame_counter (delay slot)
    mov.b r0, @(8, r12)                     ! entry.direction = cam_table_base_select result
    mov.l   .L_p_crossing_dir_flag, r2      ! r2 = &crossing_dir_flag (sym_0605DE3C)
    mov.b @r2, r2                           ! r2 = crossing_dir_flag (byte)
    mov r2, r0                              ! r0 = crossing direction
    mov.b r0, @(9, r12)                     ! entry.secondary_flag = crossing direction
    mov.l   .L_p_attract_timer, r3          ! r3 = &attract_timer (sym_0607EAE0)
    mov.l @r3, r3                           ! r3 = attract_timer (32-bit)
    extu.b r3, r0                           ! r0 = attract_timer low byte
    mov.b r0, @(10, r12)                    ! entry.cut_index = attract_timer & 0xFF
    extu.b r10, r3                          ! r3 = r10 low byte (cam type from caller)
    mov.b r3, @r12                          ! entry.camera_type = r10
    mov.l   .L_p_active_cam_entry, r3       ! r3 = &active_cam_entry (sym_06085FFC)
    mov.l r12, @r3                          ! active_cam_entry = &table[matched_index]
    mov.l   .L_p_cam_cut_index, r3          ! r3 = &cam_cut_index (sym_06086012)
    mov.b r14, @r3                          ! cam_cut_index = matched entry index
    bra     .L_check_race_time              ! proceed to race time check
    nop
.L_no_matching_entry:
    mov.l   .L_p_active_cam_entry, r3      ! r3 = &active_cam_entry
    mov.l r10, @r3                          ! active_cam_entry = r10 (caller's default)
.L_check_race_time:
    mov.l   .L_p_cam_override_ptr, r5      ! r5 = &cam_override_ptr (sym_06086000)
    mov.l   .L_p_race_time, r4             ! r4 = &race_time (sym_06078638)
    mov.l @(4, r11), r3                     ! r3 = cam_target.threshold (from end_state)
    mov.l @r4, r2                           ! r2 = race_time
    cmp/ge r3, r2                           ! race_time >= threshold?
    bt      .L_no_time_override             ! yes: no override needed
    mov.l @r4, r3                           ! r3 = race_time
    cmp/pl r3                               ! race_time > 0?
    bf      .L_no_time_override             ! no: skip override (time is zero/negative)
    mov.l @r4, r3                           ! r3 = race_time
    mov.l r3, @(4, r11)                     ! cam_target.threshold = race_time (clamp down)
    bra     .L_epilogue                     ! jump to epilogue
    mov.l r11, @r5                          ! cam_override_ptr = cam_target struct (delay slot)
.L_no_time_override:
    mov.l r10, @r5                          ! cam_override_ptr = r10 (caller's default)
.L_epilogue:
    lds.l @r15+, pr                         ! restore return address
    mov.l @r15+, r10                        ! restore r10
    mov.l @r15+, r11                        ! restore r11
    mov.l @r15+, r12                        ! restore r12
    mov.l @r15+, r13                        ! restore r13
    rts                                     ! return
    mov.l @r15+, r14                        ! restore r14 (delay slot)
.L_p_fn_memcpy_long:
    .4byte  sym_06035168                    /* memcpy_long (unrolled longword copy) */
.L_p_crossing_dir_flag:
    .4byte  sym_0605DE3C                    /* crossing direction flag (byte) */
.L_p_attract_timer:
    .4byte  sym_0607EAE0                    /* attract timer (32-bit) */
.L_p_active_cam_entry:
    .4byte  sym_06085FFC                    /* active camera cut-point entry pointer */
.L_p_cam_cut_index:
    .4byte  sym_06086012                    /* camera cut-point index (byte) */
.L_p_cam_override_ptr:
    .4byte  sym_06086000                    /* camera override pointer */
.L_p_race_time:
    .4byte  sym_06078638                    /* race time storage (32-bit) */
    /* FUN_0601ADB0: camera interpolation math (124 bytes, LEAF)
     * Retained as retail byte blob -- pure computation, no pool refs.
     * Computes smooth camera parameter interpolation for replay transitions. */
    .4byte  0xD523D624
    .4byte  0xD2246452
    .4byte  0x63624400
    .4byte  0x6033343C
    .4byte  0x4408342C
    .4byte  0x20088D2F
    .4byte  0x6442D620
    .4byte  0x52416362
    .4byte  0x33238906
    .4byte  0x62624215
    .4byte  0x8B03D21D
    .4byte  0x902F032E
    .4byte  0x1431D71C
    .4byte  0xD61CD41D
    .4byte  0x60526262
    .4byte  0x600E4208
    .4byte  0x63034008
    .4byte  0x43084300
    .4byte  0x303C600E
    .4byte  0x304C032E
    .4byte  0x62723232
    .4byte  0x8910D016
    .4byte  0x60022008
    .4byte  0x890C6052
    .4byte  0x600E6303
    .4byte  0x40084308
    .4byte  0x4300303C
    .4byte  0x600E304C
    .4byte  0x62624208
    .4byte  0x63720236
    .4byte  0x000B0009
    /* cam_table_base_select: selects camera cut-point table base address.
     * Returns table base in r0. LEAF function (no further calls). */
.L_cam_table_base_select:
    mov.l   .L_p_secondary_proc_flag, r0    ! r0 = &secondary_proc_flag (sym_06083255)
    mov.b @r0, r0                           ! r0 = secondary_proc_flag (byte)
    tst r0, r0                              ! flag == 0?
    bt      .L_use_default_table            ! yes: use default table pointer
    mov.l   .L_p_frame_output, r4           ! r4 = &frame_output (sym_0607EAB8)
    mov.l @r4, r4                           ! r4 = frame_output value
    extu.b r4, r4                           ! r4 = frame_output & 0xFF
    bra     .L_check_extra_offset           ! check if extra +0xC offset needed
    add #0xA, r4                            ! r4 += 0xA (secondary table offset, delay slot)

    .global DAT_0601ae3e
DAT_0601ae3e:
    .2byte  0x0240                          /* constant: car struct offset 0x240 */
    .4byte  sym_0607EAD8                    /* race end state (0/1/2) */
    .4byte  sym_0607EAE0                    /* attract timer (32-bit) */
    .4byte  sym_0605DE24                    /* camera target position array */
    .4byte  sym_06078638                    /* race time storage */
    .4byte  sym_06078900                    /* car array base */
    .4byte  sym_060786A4                    /* replay frame counter */
    .4byte  sym_0605AD00                    /* render state variable */
    .4byte  sym_0605DE40                    /* coordinate extent table */
    .4byte  sym_0607EBF4                    /* race event bitfield */
.L_p_secondary_proc_flag:
    .4byte  sym_06083255                    /* secondary SH-2 processing flag (byte) */
.L_p_frame_output:
    .4byte  sym_0607EAB8                    /* frame output (odd/even selector) */
.L_use_default_table:
    .byte   0xD4, 0x17    /* mov.l .L_pool_0601AECC, r4 */  ! r4 = default table ptr address
    mov.l @r4, r4                           ! r4 = *default_table_ptr
.L_check_extra_offset:
    .byte   0xD0, 0x17    /* mov.l .L_pool_0601AED0, r0 */  ! r0 = &extra_offset_flag (sym_0605DE40)
    mov.b @r0, r0                           ! r0 = extra_offset_flag (byte)
    tst r0, r0                              ! flag == 0?
    bt/s    .L_return_table_base            ! yes: return without extra offset
    extu.b r4, r4                           ! r4 = table_base & 0xFF (delay slot)
    add #0xC, r4                            ! r4 += 0xC (extra offset for alternate mode)
.L_return_table_base:
    rts                                     ! return
    mov r4, r0                              ! r0 = table base (delay slot)
