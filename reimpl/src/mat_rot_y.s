
    .section .text.FUN_06026EDE


    .global mat_rot_y
    .type mat_rot_y, @function
mat_rot_y:
    sts.l pr, @-r15
    .byte   0xD6, 0x63    /* mov.l .L_pool_06027070, r6 */
    mov #0x4, r5
    .byte   0xB2, 0x38    /* bsr 0x06027358 (external) */
    add r6, r5
    lds.l @r15+, pr
    mov.l @r5, r1
    mov.l @r6, r2
    neg r1, r1
    mov.l r1, @(8, r6)
    .byte   0xD0, 0x5D    /* mov.l .L_pool_06027068, r0 */
    mov.l r2, @(12, r6)
    mov.l @r0, r4
    mov #0x3, r3
.L_06026EFA:
    mov r4, r5
    mov r6, r7
    clrmac
    mac.l @r7+, @r5+
    add #0x4, r5
    mac.l @r7+, @r5+
    add #-0xC, r5
    sts mach, r0
    sts macl, r1
    xtrct r0, r1
    clrmac
    mac.l @r7+, @r5+
    add #0x4, r5
    mac.l @r7+, @r5+
    mov.l r1, @(0, r4)
    dt r3
    sts mach, r0
    sts macl, r2
    xtrct r0, r2
    mov.l r2, @(8, r4)
    bf/s    .L_06026EFA
    add #0xC, r4
    rts
    nop
