
    .section .text.FUN_0602DB22


    .global vdp1_cmd_list_reset
    .type vdp1_cmd_list_reset, @function
vdp1_cmd_list_reset:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x2A    /* mov.l .L_pool_0602DBD4, r4 */
    .byte   0xD1, 0x26    /* mov.l .L_pool_0602DBC8, r1 */
    mov.l r1, @r4
    .byte   0xD4, 0x29    /* mov.l .L_pool_0602DBD8, r4 */
    mov.b r1, @r4
    .byte   0xD4, 0x29    /* mov.l .L_pool_0602DBDC, r4 */
    mov.l r1, @r4
    .byte   0xD4, 0x29    /* mov.l .L_pool_0602DBE0, r4 */
    mov.l r1, @r4
    .byte   0xD0, 0x29    /* mov.l .L_pool_0602DBE4, r0 */
    mov.l @r0, r0
    .byte   0xD3, 0x29    /* mov.l .L_pool_0602DBE8, r3 */
    .byte   0xD1, 0x2A    /* mov.l .L_pool_0602DBEC, r1 */
    mov.l r3, @r1
    .byte   0xD3, 0x20    /* mov.l .L_pool_0602DBC8, r3 */
    mov.w   DAT_0602dbac, r1
    mov.l r3, @(r0, r1)
    mov.w   DAT_0602dbae, r1
    mov.l r3, @(r0, r1)
    mov.w   DAT_0602dbb0, r1
    mov.l r3, @(r0, r1)
    mov.w   DAT_0602dbb2, r1
    mov.l r3, @(r0, r1)
    .byte   0xD1, 0x25    /* mov.l .L_pool_0602DBF0, r1 */
    mov.l r3, @r1
    mov.w   DAT_0602dbb4, r1
    mov.l r3, @(r0, r1)
    mov.w   DAT_0602dbb6, r1
    mov.l r3, @(r0, r1)
    mov.w   DAT_0602dbb8, r1
    mov.l @(r0, r1), r3
    mov.w   DAT_0602dbba, r1
    mov.l r3, @(r0, r1)
    mov.w   DAT_0602dbbc, r1
    mov.l r3, @(r0, r1)
    .byte   0xD3, 0x15    /* mov.l .L_pool_0602DBC8, r3 */
    mov.w   DAT_0602dbbe, r1
    mov.l r3, @(r0, r1)
    .byte   0xD5, 0x1F    /* mov.l .L_pool_0602DBF4, r5 */
    .byte   0xD6, 0x1F    /* mov.l .L_pool_0602DBF8, r6 */
    dmuls.l r5, r6
    sts mach, r5
    sts macl, r6
    xtrct r5, r6
    mov.w   DAT_0602dbc0, r1
    mov.l @(r0, r1), r3
    .byte   0xD4, 0x1D    /* mov.l .L_pool_0602DBFC, r4 */
    cmp/gt r3, r4
    bt      .L_0602DB90
    .byte   0xD1, 0x1C    /* mov.l .L_pool_0602DC00, r1 */
    mov.l r6, @(r0, r1)
.L_0602DB90:
    .byte   0xD1, 0x1C    /* mov.l .L_pool_0602DC04, r1 */
    mov.l r6, @(r0, r1)
    .byte   0xD1, 0x1C    /* mov.l .L_pool_0602DC08, r1 */
    mov.w   DAT_0602dbc2, r2
    mov.l r2, @r1
    .byte   0xD1, 0x1C    /* mov.l .L_pool_0602DC0C, r1 */
    mov.l @r1, r2
    .byte   0xD1, 0x1C    /* mov.l .L_pool_0602DC10, r1 */
    mov.l r2, @r1
    .byte   0xD1, 0x1C    /* mov.l .L_pool_0602DC14, r1 */
    mov.w   DAT_0602dbc2, r2
    mov.l r2, @r1
    .byte   0xA0, 0x3D    /* bra 0x0602DC26 (external) */
    nop

    .global DAT_0602dbac
DAT_0602dbac:
    .2byte  0x0114

    .global DAT_0602dbae
DAT_0602dbae:
    .2byte  0x00D0

    .global DAT_0602dbb0
DAT_0602dbb0:
    .2byte  0x0040

    .global DAT_0602dbb2
DAT_0602dbb2:
    .2byte  0x0244

    .global DAT_0602dbb4
DAT_0602dbb4:
    .2byte  0x0058

    .global DAT_0602dbb6
DAT_0602dbb6:
    .2byte  0x005C

    .global DAT_0602dbb8
DAT_0602dbb8:
    .2byte  0x025C

    .global DAT_0602dbba
DAT_0602dbba:
    .2byte  0x0030

    .global DAT_0602dbbc
DAT_0602dbbc:
    .2byte  0x0028

    .global DAT_0602dbbe
DAT_0602dbbe:
    .2byte  0x0148

    .global DAT_0602dbc0
DAT_0602dbc0:
    .2byte  0x0008

    .global DAT_0602dbc2
DAT_0602dbc2:
    .2byte  0x0002
    .4byte  0x00000002
.L_pool_0602DBC8:
    .4byte  0x00000000
    .4byte  sound_cmd_dispatch
    .4byte  0x00000003
.L_pool_0602DBD4:
    .4byte  sym_06082A30
.L_pool_0602DBD8:
    .4byte  sym_06082A26
.L_pool_0602DBDC:
    .4byte  sym_060788FC
.L_pool_0602DBE0:
    .4byte  sym_06082A38
.L_pool_0602DBE4:
    .4byte  sym_0607E940
.L_pool_0602DBE8:
    .4byte  0x000000C8
.L_pool_0602DBEC:
    .4byte  sym_0607EAC8
.L_pool_0602DBF0:
    .4byte  sym_06082A2C
.L_pool_0602DBF4:
    .4byte  0x00FA0000
.L_pool_0602DBF8:
    .4byte  0x0000038E
.L_pool_0602DBFC:
    .4byte  0x000000FA
.L_pool_0602DC00:
    .4byte  0x0000000C
.L_pool_0602DC04:
    .4byte  0x00000194
.L_pool_0602DC08:
    .4byte  sym_0605A1C4
.L_pool_0602DC0C:
    .4byte  sym_06063E1C
.L_pool_0602DC10:
    .4byte  sym_06082A34
.L_pool_0602DC14:
    .4byte  sym_06063E20

    .global sym_0602DC18
sym_0602DC18:
    mov.l r8, @-r15
    mov.l r9, @-r15
    mov.l r10, @-r15
    mov.l r11, @-r15
    mov.l r12, @-r15
    mov.l r13, @-r15
