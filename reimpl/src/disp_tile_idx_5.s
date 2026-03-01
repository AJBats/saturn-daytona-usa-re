
    .section .text.FUN_06032518


    .global disp_tile_idx_5
    .type disp_tile_idx_5, @function
disp_tile_idx_5:
    sts.l pr, @-r15
    .byte   0xB0, 0x0F    /* bsr 0x0603253C (external) */
    nop
    lds.l @r15+, pr
