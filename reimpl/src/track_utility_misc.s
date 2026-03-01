
   .section .text.FUN_060185D8


   .global track_utility_misc
   .type track_utility_misc, @function
track_utility_misc:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    mov.l   .L_game_mode, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x3, r0
    bf      .L_skip_camera_setup
    mov.l   .L_fn_camera_init, r3
    jsr @r3
    nop
    mov.l   .L_camera_param_table, r14
    mov.l   .L_fn_camera_pos, r3
    mov.l @(8, r14), r6
    mov.l @(4, r14), r5
    jsr @r3
    mov.l @r14, r4
    mov.w   DAT_06018660, r4
    mov.l   .L_fn_rot_y, r3
    jsr @r3
    nop
    mov.w   .L_vec_copy_size, r5
    mov.l   .L_wram_low, r2
    mov.l   .L_wram_offset_a, r3
    mov r2, r4
    add r3, r4
    mov.l   .L_fn_vec_copy, r3
    jsr @r3
    mov.l r2, @r15
    mov.w   .L_vec_scale_size, r6
    mov.l   .L_scale_factor, r5
    mov.l @r15, r4
    mov.l   .L_wram_offset_b, r2
    mov.l   .L_fn_vec_scale, r3
    mov.w @r5, r5
    jsr @r3
    add r2, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l   .L_fn_camera_finalize, r3
    jmp @r3
    mov.l @r15+, r14
.L_skip_camera_setup:
    add #0x4, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14

    .global sym_06018634
sym_06018634:
    mov.l   .L_scroll_pos_a, r6
    mov.l   .L_scroll_pos_b, r5
    mov #0x0, r4
    mov.l   .L_race_end_state, r0
    bra     .L_end_state_dispatch
    mov.l @r0, r0
.L_state0_entry:
    bra     .L_clear_all_scroll_regs
    nop
.L_state1_entry:
    extu.w r4, r2
    mov.l   .L_scroll_offset_a, r3
    mov.w r2, @r3
    extu.w r4, r1
    mov.l   .L_scroll_offset_b, r3
    mov.w r1, @r3
    extu.w r4, r0
    bra     .L_clear_pos_b_then_a
    mov.w r0, @r5
.L_state2_entry:
    extu.w r4, r2
    mov.w r2, @r5
.L_clear_pos_b_then_a:
    extu.w r4, r4
    bra     .L_done_scroll_reset
    mov.w r4, @r6

    .global DAT_06018660
DAT_06018660:
    .2byte  0x38E3                        /* fixed rotation angle for track camera */
.L_vec_copy_size:
    .2byte  0x0178                        /* vector copy byte count (376 bytes) */
.L_vec_scale_size:
    .2byte  0x0145                        /* vector scale byte count (325 bytes) */
    .2byte  0xFFFF
.L_game_mode:
    .4byte  sym_06083254               /* game rendering mode (byte) */
.L_fn_camera_init:
    .4byte  sym_06026DBC               /* camera state initialization */
.L_camera_param_table:
    .4byte  sym_06048140               /* camera position parameters (X/Y/Z) */
.L_fn_camera_pos:
    .4byte  sym_06026E2E               /* set camera base position */
.L_fn_rot_y:
    .4byte  mat_rot_y                  /* Y-axis rotation */
.L_wram_low:
    .4byte  0x00200000                  /* Work RAM Low base */
.L_wram_offset_a:
    .4byte  0x000BABE0                  /* WRAM offset A (vec copy dest) */
.L_fn_vec_copy:
    .4byte  sym_06031D8C               /* vector copy function */
.L_scale_factor:
    .4byte  sym_06089E98               /* per-mode scale factor (16-bit) */
.L_wram_offset_b:
    .4byte  0x000BBD80                  /* WRAM offset B (vec scale dest) */
.L_fn_vec_scale:
    .4byte  sym_06031A28               /* scaled vector copy function */
.L_fn_camera_finalize:
    .4byte  sym_06026DF8               /* camera state finalization */
.L_scroll_pos_a:
    .4byte  sym_0605BE38               /* scroll position register A (16-bit) */
.L_scroll_pos_b:
    .4byte  sym_0605BE36               /* scroll position register B (16-bit) */
.L_race_end_state:
    .4byte  sym_0607EAD8               /* race end state (0/1/2 dispatch) */
.L_scroll_offset_a:
    .4byte  sym_0605BE1C               /* scroll offset A (16-bit) */
.L_scroll_offset_b:
    .4byte  sym_0605BE1E               /* scroll offset B (16-bit) */
.L_end_state_dispatch:
    cmp/eq #0x0, r0
    bt      .L_state0_entry
    cmp/eq #0x1, r0
    bt      .L_state1_entry
    cmp/eq #0x2, r0
    bt      .L_state2_entry
.L_done_scroll_reset:
    rts
    nop
.L_clear_all_scroll_regs:
    mov #0x0, r4
    mov.l   .L_scroll_reg_0, r2
    exts.w r4, r0
    mov.w r4, @r2
    mov.l   .L_scroll_reg_1, r2
    mov.w r4, @r2
    mov.l   .L_scroll_reg_2, r2
    mov.w r0, @r2
    mov.l   .L_scroll_reg_3, r2
    exts.w r4, r0
    mov.w r4, @r2
    mov.l   .L_scroll_reg_4, r2
    mov.w r4, @r2
    mov.l   .L_scroll_reg_5, r2
    mov.w r0, @r2
    mov.l   .L_scroll_reg_6, r2
    mov.w r4, @r2
    mov.l   .L_scroll_reg_7, r2
    rts
    mov.w r4, @r2
    .4byte  0xE400D20D                  /* (embedded sub-fn: raw bytes) */
    .4byte  0x634D604D                  /* clears 4 scroll regs + offsets */
    .4byte  0x2231D20C
    .4byte  0x2241D208
    .4byte  0x2201D308
    .4byte  0x000B2341
.L_scroll_reg_0:
    .4byte  sym_0605BE24               /* scroll register 0 (16-bit) */
.L_scroll_reg_1:
    .4byte  sym_0605BE22               /* scroll register 1 (16-bit) */
.L_scroll_reg_2:
    .4byte  sym_0605BE20               /* scroll register 2 (16-bit) */
.L_scroll_reg_3:
    .4byte  sym_0605BE2A               /* scroll register 3 (16-bit) */
.L_scroll_reg_4:
    .4byte  sym_0605BE26               /* scroll register 4 (16-bit) */
.L_scroll_reg_5:
    .4byte  sym_0605BE28               /* scroll register 5 (16-bit) */
.L_scroll_reg_6:
    .4byte  sym_0605BE36               /* scroll register 6 (16-bit) */
.L_scroll_reg_7:
    .4byte  sym_0605BE38               /* scroll register 7 (16-bit) */
    .4byte  sym_0605BE1C               /* (embedded pool: scroll offset A) */
    .4byte  sym_0605BE1E               /* (embedded pool: scroll offset B) */
    .4byte  0xE400D202                  /* (embedded sub-fn: raw bytes) */
    .4byte  0x2241D202                  /* clears 2 regs + offsets */
    .4byte  0x000B2241
    .4byte  sym_0605BE36               /* (embedded pool: scroll pos B) */
    .4byte  sym_0605BE38               /* (embedded pool: scroll pos A) */
