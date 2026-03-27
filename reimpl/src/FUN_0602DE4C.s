
    .section .text.FUN_0602DE4C


    .global FUN_0602DE4C
    .type FUN_0602DE4C, @function
FUN_0602DE4C:
    sts.l pr, @-r15
    jsr @r12
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x14    /* mov.l .L_pool_0602DEA8, r0 */
    cmp/ge r0, r1
    bt      .L_0602DE5C
    neg r1, r1
.L_0602DE5C:
    .byte   0xD0, 0x1E    /* mov.l .L_pool_0602DED8, r0 */
    mov.l r1, @r0

    .global FUN_0602DE60
FUN_0602DE60:
    .byte   0xDD, 0x1E    /* mov.l .L_pool_0602DEDC, r13 */


    .global FUN_0602DE62
    .type FUN_0602DE62, @function
FUN_0602DE62:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    mov.l   .L_0602DE84, r2
    mov.l @r2, r0
    tst r0, r0
    bf      .L_0602DEE0
    bra     .L_0602E05A
    nop
    .4byte  sym_06082A30
    .4byte  0x00000002
    .4byte  sym_06082A3C
.L_0602DE84:
    .4byte  sym_06082A40
    .4byte  sym_06082A54
    .4byte  sym_06082A58
    .4byte  sym_06082A44
    .4byte  sym_06082A48
    .4byte  sym_06082A50
    .4byte  0x00000010
    .4byte  sym_06082A70
    .4byte  sym_06034FFC
    .4byte  0x00000000
    .4byte  sym_06082A6C
    .4byte  0x00000008
    .4byte  sym_06082A78
    .4byte  sym_06082A74
    .4byte  0x00000004
    .4byte  sym_06063EEC
    .4byte  sym_06082A5C
    .4byte  sym_06063EF0
    .4byte  sym_06082A60
    .4byte  0x00000001
    .4byte  sym_06063E24
    .4byte  sym_06082A68
    .4byte  FUN_06012AFA
.L_0602DEE0:
    add #-0x1, r0
    mov.l r0, @r2
    mov.l   .L_0602DF0C, r2
    mov.l @r2, r4
    mov r4, r0
    mov.l   .L_0602DF10, r1
    tst r1, r0
    bt      .L_0602DF36
    mov.l   .L_0602DF14, r0
    mov.l @r0, r3
    mov.l   .L_0602DF18, r1
    mov.l @r1, r2
    cmp/ge r2, r3
    bt      .L_0602DF20
    mov.l   .L_0602DF1C, r0
    mov.l @r0, r0
    sub r0, r2
    cmp/ge r3, r2
    bt      .L_0602DF34
    bra     .L_0602DF2A
    nop
    .2byte  0x0000
.L_0602DF0C:
    .4byte  sym_06082A3C
.L_0602DF10:
    .4byte  0x00000010
.L_0602DF14:
    .4byte  sym_06082A54
.L_0602DF18:
    .4byte  sym_06082A70
.L_0602DF1C:
    .4byte  sym_06082A6C
.L_0602DF20:
    mov.l   .L_0602DF30, r0
    mov.l @r0, r0
    add r0, r2
    cmp/ge r2, r3
    bt      .L_0602DF34
.L_0602DF2A:
    mov.l r3, @r1
    bra     .L_0602DF36
    nop
.L_0602DF30:
    .4byte  sym_06082A6C
.L_0602DF34:
    mov.l r2, @r1
.L_0602DF36:
    mov r4, r0
    mov.l   .L_0602DF58, r1
    tst r1, r0
    bt      .L_0602DF7E
    mov.l   .L_0602DF5C, r0
    mov.l @r0, r3
    mov.l   .L_0602DF60, r1
    mov.l @r1, r2
    cmp/ge r2, r3
    bt      .L_0602DF68
    mov.l   .L_0602DF64, r0
    mov.l @r0, r0
    sub r0, r2
    cmp/ge r3, r2
    bt      .L_0602DF7C
    bra     .L_0602DF72
    nop
.L_0602DF58:
    .4byte  0x00000008
.L_0602DF5C:
    .4byte  sym_06082A58
.L_0602DF60:
    .4byte  sym_06082A78
.L_0602DF64:
    .4byte  sym_06082A74
