	.text
    .global disp_tile_idx_7
disp_tile_idx_7:
    sts.l pr, @-r15
    .byte   0xB0, 0x2B    /* bsr 0x06032584 (external) */
    nop
    lds.l @r15+, pr
