
    .section .text.FUN_06032518


    .global disp_tile_idx_5
    .type disp_tile_idx_5, @function
disp_tile_idx_5:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_0603253C - 4
    .2byte 0xB000    /* bsr FUN_0603253C (linker-resolved) */
    nop
    lds.l @r15+, pr
