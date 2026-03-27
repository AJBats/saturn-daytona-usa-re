
    .section .text.FUN_06032694


    .global FUN_06032694
    .type FUN_06032694, @function
FUN_06032694:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x43    /* mov.l .L_pool_060327AC, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x45    /* mov.l .L_pool_060327B8, r0 */


    .global FUN_060326A2
    .type FUN_060326A2, @function
FUN_060326A2:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x40    /* mov.l .L_pool_060327AC, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x43    /* mov.l .L_pool_060327BC, r0 */
    mov.l @(r0, r14), r4
    .byte   0xD0, 0x43    /* mov.l .L_pool_060327C0, r0 */
    mov.l @(r0, r14), r5
    .byte   0xD0, 0x43    /* mov.l .L_pool_060327C4, r0 */
    mov.l @(r0, r14), r6
    .byte   0xD0, 0x43    /* mov.l .L_pool_060327C8, r0 */


    .global FUN_060326BC
    .type FUN_060326BC, @function
FUN_060326BC:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x41    /* mov.l .L_pool_060327CC, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x41    /* mov.l .L_pool_060327D0, r0 */


    .global FUN_060326CA
    .type FUN_060326CA, @function
FUN_060326CA:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x40    /* mov.l .L_pool_060327D4, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x40    /* mov.l .L_pool_060327D8, r0 */

    .global FUN_060326D8
    .type FUN_060326D8, @function
FUN_060326D8:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x3E    /* mov.l .L_pool_060327DC, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x3E    /* mov.l .L_pool_060327E0, r0 */


    .global FUN_060326E6
    .type FUN_060326E6, @function
FUN_060326E6:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r13, r1
    .byte   0xD0, 0x3C    /* mov.l .L_pool_060327E4, r0 */
    add r14, r0
    mov.l @r1+, r2
    mov.l r2, @(0, r0)
    mov.l @r1+, r2
    mov.l r2, @(4, r0)
    mov.l @r1+, r2
    mov.l r2, @(8, r0)
    mov.l @r1+, r2
    mov.l r2, @(12, r0)
    mov.l @r1+, r2
    mov.l r2, @(16, r0)
    mov.l @r1+, r2
    mov.l r2, @(20, r0)
    mov.l @r1+, r2
    mov.l r2, @(24, r0)
    mov.l @r1+, r2
    mov.l r2, @(28, r0)
    mov.l @r1+, r2
    mov.l r2, @(32, r0)
    mov.l @r1+, r2
    mov.l r2, @(36, r0)
    mov.l @r1+, r2
    mov.l r2, @(40, r0)
    mov.l @r1, r2
    mov.l r2, @(44, r0)
    .byte   0xD0, 0x23    /* mov.l .L_pool_060327B4, r0 */

    .global FUN_06032726
    .type FUN_06032726, @function
FUN_06032726:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x1F    /* mov.l .L_pool_060327AC, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x2D    /* mov.l .L_pool_060327E8, r0 */
    add r12, r0
    mov.l @r0+, r4
    mov.l @r0+, r5
    mov.l @r0+, r6
    .byte   0xD0, 0x22    /* mov.l .L_pool_060327C8, r0 */

    .global FUN_0603273E
    .type FUN_0603273E, @function
FUN_0603273E:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x29    /* mov.l .L_pool_060327EC, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x23    /* mov.l .L_pool_060327D8, r0 */

    .global FUN_0603274C
    .type FUN_0603274C, @function
FUN_0603274C:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x26    /* mov.l .L_pool_060327F0, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x21    /* mov.l .L_pool_060327E0, r0 */


    .global FUN_0603275A
    .type FUN_0603275A, @function
FUN_0603275A:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x24    /* mov.l .L_pool_060327F4, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x1A    /* mov.l .L_pool_060327D0, r0 */

    .global FUN_06032768
    .type FUN_06032768, @function
