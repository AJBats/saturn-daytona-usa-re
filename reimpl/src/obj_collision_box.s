
    .section .text.FUN_06020B58


    .global obj_collision_box
    .type obj_collision_box, @function
obj_collision_box:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    .byte   0xD4, 0x27    /* mov.l .L_ptr_race_event_bits, r4 -- &race_event_bitfield (sym_0607EBF4) */
    mov.l @r4, r0
    or #0x1, r0
    .byte   0xBF, 0xDA    /* bsr display_list_copy_inline (0x06020B20) */
    mov.l r0, @r4
    .byte   0xD3, 0x25    /* mov.l .L_fn_display_layer_fill_cfg, r3 -- sym_0602853E */
    jsr @r3
    mov #0xC, r4
    mov #0x0, r14
    .byte   0xDB, 0x24    /* mov.l .L_ptr_render_mode_flags, r11 -- &render_mode_flags (sym_0605B6D8) */
    .byte   0xD2, 0x25    /* mov.l .L_const_bit26, r2 -- 0x04000000 */
    mov.l @r11, r3
    or r2, r3
    mov.l r3, @r11
    mov #0x2, r2
    .byte   0xD3, 0x23    /* mov.l .L_ptr_display_timer, r3 -- &display_timer (sym_0608780C) */
    mov.w r2, @r3
    .byte   0xDD, 0x23    /* mov.l .L_ptr_input_skip_flag, r13 -- &input_skip_flag (sym_0605A00C) */
    .byte   0xDC, 0x24    /* mov.l .L_fn_camera_state_finalize, r12 -- sym_06026CE0 */
    jsr @r12
    mov.l r14, @r13
    .byte   0xD2, 0x1F    /* mov.l .L_const_bit26, r2 -- 0x04000000 */
    mov.l @r11, r3
    or r2, r3
    mov #0x4, r2
    mov.l r3, @r11
    .byte   0xD3, 0x1E    /* mov.l .L_ptr_display_timer, r3 -- &display_timer (sym_0608780C) */
    mov.w r2, @r3
    jsr @r12
    mov.l r14, @r13
    mov #0x3, r3
    .byte   0xD2, 0x1E    /* mov.l .L_ptr_obj_visibility_mode, r2 -- &obj_visibility_mode (sym_06059F6F) */
    mov.b r3, @r2
    mov #0x1, r2
    .byte   0xD3, 0x1E    /* mov.l .L_ptr_display_enable_flag, r3 -- &display_enable_flag (sym_06085F8A) */
    mov.b r2, @r3
    .byte   0xD3, 0x1E    /* mov.l .L_ptr_attract_countdown, r3 -- &attract_countdown (sym_0607EBCC) */
    mov.l r14, @r3
    .byte   0xB1, 0x0F    /* bsr obj_anim_advance (0x06020DD0) */
    nop
    .byte   0xD2, 0x1D    /* mov.l .L_ptr_car_struct_base, r2 -- &car_struct_array_base (sym_06063F5C) */
    mov.l @r2, r2
    add #0x10, r2
    mov.b r14, @r2
    jsr @r12
    mov.l r14, @r13
    jsr @r12
    mov.l r14, @r13
    lds.l @r15+, pr
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
