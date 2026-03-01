
    .section .text.FUN_0601AC88


    .global replay_cam_main_loop
    .type replay_cam_main_loop, @function
replay_cam_main_loop:
    sts.l pr, @-r15
    mov.l   .L_p_frame_counter, r13
    mov.l   .L_p_race_end_state, r5
    mov.l   .L_p_render_state, r2
    mov.l @r5, r4
    mov.l @r5, r11
    mov.l @r2, r2
    mov r4, r3
    shll r2
    shll r4
    shll2 r3
    add r3, r4
    add r2, r4
    mov.l   .L_p_cam_target_array, r3
    shll2 r4
    add r3, r4
    mov.l @r4, r4
    shll r11
    shll2 r11
    mov.l   .L_p_cam_target_offset, r2
    add r2, r11
    mov.l @r11, r11
    mov.l @r13, r3
    mov.w   .L_w_last_entry_frame_off, r0
    mov.l @(r0, r4), r2
    cmp/hs r2, r3
    bt/s    .L_no_matching_entry
    mov #0x13, r14
    mov.l   .L_p_race_event_flags, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_no_matching_entry
.L_scan_loop:
    extu.b r14, r3
    mov.l @r13, r1
    add #-0x1, r3
    mov r3, r2
    shll2 r3
    shll2 r2
    shll r2
    add r2, r3
    add r4, r3
    mov.l @(4, r3), r3
    cmp/hs r3, r1
    bf      .L_no_match_copy_prev
    bra     .L_entry_found
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
    extu.b r14, r1
    extu.b r14, r2
    mov r1, r3
    add #-0x1, r2
    shll2 r1
    shll2 r3
    shll r3
    add r3, r1
    add r4, r1
    mov r2, r3
    shll2 r2
    shll2 r3
    shll r3
    add r3, r2
    add r4, r2
    mov.l   .L_p_fn_memcpy_long, r3
    jsr @r3
    mov #0xC, r0
    add #-0x1, r14
    extu.b r14, r2
    cmp/pl r2
    bt      .L_scan_loop
.L_entry_found:
    extu.b r14, r12
    mov.l @r13, r2
    mov r12, r3
    shll2 r12
    shll2 r3
    shll r3
    add r3, r12
    add r4, r12
    bsr     .L_cam_table_base_select
    mov.l r2, @(4, r12)
    mov.b r0, @(8, r12)
    mov.l   .L_p_crossing_dir_flag, r2
    mov.b @r2, r2
    mov r2, r0
    mov.b r0, @(9, r12)
    mov.l   .L_p_attract_timer, r3
    mov.l @r3, r3
    extu.b r3, r0
    mov.b r0, @(10, r12)
    extu.b r10, r3
    mov.b r3, @r12
    mov.l   .L_p_active_cam_entry, r3
    mov.l r12, @r3
    mov.l   .L_p_cam_cut_index, r3
    mov.b r14, @r3
    bra     .L_check_race_time
    nop
.L_no_matching_entry:
    mov.l   .L_p_active_cam_entry, r3
    mov.l r10, @r3
.L_check_race_time:
    mov.l   .L_p_cam_override_ptr, r5
    mov.l   .L_p_race_time, r4
    mov.l @(4, r11), r3
    mov.l @r4, r2
    cmp/ge r3, r2
    bt      .L_no_time_override
    mov.l @r4, r3
    cmp/pl r3
    bf      .L_no_time_override
    mov.l @r4, r3
    mov.l r3, @(4, r11)
    bra     .L_epilogue
    mov.l r11, @r5
.L_no_time_override:
    mov.l r10, @r5
.L_epilogue:
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
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
.L_cam_table_base_select:
    mov.l   .L_p_secondary_proc_flag, r0
    mov.b @r0, r0
    tst r0, r0
    bt      .L_use_default_table
    mov.l   .L_p_frame_output, r4
    mov.l @r4, r4
    extu.b r4, r4
    bra     .L_check_extra_offset
    add #0xA, r4

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
    .byte   0xD4, 0x17    /* mov.l .L_pool_0601AECC, r4 */
    mov.l @r4, r4
.L_check_extra_offset:
    .byte   0xD0, 0x17    /* mov.l .L_pool_0601AED0, r0 */
    mov.b @r0, r0
    tst r0, r0
    bt/s    .L_return_table_base
    extu.b r4, r4
    add #0xC, r4
.L_return_table_base:
    rts
    mov r4, r0