.L_0602DF68:
    mov.l   .L_0602DF78, r0
    mov.l @r0, r0
    add r0, r2
    cmp/ge r2, r3
    bt      .L_0602DF7C
.L_0602DF72:
    mov.l r3, @r1
    bra     .L_0602DF7E
    nop
.L_0602DF78:
    .4byte  sym_06082A74
.L_0602DF7C:
    mov.l r2, @r1
.L_0602DF7E:
    mov r4, r0
    mov.l   .L_0602DFA0, r1
    tst r1, r0
    bt      .L_0602DFC6
    mov.l   .L_0602DFA4, r0
    mov.l @r0, r3
    mov.l   .L_0602DFA8, r1
    mov.l @r1, r2
    cmp/ge r2, r3
    bt      .L_0602DFB0
    mov.l   .L_0602DFAC, r0
    mov.l @r0, r0
    sub r0, r2
    cmp/ge r3, r2
    bt      .L_0602DFC4
    bra     .L_0602DFBA
    nop
.L_0602DFA0:
    .4byte  0x00000004
.L_0602DFA4:
    .4byte  sym_06082A44
.L_0602DFA8:
    .4byte  sym_06063EEC
.L_0602DFAC:
    .4byte  sym_06082A5C
.L_0602DFB0:
    mov.l   .L_0602DFC0, r0
    mov.l @r0, r0
    add r0, r2
    cmp/ge r2, r3
    bt      .L_0602DFC4
.L_0602DFBA:
    mov.l r3, @r1
    bra     .L_0602DFC6
    nop
.L_0602DFC0:
    .4byte  sym_06082A5C
.L_0602DFC4:
    mov.l r2, @r1
.L_0602DFC6:
    mov r4, r0
    mov.l   .L_0602DFE8, r1
    tst r1, r0
    bt      .L_0602E00E
    mov.l   .L_0602DFEC, r0
    mov.l @r0, r3
    mov.l   .L_0602DFF0, r1
    mov.l @r1, r2
    cmp/ge r2, r3
    bt      .L_0602DFF8
    mov.l   .L_0602DFF4, r0
    mov.l @r0, r0
    sub r0, r2
    cmp/ge r3, r2
    bt      .L_0602E00C
    bra     .L_0602E002
    nop
.L_0602DFE8:
    .4byte  0x00000002
.L_0602DFEC:
    .4byte  sym_06082A48
.L_0602DFF0:
    .4byte  sym_06063EF0
.L_0602DFF4:
    .4byte  sym_06082A60
.L_0602DFF8:
    mov.l   .L_0602E008, r0
    mov.l @r0, r0
    add r0, r2
    cmp/ge r2, r3
    bt      .L_0602E00C
.L_0602E002:
    mov.l r3, @r1
    bra     .L_0602E00E
    nop
.L_0602E008:
    .4byte  sym_06082A60
.L_0602E00C:
    mov.l r2, @r1
.L_0602E00E:
    mov r4, r0
    mov.l   .L_0602E030, r1
    tst r1, r0
    bt      .L_0602E056
    mov.l   .L_0602E034, r0
    mov.l @r0, r3
    mov.l   .L_0602E038, r1
    mov.l @r1, r2
    cmp/ge r2, r3
    bt      .L_0602E040
    mov.l   .L_0602E03C, r0
    mov.l @r0, r0
    sub r0, r2
    cmp/ge r3, r2
    bt      .L_0602E054
    bra     .L_0602E04A
    nop
.L_0602E030:
    .4byte  0x00000001
.L_0602E034:
    .4byte  sym_06082A50
.L_0602E038:
    .4byte  sym_06063E24
.L_0602E03C:
    .4byte  sym_06082A68
.L_0602E040:
    mov.l   .L_0602E050, r0
    mov.l @r0, r0
    add r0, r2
    cmp/ge r2, r3
    bt      .L_0602E054
.L_0602E04A:
    mov.l r3, @r1
    bra     .L_0602E056
    nop
.L_0602E050:
    .4byte  sym_06082A68
.L_0602E054:
    mov.l r2, @r1
.L_0602E056:
    rts
    nop
