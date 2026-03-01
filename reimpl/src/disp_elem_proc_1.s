
    .section .text.FUN_0603227C


    .global disp_elem_proc_1
    .type disp_elem_proc_1, @function
disp_elem_proc_1:
    sts.l pr, @-r15
    .byte   0xB0, 0x41    /* bsr 0x06032304 (external) */
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x13    /* mov.l .L_pool_060322D4, r4 */
