
    .section .text.FUN_0603B92C


    .global FUN_0603B92C
    .type FUN_0603B92C, @function
FUN_0603B92C:
    sts.l pr, @-r15
    add #-0x4, r15
    .reloc ., R_SH_IND12W, FUN_0603B8B4 - 4
    .2byte 0xB000    /* bsr FUN_0603B8B4 (linker-resolved) */
    mov.l r4, @r15
    mov.l @r15, r4
    add #0x4, r15
    .reloc ., R_SH_IND12W, FUN_0603B8F4 - 4
    .2byte 0xA000    /* bra FUN_0603B8F4 (linker-resolved) */
    lds.l @r15+, pr
