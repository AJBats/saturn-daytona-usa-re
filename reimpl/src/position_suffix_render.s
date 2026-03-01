
    .section .text.FUN_06032656


    .global position_suffix_render
    .type position_suffix_render, @function
position_suffix_render:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x05    /* mov.l .L_pool_06032675, r13 */
    mov.l @r13, r13
    rts
    nop
    .2byte  0x0000
    .4byte  0x000002D4
    .4byte  0x0000000D
    .4byte  sym_06026DBC
.L_pool_06032675:
    .4byte  sym_06089EDC               /* [HIGH] matrix stack A pointer (VDP1 display list) */
    .4byte  sym_06026F72
    .4byte  0x000002DE
    .4byte  camera_push_save
    .4byte  0x00000030
    .4byte  sym_06026DF8
    .4byte  0xDD476DD2
    .4byte  0xDC47D048
