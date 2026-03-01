
    .section .text.FUN_06035EC8


    .global input_proc_buttons
    .type input_proc_buttons, @function
input_proc_buttons:
    mov.l r14, @-r15
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_fn_smpc_response_handler, r3
    jsr @r3
    mov r15, r6
    mov r0, r14
    tst r14, r14
    bt      .L_smpc_ok_process_input
    mov r14, r0
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .4byte  sym_06059CB0
    .4byte  sym_06035168
.L_fn_smpc_response_handler:
    .4byte  smpc_response_handler          /* [HIGH] SMPC peripheral response handler */
    .4byte  sym_06063594
.L_smpc_ok_process_input:
    .byte   0xD5, 0x10    /* mov.l .L_input_config_table, r5 */
    .byte   0xB0, 0x0E    /* bsr 0x06035F16 (external) */
    mov r15, r4
    mov r14, r0
    add #0x8, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
