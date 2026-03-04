
    .section .text.FUN_06032528


    .global disp_tile_idx_7
    .type disp_tile_idx_7, @function
disp_tile_idx_7:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06032584 - 4
    .2byte 0xB000    /* bsr FUN_06032584 (linker-resolved) */
    nop
    lds.l @r15+, pr
