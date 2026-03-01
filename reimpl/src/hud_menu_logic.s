
    .section .text.FUN_060127E0


    .global hud_menu_logic
    .type hud_menu_logic, @function
hud_menu_logic:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_ptr_scroll_offset, r4
    mov.l @r4, r3
    mov.l   .L_ptr_prev_scroll, r2
    mov.l r3, @r2
    mov.l   .L_ptr_render_flags, r5
    mov.l @r5, r0
    or #0x80, r0
    mov.l r0, @r5
    mov.l   .L_scroll_speed_delta, r3
    mov.l @r4, r2
    add r3, r2
    mov.l r2, @r4
    mov.l   .L_ptr_car_array_base, r4
    mov.l @r4, r4
    mov.w   DAT_06012884, r0
    mov.l @(r0, r4), r4
    mov.l   .L_fn_disp_cmd_write, r8
    mov.l   .L_fn_sound_cmd, r9
    mov.w   .L_menu_elem_stride, r10
    mov.l   .L_ptr_menu_elem_data, r11
    mov.l   .L_fn_disp_list_load, r12
    mov.l   .L_ptr_replay_struct, r13
    mov.l   .L_ptr_menu_state_ctr, r14
    bra     .L_state_dispatch
    mov.l @r14, r0
.L_state0_draw_items:
    mov.w   DAT_06012888, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   .L_disp_cmd_id_a, r6
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r12
    mov #0xC, r4
    mov.w   DAT_0601288c, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_0601288e, r6
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r12
    mov #0xC, r4
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    bra     .L_epilogue
    nop
.L_state1_check_input:
    mov r4, r0
    cmp/eq #0x52, r0
    bt      .L_handle_confirm_sel
    mov.l   .L_ptr_game_status, r3
    mov.w @r3, r2
    extu.w r2, r2
    mov.l   .L_ptr_status_mask, r3
    mov.w @r3, r3
    extu.w r3, r3
    and r3, r2
    tst r2, r2
    bf      .L_draw_highlight_sel
    mov.l   .L_ptr_render_enable, r0
    mov.w @r0, r0
    extu.w r0, r0
    tst r0, r0
    bt      .L_draw_default_item
.L_draw_highlight_sel:
    mov r13, r7
    add r10, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_06012890, r3
    add r3, r7
    bra     .L_issue_sel_disp_cmd
    nop

    .global DAT_06012884
DAT_06012884:
    .2byte  0x01EC                          /* car_array offset to input cmd field */
.L_menu_elem_stride:
    .2byte  0x0090                          /* menu element struct stride */

    .global DAT_06012888
DAT_06012888:
    .2byte  0x0098                          /* replay_struct offset: first display list */
.L_disp_cmd_id_a:
    .2byte  0x0880                          /* display command ID: menu item A */

    .global DAT_0601288c
DAT_0601288c:
    .2byte  0x00A0                          /* replay_struct offset: second display list */

    .global DAT_0601288e
DAT_0601288e:
    .2byte  0x088C                          /* display command ID: menu item B */

    .global DAT_06012890
DAT_06012890:
    .2byte  0x4000                          /* highlight display data offset */
    .2byte  0xFFFF                          /* alignment padding */
.L_ptr_scroll_offset:
    .4byte  sym_060788F8                    /* menu scroll position (32-bit) */
.L_ptr_prev_scroll:
    .4byte  sym_0605B714                    /* previous scroll position backup */
.L_ptr_render_flags:
    .4byte  sym_0605B6D8                    /* render mode flags (32-bit bitmask) */
.L_scroll_speed_delta:
    .4byte  0x0004CCCC                      /* 16.16 fixed-point scroll speed */
.L_ptr_car_array_base:
    .4byte  sym_0607E944                    /* car array base pointer */
.L_fn_disp_cmd_write:
    .4byte  sym_060283E0                    /* display command writer function */
.L_fn_sound_cmd:
    .4byte  sound_cmd_dispatch              /* sound command dispatch function */
.L_ptr_menu_elem_data:
    .4byte  sym_0605ACDD                    /* menu element data base */
.L_fn_disp_list_load:
    .4byte  sym_06028400                    /* display list loader function */
.L_ptr_replay_struct:
    .4byte  sym_06063750                    /* replay/display struct base */
.L_ptr_menu_state_ctr:
    .4byte  sym_060788F4                    /* menu state counter (32-bit) */
.L_ptr_game_status:
    .4byte  g_pad_state                    /* game status word (16-bit) */
.L_ptr_status_mask:
    .4byte  sym_0608188C                    /* status mask for input filtering */
.L_ptr_render_enable:
    .4byte  sym_0607ED8C                    /* special render enable (16-bit) */