.L_0602E05A:
    mov.l   .L_0602E06C, r1
    mov.l @r1, r0
    add #0x1, r0
    mov.l r0, @r1
    mov.l   .L_0602E070, r1
    mov.l   .L_0602E074, r0
    mov.l r0, @r1
    .reloc ., R_SH_IND12W, FUN_0602DD10 - 4
    .2byte 0xA000    /* bra FUN_0602DD10 (linker-resolved) */
    nop
.L_0602E06C:
    .4byte  sym_06082A38
.L_0602E070:
    .4byte  sym_06082A30
.L_0602E074:
    .4byte  0x00000001

    .global FUN_0602E078
FUN_0602E078:
    .byte   0xDD, 0x12    /* mov.l .L_pool_0602E0C4, r13 */

    .global FUN_0602E07A
    .type FUN_0602E07A, @function
FUN_0602E07A:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    mov.l   .L_0602E0C8, r4
    mov.l @r4, r3
    mov.l   .L_0602E0CC, r4
    mov.l r3, @r4
    mov.l   .L_0602E0D0, r4
    mov.l @r4, r3
    mov.l   .L_0602E0D4, r4
    mov.l r3, @r4
    mov.l   .L_0602E0D8, r4
    mov.l @r4, r3
    mov.l   .L_0602E0DC, r4
    mov.l r3, @r4
    mov.l   .L_0602E0E0, r4
    mov.l @r4, r3
    exts.w r3, r3
    mov.l   .L_0602E0E4, r4
    mov.l r3, @r4
    mov.l   .L_0602E0E8, r4
    mov.l @r4, r3
    mov.l   .L_0602E0EC, r4
    mov.l r3, @r4
    mov.l   .L_0602E0F0, r0
    mov.l   .L_0602E0F4, r1
    mov.l r1, @r0
    mov.l   .L_0602E0F8, r4
    mov.l   .L_0602E0FC, r3
    mov.l r3, @r4
    mov.l   .L_0602E100, r4
    mov.l   .L_0602E104, r3
    mov.l r3, @r4
    rts
    nop
    .4byte  FUN_06012AC4
.L_0602E0C8:
    .4byte  sym_06082A54
.L_0602E0CC:
    .4byte  sym_06082A70
.L_0602E0D0:
    .4byte  sym_06082A58
.L_0602E0D4:
    .4byte  sym_06082A78
.L_0602E0D8:
    .4byte  sym_06082A44
.L_0602E0DC:
    .4byte  sym_06063EEC
.L_0602E0E0:
    .4byte  sym_06082A48
.L_0602E0E4:
    .4byte  sym_06063EF0
.L_0602E0E8:
    .4byte  sym_06082A50
.L_0602E0EC:
    .4byte  sym_06063E24
.L_0602E0F0:
    .4byte  sym_06082A30
.L_0602E0F4:
    .4byte  0x00000004
.L_0602E0F8:
    .4byte  sym_06063E34
.L_0602E0FC:
    .4byte  0x0000F300
.L_0602E100:
    .4byte  sym_06063E28
.L_0602E104:
    .4byte  0x006E0000

    .global FUN_0602E108
FUN_0602E108:
    mov.l   .L_0602E148, r1
    mov.w   .L_0602E13E, r3
    mov.l r3, @r1
    mov.l   .L_0602E14C, r1
    mov.l   .L_0602E150, r3
    mov.l r3, @r1
    mov.l   .L_0602E154, r1
    mov.l @r1, r2
    mov.l   .L_0602E158, r1
    mov.l r2, @r1
    mov.l   .L_0602E15C, r1
    mov.l   .L_0602E160, r2
    mov.l r2, @r1
    mov.w   .L_0602E140, r3
    mov.l   .L_0602E164, r1
    mov.l r3, @r1
    mov.l   .L_0602E168, r0
    mov.l @r0, r0
    mov.w   .L_0602E13E, r3
    mov.w   .L_0602E142, r1
    mov.l r3, @(r0, r1)
    mov.w   .L_0602E144, r1
    mov.w r3, @(r0, r1)
    mov.w   .L_0602E146, r1
    mov.w r3, @(r0, r1)
    rts
    nop
.L_0602E13E:
    .2byte  0x0000
.L_0602E140:
    .2byte  0x0001
.L_0602E142:
    .2byte  0x01B4
.L_0602E144:
    .2byte  0x00DC
.L_0602E146:
    .2byte  0x00DE
