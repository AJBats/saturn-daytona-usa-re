
    .section .text.FUN_0603F500


    .global FUN_0603F500
    .type FUN_0603F500, @function
FUN_0603F500:
    sts.l pr, @-r15
    mov #0x4, r6
    add #-0xC, r15
    mov r15, r5
    mov.l r4, @(4, r15)
    .reloc ., R_SH_IND12W, FUN_0603F3F6 - 4
    .2byte 0xB000    /* bsr FUN_0603F3F6 (linker-resolved) */
    add #0x8, r5
    mov #0x4, r6
    mov r15, r5
    .reloc ., R_SH_IND12W, FUN_0603F3F6 - 4
    .2byte 0xB000    /* bsr FUN_0603F3F6 (linker-resolved) */
    mov.l @(4, r15), r4
    mov.l @r15, r0
    add #0xC, r15
    lds.l @r15+, pr
    rts
    nop
