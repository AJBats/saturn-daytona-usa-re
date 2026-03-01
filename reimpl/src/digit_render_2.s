
    .section .text.FUN_06032530


    .global digit_render_2
    .type digit_render_2, @function
digit_render_2:
    sts.l pr, @-r15
    .byte   0xB4, 0xB7    /* bsr 0x06032EA4 (external) */
    nop
    lds.l @r15+, pr
    rts
    nop
    .4byte  0xD0026100
    .4byte  0x21188B03
    .4byte  0x000B0009
    .4byte  sym_06082A24
    .4byte  0xD00707ED
    .4byte  0xD607D208
    .4byte  0x27288900
    .4byte  0xD607D205
    .4byte  0x27288900
    .4byte  0xD606D007
    .4byte  0x01EE316C
    .4byte  0x000B0E16
    .4byte  0x0000000E
    .4byte  0x00000001
    .4byte  0x00000002
    .4byte  0xFFFFFFFF
    .4byte  0x00000000
    .4byte  0x000002C4
    .2byte  0xD010
