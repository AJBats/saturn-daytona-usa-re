
    .section .text.FUN_06036A5C


    .global ground_shadow_render
    .type ground_shadow_render, @function
ground_shadow_render:
    sts.l pr, @-r15
    add #-0x8, r15
    mov.l   .L_fn_input_proc_analog, r3
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x71, r3
    extu.b r13, r13
    mov.b r3, @r2
    mov r13, r0
    mov r15, r2
    mov r15, r3
    mov.l r14, @(4, r2)
    mov.b r0, @(4, r3)
    mov.w   .L_periph_port_mask, r4
    mov.l   .L_fn_input_proc_buttons, r3
    jsr @r3
    mov r15, r5
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_periph_port_mask:
    .2byte  0x0200                      /* [HIGH] peripheral port A digital mask -- same value as ai_master_update */
    .2byte  0xFFFF                      /* alignment padding between word and longword pools */
.L_fn_input_proc_analog:
    .4byte  input_proc_analog           /* [HIGH] -> SMPC analog axis reader / command struct initializer */
.L_fn_input_proc_buttons:
    .4byte  input_proc_buttons          /* [HIGH] -> SMPC digital button reader / command dispatcher */