FUN_06032768:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r13, r1
    mov.l   .L_pool_060327F8, r0
    add r14, r0
    mov.l @r1+, r2
    mov.l r2, @(0, r0)
    mov.l @r1+, r2
    mov.l r2, @(4, r0)
    mov.l @r1+, r2
    mov.l r2, @(8, r0)
    mov.l @r1+, r2
    mov.l r2, @(12, r0)
    mov.l @r1+, r2
    mov.l r2, @(16, r0)
    mov.l @r1+, r2
    mov.l r2, @(20, r0)
    mov.l @r1+, r2
    mov.l r2, @(24, r0)
    mov.l @r1+, r2
    mov.l r2, @(28, r0)
    mov.l @r1+, r2
    mov.l r2, @(32, r0)
    mov.l @r1+, r2
    mov.l r2, @(36, r0)
    mov.l @r1+, r2
    mov.l r2, @(40, r0)
    mov.l @r1, r2
    mov.l r2, @(44, r0)
    bra     .L_060327FC
    nop
    .2byte  0x0000
    .4byte  sym_06089EDC
    .4byte  sym_060623C8
    .4byte  sym_06026DBC
    .4byte  sym_06026E0C
    .4byte  0x00000010
    .4byte  0x00000014
    .4byte  0x00000018
    .4byte  sym_06026E2E
    .4byte  0x0000001E
    .4byte  FUN_06026EDE
    .4byte  0x0000001C
    .4byte  FUN_06026E94
    .4byte  0x00000020
    .4byte  FUN_06026F2A
    .4byte  0x00000054
    .4byte  0x0000000C
    .4byte  0x00000022
    .4byte  0x00000026
    .4byte  0x00000024
.L_pool_060327F8:
    .4byte  0x00000084
.L_060327FC:
    .byte   0xD0, 0x9D    /* mov.l @cross-TU pool (render pipeline dispatch), r0 */


    .global FUN_060327FE
    .type FUN_060327FE, @function
FUN_060327FE:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x9C    /* mov.l .L_pool_06032A78, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x9C    /* mov.l .L_pool_06032A7C, r0 */
    add r12, r0
    mov.l @r0+, r4
    mov.l @r0+, r5
    mov.l @r0+, r6
    .byte   0xD0, 0x9A    /* mov.l .L_pool_06032A80, r0 */

    .global FUN_06032816
    .type FUN_06032816, @function
FUN_06032816:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x99    /* mov.l .L_pool_06032A84, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x99    /* mov.l .L_pool_06032A88, r0 */

    .global FUN_06032824
    .type FUN_06032824, @function
FUN_06032824:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x97    /* mov.l .L_pool_06032A8C, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x97    /* mov.l .L_pool_06032A90, r0 */


    .global FUN_06032832
    .type FUN_06032832, @function
FUN_06032832:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x96    /* mov.l .L_pool_06032A94, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x96    /* mov.l .L_pool_06032A98, r0 */

    .global FUN_06032840
    .type FUN_06032840, @function
FUN_06032840:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r13, r1
    .byte   0xD0, 0x94    /* mov.l .L_pool_06032A9C, r0 */
    add r14, r0
    mov.l @r1+, r2
    mov.l r2, @(0, r0)
    mov.l @r1+, r2
    mov.l r2, @(4, r0)
    mov.l @r1+, r2
    mov.l r2, @(8, r0)
    mov.l @r1+, r2
    mov.l r2, @(12, r0)
    mov.l @r1+, r2
    mov.l r2, @(16, r0)
    mov.l @r1+, r2
    mov.l r2, @(20, r0)
    mov.l @r1+, r2
    mov.l r2, @(24, r0)
    mov.l @r1+, r2
    mov.l r2, @(28, r0)
    mov.l @r1+, r2
    mov.l r2, @(32, r0)
    mov.l @r1+, r2
    mov.l r2, @(36, r0)
    mov.l @r1+, r2
    mov.l r2, @(40, r0)
    mov.l @r1, r2
    mov.l r2, @(44, r0)
    .byte   0xD0, 0x88    /* mov.l .L_pool_06032AA0, r0 */
    add r12, r0
    mov.l @r0+, r4
    mov.l @r0+, r5
    mov.l @r0+, r6
    .byte   0xD0, 0x7D    /* mov.l .L_pool_06032A80, r0 */


    .global FUN_0603288A
    .type FUN_0603288A, @function
FUN_0603288A:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x84    /* mov.l .L_pool_06032AA4, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x7E    /* mov.l .L_pool_06032A90, r0 */

    .global FUN_06032898
    .type FUN_06032898, @function
FUN_06032898:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r13, r1
    .byte   0xD0, 0x81    /* mov.l .L_pool_06032AA8, r0 */
    add r14, r0
    mov.l @r1+, r2
    mov.l r2, @(0, r0)
    mov.l @r1+, r2
    mov.l r2, @(4, r0)
    mov.l @r1+, r2
    mov.l r2, @(8, r0)
    mov.l @r1+, r2
    mov.l r2, @(12, r0)
    mov.l @r1+, r2
    mov.l r2, @(16, r0)
    mov.l @r1+, r2
    mov.l r2, @(20, r0)
    mov.l @r1+, r2
    mov.l r2, @(24, r0)
    mov.l @r1+, r2
    mov.l r2, @(28, r0)
    mov.l @r1+, r2
    mov.l r2, @(32, r0)
    mov.l @r1+, r2
    mov.l r2, @(36, r0)
    mov.l @r1+, r2
    mov.l r2, @(40, r0)
    mov.l @r1, r2
    mov.l r2, @(44, r0)
    .byte   0xD0, 0x75    /* mov.l .L_pool_06032AAC, r0 */
    add r12, r0
    mov.l @r0+, r4
    mov.l @r0+, r5
    mov.l @r0+, r6
    .byte   0xD0, 0x67    /* mov.l .L_pool_06032A80, r0 */


    .global FUN_060328E2
    .type FUN_060328E2, @function
