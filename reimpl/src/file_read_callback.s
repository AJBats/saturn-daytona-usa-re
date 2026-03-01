
    .section .text.FUN_060120CC


    .global file_read_callback
    .type file_read_callback, @function
file_read_callback:
    sts.l pr, @-r15
    mov #0x0, r14
    mov.l   _pool_replay_mode_flag, r2
    mov r14, r6
    mov r14, r5
    mov.b r3, @r2
    mov.l   _pool_menu_scroll_pos, r3
    mov.l r14, @r3
    mov.l   _pool_fn_display_channel_b, r3
    jsr @r3
    mov #0x20, r4
    mov.l   _pool_position_vec_a, r4
    mov.l r14, @r4
    mov.l   .L_fp_eight, r2
    mov.l r2, @(4, r4)
    shlr2 r2
    mov.l   _pool_fp_fifteen_point_two, r3
    mov.l r3, @(8, r4)
    mov.l   _pool_position_vec_b, r4
    mov.l r14, @r4
    mov.l r2, @(4, r4)
    mov r4, r2
    mov.l   _pool_fp_five_point_two, r3
    mov.l r3, @(8, r4)
    mov.l   _pool_position_vec_c, r1
    mov.l   _pool_fn_memcpy_long, r3
    jsr @r3
    mov #0xC, r0
    mov.l   _pool_position_vec_d, r1
    mov.l   _pool_fn_memcpy_long, r3
    jsr @r3
    mov #0xC, r0
    mov.l   _pool_position_vec_e, r1
    mov.l   _pool_fn_memcpy_long, r3
    jsr @r3
    mov #0xC, r0
    mov.w   DAT_0601214e, r2
    extu.b r14, r1
    mov.l   _pool_anim_counter, r3
    mov.w r2, @r3
    exts.w r14, r2
    mov.l   _pool_rotation_angle, r3
    mov.w r2, @r3
    mov.l   _pool_file_read_init_flag, r3
    mov.b r1, @r3
    mov.l   _pool_menu_state_counter, r5
    mov.l   _pool_frame_timer, r4
    mov.l   _pool_race_end_state, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_race_ended
    mov #0x3C, r3
    mov.l r3, @r4
    bra     .L_return
    mov.l r14, @r5
.L_race_ended:
    mov #0x1, r2
    mov.l r2, @r4
    mov #0x14, r3
    mov.l r3, @r5
    lds.l @r15+, pr
    .byte   0xA0, 0xA1    /* bra 0x0601228A (external) */
    mov.l @r15+, r14
.L_return:
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global DAT_0601214e
DAT_0601214e:
    .2byte  0x1000                          /* initial animation counter value */
_pool_replay_mode_flag:
    .4byte  sym_06078636                    /* replay mode flag (byte) */
_pool_menu_scroll_pos:
    .4byte  sym_060788F8                    /* menu scroll position (dword) */
_pool_fn_display_channel_b:
    .4byte  display_channel_b               /* display channel enable function */
_pool_position_vec_a:
    .4byte  sym_060788B4                    /* position vector A: primary HUD element XYZ */
.L_fp_eight:
    .4byte  0x00080000                      /* 8.0 (16.16 fixed-point) */
_pool_fp_fifteen_point_two:
    .4byte  0x000F3333                      /* ~15.2 (16.16 fixed-point) */
_pool_position_vec_b:
    .4byte  sym_060788C0                    /* position vector B: secondary HUD element XYZ */
_pool_fp_five_point_two:
    .4byte  0x00053333                      /* ~5.2 (16.16 fixed-point) */
_pool_position_vec_c:
    .4byte  sym_060788CC                    /* position vector C (initialized as copy of B) */
_pool_fn_memcpy_long:
    .4byte  sym_06035168                    /* memcpy_long(r0=nbytes, r1=dst, r2=src) */
_pool_position_vec_d:
    .4byte  sym_060788D8                    /* position vector D (initialized as copy of B) */
_pool_position_vec_e:
    .4byte  sym_060788E4                    /* position vector E (initialized as copy of B) */
_pool_anim_counter:
    .4byte  sym_060788B0                    /* animation counter (16-bit) */
_pool_rotation_angle:
    .4byte  sym_060788B2                    /* Z rotation angle state (16-bit) */
_pool_file_read_init_flag:
    .4byte  sym_060788F0                    /* file read initialized flag (byte) */
_pool_menu_state_counter:
    .4byte  sym_060788F4                    /* menu state counter (dword) */
_pool_frame_timer:
    .4byte  sym_060788AC                    /* frame timer / state counter (dword) */
_pool_race_end_state:
    .4byte  sym_0607EAD8                    /* race end state (0=racing, nonzero=ended) */

    .global sym_06012198
sym_06012198:
    .byte   0xD0, 0x21    /* mov.l .L_pool_06012220, r0 */
    mov.l @r0, r0
    tst r0, r0
    bt      .L_race_active
    .byte   0xA0, 0x73    /* bra 0x0601228A (external) */
    nop
.L_race_active:
    .byte   0xA3, 0x1C    /* bra 0x060127E0 (external) */
    nop
