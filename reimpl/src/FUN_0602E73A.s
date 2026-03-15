
    .section .text.FUN_0602E73A


    .global FUN_0602E73A
    .type FUN_0602E73A, @function
FUN_0602E73A:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_0602E770 - 4
    .2byte 0xA000    /* bra FUN_0602E770 (linker-resolved) */
    shll r0
    .2byte  0x0000
    .4byte  DAT_06083264
    .4byte  0x0000023C
    .4byte  0x00000008
    .4byte  0x00000010
    .4byte  0x00000018
    .4byte  FUN_06027552
    .4byte  FUN_06027476
    .4byte  0x6473DD07
