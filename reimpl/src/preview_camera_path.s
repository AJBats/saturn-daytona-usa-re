
    .section .text.FUN_0601AAE8


    .global preview_camera_path
    .type preview_camera_path, @function
preview_camera_path:
    sts.l pr, @-r15
    mov.l   .L_0601AB50, r3
    mov.w @r3, r2
    extu.w r2, r2
    mov.w   .L_0601AB4E, r3
    and r3, r2
    tst r2, r2
    bt      .L_0601AB48
    mov #0x1E, r3
    mov.l   .L_0601AB54, r2
    mov #0x1, r5
    mov #0x0, r4
    mov.l r3, @r2
    exts.b r4, r0
    extu.b r5, r3
    mov.l   .L_0601AB58, r2
    exts.b r5, r5
    mov.b r3, @r2
    mov.l   .L_0601AB5C, r2
    mov.b r4, @r2
    mov.l   .L_0601AB60, r2
    mov.b r0, @r2
    mov.l   .L_0601AB64, r3
    mov.b r5, @r3
    mov.l   .L_0601AB68, r3
    mov.b r4, @r3
    extu.b r4, r4
    mov.l   .L_0601AB6C, r3
    mov.b r4, @r3
    mov.l   .L_0601AB70, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_0601AB74, r4
    mov.l   .L_0601AB78, r3
    mov.l @r4, r0
    or #0x4, r0
    jsr @r3
    mov.l r0, @r4
    mov.l   .L_0601AB7C, r3
    jsr @r3
    nop
    mov.l   .L_0601AB80, r5
    mov.l   .L_0601AB84, r3
    jsr @r3
    mov #0xF, r4
    mov.l   .L_0601AB88, r3
    jmp @r3
    lds.l @r15+, pr
.L_0601AB48:
    lds.l @r15+, pr
    rts
    nop
.L_0601AB4E:
    .2byte  0x0700
.L_0601AB50:
    .4byte  sym_06063D9A
.L_0601AB54:
    .4byte  g_game_state
.L_0601AB58:
    .4byte  sym_0605E0A2
.L_0601AB5C:
    .4byte  sym_06085FF0
.L_0601AB60:
    .4byte  sym_0605D245
.L_0601AB64:
    .4byte  sym_06085FF1
.L_0601AB68:
    .4byte  sym_06085FF2
.L_0601AB6C:
    .4byte  sym_06085FF3
.L_0601AB70:
    .4byte  sym_0602853E
.L_0601AB74:
    .4byte  sym_0605B6D8
.L_0601AB78:
    .4byte  sym_06028560
.L_0601AB7C:
    .4byte  course_select_draw
.L_0601AB80:
    .4byte  0xAE0001FF
.L_0601AB84:
    .4byte  sound_cmd_dispatch         /* sound command dispatcher */
.L_0601AB88:
    .4byte  handler_init_reset

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
