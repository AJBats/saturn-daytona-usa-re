
    .section .text.FUN_06032504


    .global disp_tile_idx_3
    .type disp_tile_idx_3, @function
disp_tile_idx_3:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06032584 - 4
    .2byte 0xB000    /* bsr FUN_06032584 (linker-resolved) */
    nop
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_06032538 - 4
    .2byte 0xA000    /* bra FUN_06032538 (linker-resolved) */
    nop
