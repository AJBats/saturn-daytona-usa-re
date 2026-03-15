
    .section .text.FUN_06014A42


    .global FUN_06014A42
    .type FUN_06014A42, @function
FUN_06014A42:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06014F34 - 4
    .2byte 0xB000    /* bsr FUN_06014F34 (linker-resolved) */
    nop
    .byte   0xD3, 0x09    /* mov.l .L_pool_06014A71, r3 */
    jmp @r3
    lds.l @r15+, pr
    .2byte  0x0260
    .4byte  0x25C00000
    .4byte  sym_06044B64
    .4byte  sym_06059FFC
    .4byte  FUN_0602761E
    .4byte  FUN_060172BC
    .4byte  sym_0607EBF4
    .4byte  sym_06085F90
    .4byte  sym_06085F94
.L_pool_06014A71:
    .4byte  FUN_0601712C
