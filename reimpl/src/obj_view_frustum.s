
    .section .text.FUN_060369D8


    .global obj_view_frustum
    .type obj_view_frustum, @function
obj_view_frustum:
    sts.l pr, @-r15
    add #-0x10, r15
    mov r15, r4
    mov.l   .L_ptr_input_proc_analog, r3
    jsr @r3
    add #0x8, r4
    mov r15, r2
    mov #0x67, r3
    mov r15, r6
    mov r15, r5
    add #0x8, r2
    add #0x8, r5
    mov.b r3, @r2
    mov.l   .L_ptr_input_proc_digital, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    mov r15, r2
    mov.b @(1, r2), r0
    mov r0, r3
    extu.b r3, r3
    mov r4, r0
    mov.l r3, @r14
    add #0x10, r15
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .2byte  0x0100
.L_ptr_input_proc_analog:
    .4byte  input_proc_analog     /* [HIGH] JSR target — input_proc_analog @ 0x06035E90 */
    .4byte  input_proc_buttons    /* [HIGH] adjacent pool entry — input_proc_buttons @ 0x06035EC8 (not directly referenced in this function) */
.L_ptr_input_proc_digital:
    .4byte  input_proc_digital    /* [HIGH] JSR target — input_proc_digital @ 0x06035EA2 */