.L_draw_default_item:
    mov.w   DAT_0601299a, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_0601299c, r3
    add r3, r7
.L_issue_sel_disp_cmd:
    mov.w   DAT_0601299e, r6
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r12
    mov #0x8, r4
    bra     .L_epilogue
    nop
.L_handle_confirm_sel:
    mov r11, r7
    mov.l @r14, r2
    add #0x1, r2
    mov.l r2, @r14
    mov.l   .L_mask_nibble3, r6
    mov.w   DAT_0601299e, r5
    jsr @r8
    mov #0x8, r4
    mov r11, r7
    mov.l   .L_mask_nibble3, r6
    mov.w   DAT_060129a0, r5
    jsr @r8
    mov #0x8, r4
    mov r11, r7
    mov.l   .L_mask_nibble3, r6
    mov.w   DAT_060129a2, r5
    jsr @r8
    mov #0x8, r4
    mov r13, r7
    add #0x78, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_060129a4, r3
    mov.w   DAT_060129a6, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r12
    mov #0x8, r4
    mov.l   .L_snd_cmd_menu_select, r5
    jsr @r9
    mov #0x0, r4
    bra     .L_epilogue
    nop
.L_state2_check_mode:
    mov r4, r0
    cmp/eq #0x58, r0
    bt      .L_handle_mode_confirm
    bra     .L_epilogue
    nop
.L_handle_mode_confirm:
    mov.l @r14, r3
    mov r13, r7
    add #0x1, r3
    add #0x70, r7
    mov.l r3, @r14
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_060129a4, r3
    mov.w   DAT_060129a6, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r12
    mov #0x8, r4
    mov #0x1, r3
    mov.l   .L_ptr_lap_count, r2
    mov.b r3, @r2
    mov.l   .L_ptr_car_array_base_b, r3
    mov.l   .L_ptr_yaw_angle_store, r1
    mov.l @r3, r3
    mov.l @(48, r3), r2
    mov.l r2, @r1
    mov.l   .L_snd_cmd_mode_confirm, r5
    jsr @r9
    mov #0x0, r4
    bra     .L_epilogue
    nop
.L_state3_check_course:
    mov r4, r0
    cmp/eq #0x5D, r0
    bt      .L_handle_course_confirm
    bra     .L_epilogue
    nop
.L_handle_course_confirm:
    mov.l @r14, r3
    mov r13, r7
    add #0x1, r3
    add #0x68, r7
    mov.l r3, @r14
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_060129a4, r3
    mov.w   DAT_060129a6, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r12
    mov #0x8, r4
    mov.l   .L_snd_cmd_course_confirm, r5
    jsr @r9
    mov #0x0, r4
    bra     .L_epilogue
    nop

    .global DAT_0601299a
DAT_0601299a:
    .2byte  0x0088                          /* replay_struct offset: default item list */

    .global DAT_0601299c
DAT_0601299c:
    .2byte  0x4000                          /* base display data offset */

    .global DAT_0601299e
DAT_0601299e:
    .2byte  0x061C                          /* display cmd: selection slot 1 */

    .global DAT_060129a0
DAT_060129a0:
    .2byte  0x069C                          /* display cmd: selection slot 2 */

    .global DAT_060129a2
DAT_060129a2:
    .2byte  0x071C                          /* display cmd: selection slot 3 */

    .global DAT_060129a4
DAT_060129a4:
    .2byte  0x3000                          /* overlay base offset */

    .global DAT_060129a6
DAT_060129a6:
    .2byte  0x0626                          /* display cmd: overlay layer */
.L_mask_nibble3:
    .4byte  0x0000F000                      /* nibble 3 mask for display element */
.L_snd_cmd_menu_select:
    .4byte  0xAE1122FF                      /* sound cmd: menu selection confirm */
.L_ptr_lap_count:
    .4byte  sym_06078654                    /* lap count (byte) */
.L_ptr_car_array_base_b:
    .4byte  sym_0607E944                    /* car array base pointer (dup) */
.L_ptr_yaw_angle_store:
    .4byte  sym_06063EF0                    /* camera yaw angle storage */
.L_snd_cmd_mode_confirm:
    .4byte  0xAE1123FF                      /* sound cmd: mode selection confirm */
.L_snd_cmd_course_confirm:
    .4byte  0xAE1124FF                      /* sound cmd: course selection confirm */
