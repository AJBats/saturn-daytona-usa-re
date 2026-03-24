
    .section .text.FUN_060336AC


    .global FUN_060336AC
    .type FUN_060336AC, @function
FUN_060336AC:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06033550 - 4
    .2byte 0xB000    /* bsr FUN_06033550 (linker-resolved) */
    nop
    lds.l @r15+, pr
    mov.l @r15+, r0
    rts
    nop
    .2byte  0x0000
    .4byte  sym_0603386C
    .4byte  0x00000224
    .4byte  0x00000268
    .global FUN_060336C8
FUN_060336C8:
    .4byte  0x2F06D071
    .4byte  0x60004015
    .4byte  0x8B0CD06D
    .4byte  0x6001C810
    .4byte  0x8908D06C
    .4byte  0x60004015
    .4byte  0x89044315
    .4byte  0x8B026033
    .4byte  0x70FF6403
    .4byte  0x60F6000B
    .2byte 0x0009
    .global FUN_060336F2
FUN_060336F2:
    .2byte 0x2F06
    .4byte  0xD0626000
    .4byte  0x401560F6
    .4byte  0x000B0009
    .global FUN_06033700
FUN_06033700:
    .4byte  0x2F062F66
    .4byte  0x6E666D66
    .4byte  0x6C666B65
    .4byte  0x6A65D159
    .4byte  0x61124108
    .4byte  0x4108D030
    .4byte  0x301C7008
    .4byte  0x68066502
    .4byte  0x2F1664D3
    .2byte  0xD12D


    .global FUN_06033726
    .type FUN_06033726, @function
FUN_06033726:
    sts.l pr, @-r15
    jsr @r1
    nop
    lds.l @r15+, pr
    swap.w r0, r1
    exts.w r1, r13
    mov r14, r4
    mov r8, r5
    .byte   0xD1, 0x29    /* mov.l .L_pool_060337DC, r1 */
