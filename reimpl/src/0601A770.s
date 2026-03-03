
    .section .text.FUN_0601A770


    .global preview_camera_pos
    .type preview_camera_pos, @function
preview_camera_pos:
    sts.l pr, @-r15
    .byte   0xD0, 0x1C    /* mov.l .L_ptr_course_active_flag, r0 */
    mov.b @r0, r0
    extu.b r0, r0
    tst r0, r0
    bt      .L_0601A78E
    .byte   0xD3, 0x1A    /* mov.l .L_fn_load_gamed_lowram, r3 */
    jsr @r3
    nop
    .byte   0xD3, 0x1A    /* mov.l .L_fn_load_slctd_lowram, r3 */
    jsr @r3
    nop
    mov #0x0, r2
    .byte   0xD3, 0x16    /* mov.l .L_ptr_course_active_flag, r3 */
    mov.b r2, @r3
.L_0601A78E:
    .byte   0xD2, 0x18    /* mov.l .L_ptr_variant_init_flag, r2 */
    mov.b @r2, r2
    tst r2, r2
    bt      .L_0601A7A2
    .byte   0xD3, 0x17    /* mov.l .L_fn_race_variant_e, r3 */
    jsr @r3
    nop
    mov #0x0, r2
    .byte   0xD3, 0x14    /* mov.l .L_ptr_variant_init_flag, r3 */
    mov.b r2, @r3
.L_0601A7A2:
    .byte   0xD5, 0x15    /* mov.l .L_snd_init_cmd, r5 */
    mov #0x0, r4
    .byte   0xD3, 0x15    /* mov.l .L_fn_sound_cmd_dispatch, r3 */
    jmp @r3
    lds.l @r15+, pr
