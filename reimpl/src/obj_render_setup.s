
    .section .text.FUN_06020E84


    .global obj_render_setup
    .type obj_render_setup, @function
obj_render_setup:
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_render_timer_byte, r10
    mov.l   .L_camera_dir_flip, r11
    mov.l   .L_scene_config_base, r14
    mov.l   .L_render_trigger, r4
    mov.b @r4, r0
    extu.b r0, r0
    tst r0, r0
    bt/s    .L_trigger_cleared
    mov #0x0, r13
    mov #0xA, r3
    mov.b r3, @r10
    extu.b r13, r2
    mov.b r2, @r4
.L_trigger_cleared:
    mov.b @r10, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_timer_done
    mov.b @r10, r3
    add #-0x1, r3
    mov.b r3, @r10
.L_timer_done:
    mov.l   .L_car_array_base, r2
    mov.w   DAT_06020f2e, r0
    mov.l @r2, r2
    mov.l @(r0, r2), r3
    mov.l   .L_prev_car_state, r2
    mov.l @r2, r2
    cmp/eq r2, r3
    bt      .L_view_dispatch_done
    mov.l   .L_secondary_proc_flag, r2
    mov.b @r2, r2
    tst r2, r2
    bf      .L_view_dispatch_done
    mov.w   .L_vram_dest_offset, r9
    mov.l   .L_scene_tile_table, r12
    mov.l   .L_car_array_base, r0
    mov.l @r0, r0
    mov.w   DAT_06020f2e, r1
    mov.l @(r0, r1), r0
    bra     .L_view_mode_dispatch
    and #0xCC, r0
.L_view_replay:
    mov r12, r7
    mov r9, r6
    add #0x60, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.l @r15, r5
    mov.l   .L_fn_tile_rect_blit, r3
    mov.l @r5, r5
    jsr @r3
    mov #0x4, r4
    bra     .L_view_dispatch_done
    nop
.L_view_rear:
    mov.b @r11, r0
    tst r0, r0
    bf      .L_rear_slot_a
    bra     .L_rear_compute_src
    mov #0xB, r7
.L_rear_slot_a:
    mov #0xA, r7
.L_rear_compute_src:
    shll2 r7
    mov.b @r11, r0
    shll r7
    add r12, r7
    mov.l @(4, r7), r7
    tst r0, r0
    bf/s    .L_rear_dest_slot_a
    mov r9, r6
    bra     .L_rear_dest_slot_b
    mov #0xB, r5
.L_rear_dest_slot_a:
    mov #0xA, r5
.L_rear_dest_slot_b:
    shll2 r5
    mov.l   .L_fn_tile_rect_blit, r3
    shll r5
    add r12, r5
    mov.l @r5, r5
    jsr @r3
    mov #0x4, r4
    bra     .L_view_dispatch_done
    nop
.L_view_cockpit:
    mov.b @r11, r0
    tst r0, r0
    bf      .L_cockpit_slot_b
    bra     .L_cockpit_compute_src
    mov #0xA, r7

    .global DAT_06020f2e
DAT_06020f2e:
    .2byte  0x0214                          /* car state struct view mode offset */
.L_vram_dest_offset:
    .2byte  0x0900                          /* VRAM destination offset for tile blit */
    .2byte  0xFFFF                          /* padding */
.L_render_timer_byte:
    .4byte  sym_06089594                    /* render countdown timer (byte) */
.L_camera_dir_flip:
    .4byte  sym_06078663                    /* camera direction flip flag (byte) */
.L_scene_config_base:
    .4byte  sym_06087C84                    /* scene config struct base */
.L_render_trigger:
    .4byte  sym_06089595                    /* render trigger flag (byte) */
.L_car_array_base:
    .4byte  sym_0607E944                    /* car array base pointer */
.L_prev_car_state:
    .4byte  sym_06089598                    /* previous car state (for change detect) */
.L_secondary_proc_flag:
    .4byte  sym_06083255                    /* secondary SH-2 processing flag */
.L_scene_tile_table:
    .4byte  sym_06063750                    /* scene tile config table */
.L_fn_tile_rect_blit:
    .4byte  sym_06028400                    /* tile_rect_blit function */
.L_cockpit_slot_b:
    mov #0xB, r7
.L_cockpit_compute_src:
    shll2 r7
    mov.b @r11, r0
    shll r7
    add r12, r7
    mov.l @(4, r7), r7
    tst r0, r0
    bf/s    .L_cockpit_dest_slot_b
    mov r9, r6
    bra     .L_cockpit_dest_slot_a
    mov #0xA, r5
.L_cockpit_dest_slot_b:
    mov #0xB, r5
.L_cockpit_dest_slot_a:
    shll2 r5
    mov.l   .L_fn_tile_rect_blit_b, r3
    shll r5
    add r12, r5
    mov.l @r5, r5
    jsr @r3
    mov #0x4, r4
    bra     .L_view_dispatch_done
    nop
.L_view_default:
    mov r12, r7
    mov r9, r6
    add #0x48, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.l @r15, r5
    mov.l   .L_fn_tile_rect_blit_b, r3
    mov.l @r5, r5
    jsr @r3
    mov #0x4, r4
    bra     .L_view_dispatch_done
    nop
