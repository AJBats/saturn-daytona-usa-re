
    .section .text.FUN_060324FC


    .global disp_tile_idx_2
    .type disp_tile_idx_2, @function
disp_tile_idx_2:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_0603268C - 4
    .2byte 0xB000    /* bsr FUN_0603268C (linker-resolved) */
    nop
    lds.l @r15+, pr
