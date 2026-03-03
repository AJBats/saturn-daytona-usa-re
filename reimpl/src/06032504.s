
    .section .text.FUN_06032504


    .global disp_tile_idx_3
    .type disp_tile_idx_3, @function
disp_tile_idx_3:
    sts.l pr, @-r15
    .byte   0xB0, 0x3D    /* bsr 0x06032584 (external) */
    nop
    lds.l @r15+, pr
    .byte   0xA0, 0x14    /* bra 0x06032538 (external) */
    nop
