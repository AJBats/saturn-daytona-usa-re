
    .section .text.FUN_0603F520


    .global FUN_0603F520
    .type FUN_0603F520, @function
FUN_0603F520:
    sts.l pr, @-r15
    mov #0x4, r6
    add #-0x4, r15
    .reloc ., R_SH_IND12W, FUN_0603F3F6 - 4
    .2byte 0xB000    /* bsr FUN_0603F3F6 (linker-resolved) */
    mov r15, r5
    mov.l @r15, r0
    add #0x4, r15
    lds.l @r15+, pr
    rts
    nop