FUN_060328E2:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x70    /* mov.l .L_pool_06032AAC, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x68    /* mov.l .L_pool_06032A90, r0 */

    .global FUN_060328F0
    .type FUN_060328F0, @function
FUN_060328F0:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r13, r1
    .byte   0xD0, 0x6D    /* mov.l .L_pool_06032AB0, r0 */
    add r14, r0
    mov.l @r1+, r2
    mov.l r2, @(0, r0)
    mov.l @r1+, r2
    mov.l r2, @(4, r0)
    mov.l @r1+, r2
    mov.l r2, @(8, r0)
    mov.l @r1+, r2
    mov.l r2, @(12, r0)
    mov.l @r1+, r2
    mov.l r2, @(16, r0)
    mov.l @r1+, r2
    mov.l r2, @(20, r0)
    mov.l @r1+, r2
    mov.l r2, @(24, r0)
    mov.l @r1+, r2
    mov.l r2, @(28, r0)
    mov.l @r1+, r2
    mov.l r2, @(32, r0)
    mov.l @r1+, r2
    mov.l r2, @(36, r0)
    mov.l @r1+, r2
    mov.l r2, @(40, r0)
    mov.l @r1, r2
    mov.l r2, @(44, r0)
    .byte   0xD0, 0x61    /* mov.l .L_pool_06032AB4, r0 */

    .global FUN_06032930
    .type FUN_06032930, @function
FUN_06032930:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x4F    /* mov.l .L_pool_06032A78, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x5E    /* mov.l .L_pool_06032AB8, r0 */
    add r12, r0
    mov.l @r0+, r4
    mov.l @r0+, r5
    mov.l @r0+, r6
    .byte   0xD0, 0x4E    /* mov.l .L_pool_06032A80, r0 */

    .global FUN_06032948
    .type FUN_06032948, @function
FUN_06032948:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x5A    /* mov.l .L_pool_06032ABC, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x4C    /* mov.l .L_pool_06032A88, r0 */


    .global FUN_06032956
    .type FUN_06032956, @function
FUN_06032956:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x58    /* mov.l .L_pool_06032AC0, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x4B    /* mov.l .L_pool_06032A90, r0 */

    .global FUN_06032964
    .type FUN_06032964, @function
FUN_06032964:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x55    /* mov.l .L_pool_06032AC4, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x49    /* mov.l .L_pool_06032A98, r0 */


    .global FUN_06032972
    .type FUN_06032972, @function
FUN_06032972:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r13, r1
    .byte   0xD0, 0x52    /* mov.l .L_pool_06032AC8, r0 */
    add r14, r0
    mov.l @r1+, r2
    mov.l r2, @(0, r0)
    mov.l @r1+, r2
    mov.l r2, @(4, r0)
    mov.l @r1+, r2
    mov.l r2, @(8, r0)
    mov.l @r1+, r2
    mov.l r2, @(12, r0)
    mov.l @r1+, r2
    mov.l r2, @(16, r0)
    mov.l @r1+, r2
    mov.l r2, @(20, r0)
    mov.l @r1+, r2
    mov.l r2, @(24, r0)
    mov.l @r1+, r2
    mov.l r2, @(28, r0)
    mov.l @r1+, r2
    mov.l r2, @(32, r0)
    mov.l @r1+, r2
    mov.l r2, @(36, r0)
    mov.l @r1+, r2
    mov.l r2, @(40, r0)
    mov.l @r1, r2
    mov.l r2, @(44, r0)
    .byte   0xD0, 0x46    /* mov.l .L_pool_06032ACC, r0 */
    add r12, r0
    mov.l @r0+, r4
    mov.l @r0+, r5
    mov.l @r0+, r6
    .byte   0xD0, 0x31    /* mov.l .L_pool_06032A80, r0 */

    .global FUN_060329BC
    .type FUN_060329BC, @function
FUN_060329BC:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x42    /* mov.l .L_pool_06032AD0, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x31    /* mov.l .L_pool_06032A90, r0 */


    .global FUN_060329CA
    .type FUN_060329CA, @function
