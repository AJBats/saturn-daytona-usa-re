
    .section .text.FUN_06032A62


    .global rpm_gauge_render
    .type rpm_gauge_render, @function
rpm_gauge_render:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x03    /* mov.l .L_pool_06032A79, r13 */
    mov.l @r13, r13
    bra     .L_06032AE4
    nop
    .2byte  0x0000
    .4byte  sym_06026DBC
.L_pool_06032A79:
    .4byte  sym_06089EDC
    .4byte  0x00000018
    .4byte  sym_06026E2E
    .4byte  0x00000028
    .4byte  mat_rot_x
    .4byte  0x0000002C
    .4byte  mat_rot_z
    .4byte  0x0000002A
    .4byte  mat_rot_y
    .4byte  0x000000B4
    .4byte  0x00000024
    .4byte  0x0000002E
    .4byte  0x000000E4
    .4byte  0x00000030
    .4byte  0x00000114
    .4byte  sym_06026DF8
    .4byte  0x0000003C
    .4byte  0x00000032
    .4byte  0x00000036
    .4byte  0x00000034
    .4byte  0x00000144
    .4byte  0x00000048
    .4byte  0x00000038
    .4byte  0x00000174
    .4byte  0x00000054
    .4byte  0x0000003A
    .4byte  0x000001A4
.L_06032AE4:
    .byte   0xD0, 0x8E    /* mov.l .L_pool_06032D20, r0 */
    add r12, r0
    mov.l @r0+, r4
    mov.l @r0+, r5
    mov.l @r0+, r6
    .byte   0xD0, 0x8D    /* mov.l .L_pool_06032D24, r0 */
