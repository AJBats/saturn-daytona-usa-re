
    .section .text.FUN_06040724


    .global timer_overflow_handler
    .type timer_overflow_handler, @function
timer_overflow_handler:
    sts.l pr, @-r15
    sts.l macl, @-r15
    mov.b @(r0, r4), r3
    extu.b r3, r3
    tst r3, r3
    bf      .L_0604073A
    mov r5, r0
    lds.l @r15+, macl
    lds.l @r15+, pr
    rts
    nop
.L_0604073A:
    mov #0x1E, r0
    mov r5, r1
    mov.l   .L_06040774, r3
    mov.b @(r0, r4), r6
    extu.b r6, r6
    jsr @r3
    mov r6, r0
    mov #0x1F, r2
    mov r6, r3
    mov r5, r1
    add r4, r2
    mov.b @r2, r2
    extu.b r2, r2
    add r2, r3
    mul.l r3, r0
    mov.l   .L_06040778, r2
    sts macl, r0
    mov r0, r3
    jsr @r2
    mov r6, r0
    add r3, r0
    lds.l @r15+, macl
    lds.l @r15+, pr
    rts
    nop
    .4byte  ai_section_check
    .4byte  sym_06040FEA
.L_06040774:
    .4byte  sym_06034FFC
.L_06040778:
    .4byte  sym_06036BE4
