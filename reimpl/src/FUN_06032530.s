
    .section .text.FUN_06032530


    .global FUN_06032530
    .type FUN_06032530, @function
FUN_06032530:
    sts.l pr, @-r15
    .reloc ., R_SH_IND12W, FUN_06032EA4 - 4
    .2byte 0xB000    /* bsr FUN_06032EA4 (linker-resolved) */
    nop
    lds.l @r15+, pr
    .global FUN_06032538
FUN_06032538:
    rts
    nop
    .global FUN_0603253C
FUN_0603253C:
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
    .global FUN_06032584
FUN_06032584:
    .2byte  0xD010


    .global FUN_06032586
    .type FUN_06032586, @function
FUN_06032586:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xDD, 0x0F    /* mov.l .L_pool_060325CC, r13 */
    mov.l @r13, r13
    .byte   0xD0, 0x0F    /* mov.l .L_pool_060325D0, r0 */
    mov.l @(r0, r14), r4
    .byte   0xD0, 0x0F    /* mov.l .L_pool_060325D4, r0 */
    mov.l @(r0, r14), r5
    .byte   0xD0, 0x0F    /* mov.l .L_pool_060325D8, r0 */
    mov.l @(r0, r14), r6
    .byte   0xD0, 0x0F    /* mov.l .L_pool_060325DC, r0 */


    .global FUN_060325A0
    .type FUN_060325A0, @function
FUN_060325A0:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x0D    /* mov.l .L_pool_060325E0, r0 */
    mov.w @(r0, r14), r4
    .byte   0xD0, 0x0D    /* mov.l .L_pool_060325E4, r0 */


    .global FUN_060325AE
    .type FUN_060325AE, @function
FUN_060325AE:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_060325EC, r1
    mov.l   .L_pool_060325F0, r0
    mov.b @(r0, r14), r0
    mov.l   .L_pool_060325F4, r2
    tst r2, r0
    bf      .L_060325F8
    mov.l   .L_pool_060325F8, r0
    bra     .L_060325FA
    add r0, r1
    .4byte  sym_06026DBC
    .4byte  sym_06089EDC
    .4byte  0x00000000
    .4byte  0x00000004
    .4byte  0x00000008
    .4byte  sym_06026E2E
    .4byte  0x0000000C
    .4byte  FUN_06026EDE
.L_pool_060325EC:
    .4byte  0x00000054
.L_pool_060325F0:
    .4byte  0x000002DC
.L_pool_060325F4:
    .4byte  0xFFFFFFFC
.L_pool_060325F8:
    .4byte  sym_06081898
.L_060325F8:
    add r14, r1
.L_060325FA:
    .byte   0xD0, 0x1B    /* mov.l .L_pool_06032668, r0 */
    mov.l r1, @(r0, r14)
    .byte   0xD7, 0x1B    /* mov.l .L_pool_0603266C, r7 */
    mov.l r7, @-r15
    .byte   0xD0, 0x1B    /* mov.l .L_pool_06032670, r0 */

    .global FUN_06032604
    .type FUN_06032604, @function
FUN_06032604:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_06032675, r13
    mov.l @r13, r13
    mov.l r7, @-r15
    .byte   0xD0, 0x15    /* mov.l .L_pool_06032668, r0 */
    mov.l @(r0, r14), r4
    .byte   0xD0, 0x18    /* mov.l .L_pool_06032678, r0 */

    .global FUN_06032618
    .type FUN_06032618, @function
FUN_06032618:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l @r15+, r7
    .byte   0xD0, 0x12    /* mov.l .L_pool_0603266C, r0 */
    sub r7, r0
    .byte   0xD1, 0x15    /* mov.l .L_pool_0603267C, r1 */
    add r14, r1
    mov.b @(r0, r1), r4
    .byte   0xD0, 0x14    /* mov.l .L_pool_06032680, r0 */


    .global FUN_0603262E
    .type FUN_0603262E, @function
FUN_0603262E:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    .byte   0xD0, 0x0C    /* mov.l .L_pool_06032668, r0 */
    mov.l @(r0, r14), r1
    .byte   0xD2, 0x12    /* mov.l .L_pool_06032684, r2 */
    add r2, r1
    mov.l r1, @(r0, r14)
    .byte   0xD0, 0x11    /* mov.l .L_pool_06032688, r0 */

    .global FUN_06032642
    .type FUN_06032642, @function
FUN_06032642:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_06032675, r13
    mov.l @r13, r13
    mov.l @r15+, r7
    dt r7
    .byte   0x8B, 0xD5    /* bf 0x06032600 (external) */
    .byte   0xD0, 0x0C    /* mov.l .L_pool_06032688, r0 */

    .global FUN_06032656
    .type FUN_06032656, @function
FUN_06032656:
    sts.l pr, @-r15
    jsr @r0
    nop
    lds.l @r15+, pr
    mov.l   .L_pool_06032675, r13
    mov.l @r13, r13
    rts
    nop
    .2byte  0x0000
    .4byte  0x000002D4
    .4byte  0x0000000D
    .4byte  sym_06026DBC
.L_pool_06032675:
    .4byte  sym_06089EDC
    .4byte  sym_06026F72
    .4byte  0x000002DE
    .4byte  FUN_0600A474
    .4byte  0x00000030
    .4byte  sym_06026DF8
    .global FUN_0603268C
FUN_0603268C:
    .4byte  0xDD476DD2
    .4byte  0xDC47D048
