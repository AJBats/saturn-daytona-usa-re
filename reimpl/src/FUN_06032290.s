
    .section .text.FUN_06032290


    .global FUN_06032290
    .type FUN_06032290, @function
FUN_06032290:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06032304 - 4
    .2byte 0xB000    /* bsr FUN_06032304 (linker-resolved) */
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x10    /* mov.l .L_pool_060322DC, r4 */


    .global FUN_0603229A
    .type FUN_0603229A, @function
FUN_0603229A:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06032304 - 4
    .2byte 0xB000    /* bsr FUN_06032304 (linker-resolved) */
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x0F    /* mov.l .L_pool_060322E0, r4 */
