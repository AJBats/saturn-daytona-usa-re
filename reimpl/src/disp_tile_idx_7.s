
    .section .text.FUN_06032528


    .global disp_tile_idx_7
    .type disp_tile_idx_7, @function
disp_tile_idx_7:
    sts.l pr, @-r15
    .byte   0xB0, 0x2B    /* bsr 0x06032584 (external) */
    nop
    lds.l @r15+, pr
