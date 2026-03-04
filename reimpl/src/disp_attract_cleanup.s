
    .section .text.FUN_06033432


    .global disp_attract_cleanup
    .type disp_attract_cleanup, @function
disp_attract_cleanup:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06033700 - 4
    .2byte 0xB000    /* bsr FUN_06033700 (linker-resolved) */
    nop
    lds.l @r15+, pr
