
    .section .text.FUN_0603F948


    .global attract_mode_timer
    .type attract_mode_timer, @function
attract_mode_timer:
    sts.l pr, @-r15
    mov.l r13, @r14
    mov.l r13, @(4, r14)
    mov.l r13, @(8, r14)
    mov.l r13, @(12, r14)
    mov.l r3, @(16, r14)
    mov.l r13, @(20, r14)
    mov.l r13, @(24, r14)
    .byte   0xB0, 0x0A    /* bsr 0x0603F970 (external) */
    mov r14, r4
    mov #0x1, r5
    mov r14, r4
    mov #0x34, r0
    mov.l r5, @(48, r4)
    mov.b r13, @(r0, r14)
    mov r4, r0
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
