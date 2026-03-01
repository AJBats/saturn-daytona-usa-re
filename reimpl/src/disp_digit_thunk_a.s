
    .section .text.FUN_060325A0


    .global disp_digit_thunk_a
    .type disp_digit_thunk_a, @function
disp_digit_thunk_a:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x0D    /* mov.l .L_pool_060325E0, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x0D    /* mov.l .L_pool_060325E4, r0 */
