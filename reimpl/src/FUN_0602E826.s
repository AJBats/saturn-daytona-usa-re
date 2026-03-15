
    .section .text.FUN_0602E826


    .global FUN_0602E826
    .type FUN_0602E826, @function
FUN_0602E826:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_0602E78C - 4
    .2byte 0xA000    /* bra FUN_0602E78C (linker-resolved) */
    nop
    .2byte  0x0000
    .4byte  0x00000050
    .4byte  0x00000000
    .4byte  0xAE1106FF
    .4byte  FUN_0601D5F4
    .4byte  0xD404D505
    .2byte  0xDD05
