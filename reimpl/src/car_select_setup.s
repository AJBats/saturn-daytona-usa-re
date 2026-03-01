
    .section .text.FUN_060198E0


    .global car_select_setup
    .type car_select_setup, @function
car_select_setup:
    sts.l pr, @-r15
    mov.l   .L_fn_display_layer_config, r3
    jsr @r3
    mov #0xC, r4
    mov.l   .L_fn_render_state_commit, r3
    jsr @r3
    nop
    mov #0x1, r4
    mov.l   .L_ptr_input_dirty_flag, r3
    mov #-0x1, r1
    mov.b r4, @r3
    extu.b r4, r4
    mov.l   .L_ptr_course_active_flag, r3
    mov.b r4, @r3
    mov.l   .L_ptr_variant_init_flag, r3
    mov.b r1, @r3
    .byte   0xB0, 0x12    /* bsr 0x06019928 (track_seg_phys_init) */
    nop
    .byte   0xB7, 0x82    /* bsr 0x0601A80C (course_data_rom_load) */
    nop
    mov.l   .L_fn_course_init_pipeline, r3
    jmp @r3
    lds.l @r15+, pr
    .2byte  0xFFFF
.L_fn_display_layer_config:
    .4byte  sym_0602853E                     /* display_layer_config */
.L_fn_render_state_commit:
    .4byte  sym_06028560                     /* render_state_commit */
.L_ptr_input_dirty_flag:
    .4byte  sym_06085FF1                     /* input dirty flag (byte) */
.L_ptr_course_active_flag:
    .4byte  sym_06085FF6                     /* course active flag (byte) */
.L_ptr_variant_init_flag:
    .4byte  sym_06085FF7                     /* variant init flag (byte) */
.L_fn_course_init_pipeline:
    .4byte  course_init_pipeline             /* course selection input handler */
