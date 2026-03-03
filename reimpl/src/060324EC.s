	.text
    .global disp_tile_idx_0
disp_tile_idx_0:
    sts.l pr, @-r15
    .byte   0xB4, 0xBD    /* bsr 0x06032E6C (external) */
    nop
    lds.l @r15+, pr
