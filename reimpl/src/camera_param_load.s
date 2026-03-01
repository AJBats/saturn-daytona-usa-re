
    .section .text.FUN_0600A5B2


    .global camera_param_load
    .type camera_param_load, @function
camera_param_load:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov r4, r14
    add #-0x4, r15
    shll2 r14
    mov.l r4, @r15
    .byte   0xD5, 0x0E    /* mov.l .L_pool_rot_source_array, r5 */
    .byte   0xD4, 0x0E    /* mov.l .L_pool_rot_dest_array, r4 */
    .byte   0xD3, 0x0F    /* mov.l .L_pool_fn_matrix_xform, r3 */
    add r14, r5
    add r14, r4
    mov.l @r5, r5
    jsr @r3
    mov.l @r4, r4
    .byte   0xD6, 0x0D    /* mov.l .L_pool_display_array, r6 */
    add r14, r6
    mov.l @r6, r6
    .byte   0xD5, 0x0C    /* mov.l .L_pool_scale_factor, r5 */
    mov.w @r5, r5
    .byte   0xD4, 0x0C    /* mov.l .L_pool_model_array, r4 */
    add r14, r4
    mov.l @r4, r4
    add #0x4, r15
    lds.l @r15+, pr
    .byte   0xD3, 0x0B    /* mov.l .L_pool_fn_reg_save, r3 */
    jmp @r3
    mov.l @r15+, r14
    .4byte  sym_060634A4
    .4byte  sym_06063450
    .4byte  sym_060634C0
    .4byte  sym_0606346C
.L_pool_rot_source_array:
    .4byte  sym_06063538
.L_pool_rot_dest_array:
    .4byte  sym_06063520
.L_pool_fn_matrix_xform:
    .4byte  sym_06031D8C
.L_pool_display_array:
    .4byte  sym_0606352C
.L_pool_scale_factor:
    .4byte  sym_06089E98
.L_pool_model_array:
    .4byte  sym_06063514
.L_pool_fn_reg_save:
    .4byte  sym_06031A28
