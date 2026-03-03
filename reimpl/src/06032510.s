
    .section .text.FUN_06032510


    .global disp_tile_idx_4
    .type disp_tile_idx_4, @function
disp_tile_idx_4:
    sts.l pr, @-r15
    .byte   0xB4, 0xAB    /* bsr 0x06032E6C (external) */
    nop
    lds.l @r15+, pr
