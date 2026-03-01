
    .section .text.FUN_0601A1BA


    .global start_light_ctrl
    .type start_light_ctrl, @function
start_light_ctrl:
    mov.l r14, @-r15
    mov.l r13, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD3, 0x21    /* mov.l .L_light_state, r3 */
    mov.w @r3, r2
    extu.w r2, r2
    mov.w   .L_light_bits_mask, r3
    and r3, r2
    tst r2, r2
    bt/s    .L_check_anim_phase
    mov #0x0, r14
    .byte   0xD4, 0x1B    /* mov.l .L_pool_frame_ctr_a, r4 */
    mov.b @r4, r3
    add #0x1, r3
    mov.b r3, @r4
    .byte   0xD4, 0x1C    /* mov.l .L_frame_ctr_b, r4 */
    mov.b @r4, r2
    add #0x1, r2
    mov.b r2, @r4
    .byte   0xD2, 0x1B    /* mov.l .L_reset_byte, r2 */
    mov.b r14, @r2
    .byte   0xD2, 0x1B    /* mov.l .L_timer_word, r2 */
    mov.l r14, @r2
    .byte   0xD4, 0x1B    /* mov.l .L_ctrl_flags, r4 */
    .byte   0xD1, 0x1B    /* mov.l .L_sign_bit, r1 */
    .byte   0xD3, 0x1C    /* mov.l .L_fn_state_handler, r3 */
    mov.l @r4, r2
    or r1, r2
    jsr @r3
    mov.l r2, @r4
    mov #0x1, r2
    .byte   0xD3, 0x1A    /* mov.l .L_active_flag, r3 */
    mov.b r2, @r3
.L_check_anim_phase:
    mov #0x8, r3
    .byte   0xDD, 0x19    /* mov.l .L_anim_phase, r13 */
    mov.b @r13, r2
    extu.b r2, r2
    cmp/ge r3, r2
    bt      .L_late_anim_phase
    .byte   0xD7, 0x18    /* mov.l .L_vdp1_table_early, r7 */
    mov.w   .L_vdp1_offset, r6
    .byte   0xD3, 0x18    /* mov.l .L_anim_data, r3 */
    mov.l r3, @r15
    mov r3, r5
    add #0xD, r5
    add #0xC, r3
    mov.b @r5, r5
    mov.b @r3, r3
    extu.b r5, r5
    extu.b r3, r3
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    add #0xD, r5
    shll r5
    mov #0xC, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    .byte   0xD3, 0x0F    /* mov.l .L_fn_vdp1_draw, r3 */
    jmp @r3
    mov.l @r15+, r14
.L_light_bits_mask:
    .2byte  0x0600                        /* traffic light state bits 10:9 */
.L_vdp1_offset:
    .2byte  0x0090                        /* VDP1 command table offset */
    .2byte  0xFFFF
.L_pool_frame_ctr_a:
    .4byte  sym_06085FF2               /* frame counter A (byte) */
    .4byte  sym_0605D280               /* (adjacent data) */
.L_light_state:
    .4byte  sym_06063D9A               /* traffic light state register (16-bit) */
.L_frame_ctr_b:
    .4byte  sym_06085FF3               /* frame counter B (byte) */
.L_reset_byte:
    .4byte  sym_0605D245               /* animation reset byte */
.L_timer_word:
    .4byte  sym_06059F44               /* animation timer (32-bit, cleared on change) */
.L_ctrl_flags:
    .4byte  sym_0605B6D8               /* control flags (sign bit = state change) */
.L_sign_bit:
    .4byte  0x80000000                  /* sign bit / negative flag */
.L_fn_state_handler:
    .4byte  sym_06026CE0               /* light state change handler */
.L_active_flag:
    .4byte  sym_06085FF1               /* light active flag (byte, 1 = active) */
.L_anim_phase:
    .4byte  sym_0605D242               /* animation phase counter (byte, 0-16+) */
.L_vdp1_table_early:
    .4byte  sym_06049E48               /* VDP1 display table (early phase) */
.L_anim_data:
    .4byte  sym_06049AFC               /* animation data struct (sprite indices) */
.L_fn_vdp1_draw:
    .4byte  sym_060284AE               /* VDP1 sprite draw function */
.L_late_anim_phase:
    .byte   0xD7, 0x25    /* mov.l .L_vdp1_table_late, r7 */
    .byte   0x96, 0x48    /* mov.w .L_wpool_0601A30E, r6 */
    .byte   0xD2, 0x25    /* mov.l .L_anim_data_late, r2 */
    mov.l @r7, r7
    mov r2, r5
    mov r2, r3
    mov.l r2, @r15
    add #0xD, r5
    add #0xC, r3
    mov.b @r5, r5
    mov.b @r3, r3
    extu.b r5, r5
    extu.b r3, r3
    shll2 r5
    shll2 r5
    shll2 r5
    add r3, r5
    add #0xD, r5
    .byte   0xD3, 0x1E    /* mov.l .L_fn_vdp1_draw_late, r3 */
    shll r5
    jsr @r3
    mov #0xC, r4
    mov.b @r13, r2
    mov #0x10, r3
    extu.b r2, r2
    cmp/gt r3, r2
    bf      .L_epilogue
    extu.b r14, r3
    mov.b r3, @r13
.L_epilogue:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
