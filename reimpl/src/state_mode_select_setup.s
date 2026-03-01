
    .section .text.FUN_06008CD0


    .global state_mode_select_setup
    .type state_mode_select_setup, @function
state_mode_select_setup:
    sts.l pr, @-r15
    mov.l   .L_pool_06008D3C, r3
    mov.l r14, @r3
    mov.l   .L_pool_06008D40, r3
    jsr @r3
    nop
    mov.l   .L_pool_06008D44, r3
    jsr @r3
    nop
    mov.l   .L_pool_06008D48, r3
    mov.l r14, @r3
    mov.l   .L_pool_06008D4C, r3
    jsr @r3
    nop
    mov.l   .L_pool_06008D50, r3
    jsr @r3
    nop
    mov.w   .L_wpool_06008D38, r2
    mov.l   .L_pool_06008D54, r3
    mov.l r2, @r3
    mov.l   .L_pool_06008D58, r3
    mov #0x5, r2
    mov.l r14, @r3
    mov.l   .L_pool_06008D5C, r3
    mov.l r2, @r3
    mov.l   .L_pool_06008D60, r4
    mov.l   .L_pool_06008D64, r2
    mov.l @r4, r3
    or r2, r3
    mov.l r3, @r4
    mov.l   .L_pool_06008D44, r3
    jsr @r3
    nop
    mov #0x3, r2
    mov.l   .L_pool_06008D48, r3
    mov.l r14, @r3
    mov.l   .L_pool_06008D68, r3
    mov.w r2, @r3
    mov.l   .L_pool_06008D6C, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x1, r0
    bf      .L_06008D32
    mov.l   .L_pool_06008D70, r3
    jsr @r3
    nop
    extu.b r14, r14
    mov.l   .L_pool_06008D6C, r3
    mov.b r14, @r3
.L_06008D32:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
.L_wpool_06008D38:
    .2byte  0x0258                          /* 600 frames (10 seconds at 60fps) */
    .2byte  0xFFFF                          /* alignment padding */
.L_pool_06008D3C:
    .4byte  sym_06078644                    /* &course_type (32-bit) */
.L_pool_06008D40:
    .4byte  sym_060149E0                    /* disable_display — clear bit 15 */
.L_pool_06008D44:
    .4byte  sym_06026CE0                    /* camera_finalize / display update */
.L_pool_06008D48:
    .4byte  sym_06059F44                    /* &animation_state (32-bit) */
.L_pool_06008D4C:
    .4byte  render_coord_transform          /* render coordinate transform */
.L_pool_06008D50:
    .4byte  course_setup_handler            /* course data setup */
.L_pool_06008D54:
    .4byte  sym_0607EBCC                    /* &attract_countdown (32-bit timer) */
.L_pool_06008D58:
    .4byte  sym_06086024                    /* &dma_pending_flag (32-bit) */
.L_pool_06008D5C:
    .4byte  g_game_state                    /* &game_state_dispatch (32-bit) */
.L_pool_06008D60:
    .4byte  sym_0605B6D8                    /* &render_mode_flags (32-bit bitmask) */
.L_pool_06008D64:
    .4byte  0x40000000                      /* bit 30 — mode select active flag */
.L_pool_06008D68:
    .4byte  sym_0605A016                    /* &display_mode (16-bit) */
.L_pool_06008D6C:
    .4byte  sym_0607864B                    /* &demo_flag_b (byte) */
.L_pool_06008D70:
    .4byte  race_state_pair_1               /* race state teardown */
