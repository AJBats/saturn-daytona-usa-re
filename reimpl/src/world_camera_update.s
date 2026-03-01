
    .section .text.FUN_06005C98


    .global world_camera_update
    .type world_camera_update, @function
world_camera_update:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   _pool_dlist_cmd_writer, r8
    mov.l   _pool_geom_dispatch, r10
    mov.l   _pool_max_frame, r14
    mov.l   _pool_car_state_ptr, r4
    mov.l   _pool_max_car_count, r6
    mov.w   DAT_06005d3e, r0
    mov.l @r4, r4
    mov.l @r6, r5
    mov.l @(r0, r4), r3
    add #-0x1, r5
    cmp/hs r5, r3
    bt      .L_clamp_to_max
    mov.w   DAT_06005d3e, r0
    bra     .L_after_clamp
    mov.l @(r0, r4), r11
.L_clamp_to_max:
    mov r5, r11
.L_after_clamp:
    mov.l   _pool_countdown_state, r0
    mov.l @r0, r0
    cmp/eq #0x28, r0
    bf      .L_nonrace_path
    mov.w   _wpool_target_frame_ofs, r0
    mov.l @(r0, r4), r3
    mov r11, r4
    add #-0x7, r4
    cmp/pz r4
    bt/s    .L_window_start_valid
    mov.l r3, @r15
    bra     .L_window_start_set
    mov #0x0, r13
.L_window_start_valid:
    mov r4, r13
.L_window_start_set:
    cmp/gt r11, r13
    bt/s    .L_epilogue
    mov #0x0, r9
.L_lap_loop:
    mov r13, r12
    mov.l   _pool_lap_time_array, r3
    shll2 r12
    add r3, r12
    mov.l @r12, r12
    cmp/gt r14, r12
    bf      .L_lap_time_ok
    mov r14, r12
.L_lap_time_ok:
    .byte   0xB0, 0x6A    /* bsr 0x06005DD4 (anim_frame_transform) */
    mov r12, r4
    mov r0, r7
    mov.l @r15, r2
    cmp/eq r2, r12
    bf      .L_use_normal_slot
    bra     .L_slot_value_set
    mov #0x54, r6
.L_use_normal_slot:
    mov #0x48, r6
.L_slot_value_set:
    mov r9, r5
    add #0x5, r5
    shll2 r5
    shll2 r5
    shll2 r5
    mov.l r5, @(4, r15)
    add #0x3, r5
    shll r5
    jsr @r10
    mov #0x8, r4
    mov r13, r7
    mov #0x3C, r6
    mov.l @(4, r15), r5
    add #0x1, r7
    add #0x1, r5
    shll r5
    jsr @r8
    mov #0x8, r4
    add #0x1, r13
    cmp/gt r11, r13
    bf/s    .L_lap_loop
    add #0x1, r9
    bra     .L_epilogue
    nop

    .global DAT_06005d3e
DAT_06005d3e:
    .2byte  0x021C                              /* car struct offset: current frame counter */
_wpool_target_frame_ofs:
    .2byte  0x0240                              /* car struct offset: target frame / lap entry */
    .2byte  0xFFFF                              /* pool alignment padding */
_pool_dlist_cmd_writer:
    .4byte  sym_06028430                        /* display_list_cmd_writer function */
_pool_geom_dispatch:
    .4byte  sym_060284AE                        /* geom_dispatch_final function */
_pool_max_frame:
    .4byte  0x000927BF                          /* max frame index (599,999 = ~10 min at 60fps) */
_pool_car_state_ptr:
    .4byte  sym_0607E944                        /* car state struct pointer */
_pool_max_car_count:
    .4byte  sym_06063F28                        /* max car/frame count variable */
_pool_countdown_state:
    .4byte  sym_0607EAC0                        /* race countdown state variable */
_pool_lap_time_array:
    .4byte  sym_0607EBF8                        /* per-lap time array (4 bytes per entry) */
.L_nonrace_path:
    mov.w   DAT_06005dcc, r0
    mov.l @r6, r3
    mov.l @(r0, r4), r2
    cmp/eq r3, r2
    bt      .L_epilogue
    mov #0x7, r5
    cmp/ge r5, r11
    bt      .L_use_max_laps
    bra     .L_laps_set
    mov.l r11, @r15
.L_use_max_laps:
    mov.l r5, @r15
.L_laps_set:
    mov.l   _pool_frame_counter, r13
    mov.w   DAT_06005dce, r0
    mov.l @r13, r13
    mov.l @(r0, r4), r2
    mov r13, r3
    shll2 r13
    add r3, r13
    sub r2, r13
    cmp/gt r14, r13
    bf      .L_elapsed_ok
    mov r14, r13
.L_elapsed_ok:
    .byte   0xB0, 0x22    /* bsr 0x06005DD4 (anim_frame_transform) */
    mov r13, r4
    mov r0, r7
    mov #0x48, r6
    mov.l @r15, r5
    add #0x5, r5
    shll2 r5
    shll2 r5
    shll2 r5
    mov.l r5, @(4, r15)
    add #0x3, r5
    shll r5
    jsr @r10
    mov #0x8, r4
    mov r11, r7
    mov #0x3C, r6
    mov.l @(4, r15), r5
    add #0x1, r7
    add #0x1, r5
    shll r5
    jsr @r8
    mov #0x8, r4
.L_epilogue:
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06005dcc
DAT_06005dcc:
    .2byte  0x021C                              /* car struct offset: frame counter (re-read) */

    .global DAT_06005dce
DAT_06005dce:
    .2byte  0x022C                              /* car struct offset: lap start timestamp */
_pool_frame_counter:
    .4byte  sym_0607EBD0                        /* global frame counter (32-bit) */
