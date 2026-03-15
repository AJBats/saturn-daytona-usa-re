
    .section .text.FUN_0603312C


    .global FUN_0603312C
    .type FUN_0603312C, @function
FUN_0603312C:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_0603320C - 4
    .2byte 0xB000    /* bsr FUN_0603320C (linker-resolved) */
    nop
    lds.l @r15+, pr
    mov.l @r15+, r0
    add r10, r0
    add #-0x1, r7
    cmp/pl r7
    .byte   0x89, 0xC0    /* bt 0x060330C0 (external) */
    rts
    nop
    .2byte  0x0000
    .4byte  sym_06033870
    .4byte  0x00000010
    .4byte  0x00000018
    .4byte  0x00000268
    .4byte  sym_0603386C
    .4byte  0x00220000
    .4byte  0x001A0000
    .4byte  sym_06033884
    .4byte  0x00000700
    .4byte  0x0000FFFF
    .global FUN_0603316C
FUN_0603316C:
    .4byte  0xD204042E
    .4byte  0xD204032E
    .4byte  0x343C343C
    .4byte  0x664B000B
    .4byte  0x00090000
    .4byte  0x00000020
    .4byte  0x000001D8
    .global FUN_06033188
FUN_06033188:
    .4byte  0x2F062F66
    .4byte  0x2F762F86
    .4byte  0x6463D019
    .4byte  0x2409D519
    .4byte  0xD619D01A
