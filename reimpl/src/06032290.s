
    .section .text.FUN_06032290


    .global disp_elem_proc_3
    .type disp_elem_proc_3, @function
disp_elem_proc_3:
    sts.l pr, @-r15
    .byte   0xB0, 0x37    /* bsr 0x06032304 (external) */
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x10    /* mov.l .L_pool_060322DC, r4 */
