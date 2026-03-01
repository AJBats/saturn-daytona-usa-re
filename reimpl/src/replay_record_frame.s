
    .section .text.FUN_0601BA50


    .global replay_record_frame
    .type replay_record_frame, @function
replay_record_frame:
    mov.l r14, @-r15
    mov r5, r0
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov r4, r12
    mov.l r10, @-r15
    sts.l pr, @-r15
    add #-0x10, r15
    mov r15, r1
    mov.l   .L_fn_vdp1_draw_pos, r10
    mov.l   .L_replay_state, r11
    add #0xC, r1
    mov.b r0, @(4, r15)
    mov r6, r0
    mov.b r0, @(8, r15)
    mov.l   .L_init_data_src, r2
    mov.l   .L_fn_data_copy, r3
    jsr @r3
    mov #0x4, r0
    mov.l   .L_fn_sprite_draw, r13
    mov.l   .L_model_table, r14
    mov.w   DAT_0601bb3a, r7
    add r14, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.l   .L_model_offset_a, r3
    mov.w   .L_vdp1_off_car_a, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r13
    mov #0xC, r4
    mov.w   DAT_0601bb3e, r7
    add r14, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.l   .L_model_offset_a, r3
    mov.w   DAT_0601bb40, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r13
    mov #0xC, r4
    exts.b r12, r7
    add #0x30, r7
    shll2 r7
    shll r7
    add r14, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.l   .L_model_offset_b, r3
    mov.w   .L_vdp1_off_car_c, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r13
    mov #0xC, r4
    mov.b @(4, r15), r0
    mov r0, r7
    add #0x33, r7
    shll2 r7
    shll r7
    add r14, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.l   .L_model_offset_b, r3
    mov.w   DAT_0601bb44, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r13
    mov #0xC, r4
    exts.b r12, r4
    mov.b @(4, r15), r0
    mov #0xA, r6
    mov.b @r11, r2
    mov r4, r3
    extu.b r2, r2
    shll r4
    shll2 r3
    add r3, r4
    mov r0, r3
    shll r3
    mov.b @(8, r15), r0
    add r3, r4
    add r2, r4
    mov.l   .L_record_table, r3
    shll2 r4
    add r3, r4
    mov.l @r4, r4
    .byte   0xB0, 0x61    /* bsr 0x0601BBCC (external) */
    mov r0, r5
    mov.w   DAT_0601bb46, r7
    add r14, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_0601bb48, r3
    mov.w   DAT_0601bb4a, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r13
    mov #0xC, r4
    exts.b r12, r14
    shll r14
    mov.b @r11, r3
    extu.b r3, r3
    add r3, r14
    shll2 r14
    mov.l   .L_frame_data_table, r2
    add r2, r14
    mov.l @r14, r14
    mov r15, r7
    add #0xC, r7
    bra     .L_pos_elem_render
    nop

    .global DAT_0601bb3a
DAT_0601bb3a:
    .2byte  0x01B0                        /* model table offset: car element A */
.L_vdp1_off_car_a:
    .2byte  0x0290                        /* VDP1 cmd offset: car model A */

    .global DAT_0601bb3e
DAT_0601bb3e:
    .2byte  0x01B8                        /* model table offset: car element B */

    .global DAT_0601bb40
DAT_0601bb40:
    .2byte  0x02AC                        /* VDP1 cmd offset: car model B */
.L_vdp1_off_car_c:
    .2byte  0x0390                        /* VDP1 cmd offset: car A specific */

    .global DAT_0601bb44
DAT_0601bb44:
    .2byte  0x03AC                        /* VDP1 cmd offset: car B specific */

    .global DAT_0601bb46
DAT_0601bb46:
    .2byte  0x01D8                        /* model table offset: overlay entry */

    .global DAT_0601bb48
DAT_0601bb48:
    .2byte  0x6000                        /* model data offset for overlay */

    .global DAT_0601bb4a
DAT_0601bb4a:
    .2byte  0x0C86                        /* VDP1 cmd offset: overlay element */
.L_fn_vdp1_draw_pos:
    .4byte  sym_060284AE               /* VDP1 position element draw */
.L_replay_state:
    .4byte  sym_0605D4F7               /* replay playback state byte */
.L_init_data_src:
    .4byte  sym_0605DF3A               /* replay init data source */
.L_fn_data_copy:
    .4byte  sym_06035228               /* byte/word copy function */
.L_fn_sprite_draw:
    .4byte  sym_06028400               /* sprite/model draw function */
.L_model_table:
    .4byte  sym_06063750               /* model geometry table (8 bytes per entry) */
.L_model_offset_a:
    .4byte  0x0000A000                  /* model data offset A (car elements) */
.L_model_offset_b:
    .4byte  0x00009000                  /* model data offset B (per-car models) */
.L_record_table:
    .4byte  sym_0605DD6C               /* replay record lookup table */
.L_frame_data_table:
    .4byte  sym_0605DE24               /* per-frame animation data table */
.L_pos_elem_render:
    mov #0x60, r6
    mov.w   DAT_0601bbc0, r5
    jsr @r10
    mov #0x8, r4
    mov.b @r14, r3
    extu.b r3, r3
    tst r3, r3
    bt      .L_skip_overlay
    mov r14, r7
    mov #0x60, r6
    mov.w   DAT_0601bbc0, r5
    jsr @r10
    mov #0x8, r4
.L_skip_overlay:
    exts.b r12, r4
    mov.b @r11, r3
    mov.l   .L_frame_data_table_2, r2
    shll r4
    extu.b r3, r3
    add r3, r4
    shll2 r4
    mov.l   .L_fn_anim_transform, r3
    add r2, r4
    mov.l @r4, r4
    jsr @r3
    mov.l @(4, r4), r4
    mov r0, r7
    mov #0x78, r6
    mov.w   .L_vdp1_off_final, r5
    jsr @r10
    mov #0x8, r4
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0601bbc0
DAT_0601bbc0:
    .2byte  0x0CA4                        /* VDP1 cmd offset: position element */
.L_vdp1_off_final:
    .2byte  0x0CB2                        /* VDP1 cmd offset: final indicator */
.L_frame_data_table_2:
    .4byte  sym_0605DE24               /* per-frame data table (dup for reach) */
.L_fn_anim_transform:
    .4byte  anim_frame_transform       /* animation frame transform */
