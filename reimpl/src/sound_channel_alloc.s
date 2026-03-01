
    .section .text.FUN_0601D478


    .global sound_cmd_queue_write
    .type sound_cmd_queue_write, @function
sound_cmd_queue_write:
    sts.l pr, @-r15
    mov #0x2, r2
    mov #0x0, r6
    mov.l   _pool_display_config_word, r3
    mov.w r2, @r3
    mov.l   _pool_initial_scroll_offset, r3
    mov.l   _pool_display_slot_ptr, r2
    mov.l r3, @r2
    mov r2, r5
    mov.l   _pool_fn_display_channel_b, r3
    mov.l @r5, r5
    jsr @r3
    mov #0x20, r4
    mov #0x2A, r2
    mov.l   _pool_transition_state_word, r3
    mov.w r2, @r3
    bsr     camera_view_update
    mov r2, r4
    mov.l   _pool_game_state_byte, r4
    lds.l @r15+, pr
    mov.b @r4, r2
    add #0x1, r2
    rts
    mov.b r2, @r4

    .global sound_channel_alloc
    .type sound_channel_alloc, @function
sound_channel_alloc:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    mov.l   _pool_fp_sixteen, r4
    mov.l   _pool_transition_state_word, r13
    mov.l   _pool_display_slot_ptr, r14
    mov.w @r13, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_countdown_done
    mov #0x0, r6
    mov.l @r14, r3
    sub r4, r3
    mov.l r3, @r14
    mov r3, r5
    mov.l   _pool_fn_display_channel_b, r3
    jsr @r3
    mov #0x20, r4
    mov.w @r13, r4
    add #-0x2, r4
    mov.w r4, @r13
    lds.l @r15+, pr
    mov.l @r15+, r13
    bra     camera_view_update
    mov.l @r15+, r14
.L_countdown_done:
    mov.l   _pool_game_state_byte, r5
    mov.b @r5, r2
    add #0x1, r2
    mov.b r2, @r5
    mov.l @r14, r3
    sub r4, r3
    mov.l r3, @r14
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
_pool_display_config_word:
    .4byte  sym_0605AAA2                        /* &display_config_word (16-bit) */
_pool_initial_scroll_offset:
    .4byte  0x01500000                          /* initial scroll offset (16.16 fp: 336.0) */
_pool_display_slot_ptr:
    .4byte  sym_0607885C                        /* &display_slot_ptr (32-bit, 16.16 fp scroll) */
_pool_fn_display_channel_b:
    .4byte  display_channel_b                   /* display channel setup function */
_pool_transition_state_word:
    .4byte  sym_0607886E                        /* &transition_state_word (16-bit countdown) */
_pool_game_state_byte:
    .4byte  sym_0607887F                        /* &game_state byte (8-bit, 0-4 index) */
_pool_fp_sixteen:
    .4byte  0x00100000                  /* 16.0 (16.16 fixed-point) */

    .global loc_0601D50C
loc_0601D50C:
    mov.l   _pool2_display_slot_ptr, r0
    mov.l @r0, r0
    tst r0, r0
    bt      .L_fade_done
    mov.l   _pool2_mode_config_flags, r0
    mov.l @r0, r0
    tst #0x1, r0
    bt/s    .L_negate_offset
    mov #0x0, r6
    mov.l   _pool2_display_slot_ptr, r5
    mov #0x0, r3
    mov.l @r5, r5
    cmp/gt r5, r3
    addc r3, r5
    shar r5
    mov.l   _pool2_display_slot_ptr, r3
    bra     .L_commit_fade
    mov.l r5, @r3
.L_negate_offset:
    mov.l   _pool2_display_slot_ptr, r5
    mov.l @r5, r5
    neg r5, r5
.L_commit_fade:
    mov.l   _pool2_fn_display_channel_b, r3
    jmp @r3
    mov #0x20, r4
.L_fade_done:
    mov.l   _pool2_game_state_byte, r4
    mov.b @r4, r2
    add #0x1, r2
    rts
    mov.b r2, @r4

    .global loc_0601D546
loc_0601D546:
    mov #0x17, r5
    mov.l   _pool3_countdown_timer, r4
    mov.l   _pool3_fn_dlist_slot_select, r3
    jmp @r3
    mov.l @r4, r4
_pool2_display_slot_ptr:
    .4byte  sym_0607885C                        /* &display_slot_ptr (32-bit scroll offset) */
_pool2_mode_config_flags:
    .4byte  sym_0607EBC8                        /* &mode_config_flags (bit 0 = fade dir) */
_pool2_fn_display_channel_b:
    .4byte  display_channel_b                   /* display channel setup function */
_pool2_game_state_byte:
    .4byte  sym_0607887F                        /* &game_state byte (8-bit) */
_pool3_countdown_timer:
    .4byte  sym_0607EBCC                        /* &state_countdown_timer (32-bit) */
_pool3_fn_dlist_slot_select:
    .4byte  sym_0600338C                        /* dlist_slot_select function */

    .global loc_0601D568
loc_0601D568:
    mov.l   _pool4_countdown_timer, r3
    mov #0x1, r2
    mov.l @r3, r3
    cmp/ge r2, r3
    bt      .L_timer_still_active
    mov #0x6, r2
    mov.l   _pool4_game_state_dispatch, r3
    mov.l r2, @r3
.L_timer_still_active:
    rts
    nop

    .global camera_view_update
    .type camera_view_update, @function
camera_view_update:
    mov.l r14, @-r15
    mov #0x1C, r14
    mov.l r13, @-r15
    mov #0x2C, r13
    mov.l r12, @-r15
    sts.l macl, @-r15
    add #-0x4, r15
    mov.w r4, @r15
    mov.l   _pool5_src_table_base, r12
    mov #0x0, r4
    mov.w @r15, r1
    mov.l   _pool5_dest_table_base, r7
    extu.w r1, r1
    shll r1
.L_copy_loop:
    extu.w r4, r5
    extu.w r4, r6
    shll r5
    mul.l r13, r6
    add #0x1, r4
    shll r5
    sts macl, r6
    add r7, r5
    shll r6
    add r1, r6
    add r12, r6
    mov.w @r6, r3
    mov.w r3, @r5
    extu.w r4, r3
    mov.w @(2, r6), r0
    cmp/ge r14, r3
    bf/s    .L_copy_loop
    mov.w r0, @(2, r5)
    mov #0x0, r7
    mov.w @r15, r0
    extu.w r0, r0
    and #0x3F, r0
    mov r0, r6
    shll r6
    mov.l   _pool5_display_config_word, r5
    mov #0xC, r4
    add #0x4, r15
    lds.l @r15+, macl
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   _pool5_fn_display_list_loader, r3
    jmp @r3
    mov.l @r15+, r14
    .2byte  0xFFFF                              /* alignment padding */
_pool4_countdown_timer:
    .4byte  sym_0607EBCC                        /* &state_countdown_timer (32-bit) */
_pool4_game_state_dispatch:
    .4byte  g_game_state                        /* &game_state_dispatch_value (32-bit) */
_pool5_src_table_base:
    .4byte  sym_06094FAC                        /* &display_channel_src_table (source entries) */
_pool5_dest_table_base:
    .4byte  sym_0605AAA6                        /* &display_channel_dest_table (28 x 4-byte dest) */
_pool5_display_config_word:
    .4byte  sym_0605AAA2                        /* &display_config_word (16-bit) */
_pool5_fn_display_list_loader:
    .4byte  sym_06028400                        /* display_list_loader function */
