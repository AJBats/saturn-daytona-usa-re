
    .section .text.FUN_060192CC


    .global FUN_060192CC
    .type FUN_060192CC, @function
FUN_060192CC:
    mov.l r14, @-r15
    sts.l pr, @-r15
    mov.l   .L_pool_06019304, r14
    jsr @r14
    mov #0x1, r4
    mov #0x0, r5
    jsr @r14
    mov #0x3, r4
    mov #0x0, r5
    jsr @r14
    mov #0x2, r4
    lds.l @r15+, pr
    rts
    mov.l @r15+, r14
    .global FUN_060192E8
FUN_060192E8:
    .4byte  0xD107D708
    .4byte  0xD608E501
    .4byte  0xD4084410
    .4byte  0x8B10A013
    .4byte  0x2152FFFF
    .4byte  0x25A00000
    .4byte  0x0007FFFF
.L_pool_06019304:
    .4byte  FUN_0601D5F4          /* [HIGH] sound command dispatch function */
    .4byte  sym_06086050
    .4byte  0x25A02DBE
    .4byte  0x0000FFFF
    .4byte  0x000186A0
    .4byte  0x6271622D
    .4byte  0x32608BE8
    .4byte  0x000B0009
