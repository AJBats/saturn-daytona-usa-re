
    .section .text.FUN_060322A4


    .global disp_elem_proc_5
    .type disp_elem_proc_5, @function
disp_elem_proc_5:
    sts.l pr, @-r15
    .byte   0xB0, 0x2D    /* bsr 0x06032304 (external) */
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x0D    /* mov.l .L_pool_060322E4, r4 */