FUN_060329CA:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r13, r1
    .byte   0xD0, 0x3F    /* mov.l .L_pool_06032AD4, r0 */
    add r14, r0
    mov.l @r1+, r2
    mov.l r2, @(0, r0)
    mov.l @r1+, r2
    mov.l r2, @(4, r0)
    mov.l @r1+, r2
    mov.l r2, @(8, r0)
    mov.l @r1+, r2
    mov.l r2, @(12, r0)
    mov.l @r1+, r2
    mov.l r2, @(16, r0)
    mov.l @r1+, r2
    mov.l r2, @(20, r0)
    mov.l @r1+, r2
    mov.l r2, @(24, r0)
    mov.l @r1+, r2
    mov.l r2, @(28, r0)
    mov.l @r1+, r2
    mov.l r2, @(32, r0)
    mov.l @r1+, r2
    mov.l r2, @(36, r0)
    mov.l @r1+, r2
    mov.l r2, @(40, r0)
    mov.l @r1, r2
    mov.l r2, @(44, r0)
    .byte   0xD0, 0x33    /* mov.l .L_pool_06032AD8, r0 */
    add r12, r0
    mov.l @r0+, r4
    mov.l @r0+, r5
    mov.l @r0+, r6
    .byte   0xD0, 0x1B    /* mov.l .L_pool_06032A80, r0 */

    .global FUN_06032A14
    .type FUN_06032A14, @function
FUN_06032A14:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x2F    /* mov.l .L_pool_06032ADC, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x1B    /* mov.l .L_pool_06032A90, r0 */


    .global FUN_06032A22
    .type FUN_06032A22, @function
FUN_06032A22:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r13, r1
    .byte   0xD0, 0x2C    /* mov.l .L_pool_06032AE0, r0 */
    add r14, r0
    mov.l @r1+, r2
    mov.l r2, @(0, r0)
    mov.l @r1+, r2
    mov.l r2, @(4, r0)
    mov.l @r1+, r2
    mov.l r2, @(8, r0)
    mov.l @r1+, r2
    mov.l r2, @(12, r0)
    mov.l @r1+, r2
    mov.l r2, @(16, r0)
    mov.l @r1+, r2
    mov.l r2, @(20, r0)
    mov.l @r1+, r2
    mov.l r2, @(24, r0)
    mov.l @r1+, r2
    mov.l r2, @(28, r0)
    mov.l @r1+, r2
    mov.l r2, @(32, r0)
    mov.l @r1+, r2
    mov.l r2, @(36, r0)
    mov.l @r1+, r2
    mov.l r2, @(40, r0)
    mov.l @r1, r2
    mov.l r2, @(44, r0)
    .byte   0xD0, 0x14    /* mov.l .L_pool_06032AB4, r0 */

    .global FUN_06032A62
    .type FUN_06032A62, @function
FUN_06032A62:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_06032A79, r13
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
    .4byte  FUN_06026E94
    .4byte  0x0000002C
    .4byte  FUN_06026F2A
    .4byte  0x0000002A
    .4byte  FUN_06026EDE
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

    .global FUN_06032AF0
    .type FUN_06032AF0, @function
FUN_06032AF0:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x8B    /* mov.l .L_pool_06032D28, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x8B    /* mov.l .L_pool_06032D2C, r0 */


    .global FUN_06032AFE
    .type FUN_06032AFE, @function
FUN_06032AFE:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x8A    /* mov.l .L_pool_06032D30, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x8A    /* mov.l .L_pool_06032D34, r0 */

    .global FUN_06032B0C
    .type FUN_06032B0C, @function
FUN_06032B0C:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x88    /* mov.l .L_pool_06032D38, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x88    /* mov.l .L_pool_06032D3C, r0 */


    .global FUN_06032B1A
    .type FUN_06032B1A, @function
FUN_06032B1A:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r13, r1
    .byte   0xD0, 0x86    /* mov.l .L_pool_06032D40, r0 */
    add r14, r0
    mov.l @r1+, r2
    mov.l r2, @(0, r0)
    mov.l @r1+, r2
    mov.l r2, @(4, r0)
    mov.l @r1+, r2
    mov.l r2, @(8, r0)
    mov.l @r1+, r2
    mov.l r2, @(12, r0)
    mov.l @r1+, r2
    mov.l r2, @(16, r0)
    mov.l @r1+, r2
    mov.l r2, @(20, r0)
    mov.l @r1+, r2
    mov.l r2, @(24, r0)
    mov.l @r1+, r2
    mov.l r2, @(28, r0)
    mov.l @r1+, r2
    mov.l r2, @(32, r0)
    mov.l @r1+, r2
    mov.l r2, @(36, r0)
    mov.l @r1+, r2
    mov.l r2, @(40, r0)
    mov.l @r1, r2
    mov.l r2, @(44, r0)
    .byte   0xD0, 0x7A    /* mov.l .L_pool_06032D44, r0 */

    .global FUN_06032B5A
    .type FUN_06032B5A, @function
