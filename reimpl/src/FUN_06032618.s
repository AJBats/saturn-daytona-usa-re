
    .section .text.FUN_06032618


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
