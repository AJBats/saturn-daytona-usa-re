
    .section .text.FUN_06008CD0


    .global state_mode_select_setup
    .type state_mode_select_setup, @function
state_mode_select_setup:
    sts.l pr, @-r15
    mov.l   _pool_course_type_ptr, r3
    mov.l r14, @r3
    mov.l   _pool_fn_disable_display, r3
    jsr @r3
    nop
    mov.l   _pool_fn_camera_finalize, r3
    jsr @r3
    nop
    mov.l   _pool_anim_state_ptr, r3
    mov.l r14, @r3
    mov.l   _pool_fn_render_coord, r3
    jsr @r3
    nop
    mov.l   _pool_fn_course_setup, r3
    jsr @r3
    nop
    mov.w   _wpool_timer_600, r2
    mov.l   _pool_countdown_ptr, r3
    mov.l r2, @r3
    mov.l   _pool_dma_pending_ptr, r3
    mov #0x5, r2
    mov.l r14, @r3
    mov.l   _pool_game_state_ptr, r3
    mov.l r2, @r3
    mov.l   _pool_render_flags_ptr, r4
    mov.l   _pool_mode_select_bit, r2
    mov.l @r4, r3
    or r2, r3
    mov.l r3, @r4
    mov.l   _pool_fn_camera_finalize, r3
    jsr @r3
    nop
    mov #0x3, r2
    mov.l   _pool_anim_state_ptr, r3
    mov.l r14, @r3
    mov.l   _pool_display_mode_ptr, r3
    mov.w r2, @r3
    mov.l   _pool_demo_flag_b_ptr, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_06008D32
    mov.l   _pool_fn_race_state_pair, r3
    jsr @r3
    nop
    extu.b r14, r14
    mov.l   _pool_demo_flag_b_ptr, r3
    mov.b r14, @r3
.L_06008D32:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
_wpool_timer_600:
    .2byte  0x0258                          /* 600 frames (10 seconds at 60fps) */
    .2byte  0xFFFF                          /* alignment padding */
_pool_course_type_ptr:
    .4byte  sym_06078644                    /* &course_type (32-bit) */
_pool_fn_disable_display:
    .4byte  sym_060149E0                    /* disable_display — clear bit 15 */
_pool_fn_camera_finalize:
    .4byte  sym_06026CE0                    /* camera_finalize / display update */
_pool_anim_state_ptr:
    .4byte  sym_06059F44                    /* &animation_state (32-bit) */
_pool_fn_render_coord:
    .4byte  render_coord_transform          /* render coordinate transform */
_pool_fn_course_setup:
    .4byte  course_setup_handler            /* course data setup */
_pool_countdown_ptr:
    .4byte  sym_0607EBCC                    /* &attract_countdown (32-bit timer) */
_pool_dma_pending_ptr:
    .4byte  sym_06086024                    /* &dma_pending_flag (32-bit) */
_pool_game_state_ptr:
    .4byte  g_game_state                    /* &game_state_dispatch (32-bit) */
_pool_render_flags_ptr:
    .4byte  sym_0605B6D8                    /* &render_mode_flags (32-bit bitmask) */
_pool_mode_select_bit:
    .4byte  0x40000000                      /* bit 30 — mode select active flag */
_pool_display_mode_ptr:
    .4byte  sym_0605A016                    /* &display_mode (16-bit) */
_pool_demo_flag_b_ptr:
    .4byte  sym_0607864B                    /* &demo_flag_b (byte) */
_pool_fn_race_state_pair:
    .4byte  race_state_pair_1               /* race state teardown */
