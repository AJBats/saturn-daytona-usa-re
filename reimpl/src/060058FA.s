
    .section .text.FUN_060058FA
    .global frame_dispatch
    .type frame_dispatch, @function

frame_dispatch:
    sts.l   pr, @-r15
    .byte   0xB1, 0xCC          /* bsr FUN_06005C98 (subsystem 1) */
    nop
    .byte   0xB0, 0x8F          /* bsr FUN_06005A22 (subsystem 2) */
    nop
    .byte   0xB0, 0x10          /* bsr FUN_06005928 (subsystem 3) */
    nop
    .byte   0xA0, 0xEE          /* bra FUN_06005AE8 (tail-call subsystem 4) */
    lds.l   @r15+, pr

    .byte   0x01, 0x10
    .global DAT_0600590e
DAT_0600590e:
    .byte   0x01, 0x4E
    .global DAT_06005910
DAT_06005910:
    .byte   0x10, 0x00
    .byte   0xFF, 0xFF
    .4byte  sym_06028430
    .4byte  sym_0607EAE0
    .4byte  sym_0607EA98
    .4byte  sym_06078644
    .4byte  sym_06028400
