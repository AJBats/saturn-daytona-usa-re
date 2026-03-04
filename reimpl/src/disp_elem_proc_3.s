
    .section .text.FUN_06032290


    .global disp_elem_proc_3
    .type disp_elem_proc_3, @function
disp_elem_proc_3:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06032304 - 4
    .2byte 0xB000    /* bsr FUN_06032304 (linker-resolved) */
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x10    /* mov.l .L_pool_060322DC, r4 */
