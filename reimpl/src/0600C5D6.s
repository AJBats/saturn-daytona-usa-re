
    .section .text.FUN_0600C5D6


    .global FUN_0600C5D6
    .type FUN_0600C5D6, @function
FUN_0600C5D6:
    mov.l r14, @-r15
    mov.l r13, @-r15
    mov.l r12, @-r15
    mov.l r11, @-r15
    mov.l r10, @-r15
    sts.l pr, @-r15
    add #-0x4, r15
    .byte   0xDA, 0x0E    /* mov.l .L_0600C620, r10 */
    .byte   0xDB, 0x0F    /* mov.l .L_0600C624, r11 */
    .byte   0xDE, 0x0F    /* mov.l .L_0600C628, r14 */
    .byte   0xDD, 0x10    /* mov.l .L_0600C62C, r13 */
    .byte   0xB3, 0xA8    /* bsr 0x0600CD40 (external) */
    mov.l @r14, r14
    mov r0, r12
    .byte   0xD0, 0x0F    /* mov.l .L_0600C630, r0 */
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x2, r0
    bt/s    .L_0600C60E
    add #0x18, r12
    mov.w   DAT_0600c616, r0
    mov.l @(r0, r14), r2
    cmp/pl r2
    bt      .L_0600C60E
    mov.w   .L_0600C618, r0
    mov.l @(r0, r14), r2
    cmp/pl r2
    bf      .L_0600C634
.L_0600C60E:
    .byte   0xB2, 0x42    /* bsr 0x0600CA96 (external) */
    mov r13, r4
    bra     .L_0600C692
    nop

    .global DAT_0600c616
DAT_0600c616:
    .2byte  0x01BC
.L_0600C618:
    .2byte  0x00B8
    .2byte  0xFFFF
    .4byte  0x00480000
.L_0600C620:
    .4byte  fpmul
.L_0600C624:
    .4byte  sym_0607EBDC
.L_0600C628:
    .4byte  sym_0607E940
.L_0600C62C:
    .4byte  sym_06078680
.L_0600C630:
    .4byte  sym_06087804
.L_0600C634:
    .byte   0xD2, 0x33    /* mov.l .L_0600C704, r2 */
    mov.l @r2, r2
    mov r2, r0
    mov.b @(3, r0), r0
    tst #0x8, r0
    bf      .L_0600C68C
    mov.w   DAT_0600c6f6, r0
    mov.l @(r0, r14), r3
    cmp/pl r3
    bt      .L_0600C68C
    mov.w   DAT_0600c6f8, r0
    mov.b @(r0, r14), r0
    tst #0x20, r0
    bf      .L_0600C68C
    mov #0xA, r2
    mov.l @r11, r3
    cmp/gt r2, r3
    bt      .L_0600C666
    mov.w   DAT_0600c6fa, r0
    mov #0x66, r3
    mov.l @(r0, r14), r2
    cmp/ge r3, r2
    bt      .L_0600C666
    .byte   0xB4, 0x79    /* bsr 0x0600CF58 (external) */
    mov r12, r4
.L_0600C666:
    mov.w   DAT_0600c6fa, r0
    mov.l @(r0, r14), r2
    cmp/pl r2
    bf      .L_0600C682
    mov.w   DAT_0600c6fa, r0
    mov.l @(r0, r14), r2
    add #-0x2, r2
    mov.l r2, @(r0, r14)
    .byte   0xB2, 0x0E    /* bsr 0x0600CA96 (external) */
    mov r13, r4
    mov.l @r11, r2
    add #0x1, r2
    bra     .L_0600C692
    mov.l r2, @r11
.L_0600C682:
    mov r13, r5
    .byte   0xB2, 0xD8    /* bsr 0x0600CC38 (external) */
    mov r12, r4
    bra     .L_0600C692
    nop
.L_0600C68C:
    mov r13, r5
    .byte   0xB2, 0xD3    /* bsr 0x0600CC38 (external) */
    mov r12, r4
