
    .section .text.FUN_0600E0C0


    .global car_update_racing
    .type car_update_racing, @function
car_update_racing:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    sts.l macl, @-r15
    mov.l   .L_game_flags, r8
    mov.l   .L_car_array_base, r9
    mov.w   .L_car_struct_size, r10
    mov.l   .L_fp_half, r11
    mov.l   .L_car_struct_ptr, r12
    mov.l   .L_fn_scene_3d, r14
    mov.l   .L_race_end_flag, r0
    mov.l @r0, r0
    tst r0, r0
    bf      .L_epilogue
    bra     .L_loop_cond
    mov #0x1, r13
.L_car_struct_size:
    .2byte  0x0268                        /* car struct size: 616 bytes */
    .4byte  sym_0607E944               /* secondary car struct pointer */
    .4byte  sym_0607EA98               /* total car count */
    .4byte  sym_060786CA               /* car visibility state */
.L_car_struct_ptr:
    .4byte  sym_0607E940               /* pointer to current car struct */
    .4byte  sym_06078B68               /* car additional data table */
    .4byte  sym_0607E948               /* tertiary car struct pointer */
    .4byte  sym_0602DC18               /* car init/setup function A */
    .4byte  sym_06006838               /* car init/setup function B */
    .4byte  sym_060786B8               /* car state flags */
    .4byte  segment_position_track     /* track segment tracking */
.L_fn_scene_3d:
    .4byte  scene_3d_processor         /* 3D scene rendering dispatch */
    .4byte  sym_06063EB0               /* display table entry 0 */
    .4byte  sym_06063E9C               /* display table entry 1 */
    .4byte  sym_06063ED8               /* display table entry 2 */
    .4byte  sym_06063EC4               /* display table entry 3 */
    .4byte  disp_mode_switch           /* display mode finalize */
.L_game_flags:
    .4byte  sym_0607EBC4               /* game state flags (bit 15 = AI mode) */
.L_car_array_base:
    .4byte  sym_06078900               /* car struct array base */
.L_fp_half:
    .4byte  0x00008000                  /* bitmask: bit 15 (AI vs player flag) */
.L_race_end_flag:
    .4byte  sym_0607EAE0               /* race end flag (nonzero = ended) */
.L_loop_body:
    mul.l r10, r13
    mov.l   .L_fn_car_setup, r3
    sts macl, r2
    add r9, r2
    jsr @r3
    mov.l r2, @r12
    mov.l   .L_fn_car_state, r3
    jsr @r3
    nop
    mov.l @r8, r2
    and r11, r2
    tst r2, r2
    bt      .L_player_physics
    .byte   0xB3, 0xD6    /* bsr 0x0600E906 (external) */
    nop
    bra     .L_next_car
    nop
.L_player_physics:
    .byte   0xB2, 0xDC    /* bsr 0x0600E71A (external) */
    nop
    mov.l @r12, r2
    mov r2, r0
    mov.b @(1, r0), r0
    tst #0x80, r0
    bt      .L_next_car
    mov.l   .L_fn_pre_render, r3
    jsr @r3
    nop
    mov.l   .L_disp_table_0, r4
    jsr @r14
    mov #0x0, r5
    mov.l   .L_disp_table_1, r4
    jsr @r14
    mov #0x1, r5
    mov.l   .L_disp_table_2, r4
    jsr @r14
    mov #0x2, r5
    mov.l   .L_disp_table_3, r4
    jsr @r14
    mov #0x3, r5
    mov.l   .L_fn_disp_finalize, r3
    jsr @r3
    mov #0x1, r4
.L_next_car:
    add #0x1, r13
.L_loop_cond:
    mov.l   .L_car_count, r2
    mov.l @r2, r2
    cmp/hs r2, r13
    bf      .L_loop_body
.L_epilogue:
    lds.l @r15+, macl
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF
.L_fn_car_setup:
    .4byte  sym_06030A06               /* per-car initialization */
.L_fn_car_state:
    .4byte  sym_06030EE0               /* per-car state update */
.L_fn_pre_render:
    .4byte  pre_render_transform       /* pre-render 3D transform setup */
.L_disp_table_0:
    .4byte  sym_06063EB0               /* display table entry 0 */
.L_disp_table_1:
    .4byte  sym_06063E9C               /* display table entry 1 */
.L_disp_table_2:
    .4byte  sym_06063ED8               /* display table entry 2 */
.L_disp_table_3:
    .4byte  sym_06063EC4               /* display table entry 3 */
.L_fn_disp_finalize:
    .4byte  sym_0603053C               /* display mode finalize */
.L_car_count:
    .4byte  sym_0607EA98               /* total active car count */
