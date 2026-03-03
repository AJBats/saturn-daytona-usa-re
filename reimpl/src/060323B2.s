	.text
    .global display_cmd_hscroll
display_cmd_hscroll:
    sts.l pr, @-r15
    .byte   0xB5, 0x30    /* bsr 0x06032E18 (external) */
    nop
    lds.l @r15+, pr
    .byte   0xAF, 0xA6    /* bra 0x0603230A (external) */
    nop
    .short  0x0000
    .long  0x0000000E
    .long  0x00000003
    .long  0x000002D0

    .global loc_060323CC
loc_060323CC:
    .byte   0xD0, 0x03    /* mov.l .L_pool_060323DC, r0 */
    mov.w @(r0, r14), r1
    .byte   0xD2, 0x03    /* mov.l .L_pool_060323E0, r2 */
    or r2, r1
    mov.w r1, @(r0, r14)
    .byte   0xAF, 0x98    /* bra 0x0603230A (external) */
    nop
    .short  0x0000
.L_pool_060323DC:
    .long  0x0000000E
.L_pool_060323E0:
    .long  0x00000001
