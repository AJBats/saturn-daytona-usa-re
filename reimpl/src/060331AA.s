	.text
    .global disp_result_digit_1
disp_result_digit_1:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r3
    mov r2, r4
    mov r12, r5
    .byte   0xD0, 0x13    /* mov.l .L_pool_06033208, r0 */
