
    .section .text.FUN_0603B92C


    .global save_checksum_seed
    .type save_checksum_seed, @function
save_checksum_seed:
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xBF, 0xC0    /* bsr 0x0603B8B4 (external) */
    mov.l r4, @r15
    mov.l @r15, r4
    add #0x4, r15
    .byte   0xAF, 0xDC    /* bra 0x0603B8F4 (external) */
    lds.l @r15+, pr
