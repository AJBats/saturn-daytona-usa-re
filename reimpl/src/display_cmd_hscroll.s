
    .section .text.FUN_060323B2


    .global display_cmd_hscroll
    .type display_cmd_hscroll, @function
display_cmd_hscroll:
    sts.l pr, @-r15
    .byte   0xB5, 0x30    /* bsr 0x06032E18 (external) */
    nop
    lds.l @r15+, pr
    .byte   0xAF, 0xA6    /* bra 0x0603230A (external) */
    nop
    .2byte  0x0000
    .4byte  0x0000000E
    .4byte  0x00000003
    .4byte  0x000002D0

    .global loc_060323CC
loc_060323CC:
    .byte   0xD0, 0x03    /* mov.l _pool_ctrl_word_off, r0 */
    mov.w @(r0, r14), r1
    .byte   0xD2, 0x03    /* mov.l _pool_scroll_enable_bit, r2 */
    or r2, r1
    mov.w r1, @(r0, r14)
    .byte   0xAF, 0x98    /* bra 0x0603230A (external) */
    nop
    .2byte  0x0000
_pool_ctrl_word_off:
    .4byte  0x0000000E
_pool_scroll_enable_bit:
    .4byte  0x00000001
