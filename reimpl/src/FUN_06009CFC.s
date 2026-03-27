
    .section .text.FUN_06009CFC


    .global FUN_06009CFC
    .type FUN_06009CFC, @function
FUN_06009CFC:
    sts.l pr, @-r15

    mov #0x3, r3
    mov.l   .L_pool_06009D7C, r2
    mov.w r3, @r2

    mov.l   .L_pool_06009D80, r3
    jsr @r3
    nop

    mov.l   .L_pool_06009D84, r3
    jsr @r3
    nop

    .reloc ., R_SH_IND12W, FUN_0600A1B8 - 4
    .2byte 0xB000    /* bsr FUN_0600A1B8 (linker-resolved) */
    nop

    mov #0x19, r2
    mov.l   .L_pool_06009D88, r3
    mov.l r2, @r3

    mov #0x6, r2
    mov.l   .L_pool_06009D8C, r3
    mov.b r2, @r3

    mov.l   .L_pool_06009D90, r3
    jsr @r3
    nop
    mov.l   .L_pool_06009D94, r3
    jsr @r3
    nop

    mov.l   .L_pool_06009D98, r2
    mov #0x0, r3
    mov.l @r2, r2
    mov.l r3, @(8, r2)

    mov.l   .L_pool_06009D9C, r4
    mov.l   .L_pool_06009DA0, r2
    mov.l @r4, r3
    or r2, r3
    mov.l r3, @r4

    mov.l   .L_pool_06009DA4, r3
    jsr @r3
    nop

    mov #0x0, r2
    mov.l   .L_pool_06009DA8, r3
    lds.l @r15+, pr
    rts
    mov.l r2, @r3


    .global FUN_06009D4E
    .type FUN_06009D4E, @function
FUN_06009D4E:
    sts.l pr, @-r15
    mov.l   .L_pool_06009DB5, r3
    jsr @r3
    nop
    mov.l   .L_pool_06009DB9, r2
    mov.b @r2, r2
    tst r2, r2
    bf      .L_06009D76

    mov.l   .L_pool_06009DBD, r3
    jsr @r3
    nop
    mov.l   .L_pool_06009DC1, r6
    mov.l   .L_pool_06009DC5, r5
    mov.l   .L_pool_06009DC9, r4
    mov.l   .L_pool_06009DCD, r3
    jsr @r3
    mov.l @r6, r6
    mov.l   .L_pool_06009DD1, r3
    jsr @r3
    nop

.L_06009D76:
    mov.l   .L_pool_06009DD5, r3
    jmp @r3
    lds.l @r15+, pr
.L_pool_06009D7C:

.L_pool_06009D7C:
    .4byte  sym_0605A016
.L_pool_06009D80:
    .4byte  FUN_06014A74
.L_pool_06009D84:
    .4byte  FUN_06019058
.L_pool_06009D88:
    .4byte  FUN_0605ACC4
.L_pool_06009D8C:
    .4byte  sym_06078654
.L_pool_06009D90:
    .4byte  FUN_060032D4
.L_pool_06009D94:
    .4byte  FUN_060210F6
.L_pool_06009D98:
    .4byte  sym_0607E944
.L_pool_06009D9C:
    .4byte  sym_0605B6D8
.L_pool_06009DA0:
    .4byte  0x40000000
.L_pool_06009DA4:
    .4byte  sym_06026CE0
.L_pool_06009DA8:
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