.L_state4_race_start:
    mov r4, r0
    cmp/eq #0x61, r0
    bf      .L_epilogue
    mov.l @r14, r3
    add #0x1, r3
    mov.l r3, @r14
    mov.w   DAT_06012a92, r7
    add r13, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_06012a94, r3
    mov.w   .L_disp_cmd_elem_a, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r12
    mov #0x8, r4
    mov.l   .L_snd_cmd_race_start, r5
    jsr @r9
    mov #0x0, r4
    mov #0x14, r3
    mov.l   .L_ptr_countdown_timer, r2
    mov.w r3, @r2
    mov #0x1, r3
    mov.l   .L_ptr_race_ready_flag, r2
    mov.b r3, @r2
    bra     .L_epilogue
    nop
.L_state19_cleanup:
    mov.l   .L_fn_disp_elem_render, r14
    mov r11, r7
    mov r10, r6
    mov.w   .L_disp_cmd_elem_a, r5
    jsr @r14
    mov #0x8, r4
    mov r11, r7
    mov r10, r6
    mov.w   .L_disp_cmd_elem_b, r5
    jsr @r14
    mov #0x8, r4
    mov r11, r7
    mov r10, r6
    mov.w   .L_disp_cmd_elem_c, r5
    jsr @r14
    mov #0x8, r4
    mov r11, r7
    mov.l   .L_mask_nibble3_b, r6
    mov.w   .L_disp_cmd_elem_d, r5
    jsr @r8
    mov #0x8, r4
    mov r10, r6
    mov.w   .L_disp_cmd_elem_e, r5
    mov.l   .L_ptr_text_sprite_data, r7
    jsr @r14
    mov #0xC, r4
    mov.l   .L_ptr_text_sprite_data, r7
    mov r10, r6
    mov.w   .L_disp_cmd_elem_f, r5
    jsr @r14
    mov #0xC, r4
    mov #0x0, r4
    mov.l   .L_ptr_prev_scroll_b, r3
    mov.l r4, @r3
    exts.b r4, r4
    mov.l   .L_ptr_replay_mode_flag, r3
    mov.b r4, @r3
    bra     .L_epilogue
    nop
.L_default_inc_counter:
    mov.l @r14, r2
    add #0x1, r2
    bra     .L_epilogue
    mov.l r2, @r14
.L_state_dispatch:
    cmp/eq #0x0, r0
    bf      .L_chk_state1
    bra     .L_state0_draw_items
    nop
.L_chk_state1:
    cmp/eq #0x1, r0
    bf      .L_chk_state2
    bra     .L_state1_check_input
    nop
.L_chk_state2:
    cmp/eq #0x2, r0
    bf      .L_chk_state3
    bra     .L_state2_check_mode
    nop
.L_chk_state3:
    cmp/eq #0x3, r0
    bf      .L_chk_state4_or_19
    bra     .L_state3_check_course
    nop
.L_chk_state4_or_19:
    cmp/eq #0x4, r0
    bt      .L_state4_race_start
    cmp/eq #0x13, r0
    bt      .L_state19_cleanup
    bra     .L_default_inc_counter
    nop
.L_epilogue:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_06012a92
DAT_06012a92:
    .2byte  0x0080                          /* replay_struct offset: race start list */

    .global DAT_06012a94
DAT_06012a94:
    .2byte  0x3000                          /* overlay base offset */
.L_disp_cmd_elem_a:
    .2byte  0x0520                          /* display cmd: cleanup elem A */
.L_disp_cmd_elem_b:
    .2byte  0x0620                          /* display cmd: cleanup elem B */
.L_disp_cmd_elem_c:
    .2byte  0x0720                          /* display cmd: cleanup elem C */
.L_disp_cmd_elem_d:
    .2byte  0x0820                          /* display cmd: cleanup elem D (masked) */
.L_disp_cmd_elem_e:
    .2byte  0x0880                          /* display cmd: cleanup text elem E */
.L_disp_cmd_elem_f:
    .2byte  0x0980                          /* display cmd: cleanup text elem F */
    .2byte  0xFFFF                          /* alignment padding */
.L_snd_cmd_race_start:
    .4byte  0xAE1125FF                      /* sound cmd: race start */
.L_ptr_countdown_timer:
    .4byte  sym_06086056                    /* countdown timer (16-bit) */
.L_ptr_race_ready_flag:
    .4byte  sym_0608605A                    /* race ready flag (byte) */
.L_fn_disp_elem_render:
    .4byte  sym_060284AE                    /* display element render function */
.L_mask_nibble3_b:
    .4byte  0x0000F000                      /* nibble 3 mask (dup for pool reach) */
.L_ptr_text_sprite_data:
    .4byte  sym_0605AC9C                    /* text/sprite data base */
.L_ptr_prev_scroll_b:
    .4byte  sym_0605B714                    /* previous scroll position (dup) */
.L_ptr_replay_mode_flag:
    .4byte  sym_06078636                    /* replay mode flag (byte) */
