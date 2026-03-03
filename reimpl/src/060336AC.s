
    .section .text.FUN_060336AC


    .global course_stats_display
    .type course_stats_display, @function
course_stats_display:
    sts.l pr, @-r15
    .byte   0xBF, 0x4F    /* bsr 0x06033550 (external) */
    nop
    lds.l @r15+, pr
    mov.l @r15+, r0
    rts
    nop
    .2byte  0x0000
    .4byte  sym_0603386C
    .4byte  0x00000224
    .4byte  0x00000268
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
    .4byte  0x00092F06
    .4byte  0xD0626000
    .4byte  0x401560F6
    .4byte  0x000B0009
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
