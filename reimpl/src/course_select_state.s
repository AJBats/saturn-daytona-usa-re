
    .section .text.FUN_060193FE


    .global course_select_state
    .type course_select_state, @function
course_select_state:
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xD2, 0x2B    /* mov.l .L_select_flag_a, r2 — selection flag A */
    mov.b r3, @r2
    extu.b r4, r3
    .byte   0xD2, 0x2A    /* mov.l .L_select_flag_b, r2 — selection flag B */
    mov.b r4, @r2
    .byte   0xD2, 0x2A    /* mov.l .L_select_flag_c, r2 — selection flag C */
    mov.b r0, @r2
    extu.b r4, r0
    .byte   0xD2, 0x2A    /* mov.l .L_select_flag_d, r2 — selection flag D */
    extu.b r4, r4
    mov.b r0, @r2
    .byte   0xD2, 0x29    /* mov.l .L_select_flag_e, r2 — selection flag E */
    mov.b r3, @r2
    .byte   0xD2, 0x29    /* mov.l .L_select_flag_f, r2 — selection flag F */
    mov.b r4, @r2
    .byte   0xD5, 0x29    /* mov.l .L_snd_cmd_select, r5 — 0xAE0003FF */
    .byte   0xD2, 0x2A    /* mov.l .L_fn_sound_dispatch, r2 */
    jsr @r2
    mov #0xF, r4
    .byte   0xDE, 0x29    /* mov.l .L_render_flags, r14 — render mode flags */
    .byte   0xD3, 0x2A    /* mov.l .L_fp_min, r3 — 0x80000000 */
    mov.l @r14, r2
    or r3, r2
    .byte   0xD3, 0x29    /* mov.l .L_fn_camera_finalize, r3 */
    jsr @r3
    mov.l r2, @r14
    .byte   0xD3, 0x28    /* mov.l .L_fn_camera_finalize, r3 */
    jsr @r3
    nop
    .byte   0xBF, 0xA6    /* bsr 0x0601938C (external helper) */
    nop
    .byte   0xD3, 0x26    /* mov.l .L_fn_course_name_render, r3 */
    jsr @r3
    nop
    mov #0x9, r7
    .byte   0xD5, 0x25    /* mov.l .L_tile_data_a, r5 — 0x14000 */
    .byte   0xD4, 0x26    /* mov.l .L_vdp2_vram_0x76174, r4 — 0x25E76174 */
    .byte   0xD3, 0x26    /* mov.l .L_fn_vram_tile_copy, r3 */
    jsr @r3
    mov #0x0, r6
    mov #0x8, r7
    .byte   0xD5, 0x25    /* mov.l .L_tile_data_b, r5 — 0x17700 */
    .byte   0xD4, 0x26    /* mov.l .L_vdp2_vram_0x761FC, r4 — 0x25E761FC */
    .byte   0xD3, 0x23    /* mov.l .L_fn_vram_tile_copy, r3 */
    jsr @r3
    mov #0x0, r6
    mov #0x0, r6
    .byte   0xDD, 0x24    /* mov.l .L_fn_display_channel, r13 */
    mov r6, r5
    jsr @r13
    mov #0x8, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r13
    mov #0x10, r4
    mov #0x0, r6
    mov r6, r5
    jsr @r13
    mov #0x20, r4
    .byte   0xD3, 0x1F    /* mov.l .L_fn_layer_config, r3 */
    jsr @r3
    mov #0x4, r4
    .byte   0xD3, 0x1E    /* mov.l .L_fn_layer_config, r3 */
    jsr @r3
    mov #0xC, r4
    mov.l @r14, r0
    .byte   0xD3, 0x1D    /* mov.l .L_fn_render_commit, r3 */
    or #0x4, r0
    jsr @r3
    mov.l r0, @r14
    mov #0x0, r6
    .byte   0xD2, 0x1B    /* mov.l .L_layer_data, r2 — display layer params */
    mov.l r2, @r15
    mov r2, r7
    mov r2, r5
    .byte   0xD3, 0x1A    /* mov.l .L_tile_vram_offset, r3 — 0xA000 */
    mov.l @(4, r7), r7
    mov.l @r5, r5
    add r3, r7
    .byte   0xD3, 0x19    /* mov.l .L_fn_layer_setup, r3 */
    jsr @r3
    mov #0x4, r4
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    .byte   0xAF, 0x3A    /* bra 0x06019324 (external tail-call) */
    mov.l @r15+, r14
.L_select_flag_a:
    .4byte  sym_06085FF0               /* course select flag A (byte) */
.L_select_flag_b:
    .4byte  sym_0605D245               /* course select flag B (byte) */
.L_select_flag_c:
    .4byte  sym_06085FF1               /* course select flag C (byte) */
.L_select_flag_d:
    .4byte  sym_06085FF2               /* course select flag D (byte) */
.L_select_flag_e:
    .4byte  sym_06085FF3               /* course select flag E (byte) */
.L_select_flag_f:
    .4byte  sym_06085FF5               /* course select flag F (byte) */
.L_snd_cmd_select:
    .4byte  0xAE0003FF                  /* sound command: course select music */
.L_fn_sound_dispatch:
    .4byte  sound_cmd_dispatch         /* sound command dispatcher */
.L_render_flags:
    .4byte  sym_0605B6D8               /* render mode flags (32-bit) */
.L_fp_min:
    .4byte  0x80000000                  /* min negative / sign bit */
.L_fn_camera_finalize:
    .4byte  sym_06026CE0               /* camera state finalization */
.L_fn_course_name_render:
    .4byte  sym_0601A73E               /* course name rendering */
.L_tile_data_a:
    .4byte  0x00014000                  /* tile set A source address */
.L_vdp2_vram_0x76174:
    .4byte  0x25E76174                  /* VDP2 VRAM +0x76174 */
.L_fn_vram_tile_copy:
    .4byte  sym_0600511E               /* VRAM tile data copy */
.L_tile_data_b:
    .4byte  0x00017700                  /* tile set B source address */
.L_vdp2_vram_0x761FC:
    .4byte  0x25E761FC                  /* VDP2 VRAM +0x761FC */
.L_fn_display_channel:
    .4byte  display_channel_b          /* display channel B enable */
.L_fn_layer_config:
    .4byte  sym_0602853E               /* display layer configuration */
.L_fn_render_commit:
    .4byte  sym_06028560               /* render state commit */
.L_layer_data:
    .4byte  sym_06063AF8               /* display layer parameters */
.L_tile_vram_offset:
    .4byte  0x0000A000                  /* tile VRAM offset (+0xA000) */
.L_fn_layer_setup:
    .4byte  sym_06028400               /* display layer setup */
