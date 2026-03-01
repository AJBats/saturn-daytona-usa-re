
    .section .text.FUN_06025478


    .global scene_process_b
    .type scene_process_b, @function
scene_process_b:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    mov.l r9, @-r15
    mov.l r8, @-r15
    sts.l pr, @-r15
    add #-0x18, r15
    mov.w   DAT_060254de, r8
    mov.l   .L_render_base_table, r12
    mov.l   .L_fn_layer_setup, r14
    mov r8, r11
    mov.l r4, @(4, r15)
    mov.l   .L_game_state_byte, r4
    mov.w   .L_text_pos_offset, r13
    mov.w   .L_slot_data_offset, r10
    mov.b @r4, r0
    extu.b r0, r0
    cmp/eq #0x4, r0
    bf/s    .L_not_state4
    add #0xC, r11
    mov.l   .L_str_press_start, r7
    mov r13, r5
    mov.l   .L_fn_text_render, r3
    mov.w   .L_text_len, r6
    jsr @r3
    mov #0x8, r4
    mov r12, r7
    add r10, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_060254e6, r6
    mov.l @r15, r5
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    bra     .L_after_text_layers
    nop
.L_not_state4:
    mov.b @r4, r0
    extu.b r0, r0
    cmp/eq #0x5, r0
    bf      .L_default_text
    mov.l   .L_str_press_ac_decide, r7
    mov r13, r5
    mov.l   .L_fn_text_render, r3
    mov.w   .L_text_len, r6
    jsr @r3
    mov #0x8, r4
    bra     .L_render_two_layers
    nop

    .global DAT_060254de
DAT_060254de:
    .2byte  0x00A8                       /* render param (variant B) */
.L_text_pos_offset:
    .2byte  0x0C08                       /* text screen position */
.L_slot_data_offset:
    .2byte  0x0590                       /* offset into render_base for slot data */
.L_text_len:
    .2byte  0x0090                       /* text string length param */

    .global DAT_060254e6
DAT_060254e6:
    .2byte  0x0C3E                       /* layer param for state-4 geometry */
.L_render_base_table:
    .4byte  sym_06063750                 /* render base table (8-byte stride) */
.L_fn_layer_setup:
    .4byte  sym_06028400                 /* layer setup / geometry dispatch */
.L_game_state_byte:
    .4byte  sym_06061198                 /* game state byte (render phase) */
.L_str_press_start:
    .4byte  sym_060590B8                 /* "PRESS START TO EXIT" */
.L_fn_text_render:
    .4byte  sym_060284AE                 /* text renderer / geometry dispatch */
.L_str_press_ac_decide:
    .4byte  sym_060590E0                 /* "PRESS A OR C TO DECIDE  B TO CANCEL" */
.L_default_text:
    mov.l   .L_str_press_ac_alt, r7
    mov r13, r5
    mov.l   .L_fn_text_render_2, r3
    mov.w   .L_text_len_2, r6
    jsr @r3
    mov #0x8, r4
.L_render_two_layers:
    mov r12, r13
    mov.w   DAT_060255ce, r6
    add r10, r13
    mov.l @(4, r13), r7
    mov.l @r13, r5
    jsr @r14
    mov #0x8, r4
    mov.l @(4, r13), r7
    mov.w   DAT_060255d0, r6
    mov.l @r13, r5
    jsr @r14
    mov #0x8, r4
.L_after_text_layers:
    mov.l @(4, r15), r7
    mov.l   .L_type_name_table, r3
    mov.w   .L_text_len_2, r6
    mov.w   DAT_060255d2, r5
    mov.l   .L_fn_text_render_2, r2
    shll2 r7
    shll r7
    add r3, r7
    jsr @r2
    mov #0x8, r4
    mov.w   DAT_060255d4, r7
    mov #0x10, r6
    add r12, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_060255d6, r3
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov.w   DAT_060255d8, r7
    add r12, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_060255da, r3
    mov.w   .L_geom_param_a, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov.w   DAT_060255de, r7
    add r12, r7
    mov.l r7, @r15
    mov.l @(4, r7), r7
    mov.w   DAT_060255da, r3
    mov.w   .L_geom_param_b, r6
    mov.l @r15, r5
    add r3, r7
    mov.l @r5, r5
    jsr @r14
    mov #0x8, r4
    mov #0x0, r13
    mov.l @(4, r15), r10
    shll2 r10
    mov.l   .L_render_record_table, r3
    add r3, r10
.L_slot_loop_top:
    extu.w r8, r5
    mov.l   .L_fn_car_physics_final, r3
    jsr @r3
    extu.w r13, r4
    mov r13, r2
    mov.l @r10, r3
    shll2 r2
    shll r2
    add r3, r2
    mov.w @(6, r2), r0
    mov r0, r2
    extu.w r2, r2
    cmp/eq r11, r2
    bf      .L_process_slot
    mov.l   .L_game_state_byte_2, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x4, r0
    bt      .L_process_slot
    mov.l   .L_game_state_byte_2, r0
    mov.b @r0, r0
    extu.b r0, r0
    cmp/eq #0x5, r0
    bf      .L_next_slot
