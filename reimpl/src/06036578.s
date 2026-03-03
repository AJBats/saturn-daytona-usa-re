
    .section .text.FUN_06036578


    .global course_data_access_f
    .type course_data_access_f, @function
course_data_access_f:
    sts.l pr, @-r15
    mov r5, r13
    add #-0x10, r15
    mov r15, r4
    mov.l   .L_060365BC, r3
    jsr @r3
    add #0x8, r4
    mov r15, r2
    mov #0x51, r3
    extu.b r14, r14
    mov r15, r6
    mov r15, r5
    add #0x8, r2
    mov r14, r0
    add #0x8, r5
    mov.b r3, @r2
    mov r15, r2
    add #0x8, r2
    mov.b r0, @(4, r2)
    mov.l   .L_060365C0, r3
    jsr @r3
    mov #0x0, r4
    mov r0, r4
    mov r15, r2
    mov.w @(6, r2), r0
    mov r0, r3
    extu.w r3, r3
    mov r4, r0
    mov.l r3, @r13
    add #0x10, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
.L_060365BC:
    .4byte  input_proc_analog
.L_060365C0:
    .4byte  input_proc_digital
