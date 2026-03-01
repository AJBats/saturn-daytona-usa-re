
    .section .text.FUN_06032840


    .global speed_hundreds_digit
    .type speed_hundreds_digit, @function
speed_hundreds_digit:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r13, r1
    .byte   0xD0, 0x94    /* mov.l .L_pool_06032A9C, r0 */
    add r14, r0
    mov.l @r1+, r2
    mov.l r2, @(0, r0)
    mov.l @r1+, r2
    mov.l r2, @(4, r0)
    mov.l @r1+, r2
    mov.l r2, @(8, r0)
    mov.l @r1+, r2
    mov.l r2, @(12, r0)
    mov.l @r1+, r2
    mov.l r2, @(16, r0)
    mov.l @r1+, r2
    mov.l r2, @(20, r0)
    mov.l @r1+, r2
    mov.l r2, @(24, r0)
    mov.l @r1+, r2
    mov.l r2, @(28, r0)
    mov.l @r1+, r2
    mov.l r2, @(32, r0)
    mov.l @r1+, r2
    mov.l r2, @(36, r0)
    mov.l @r1+, r2
    mov.l r2, @(40, r0)
    mov.l @r1, r2
    mov.l r2, @(44, r0)
    .byte   0xD0, 0x88    /* mov.l .L_pool_06032AA0, r0 */
    add r12, r0
    mov.l @r0+, r4
    mov.l @r0+, r5
    mov.l @r0+, r6
    .byte   0xD0, 0x7D    /* mov.l .L_pool_06032A80, r0 */
