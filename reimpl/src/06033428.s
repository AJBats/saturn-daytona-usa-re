
    .section .text.FUN_06033428


    .global disp_attract_elem
    .type disp_attract_elem, @function
disp_attract_elem:
    sts.l pr, @-r15
    .byte   0xB1, 0x69    /* bsr 0x06033700 (external) */
    nop
    lds.l @r15+, pr
    .byte   0xD6, 0x0E    /* mov.l .L_pool_0603346C, r6 */
