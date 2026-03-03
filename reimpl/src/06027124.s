
    .section .text.FUN_06027124


    .global mat_scale_b
    .type mat_scale_b, @function
mat_scale_b:
    .byte   0xD0, 0x81    /* mov.l .L_pool_0602732C, r0 */
    mov.l @r0, r7
    mov #0x3, r3
.L_0602712A:
    mov.l @(0, r7), r0
    dmuls.l r0, r4
    mov.l @(12, r7), r0
    sts mach, r1
    sts macl, r2
    xtrct r1, r2
    dmuls.l r0, r5
    mov.l r2, @(0, r7)
    mov.l @(24, r7), r0
    sts mach, r1
    sts macl, r2
    xtrct r1, r2
    dmuls.l r0, r6
    mov.l r2, @(12, r7)
    dt r3
    sts mach, r1
    sts macl, r2
    xtrct r1, r2
    mov.l r2, @(24, r7)
    bf/s    .L_0602712A
    add #0x4, r7
    rts
    nop
