
    .section .text.FUN_0602E826


    .global billboard_facing
    .type billboard_facing, @function
billboard_facing:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xAF, 0xAD    /* bra 0x0602E78C (external) */
    nop
    .2byte  0x0000
    .4byte  0x00000050
    .4byte  0x00000000
    .4byte  0xAE1106FF
    .4byte  sound_cmd_dispatch
    .4byte  0xD404D505
    .2byte  0xDD05