FUN_06032B5A:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x79    /* mov.l .L_pool_06032D48, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x79    /* mov.l .L_pool_06032D4C, r0 */
    add r12, r0
    mov.l @r0+, r4
    mov.l @r0+, r5
    mov.l @r0+, r6
    .byte   0xD0, 0x6C    /* mov.l .L_pool_06032D24, r0 */

    .global FUN_06032B72
    .type FUN_06032B72, @function
FUN_06032B72:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x75    /* mov.l .L_pool_06032D50, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x6B    /* mov.l .L_pool_06032D2C, r0 */

    .global FUN_06032B80
    .type FUN_06032B80, @function
FUN_06032B80:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x72    /* mov.l .L_pool_06032D54, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x69    /* mov.l .L_pool_06032D34, r0 */


    .global FUN_06032B8E
    .type FUN_06032B8E, @function
FUN_06032B8E:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x70    /* mov.l .L_pool_06032D58, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x68    /* mov.l .L_pool_06032D3C, r0 */

    .global FUN_06032B9C
    .type FUN_06032B9C, @function
FUN_06032B9C:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r13, r1
    .byte   0xD0, 0x6D    /* mov.l .L_pool_06032D5C, r0 */
    add r14, r0
    mov.l @r1+, r2
    mov.l r2, @(0, r0)
    mov.l @r1+, r2
    mov.l r2, @(4, r0)
    mov.l @r1+, r2
    mov.l r2, @(8, r0)
    mov.l @r1+, r2
    mov.l r2, @(12, r0)
    mov.l @r1+, r2
    mov.l r2, @(16, r0)
    mov.l @r1+, r2
    mov.l r2, @(20, r0)
    mov.l @r1+, r2
    mov.l r2, @(24, r0)
    mov.l @r1+, r2
    mov.l r2, @(28, r0)
    mov.l @r1+, r2
    mov.l r2, @(32, r0)
    mov.l @r1+, r2
    mov.l r2, @(36, r0)
    mov.l @r1+, r2
    mov.l r2, @(40, r0)
    mov.l @r1, r2
    mov.l r2, @(44, r0)
    .byte   0xD0, 0x61    /* mov.l .L_pool_06032D60, r0 */
    add r12, r0
    mov.l @r0+, r4
    mov.l @r0+, r5
    mov.l @r0+, r6
    .byte   0xD0, 0x4F    /* mov.l .L_pool_06032D24, r0 */


    .global FUN_06032BE6
    .type FUN_06032BE6, @function
FUN_06032BE6:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x5D    /* mov.l .L_pool_06032D64, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x50    /* mov.l .L_pool_06032D34, r0 */

    .global FUN_06032BF4
    .type FUN_06032BF4, @function
FUN_06032BF4:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r13, r1
    .byte   0xD0, 0x5A    /* mov.l .L_pool_06032D68, r0 */
    add r14, r0
    mov.l @r1+, r2
    mov.l r2, @(0, r0)
    mov.l @r1+, r2
    mov.l r2, @(4, r0)
    mov.l @r1+, r2
    mov.l r2, @(8, r0)
    mov.l @r1+, r2
    mov.l r2, @(12, r0)
    mov.l @r1+, r2
    mov.l r2, @(16, r0)
    mov.l @r1+, r2
    mov.l r2, @(20, r0)
    mov.l @r1+, r2
    mov.l r2, @(24, r0)
    mov.l @r1+, r2
    mov.l r2, @(28, r0)
    mov.l @r1+, r2
    mov.l r2, @(32, r0)
    mov.l @r1+, r2
    mov.l r2, @(36, r0)
    mov.l @r1+, r2
    mov.l r2, @(40, r0)
    mov.l @r1, r2
    mov.l r2, @(44, r0)
    .byte   0xD0, 0x4E    /* mov.l .L_pool_06032D6C, r0 */

    .global FUN_06032C34
    .type FUN_06032C34, @function
