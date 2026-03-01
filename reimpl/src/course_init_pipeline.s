
    .section .text.FUN_0601A940


    .global course_init_pipeline
    .type course_init_pipeline, @function
course_init_pipeline:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    mov.l   .L_ptr_input_struct, r12
    mov.l   .L_ptr_course_index, r14
    mov.l   .L_fp_half, r5
    mov.l   .L_ptr_course_confirm, r4
    mov.w @(2, r12), r0
    mov r0, r3
    extu.w r3, r3
    and r5, r3
    tst r3, r3
    bt/s    .L_check_dpad_left
    mov #0x0, r13
    mov.b @r14, r3
    add #0x1, r3
    mov.b r3, @r14
    exts.b r13, r2
    bra     .L_clamp_index
    mov.b r2, @r4
.L_check_dpad_left:
    mov.w   DAT_0601a9a4, r6
    mov.w @(2, r12), r0
    mov r0, r2
    extu.w r2, r2
    and r6, r2
    tst r2, r2
    bt      .L_check_held_right
    mov.b @r14, r3
    add #-0x1, r3
    mov.b r3, @r14
    exts.b r13, r2
    bra     .L_clamp_index
    mov.b r2, @r4
.L_check_held_right:
    mov.w @r12, r2
    extu.w r2, r2
    and r5, r2
    tst r2, r2
    bt      .L_check_held_left
    mov.b @r4, r0
    cmp/eq #0x14, r0
    bf      .L_clamp_index
    mov.b @r14, r2
    add #0x1, r2
    mov.b r2, @r14
    exts.b r13, r3
    mov.b r3, @r4
    bra     .L_clamp_index
    nop

    .global DAT_0601a9a4
DAT_0601a9a4:
    .2byte  0x4000
    .2byte  0xFFFF
.L_ptr_input_struct:
    .4byte  g_pad_state
.L_ptr_course_index:
    .4byte  sym_0605D24C
.L_fp_half:
    .4byte  0x00008000                  /* 0.5 (16.16 fixed-point) */
.L_ptr_course_confirm:
    .4byte  sym_0605D243
.L_check_held_left:
    mov.w @r12, r2
    extu.w r2, r2
    and r6, r2
    tst r2, r2
    bt      .L_clamp_index
    mov.b @r4, r0
    cmp/eq #0x14, r0
    bf      .L_clamp_index
    mov.b @r14, r2
    add #-0x1, r2
    mov.b r2, @r14
    exts.b r13, r3
    mov.b r3, @r4
.L_clamp_index:
    mov #0x32, r3
    mov.b @r14, r2
    cmp/ge r3, r2
    bf      .L_check_negative
    exts.b r13, r3
    mov.b r3, @r14
.L_check_negative:
    mov.b @r14, r2
    cmp/pz r2
    bt      .L_check_action_buttons
    mov #0x31, r2
    mov.b r2, @r14
.L_check_action_buttons:
    mov.w @(2, r12), r0
    extu.w r0, r0
    tst #0xF8, r0
    bt      .L_check_start_pressed
    exts.b r13, r3
    mov.b r3, @r14
.L_check_start_pressed:
    mov.w @(2, r12), r0
    mov.w   DAT_0601aa3a, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_update_scroll_layers
    mov.l   .L_ptr_course_active_flag, r0
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_select_variant
    mov.l   .L_fn_sound_ram_upload_a, r3
    jsr @r3
    nop
    mov.l   .L_fn_sound_ram_upload_b, r3
    jsr @r3
    nop
    extu.b r13, r2
    mov.l   .L_ptr_course_active_flag, r3
    mov.b r2, @r3
.L_select_variant:
    mov #0x24, r3
    mov.l   .L_ptr_variant_init_flag, r11
    mov.b @r14, r2
    cmp/ge r3, r2
    bt      .L_index_ge_0x24
    mov.b @r11, r3
    tst r3, r3
    bt      .L_send_sound_cmds
    mov.l   .L_fn_race_variant_e, r3
    jsr @r3
    nop
    exts.b r13, r2
    bra     .L_send_sound_cmds
    mov.b r2, @r11

    .global DAT_0601aa3a
DAT_0601aa3a:
    .2byte  0x0600
.L_ptr_course_active_flag:
    .4byte  sym_06085FF6
.L_fn_sound_ram_upload_a:
    .4byte  sym_06012EC4
.L_fn_sound_ram_upload_b:
    .4byte  sym_06012F00
.L_ptr_variant_init_flag:
    .4byte  sym_06085FF7
.L_fn_race_variant_e:
    .4byte  race_variant_e
.L_index_ge_0x24:
    mov.b @r11, r0
    cmp/eq #0x1, r0
    bt      .L_send_sound_cmds
    mov.l   .L_fn_race_variant_f, r3
    jsr @r3
    nop
    mov #0x1, r2
    mov.b r2, @r11
.L_send_sound_cmds:
    mov.l   .L_snd_init_cmd, r5
    mov.l   .L_fn_sound_cmd_dispatch, r3
    jsr @r3
    mov #0x0, r4
    mov.b @r14, r5
    mov.l   .L_course_snd_cmd_table, r3
    mov.l   .L_fn_sound_cmd_dispatch, r2
    shll2 r5
    add r3, r5
    mov.l @r5, r5
    jsr @r2
    mov #0x0, r4
.L_update_scroll_layers:
    mov.l   .L_fn_geom_render_dispatch, r11
    mov #0x0, r6
    mov.w   DAT_0601aac2, r5
    mov.l   .L_scroll_layer_name, r7
    jsr @r11
    mov #0xC, r4
    mov.l   .L_scroll_layer_name, r7
    mov #0x0, r6
    mov.w   .L_scroll_offset_b, r5
    jsr @r11
    mov #0xC, r4
    mov.b @r14, r7
    mov.l   .L_course_render_params, r3
    mov.l   .L_mask_0xE000, r6
    mov.w   .L_scroll_offset_b, r5
    shll r7
    shll2 r7
    add r3, r7
    mov.l @r7, r7
    jsr @r11
    mov #0xC, r4
    mov.b @r14, r7
    mov.l   .L_course_render_params, r3
    mov.l   .L_mask_0xE000, r6
    mov.w   DAT_0601aac2, r5
    shll r7
    shll2 r7
    add r3, r7
    mov.l @(4, r7), r7
    jsr @r11
    mov #0xC, r4
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14

    .global DAT_0601aac2
DAT_0601aac2:
    .2byte  0x099C
.L_scroll_offset_b:
    .2byte  0x091C
    .2byte  0xFFFF
.L_fn_race_variant_f:
    .4byte  race_variant_f
.L_snd_init_cmd:
    .4byte  0xAE0001FF
.L_fn_sound_cmd_dispatch:
    .4byte  sound_cmd_dispatch
.L_course_snd_cmd_table:
    .4byte  sym_06049CFC
.L_fn_geom_render_dispatch:
    .4byte  sym_060283E0
.L_scroll_layer_name:
    .4byte  sym_06049CDC
.L_course_render_params:
    .4byte  sym_0605D35C
.L_mask_0xE000:
    .4byte  0x0000E000                  /* bits 15:13 mask */
