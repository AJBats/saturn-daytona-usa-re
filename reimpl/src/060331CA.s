
    .section .text.FUN_060331CA


    .global disp_result_digit_3
    .type disp_result_digit_3, @function
disp_result_digit_3:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r8
    mov r1, r4
    mov r12, r5
    .byte   0xD0, 0x0B    /* mov.l .L_pool_06033208, r0 */
