
    .section .text.FUN_060331BA


    .global disp_result_digit_2
    .type disp_result_digit_2, @function
disp_result_digit_2:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r0, r6
    mov r1, r4
    mov r11, r5
    .byte   0xD0, 0x0F    /* mov.l .L_pool_06033208, r0 */
