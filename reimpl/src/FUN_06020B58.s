
    .section .text.FUN_06020B58


    .global FUN_06020B58
    .type FUN_06020B58, @function
FUN_06020B58:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    sts.l pr, @-r15
    .byte   0xD4, 0x27    /* mov.l .L_ptr_race_event_bits, r4 */
    mov.l @r4, r0
    or #0x1, r0
    .byte   0xBF, 0xDA    /* bsr display_list_copy_inline (0x06020B20) */
    mov.l r0, @r4
    .byte   0xD3, 0x25    /* mov.l .L_fn_display_layer_fill_cfg, r3 */
    jsr @r3
    mov #0xC, r4
    mov #0x0, r14
    .byte   0xDB, 0x24    /* mov.l .L_ptr_render_mode_flags, r11 */
    .byte   0xD2, 0x25    /* mov.l .L_const_bit26, r2 */
    mov.l @r11, r3
    or r2, r3
    mov.l r3, @r11
    mov #0x2, r2
    .byte   0xD3, 0x23    /* mov.l .L_ptr_display_timer, r3 */
    mov.w r2, @r3
    .byte   0xDD, 0x23    /* mov.l .L_ptr_input_skip_flag, r13 */
    .byte   0xDC, 0x24    /* mov.l .L_fn_camera_state_finalize, r12 */
    jsr @r12
    mov.l r14, @r13
    .byte   0xD2, 0x1F    /* mov.l .L_const_bit26, r2 */
    mov.l @r11, r3
    or r2, r3
    mov #0x4, r2
    mov.l r3, @r11
    .byte   0xD3, 0x1E    /* mov.l .L_ptr_display_timer, r3 */
    mov.w r2, @r3
    jsr @r12
    mov.l r14, @r13
    mov #0x3, r3
    .byte   0xD2, 0x1E    /* mov.l .L_ptr_obj_visibility_mode, r2 */
    mov.b r3, @r2
    mov #0x1, r2
    .byte   0xD3, 0x1E    /* mov.l .L_ptr_display_enable_flag, r3 */
    mov.b r2, @r3
    .byte   0xD3, 0x1E    /* mov.l .L_ptr_attract_countdown, r3 */
    mov.l r14, @r3
    .byte   0xB1, 0x0F    /* bsr FUN_06020DD0 (0x06020DD0) */
    nop
    .byte   0xD2, 0x1D    /* mov.l .L_ptr_car_struct_base, r2 */
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


    .global FUN_06020BCE
    .type FUN_06020BCE, @function

FUN_06020BCE:
    sts.l pr, @-r15
    .byte   0xD3, 0x16    /* mov.l .L_06020C2C, r3 */
    jsr @r3
    mov #0x8, r4
    .byte   0xD5, 0x16    /* mov.l .L_06020C30, r5 */
    .byte   0xD3, 0x16    /* mov.l .L_06020C34, r3 */
    jsr @r3
    mov r5, r4
    .byte   0xD3, 0x16    /* mov.l .L_06020C38, r3 */
    jsr @r3
    nop
    .byte   0xD4, 0x08    /* mov.l .L_06020C08, r4 */
    .byte   0xD2, 0x09    /* mov.l .L_06020C0C, r2 */
    mov.l @r4, r3
    or r2, r3
    mov.l r3, @r4
    mov #0x2, r2
    .byte   0xD3, 0x07    /* mov.l .L_06020C10, r3 */
    mov.w r2, @r3
    mov #0x0, r2
    .byte   0xD3, 0x07    /* mov.l .L_06020C14, r3 */
    mov.l r2, @r3
    .byte   0xD3, 0x07    /* mov.l .L_06020C18, r3 */
    jmp @r3
    lds.l @r15+, pr

    .4byte  sym_0607EBF4
    .4byte  sym_0602853E
.L_06020C08:
    .4byte  sym_0605B6D8
.L_06020C0C:
    .4byte  0x04000000
.L_06020C10:
    .4byte  sym_0608780C
.L_06020C14:
    .4byte  sym_0605A00C
.L_06020C18:
    .4byte  sym_06026CE0
    .4byte  sym_06059F6F
    .4byte  sym_06085F8A
    .4byte  sym_0607EBCC
    .4byte  sym_06063F5C
.L_06020C2C:
    .4byte  sym_0603850C
.L_06020C30:
    .4byte  0x00010000
.L_06020C34:
    .4byte  FUN_06038794
.L_06020C38:
    .4byte  sym_06038520