.L_process_slot:
    mov r13, r9
    mov.l @r10, r3
    shll2 r9
    shll r9
    add r9, r3
    mov.w @(6, r3), r0
    mov r0, r2
    extu.w r2, r2
    cmp/eq r11, r2
    bt      .L_sentinel_match
    bra     .L_dispatch_render
    mov #0x8, r2
.L_text_len_2:
    .2byte  0x0090                       /* text length param (duplicate) */

    .global DAT_060255ce
DAT_060255ce:
    .2byte  0x0C34                       /* layer A geometry param */

    .global DAT_060255d0
DAT_060255d0:
    .2byte  0x0C4E                       /* layer B geometry param */

    .global DAT_060255d2
DAT_060255d2:
    .2byte  0x02A4                       /* type name text screen position */

    .global DAT_060255d4
DAT_060255d4:
    .2byte  0x0428                       /* render_base offset: layer C entry */

    .global DAT_060255d6
DAT_060255d6:
    .2byte  0x6000                       /* frame data offset for layer C */

    .global DAT_060255d8
DAT_060255d8:
    .2byte  0x0430                       /* render_base offset: layer D entry */

    .global DAT_060255da
DAT_060255da:
    .2byte  0x7000                       /* frame data offset for layers D/E */
.L_geom_param_a:
    .2byte  0x02A0                       /* layer D geometry param */

    .global DAT_060255de
DAT_060255de:
    .2byte  0x0438                       /* render_base offset: layer E entry */
.L_geom_param_b:
    .2byte  0x02B4                       /* layer E geometry param */
    .2byte  0xFFFF                       /* padding */
.L_str_press_ac_alt:
    .4byte  sym_06059104                 /* "PRESS A OR C..." (alt/truncated) */
.L_fn_text_render_2:
    .4byte  sym_060284AE                 /* text renderer (duplicate ref) */
.L_type_name_table:
    .4byte  sym_06058F94                 /* " TYPE A"/" TYPE B"/..." string table */
.L_render_record_table:
    .4byte  sym_06061184                 /* render record ptr table (variant B) */
.L_fn_car_physics_final:
    .4byte  car_physics_final            /* per-car geometry dispatch */
.L_game_state_byte_2:
    .4byte  sym_06061198                 /* game state byte (duplicate ref) */
.L_sentinel_match:
    mov #0x9, r2
.L_dispatch_render:
    extu.w r2, r2
    mov r13, r6
    mov r2, r0
    shll r6
    mov.w r0, @(16, r15)
    mov.l   .L_slot_index_table, r7
    add r9, r7
    mov.l r7, @r15
    mov.l @r7, r7
    shll2 r7
    shll r7
    add r12, r7
    mov.l r7, @(8, r15)
    mov.l @(4, r7), r7
    mov.l   .L_fp_half, r3
    mov.l r6, @(4, r15)
    add r3, r7
    mov.l   .L_dir_table_a, r3
    add r3, r6
    mov.l r6, @(12, r15)
    mov.b @(1, r6), r0
    mov.l @(12, r15), r2
    mov r0, r6
    mov.b @r2, r2
    extu.b r6, r6
    extu.b r2, r2
    shll2 r6
    shll2 r6
    shll2 r6
    add r2, r6
    shll r6
    mov.l @(8, r15), r5
    mov.l @r15, r4
    mov.l @r5, r5
    add #0x4, r4
    mov.l r4, @(20, r15)
    mov.l @r4, r4
    jsr @r14
    shll2 r4
    mov.w @(16, r15), r0
    mov.l @r10, r3
    mov r0, r7
    add r9, r3
    extu.w r7, r7
    mov.w @(6, r3), r0
    shll8 r7
    mov r0, r2
    shll2 r7
    extu.w r2, r3
    shll2 r7
    shll2 r3
    shll r3
    mov r12, r2
    add r3, r2
    mov.l r2, @(8, r15)
    mov.l @(4, r2), r3
    add r3, r7
    mov.l @(4, r15), r6
    mov.l   .L_dir_table_b, r3
    add r3, r6
    mov.l r6, @r15
    mov.b @(1, r6), r0
    mov r0, r6
    extu.b r6, r6
    shll2 r6
    shll2 r6
    shll2 r6
    mov.l @r15, r2
    mov.b @r2, r2
    extu.b r2, r2
    add r2, r6
    shll r6
    mov.l @(8, r15), r5
    mov.l @(20, r15), r4
    mov.l @r5, r5
    mov.l @r4, r4
    jsr @r14
    shll2 r4
.L_next_slot:
    add #0x1, r13
    mov #0x8, r3
    cmp/ge r3, r13
    bt      .L_epilogue
    bra     .L_slot_loop_top
    nop
.L_epilogue:
    add #0x18, r15
    lds.l @r15+, pr
    mov.l @r15+, r8
    mov.l @r15+, r9
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
    .2byte  0xFFFF                       /* padding */
.L_slot_index_table:
    .4byte  sym_0605900C                 /* per-slot render base index table */
.L_fp_half:
    .4byte  0x00008000                   /* 0.5 (16.16 fixed-point) */
.L_dir_table_a:
    .4byte  sym_06059074                 /* direction byte-pair table A (2-byte stride) */
.L_dir_table_b:
    .4byte  sym_06059084                 /* direction byte-pair table B (2-byte stride) */
