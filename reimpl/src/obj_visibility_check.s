
    .section .text.FUN_06036890


    .global obj_visibility_check
    .type obj_visibility_check, @function
obj_visibility_check:
    sts.l pr, @-r15
    mov r4, r12
    add #-0x8, r15
    mov.l   .L_fn_input_proc_analog, r3
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x63, r3
    extu.w r14, r14
    extu.b r12, r12
    extu.w r13, r13
    mov.b r3, @r2
    mov r14, r0
    mov r15, r2
    mov r15, r3
    mov.w r0, @(2, r2)
    mov r12, r0
    mov.b r0, @(4, r3)
    mov r15, r3
    mov r13, r0
    mov.w r0, @(6, r3)
    mov.w   .L_periph_port_mask, r4
    mov.l   .L_fn_input_proc_buttons, r3
    jsr @r3
    mov r15, r5
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_periph_port_mask:
    .2byte  0x0080                      /* [MEDIUM] peripheral port mask — 0x80 = port B analog? (cf. 0x0200 in ai_master_update) */
    .2byte  0xFFFF                      /* padding */
.L_fn_input_proc_analog:
    .4byte  input_proc_analog           /* [HIGH] fn ptr: SMPC analog axis reader */
.L_fn_input_proc_buttons:
    .4byte  input_proc_buttons          /* [HIGH] fn ptr: SMPC digital button reader */
