
    .section .text.FUN_060322AE


    .global disp_elem_proc_6
    .type disp_elem_proc_6, @function
disp_elem_proc_6:
    sts.l pr, @-r15
    .byte   0xB0, 0x28    /* bsr 0x06032304 (external) */
    nop
    lds.l @r15+, pr