FUN_06032C34:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x42    /* mov.l .L_pool_06032D48, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x4B    /* mov.l .L_pool_06032D70, r0 */
    add r12, r0
    mov.l @r0+, r4
    mov.l @r0+, r5
    mov.l @r0+, r6
    .byte   0xD0, 0x36    /* mov.l .L_pool_06032D24, r0 */

    .global FUN_06032C4C
    .type FUN_06032C4C, @function
FUN_06032C4C:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x47    /* mov.l .L_pool_06032D74, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x34    /* mov.l .L_pool_06032D2C, r0 */


    .global FUN_06032C5A
    .type FUN_06032C5A, @function
FUN_06032C5A:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x45    /* mov.l .L_pool_06032D78, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x33    /* mov.l .L_pool_06032D34, r0 */

    .global FUN_06032C68
    .type FUN_06032C68, @function
FUN_06032C68:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x42    /* mov.l .L_pool_06032D7C, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x31    /* mov.l .L_pool_06032D3C, r0 */


    .global FUN_06032C76
    .type FUN_06032C76, @function
FUN_06032C76:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r13, r1
    .byte   0xD0, 0x3F    /* mov.l .L_pool_06032D80, r0 */
    add r14, r0
    mov.l @r1+, r2
    mov.l r2, @(0, r0)
    mov.l @r1+, r2
    mov.l r2, @(4, r0)
    mov.l @r1+, r2
    mov.l r2, @(8, r0)
    mov.l @r1+, r2
    mov.l r2, @(12, r0)
    mov.l @r1+, r2
    mov.l r2, @(16, r0)
    mov.l @r1+, r2
    mov.l r2, @(20, r0)
    mov.l @r1+, r2
    mov.l r2, @(24, r0)
    mov.l @r1+, r2
    mov.l r2, @(28, r0)
    mov.l @r1+, r2
    mov.l r2, @(32, r0)
    mov.l @r1+, r2
    mov.l r2, @(36, r0)
    mov.l @r1+, r2
    mov.l r2, @(40, r0)
    mov.l @r1, r2
    mov.l r2, @(44, r0)
    .byte   0xD0, 0x33    /* mov.l .L_pool_06032D84, r0 */
    add r12, r0
    mov.l @r0+, r4
    mov.l @r0+, r5
    mov.l @r0+, r6
    .byte   0xD0, 0x19    /* mov.l .L_pool_06032D24, r0 */

    .global FUN_06032CC0
    .type FUN_06032CC0, @function
FUN_06032CC0:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x2F    /* mov.l .L_pool_06032D88, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x19    /* mov.l .L_pool_06032D34, r0 */


    .global FUN_06032CCE
    .type FUN_06032CCE, @function
FUN_06032CCE:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov r13, r1
    .byte   0xD0, 0x2C    /* mov.l .L_pool_06032D8C, r0 */
    add r14, r0
    mov.l @r1+, r2
    mov.l r2, @(0, r0)
    mov.l @r1+, r2
    mov.l r2, @(4, r0)
    mov.l @r1+, r2
    mov.l r2, @(8, r0)
    mov.l @r1+, r2
    mov.l r2, @(12, r0)
    mov.l @r1+, r2
    mov.l r2, @(16, r0)
    mov.l @r1+, r2
    mov.l r2, @(20, r0)
    mov.l @r1+, r2
    mov.l r2, @(24, r0)
    mov.l @r1+, r2
    mov.l r2, @(28, r0)
    mov.l @r1+, r2
    mov.l r2, @(32, r0)
    mov.l @r1+, r2
    mov.l r2, @(36, r0)
    mov.l @r1+, r2
    mov.l r2, @(40, r0)
    mov.l @r1, r2
    mov.l r2, @(44, r0)
    .byte   0xD0, 0x17    /* mov.l .L_pool_06032D6C, r0 */

    .global FUN_06032D0E
    .type FUN_06032D0E, @function
FUN_06032D0E:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_06032D48, r13
    mov.l @r13, r13
    rts
    nop
    .2byte  0x0000
    .4byte  0x00000060
    .4byte  sym_06026E2E
    .4byte  0x0000003C
    .4byte  FUN_06026E94
    .4byte  0x00000040
    .4byte  FUN_06026F2A
    .4byte  0x0000003E
    .4byte  FUN_06026EDE
    .4byte  0x000001D4
    .4byte  sym_06026DBC
.L_06032D48:
    .4byte  sym_06089EDC
    .4byte  0x0000006C
    .4byte  0x00000042
    .4byte  0x00000046
    .4byte  0x00000044
    .4byte  0x00000204
    .4byte  0x00000078
    .4byte  0x00000048
    .4byte  0x00000234
    .4byte  sym_06026DF8
    .4byte  0x00000084
    .4byte  0x0000004A
    .4byte  0x0000004E
    .4byte  0x0000004C
    .4byte  0x00000264
    .4byte  0x00000090
    .4byte  0x00000050
    .4byte  0x00000294
    .global FUN_06032D90