.L_view_mode_dispatch:
    cmp/eq #0x0, r0
    bt      .L_view_default
    cmp/eq #0x44, r0
    bt      .L_view_cockpit
    mov.w   .L_view_mode_rear, r1
    cmp/eq r1, r0
    bt      .L_view_rear
    mov.w   DAT_06020fc8, r1
    cmp/eq r1, r0
    bt      .L_view_replay
.L_view_dispatch_done:
    mov.l   .L_car_array_base_b, r2
    mov.w   DAT_06020fca, r0
    mov.l   .L_cur_car_state_store, r1
    mov.l @r2, r2
    mov.l @(r0, r2), r3
    mov.l r3, @r1
    mov.l   .L_game_state_flag, r0
    mov.l @r0, r0
    cmp/eq #0x1, r0
    bt      .L_active_race
    bra     .L_early_return
    nop
.L_view_mode_rear:
    .2byte  0x0088                          /* view mode: rear-view mirror */

    .global DAT_06020fc8
DAT_06020fc8:
    .2byte  0x00CC                          /* view mode: replay camera */

    .global DAT_06020fca
DAT_06020fca:
    .2byte  0x0214                          /* car state struct view mode offset (dup) */
.L_fn_tile_rect_blit_b:
    .4byte  sym_06028400                    /* tile_rect_blit function (pool B copy) */
.L_car_array_base_b:
    .4byte  sym_0607E944                    /* car array base pointer (pool B copy) */
.L_cur_car_state_store:
    .4byte  sym_06089598                    /* current car state store (for secondary) */
.L_game_state_flag:
    .4byte  sym_06063E20                    /* game state flag (1 = active race) */
.L_active_race:
    mov r13, r12
    mov r13, r6
    mov.b @r10, r7
    mov #0x60, r0
    mov.l   .L_heading_lookup_table, r3
    mov.l   .L_car_array_base_c, r4
    extu.b r7, r7
    mov.l @r4, r4
    shll2 r7
    mov.l @(r0, r4), r4
    add r3, r7
    shar r4
    mov.b @r11, r0
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    shar r4
    tst r0, r0
    bt/s    .L_heading_positive
    mov.l @r7, r7
    neg r4, r4
.L_heading_positive:
    mov.w   DAT_06021098, r3
    cmp/ge r3, r4
    bt      .L_clamp_step_to_zero
    mov.w   DAT_0602109a, r3
    cmp/gt r3, r4
    bf      .L_clamp_step_to_zero
    mov r13, r4
.L_clamp_step_to_zero:
    mov.w   DAT_0602109c, r0
    mov.l r13, @(r0, r14)
    extu.b r13, r5
.L_coord_fill_loop:
    add r4, r12
    extu.b r5, r3
    mov r8, r2
    sub r4, r6
    mov r12, r1
    sub r3, r2
    add r7, r1
    shll2 r2
    mov.w   DAT_0602109e, r3
    add r14, r3
    add r3, r2
    extu.b r5, r3
    mov.l r1, @r2
    shll2 r3
    add #0x1, r5
    mov r6, r1
    mov.w   DAT_0602109e, r2
    add r7, r1
    add r14, r2
    add r2, r3
    add #0x58, r3
    mov #0x16, r2
    mov.l r1, @r3
    extu.b r5, r3
    cmp/ge r2, r3
    bf      .L_coord_fill_loop
    mov.l   .L_fn_cmd_slot_write, r3
    jsr @r3
    mov #0x8, r4
    mov.l   .L_scene_buf_init_arg, r4
    mov.l   .L_fn_scene_buf_init, r3
    jsr @r3
    nop
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    mov.l   .L_fn_cmd_queue_commit, r3
    jmp @r3
    mov.l @r15+, r14
.L_early_return:
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

    .global DAT_06021098
DAT_06021098:
    .2byte  0x1000                          /* heading step positive clamp (+4096) */

    .global DAT_0602109a
DAT_0602109a:
    .2byte  0xF000                          /* heading step negative clamp (-4096 sign-ext) */

    .global DAT_0602109c
DAT_0602109c:
    .2byte  0x1868                          /* config clear field offset */

    .global DAT_0602109e
DAT_0602109e:
    .2byte  0x1810                          /* scene coord array offset in config */
.L_heading_lookup_table:
    .4byte  sym_0604D3E0                    /* heading-to-Y lookup table (indexed by timer) */
.L_car_array_base_c:
    .4byte  sym_0607E944                    /* car array base pointer (pool C copy) */
.L_fn_cmd_slot_write:
    .4byte  sym_0603850C                    /* cmd_slot_write (command queue channel write) */
.L_scene_buf_init_arg:
    .4byte  sym_06087C84                    /* scene config base (arg for scene_buffer_init) */
.L_fn_scene_buf_init:
    .4byte  scene_buffer_init               /* scene buffer initialization function */
.L_fn_cmd_queue_commit:
    .4byte  sym_06038520                    /* cmd_queue_commit (signal command ready) */
