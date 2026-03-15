
    .section .text.FUN_060333F4


    .global FUN_060333F4
    .type FUN_060333F4, @function
FUN_060333F4:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06033550 - 4
    .2byte 0xB000    /* bsr FUN_06033550 (linker-resolved) */
    nop
    lds.l @r15+, pr
    .byte   0xD1, 0x17    /* mov.l .L_pool_0603345C, r1 */
    mov #0x8, r2
    mov.w r2, @r1