.L_0602E148:
    .4byte  sym_0605A1C4
.L_0602E14C:
    .4byte  sym_0605A1D0
.L_0602E150:
    .4byte  0x00010000
.L_0602E154:
    .4byte  sym_06082A34
.L_0602E158:
    .4byte  sym_06063E20
.L_0602E15C:
    .4byte  sym_06082A30
.L_0602E160:
    .4byte  0x00000000
.L_0602E164:
    .4byte  sym_0607EAC8
.L_0602E168:
    .4byte  sym_0607E940
    .global FUN_0602E16C
FUN_0602E16C:
    .4byte  0xD10E6312
    .4byte  0x23388907
    .4byte  0x6033D20D
    .4byte  0x4008022E
    .4byte  0xD00C2022
    .4byte  0x73FF2132
    .4byte  0xD00B6002
    .2byte  0xDD0B

    .global FUN_0602E18A
    .type FUN_0602E18A, @function
FUN_0602E18A:
    sts.l pr, @-r15
    jsr @r13
    nop
    lds.l @r15+, pr
    nop
    mov.l   .L_pool_0602E1B4, r0
    mov.l @r0, r0
    mov.l   .L_pool_0602E1BC, r1
    mov.l @(r0, r1), r3
    mov.l   .L_pool_0602E1C0, r1
    cmp/ge r1, r3
    bf      .L_0602E1C4
    .reloc ., R_SH_IND12W, FUN_0602E3A0 - 4
    .2byte 0xA000    /* bra FUN_0602E3A0 (linker-resolved) */
    nop
    .2byte  0x0000
    .4byte  sym_0608325C
    .4byte  sym_0602EC54
    .4byte  sym_06083258
.L_pool_0602E1B4:
    .4byte  sym_0607E940
    .4byte  sym_0600DB64
.L_pool_0602E1BC:
    .4byte  0x00000244
.L_pool_0602E1C0:
    .4byte  0x00000007
.L_0602E1C4:
    .byte   0xD3, 0x34    /* mov.l .L_pool_0602E298, r3 */
    mov.l @r3, r3
    .byte   0xD1, 0x34    /* mov.l .L_pool_0602E29C, r1 */
    sub r1, r3
    .byte   0xD4, 0x34    /* mov.l .L_pool_0602E2A0, r4 */
    cmp/eq r3, r4
    bf      .L_0602E1F8
    .byte   0x91, 0x57    /* mov.w .L_wpool_0602E284, r1 */
    mov.l @(r0, r1), r3
    .byte   0x92, 0x56    /* mov.w .L_wpool_0602E286, r2 */
    not r2, r2
    and r2, r3
    .byte   0x92, 0x54    /* mov.w .L_wpool_0602E288, r2 */
    not r2, r2
    and r2, r3
    .byte   0x92, 0x52    /* mov.w .L_wpool_0602E28A, r2 */
    not r2, r2
    and r2, r3
    .byte   0x92, 0x50    /* mov.w .L_wpool_0602E28C, r2 */
    not r2, r2
    and r2, r3
    mov.l r3, @(r0, r1)
    .byte   0xD1, 0x29    /* mov.l .L_pool_0602E298, r1 */
    mov.l @r1, r3
    .byte   0xD2, 0x29    /* mov.l .L_pool_0602E29C, r2 */
    sub r2, r3
.L_0602E1F8:
    .byte   0xD1, 0x27    /* mov.l .L_pool_0602E298, r1 */
    mov.l r3, @r1
    .byte   0x91, 0x47    /* mov.w .L_wpool_0602E28E, r1 */
    mov.l @(r0, r1), r3
    .byte   0xD2, 0x28    /* mov.l .L_pool_0602E2A4, r2 */
    cmp/eq r2, r3
    bt      .L_0602E20C
    .byte   0xD2, 0x25    /* mov.l .L_pool_0602E29C, r2 */
    sub r2, r3
    mov.l r3, @(r0, r1)
.L_0602E20C:
    .byte   0xD3, 0x25    /* mov.l .L_pool_0602E2A4, r3 */
    .byte   0xD1, 0x26    /* mov.l .L_pool_0602E2A8, r1 */
    mov.l r3, @(r0, r1)
    .byte   0xDD, 0x26    /* mov.l .L_pool_0602E2AC, r13 */
