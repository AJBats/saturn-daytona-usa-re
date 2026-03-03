
    .section .text.FUN_060333E4


    .global disp_result_sub_b
    .type disp_result_sub_b, @function
disp_result_sub_b:
    mov.l r14, @-r15
    .byte   0xD0, 0x1B    /* mov.l .L_pool_06033454, r0 */
    mov.l @r0, r0
    .byte   0xD1, 0x1B    /* mov.l .L_pool_06033458, r1 */
    mov #0x8, r2
    mov.w r2, @r1
    mov #0x2, r2
    mov.w r2, @-r1
