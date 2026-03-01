
    .section .text.FUN_06032286


    .global disp_elem_proc_2
    .type disp_elem_proc_2, @function
disp_elem_proc_2:
    sts.l pr, @-r15
    .byte   0xB0, 0x3C    /* bsr 0x06032304 (external) */
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x12    /* mov.l .L_pool_060322D8, r4 */
