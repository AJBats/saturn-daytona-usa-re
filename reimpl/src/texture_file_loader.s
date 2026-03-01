
    .section .text.FUN_0601B644


    .global texture_file_loader
    .type texture_file_loader, @function
texture_file_loader:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l   .L_ptr_scroll_param_base, r13
    mov.l   .L_ptr_file_index, r14
    mov.l   .L_ptr_input_state, r4
    mov.w   .L_mask_dpad_bits, r2
    mov.w @(2, r4), r0
    mov r0, r3
    extu.w r3, r3
    and r2, r3
    tst r3, r3
    bt/s    .L_check_increment
    mov #0x0, r5
    mov.l   .L_ptr_course_state_b, r3
    bra     .L_return
    mov.b r5, @r3
.L_check_increment:
    mov.w @(2, r4), r0
    mov.w   .L_mask_btn_increment, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_check_decrement
    mov.b @r14, r3
    add #0x5, r3
    mov.b r3, @r14
    mov #0x14, r3
    mov.b @r14, r2
    cmp/ge r3, r2
    bf      .L_load_params_and_call
    exts.b r5, r5
    mov.b r5, @r14
.L_load_params_and_call:
    mov.b @r14, r6
    mov.b @(1, r13), r0
    mov r0, r5
    mov.b @r13, r4
    mov.l @r15+, r13
    .byte   0xA1, 0xDF    /* bra 0x0601BA50 (external) */
    mov.l @r15+, r14
.L_check_decrement:
    mov.w @(2, r4), r0
    mov.w   .L_mask_btn_decrement, r3
    mov r0, r2
    extu.w r2, r2
    and r3, r2
    tst r2, r2
    bt      .L_return
    mov.b @r14, r3
    add #-0x5, r3
    mov.b r3, @r14
    mov.b @r14, r2
    cmp/pz r2
    bt      .L_load_params_and_call_b
    mov #0xF, r2
    mov.b r2, @r14
.L_load_params_and_call_b:
    mov.b @r14, r6
    mov.b @(1, r13), r0
    mov r0, r5
    mov.b @r13, r4
    mov.l @r15+, r13
    .byte   0xA1, 0xC9    /* bra 0x0601BA50 (external) */
    mov.l @r15+, r14
.L_return:
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_mask_dpad_bits:
    .2byte  0x0F00                              /* bits 8-11: D-pad / abort button mask */
.L_mask_btn_increment:
    .2byte  0x2000                              /* bit 13: file index increment button */
.L_mask_btn_decrement:
    .2byte  0x1000                              /* bit 12: file index decrement button */
    .2byte  0xFFFF                              /* alignment padding */
.L_ptr_scroll_param_base:
    .4byte  sym_0605D4F4                        /* scroll parameter base (+0=A, +1=B) */
.L_ptr_file_index:
    .4byte  sym_0605D4FA                        /* texture file index / course state A */
.L_ptr_input_state:
    .4byte  g_pad_state                        /* input button state struct (+2=flags) */
.L_ptr_course_state_b:
    .4byte  sym_0608600D                        /* course state flag B (cleared on abort) */
