	.text
    .global rpm_gauge_render
rpm_gauge_render:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x03    /* mov.l .L_pool_06032A79, r13 */
    mov.l @r13, r13
    bra     .L_06032AE4
    nop
    .short  0x0000
    .long  sym_06026DBC
.L_pool_06032A79:
    .long  sym_06089EDC
    .long  0x00000018
    .long  sym_06026E2E
    .long  0x00000028
    .long  mat_rot_x
    .long  0x0000002C
    .long  mat_rot_z
    .long  0x0000002A
    .long  mat_rot_y
    .long  0x000000B4
    .long  0x00000024
    .long  0x0000002E
    .long  0x000000E4
    .long  0x00000030
    .long  0x00000114
    .long  sym_06026DF8
    .long  0x0000003C
    .long  0x00000032
    .long  0x00000036
    .long  0x00000034
    .long  0x00000144
    .long  0x00000048
    .long  0x00000038
    .long  0x00000174
    .long  0x00000054
    .long  0x0000003A
    .long  0x000001A4
.L_06032AE4:
    .byte   0xD0, 0x8E    /* mov.l .L_pool_06032D20, r0 */
    add r12, r0
    mov.l @r0+, r4
    mov.l @r0+, r5
    mov.l @r0+, r6
    .byte   0xD0, 0x8D    /* mov.l .L_pool_06032D24, r0 */
