
    .section .text.FUN_06032FBC


    .global disp_helper_c
    .type disp_helper_c, @function
disp_helper_c:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x13    /* mov.l .L_pool_06033014, r0 */