FUN_06032D90:
    .4byte  0xD0166002
    .4byte  0xD116210E
    .4byte  0x001AD316
    .4byte  0x330CD013
    .4byte  0x60024008
    .4byte  0xD114021E
    .4byte  0xD01401EC
    .4byte  0x41084108
    .4byte  0x321C6126
    .4byte  0x6436314C
    .4byte  0xD0110E16
    .4byte  0x61266436
    .4byte  0x314CD010
    .4byte  0x0E166126
    .4byte  0x6436314C
    .4byte  0xD00E0E16
    .4byte  0x6125D007
    .4byte  0x0E156124
    .4byte  0xD00C0E14
    .4byte  0xD00B01EC
    .4byte  0x4108D00B
    .4byte  0x021ED00B
    .4byte  0x000B0E26
    .4byte  sym_0607EAD8
    .4byte  0x0000000C
    .4byte  sym_060624A4
    .4byte  sym_060624F8
    .4byte  0x000002DC
    .4byte  0x00000000
    .4byte  0x00000004
    .4byte  0x00000008
    .4byte  0x000002DD
    .4byte  sym_06062624
    .4byte  0x000002D8
    .global FUN_06032E18
FUN_06032E18:
    .4byte  0xD00A0E46
    .4byte  0x44084400
    .4byte  0xD009340C
    .4byte  0x61466246
    .4byte  0xD0080E16
    .4byte  0xD0080E26
    .4byte  0xD00801ED
    .4byte  0xD0082108
    .4byte  0x89106123
    .4byte  0x71FFA00E
    .4byte  0x00090000
    .4byte  0x000002D0
    .4byte  sym_060627F8
    .4byte  0x000002CC
    .4byte  0x000002C8
    .4byte  0x0000000E
    .4byte  0x00000002
    .4byte  0xD101D002
    .4byte  0x000B0E16
    .4byte  0x00000001
    .4byte  0x000002C4
    .global FUN_06032E6C
FUN_06032E6C:
    .4byte  0xD00800EE
    .4byte  0xD108210F
    .4byte  0x011AD008
    .4byte  0x02EE321C
    .4byte  0xD30733EC
    .4byte  0xD6076726
    .4byte  0x23727304
    .4byte  0x46108BFA
    .4byte  0x000B0009
    .4byte  0x000002C4
    .4byte  0x00000044
    .4byte  0x000002CC
    .4byte  0x00000010
    .4byte  0x00000011
    .global FUN_06032EA4
FUN_06032EA4:
    .4byte  0xD00301ED
    .4byte  0xD0032108
    .4byte  0x8B06000B
    .4byte  0x00090000
    .4byte  0x0000000E
    .4byte  0x0000001C
    .2byte  0xD049

    .global FUN_06032EBE
    .type FUN_06032EBE, @function
FUN_06032EBE:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x48    /* mov.l .L_pool_06032FE8, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x48    /* mov.l .L_pool_06032FEC, r0 */
    mov.l @(r0, r14), r4
    .byte   0xD0, 0x48    /* mov.l .L_pool_06032FF0, r0 */
    mov.l @(r0, r14), r5
    .byte   0xD0, 0x48    /* mov.l .L_pool_06032FF4, r0 */
    mov.l @(r0, r14), r6
    .byte   0xD0, 0x48    /* mov.l .L_pool_06032FF8, r0 */

    .global FUN_06032ED8
    .type FUN_06032ED8, @function
FUN_06032ED8:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x46    /* mov.l .L_pool_06032FFC, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x46    /* mov.l .L_pool_06033000, r0 */


    .global FUN_06032EE6
    .type FUN_06032EE6, @function
FUN_06032EE6:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x45    /* mov.l .L_pool_06033004, r0 */
    mov.w @(r0, r14), r1
    .byte   0xD0, 0x3F    /* mov.l .L_pool_06032FF0, r0 */
    tst r0, r1
    .byte   0x89, 0x24    /* bt 0x06032F42 (external) */
    mov.l r1, @-r15
    .byte   0xD0, 0x3A    /* mov.l .L_pool_06032FE4, r0 */

    .global FUN_06032EFC
    .type FUN_06032EFC, @function
FUN_06032EFC:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x38    /* mov.l .L_pool_06032FE8, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x3F    /* mov.l .L_pool_06033008, r0 */
    mov.l @r0+, r4
    mov.l @r0+, r5
    mov.l @r0, r6
    .byte   0xD0, 0x39    /* mov.l .L_pool_06032FF8, r0 */


    .global FUN_06032F12
    .type FUN_06032F12, @function
