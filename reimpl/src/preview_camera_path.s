
    .section .text.FUN_0601AAE8


    .global preview_camera_path
    .type preview_camera_path, @function
preview_camera_path:
    sts.l pr, @-r15
    mov.l   .L_status_word, r3
    mov.w @r3, r2
    extu.w r2, r2
    mov.w   .L_preview_button_mask, r3
    and r3, r2
    tst r2, r2
    bt      .L_0601AB48
    mov #0x1E, r3
    mov.l   .L_game_state, r2
    mov #0x1, r5
    mov #0x0, r4
    mov.l r3, @r2
    exts.b r4, r0
    extu.b r5, r3
    mov.l   .L_preview_flag_a, r2
    exts.b r5, r5
    mov.b r3, @r2
    mov.l   .L_preview_flag_b, r2
    mov.b r4, @r2
    mov.l   .L_preview_flag_c, r2
    mov.b r0, @r2
    mov.l   .L_preview_flag_d, r3
    mov.b r5, @r3
    mov.l   .L_preview_flag_e, r3
    mov.b r4, @r3
    extu.b r4, r4
    mov.l   .L_preview_flag_f, r3
    mov.b r4, @r3
    mov.l   .L_fn_layer_config, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_render_flags, r4
    mov.l   .L_fn_render_commit, r3
    mov.l @r4, r0
    or #0x4, r0
    jsr @r3
    mov.l r0, @r4
    mov.l   .L_fn_course_draw, r3
    jsr @r3
    nop
    mov.l   .L_snd_cmd_preview, r5
    mov.l   .L_fn_sound_dispatch, r3
    jsr @r3
    mov #0xF, r4
    mov.l   .L_fn_handler_reset, r3
    jmp @r3
    lds.l @r15+, pr
.L_0601AB48:
    lds.l @r15+, pr
    rts
    nop
.L_preview_button_mask:
    .2byte  0x0700                        /* preview trigger: bits 8-10 */
.L_status_word:
    .4byte  sym_06063D9A               /* input status word (16-bit) */
.L_game_state:
    .4byte  g_game_state               /* game state dispatch value */
.L_preview_flag_a:
    .4byte  sym_0605E0A2               /* preview camera flag A (byte) */
.L_preview_flag_b:
    .4byte  sym_06085FF0               /* preview camera flag B (byte) */
.L_preview_flag_c:
    .4byte  sym_0605D245               /* preview camera flag C (byte) */
.L_preview_flag_d:
    .4byte  sym_06085FF1               /* preview camera flag D (byte) */
.L_preview_flag_e:
    .4byte  sym_06085FF2               /* preview camera flag E (byte) */
.L_preview_flag_f:
    .4byte  sym_06085FF3               /* preview camera flag F (byte) */
.L_fn_layer_config:
    .4byte  sym_0602853E               /* display layer configuration */
.L_render_flags:
    .4byte  sym_0605B6D8               /* render mode flags (32-bit) */
.L_fn_render_commit:
    .4byte  sym_06028560               /* render state commit */
.L_fn_course_draw:
    .4byte  course_select_draw         /* course selection screen draw */
.L_snd_cmd_preview:
    .4byte  0xAE0001FF                  /* sound command: preview music */
.L_fn_sound_dispatch:
    .4byte  sound_cmd_dispatch         /* sound command dispatcher */
.L_fn_handler_reset:
    .4byte  handler_init_reset         /* handler initialization reset */

    .global sym_0601AB8C
sym_0601AB8C:
    .byte   0xD4, 0x21    /* mov.l .L_path_index, r4 */
    .byte   0xD2, 0x22    /* mov.l .L_path_table_base, r2 */
    mov.l @r4, r0
    exts.b r0, r0
    mov r0, r3
    shll2 r0
    shll2 r3
    shll r3
    add r3, r0
    exts.b r0, r0
    .byte   0xD3, 0x1E    /* mov.l .L_path_data_index, r3 */
    add r2, r0
    mov.l @r3, r3
    shll2 r3
    mov.l @(r0, r3), r1
    .byte   0xD3, 0x1D    /* mov.l .L_camera_pos_store, r3 */
    mov.l r1, @r3
    mov.l @r4, r0
    .byte   0xD3, 0x1C    /* mov.l .L_orient_data_index, r3 */
    .byte   0xD2, 0x1D    /* mov.l .L_orient_table, r2 */
    shll r0
    mov.l @r3, r3
    add r3, r0
    shll2 r0
    mov.l @(r0, r2), r4
    mov.l @(4, r4), r1
    .byte   0xD0, 0x1A    /* mov.l .L_camera_orient_store, r0 */
    rts
    mov.l r1, @r0

    .global sym_0601ABC6
sym_0601ABC6:
    mov #0x0, r4
