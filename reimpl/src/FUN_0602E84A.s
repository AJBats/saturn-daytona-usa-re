
    .section .text.FUN_0602E84A


    .global FUN_0602E84A
    .type FUN_0602E84A, @function
FUN_0602E84A:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_0602E78C - 4
    .2byte 0xA000    /* bra FUN_0602E78C (linker-resolved) */
    nop
    .2byte  0x0000
    .4byte  0x00000000
    .4byte  0xAE110AFF
    .4byte  FUN_0601D5F4
    .4byte  0xD3053833
    .4byte  0x8910D405
    .4byte  0xD505DD06
