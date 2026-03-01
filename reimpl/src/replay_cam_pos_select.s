
    .section .text.FUN_0601ABC8


    .global replay_cam_pos_select
    .type replay_cam_pos_select, @function
replay_cam_pos_select:
    sts.l pr, @-r15
    extu.b r4, r3
    mov.l   .L_p_pos_index_u8, r2
    mov.b r3, @r2
    mov.l   .L_p_pos_index_s8, r2
    mov.b r4, @r2
    mov.l   .L_p_active_cam_entry, r2
    mov.l r4, @r2
    mov.l   .L_p_cam_override_ptr, r2
    mov.l r4, @r2
    .byte   0xB0, 0xE8    /* bsr 0x0601ADB0 (external) */
    nop
    mov.l   .L_p_race_end_state, r4
    mov.l   .L_p_cam_target_pos_arr, r3
    mov.l   .L_p_race_time, r5
    mov.l @r4, r4
    mov.l @r5, r2
    shll r4
    shll2 r4
    add r3, r4
    mov.l @r4, r4
    mov.l @(4, r4), r3
    cmp/ge r3, r2
    bt      .L_check_pos_override
    mov.l @r5, r3
    cmp/pl r3
    bf      .L_check_pos_override
    mov #0x1, r3
    mov.l   .L_p_pos_index_s8, r2
    mov.b r3, @r2
.L_check_pos_override:
    mov.l   .L_p_race_event_flags, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_race_event_path
    lds.l @r15+, pr
    rts
    nop
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
    .byte   0xD4, 0x27    /* mov.l .L_pool_0601ACE8, r4 */
    .byte   0xD2, 0x28    /* mov.l .L_pool_0601ACEC, r2 */
    .byte   0x90, 0x4A    /* mov.w .L_wpool_0601ACE4, r0 */
    mov.l @r4, r4
    mov.l @r2, r2
    mov r4, r3
    shll r2
    shll r4
    shll2 r3
    add r3, r4
    add r2, r4
    .byte   0xD3, 0x24    /* mov.l .L_pool_0601ACF0, r3 */
    shll2 r4
    .byte   0xD2, 0x24    /* mov.l .L_pool_0601ACF4, r2 */
    add r3, r4
    mov.l @r2, r2
    mov.l @r4, r4
    mov.l @(r0, r4), r3
    cmp/hs r3, r2
    bt      .L_no_event_override
    mov #0x1, r2
    .byte   0xD3, 0x21    /* mov.l .L_pool_0601ACF8, r3 */
    mov.b r2, @r3
.L_no_event_override:
    lds.l @r15+, pr
    rts
    nop
