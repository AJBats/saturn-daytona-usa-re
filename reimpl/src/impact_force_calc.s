
    .section .text.FUN_060367B4


    .global impact_force_calc
    .type impact_force_calc, @function
impact_force_calc:
    sts.l pr, @-r15
    add #-0x8, r15
    .byte   0xD3, 0x1E    /* mov.l .L_pool_06036834, r3 */
    jsr @r3
    mov r15, r4
    mov r15, r2
    mov #0x60, r3
    extu.b r14, r14
    extu.b r13, r13
    mov r15, r5
    mov.b r3, @r2
    mov r14, r0
    mov r15, r2
    mov r15, r3
    mov.b r0, @(1, r2)
    mov r13, r0
    mov.b r0, @(2, r3)
    .byte   0xD3, 0x18    /* mov.l .L_pool_06036838, r3 */
    jsr @r3
    mov #0x40, r4
    mov r0, r4
    add #0x8, r15
    lds.l @r15+, pr
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
