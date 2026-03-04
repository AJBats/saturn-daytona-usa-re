
    .section .text.FUN_060322AE


    .global disp_elem_proc_6
    .type disp_elem_proc_6, @function
disp_elem_proc_6:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06032304 - 4
    .2byte 0xB000    /* bsr FUN_06032304 (linker-resolved) */
    nop
    lds.l @r15+, pr