.L_0600C692:
    .byte   0xD0, 0x1D    /* mov.l .L_0600C708, r0 */
    mov.w @r0, r0
    extu.w r0, r0
    cmp/eq #0x3, r0
    bf      .L_0600C6AA
    mov.w   DAT_0600c6fc, r0
    mov.l @(r0, r14), r5
    jsr @r10
    mov.l @(8, r12), r4
    mov.w   DAT_0600c6fe, r1
    add r14, r1
    mov.l r0, @r1
.L_0600C6AA:
    mov r13, r5
    .byte   0xB1, 0x0E    /* bsr 0x0600C8CC (external) */
    mov r14, r4
    .byte   0xD2, 0x16    /* mov.l .L_0600C70C, r2 */
    mov.l @r2, r2
    mov.l @r2, r3
    .byte   0xD2, 0x16    /* mov.l .L_0600C710, r2 */
    and r2, r3
    tst r3, r3
    bf      .L_0600C718
    mov.w @(14, r13), r0
    mov r0, r3
    mov.l r0, @(32, r14)
    mov.w   DAT_0600c700, r6
    mov.w   DAT_0600c702, r5
    mov.l @(40, r14), r4
    .byte   0xD3, 0x12    /* mov.l .L_0600C714, r3 */
    add r14, r6
    add r14, r5
    jsr @r3
    neg r4, r4
    mov.w   DAT_0600c702, r0
    mov.l @(r0, r14), r5
    jsr @r10
    mov.l @(12, r14), r4
    mov.l @(16, r14), r3
    add r0, r3
    mov.l r3, @(16, r14)
    mov.w   DAT_0600c700, r0
    mov.l @(r0, r14), r5
    jsr @r10
    mov.l @(12, r14), r4
    mov.l @(24, r14), r3
    add r0, r3
    mov.l r3, @(24, r14)
    mov #0x0, r2
    bra     .L_0600C73E
    mov.l r2, @(20, r14)

    .global DAT_0600c6f6
DAT_0600c6f6:
    .2byte  0x0208

    .global DAT_0600c6f8
DAT_0600c6f8:
    .2byte  0x0161

    .global DAT_0600c6fa
DAT_0600c6fa:
    .2byte  0x0204

    .global DAT_0600c6fc
DAT_0600c6fc:
    .2byte  0x0198

    .global DAT_0600c6fe
DAT_0600c6fe:
    .2byte  0x0194

    .global DAT_0600c700
DAT_0600c700:
    .2byte  0x0190

    .global DAT_0600c702
DAT_0600c702:
    .2byte  0x018C
.L_0600C704:
    .4byte  sym_0607E944
.L_0600C708:
    .4byte  sym_06087804
.L_0600C70C:
    .4byte  sym_0607E940
.L_0600C710:
    .4byte  0x00E00000
.L_0600C714:
    .4byte  sincos_pair
.L_0600C718:
    .byte   0xB1, 0x06    /* bsr 0x0600C928 (external) */
    mov r14, r4
    mov r13, r5
    .byte   0xB0, 0x59    /* bsr 0x0600C7D4 (external) */
    mov r14, r4
    mov r15, r6
    mov r14, r5
    mov.l r6, @-r15
    add #0x10, r5
    mov.l r5, @-r15
    mov.l @(24, r14), r5
    .byte   0xD3, 0x25    /* mov.l .L_fn_atan2, r3 */
    jsr @r3
    mov.l @(16, r14), r4
    mov r0, r4
    mov.l @r15+, r5
    .byte   0xD3, 0x23    /* mov.l .L_fn_apply_response, r3 */
    jsr @r3
    mov.l @r15+, r6
.L_0600C73E:
    add #0x4, r15
    lds.l @r15+, pr
    mov.l @r15+, r10
    mov.l @r15+, r11
    mov.l @r15+, r12
    mov.l @r15+, r13
    rts
    mov.l @r15+, r14
