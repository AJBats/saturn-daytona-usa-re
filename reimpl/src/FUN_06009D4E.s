
    .section .text.FUN_06009D4E


    .global FUN_06009D4E
    .type FUN_06009D4E, @function
FUN_06009D4E:
    sts.l pr, @-r15
    .byte   0xD3, 0x16    /* mov.l .L_pool_06009DB5, r3 */
    jsr @r3
    nop
    .byte   0xD2, 0x16    /* mov.l .L_pool_06009DB9, r2 */
    mov.b @r2, r2
    tst r2, r2
    bf      .L_06009D76

    .byte   0xD3, 0x15    /* mov.l .L_pool_06009DBD, r3 */
    jsr @r3
    nop
    .byte   0xD6, 0x14    /* mov.l .L_pool_06009DC1, r6 */
    .byte   0xD5, 0x15    /* mov.l .L_pool_06009DC5, r5 */
    .byte   0xD4, 0x15    /* mov.l .L_pool_06009DC9, r4 */
    .byte   0xD3, 0x16    /* mov.l .L_pool_06009DCD, r3 */
    jsr @r3
    mov.l @r6, r6
    .byte   0xD3, 0x15    /* mov.l .L_pool_06009DD1, r3 */
    jsr @r3
    nop

.L_06009D76:
    .byte   0xD3, 0x15    /* mov.l .L_pool_06009DD5, r3 */
    jmp @r3
    lds.l @r15+, pr

    .4byte  sym_0605A016
    .4byte  FUN_06014A74
    .4byte  FUN_06019058
    .4byte  FUN_0605ACC4
    .4byte  sym_06078654
    .4byte  FUN_060032D4
    .4byte  FUN_060210F6
    .4byte  sym_0607E944
    .4byte  sym_0605B6D8
    .4byte  0x40000000
    .4byte  sym_06026CE0
    .4byte  sym_06059F44
.L_pool_06009DB5:
    .4byte  FUN_06014D2C
.L_pool_06009DB9:
    .4byte  sym_06085F8A
.L_pool_06009DBD:
    .4byte  FUN_0600BB94
.L_pool_06009DC1:
    .4byte  sym_06063E24
.L_pool_06009DC5:
    .4byte  sym_06063EEC
.L_pool_06009DC9:
    .4byte  sym_06063EF8
.L_pool_06009DCD:
    .4byte  FUN_060053AC
.L_pool_06009DD1:
    .4byte  FUN_0600BFFC
.L_pool_06009DD5:
    .4byte  FUN_060078DC
