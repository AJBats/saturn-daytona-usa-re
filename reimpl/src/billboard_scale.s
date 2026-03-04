
    .section .text.FUN_0602E84A


    .global billboard_scale
    .type billboard_scale, @function
billboard_scale:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .reloc ., R_SH_IND12W, FUN_0602E78C - 4
    .2byte 0xA000    /* bra FUN_0602E78C (linker-resolved) */
    nop
    .2byte  0x0000
    .4byte  0x00000000
    .4byte  0xAE110AFF
    .4byte  sound_cmd_dispatch
    .4byte  0xD3053833
    .4byte  0x8910D405
    .4byte  0xD505DD06
