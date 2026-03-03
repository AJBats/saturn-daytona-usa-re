
    .section .text.FUN_06036890


    .global obj_visibility_check
    .type obj_visibility_check, @function
obj_visibility_check:
    sts.l pr, @-r15
    mov r4, r12
    add #-0x8, r15
    mov.l   .L_060368D4, r3
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
    mov.w   .L_060368D0, r4
    mov.l   .L_060368D8, r3
    jsr @r3
    mov r15, r5
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_060368D0:
    .2byte  0x0080
    .2byte  0xFFFF
.L_060368D4:
    .4byte  input_proc_analog
.L_060368D8:
    .4byte  input_proc_buttons
