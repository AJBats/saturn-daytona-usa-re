
    .section .text.FUN_060324F4


    .global disp_tile_idx_1
    .type disp_tile_idx_1, @function
disp_tile_idx_1:
    sts.l pr, @-r15
    .byte   0xB0, 0x21    /* bsr 0x0603253C (external) */
    nop
    lds.l @r15+, pr
