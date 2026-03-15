
    .section .text.FUN_06033428


    .global FUN_06033428
    .type FUN_06033428, @function
FUN_06033428:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06033700 - 4
    .2byte 0xB000    /* bsr FUN_06033700 (linker-resolved) */
    nop
    lds.l @r15+, pr
    .byte   0xD6, 0x0E    /* mov.l .L_pool_0603346C, r6 */
