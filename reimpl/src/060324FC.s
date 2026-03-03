
    .section .text.FUN_060324FC


    .global disp_tile_idx_2
    .type disp_tile_idx_2, @function
disp_tile_idx_2:
    sts.l pr, @-r15
    .byte   0xB0, 0xC5    /* bsr 0x0603268C (external) */
    nop
    lds.l @r15+, pr
