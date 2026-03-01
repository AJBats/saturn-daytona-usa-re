
    .section .text.FUN_0602E870


    .global billboard_uv_map
    .type billboard_uv_map, @function
billboard_uv_map:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xAF, 0x88    /* bra 0x0602E78C (external) */
    nop
    .4byte  0x00000050
    .4byte  0x00000000
    .4byte  0xAE1105FF
    .4byte  sound_cmd_dispatch
    .4byte  0xD404D505
    .2byte  0xDD05