FUN_06032F12:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x3B    /* mov.l .L_pool_06033008, r0 */
    mov.l @(12, r0), r4
    .byte   0xD0, 0x3B    /* mov.l .L_pool_0603300C, r0 */

    .global FUN_06032F20
    .type FUN_06032F20, @function
FUN_06032F20:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x39    /* mov.l .L_pool_06033010, r0 */


    .global FUN_06032F2A
    .type FUN_06032F2A, @function
FUN_06032F2A:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x38    /* mov.l .L_pool_06033014, r0 */

    .global FUN_06032F34
    .type FUN_06032F34, @function
FUN_06032F34:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x2A    /* mov.l .L_pool_06032FE8, r13 */
    mov.l @r13, r13
    mov.l @r15+, r1
    .byte   0xD0, 0x2C    /* mov.l .L_pool_06032FF4, r0 */
    tst r0, r1
    .byte   0x89, 0x24    /* bt 0x06032F92 (external) */
    mov.l r1, @-r15
    .byte   0xD0, 0x26    /* mov.l .L_pool_06032FE4, r0 */

    .global FUN_06032F4C
    .type FUN_06032F4C, @function
FUN_06032F4C:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x24    /* mov.l .L_pool_06032FE8, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x2B    /* mov.l .L_pool_06033008, r0 */
    mov.l @(16, r0), r4
    mov.l @(20, r0), r5
    mov.l @(24, r0), r6
    .byte   0xD0, 0x25    /* mov.l .L_pool_06032FF8, r0 */


    .global FUN_06032F62
    .type FUN_06032F62, @function
FUN_06032F62:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x27    /* mov.l .L_pool_06033008, r0 */
    mov.l @(28, r0), r4
    .byte   0xD0, 0x27    /* mov.l .L_pool_0603300C, r0 */

    .global FUN_06032F70
    .type FUN_06032F70, @function
FUN_06032F70:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x25    /* mov.l .L_pool_06033010, r0 */


    .global FUN_06032F7A
    .type FUN_06032F7A, @function
FUN_06032F7A:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x24    /* mov.l .L_pool_06033014, r0 */

    .global FUN_06032F84
    .type FUN_06032F84, @function
FUN_06032F84:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x16    /* mov.l .L_pool_06032FE8, r13 */
    mov.l @r13, r13
    mov.l @r15+, r1
    .byte   0xD0, 0x21    /* mov.l .L_pool_06033018, r0 */
    tst r0, r1
    .byte   0x89, 0x1C    /* bt 0x06032FD2 (external) */
    .byte   0xD0, 0x12    /* mov.l .L_pool_06032FE4, r0 */


    .global FUN_06032F9A
    .type FUN_06032F9A, @function
FUN_06032F9A:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x11    /* mov.l .L_pool_06032FE8, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x18    /* mov.l .L_pool_06033008, r0 */
    mov.l @(32, r0), r4
    mov.l @(36, r0), r5
    mov.l @(40, r0), r6
    .byte   0xD0, 0x12    /* mov.l .L_pool_06032FF8, r0 */

    .global FUN_06032FB0
    .type FUN_06032FB0, @function
FUN_06032FB0:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD4, 0x0C    /* mov.l .L_pool_06032FEC, r4 */
    .byte   0xD0, 0x18    /* mov.l .L_pool_0603301C, r0 */

    .global FUN_06032FBC
    .type FUN_06032FBC, @function
FUN_06032FBC:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x13    /* mov.l .L_pool_06033014, r0 */


    .global FUN_06032FC6
    .type FUN_06032FC6, @function
FUN_06032FC6:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x06    /* mov.l .L_pool_06032FE8, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x10    /* mov.l .L_pool_06033014, r0 */

    .global FUN_06032FD4
    .type FUN_06032FD4, @function
FUN_06032FD4:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_06032FE8, r13
    mov.l @r13, r13
    rts
    nop
    .4byte  sym_06026DBC
.L_pool_06032FE8:
    .4byte  sym_06089EDC
    .4byte  0x00000000
    .4byte  0x00000004
    .4byte  0x00000008
    .4byte  sym_06026E2E
    .4byte  0x0000000C
    .4byte  FUN_06026EDE
    .4byte  0x0000000E
    .4byte  sym_060624C8
    .4byte  FUN_06026F2A
    .4byte  FUN_0600A4AA
    .4byte  sym_06026DF8
    .4byte  0x00000010
    .4byte  FUN_0600A474
