
    .section .text.FUN_06020BCE


    .global obj_state_pack
    .type obj_state_pack, @function

obj_state_pack:
    sts.l pr, @-r15
    .byte   0xD3, 0x16    /* mov.l .L_ptr_cmd_slot_write, r3 */
    jsr @r3
    mov #0x8, r4
    .byte   0xD5, 0x16    /* mov.l .L_fp_one, r5 */
    .byte   0xD3, 0x16    /* mov.l .L_ptr_scene_color_intensity, r3 */
    jsr @r3
    mov r5, r4
    .byte   0xD3, 0x16    /* mov.l .L_ptr_cmd_queue_commit, r3 */
    jsr @r3
    nop
    .byte   0xD4, 0x08    /* mov.l .L_ptr_render_mode_flags, r4 */
    .byte   0xD2, 0x09    /* mov.l .L_render_flag_bit26, r2 */
    mov.l @r4, r3
    or r2, r3
    mov.l r3, @r4
    mov #0x2, r2
    .byte   0xD3, 0x07    /* mov.l .L_ptr_display_timer, r3 */
    mov.w r2, @r3
    mov #0x0, r2
    .byte   0xD3, 0x07    /* mov.l .L_ptr_input_skip_flag, r3 */
    mov.l r2, @r3
    .byte   0xD3, 0x07    /* mov.l .L_ptr_display_update, r3 */
    jmp @r3
    lds.l @r15+, pr

    .4byte  sym_0607EBF4                     /* display/mode flags (32-bit) */
    .4byte  sym_0602853E                     /* display channel configure */
.L_ptr_render_mode_flags:
    .4byte  sym_0605B6D8                     /* render mode flags (32-bit bitmask) */
.L_render_flag_bit26:
    .4byte  0x04000000                       /* bit 26 flag constant */
.L_ptr_display_timer:
    .4byte  sym_0608780C                     /* display_timer (16-bit word; 2 = active) */
.L_ptr_input_skip_flag:
    .4byte  sym_0605A00C                     /* input skip flag (nonzero = skip input) */
.L_ptr_display_update:
    .4byte  sym_06026CE0                     /* display_update (tail-call target) */
    .4byte  sym_06059F6F                     /* (shared pool data) */
    .4byte  sym_06085F8A                     /* object compaction needed flag (byte) */
    .4byte  sym_0607EBCC                     /* countdown timer (attract mode) */
    .4byte  sym_06063F5C                     /* car struct array base pointer */
.L_ptr_cmd_slot_write:
    .4byte  sym_0603850C                     /* command_slot_write */
.L_fp_one:
    .4byte  0x00010000                       /* 1.0 (16.16 fixed-point) */
.L_ptr_scene_color_intensity:
    .4byte  scene_color_intensity            /* scene color intensity function */
.L_ptr_cmd_queue_commit:
    .4byte  sym_06038520                     /* command_queue_commit */
