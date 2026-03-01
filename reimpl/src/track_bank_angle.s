
    .section .text.FUN_06036248


    .global track_bank_angle
    .type track_bank_angle, @function
track_bank_angle:
    sts.l pr, @-r15
    mov r4, r12
    add #-0x10, r15
    mov r15, r4
    mov.l   .L_06036298, r3
    jsr @r3
    add #0x8, r4
    mov r15, r2
    mov #0x41, r3
    extu.b r12, r12
    mov r15, r6
    mov r15, r5
    add #0x8, r2
    mov r12, r0
    add #0x8, r5
    mov.b r3, @r2
    mov r15, r2
    add #0x8, r2
    mov.b r0, @(4, r2)
    mov.l   .L_060362A0, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    mov r15, r2
    mov r4, r0
    mov.l @r2, r3
    mov.l   .L_060362A4, r2
    and r2, r3
    mov.l r3, @r13
    mov r15, r2
    mov.l @(4, r2), r3
    mov.l   .L_060362A4, r2
    and r2, r3
    mov.l r3, @r14
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_06036298:
    .4byte  input_proc_analog
    .4byte  input_proc_buttons
.L_060362A0:
    .4byte  input_proc_digital
.L_060362A4:
    .4byte  0x00FFFFFF
