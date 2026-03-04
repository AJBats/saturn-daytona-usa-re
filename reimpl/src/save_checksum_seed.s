
    .section .text.FUN_0603B92C


    .global save_checksum_seed
    .type save_checksum_seed, @function
save_checksum_seed:
    sts.l pr, @-r15
    add #-0x4, r15
    .reloc ., R_SH_IND12W, sys_dma_channel_init - 4
    .2byte 0xB000    /* bsr sys_dma_channel_init (linker-resolved) */
    mov.l r4, @r15
    mov.l @r15, r4
    add #0x4, r15
    .reloc ., R_SH_IND12W, FUN_0603B8F4 - 4
    .2byte 0xA000    /* bra FUN_0603B8F4 (linker-resolved) */
    lds.l @r15+, pr
