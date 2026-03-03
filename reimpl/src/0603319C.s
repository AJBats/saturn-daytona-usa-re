
    .section .text.FUN_0603319C


    .global disp_result_digit_0
    .type disp_result_digit_0, @function
disp_result_digit_0:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r2, r4
    mov r11, r5
    .byte   0xD0, 0x17    /* mov.l .L_pool_06033208, r0 */
